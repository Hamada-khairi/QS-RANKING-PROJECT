// UserManager.cpp

#include "UserManager.h"
#include "RegisteredUser.h" // Include the RegisteredUser.h header

UserManager::UserManager() {}

UserManager::~UserManager() {
    for (auto& user : users) {
        delete user.second;
    }
}

void UserManager::addUser(BaseUser* user) {
    users[user->getUsername()] = user;
}

BaseUser* UserManager::findUser(const std::string& username) const {
    if (users.count(username) > 0) {
        return users.at(username);
    }
    return nullptr;
}

void UserManager::modifyPassword(BaseUser* user, const std::string& newPassword) {
    user->setPassword(newPassword);
}

void UserManager::addFavoriteUniversity(RegisteredUser* user, const University& university) {
    favoriteLists[user->getUsername()].push_back(university);
}

std::vector<University> UserManager::getFavoriteUniversities(BaseUser* user) {
    return favoriteLists[user->getUsername()];
}

void UserManager::deleteFavoriteUniversity(RegisteredUser* user, const University& university) {
    std::vector<University>& favoriteUniversities = favoriteLists[user->getUsername()];

    for (auto it = favoriteUniversities.begin(); it != favoriteUniversities.end(); ++it) {
        if (*it == university) {
            favoriteUniversities.erase(it);
            break;
        }
    }
}


std::vector<BaseUser*> UserManager::getAllUsers() {
    std::vector<BaseUser*> allUsers;
    for (const auto& user : users) {
        allUsers.push_back(user.second);
    }
    return allUsers;
}