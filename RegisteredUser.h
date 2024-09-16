//RegisteredUser.h

#ifndef REGISTEREDUSER_H
#define REGISTEREDUSER_H

#include "BaseUser.h"
#include <iostream>
#include "BaseUser.h"

#include "University.h"
#include "UserInterface.h"
#include "DataSeeder.h"
#include "SortAndSearch.h"
#include "UserManager.h"
#include <string>


 // Forward declaration

class RegisteredUser : public BaseUser {
public:
    RegisteredUser(const std::string& username, const std::string& password);
    void setLoggedIn(bool value);
    void displayRegisteredMenu(UserInterface& ui, UserManager& userManager);

    
    std::string getPassword(); // Get the password of the user

    void addUniversityFeedback(University& university, const std::string& feedback);
    void viewFeedbacks();
    void deleteFeedback(int index);
    bool isLoggedIn() const; // Add this member function
    
private:
    
    bool loggedIn; // Flag to track the login status
    std::vector<std::pair<University*, std::string>> feedbacks;
    // Other member functions and variables
   

};

#endif  // REGISTEREDUSER_H
