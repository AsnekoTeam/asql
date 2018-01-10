#include "ComputableVal.h"
ComputeResult ComputableVal::Compute()
{
	std::vector<DataValue> computedVal;
	ComputeResult result;
	for (size_t i = 0; i < valRef.size(); i++)
	{
		ComputeResult r = valRef.at(i)->Compute();
		computedVal.push_back(r.value());
	}
	switch (ope)
	{
	case NOTAOPERATOR:
		break;
	case INSVALUE:
		result =  val;
		break;
	case OP_AND:
		result = CreateBoolResult(computedVal.at(0) && computedVal.at(1));
		break;
	case OP_OR:
		result = CreateBoolResult(computedVal.at(0) || computedVal.at(1));
		break;
	case OP_NOT:
		result = CreateBoolResult(!computedVal.at(0));
		break;
	case OP_PLUS:
		result = CreateResult(computedVal.at(0) + computedVal.at(1));
		break;
	case OP_MINUS:
		result = CreateResult(computedVal.at(0) - computedVal.at(1));
		break;
	case OP_MUL:
		result = CreateResult(computedVal.at(0) * computedVal.at(1));
		break;
	case OP_DIV:
		result = CreateResult(computedVal.at(0) / computedVal.at(1));
		break;
	case OP_FDIV:
		break;
	case OP_MOD:
		break;
	case OP_EQUAL:
		CreateBoolResult(computedVal.at(0) == computedVal.at(1));
		break;
	case OP_NOTEQUAL:
		CreateBoolResult(computedVal.at(0) != computedVal.at(1));
		break;
	case OP_LESS:
		CreateBoolResult(computedVal.at(0) < computedVal.at(1));
		break;
	case OP_GREATER:
		CreateBoolResult(computedVal.at(0) > computedVal.at(1));
		break;
	case OP_LESSEQUAL:
		CreateBoolResult(computedVal.at(0) <= computedVal.at(1));
		break;
	case OP_GREATEREQUAL:
		CreateBoolResult(computedVal.at(0) >= computedVal.at(1));
		break;
	case OP_BETWEEN:
		break;
	case OP_ISNULL:
		break;
	case OP_NOTNULL:
		break;
	case OP_LIKE:
		break;
	case OP_REGEX:
		break;
	default:
		break;
	}
	return result;
}