//
// Created by jairj on 10/11/2021.
//
#include <iostream>
#include <fstream>
#include <string>
#include "../util/FileHandler.h"
#include "../entity/Student.h"

using namespace std;
int main(){
//    ifstream file;
//    string line;
//    file.open("../files/test.csv");
//
//    if(file.fail()){
//        cout<<"failed";
//    }else{
//        while(!file.eof()){
//            getline(file,line);
//            cout<<line<<endl;
//        }
//        file.close();
//    }
//    auto *p = new Person("Mike",14);
//    Course c("COP","Comp Progr",3.4,3);
//    Course d("MAC","Calculus",3,5);
//    Course e("ENC","Enlgish",2,3);
//    Course f("CHM","Chemistry",2.5,4);
//
//    //gpa for a student should be calculated
//
//    auto *list = new SLinkedList<Course>;
//    //list->pushToFront(c);
//    list->pushToFront(d);
//    list->pushToFront(e);
//    list->pushToFront(f);
//
//    Student student("Jon",23,7878,list);
//    //student.print();
//
//    auto *list1 = new SLinkedList<Course>;
//    list1->pushToFront(c);
//    list1->pushToFront(e);
//
//    Student student1("Will",12,3443,list1);
//
//    auto *students = new JLinkedList<Student>;
//
//    students->pushToFront(student1);
//    students->pushToFront(student);
//    //student.print();
////
    FileHandler<Student> fileHandler;
//    fileHandler.write(students);
    fileHandler.read();
    auto *s = fileHandler.getStudents1()->getHead();
    while(s){
        s->getData().print();
        s=s->getNext();
    }
    return 0;
}