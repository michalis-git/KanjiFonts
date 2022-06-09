#include "fontmanager.h"

#include <QFont>
#include <QGuiApplication>
//#include <QApplication>
#include <QDebug>


Q_INVOKABLE FontManager::FontManager(QObject *parent)
    : QObject(parent){
  QFont systemFont = QFontDatabase::systemFont(QFontDatabase::GeneralFont);
  m_fontFamilyName =  systemFont.family();
}

void FontManager::setAppFontForWritingSystem(const QString &writingSystem) {
  if (writingSystem == "Japanese")
    setAppFontForWritingSystem0(QFontDatabase::Japanese);
  else if (writingSystem == "Default")
    setAppFontForWritingSystem0(QFontDatabase::Any);
  else
    qDebug() << "ERROR UNKNOWN WRITING SYSTEM!";
}

void FontManager::setAppFontForWritingSystem0(QFontDatabase::WritingSystem writingSystem) {
  QFontDatabase fontDB;
  auto families = fontDB.families(writingSystem);

    qDebug() << families;
    auto family = families[1];
    qDebug() << family;
    QFont font  = QFont(family);

    QGuiApplication::setFont(font);

    m_fontFamilyName = font.family();
    emit applicationFontChanged();
}

QFont FontManager::applicationFont() {
  return QGuiApplication::font();
}

QString FontManager::fontFamilyName() {
  return m_fontFamilyName;
}
