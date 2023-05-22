/**
 * @author Putu Mas Diani Chandra
 */

//declaration to access the header file
#include "CTIS.h"

//iostream library to enable input output activity
#include <iostream>
using namespace std;

//library to get time and date in real time
#include <ctime>
#include <cstdlib>

//declaration of CTIS constructor
CTIS::CTIS(){};

//declaration of CTIS destructor
CTIS::~CTIS() {};


//here goes the setter of the stored vector to push back elements into the vector

//adds patient objects into the vector of Patient
void CTIS::setListOfPatient(Patient inputPatient) {
    listOfPatient.push_back(inputPatient);
}

//adds centre officer objects into the vector of Centre Officer
void CTIS::setListOfCentreOfficer(CentreOfficer inputCentreOfficer) {
    listOfCentreOfficer.push_back(inputCentreOfficer);
}

//adds test centre objects into the vector of Test Centre
void CTIS::setListOfCentre(TestCentre inputCentre) {
    listOfCentre.push_back(inputCentre);
}

//here goes the getter of the stored vector to get the vector

//get vector of Patient
vector<Patient> CTIS::getPatientList() {
    return listOfPatient;
}

//get vector of Centre Officer
vector<CentreOfficer> CTIS::getListOfCentreOfficer() {
    return listOfCentreOfficer;
}

//get vector of Patient
vector<TestCentre> CTIS::getListOfCentre() {
    return listOfCentre;
}

//a method header declaration of pointer to get the address of the centre officer
// account in the vector based on the username and password
CentreOfficer* CTIS :: getOfficerAddress(string usernameInput, string passInput)
{
    //looping through the vector of centre officer
    for(int a = 0; a < listOfCentreOfficer.size(); a++) {
        //condition if the object of index a in the vector has the same username and password
        //as the username and password inputted in parameter
        if (usernameInput == listOfCentreOfficer[a].getUsername()
            && passInput == listOfCentreOfficer[a].getPassword())
            //return the address of the object of index a in the centre officer vector
            return &listOfCentreOfficer[a];
    }
    //returning NULL if it doesn't meet the condition
    return NULL;
}

//a method header declaration of pointer to get the address of the patient
// account in the vector based on the username
Patient* CTIS::getPatientListAddress(string uname) {
    //looping through the vector of patient
    for(int a = 0; a < listOfPatient.size(); a++){
        //condition if the object of index a in the vector has the same username
        //as the username inputted in parameter
        if(uname == listOfPatient[a].getUsername()){
            //return the address of the object of index a in the patient vector
            return &listOfPatient[a];
        }
    }
    //returning NULL if it doesn't meet the condition
    return NULL;
};

//a method header declaration to check whether the
//inputted username of centre officer is unique or not
bool CTIS::checkUsernameOfficer(string inputUsername) {
    //looping through the vector of Centre Officer
    for (int a = 0; a < listOfCentreOfficer.size(); a++){
        //condition if the object of index a in the vector has the same username
        //as the username inputted in parameter
        if (inputUsername == listOfCentreOfficer[a].getUsername()) {
            //returning boolean true that agree if the username is taken
            return true;
        }
    }
    //returning boolean false is the username is available
    return false;
}

//a method header declaration to check whether the
//inputted username of patient is unique or not
bool CTIS::checkUsernamePatient(string inputUsername) {
    //looping through the vector of Patient
    for (int a = 0; a < listOfPatient.size(); a++){
        //condition if the object of index a in the vector has the same username
        //as the username inputted in parameter
        if (inputUsername == listOfPatient[a].getUsername()) {
            //returning boolean true that agree if the username is taken
            return true;
        }
    }
    //returning boolean false is the username is available
    return false;
}

//a method header declaration to generate random
// number for ID of the test centre
int CTIS::randomCentreID() {
    srand((unsigned) time(0));
    int centreIDRandom;
    for (int a = 0; a < 1; a++) {
        centreIDRandom = (rand() % 50) + 1;
    }
    return centreIDRandom;
}

//a method header declaration to generate random
// number for ID of the test kit
int CTIS::randomKitID() {
    srand((unsigned) time(0));
    int kitIDRandom;
    for (int a = 0; a < 1; a++) {
        kitIDRandom = (rand() % 50) + 1;
    }
    return kitIDRandom;
}

///a method header declaration to generate random
// number for ID of the covid test
int CTIS::randomTestID() {
    srand((unsigned) time(0));
    int covidTestIDRandom;
    for (int a = 0; a < 1; a++) {
        covidTestIDRandom = (rand() % 50) + 1;
    }
    return covidTestIDRandom;
}

//a method header declaration to validate
//the login process of the manager account
bool CTIS::checkManagerLogin(string inputUsername, string inputPassword) {
    //looping through vector of centre officer
    for(int a = 0; a < listOfCentreOfficer.size(); a++){
        //condition where the object of index a's position is Manager
        if(getListOfCentreOfficer()[a].getPosition() == "Manager") {
            //condition if the object of index a in the vector has the same username and password
            //as the username and password inputted in parameter
            if (getListOfCentreOfficer()[a].getUsername() == inputUsername &&
                getListOfCentreOfficer()[a].getPassword() == inputPassword)
                //returning boolean true to prove that the account is found
                return true;
        }
    }
    //returning boolean false to prove that the account is not found
    return false;
}

//a method header declaration to validate
//the login process of the tester account
bool CTIS::checkTesterLogin(string inputUsername, string inputPassword) {
    //looping through vector of centre officer
    for(int a = 0; a < listOfCentreOfficer.size(); a++) {
        //condition where the object of index a's position is Tester
        if (getListOfCentreOfficer()[a].getPosition() == "Tester") {
            //condition if the object of index a in the vector has the same username and password
            //as the username and password inputted in parameter
            if (getListOfCentreOfficer()[a].getUsername() == inputUsername &&
                getListOfCentreOfficer()[a].getPassword() == inputPassword)
                //returning boolean true to prove that the account is found
                return true;
        }
    }
    //returning boolean false to prove that the account is not found
    return false;
}

//a method header declaration to validate
//the login process of the patient account
bool CTIS::checkPatientLogin(string inputUsername, string inputPassword) {
    //looping through vector of patient
    for(int a = 0; a < listOfPatient.size(); a++) {
        //condition if the object of index a in the vector has the same username and password
        //as the username and password inputted in parameter
        if (getPatientList()[a].getUsername() == inputUsername &&
            getPatientList()[a].getPassword() == inputPassword)
            //returning boolean true to prove that the account is found
            return true;
    }
    //returning boolean false to prove that the account is not found
    return false;
}




