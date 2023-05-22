/**
 * @author Putu Mas Diani Chandra
 */

//including the header file needed
#include "Patient.h"

//iostream library to enable input output activity
#include <iostream>
using namespace std;

//default constructor of Patient with no parameter
Patient::Patient() {
    setUsername("no name");
    setPassword("no password");
    setName("no name");
    setPatientType("no type");
    setSymptoms("no symptoms");
}

//constructor of Patient with parameters
Patient::Patient(string uname, string pw, string nm, string pType, string s) {
    setUsername(uname);
    setPassword(pw);
    setName(nm);
    setPatientType(pType);
    setSymptoms(s);
}

//destructor
Patient::~Patient() {}

//getter for the Patient class attributes
string Patient::getPatientType() {return patientType;};
string Patient::getSymptoms() {return symptoms;};

//setter for the Patient class attributes
void Patient::setPatientType(string pType) {patientType = pType;};
void Patient::setSymptoms(string s) {symptoms = s;};


//method from the parent class to view the test history
string Patient::viewTestHistory(string inputUsername, string inputPassword) {
    //condition if the username and password from this class are
    //as the username and password inputted in parameter
    if(getUsername() == inputUsername && getPassword() == inputPassword){
        //looping through the vector of Covid Test
        for(int i = 0; i < listOfCovidTest.size(); i++){
            cout << "------- TESTING HISTORY REPORT -------" << endl;
            cout << "\nTesting report of patient " << getName() << "."<< endl;
            cout << "Test ID: " << getCovidTestList().at(i).getTestID() << endl;
            cout << "Test Date: " << listOfCovidTest[i].getTestDate() << endl;
            cout << "Result: " << listOfCovidTest[i].getResult() << endl;
            cout << "Result Date: " << listOfCovidTest[i].getResultDate() << endl;
            cout << "Status: " << listOfCovidTest[i].getStatus() << endl;
        }
    }
    return "";
}

//aggregation related methods

//getting the vector of Covid Test in aggregation
vector<CovidTest> Patient::getCovidTestList() {
    return listOfCovidTest;
}

//adding a new object into the vector
void Patient::createNewCovidTest(CovidTest cvTest) {
    listOfCovidTest.push_back(cvTest);
}

//getter for the CovidTest vector stored and return the address
CovidTest* Patient::getCovidTestAddress(string testID) {
    for(int i = 0; i < listOfCovidTest.size(); i++){
        if(testID == listOfCovidTest[i].getTestID()){
            return &listOfCovidTest[i];
        }
    }
    return NULL;
};