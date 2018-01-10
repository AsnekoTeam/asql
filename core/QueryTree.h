#pragma once
#include "Query.h"
class QueryTree
{
public:
	QueryTree();
	QueryTree(Query * query);
	~QueryTree();
	static QueryTree &CreateQueryTreeWithSubQuery(Query& subQuery);
	static QueryTree &CreateQueryTreeEmptyRoot();
	QueryTree &InsertQuery();
private:
	Query *query;
};

