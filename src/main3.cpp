#include <iostream>
#include "DateTime.h"

#if true
int main()
{
	DateTime dateTime1(10, 11, 2000);
	DateTime dateTime2(15, 11, 2000);
	
	int32_t diff = dateTime1.getDifference(dateTime2);

	return 0;
};
#endif
