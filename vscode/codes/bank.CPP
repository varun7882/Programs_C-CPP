#include<fstream.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>



class bank
{
int acno;
char name[25];
char type;
float amount;
int available;
public:
void indata();
void outdata();
void addrec();
void listrec();
void delrec();
void depamt();
void withamt();
int search();
};




void bank::delrec()
{
	ifstream f1("bank.dat",ios::binary);
	ofstream f2("tmp.dat",ios::binary);
	int f=0;
	int an;
	bank x;
	cout<<"\n\n\tENTER THE ACCOUNT NO. TO BE DELETED : ";
	cin>>an;
	while(f1.read((char*)&x,sizeof(x)))
	{
		if(x.acno!=an)
			f2.write((char*)&x,sizeof(x));
		else
			f=1;
	}
	f1.close();
	f2.close();
	if(f==1)
	{
		remove("bank.dat");
		rename("tmp.dat","bank.dat");
		cout<<"\n\n\n\t\t\tACCOUNT CLOSED SUCCESSFULLY...... ";
	}
	else
		cout<<"\n\n\n\t\t\tACCOUNT NOT FOUND....!!!! ";
	getch();
}


void bank::depamt()
{
	ifstream f1("bank.dat",ios::binary);
	ofstream f2("tmp.dat",ios::binary);
	int f=0;
	int bk;
	int b=0;
	bank x;
	cout<<"\n\n\tENTER THE ACCOUNT NO. TO BE UPDATED : ";
	cin>>bk;

	while(f1.read((char*)&x,sizeof(x)))
	{
		if(x.acno==bk)
		{
			cout<<"\n\tENTER THE AMOUNT TO BE ADDED: ";
			cin>>b;
			x.amount=b+x.amount;
			f=1;
		}
		f2.write((char*)&x,sizeof(x));
	}
	f1.close();
	f2.close();
	if(f==1)
	{
		remove("bank.dat");
		rename("tmp.dat","bank.dat");
		cout<<"\n\n\n\t\t\tACCOUNT UPDATED SUCCESSFULLY.... ";
	}
	else
		cout<<"\n\n\n\t\t\tACCOUNT NOT FOUND.....!!!!! ";
getch();

}


void bank::withamt()
{
	ifstream f1("bank.dat",ios::binary);
	ofstream f2("tmp.dat",ios::binary);
	int f=0;
	int an;
	int b=0;
	bank x;
	cout<<"\n\n\tENTER THE ACCOUNT NO. TO BE UPDATED : ";
	cin>>an;

	while(f1.read((char*)&x,sizeof(x)))
	{
		if(x.acno==an)
		{
			cout<<"\n\tENTER THE AMOUNT TO BE WITHDRAWN: ";
			cin>>b;
			if(x.amount-b>=500)
			{
			 x.amount=x.amount-b;
			 f=1;
			}
			else
			{
			 cout<<"\n\tYOU CANNOT WITHDRAW THIS MUCH OF AMOUNT";
			 f=2;
			 break;
			}
		}
		f2.write((char*)&x,sizeof(x));
	}
	f1.close();
	f2.close();
	if(f==1)
	{
		remove("bank.dat");
		rename("tmp.dat","bank.dat");
		cout<<"\n\n\n\t\t\tACCOUNT UPDATED SUCCESSFULLY.... ";
	}
	else if(f==2)
	cout<<"\n\t\tPLEASE PROCEED AGAIN";
	else
		cout<<"\n\n\n\t\t\tACCOUNT NOT FOUND.....!!!!! ";
getch();

}



void bank::addrec()
{
	ofstream f("bank.dat",ios::binary|ios::app);
	bank x;
	x.indata();
	f.write((char *)&x, sizeof(x));
	f.close();
}

void bank::listrec()
{
	ifstream f("bank.dat",ios::binary);
	bank x;
	cout<<"\n\n\t\t\t    ***** ACCOUNT LIST *****";
	while(f.read((char*)&x,sizeof(x)))
	{
		x.outdata();
	}
	f.close();
	getch();
}

int bank::search()
{
	ifstream f("bank.dat",ios::binary);
	bank x;
	int y=0;
	char sb[25];
	int a;
	cout<<"\n\n\tENTER THE ACCOUNT NO. : ";
	cin>>a;
	while(f.read((char*)&x,sizeof(x)))
	{
		if(x.acno==a)
		{
			cout<<"\n\n\t\t\t****ACCOUNT DETAILS****";
			x.outdata();
			y=1;
			break;
		}
	}
	f.close();
	return(y);
}


void bank::indata()
{
	cout<<"\n\n\n********************************************************************************";
	cout<<"\t\t\tENTER ACCOUNT DETAILS";
	cout<<"\n********************************************************************************";
	int a;
	cout<<"\n\n\tENTER THE ACCOUNT NO.                      : ";
	cin>>acno;
	cout<<"\tENTER THE ACCOUNT HOLDER NAME              : ";
	gets(name);
	cout<<"\tTYPE OF  THE ACCOUNT(C/S)       	   : ";
	cin>>type;
	tolower(type);
	int x=4;
	while(x==4)
	{
	switch(type)
	{
	case 'c':
	case 's':x=2;
	    break;
	default :cout<<"\tPLEASE TYPE C OR S      	           : ";
	    cin>>type;
	}
	}


	cout<<"\tENTER THE INITIAL AMOUNT\n";
	cout<<"\t(>=500 FOR SAVING AND >=1000 FOR CURRENT ) : ";
	cin>>amount;
	int q=4;
	while(q==4)
	{
	if(type=='c')
	{
		if(amount>=1000)
		{
		q=2;
		}
		else
		{
		cout<<"\tPLEASE ENTER A VALUE >=1000                : ";
		cin>>amount;
		}
	}
	else
	{
		if(amount>=500)
		{
		q=2;
		}
		else
		{
		cout<<"\tPLEASE ENTER A VALUE >=500                 : ";
		cin>>amount;
		}
	 }
	}

	cout<<"\n\n\n\t\t\tACCOUNT CREATED SUCCUSSFULLY........";
	getch();
}



void bank::outdata()
{
	cout<<"\n\n\tACCOUNT NO.         : "<<acno;
	cout<<"\n\tACCOUNT HOLDER NAME : "<<name;
	cout<<"\n\tTYPE OF ACCOUNT     : "<<type;
	cout<<"\n\tBALANCE AMOUNT      : "<<amount;
}

void intro();

void main()
{
	int ch;
	bank x;
	clrscr();
	intro();
	do
	{
		clrscr();
		cout<<"\n\n\n\n\n********************************************************************************";
		cout<<"\t\t\t\tMAIN MENU";
		cout<<"\n********************************************************************************\n\n";
		cout<<"\n\t\t\t1. OPEN NEW ACCOUNT";
		cout<<"\n\t\t\t2. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t3. DEPOSIT AMOUNT ";
		cout<<"\n\t\t\t4. WITHDRAW AMOUNT ";
		cout<<"\n\t\t\t5. DISPLAY ALL ACCOUNTS";
		cout<<"\n\t\t\t6. BALANCE ENQUIRY";
		cout<<"\n\t\t\t7. EXIT........";
		cout<<"\n\n\t\t\tCHOOSE YOUR OPTION(1-8) ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
		case 1:x.addrec();
			break;
		case 2:x.delrec();
			break;
		case 3:x.depamt();
			break;
		case 4:x.withamt();
			break;
		case 5:x.listrec();
			break;
		case 6:if(x.search()==0)
			cout<<"\n\n\t\tNOT AVAILABLE";
			getch();
		}
	}
while(ch!=7);
}


void intro()
{
	cout<<"\n\n\n\n\n********************************************************************************";
	cout<<"\n\t\t\t  BANK MANAGEMENT SYSTEM";
	cout<<"\n\n********************************************************************************";
	cout<<"\n\n\n\t\t\tMADE BY : VISHAL SHARMA ";
	cout<<"\n\n\t\t\tSCHOOL  : DAV PUBLIC SCHOOL";
	getch();
}