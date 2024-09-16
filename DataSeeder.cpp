//DataSeeder.cpp

#include "DataSeeder.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<University> DataSeeder::universities;

std::vector<University>& DataSeeder::loadData() {
    std::ifstream file("data.csv");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return universities;
    }

    universities.clear();

    std::string line;
    std::getline(file, line);  // Skip the header line

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        University university;

        try {
            std::getline(iss, token, ',');
            university.rank = (token.empty() ? 0 : std::stoi(token));
            std::getline(iss, university.name, ',');
            std::getline(iss, university.locationCode, ',');
            std::getline(iss, university.location, ',');

            std::vector<double> scores;
            std::vector<int> ranks;

            for (int i = 0; i < 13; i++) {
                std::getline(iss, token, ',');
                if (token.empty() || token == "-" || token == "NA" || token == "601+") {
                    scores.push_back(0.0);
                    ranks.push_back(0);
                }
                else {
                    scores.push_back(std::stod(token));
                    std::getline(iss, token, ',');
                    if (token.empty() || token == "-" || token == "NA" || token == "601+") {
                        ranks.push_back(0);
                    }
                    else {
                        ranks.push_back(std::stoi(token));
                    }
                }
            }

            university.arScore = scores[0];
            university.arRank = ranks[0];
            university.erScore = scores[1];
            university.erRank = ranks[1];
            university.fsrScore = scores[2];
            university.fsrRank = ranks[2];
            university.cpfScore = scores[3];
            university.cpfRank = ranks[3];
            university.ifrScore = scores[4];
            university.ifrRank = ranks[4];
            university.isrScore = scores[5];
            university.isrRank = ranks[5];
            university.irnScore = scores[6];
            university.irnRank = ranks[6];
            university.gerScore = scores[7];
            university.gerRank = ranks[7];
            university.scoreScaled = scores[8];
        }
        catch (const std::invalid_argument& e) {
            //std::cerr << "Error: Invalid data in line: " << line << std::endl;
            continue;
        }
        catch (const std::exception& e) {
            //std::cerr << "An exception occurred: " << e.what() << '\n';
            continue;
        }

        universities.push_back(university);
    }

    file.close();

    return universities;
}

std::vector<University>& DataSeeder::getUniversities() {
    return universities;
}
