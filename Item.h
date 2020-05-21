// Name: Arshdeep Singh
// Seneca Student ID: 133462176
// Seneca email: asingh568@myseneca.ca
// Date of completion: 22 November 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef ITEM_H
#define ITEM_H

#include "Utilities.h"

class Item
{
	std::string m_name;
	std::string m_description;
	size_t m_serialNumber;
	size_t m_quantity;
	static unsigned int m_widthField;

public:
	//Constructor
	Item(const std::string&);

	//Queries
	const std::string& getName() const;
	const unsigned int getQuantity();

	//Modifiers
	const unsigned int getSerialNumber();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};


#endif // !ITEM_H
