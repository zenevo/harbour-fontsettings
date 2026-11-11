#include <sailfishapp.h>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickView>
#include <QScopedPointer>
#include <QUrl>

#include "fontbackend.h"

int main(int argc, char *argv[])
{
    // Headless mode, useful over SSH and for testing without a display.
    if (argc > 1 && qstrcmp(argv[1], "--cli") == 0) {
        QCoreApplication app(argc, argv);
        FontBackend backend;
        return backend.runCli(app.arguments().mid(2));
    }

    QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
    QScopedPointer<QQuickView> view(SailfishApp::createView());

    FontBackend backend;
    view->rootContext()->setContextProperty("backend", &backend);

    view->setSource(SailfishApp::pathTo("qml/main.qml"));
    view->show();

    return app->exec();
}
