// Name: Arshdeep Singh
// Seneca Student ID: 133462176
// Seneca email: asingh568@myseneca.ca
// Date of completion: 22 November 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <fstream>
#include <utility>
#include <algorithm>
#include <functional>

#include "LineManager.h"

//Constructors
LineManager::LineManager(const std::string& fileName, std::vector<Task*>& AsmblLine, std::vector<CustomerOrder>& tbFilled)
{
	std::ifstream fin(fileName);
	std::string rec;
	
	while (fin)
	{
		std::getline(fin, rec);

		Utilities::setDelimiter('|');
		Utilities U;
		size_t pos = 0;
		bool more;

		std::string Item1, Item2;

		Item1 = U.extractToken(rec, pos, more);
		Item2 = U.extractToken(rec, pos, more);
		
		if(Item1 != Item2)
		{
			for (auto i : AsmblLine)
			{
				if (Item1 == i->getName())
				{
					for (auto j : AsmblLine)
					{
						if (Item2 == j->getName())
						{
							i->setNextTask(*j);
						}
					}
				}
			}
		}
	}
	for (auto &i : tbFilled)
		ToBeFilled.push_back(std::move(i));
	m_cntCustomerOrder = ToBeFilled.size();
	for (auto i : AsmblLine)
		AssemblyLine.push_back(i);
};

//Modifiers
bool LineManager::run(std::ostream& os)
{
	bool ret = false;
	

	if (Completed.size() != m_cntCustomerOrder)
	{
		
		for (auto &i : AssemblyLine)
		{
			if (!ToBeFilled.empty() && i->getName() == "Power Supply")
			{
				*i += std::move(ToBeFilled.front());
				ToBeFilled.pop_front();
			}
		}

		for (auto i : AssemblyLine)
		{
			i->runProcess(os);
		}

		for (auto &i : AssemblyLine)
		{
			if (i->getName() == "SSD")
			{
				CustomerOrder tmp;
				if (i->getCompleted(std::ref(tmp)))
					Completed.push_back(std::move(tmp));
			}
		}
		
		for (auto i : AssemblyLine)
		{
			i->moveTask();
		}
	}
	else
	{
		ret = true;
	}

	return ret;
};

//Queries
void LineManager::displayCompleted(std::ostream& os) const
{
	for (auto &i : Completed)
		i.display(os);
};
void LineManager::validateTasks() const
{
	for (auto i : AssemblyLine)
		i->validate(std::cout);
};
