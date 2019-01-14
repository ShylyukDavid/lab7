/***********************************************************************
 * Module:  conveyer_line.cpp
 * Author:  David
 * Modified: четверг, 22 но€бр€ 2018 г. 01:34:18
 * Purpose: Implementation of the class conveyer_line
 ***********************************************************************/
#include <iostream>
#include <vector>
#include "hand_worker.h"
#include "Errors.h"
#include <ctime>
#include <cctype>  
#include <cstdlib> 
#include "conveyer_line.h"
#include <fstream>
using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       conveyer_line::make_item_product()
// Purpose:    Implementation of conveyer_line::make_item_product()
// Return:     void
////////////////////////////////////////////////////////////////////////
conveyer_line::conveyer_line() :
	workers(4),
	pos_in_production(0),
	eqiupment_stat(6),
	time_per_item(20),
	work_taken(false),
	color_danger("green"),
	current_work_performed(false),
	hand(0)
{
	cout << "conveyer_line was initialized (default).\n";
}

conveyer_line::conveyer_line(int s) :
	workers(s),
pos_in_production(0),
eqiupment_stat(6),
time_per_item(20),
work_taken(false),
color_danger("green"),
current_work_performed(false)
{
	cout << "Conveyer_line was initialized (parametrised).\n";
}


conveyer_line::conveyer_line(int workers, int pos_in_production, int eqiupment_stat, int time_per_item, bool work_taken, string color_danger, bool current_work_performed) :
	workers(workers),
	pos_in_production(pos_in_production),
	eqiupment_stat(eqiupment_stat),
	time_per_item(time_per_item),
	work_taken(work_taken),
	color_danger(color_danger),
	current_work_performed(current_work_performed),
	hand (workers)
{
	cout << "Conveyer_line line was initialized (normal).\n";
}
conveyer_line::conveyer_line(int workers, int pos_in_production, int eqiupment_stat, int time_per_item, bool work_taken, bool current_work_performed):
	workers(workers),
	pos_in_production(pos_in_production),
	eqiupment_stat(eqiupment_stat),
	time_per_item(time_per_item),
	work_taken(work_taken),
	color_danger("green"),
	current_work_performed(current_work_performed),
	hand(0)
{
}
conveyer_line::conveyer_line(const conveyer_line & conv) :
	workers(conv.workers),
	pos_in_production(conv.pos_in_production),
	eqiupment_stat(conv.eqiupment_stat),
	time_per_item(conv.time_per_item),
	work_taken(conv.work_taken),
	color_danger(conv.color_danger),
	current_work_performed(conv.current_work_performed),
	hand(conv.hand)
{
	//cout << "Conveyer_line was initialized (copy).\n";
}

conveyer_line::~conveyer_line() { }









void conveyer_line::calls()
{
	hand[0].qualification = 3;
	cout << "I changed qualification via setter of Worker - " << hand[0].qualification<<endl;
	hand[0].display();
}

bool conveyer_line::get_work_taken(void)
{
	return work_taken;
}


vector<hand_worker> conveyer_line::get_hand(void)
{
	return vector<hand_worker>(hand);
}

void conveyer_line::choose_workers()
{
	int first, second; bool r;
	do
	{
		r = true;
		try
		{
			cout << "Enter position of 1-st qualified and last worker(existing workers - " << workers << ") - ";
			cin.clear();
			fflush(stdin);
			cin >> first >> second;
			if (cin.fail() || cin.bad())
			{
				cin.clear();
				fflush(stdin);
				cin.ignore(INT_MAX, '\n'); r = false;
				throw Errors(3);
			}
			else if (first >= workers || first < 0 || second >= workers || second < 0||first>second)
			{
				throw Errors(2); r = false;
			}
			else
			{
				for (int i = first; i <= second; i++)
				{
					cout << "Worker#" << i << ": previous qualification - " << hand[i].get_qualification();
					 ++hand[i]; 
					 hand[i].display();
				}
			}
		}
		catch (Errors er)
		{
			er.error();
		}
		//cout << first << second<<workers;
	} while (r == false);
	cout << "Qualification succesful!" << endl;

}

void conveyer_line::add_workers(void)
{
	int qualifications; int num_positions;
	cout << "\nDescripting workers - " << endl;
	for (int i = 0; i < workers; i++)
	{
		cout << "Qualification worker #" << i << " : ";
		cin >> qualifications;
		cout << "Num_position - " << i << endl; num_positions = i;
		this->hand.emplace_back(num_positions, qualifications);
	}
}



void conveyer_line::set_pos_in_production(int s)
{
	pos_in_production = s;
}

void conveyer_line::set_eqiupment_stat(int s)
{
}

void conveyer_line::set_time_per_item(int s)
{
	time_per_item = s;
}

void conveyer_line::set_color_danger(string s)
{
	color_danger = s;
}

void conveyer_line::set_hand(vector<hand_worker> s)
{
	hand = s;
}

void conveyer_line::input_workers(ifstream & f,int div)
{
	int i = 0;
	int qualifications; int num_positions, number;   
	while (i!=div)
	{
		f >> number; 
		f >> qualifications;
		for (int c = 0; c < number; c++)
		{
			this->hand.emplace_back(i, qualifications);
			i++;
		}
	}
}

void conveyer_line::make_item_product(void)
{
   // TODO : implement
}