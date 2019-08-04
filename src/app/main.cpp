#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QDebug>
#include <util_misc.h>
#include <qml_backend_engine.h>

void runQmlEngine();

int main(int argc, char *argv[])
{
    Util::Misc::enableHighDpiSupport();

    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);

    QGuiApplication app(argc, argv);

    runQmlEngine();

    return app.exec();
}

void runQmlEngine()
{
    qmlRegisterType<QmlBackendEngine>("io.rateldata.qmlbe", 1, 0, "QmlBackendEngine");

    auto qmlAppEngine = new QQmlApplicationEngine();
    qmlAppEngine->load(QUrl(QStringLiteral("qrc:/ui/main.qml")));
    if (qmlAppEngine->rootObjects().isEmpty())
        return;
}
