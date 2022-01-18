/* 3 Student strutcture records */
#include <stdio.h>
#include <stdlib.h>

#define N 4

struct student {
  char name[100];
  int rollno;
  int marks;
};

void add_record(struct student *records, int size) {
  // Fill a new struct and add that to records array
  int i = size;
  printf("Name, Roll, Marks: ");
  scanf("%s %d %d", records[i].name, &records[i].rollno, &records[i].marks);
}

void sort_records(struct student *records, int size){
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
    if(records[i].marks > records[j].marks){
      struct student temp = records[i];
      records[i] = records[j];
      records[j] = temp;
    }
  }
  }
}

int main(void) {
  struct student students[N];
  for (int i=0; i<N; i++){
    add_record(students, i);
  }

  sort_records(students, N);

  struct student highest = students[0], lowest = students[N-1];
  printf("The highest marks scorer:\n");
  printf("%s\t%d\t%d\n", highest.name, highest.rollno, highest.marks);
  printf("The lowest marks scorer:\n");
  printf("%s\t%d\t%d\n", lowest.name, lowest.rollno, lowest.marks);
  return 0;
}
