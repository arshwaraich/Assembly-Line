// Name: Arshdeep Singh
// Seneca Student ID: 133462176
// Seneca email: asingh568@myseneca.ca
// Date of completion: 22 November 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <vector>

#include "Task.h"

class LineManager
{
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;

public:
	//Constructors
	LineManager(const std::string& fileName, std::vector<Task*>& AsmblLine, std::vector<CustomerOrder>& tbFilled);

	//Modifiers
	bool run(std::ostream&);

	//Queries
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;
};
#endif // !LINEMANAGER_H
