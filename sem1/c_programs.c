// C program to write struct to text file and read and update it
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct example{
    char name[20];
    int age;
};


struct example fill_struct(struct example e){
    printf("Enter name: ");
    scanf("%s", e.name);
    printf("Enter age: ");
    scanf("%d", &e.age);
    return e;
}

int main(){
    FILE  *fp;
    fp = fopen("example.txt", "r");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    struct example reads[2];
    for(int i = 0; i < 2; i++){
        fscanf(fp, "\n%s %d", reads[i].name, &reads[i].age);
        printf("%s %d\n", reads[i].name, reads[i].age);
    }
    fclose(fp);

    int which_index;
    printf("Which record to edit bro?:");
    scanf("%d", &which_index);

    struct example structToEdit = reads[which_index];
    structToEdit = fill_struct(structToEdit);

    reads[which_index] = structToEdit;

    fp = fopen("example.txt", "w");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    for(int i = 0; i < 2; i++){
        fprintf(fp, "\n%s %d", reads[i].name, reads[i].age);
        printf("%s %d\n", reads[i].name, reads[i].age);
    }
    fclose(fp);

    return 0;
}