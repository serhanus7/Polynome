#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "functions.c"


int main(){
    int option=0,e,c,x;
    mono* polynome=NULL;
    do{
    do{
        printf("/*******************************/\n");
        printf("1 - Insert monome.\n");
        printf("2 - Put out the polynome.\n");
        printf("3 - Calcul P(X).\n");
        printf("4 - Delete monome.\n");
        printf("5 - Quit.\n");
        printf("/*******************************/\n");
        scanf("%i",&option);
    }while(option!=1 ||option!=2 ||option!=3 ||option!=4 ||option!=5);
    
    switch(option){
            case 1 :
                printf("Put coef and exp :\n");
                scanf("%i%i",&c,&e); 
                polynome=insert(c,e,polynome);
                break;
            case 2 :
                putOut(polynome);
                break;
            case 3 :
                printf("Put the X value :\n");
                scanf("%i",&x);
                printf("The result : P(%i)=%f",x,calc(polynome,x));
            case 4 :
                printf("Put coef and exp of:\n");
                scanf("%i%i",&c,&e);
                Delete(&polynome,c,e); 
    }
    }while(option!=5);
    return 0;
}








