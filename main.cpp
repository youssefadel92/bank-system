// Course:  CS213 - Programming II  - 2018
// Id:      20170345
// Name:    Youssef Adel El-Sayed
// Id:      20170346
// Name:    Youssef Essam Farid
// Title:   Assignment III - Group Problem 2 (Banking System)
// Program: CS213-2018-Banking System
// Purpose: System for managing clients of bank
// Author:  Dr. Mohammad El-Ramly
// Date:    16 November 2018
// Version: 1.0
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;



/*------------------------------------*/
static int counter=1;   // counter for the is
class bankaccount;   // initial declaration
static vector<bankaccount*> objList; //vector for the bank acounts
class client; // initial declaration
/*------------------------------------*/


class client{
protected: //members of class
    bankaccount *j;
    string name;
    string address;
    string phonenum;
public:
    client(string x,string y,string z,bankaccount *q){  //default constructor
        j=q;
        name=x;
        address=y;
        phonenum=z;
    }
    void print(){   // printing details of client
        cout<<name<<endl;
        cout<<address<<endl;
        cout<<phonenum<<endl;
    }
};
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
class bankaccount{
protected: //members of class
    client* person;
    string id;
    float balance;
public:
    bankaccount(float balance1,client & p){ //default constructor
        person =&p;
        id="FCI-"+to_string(counter);
        counter++;
        balance=balance1;

;    }
    bankaccount(){
        id="FCI-"+to_string(counter);
        counter ++;
        balance=0;

    }
    virtual void setminimumbalance(float x){} //virtual for the inheritance with the saving bank acount
    void setperson(client * p){
        person=p;
    }
    void setbalance(float balance1){
        balance=balance1;
    }
    void getbalance(){
        cout<<balance<<endl;
    }
    string getid(){
        return id;
    }

    virtual void showaccount(){
        cout<<"id:"<<id<<endl;
        person->print();
        cout<<"type:"<<"Basic"<<endl;
        cout<<"balance: "<<balance<<endl;

    }
    virtual void withdraw() {          // withdraw money method
        float wdraw;
        while(1==1){
            cout << "Enter amount to be withdrawn:";
            cin >>wdraw;
            if(wdraw<balance){
                break;
            }
        }
        balance = balance - wdraw;
    }
    virtual void deposit() {          // deposit money method
        float depos;
        cout << "Enter amount to be deposited:";
        cin >>depos;
        balance = balance + depos;
    }
};
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
class savingbankacounts:public bankaccount{
private:
    float minimumbalance;
public:
    savingbankacounts(){
        minimumbalance=0;
    }
    savingbankacounts(float x){
        minimumbalance=x;
    }
    void setminimumbalance(float x){
        minimumbalance=x;
    }
    float getminimumbalance(){
        return minimumbalance;
    }
    void withdraw() {          // withdraw money method
        float wdraw;
        while(1==1){
            cout << "Enter amount to be withdrawn:";
            cin >>wdraw;
            if(balance-wdraw>=minimumbalance){
                break;
            }
        }
        balance = balance - wdraw;
    }
    void deposit() {          // deposit money method
        float depos;
        while(1==1){
            cout << "Enter amount to be Deposited:";
            cin >>depos;
            if(depos>=100){
                break;
            }
        }
        balance =balance+depos;
    }
    void showaccount(){
        cout<<"id:"<<id<<endl;
        person->print();
        cout<<"type:"<<"Saving Bank Account"<<endl;
        cout<<"minimum balance: "<<minimumbalance<<endl;
        cout<<"balance: "<<balance<<endl;

    }


};
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
class Bankapplications
{
public:
    int x;
    bank(){};
    void printmenu(){
    cout<<"Welcome to FCI Banking Application"<<endl;
    cout<<"1. Create a New Account"<<endl;
    cout<<"2. List Clients and Accounts"<<endl;
    cout<<"3. Withdraw Money"<<endl;
    cout<<"4. Deposit Money"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Please Enter Choice =========>";
    }
    int retchoice(){
        cin>>x;
    }
    void addclient(){
        string clientname,clientadress,clientphone;
        cout << "Please enter Client Name:";
        cin>>clientname;
        cout << "Please enter Client Address:";
        cin>>clientadress;
        cout << "Please enter Client Phone:";
        cin>>clientphone;
        cout << "What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2 =========>";
        int y;
        cin >>y;
        if (y==1) {
            cout<<"Please Enter the Starting Balance:";
            float bal;
            cin>>bal;
            bankaccount *x=new bankaccount;
            client *p=new client(clientname,clientadress,clientphone,x);
            x->setperson(p);
            x->setbalance(bal);
            objList.push_back(x);
        }
        else if (y==2){
            cout<<"Please Enter the Minimum Balance:";
            float bal;
            cin>>bal;
            bankaccount *x=new savingbankacounts();
            client *p=new client(clientname,clientadress,clientphone,x);
            x->setperson(p);
            x->setbalance(bal);
            x->setminimumbalance(bal);
            objList.push_back(x);
        }
    }

    void clientlist(){
        for (int i=0;i<=counter-2;i++){
            objList[i]->showaccount();
        }
    }
    void withdraw(){
        int pos=0;
        string ss;
        float zz;
        cout<<"Enter Acount ID:";
        cin>>ss;
        for (pos;pos<=counter-2;pos++){
            if(objList[pos]->getid()==ss){
                objList[pos]->showaccount();
                break;
            }
        }
        objList[pos]->withdraw();
    }
    void deposit(){
        int pos=0;
        string ss;
        float zz;
        cout<<"Enter Acount ID:";
        cin>>ss;
        for (pos;pos<=counter-2;pos++){
            if(objList[pos]->getid()==ss){
                objList[pos]->showaccount();
                break;
            }
        }
        objList[pos]->deposit();
    }


};


int main()
{
    Bankapplications app1;
    while (1==1){
        app1.printmenu();
        app1.retchoice();
        switch (app1.x){
            case 1 :
                app1.addclient();
                break;
            case 2 :
                app1.clientlist();
                break;
            case 0 :
                break;
            case 3 :
                app1.withdraw();
                break;
            case 4 :
                app1.deposit();
                break;
            default :
                cout << "Invalid choice" << endl;
        }
    }

}
