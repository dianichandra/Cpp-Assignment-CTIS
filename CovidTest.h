/**
 * @author Putu Mas Diani Chandra
 */

#include <string>
using namespace std;

#ifndef ASSIGNMENT_1_COVIDTEST_H
#define ASSIGNMENT_1_COVIDTEST_H

//class CovidTest header
class CovidTest {
    //public methods of CovidTest Class
public:
    //default constructor header declaration of CovidTest with no parameter
    CovidTest();

    //constructor header declaration of CovidTest
    CovidTest(string tID, string tDate, string rslt, string rsltDate, string sts);

    //destructor
    ~CovidTest();

    //setter for the attributes
    void setTestID(string tID);
    void setTestDate(string tDate);
    void setResult(string rslt);
    void setResultDate(string rsltDate);
    void setStatus(string sts);

    //getter for the attributes
    string getTestID();
    string getTestDate();
    string getResult();
    string getResultDate();
    string getStatus();

    //private attributes of CovidTest Class
private:
    string testID;
    string testDate;
    string result;
    string resultDate;
    string status;
};

#endif //ASSIGNMENT_1_COVIDTEST_H
