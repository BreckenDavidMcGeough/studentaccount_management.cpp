//
//  main.cpp
//  testproduct
//
//  Created by Brecken McGeough on 4/21/18.
//  Copyright © 2018 Brecken McGeough. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Account{
private:
    vector<string> Usernames;
    vector<string> Passwords;
    string arrayUsernames[sizeof(Usernames)/sizeof(Usernames[0])];
    string arrayPasswords[sizeof(Passwords)/sizeof(Passwords[0])];
public:
    vector<string> classesVector;
    string classesArray[sizeof(classesVector)/sizeof(classesVector[0])];
    typedef unsigned long int ULI64;
    vector<string> Classes;
    float * gpa_pointer;
    ULI64 * id_pointerl;
    void initializeVectors(string testuser, string testpass){
        this->Usernames.push_back(testuser);
        this->Passwords.push_back(testpass);
        cout << "Initialized info" << endl;
    }
    void setBasicinfo(float gpa, ULI64 id){
        this->gpa_pointer = &gpa;
        this->id_pointerl = &id;
        cout << *gpa_pointer << endl;
        cout << gpa_pointer << endl;
    }
    void setArrays(){
        ULI64 sizeUsers = sizeof(this->Usernames)/sizeof(this->Usernames[0]);
        ULI64 sizePass = sizeof(this->Passwords)/sizeof(this->Passwords[0]);
        if(sizeUsers == sizePass){
            for(int i = 0; i <= sizePass-1; i++){
                this->arrayUsernames[i] = this->Usernames[i];
                this->arrayPasswords[i] = this->Passwords[i];
            }
        }
    }
    void setInfo(string username, string password){
        ULI64 sizeUsernames = sizeof(this->Usernames)/sizeof(this->Usernames[0]);
        ULI64 sizePasswords = sizeof(this->Passwords)/sizeof(this->Passwords[0]);
        if(sizeof(username) != 0 && sizeof(password) != 0 && sizeUsernames == sizePasswords){
            if(sizeUsernames == 0){
                this->Usernames.push_back(username);
                this->Passwords.push_back(password);
            }else{
                for(int i = 0;i <= sizeUsernames; i++){
                    if(Usernames[i] == username or Passwords[i] == password){
                        cout << "Error" << endl;
                    }else{
                        if(i == sizeUsernames){
                            this->Usernames.push_back(username);
                            this->Passwords.push_back(password);
                            cout << "Success" << endl;
                        }
                    }
                }
            }
        }
    }
    bool checkInfo(string username, string password){
        bool check = false;;
        ULI64 sizeArray = sizeof(this->Usernames)/sizeof(this->Usernames[0]);
        if(sizeof(username) != 0 && sizeof(password) != 0){
            for(int i = 0; i <= sizeArray;i++){
                if(this->Usernames[i] == username && this->Passwords[i] == password){
                    cout << "Welcome" << endl;
                    check = true;
                }else{
                    if(i == sizeArray){
                        check = false;
                    }
                }
            }
        }
        return check;
    }
    void setClasses(string arrayClasses[]){
        ULI64 sizeclassArray = sizeof(arrayClasses)/sizeof(arrayClasses[0]);
        for(int i = 0; i<= sizeclassArray-1; i ++){
            this->classesVector[i] = arrayClasses[i];
        }
    }
    void getClasses(){
        for(string c : this->classesArray){
            cout << c;
        }
    }
};
int main(int argc, const char * argv[]) {
    Account test;
    test.initializeVectors("brecken", "brecken");
    test.setInfo("hello","hello");
    test.setArrays();
    if(test.checkInfo("hello", "hello") == true){
        cout << "Two" << endl;
    }else{
        cout << "Wrong" << endl;
    }
    test.setBasicinfo(3.7, 1234567);
}
