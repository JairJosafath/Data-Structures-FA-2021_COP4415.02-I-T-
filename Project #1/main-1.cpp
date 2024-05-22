//
// Created by jairj on 10/12/2021.
//

// I have not done any error handling, entering data other than requested might lead to unwanted results

#include <iostream>
#include "util/FileHandler.h"

using namespace std;
JLinkedList<Student> *getStudents();
JNode<Student> *getStudent(uint32_t id, JLinkedList<Student> *student);
void printAll(JLinkedList<Student> *students);
JNode<Student> *chooseFromRecords(JLinkedList<Student> *students);
Course *chooseFromRecords(SLinkedList<Course> *courses, uint32_t id);
uint32_t chooseFromRecordsGetCode(SLinkedList<Course> *courses, uint32_t id);
uint32_t chooseFromRecords(SLinkedList<Course> *courses);
SLinkedList<Course> *getAllCourses();
uint32_t chooseFromRecordsGetID(JLinkedList<Student> *students);

//this function controls the menu operations using a switch
void control(uint16_t choice){


    JLinkedList<Student> *students = getStudents();
    SLinkedList<Course> *allCourses = getAllCourses();
    Student student;
    Course course;
    FileHandler<Student> fileHandler;
    JNode<Student> *p;
    string str;
    int id=0;
    string name;
    uint16_t age;
    uint16_t choice1,credHrs;
    double grade;
    bool correct;
    string code;
    string title;
    double gpa;
    uint16_t total=0;
    int i = 1;
    uint16_t index = 0;
    switch (choice) {

        case 1:
            p = students->getHead();
            if(!p){
                cout<<"no records found"<<endl;
                break;
            }
            while(p){
                p->getData().print();
                p=p->getNext();
            }
            break;
        case 2:
            index = chooseFromRecordsGetID(students);
            students->nodeAt(index)->getData().print();
            break;
        case 3:
            cout << "student id: ";
            cin >> id;
            cout << "student name: ";
            cin >> name;
            cout << "student age: ";
            cin >> age;
            student.setUid(id);

            student.setName(name);
            student.setAge(unsigned(age));
            //ask for id, name and age.
            //ask user to choose from a list of courses the student not yet has or to create a new course
            course = allCourses->nodeAt(chooseFromRecords(allCourses))->getData();

            student.setCourses(new SLinkedList<Course>());
            cout << "student grade in this class: " << endl;
            cin >> grade;
            gpa += grade;
            student.addCourse(*(new Course(course.getCode(), course.getTitle(), grade, course.getCreditHour())));
            total++;
            students->pushToBack(student);
            fileHandler.write(students);
            cout << "enter y if you want to continue adding courses, otherwise enter n" << endl;
            cin >> str;
            if (str != "y") correct = false;
            else correct = true;
            while (correct) {
                course = *chooseFromRecords(allCourses, id);
                gpa += course.getGrade();
                student.addCourse(course);
                total++;
                cout << "enter y if you want to continue adding courses, otherwise enter n" << endl;
                cin >> str;
                if (str != "y") correct = false;
            }
            gpa /= total;
            students->getTail()->setData(
                    Student(student.getName(), student.getAge(), gpa, student.getUid(), total, student.getCourses()));

            fileHandler.write(students);
            break;
        case 4:

            id = chooseFromRecordsGetID(students);


            //confirm deletion of student
            if(students->deleteNode(id)){
                cout<<"deletion was succesful";
            }

            fileHandler.write(students);
            break;
        case 5:
            //give user an option to find a student by their id or by choosing from a list
            cout<<"(1) choose student from list"<<endl;

                    student = chooseFromRecords(students)->getData();



                    students->pushToBack(student);
                    fileHandler.write(students);


        cout<<"please add the courses for the student\n(1) choose course from list\n(2) create new course"<<endl;

        cin>>choice1;
            switch (choice1) {
                case 1: course = *chooseFromRecords(allCourses,student.getUid());

                student.addCourse((course));
                gpa+=course.getGrade();
                total++;
                    break;
                case 2:
                    cout<<"course Code: "<<endl;
                    cin>>code;
                    cout<<"course Title: "<<endl;
                    cin>>title;
                    cout<<"credit hours: "<<endl;
                    cin>>credHrs;
                    cout<<"student grade in this course: "<<endl;
                    cin>>grade;
                    student.addCourse(Course(code,title,grade,credHrs));
                    total++;
                    gpa+=grade;
                    allCourses->pushToBack(Course(code,title,grade,credHrs));
                    fileHandler.writeToCourses(allCourses);
                    break;
            }
            student.setGpa((student.getGpa()+(gpa/total))/2);

            fileHandler.write(students);

            break;
        case 6:

            index = chooseFromRecordsGetID(students);

            student = students->nodeAt(index)->getData();
            index = chooseFromRecordsGetCode(allCourses,student.getUid());
            course = allCourses->nodeAt(index)->getData();

            if(student.deleteCourse(course.getCode())){
                cout<<"course has been deleted";
            }

            //Student(student.getName(),student.getAge(),gpa,student.getUid(),total,student.getCourses());
            fileHandler.write(students);

            break;
    }

}


int main(){
    cout<<"Welcome to the Phoenix Record System"<<endl<<endl;
    uint16_t choice=0;
    //menu
    while(true){
        cout<<"Please select one of the following:"<<endl;
        cout<<"(1) Print all records"<<endl;
        cout<<"(2) Print the record for a single student"<<endl;
        cout<<"(3) Add a student"<<endl;
        cout<<"(4) Delete a student"<<endl;
        cout<<"(5) Add a course to a student"<<endl;
        cout<<"(6) Delete a course from a student"<<endl;
        cout<<"(0) EXIT"<<endl;
        cin>>choice;
        if(choice==0){
            cout<<"thanks for using the system, enjoy your day!"<<endl;
            choice=false;
            break;
        }
        if(1<=choice&&choice<=6){
            control(choice);
        }else{
            cout<<"please choose one of the options given"<<endl;
        }
    }
    return 0;

}

//read from csv file
JLinkedList<Student> *getStudents(){
    FileHandler<Student> fileHandler;
    fileHandler.read();
    return fileHandler.getStudents1();
}
//get student by id
JNode<Student> *getStudent(uint32_t id, JLinkedList<Student> *students){
    auto *p = students->getHead();
    while(p){
        if(p->getData().getUid()==id){
            //p->getData().print();

            return p;
        }
        p=p->getNext();
    }
    cout<<"no record found"<<endl;
    return nullptr;
}

//print all students
void printAll(JLinkedList<Student> *students) {
    auto *p = students->getHead();
    while(p){
       // p->getData().print();
        p=p->getNext();
        if(!p) return;
    }
    cout<<"no record found"<<endl;
}

//function guiding the user to choose desired student
JNode<Student> *chooseFromRecords(JLinkedList<Student> *students){
    cout<<"choose the desired student"<<endl;
    auto *p=students->getHead();
    uint16_t i=1,choice=0;

    while(p){
        cout<<"("<<i<<")"<<"student ID: "<<p->getData().getUid()<<
        ", student name: "<<p->getData().getName()<<endl;
        i++;
        p=p->getNext();
    }
    cin>>choice;

    return students->nodeAt(choice-1);

}
//function guiding the user to choose desired student
uint32_t chooseFromRecordsGetID(JLinkedList<Student> *students){
    cout<<"choose the desired student"<<endl;
    auto *p=students->getHead();
    uint16_t i=1,choice=0;

    while(p){
        cout<<"("<<i<<")"<<"student ID: "<<p->getData().getUid()<<
            ", student name: "<<p->getData().getName()<<endl;
        i++;
        p=p->getNext();
    }
    cin>>choice;

    return choice-1;

}
//function guiding the user to choose desired course
Course *chooseFromRecords(SLinkedList<Course> *courses, uint32_t id){
    bool correct = false;
    Course temp;
    uint16_t choice=0;
    double grade;
    while(!correct){
        cout<<"choose the desired course"<<endl;
        auto *p = courses->getHead();

        uint16_t i=1;
        while(p){
            cout<<"("<<i<<")";
            p->getData().print1();
            i++;
            p=p->getNext();
        }
        cin>>choice;
        correct=true;

            auto *q = getStudent(id, getStudents())->getData().getCourses()->getHead();
            while (q) {
                if (courses->nodeAt(choice - 1)->getData().getCode() != q->getData().getCode()) {
                    q = q->getNext();

                } else {
                    cout << "the student is already in this course" << endl;
                    break;
                }
               if(!q){
                   correct = true;
                   cout<<"student grade in this class: "<<endl;
                   cin>>grade;
                   temp = courses->nodeAt(choice-1)->getData();

               }
            }


    }
    return new Course(temp.getCode(),temp.getTitle(),grade,temp.getCreditHour());

};

//function guiding the user to choose desired course
uint32_t chooseFromRecords(SLinkedList<Course> *courses){
    bool correct = false;
    string patch;
    uint16_t choice=0;
    while(!correct){
        cout<<"choose the desired course"<<endl;
        auto *p = courses->getHead();

        uint16_t i=1;
        while(p){
            cout<<"("<<i<<")";
            p->getData().print1();
            i++;
            p=p->getNext();
        }
//        cin>>choice ;
//        cin.ignore();
        getline(cin,patch);
        cin>>choice;


        if(choice>0&&choice<=i){
            correct=true;
        }else{
            cout<<"please choose one of the given options"<<endl;
        }
    }
    return (choice-1);

};

////function guiding the user to choose desired course
uint32_t chooseFromRecordsGetCode(SLinkedList<Course> *courses, uint32_t uid){
    bool correct = false;
    string patch;
    uint16_t choice=0;
    while(!correct){
        cout<<"choose the desired course"<<endl;
        auto *p = courses->getHead();

        uint16_t i=1;
        while(p){
            cout<<"("<<i<<")";
            p->getData().print1();
            i++;
            p=p->getNext();
        }

        getline(cin,patch);
        cin>>choice;


        if(choice>0&&choice<=i){
            correct=true;
        }else{
            cout<<"please choose one of the given options"<<endl;
        }
    }
    return (choice-1);

};

//read all courses
SLinkedList<Course> *getAllCourses(){
    FileHandler<Course> fileHandler;
    return fileHandler.readAllCourses();
}