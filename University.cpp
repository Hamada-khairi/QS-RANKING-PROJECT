//University.cpp

#include "University.h"
#include <iostream>
#include "DataSeeder.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "UserInterface.h"
#include "UserManager.h"

std::string University::getName() const {
    return name;
}

void sortUniversities() {
    std::vector<University>& universities = DataSeeder::getUniversities();

    std::sort(universities.begin(), universities.end(), [](const University& a, const University& b) {
        return a.name < b.name;
        });
}

void displayAllUniversities() {
    const std::vector<University>& universities = DataSeeder::getUniversities();
    for (const University& university : universities) {
        std::cout << "Name: " << university.getName() << std::endl;
        std::cout << "Location: " << university.location << std::endl;
        std::cout << "Rank: " << university.rank << std::endl;
        std::cout << "AR Score: " << university.arScore << std::endl;
        std::cout << "AR Rank: " << university.arRank << std::endl;
        std::cout << "ER Score: " << university.erScore << std::endl;
        std::cout << "ER Rank: " << university.erRank << std::endl;
        std::cout << "FSR Score: " << university.fsrScore << std::endl;
        std::cout << "FSR Rank: " << university.fsrRank << std::endl;
        std::cout << "CPF Score: " << university.cpfScore << std::endl;
        std::cout << "CPF Rank: " << university.cpfRank << std::endl;
        std::cout << "IFR Score: " << university.ifrScore << std::endl;
        std::cout << "IFR Rank: " << university.ifrRank << std::endl;
        std::cout << "ISR Score: " << university.isrScore << std::endl;
        std::cout << "ISR Rank: " << university.isrRank << std::endl;
        std::cout << "IRN Score: " << university.irnScore << std::endl;
        std::cout << "IRN Rank: " << university.irnRank << std::endl;
        std::cout << "GER Score: " << university.gerScore << std::endl;
        std::cout << "GER Rank: " << university.gerRank << std::endl;
        std::cout << "Score Scaled: " << university.scoreScaled << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}


University* University::searchUniversityByNameBinary(const std::string& name) {
    std::vector<University>& universities = DataSeeder::getUniversities();
    sortUniversities();

    int low = 0;
    int high = universities.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (universities[mid].name == name) {
            return &universities[mid];
        }
        if (universities[mid].name < name) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return nullptr; // University not found
}

University* searchUniversityByRankLinear(int rank) {
    std::vector<University>& universities = DataSeeder::getUniversities();
    for (int i = 0; i < universities.size(); ++i) {
        if (universities[i].rank == rank) {
            return &universities[i];
        }
    }
    return nullptr; // University not found
}

University* University::searchUniversityByNameLinear(const std::string& name) {
    std::vector<University>& universities = DataSeeder::getUniversities();
    for (int i = 0; i < universities.size(); ++i) {
        if (universities[i].name == name) {
            return &universities[i];
        }
    }
    return nullptr; // University not found
}

University* searchUniversityByRankBinary(int rank) {
    std::vector<University>& universities = DataSeeder::getUniversities();

    int low = 0;
    int high = universities.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (universities[mid].rank == rank) {
            return &universities[mid];
        }
        if (universities[mid].rank < rank) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return nullptr; // University not found
}

void SearchMenu() {
    int searchRank;   // Rank to be searched
    std::string searchName; // Name to be searched

    std::cout << "\n\n";
    std::cout << "========================\n";
    std::cout << "=====  Search Menu =====\n";
    std::cout << "========================\n";
    std::cout << "\n";

    std::cout << "  1. Search universities By Rank (Binary Search)\n";
    std::cout << "  2. Search universities By Rank (Linear Search)\n";
    std::cout << "  3. Search universities By Name (Binary Search)\n";
    std::cout << "  4. Search universities By Name (Linear Search)\n";
    std::cout << "  0. Main Menu\n";

    std::cout << "\n";
    std::cout << "========================\n";
    std::cout << "Enter your choice: ";

    UserManager userManager;  // Create a UserManager object
    UserInterface ui(userManager);

    while (true) {
        int choice;
        std::cin >> choice;

        if (choice < 0 || choice > 4) {
            std::cout << "Invalid option. Please try again.\n";
            continue; // This will skip the rest of the loop and go back to the beginning
        }

        switch (choice) {
        case 1:
            std::cout << "Enter Rank to Search: ";
            std::cin >> searchRank;

            {
                auto start = std::chrono::steady_clock::now();
                University* result = searchUniversityByRankBinary(searchRank);
                auto end = std::chrono::steady_clock::now();

                if (result) {
                    std::cout << "University found:\n";
                    std::cout << "Name: " << result->name << std::endl;
                    std::cout << "Location: " << result->location << std::endl;
                    std::cout << "Rank: " << result->rank << std::endl;
                }
                else {
                    std::cout << "University not found.\n";
                }

                std::cout << "Execution Time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";
                SearchMenu();
            }
            break;
        case 2:
            std::cout << "Enter Rank to Search: ";
            std::cin >> searchRank;

            {
                auto start = std::chrono::steady_clock::now();
                University* result = searchUniversityByRankLinear(searchRank);
                auto end = std::chrono::steady_clock::now();

                if (result) {
                    std::cout << "University found:\n";
                    std::cout << "Name: " << result->name << std::endl;
                    std::cout << "Location: " << result->location << std::endl;
                    std::cout << "Rank: " << result->rank << std::endl;
                }
                else {
                    std::cout << "University not found.\n";
                }

                std::cout << "Execution Time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";
                SearchMenu();
            }
            break;
        case 3:
            std::cout << "Enter Name to Search: ";
            std::cin.ignore(); // Ignore the newline character in the input buffer
            std::getline(std::cin, searchName);

            {
                auto start = std::chrono::steady_clock::now();
                University* result = University::searchUniversityByNameBinary(searchName);
                auto end = std::chrono::steady_clock::now();

                if (result) {
                    std::cout << "University found:\n";
                    std::cout << "Name: " << result->name << std::endl;
                    std::cout << "Location: " << result->location << std::endl;
                    std::cout << "Rank: " << result->rank << std::endl;
                }
                else {
                    std::cout << "University not found.\n";
                }

                std::cout << "Execution Time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";
                SearchMenu();
            }
            break;
        case 4:
            std::cout << "Enter Name to Search: ";
            std::cin.ignore(); // Ignore the newline character in the input buffer
            std::getline(std::cin, searchName);

            {
                auto start = std::chrono::steady_clock::now();
                University* result = University::searchUniversityByNameLinear(searchName);
                auto end = std::chrono::steady_clock::now();

                if (result) {
                    std::cout << "University found:\n";
                    std::cout << "Name: " << result->name << std::endl;
                    std::cout << "Location: " << result->location << std::endl;
                    std::cout << "Rank: " << result->rank << std::endl;
                }
                else {
                    std::cout << "University not found.\n";
                }

                std::cout << "Execution Time: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";
                SearchMenu();
            }
            break;
        case 0:
            return;
            
            
        }

        SearchMenu();  // Recursive call to display the search menu again
        return;  // Exit the function after the recursive call


    }
}





void University::addFeedback(const std::string& feedback) {
    feedbacks.push_back(feedback);
}

std::vector<std::string> University::getFeedbacks() const {
    return feedbacks;
}


bool University::operator==(const University& other) const {
    // Compare the universities based on some criteria (e.g., name)
    return name == other.name;
}


void University::addReply(const std::string& reply) {
    feedbacks.push_back(reply);
}

