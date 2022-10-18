# gradebook_csc212

**group memebr names:**
Michael Sayers msayers1, Vanessa Melgar vmelgar9272, Linda Tran lindaqtran, Shina Adewumi fa-adewumi

**a brief summary of the project and github repo address (with allowed access for viewing) for member contributions (most easily shown through commits in the repo where your project lives)**

**This purpose of the project is to keep track of individual grades to understand where the students stand in regards to CSC 212 data structures course. The project helps build an algorithm to analyze the grades into a final grade. There will be a series of functions that will help build the algorithm for the calculations provided which is under the description section of the README.md.** 

**proof of planning: pseudocode (and or flowcharts showing program logic if desired)**
The original commit of the readme file and the pseudocode file were proof of planning. 

**describe features of the algorithm**
The algorithm is a full application which can load the grade file, save the grade file. When the grade file is loaded, it can print out all grades or just a category. It can print the final grade or average of the categories. It can give you the minimum grade you need in a category. And run through what if situations. It can add an assignment that is added to the course. It can add or modify the grades, or clear the grade if entered incorrectly. 

**'what input can it take in'**
The input is the file, must be formated correctly like the blank.txt is formatted.

**'what is/are the output(s) you can receive back?'**
The outputs are the grades and other information in the file.

**Description of each function**

    printCoursework
        Type: Void
        Arguments Accepted: None
            This function prints assignments, labs, projects and exams along with each grade
            as requested. The user will be prompted to enter a number 1 to 5. 1 to print all 
            assignments. 2 to print all labs. 3 to print all projects. 4 to print all exams. 
            5 to print all coursework. After valid user input is received, the function will 
            iterate through the vector of the selected data member and print the coursework 
            and grades in the form of a list.

    catGrade
        Type: Double
        Arguments Accepted: None
            This will calculate the average grade of a selected category. It will return a 
            double value based on current reported grades. The user will be prompted to 
            enter a number 1 to 4. 1 to select assignments. 2 to select labs. 3 to select 
            projects. 4 to select exams. After valid user input is received, the function 
            will iterate through the vector of the selected data member, compute the average 
            grade in the category and print it for the user.

    finalGrade
        Type: Double
        Arguments Accepted: None
            This will calculate the current grade of the student. It will return a double 
            value representing the final grade based on all 4 categories. Out of 1000 
            possible points awarded in the course, labs make up 50 points, programming 
            assignments make up 500 points, the term project makes up 350 points, and the 
            final exam makes up 100 points. The review project will be added on as an 
            additional 30 points of extra credit. If this function is called and there is 
            currently no final exam grade in the database, this function will also output 
            whether the student is exempt from the exam by checking if the student's 
            weighted grade is above a 90.

    minGrade
        Type: Void
        Arguments Accepted: None
            This function calculates the minimum grade necessary to get a desired grade in a 
            category. The user will be prompted to enter a number 1 or 2. 1 to select 
            assignments. 2 to select labs. The user will then be prompted to enter their 
            desired grade in the category. The function will then calculate what the lowest 
            grade the student may receive on the rest of the coursework of that category in 
            order to reach the entered desired grade.

    whatIfReport
        Type: Void
        Arguments Accepted: None
           This function will calculate a hypothetical grade based on user-input for each 
           category. The user will be prompted to enter a double from 1 to 100 for each of 
           the following categories: assignments, labs, projects and extra credit. Entering 
           an exam grade will be optional. After valid user input is received for each       
           category, this function will calculate a hypothetical final grade and print it.

    addEntry
        Type: Void
        Arguments Accepted: None
            addEntry allows the user to add coursework not currently in the database to 
            their gradebook. The user will be prompted to enter a number 1 to 4. 1 to select 
            assignments. 2 to select labs. 3 to select projects. 4 to select exams. After 
            receiving valid input, the user will be prompted to enter a double value from 0 
            to 100 to represent the grade. This entered grade will be appended to the 
            appropriate data member.

    addGrade
        Type: Void
        Arguments Accepted: None
            addGrade asks the user for the assignment which the grade would like to be entered
            for. Takes a grade input, provides simple input validationm. Then modifies the 
            grade field and sets the entered field. 

    removeGrade
        Type: Void
        Arguments Accepted: None
            removeGrade asks the user for the assignment which the grade would like to be removed. 
            Verifies they want to remove the grade. Then sets the grade field to 0 and clears the 
            entered field. 


**'why was development like this important to your group?'**
This development was important because it was a learning experience for all involved.

**clear, conscientious comments embedded within the your code**

**provide detailed instructions how to compile your algorithm, including:
how to input data**
You enter data by having a file ready or using the application. 

**how to compile each/any option from your feature set**
g++ -g -std=c++11 main.cpp gradebook.cpp -o output && ./output 
or use your own compiler making sure you include main.cpp and gradebook.cpp, and choose your own function. 
