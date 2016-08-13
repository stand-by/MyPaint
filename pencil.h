#ifndef PENCIL_H
#define PENCIL_H

#include <QObject>

class Pencil : public QObject
{
    Q_OBJECT
public:
    explicit Pencil(QObject *parent = 0);

signals:

public slots:
};

#endif // PENCIL_H
