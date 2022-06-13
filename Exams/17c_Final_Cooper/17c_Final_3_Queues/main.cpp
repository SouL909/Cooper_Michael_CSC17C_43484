/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Jun 6, 2022, 3:00 PM
 * Purpose: Final: Problem 3 Queues
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Customer {
	int time = 100;
};

struct Clerk {
	int rate = 100;
	Customer customer;
};

const int OVERFILL = 5;

const int PUSH_TIME = 4;

const int MIN_EMPL = 3; // Minimum amount of clerks

const int START = 50;

int MAX = START;

int TEMP_CLERKS = 0;

int TIME = 0;

int time_spent = 0;
int n = 0;

void update(vector<Clerk>&, queue<Customer>&);

int main(int argc, char** argv) {
	queue<Customer> line;
	for (int i = 0; i < 50; i++)	// Inserts 4 new customers
		line.push(Customer());
	vector<Clerk> clerks;
	Clerk clerk1;			// Inserting Clerk 1
	Customer customer;
	customer.time = 0;
	clerk1.customer = customer;
	clerks.push_back(clerk1);
	// Inserting Clerk 2
	Clerk clerk2;
	clerk2.rate = 50;
	clerk2.customer = customer;

	clerks.push_back(clerk2);
	// Inserting Clerk 3
	Clerk clerk3;
	clerk3.rate = 75;
	clerk3.customer = customer;

	clerks.push_back(clerk3);

	while (line.size() != 0) {	// Clerks servicing customers
		update(clerks, line);
	}
	cout << "Average Time: " << (time_spent / 100.0f)/ n << " mintues." << endl;
	return 0;
}


void update(vector<Clerk>& clerks, queue<Customer>& line) {
	if (MAX < line.size()) {
		MAX = line.size();
	}

	for (int i = 0; i < clerks.size(); i++) {
		if (clerks[i].customer.time > 0) {
			clerks[i].customer.time -= clerks[i].rate;
			cout << "Clerk " << i + 1 << " is attending a customer" << endl;
			cout << "\t Time remaining: " << clerks[i].customer.time << endl;
		}
		if (line.size() != 0 && clerks[i].customer.time <= 0) {
			clerks[i].customer = line.front();
			line.pop();
			cout << "Clerk " << i + 1 << " is attending a new customer" << endl;
			time_spent += clerks[i].rate;
			n++;
		}
	}
	if (TIME == PUSH_TIME) {
		line.push(Customer());
		cout << "A new customer has arrived!" << endl;
		TIME = 0;
	}
	if (line.size() != 0 && line.size() % OVERFILL == 0) {
		int temp = line.size() / OVERFILL;
		if (clerks.size() - MIN_EMPL - TEMP_CLERKS != temp) {
			TEMP_CLERKS++;
			cout << "The line is getting too large ... a clerk has been added!" << endl;
			Customer customer;
			customer.time = 0;
			Clerk clerk;
			clerk.customer = customer;
			clerks.push_back(clerk);
		}
	}
	if (line.size() % OVERFILL == 0 && TEMP_CLERKS != 0 && TEMP_CLERKS != line.size() / OVERFILL) {
		clerks.pop_back();
		cout << "Line is clearing up ... removing one clerk!" << endl;
	}
}


