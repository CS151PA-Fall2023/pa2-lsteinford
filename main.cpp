/**
 * @file main.cpp
 * @author Luke Steinford
 * @brief 
 * @version 0.1
 * @date 2023-09-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "index.h"
using namespace std;

int main()
{
    ifstream inputFile;
    openInputFile(inputFile, "grades.csv");

    int SIZE = 20;
    Student studentGrades[SIZE];
    Student *sortLastName[SIZE];
    Student *sortSSN[SIZE];

    readFile(inputFile, studentGrades);
    point(sortLastName, studentGrades, SIZE);
    point(sortSSN, studentGrades, SIZE);

    bool cont = true;
    while(cont){
        homeScreen();

        int userInput;
        do{
            cout << "Select a menu: ";
            cin >> userInput;
            cout << endl;
        }while(userInput < 1 || userInput > 5);

        cin.ignore();

        switch(userInput){
            case 1:
                    indexByLastName(sortLastName,SIZE);
                    cout << endl << "Press Enter to continue...";
                    cin.ignore();
                    break;
            case 2:
                    indexBySSN(sortSSN,SIZE);
                    cout << endl << "Press Enter to continue...";
                    cin.ignore();
                    break;
            case 3:
                    searchByLastName(sortLastName,SIZE);
                    cout << endl << "Press Enter to continue...";
                    cin.ignore();
                    break;
            case 4:
                    searchBySSN(sortSSN,SIZE);
                    cout << endl << "Press Enter to continue...";
                    cin.ignore();
                    break;
            case 5:
                    cont = false;
                    break;
            default:
                    break;
        }   

    }

    inputFile.close();
    
    return 0;
}