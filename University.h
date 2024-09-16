//University.h

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono> // For measuring execution time
#include <algorithm>
#include <iostream>
#include "BaseUser.h"

struct University {
    int rank;
    std::string name;
    std::string locationCode;
    std::string location;
    double arScore;
    int arRank;
    double erScore;
    int erRank;
    double fsrScore;
    int fsrRank;
    double cpfScore;
    int cpfRank;
    double ifrScore;
    std::string ifrRank;
    double isrScore;
    int isrRank;
    double irnScore;
    int irnRank;
    double gerScore;
    int gerRank;
    double scoreScaled;

    std::string getName() const;
    static University* searchUniversityByNameBinary(const std::string& name);
    static University* searchUniversityByNameLinear(const std::string& name); // Function declaration
    bool operator==(const University& other) const;
    void addFeedback(const std::string& feedback);
    std::vector<std::string> getFeedbacks() const;

    void addReply(const std::string& reply);


private:
    std::vector<std::string> feedbacks;

};

void displayAllUniversities(); // Function declaration

void sortUniversities();
void SearchMenu();


University* searchUniversityByRankLinear(int rank);

University* searchUniversityByRankBinary(int rank);

#endif
