#include <stdio.h>
#include <string.h>
#include <math.h>

// structure to store login information record
struct new_dttyp
{
  int numb1;
  char fname[100];
};

/*union to compare passcodes and verfying it and completing final project */
union uni
{
  int numb2;
  char lname[50];
};

// main function 
int main()
{
  struct new_dttyp var1[50];
  union uni var2[50];
  FILE *ptr;
  ptr = fopen("new.txt","w");
  if(ptr==NULL)
  {
    printf("oops create new file");
    return 0;
  }

  // Recording the credentials part-1
  int n,key[50];
  printf("HI THERE !!!!!! WELCOME TO THE CONSOLE INPUT FOR THE PROGRAM OF STORING THE RECORDS INTO A  .TXT FILE  ||||||||||||||||||NOTE : LESS SECURE BUT USE FRIENDLY \n\n");
  printf("PLEASE ENTER THE NUMBER OF RECORDS SIZE THAT YOU WANT TO STORE: ");
  scanf("%d",&n);
  int a[100];
  for(int i=0; i<n ; i++)
  {
    printf("\nASK THE USER ABOUT DETAILS OF RECORD %d\n\n",i+1);
    printf("ENTER NUMBER: ");
    scanf("%d",&var1[i].numb1);
    printf("enter fname: ");
    scanf("%s",var1[i].fname);
    key[i] = (int)sqrt(var1[i].numb1);
    printf("\nYOUR SECRET PASSCODE FOR FUTHER LAST DETAILS OF RECORD INFO %d is %d\n\n",i+1,key[i]);
  }

  // Recording the credentials part-2::lastname
  // details to complete the record 

  for (int l=0; l<n; l++)
  {
    printf("\nENTER YOUR SECRET PASSCODE TO MOVE FUTHER:  ");
    scanf("%d",&var2[l].numb2);
    if(key[l] == var2[l].numb2)
    {
      printf("\nENTER YOUR LAST NAME TO COMPLETE THE RECORD\n");
      printf("PLEASE ENTER YOUR LAST NAME: ");
      scanf("%s",var2[l].lname);
    }
  }

  //RECORDING ALL COLLECTED INTO A TEXT FILE
  fprintf(ptr,"THIS IS A SMALL USER RECORDS STORING USING THE C LANGUAGE FILE OPERATIONS AND AS WELL AS USING BASICS CONCEPTS\n\nTHIS IS A LOGIN INFO DETAILS RECORDED DB\n");
  for(int j=0; j<n; j++)
  {
    fprintf(ptr,                                          "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(ptr,"record %d\n",j);
    fprintf(ptr,"ROLLID: %d\n FULL NAME: %s\n key: %d\n\n", var1[j].numb1,strcat(var1[j].fname,var2[j].lname),key[j]);
    fprintf(ptr,                                            "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n SIZE OF THIS RECORD IS %zu",(sizeof(var1[j].fname) + sizeof(var2[j].lname)+ sizeof(var1[j].numb1)));
  }
  fclose(ptr);

  /*OPENING THE FILE AGAIN TO READ THE DETAILS RECORDED IN THE FILE USING "r" mode*/

  ptr=fopen("new.txt","r");

  // printing on the screen back once to refer once.
  printf("\n::::: summary details are given below ::::::");
  for(int k=0; k<n; k++)
  {
    printf("\n RECORD DETAIL - %d\n ",k+1);
    printf("~||||||||||||||||||||||||||~");
    printf("\n NUMBER :%d\n NAME : %s\n\n",var1[k].numb1,strcat(var1[k].fname,var2[k].lname));
    printf("~||||||||||||||||||||||||||~");
  }
  fclose(ptr);

  return 0;
}

// RECORD OF 10 NUMBERS ARE GIVEN