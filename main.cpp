#include "casino.h"
#include <vector>
#include <map>
#include <iostream>
#define MIN 1
#define MAX 99999
using namespace std;
void verif_entier(int& mavariable){
            while(isdigit(mavariable)==false){
                cout<<"Desole veuillez reessayez car l insertion doit etre un nombre entier:"<<endl;
                cin>>mavariable;
            }
}
int main()
{
    //casino *kanty= new casino();
    //kanty->menu();
    //bool arret=kanty->confirmation();
    //kanty->boucle_pari(arret);

int x,n;
printf("Vous allez creer une nouvelle configuration\n" );
printf("Saisissez le nombre de tirages auxquels vous voulez proceder compris entre [%d] et [%d] : ",MIN,MAX);
x=scanf("%d",&n);
while ((x!=1)||(n<MIN)||(n>MAX))
{
 if (x!=1)
 	printf("Taper un chiffre : " );
 else
 	printf("Chiffre compris entre [%d] et [%d] : ",MIN,MAX);
 if (n!='\n')
 	while (getchar()!='\n');
 x=scanf("%d",&n);
 if ((n>MAX)&&(n<MIN))
 {
 	printf("Entrer un chiffre compris entre [%d] et [%d]\n",MIN,MAX);
 	printf("Retapper le nombre de tirages : " );
 }
}
}
