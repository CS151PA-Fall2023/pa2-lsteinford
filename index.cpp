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
    cout << "2. Print data in ascending order by first name\n";
    cout << "3. Print data in ascending order by SSN\n";
    cout << "4. Search by last name\n";
    cout << "5. Search by SSN\n";
    cout << "6. Exit\n" << endl;
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
 * @brief Sorts the lastName pointer array
 * 
 * @param ptrs 
 * @param size 
 */
void indexByLastName(Student * ptrs[], int size)
{
    for(int i = 0; i < size - 1; i++){
        for(int j =0; j < size - i - 1; j++){
            if(strcasecmp(ptrs[j]->lastName.c_str(), ptrs[j+1]->lastName.c_str()) > 0){
                Student* temp = ptrs[j];
                ptrs[j] = ptrs[j+1];
                ptrs[j+1] = temp;
            }
        }
    }
}

/**
 * @brief Sorts the firstName pointer array
 * 
 * @param ptrs 
 * @param size 
 */
void indexByFirstName(Student * ptrs[], int size)
{
    for(int i = 0; i < size - 1; i++){
        for(int j =0; j < size - i - 1; j++){
            if(strcasecmp(ptrs[j]->firstName.c_str(), ptrs[j+1]->firstName.c_str()) > 0){
                Student* temp = ptrs[j];
                ptrs[j] = ptrs[j+1];
                ptrs[j+1] = temp;
            }
        }
    }
}

/**
 * @brief Sorts the SSN pointer array
 * 
 * @param ptrs 
 * @param size 
 */
void indexBySSN(Student * ptrs[], int size)
{
    for(int i = 0; i < size - 1; i++){
        for(int j =0; j < size - i - 1; j++){
            if(strcasecmp(ptrs[j]->ssn.c_str(), ptrs[j+1]->ssn.c_str()) > 0){
                Student* temp = ptrs[j];
                ptrs[j] = ptrs[j+1];
                ptrs[j+1] = temp;
            }
        }
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
                displayStudentInfo(ptrs, i);
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
                displayStudentInfo(ptrs, i);
                valid = true;
            } 
        }
        if (!valid){
            cout << "SSN not found. Please enter valid SSN. ";
        }
    }
}

/**
 * @brief Displays all students info with ssn, id, and letterGrade
 * 
 * @param ptrs 
 * @param size 
 */
void displayAllInfo(Student * ptrs[], int size)
{

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
 * @brief Displays all information available for single student
 * 
 * @param ptrs 
 * @param i 
 */
void displayStudentInfo(Student * ptrs[], int i)
{
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
}