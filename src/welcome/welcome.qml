import QtQuick 2.0

Item {
    id: element

    signal qmlSignal(msg: string);

    Column {
        id: column
        x: 0
        y: 0
        width: 640
        height: 480

        Text {
            id: element1
            text: qsTr("Welcome")
            anchors.horizontalCenter: parent.horizontalCenter
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 70
        }

        Column {
            id: column1
            width: 400
            height: 295
            anchors.horizontalCenter: parent.horizontalCenter

            Rectangle {
                id: newbackground
                width: 200
                height: 40
                color: "#aa55ff"
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    id: newtext
                    text: qsTr("New...")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 16
                }

                MouseArea {
                    id: newarea
                    y: 0
                    width: 200
                    height: 40
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            Rectangle {
                id: openbackground
                width: 200
                height: 40
                color: "#60ffe8"
                anchors.top: parent.top
                anchors.topMargin: 50
                anchors.horizontalCenter: newbackground.horizontalCenter

                Text {
                    id: opentext
                    text: qsTr("Open...")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 16
                }

                MouseArea {
                    id: openarea
                    y: 0
                    width: 200
                    height: 40
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            Rectangle {
                id: questionbackground
                width: 200
                height: 40
                color: "#caff4f"
                anchors.top: openbackground.bottom
                anchors.topMargin: 10
                anchors.horizontalCenter: openbackground.horizontalCenter

                Text {
                    id: questiontext
                    text: qsTr("Questions?")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 16
                }

                MouseArea {
                    id: questionarea
                    y: 0
                    width: 200
                    height: 40
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

            Rectangle {
                id: bugbackground
                width: 200
                height: 40
                color: "#aa0000"
                anchors.top: questionbackground.bottom
                anchors.topMargin: 10
                anchors.horizontalCenter: parent.horizontalCenter

                Text {
                    id: bugtext
                    text: qsTr("Found a bug?")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 16
                }

                MouseArea {
                    id: bugarea
                    y: 0
                    width: 200
                    height: 40
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
