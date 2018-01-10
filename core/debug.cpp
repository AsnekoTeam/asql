#include "ComputableVal.h"
#include "DataValue.h"
#include "Query.h"
#include <Windows.h>
int main()
{
	
	ULONGLONG u1 = GetTickCount64();
	for (size_t i = 0; i < 1000000; i++)//3s
	{
		Query & query = Query();
		query.CompileQuery("SELECT  col1 , col2 FROM table1 ,  table2 WHERE s.a = 1 AND s.b= 'str' ORDER  BY s.a");
		//printf("%d", c.Compute()->value()->value().Int);
	}
	ULONGLONG u2 = GetTickCount64();
	printf("take:%lldms", u2 - u1);
	system("pause");
	return 0;
}
int main2()
{
	system("pause");
	ULONGLONG u1 = GetTickCount64();
	int a = 3, b = 4;
	DataValue s1 = DataValue(&a, DT_INT);
	DataValue s2 = DataValue(&b, DT_INT);
	ComputableVal c(Operator::OP_PLUS);
	ComputableVal c1(s1);
	ComputableVal c2(Operator::OP_MINUS);
	ComputableVal c3(Operator::OP_MUL);
	c.AddComponent(c1);
	c.AddComponent(c2);
	c2.AddComponent(c1);
	c2.AddComponent(c3);
	c3.AddComponent(c1);
	c3.AddComponent(c1);
	for (size_t i = 0; i < 1000000; i++)// less than 1s
	{
	//	delete c.Compute();
		c.Compute();
		//printf("%d", c.Compute().value().value().Int);
	}
	ULONGLONG u2 = GetTickCount64();
	printf("take:%lldms", u2-u1);
	system("pause");
	return 0;
}