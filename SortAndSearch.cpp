//SortAndSearch.cpp

#include "SortAndSearch.h"
#include "University.h" // Include the University.h header file
#include <algorithm>
#include <chrono>
#include <iostream>
#include "UserInterface.h"
#include "DataSeeder.h"
#include "RegisteredUser.h"
#include <string>
#include <vector>
#include <unordered_map> 

UserManager userManager;  // Create a UserManager object
UserInterface ui2(userManager);

// Add the declaration of displayAllUniversities function

void bubbleSortByName() {
    std::vector<University>& universityData = DataSeeder::getUniversities();
    int n = universityData.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (universityData[j].name > universityData[j + 1].name) {
                std::swap(universityData[j], universityData[j + 1]);
            }
        }
    }
}

void insertionSortByName() {
    std::vector<University>& universityData = DataSeeder::getUniversities();
    int n = universityData.size();
    for (int i = 1; i < n; i++) {
        University key = universityData[i];
        int j = i - 1;

        while (j >= 0 && universityData[j].name > key.name) {
            universityData[j + 1] = universityData[j];
            j = j - 1;
        }
        universityData[j + 1] = key;
    }
}

void insertionSortByRank() {
    std::vector<University>& universityData = DataSeeder::getUniversities();
    int n = universityData.size();
    for (int i = 1; i < n; i++) {
        University key = universityData[i];
        int j = i - 1;

        while (j >= 0 && universityData[j].rank > key.rank) {
            universityData[j + 1] = universityData[j];
            j = j - 1;
        }
        universityData[j + 1] = key;
    }
}

void bubbleSortByRank() {
    std::vector<University>& universityData = DataSeeder::getUniversities();
    int n = universityData.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (universityData[j].rank > universityData[j + 1].rank) {
                std::swap(universityData[j], universityData[j + 1]);
            }
        }
    }
}

void SortMenu()
{
    std::cout << "\n\n";
    std::cout << "======================\n";
    std::cout << "=====  Sort Menu =====\n";
    std::cout << "======================\n";
    std::cout << "\n";

    std::cout << "  1. Sort universities By Rank (Insertion Sort)\n";
    std::cout << "  2. Sort universities By Rank (Bubble Sort)\n";
    std::cout << "  3. Sort universities By Name (Insertion Sort)\n";
    std::cout << "  4. Sort universities By Name (Bubble Sort)\n";
    std::cout << "   0. Main Menu\n";

    std::cout << "\n";
    std::cout << "==================\n";
    std::cout << "Enter your choice: ";

    while (true)
    {
        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            auto start = std::chrono::steady_clock::now();
            insertionSortByRank();
            auto end = std::chrono::steady_clock::now();
            displayAllUniversities();
            std::chrono::duration<double> diff = end - start;
            std::cout << "Sorting time (Insertion Sort by Rank): " << diff.count() << " seconds" << std::endl;
            SortMenu();
        }
        break;
        case 2:
        {
            auto start = std::chrono::steady_clock::now();
            bubbleSortByRank();
            auto end = std::chrono::steady_clock::now();
            displayAllUniversities();
            std::chrono::duration<double> diff = end - start;
            std::cout << "Sorting time (Bubble Sort by Rank): " << diff.count() << " seconds" << std::endl;
            SortMenu();
        }
        break;
        case 3:
        {
            auto start = std::chrono::steady_clock::now();
            insertionSortByName();
            auto end = std::chrono::steady_clock::now();
            displayAllUniversities();
            std::chrono::duration<double> diff = end - start;
            std::cout << "Sorting time (Insertion Sort by Name): " << diff.count() << " seconds" << std::endl;
            SortMenu();
        }
        break;
        case 4:
        {
            auto start = std::chrono::steady_clock::now();
            bubbleSortByName();
            auto end = std::chrono::steady_clock::now();
            displayAllUniversities();
            std::chrono::duration<double> diff = end - start;
            std::cout << "Sorting time (Bubble Sort by Name): " << diff.count() << " seconds" << std::endl;

            SortMenu();
        }
        break;
        case 0:
            return;
                
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    SearchMenu();  // Recursive call to display the search menu again
    return;  // Exit the function after the recursive call
}
