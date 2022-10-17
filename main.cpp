//main.cpp:
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <ctime>
#include "gradebook.h"

bool takeInput(int * input, Gradebook *gradebook);

int main(int argc, char* argv[]){
    Gradebook *gradebook = new Gradebook();

    int input;
    
    bool running = true;
 
    while(running == true){
        std::cout << "Press 1 to print coursework." << std::endl;
        std::cout << "Press 2 to print a category grade." << std::endl;
        std::cout << "Press 3 to print the final grade" << std::endl;
        std::cout << "Press 4 to print minimum grade needed in a category based on a desired grade." << std::endl;
        std::cout << "Press 5 to print a final grade based on inputed category grades." << std::endl;
        std::cout << "Press 6 to add an entry." << std::endl;
        std::cout << "Press 7 to add/modify a grade." << std::endl;
        std::cout << "Press 8 to remove a grade." << std::endl;
        std::cout << "Press 9 to load a file." << std::endl;
        std::cout << "Press 10 to save as a different file." << std::endl;
        std::cout << "Press 0 to quit" << std::endl;
        std::cout << "Please Make a selection:";
        std::cin >> input;
        running = takeInput(&input, gradebook);
    }
}

bool takeInput(int * input, Gradebook *gradebook){
    std::string input_filename;
    switch(*input){
        case 1:
            //Call function
            (*gradebook).printCoursework();
            break;
        case 2:
            //Call function
            (*gradebook).catGrade();
            break;
        case 3:
            //Call function
            (*gradebook).finalGrade();
            break;
        case 4:
            //Call function
            (*gradebook).minGrade();
            break;
        case 5:
            //Call function
            (*gradebook).whatIfReport();
            break;
        case 6:
            //Call function
            (*gradebook).addEntry();
            break;
        case 7:
            //Call function
            (*gradebook).addGrade();
            break;
        case 8:
            //Call function
            (*gradebook).removeGrade();
            break;
        case 9:
            std::cout << "Please enter filename:" << std::endl;
            std::cin >> input_filename;
            (*gradebook).loadNewFile(input_filename);
            break;
        case 10:
            std::cout << "Please enter filename:" << std::endl;
            std::cin >> input_filename;
            (*gradebook).saveAs(input_filename);
            break;
        case 0:
            return false;
            break;
        default:
            std::cout << "Your input is invalid, Please press 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, or 0." << std::endl;
            break;

    }
    return true;
}

