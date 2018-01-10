#pragma once
#include "header.h"
#include "ComputeResult.hpp"
#include "DataValue.h"
class ComputableVal
{
public:
	ComputableVal(Operator ope,bool overrided = false) {
		this->overrided = overrided;
		this->ope = ope;
	}
	ComputableVal(DataValue val) {
		this->val = val;
		this->ope = INSVALUE;
		this->ope = ope;
	}
	void AddComponent(ComputableVal& val)
	{
		valRef.push_back(&val);
		//printf("0x%016x",this,)
	}
	~ComputableVal() {
		
	}


private:
	ComputeResult CreateBoolResult(bool b) {
		return CreateValueResult(&b, DT_TINYINT);
	}
	ComputeResult CreateStringResult(const char* data) {
		return ComputeResult(std::string(data));
	}
	ComputeResult CreateValueResult(void* val,DataType tVal) {
		return ComputeResult(DataValue(val,tVal));
	}
	ComputeResult CreateResult(DataValue dataVal) {
		return ComputeResult(dataVal);
	}
	
	Operator ope;
	DataValue val;
	std::vector <ComputableVal*> valRef;
	ComputeResult* cpRes = NULL;
	public:
		bool overrided = false;
		ComputeResult Compute();
};

