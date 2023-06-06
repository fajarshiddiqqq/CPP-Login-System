#include <iostream>

using namespace std;

struct user 
{
    string username;
    string password;
} users[100];

int loginCondition(string username, string password) {
  for (int i = 0; i < 100; i++) {
    if (users[i].username == username) {
      if (users[i].password == password) {
        return 200;
      } else {
        return 203;
      }
    }
  }
  return 500;
}

int cekUsername(string a) {
  for (int i = 0; i < 100; i++) {
    if (users[i].username == a) {
      return 0;
    }
  }
  return 1;
}

void printUsers(){
    for (int i = 0; i < 100; i++) 
    {
        if (!users[i].username.empty() || !users[i].password.empty()) 
        {
            cout << "user ke-" << i + 1 << endl;
            cout << "Username: " << users[i].username << endl;
            cout << "Password: " << users[i].password << endl;
            break;
            cout << endl;
        }
        else if (users[i].username.empty() || users[i].password.empty())
        {
            cout << "Empty!" << endl;
            break;
        }
    }
}

int main() {
    int count = 0;
    while (true) 
    {
        cout << endl;
        
        int a;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Print Users" << endl;
        cout << "4. Exit" << endl;
        cout << "pilih menu: ";
        
        try {
            cin >> a;
            cout << endl;
    
            if (a == 1) 
            {
                if (count == 1) 
                {
                    cout << "overload" << endl;
                } 
                else 
                {
                    string inputUsername, inputPassword;
    
                    cout << "Input Username: "; cin >> inputUsername;
                    cout << "Input Password: "; cin >> inputPassword;
                    cout << endl;
                    
                    if (cekUsername(inputUsername) == 0) 
                    {
                        cout << "Pilih username lain" << endl;
                    } 
                    else if (cekUsername(inputUsername) == 1) 
                    {
                        cout << "username berhasil tersimpan" << endl;
                        users[count].username = inputUsername;
                        users[count].password = inputPassword;
                        count += 1;
                    }
                }
            }
            else if (a == 2)
            {
                string inputUsername, inputPassword;
                
                cout << "Input Username: "; cin >> inputUsername;
                cout << "Input Password: "; cin >> inputPassword;
                cout << endl;
    
                if (loginCondition(inputUsername, inputPassword) == 200) 
                {
                    cout << "Berhasil Login!" << endl << endl;
                    
                    while(true)
                    {
                        int inputMenu;
                        cout << "1. Print Users" << endl;
                        cout << "2. Logout" << endl;
                        cout << "3. Exit" << endl;
                        cin >> inputMenu; 
                        cout << endl;
                        
                        if (inputMenu == 1)
                        {
                            printUsers();
                        }
                        else if (inputMenu == 2)
                        {
                            break;
                        }
                        else if (inputMenu == 3)
                        {
                            return(0);
                        }
                    }
                } 
                else if (loginCondition(inputUsername, inputPassword) == 203) 
                {
                    cout << "Password salah!" << endl;
                } 
                else if (loginCondition(inputUsername, inputPassword) == 500) {
                    cout << "Username Tidak ditemukan!" << endl;
                }
            } 
            else if (a == 3) 
            {
                printUsers();
            } 
            else if (a == 4) 
            {
                cout << "sampai jumpa!";
                break;
            } 
        } catch (int error) {
            
        }
    }
    return 0;
}

