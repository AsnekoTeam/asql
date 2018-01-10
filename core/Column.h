#pragma once
#include "header.h"
#include "DataValue.h"
class Column
{
public:
	Column();
	~Column();
	size_t count() { return this->_count; }
	void push_back(DataValue val)
	{
		values.push_back(val);
		_count++;
	}
private:
	std::string name; //column name
	std::string alias;
	size_t _count = 10;
	std::list<DataValue> values;
};

