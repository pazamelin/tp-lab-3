#include <iostream>
#include "DateTime.h"

int main()
{
    DateTime temp_date_1(16,12,2019);
    std::cout << temp_date_1.getTomorrow() << std::endl;
    std::cout << temp_date_1.getYesterday() << std::endl;
    DateTime temp_date_2(19,12,2019);
    std::cout << temp_date_1.getDifference(temp_date_2) << std::endl;
    
    return 0;
}
