/**
 * @author Putu Mas Diani Chandra
 */


#ifndef ASSIGNMENT_1_CTIS_H
#define ASSIGNMENT_1_CTIS_H

//include stl library vector to be able to store a list with unknown size
#include <vector>

//declaration of header file that needed in this class
#include "Patient.h"
#include "CentreOfficer.h"

//header file for CTIS class
class CTIS {
    //private attribute of CTIS Class
private:
    //vector declaration of some classes that have a relationship with CTIS Class
    vector<TestCentre> listOfCentre;
    vector<Patient> listOfPatient;
    vector<CentreOfficer> listOfCentreOfficer;

    //public methods of CTIS Class
public:
    //constructor header declaration
    CTIS();

    //destructor header declaration
    ~CTIS();

    //setter header declaration of the vector stored
    void setListOfPatient(Patient);
    void setListOfCentreOfficer(CentreOfficer);
    void setListOfCentre(TestCentre);

    //getter header declaration of the vector stored
    vector<Patient> getPatientList();
    vector<CentreOfficer> getListOfCentreOfficer();
    vector<TestCentre> getListOfCentre();

    //a method header declaration to generate random
    // number for ID of the test centre
    int randomCentreID();

    //a method header declaration to generate random
    // number for ID of the test kit
    int randomKitID();

    ///a method header declaration to generate random
    // number for ID of the covid test
    int randomTestID();

    //a method header declaration to validate 
    //the login process of the manager account
    bool checkManagerLogin(string inputUsername, string inputPassword);
    
    //a method header declaration to validate 
    //the login process of the tester account
    bool checkTesterLogin(string inputUsername, string inputPassword);
    
    //a method header declaration to validate 
    //the login process of the patient account
    bool checkPatientLogin(string inputUsername, string inputPassword);
    
    //a method header declaration of pointer to get
    //the address of the centre officer account in the vector
    CentreOfficer* getOfficerAddress(string usernameInput, string passInput);

    //a method header declaration of pointer to get
    //the address of the patient account in the vector
    Patient* getPatientListAddress(string uname);

    //a method header declaration to check whether the
    //inputted username of centre officer is unique or not
    bool checkUsernameOfficer(string inputUsername);

    //a method header declaration to check whether the
    //inputted username of patient is unique or not
    bool checkUsernamePatient(string inputUsername);

};


#endif //ASSIGNMENT_1_CTIS_H
