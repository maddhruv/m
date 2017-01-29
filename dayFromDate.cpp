#include<iostream>
#include<string>

using namespace std;

//days in the months
const int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

//days from the beginning to the end
const int daysToMonth[12] = {0,31,59,90,120,151,181,212,243,273,304,334};

//days
string dayName[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

//day 0 => 01-01-1900 i.e. Monday
const int DAY0 = 1;

//check the leap year
int LeapYear(int year){
    int status = 0;
    if(year%4 == 0 && (year%100 != 0 || year%400 == 0))
        status = 1;
    return status;
}

//date verify
int ValidDate(int day, int month, int year){
    // b/w 01-01-1900 and 12-31-2999
    int valid = 0;
    int days;
    if(year>=1900 && year<=2999 && month>=1 && month<=12){
        days = daysInMonth[month-1];
        if(month==2 && (LeapYear(year)==1)){
            days++;
        }
        if(day>=1 && day<=days){
            valid=1;
        }
    }
    return valid;
}

//Days Since 1900 to the DD-MM-YYYY
long DaysSince(int day, int month, int year){
    long days;

    days = long(year-1900)*365 + (year-1897)/4 - (year-1801)/100 + (year-1601)/400;

    days += daysToMonth[month-1];
    if(LeapYear(year) && month>=2){
        days++;
    }
    days += day-1;
    return days;
}

int DayOfWeek(int day, int month, int year){
    return(DAY0 + (DaysSince(day, month, year))%7);
}

int main(){
    int day, month, year, weekday;
    cout<<"Please enter a date: DD-MM-YYYY =>";
    cin>>day>>month>>year;

    if(ValidDate(day,month,year)==0){
        cout<<"\a"<<"**** Invalid Date ****\n";
        return 0;
    }

    weekday = DayOfWeek(day, month, year);

    cout<<day<<"-"<<month<<"-"<<year<<" ------ "<<dayName[weekday]<<endl;
    return 0;
}
