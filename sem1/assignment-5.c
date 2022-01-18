/* // 9 Centered 15 */
/* #include <stdio.h> */
/* #include <stdlib.h> */

/* int isCentered15(int *array, int size){ */
/*   for(int offset = 0; offset <= size/2; offset++){ */
/*     int sum = 0, i; */
/*     for (i=offset; i<size; i++){ */
/*       sum += array[i]; */
/*       if (sum == 15 && offset == (size-1-i)) */
/* 	return 1; */
/*     } */
/*   } */
/*   return 0; */
/* } */

/* int main(void){ */
/*   printf("Array size: "); */
/*   int size; */
/*   scanf("%d", &size); */
/*   int *array = malloc(size * sizeof(int)); */

/*   for(int i=0; i<size; i++){ */
/*     scanf("%d", &array[i]); */
/*   } */
/*   if (isCentered15(array, size)){ */
/*     puts("It is centered 15 array :)"); */
/*   }else{ */
/*     puts("It is not a centered 15 array :("); */
/*   } */

/*   free(array); */
/*   return 0; */
/* } */



/* // 10. perfect nums */
/* #include <stdio.h> */

/* int is_perfect_num(int num){ */
/*   int sum = 0; */
/*   for(int i=1; i<=num/2; i++) */
/*     if (num % i == 0) */
/*       sum += i; */
/*   return sum == num; */
/* } */

/* int next_perfect_num(int start){ */
/*   int next = start+1; */
/*   while(!is_perfect_num(next)) */
/*     next++; */
/*   return next; */
/* } */

/* int sum_of_perfectnum(int i, int j){ */
/*   int perfect_nums[1000]; */
/*   perfect_nums[0] = 6; */
/*   int num_size; */
  
/*   for(num_size = 1; num_size < i || num_size < j; num_size++)  */
/*     perfect_nums[num_size] = next_perfect_num(perfect_nums[num_size-1]); */
   
/*   return perfect_nums[i-1] + perfect_nums[j-1]; */
/* } */


/* int main(void){ */
/*   printf("%d\n", sum_of_perfectnum(2, 3)); */
/*   return 0; */
/* } */


/* // 8 Append two files to one */
/* #include <stdio.h> */
/* #include <stdlib.h> */
        
/* int write_contents_to_file(char* filename){ */
/*   size_t N = 10000; */
/*   char content[N]; */
/*   printf("Contents for %s file:\n", filename); */
/*   fgets(content, N, stdin); */

/*   FILE *infile = fopen(filename, "w"); */
/*   if (infile == NULL){ */
/*     printf("Failed opening %s file\n", filename); */
/*     return 0; */
/*   } */
 
/*   for (int i=0; content[i]!='\0'; i++) */
/*     fwrite(&content[i], sizeof(char), 1, infile); */

/*   printf("Written contents to %s file\n", filename); */
/*   fclose(infile); */
/*   return 1; */
/* } */

/* int append_files_to_file(char* tofile, char* file1, char* file2){ */
/*   FILE *first = fopen(file1, "r"); */
/*   if (first == NULL){ */
/*     printf("Failed opening %s file\n", file1); */
/*     return 0; */
/*   } */
    
/*   FILE *second = fopen(file2, "r"); */
/*   if (second == NULL){ */
/*     printf("Failed opening %s file\n", file2); */
/*     fclose(first); */
/*     return 0; */
/*   } */
 
/*   FILE *third = fopen(tofile, "w"); */
/*   if (third == NULL){ */
/*     printf("Failed opening %s file\n", tofile); */
/*     fclose(first); */
/*     fclose(second); */
/*     return 0; */
/*   } */

/*   while(1){ */
/*     char buf; */
/*     int read_status = fread(&buf, sizeof(char), 1, first); */
/*     if (read_status != 1){ */
/*       break; */
/*     } */
/*     fwrite(&buf, sizeof(char), 1, third); */
/*   } */
/*   fclose(first); */
 
/*   while(1){ */
/*     char buf; */
/*     int read_status = fread(&buf, sizeof(char), 1, second); */
/*     if (read_status != 1){ */
/*       break; */
/*     } */
/*     fwrite(&buf, sizeof(char), 1, third); */
/*   } */
/*   fclose(second); */
/*   fclose(third); */
/*   printf("Contents of first and second file written to third.txt\n"); */
/*   return 1; */
/* } */

/* int main(void){ */
/*   if (write_contents_to_file("first.txt") == 0) { */
/*     return 1; */
/*   } */

/*   if (write_contents_to_file("second.txt") == 0) { */
/*     return 1; */
/*   } */

/*   if (append_files_to_file("third.txt", "first.txt", "second.txt") == 0){ */
/*     return 1; */
/*   } */

/*   return 0; */
/* } */



// 7.Employee records
#include <stdio.h>
#include <stdlib.h>

struct Employee {
  char name[100];
  char addr[100];
  char post[100];
  int salary;
};

void input_to_records(FILE *file, int emp_no);
void read_from_records(FILE *file, struct Employee *records);
void sort_by_salary(struct Employee *employees, int emp_no);
void print_records(struct Employee *employees, int emp_no);

int main(void) {
  printf("How many employees? ");
  int emp_no;
  scanf("%d", &emp_no);

  FILE *file = fopen("employee.txt", "w");
  if (file == NULL) {
    printf("Cannot open file \n");
    return 1;
  }
  input_to_records(file, emp_no);
  fclose(file);

  file = fopen("employee.txt", "r");
  if (file == NULL) {
    printf("Cannot open file \n");
    return 1;
  }
  struct Employee employees[100];
  read_from_records(file, employees);
  fclose(file);

  sort_by_salary(employees, emp_no);
  print_records(employees, emp_no);
  return 0;
}

void input_to_records(FILE *file, int emp_no) {
  struct Employee employee;
  for (int i = 0; i < emp_no; i++) {
    printf("Enter details for employee no %d\n", i + 1);
    printf("Name Address Post Salary: ");
    scanf(" %s %s %s %d", employee.name, employee.addr,
          employee.post, &employee.salary);
    fwrite(&employee, sizeof(struct Employee), 1, file);
  }
}

void read_from_records(FILE *file, struct Employee *records) {
  int i = 0;
  while (1) {
    int read_status = fread(&records[i], sizeof(struct Employee), 1, file);
    if (read_status != 1)
      break;
    i++;
  }
}

void sort_by_salary(struct Employee *employees, int emp_no) {
  for (int i = 0; i < emp_no; i++) {
    for (int j = 0; j < emp_no; j++) {
      if (employees[i].salary < employees[j].salary) {
        struct Employee temp = employees[i];
        employees[i] = employees[j];
        employees[j] = temp;
      }
    }
  }
}

void print_records(struct Employee *employees, int emp_no) {
  for (int i = 0; i < emp_no; i++) {
    printf("%s\t%s\t%s\t%d\n", employees[i].name, employees[i].addr,
           employees[i].post, employees[i].salary);
  }
}





/* // 4 Odd even classifier */
/* #include <stdio.h> */
/* #include <stdlib.h> */

/* int input_nums_to_file(char *filename) { */
/*   FILE *numfile = fopen(filename, "w"); */
/*   if (numfile == NULL) { */
/*     printf("Error creating file\n"); */
/*     return 0; */
/*   } */

/*   int N; */
/*   printf("How many number to input? "); */
/*   scanf(" %d", &N); */

/*   for (int i = 0, num; i < N; i++) { */
/*     scanf("%d", &num); */
/*     fprintf(numfile, "%d\n", num); */
/*   } */
/*   printf("Numbers written to file!\n"); */
/*   fclose(numfile); */
/*   return 1; */
/* } */

/* void classify_nums(FILE *numfile, FILE *evenfile, FILE *oddfile) { */
/*   while (1) { */
/*     int digit; */
/*     int read = fscanf(numfile, "%d\n", &digit); */
/*     if (read == -1) */
/*       break; */
/*     int rem = digit % 2; */
/*     if (rem == 0) { */
/*       fprintf(evenfile, "%d\n", digit); */
/*     } else { */
/*       fprintf(oddfile, "%d\n", digit); */
/*     } */
/*   } */
/* }   */

/* int main(void) { */
/*   if (input_nums_to_file("NUMBER.txt") == 0) { */
/*     return 1; */
/*   }     */

/*   FILE *numfile = fopen("NUMBER.txt", "r"); */
/*   if (numfile == NULL) { */
/*     printf("Error reading number file\n"); */
/*     return 1; */
/*   } */

/*   FILE *oddfile = fopen("ODD.txt", "w"); */
/*   if (oddfile == NULL) { */
/*     printf("Error creating file\n"); */
/*     fclose(numfile); */
/*     return 1; */
/*   } */

/*   FILE *evenfile = fopen("EVEN.txt", "w"); */
/*   if (oddfile == NULL) { */
/*     printf("Error creating file\n"); */
/*     fclose(numfile); */
/*     fclose(oddfile); */
/*     return 1; */
/*   } */

/*   classify_nums(numfile, evenfile, oddfile); */

/*   fclose(numfile); */
/*   fclose(oddfile); */
/*   fclose(evenfile); */
/* } */






/* // 3 Student strutcture records */
/* #include <stdio.h> */
/* #include <stdlib.h> */

/* #define N 10 */

/* struct student { */
/*   char name[100]; */
/*   int rollno; */
/*   int marks; */
/* }; */

/* int search_record(struct student *records, int size, int roll) { */
/*   // Gives the index of the struct in records matching given roll */
/*   for (int i = 0; i < size; i++) { */
/*     struct student record = records[i]; */
/*     if (record.rollno == roll && strcmp(record.name, "") != 0) */
/*       return i; */
/*   } */
/*   // if no match */
/*   return -1; */
/* } */

/* int roll_to_index(struct student *records, int size) { */
/*   int roll; */
/*   printf("Roll No to edit: "); */
/*   scanf(" %d", &roll); */
/*   int i = search_record(records, size, roll); */
/*   if (i == -1) { */
/*     printf("No such roll no exists\n"); */
/*     return i; */
/*   } else */
/*     return 0; */
/* } */

/* void add_record(struct student *records, int size) { */
/*   // Fill a new struct and add that to records array */
/*   int i = size; */
/*   printf("Name, Roll, Marks: "); */
/*   scanf("%s %d %d", records[i].name, &records[i].rollno,
 * &records[i].marks); */
/* } */

/* void edit_record(struct student *records, int size) { */
/*   // Fill a new struct and add that to records array */
/*   int i = roll_to_index(records, size); */
/*   if (i) { */
/*     printf("Name, Roll, Marks: "); */
/*     scanf("%s %d %d", records[i].name, &records[i].rollno,
 * &records[i].marks); */
/*   } */
/* } */

/* void del_record(struct student *records, int size) { */
/*   // Gets the no of the record and deletes it from array */
/*   int i = roll_to_index(records, size); */
/*   if (i) */
/*     // we consider struct with no name as deleted and we wont list them. */
/*     strcpy(records[i].name, ""); */
/* } */

/* void print_record(struct student *records, int index) { */
/*   struct student record = records[index]; */
/*   printf("%d\t%s\t%d\n", record.rollno, record.name, record.marks); */
/* } */

/* void list_record(struct student *records, int size) { */
/*   // Got through the array and print all records except the ones with empty
 */
/*   // names */
/*   for (int i = 0; i < size; i++) { */
/*     struct student record = records[i]; */
/*     if (strcmp(record.name, "") != 0) */
/*       print_record(records, i); */
/*   } */
/* } */

/* void show_record(struct student *records, int size) { */
/*   int i = roll_to_index(records, size); */
/*   if (i) { */
/*     print_record(records, i); */
/*   } */
/* } */

/* int main(void) { */
/*   struct student *records = malloc(sizeof(struct student) * N); */
/*   int size = 0; */
/*   printf(":: Welcome! Use " */
/*          "commands\n'a'->add\n'd'->delete\n'e'->edit\n'l'->list
 * all\n's':show record\n'q'->quit\n"); */
/*   char *prompt = "Commands: a/d/l/q >> "; */
/*   while (1) { */
/*     printf("\n%s", prompt); */
/*     char command; */
/*     scanf(" %c", &command); */
/*     if (command == 'a') { */
/*       add_record(records, size); */
/*       size++; */
/*     } else if (command == 'd') { */
/*       del_record(records, size); */
/*     } else if (command == 'e') { */
/*       edit_record(records, size); */
/*     } else if (command == 'l') { */
/*       list_record(records, size); */
/*     } else if (command == 's') { */
/*       show_record(records, size); */
/*     } else if (command == 'q') { */
/*       break; */
/*     } */
/*   } */
/*   return 0; */
/* } */





// 1 read write txt files
/* #include <stdio.h> */
/* #include <stdlib.h> */

/* int main(void){ */
/*   FILE *infile = fopen("input.txt", "r"); */
/*   if(infile == NULL){ */
/*     printf("Failed to read file"); */
/*     return 1; */
/*   } */
/*   FILE *outfile = fopen("output.txt", "w"); */
/*   if(outfile == NULL){ */
/*     printf("Failed to create file"); */
/*     fclose(infile); */
/*     return 1; */
/*   } */

/*   while(1){ */
/*     char buf; */
/*     int read = fread(&buf, sizeof(char), 1, infile); */
/*     if(read != 1){ */
/*       break; */
/*     } */
/*     fwrite(&buf, sizeof(char), 1, outfile); */
/*   } */
/*   fclose(infile); */
/*   fclose(outfile); */
/*   return 0; */
/* } */
