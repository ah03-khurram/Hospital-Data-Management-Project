#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<conio.h>
#include<stdio.h>
using namespace std;

struct doctor_info
{
	char name[50];
	char CNIC[15];
	char phone[15];
	string spec;
	string email;
	string dept;
	double salary;
};

struct nurse_info
{
	char name[50];
	char CNIC[15];
	char phone[15];
	string ward;
	string email;
	double salary;
};

struct patient {
	char name[50];
	int age;
	char gender;
	char CNIC[15];
	char phone[15];
	char address[150];
	string email;
	char relativesphone[15];
	char illness[50];
};

int main()
{
	doctor_info docinfo;
	nurse_info nurseinfo;
	patient patinfo;
	int choice1, choice_doc, choice_nurs, choice_patient, pat_ID, age, mob_no, doc, nurs, pat, choice_add;
	char choice2, gender, user_choice;
	string name, address, email_ID, med_prob, appoint, patname;

	do
	{
		cout << "Welcome to Hospital Management Software 2022. \n To view/edit \n 1. Staff Information press (1) \n 2. Patient's Information press(2)." << endl;
		cin >> choice1;
		system("cls");
		if (choice1 == 1)
		{
			cout << "Do you wish to check \n 1. Doctor's Information, press (D). \n 2. Nurse's Information, press (N)." << endl;
			cin >> choice2;

			if (choice2 == 'D' || choice2 == 'd') {
				cout << "Welcome to the Doctor's Menu :  \n Do you wish to: \n Search(1) \n Update(2) \n Add(3) \n Delete(4) \n Any of their data? " << endl;
				cin >> choice_doc;
				if (choice_doc == 1)
				{
					string input, docname;
					fstream docfile;
					cout << "Enter the doctor's name: ";
					cin.ignore();
					cin.getline(docinfo.name, 50);
					docname = docinfo.name;
					docfile.open(docname + ".txt", ios::in);

					if (docfile)
					{
						getline(docfile, input);
						while (docfile)
						{
							cout << input << endl;
							getline(docfile, input);
						}
						docfile.close();
					}
					else
					{
						cout << "Error " << endl;
					}
				}
				if (choice_doc == 2)
				{

					string input;
					fstream docfile;
					string temp;
					char newdocinfo[200];
					cout << "Select \n Add new information(1) \n Rewrite information(2) \nSelect: ";
					cin >> choice_add;
					cout << "Please enter the doctor's name: ";
					cin.ignore();
					cin.getline(docinfo.name, 50);
					temp = docinfo.name;
					if (choice_add == 1)
					{
						cout << "Add new information..........." << endl;
						cin.ignore();
						cin.getline(newdocinfo, 200);
						if (docfile)
						{
							docfile.open(temp + ".txt", ios::out | ios::app);
							docfile << endl;
							docfile << "The new information of the Doctor is: " << endl;
							docfile << newdocinfo << endl;
							docfile << endl;
							docfile.close();
						}
					}
					else if (choice_add == 2)
					{
						cout << "Enter the doctor's phone number: ";
						cin.ignore();
						cin.getline(docinfo.phone, 15);
						cout << "Please enter the CNIC of the Doctor: ";
						cin.ignore();
						cin.getline(docinfo.CNIC, 15);
						cout << "Enter the doctor's Email address: ";
						cin >> docinfo.email;
						cout << "Enter the speciality of the doctor: ";
						cin >> docinfo.spec;
						cout << "Enter doctor's department: ";
						cin >> docinfo.dept;
						cout << "Doctor's salary: ";
						cin >> docinfo.salary;
						string temp = docinfo.name;
						docfile.open(temp + ".txt", ios::out);

						if (!docfile.fail())
						{
							docfile << "Doctor's name is: " << docinfo.name << endl;
							docfile << "The doctor's CNIC number: " << docinfo.CNIC << endl;
							docfile << "The doctor's phone number :" << docinfo.phone << endl;
							docfile << "The speciality of Doctor is: " << docinfo.spec << endl;
							docfile << "The doctor's Email Address is: " << docinfo.email << endl;
							docfile << "The doctor's departement is: " << docinfo.dept << endl;
							docfile << "The doctor's salary is: " << docinfo.salary << endl;
							docfile.close();
						}
						else
						{
							cout << "Doctor Does not exist in the system..." << endl;
						}
					}
				}
				if (choice_doc == 3)
				{
					string input, docname;
					fstream docfile;
					cout << "Enter the doctor's name: ";
					cin.ignore();
					cin.getline(docinfo.name, 50);
					cout << "Enter the doctor's phone number: ";
					cin.ignore();
					cin.getline(docinfo.phone, 15);
					cout << "Please enter the CNIC of the Doctor: ";
					cin.ignore();
					cin.getline(docinfo.CNIC, 15);
					cout << "Enter the doctor's Email address: ";
					cin >> docinfo.email;
					cout << "Enter the speciality of the doctor: ";
					cin >> docinfo.spec;
					cout << "Enter doctor's department: ";
					cin >> docinfo.dept;
					cout << "Doctor's salary: ";
					cin >> docinfo.salary;
					string temp = docinfo.name;
					docfile.open(temp + ".txt", ios::out);

					if (!docfile.fail())
					{
						docfile << "Doctor's name is: " << docinfo.name << endl;
						docfile << "The doctor's CNIC number: " << docinfo.CNIC << endl;
						docfile << "The doctor's phone number :" << docinfo.phone << endl;
						docfile << "The speciality of Doctor is: " << docinfo.spec << endl;
						docfile << "The doctor's Email Address is: " << docinfo.email << endl;
						docfile << "The doctor's departement is: " << docinfo.dept << endl;
						docfile << "The doctor's salary is: " << docinfo.salary << endl;
						docfile.close();
					}

				}
				if (choice_doc == 4)
				{
					int status;
					string name;
					char docname[50];
					cout << "Enter the name of the doctor whose data you want to delete e.g: name + .txt \nName: ";
					cin >> docname;
					status = remove(docname);
					if (status == 0)
					{
						cout << "File Deleted" << endl;
					}
					else
					{
						cout << "Error" << endl;
					}
				}
			}
			else if (choice2 == 'N' || choice2 == 'n') {
				cout << "Welcome to the Nurse's Menu : \n Do you wish to: \n Search(1) \n Update(2) \n Add(3) \n Delete(4) \n any of their data? Please enter a valid choice." << endl;
				cin >> choice_nurs;
				if (choice_nurs == 1) {

					string input, nursname;
					fstream nursfile;
					cout << "Enter the nurse's name: ";
					cin.ignore();
					cin.getline(nurseinfo.name, 50);
					nursname = nurseinfo.name;
					nursfile.open(nursname + ".txt", ios::in);

					if (nursfile)
					{
						getline(nursfile, input);
						while (nursfile)
						{
							cout << input << endl;
							getline(nursfile, input);
						}
						nursfile.close();
					}
					else
					{
						cout << "Error " << endl;
					}



				}

				if (choice_nurs == 2) {
					string input;
					fstream nursfile;
					string temp;
					char newnursinfo[200];
					cout << "Select \n Add new information(1) \n Rewrite information(2) \nSelect: ";
					cin >> choice_add;
					cout << "Please enter the nurse's name: ";
					cin.ignore();
					cin.getline(nurseinfo.name, 50);
					temp = nurseinfo.name;
					if (choice_add == 1)
					{
						cout << "Add new information..........." << endl;
						cin.ignore();
						cin.getline(newnursinfo, 200);
						if (nursfile)
						{
							nursfile.open(temp + ".txt", ios::out | ios::app);
							nursfile << endl;
							nursfile << "The new information of the Nurse is: " << endl;
							nursfile << newnursinfo << endl;
							nursfile << endl;
							nursfile.close();
						}
					}
					else if (choice_add == 2)
					{
						cout << "Enter the nurse's name: ";
						cin.ignore();
						cin.getline(nurseinfo.name, 50);
						cout << "Enter the nurse's phone number: ";
						cin.ignore();
						cin.getline(nurseinfo.phone, 15);
						cout << "Please enter the CNIC of the Nurse: ";
						cin.ignore();
						cin.getline(nurseinfo.CNIC, 15);
						cout << "Enter the nurse's Email address: ";
						cin >> nurseinfo.email;
						cout << "Enter nurse's ward: ";
						cin >> nurseinfo.ward;
						cout << "Nurse's salary: ";
						cin >> nurseinfo.salary;
						string temp = nurseinfo.name;
						nursfile.open(temp + ".txt", ios::out);

						if (!nursfile.fail())
						{
							nursfile << "Nurse's name is: " << nurseinfo.name << endl;
							nursfile << "The nurse's CNIC number: " << nurseinfo.CNIC << endl;
							nursfile << "The nurse's phone number :" << nurseinfo.phone << endl;
							nursfile << "The nurse's Email Address is: " << nurseinfo.email << endl;
							nursfile << "The nurse's ward is: " << nurseinfo.ward << endl;
							nursfile << "The nurse's salary is: " << nurseinfo.salary << endl;
							nursfile.close();
						}
					}
				}

				if (choice_nurs == 3)
				{

					string input, nursname;
					fstream nursfile;
					cout << "Enter the nurse's name: ";
					cin.ignore();
					cin.getline(nurseinfo.name, 50);
					cout << "Enter the nurse's phone number: ";
					cin.ignore();
					cin.getline(nurseinfo.phone, 15);
					cout << "Please enter the CNIC of the Nurse: ";
					cin.ignore();
					cin.getline(nurseinfo.CNIC, 15);
					cout << "Enter the nurse's Email address: ";
					cin >> nurseinfo.email;
					cout << "Enter nurse's ward: ";
					cin >> nurseinfo.ward;
					cout << "Nurse's salary: ";
					cin >> nurseinfo.salary;
					string temp = nurseinfo.name;
					nursfile.open(temp + ".txt", ios::out);

					if (!nursfile.fail())
					{
						nursfile << "Nurse's name is: " << nurseinfo.name << endl;
						nursfile << "The nurse's CNIC number: " << nurseinfo.CNIC << endl;
						nursfile << "The nurse's phone number :" << nurseinfo.phone << endl;
						nursfile << "The nurse's Email Address is: " << nurseinfo.email << endl;
						nursfile << "The nurse's ward is: " << nurseinfo.ward << endl;
						nursfile << "The nurse's salary is: " << nurseinfo.salary << endl;
						nursfile.close();
					}

				}
				if (choice_nurs == 4)
				{


					int status;
					string name;
					char nursename[50];
					cout << "Enter the name of the nurse whose data you want to delete \ne.g: name + .txt: \nName: ";
					cin.ignore();
					cin.getline(nursename, 50);
					status = remove(nursename);
					if (status == 0)
					{
						cout << "File Deleted" << endl;
					}
					else
					{
						cout << "Error" << endl;
					}

				}
			}
			else
				cout << "Enter a valid choice." << endl;

		}
		else if (choice1 == 2)
		{
			cout << "Welcome to the Patient's Menu :\nDo you wish to: \n Search an old patient(1) \n Update an old patient's information(2) \n Add a new one(3) : ";
			cin >> choice_patient;
			system("cls");
			if (choice_patient == 1)
			{

				string input;
				fstream patfile;
				cout << "Enter the Patient's name: ";
				cin.ignore();
				cin.getline(patinfo.name, 50);
				patname = patinfo.name;
				patfile.open(patname + ".txt", ios::in);

				if (patfile)
				{
					getline(patfile, input);
					while (patfile)
					{
						cout << input << endl;
						getline(patfile, input);
					}
					patfile.close();
				}
				else
				{
					cout << "Error " << endl;
				}
			}

			if (choice_patient == 2)
			{
				string input;
				fstream patfile;
				string temp;
				char newpatinfo[200];
				cout << "Enter the name of the patient: ";
				cin.ignore();
				cin.getline(patinfo.name, 50);
				temp = patinfo.name;
				cout << "Add new information..........." << endl;
				cin.ignore();
				cin.getline(newpatinfo, 200);
				if (patfile)
				{
					patfile.open(temp + ".txt", ios::out | ios::app);
					patfile << endl;
					patfile << "The new information of the Patient is: " << endl;
					patfile << newpatinfo << endl;
					patfile << endl;
					patfile.close();
				}
			}


			else if (choice_patient == 3)
			{
				string input, patname, temp;
				fstream patfile;
				cout << "Enter the patient's ID: ";
				cin >> pat_ID;
				cout << "Enter the patient's name: ";
				cin.ignore();
				cin.getline(patinfo.name, 50);
				cout << "Enter the age of patient: ";
				cin >>  patinfo.age;
				cout << "Enter the gender of patient: (M/F/O) ";
				cin >> patinfo.gender;
				cout << "Enter the patient illness : ";
				cin.ignore();
				cin.getline(patinfo.illness, 50);
				cout << "Enter the patient's phone number: ";
				cin.ignore();
				cin.getline(patinfo.phone, 15);
				cout << "Please enter the CNIC of the patient: ";
				cin.ignore();
				cin.getline(patinfo.CNIC, 15);
				cout << "Enter the patient's Email address: ";
				cin >> patinfo.email;
				cout << "Enter the patient's home address: ";
				cin.ignore();
				cin.getline(patinfo.address, 150);
				cout << "Enter any relative's phone number: ";
				cin.ignore();
				cin.getline(patinfo.relativesphone, 15);
				temp = patinfo.name;
				patfile.open(temp + ".txt", ios::out);

				if (!patfile.fail())
				{
					patfile << "Patient's ID is: " << pat_ID << endl;
					patfile << "Patient's name is: " << patinfo.name << endl;
					patfile << "Patient's age is: " << patinfo.age << endl;
					patfile << "Patient's gender is: " << patinfo.gender << endl;
					patfile << "Patient's illness is: " << patinfo.illness << endl;
					patfile << "The Patient's CNIC number: " << patinfo.CNIC << endl;
					patfile << "The Patient's phone number:" << patinfo.phone << endl;
					patfile << "The Patient's Email Address is: " << patinfo.email << endl;
					patfile << "The Patient's home address is: " << patinfo.address << endl;
					patfile << "The relative contact numner of the patient is: " << patinfo.relativesphone << endl;

					patfile.close();
				}

			}

		}
		else
		{
			cout << "Enter a valid choice." << endl;
		}


		cout << "Do you wish to look through the Menu again? (Y/N): " << endl;
		cin >> user_choice;
		system("cls");

	} while (user_choice == 'Y' || user_choice == 'y');



	system("pause");
	return 0;
}
