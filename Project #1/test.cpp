//
// Created by jairj on 10/11/2021.
//
#include "../entity/Person.h"
#include"../entity/Course.h"
#include "../linked-list/SLinkedList.h"
#include "../entity/Student.h"
#include "../entity/Records.h"
#include <iostream>

int main(){

    //auto *p = new Person("Mike",14);
    Course c("COP","Comp Progr",3.4,3);
    Course d("MAC","Calculus",3,5);
    Course e("ENC","Enlgish",2,3);
    Course f("CHM","Chemistry",2.5,4);

    //gpa for a student should be calculated

    auto *list = new SLinkedList<Course>;
    //list->pushToFront(c);
    list->pushToFront(d);
    list->pushToFront(e);
    list->pushToFront(f);

    Student student("Jon",23,7878,list);
    //student.print();

    auto *list1 = new SLinkedList<Course>;
    list1->pushToFront(c);
    list1->pushToFront(e);

    Student student1("Will",12,3443,list1);

    auto *students = new JLinkedList<Student>;

    students->pushToFront(student1);
    students->pushToFront(student);

    auto *p = students->getHead();
    while(p){
        p->getData().print();
        p=p->getNext();
    }

    //Records records(students);
    //student1.deleteCourse(c.getCode());
    //student1.print();

//    auto *h = list->getHead();
//    while(h){
//        h->getData().print();
//        h=h->getNext();
//    }

    return 0;
}