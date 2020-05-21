// Name: Arshdeep Singh
// Seneca Student ID: 133462176
// Seneca email: asingh568@myseneca.ca
// Date of completion: 22 November 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iomanip>

#include "Item.h"

unsigned int Item::m_widthField = 0u;

//Constructor
Item::Item(const std::string& str)
{
	Utilities U;
	size_t pos = 0;
	bool more;
	
	m_name = U.extractToken(str, pos, more);
	m_serialNumber = (unsigned)(std::stoi(U.extractToken(str, pos, more)));
	m_quantity = (unsigned)(std::stoi(U.extractToken(str, pos, more)));
	m_description = U.extractToken(str, pos, more);
	
	if (m_widthField < U.getFieldWidth())
		m_widthField = U.getFieldWidth();

};

//Queries
const std::string& Item::getName() const
{
	return m_name;
};
const unsigned int Item::getQuantity()
{
	return m_quantity;
};

//Modifiers
const unsigned int Item::getSerialNumber()
{
	return m_serialNumber++;
};

void Item::updateQuantity()
{
	if (m_quantity > 0)
		--m_quantity;
};

void Item::display(std::ostream& os, bool full) const
{
	os << std::left;
	os << std::setw(m_widthField) << m_name;
	os << " [" << std::setw(6) << std::right << std::setfill('0') << m_serialNumber << "]";
	os << std::left << std::setfill(' ');
	if (full)
		os << " Quantity: " << std::setw(m_widthField) << m_quantity
		<< " Description: " << m_description;
	os << std::endl;
};
