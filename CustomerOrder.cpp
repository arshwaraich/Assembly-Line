// Name: Arshdeep Singh
// Seneca Student ID: 133462176
// Seneca email: asingh568@myseneca.ca
// Date of completion: 22 November 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iomanip>
#include <algorithm>

#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0u;

//Constructors
CustomerOrder::CustomerOrder() 
{
	m_lstItem = nullptr;
};

CustomerOrder::CustomerOrder(std::string& rec) 
{
	Utilities U;
	size_t pos = 0;
	bool more;

	m_name = U.extractToken(rec, pos, more);
	m_product = U.extractToken(rec, pos, more);
	m_cntItem = std::count(rec.begin(), rec.end(), U.getDelimiter()) - 1;
	m_lstItem = new ItemInfo*[m_cntItem];
	for (size_t i = 0u; i < m_cntItem; ++i)
	{
		m_lstItem[i] = new ItemInfo(U.extractToken(rec, pos, more));
	}

	if (m_widthField < U.getFieldWidth())
		m_widthField = U.getFieldWidth();
};

//Move semantics
CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept 
{
	m_lstItem = nullptr;
	*this = std::move(src);
};

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) 
{
	if (this != &src)
	{
		if (m_lstItem != nullptr)
		{
			for (size_t i = 0u; i < m_cntItem; ++i)
				delete m_lstItem[i];
			delete[] m_lstItem;
		}

		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;
		m_lstItem = src.m_lstItem;
		src.m_lstItem = nullptr;
	}

	return *this;
};

//Destructor
CustomerOrder::~CustomerOrder() 
{
	if (m_lstItem != nullptr)
	{
		for (size_t i = 0u; i < m_cntItem; ++i)
			delete m_lstItem[i];
		delete[] m_lstItem;
	}
};

//Queries
bool CustomerOrder::getItemFillState(std::string it) const
{
	bool ret = true;
	for (size_t i = 0u; i < m_cntItem; ++i)
	{
		if(m_lstItem[i]->m_itemName == it)
			ret = m_lstItem[i]->m_fillState;
	}
	return ret;
};

bool CustomerOrder::getOrderFillState() const
{
	bool ret = true;
	for (size_t i = 0u; i < m_cntItem && ret; ++i)
	{
			ret = m_lstItem[i]->m_fillState;
	}
	return ret;
};

void CustomerOrder::display(std::ostream& os) const
{
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0u; i < m_cntItem; ++i)
	{
		os << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << std::left << "] " << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - " << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl;
	}
};

//Modifiers
void CustomerOrder::fillItem(Item& item, std::ostream& os)
{
	bool flag = true;
	for (size_t i = 0u; i < m_cntItem && flag; ++i)
	{
		if (m_lstItem[i]->m_itemName == item.getName())
		{
			if (item.getQuantity() != 0)
			{
				item.updateQuantity();
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				m_lstItem[i]->m_fillState = true;
				os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
			}
			else
			{
				os << "Unable to fill " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
			}
		}
	}
};
