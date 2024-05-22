//
// Created by jairj on 10/11/2021.
//
#include <iomanip>
#include "Student.h"

Student ::Student() {
    setName("");
    setAge(0);
    totalCreditHours=numberOfCourses=uID=0;
    gpa=0;
    courses= nullptr;
}

Student ::Student(std:: string name, uint8_t age, uint32_t uID, SLinkedList<Course> *courses) {
    setName(name);
    setAge(age);
    this->uID=uID;
    this->courses=courses;
    this->numberOfCourses=getNumberOfCourses();
    this->totalCreditHours=getTotalCreditHours();
    auto *p = courses->getHead();
    double total=0;
//    while(p){
//        total +=p->getData().getGrade();
//        p=p->getNext();
//    }
//    this->gpa = total/courses->getSize();
}

Student::Student(std:: string name, uint8_t age, double gpa, uint32_t uID,uint32_t totalCreditHours, uint32_t numCourses, SLinkedList<Course> *courses){
    setName(name);
    setAge(age);
    this->uID=uID;
    this->courses=courses;
    this->numberOfCourses=numCourses;
    this->totalCreditHours=totalCreditHours;
    this->gpa=gpa;
};
Student ::Student(std:: string name, uint8_t age, double gpa, uint32_t uID,uint32_t totalCreditHours, SLinkedList<Course> *courses) {
    setName(name);
    setAge(age);
    this->uID=uID;
    this->courses=courses;
    this->numberOfCourses=courses->getSize();
    this->totalCreditHours=totalCreditHours;
    this->gpa=gpa;
}
//void Student:: updateGPA(){
//    auto *p = courses->getHead();
//    double total=0;
//    while(p){
//        total +=p->getData().getGrade();
//        p=p->getNext();
//    }
//    gpa = total/courses->getSize();
//}
bool Student:: addCourse(Course course){
    if(courses->pushToBack(course)){

       numberOfCourses++;
 //       updateGPA();
       return true;
    }
    return false;
};
bool Student:: deleteCourse(std:: string code){
    auto *p = courses->getHead();
    uint8_t index=0;
    while(p){
        if(p->getData().getCode()==code){
            courses->deleteNode(index);
            numberOfCourses--;
  //          updateGPA();
            return true;
        }
        index++;
        p=p->getNext();
    }
    return false;
};

uint32_t Student:: getTotalCreditHours(){
    return totalCreditHours;
} ;
void Student:: setTotalCreditHours(uint32_t totalCreditHours) {
    this->totalCreditHours=totalCreditHours;
};
uint32_t Student:: getNumberOfCourses(){
    return this->courses->getSize();
} ;
void Student:: setNumberOfCourses(uint32_t numberOfCourses){
    this->numberOfCourses=numberOfCourses;
};
uint32_t Student:: getUid(){
    return uID;
} ;
void Student:: setUid(uint32_t uId){
    this->uID=uId;
};
double Student:: getGpa(){
    return gpa;
} ;
void Student:: setGpa(double gpa){
    this->gpa=gpa;
};

SLinkedList<Course> *Student:: getCourses(){
    return courses;
};
void Student:: setCourses(SLinkedList<Course> *courses){

    this->courses=courses;
}

void Student :: patchCleanupRecords(){
    numberOfCourses = courses->getSize();
    totalCreditHours = 0;
    auto *p = courses->getHead();
    while(p){
        totalCreditHours+=p->getData().getCreditHour();
        p=p->getNext();
    }
    gpa=totalCreditHours/numberOfCourses;
}

void Student::print() {

    std::cout<<"Name: "<<getName()<<
    "\nAge: "<<unsigned(getAge())<<"\nCredit Hours: "<<totalCreditHours<<
    "\nGPA: "<<gpa<<"\nNumber of Courses: "<<numberOfCourses<<std::endl;
    std::cout<<"====student courses===="<<std::endl;
    auto *p=courses->getHead();
    while(p){
        p->getData().print();
        p=p->getNext();
    }
    std::cout<<"====  x  ===="<<std::endl<<std::endl;
}

