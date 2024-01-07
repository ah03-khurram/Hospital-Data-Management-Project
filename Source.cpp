#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

//TASK 1

void increment_function(int*);
int main()
{
	int arr[5];
	
	cout << "Enter the elements if the array: " << endl;
	
	for (int i = 0; i < 5; i++) 
	{
		cout << "arr[" << i << "]: ";
		cin >> arr[i];
	}
	cout << endl;

	increment_function(arr);

	cout << "The array increment array is: " << endl;
	for (int i = 0; i < 5; i++) 
	{
		cout << "arr[" << i << "]: " << arr[i] << endl;
	}

	system("pause");
	return 0;
}

void increment_function(int* ptr) 
{
	int a;
	for (int i = 0; i < 5; i++)
	{
		a = *(ptr + i) + 1;
		*(ptr + i) = a;

	}
}

//************************************************************************************************************************************************************

//Task 2

struct family
{
	char name[50];
	int age;
	int CNIC;
	int time;
};

int main()
{
	int bill;
	family data;
	string temp;
	string ride;
	int ticket;
	int choice;
	char namet[50];
	int aget;
	int CNICt;
	int timet;
	char swingt[50];
	int members, family[40];
	string swing1 = "Discovery ride";
	string swing2 = "maryland swing";
	cout << "Enter the no. of family members: ";
	cin >> members;
	for (int i = 0; i < members; i++) 
	{
		cout << "Enter the name of the family member: ";
		cin.ignore();
		cin.getline(data.name, 30);
		cout << "Enter the age: ";
		cin >> aget;
		cout << "Enter CNIC: ";
		cin.ignore();
		cin >> CNICt;
		cout << "Enter the no. of hours you want to spend: ";
		cin >> timet;
		cout << "Please select the swing: " << endl;
		cout << "1). Discovery ride(1) \n2). maryland swing(2) \nchoice: ";
		cin >> choice;
		switch (choice) 
		{
		case 1:
		{
			ride = swing1;

			if (aget >= 5 && aget <= 15) 
			{
				ticket = 90;
			}
			else if (aget >= 15 && aget <= 20) 
			{
				ticket = 95;
			}
			else if (aget < 5) 
			{
				cout << "You are not allowed to take ride....." << endl;
				ticket = 0;
			}
			else if (aget > 20) 
			{
				ticket = 100;
			}
			break;
		}
		case 2: 
			
		{
			ride = swing2;
			if (aget >= 5 && aget <= 10)
			{
				ticket = 75;
			}
			else if (aget > 10)
			{
				ticket = 100;
			}
			else if (aget < 5)
			{
				ticket = 50;
			}
			break;
		}
		}
		data.age = aget;
		data.time = timet;
		data.CNIC = CNICt;
		bill = ticket + (data.time * 10);
		cout << "Your Bill is: " << bill << endl;
		temp = data.name;
		fstream joyland;
		joyland.open(temp + ".txt", ios::out);
		joyland << "Name of the member: " << data.name << endl;
		joyland << "Age of the member: " << data.age << endl;
		joyland << "CNIC of member: " << data.CNIC << endl;
		joyland << "Ride taken: " << ride << endl;
		joyland << "Total Bill: " << bill << endl;
		joyland.close();
		joyland.open("people.txt", ios::out | ios::app);
		joyland << "Name of the member: " << data.name << endl;
		joyland << "Age of the member: " << data.age << endl;
		joyland << "CNIC of member: " << data.CNIC << endl;
		joyland << "Ride taken: " << ride << endl;
		joyland << "Total Bill: " << bill << endl;
		joyland << endl;
		joyland.close();
		fstream billwhole;
		billwhole.open("bill.txt", ios::out | ios::app);
		billwhole << "Bill of " << data.name << "is: " << bill << endl;
		billwhole.close();
	}
	fstream billwhole;
	string input;
	billwhole.open("bill.txt", ios::in);
		if (billwhole) 
		{
			getline(billwhole, input);
			while (billwhole) 
			{
				cout << input << endl;
				getline(billwhole, input);

			}
		}
		billwhole.close();

	system("pause");
	return 0;
}