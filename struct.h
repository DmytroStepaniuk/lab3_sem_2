//
// Created by Helen Stepaniuk on 2019-02-18.
//

#ifndef LAB3_STRUCT_H
#define LAB3_STRUCT_H

typedef struct Person{ /// структура для збереження даних про пацієнта
    char name[64]; ///ім'я пацієнта
    char birthday[8]; /// день народження пацієнта
    int blood_group; /// група крові
    char illness_begin[8]; /// дата початку хвороби
}SPerson;

 typedef struct list{
    SPerson person;
    struct list *Pnext;
}SList;


#endif //LAB3_STRUCT_H
