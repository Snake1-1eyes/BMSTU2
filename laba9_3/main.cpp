
#include "calcdialog.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calcDialog * dialog = new calcDialog();

    dialog->show();
    return a.exec();
}
