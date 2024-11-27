#include <iostream>
#include <string>

#include "HospitalStay.h"
#include "ArrayOperations.h"

int main() {
    HospitalStay HospitalStays[] = {
        HospitalStay("D001", 15),
        HospitalStay("D002", 10),
        HospitalStay("D003", 20),
        HospitalStay("D004", 25),
        HospitalStay("D005", 18)
    };

    int n = sizeof(HospitalStays) / sizeof(HospitalStays[0]);
    
    std::cout << "HospitalStay with Min Stay: " << HospitalStays[findMinStay(HospitalStays, n)].GetStayID() << " with NumberOfDays " << HospitalStays[findMinStay(HospitalStays, n)].GetNumberOfDays() << std::endl;
    std::cout << "HospitalStay with Max Stay: " << HospitalStays[findMaxStay(HospitalStays, n)].GetStayID() << " with NumberOfDays " << HospitalStays[findMaxStay(HospitalStays, n)].GetNumberOfDays() << std::endl;
    std::cout << "HospitalStay with 2nd Min Stay: " << HospitalStays[findSecondMinStay(HospitalStays, n)].GetStayID() << " with NumberOfDays " << HospitalStays[findSecondMinStay(HospitalStays, n)].GetNumberOfDays() << std::endl;
    std::cout << "HospitalStay with 2nd Max Stay: " << HospitalStays[findSecondMaxStay(HospitalStays, n)].GetStayID() << " with NumberOfDays " << HospitalStays[findSecondMaxStay(HospitalStays, n)].GetNumberOfDays() << std::endl;

    return 0;
}


/*

### Example Output:
```
HospitalStay with Min Stay: D002 with NumberOfDays 10
HospitalStay with Max Stay: D004 with NumberOfDays 25
HospitalStay with 2nd Min Stay: D001 with NumberOfDays 15
HospitalStay with 2nd Max Stay: D003 with NumberOfDays 20
```

*/