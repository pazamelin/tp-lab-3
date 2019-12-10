#ifndef _COUNTER_H
#define _COUNTER_H_

class DateTime{
    private:
        int day;
        int month;
        int year;
        string weekDNames [7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
        string monNames [12] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
    public:
        DateTime();
        DateTime(const DateTime&);
        DateTime(int day, int month, int year);
        string getToday();
        string getYesterday();
        string getTomorrow();
        string getFuture(unsigned int N);
        string getPast(unsigned int N);
        int getDifference(DateTime& U);
        string ttos(tm* th);
};

#endif
