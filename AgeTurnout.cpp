/*
    Author: Nathan, Prabal
    Date: 11th Dec, 2024
    Description: This file contains functions definitions for AgeTurnout class, which 
    stores Age-based Election turnout data and functions.
*/



#include "AgeTurnout.h"


// @brief Constructor which sets up ageGroup categories.
// @param file path to data file.
AgeTurnout::AgeTurnout(string file) : ElectionData("Age-Based Turnout", file) {
    
    ageGroups.push_back("60+");
    ageGroups.push_back("18-29");
    ageGroups.push_back("30-44");
    ageGroups.push_back("45-59");

}


// @brief function to get rate vector for given age group.
// @param index corresponding to age group.
// @return reference to vector containing turnout rates for a specific age group.
vector<double>& AgeTurnout::getRateVector(int index) {
    
    switch(index) {
        case 0: 
            return sixty;
        case 1: 
            return eighteen;
        case 2: 
            return thirty;
        case 3: 
            return fortyFive;
        default:
            return sixty;
    }
}


// @brief Calculates and displays stats for a specific age group
// @param groupRates vector for turnout rates for a specific age group.
// @param groupName identifier for the age group.
void AgeTurnout::calculateStatsAgeGroup(vector<double>& groupRates, string groupName) {
    
    rates = groupRates;
    cout<<setw(15)<<groupName<< setw(15)<<(calculateAverage()*100)<<setw(15)<<(getMaxRate()*100)<<setw(15)<<(getMinRate()*100)<<endl;
    
}


// @brief Loads data from the CSV file
void AgeTurnout::loadData() {
    
    ifstream file(filename);
    string line;
    getline(file, line); //skip header 

    while (getline(file, line)){
        stringstream ss(line);
        string value;

        // read year
        getline(ss, value, ',');
        years.push_back(stoi(value));

        // read Turnout Rates
        for(int i=0; i<4; i++) {

            getline(ss, value, ',');
            getRateVector(i).push_back(stod(value));

        }
    }

    file.close();
}

// @brief Displays data in a table format
void AgeTurnout::displayData() {

    cout<<"\nAge-Based Turnout Data:"<<endl;
    cout<< setw(10)<< "Year";
    for(int i=0; i<ageGroups.size(); i++) {
        cout << setw(15)<< ageGroups[i];
    }
    cout<<endl;
    cout<<"-------------------------------------------------------------------"<< endl;

    // print out rows and columns
    for(int i=0; i<years.size(); i++) {
        cout<<setw(10) << years[i];
        for(int j = 0; j < ageGroups.size(); j++) {
            cout << setw(15)<< (getRateVector(j)[i]*100);
        }
        cout<<endl;
    }
}


// @brief display stats summary for each age group
void AgeTurnout::displayStats() {

    cout<<"\nTurnout Statistics by Age Group"<<endl<<endl;
    cout<< setw(15)<< "Age Group"<< setw(15)<< "Mean (%)"<< setw(15)<< "Max (%)"<< setw(15)<< "Min (%)"<< endl;
    cout<<"-------------------------------------------------------------------"<< endl;
    
    for(int i=0; i<ageGroups.size(); i++) {
        calculateStatsAgeGroup(getRateVector(i), ageGroups[i]);
    }

}


