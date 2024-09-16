//BaseUser.h
#ifndef BASEUSER_H
#define BASEUSER_H

#include <string>

class BaseUser {
protected:
    std::string username;
    std::string password;

public:
    BaseUser(const std::string& username, const std::string& password);
    virtual ~BaseUser();

    std::string getUsername() const;
    void setPassword(const std::string& newPassword);
    bool authenticate(const std::string& inputPassword) const;
    

};

#endif
