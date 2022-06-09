import QtQuick 2.15
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Window 2.14

//import com.myself.qml 1.0


ApplicationWindow {

  width: 640
  height: 480
  visible: true
  title: qsTr("Font manager")
  color: "#F96F51"
  font: fontManager.applicationFont
  Item {
    anchors.fill: parent

    ColumnLayout {

      anchors.centerIn: parent

      Item { Layout.fillHeight: true }

      RowLayout {
        Label {
          text: "Sample text: 直直直"
        }
        Item { Layout.fillWidth: true }
      }

      RowLayout {
        Label { text: "Font family: " }
        Label {
          id: fontFamilyLabel
          text: fontManager.fontFamilyName
        }
        Item { Layout.fillWidth: true }
      }

      RowLayout {
        Item { Layout.fillWidth: true }
        Button {
          text: "Japanese font"
          onClicked: fontManager.setAppFontForWritingSystem("Japanese")
        }
        Button {
          text: "System's font"
          onClicked: fontManager.setAppFontForWritingSystem("Default")
        }
        Item { Layout.fillWidth: true }
      }

      Item { Layout.fillHeight: true }

    }

  }

}
