#include <iostream>
#include <math.h>
#include <complex>
#include <string>
#include <stdlib.h>//pour faire le random
using namespace std;
//fichier header pour la creation des foonctions,..etc

#ifndef DEF_casino
#define DEF_casino
class casino
{
    public:
    //constructeur de la classe casino avec une valeur par defaut du variable nom_casino qui est My casino
    casino() : nom_casino("My casino"){
        this->nom_casino= nom_casino;
        cout<<"Quel est votre nom?"<<endl;
        cin>> nom_invite;//ma variable nom_invite du nom de l invite
        this->nom_invite = nom_invite;
        cout<<"Veuillez choisir votre nombre de 1 a 10:"<<endl;
        cin>> nb_choisi;//ma variable nb_choisi du nombre choisi
        this->nb_choisi = nb_choisi;
        cout<<"Votre argent de debut:"<<endl;
        cin>> total;//ma variable total de l'argent total de l'invite
        this->total = total;//pointeur pour utiliser l'argent total
        cout<<"Placez la mise:"<<endl;
        cin>> mise;//ma variable mise pour la mise a placer
        this->mise = mise;//pointeur pour la mise
        this->chance=0;
    }
    //un destructeur de la classe casino
    ~casino(){
        cout<<"La classe casino est detruite"<<endl;
    }
    void changer_mise(){
        cout<<"Entrez votre mise:"<<endl;
        cin>>mise;
        this->mise = mise;
    }
    void changer_nombre(){
        cout<<"Entrez le nombre que vous voulez:"<<endl;
        cin>>nb_choisi;
        this->nb_choisi = nb_choisi;
    }
    void presentation(){
        cout<<this->nom_casino<<"  vous souhaite le bienvenue  "<<this->nom_invite<<endl;
    }
//fonction pour afficher les variables creer dans la classe
    void affichervariable(){
        cout<<"Vous vous appellez:"<<this->nom_invite<<endl;
        cout<<"Le nombre que vous avez choisi est: "<<this->nb_choisi<<endl;
        cout<<"Votre argent est: "<<this->total<<endl;
        cout<<"Votre mise est: "<<this->mise<<endl;
    }
//fonction pour comparer deux nombre et retourne un boolean
    bool comparaison(int& nb_1,int& nb_2){
        if(nb_1==nb_2){
            return true;
        }
        else{
            return false;
        }
    }
//fonction de reponse par oui ou non et retourne un boolean
    bool confirmation(){
        string choix;
        cout<<"Voulez-vous continuer (Y/N)"<<endl;
        cin>>choix;
        if(choix=="Y" or choix=="O"){
            return true;
        }

        else{
            cout<<"Au revoir!!"<<endl;
            return false;
        }
    }
//fonction pour les operations
    void pari(){
        chance=rand() % 10 + 1;
        this->chance = chance;
        bool meme_chiffre= comparaison(this->nb_choisi,this->chance);
        total = total-mise;
        if(meme_chiffre==true){
            cout<<"Vous avez gagnez!! Felicitations"<<endl;
            mise=mise*10;
            this->mise = mise;
            total = total+this->mise;
            this->total = total;
        }
        else{
            cout<<"Vous avez perdu!! aboule le fric"<<endl;
        }
    }
    void boucle_pari(bool& arret){
        system("pause");//mettre en pause la console cmd sur windows
        system("cls");//effacer la console cmd du windows
        while(arret==true){
            menu();
            bool arret=confirmation();// variable booleen pour savoir la confirmation du joueur
        }
    }
    void menu(){
        int menu;
            cout<<"1-Voir les infos"<<endl;
            cout<<"2-Pour commencer le pari"<<endl;
            cout<<"3-Changer la mise"<<endl;
            cout<<"4-Changer de nombre"<<endl;
            cin>>menu;
            switch(menu){
                case 1:
                    affichervariable();
                    break;
                case 2:
                    if(this->total>=0){
                        pari();
                    }
                    else{
                        cout<<"Vous n avez plus d argent au revoir revenez quand vous en avez!!"<<endl;
                    }
                    break;
                case 3:
                    changer_mise();
                    break;
                case 4:
                    changer_nombre();
                    break;
                default:
                    cout<<"Veuillez choisir une reponse valide!!"<<endl;
                    break;
            }
    }
    //private:
    string nom_casino;//variable qui caracterise le nom du casino par defaut c est My casino
    string nom_invite;//variable qui caracterise le nom du joueur
    float total;//dans le cas ou le joueur a de l'argent depuis le debut
    float mise;//variable mise qui caracterise la mise du joueur
    int nb_choisi;//variable qui caracterise le nombre choisi par le joueur
    int chance;//variable qui caracterise le nombre obtenu de la roulette 1-10
};

#endif // casino
