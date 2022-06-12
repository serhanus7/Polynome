#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "prototypes.h"

/************insert function*************/

mono* insert(int vcoef, int vexp, mono* poly){
    mono* elem,*precedent,*result=poly;
    elem=(mono*)malloc(sizeof(mono));
    elem->coef=vcoef;
    elem->exp=vexp;
    elem->next=NULL;
    
    if(!poly) return elem;
    if(poly->exp < vexp){
            elem->next=poly;
            return elem;
    }else{
            while(poly && poly->exp>vexp){
                precedent=poly;
                poly=poly->next;
            }
            if(poly->exp=vexp){
                poly->coef=vcoef;
            }else{
            precedent->next=elem;
            elem->next=poly;
            }
            return result;
    } 
    
}

/*******************putOut function********************/

void putOut(mono* poly){
    printf("P(X) = ");
    while(poly){
        printf("%i",poly->coef);
        printf("X^%i ",poly->exp);
        if(poly->next) printf("+ ");
        poly=poly->next;
    }
    printf("\n");
}

/********************calcul function***********************/

float calc( mono* poly,int x){
    float result=0,y;
    while(poly){
        x=pow(x,poly->exp);
        result+=(float)(poly->coef*y);
        poly=poly->next;
    } 
    return result;
}

/**********************delete function**********************/

void Delete(mono** poly, int vcoef, int vexp){
    mono* temp,*prec,*index;
    if((*poly)->exp=vexp && (*poly)->exp==vexp){
        temp= *poly;
        *poly=(*poly)->next;
    }else{
        index=*poly;
        while(index && (index->exp || index->coef)){
            prec=index;
            index=index->next;
        }
        if(!index) printf("No element to delete !\n");
        else{
            prec->next=index;
            free(index);
        }
    }
}

/*********************add function**************************/

mono* add(mono* poly1, mono* poly2){
    mono* result;
    while(poly1) result=insert(poly1->coef,poly1->exp,poly1);
    
    while(poly2){
        while(result){
            if(poly1->exp==result->exp){
                result->coef+=poly2->exp;
                break;
            }else result=insert(poly2->coef,poly2->exp,poly2);
            result=result->next;
        }
        poly2=poly2->next;
    }
    return result;
}







