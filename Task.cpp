// Name: Arshdeep Singh
// Seneca Student ID: 133462176
// Seneca email: asingh568@myseneca.ca
// Date of completion: 22 November 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <utility>

#include "Task.h"

//Constructors
Task::Task(const std::string& rec) : Item(rec), m_pNextTask(nullptr){};

//Modifiers
void Task::runProcess(std::ostream& os)
{
	if (!m_orders.empty())
	{
		if (!m_orders.back().getOrderFillState())
		{
			m_orders.back().fillItem(*this, os);
		}
	}
};
bool Task::moveTask()
{
	bool ret = true;
	if (!m_orders.empty() && m_orders.front().getItemFillState(this->getName()) && m_pNextTask != nullptr)
	{
		m_pNextTask->m_orders.push_back(std::move(this->m_orders.front()));
		this->m_orders.pop_front();
	}
	else
	{
		ret = false;
	}
	return ret;
};
void Task::setNextTask(Task& T)
{
	m_pNextTask = &T;
};
bool Task::getCompleted(CustomerOrder& C)
{
	bool ret = true;
	if (!m_orders.empty())
	{
		C = std::move(m_orders.back());
		m_orders.pop_back();
	}
	else
	{
		ret = false;
	}
	return ret;
};
void Task::validate(std::ostream& os)
{
	os << this->getName() << " --> ";
	if (m_pNextTask == nullptr)
		os << "END OF LINE";
	else
		os << m_pNextTask->getName();
	os << std::endl;
};

//Operator Overloading
Task& Task::operator+=(CustomerOrder&& C)
{
	m_orders.push_front(std::move(C));
	return *this;
};
