//
// Created by jairj on 10/10/2021.
//this is the implementation of records

#ifndef UNTITLED_RECORDS_H
#define UNTITLED_RECORDS_H
#include "../linked-list/JLinkedList.h"
#include "Student.h"

class Records{

    uint32_t numberOfStudents;
    double averageGPA;
    JLinkedList<Student> *students;
    //average GPA of all students
public:
    Records();

    Records(JLinkedList<Student> *students);

    uint32_t getNumberOfStudents();

    void setNumberOfStudents(uint32_t numberOfStudents);

    double getAverageGpa();

    void setAverageGpa(double averageGpa);

    JLinkedList<Student> *getStudents() const;

    void setStudents(JLinkedList<Student> *students);

    //doublyLinkedList students


};
#endif //UNTITLED_RECORDS_H
