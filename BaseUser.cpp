//BaseUser.cpp

#include "BaseUser.h"

BaseUser::BaseUser(const std::string& username, const std::string& password)
    : username(username), password(password) {}

BaseUser::~BaseUser() {}

std::string BaseUser::getUsername() const {
    return username;
}

void BaseUser::setPassword(const std::string& newPassword) {
    password = newPassword;
}

bool BaseUser::authenticate(const std::string& inputPassword) const {
    return password == inputPassword;
}