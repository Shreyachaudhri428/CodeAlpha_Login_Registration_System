#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser()
{
    string username, password;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "\nRegistration Successful\n";
}

void loginUser()
{
    string username, password;
    string u, p;
    bool found = false;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while(file >> u >> p)
    {
        if(username == u && password == p)
        {
            found = true;
            break;
        }
    }

    file.close();

    if(found)
        cout << "\nLogin Successful\n";
    else
        cout << "\nInvalid Username or Password\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Program Closed\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 3);

    return 0;
}