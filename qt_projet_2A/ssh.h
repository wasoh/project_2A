#include <libssh/libssh.h>
#include <string>
#include <QApplication>
#include <iostream>
#include <QDebug>
using namespace std;

class Ssh{
private:
    ssh_session session;
    char* hostname;
    char* user;
    char* password;
    int port;

public:
    Ssh(char*,char*,char*,int);
    void Ssh_Connexion();
    void Ssh_Identification();
    void Ssh_Lancer(char*);
    void Ssh_Terminer();
};
