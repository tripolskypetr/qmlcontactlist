#include <QtWidgets/QApplication>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlContext>

#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    QQuickView viewer;
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);

    BackEnd backend;

    viewer.rootContext()->setContextProperty("backEnd", &backend);

    QObject::connect(viewer.engine(), &QQmlEngine::quit, &viewer, &QWindow::close);
    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();
    return app.exec();
}
