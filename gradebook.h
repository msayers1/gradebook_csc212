#pragma once
#include <string>
#include <vector>
class Gradebook
{
    private:

    // properties of a gradebook
    std::vector<double> grade;
    std::vector<double> id;
    std::vector<double> total_points;
    std::vector<double> weight;
    std::vector<std::string> name;
    std::vector<std::string> category;
    std::vector<std::string> course;
    std::vector<bool> entered;
    std::string filename;
    int assignmentCount = 0;

    void readFile(std::string filename);
    void saveFile(std::string filename);

    public:

    // default constructor????
    Gradebook();

    // parameter constructor???
    Gradebook(std::string filename);
    
    // add your method functions here, modify if necessary
    double catGrade();

    double finalGrade();

    void minGrade();
    
    void whatIfReport();

    void addGrade();

    void removeGrade();
    
    //Helper functions
    int selectionInput(int n);
    double gradeInput();
    
    //Loads a new file into memory. 
    void loadNewFile(std::string filename);
    //Saves as a new file. 
    void saveAs(std::string filename);

};
