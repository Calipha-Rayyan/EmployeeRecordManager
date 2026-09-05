#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
#include<windows.h>
using namespace std;


struct employee
{
	char name[40];
	int id;

};

employee emp[50];
int n = 0;

//////////////////////////////////////
//////function prototypes/////////////
//////////////////////////////////////
void gotoxy(short, short); // 
void display(employee[],int&);	// for record displaying
void add(employee[],int&);
void search(employee[],int&);
void sort(employee[],int&);
void del(employee[],int&);
void modify(employee[],int&);

//////////////////////////////////////
///////////////////main///////////////
/////////////////////////////////////
int main()
{
	char ch1;
	while (1)
	{
		system("cls");

		cout << setw(25) << "-------------" << endl

			<< setw(25) << "| MAIN MENU |" << endl

			<< setw(25) << "-------------" << endl << endl

			<< setw(52)

			<< "Please choose one of the options below: "

			<< endl << setw(71)

			<< "--------------------------------------------------------------"

			<< endl << endl



			<< setw(25) << "( A ) add record" << endl << endl

			<< setw(31) << "( O ) sort all records" << endl << endl

			<< setw(34) << "( S ) search for a record" << endl << endl

			<< setw(31) << "( D ) display a record" << endl << endl

			<< setw(32) << "( T ) delete / undelete" << endl << endl

			<< setw(28) << "( M ) update record" << endl << endl

			<< setw(19) << "( Q ) Quit" << endl << endl
			<< setw(30) << "Enter Option      [ ]" << endl << endl;
		gotoxy(28, 21);
		//	cin>>ch1;




		switch (getche())
			//switch(ch1)
		{
		case 'a':
		case 'A':add(emp,n);break;

		case 'd':
		case 'D': display(emp,n);break;

		case 'S':
		case 's':search(emp,n);break;

		case 't':
		case 'T':del(emp,n);break;

		case 'O':
		case 'o':sort(emp,n);break;

		case 'm':
		case 'M':modify(emp,n);break;

		case 'q':
		case 'Q':exit(0);break;
		default:
			puts("\n enter only from selection listed");
		} //end switch
	}//end while

	getch();
}//end main

//////////////////////////////////////
///////////////////Display///////////////
/////////////////////////////////////

void display(employee emp[], int& n)
{
	system("cls");
	cout << "in display function\n";
	cout << setw(10) << " Name:" << setw(20) << "Id:" << endl;
	cout << setw(10) << "-------" << setw(20) << "----" << endl;
	for (int i = 0;i < n;i++)
	{
		cout << setw(10) << emp[i].name << setw(20) << emp[i].id << endl;
	}

	cout << "Press enter to goto main manu.....";
	getch();

}


//////////////////////////////////////
///////////////////Add///////////////
/////////////////////////////////////
void add(employee emp[], int& n)
{
	char ch;char id1[15];
	do
	{
		system("cls");
		cout << endl;
		cout << "in ADD function\n";
		cout << "enter name:";
		//gets(emp[n].name);
		cin.getline(emp[n].name,40);
		//cin.ignore(40,'\n');
		cout << "eneter ID:";
		//gets(id1);
		cin.getline(id1,15);
		emp[n].id = atoi(id1);
		//cin.ignore();
		n++;
		cout << "do you want to add more recors [y/n]";
		ch = getch();
	} while (ch != 'n'&& ch != 'N');
}

//////////Search////////////////////
void search(employee emp[], int& n)
{
	system("cls");
		cout << "in SEARCH function\n";

		char choice;
		cout << "Do you want to search by Name(N) or ID(I)? ";
		cin >> choice;

		if (choice == 'N'|| choice == 'n')
		{
			bool found=false;
			char searchName[40];
			cout << "Enter name to search: ";
			cin.ignore();  
			cin.getline(searchName, 40);

			for (int i = 0; i < n; i++) 
			{
				//	bool found=false;
				if (strcmp(emp[i].name, searchName) == 0) 
				{
					cout << "Record Found:\n";
					found=true;
					cout << "Name: " << emp[i].name << "\nID: " << emp[i].id << endl;
					break;
				}
		
			}
				if(found==false)
				{
					cout<<"Record not Found:\n";
				}
		}
		else if (choice == 'I' || choice == 'i')
		{
			bool found=false;
			int searchId;
			cout << "Enter ID to search: ";
			cin >> searchId;

			for (int i = 0; i < n; i++)
			{
				//bool found=false;
				if (emp[i].id == searchId)
				{
					cout << "Record Found:\n";
					found=true;
					cout << "Name: " << emp[i].name << "\nID: " << emp[i].id << endl;
					break;
				}
				
			}
			if(found==false)
				{
					cout<<"Record not Found:\n";
				}
		}
		else 
		{
			cout << "Invalid choice. Please enter 'N' or 'I' for Name or ID search.\n";
		}

		cout << "Press enter to go to the main menu.....";
		getch();
	

}

//////////sort///////////////////////
void sort(employee emp[], int& n)
{
		system("cls");
		cout << "in SORT function\n";

		char choice;
		cout << "Do you want to sort by Name(N) or ID(I)? ";
		cin >> choice;

		if (choice == 'N' || choice == 'n') 
		{
			for (int i = 0; i < n - 1; i++) 
			{
				for (int j = 0; j < n - i - 1; j++)
				{
					if (strcmp(emp[j].name, emp[j + 1].name) > 0)
					{
						employee temp = emp[j];
						emp[j] = emp[j + 1];
						emp[j + 1] = temp;
					}
				}
			}

			cout << "Records sorted by Name\n";
		}
		else if (choice == 'I' || choice == 'i') 
		{
			for (int i = 0; i < n - 1; i++) 
			{
				for (int j = 0; j < n - i - 1; j++)
				{
					if (emp[j].id > emp[j + 1].id)
					{
						employee temp = emp[j];
						emp[j] = emp[j + 1];
						emp[j + 1] = temp;
					}
				}
			}

			cout << "Records sorted by ID\n";
		}
		else 
		{
			cout << "Invalid choice. Please enter 'N' or 'I' for Name or ID sorting.\n";
		}

		display(emp,n); 

		cout << "Press enter to go to the main menu.....";
		getch();
	

}

////////////Delete//////////////////////
void del(employee emp[], int& n)
{
		system("cls");
		cout << "in DELETE function\n";

		char choice;
		cout << "Do you want to delete by Name(N) or ID(I)? ";
		cin >> choice;

		if (choice == 'N' || choice == 'n')
		 {
    	    char deleteName[40];
        	cout << "Enter name to delete: ";
        	cin.ignore();
        	cin.getline(deleteName, 40);

        for (int i = 0; i < n; i++)
		 {
            if (strcmp(emp[i].name, deleteName) == 0)
			 {
                for (int j = i; j < n - 1; j++) 
				{
                    strcpy(emp[j].name, emp[j + 1].name);
                    emp[j].id = emp[j + 1].id;
                }
                emp[n - 1].name[i] = '\0'; 
                emp[n - 1].id = -1;
                cout << "Record Deleted\n";
                n--; 
                break;
            }
        }
    } 
	else if (choice == 'I' || choice == 'i') 
	{
        int deleteId;
        cout << "Enter ID to delete: ";
        cin >> deleteId;

        for (int i = 0; i < n; i++) 
		{
            if (emp[i].id == deleteId) 
			{
                for (int j = i; j < n - 1; j++)
				 {
                    strcpy(emp[j].name, emp[j + 1].name);
                    emp[j].id = emp[j + 1].id;
                }
                emp[n - 1].name[i] = '\0'; 
                emp[n - 1].id = -1;
                cout << "Record Deleted\n";
                n--; 
                break;
            }
        }
    }
	 else 
	 {
        cout << "Invalid choice. Please enter 'N' or 'I' for Name or ID deletion.\n";
    }
		cout << "Press enter to go to the main menu.....";
		getch();
	

}

///////////Modify//////////////////////
void modify(employee emp[], int& n)
{
		system("cls");
		cout << "in MODIFY function\n";

		char choice;
		cout << "Do you want to modify by Name(N) or ID(I) ? ";
		cin >> choice;

		if (choice == 'N' || choice == 'n')
		{
			char modifyName[40];
			cout << "Enter name to modify: ";
			cin.ignore(); 
			cin.getline(modifyName, 40);

			bool found=false;
			for(int i=0;i<n;i++)
			{
			//	bool found=false;
				if (strcmp(emp[i].name, modifyName) == 0)
				{
					cout<<"\n Record Found: \n";
					found=true;
					cout << setw(10) << " Name:" << setw(20) << "Id:" << endl;
					cout << setw(10) << "-------" << setw(20) << "----" << endl;
					cout << setw(10) << emp[i].name << setw(20) << emp[i].id << endl;
					//display(emp,n);
					cout<<"IF YOU WANT TO MODIFY THE RECORD : THEN PRESS THE ONLY KEY 'Y' ==> ";
					cin>>choice;
				//	getch();
					if(choice =='Y' || choice == 'y')
					{
						cout << "Enter new name: ";
						cin.ignore();  
						cin.getline(emp[i].name, 40);
						cout << "Enter new ID: ";
						//	cin.ignore();
						cin >> emp[i].id;
						cout << "Record Modified\n";
						break;
					}
					
				}
					
			}
			if (found==false)
				{
					cout<<"\n Record not Found: \n";
				}
		/*	for (int i = 0; i < n; i++)
			{
				if (strcmp(emp[i].name, modifyName) == 0) 
				{
					cout<<"\n Record Found \n:";
					display(emp,n);
					
					cout << "Enter new name: ";
					cin.ignore();  
					cin.getline(emp[i].name, 40);
					cout << "Enter new ID: ";
				//	cin.ignore();
					cin >> emp[i].id;
					cout << "Record Modified\n";
					break;
				}
			}*/
		}
		else if (choice == 'I' || choice == 'i')
		{
			int modifyId;
			cout << "Enter ID to modify: ";
			cin >> modifyId;
			
			bool found=false;
			for(int i=0;i<n;i++)
			{
				//bool found=false;
				if (emp[i].id == modifyId)
				{
					cout<<"\n Record Found: \n";
					found=true;
					cout << setw(10) << " Name:" << setw(20) << "Id:" << endl;
					cout << setw(10) << "-------" << setw(20) << "----" << endl;
					cout << setw(10) << emp[i].name << setw(20) << emp[i].id << endl;
	
					//display(emp,n);
					cout<<"IF YOU WANT TO MODIFY THE RECORD : THEN PRESS THE KEY 'Y' ==> ";
					cin>>choice;
					if(choice =='Y' || choice == 'y')
					{
						cout << "Enter new name: ";
						cin.ignore();  
						cin.getline(emp[i].name, 40);
						cout << "Enter new ID: ";
						//	cin.ignore();
						cin >> emp[i].id;
						cout << "Record Modified\n";
						break;
					}
					
				}
					
			}
			if (found==false)
				{
					cout<<"\n Record not Found: \n";
				}
		/*	for (int i = 0; i < n; i++) 
			{
				if (emp[i].id == modifyId) 
				{
					cout << "Enter new name: ";
					cin.ignore(); 
					cin.getline(emp[i].name, 40);
					cout << "Enter new ID: ";
				//	cin.ignore();
					cin >> emp[i].id;
					cout << "Record Modified\n";
					break;
				}
			}*/
		}
		else
		{
			cin.ignore();
			cout << "Invalid choice. Please enter 'N' or 'I' for Name or ID modification.\n";
		}
		
		cout << "Press enter to go to the main menu.....";
		getch();
}

////////////////////////////////////////
/////////////////gotoxy //////////////////////////
void gotoxy(short x, short y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
////////////////////////////////////////// 