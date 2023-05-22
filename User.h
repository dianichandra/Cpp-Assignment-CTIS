/**
 * @author Putu Mas Diani Chandra
 */

#include <string>
using namespace std;

#ifndef ASSIGNMENT_1_USER_H
#define ASSIGNMENT_1_USER_H

//class user header
class User{
    //public methods of User Class
public:

    //default constructor header declaration of User with no parameter
    User();

    //constructor header declaration of User
    User(string uname, string pw, string nm);

    //destructor
    ~User();

    //declaration of pure virtual function to make this class Abstract and parent class
    virtual string viewTestHistory(string inputUsername, string inputPassword) = 0;

    //setter for the attributes
    void setUsername(string uname);
    void setPassword(string pw);
    void setName(string nameInput);

    //getter for the attributes
    string getUsername();
    string getPassword();
    string getName();

    //private attributes of User Class
private:
    string username;
    string password;
    string name;
};

#endif //ASSIGNMENT_1_USER_H

