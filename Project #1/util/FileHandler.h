//
// Created by jairj on 10/11/2021.
//

#ifndef UNTITLED_FILEHANDLER_H
#define UNTITLED_FILEHANDLER_H
#include "../entity/Student.h"
#include "../linked-list/JLinkedList.h"
#include "../linked-list/SLinkedList.h"
#include <fstream>
//the filehandler will make writing and reading simpler to code
template<typename T>
class FileHandler{
    const std::string STUDENT="../files/ddefault.csv";
    const std::string COURSE="../files/coursesDefault.csv";
    const std::string ALLCOURSES="../files/courses.csv";


    const std::string STUDENTCOL="uid,\"Name\",age, Total Credit Hours, Number of Courses, gpa\n";
    const std::string COURSECOL="uid,\"Course Code\", \"Course Title\", Credit Hours, Grade\n";
    const std::string ALLCOURSESCOL="\"Course Code\", \"Course Title\", Credit Hours\n";

    JLinkedList<Student> *students1;

public:
    //create files if they do not exist (default and coursedefault)
    //this updates the csv files
    bool write(JLinkedList<Student> *students){

        std::ofstream studentFile(STUDENT);
        studentFile<<STUDENTCOL;
        std::ofstream courseFile(COURSE);
        courseFile<<COURSECOL;
        auto *p = students->getHead();
        while(p){
            p->getData().patchCleanupRecords();
            studentFile<<p->getData().getUid()<<","<<p->getData().getName()<<","<<unsigned(p->getData().getAge())<<","
            <<p->getData().getTotalCreditHours()<<
            ","<<p->getData().getNumberOfCourses()<<","<<p->getData().getGpa()<<"\n";

            auto *q = p->getData().getCourses()->getHead();

            while(q){
                courseFile<<p->getData().getUid()<<","<<q->getData().getCode()<<","<<q->getData().getTitle()<<
                ","<<unsigned(q->getData().getCreditHour())<<","<<q->getData().getGrade()<<"\n";
                q=q->getNext();
            }

            p=p->getNext();
        }

        studentFile.close();
        courseFile.close();
        return true;
    };
//read from csv file
    void read(){
        std::ifstream studentFile(STUDENT);
        JLinkedList<std::string> list;
        students1 = new JLinkedList<Student>;
        std::string name,data;
        uint8_t age;
        uint32_t uid,totcred,numcour;
        double gpa;
        getline(studentFile,data);
        while(getline(studentFile,data,',')){
            uid = std::stoi(data);
            getline(studentFile,name,',');
            getline(studentFile,data,',');
            age= std::stoi(data);
            getline(studentFile,data,',');
            totcred = std::stoi(data);
            getline(studentFile,data,',');
            numcour = std::stoi(data);
            getline(studentFile,data,'\n');
            gpa = std::stod(data);
            Student student(name,age,gpa,uid,totcred,numcour, new SLinkedList<Course>);
            students1->pushToBack(student);

            std::ifstream courseFile(COURSE);
            std::string code,title;
            uint8_t credHrs;
            double grade;
            getline(courseFile,data);
            while(getline(courseFile,data,',')){

                uint32_t courseUid = std::stoi(data);
                getline(courseFile,code,',');
                getline(courseFile,title,',');
                getline(courseFile,data,',');
                credHrs= std::stoi(data);
                getline(courseFile,data,'\n');
                grade= std::stod(data);
                if(courseUid==uid)
                    student.getCourses()->pushToBack(Course(code,title,grade,credHrs));
            }
            courseFile.close();
        }

studentFile.close();
    };
    //write to course file
    void writeToCourses(SLinkedList<Course> *courses){
        std::ofstream courseFile(ALLCOURSES);
        courseFile<<ALLCOURSESCOL;
        auto *q = courses->getHead();
        while(q){
            while(q){
                courseFile<<q->getData().getCode()<<","<<q->getData().getTitle()<<
                          ","<<unsigned(q->getData().getCreditHour())<<"\n";
                q=q->getNext();
            }
        }
        courseFile.close();
    }
//read courses in course file
    SLinkedList<Course> *readAllCourses(){
        std::ifstream courseFile(ALLCOURSES);
        auto *courses = new SLinkedList<Course>;
        std::string code,title;
        uint8_t credHrs;
        double grade;
        std::string data;
        getline(courseFile,data);
        while(getline(courseFile,code,',')){
            getline(courseFile,title,',');
            getline(courseFile,data,'\n');
            credHrs= std::stoi(data);
                courses->pushToBack(Course(code,title,grade,credHrs));
        }
        courseFile.close();
        return courses;
    }

    JLinkedList<Student> *getStudents1() const {
        return students1;
    }

    void setStudents1(const JLinkedList<Student> *students1) {
        FileHandler::students1 = students1;
    }
};
#endif //UNTITLED_FILEHANDLER_H
