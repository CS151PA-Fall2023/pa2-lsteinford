/**
 * @file index.cpp
 * @author Luke Steinford
 * @brief 
 * @version 0.1
 * @date 2023-09-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "index.h"

/**
 * @brief Opens the ifstream file
 * 
 * @param file 
 * @param fileName 
 */
void openInputFile(ifstream &file, string fileName)
{   
    file.open(fileName);
    if (!file){
        cout << "Error opening file\n";
        exit(1);
    }
}

/**
 * @brief Adds data from file to the Student array
 * 
 * @param file 
 * @param a 
 */
void readFile(ifstream &file, Student a[])
{
    string header; // variable for first line
    char delim; // variable for ',' char between values
    int i = 0; // counter for array position

    getline(file, header);

    while(file.peek() != EOF){
        Student newStudent;
        
        file >> newStudent.id >> delim;

        getline(file, newStudent.lastName, ',');
        getline(file, newStudent.firstName, ',');
        getline(file, newStudent.ssn, ',');

        file >> newStudent.test[0] >> delim
             >> newStudent.test[1] >> delim
             >> newStudent.test[2] >> delim
             >> newStudent.test[3] >> delim
             >> newStudent.final >> delim;

        getline(file, newStudent.letterGrade);

        a[i] = newStudent;
        i++;
    }
}

/**
 * @brief Display menu options
 * 
 */
void homeScreen()
{
    cout << "1. Print data in ascending order by last name\n";
    cout << "2. Print data in ascending order by SSN\n";
    cout << "3. Search by last name\n";
    cout << "4. Search by SSN\n";
    cout << "5. Exit\n" << endl;
}

/**
 * @brief Points the pointer arrays to the main student array
 * 
 * @param ptrs 
 * @param array 
 * @param size 
 */
void point(Student * ptrs[], Student array[], int size)
{
   //ASSIGN EACH POINTER IN ptrs THE ADRESS OF CORRESPONDING ELEMENT IN array
   for (int i = 0; i < size; i++)
   {
        ptrs[i] = &array[i];
   }
}

/**
 * @brief Compares the last name strings
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool compareLast(Student* a, Student* b){
    return a->lastName < b->lastName;
}

/**
 * @brief Sorts the lastName pointer array and displays it
 * 
 * @param ptrs 
 * @param size 
 */
void indexByLastName(Student * ptrs[], int size)
{
    sort(ptrs, ptrs + size, compareLast);
    cout << "Sorted by Last Name\n";
    cout << left << setw(4) <<"ID" << setw(10) << "Last Name" << setw(12) << "First Name" << setw(12) << "SSN" << "Grade\n";
    for (int i = 0; i < size; i++){
        cout << right << setw(2) << ptrs[i]->id << "  " 
             << left << setw(10) << ptrs[i]->lastName 
             << left << setw(12) << ptrs[i]->firstName 
             << left << setw(12) << ptrs[i]->ssn 
             << ptrs[i]->letterGrade << endl;
    }
}

/**
 * @brief Compares the SSN strings
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool compareSSN(Student* a, Student* b)
{
    return a->ssn < b->ssn;
}

/**
 * @brief Sorts the SSN pointer array and displays it
 * 
 * @param ptrs 
 * @param size 
 */
void indexBySSN(Student * ptrs[], int size)
{
    sort(ptrs, ptrs + size, compareSSN);
    cout << "Sorted by SSN\n";
    cout << left << setw(4) <<"ID" << setw(10) << "Last Name" << setw(12) << "First Name" << setw(12) << "SSN" << "Grade\n";
    for (int i = 0; i < size; i++){
        cout << right << setw(2) << ptrs[i]->id << "  " 
             << left << setw(10) << ptrs[i]->lastName 
             << left << setw(12) << ptrs[i]->firstName 
             << left << setw(12) << ptrs[i]->ssn 
             << ptrs[i]->letterGrade << endl;
    }
}

/**
 * @brief Takes user input to search the lastName array
 *        Displays all info of requested student
 * 
 * @param ptrs 
 * @param size 
 */
void searchByLastName(Student * ptrs[], int size)
{
    string userInput;
    bool valid = false;
    cout << "Please enter a Last Name: ";
    while (!valid){
        getline(cin, userInput);
        for(int i = 0; i < size; i++){
            if (userInput == ptrs[i]->lastName){
                cout << "\nStudent Info\n" << "---------------\n";
                cout << "Name: " << right << setw(10) << ptrs[i]->firstName << " " << ptrs[i]->lastName << endl;
                cout << "ID: " << right << setw(18) << ptrs[i]->id << endl;
                cout << "SSN: " << right << setw(17) << ptrs[i]->ssn << endl;
                cout << "Test 1: " << right << setw(14) << ptrs[i]->test[0] << endl;
                cout << "Test 2: " << right << setw(14) << ptrs[i]->test[1] << endl;
                cout << "Test 3: " << right << setw(14) << ptrs[i]->test[2] << endl;
                cout << "Test 4: " << right << setw(14) << ptrs[i]->test[3] << endl;
                cout << "Final: " << right << setw(15) << ptrs[i]->final << endl;
                cout << "Final Letter Grade: " << ptrs[i]->letterGrade << endl;

                valid = true;
            } 
        }
        if (!valid){
            cout << "Last Name not found. Please enter valid Last Name. ";
        }
    }
}

/**
 * @brief Takes user input to search the SSN array
 *        Displays all info of requested student
 * 
 * @param ptrs 
 * @param size 
 */
void searchBySSN(Student * ptrs[], int size)
{
    string userInput;
    bool valid = false;
    cout << "Please enter a SSN: ";
    while (!valid){
        getline(cin, userInput);
        for(int i = 0; i < size; i++){
            if (userInput == ptrs[i]->ssn){
                cout << "\nStudent Info\n" << "---------------\n";
                cout << "Name: " << right << setw(10) << ptrs[i]->firstName << " " << ptrs[i]->lastName << endl;
                cout << "ID: " << right << setw(18) << ptrs[i]->id << endl;
                cout << "SSN: " << right << setw(17) << ptrs[i]->ssn << endl;
                cout << "Test 1: " << right << setw(14) << ptrs[i]->test[0] << endl;
                cout << "Test 2: " << right << setw(14) << ptrs[i]->test[1] << endl;
                cout << "Test 3: " << right << setw(14) << ptrs[i]->test[2] << endl;
                cout << "Test 4: " << right << setw(14) << ptrs[i]->test[3] << endl;
                cout << "Final: " << right << setw(15) << ptrs[i]->final << endl;
                cout << "Final Letter Grade: " << ptrs[i]->letterGrade << endl;

                valid = true;
            } 
        }
        if (!valid){
            cout << "SSN not found. Please enter valid SSN. ";
        }
    }
}