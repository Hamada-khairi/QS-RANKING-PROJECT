// AdminUser.cpp

#include "AdminUser.h"
#include <iostream>


AdminUser::AdminUser(const std::string& username, const std::string& password)
    : BaseUser(username, password), loggedIn(false) {}

void AdminUser::setLoggedIn(bool value) {
    loggedIn = value;
}

void AdminUser::displayCustomersDetails(UserManager& userManager) {
    std::cout << "Customers' details:\n";

    // Retrieve all users from the user manager
    std::vector<BaseUser*> users = userManager.getAllUsers();

    // Display each customer's details
    for (BaseUser* user : users) {
        // Check if the user is a registered customer
        RegisteredUser* registeredUser = dynamic_cast<RegisteredUser*>(user);
        if (registeredUser) {
            std::cout << "Username: " << registeredUser->getUsername() << std::endl;
            std::cout << "Password: " << registeredUser->getPassword() << std::endl;
            // Display other customer details
            std::cout << "-------------------------" << std::endl;
        }
    }
}

void AdminUser::modifyCustomerDetails(UserManager& userManager) {
    std::string username;
    std::cout << "Enter the username of the customer to modify: ";
    std::getline(std::cin, username);

    // Find the user in the user manager
    BaseUser* user = userManager.findUser(username);
    if (user) {
        // Check if the user is a registered customer
        RegisteredUser* registeredUser = dynamic_cast<RegisteredUser*>(user);
        if (registeredUser) {
            // Perform modifications on the customer's details
            // For example, modify username or password
            // ui.modifyCustomerDetails(registeredUser);
        }
        else {
            std::cout << "User is not a registered customer.\n";
        }
    }
    else {
        std::cout << "User not found.\n";
    }
}

void AdminUser::deleteInactiveCustomers(UserManager& userManager) {
    // Get all users from the user manager
    std::vector<BaseUser*> users = userManager.getAllUsers();

    // Iterate over the users and delete inactive customers
    for (auto it = users.begin(); it != users.end(); ) {
        RegisteredUser* registeredUser = dynamic_cast<RegisteredUser*>(*it);
        if (registeredUser && !registeredUser->isLoggedIn()) {
            // Delete the customer from the user manager
            it = users.erase(it);
            delete registeredUser;
        }
        else {
            ++it;
        }
    }

    std::cout << "Inactive customers deleted.\n";
}

void AdminUser::readFeedbacks(UserManager& userManager) {
    std::cout << "Feedbacks:\n";

    // Retrieve all users from the user manager
    std::vector<BaseUser*> users = userManager.getAllUsers();

    // Iterate over the users and read their feedbacks
    for (BaseUser* user : users) {
        // Check if the user is a registered customer
        RegisteredUser* registeredUser = dynamic_cast<RegisteredUser*>(user);
        if (registeredUser) {
            std::cout << "Username: " << registeredUser->getUsername() << std::endl;

            // Retrieve the favorite universities of the customer
            std::vector<University> favoriteUniversities = userManager.getFavoriteUniversities(registeredUser);

            // Display the feedbacks for each favorite university
            for (const University& university : favoriteUniversities) {
                std::cout << "University: " << university.getName() << std::endl;
                std::cout << "Feedbacks:\n";
                std::vector<std::string> feedbacks = university.getFeedbacks();
                for (const std::string& feedback : feedbacks) {
                    std::cout << "- " << feedback << std::endl;
                }
                std::cout << "-------------------------" << std::endl;
            }
        }
    }
}

void AdminUser::replyFeedback(UserManager& userManager) {
    std::string username;
    std::cout << "Enter the username of the customer to reply to: ";
    std::getline(std::cin, username);

    // Find the user in the user manager
    BaseUser* user = userManager.findUser(username);
    if (user) {
        // Check if the user is a registered customer
        RegisteredUser* registeredUser = dynamic_cast<RegisteredUser*>(user);
        if (registeredUser) {
            // Retrieve the favorite universities of the customer
            std::vector<University> favoriteUniversities = userManager.getFavoriteUniversities(registeredUser);

            // Display the feedbacks for each favorite university
            for (University& university : favoriteUniversities) {
                std::cout << "University: " << university.getName() << std::endl;
                std::cout << "Feedbacks:\n";
                std::vector<std::string> feedbacks = university.getFeedbacks();

                for (const std::string& feedback : feedbacks) {
                    std::cout << "- " << feedback << std::endl;
                }

                // Prompt the admin to enter a reply for each feedback
                std::string reply;
                std::cout << "Enter a reply to the feedback: ";
                std::getline(std::cin, reply);

                // Store the admin's reply
                university.addReply(reply);

                std::cout << "Reply added.\n";
                std::cout << "-------------------------" << std::endl;
            }
        }
        else {
            std::cout << "User is not a registered customer.\n";
        }
    }
    else {
        std::cout << "User not found.\n";
    }
}


void AdminUser::generateTopPreferredUniversitiesReport(UserManager& userManager) {
    std::cout << "Top 10 Preferred Universities Report:\n";

    // Retrieve all users from the user manager
    std::vector<BaseUser*> users = userManager.getAllUsers();

    // Map to store the count of each university
    std::unordered_map<std::string, int> universityCounts;

    // Iterate over the users and count the preferred universities
    for (BaseUser* user : users) {
        // Check if the user is a registered customer
        RegisteredUser* registeredUser = dynamic_cast<RegisteredUser*>(user);
        if (registeredUser) {
            // Retrieve the favorite universities of the customer
            std::vector<University> favoriteUniversities = userManager.getFavoriteUniversities(registeredUser);

            // Increment the count for each university
            for (const University& university : favoriteUniversities) {
                universityCounts[university.getName()]++;
            }
        }
    }

    // Sort the universities based on their counts in descending order
    std::vector<std::pair<std::string, int>> sortedUniversities(
        universityCounts.begin(),
        universityCounts.end()
    );
    std::sort(sortedUniversities.begin(), sortedUniversities.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second;
        }
    );

    // Display the top 10 preferred universities
    int count = 0;
    for (const auto& pair : sortedUniversities) {
        if (count >= 10) {
            break;
        }
        std::cout << "University: " << pair.first << std::endl;
        std::cout << "Count: " << pair.second << std::endl;
        std::cout << "-------------------------" << std::endl;
        count++;
    }
}

void AdminUser::displayAdminMenu(UserInterface& ui, UserManager& userManager) {
    while (loggedIn) {
        std::cout << "\n\n";
        std::cout << "================================================\n";
        std::cout << "=======  Welcome to Admin User Menu  ==========\n";
        std::cout << "================================================\n";
        std::cout << "\n";

        std::cout << "  1. Display all customers' details\n";
        std::cout << "  2. Modify a customer's details\n";
        std::cout << "  3. Delete inactive customers\n";
        std::cout << "  4. Read feedbacks\n";
        std::cout << "  5. Reply to feedback\n";
        std::cout << "  6. Generate report for Top 10 preferred universities\n";
        std::cout << "  0. Back to Main Menu\n";

        std::cout << "\n";
        std::cout << "================================================\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline character

        switch (choice) {
        case 1:
            displayCustomersDetails(userManager);
            break;
        case 2:
            modifyCustomerDetails(userManager);
            break;
        case 3:
            deleteInactiveCustomers(userManager);
            break;
        case 4:
            readFeedbacks(userManager);
            break;
        case 5:
            replyFeedback(userManager);
            break;
        case 6:
            generateTopPreferredUniversitiesReport(userManager);
            break;
        case 0:
            ui.logoutUser();
            return;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
    }
}
