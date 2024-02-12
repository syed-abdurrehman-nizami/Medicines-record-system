#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<fstream>
#include<windows.h>
#include<vector>

using namespace std;

void owner();
void billmaker();
void worker();
void customer();

void addmedicine();
void search();
void delmed();
void showall();
void bill(int m);


void gotoxy(int x,int y);

struct med{
	string name;
	int rackno,quantity,price;
};
med phar;
vector<med> medics;

void save();
int a1=0;
int i;

int main()
{
	cout<<endl;
	cout<<"-----------------------------------------WELCOME TO THE PROGRAM OF PHARMACY MANAGEMENT SYSTEM.----------------------------------------"<<endl<<endl;
	A:
	while(1){
		cout<<"***************************************************  WELCOME TO THE MAIN MENU  *******************************************************"<<endl<<endl;
		cout<<endl;
		cout<<"                                             ********************************"<<endl;
		cout<<"                                            |                                |"<<endl;
		cout<<"                                            |     1 to use as billmaker      |"<<endl;
		cout<<"                                            |     2 to work on medicines.    |"<<endl;
		cout<<"                                            |     3 to use as customer.      |"<<endl;
		cout<<"                                            |     4 to exit the program.     |"<<endl;
		cout<<"                                            |                                |"<<endl;
		cout<<"                                             ********************************"<<endl;
		string a;
		cout<<endl<<"                                      ENTER HERE : ";
		cin>>a;
		
		system("cls");
		if(a=="1")
			billmaker();
		if(a=="2")
			worker();
		if(a=="3")
			customer();
		if(a=="4")
			exit(1);
		if(a!="1"&&a!="2"&&a!="3"&&a!="4")
			cout << "invalaid number." << endl;
			goto A;
	}
	return 0;
}
 
 
void billmaker()
{
	if(a1==1)
	{
		cout<<endl;	
		cout<<"------------------------------------------------------- WELCOME TO SALE MEDICINE -----------------------------------------------------";
		cout<<endl<<endl;
		A:
		cout<<"Search by name of medicine : ";
		string n;
		cin.ignore();
		getline(cin,n);
		for(i=0;i<medics.size();i++)
		{
			if(medics[i].name==n)
			{	
				cout<<"Quanity  : "<<medics[i].quantity<<endl;
				cout<<"Rack no  : "<<medics[i].rackno<<endl;
				cout<<"price    : "<<medics[i].price<<endl;
				cout<<endl;
				abc:
				cout<<"Enter quantity you want of "<<n<<" : ";
				int n1;
				cin>>n1;
				if(n1<=medics[i].quantity)
				{
					int q;
					q = n1*medics[i].price;
					cout<<endl;
					cout<<"-----------Bill of medicines-----------"<<endl;
					cout<<"NAME                 : "<<medics[i].name<<endl;
					cout<<"QUANTITY             : "<<n1<<endl;
					cout<<"PRICE OF 1 MEDICINE  : "<<medics[i].price<<endl<<endl;
					cout<<"TOTAL                : "<<q<<endl;
					cout<<"---------------------------------------"<<endl;
					medics[i].quantity = medics[i].quantity - n1;
					goto z;
				}
				else
				{
					cout<<"YOU HAVE NOT ENOUGH QUANTITY."<<endl;
					goto abc;
				}
		
			}	
		
		}
		cout<<" ___________________________"<<endl;
		cout<<"|     MEDICINE NOT FOUND    |"<<endl;
		cout<<"|___________________________|"<<endl;
		z:
		cout<<"                                                                                 1 to continue."<<endl;
		cout<<"                                                                                 2 to exit."<<endl;
		int ab;
		cout<<"                                                                                 ENTER HERE : ";
		cin>>ab;
		cout<<endl;
		if(ab==1)
		{
			goto A;
		}
		else if(ab==2)
		{
			cout<<"";	
			system("cls");
		}
		else
		{
			cout<<"invalaid"<<endl;
			goto z;	
		}
	}
	else
	{
	cout<<"ERROR! THE MEDICINES ARE NOT AVALAIBLE IN SYSTEM"<<endl;
	}
}
 
void worker()
{
		a1=1;
		A:
		cout<<endl;
		cout<<"----------------------------------------------------- WELCOME TO THE MEDICINE MENU ---------------------------------------------------";
		cout<<endl<<endl<<endl;
		cout<<"  _________________________________"<<endl;
		cout<<"||   1 to add medicines.           ||"<<endl;
		cout<<"||   2 to search medicines.        ||"<<endl;
		cout<<"||   3 to delete medicines.        ||"<<endl;
		cout<<"||   4 to save medicines in file.  ||"<<endl;
		cout<<"||   5 to show all medicines.      ||"<<endl;
		cout<<"||   6 to exit.                    ||"<<endl;
		cout<<"||_________________________________||"<<endl<<endl;
		int n;
		cout<<"Enter choice here : "; 
		cin>>n;
		system("cls");
		switch(n)
		{
			case 1:
				addmedicine();
				goto A;
				break;
			
			case 2:
				search();
				goto A;
				break;
			
			case 3:
				delmed();
				goto A;
				break;
				
			case 4:
				save();
				goto A;
				break;
				
			case 5:
				showall();
				goto A;
				break;
				
			case 6:
				break;
				
			default:
				cout<<"Please enter a valaid number"<<endl;
				goto A;
		}
	
}
 
void customer()
{
	system("cls");
	cout<<"------------------------------------------------------ WELCOME TO CUSTOMER SECTION ---------------------------------------------------";
	cout<<endl<<endl;
	A:
	cout<<"Search by name of medicine : ";
	string n;
	cin.ignore();
	getline(cin,n);
	for(i=0;i<medics.size();i++)
	{
		if(medics[i].name==n)
		{
			cout<<"|   AVALAIBLE   |"<<endl;
			goto a;
		}
	}
	cout<<"|   MEDICINE NOT AVALAIBLE   |"<<endl;
	a:
	cout<<"                                                                                 1 to continue."<<endl;
	cout<<"                                                                                 2 to exit."<<endl;
	int ab;
	cout<<"                                                                                 ENTER HERE : ";
	cin>>ab;
	if(ab==1)
	{
		goto A;
	}
	else if(ab==2)
	{
		cout<<"";
		system("cls");	
	}
	else
	{
		cout<<"invalaid"<<endl;
		goto a;
	}
}
 
 
void addmedicine()
{
	system("cls");
	cout<<"------------------------------------------------------- WELCOME TO ADD MEDICINES -----------------------------------------------------";
	cout<<endl<<endl<<endl;
	A:
		cout<<"||   Enter name of medicine      : ";
		cin.ignore();
		cin>>phar.name;
		
		cout<<"||   Enter rack of medicine      : ";
		cin.ignore();
		cin>>phar.rackno;
		
		cout<<"||   Enter quantity of medicine  : ";
		cin.ignore();
		cin>>phar.quantity;
		
		cout<<"||   Enter price of  medicine    : ";
		cin.ignore();
		cin>>phar.price;
		
		medics.push_back(phar);
		
		cout<<endl;
		cout<<" _____________________"<<endl;
		cout<<"|  Save successfully  |"<<endl;
		cout<<"|_____________________|"<<endl;
		az:
		cout<<"                                                                                 1 to continue."<<endl;
		cout<<"                                                                                 2 to exit."<<endl;
		int ab;
		cout<<"                                                                                 ENTER HERE : ";
		cin>>ab;
		cout<<endl;
		if(ab==1)
		{
			goto A;
		}
		else if(ab==2)
		{
			cout<<"";	
			system("cls");
		}
		else
		{
			cout<<"invalaid"<<endl;
			goto az;
		}
				
}
 
void search()
{
	cout<<endl;	
	cout<<"------------------------------------------------------ WELCOME TO SEARCH MEDICINE ----------------------------------------------------";
	cout<<endl<<endl;
	A:
	cout<<"Search by name of medicine : ";
	string n;
	cin.ignore();
	getline(cin,n);
	for(i=0;i<medics.size();i++)
	{
		if(medics[i].name==n)
		{
			cout<<"Quanity  : "<<medics[i].quantity<<endl;
			cout<<"Rack no  : "<<medics[i].rackno<<endl;
			cout<<"price    : "<<medics[i].price<<endl;
			cout<<endl;
			goto a;
		}
	}
	cout<<" ___________________________"<<endl;
	cout<<"|     MEDICINE NOT FOUND    |"<<endl;
	cout<<"|___________________________|"<<endl;
	a:
	cout<<"                                                                                 1 to continue."<<endl;
	cout<<"                                                                                 2 to exit."<<endl;
	int ab;
	cout<<"                                                                                 ENTER HERE : ";
	cin>>ab;
	if(ab==1)
	{
		goto A;
	}
	else if(ab==2)
	{
		cout<<"";
		system("cls");	
	}
	else
	{
		cout<<"invalaid"<<endl;
		goto a;
	}
}
 
void delmed()
{
	cout<<endl;
	cout<<"------------------------------------------------------ WELCOME TO DELETE MEDICINE ----------------------------------------------------";
	A:
	cout<<"Delete by name of medicine : ";
	string n;
	cin.ignore();
	getline(cin,n);
	for(i=0;i<medics.size();i++)
	{
		if(medics[i].name==n)
		{
			medics.erase(medics.begin()+i);
			cout<<" ___________________________"<<endl;
			cout<<"|    DELETED SUCCESSFULLY   |"<<endl;
			cout<<"|___________________________|"<<endl;
			goto a;
		}
	}
	cout<<endl<<"Medicine not found to delete."<<endl;
	a:
	cout<<"                                                                                 1 to continue."<<endl;
	cout<<"                                                                                 2 to exit."<<endl;
	int ab;
	cout<<"                                                                                 ENTER HERE : ";
	cin>>ab;	
	if(ab==1)
	{
		goto A;
	}
	else if(ab==2)
	{
		cout<<"";
		system("cls");	
	}
	else
	{
		cout<<"invalaid"<<endl;
		goto a;	
	}		
}
 
void save()
{
	ofstream savefile("medicines.txt");
	if(!savefile)
	{
		cout<<"FILE NOT FOUND";
	}
	else
	{
		for(i=0;i<medics.size();i++)
		{
			savefile<<"Name      : "<<medics[i].name<<endl;
			savefile<<"Quantity  : "<<medics[i].quantity<<endl;
			savefile<<"Rack no   : "<<medics[i].rackno<<endl;
			savefile<<"price     : "<<medics[i].price<<endl<<endl;
		}
	}
	savefile.close();
	cout<<" _______________________________________________"<<endl;
	cout<<"|    MEDICINES ARE SUCCESSFULLY SAVED TO FILE   |"<<endl;
	cout<<"|_______________________________________________|"<<endl;
	cout<<endl<<endl;
}
                                                 
void showall()
{
	system("cls");
	int a=2;
	cout<<"NAME                QUANTITY            PRICE          RACK NO "<<endl;
	for(i=0;i<medics.size();i++)
	{
		gotoxy(0,a);
		cout<<medics[i].name;
		gotoxy(20,a);
		cout<<medics[i].quantity;
		gotoxy(40,a);
		cout<<medics[i].price;
		gotoxy(55,a);
		cout<<medics[i].rackno;
		a++;
	}
	cout<<endl<<"______________________________________________________________________________________________________________________________";
	cout<<endl<<endl<<endl<<endl;
}
                                                  
void gotoxy(int x, int y)
{
    COORD A;
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    A.X=x;
    A.Y=y;
    SetConsoleCursorPosition(H,A);
}

