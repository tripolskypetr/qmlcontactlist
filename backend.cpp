#include "backend.h"

//Для вызова нативного интерфейса
#include <QtAndroidExtras/QAndroidJniObject>
#include <QtAndroid>

//Отладка
#include <QDebug>

BackEnd::BackEnd()
{

}

QString BackEnd::getContacts(){
QAndroidJniObject str = QAndroidJniObject::callStaticObjectMethod("com/example/contacts/fetch/FetchClass", "getContacts", "(Landroid/content/Context;)Ljava/lang/String;", QtAndroid::androidActivity().object<jobject>());

qDebug() << "Value from java is " << str.toString();
return str.toString();
}
