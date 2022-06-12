typedef struct elemt {
    int coef,exp;
    struct elemt *next;
}mono;

mono* insert(int, int, mono*);
void putOut(mono*);
float calc( mono*, int);
void Delete(mono**, int, int);
mono* add(mono*, mono*);
