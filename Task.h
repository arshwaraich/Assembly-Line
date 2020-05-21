// Name: Arshdeep Singh
// Seneca Student ID: 133462176
// Seneca email: asingh568@myseneca.ca
// Date of completion: 22 November 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <deque>

#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item
{
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;

public:
	//Constructors
	Task(const std::string& rec);

	//Copy Semantics
	Task(Task&) = delete;
	Task& operator=(Task&) = delete;

	//Move Semantics
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;

	//Modifiers
	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);

	//Operator Overloading
	Task& operator+=(CustomerOrder&&);
};

#endif // !TASK_H
