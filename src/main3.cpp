#include <iostream>
#include "Circle.h"
#include "task1.h"
#include "DateTime.h"
using namespace std;


int main(){
    DateTime datetime;
    cout<<datetime.getToday()<<endl;
    cout<<datetime.getFuture(2)<<endl;
    cout<<datetime.getPast(1)<<endl;
    DateTime dt(02,02,2001);
    cout<<dt.getTomorrow()<<endl;
    cout<<dt.getYesterday()<<endl;
    DateTime dtoday(17,12,2019);
    cout<<dtoday.getDifference(dt)<<endl;

}