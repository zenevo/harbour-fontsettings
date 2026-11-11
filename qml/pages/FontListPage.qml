import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    // "primary" | "heading" | "mono" | "fallback"
    property string mode: "primary"
    property string filter: ""
    property var allFamilies: backend.families

    onModeChanged: filter = ""

    SilicaListView {
        id: listView

        anchors.fill: parent
        model: {
            var out = []
            for (var i = 0; i < page.allFamilies.length; ++i) {
                var f = page.allFamilies[i]
                if (page.filter.length === 0 || f.toLowerCase().indexOf(page.filter) >= 0) {
                    out.push(f)
                }
            }
            return out
        }

        header: Column {
            width: listView.width

            PageHeader {
                title: page.mode === "fallback" ? qsTr("添加回退字体")
                     : page.mode === "mono"     ? qsTr("等宽字体")
                     : page.mode === "heading"  ? qsTr("标题字体")
                     : qsTr("正文字体")
            }

            SearchField {
                id: search

                width: parent.width
                placeholderText: qsTr("搜索字体")
                onTextChanged: page.filter = text.toLowerCase()
            }
        }

        delegate: ListItem {
            id: item

            contentHeight: Theme.itemSizeLarge

            Column {
                x: Theme.horizontalPageMargin
                y: Theme.paddingMedium
                width: parent.width - 2 * Theme.horizontalPageMargin
                spacing: Theme.paddingSmall

                Label {
                    width: parent.width
                    text: modelData
                    font.family: modelData
                    truncationMode: TruncationMode.Fade
                }

                Label {
                    text: qsTr("Aa 你好 123 ！")
                    font.family: modelData
                    font.pixelSize: Theme.fontSizeSmall
                    color: Theme.secondaryColor
                }
            }

            onClicked: {
                if (page.mode === "primary") {
                    backend.primary = modelData
                } else if (page.mode === "heading") {
                    backend.heading = modelData
                } else if (page.mode === "mono") {
                    backend.mono = modelData
                } else {
                    backend.addFallback(modelData)
                }
                pageStack.pop()
            }
        }

        ViewPlaceholder {
            enabled: listView.count === 0
            text: qsTr("没有匹配的字体")
        }

        VerticalScrollDecorator {}
    }
}
