/*
==========================================
Name: Anurag Prashant Umale              =   
Student Id: 1887255                      =
E-mail: aumale@ucsc.edu                  =
File: Lex.c                              =
Class: CSE 101 Spring 2023               =
==========================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

#define MAX_LEN 1024

int count = 0;

void list_manipulation(char text[count][MAX_LEN],FILE *out){
    List new_list = newList();
    int idx = 0;
    prepend(new_list, idx);
    for (idx = 1; idx < count; idx++)
    {
        for (moveFront(new_list); index(new_list) >= 0; moveNext(new_list))
        {
            if (strcmp(&text[idx][0], &text[get(new_list)][0]) < 0)
            {
                insertBefore(new_list, idx);
                break;
            }
        }

        if (index(new_list) < 0)
        {
            append(new_list, idx);
        }
    }

    for (moveFront(new_list);index(new_list) >= 0; moveNext(new_list))
    {
        fprintf(out, "%s", text[get(new_list)]);
    }

    freeList(&new_list);
}

void cleanup(FILE *in, FILE *out){
    fclose(in);
    fclose(out);
}

int main(int argc, char const *argv[])
{
    
    char line[MAX_LEN];
    FILE *in = stdin;
    FILE *out = stdout;

    if (argc != 3)
    {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    if (in == NULL)
    {
        printf("Error: Unable to open file %s for reading or the file is not in the directory\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (out == NULL)
    {
        printf("Error: Unable to open file %s for writing  or the file is not in the directory\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LEN, in) != NULL)
    {
        count++;
    }
    if (count < 1)
    {
        printf("Error: Empty Flile");
        exit(EXIT_FAILURE);
    }

    

    fseek(in, 0, SEEK_SET);
    char text[count][MAX_LEN];
    int q = 0;
    while (fgets(line, MAX_LEN, in) != NULL)
    {
        strcat(line, "\0");
        strcpy(text[q], line);
        q++;
    }
    list_manipulation(text,out);
    cleanup(in,out);
    
    return EXIT_SUCCESS;
}
