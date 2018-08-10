/* This works. It seems so redundant, but it must be useful for large apps. I suppose the benefit is I don't have to rewrite this class. I can keep reusing it via different objects.*/

#include <iostream>
using namespace std;

class Date 
{
    private:
        int month;
        int day;
        int year;
    public: 
       void setMonth(int);
       void setDay(int);
       void setYear(int);
       int getMonth() const;
       int getDay() const;
       int getYear() const;
};

void Date::setMonth(int m)
{
    month = m;
}
void Date::setDay(int d)
{
    day = d;
}
void Date::setYear(int y)
{
    year = y;
}

int Date::getMonth() const 
{
    return month;
}

int Date::getDay() const
{
    return day;
}
int Date::getYear() const
{
    return year;
}


int main()
{
    
Date todaysDate;
int month = 4, day = 2, year = 2014;

// NEED TO SET EM BEFORE YOU GET EM
todaysDate.setMonth(month);
todaysDate.setDay(day);
todaysDate.setYear(year);


cout << todaysDate.getMonth() << "/" << todaysDate.getDay() << "/" << todaysDate.getYear();

}