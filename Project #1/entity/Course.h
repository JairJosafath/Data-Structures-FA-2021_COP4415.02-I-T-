//
// Created by jairj on 10/10/2021.
//this is the implementation of a course

#ifndef UNTITLED_COURSE_H
#define UNTITLED_COURSE_H

#include <iostream>

class Course{
    std::string code, title;
    double grade;
    uint8_t creditHour;

public:
    Course();
    //equivalent to setAll
    Course(std::string code,std::string title, double grade, uint8_t creditHour);
    //set all the datamembers of the course class
    void setAll(std::string code, std::string title, uint8_t creditHour);

    const std::string getCode() ;

    void setCode(const std::string code);

    const std::string getTitle() ;

    void setTitle(const std::string title);

    double getGrade();

    void setGrade(double grade);

    const uint8_t getCreditHour() ;

    void setCreditHour(const uint8_t &creditHour);

    //simple print in multiple lines
    void print();

    //simple print in one line
    void print1();
};
#endif //UNTITLED_COURSE_H
