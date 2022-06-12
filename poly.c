#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct elemt {
    int coef,exp;
    struct elemt *suiv;
}mono;
/***************************************************/
void afficher(mono* poly){
    printf("P(X) = ");
    while(poly){
        printf("%i",poly->coef);
        printf("X^%i ",poly->exp);
        if(poly->suiv) printf("+ ");
        poly=poly->suiv;
    }
    printf("\n\n");
}
/***********************************************/
void creer(mono** poly){
     *poly=NULL;
     mono* element;
     char test='o';
     int c,e;
     //while(printf("ajouter un element (o/n)?"),scanf("%c",&test),test='o'){
                           printf("****************Initialisation**********\n");
                           element=(mono*)malloc(sizeof(mono));
                           printf("Donnez le coef et l'exp \n");
                           scanf("%d%d",&c,&e);
                           element->coef=c;
                           element->exp=e;
                           element->suiv=NULL;
                           (*poly)=element;
     //}
     
     
}
/************insert function*************/

mono* inserer(int vcoef, int vexp, mono* poly){
    mono* elem,*precedent,*result=poly,*test=poly;
    elem=(mono*)malloc(sizeof(mono));
    elem->coef=vcoef;
    elem->exp=vexp;
    elem->suiv=NULL;
    
    if(!poly) return elem;
    if(poly->exp < vexp){
            elem->suiv=poly;
            printf("\n");
            return elem;
    }else{
            while(poly && poly->exp>vexp){
                precedent=poly;
                poly=poly->suiv;
            }
            if(poly==NULL)
            {
             precedent->suiv=elem;
            }else
            {
            if(poly->exp==vexp){
                poly->coef+=vcoef; 
            }else{
            precedent->suiv=elem;
            elem->suiv=poly;
            }
            }    
            printf("\n");          
            return result;
    } 
    
}
/*****************fonction de clcule*******************/
float calc( mono* poly,int x){
    float result=0,y;
    while(poly){
        y=pow(x,poly->exp);
        result+=(float)(poly->coef*y);
        poly=poly->suiv;
    } 
    printf("\n");
    return result;
}
/*******************************************/
void supprimer(mono** poly, int vcoef, int vexp){
    mono* temp,*prec,*parcours;
    if(!(*poly)) printf("Le polynome est vide \n");
    else{
         if((*poly)->exp==vexp && (*poly)->coef==vcoef){
        temp= *poly;
        *poly=(*poly)->suiv;
        free(temp);
    }else{
        parcours=*poly;
        while(parcours && (parcours->exp!=vexp || parcours->coef!=vcoef)){
            prec=parcours;
            parcours=parcours->suiv;
        }
        if(!parcours) printf("No element to delete !\n");
        else{
            prec->suiv=parcours->suiv;
            free(parcours);
        }
    }     
    }
    printf("\n");
}
/*******************som function**********************/
mono* ajouter(mono* poly1, mono* poly2){
    mono* result=NULL;
    while(poly1) {
                 result=inserer(poly1->coef,poly1->exp,result);
                 poly1=poly1->suiv;
                 }
    afficher(result);
    while(poly2){
        result=inserer(poly2->coef,poly2->exp,result);
        poly2=poly2->suiv;
    }
    printf("\n");
    return result;
}
/***************fonction de vidage*********************/
void vider(mono* poly){
     mono* temp;
     while(poly){
                 temp=poly;
                 poly=poly->suiv;
                 free(temp);
     }
}
/********************fonction main********************/
int main(){
    /*mono* polynome1=NULL;
    mono* polynome2=NULL;*/
    mono* som=NULL; 
    char test='o';
    mono* polynome=NULL;
    mono* polynome2=NULL; 
    int option=0,e,c,x;  
    //creer(&polynome);
    //afficher(polynome);
    system("color 0a");
    /*polynome1=inserer(5,3,polynome1);
    polynome1=inserer(2,2,polynome1);
    polynome1=inserer(3,4,polynome1);
    polynome2=inserer(7,3,polynome2);
    polynome2=inserer(6,6,polynome2);
    polynome2=inserer(8,9,polynome2);
    afficher(polynome1);
    afficher(polynome2);
    som=ajouter(polynome1,polynome2);
    afficher(som);
    supprimer(&som,8,9);
    afficher(som);
    //afficher(polynome);
    printf("som(2)=%.2f\n",calc(som,2));*/
    
    do{
    //do{
        printf("/*******************************/\n");
        printf("1 - Inserer un monome.\n");
        printf("2 - Afficher le polynome.\n");
        printf("3 - Calculer P(X).\n");
        printf("4 - Supprimer un monome.\n");
        printf("5 - Calculer la somme de deux polynome.\n");
        printf("6 - Quiter.\n");
        printf("/*******************************/\n\n");
        scanf("%i",&option);
    //}while(option!=1 ||option!=2 ||option!=3 ||option!=4 ||option!=5);
    
    switch(option){
            case 1 :
                //system("color ed");
                printf("Donner coef et exp :\n");
                scanf("%i%i",&c,&e); 
                polynome=inserer(c,e,polynome);
                break;
            case 2 :
                //system("color b9");
                afficher(polynome);
                break;
            case 3 :
                 //system("color f0");
                printf("Donner la valeur de X :\n");
                scanf("%i",&x);
                printf("Le resultat : P(%i)=%.2f\n",x,calc(polynome,x));
                break;
            case 5:
                printf("Remplir le deusieme polynome\n");
                while(test!='n'){
                printf("Donner coef et exp :\n");
                scanf("%i%i",&c,&e); 
                polynome2=inserer(c,e,polynome2);
                printf("Voulez vous ajouter un autre monome (o/n)\n");
                fflush(stdin);
                scanf("%c",&test);
                }
                som=ajouter(polynome,polynome2);
                afficher(som);
                vider(polynome2);
                vider(som); 
                break;
            case 6 :
                //system("color 57");
                printf("donner le coef et le exp de le element a supprimer :\n");
                scanf("%i%i",&c,&e);
                supprimer(&polynome,c,e);
                break;
    }
    }while(option!=6);
   
    system("pause");
    return 0;  
}





