#include <iostream>
#include <string>
#include "DateTime.h"

int main()
{
	DateTime datetimeobject(31, 10, 2018);
	std::cout << datetimeobject.getTomorrow();

	return 0;
}
