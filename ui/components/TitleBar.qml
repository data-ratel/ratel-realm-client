import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Rectangle {
    id: title_bar
    width: 500
    height: 40
    color: "#F2F6FC"
    border.width: 0

    MouseArea {
        id: ma
        anchors.fill: parent
        property variant pt_pressed: Qt.point(0, 0)
        property bool mouse_double_clicked: false
        onPressed: {
            pt_pressed.x = mouseX
            pt_pressed.y = mouseY
        }
        onReleased: {
            mouse_double_clicked = false
        }

        onPositionChanged: {
            if (main_window.visibility !== Window.Windowed ||
                mouse_double_clicked) {
                return
            }

            main_window.x += mouseX - pt_pressed.x
            main_window.y += mouseY - pt_pressed.y
        }

        onDoubleClicked: {
            main_window.visibility = main_window.visibility === Window.Maximized ?
                           Window.AutomaticVisibility : Window.Maximized
            mouse_double_clicked = true
        }
    }

    Row {
        id: row_title_bar_buttons
        layoutDirection: Qt.RightToLeft
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        IconButton {
            id: btn_close
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 4
            anchors.top: parent.top
            anchors.topMargin: 4
            bk_img_normal: "qrc:/res/title_button_win/close_normal.png";
            bk_img_hover: "qrc:/res/title_button_win/close_hover.png";
            bk_img_click: "qrc:/res/title_button_win/close_click.png";
            bk_img_disable: "qrc:/res/title_button_win/close_disable.png";

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    main_window.close()
                }
            }
        }

        IconButton {
            id: btn_max_restore
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 4
            anchors.top: parent.top
            anchors.topMargin: 4
            bk_img_normal: "qrc:/res/title_button_win/maximize_normal.png";
            bk_img_hover: "qrc:/res/title_button_win/maximize_hover.png";
            bk_img_click: "qrc:/res/title_button_win/maximize_click.png";
            bk_img_disable: "qrc:/res/title_button_win/maximize_disable.png";

            Connections {
                target: main_window
                onVisibilityChanged: {
                    var is_maximize = main_window.visibility === Window.Maximized

                    btn_max_restore.bk_img_normal = is_maximize ? "qrc:/res/title_button_win/restore_normal.png" :
                                                                  "qrc:/res/title_button_win/maximize_normal.png"
                    btn_max_restore.bk_img_hover = is_maximize ? "qrc:/res/title_button_win/restore_hover.png" :
                                                                 "qrc:/res/title_button_win/maximize_hover.png"
                    btn_max_restore.bk_img_click = is_maximize ? "qrc:/res/title_button_win/restore_click.png" :
                                                                 "qrc:/res/title_button_win/maximize_click.png"
                    btn_max_restore.bk_img_disable = is_maximize ? "qrc:/res/title_button_win/restore_disable.png" :
                                                                   "qrc:/res/title_button_win/maximize_disable.png"
                }
            }

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    var is_maximize = main_window.visibility === Window.Maximized
                    main_window.visibility = is_maximize ? Window.AutomaticVisibility : Window.Maximized
                }
            }
        }

        IconButton {
            id: btn_min
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 4
            anchors.top: parent.top
            anchors.topMargin: 4
            bk_img_normal: "qrc:/res/title_button_win/minimize_normal.png";
            bk_img_hover: "qrc:/res/title_button_win/minimize_hover.png";
            bk_img_click: "qrc:/res/title_button_win/minimize_click.png";
            bk_img_disable: "qrc:/res/title_button_win/minimize_disable.png";

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    main_window.visibility = Window.Minimized
                }
            }
        }
    }
}
