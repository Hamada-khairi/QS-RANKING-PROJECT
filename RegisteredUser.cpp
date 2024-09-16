// RegisteredUser.cpp

#include "RegisteredUser.h"
#include <iostream>
#include "University.h"

RegisteredUser::RegisteredUser(const std::string& username, const std::string& password)
    : BaseUser(username, password), loggedIn(false) {}

void RegisteredUser::setLoggedIn(bool value) {
    loggedIn = value;
}

std::string RegisteredUser::getPassword() {
    return password; // Assuming 'password' is a member variable of the BaseUser class
}


void RegisteredUser::addUniversityFeedback(University& university, const std::string& feedback) {
    feedbacks.push_back(std::make_pair(&university, feedback));
    university.addFeedback(feedback);
}

void RegisteredUser::viewFeedbacks() {
    if (feedbacks.empty()) {
        std::cout << "No feedbacks found.\n";
    }
    else {
        std::cout << "Feedbacks:\n";
        for (int i = 0; i < feedbacks.size(); ++i) {
            std::cout << i + 1 << ". University: " << feedbacks[i].first->getName() << std::endl;
            std::cout << "   Feedback: " << feedbacks[i].second << std::endl;
        }
    }
}

void RegisteredUser::deleteFeedback(int index) {
    if (index >= 1 && index <= feedbacks.size()) {
        feedbacks.erase(feedbacks.begin() + index - 1);
        std::cout << "Feedback deleted.\n";
    }
    else {
        std::cout << "Invalid feedback index.\n";
    }
}

University* result = nullptr;
void RegisteredUser::displayRegisteredMenu(UserInterface& ui, UserManager& userManager) {
    University* result = nullptr;

    while (loggedIn) {
        std::cout << "\n\n";
        std::cout << "================================================\n";
        std::cout << "============  Welcome to Customer Menu =========\n";
        std::cout << "================================================\n";
        std::cout << "\n";

        std::cout << "  1. Display all universities' information\n";
        std::cout << "  2. Sort universities\n";
        std::cout << "  3. Search university details\n";
        std::cout << "  4. Add universities to favorite\n";
        std::cout << "  5. View favorite universities\n";
        std::cout << "  6. Delete favorite universities\n";
        std::cout << "  7. Add Feedback on University\n";
        std::cout << "  8. View Feedbacks\n";
        std::cout << "  9. Delete Feedback\n";
        std::cout << "  0. Back to Main Menu\n";

        std::cout << "\n";
        std::cout << "================================================\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline character

        std::string universityName;

        switch (choice) {
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
            std::cout << "Enter university name to add to favorites: ";
            std::getline(std::cin, universityName);

            result = University::searchUniversityByNameLinear(universityName);
            if (result) {
                userManager.addFavoriteUniversity(this, *result);
                std::cout << "University added to favorites.\n";
            }
            else {
                std::cout << "University not found.\n";
            }
            break;
        case 5:
        {
            std::vector<University> favoriteUniversities = userManager.getFavoriteUniversities(this);
            if (favoriteUniversities.empty()) {
                std::cout << "No favorite universities found.\n";
            }
            else {
                std::cout << "Favorite universities:\n";
                for (const University& university : favoriteUniversities) {
                    std::cout << "Name: " << university.getName() << std::endl;
                    // Display other university details
                    std::cout << "-------------------------" << std::endl;
                }
            }
            break;
        }
        case 6:
        {
            std::vector<University> favoriteUniversities = userManager.getFavoriteUniversities(this);
            if (favoriteUniversities.empty()) {
                std::cout << "No favorite universities found.\n";
            }
            else {
                std::cout << "Favorite universities:\n";
                for (int i = 0; i < favoriteUniversities.size(); ++i) {
                    std::cout << i + 1 << ". " << favoriteUniversities[i].getName() << std::endl;
                }
                std::cout << "Enter the index of the university to delete: ";
                int index;
                std::cin >> index;
                std::cin.ignore(); // Consume the newline character

                if (index >= 1 && index <= favoriteUniversities.size()) {
                    University& universityToDelete = favoriteUniversities[index - 1];
                    userManager.deleteFavoriteUniversity(this, universityToDelete);
                    std::cout << "University deleted from favorites.\n";
                }
                else {
                    std::cout << "Invalid university index.\n";
                }
            }
            break;
        }
        case 7:
        {
            std::cout << "Enter university name to add feedback: ";
            std::getline(std::cin, universityName);

            result = University::searchUniversityByNameLinear(universityName);
            if (result) {
                std::cout << "Enter your feedback: ";
                std::string feedback;
                std::getline(std::cin, feedback);

                addUniversityFeedback(*result, feedback);
                std::cout << "Feedback added to the university.\n";
            }
            else {
                std::cout << "University not found.\n";
            }
            break;
        }
        case 8:
            viewFeedbacks();
            break;
        case 9:
            std::cout << "Enter the index of the feedback to delete: ";
            int index;
            std::cin >> index;
            deleteFeedback(index);
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


bool RegisteredUser::isLoggedIn() const {
    return loggedIn;
}
