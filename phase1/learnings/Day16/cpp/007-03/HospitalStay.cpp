#include <string>

#include "HospitalStay.h"

using std::string;

//friends
bool StayComparison::Equals(const HospitalStay& first, const HospitalStay& second)
{
    return (first.NumberOfDays == second.NumberOfDays);
}

bool StayComparison::NotEquals(const HospitalStay& first, const HospitalStay& second)
{
    return (first.NumberOfDays != second.NumberOfDays);
}

bool StayComparison::GreaterThan(const HospitalStay& first, const HospitalStay& second)
{
    return (first.NumberOfDays > second.NumberOfDays);
}

bool StayComparison::GreaterThanEquals(const HospitalStay& first, const HospitalStay& second)
{
    return (first.NumberOfDays >= second.NumberOfDays);
}

bool StayComparison::LessThan(const HospitalStay& first, const HospitalStay& second)
{
    return (first.NumberOfDays < second.NumberOfDays);
}

bool StayComparison::LessThanEquals(const HospitalStay& first, const HospitalStay& second)
{
    return (first.NumberOfDays <= second.NumberOfDays);
}

//constructor
HospitalStay::HospitalStay(string p_StayID, int p_NumberOfDays)
{
    StayID = p_StayID;
    NumberOfDays = p_NumberOfDays;
}

