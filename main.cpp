#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "fontmanager.h"



int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  QGuiApplication app(argc, argv);


  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
      &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      }, Qt::QueuedConnection);
  FontManager* fontManager = new FontManager();
//  qmlRegisterType<FontManager>("com.myself.qml", 1, 0, "FontManager");
//  qmlRegisterUncreatableType<FontManager>("com.myself.qml", 1, 0, "FontManager", "Can't create");
//  engine.rootContext()->setContextProperty("defaultAppFont", defaultAppFont);
  engine.rootContext()->setContextProperty("fontManager", fontManager);

  engine.load(url);

  return app.exec();
}
