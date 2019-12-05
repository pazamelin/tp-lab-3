#include "DateTime.h"

 string  DateTime::getToday() // возвращение текущей даты в виде строки, с указанием дня недели и названия месяца(например 07 november 2018, wedensday);
{
	 string answ = retDate(timeStruct);
	 return answ;
}
 string DateTime::retDate(tm datetm)
 {
	 string answ = "";
	 if (datetm.tm_mday < 10)
	 {
		 answ += "0";
	 }
	 answ += to_string(datetm.tm_mday) + " ";
	 string mons[12] = { "january ", "february ", "march ", "april ", "may ", "june ", "july ", "august ", "september ", "october ", "november ", "december " };
	 answ += mons[datetm.tm_mon];
	 answ += to_string(datetm.tm_year + 1900);
	 answ += ", ";
	 string wdays[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	 answ += wdays[datetm.tm_wday];
	 return answ;
 }
 string DateTime::getTomorrow()
 {
	 string answ = getFuture(1);
	 return answ;
 }
 string DateTime::getPast(unsigned int N)
 {
	 tm curDay = timeStruct;
	 for (int i = 0; i < N; i++)
	 {
		 if (curDay.tm_mday > 1)
		 {
			 curDay.tm_mday--;
		 }
		 else
		 {
			 if (curDay.tm_mon > 0)
			 {
				 curDay.tm_mon--;
			 }
			 else
			 {
				 curDay.tm_year--;
				 curDay.tm_mon = 11;
			 }
			 curDay.tm_mday = daysInMon(curDay.tm_mon, visYear(curDay.tm_year + 1900));
		 }
	 }
	 mktime(&curDay);
	 string answ = retDate(curDay);
	 return answ;
 }
 string DateTime::getYesterday()
 {
	 string answ = getPast(1);
	 return answ;
 }

 string DateTime::getFuture(unsigned int N) // -возвращение даты через N дней в будущем;
 {
	 int mdays = daysInMon(timeStruct.tm_mon, visYear(timeStruct.tm_year + 1900));
	 tm curDay = timeStruct;
	 for (int i = 0; i < N; i++)
	 {
		 if ( curDay.tm_mday < mdays)
		 {
			 curDay.tm_mday++;
		 }
		 else
		 {
			 curDay.tm_mday = 1;
			 if (curDay.tm_mon < 11)
			 {
				 curDay.tm_mon++;

			 }
			 else
			 {
				 curDay.tm_mon = 0;
				 curDay.tm_year++;
			 }
			 mdays = daysInMon(curDay.tm_mon, visYear(curDay.tm_year + 1900));
		 }
	 }
	 mktime(&curDay);
	 string answ = retDate(curDay);
	 return answ;
 }

 int DateTime::daysInMon(int m, bool y)
 {
	 int days = 31;
	 switch (m)
	 {
	 case 3: days--;
		 break;
	 case 5: days--;
		 break;
	 case 8: days--;
		 break;
	 case 10: days--;
		 break;
	 case 1: days = 28;
		 if (y) days++;
		 break;
	 default:
		 break;
	 }
	 return days;
 }
 bool DateTime::visYear(int y)
 {
	 if (y % 4 == 0)
	 {
		 if ((y % 100 != 0) || (y % 400 == 0))
		 {
			 return true;
		 }
	 }
	 return false;
 }

 tm DateTime::retTM(DateTime t)
 {
	 tm cur;
	 cur.tm_year = t.timeStruct.tm_year;
	 cur.tm_mon = t.timeStruct.tm_mon;
	 cur.tm_mday = t.timeStruct.tm_mday;
	 mktime(&cur);
	 return cur;
 }

 int DateTime::getDifference(DateTime& dt2)
 {
	 tm t1 = timeStruct;
	 tm t2 = dt2.timeStruct;
	 int diff = difftime(mktime(&t1), mktime(&t2)) / 86400;
	 diff = abs(diff);
	 return diff;
 }

 bool DateTime::sameDate(tm date2)
 {
	 return((timeStruct.tm_year == date2.tm_year) && (timeStruct.tm_mon == date2.tm_mon) && (timeStruct.tm_mday == date2.tm_mday));
 }