#include <stdio.h>
#include "function.h"



int main() {
    printf("\t\t\tBegin executing lab:\t\t\t");
    printf("How many patient do you want to add?");
    unsigned int n_pat; // количество пациентов
    scanf("%d", &n_pat);
    SPerson patient[n_pat];
    int n;
    printf("How would you like to add a patient?(1 - console, 2 - FILE)");
    do{
    scanf("%i", &n);
    }
    while(n > 2 || n < 1);

    FILE *InStream=fopen("person.txt","r");
    //FILE *OutStream=fopen("person.bin","wb");

    switch(n){
        case 1 : PersonCreate(patient, n_pat);
        case 2 : PersonCreateFile(patient, n_pat, InStream);
    }

    printf("Initializing a list of patients: ...");
    struct list *root= NULL, *last = NULL;
    init(root, patient);
    last = root;
    printf("Adding patients into list:...");
    struct list *temp = NULL, *p= NULL;
    addelem(last, patient, temp, p);
    listprint(last, n_pat);

    return 0;
}
