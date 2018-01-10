#pragma once
#include "header.h"
class DataValue
{
	typedef union
	{
		short TinyInt;
		int Int;
		long long BigInt;
		float Float;
		double Double;
	}data_value;
public:
	DataValue(){}
	DataValue(std::string & val);
	DataValue(void * val, DataType type);
	~DataValue();
	std::string& GetPureString();
	data_value value() { return _val; }

	const bool operator && (DataValue &a)const {
		data_value val = a.value();
		switch (this->type)
		{
		case DT_ANY:
			return _val.BigInt > 0 && val.BigInt > 0;
			break;
		case DT_VARCHAR:
			//unsupport
			break;
		case DT_INT:
			return _val.Int > 0 && val.Int > 0;
			break;
		case DT_TINYINT:
			return _val.TinyInt > 0 && val.TinyInt > 0;
			break;
		case DT_BIGINT:
			return _val.BigInt > 0 && val.BigInt > 0;
			break;
		case DT_DATE:
			return _val.BigInt > 0 && val.BigInt > 0;
			break;
		case DT_DATETIME:
			return _val.BigInt > 0 && val.BigInt > 0;
			break;
		case DT_TEXT:
			//unsupport
			break;
		case DT_DOUBLE:
			return _val.Double > 0 && val.Double > 0;
			break;
		case DT_FLOAT:
			return _val.Float > 0 && val.Float > 0;
			break;
		default:
			break;
		}
		return false;
	}
	const bool operator || (DataValue &a)const {
		data_value val = a.value();
		switch (this->type)
		{
		case DT_ANY:
			return _val.BigInt > 0 || val.BigInt > 0;
			break;
		case DT_VARCHAR:
			//unsupport
			break;
		case DT_INT:
			return _val.Int > 0 || val.Int > 0;
			break;
		case DT_TINYINT:
			return _val.TinyInt > 0 || val.TinyInt > 0;
			break;
		case DT_BIGINT:
			return _val.BigInt > 0 || val.BigInt > 0;
			break;
		case DT_DATE:
			return _val.BigInt > 0 || val.BigInt > 0;
			break;
		case DT_DATETIME:
			return _val.BigInt > 0 || val.BigInt > 0;
			break;
		case DT_TEXT:
			//unsupport
			break;
		case DT_DOUBLE:
			return _val.Double > 0 || val.Double > 0;
			break;
		case DT_FLOAT:
			return _val.Float > 0 || val.Float > 0;
			break;
		default:
			break;
		}
		return false;
	}
	const bool operator != (DataValue &a)const {
		data_value val = a.value();
		switch (this->type)
		{
		case DT_ANY:
			return _val.BigInt != val.BigInt;
			break;
		case DT_VARCHAR:
			return a.GetPureString().compare(pureString->c_str()) != 0;
			break;
		case DT_INT:
			return _val.Int != val.Int;
			break;
		case DT_TINYINT:
			return _val.TinyInt != val.TinyInt;
			break;
		case DT_BIGINT:
			return _val.BigInt != val.BigInt;
			break;
		case DT_DATE:
			return _val.BigInt != val.BigInt;
			break;
		case DT_DATETIME:
			return _val.BigInt != val.BigInt;
			break;
		case DT_TEXT:
			return a.GetPureString().compare(pureString->c_str()) != 0;
			break;
		case DT_DOUBLE:
			return _val.Double != val.Double;
			break;
		case DT_FLOAT:
			return _val.Float != val.Float;
			break;
		default:
			break;
		}
		return false;
	}
	const bool operator == (DataValue &a)const {
		data_value val = a.value();
		switch (this->type)
		{
		case DT_ANY:
			return _val.BigInt == val.BigInt;
			break;
		case DT_VARCHAR:
			return a.GetPureString().compare(pureString->c_str()) == 0;
			break;
		case DT_INT:
			return _val.Int == val.Int;
			break;
		case DT_TINYINT:
			return _val.TinyInt == val.TinyInt;
			break;
		case DT_BIGINT:
			return _val.BigInt == val.BigInt;
			break;
		case DT_DATE:
			return _val.BigInt == val.BigInt;
			break;
		case DT_DATETIME:
			return _val.BigInt == val.BigInt;
			break;
		case DT_TEXT:
			return a.GetPureString().compare(pureString->c_str()) == 0;
			break;
		case DT_DOUBLE:
			return _val.Double == val.Double;
			break;
		case DT_FLOAT:
			return _val.Float == val.Float;
			break;
		default:
			break;
		}
		return false;
	}
	const bool operator > (DataValue &a)const {
		data_value val = a.value();
		switch (this->type)
		{
		case DT_ANY:
			return _val.BigInt > val.BigInt;
			break;
		case DT_VARCHAR:
			//
			break;
		case DT_INT:
			return _val.Int > val.Int;
			break;
		case DT_TINYINT:
			return _val.TinyInt > val.TinyInt;
			break;
		case DT_BIGINT:
			return _val.BigInt > val.BigInt;
			break;
		case DT_DATE:
			return _val.BigInt > val.BigInt;
			break;
		case DT_DATETIME:
			return _val.BigInt > val.BigInt;
			break;
		case DT_TEXT:
			//
			break;
		case DT_DOUBLE:
			return _val.Double > val.Double;
			break;
		case DT_FLOAT:
			return _val.Float > val.Float;
			break;
		default:
			break;
		}
		return false;
	}
	const bool operator < (DataValue &a)const {
		data_value val = a.value();
		switch (this->type)
		{
		case DT_ANY:
			return _val.BigInt < val.BigInt;
			break;
		case DT_VARCHAR:
			//
			break;
		case DT_INT:
			return _val.Int < val.Int;
			break;
		case DT_TINYINT:
			return _val.TinyInt < val.TinyInt;
			break;
		case DT_BIGINT:
			return _val.BigInt < val.BigInt;
			break;
		case DT_DATE:
			return _val.BigInt < val.BigInt;
			break;
		case DT_DATETIME:
			return _val.BigInt < val.BigInt;
			break;
		case DT_TEXT:
			//
			break;
		case DT_DOUBLE:
			return _val.Double < val.Double;
			break;
		case DT_FLOAT:
			return _val.Float < val.Float;
			break;
		default:
			break;
		}
		return false;
	}
	const bool operator >= (DataValue &a)const {
		data_value val = a.value();
		switch (this->type)
		{
		case DT_ANY:
			return _val.BigInt >= val.BigInt;
			break;
		case DT_VARCHAR:
			//
			break;
		case DT_INT:
			return _val.Int >= val.Int;
			break;
		case DT_TINYINT:
			return _val.TinyInt >= val.TinyInt;
			break;
		case DT_BIGINT:
			return _val.BigInt >= val.BigInt;
			break;
		case DT_DATE:
			return _val.BigInt >= val.BigInt;
			break;
		case DT_DATETIME:
			return _val.BigInt >= val.BigInt;
			break;
		case DT_TEXT:
			//
			break;
		case DT_DOUBLE:
			return _val.Double >= val.Double;
			break;
		case DT_FLOAT:
			return _val.Float >= val.Float;
			break;
		default:
			break;
		}
		return false;
	}
	const bool operator <= (DataValue &a)const {
		data_value val = a.value();
		switch (this->type)
		{
		case DT_ANY:
			return _val.BigInt <= val.BigInt;
			break;
		case DT_VARCHAR:
			//
			break;
		case DT_INT:
			return _val.Int <= val.Int;
			break;
		case DT_TINYINT:
			return _val.TinyInt <= val.TinyInt;
			break;
		case DT_BIGINT:
			return _val.BigInt <= val.BigInt;
			break;
		case DT_DATE:
			return _val.BigInt <= val.BigInt;
			break;
		case DT_DATETIME:
			return _val.BigInt <= val.BigInt;
			break;
		case DT_TEXT:
			//
			break;
		case DT_DOUBLE:
			return _val.Double <= val.Double;
			break;
		case DT_FLOAT:
			return _val.Float <= val.Float;
			break;
		default:
			break;
		}
		return false;
	}
	const bool operator ! ()const {
		switch (this->type)
		{
		case DT_ANY:
			return _val.BigInt > 0 ? false : true;
			break;
		case DT_VARCHAR:
			//
			break;
		case DT_INT:
			return _val.Int > 0 ? false : true;
			break;
		case DT_TINYINT:
			return _val.TinyInt > 0 ? false : true;
			break;
		case DT_BIGINT:
			return _val.BigInt > 0 ? false : true;
			break;
		case DT_DATE:
			return _val.BigInt > 0 ? false : true;
			break;
		case DT_DATETIME:
			return _val.BigInt > 0 ? false : true;
			break;
		case DT_TEXT:
			//
			break;
		case DT_DOUBLE:
			return _val.Double > 0 ? false : true;
			break;
		case DT_FLOAT:
			return _val.Float > 0 ? false : true;
			break;
		default:
			break;
		}
		return false;
	}
	const DataValue operator + (DataValue &a)const {
		data_value val = a.value();
		data_value nval;
		switch (this->type)
		{
		case DT_ANY:
			
			break;
		case DT_VARCHAR:
			//
			break;
		case DT_INT:
			nval.Int = _val.Int + val.Int;
			return DataValue(&nval, DT_INT);
			break;
		case DT_TINYINT:
			nval.TinyInt = _val.TinyInt + val.TinyInt;
			return DataValue(&nval, DT_TINYINT);
			break;
		case DT_BIGINT:
			nval.BigInt = _val.BigInt + val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_DATE:
			nval.BigInt = _val.BigInt + val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_DATETIME:
			nval.BigInt = _val.BigInt + val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_TEXT:
			//
			break;
		case DT_DOUBLE:
			nval.Double = _val.Double + val.Double;
			return DataValue(&nval, DT_DOUBLE);
			break;
		case DT_FLOAT:
			nval.Float = _val.Float + val.Float;
			return DataValue(&nval, DT_FLOAT);
			break;
		default:
			break;
		}
		return DataValue(std::string("null"));
	}
	const DataValue operator - (DataValue &a)const {
		data_value val = a.value();
		data_value nval;
		switch (this->type)
		{
		case DT_ANY:

			break;
		case DT_VARCHAR:
			//
			break;
		case DT_INT:
			nval.Int = _val.Int - val.Int;
			return DataValue(&nval, DT_INT);
			break;
		case DT_TINYINT:
			nval.TinyInt = _val.TinyInt - val.TinyInt;
			return DataValue(&nval, DT_TINYINT);
			break;
		case DT_BIGINT:
			nval.BigInt = _val.BigInt - val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_DATE:
			nval.BigInt = _val.BigInt - val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_DATETIME:
			nval.BigInt = _val.BigInt - val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_TEXT:
			//
			break;
		case DT_DOUBLE:
			nval.Double = _val.Double - val.Double;
			return DataValue(&nval, DT_DOUBLE);
			break;
		case DT_FLOAT:
			nval.Float = _val.Float - val.Float;
			return DataValue(&nval, DT_FLOAT);
			break;
		default:
			break;
		}
		return DataValue(std::string("null"));
	}
	const DataValue operator * (DataValue &a)const {
		data_value val = a.value();
		data_value nval;
		switch (this->type)
		{
		case DT_ANY:

			break;
		case DT_VARCHAR:
			//
			break;
		case DT_INT:
			nval.Int = _val.Int * val.Int;
			return DataValue(&nval, DT_INT);
			break;
		case DT_TINYINT:
			nval.TinyInt = _val.TinyInt * val.TinyInt;
			return DataValue(&nval, DT_TINYINT);
			break;
		case DT_BIGINT:
			nval.BigInt = _val.BigInt * val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_DATE:
			nval.BigInt = _val.BigInt * val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_DATETIME:
			nval.BigInt = _val.BigInt * val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_TEXT:
			//
			break;
		case DT_DOUBLE:
			nval.Double = _val.Double * val.Double;
			return DataValue(&nval, DT_DOUBLE);
			break;
		case DT_FLOAT:
			nval.Float = _val.Float * val.Float;
			return DataValue(&nval, DT_FLOAT);
			break;
		default:
			break;
		}
		return DataValue(std::string("null"));
	}
	const DataValue operator / (DataValue &a)const {
		data_value val = a.value();
		data_value nval;
		switch (this->type)
		{
		case DT_ANY:

			break;
		case DT_VARCHAR:
			//
			break;
		case DT_INT:
			nval.Int = _val.Int / val.Int;
			return DataValue(&nval, DT_INT);
			break;
		case DT_TINYINT:
			nval.TinyInt = _val.TinyInt / val.TinyInt;
			return DataValue(&nval, DT_TINYINT);
			break;
		case DT_BIGINT:
			nval.BigInt = _val.BigInt / val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_DATE:
			nval.BigInt = _val.BigInt / val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_DATETIME:
			nval.BigInt = _val.BigInt / val.BigInt;
			return DataValue(&nval, DT_BIGINT);
			break;
		case DT_TEXT:
			//
			break;
		case DT_DOUBLE:
			nval.Double = _val.Double / val.Double;
			return DataValue(&nval, DT_DOUBLE);
			break;
		case DT_FLOAT:
			nval.Float = _val.Float / val.Float;
			return DataValue(&nval, DT_FLOAT);
			break;
		default:
			break;
		}
		return DataValue(std::string("null"));
	}
private:
	DataType type = DT_ANY;
	std::string *pureString;
	data_value _val;
	int size; //int
	int decimal;//dec
};

