// tamrin jalase 7-8.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<string>
#include<iomanip>
using namespace std;
multimap<string,string>savep;
class Person 
{
protected:
	string Name, Family,Phonenumber,Age;
public:
	   Person(){}
	   Person(string Name, string Family, string Phonenumber, string  Age)
{
	this->Name = Name;
	this->Family = Family;
	this->Phonenumber = Phonenumber;
	this->Age = Age;
}
	   void setName(string Name)
	   {
		   this->Name = Name;
	   }
	   void setFamily(string Family)
	   {
		   this->Family = Family;
	   }
	   void setPhonumber(string Phonenumber)
	   {
		   this->Phonenumber = Phonenumber;
	   }
	   void setAge(string Age)
	   {
		   this->Age = Age;
	   }

	   string getName()
	   {
		   return Name;
	   }
	   string getFamily()
	   {
		   return Family;
	   }
	   string getPhonumber()
	   {
		   return Phonenumber;
	   }
	   string getAge()
	   {
			return Age;
	   }
	   void print1()
	   {
		   cout << "NAME:("<<Name << ")" << setw(6) << " " << "FAMILY:("<<Family<<")" << setw(6) << " " <<"MOBILE PHONE:("<<Phonenumber<<")" << setw(6) << " " <<"AGE:("<<Age<<")" << endl;
	   }
};
class Patient :public Person
{
private:string kind, ndoctor, fdoctor,codep, doctorcod;
		static int number;
public:Patient() { number++; }
	   Patient(string Name, string Family, string Phonenumber, string Age, string codep, string kind,string ndoctor,string fdoctor, string doctorcod) :Person(Name, Family, Phonenumber, Age)
	   {
		   this->codep = codep;
		   this->kind = kind;
		   this->ndoctor = ndoctor;
		   this->fdoctor = fdoctor;
		   this->doctorcod = doctorcod;
	  }
	   void setCodep(string codep)
	   {
		   this->codep = codep;
	   }
	   void setKind(string kind)
	   {
		   this->kind = kind;
	   }
	   void setndoctor(string ndoctor)
	   {
		   this->ndoctor = ndoctor;
	   }
	   void setfdoctor(string fdoctor)
	   {
		   this->fdoctor = fdoctor;
	   }
	   void setDoctorcod(string doctorcod)
	   {
		   this->doctorcod = doctorcod;
	   }
	   string getCodep()
	   {
		   return codep;
	   }
	   string getKind()
	   {
		   return kind;
	   }
	   string getndoctor()
	   {
		   return ndoctor;
	   }
	   string getfdoctor()
	   {
		   return fdoctor;
	   }
	   string getDoctorcod()
	   {
		   return doctorcod;
	   }
	   static int getNumber()
	   { return number; }
	   void print2()
	   {
		   cout << "NAME:(" << Name << ")" << setw(6) << " " << "FAMILY:(" << Family << ")" << setw(6) << " " << "MOBILE PHONE:(" << Phonenumber << ")" << setw(6) << " " << "AGE:(" << Age << ")" << setw(6) << "  " <<"CODE:("<< codep<<")" << setw(6) << " " <<"KIND:("<< kind <<")"<< setw(6) << "  " <<"DOCTOR NAME:("<< ndoctor <<")"<< "   " << "DOCTOR FAMILY:("<<fdoctor<<")"<<setw(6) << " " << "DOCTOR CODE:(" << doctorcod << ")" "\n";
	   }

};
int Patient::number = 0;
class Doctor :public Person
{
private: 
	    string filed,coded;
		static int count;
public:Doctor() { count++; }
	   Doctor(string Name, string Family, string Phonenumber, string Age, string coded, string field) :Person(Name, Family, Phonenumber, Age)
	   {
		   this->coded = coded;
		   this->filed = field;
	   }
	   void setCoded(string coded)
	   {
		   this->coded = coded;
	   }
	   void setFiled(string field)
	   {
		   this->filed = filed;
	   }
	   string getCoded()
	   {
		   return coded;
	   }
	   string getFiled()
	   {
		   return filed;
	   }
	  static int getCount() { return count; }
	   void print3()
	   {
			   cout << "NAME:(" << Name << ")" << setw(6) << " " << "FAMILY:(" << Family << ")" << setw(6) << " " << "MOBILEPHONE:("<<Phonenumber<<")" << setw(6) << " " << "AGE:("<<Age<<")" << setw(6) << "  " <<"DOCTORCODE:("<< coded <<")" <<setw(6) << " " <<"SPECIALITY:( "<<filed <<")"<< endl;
	   }
};
int Doctor::count = 0;
//*************************************************
//                PERSON CLASS
//*************************************************
vector<Person>m1, m2;

void write()
{
	fstream outputperson;
	string Name, Family, Phonenumber;
	string Age;
	cout << "ENTER YOUR NAME:";
	cin >> Name;
	cout << "ENTER YOUR FAMILY:";
	cin >> Family;
	cout << "ENTER YOUR PHONENUMBER:";
	cin >> Phonenumber;
	cout << "ENTER YOUR AGE:";
	cin >> Age;
	m1.push_back(Person(Name, Family, Phonenumber, Age));
	outputperson.open("Person.csv", ios::app);
	outputperson << Name + "," + Family + "," + Phonenumber + "," + Age << endl;
}

//*************************************************
//               PATIENT CLASS
//*************************************************
vector<Patient>listp1, listp2;
void writep()
{
	Patient p;
	fstream outputpatient;
	string Name, Family, Phonenumber, kind, ndoctor, fdoctor;
	string Age, codep, doctorcod;
	cout << "\nENTER YOUR NAME:";
	cin >> Name;
	cout << "\nENTER YOUR FAMILY:";
	cin >> Family;
	cout << "\nENTER CODE OF PATIENT:";
	cin >> codep;
	for (int i = 0; i < listp1.size(); i++)
	{
		if (listp1[i].getCodep() == codep)
			while (true)
			{
				cout << "this code enter by someone!\n";
				cout << "please enter another code:";
				cin >> codep;
				if (listp1[i].getCodep() != codep)
					break;
			}
	}
	cout << "\nENTER YOUR PHONENUMBER:";
	cin >> Phonenumber;
	cout << "\nENTER YOUR AGE:";
	cin >> Age;
	cout << "\nENTER KIND OF ILL:";
	cin >> kind;
	cout << "\nENTER NAME OF PATIENT'S DOCTOR:";
	cin >> ndoctor;
	cout << "\nENTER FAMILY OF PATIEMT'S DOCTOR:";
	cin >> fdoctor;
	cout << "\nENTER CODE OF PATIEMT'S DOCTOR:";
	cin >> doctorcod;
	listp1.push_back(Patient(Name, Family, Phonenumber, Age, codep, kind, ndoctor, fdoctor, doctorcod));
	outputpatient.open("Patient.csv", ios::app);
	outputpatient << Name + "," + Family + "," + Phonenumber + "," + Age + "," + codep + "," + kind + "," + ndoctor + "," + fdoctor + "," + doctorcod<< endl;
}
void editp(string codep)
{
	int answer5;
	string Name, Family, Phonenumber, ndoctor, fdoctor;
	string code;
	for (int i = 0; i < listp1.size(); i++)
	{
		if (listp1[i].getCodep() == codep)
		{
			cout << "YOU WANT WHICH PART EDIT?\n";
			cout << "1.NAME:\n";
			cout << "2.FAMILY:\n";
			cout << "3.PHONENUMBER:\n";
			cout << "4.CODE:\n";

			cout << "5.BACK TO MENUE:\n";
			cout << "ENTER YOUR OPINION(1-2-3-4-5):";
			cin >> answer5;
		}
		switch (answer5)
		{
		case 1:cout << "ENTER NEW NAME:"; cin >> Name; listp1[i].setName(Name); break;
		case 2:cout << "ENTER NEW FAMILY:"; cin >> Family; listp1[i].setFamily(Family); break;
		case 3:cout << "ENTER NEW PHONENUMBER:"; cin >> Phonenumber; listp1[i].setPhonumber(Phonenumber); break;
		case 4:cout << "ENTER NEW CODE:"; cin >> code; listp1[i].setCodep(code); break;
		case 5:break;
		}
	}
}
void deleteallp(){listp1.clear();}
void deleteonep(string codep)
{
	for (int i = 0; i < listp1.size(); i++)
	{
		listp1[i].getCodep() != codep;
		listp2.push_back(listp1[i]);
	}
	listp1 = listp2;
	vector<Patient>().swap(listp2);
}
void desplayp()
{
	
	for (int i = 0; i < listp1.size(); i++)
	{
		listp1[i].print2();
	}
	cout <<"\nTHE NUMBER OF PATIENTS:"<< Patient::getNumber()<<"\n";
	
}
void desplayonep(string codep)
{
	for (int i = 0; i < listp1.size(); i++)
	{
		if (listp1[i].getCodep() == codep)
		{
			listp1[i].print2();
		}
	}
	
}
void patient_saved(string coded)
{
	for (multimap<string, string>::iterator i = savep.begin();i!= savep.end();i++)
	{
		if (coded == i->first)
		{
			cout << i->second << "\n";
		}
	}
}
void list_patient_saved()
{
	string coded;
	cout << "ENTER YOUR CODE:";
	cin >> coded;
	for (int i = 0; i < listp1.size(); i++)
	{
		savep.insert(pair<string, string>(listp1[i].getDoctorcod(), listp1[i].getName() + " " + listp1[i].getFamily() + " " + listp1[i].getKind()));
	}
	patient_saved(coded);
}

//*************************************************
//                DOCTOR CLASS
//*************************************************
vector<Doctor>listd1, listd2;

void writed()
{
	Doctor d;
	fstream outputdoctor;
	string Name, Family, Phonenumber, field;
	string Age, coded;
	cout << "\nENTER YOUR NAME:";
	cin >> Name;
	cout << "\nENTER YOUR FAMILY:";
	cin >> Family;
	cout << "\nENTER CODE OF DOCTOR:";
	cin >> coded;
	cout << "\nENTER YOUR PHONENUMBER:";
	cin >> Phonenumber;
	cout << "\nENTER YOUR AGE:";
	cin >> Age;
	cout << "\nENTER FIELD YOU WORK:";
	cin >> field;
	listd1.push_back(Doctor(Name, Family, Phonenumber, Age, coded,field));
	outputdoctor.open("Doctor.csv", ios::app);
	outputdoctor << Name  +","+  Family  +","+  Phonenumber  +","+ Age  +","+ coded  +","+  field << endl;
}
void editd(string coded)
{
	int answer5;
	string Name, Family, Phonenumber, Namep, Familyp;
	string code,codepr;
	for (int i = 0; i < listd1.size(); i++)
	{
		if (listd1[i].getCoded() == coded)
		{
			cout << "YOU WANT WHICH PART EDIT?\n";
			cout << "1.NAME:\n";
			cout << "2.FAMILY:\n";
			cout << "3.PHONENUMBER:\n";
			cout << "4.CODE:\n";
			cout << "5.BACK TO MENUE:\n";
			cout << "ENTER YOUR OPINION(1-2-3-4-5):";
			cin >> answer5;
		}
		switch (answer5)
		{
		case 1:
			cout << "ENTER NEW NAME:"; 
			cin >> Name;
			for (int i = 0; i < listp1.size(); i++)
			{
				if (listp1[i].getDoctorcod() == coded)
				{
					listp1[i].setndoctor(Name);
				}
			}
			listd1[i].setName(Name); 
			break;
		case 2:
			cout << "ENTER NEW FAMILY:";
			cin >> Family;
			for (int i = 0; i < listp1.size(); i++)
			{
				if (listp1[i].getDoctorcod() == coded)
				{
					listp1[i].setfdoctor(Family);
				}
			}
			listd1[i].setFamily(Family);
			break;
		case 3:cout << "ENTER NEW PHONENUMBER:"; cin >> Phonenumber; listd1[i].setPhonumber(Phonenumber); break;
		case 4:
			cout << "ENTER NEW CODE:";
			cin >>code;
			for (int i = 0; i < listp1.size(); i++)
			{
				if (listp1[i].getDoctorcod() == coded)
				{
					listp1[i].setDoctorcod(code);
				}
			}
			listd1[i].setCoded(code);
			break;
		case 5:break;
		}
	}
}
void deletealld() { listd1.clear(); }
void deleteoned(string coded)
{
	for (int i = 0; i < listd1.size(); i++)
	{
		listd1[i].getCoded() != coded;
		listd2.push_back(listd1[i]);
	}
	listd1 = listd2;
	vector<Doctor>().swap(listd2);
	for (int i = 0; i < listp1.size(); i++)
	{
		listp1[i].getDoctorcod() != coded;
		listp2.push_back(listp1[i]);
	}
	listp1 = listp2;
	vector<Patient>().swap(listp2);
}
void desplayd()
{

	for (int i = 0; i < listd1.size(); i++)
	{
		listd1[i].print3();
	}
	cout << "\nTHE NUMBER OF PATIENTS:" << Doctor::getCount() << "\n";
}
void desplayoned(string coded)
{
	for (int i = 0; i < listd1.size(); i++)
	{
		if (listd1[i].getCoded() == coded)
		{
			listd1[i].print3();
		}
	}
}
//*************************************************
//                     MENU
//*************************************************
void entry()
{
	int answer2,answer3, answer7;
	string codep,coded;
	char answer4;
		cout << "*********1.GO TO PATIENT CLASS*********\n";
		cout << "*********2.GO TO DOCTOR CLASS*********\n";
		cout << "********ENTER YOUR WORK(1-2)********\n";
		cin >> answer2;
		system("cls");
		if (answer2 == 1)
		{
			cout << "\t1.create new patient?\n";
			cout << "\t2.edit one patient?\n";
			cout << "\t3.delete all of patients?\n";
			cout << "\t4.delet one of patients?\n";
			cout << "\tenter your work(1-2-3-4):";
			cin >> answer3;
			switch (answer3)
			{
			case 1:
				do {
					writep();
					cout << "\npatient create succsesful;)\n";
					cout << "\ndo you want continue(y||n):";
					cin >> answer4;
					system("cls");
				} while (answer4 == 'y' || answer4 == 'Y'); break;
			case 2:
				cout << "ENTER CODE OF PATIENT:";
				cin >> codep;
				editp(codep); break;
			case 3:deleteallp(); break;
			case 4:cout << "ENTER CODE OF PATIENT:";
				cin >> codep;
				deleteonep(codep); break;
			}
		}
			if (answer2 == 2)
			{
				cout << "\t1.create new doctor?\n";
				cout << "\t2.edit one doctor?\n";
				cout << "\t3.delete all of doctors?\n";
				cout << "\t4.delet one of doctor?\n";
				cout << "\tenter your work(1-2-3-4):";
				cin >> answer7;
				switch (answer7)
				{
				case 1:
					do {
						writed();
						cout << "\ndoctor create succsesful;)\n";
						cout << "\ndo you want continue(y||n):";
						cin >> answer4;
						system("cls");
					} while (answer4 == 'y' || answer4 == 'Y'); break;
				case 2:cout << "ENTER CODE OF DOCTOR:";
					cin >> coded;
					editd(coded); break;
				case 3:
					deleteallp(); break;
					deletealld(); break;
				case 4:cout << "ENTER CODE OF DOCTOR:";
					cin >> coded;
					deleteoned(coded); break;
				}
			}
}
void report()
{
	string w;
	string codep, coded;
	int answer6;
	cout << "*********1.GO TO PATIENT CLASS*********\n";
	cout << "*********2.GO TO DOCTOR CLASS*********\n";
	cout << "*********3.back to MAIN MENU**********\n";
	cout << "*********ENTER YOUR WORK(1-2-3)*******\n";
	cin >> answer6;
	system("cls");
	switch (answer6)
	{
	case 1:
	       cout << "you want whatch all patient or one patient?(a||o)";
	       cin >> w;
	       if (w == "a")
	       {
		       desplayp(); break;
	       }
	      if (w == "o")
	      {
		       cout << "ENTER CODE OF PATIENT THAT YOU WANT WATCH";
		       cin >> codep;
		       desplayonep(codep); break;
	       }
	case 2:
		cout << "you want whatch all doctor or one doctor?(a||o)\n";
		cout << "if you watch patients for you enter s\n";
		cin >> w;
		if (w == "a")
		{
			desplayd(); break;
		}
		if (w == "o")
		{
			cout << "ENTER CODE OF PATIENT THAT YOU WANT WATCH";
			cin >> coded;
			desplayoned(coded); break;
		}
		if (w == "s")
		{
			list_patient_saved();
		}
	case 3:break;
	}
}
int main()
{
	int answer1;
	do {
		cout << "************MAIN MENU*************\n";
		cout << "********1.ENTRY/EDIT MENUE********\n";
		cout << "*********2.REPORT MENU************\n";
		cout << "*************3.EXIT***************\n";
		cin >> answer1;
		system("cls");
		switch (answer1)
		{
		case 1:entry(); break;
		case 2:report(); break;
		case 3:break;
		}
	} while (answer1 != 3);
	system("cls");
    return 0;
}

