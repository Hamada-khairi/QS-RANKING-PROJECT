//DataSeeder.h
#ifndef DATASEEDER_H
#define DATASEEDER_H

#include <vector>
#include "University.h"

class DataSeeder {
public:
    static std::vector<University>& loadData();
    static std::vector<University>& getUniversities();

private:
    static std::vector<University> universities;
};

#endif
