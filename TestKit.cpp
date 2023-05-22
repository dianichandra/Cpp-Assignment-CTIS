/**
 * @author Putu Mas Diani Chandra
 */

//including the header file
#include "TestKit.h"

//iostream library to enable input output activity
#include <iostream>
using namespace std;

//default constructor of TestKit with no parameter
TestKit::TestKit() {
    setTestName("no test name");
    setKitID("no kit ID");
    setAvailableStock(0);
}

//constructor of TestKit with parameters
TestKit::TestKit(string tName, string kID, int availStck) {
    setTestName(tName);
    setKitID(kID);
    setAvailableStock(availStck);
}

//destructor
TestKit::~TestKit() {}

//getter for the User class attributes
string TestKit::getTestName() {return testName;};
string TestKit::getKitID() {return kitID;};
int TestKit::getAvailableStock() {return availableStock;};

//setter for the User class attributes
void TestKit::setTestName(string tName) {testName = tName;};
void TestKit::setKitID(string kID) {kitID = kID;};
void TestKit::setAvailableStock(int availStck) {availableStock = availStck;};

//getter for vector CovidTest aggregated
vector<CovidTest> TestKit::getCovidTestList() {
    return listOfCovidTest;
}

//adding new object to the vector of CovidTest
void TestKit::createCovidTest(CovidTest cvdTest) {
    listOfCovidTest.push_back(cvdTest);
}