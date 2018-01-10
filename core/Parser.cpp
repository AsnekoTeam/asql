#include "Parser.h"




Parser::Parser()
{
}

Parser::~Parser()
{
}

Keyword Parser::GetKeyword(char* keyword, int length)
{
	int pos = 0;
	switch (length)
	{
	case 1:
		if (keyword[0] == '+')
			return KW_PLUS;
		if (keyword[0] == '-')
			return KW_MINUS;
		if (keyword[0] == '>')
			return KW_GREATER;
		if (keyword[0] == '<')
			return KW_LESS;
		if (keyword[0] == '*')
			return KW_MUL;
		if (keyword[0] == '/')
			return KW_DIV;
		if (keyword[0] == '%')
			return KW_MOD;
		if (keyword[0] == '=')
			return KW_EQUAL;
		break;
	case 2:
		if (strcmp(keyword, "IS") == 0)
			return KW_IS;
		if (strcmp(keyword, "OR") == 0)
			return KW_OR;
		if (strcmp(keyword, "BY") == 0)
			return KW_BY;
		if (strcmp(keyword, ">=") == 0)
			return KW_GREATEREQUAL;
		if (strcmp(keyword, "<=") == 0)
			return KW_LESSEQUAL;
		if (strcmp(keyword, "<>") == 0)
			return KW_NOTEQUAL;
		break;
	case 3:
		if (strcmp(keyword, "AND") == 0)
			return KW_AND;
		if (strcmp(keyword, "NOT") == 0)
			return KW_NOT;
		if (strcmp(keyword, "DIV") == 0)
			return KW_FDIV;
		if (strcmp(keyword, "SET") == 0)
			return KW_SET;
		break;
	case 4:
		if (strcmp(keyword, "NULL") == 0)
			return KW_NULL;
		if (strcmp(keyword, "LIKE") == 0)
			return KW_LIKE;
		if (strcmp(keyword, "DROP") == 0)
			return KW_DROP;
		if (strcmp(keyword, "FROM") == 0)
			return KW_FROM;
		break;
	case 5:
		if (strcmp(keyword, "REGEX") == 0)
			return KW_REGEX;
		if (strcmp(keyword, "COUNT") == 0)
			return KW_COUNT;
		if (strcmp(keyword, "TABLE") == 0)
			return KW_TABLE;
		if (strcmp(keyword, "WHERE") == 0)
			return KW_WHERE;
		if (strcmp(keyword, "ORDER") == 0)
			return KW_ORDER;
		break;
	case 6:
		if (strcmp(keyword, "CREATE") == 0)
			return KW_CREATE;
		if (strcmp(keyword, "SELECT") == 0)
			return KW_SELECT;
		if (strcmp(keyword, "INSERT") == 0)
			return KW_INSERT;
		if (strcmp(keyword, "UPDATE") == 0)
			return KW_UPDATE;
		if (strcmp(keyword, "DELETE") == 0)
			return KW_DELETE;
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	default:
		break;
	}
	return NOT_KEYWORD;
}

StateInput Parser::CheckNextword(std::string& condition, int start, int& next)
{
	char buffer[MAX_KEYWORD + 1] = { 0 };
	short pos = 0;
	char c;
	bool symbolMode = false;
	for (int i = start; i < condition.size(); i++)
	{
		c = condition.at(i);
		next = i;
		if (IsSymbol(c) || i == condition.size() - 1)
			if (!pos)
			{
				if (c == ' ') //开头过滤空格
					continue;
				if (IsOperatorSymbol(c))
					symbolMode = true;//第一个字符是符号 则开始符号关键字匹配		
			}
			else {
				if (i - start > MAX_KEYWORD)
				{
					next = i - pos; // start from the begining of field
					return FIELD;
				}

				Keyword ope = GetKeyword(buffer, pos);
				if (ope == NOT_KEYWORD)
				{
					next = i - pos; // start from the begining of field
					return FIELD;
				}
				return (StateInput)ope;
			}
			if (c == ',')
			{
				next = i + 1;
				return COMMA;//匹配四个语法字符
			}
			if (c == '(')
			{
				next = i + 1;
				return LBRACKET;
			}
			if (c == ')') {
				next = i + 1;
				return RBRACKET;
			}
			if (c == '\'')
			{
				next = i + 1;
				return STRING;
			}

			if ((c >= '0' && c <= '9') && !pos)
			{
				next = i;
				return NUMBER;
			}


			if (pos < MAX_KEYWORD)
			{
				if (symbolMode)
				{
					if (IsOperatorSymbol(c))
						buffer[pos++] = c;
					else
					{

						Keyword ope = GetKeyword(buffer, pos);
						if (ope == NOT_KEYWORD)//如果不是关键字则当作分隔符
						{
							if (pos != 1 || buffer[0] != ',')//不是分隔符 交给状态机无效内容 语法错误
								return (StateInput)INVALID;
							memset(buffer, 0, pos);//是分隔符就情况buffer继续读入
							symbolMode = false;
							pos = 0;
							i--;
						}
						else {
							next = i;
							return (StateInput)ope;
						}

					}
				}
				else
					buffer[pos++] = c;

			}


	}
	return (StateInput)INVALID; //结尾不Trim会产生无效字符
}
