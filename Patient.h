/**
 * @author Putu Mas Diani Chandra
 */

#ifndef ASSIGNMENT_1_PATIENT_H
#define ASSIGNMENT_1_PATIENT_H

//include stl library vector to be able to store a list with unknown size
#include <vector>

//declaration of header file that needed in this class
#include "User.h"
#include "CovidTest.h"

//header file for Patient class

//declare that Patient is the child class of User
class Patient: public User{
    //public methods of Patient class
public:
    //default constructor header declaration of Patient class with no parameter
    Patient();

    //constructor header declaration of Patient class with parameters
    Patient(string uname, string pw, string nm, string pType, string s);

    //destructor
    ~Patient();

    //setter of the attributes
    void setPatientType(string pType);
    void setSymptoms(string s);

    //getter of the attributes
    string getPatientType();
    string getSymptoms();

    //method from the parent class
    string viewTestHistory(string inputUsername, string inputPassword) override;

    //aggregation related method
    vector<CovidTest> getCovidTestList();
    void createNewCovidTest(CovidTest cvTest);
    CovidTest* getCovidTestAddress(string testID);

private:
    //private attributes of Patient class
    string patientType;
    string symptoms;
    vector<CovidTest> listOfCovidTest;
};

#endif //ASSIGNMENT_1_PATIENT_H
