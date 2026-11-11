import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.Pickers 1.0

Page {
    id: page

    Component {
        id: fontPicker

        FilePickerPage {
            nameFilters: ["*.ttf", "*.otf", "*.ttc", "*.TTF", "*.OTF", "*.TTC"]

            onSelectedContentPropertiesChanged: {
                var path = selectedContentProperties['filePath']
                if (path) {
                    backend.importFont(path)
                }
                pageStack.pop()
            }
        }
    }

    SilicaFlickable {
        id: flickable

        anchors.fill: parent
        contentHeight: column.height + Theme.paddingLarge

        Column {
            id: column

            width: parent.width
            spacing: Theme.paddingMedium

            PageHeader {
                title: qsTr("字体设置")
            }

            SectionHeader {
                text: qsTr("预览")
            }

            Rectangle {
                x: Theme.horizontalPageMargin
                width: parent.width - 2 * Theme.horizontalPageMargin
                height: previewColumn.height + 2 * Theme.paddingLarge
                radius: Theme.paddingSmall
                color: Theme.rgba(Theme.highlightBackgroundColor, 0.12)

                Column {
                    id: previewColumn

                    x: Theme.paddingLarge
                    y: Theme.paddingLarge
                    width: parent.width - 2 * Theme.paddingLarge
                    spacing: Theme.paddingSmall

                    Label {
                        width: parent.width
                        text: "Aa Bb Cc 0123"
                        font.family: backend.primary || backend.defaultFamily
                        font.pixelSize: Theme.fontSizeLarge
                        truncationMode: TruncationMode.Fade
                    }

                    Label {
                        width: parent.width
                        text: qsTr("中文示例：永和九年，岁在癸丑")
                        font.family: backend.primary || backend.defaultFamily
                        color: Theme.secondaryColor
                        wrapMode: Text.Wrap
                    }

                    Label {
                        width: parent.width
                        text: qsTr("符号：！@#￥%…&*（）「」")
                        font.family: backend.primary || backend.defaultFamily
                        color: Theme.secondaryColor
                        wrapMode: Text.Wrap
                    }
                }
            }

            SectionHeader {
                text: qsTr("字体")
            }

            ValueButton {
                label: qsTr("正文字体")
                value: backend.primary || qsTr("系统默认")
                onClicked: pageStack.push(Qt.resolvedUrl("FontListPage.qml"), { mode: "primary" })
            }

            ValueButton {
                label: qsTr("标题字体")
                value: backend.heading || qsTr("同正文字体")
                onClicked: pageStack.push(Qt.resolvedUrl("FontListPage.qml"), { mode: "heading" })
            }

            ValueButton {
                label: qsTr("等宽字体（终端）")
                value: backend.mono || qsTr("系统默认")
                onClicked: pageStack.push(Qt.resolvedUrl("FontListPage.qml"), { mode: "mono" })
            }

            ValueButton {
                label: qsTr("回退字体")
                value: backend.fallbacks.length > 0
                       ? qsTr("%1 个").arg(backend.fallbacks.length)
                       : qsTr("无")
                onClicked: pageStack.push(Qt.resolvedUrl("FallbackPage.qml"))
            }

            SectionHeader {
                text: qsTr("操作")
            }

            Button {
                x: Theme.horizontalPageMargin
                width: parent.width - 2 * Theme.horizontalPageMargin
                text: qsTr("导入字体文件…")
                onClicked: pageStack.push(fontPicker)
            }

            Button {
                x: Theme.horizontalPageMargin
                width: parent.width - 2 * Theme.horizontalPageMargin
                text: qsTr("应用设置")
                enabled: backend.primary.length > 0 || backend.heading.length > 0
                         || backend.mono.length > 0 || backend.fallbacks.length > 0
                onClicked: backend.apply()
            }

            Button {
                x: Theme.horizontalPageMargin
                width: parent.width - 2 * Theme.horizontalPageMargin
                text: qsTr("恢复系统默认")
                onClicked: remorse.execute(qsTr("正在恢复…"), function() { backend.reset() })
            }

            Button {
                x: Theme.horizontalPageMargin
                width: parent.width - 2 * Theme.horizontalPageMargin
                text: qsTr("重启主屏幕")
                onClicked: {
                    if (!backend.restartHomeScreen()) {
                        remorse.execute(qsTr("重启失败，请用「设置 → 工具 → 重启主屏幕」"))
                    }
                }
            }

            Label {
                x: Theme.horizontalPageMargin
                width: parent.width - 2 * Theme.horizontalPageMargin
                text: backend.lastMessage
                visible: text.length > 0
                color: Theme.highlightColor
                wrapMode: Text.Wrap
                font.pixelSize: Theme.fontSizeSmall
            }

            Label {
                x: Theme.horizontalPageMargin
                width: parent.width - 2 * Theme.horizontalPageMargin
                text: qsTr("改动会写入 ~/.config/fontconfig/fonts.conf 并替换 Sailfish UI 使用的 "
                           "「Sail Sans Pro Light」，重启主屏幕后生效。只影响本用户，不修改系统文件。")
                color: Theme.secondaryColor
                wrapMode: Text.Wrap
                font.pixelSize: Theme.fontSizeExtraSmall
            }
        }

        VerticalScrollDecorator {}
    }

    RemorsePopup {
        id: remorse
    }
}
