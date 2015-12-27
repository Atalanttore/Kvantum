#include "KvantumManager.h"
#include <QApplication>
#include <QStyleFactory>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication::setApplicationName ("KvantumManager");
    QApplication a (argc, argv);
#if QT_VERSION >= 0x050500
    a.setAttribute(Qt::AA_UseHighDpiPixmaps, true);
#endif
#if QT_VERSION >= 0x050000
    if (!QStyleFactory::keys().contains ("kvantum"))
#else
    if (!QStyleFactory::keys().contains ("Kvantum"))
#endif
    {
        QMessageBox msgBox (QMessageBox::Critical,
                            QObject::tr ("Kvantum"),
                            QObject::tr ("<center><b>Kvantum is not installed on your system.</b></center>"\
                                         "<p><center>Please first install the Kvantum style plugin!</center><p>"),
                            QMessageBox::Close);
        msgBox.exec();
        return 1;
    }
    KvantumManager km (NULL);
    km.show();

    return a.exec();
}
