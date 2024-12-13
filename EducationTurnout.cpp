/*
    Author: Nathan, Prabal
    Date: 11th Dec, 2024
    Description: This file contains function definitions for EducationTurnout class, which 
    stores Education level based Election turnout data and functions.
*/

#include "EducationTurnout.h"



// @brief Constructor which sets up Education-based categories.
// @param file path to data file.
EducationTurnout::EducationTurnout(string file) : ElectionData("Education-Based Turnout", file) {
    
    eduGroups.push_back("College");
    eduGroups.push_back("High School");
    eduGroups.push_back("No High School");
    eduGroups.push_back("Post College");
}


// @brief function to get rate vector for given Edu group.
// @param index corresponding to Edu group.
// @return reference to vector containing turnout rates for a specific Edu group.
vector<double>& EducationTurnout::getRateVector(int index) {
    
    switch(index) {

        case 0: 
            return college;
        case 1: 
            return highSchool;
        case 2: 
            return noHighSchool;
        case 3: 
            return postCollege;
        default:
            return college;

    }
}


// @brief Calculates and displays stats for a specific Edu group
// @param groupRates vector for turnout rates for a specific Edu group.
// @param groupName identifier for the Edu group.
void EducationTurnout::calculateStatsEduGroup(vector<double>& groupRates, string groupName) {

    rates = groupRates;    
    cout<< setw(15)<< groupName<< setw(15)<< (calculateAverage()*100)<< setw(15)<< (getMaxRate()*100)<< setw(15)<< (getMinRate()*100)<<endl;

}


// @brief Loads data from the CSV file
void EducationTurnout::loadData() {
    
    ifstream file(filename);
    string line;
    getline(file, line); //skip header

    while (getline(file, line)) {

        stringstream ss(line);
        string value;

        // read year
        getline(ss, value, ',');
        years.push_back(stoi(value));

        // read turnout rates
        for(int i=0; i<4; i++) {
            getline(ss, value, ',');
            getRateVector(i).push_back(stod(value));
        }
    }

    file.close();
}


// @brief Displays data in a table format
void EducationTurnout::displayData() {

    cout<<"\nEducation-Based Turnout Data:"<<endl;
    cout<<setw(10)<<"Year";
    for(int i=0; i<eduGroups.size(); i++) {
        cout<<setw(15)<<eduGroups[i];
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;

    // print out rows and columns
    for(int i=0; i<years.size(); i++) {
        cout << setw(10) << years[i];
        for(int j=0; j<eduGroups.size(); j++) {
            cout << setw(15) << (getRateVector(j)[i]*100);
        }
        cout << endl;
    }
}


// @brief display stats summary for each age group
void EducationTurnout::displayStats() {

    cout<<"\nTurnout Statistics by Education Level"<<endl<<endl;
    cout<<setw(15)<<"Education"<<setw(15)<<"Mean (%)"<<setw(15)<<"Max (%)"<< setw(15)<<"Min (%)"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    
    for(int i=0; i<eduGroups.size(); i++) {
        calculateStatsEduGroup(getRateVector(i), eduGroups[i]);
    }
}


// @brief creates visaluization script of data and visualize it using gnuplot with system commands
void EducationTurnout::visualizeData() {
    // create data files for each edu group
    ofstream fileCollege("college.dat");
    ofstream fileHS("highschool.dat");
    ofstream fileNoHS("nohighschool.dat");
    ofstream filePostCollege("postcollege.dat");

    for(int i=0; i<years.size(); i++) {
        fileCollege<<years[i]<<" " <<(college[i]*100)<<"\n";
        fileHS<<years[i] << " " <<(highSchool[i]*100)<<"\n";
        fileNoHS<<years[i] << " " <<(noHighSchool[i]*100) <<"\n";
        filePostCollege<<years[i] <<" "<<(postCollege[i]*100)<<"\n";
    }

    fileCollege.close();
    fileHS.close();
    fileNoHS.close();
    filePostCollege.close();

    // gnuplot script
    ofstream script("education_turnout.plt");
    script << "set title 'Voter Turnout by Education Level'\n"
           << "set xlabel 'Year'\n"
           << "set ylabel 'Turnout Rate (%)'\n"
           << "set grid\n"
           << "plot 'college.dat' with linespoints title 'College', \\\n"
           << "     'highschool.dat' with linespoints title 'High School', \\\n"
           << "     'nohighschool.dat' with linespoints title 'No High School', \\\n"
           << "     'postcollege.dat' with linespoints title 'Post College'\n";

    script.close();
    system("gnuplot -persistent education_turnout.plt");
}

