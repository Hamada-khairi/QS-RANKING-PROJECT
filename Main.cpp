//main.cpp 

// Include necessary header files
#include "BaseUser.h"
#include "RegisteredUser.h"
#include "AdminUser.h"
#include "University.h"
#include "UserInterface.h"
#include "DataSeeder.h"
#include "SortAndSearch.h"
#include "UserManager.h"



#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
#include <string> 

using namespace std::chrono;
using namespace std;

tm* default_time = new tm;
string tm2string(tm* time) {
    string hour = to_string(time->tm_hour);
    string min = to_string(time->tm_min);
    string sec = to_string(time->tm_sec);
    string year = to_string(time->tm_year + 1900);
    string month = to_string(time->tm_mon + 1);
    string day = to_string(time->tm_mday);
    return day + "/" + month + "/" + year + "-" + hour + ":" + min + ":" + sec;
}

string tm2string(tm*);

int main()
{
    // Load the data from the CSV file
    DataSeeder::loadData();

    // Check if data is loaded correctly
    if (DataSeeder::getUniversities().empty()) {
        std::cerr << "Error: No university data loaded.\n";
        return -1;
    }

    UserManager userManager;  // Create a UserManager object
    UserInterface ui(userManager);

    int choice;
    while (true)
    {
        ui.mainMenu();

        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            displayAllUniversities();
            break;
        case 2:
            SortMenu();
            break;
        case 3:
            SearchMenu();
            break;
        case 4:
            ui.createUserAccount();
            break;
        case 5:
            ui.loginUser();
            break;
        case 6:
            ui.loginAdmin();
            break;
        case 0:
            return 0;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
    }

    return 0;
}

