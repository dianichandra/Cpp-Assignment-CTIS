/**
 * @author Putu Mas Diani Chandra
 */

//including the header file needed
#include "CentreOfficer.h"
#include "TestCentre.h"

//iostream library to enable input output activity
#include <iostream>
using namespace std;

//default constructor of Centre Officer with no parameter
CentreOfficer::CentreOfficer() {
    setUsername("no username");
    setPassword("no password");
    setName("no name");
    setPosition("no position");
}

//constructor of Centre Officer with parameters
CentreOfficer::CentreOfficer(string uname, string pw, string nm, string posi, TestCentre tc) {
    setUsername(uname);
    setPassword(pw);
    setName(nm);
    setPosition(posi);
}

//destructor
CentreOfficer::~CentreOfficer() {}

//getter for the CentreOfficer class attributes
string CentreOfficer::getPosition() {return position;}
TestCentre CentreOfficer::getTestCentreObj(){return tc1;}
//also getter but returning the address
TestCentre* CentreOfficer::getTestCentre() {return &tc1;}

//setter for the CentreOfficer class attributes
void CentreOfficer::setPosition(string posi) {position = posi;}
void CentreOfficer::setTestCentre(TestCentre tc) {tc1 = tc;}

//method from the parent class to view the test history
string CentreOfficer::viewTestHistory(string inputUsername, string inputPassword) {
    //condition if the username and password from this class are
    //as the username and password inputted in parameter
    if(getUsername() == inputUsername && getPassword() == inputPassword) {
        //looping through the vector of Covid Test
        for (int i = 0; i < listOfCovidTest.size(); i++) {
            cout << "------- TESTING HISTORY REPORT -------" << endl;
            cout << "\nRegistered at Test Centre " << tc1.getCentreName() << ". " << endl;
            cout << "Test ID: " << listOfCovidTest[i].getTestID() << endl;
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
vector<CovidTest> CentreOfficer::getCovidTestList() {
    return listOfCovidTest;
}

//adding a new object into the vector
void CentreOfficer::createCovidTest(CovidTest cvdTest) {
    listOfCovidTest.push_back(cvdTest);
}

//getter for the CovidTest vector stored and return the address
CovidTest* CentreOfficer::getCovidTestAddress(string testID) {
    for(int i = 0; i < listOfCovidTest.size(); i++){
        if(testID == listOfCovidTest[i].getTestID()){
            return &listOfCovidTest[i];
        }
    }
    return NULL;
};