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


// Assures that input is between an integer 1 to n
int Gradebook::selectionInput(int n){
    // Initializes a variable for input and sets a boolean to true to represent an invalid input
    int input;
    bool selection_invalid = true;
    while(selection_invalid){
        // Has user enter input
        std::cin >> input;
        // If input is invalid, loop to request new input
        if(input < 0 || input > n){
            std::cout << "Your input is invalid. Please try again: ";
        }
        // Otherwise, exit loop by setting "selection_invalid" to false
        else{
            selection_invalid = false;
        }
    }
    // Returns a valid input
    return input;
}

// Assures that input is between a double value of 0 to 100
double Gradebook::gradeInput(){
    // Initializes a variable for input and sets a boolean to true to represent an invalid input
    double input;
    bool grade_invalid = true;
    while(grade_invalid){
        // Has user enter input
        std::cin >> input;
        // If input is invalid, loop to request new input
        if(input < 0 || input > 100){
            std::cout << "Your input is invalid. Please enter a number from 1 to 100: " << std::endl;
        }
        // Otherwise, exit loop by setting "grade_invalid" to false
        else{
            grade_invalid = false;
        }
    }
    // Returns a valid input
    return input;
}




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





// add to file.cpp
 #include <iostream>
 #include <stdlib.h>
 #include <vector>
 #include <fstream>
 #include <algorithm>
 #include <sstream>
 #include <cmath>
 #include <string>



// catGrade
//     Type: Double
//     Arguments Accepted: None
//         This will calculate the average grade of a selected category.
//         It will return a double value based on current reported grades.
//           The user will be prompted to enter a number 1 to 4.
        //   1 to select assignments.
//           2 to select labs
         //  3 to select projects.
//           4 to select exams
          // 5 to select quiz.
//.        After valid user input is received, the function
//         will iterate through the vector of the selected data member, compute the average
//         grade in the category and print it for the user.


// similiar to mingrade
double Gradebook::catGrade(){

    int input = 0;
    double sum = 0;
    double avg = 0;
    std::string name;
    std::string category;

   // prints out prompt for user to pick from
    std::cout << "Press 1 to calculate average for assignments " << std::endl;
    std::cout << "Press 2 to calculate average for labs" << std::endl;
    std::cout << "Press 3 to calculate average for projects" << std::endl;
    std::cout << "Press 4 to calculate average for exams" << std::endl;
    std::cout << "Press 5 to calculate average for quiz" << std::endl;

    // If user selected , sets the "category" string to "assignment" to calculate based on student's current assignment grades
    // option 1
    if(input == 1){
        category += "assignment";
    }
    else if (input == 2){
        category += "lab";
    }
    else if (input == 3 ){
        category += "project";
    }
    else if (input == 4 ){
        category += "exam";
    }
    else{
        category += "quiz";
    }

    // goes through the gradebook
    for(int i = 0; i < gradebook.size(); i++){

        //// searches for coursework of selected category
        if(name[i] == category){
            // goes through the all the specific elements of chosen category
            for(int i = 0; i < category.size(); i++){
                // adds the sum of the specific category
                sum += category[i];
                // calculates the average of the category
                avg = sum / category;
                // prints out to the user what the average of the category is.
                std::cout << "The calculated average for this category is" << avg << std::endl;
                    }
                }
            else{
                // user must type in correct category name from gradebook or statement will appear.
                std::cout << "Not a valid category, cannot do calculations. " << std::endl;
            }
        }
    return avg;
}



// Calculates the minimum grade necessary to get a desired grade in a selected category
void Gradebook::minGrade(){
    // Prompts user to enter 1 to calculate min grade for assignments and 2 for labs
    std::cout << "\nPress 1 to choose assignments." << std::endl;
    std::cout << "Press 2 to choose labs." << std::endl;
    int input = selectionInput(2);
    // Stores the category selected in a string
    std::string selected_category;
    // If user selected 1, sets the "selected_category" string to "assignment" to calculate based on student's current assignment grades
    if(input == 1){
        selected_category += "assignment";
    }
    // If user selected 2, sets the "selected_category" string to "lab" to calculate based on student's current lab grades
    else if(input == 2){
        selected_category += "lab";
    }

    // Prompts user to enter grade they wish to get in the selected category
    std::cout << "\nEnter desired grade for selected coursework: ";
    double desired_grade = gradeInput();
    double minimum_grade;

    // Represents total points available to earn in selected category
    double max_pts = 0;
    // Represents points currently earned in selected category
    double sum_current_pts = 0;
    // Counter for the amount of coursework not yet completed in selected category
    int remaining = 0;

    // Iterates through gradebook, searching for courswork of selected category
    for(int i = 0; i < id.size(); i++){
        if(category[i] == selected_category){
            // Adds how many points the individual coursework is worth to "max_pts"
            max_pts += total_points[i];
            if(entered[i] == 1){
                // If the assignment is graded, add that grade to the sum of current points
                sum_current_pts += grade[i];
            }
            else{
                // If the assignment is not graded, increment the coursework remaining counter
                remaining++;
            }
        }
    }

    // If there is no courswork of the selected category in the gradebook, exit the function as there is nothing to calculate
    if(max_pts == 0){
        std::cout << "\nThere is no courswork of type \"" << category << "\" recorded in your gradebook." << std::endl;
        return;
    }
    // If the student completed all courswork of the selected category, exit the function as there is nothing to calculate
    if(remaining == 0){
        std::cout << "\nYour gradebook reads that there is no more coursework of that type to complete this semester. If this does not seem correct, please press 1 in the main menu to print your current corsework or press 6 to add an entry to the gradebook." << std::endl;
        return;
    }

    // Calculates the minimum grade they must receive on the rest of their coursework in that category for the rest of the semester
    minimum_grade = ((max_pts * (desired_grade/100)) - sum_current_pts) / remaining;
    std::cout << "\nFor the rest of the semester, you must get a score of " << minimum_grade << " on your courswork in this category." << std::endl;
}

// Calculate a hypothetical grade based on user-input for each category
void Gradebook::whatIfReport(){
    // Prompts user to enter hypothetical grades for each category
    std::cout << "Enter hypothetical grades for the following categories." << std::endl;
    std::cout << "Assignments: ";
    double assignment_grade = gradeInput() / 100;
    std::cout << "Labs: ";
    double lab_grade = gradeInput() / 100;
    std::cout << "Projects: ";
    double project_grade = gradeInput() / 100;
    std::cout << "Extra Credit: ";
    double extra_credit_grade = gradeInput() / 100;

    // Asks the user if they wish to include the final exam
    std::cout << "\nHave you taken the final exam in this hypothetical situation? Press 1 for yes or 2 for no." << std::endl;
    int input = selectionInput(2);

    // If they select no, the final exam grade will be recorded as 100 for the calculation
    double final_exam_grade = 100 / 100;

    // If they select yes, ask them to input their grade
    if(input == 1){
        std::cout << "Final Exam: ";
        double final_exam_grade = gradeInput() / 100;
    }

    // Calculate the final grade with the given values
    double final_grade = (((assignment_grade*500) + (lab_grade*50) + (project_grade*350) + (final_exam_grade*100) + (extra_credit_grade*30)) / 1000) * 100;

    // Prints the hypothetical grade
    std::cout << "\nHypothetical Final Grade: " << final_grade << std::endl;
    // If they did not input a final exam grade, print whether they are exempt from taking it
    if(input == 2){
        std::cout << "Exempt from Final Exam?: ";
        if(final_grade > 90){
            // If their final grade > 90, they are exempt
            std::cout << "Yes" << std::endl;
        }
        else{
            // If their final grade < 90, they are not exempt
            std::cout << "No" << std::endl;
        }
    }
}

double Gradebook::finalGrade()
{
    // variables to store grade with and without exam available
    double final_grade, no_exam;

    // this bool will check if final exam is available
    bool theresFinal = true;

    // add up the grades
    for (int i = 0; i < grade.size(); i++)
    {
        final_grade += grade[i];
    }

    // set the other vairable to the sum of all the grades
    no_exam = final_grade;

    // now we remove final grades from the total
    for (int j = 0; j < grade.size(); j++)
    {
        if (category[i] == "exam")
        {
            no_exam -= grade[i]
        }
    }

    //check if final exam is available
    for (int k = 0; k < grade.size(); k++)
    {
        if ((category[i] == "exam") && (entered[i] == 0))
        {
            theresFinal = false;
        }
    }


//print the grade depening on the presence or absence of a final exam grade
    if (theresFinal == false)
    {
        if (no_exam > 900)
        {
            std::cout << "your grade without your final exam is " << no_exam << " you are exempt from the final exam" << std::endl;
        }
        else
        {
            std::cout << "your grade without your final exam is " << no_exam << " you are not exempt from the final exam" << std::endl;
        }
    }
    else
        std::cout << "Your final grade is: " << final_grade << "." << std::endl;
}

void Gradebook::printCourseWork()
{

    // asks user to enter an input to get results.
    std::cout << "Please enter a number from 1-5" << std::endl;
    std::cout << "Enter 1 to print assignments" << std::endl;
    std::cout << "Enter 2  to print labs" << std::endl;
    std::cout << "Enter 3 to print projects" << std::endl;
    std::cout << "Enter 4 to print exams" << std::endl;
    std::cout << "Enter 5 to print all" << std::endl;

    // call to function to check if input is valid.
    int input = selectionInput(5);

    // switch statements for each input
    switch (input)
    {
    case 1:
        for (int i = 0; i < name.size(); i++)
        {
            if ((category_value[i] == "assignment") && (entered[i] == 1))
            {
                std::cout << name[i] << " = " << grade[i] << std::endl;
            }
        }
        break;
    case 2:
        for (int i = 0; i < name.size(); i++)
        {
            if ((category[i] == "lab") && (entered[i] == 1))
            {
                std::cout << name[i] << " = " << grade[i] << std::endl;
            }
        }
        break;
    case 3:
        for (int i = 0; i < name.size(); i++)
        {
            if ((category[i] == "project") && (entered[i] == 1))
            {
                std::cout << name[i] << " = " << grade[i] << std::endl;
            }
        }
        break;
    case 4:
        for (int i = 0; i < name.size(); i++)
        {
            if ((category[i] == "exam") && (entered[i] == 1))
            {
                std::cout << name[i] << " = " << grade[i] << std::endl;
            }
        }
        break;
    case 5:
        for (int i = 0; i < name.size(); i++)
        {
            std::cout << name[i] << " = " << grade[i] << std::endl;
        }
        break;

    default:
        std::cout << std::endl;
        break;
    }
}
