import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import QtQuick.XmlListModel 2.0

ColumnLayout{
    function lol(){
    xmlModel.xml=backEnd.getContacts();
    }



    XmlListModel {
        id: xmlModel
        query: "/root/item"

        XmlRole { name: "name"; query: "name/string()" }
        XmlRole { name: "number"; query: "number/string()" }
    }

    ListView {
        Layout.fillWidth: true
        Layout.fillHeight: true
        spacing: 10
        boundsBehavior: Flickable.StopAtBounds

        model: xmlModel

        delegate: RowLayout {
        anchors.left: parent.left
        anchors.right: parent.right
        Text{
            Layout.fillWidth: true
            text: model.name
        }
        Button{
            text: model.number
            width: 250
            onClicked: Qt.openUrlExternally("tel:"+model.phone)
        }
        }


    }


    Button{
        text: "Get contacts list"
        Layout.fillWidth: true
        height: 100
        onClicked: lol();
    }

}
