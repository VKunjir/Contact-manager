
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"data.h"
#include"search.h"
void main()
{   void add_contact();
	void list_contact();
	void delete_contact();
	void edit_contact();
	void search_contact();
	void change_password();
	char pass[30],ch,orginal[30],choice;
	int i;
	FILE *fp;
	window(1,1,80,25);
	textbackground(YELLOW);
	clrscr();
	window(20,10,60,15);
	textbackground(BLACK);
	clrscr();
	gotoxy(4,3);
	textcolor(RED+BLINK);
	cprintf("Enter the password :");
	i=0;
	while(1)
	{
		ch=getch();
		if(ch==13)  	//ASCII code ENTER key
		{
			pass[i]='\0';
			break;
		}
		pass[i++]=ch;
		printf("*");
	}
	fp=fopen("password.dat","r");
	fgets(orginal,30,fp);
	if(!(strcmp(orginal,pass))==0)
		{
			gotoxy(4,5);
			textcolor(WHITE+BLINK);
			cprintf("Incorrect password Press any key.....");
			getch();
			exit(0);
		}
	else
		{
			window(1,1,80,25);
			textbackground(11);
			clrscr();
			gotoxy(32,3);
			textcolor(RED);
			cprintf("CONTACT MANAGER");
			gotoxy(31,5);
			textcolor(BLUE);
			cprintf("Version no. : 1.0 ");
			gotoxy(22,8);
			textcolor(WHITE);
			cprintf("Developed By :- Viraj Kunjir");
			textcolor(RED);
			gotoxy(5,15);
			cprintf("Please wait ");
			for(i=1;i<=50;i++)
			{
				cprintf("%c",220);
				delay(200);
				}
				while(1)
		  {	textbackground(YELLOW);
			clrscr();
			window(18,5,60,22);
			textbackground(BLACK);
			clrscr();
			textcolor(11);
			gotoxy(18,2);
			cprintf("MAIN MENU");
			gotoxy(16,3);
			cprintf("-----------------");
			textcolor(WHITE);
			gotoxy(15,5);
			cprintf("1 Add new contact");
			gotoxy(15,6);
			cprintf("2 Delete contact");
			gotoxy(15,7);
			cprintf("3  Editing contact");
			gotoxy(15,8);
			cprintf("4 Search contact");
			gotoxy(15,9);
			cprintf("5 List of all contact ");
			gotoxy(15,10);
			cprintf("6 Change password");
			gotoxy(15,11);
			cprintf("7 Exit");

			gotoxy(10,12);
			cprintf("---------------------------------");
			textcolor(RED+BLINK);
			gotoxy(12,14);
			cprintf("Enter your choice(1-7)");
			choice=getch();
			switch(choice)
			{
				case '1': add_contact();  break;
				case '2': delete_contact(); break;
				case '3': edit_contact();  break;
				case '4': search_contact(); break;
				case '5': list_contact();  break;
				case '6': change_password(); break;
				case '7':
					exit(0);
			}
		}

	}

}
//change password
void change_password()
{
 FILE *fp;
 char current[30],newpass[30],orginial[30],confirm[30];
 window(1,1,80,25);
 textbackground(WHITE);
 textcolor(11);
 clrscr();
 printf("change Password");
 printf("\n--------------------------------------");
 printf("\nEnter the current password");
 gets(current);

 //Reading password from password.adt
 fp=fopen("password.dat","r");
 fgets(orginial,30,fp);
 fclose(fp);

 if(strcmp(current,orginial)!=0)
 {
  printf("Incorrect password, Press any key......");
  getch();
  return;
 }
 printf("\nEnter new password : ");
 gets(newpass);
 printf("\nRe-Enter password  : ");
 gets(confirm);
 if(strcmp(confirm,newpass)!=0)
 {
  printf("\nNot match, Press any key");
  getch();
  return;
 }
  fp=fopen("password.dat","w");
  fprintf(fp,"%s",newpass);
  fclose(fp);
  printf("Successfully updated, Press any key...");
  getch();


 getch();

}

//delete contact
void delete_contact()
{
	char choice;
	int n,found;
	FILE *fp1,*fp2;
   window(1,1,80,25);
   textbackground(BLACK);
   textcolor(WHITE);
   clrscr();
   printf("Delete Contact");
   printf("\n-----------------------------------------------");
   printf("\nEnter serial no to be deleted : ");
   scanf("%d",&n);
   fp1=fopen("info.dat","rb");
   found=0;
   while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
   {
		if(cont.sno==n)
		{
		 printf("\nCategory : %s",cont.category);
		 printf("\nNmae     : %s",cont.name);
		 printf("\nGender   : %c",cont.gender);
		 printf("\nAge      : %d",cont.age);
		 printf("\nAddress  : %s",cont.address);
		 printf("\nPhone no : %s",cont.phone);
		 printf("\nEmail id : %s",cont.email);
		 printf("\n------------------------------");
		 found=1;
		break;
		}
   }
   if(found==0)
   {
   textcolor(RED+BLINK);
   printf("\n");
	cprintf("Not found");
	fclose(fp1);
	return;
   }
   printf("\nDelete it y/n : ");
   choice=getch();
   if(choice=='y' || choice=='Y')
	   { rewind(fp1);
		 fp2=fopen("temp.dat","wb");
		while(fread(&cont,sizeof(cont),1,fp1)>NULL)
		{
		 if(cont.sno!=n)
		 fwrite(&cont,sizeof(cont),1,fp2);
	   }
	fclose(fp1);
	fclose(fp2);
	remove("info.dat");
	rename("temp.dat","info.dat");
	textcolor(GREEN+BLINK);
	printf("\n");
	cprintf("Successfully deleted, Press any key.....");
	getch();
	}
}
//edit contact
void edit_contact()
{
	FILE *fp;
	int pos,found,n;
	window(1,1,80,25);
	textcolor(YELLOW);
	textbackground(BLACK);
	clrscr();
	printf("Edit contact");
	printf("---------------------------------------------------------\n");
	printf("Enter the serial no to be editd");
	scanf("%d",&n);
	fp=fopen("info.dat","r+b");
	found=0;
	while(fread(&cont,sizeof(cont),1,fp)>0)
	{
	 if(cont.sno==n)
	 {
	  found=1;
	  printf("\nCategory    :  %s",cont.category);
	  printf("\nName 		:	%s",cont.name);
	  printf("\nGender		:	%c",cont.gender);
	  printf("\nAddress		:	%s",cont.address);
	  printf("\nAge			:	%d",cont.age);
	  printf("\nContact no	: 	%s",cont.phone);
	  printf("\nEmail.com	:	%s",cont.email);
	  break;
	 }
	}
	if(found==0)
	{
	 printf("\n");
	 textcolor(RED+BLINK);
	 cprintf("NOT Found ,Press any key...");
	 fclose(fp);
	 getch();
	 return;
	}
	printf("\n\nENTER NEW DATA\n");
	pos=ftell(fp);
	fseek(fp,pos-sizeof(cont),SEEK_SET);

	fflush(stdin); //to clear input buffer
	printf("Enter category(Friend/PG/Salesman/Student) : ");
	gets(cont.category);
	fflush(stdin);
	printf("Enter name : ");
	gets(cont.name);
	fflush(stdin);
	printf("Enter gender m/f : ");
	scanf("%c",&cont.gender);
	fflush(stdin);
	printf("Enter age : ");
	scanf("%d",&cont.age);
	fflush(stdin);
	printf("Enter  address : ");
	gets(cont.address);
	fflush(stdin);
	printf("Enter Phone no : ");
	gets(cont.phone);
	fflush(stdin);
	printf("Enter email ID : ");
	gets(cont.email);
	fflush(stdin);
	fwrite(&cont,sizeof(cont),1,fp);
	fclose(fp);
	printf("\n");
	textcolor(RED+BLINK);
	cprintf("Successfully Updated, Press any key.....");
	getch();

}



//list of contact
void list_contact()
{
	int i;
	FILE *fp;
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLUE);
	clrscr();
	gotoxy(34,1);
	printf("List of Contact : ");
	printf("\n");
	for(i=1;i<=80;i++)
		printf("-");
	gotoxy(1,3);
	printf("SNO");
	gotoxy(8,3);
	printf("CATEGORY");
	gotoxy(20,3);
	printf("Name");
	gotoxy(36,3);
	printf("GENDER");
	gotoxy(46,3);
	printf("AGE");
	gotoxy(55,3);
	printf("ADDRESS");
	gotoxy(70,3);
	printf("PHONE No");
   //	gotoxy(70,3);
	//printf("EMAIL");
	printf("\n");
	for(i=1;i<=80;i++)
		printf("-");
	fp=fopen("info.dat","r");
	i=5;
	while(fread(&cont,sizeof(cont),1,fp)>0)
	{
	 gotoxy(1,i);
	 printf("%d",cont.sno);
	 gotoxy(8,i);
	 printf("%s",cont.category);
	 gotoxy(20,i);
	 printf("%s",cont.name);
	 gotoxy(36,i);
	 printf("%c",cont.gender);
	 gotoxy(46,i);
	 printf("%d",cont.age);
	 gotoxy(55,i);
	 printf("%s",cont.address);
	 gotoxy(70,i);
	 printf("%s",cont.phone);
	 i++;

	}
	fclose(fp);
	textcolor(RED+BLINK);
	printf("\n");
	cprintf("Press any key.....");

	getch();
}
//search contact
void search_contact()
{
	int ch;
 window(1,1,80,25);
 textbackground(BLACK);
 textcolor(11);
 clrscr();
 textcolor(RED);
 cprintf("SEARCH OPTION ");
 printf("----------------------------------------------------");
 printf("\n");
 printf("\n1 Search by serial no");
 printf("\n2 Search by category");
 printf("\n3 Search by name");
 printf("\n4 Search by phone no");
 printf("\n5 Back to mean");
 printf("\n-------------------------------------------------------\n");
 textcolor(WHITE+BLINK);
 cprintf("\nEnter your choice ?");
 ch=getch();
 switch(ch)
 {
	case '1': search_sno();  break;
	case '2': search_category();   break;
	case '3': search_name();     break;
	case '4': search_phone();          break;
	case '5': return;

 }


}
//auto serial no
int getsno()
{
 FILE *fp;
 int n,size;
 fp=fopen("info.dat","rb");
 size=sizeof(cont);
 fseek(fp,-size,SEEK_END);
 fread(&cont,sizeof(cont),1,fp);
 n=cont.sno;
 fclose(fp);
 n++;
 return (n);

}

//add contact
void add_contact()
{
	FILE *fp;
	window(1,1,80,25);
	textbackground(YELLOW);
	textcolor(11);
	clrscr();
	printf("Add new contact\n");
	printf("------------------------------------------");
	fflush(stdin);
	cont.sno=getsno();
	printf("\nSerial no %d : ",cont.sno);


	fflush(stdin); //to clear input buffer
	printf("\nEnter category(Friend/PG/Salesman/Student) : ");
	gets(cont.category);
	fflush(stdin);
	printf("Enter name : ");
	gets(cont.name);
	fflush(stdin);
	printf("Enter gender m/f : ");
	scanf("%c",&cont.gender);
	fflush(stdin);
	printf("Enter age : ");
	scanf("%d",&cont.age);
	fflush(stdin);
	printf("Enter  address : ");
	gets(cont.address);
	fflush(stdin);
	printf("Enter Phone no : ");
	gets(cont.phone);
	fflush(stdin);
	printf("Enter email ID : ");
	gets(cont.email);
	fflush(stdin);
	fp=fopen("info.dat","ab");
	fwrite(&cont,sizeof(cont),1,fp);
	fclose(fp);
	printf("\n");
	textcolor(WHITE+BLINK);
	cprintf("\nSuccessfully saveed, Press any key....");
	getch();

}