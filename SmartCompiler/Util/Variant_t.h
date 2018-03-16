/******************************************************************************
 * @file Variant_t.h
 *
 * @brief Some description
 *
 * @version 1.0
 * @author It's me
 * @date 2018/03/13
 *
 *****************************************************************************/

#ifndef VARIANT_T_H_
#define VARIANT_T_H_

#include <string>

/*****************************************************************************/
namespace Util
{

class variant_t
{
public:
	enum class EVarType : uint
	{
		INT = 0,
		CHAR,
		STRING,
	};

public:
	variant_t();
	virtual ~variant_t();
	variant_t(const variant_t& t);
	variant_t& operator=(const variant_t& t);

public:
	variant_t(char in) {_type = EVarType::CHAR; asChar = in;}
	variant_t(int in) {_type = EVarType::INT; asInt = in;}
	variant_t(const std::string& s) { _type = EVarType::STRING; asString = s;}

public:
	EVarType getType() { return _type; }

	int getInt();   // todo: get value if type correct otherwise exception
	char getChar();
	std::string getString();

protected:
	void init(const variant_t& t);

private:
	EVarType _type;

	union
	{
	     char asChar;
	     int asInt;
	     std::string asString;  // string has default constructor, copy operations, and destruct
	};
};

} /* namespace Uitl */



#endif /* VARIANT_T_H_ */
