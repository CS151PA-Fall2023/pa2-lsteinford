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
        Student *sortFirstName[SIZE];
        Student *sortSSN[SIZE];

        readFile(inputFile, studentGrades);
        point(sortLastName, studentGrades, SIZE);
        point(sortSSN, studentGrades, SIZE);
        point(sortFirstName, studentGrades, SIZE);

        indexByLastName(sortLastName,SIZE);
        indexByFirstName(sortFirstName,SIZE);
        indexBySSN(sortSSN,SIZE);

        bool cont = true;
        while(cont){
        homeScreen();

        int userInput;
        do{
                cout << "Select a menu: ";
                cin >> userInput;
                cout << endl;
        }while(userInput < 1 || userInput > 6);

        cin.ignore();

        switch(userInput){
                case 1:
                        cout << "Sorted by Last Name\n";
                        displayAllInfo(sortLastName, SIZE);
                        cout << endl << "Press Enter to continue...";
                        cin.ignore();
                        break;
                case 2:
                        
                        cout << "Sorted by First Name\n";
                        displayAllInfo(sortFirstName, SIZE);
                        cout << endl << "Press Enter to continue...";
                        cin.ignore();
                        break;
                case 3:
                        
                        cout << "Sorted by SSN\n";
                        displayAllInfo(sortSSN, SIZE);
                        cout << endl << "Press Enter to continue...";
                        cin.ignore();
                        break;
                case 4:
                        searchByLastName(sortLastName,SIZE);
                        cout << endl << "Press Enter to continue...";
                        cin.ignore();
                        break;
                case 5:
                        searchBySSN(sortSSN,SIZE);
                        cout << endl << "Press Enter to continue...";
                        cin.ignore();
                        break;
                case 6:
                        cont = false;
                        break;
                default:
                        break;
        }   

        }

        inputFile.close();

        return 0;
}