//
// Created by Helen Stepaniuk on 2019-02-18.
//
#include "./function.c"
#include "./struct.h"

    void PersonCreate(SPerson *ptr, unsigned int N);
    void Display(SPerson *ptr, unsigned int N);
    void PersonCreateFile(SPerson *ptr, unsigned int N, FILE *f);
    void ReadBin(SPerson *ptr, unsigned int N, FILE *f);
    void init(struct list *lst ,SPerson *data);
    void addelem(struct list *lst, SPerson *data, struct list *temp, struct list *p);
    void deletelem(struct list *lst, struct list *root, struct list *temp);
    void deletehead(struct list *root, struct list *temp);
    void listprint(struct list *ptr, unsigned int n_pers);
