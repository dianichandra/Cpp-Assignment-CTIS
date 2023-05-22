/**
 * @author Putu Mas Diani Chandra
 */

#ifndef ASSIGNMENT_1_CENTREOFFICER_H
#define ASSIGNMENT_1_CENTREOFFICER_H

//include stl library vector to be able to store a list with unknown size
#include <vector>

//declaration of header file that needed in this class
#include "User.h"
#include "TestCentre.h"
#include "CovidTest.h"

//header file for Centre Officer class

//declare that Centre Officer is the child class of User
class CentreOfficer: public User{
    //public methods of Centre Officer Class
public:
    //default constructor header declaration of CentreOfficer class with no parameter
    CentreOfficer();

    //constructor header declaration of CentreOfficer class with parameters
    CentreOfficer(string uname, string pw, string nm, string posi, TestCentre tc);

    //destructor
    ~CentreOfficer();

    //setter of the attributes
    void setPosition(string posi);
    void setTestCentre(TestCentre tc);

    //getter of the attributes
    string getPosition();
    TestCentre* getTestCentre();
    TestCentre getTestCentreObj();

    //method from the parent class
    string viewTestHistory(string inputUsername, string inputPassword) override;

    //aggregation related method
    vector<CovidTest> getCovidTestList();
    void createCovidTest(CovidTest cvdTest);
    CovidTest* getCovidTestAddress(string testID);

    //private attributes of Centre Officer Class
private:
    TestCentre tc1;
    string position;
    vector<CovidTest> listOfCovidTest;
};


#endif //ASSIGNMENT_1_CENTREOFFICER_H
