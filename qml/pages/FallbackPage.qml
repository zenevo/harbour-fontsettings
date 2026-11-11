import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    SilicaListView {
        id: listView

        anchors.fill: parent
        model: backend.fallbacks

        header: Column {
            width: listView.width

            PageHeader {
                title: qsTr("回退字体")
            }

            Label {
                x: Theme.horizontalPageMargin
                width: parent.width - 2 * Theme.horizontalPageMargin
                text: qsTr("当前字体缺少某个字符时，会按这里的顺序依次尝试。建议保留一个中文字体和一个 emoji 字体。")
                color: Theme.secondaryColor
                wrapMode: Text.Wrap
                font.pixelSize: Theme.fontSizeSmall
            }
        }

        delegate: ListItem {
            id: item

            contentHeight: Theme.itemSizeMedium
            menu: ContextMenu {
                MenuItem {
                    text: qsTr("上移")
                    enabled: index > 0
                    onClicked: backend.moveFallback(index, index - 1)
                }
                MenuItem {
                    text: qsTr("下移")
                    enabled: index < backend.fallbacks.length - 1
                    onClicked: backend.moveFallback(index, index + 1)
                }
                MenuItem {
                    text: qsTr("移除")
                    onClicked: backend.removeFallback(modelData)
                }
            }

            Label {
                x: Theme.horizontalPageMargin
                width: parent.width - 2 * Theme.horizontalPageMargin
                anchors.verticalCenter: parent.verticalCenter
                text: (index + 1) + ". " + modelData
                font.family: modelData
                truncationMode: TruncationMode.Fade
            }
        }

        footer: Column {
            width: listView.width
            spacing: Theme.paddingMedium

            Label {
                x: Theme.horizontalPageMargin
                width: parent.width - 2 * Theme.horizontalPageMargin
                text: qsTr("最后回退：%1（系统默认，固定保留）").arg(backend.defaultFamily)
                color: Theme.secondaryColor
                font.pixelSize: Theme.fontSizeExtraSmall
                wrapMode: Text.Wrap
                topPadding: Theme.paddingMedium
            }

            Button {
                id: addButton

                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("添加回退字体")
                onClicked: pageStack.push(Qt.resolvedUrl("FontListPage.qml"), { mode: "fallback" })
            }
        }

        ViewPlaceholder {
            enabled: listView.count === 0
            text: qsTr("还没有回退字体")
            hintText: qsTr("点下方按钮添加")
        }

        VerticalScrollDecorator {}
    }
}
