#pragma once
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>
#include <stack>
#include <vector>
#include <functional>
#include <memory>
#include <map>
#include <regex>
#define MAX_KEYWORD 10
#define MAX_COLNAME 32
#define MAX_RECORD 8192
#define INFUN_START 512
#define KEYWORD_START 100
#define OPERATOR_START KEYWORD_START
#define OPERATOR_END 119 //modify if you add operator
#define KEYWORD_END 133 //modify if you add keyword
#define INFUN_END 512 //modify if you add innerfunction
#define IS_OPERATOR(kw) kw>=OPERATOR_START&&kw<=OPERATOR_END
#define IS_KEYWORD(kw) kw>=KEYWORD_START&&kw<=KEYWORD_END
#define IS_INFUN(kw) kw>=INFUN_START&&kw<=INFUN_END
enum Operator
{
	NOTAOPERATOR = KEYWORD_END+1,INSVALUE, OP_AND = OPERATOR_START, OP_OR, OP_NOT,
	OP_PLUS, OP_MINUS, OP_MUL, OP_DIV, OP_FDIV, OP_MOD,
	OP_EQUAL, OP_NOTEQUAL, OP_LESS, OP_GREATER, OP_LESSEQUAL,
	OP_GREATEREQUAL, OP_BETWEEN, OP_ISNULL, OP_NOTNULL, OP_LIKE,
	OP_REGEX
};
enum InnerFunction
{
	FUN_COUNT = INFUN_START
};
enum Keyword
{
	INVALID=-1 ,NOT_KEYWORD = KEYWORD_END+1, KW_AND = KEYWORD_START, KW_OR, KW_NOT,
	KW_PLUS, KW_MINUS, KW_MUL, KW_DIV, KW_FDIV, KW_MOD,
	KW_EQUAL, KW_NOTEQUAL, KW_LESS, KW_GREATER, KW_LESSEQUAL,
	KW_GREATEREQUAL, KW_BETWEEN, KW_IS, KW_NULL, KW_NOTNULL, KW_LIKE,
	KW_REGEX, KW_SET, KW_DROP, KW_CREATE, KW_TABLE, KW_SELECT, KW_INSERT, KW_UPDATE, KW_DELETE, KW_FROM, KW_WHERE,
	KW_COUNT,KW_ORDER,KW_BY
};
enum DataType
{
	DT_ANY,DT_VARCHAR,DT_INT,DT_BIGINT,DT_TINYINT,DT_DATE,DT_DATETIME,DT_TEXT,DT_DOUBLE,DT_FLOAT
};