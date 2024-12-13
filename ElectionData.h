/*
    Author: Nathan, Prabal
    Date: 10th Dec, 2024
    Description: This file contains function declarations for the Base class ElectionData. 
*/


#ifndef ELECTION_DATA_H
#define ELECTION_DATA_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class ElectionData {
    
protected:
    vector<int> years;
    vector<double> rates;
    string dataType;
    string filename;

public:
    ElectionData(string type, string file);

    virtual void loadData() = 0;
    virtual void displayData() = 0;
    virtual void visualizeData() = 0;
    
    virtual void displayStats();
    
    double calculateAverage();
    double getMaxRate();
    double getMinRate();

    virtual ~ElectionData(){}
};

#endif