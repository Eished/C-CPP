#ifndef HELLO_H
#define HELLO_H

#include <QMainWindow>
#include <QObject>

class hello : public QObject
{
    Q_OBJECT
public:
    explicit hello(QObject *parent = nullptr);

signals:

};

#endif // HELLO_H
