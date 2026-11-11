# 字体设置（harbour-fontsettings）

Sailfish OS 的系统 UI 字体管理器。导入字体、选正文字体/标题字体/等宽字体、维护回退顺序，
一键应用并重启主屏幕。

不改任何系统文件：所有改动都写进当前用户的
`~/.config/fontconfig/fonts.conf`，把 Sailfish UI 实际在用的
**`Sail Sans Pro Light`** 家族替换掉。删掉这个文件（或用应用里的「恢复系统默认」）即可回到原样。

## 功能

| 功能 | 说明 |
|---|---|
| 导入字体 | 支持 `.ttf` / `.otf` / `.ttc`，复制到 `~/.local/share/fonts/` 并刷新 fontconfig 缓存 |
| 正文字体 | 全局 UI 字体（列表里带中文/符号预览） |
| 标题字体 | 额外写 dconf `font_family_heading`，重启主屏幕后部分标题会跟随 |
| 等宽字体 | 同时替换 `monospace` 与 `DejaVu Sans Mono`（终端、代码显示） |
| 回退链 | 有序列表，缺字时按顺序找；支持上移/下移/删除 |
| 应用 | 生成 fontconfig 配置 + `fc-cache -f`，可选立刻重启主屏幕 |
| 恢复 | 删除/还原 `fonts.conf`，重置 dconf 键 |
| 预览 | 用当前选择实时渲染中文、西文、符号 |
| CLI | 同样的后端可以在终端里用，方便脚本化和远程排查 |

## 原理

Sailfish 的 Silica 主题把 UI 字体写死为 `Sail Sans Pro Light`
（`libsailfishsilica.so` 里的默认值）。字体最终由 fontconfig 解析，所以只要在
**用户级** fontconfig 配置里给这个家族名做一个 `binding="strong"` 的 prefer 别名，
就能在不碰 `/usr` 的前提下换掉整个 UI 字体：

```xml
<alias binding="strong">
  <family>Sail Sans Pro Light</family>
  <prefer>
    <family>你的字体</family>
    <family>WenQuanYi Zen Hei</family>   <!-- 中文回退 -->
    <family>emoji</family>
  </prefer>
</alias>
<selectfont><rejectfont><glob>/usr/share/fonts/sail-sans-pro</glob></rejectfont></selectfont>
```

应用会生成这份文件（带标记注释），并在需要时先把已有的 `fonts.conf` 备份成
`fonts.conf.before-harbour-fontsettings`。

因为要写 `~/.config/fontconfig`、调用 `fc-cache`、`dconf`、`systemctl --user`，
应用的 desktop 文件里关闭了 sailjail 沙箱：

```ini
[X-Sailjail]
Sandboxing=Disabled
```

这是有意为之——它是个系统配置工具，和文件管理器同类。请只从可信来源安装。

## 安装

```sh
# 手机上（开发者模式已开）
devel-su
pkcon install-local harbour-fontsettings-0.1.0-1.aarch64.rpm
# 或
zypper in ./harbour-fontsettings-0.1.0-1.aarch64.rpm
```

装完在应用菜单里会出现「字体设置」。

## 使用

1. 打开应用 → **导入字体文件…** → 选 `.ttf/.otf/.ttc`（可以从下载目录或任意位置选）。
2. 点 **正文字体** 选一个，列表里能直接看到中文和符号的渲染效果。
3. 需要的话设置 **回退字体**（建议保留一个中文字体 + 一个 emoji 字体）。
4. **应用设置** → 提示时选「立即重启」，或稍后用「重启主屏幕」。
5. 不满意：**恢复系统默认**。

## 命令行

```sh
harbour-fontsettings --cli status
harbour-fontsettings --cli list
harbour-fontsettings --cli import ~/Downloads/Inter-Regular.ttf
harbour-fontsettings --cli apply --primary "Inter" \
    --fallback "WenQuanYi Zen Hei" --fallback "Noto Color Emoji"
harbour-fontsettings --cli reset
```

CLI 不需要图形界面，适合 SSH 远程操作；它和应用写的是同一份配置。

## 构建

```sh
# 主机上装好 Sailfish Platform SDK，并创建好目标
cd fontsettings
mb2 -t <target> build          # 例如 mb2 -t oneplus-dumpling-aarch64 build
# 产物：RPMS/harbour-fontsettings-<version>-<release>.<arch>.rpm
```

依赖：`Qt5Quick`、`Qt5Qml`、`sailfishapp`（见 `rpm/harbour-fontsettings.spec`）。

## 测试状态

- **CLI 已在 qemu-aarch64 + SFOS 5.2 target 的 sysroot 下跑通**：`status` / `list` / `import` /
  `apply` / `reset` 全部返回 0；生成的 `fonts.conf` 通过 XML 校验，`fc-match` 用这份配置
  能把 `Sail Sans Pro Light` 解析成所选字体；用户已有的 `fonts.conf` 会被备份，`reset`
  能原样恢复。
- **GUI 还没有在真机上跑过**（开发时手机不在线）。QML 只做了静态检查，首次安装如果
  界面有问题，多半是某个 Silica 属性名，报错会写进 `journalctl --user -u lipstick`。

## 限制与已知问题

- **标题字体** 走 dconf（`/desktop/sailfish/silica/font_family_heading`），只有部分界面会跟随；
  正文通过 fontconfig 生效，覆盖最广。
- **Android 应用**（AppSupport/AlienDalvik）有独立的 fontconfig，本工具不影响。
- 部分应用把字体写死（Fingerterm 的等宽字体需要单独改它的设置），或自带 QML 字体属性。
- 换字体后布局可能变化（字宽/行高不同），个别页面会挤压。
- **`Sail Sans Pro` 是 Jolla 的授权字体**：自己替换没问题，不要把字体文件打包分发。
- 从系统包升级后 `/usr/share/fonts` 可能变化，用户级配置不受影响。
- Harbour 商店不接受关闭沙箱的应用；这是社区工具，需要手动安装。

## 卸载

```sh
devel-su zypper rm harbour-fontsettings
```

卸载不会自动恢复字体。卸载前先在应用里点「恢复系统默认」，或手动删掉
`~/.config/fontconfig/fonts.conf`（有备份的话把
`fonts.conf.before-harbour-fontsettings` 改名回来）。

## 许可证

MIT。
