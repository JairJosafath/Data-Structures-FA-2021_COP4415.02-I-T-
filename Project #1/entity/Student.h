//
// Created by jairj on 10/10/2021.
// this is the implementation of a Student

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include "Person.h"
#include "../linked-list/SLinkedList.h"

class Student : public Person{
    uint32_t totalCreditHours, numberOfCourses, uID;
    double gpa;
    SLinkedList<Course> *courses;
public:

    Student();

    //constructors
    Student(std:: string name, uint8_t age, uint32_t uID, SLinkedList<Course> *courses);
    Student(std:: string name, uint8_t age, double gpa, uint32_t uID,uint32_t totalCreditHours, SLinkedList<Course> *courses);
    Student(std:: string name, uint8_t age, double gpa, uint32_t uID,uint32_t totalCreditHours, uint32_t numCourses ,SLinkedList<Course> *courses);

    //adds a course to the student
    bool addCourse(Course course);
    //deletes a course
    bool deleteCourse(std::string code);
    //update gpa
    void updateGPA();
    uint32_t getTotalCreditHours() ;
    void setTotalCreditHours(uint32_t totalCreditHours) ;
    uint32_t getNumberOfCourses() ;
    void setNumberOfCourses(uint32_t numberOfCourses);
    uint32_t getUid() ;
    void setUid(uint32_t uId);
    double getGpa() ;
    void setGpa(double gpa);
    SLinkedList<Course> *getCourses();
    void setCourses(SLinkedList<Course> *courses);
    //print student info
    void print();
    //update student records so the average gpa and num of courses is correct
    void patchCleanupRecords();


};


#endif //UNTITLED_STUDENT_H
