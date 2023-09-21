/**
 * @file index.h
 * @author Luke Steinford
 * @brief 
 * @version 0.1
 * @date 2023-09-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

struct Student
{
    int id;
    string lastName;
    string firstName;
    string ssn;
    float test[4];
    float final;
    string letterGrade;
};

void openInputFile(ifstream &file, string fileName);
void readFile(ifstream &file, Student a[]);
void homeScreen();
void point(Student * ptrs[], Student array[], int size);
bool compareLast(Student* a, Student* b);
void indexByLastName(Student * ptrs[], int size);
bool compareSSN(Student* a, Student* b);
void indexBySSN(Student * ptrs[], int size);
void searchByLastName(Student * ptrs[], int size);
void searchBySSN(Student * ptrs[], int size);
void displayAllInfo(Student * ptrs[], int size);
void displayStudentInfo(Student * ptrs[], int i);


#endif