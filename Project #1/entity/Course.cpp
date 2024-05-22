//
// Created by jairj on 10/11/2021.
//course class

#include "Course.h"

Course :: Course(){
    code="";
    title="";
    grade=0;
    creditHour=0;
};
Course :: Course(std::string code,std::string title, double grade, uint8_t creditHour){
    this->code=code;
    this->title=title;
    this->grade=grade;
    this->creditHour=creditHour;
};

void Course::setAll(std::string code, std::string title, uint8_t creditHour){
    Course(code,title,grade,creditHour);
};

const std::string Course::getCode() {
    return code;
};

void Course::setCode(const std::string code){
    this->code=code;
};

const std::string Course::getTitle() {
    return title;
};

void Course::setTitle(const std::string title){
    this->title=title;
};

double Course::getGrade(){
    return grade;
};

void Course::setGrade(double grade){
    this->grade=grade;

};

const uint8_t Course::getCreditHour() {
    return creditHour;
};

void Course::setCreditHour(const uint8_t &creditHour){
    this->creditHour=creditHour;
};

void Course::print(){
    std::cout<<"--------------------\nTitle: "<<title<<
    "\nCode: "<<code<<
    "\nGrade: "<<grade<<
    "\nCredit Hours: "<<unsigned(creditHour)<<std::endl;
};

void Course::print1(){
    std::cout<<"Title: "<<title<<
             ", Code: "<<code<<
             ", Credit Hours: "<<unsigned(creditHour)<<std::endl;
};