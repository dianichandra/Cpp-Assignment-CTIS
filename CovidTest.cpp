/**
 * @author Putu Mas Diani Chandra
 */

//including the header file
#include "CovidTest.h"
using namespace std;

//default constructor of CovidTest with no parameter
CovidTest::CovidTest() {
    setTestID("no test ID");
    setTestDate("no test date");
    setResult("no result");
    setResultDate("no result date");
    setStatus("no status");
}

//constructor of CovidTest with parameters
CovidTest::CovidTest(string tID, string tDate, string rslt, string rsltDate, string sts) {
    setTestID(tID);
    setTestDate(tDate);
    setResult(rslt);
    setResultDate(rsltDate);
    setStatus(sts);
}

//destructor
CovidTest::~CovidTest() {}

//getter for the User class attributes
string CovidTest::getTestID() {return testID;}
string CovidTest::getTestDate() {return testDate;}
string CovidTest::getResult() {return result;}
string CovidTest::getResultDate() {return resultDate;}
string CovidTest::getStatus() {return status;}

//setter for the User class attributes
void CovidTest::setTestID(string tID) {testID = tID;}
void CovidTest::setTestDate(string tDate) {testDate = tDate;}
void CovidTest::setResult(string rslt) {result = rslt;}
void CovidTest::setResultDate(string rsltDate) {resultDate = rsltDate;}
void CovidTest::setStatus(string sts) {status = sts;}