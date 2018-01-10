#pragma once
#include "header.h"
enum StateInput
{
	STRING, NUMBER, FIELD, OPERATOR, LBRACKET, RBRACKET,COMMA, KEYWORD = KEYWORD_START
};
enum StateOutput
{
	SYNTAXERR,NONE,QUERYSTART,ORDERBYNAME,TABLENAME,COLUMNNAME,ALLCOLUMN,CONDITION,END_FUNC, ENTER_CONDITION,END_CONDITION
};
class ParserAutomaton
{
#define stat(a,b,...) {(StateInput)a,(StateOutput)b,__VA_ARGS__}
	typedef struct state
	{
		StateInput state_in;
		StateOutput state_out;
		void* next_state; //指向下一个state_group 若=0 则不跳转
		void* func_next; //调用函数后跳转的sg
		bool last;
	}state;
	typedef struct
	{
		bool func;
		int total;
		state states[10];
	}state_group;
#pragma region
	///Functions
	state_group fun_count_ = { true, 2,{ //COUNT
		stat(KW_MUL,ALLCOLUMN,0),
		stat(FIELD,COLUMNNAME,0,0) //last state
	} };
#pragma endregion 
	state_group sg_select_from_where_order_by_ = { false, 1,{//SELECT [cols] from
		stat(FIELD,ORDERBYNAME,0,0,true)
	} };
	state_group sg_select_from_where_order_ = { false, 1,{//SELECT [cols] from
		stat(KW_BY,NONE,&sg_select_from_where_order_by_),
	} };
	state_group sg_select_from_where_ = { false, 7,{//SELECT [cols] from [table] where [condition]
		stat(NUMBER,CONDITION,0),
		stat(FIELD,CONDITION,0),
		stat(STRING,CONDITION,0),
		stat(OPERATOR,CONDITION,0),
		stat(LBRACKET,CONDITION,0),
		stat(RBRACKET,CONDITION,0),
		stat(KW_ORDER,END_CONDITION,&sg_select_from_where_order_)
	} };
	state_group sg_select_from_table = { false, 2,{//SELECT [cols] from table,
		stat(KW_WHERE,ENTER_CONDITION,&sg_select_from_where_),
		stat(COMMA,NONE,&sg_select_from_),
	} };
	state_group sg_select_from_ = {false, 2,{//SELECT [cols] from
		stat(KW_WHERE,ENTER_CONDITION,&sg_select_from_where_),
		stat(FIELD,TABLENAME,&sg_select_from_table)
	}};
	state_group sg_select_col = { false, 3,{//SELECT * / col1,
		stat(KW_COUNT,FUN_COUNT,&fun_count_,&sg_select_),
		stat(COMMA,NONE,&sg_select_),
		stat(KW_FROM,NONE,&sg_select_from_)
	} };
	state_group sg_select_ = { false, 4,{//SELECT * / 
		stat(KW_COUNT,FUN_COUNT,&fun_count_,&sg_select_),
		stat(KW_MUL,ALLCOLUMN,0 ),
		stat(FIELD,COLUMNNAME,&sg_select_col),
		stat(KW_FROM,NONE,&sg_select_from_)
	}};
	state_group sg__ = { false, 3,{ //SELECT UPDATE DELETE
		stat(KW_SELECT,QUERYSTART,&sg_select_),
		stat(KW_UPDATE,QUERYSTART,0),
		stat(KW_DELETE,QUERYSTART,0)
	}};
public:
	ParserAutomaton();
	~ParserAutomaton();
	StateOutput Update(StateInput input)
	{
		StateOutput output;
		if (dead)
			return SYNTAXERR;
		for (size_t i = 0; i < state_cur->total; i++)
		{
			if (function_mode)
			{
				if (input == LBRACKET) {
					if (function_lb)
						return SYNTAXERR; //两个左括号
					function_lb = true;
					continue;
				}
					
				if (input == RBRACKET)
				{
					if (!function_lb)
						return SYNTAXERR; //无左括号
					function_lb = false;
					function_mode = false;
					state_cur = state_prev;
					return END_FUNC;
				}
			}
			if (input == state_cur->states[i].state_in)
			{
				if (state_cur->states[i].last)
				{
					dead = true;
				}
				output = state_cur->states[i].state_out;
				state_group* next = ((state_group*)state_cur->states[i].next_state);
				if (next != NULL)
				{
					//printf("进入下一状态\n");
					if (next->func)
					{
						function_mode = true; //开启函数调用模式
						state_prev = (state_group*)state_cur->states[i].func_next; //如果是函数保存原sg
					}
					state_cur = next;
				}
				else
				{
					
				}
				return output;
			}
		}
		return SYNTAXERR;
	}
private:
	bool dead = false;
	bool function_mode = false;
	bool function_lb = false;
	state_group* state_cur = &sg__;
	state_group* state_prev = NULL;
};

