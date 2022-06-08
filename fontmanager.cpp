#include "fontmanager.h"

#include <QFont>
#include <QGuiApplication>
//#include <QApplication>
#include <QDebug>


Q_INVOKABLE void FontManager::setAppFontForWritingSystem(const QString &writingSystem) {
  if (writingSystem == "Japanese")
    setAppFontForWritingSystem0(QFontDatabase::Japanese);
  else if (writingSystem == "Default")
    setAppFontForWritingSystem0(QFontDatabase::Any);
  else
    qDebug() << "ERROR UNKNOWN WRITING SYSTEM!";
}

void FontManager::setAppFontForWritingSystem0(QFontDatabase::WritingSystem writingSystem) {
  QFont systemFont = QFontDatabase::systemFont(QFontDatabase::GeneralFont);
  qDebug() << systemFont.family() << "**********************";
  QFontDatabase fontDB;
  auto families = fontDB.families(writingSystem);
//  if (!families.contains(systemFont.family())) {
    qDebug() << families;
    auto family = families[1];
    qDebug() << family;
    QFont font  = QFont(family);

    QGuiApplication::setFont(font);
    emit applicationFontChanged();
    //    qApp->setFont(font);
//  }
}

QFont FontManager::applicationFont() {
  return QGuiApplication::font();
}
