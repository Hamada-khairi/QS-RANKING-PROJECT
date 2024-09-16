// UserManager.h

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "BaseUser.h"
#include "University.h"
#include <string>
#include <iostream>
#include <unordered_map>

// Forward declaration
class RegisteredUser;

class UserManager {
private:
    std::unordered_map<std::string, BaseUser*> users;
    std::unordered_map<std::string, std::vector<University>> favoriteLists; // Store favorite universities for each user

public:
    UserManager();
    ~UserManager();

    void addUser(BaseUser* user);
    BaseUser* findUser(const std::string& username) const;
    void modifyPassword(BaseUser* user, const std::string& newPassword);
    void deleteFavoriteUniversity(RegisteredUser* user, const University& university);

    std::vector<BaseUser*> getAllUsers(); // Retrieve all users from the user manager


    void addFavoriteUniversity(RegisteredUser* user, const University& university);
    std::vector<University> getFavoriteUniversities(BaseUser* user);
};

#endif
