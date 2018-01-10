#pragma once
#include "Column.h"
#include "header.h"
class ResultSet
{
public:
	ResultSet();
	~ResultSet()
	{
		for each (auto var in this->columns)
		{
			delete var.second;
		}
	}
	bool build();
	Column* CreateColumn(std::string name) {
		columns.find(name) != columns.end();
		Column* col = new Column();
		columns[name] = col;
		return col;
	}
private:
	std::map<std::string, Column*> columns;
};

