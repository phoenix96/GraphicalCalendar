#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
int mo[]={0,3,3,6,1,4,6,2,5,0,3,5};
char *s[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
void bk();//Function for making a rectangle.
int date_check(int d2,int m2,int y2);
int calf(int d,int m,int y);//Function to calculate the f factor.
void print_c(int m,int y,int f)
{	 int i;
	int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
	clrscr();
	cleardevice();
	if((m==1||m==2)&&(y%4==0)&&(y%100!=0))
		{ a[1]=29;
		}
	else if(y%400==0)
		{ a[1]=29;
		}
       printf("\n\n\t\t\t\t%s %d\n\n",s[m-1],y);
	//Printing Calender
	printf("\n\n\n\t\tSun    Mon    Tue    Wed    Thu    Fri    Sat\n\n\t\t");
	for(i=0;i<f;i++)
	printf("       ");
	for(i=1;i<=a[m-1];i++)
	{
	printf(" %2d    ",i);
	if((f+i)%7==0)
	printf("\n\n\t\t");
	}
printf("\n\n\n\tQuote of the month:\n\t");
switch(random(20))
{
case 1:printf("Life isn't about getting and having, it's about giving and being.\n\t-Kevin Kruse");break;

case 2:printf("Whatever the mind of man can conceive and believe,\n\tit can achieve.\n\t-Napoleon Hill"); break;

case 3: printf("Strive not to be a success, but rather to be of \n\tvalue.\n\t-Albert Einstein\n");break;

case 4:printf("Two roads diverged in a wood, and I took the one less traveled by,\n\tAnd that has made all the difference.\n\t-Robert Frost\n"); break;

case 5: printf("I attribute my success to this: I never gave or took any excuse.\n\t-Florence Nightingale\n"); break;

case 6 : printf("You miss 100 percent of the shots you don't take.\n\t -Wayne Gretzky\n"); break;

case 7: printf("I've failed over and over and over again in my life.\n\tAnd that is why I succeed.\n\t-Michael Jordan\n"); break;

case 8:printf("The most difficult thing is the decision to act,\n\tthe rest is merely tenacity.\n\t-Amelia Earhart\n"); break;

case 9:printf("Every strike brings me closer to the next home run. \n\t-Babe Ruth\n"); break;

case 10:printf("Definiteness of purpose is the starting point of all\n\tachievement.\n\t-W. Clement Stone\n"); break;

case 11: printf("We must balance conspicuous consumption with\n\tconscious capitalism.\n\t-Kevin Kruse"); break;

case 12:printf("Life is what happens to you while you're busy making\n\tother plans.\n\t-John Lennon\n"); break;

case 13:printf("We become what we think about. \n\t-Earl Nightingale\n");break;

case 14:printf("Twenty years from now you will be more disappointed by the things \n\tthat you didn't do than by the ones you did do, \n\tso throw off the bowlines, sail away from safe harbor, \n\tcatch the trade winds in your sails.\n\tExplore, Dream, Discover. \n\t-Mark Twain\n"); break;

case 15:printf("Life is 10% what happens to me and 90% of how I react to it.\n\t-Charles Swindoll\n"); break;
case 16: printf("The most common way people give up their power is by thinking they \n\tdon't have any. \n\t-Alice Walker\n"); break;

case 17:printf("The mind is everything. What you think you become. \n\t-Buddha\n"); break;

case 18:printf("The best time to plant a tree was 20 years ago.\n\tThe second best time is now. \n\t-Chinese Proverb\n"); break;

case 19:printf("An unexamined life is not worth living.\n\t-Socrates\n"); break;
case 20:printf("Eighty percent of success is showing up.\n\t-Woody Allen\n"); break;
default: printf("The best mirror is a friend's eye. \n\t-Rishabh Jain\n"); break;
	}
	bk();
}
void main()
{       int i,d,m,y,f,k,k2;int pass[4];
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	cleardevice();
	printf("\n\n\n\n\t\tWelcome to the calender Application\n\n\n");
	bk();
	printf("\t\tEnter the password to continue..\n\t\t");bk();
	for(i=0;i<4;i++)
	{pass[i]=getch();
	printf("*");
	}
	getch();
	for(i=0;i<4;i++)
	{if(pass[i]!=49) {printf("\n\t\tInvalid login attempted.");bk();getch();return;}
	}
	printf("\n\n\n\t\tEnter the month and year in the format MM YYYY\n\n\n\t\t");  bk();
	scanf("%d %d",&m,&y);
	printf("\n\t\tUse arrow keys to navigate through the calender");
	bk();
	getch();
	d=1;
	if(date_check(d,m,y)==1)
	{f=calf(d,m,y);
	cleardevice();
	print_c(m,y,f);
	bk();
	k=0;
	while(k==0)
	{   	k=getch();
		k2=getch();
		if(k2==72)
		{cleardevice();
		if(y==9999)y=0;
		y++;
		f=calf(1,m,y);
		print_c(m,y,f);
		}
		else if(k2==80)
		{cleardevice();
		if(y==1)y=10000;
		y--;
		f=calf(1,m,y);
		print_c(m,y,f);
		}
		else if(k2==77)
		{cleardevice();
		if(m==12){m=0;y++;if(y==10000) y=1;}
		f=calf(1,++m,y);
		print_c(m,y,f);
		}
		else if(k2==75)
		{cleardevice();
		if(m==1){m=13;y--;if(y==0) y=9999;}
		f=calf(1,--m,y);
		print_c(m,y,f);
		}
		else
		{clrscr();
		cleardevice();
		bk();
		printf("\n\n\n\n\n\n\n\n\t\t\t\tCredits:\n\t\t\t\n\n\n\t\t\t\tRishabh Jain (F-5)\n\n\t\t\t\tHimanshu Singh (F-5)\n\n\t\t\t\tAditya Shukla (F-5)\n");
		bk();
		break;
		}
	}}
	getch();
	closegraph();

}

int date_check(int d2,int m2,int y2)
//Date checking Function.
{int a[]={31,28,31,30,31,30,31,31,30,31,30,31};

if((m2==1||m2==2)&&(y2%4==0)&&(y2%100!=0))
	{a[1]=29;}
else if(y2%400==0)
		{a[1]=29;}
if(m2<13&&y2<=9999&&d2>0&&m2>0&&y2>=0)

return 1;

else {printf("\n\t\tThe Data that you have entered is invalid. \n\t\tPlease Try Again."); bk();
return 0;
}

	}
	int calf(int d,int m,int y)
	{int f;//Calculate the value of f:Date Code.
	f=(d+((y%100)/4)+(((y%100))%7)+8-((((y/100)%4)+1)*2))%7+mo[m-1];
		if((m==1||m==2)&&(y%4==0)&&(y%100!=0))
				{	f=f-1;
				}
			else if(y%400==0)
				{	f=f-1;
				}
		f=f%7;
			return f;
	}

void bk()
{
int i;int x,y;
x=getmaxx();
y=getmaxy();
	 setcolor(random(15)+1);
	 for(i=10;i>=0;i--)
	 rectangle(0+i,0+i,x-i,y-i);

}
