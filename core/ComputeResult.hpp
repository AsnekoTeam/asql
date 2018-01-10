#pragma once
#include "header.h"
#include "DataValue.h"
class ComputeResult
{
public:
	ComputeResult()
	{

	}
	ComputeResult(std::string str) {
		this->val =  DataValue(str);
	}
	ComputeResult(DataValue val) {
		this->val = val;
	}
	~ComputeResult() {

	}
	DataValue value() { return val; }
private:
	DataValue val;
};