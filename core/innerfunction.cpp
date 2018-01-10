#include "innerfunction.h"
ComputeResult count(std::list<Column*> args)
{
	size_t total = 0;
	for each (auto arg in args)
	{
		total += arg->count();
	}
	return ComputeResult(DataValue(&total, DT_BIGINT));
}