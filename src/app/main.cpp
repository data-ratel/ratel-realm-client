#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QDebug>

#include <util_misc.h>
#include <native_event_filter.h>

int main(int argc, char *argv[])
{
    qputenv("QT_SCALE_FACTOR", "1.25");
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
//    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject *toplevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(toplevel);
    if (window == Q_NULLPTR) {
        qWarning("error: root item has window.");
        return -1;
    }


    NativeEventFilter nef;
    qApp->installNativeEventFilter(&nef);
    Util::Misc::enableWindowBorderless(window->winId());

    return app.exec();
}
