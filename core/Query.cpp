#include "Query.h"



Query::Query()
{
	//this->context = context;
}
Query::~Query()
{
	for each (auto var in this->column)
		delete var;
	for each (auto var in this->value)
		delete var;
	for each (auto var in this->table)
		delete var;
	if (order != nullptr)
		delete order;
}
bool Query::CompileQuery(std::string query)
{

	Parser parser;
	StateInput input;
	StateInput realInput;
	StateOutput output;
	ParserAutomaton automaton;
	std::string str;
	int next = 0;
	bool condition = false; //正在条件编译
	while (next < query.size())
	{
		realInput = input = parser.ParseQuery(query, next, next);
		if (IS_OPERATOR(input) && condition)
			realInput = OPERATOR;//所有运算符都算为一种类型
		if (input == STRING)
			str = parser.GetNextRecord(query, next, next);
		if (input == FIELD)
			str = parser.GetColumnName(query, next, next);
		if (input == NUMBER)
			str = parser.GetColumnName(query, next, next);
		output = automaton.Update(realInput);
		if (output == SYNTAXERR)
			return false;
		switch (output)
		{
		case StateOutput::QUERYSTART :
			this->query_type = (QueryType)input;
			break;
		case StateOutput::COLUMNNAME:
			this->column.push_back(new std::string(str));
			break;
		case StateOutput::TABLENAME:
			this->table.push_back(new std::string(str));
			break;
		case StateOutput::ALLCOLUMN:
			queryAll = true;
			break;
		case StateOutput::ENTER_CONDITION:
			condition = true;
			break;
		case StateOutput::END_CONDITION:
			condition = false;
			break;
		case StateOutput::ORDERBYNAME:
			this->order = (new std::string(str));
			break;
		case StateOutput::CONDITION:
			
			break;
		case StateOutput::END_FUNC:

			break;
		default:
			if (IS_INFUN(output)) {

			}
			break;
		}
	}
	return true;
}
ResultSet& Query::ExecuteQuery()
{
	return ResultSet{};
}

