// Name: Arshdeep Singh
// Seneca Student ID: 133462176
// Seneca email: asingh568@myseneca.ca
// Date of completion: 22 November 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include<string>
#include "Item.h"

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;

public:
	//Constructors
	CustomerOrder();
	CustomerOrder(std::string& rec);

	//Copy semantics
	CustomerOrder(const CustomerOrder& src) { throw "Copy construction prohibited!"; };
	CustomerOrder& operator=(const CustomerOrder& src) = delete;

	//Move semantics
	CustomerOrder(CustomerOrder&& src) noexcept;
	CustomerOrder& operator=(CustomerOrder&& src);

	//Destructor
	~CustomerOrder();

	//Queries
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void display(std::ostream&) const;

	//Modifiers
	void fillItem(Item& item, std::ostream&);
};

#endif // !CUSTOMERORDER_H
