/**
 * @author Putu Mas Diani Chandra
 */

//include stl library vector to be able to store a list with unknown size
#include <vector>
#include <string>

//declaration of header file that needed in this class (aggregation)
#include "CovidTest.h"
using namespace std;

#ifndef ASSIGNMENT_1_TESTKIT_H
#define ASSIGNMENT_1_TESTKIT_H

//class TestKit header
class TestKit {
    //public methods of TestKit Class
public:
    //default constructor header declaration of TestKit with no parameter
    TestKit();

    //constructor header declaration of TestKit
    TestKit(string tName, string kID, int availStck);

    //destructor
    ~TestKit();

    //setter for the attributes
    void setTestName(string tName);
    void setKitID(string kID);
    void setAvailableStock(int availStck);

    //getter for the attributes
    string getTestName();
    string getKitID();
    int getAvailableStock();

    //getter for the aggregation vector
    vector<CovidTest> getCovidTestList();

    //setter for the aggregation vector
    void createCovidTest(CovidTest cvdTest);

    //private attributes of TestKit Class
private:
    string testName;
    string kitID;
    int availableStock;

    //vector to store CovidTest based on aggregation
    vector<CovidTest> listOfCovidTest;
};


#endif //ASSIGNMENT_1_TESTKIT_H
