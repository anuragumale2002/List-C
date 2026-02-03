/*
==========================================
Name: Anurag Prashant Umale              =   
Student Id: 1887255                      =
E-mail: aumale@ucsc.edu                  =
File: ListTest.c (Test for the  List ADT)=
Class: CSE 101 Spring 2023               =
==========================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

void test_constructor_destructor(){
    fprintf(stdout,"********************************************************\n");
    fprintf(stdout,"Testing Constructer\n");
    List list_a = newList();
    if(list_a != NULL){
        fprintf(stdout,"List was created successfully\n");
    }
    fprintf(stdout,"Constructor Test Completed!!!\n");
    fprintf(stdout,"Testing Destructor\n");
    freeList(&list_a);
    if(list_a == NULL){
        fprintf(stdout,"List was deleted successfully\n");
    }
    fprintf(stdout,"Destructor Test Completed!!!\n");
    fprintf(stdout,"********************************************************\n");
}

void test_functions(){
    fprintf(stdout,"********************************************************\n");
    fprintf(stdout,"Malipulation Functions Test\n");
    List list_1 = newList();
    List list_2 = newList();
    List list_3 = newList();
    List list_4 = newList();
    fprintf(stdout,"Testing append and prepend...\n");
    for(int i = 0; i < 20;i++){
        append(list_1,i);
        append(list_2,i);
        prepend(list_3,i);
        prepend(list_4,i);
    }
    if(equals(list_1,list_2) && equals(list_3,list_4)){
        fprintf(stdout,"Appended List 1: ");
        printList(stdout,list_1);
        fprintf(stdout,"\n");
        fprintf(stdout,"Prepended List 2: ");
        printList(stdout,list_3);
        fprintf(stdout,"\n");
        fprintf(stdout,"Lists are appeneded and prepended successfully\n");
        fprintf(stdout,"Append and Prepend Test Completed!!!\n");
    }
    else{
        fprintf(stdout,"Append and Perpend Test failed!!!\n");
    }
    fprintf(stdout,"Testing moveFront, moveNext,index and get functions\n");
    fprintf(stdout,"List 3: ");
    for (moveFront(list_4); index(list_4) >= 0; moveNext(list_4))
    {
        printf("%d ", get(list_4));
    }
    fprintf(stdout,"\n");
    fprintf(stdout,"List 4: ");
    for (moveBack(list_2); index(list_2) >= 0; movePrev(list_2))
    {
        printf("%d ", get(list_2));
    }
    fprintf(stdout,"\n");

    List list_5 = copyList(list_1);
    if(equals(list_5,list_1)){
        fprintf(stdout,"Copying List was successful\n");
        fprintf(stdout,"Copied List:");
        printList(stdout, list_5);
        fprintf(stdout,"\n");
    }
    else{
        fprintf(stdout,"failed copying the list\n");
    }
    moveFront(list_1);
    fprintf(stdout,"Testing insertBefore, insertAfter, and delete functions\n");
    for(int i=0; i<5; i++) moveNext(list_1); // at index 5
    insertBefore(list_1, -1);            // at index 6
    for(int i=0; i<9; i++) moveNext(list_1); // at index 15
    insertAfter(list_1, -2);
    for(int i=0; i<5; i++) movePrev(list_1); // at index 10
    delete(list_1);
    printList(stdout,list_1);
    fprintf(stdout,"\n");

    freeList(&list_1);
    freeList(&list_2);
    freeList(&list_3);
    freeList(&list_4);
    freeList(&list_5);
    fprintf(stdout,"********************************************************\n");
}


int main(void){
    test_constructor_destructor();
    fprintf(stdout,"\n\n");
    test_functions();
    return EXIT_SUCCESS;
}
