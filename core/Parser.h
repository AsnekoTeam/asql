#pragma once
#include "header.h"
#include "Query.h"
#include "state.h"
class Parser
{
public:
	Parser();
	~Parser();
	Keyword GetKeyword(char * keyword, int length);
	StateInput CheckNextword(std::string & condition, int start, int & next);
	StateInput ParseQuery(std::string& query, int start, int& next) { return CheckNextword(query, start, next); }
	std::string GetNextRecord(std::string& condition, int start, int& next)
	{
		char c;
		char buffer[MAX_RECORD + 1] = { 0 };
		short pos = 0;
		for (int i = start; i < condition.size(); i++)
		{
			c = condition.at(i);
			if (c == '\'') {
				next = i + 1;
				break;
			}
			buffer[pos++] = c;
		}
		return std::string(buffer);
	}
	std::string GetColumnName(std::string& condition, int start, int& next)
	{
		char c;
		char buffer[MAX_COLNAME + 1] = { 0 };
		short pos = 0;
		bool end = true;
		for (int i = start; i < condition.size(); i++)
		{
			c = condition.at(i);
			if (IsSymbol(c)) {
				next = i;
				end = false;
				break;
			}
			buffer[pos++] = c;
		}
		if (end)
			next = (int)condition.size();
		return std::string(buffer);
	}
private:
	
	inline bool IsSymbol(char c)
	{
		return (((c >= ' ' && c <= '/') 
			|| (c >= ':' && c <= '@') 
			|| (c >= '{' && c <= '~') 
			|| (c >= '[' && c <= '`')) && c != '.');
	}
	inline bool IsOperatorSymbol(char c)
	{
		return (c=='<' || c == '>' || c == '=' || c == '+'|| c == '-' || c == '*' || c == '/' || c == '%');
	}
};

