#include <iostream>
#include <string>
#include "DateTime.h"

int main()
{
	{
		DateTime dt(31, 10, 2018);
		std::string expect = "01 november 2018, thursday";
		//EXPECT_EQ(expect, dt.getTomorrow());
		std::cout << dt.getTomorrow() << std::endl;
	}

	{
		DateTime dt(1, 11, 2018);
		std::string expect = "02 november 2018, friday";
		//EXPECT_EQ(expect, dt.getTomorrow());
		std::cout << dt.getTomorrow() << std::endl;
	}

	{
		DateTime dt(1, 11, 2018);
		std::string expect = "01 november 2018, thursday";
		std::cout << dt.getToday() << std::endl;
		//EXPECT_EQ(expect, dt.getToday());
	}

	{
		DateTime dt1(20, 11, 2018);
		DateTime dt2(20, 11, 2018);
		int diff = 0;
		std::cout << dt1.getDifference(dt2) << std::endl;
		//EXPECT_EQ(diff, dt1.getDifference(dt2));
		
	}

	{
		DateTime dt1(20, 11, 2018);
		DateTime dt2(21, 11, 2018);
		int diff = 1;
		std::cout << dt2.getDifference(dt1) << std::endl;
		//EXPECT_EQ(diff, dt2.getDifference(dt1));
	}

	return 0;
}
