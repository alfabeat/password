 passman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring> 


using namespace std;
//defning functions
int enterpass();
unsigned long getmainpassword();
int check(string pass, unsigned long mainpass);
void addpass();
void display();
void seachpass();
//struct for the pass words
struct passlist
{
    string pass;
    string username;
    string website;
};
vector<passlist> aa;

int main()
{
    int x = 0;
    string getmainpassword;
    int enter = 0;

    //Home screen and options
    x = enterpass();
    while (x == 0) {
        cout << "\n\nEnter the number for requerd option \n\n";
        cout << "1. Display passwords\n\n";
        cout << "2. Search passwords\n\n";
        cout << "3. Add password\n\n";
        cin >> enter;
        switch (enter)
        {
        case(1):
            display();
            break;
        case(2):
            seachpass();
            break;
        case(3):
            addpass();
            break;
        }

    }


}



int enterpass() {//entering passwork
    string pass;

    cout << "Enter password \n\n";
    cin >> pass;
    unsigned long mainpass = getmainpassword();
    int pas = check(pass, mainpass);
    return 0;
}

unsigned long getmainpassword() {//gets password and password data
    int x = 0;
    int y = 0;
    unsigned long mainpass;
    passlist a;

    string line;
    ifstream myfile("pass.txt");
    unsigned long pass;
    getline(myfile, line);


    hash <string> hash;
    pass = hash(line);
    while (getline(myfile, line))
    {
        if (x == 0) {
            a.pass = line;
            int length = a.pass.length();

         

            for (int i = 0; i < length; i++)
            {
                if(y==1){
                    a.pass.erase(a.pass.begin() + i);
                    y = y - 1;
                    length = length - 1;
                }
                else {
                    y = y + 1;
                }
            }
           
           y = 0;

            
        }
        else if (x == 1) {
            a.username = line;
        }
        else if (x == 2) {
            a.website = line;
            aa.push_back(a);
            x = -1;
       
        }

        x = x + 1;
       
    }

    myfile.close();


    return pass;
}
int check(string pass, unsigned long mainpass) {//check the password
    hash <string> hash;
    unsigned long passs = hash(pass);
    if (passs == mainpass) {

        return 0;
    }
    else {
        return 1;
    }

}
void addpass() {// adds and encryps the password basic encrypion 
    passlist a;
    int y = 0;
    cout << "Enter the website \n\n";
    cin >> a.website;
    cout << "Enter the pass \n\n";
    cin >> a.pass;
    cout << "Enter the username \n\n";
    cin >> a.username;
    aa.push_back(a);
   int length = a.pass.length();

    string str = "g";
    for (int i = 0; i < length; i++)
    {
        if (y == 1) {
         
            a.pass.insert(i, 1, '$');
            y = y - 1;
            length = length + 1;
        }
        else {
            y = y + 1;
        }
       
    }

  
    std::ofstream out;
   
    // std::ios::app is the open mode "append" meaning
    // new data will be written to the end of the file.
    out.open("pass.txt", std::ios::app);

    out << endl;
    out << a.pass  ;
    out << endl;
    out << a.username;
    out << endl;
    out << a.website;
    out.close();
}

void seachpass() {//search of website
    string value;
    cout << "Enter search website\n\n";
    cin >> value;

    passlist a;
    for (int i = 0; i < aa.size(); i++){
        if (aa[i].website == value)
        {
            cout << "Username\n\n";
            cout << aa[i].username + "\n\n";
            cout << "Website\n\n";
            cout << aa[i].website + "\n\n";
            cout << "Password\n\n";
            cout << (aa[i].pass) + "\n\n";
        }
}
  
}

void display() {//displays all password with data
    
    for (int i = 0; i < aa.size(); i++)
    {   
        cout << "Username\n\n";
        cout << aa[i].username + "\n\n";
     
        cout << "Website\n\n";
        cout << aa[i].website + "\n\n";
        cout << "Password\n\n";
        cout << (aa[i].pass)+"\n\n";
        
  
    }
}
