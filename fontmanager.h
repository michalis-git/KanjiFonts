#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <QFontDatabase>
#include <QObject>

class FontManager : public QObject
{
  Q_OBJECT
public:
  Q_PROPERTY(QFont applicationFont  READ applicationFont()  NOTIFY applicationFontChanged)

  explicit FontManager(QObject *parent = 0)
      : QObject(parent){};
  Q_INVOKABLE void setAppFontForWritingSystem(const QString &writingSystem);
  void setAppFontForWritingSystem0(QFontDatabase::WritingSystem writingSystem);

  QFont applicationFont();

signals:
  void applicationFontChanged();
};

#endif // FONTMANAGER_H
