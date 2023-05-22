/**
 * @author Putu Mas Diani Chandra
 */

//including the header files needed
#include "CTIS.h"
#include "TestCentre.h"
#include "TestKit.h"

//iostream library to enable input output activity
#include <iostream>
#include <ctime>
using namespace std;

//variables needed declaration
int choice = 20, choice2 = 20, stockKitInput, newStockKit;
char takenTestChar, testKitChar, patientTypeInput;
string usernameInput, passInput, usernameInput2, passInput2,
nameInput, nameOfCentre, testCentreID,
        symptomsInput, kitNameInput, testKitID, patientType,
        testID, testDate, resultTest, resultDate;

//a CTIS object to access methods in CTIS
CTIS CTIS1;

//default TestCentre object that'll be assigned later
TestCentre defaultTc;

int main() {
    while (choice!= 6){
        //main menu
        cout << "\n====== Welcome to Covid Testing Information System ======" << endl;
        cout << "\nMenu: " << endl;
        cout << "1. Sign up as Centre Manager" << endl;
        cout << "2. Log in as Centre Manager" << endl;
        cout << "3. Log in as Tester" << endl;
        cout << "4. Log in as Patient" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter number you want to select: ";
        cin >> choice;

        //switch case for the main menu
        switch (choice) {
            //Sign Up As Centre Manager
            case 1: {
                signUpManager:
                cout << "\n------- CREATING A CENTRE MANAGER ACCOUNT -------" << endl;
                cout << "\nCreate username: ";
                cin >> usernameInput;

                cout << "Create password: ";
                cin >> passInput;

                cout << "Enter your name: ";
                cin.ignore();
                getline(cin, nameInput);

                //condition when the username is taken
                while(CTIS1.checkUsernameOfficer(usernameInput)){
                    cout << "\nUsername is taken! \n Please create a new one!" << endl;
                    //go back to the signUpManager label and enter a new data
                    goto signUpManager;
                }

                //Creating a CentreOfficer object with position of Manager
                CentreOfficer manager1(usernameInput, passInput, nameInput,
                                       "Manager",defaultTc);
                //adding the CentreOfficer object to the vector in CTIS
                CTIS1.setListOfCentreOfficer(manager1);
                cout << "\nManager account successfully created!" <<endl;

            }
                break;

            //Log In as Centre Manager
            case 2: {
                cout << "Enter username: ";
                cin >> usernameInput;
                cout << "Enter password: ";
                cin >> passInput;

                //creating a CentreOfficer object to store the address of the manager
                //who is currently logged in to the system
                CentreOfficer *currentManager = CTIS1.getOfficerAddress
                        (usernameInput, passInput);

                //validate the login process
                if (CTIS1.checkManagerLogin(usernameInput, passInput)) {
                    cout << "\n------- LOGGED IN AS CENTRE MANAGER -------" << endl;
                    cout << "\nMenu: " <<endl;
                    cout << "1. Register Test Centre" << endl;
                    cout << "2. Record Tester" << endl;
                    cout << "3. Manage Test Kit Stock" << endl;
                    cout << "4. Generate Test Report" << endl;
                    cout << "5. Back" << endl;
                    cout << "\nEnter number you want to choose: ";
                    cin >> choice2;

                    switch (choice2) {
                        //Registering a Test Centre
                        case 1: {
                            cout << "Registering for Test Centre." << endl;
                            cout << "Enter Test Centre's Name: ";
                            cin.ignore();
                            getline(cin, nameOfCentre);

                            //looping through the vector of test centre
                            for(int i = 0; i < CTIS1.getListOfCentre().size(); i++){
                                //condition where inputted centre name is already created
                                while(nameOfCentre == CTIS1.getListOfCentre().at(i).getCentreName()){
                                    cout << "The centre has been registered!" << endl;
                                    cout << "Enter another Test Centre's Name: ";
                                    getline(cin, nameOfCentre);
                                }
                            }
                            //generate centre ID
                            testCentreID = "TC-" + to_string(CTIS1.randomCentreID());

                            //a TestCentre object created to store the test centre inputted
                            TestCentre tCentre1(testCentreID, nameOfCentre);
                            //adding the test centre into the vector in CTIS
                            CTIS1.setListOfCentre(tCentre1);

                            //adding the test centre into the manager that registered it
                            currentManager->setTestCentre(tCentre1);
                            cout << "Manager " << currentManager->getName() <<
                            " successfully register a test centre" <<
                            " with the name of: " << currentManager->getTestCentre()->
                            getCentreName() << "Test Centre." << endl;
                        }
                            break;

                        //Record Tester
                        case 2: {
                            signUpTester:
                            cout << "\n------- CREATING A TESTER ACCOUNT -------" << endl;
                            cout << "\nCreate username: ";
                            cin >> usernameInput2;
                            cout << "Create password: ";
                            cin >> passInput2;
                            cout << "Enter name: ";
                            cin.ignore();
                            getline(cin, nameInput);

                            //condition when the username is taken
                            while(CTIS1.checkUsernameOfficer(usernameInput2)){
                                cout << "\nUsername is taken! \n Please create a new one!" << endl;
                                //go back to the selected label
                                goto signUpTester;
                            }

                            //A TestCentre object is created
                            TestCentre centreTester = currentManager->getTestCentreObj();
                            //A CentreOfficer object is created to store the tester
                            CentreOfficer tester1(usernameInput2, passInput2,
                                                  nameInput, "Tester",centreTester);
                            //adding the tester account into the vector of centre officer in CTIS
                            CTIS1.setListOfCentreOfficer(tester1);

                            //another tester account created to get the address of the tester that created just now
                            CentreOfficer *tester2 = CTIS1.getOfficerAddress
                                    (usernameInput2, passInput2);
                            //assign the test centre into the tester
                            tester2->setTestCentre(centreTester);

                            cout << "\nA tester account succesfully created !" << endl;
                        }
                            break;

                        //Manage Test Kit Stock
                        case 3:
                            cout << "\n------- MANAGE TEST KIT STOCK -------" << endl;
                            cout << "\nNew Test Kit or Not? [Y/N]: ";
                            cin >> testKitChar;

                            //creating a new test kit
                            if(testKitChar == 'Y' || testKitChar == 'y'){
                                cout << "Enter Test Kit Name: ";
                                cin.ignore();
                                getline(cin,kitNameInput);

                                cout << "Enter stock: ";
                                cin >> stockKitInput;

                                testKitID = "KT-" + to_string(CTIS1.randomKitID());
                                cout << "Test Kit ID Debug: " << testKitID << endl;

                                //a TestKit object is created to store the test kit created just now
                                TestKit testKit1(kitNameInput,testKitID, stockKitInput);

                                //adding the test kit into the manager that logged in and also in its test centre
                                currentManager->getTestCentre()->createTestKit
                                (kitNameInput,testKitID,stockKitInput);

                                cout << "Test Kit recorded with Kit ID: " << testKit1.getKitID() << endl;
                            }

                            //accessing the recorded test kit
                            else if(testKitChar == 'N' || testKitChar == 'n'){
                                cout << "=== Searching for the recorded Test Kit ===" << endl;
                                cout << "Enter Test Kit ID (ex: KT-43): " << endl;
                                cin >> testKitID;

                                //looping through the test kit stored in the test centre of the logged in manager
                                for(int a = 0; a < currentManager->getTestCentre()->getTestKitList().size(); a++) {
                                    //condition where the current manager store the kit ID the same as the inputted test kit ID
                                    if (testKitID == currentManager->getTestCentre()->getTestKitList().at(a).getKitID()){
                                        //A TestKit object created
                                        //getting the address of test kit index of a which stored the kit id searched
                                        TestKit *kit1 = currentManager->getTestCentre()->getTestKitAddress(testKitID);
                                        cout << "Enter the new stock for Test Kit: ";
                                        cin >> newStockKit;

                                        //changing the stock of available test kit
                                        kit1->setAvailableStock(newStockKit);
                                        cout << "Stock updated! Current stock: " << currentManager->getTestCentre()
                                        ->getTestKitList().at(a).getAvailableStock();
                                    }
                                }
                            }
                            else{
                                cout << "Invalid character inputted ! Please input the right one!";
                            }

                            break;

                        //Generate Report
                        case 4:
                            currentManager->viewTestHistory(usernameInput,passInput);
                            break;

                        case 5:
                            break;
                        default:
                            cout << "Invalid input. Please enter the right number !";

                    }

                } else {
                    cout << "Account not found !" << endl;
                }
            }
                break;

            //Login as Tester
            case 3:
                cout << "\n------- LOGGED IN AS A TESTER -------" << endl;
                cout << "Enter username: ";
                cin >> usernameInput;
                cout << "Enter password: ";
                cin >> passInput;
                //validate the login process
                if(CTIS1.checkTesterLogin(usernameInput,passInput)) {
                    cout << "\n------- LOGGED IN AS TESTER -------" << endl;
                    cout << "\nMenu: " << endl;
                    cout << "\n1. Record New Test" << endl;
                    cout << "2. Update Test Result" << endl;
                    cout << "3. Generate Test Report" << endl;
                    cout << "4. Back" << endl;
                    cout << "\nEnter number you want to choose: ";
                    cin >> choice2;

                    switch (choice2) {
                        case 1:
                            cout << "Has the patient taken a test before? (Y/N): ";
                            cin >> takenTestChar;
                            //creating a new patient
                            if(takenTestChar == 'N' || takenTestChar == 'n'){
                                signUpPatient:
                                cout << "\n------- REGISTERING A NEW PATIENT -------" << endl;
                                cout << "\nEnter username: ";
                                cin >> usernameInput2;

                                //condition where the username is taken
                                while(CTIS1.checkUsernamePatient(usernameInput2)){
                                    cout << "\nUsername is taken! \n Please create a new one!" << endl;
                                    goto signUpPatient;
                                }

                                cout << "Enter password: ";
                                cin >> passInput2;
                                cout << "Enter name: ";
                                cin >> nameInput;

                                TypeInput:
                                cout << "Patient's type: (Input the character only)"
                                        << "\n[R]eturnee/[Q]uarantined/[C]lose Contact/ [I]nfected/ [S]uspected): ";
                                cin >> patientTypeInput;

                                if(patientTypeInput == 'R'|| patientTypeInput == 'r'){
                                    patientType = "Returnee";
                                }
                                else if(patientTypeInput == 'Q'|| patientTypeInput == 'q'){
                                    patientType = "Quarantined";
                                }
                                else if(patientTypeInput == 'C'|| patientTypeInput == 'c'){
                                    patientType = "Close Contact";
                                }
                                else if(patientTypeInput == 'I'|| patientTypeInput == 'i'){
                                    patientType = "Infected";
                                }
                                else if(patientTypeInput == 'S'|| patientTypeInput == 's'){
                                    patientType = "Suspected";
                                }
                                else{
                                    cout << "Invalid input ! Please try again!" << endl;
                                    goto TypeInput;
                                }

                                cout << "Symptoms: ";
                                cin >> symptomsInput;

                                //generating the test ID
                                testID = "T-" + to_string(CTIS1.randomTestID());

                                //generating the test Date
                                time_t timeOfNow = time(NULL);
                                tm * tmOfNow;
                                char stringOfDate[100];
                                tmOfNow = localtime(&timeOfNow);
                                strftime(stringOfDate, 50, "Today is %B %d, %Y", tmOfNow);
                                testDate = stringOfDate;

                                cout << "\nPatient succesfully registered registered with Test ID: " << testID
                                << ", and Date: " << testDate << endl;

                                //A CovidTest object created
                                CovidTest cvT(testID, testDate, "no result",
                                              "no result date", "Pending");

                                //a patient object created
                                Patient patient1(usernameInput2, passInput2,
                                                 nameInput, patientType, symptomsInput);
                                //add the patient object to the vector in CTIS
                                CTIS1.setListOfPatient(patient1);

                                //set aggregation for patient goes here:

                                //a new patient object that gets the address of patient that currently recorded
                                Patient *patient2 = CTIS1.getPatientListAddress(usernameInput2);
                                //add the covidTest into the vector of covidtest aggregated in patient class
                                patient2->createNewCovidTest(cvT);

                                //set aggregation for tester goes here:
                                //getting the address of the tester that logged in and store it into an object
                                CentreOfficer *currentTester = CTIS1.getOfficerAddress
                                        (usernameInput, passInput);
                                //add the covidTest into the vector of covidtest aggregated in CentreOfficer class
                                currentTester->createCovidTest(cvT);

                                //looping through the centre officer vector in CTIS
                                for(int i = 0; i < CTIS1.getListOfCentreOfficer().size(); i++){
                                    //condition where the manager has the same test centre as the tester
                                    if(CTIS1.getListOfCentreOfficer()[i].getTestCentre()->
                                    getCentreName() == currentTester->getTestCentre()->getCentreName()
                                    && CTIS1.getListOfCentreOfficer()[i].getPosition() == "Manager"){
                                        //getting the username and password of the manager
                                        string unameMngr = CTIS1.getListOfCentreOfficer()[i].getUsername();
                                        string passMngr = CTIS1.getListOfCentreOfficer()[i].getPassword();
                                        //set aggregation for manager goes here:
                                        //getting the address of the manager that logged in and store it into an object
                                        CentreOfficer *managerWithSameTc = CTIS1.getOfficerAddress
                                                (unameMngr, passMngr);
                                        //add the covidTest into the vector of covidtest aggregated in CentreOfficer class (manager version)
                                        managerWithSameTc->createCovidTest(cvT);

                                        //reducing the kit stock
                                        TestKit *reduceKit = managerWithSameTc->getTestCentre()->
                                                getTestKitAddress(testKitID);
                                        reduceKit->setAvailableStock(reduceKit->getAvailableStock() - 1);
                                    }
                                }

                            }
                            //searching for the patient registered
                            else if(takenTestChar == 'Y' || takenTestChar == 'y'){
                                cout << "------- SEARCHING FOR THE RECORDED PATIENT -------" << endl;
                                cout << "Enter username of the Patient: " << endl;
                                cin >> usernameInput2;

                                //looping through the patient list
                                for(int a = 0; a < CTIS1.getPatientList().size(); a++) {
                                    //condition where the username matched the username of object at patientList
                                    if (usernameInput2 == CTIS1.getPatientList()[a].getUsername()){
                                        //getting the patient address with the same username
                                        Patient *patient1 = CTIS1.getPatientListAddress(usernameInput2);
                                        TypeInput2:
                                        cout << "Enter new Patient's type: (Input the character only)"
                                             << "\n[R]eturnee/[Q]uarantined/[C]lose Contact/ [I]nfected/ [S]uspected): ";
                                        cin >> patientTypeInput;
                                        if(patientTypeInput == 'R'|| patientTypeInput == 'r'){
                                            patientType = "Returnee";
                                        }
                                        else if(patientTypeInput == 'Q'|| patientTypeInput == 'q'){
                                            patientType = "Quarantined";
                                        }
                                        else if(patientTypeInput == 'C'|| patientTypeInput == 'c'){
                                            patientType = "Close Contact";
                                        }
                                        else if(patientTypeInput == 'I'|| patientTypeInput == 'i'){
                                            patientType = "Infected";
                                        }
                                        else if(patientTypeInput == 'S'|| patientTypeInput == 's'){
                                            patientType = "Suspected";
                                        }
                                        else{
                                            cout << "Invalid input ! Please try again!" << endl;
                                            goto TypeInput2;
                                        }
                                        cout << "Enter new symptoms for the patient: ";
                                        cin >> symptomsInput;

                                        //changing the type of patient
                                        patient1->setPatientType(patientType);
                                        //changing the symptoms of patient
                                        patient1->setSymptoms(symptomsInput);

                                        cout << "\nPatient type and Symptoms changed!" << endl;

                                    }
                                    else{
                                        cout << "Account not found! Please input the right username!" << endl;
                                    }
                                }



                            } else{
                                cout << "Invalid character! Please input the right one!";
                            }

                            break;

                        //Update Test Result
                        case 2: {
                            cout << "------- UPDATE TEST RESULT -------" << endl;
                            cout << "Enter test ID(ex: T-28) : ";
                            cin >> testID;

                            //getting the address of the tester that logged in
                            CentreOfficer *currentTester = CTIS1.getOfficerAddress
                                    (usernameInput, passInput);
                            //looping through the covid test vector in the tester
                            for (int a = 0; a < currentTester->getCovidTestList().size(); a++) {
                                //condition if the testID inputted is the same as the object
                                if (testID == currentTester->getCovidTestList().at(a).getTestID()) {
                                    cout << "Enter result: ";
                                    cin >> resultTest;

                                    //getting the address of the covid test in the tester
                                    CovidTest *cvTest1 = currentTester->getCovidTestAddress(testID);

                                    //generating the date for resultDate
                                    time_t timeOfNow = time(NULL);
                                    tm * tmOfNow;
                                    char stringOfDate[100];
                                    tmOfNow = localtime(&timeOfNow);
                                    strftime(stringOfDate, 50, "Today is %B %d, %Y", tmOfNow);

                                    resultDate = stringOfDate;

                                    //update test result
                                    cvTest1->setResult(resultTest);
                                    cvTest1->setResultDate(resultDate);
                                    cvTest1->setStatus("Complete");

                                    string usernamePtn, passPtn;
                                    for(int j = 0; j < CTIS1.getPatientList().size(); j++) {
                                        if (testID == CTIS1.getPatientList()[j].getCovidTestList()[j].getTestID()){
                                            usernamePtn = CTIS1.getPatientList()[j].getUsername();
                                            Patient *ptn1 = CTIS1.getPatientListAddress(usernamePtn);
                                            //update test result
                                            ptn1->getCovidTestAddress(testID)->setResult(resultTest);
                                            ptn1->getCovidTestAddress(testID)->setResultDate(resultDate);
                                            ptn1->getCovidTestAddress(testID)->setStatus("Complete");
                                        }
                                    }
                                    cout << "\n Test has been updated! " << endl;

                                } else {
                                    cout << "No test found based on the inputted test ID !" << endl;
                                }
                            }
                        }
                            break;

                        //Generate Report
                        case 3: {
                            CentreOfficer *currentTester = CTIS1.getOfficerAddress
                                    (usernameInput, passInput);
                            currentTester->viewTestHistory(usernameInput, passInput);
                        }
                            break;
                        case 4:
                            break;
                        default:
                            cout << "Invalid input. Please enter the right number !";

                    }
                }
                else{
                    cout << "Account not found !";
                }
                break;

            //Login as Patient
            case 4:
                cout << "------- LOGGED IN AS PATIENT -------" << endl;
                cout << "Enter username: ";
                cin >> usernameInput;
                cout << "Enter password: ";
                cin >> passInput;

                //validate login process
                if(CTIS1.checkPatientLogin(usernameInput,passInput)) {
                    cout << "Menu: "<<endl;
                    cout << "\n1. View Test History" << endl;
                    cout << "2. Back" << endl;
                    cout << "\nEnter number you want to choose: ";
                    cin >> choice2;

                    switch (choice2) {
                        //viewing the test history of the patient
                        case 1: {
                            Patient *patient1 = CTIS1.getPatientListAddress(usernameInput);
                            cout << patient1->viewTestHistory(usernameInput, passInput);
                        }
                            break;
                        case 2:
                            break;
                        default:
                            cout << "Invalid input. Please enter the right number !";
                    }
                }
                else{
                    cout << "Account not found !" << endl;
                }
                break;
            case 5:
                break;
        }
    }
    return 0;
}
