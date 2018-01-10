#pragma once
#include "DataValue.h"
#include "ComputableVal.h"
#include "Column.h"
class Transfer :public ComputableVal
{
public:
	typedef ComputeResult(*transfer)(std::list<DataValue>& args);
	Transfer():ComputableVal(Operator::NOTAOPERATOR,true) {

	}
	~Transfer() {

	}
	void AddArg(ComputableVal arg)
	{
		args.push_back(arg);
	}
	ComputeResult Compute()
	{
		std::list<DataValue> transferArgs;
		for each (auto var in args)
		{
			if(!var.overrided)
				transferArgs.push_back(var.Compute().value());
			else
				transferArgs.push_back(((Transfer*)(&var))->Compute().value());
		}
		return function(transferArgs);
	}
private:
	transfer function;
	bool instance = false;
	Column* column;
	std::list<ComputableVal> args;

};

