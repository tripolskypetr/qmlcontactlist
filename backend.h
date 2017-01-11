#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class BackEnd : public QObject
{
    Q_OBJECT
public:
BackEnd();

signals:

public slots:
QString getContacts();
};

#endif // BACKEND_H
