// Name: Arshdeep Singh
// Seneca Student ID: 133462176
// Seneca email: asingh568@myseneca.ca
// Date of completion: 22 November 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

class Utilities
{
	size_t m_widthField = 0u;
	
	//Class variables
	static char m_delimiter;

public:
	//TODO : Check if i have to make the five functions

	//Modifiers
	void setFieldWidth(size_t);
	static void setDelimiter(const char);
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

	//Queries
	size_t getFieldWidth() const;
	const char getDelimiter() const;
};


#endif // !UTILITIES_H
