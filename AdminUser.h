// AdminUser.h

#ifndef ADMINUSER_H
#define ADMINUSER_H
#include <iostream>
#include "UserInterface.h"
#include "BaseUser.h"
#include "UserManager.h"
#include "University.h"
#include "RegisteredUser.h"

class AdminUser : public BaseUser {
public:
    AdminUser(const std::string& username, const std::string& password);
    void setLoggedIn(bool value);
    void displayAdminMenu(UserInterface& ui, UserManager& userManager);

private:
    bool loggedIn;

    void displayCustomersDetails(UserManager& userManager);
    void modifyCustomerDetails(UserManager& userManager);
    void deleteInactiveCustomers(UserManager& userManager);
    void readFeedbacks(UserManager& userManager);
    void replyFeedback(UserManager& userManager);
    void generateTopPreferredUniversitiesReport(UserManager& userManager);
};

#endif // ADMINUSER_H
