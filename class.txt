#pragma once

class Gradebook
{
    private:

    // properties of a gradebook
    double grade;
    double id;
    double total_points;
    double weight;
    std::string name;
    std::string category;
    std::string course;
    bool entered;


    public:

    // default constructor????
    // parameter constructor???

    // add your method functions here, modify if necessary
    double catGrade();

    double finalGrade();

    double minGrade();

    double WhatIfReport();

    void addEntry();

    void ModifyEntry();

    void saveFile(std::string filename);

};
