import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import "components"

Window {
    id: main_window

    visible: true
    width: 1200
    height: 700
    minimumWidth: 1200
    minimumHeight: 700
    title: qsTr("Ratel Realm")
    color: "transparent" // transparent window

    Rectangle {
        id: window_content
        anchors.fill: parent

        color: "#FFFFFF"

        Rectangle {
            id: left_panel
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            width: 60
            color: "slategray"

            MouseArea {
                id: ma
                anchors.fill: parent
                property variant pt_pressed: Qt.point(0, 0)
                onPressed: {
                    pt_pressed.x = mouseX
                    pt_pressed.y = mouseY
                }

                onPositionChanged: {
                    if (main_window.visibility !== Window.Windowed) {
                        return
                    }

                    main_window.x += mouseX - pt_pressed.x
                    main_window.y += mouseY - pt_pressed.y
                }
            }
        }

        Rectangle {
            id: right_panel
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: left_panel.right
            anchors.right: parent.right

            TitleBar {
                id: title_bar
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.top: parent.top
                anchors.topMargin: 0

                height: 40
            }
        }
    }
}
