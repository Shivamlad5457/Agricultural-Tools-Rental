#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Farmers {
    string name;
    string mobNo;
    int pin;
    int area;
    int toolStock[5] = {10, 10, 10, 10, 10};
    vector<string> rentedTools;

public:
    void personInfo() {
        cout << "Enter Your Name: ";
        cin >> name;

        while (true) {
            cout << "Enter Your Mobile Number: ";
            cin >> mobNo;

            bool isValid = mobNo.length() == 10;
            for (char c : mobNo) {
                if (!isdigit(c)) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) break;
            else cout << "Invalid mobile number. Please enter a 10-digit number only." << endl;
        }
        cout << "Enter Your Pin Code: ";
        cin >> pin;
        cout << "Enter your Area (in guntha): ";
        cin >> area;
    }

    void displayTool() {
        cout << "\nAvailable Tools are:\n";
        cout << "1- Tractor (90/guntha) Stock: " << toolStock[0] << "\n";
        cout << "2- Plough (60/guntha) Stock: " << toolStock[1] << "\n";
        cout << "3- Seeder (70/guntha) Stock: " << toolStock[2] << "\n";
        cout << "4- Harvester (72/guntha) Stock: " << toolStock[3] << "\n";
        cout << "5- Sprayer (60/guntha) Stock: " << toolStock[4] << "\n";
    }

    void rentTool() {
        int choice;
        cout << "\nEnter Tool ID: ";
        cin >> choice;


        if (choice >= 1 && choice <= 5) {
            if (toolStock[choice - 1] > 0) {
                toolStock[choice - 1]--;
                string rentedToolName;
                int cost = 0;

                switch (choice) {
                    case 1: rentedToolName = "Tractor"; cost = area * 90; break;
                    case 2: rentedToolName = "Plough"; cost = area * 60; break;
                    case 3: rentedToolName = "Seeder"; cost = area * 70; break;
                    case 4: rentedToolName = "Harvester"; cost = area * 72; break;
                    case 5: rentedToolName = "Sprayer"; cost = area * 60; break;
                }

                rentedTools.push_back(rentedToolName);
                cout << "\nYou have successfully rented " << rentedToolName;
                cout << "\nTotal Cost: " << cost << "\n";

                time_t now = time(0);
                char* dt = ctime(&now);
                cout << "Rental Date and Time: " << dt;
            } else {
                cout << "Sorry, the selected tool is out of stock.\n";
            }
        } else {
            cout << "Incorrect Choice\n";
        }
    }

    void displayRentedTools() {
        cout << name << " has rented " << rentedTools.size() << " tools:\n";
        if (rentedTools.empty()) {
            cout << "No tools rented yet.\n";
        } else {
            for (const string &tool : rentedTools) {
                cout << "- " << tool << "\n";
            }
        }
    }
};


int main() {
    vector<Farmers> customers;
    int choice;

    while (true) {
        cout << "\n1. Display Available Tools";
        cout << "\n2. Rent a Tool";
        cout << "\n3. Display Rented Tools";
        cout << "\n4. Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                if (!customers.empty()) {
                    customers.back().displayTool();
                } else {
                    Farmers temp;
                    temp.displayTool();
                }
                break;
            }
            case 2: {
                Farmers newCustomer;
                newCustomer.personInfo();
                newCustomer.displayTool();
                newCustomer.rentTool();
                customers.push_back(newCustomer);
                break;
            }
            case 3: {
                if (customers.empty()) {
                    cout << "No rentals have been made yet.\n";
                } else {
                    for (Farmers &customer : customers) {
                        customer.displayRentedTools();
                    }
                }
                break;
            }
            case 4: exit(0);
            default: cout << "Incorrect Choice\n";
        }
    }
    return 0;
}