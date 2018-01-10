#pragma once
#include "header.h"
#include "ResultSet.h"
#include "Parser.h"
#include "Database.h"
class Query
{
public:
	enum QueryType
	{
		QSELECT = KW_SELECT, QUPDATE = KW_UPDATE, QDELETE = KW_DELETE, QINSERT = KW_INSERT
	};
	Query();
	~Query();
	bool CompileQuery(std::string query);
	ResultSet& ExecuteQuery();
private:
	QueryType query_type;
	Database *context;
	bool rootQuery = false;
	bool count;//count()
	bool queryAll = false;
	std::list<std::string*> column; //select column.0,column.1,column.2 from context->table //insert into context->table set col.1=val.1.
	std::list<std::string*> table;//from xx,xx
	std::list<std::string*> value;//set column.0 = value.0,column.1 = ....
	std::string* order = nullptr;//orderby order.0 and order.1 = ....
};

