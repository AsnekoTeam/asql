#include "DataValue.h"

DataValue::DataValue(std::string & val)
{
	this->pureString = &val;
}

DataValue::DataValue(void * src, DataType type)
{
	this->type = type;
	switch (type)
	{
	case DT_TINYINT:
		this->_val.TinyInt = *((short*)src);
		break;
	case DT_INT:
		this->_val.Int = *((int*)src);
		break;
	case DT_DOUBLE:
		this->_val.Double = *((double*)src);
		break;
	case DT_FLOAT:
		this->_val.Float = *((float*)src);
		break;
	default:
		this->_val.BigInt = *((long long*)src);
		break;
	}


}

DataValue::~DataValue()
{

}

std::string& DataValue::GetPureString()
{
	return *this->pureString;
}

