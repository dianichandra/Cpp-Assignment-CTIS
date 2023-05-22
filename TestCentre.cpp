/**
 * @author Putu Mas Diani Chandra
 */

//including the header file
#include "TestCentre.h"

//iostream library to enable input output activity
#include <iostream>
using namespace std;

//default constructor header declaration of TestCentre with no parameter
TestCentre::TestCentre() {
    setCentreID("no ID");
    setCentreName("no name");
}

//constructor header declaration of TestCentre with parameters
TestCentre::TestCentre(string ctrID, string ctrName) {
    setCentreID(ctrID);
    setCentreName(ctrName);
}

//destructor
TestCentre::~TestCentre() {}

//getter for the attributes
string TestCentre::getCentreID() {return centreID;}
string TestCentre::getCentreName() {return centreName;}

//setter for the attributes
void TestCentre::setCentreID(string ctrID) {centreID = ctrID;}
void TestCentre::setCentreName(string ctrName) {centreName = ctrName;}

//getter for vector TestKit aggregated
vector<TestKit> TestCentre::getTestKitList() {
    return listOfTestKit;
}

//getter for the TestKit vector stored and return the address
TestKit* TestCentre::getTestKitAddress(string inKitID) {
    //looping through the vector of TestKit
    for(int a = 0; a < listOfTestKit.size(); a++){
        //condition where the inputted kitID match the object in the index a
        if(inKitID == listOfTestKit[a].getKitID()){
            return &listOfTestKit[a];
        }
    }
    return NULL;
};

//adding new object to the vector of TestKit
void TestCentre::createTestKit(string tName, string kID, int availStck) {
    TestKit kit1(tName, kID, availStck);
    listOfTestKit.push_back(kit1);
}

