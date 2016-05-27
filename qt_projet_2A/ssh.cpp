#include "ssh.h"

ssh_session session;
char* hostname;
char* password;
char* user;
int port;

Ssh::Ssh(char* hostname, char* user, char* password, int port){
    this->hostname = hostname;
    this->user = user;
    this->password = password;
    this->port = port;
    this->session = NULL;
}

void Ssh::Ssh_Connexion(){
    bool test;

    this->session = ssh_new();

    if(this->session == NULL){
        qDebug("Problème d'instanciation de session");
        exit(-1);
    }

    // options de conenxion
    ssh_options_set(this->session, SSH_OPTIONS_HOST, this->hostname);
    ssh_options_set(this->session, SSH_OPTIONS_PORT, &port);
    ssh_options_set(this->session, SSH_OPTIONS_USER, this->user);

    test = ssh_connect(this->session);
    if(test != SSH_OK){
        qDebug("Erreur lors de la connexion");
        exit(-1);
    }

    qDebug("Succès de la connexion");
}

void Ssh::Ssh_Identification(){
    bool test;

    test = ssh_userauth_password(this->session, NULL, password);
    if(test != SSH_AUTH_SUCCESS){
        qDebug("Erreur d'identification");
        ssh_disconnect((this->session));
        ssh_free(this->session);
        exit(-1);
    }

    qDebug("Succès de l'identification");
}

// Permet de fermer les connexions et libére la mémoire
void Ssh::Ssh_Terminer(){
    ssh_disconnect(this->session);
    ssh_free(this->session);
    qDebug("Fin de la connexion ssh");
}
