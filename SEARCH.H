void search_sno()
{
	FILE  *
	fp;
	int n,found;
	textcolor(11);
	clrscr();
	printf("Enter the serial no : ");
	scanf("%d",&n);
	fp=fopen("info.dat","r");
	found=0;
	while(fread(&cont,sizeof(cont),1,fp)>0)
	{
		if(cont.sno==n)
		{
		 printf("\nCategory 	: %s",cont.category);
		 printf("\nName			:%s",cont.name);
		 printf("\nGender		:%c",cont.gender);
		 printf("\nAge			:%d",cont.age);
		 printf("\nAddress		:%s",cont.address);
		 printf("\nPhone no		:%s",cont.phone);
		 printf("\nEmail Id		:%s",cont.email);
		 found=1;
		 break;
		}
	}
	if(found==0)
	{
	 printf("\nNot found, Press any key");
	 fclose(fp);
	 getch();
	 return;
	}
	fclose(fp);
	getch();
}
//search by category
void search_category()
{
	int i;
	char cat[20];
	FILE *fp;
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLUE);
	clrscr();
	printf("Enter category :  ");
	gets(cat);

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
	if(strcmpi(cat,cont.category)==0)
   { gotoxy(1,i);
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

	}
	fclose(fp);
	textcolor(RED+BLINK);
	printf("\n");
	cprintf("Press any key.....");

	getch();
}
//  search name
void search_name()
{
	int i;
	char na[20];
	FILE *fp;
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLUE);
	clrscr();
	printf("Enter name :  ");
	gets(na);

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
	if(strcmpi(na,cont.name)==0)
   { gotoxy(1,i);
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

	}
	fclose(fp);
	textcolor(RED+BLINK);
	printf("\n");
	cprintf("Press any key.....");

	getch();
}
//search by phone no
void search_phone()
{
	FILE  *
	fp;
	int found;
	char ph[15];
	textcolor(11);
	clrscr();
	printf("Enter the phone no : ");
	gets(ph);
	fp=fopen("info.dat","r");
	found=0;
	while(fread(&cont,sizeof(cont),1,fp)>0)
	{
		if(strcmpi(ph,cont.phone)==0)
		{
		 printf("\nCategory 	: %s",cont.category);
		 printf("\nName			:%s",cont.name);
		 printf("\nGender		:%c",cont.gender);
		 printf("\nAge			:%d",cont.age);
		 printf("\nAddress		:%s",cont.address);
		 printf("\nPhone no		:%s",cont.phone);
		 printf("\nEmail Id		:%s",cont.email);
		 found=1;
		 break;
		}
	}
	if(found==0)
	{
	 printf("\nNot found, Press any key");
	 fclose(fp);
	 getch();
	 return;
	}
	fclose(fp);
	getch();
}
