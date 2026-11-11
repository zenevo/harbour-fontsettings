# 字体设置（harbour-fontsettings）

Sailfish OS 的系统 UI 字体管理器：导入字体文件、选正文/标题/等宽字体、一键应用并重启主屏幕。

**不修改任何系统文件**——所有改动只写当前用户的 `~/.config/fontconfig/fonts.conf`，删掉这个文件（或点「恢复系统默认」）即可完全回滚。

> A small Sailfish OS app to change the UI font. Everything is per-user: no files under `/usr` or `/etc` are touched.

![icon](icons/harbour-fontsettings-256.png)

## 功能

| 功能 | 说明 |
|---|---|
| 导入字体 | 从系统文件选择器选 `.ttf` / `.otf` / `.ttc`，复制到 `~/.local/share/fonts/` 并刷新 fontconfig 缓存 |
| 正文字体 | 替换 Sailfish UI 实际使用的 `Sail Sans Pro Light` 家族，全局生效 |
| 标题字体 | 额外写 dconf `font_family_heading`，部分界面标题会跟随 |
| 等宽字体 | 同时替换 `monospace` 与 `DejaVu Sans Mono`（终端、代码显示） |
| 预览 | 用当前选择实时渲染西文、中文、符号 |
| 恢复默认 | 删除覆盖配置（用户原有配置会被备份/还原），重置 dconf |
| CLI | 同样的后端可以在终端里用，方便 SSH 排查和脚本化 |

## 原理

Silica 主题把 UI 字体写死为 `Sail Sans Pro Light`（`libsailfishsilica.so` 里的默认值），
字体最终由 fontconfig 解析。应用只在**用户级** fontconfig 里给这个家族名做一个
`binding="strong"` 的别名，指向你选的字体：

```xml
<fontconfig>
  <alias binding="strong">
    <family>Sail Sans Pro Light</family>
    <prefer>
      <family>MiSans</family>
    </prefer>
  </alias>
</fontconfig>
```

配置里**只有主字体一项**。中文、emoji、符号、乃至 Sail Sans Pro 本身的回退，全部交给系统
原有的 fontconfig 配置（`/etc/fonts/local.conf` 等）处理——缺字行为和没换字体时完全一致。

系统自带的 `50-user.conf` 会包含 `~/.config/fontconfig/fonts.conf`，所以这是一个标准的
用户级覆盖，其他用户和 root 都不受影响。可验证：

```sh
HOME=/tmp/empty fc-match "Sail Sans Pro Light"   # → SailSansPro-Light.ttf，系统策略没变
```

## 安装

```sh
# 手机上（开发者模式已开）
devel-su /bin/sh -c "zypper --no-refresh in --allow-unsigned-rpm ./harbour-fontsettings-*.rpm"
```

RPM 在 Releases 页。装完应用菜单里会出现「字体设置」。

## 使用

1. 打开应用 → **导入字体文件…** → 选一个字体（可以浏览任意目录，选完直接回到主页）
2. 点 **正文字体** 选择（列表里能看到中文和符号的实际渲染）
3. **应用设置** → **重启主屏幕**
4. 不满意：**恢复系统默认**

## 命令行

```sh
harbour-fontsettings --cli status
harbour-fontsettings --cli list
harbour-fontsettings --cli import ~/Downloads/MiSans-Regular.ttf
harbour-fontsettings --cli apply --primary MiSans
harbour-fontsettings --cli reset
```

CLI 不需要图形界面，和应用写的是同一份配置。

## 依赖

共享库由 rpmbuild 自动生成 soname 依赖（Qt5 Core/Gui/Qml/Quick、`libsailfishapp` 等），
下面这些是 rpm 看不到、已在 spec 里显式声明的：

| 依赖 | 用途 |
|---|---|
| `sailfishsilica-qt5` | `Sailfish.Silica` QML 模块 |
| `sailfish-components-pickers-qt5` | `Sailfish.Pickers`（文件选择器） |
| `qt5-qtdeclarative-import-qtquick2plugin` / `-import-window2` | `QtQuick 2.0` / `QtQuick.Window 2.1` |
| `fontconfig` | `fc-cache` / `fc-list` / `fc-scan` |
| `dconf` | 写标题字体键 |

全部是 SFOS 底包自带组件，安装时不需要额外下载。

## 构建

```sh
# 主机上装好 Sailfish Platform SDK 并创建目标（例如 oneplus-dumpling-aarch64）
cd fontsettings
mb2 -t <target> build
# 产物：RPMS/harbour-fontsettings-<version>-1.<arch>.rpm
```

## 仓库结构

```
fontsettings.pro          qmake 工程（只编二进制）
src/fontbackend.{h,cpp}   后端：字体枚举 / 导入 / fontconfig 生成 / dconf / 重置
src/main.cpp              GUI 与 --cli 两种入口
qml/main.qml              ApplicationWindow
qml/pages/FirstPage.qml   预览 + 字体选择 + 导入/应用/恢复
qml/pages/FontListPage.qml  可搜索的字体列表（带渲染预览）
qml/cover/CoverPage.qml   封面
icons/                    图标（86–512 PNG + SVG）
rpm/harbour-fontsettings.spec
```

## 限制

- **标题字体**走 dconf，只有部分界面跟随；正文通过 fontconfig 生效，覆盖最广。
- **Android 应用**（AppSupport / AlienDalvik）有独立的 fontconfig，本工具不影响。
- 部分应用把字体写死（例如 Fingerterm 的终端字体需要单独设置）。
- 换字体会改变字宽/行高，个别页面可能挤压。
- **`Sail Sans Pro` 是 Jolla 的授权字体**：自己替换没问题，不要把字体文件打包分发。
- 应用在 desktop 文件里关闭了 sailjail 沙箱（`[X-Sailjail] Sandboxing=Disabled`）——它需要写
  `~/.config/fontconfig`、执行 `fc-cache`/`dconf`/`systemctl --user`。这是和文件管理器同类的
  系统配置工具；Harbour 商店不接受这类应用，需要手动安装。

## 卸载

```sh
devel-su /bin/sh -c "zypper rm harbour-fontsettings"
```

卸载不会自动恢复字体。卸载前先在应用里点「恢复系统默认」，或手动删除
`~/.config/fontconfig/fonts.conf`（有备份时把 `fonts.conf.before-harbour-fontsettings` 改回来）。

## 许可证

MIT。图标使用 SFOS 基础图标轮廓，字体与系统组件版权归各自所有者。
