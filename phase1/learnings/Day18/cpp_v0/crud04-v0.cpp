#include <iostream>
#include <iomanip>

using namespace std;

// *****Const.h*****
// Constants
const int MAX_HOSPITAL_STAYS = 100;
// *****HospitalStay.h*****
class HospitalStay {
    friend class HospitalStayManager;
    private:
        string StayID;
        int NumberOfDays;
};
// *****HospitalStayManager.h*****
class HospitalStayManager {
    private:
        // attributes
        HospitalStay stays[MAX_HOSPITAL_STAYS];    
        int numHospitalStays;
    public:
        // support
        int findIndexById(string StayID);
        // behaviours
        void create();
        void displayAll();
        void editById();
        void deleteById();
        //
        HospitalStayManager();
};
// *****Menu.h*****
void printMenu();

// *****Main.cpp*****

int main() {
    HospitalStayManager manager;
   
    int choice; // User's menu choice

    do {
        printMenu(); // Display menu
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu-driven functionality
        switch (choice) {
            case 1: manager.create();    break;
            case 2: manager.displayAll();  break;
            case 3: manager.editById();      break;
            case 4: manager.deleteById();    break;
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}

// *****HospitalStayManager.cpp*****
/**
 * @brief Creates a new hospital stay and stores details in arrays. 
 */
void HospitalStayManager::create() {
    if (numHospitalStays >= MAX_HOSPITAL_STAYS) {
        cout << "Error: Maximum hospital stay limit reached.\n";
        return;
    }

    string StayID;
    int NumberOfDays;

    cout << "Enter HospitalStay STAYID: ";
    cin >> StayID;

    // Ensure hospital stay STAYID is unique
    if (findIndexById(StayID) != -1) {
        cout << "Error: HospitalStay STAYID already exists. Please use a unique STAYID.\n";
        return;
    }

    cout << "Enter Number Of Days: ";
    cin >> NumberOfDays;

    // Store the hospital stay details
    stays[numHospitalStays].StayID = StayID;
    stays[numHospitalStays].NumberOfDays = NumberOfDays;
    numHospitalStays++;

    cout << "HospitalStay created successfully.\n";
}

/**
 * @brief Displays all existing stays in a tabular format.
 */
void HospitalStayManager::displayAll() {
    if (numHospitalStays == 0) {
        cout << "No stays available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "|   STAYID | Number Of Days                    |\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < numHospitalStays; i++) {
        cout << "| " << setw(10) << stays[i].StayID << " | "
             << setw(13) << stays[i].NumberOfDays << " |\n";
    }
    cout << "------------------------------------------------\n";
}

/**
 * @brief Finds the index of a hospital stay by STAYID.
 * @param StayID HospitalStay STAYID to search for.
 * @return Index of the hospital stay if found, -1 otherwise.
 */
int HospitalStayManager::findIndexById(string StayID) {
    for (int i = 0; i < numHospitalStays; i++) {
        if (stays[i].StayID == StayID) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Edits an existing hospital stay by STAYID.
 */
void HospitalStayManager::editById() {
    string StayID;
    cout << "Enter HospitalStay STAYID to edit: ";
    cin >> StayID;

    int index = findIndexById(StayID);
    if (index == -1) {
        cout << "Error: HospitalStay STAYID not found.\n";
        return;
    }

    cout << "Current Details - Number Of Days: " << stays[index].NumberOfDays << "\n";

    cout << "Enter New Number Of Days: ";
    cin >> stays[index].NumberOfDays;

    cout << "HospitalStay updated successfully.\n";
}

/**
 * @brief Deletes an existing hospital stay by STAYID.
 */
void HospitalStayManager::deleteById() {
    string StayID;
    cout << "Enter HospitalStay STAYID to delete: ";
    cin >> StayID;

    int index = findIndexById(StayID);
    if (index == -1) {
        cout << "Error: HospitalStay STAYID not found.\n";
        return;
    }

    // Shift data to fill the gap
    for (int i = index; i < numHospitalStays - 1; i++) {
        stays[i] = stays[i + 1];
    }
    numHospitalStays--;

    cout << "HospitalStay deleted successfully.\n";
}

HospitalStayManager::HospitalStayManager() {
    numHospitalStays = 0;
}
// *****Menu.cpp*****
void printMenu() {
    cout << "\n=== Hospital Stay Management Module ===\n";
    cout << "1. Create Hospital Stay\n";
    cout << "2. Display All Hospital Stays\n";
    cout << "3. Edit Hospital Stay\n";
    cout << "4. Delete Hospital Stay\n";
    cout << "5. Exit\n";
}