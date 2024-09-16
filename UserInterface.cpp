//UserInterface.cpp

#include "UserInterface.h"
#include <iostream>
#include "AdminUser.h"
#include "SortAndSearch.h"
#include "BaseUser.h"
#include "RegisteredUser.h"
#include "UserManager.h"
#include "University.h"










void UserInterface::mainMenu() {
    std::cout << "\n\n";
    std::cout << "================================================\n";
    std::cout << "=====  Welcome to Hamada QSRanking Program =====\n";
    std::cout << "================================================\n";
    std::cout << "\n";

    std::cout << "=================== Main Menu ==================\n";
    std::cout << "  1. Display all universities' information\n";
    std::cout << "  2. Sort universities\n";
    std::cout << "  3. Search university details\n";
    std::cout << "  4. Register as customer\n";
    std::cout << "  5. Login as registered customer\n";
    std::cout << "  6. Login as Admin\n";
    std::cout << "  0. Exit program\n";

    std::cout << "\n";
    std::cout << "================================================\n";
    std::cout << "Enter your choice: ";
}

void UserInterface::logoutUser() {
    loggedInUser = nullptr;
    mainMenu();
}

UserInterface::UserInterface(UserManager& userManager) : userManager(userManager), loggedInUser(nullptr) {}

UserInterface::~UserInterface() {}

void UserInterface::createUserAccount() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (userManager.findUser(username)) {
        std::cout << "Username already exists. Please choose a different username.\n";
    }
    else {
        BaseUser* newUser = new RegisteredUser(username, password);
        userManager.addUser(newUser);
        std::cout << "User account created successfully.\n";
    }
}

void UserInterface::loginUser() {
    if (loggedInUser) {
        std::cout << "You are already logged in as " << loggedInUser->getUsername() << ".\n";
        return;
    }

    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    BaseUser* user = userManager.findUser(username);
    if (user && user->authenticate(password)) {
        loggedInUser = user;
        RegisteredUser* registeredUser = dynamic_cast<RegisteredUser*>(user);
        if (registeredUser) {
            registeredUser->setLoggedIn(true);
            std::cout << "Login successful.\n";
            registeredUser->displayRegisteredMenu(*this, userManager);
        }
    }
    else {
        std::cout << "Invalid username or password. Login failed.\n";
    }
}

void UserInterface::modifyPassword() {
    if (!loggedInUser) {
        std::cout << "You must be logged in to modify your password.\n";
        return;
    }

    std::string newPassword;
    std::cout << "Enter new password: ";
    std::cin >> newPassword;
    userManager.modifyPassword(loggedInUser, newPassword);
    std::cout << "Password modified successfully.\n";
}

void UserInterface::loginAdmin() {
    std::cout << "Enter your login details:\n";
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (username == "admin" && password == "123") {
        // Admin login successful
        std::cout << "Login successful.\n";

        AdminUser admin("admin", "123"); // Create an instance of the AdminUser class
        admin.setLoggedIn(true); // Set the admin as logged in

        std::cout << "Admin Menu:\n";

        // Pass the userManager object to the displayAdminMenu function
        admin.displayAdminMenu(*this, userManager);
    }
    else {
        std::cout << "Invalid username or password.\n";
    }
}


void UserInterface::displayRegisteredMenu() {
    if (loggedInUser) {
        RegisteredUser* registeredUser = dynamic_cast<RegisteredUser*>(loggedInUser);
        if (registeredUser) {
            registeredUser->displayRegisteredMenu(*this, userManager);  // Pass the userManager object to displayRegisteredMenu
        }
    }
    else {
        std::cout << "You must be logged in as a registered user to access the registered menu.\n";
    }
}