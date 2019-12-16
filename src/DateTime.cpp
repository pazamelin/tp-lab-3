//
//  DateTime.cpp
//  Third Shtanyuk's lab
//
//  Created by Коля on 16/12/2019.
//  Copyright © 2019 Коля. All rights reserved.
//

#include "DateTime.h"


DateTime::DateTime(short day, short month, short year)
{
    getCurrentTime();
    timeval.tm_mday = day;
    timeval.tm_mon = month - 1;
    timeval.tm_year = year;
    mktime(&timeval);
}

DateTime::DateTime()
{
    getCurrentTime();
}

void DateTime::getCurrentTime()
{
    auto cTime = time(NULL);
    timeval = *localtime(&cTime);
}

DateTime::DateTime (const DateTime &newval)
{
    timeval = newval.timeval;
}

std::string DateTime::dateToString(tm val)
{
    char mbstr[100] = "";
    val.tm_year-=1900;
    auto tmp = mktime(&val);
    std::strftime(mbstr, 40, "%d %B %Y, %A", localtime(&tmp));
    std::string data (mbstr);
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return data;
}

std::string DateTime::getPast(unsigned int N)
{
    auto result = mktime(&timeval) - N * DAY;
    return dateToString(*localtime(&result));
}

std::string DateTime::getFuture(unsigned int N)
{
    auto result = mktime(&timeval) + N * DAY;
    return dateToString(*localtime(&result));
}

std::string DateTime::getToday()
{
    return dateToString(timeval);
}

std::string DateTime::getYesterday()
{
    return getPast(1);
}

std::string DateTime::getTomorrow()
{
    return getFuture(1);
}

unsigned int DateTime::getDifference(DateTime &val)
{
    return (unsigned int)std::abs(mktime(&timeval) - mktime(&val.timeval)) / DAY;
}
