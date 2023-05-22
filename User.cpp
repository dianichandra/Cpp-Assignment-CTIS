/**
 * @author Putu Mas Diani Chandra
 */

//including the header file
#include "User.h"
using namespace std;

//default constructor of User with no parameter
User::User() {
    setName("no name");
    setUsername("no username");
    setPassword("no password");
}

//constructor of User with parameters
User::User(string uname, string pw, string nm) {
    setName(nm);
    setUsername(uname);
    setPassword(pw);
}

//destructor of User class
User::~User() {}


//getter for the User class attributes
string User::getUsername() {return username;}
string User::getPassword() {return password;}
string User::getName() {return name;}

//setter for the User class attributes
void User::setUsername(string uname) {username = uname;}
void User::setPassword(string pw) {password = pw;}
void User::setName(string nameInput) {name = nameInput;}

//virtual method that will be inherited and polymorph to the child class
string User::viewTestHistory(string inputUsername, string inputPassword){
    return "";
}
