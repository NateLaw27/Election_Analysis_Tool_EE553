/*
    Author: Nathan, Prabal
    Date: 10th Dec, 2024
    Description: This file contains function definitions for the Base class ElectionData. 
*/

#include "ElectionData.h"

// @brief constructor for ElectionData class
// @param type Describing the type of data
// @param file path to file
ElectionData::ElectionData(string type, string file){
    dataType = type;
    filename = file;
}


// @brief calcualtes mean of Voter turnout rates
// @return mean of rates vector
double ElectionData::calculateAverage() {
    
    double sum = 0;

    for(int i = 0; i<rates.size(); i++) {
        sum += rates[i];
    }

    return sum / rates.size();
}


// @brief Calculates Max value of rates in voter turnout rates
// @return max value of rate in rates vector
double ElectionData::getMaxRate() {
    double max = rates[0];

    for(int i = 0; i < rates.size(); i++) {
        if(rates[i] > max) {
            max = rates[i];
        }
    }

    return max;
}

// @brief Calculates Min value of rates in voter turnout rates
// @return min value of rate in rates vector
double ElectionData::getMinRate() {
    double min = rates[0];

    for(int i = 0; i < rates.size(); i++) {
        if(rates[i] < min){
            min = rates[i];
        } 
    }

    return min;
}

// @brief Display summary of all stats
void ElectionData::displayStats() {
    cout<<"\nStats for "<<dataType<<endl;
    cout<<"average turnout: "<<calculateAverage()*100<<"%"<<endl;
    cout<<"maximum Turnout: "<<getMaxRate()*100<<"%"<<endl;
    cout<< "minimum turnout: "<<getMinRate()*100<<"%"<<endl;
}