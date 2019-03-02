//
// Created by Helen Stepaniuk on 2019-02-18.
//

//#include "function.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

void PersonCreate(SPerson *ptr, unsigned int N){
    for(int i = 0; i < N; i++)
    {
        char tmp[2];
        printf("Enter the name:");
        if(!fgets(ptr->name, 64, stdin))
        {
            return ;
        }
        printf("Enter the birthday:");
        if(!fgets(ptr->birthday,64, stdin))
        {
            return ;
        }
        printf("Enter when the illness beginning:");
        if(!fgets(ptr->illness_begin, 64, stdin))
        {
            return ;
        }
        printf("Enter the blood group:");
        if(!fgets(tmp, 2, stdin))
        {
            return ;
        }
        ptr->blood_group = atoi(tmp);
    }

}

void Display(SPerson *ptr, unsigned int N){
    printf("/t/tPatient:/t/t");
    printf("/nName:/tBirthday:/tBloodgroup/tIllness beginning:/t");
    printf("/n%s/t%s/t%i/t%s", ptr ->name, ptr->birthday, ptr->blood_group, ptr->illness_begin);
}
void PersonCreateFile(SPerson *ptr, unsigned int N, FILE *f){
    for(int i = 0; i < N; i++){
        char tmp[2];
        printf("Enter the name:");
        if(!fgets(ptr->name, 64, f))
        {
            return ;
        }
        printf("Enter the birthday:");
        if(!fgets(ptr->birthday, 64, f))
        {
            return ;
        }
        printf("Enter when the illness beginning:");
        if(!fgets(ptr->illness_begin, 64, f))
        {
            return ;
        }
        printf("Enter the blood group:");
        if(!fgets((tmp),  64, f))
        {
            return ;
        }
        ptr->blood_group = atoi(tmp);
    }
}

void init(struct list *lst ,SPerson *data){ // struct list *lst- последний элемент
    if(!data) return;
    if(!lst) return;
    lst = (struct list*)malloc(sizeof(*lst));
    lst->Pnext = NULL;
    lst->person = *data;
}

void addelem(struct list *lst, SPerson *data, struct list *temp, struct list *p){
    if(!lst) return;
    if(!data) return;
    if(!temp) return;
    if(!p) return;
   // p для сохранения указателя на следующий узел, temp для добавления нового елемента
    temp = (struct list*)malloc(sizeof(*lst));
    p = lst->Pnext;
    lst->Pnext = temp;
    temp->person = *data;
    temp->Pnext = p;
}

void deletelem(struct list *lst, struct list *root, struct list *temp)
{
    if(!lst) return;
    if(!root) return;
    if(!temp) return;
    temp = root;
    while (temp->Pnext != lst) // просматриваем список начиная с корня
    { // пока не найдем узел, предшествующий ptr
        temp = temp->Pnext;
    }
    temp->Pnext = lst->Pnext; // переставляем указатель
    free(lst); // освобождаем память удаляемого узла
}

void deletehead(struct list *root, struct list *temp)
{
   if(!root) return;
   if(!temp) return;
    temp = root->Pnext;
    free(root); // освобождение памяти текущего корня
}

void listprint(struct list *lst, unsigned int n_pers)
{
    struct list *p;
    p = lst;
    do {
        Display(&(p->person), n_pers);
        p = p->Pnext; // переход к следующему узлу
    }
    while (p != NULL);
}
