//
// Created by Jonathan G. Westerfield on 10/20/16.
//

#ifndef CLASSPRACTICE_DATE_H
#define CLASSPRACTICE_DATE_H

class Date{
private:
    int day;
    int month;
    int year;
public:
    void printDate();
    int getDay();
    void setDay(int day);
    int getMonth();
    void setMonth(int month);
};
#endif //CLASSPRACTICE_DATE_H
