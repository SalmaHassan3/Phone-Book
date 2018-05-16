#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{
    char street[50];
    int flat;
    char city[50];
}Address;
typedef struct{
    char first[50];
    char last[50];
    Address adrs;
    int number;
    char email[50];
}Contact;
Contact s[1000];
int i=0;
void readfromfile()
{
    FILE*f;
    f=fopen("sample.txt","r");
    if(f==NULL)
        printf("Warning!File not found\n");
    else
    {
        while(!feof(f))
        {
  fscanf(f,"%[^,],%[^,],%[^,],%d,%[^,],%d,%s",s[i].first,s[i].last,s[i].adrs.street,&s[i].adrs.flat,s[i].adrs.city,&s[i].number,s[i].email);
     fscanf(f,"\n");
         i++;
        }
        fclose(f);
        printf("\n\n'File is loaded successfully'\n");
    }

    printf("------------------------------------------------------------------------------");
     printf("\n\n");
    menu();
}
void search()
{ char name[50];
int j,counter=0;;
   if(i==0)
    printf("\n\n'There are no contacts,Enter or load ones'\n");
   else {
  printf("\n\nEnter the first name\t");
  scanf("%s",name);
  name[0]=toupper(name[0]);
  for(j=0;j<i;j++)
  {
      if(strcmp(s[j].first,name)==0)
      {
        printf("\nContacts matching are:\n\nResult #%d\n================\n\n",counter+1);
      printf("First name:\t%s\n",s[j].first);
      printf("Last name:\t%s\n",s[j].last);
      printf("Street:\t%s\n",s[j].adrs.street);
      printf("flat no.:\t%d\n",s[j].adrs.flat);
      printf("City:\t%s\n",s[j].adrs.city);
      printf("Phone number:\t%d\n",s[j].number);
      printf("E-mail:\t%s\n",s[j].email);
      printf("\n\n");
       counter++;
      }}
      if(counter==0)
    printf("'Contact doesn't exist'\n");
  }
  printf("-----------------------------------------------------------------------------\n");
  printf("\n\n");
  menu();
}
void add()
{   int n,k;
    printf("Enter no. of contacts you want to add:\n");
    scanf("%d",&n);
     for(k=0;k<n;k++)
   {printf("Enter contact %d data\n\n",k+1);
    printf("First name:\t"); scanf("%s",s[i].first);
    printf("Last name:\t"); scanf("%s",s[i].last);
    printf("Street:\t"); scanf("%s",s[i].adrs.street);
    printf("Flat no.:\t"); scanf("%d",&s[i].adrs.flat);
    printf("City:\t"); scanf("%s",s[i].adrs.city);
    printf("Phone number:\t"); scanf("%d",&s[i].number);
    printf("E-mail:\t"); scanf("%s",s[i].email);
    printf("\n\n");
    s[i].first[0]=toupper(s[i].first[0]);
    s[i].last[0]=toupper(s[i].last[0]);
    i++;printf("------------------------------------------------------------------\n");}
    printf("'Contact(s) is/are added successfullly'\n----------------------------------------------\n");
    printf("\n\n");
    menu();

}
void sort(){
    if(i==0)
       printf("\n\n'There are no contacts,Enter or load ones'\n");
    else {
    int pass,pass2;
    int j,j2,k;
    Contact temp;
    int position,position2;
    for(pass=0;pass<i-1;pass++)
    {
        position=pass;
        for(j=pass+1;j<i;j++)
        {
            if(strcmp(s[position].first,s[j].first)>0)

                position=j;
        }
            if(position!=pass)
            {
                temp=s[pass];
                s[pass]=s[position];
                s[position]=temp;
            }

    }
    for(pass2=0;pass2<i-1;pass2++)
    {
        position2=pass2;
        for(j2=pass2+1;j2<i;j2++)
        {
            if(strcmp(s[position2].first,s[j2].first)==0&&strcmp(s[position2].last,s[j2].last)>0)

                position2=j2;
        }
            if(position2!=pass2)
            {
                temp=s[pass2];
                s[pass2]=s[position2];
                s[position2]=temp;
            }

    }
    printf("All Contacts:\n\n");
    for(k=0;k<i;k++){
            printf("%d)\n",k+1);
     printf("First name:\t%s\n",s[k].first);
      printf("Last name:\t%s\n",s[k].last);
      printf("Street:\t%s\n",s[k].adrs.street);
      printf("flat no.:\t%d\n",s[k].adrs.flat);
      printf("City:\t%s\n",s[k].adrs.city);
      printf("Phone number:\t%d\n",s[k].number);
      printf("E-mail:\t%s\n\n\n",s[k].email);} }
    printf("-------------------------------------------------------------------------\n");
      menu();

}
void del()
{    char firstname[50];
    int k,j=0,n,y,counter=0;
    int x[50];
       if(i==0)
       printf("\n\n'There are no contacts,Enter or load ones'\n");
        else {
         printf("please enter first name\n");
          scanf("%s",firstname);
          firstname[0]=toupper(firstname[0]);
   for(k=0;k<i;k++)
    if(strcmp(s[k].first,firstname)==0)
        counter++;
    if(counter==0)
        printf("'Contact doesn't exist'\n\n");
    else {     for(k=0;k<i;k++){
            if(strcmp(s[k].first,firstname)==0){
            printf("Result #%d\n",j+1);
            printf("===============\n\n");
             printf("First name:\t%s\n",s[k].first);
      printf("Last name:\t%s\n\n",s[k].last);
      x[j]=k;
      j++;
        }}

    printf("Enter no. of result you want to delete");
    scanf("%d",&n);
    for(k=0;k<j;k++)
    {
        if(n==k+1)
            y=k;
    }
    for(k=x[y];k<i;k++)
        s[k]=s[k+1];

               i--;
               printf("\n\nContact is successfully deleted\n\n\n");}}

    printf("-----------------------------------------------------------------------------\n");
    menu();
}
void save()
{    int j;
     if(i==0)
       {printf("\n\nThere are no contacts to be saved !\n\n\n");
       printf("-------------------------------------------------------------------------------------------------\n");}
     else {
    FILE*f;
    f=fopen("sample.txt","w");
    for(j=0;j<i;j++)
    {
fprintf(f,"%s,%s,%s,%d,%s,%d,%s",s[j].first,s[j].last,s[j].adrs.street,s[j].adrs.flat,s[j].adrs.city,s[j].number,s[j].email);
fprintf(f,"\n");
    }
    fclose(f);
    printf("'Contacts are saved'\n\n\n");
    printf("-------------------------------------------------------------------------------------------------\n");}
    menu();
}
void modify()
{   char firstname[50];
    int k,j=0,n,y,counter=0;
    int x[50];
    if(i==0)
     {printf("\n\n'There are no contacts,Enter or load ones'\n");
     menu();}
      else {
    printf("please enter first name\n");
    scanf("%s",firstname);
    firstname[0]=toupper(firstname[0]);
    for(k=0;k<i;k++)
        if(strcmp(s[k].first,firstname)==0)
        counter++;
    if(counter==0)
       {printf("contact doesn't exist\n\n");
       menu();}

    else {
    for(k=0;k<i;k++)
    {
        if(strcmp(s[k].first,firstname)==0)
        {
            printf("\n\nResult #%d\n",j+1);
            printf("===============\n");
             printf("First name:\t%s\n",s[k].first);
      printf("Last name:\t%s\n",s[k].last);
      x[j]=k;
      j++;
        }
    }
    printf("\n\nEnter no. of result you want to modify\n\n");
    scanf("%d",&n);
    for(k=0;k<j;k++)
    {
        if(n==k+1)
            y=k;
    }
    modify2(x[y]);
      }}
}
void modify2(int x)
{    int n;
    printf("press <1> to edit first name\n\n");
    printf("press <2> to edit last name\n\n");
    printf("press <3> to edit street\n\n");
    printf("press <4> to edit flatno.\n\n");
    printf("press <5> to edit city\n\n");
    printf("press <6> to edit phone no.\n\n");
    printf("press <7> to edit e-mail\n\n");
    printf("press <8> to go back to main menu\n\n");
    scanf("%d",&n);
    if(n==1)
       {printf("enter new first name\n");
    scanf("%s",s[x].first);
    s[x].first[0]=toupper(s[x].first[0]);
    modify2(x);
       }
      if(n==2)
       {printf("enter new last name\n");
    scanf("%s",s[x].last);
    s[x].last[0]=toupper(s[x].last[0]);
    modify2(x); }
    if(n==3)
       {printf("enter new street name\n");
    scanf("%s",s[x].adrs.street);
    modify2(x); }
    if(n==4)
       {printf("enter new flat no.\n");
    scanf("%d",&s[x].adrs.flat);
    modify2(x); }
    if(n==5)
       {printf("enter new city\n");
    scanf("%s",s[x].adrs.city);
    modify2(x); }
    if(n==6)
       {printf("enter new phone no.\n");
    scanf("%d",&s[x].number);
    modify2(x); }
    if(n==7)
       {printf("enter new e-mail\n");
    scanf("%s",s[x].email);
    modify2(x); }
    if(n==8)
    {
        printf("Contact is successfully modified\n\n\n");
        menu();
    }

}
void Exit()
{   char x;
    printf("Are you sure you want to exit? Your changes won't be saved!\n");
    printf("Press 'Y' to exit:\n");
    printf("Press 'N' to go back to menu:\n");
    scanf(" %c",&x);
    x=toupper(x);
    if(x=='N')
        menu();
    else if(x=='Y')
        printf("\n\n\n***Thanks***");
}
void menu()
{
    int n;
    printf("Main Menu :\n===========\nChoose your command:\n");
    printf("1->To read from a file\n");
    printf("2->To search for a contact\n");
    printf("3->To add a new contact\n");
    printf("4->To print all contacts\n");
    printf("5->To delete a contact\n");
    printf("6->To save changes\n");
    printf("7->To Modify\n");
    printf("8->To Exit");


    scanf("%d",&n);
    if(n==1)
        readfromfile();
        if(n==2)
    search();
    if(n==3)
        add();
    if(n==4)
        sort();
    if(n==5)
        del();
    if(n==6)
        save();
    if(n==7)
        modify();
    if(n==8)
        Exit();


}

int main()
{   printf("\n\t\t\t*****Welcome to Phone book*****\n\n");
    menu();


    return 0;
}


