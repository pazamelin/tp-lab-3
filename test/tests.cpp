#include "gtest/gtest.h"

#include "task1.h"
#include "Circle.h"
#include "DateTime.h"
#include <cmath>
#include <string>
	
TEST(circle,circle_get_area1)
{
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0,c.getArea());
}
TEST(circle,circle_get_ference1)
{
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0,c.getFerence());
}
TEST(circle,circle_get_area2)
{
    Circle c(10.0);
    EXPECT_DOUBLE_EQ(31416.0,round(c.getArea()*100));
}
TEST(circle,circle_get_ference2)
{
    Circle c(10.0);
    EXPECT_DOUBLE_EQ(6283.0,round(c.getFerence()*100));
}
TEST(date,datetime_gettomorrow1)
{
    DateTime dt(31,10,2018);
    std::string expect="01 november 2018, thursday";
    EXPECT_EQ(expect,dt.getTomorrow());
}
TEST(date,datetime_gettomorrow2)
{
    DateTime dt(1,11,2018);
    std::string expect="02 november 2018, friday";
    EXPECT_EQ(expect,dt.getTomorrow());
}
TEST(date,datetime_gettoday)
{
    DateTime dt(1,11,2018);
    std::string expect="01 november 2018, thursday";
    EXPECT_EQ(expect,dt.getToday());
}
TEST(date,datetime_getdiff1)
{
    DateTime dt1(20,11,2018);
    DateTime dt2(20,11,2018);
    int diff=0;
    EXPECT_EQ(diff,dt1.getDifference(dt2));
}
TEST(date,datetime_getdiff2)
{
    DateTime dt1(20,11,2018);
    DateTime dt2(21,11,2018);
    int diff=1;
    EXPECT_EQ(diff,dt2.getDifference(dt1));
}
TEST(calc,delta)
{    
    EXPECT_DOUBLE_EQ(16.0,round(calcDelta()*100));
}
TEST(calc,pool_cost)
{    
    EXPECT_DOUBLE_EQ(72257.0,round(calcCost()));
}
