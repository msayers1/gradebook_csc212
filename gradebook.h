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

    public:

    // default constructor????
    Gradebook();

    // parameter constructor???
    Gradebook(std::string filename);
    
    // Read and Write Functions
    void readFile(std::string filename);
    void saveFile(std::string filename);
    
    //Helper functions
    int selectionInput(int n);
    double gradeInput(double max_pts);
    
    void addEntry();

    void addGrade();
    void removeGrade();
    
    void printCoursework();

    double catGrade();
    double finalGrade();

    void minGrade();
    void whatIfReport();
    
    //Loads a new file into memory. 
    void loadNewFile(std::string filename);
    //Saves as a new file. 
    void saveAs(std::string filename);

};
