#pragma once

#include <string>

using std::string;

class StayComparison;

class HospitalStay
{
    private:
        string StayID;
        int NumberOfDays;
    public:
        friend StayComparison;
        //constructor
        HospitalStay(string p_StayID, int p_NumberOfDays);
};

//behaviours
class StayComparison
{
    public:
        static bool Equals(const HospitalStay& first, const HospitalStay& second);
        static bool NotEquals(const HospitalStay& first, const HospitalStay& second);
        static bool GreaterThan(const HospitalStay& first, const HospitalStay& second);
        static bool GreaterThanEquals(const HospitalStay& first, const HospitalStay& second);
        static bool LessThan(const HospitalStay& first, const HospitalStay& second);
        static bool LessThanEquals(const HospitalStay& first, const HospitalStay& second);
};

// StayComparison::Equals(hs1, hs2)