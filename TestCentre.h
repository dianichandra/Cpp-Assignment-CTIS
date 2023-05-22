/**
 * @author Putu Mas Diani Chandra
 */

//include stl library vector to be able to store a list with unknown size
#include <vector>
#include <string>

//declaration of header file that needed in this class (aggregation)
#include "TestKit.h"
using namespace std;

#ifndef ASSIGNMENT_1_TESTCENTRE_H
#define ASSIGNMENT_1_TESTCENTRE_H

//class TestCentre header
class TestCentre {
    //public methods of TestCentre Class
public:
    //default constructor header declaration of TestCentre with no parameter
    TestCentre();

    //constructor header declaration of TestCentre
    TestCentre(string ctrID, string ctrName);

    //destructor
    ~TestCentre();

    //setter for the attributes
    void setCentreID(string ctrID);
    void setCentreName(string ctrName);

    //getter for the attributes
    string getCentreID();
    string getCentreName();

    //getter for the aggregation vector
    vector<TestKit> getTestKitList();

    //setter for the aggregation vector
    void createTestKit(string tName, string kID, int availStck);

    //a pointer to get address of a test kit object
    TestKit * getTestKitAddress(string inKitID);

    //private attributes of TestCentre Class
private:
    string centreID;
    string centreName;
    vector<TestKit> listOfTestKit;
};

#endif //ASSIGNMENT_1_TESTCENTRE_H
