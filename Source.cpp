#define _CRT_SECURE_NO_WARNINGS
#include "libr.h"
#include "Errors.h"
#include <vector>
#include <string> 
#include <cctype>   // для функции isdigit
#include <cstdlib>  // для функции atoi
#include <iostream>
#include <iterator>
#include <conio.h>
#include<fstream>

void menu1()
{
	cout << "Enter generail info about your enterprise:\n";
	float productivity; int num_dp, prod_num;
	cout << "Enter number departments - "; cin >> num_dp;
	cout << "Enter number products - "; cin >> prod_num;
	cout << "Enter power productivity - "; cin >> productivity;
	enterprise factory(productivity, num_dp, prod_num);
	bool departs = false; bool productions = false;
	if (factory.have_departs())
	{
		factory.describe_department(num_dp); departs = true; system("pause"); system("cls");
	}
	else cout << "Your enterprise has no departments!" << endl;

	if (factory.has_products())
	{
		factory.describe_products(prod_num); productions = true;
	}
	else cout << "No production is defined!" << endl;
	if (departs && productions)cout << "You finally described enterprise!" << endl;
	char x;
	do
	{
		cout << "1.Show info departments\n"
			<< "2.Show info products\n"
			<< "3.Qualify workers\n"
			<< "4.Take order\n"
			<< "5.Add product\n"
			<< "6.Add department\n"
			<< "0.Exit\n";
		switch (x = _getch())
		{
		case '1': if (factory.have_departs())
		{
		factory.show_depart(); break;
		}
				  else cout << "You have no departments!" << endl; break;
		case '2': if (factory.has_products())
		{
			 factory.show_products(); break;
		}
				  else cout << "No production in your enterprise.Its bad!\n"; break;
		case'3':  cout << "Notice:input countdown starts from index 0:\n"; factory.choose_depart(); break;
		case '4':  if (factory.get_s().have_materials())
		{
					   int c = factory.get_pow(); ++factory;
					   if (factory.create_order())
					   {
						   cout << "Previous productivity - " << c << ", productivity after performing order - " << factory.get_pow() << endl;
					   }

					   break;
		}
				   else throw Errors(4); break;
		case '5': int w; cout << "Enter number of products u want to add - "; cin >> w; factory.describe_products(w); break;
		case '6': int l; cout << "Enter number of departments to add - "; cin >> l; factory.describe_department(l); break;
		case'0':exit(0); break;

		}

		system("pause");
		system("cls");
	} while (x != '0');
	system("pause");

}

void menu2()
{
	float produc; int dep, prod; 
	ifstream f("data.txt");
	f >> produc;
	f >> dep;
	f >> prod;
	enterprise factory(produc, dep, prod,true);
    factory.input_departments(f);
	factory.show_depart();
	factory.input_products(f);

	//factory.get();
	system("pause");
	system("cls");
	char x;
	do
	{
		try
		{
			cout << "1.Show info departments\n"
				<< "2.Show info products\n"
				<< "3.Qualify workers\n"
				<< "4.Take order\n"
				<< "5.Add product\n"
				<< "6.Add department\n"
				<< "0.Exit\n";
			switch (x = _getch())
			{
			case '1': if (factory.have_departs())
			{
				factory.show_depart(); break;
			}
					  else cout << "You have no departments!" << endl; break;
			case '2': if (factory.has_products())
			{
				factory.show_products(); break;
			}
					  else cout << "No production in your enterprise.Its bad!\n"; break;
			case'3':  cout << "Notice:input countdown starts from index 0:\n"; factory.choose_depart(); break;
			case '4': if (factory.get_s().have_materials())
			{
				int c = factory.get_pow(); ++factory;
				if (factory.create_order())
				{
					cout << "Previous productivity - " << c << ", productivity after performing order - " << factory.get_pow() << endl;
				}

				break;
			}
					  else throw Errors(4); break;
			case '5': int w; cout << "Enter number of products u want to add - "; cin >> w; factory.describe_products(w); break;
			case '6': int l; cout << "Enter number of departments to add - "; cin >> l; factory.describe_department(l); break;
			case'0':exit(0); break;
			default:throw Errors(1); break;
			}

			system("pause");
			system("cls");


		}
		catch (Errors ex)
		{
			ex.error();
			system("cls");
		}
	} while (x != '0');

}
int main()
{
	{  
		
		char c;
		cout << "Lab 7 done by Shylyuk David, IS-73\nAdded a lot of error handlers\nA lot of content wasnt realized or added from previous labs because of lack of time or just its uselessness\nProject was succesully generated!\n";
		cout << "Program is running...\n----------------------------" << endl;
		bool r;
		do
		{
			r = true;
			try
			{
				cout << "Wanna create enterprise by yourself or from file-data?(1,2)\n"; 
				switch (c = _getch())
				{
				case'1':menu1(); break;
				case '2':menu2(); break;
				default: throw Errors(1); break;

				}
			}
			catch (Errors ex)
			{
				r = false;
				ex.error();
				system("pause");
				system("cls");
			}
		} while (r==false);
	
	
	}

}