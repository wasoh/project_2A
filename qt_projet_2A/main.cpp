#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //test();
    //Ssh connexion_ssh("192.168.62.103","robot","maker",22);
    //connexion_ssh.Ssh_Connexion();
    //connexion_ssh.Ssh_Identification();
    //connexion_ssh.Ssh_Terminer();
    return a.exec();
}
