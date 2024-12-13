/*
    Author: Nathan, Prabal
    Date: 11th Dec, 2024
    Description: This header file contains function declarations for AgeTurnout class which 
    stores Age-based Election turnout data and functions.
*/


#ifndef AGE_TURNOUT_H
#define AGE_TURNOUT_H

#include "ElectionData.h"
#include <fstream>
#include <sstream>

class AgeTurnout : public ElectionData {
private:
    vector<double> sixty;
    vector<double> eighteen;
    vector<double> thirty;
    vector<double> fortyFive;
    vector<string> ageGroups;

    vector<double>& getRateVector(int index);
    void calculateStatsAgeGroup(vector<double>& groupRates, string groupName);

public:
    AgeTurnout(string file);
    void loadData();
    void displayData();
    void visualizeData();
    void displayStats();
};

#endif