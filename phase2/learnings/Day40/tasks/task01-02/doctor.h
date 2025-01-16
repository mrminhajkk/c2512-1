#pragma once
#include "type.h"
class Doctor {
    private:
        identity_t id;
        years_t yearsOfExperience;
    public: 
        Doctor(identity_t id, years_t yearsOfExperience) : id(id), yearsOfExperience(yearsOfExperience) { }
        years_t getYearsOfExperience() { return this->yearsOfExperience; }
};