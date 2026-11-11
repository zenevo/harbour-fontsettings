import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground {
    Column {
        anchors.centerIn: parent
        spacing: Theme.paddingMedium

        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            source: "image://theme/icon-m-font-size"
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("字体设置")
        }
    }
}
