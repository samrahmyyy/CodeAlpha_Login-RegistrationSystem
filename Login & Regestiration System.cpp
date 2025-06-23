
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void login();
void registerr ();

int main() {
    cout << "Hello User, Enter ur command" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;

int choice;
cin >> choice;

switch (choice) {

case 1:
login();
break;
        case 2:
registerr ();
break;

default:
cout << "Invalid Choice";
}

    return 0;
}


void login () {
    string username , password , userfile , passwordfile;
    bool flag = false;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    ifstream input ("Database.txt");
    while (input >> userfile >> passwordfile) {
        if (userfile==username && passwordfile==password) {
            flag = true;
        }
    }
    input.close();
    if (flag == true) {
        cout << "Hi:"<<username<< " Logged In Successfully!\n";
    }

else {
    cout << "Logged In Failed!\n";
}

}


void registerr () {
    string username , password , userfile , passwordfile ;
    bool flag = false;
    cout << "Enter Username: ";
    cin >> username ;
    cout << "Enter Password: ";
    cin >> password;

    // check if any usernames is dublicated.
    ifstream input ("Database.txt");
    while (input >> userfile >> passwordfile) {
        if (userfile==username) {
            flag = true;
        }
    }
    input.close();

if (flag) {
    cout << "Ur username already exist , please try another one :)";
}
    else {
        ofstream reg ("Database.txt", ios::app);
        reg << username << " " << password << endl;
        reg.close ();
        cout << "Registered Successfully!\n";

    }
}