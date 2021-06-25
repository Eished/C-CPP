#include "hello.h"

hello::hello(QObject *parent) : QObject(parent)
{
    QDebug<<"hello";
}
