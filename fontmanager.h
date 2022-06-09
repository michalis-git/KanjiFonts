#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <QFontDatabase>
#include <QObject>

class FontManager : public QObject
{
  Q_OBJECT
      QString m_fontFamilyName;
public:
  Q_PROPERTY(QFont applicationFont  READ applicationFont()  NOTIFY applicationFontChanged)
  Q_PROPERTY(QString fontFamilyName  READ fontFamilyName()  NOTIFY applicationFontChanged)

  explicit FontManager(QObject *parent = 0);;
  Q_INVOKABLE void setAppFontForWritingSystem(const QString &writingSystem);
  void setAppFontForWritingSystem0(QFontDatabase::WritingSystem writingSystem);

  QFont applicationFont();
  QString fontFamilyName();

signals:
  void applicationFontChanged();
  void fontFamilyNameChanged();
};

#endif // FONTMANAGER_H
