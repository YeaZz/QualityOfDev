#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "data.h"

void Data::readList(const QString &filename)
{
    QString line;
    QFile myfile (filename+"sd");
    if (myfile.open(QIODevice::ReadOnly | QFile::Text))
    {
        QTextStream in(&myfile);
        in.readLine();
        in.readLine();
        in.readLine();
        in.readLine();
        in.readLine();

        QString id;
        int cl, ag, sx, sv;
        while (!in.atEnd())
        {
            in >> id;
            in >> cl;
            in >> ag;
            in >> sx;
            in >> sv;
            passengers.append(Passenger(id, cl, ag, sx, sv));
        }
        myfile.close();
    }

    else qDebug() << "Unable to open file" << filename << ": error" << myfile.error() << "," << myfile.errorString();
}
