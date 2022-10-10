#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "gradebook.h"
 // properties of a gradebook
    // double grade;
    // double id;
    // double total_points;
    // double weight;
    // std::string name;
    // std::string category;
    // std::string course;
    // bool entered;
    // default constructor????
    Gradebook::Gradebook(){
        filename = "blank.txt";
        readFile(filename);
        //saveFile(filename);
    };

    // parameter constructor???
    Gradebook::Gradebook(std::string inputFilename):filename(inputFilename){
        readFile(filename);
        //saveFile(filename);
    };
    

void Gradebook::readFile(std::string filename){
    // Opens the file for reading
    std::ifstream file(filename);
    // Creates a string to hold each line in temporarily
    std::string str;
    //initializes the double variables. 
    double id_value, grade_value, total_points_value, weight_value;
    //initializes the string variables. 
    std::string name_value, category_value, course_value;
    //initializes the boolean variable. 
    bool entered_value;
    // initialize counter for assignments
    int counter = 0;
    id.clear();
    name.clear();
    grade.clear();
    total_points.clear();
    category.clear();
    weight.clear();
    course.clear();
    entered.clear();    
    // Iterates over the file, storing one line at a time into `str`
    while (getline(file, str)) {
        // Create a stringstream object with our line of integers from the file
        std::istringstream ss(str); 
        //Grabs the values from the line. 
        ss >> id_value >> name_value >> grade_value >> total_points_value >> category_value >> weight_value >> course_value >> entered_value;
        //Places the values in the correct variables.
        id.push_back(id_value);
        name.push_back(name_value);
        grade.push_back(grade_value);
        total_points.push_back(total_points_value);
        category.push_back(category_value);
        weight.push_back(weight_value);
        course.push_back(course_value);
        entered.push_back(entered_value);
        //increments the counter. 
        counter++;
        //test output, will replace with assignment to the class gradebook array. 
        //std::cout << id_value << " " << name_value << " " <<  grade_value << " " <<  total_points_value << " " <<  category_value << " " <<  weight_value << " " <<  course_value << " " <<  entered_value << std::endl;
    }
    //sets the overall assignment count. 
    assignmentCount = counter;
};



void Gradebook::saveFile(std::string filename){
    // Open our file with write permissions
    std::ofstream output_file(filename);
    //placeholder for the length property from class. 
    int length = assignmentCount;
    // Use an i to traverse the assignments
    for(int i = 0; i < length; i++){
        //writes each line of the file. 
        output_file << std::to_string(id[i]) << " " << name[i] << " " << std::to_string(grade[i]) << " " <<  std::to_string(total_points[i]) << " " <<  category[i] << " " <<  std::to_string(weight[i]) << " " <<  course[i] << " " <<  std::to_string(entered[i]) << "\n";
        //Left for troubleshooting
        //std::cout << name[i] << std::endl;
        //std::cout << id[i] << " " << name[i] << " " <<  grade[i] << " " <<  total_points[i] << " " <<  category[i] << " " <<  weight[i] << " " <<  course[i] << " " <<  entered[i] << std::endl;
        
    }
};


void Gradebook::addGrade(){
    //Initilize the variables needed. 
    int input;
    double grade_input; 
    bool entering = true;
    //Start a loop to ensure we have a good grade. 
    while(entering == true){
        //Asks for the input to choose assignment. 
        std::cout << "Please choose the entry to add selection:" << std::endl;
        //Takes assignment input and places it in input variable
        std::cin >> input;
        //Decrements input 1 to change it to index. 
        input--;
        //Asks for the grade. 
        std::cout << "Please enter the grade for " << name[input] << std::endl;
        //Takes grade input and places it in a grade input variable.
        std::cin >> grade_input;
        //checks to ensure the grade is less than the total points. 
        if(grade_input > total_points[input]){
            //Tells them to try again if the value is too high. 
            std::cout << "Please enter a number less than " << total_points[input] << " points" << std::endl;
        }
        else{
            //Enters the grade,  
            grade[input] = grade_input;
            //makes sure the entered flag is set,
            entered[input] = 1;
            //Saving the file. 
            saveFile(filename);
            //and exits with setting the entering to false. 
            entering = false;
        }
    }

}

void Gradebook::removeGrade(){
    int input;
    std::string validation; 
    std::cout << "Please choose the entry to clear:" << std::endl;
    std::cin >> input;
    //Decrements input 1 to change to index. 
    input--;
    std::cout << "Please confirm you want to clear " << name[input] << " with a 'y' or 'yes'" << std::endl;
    std::cin >> validation;
    if(validation == "y" || validation == "yes"){
        grade[input] = 0;
        entered[input] = 0;
        //Saving the file. 
        saveFile(filename);
    }
    else{
        std::cout << "You are not clearing the grade, returning to main menu." << std::endl;
    }

}


void Gradebook::loadNewFile(std::string input_filename){
    filename = input_filename;
    readFile(filename);
}


void Gradebook::saveAs(std::string input_filename){
    filename = input_filename;
    saveFile(filename);
}
