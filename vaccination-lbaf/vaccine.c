/*Covid Vaccine Inventory Management System

A interactive program to manage the records of the vaccine inventory.

VaccineInfo:
:: name of vaccine
:: Vaccine code
:: Production country
:: Dosage required
:: Population covered (%)
:: Quantity of vaccine (in millions)
 
DistributeInfo:
:: Code of vaccine
:: distributed quantity


*/
#include <stdio.h>
/* #include<conio.h> */
#include <string.h>


struct vaccineinfo{
    char vac_name[20];
    char vac_code[10];
    char producing_country[25];
    int dosage_required;
    float population_covered;
    long int quantity;
};

struct distributeinfo{
    char vac_name[20];
    long int quantity;
};

void show_vaccine_info();

void add_vaccine();

void update_vaccine_quantity();

void edit_vaccine_info(int n, int amount, char ch);

void search_vaccine();

void dist_vaccine_info();

void sort_vaccine(struct distributeinfo[],int);



int main(void)
{
    while(1)
    {
        int z;
        printf("-----------------------------------------------------------\n");
        printf("     Covid Vaccine Inventory Management System      \n");
        printf("------------------------------------------------------------\n");
        printf("\n\n\t\t1.Dispaly available  vaccine information\n");
        printf("\t\t2.Add new vaccine in inventory\n");
        printf("\t\t3.Update the vaccine amount in the inventory\n");
        printf("\t\t4.Search the vaccine\n");
        printf("\t\t5.Display the distributed vaccine information\n");
        printf("\t\t6.Exit");
        printf("--------------------------------------------------------------\n");
        scanf("%d",&z);

        switch(z)
        {
            case 1:
                show_vaccine_info();  // this will show all the available vaccine in the inventory
            break;
            case 2:
                add_vaccine(); // thiswill add vaccine in the inventory system
            break;
            case 3:
                update_vaccine_quantity(); // this will update the vaccine amount in the inventory
            break;
            case 4:
                search_vaccine(); // this will assist to find the vaccine we want 
            break;
            case 5:
                dist_vaccine_info(); // this will show the information of the distributed vaccines information
            break;
            case 6:
            default:
            printf("Selection exceed the option\n");
            break;
        }

    }
    return 0;
}

void show_vaccine_info(){
    struct vaccineinfo vc1;
    FILE * fptr;
    fptr=fopen("vaccine.txt","r");
    if(fptr==NULL)
    {
        printf("Error while opening the file!!");
    }
    printf("\t\t\tDisplaying Available Vaccine Information In The Inventory");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    printf("   VACCINE NAME   VACCINE CODE   PRODUCING COUNTRY   REQUIRED DOASGE   POPULATION COVERED(IN PER)   AVAILABLE QUANTITY  ");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
     while(fread(&vc1,sizeof(struct vaccineinfo),1,fptr))
     {
         printf("%s %s %s %d %.1f %ld",vc1.vac_name,vc1.vac_code,vc1.producing_country,vc1.dosage_required,vc1.population_covered,vc1.quantity);
         printf("\n");
     }
     printf("\n");
     printf("\n");
     fclose(fptr);
}

void add_vaccine(){
    int i=0, num=0;
    printf("Enter the number of vaccine you want to add in the system:\n ");
    scanf(" %d",&num);
    struct vaccineinfo vc[num];
    for (i=0; i<num;i++)
    {
        printf("Enter the name of covid vaccine:\n");
        scanf(" %s",vc[i].vac_name);

        printf("Enter the code of the vaccine:\n");
        scanf(" %s",vc[i].vac_code);

        printf("Enter the name of the covid vaccine producing country:\n");
        scanf(" %s",vc[i].producing_country);

        printf("Enter the required dosage of vaccine:\n");
        scanf(" %d",&vc[i].dosage_required);

        printf("Enter the population covered are by the vaccine:\n");
        scanf("%f",&vc[i].population_covered);

        printf("Enter the initial quantity of the vaccine:\n");
        scanf(" %ld",&vc[i].quantity);
    }
    FILE *fptr;
    fptr = fopen("vaccine.txt","a");
    if (fptr==NULL)
      printf("Error while creating the file");

    for (i=0; i<num; i++)
    {
        fwrite(&vc[i],sizeof(struct vaccineinfo),1,fptr);
    }
    fclose(fptr);
}


void update_vaccine_quantity()
{
    int num=0, vac=0, vc_amt=0;

    show_vaccine_info();
    printf("\n\n");
    printf("Enter the vaccine to up date serially:\n");
    fflush(stdin);
    scanf("%d", &num);

    printf("Choose the task to execute:\n");
    printf("1.Add vaccine in the inventory:\n");
    printf("Distribute the vaccine from the inventory:\n");
    scanf("%d",&vac);

    switch(vac)
    {
        case 1:
            printf("Enter the quantity of vaccine to add:\n");
            scanf("%d",&vc_amt);
            edit_vaccine_info(num,vc_amt,'+');
            break;
        case 2:
            printf("Enter the amount of vaccine to distribute dro the inventory:\n");
            scanf("%d",&vc_amt);
            edit_vaccine_info(num ,vc_amt,'-');
        default:
            printf("Selection exceed the option");
    }
}


void edit_vaccine_info(int n, int amount, char ch){
    int check=0;
    struct vaccineinfo vc;
    struct distributeinfo d;
    FILE * fptr, *fptr2, *fptr3;
    fptr = fopen("vaccine.txt","r");
    fptr2 = fopen("temp.txt","w");
    fptr3 = fopen("dist.txt","a");
    if(fptr==NULL) printf("Error while opening the file!!");

    while (fread(&vc, sizeof(struct vaccineinfo),1,fptr))
    {
        if (check == n - 1)
        {
            if (ch == '+') vc.quantity += amount;
            else
            {
                vc.quantity -= amount;
                strcpy(d.vac_name, vc.vac_name);
                d.quantity = amount;
                fwrite(&d, sizeof(struct distributeinfo),1,fptr3);

            }
        }
        fwrite(&d, sizeof(struct vaccineinfo), 1, fptr2);
        check++;
    }

    fclose(fptr);
    fclose(fptr2);

    fptr = fopen("vaccine.txt","w");
    fptr2=fopen("temp.txt","r");
    if (fptr==NULL) printf("Error while openning the file");

    while (fread(&vc, sizeof(struct vaccineinfo),1,fptr2))
    {
        fwrite(&vc, sizeof(struct vaccineinfo),1,fptr);
    }
    fclose(fptr);
    fclose(fptr2);
    fclose(fptr3);

    printf("\n\n\t\tUpdate successfuly !!!\nPress any key to continue");
    /* getch(); */

    }


    void search_vaccine(){
        char vaccine_code[5];
        int check =0;
        struct vaccineinfo vc1;
        printf("Enter the code for searching the vaccine:\n");
        scanf("%s",vaccine_code);

        FILE *fptr;
        fptr=fopen("vaccine.txt","r");
        if(fptr == NULL) printf("Error while opening the file");

        printf("\n\n\t\tDisplaying the information of %s\n\n",vaccine_code);
        printf("------------------------------------------------------------------------");
        printf("\t\t    VACCNE NAME    VACCINE CODE    AVAILABLE QUANTITY\n");
        printf("------------------------------------------------------------------------");
        while (fread(&vc1, sizeof(struct vaccineinfo),1,fptr))
        {
            if(strcmp(vaccine_code,vc1.vac_code)==0)
            {
                printf("\t\t  %s %s %ld", vc1.vac_name,vc1.vac_code, vc1.quantity);
                printf("\n");
                check++;
            }
        }
        printf("\n");
        fclose(fptr);
        if (check == 0)
        printf("\n\t Selection not reconised !! \n press any key to continue");
        else printf("\n\n\t\t\tPress any key to continue");
        /* getch(); */

    }


void dist_vaccine_info(){
    int i=0, j=0;
    struct distributeinfo d, darry[20];

    FILE * fptr;
    fptr = fopen("dist.txt","r");
    if(fptr==0)
      printf("Erro while opening the file!!");

    printf("\n\nDistributed vaccine quantity");
    printf("----------------------------------------------------\n");
    printf("\t\t\t     VACCINE NAME     DIST QUANTITY  \n");
    printf("-----------------------------------------------------\n");

    while (fread(&d, sizeof(struct distributeinfo),1,fptr))
    {
        darry[i] = d;
        i++;
    }
    if (i>1) sort_vaccine(darry,i);
    for (j = 0; j<i; j++)
    {
        printf("\t\t\t %s %ld \n", darry[j].vac_name,darry[j].quantity);

    }
    printf("\n");
    fclose(fptr);
    /* getch(); */
}


void sort_vaccine(struct distributeinfo darry[], int z) {
	int i=0, j=0;
	struct distributeinfo temp;
	for(i=0;i<z;i++)
	{
	for(j=i + 1; j<z; j++)	
	{
		if(darry[i].quantity< darry[j].quantity)
		{
			temp= darry[j];
			darry[j]=darry[i];
			darry[i]=temp;
			
		}
	}
	}

}
