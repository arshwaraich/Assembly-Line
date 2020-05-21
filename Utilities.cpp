// Name: Arshdeep Singh
// Seneca Student ID: 133462176
// Seneca email: asingh568@myseneca.ca
// Date of completion: 22 November 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Utilities.h"

char Utilities::m_delimiter;

//Modifiers
void Utilities::setFieldWidth(size_t widthField)
{
	m_widthField = widthField;
};

void Utilities::setDelimiter(const char delimiter)
{
	m_delimiter = delimiter;
};

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	size_t pos;
	pos = str.substr(next_pos).find(m_delimiter);
	if (pos == 0)
	{
		more = false;
		throw "Token not found"; //TODO check if i have to handle
	}
	if (pos > m_widthField && pos != std::string::npos)
		m_widthField = pos;
	more = true;
	next_pos += (pos + 1);
	return str.substr(next_pos - (pos + 1), pos);
};

//Queries
size_t Utilities::getFieldWidth() const
{
	return m_widthField;
};

const char Utilities::getDelimiter() const
{
	return m_delimiter;
};
