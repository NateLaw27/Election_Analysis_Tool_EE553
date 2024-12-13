/*
    Author: Nathan, Prabal
    Date: 10th Dec, 2024
    Description: This file contains functions definitions for GenerealTurnout class, which 
    stores Country level based Election turnout data and functions.
*/

#include "GeneralTurnout.h"


// @brief constructor to general turnout class
// @param file path to file
// @type Describing the type of data
GeneralTurnout::GeneralTurnout(string file, string type) : ElectionData(type, file) {}

void GeneralTurnout::loadData() {
    ifstream file(filename);
    string line;
    
    // read line by line
    while (getline(file, line)) {
        stringstream ss(line);
        string year;
        string rate;
        
        // getting year and rate
        getline(ss, year, ',');
        getline(ss, rate);
        years.push_back(stoi(year));
        rates.push_back(stod(rate));
    }
    
    file.close();
}


// @brief prints turnout data in formatted way
void GeneralTurnout::displayData() {
    cout<<"\n"<<dataType <<" Data:"<<endl;
    cout<<setw(10)<<"Year"<<setw(15)<<"Turnout(%)"<<endl;
    cout<<"-------------------------------------"<<endl;
    
    for (int i=0; i<years.size(); i++) {

        cout<<setw(10)<<years[i]<<setw(15)<<rates[i]*100<<endl;
    }
}


// @brief Creates a visualization of the turnout data using gnuplot
void GeneralTurnout::visualizeData() {
    // creating a data file for plotting
    ofstream plotData("turnout.dat");
    for (int i=0; i<years.size(); i++) {
        plotData<<years[i]<<" "<<(rates[i]*100)<<endl;
    }
    plotData.close();

    // gnuplot script
    ofstream script("turnout.plt");
    script<<"set title '"<< dataType<<"'\n"
            <<"set xlabel 'Year'\n"
            <<"set ylabel 'Turnout Rate (%)'\n"
            <<"set grid\n"
            <<"plot 'turnout.dat' with linespoints title 'Turnout'\n";
    script.close();

    system("gnuplot -persistent turnout.plt");
}