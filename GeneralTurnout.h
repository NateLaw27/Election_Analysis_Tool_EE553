/*
    Author: Nathan, Prabal
    Date: 10th Dec, 2024
    Description: This file contains functions declarations for GenerealTurnout class, which 
    stores Country level based Election turnout data and functions.
*/

#ifndef GENERAL_TURNOUT_H
#define GENERAL_TURNOUT_H

#include "ElectionData.h"
#include <fstream>
#include <sstream>

class GeneralTurnout : public ElectionData {
public:
    GeneralTurnout(string file, string type);
    void loadData();
    void displayData();
    void visualizeData();
};

#endif