#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <unordered_map>
#include <vector>
#include <string>
#include "University.h"

class UserManager; // Forward declaration of the UserManager class

class UserInterface {
public:
    void mainMenu();
    void logoutUser();
    UserInterface(UserManager& userManager); // Constructor
    ~UserInterface(); // Destructor
    void createUserAccount();
    void loginUser();
    void modifyPassword();
    void loginAdmin();
    void displayRegisteredMenu(); // Updated function declaration

private:
    UserManager& userManager; // Reference to the UserManager object
    BaseUser* loggedInUser;
};

#endif
