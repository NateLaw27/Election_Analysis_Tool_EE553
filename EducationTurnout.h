/*
    Author: Nathan, Prabal
    Date: 11th Dec, 2024
    Description: This file contains function decalarations for EducationTurnout class, which 
    stores Education level based Election turnout data and functions.
*/


#ifndef EDUCATION_TURNOUT_H
#define EDUCATION_TURNOUT_H

#include "ElectionData.h"
#include <fstream>
#include <sstream>


class EducationTurnout : public ElectionData{
private:
    vector<double> college;
    vector<double> highSchool;
    vector<double> noHighSchool;
    vector<double> postCollege;
    vector<string> eduGroups;

    vector<double>& getRateVector(int index);
    void calculateStatsEduGroup(vector<double>& groupRates, string groupName);

public:
    
    EducationTurnout(string file);
    void loadData();
    void displayData();
    void displayStats();
    void visualizeData();

};


#endif