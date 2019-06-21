import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import "components"

Window {
    id: main_window

    flags: Qt.FramelessWindowHint | Qt.Window

    visible: true
    width: 1200
    height: 700
    minimumWidth: 1200
    minimumHeight: 700
    title: qsTr("Ratel Realm")
    color: "#00000000" // transparent window

    Rectangle {
        id: window_content
        anchors.fill: parent
        anchors {
            margins: {10, 10, 10, 10}
        }

        color: "#FFFFFF"
        radius: 4

        TitleBar {
            id: title_bar
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            radius: parent.radius

            height: 40
        }
    }

    DropShadow {
        anchors.fill: window_content
        radius: 10
        samples: 10
        source: window_content
        color: "black"
    }
}
