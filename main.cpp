/*
    Author: Nathan, Prabal
    Date: 9th Dec, 2024
    Description: This file is the main file for election analysis project
*/

#include "AgeTurnout.h"
#include "GeneralTurnout.h"
#include "EducationTurnout.h"
#include <fstream>



int main(){
    
    ElectionData* dataset = nullptr;
    
    while(true){
        int choice;

        // Main menu
        cout<<"\nCountry Wide Election Turnout Analysis System"<<endl;
        cout<<"1. Age-Based Turnout Analysis"<<endl;
        cout<<"2. Midterm Election Turnout Analysis"<<endl;
        cout<<"3. Presidential Election Turnout Analysis"<<endl;
        cout<<"4. Education-based Turnout Analysis"<<endl;
        cout<<"5. Print out current 2024 US presidential election results report"<<endl;
        cout<< "0. Exit"<<endl;
        cout<< "Enter your choice: ";
        
        cin>>choice;
        
        if (choice==0){
            break;
        }
        
        switch(choice) {
            
            case 1:{
                string file = "Age_turnout.csv";
                dataset = new AgeTurnout(file);
                break;
            }
            
            case 2:{
                string file = "midterm_turnout_historical.txt";
                string type = "Midterm Election Turnout";
                dataset = new GeneralTurnout(file, type);
                break;
            }
            
            case 3:{
                string file = "Presidential_turnout_historical.txt";
                string type = "Presidential Election Turnout";
                dataset = new GeneralTurnout(file, type);
                break;
            }
            
            case 4:{
                string file = "Education_turnout.csv";
                dataset = new EducationTurnout(file);
                break;
            }

            case 5:{
                ifstream file("Election_results.txt");
                
                if (!file.is_open()) {
                    cout << "Error: Could not open file" << endl;
                    break;
                }
                
                string line;
                
                cout<<"\n----------------------------------------------------------------------------------------\n\n";
                while (getline(file, line)) {
                    cout << line << endl;
                }
                
                file.close();
                continue;
            }

            default:
                cout << "Invalid choice!\n";
                continue;
        }
        
        // Load selected dataset
        dataset->loadData();
        
        // Analysis Menu
        while (true) {
            
            int analysisChoice;
            
            cout<< "\nAnalysis Options:"<<endl;
            cout<< "1. Display Raw Data"<<endl;
            cout<< "2. Show Statistics"<<endl;
            cout<< "3. Visualize Data"<<endl;
            cout<< "0. Back to Main Menu"<<endl;
            cout<< "Enter choice: ";
            
            cin>>analysisChoice;
            
            if (analysisChoice == 0) break;
            
            switch(analysisChoice) {
                case 1:{
                    dataset->displayData();
                    break;
                }
                case 2:{
                    dataset->displayStats();
                    break;
                }
                case 3:{
                    dataset->visualizeData();
                    break;
                }   
                default:
                    cout<<"Invalid choice!"<<endl;
                    continue;
            }
        }
    }
    
    if(dataset!=nullptr) {
        delete dataset;
    }
    
    return 0;
}