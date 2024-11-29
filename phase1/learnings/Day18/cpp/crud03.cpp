#include <iostream>
#include <iomanip>

using namespace std;

// *****Const.h*****
// Constants
const int MAX_BOOKINGS = 100;
// *****Booking.h*****
class Booking {
    friend class BookingManager;
    private:
        int id;
        int ticketAmount;
        int foodAmount;
};
// *****BookingManager.h*****
class BookingManager {
    private:
        // attributes
        Booking bookings[MAX_BOOKINGS];    
        int numBookings;
    public:
        // support
        int findIndexById(int id);
        // behaviours
        void create();
        void displayAll();
        void editById();
        void deleteById();
        //
        BookingManager();
};
// *****Menu.h*****
void printMenu();

// *****Main.cpp*****

int main() {
    BookingManager manager;
   
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

// *****BookingManager.cpp*****
/**
 * @brief Creates a new booking and stores details in arrays. 
 */
void BookingManager::create() {
    if (numBookings >= MAX_BOOKINGS) {
        cout << "Error: Maximum booking limit reached.\n";
        return;
    }

    int id, ticketAmount, foodAmount;

    cout << "Enter Booking ID: ";
    cin >> id;

    // Ensure booking ID is unique
    if (findIndexById(id) != -1) {
        cout << "Error: Booking ID already exists. Please use a unique ID.\n";
        return;
    }

    cout << "Enter Ticket Amount: ";
    cin >> ticketAmount;
    cout << "Enter Food Amount: ";
    cin >> foodAmount;

    // Store the booking details
    bookings[numBookings].id = id;
    bookings[numBookings].ticketAmount = ticketAmount;
    bookings[numBookings].foodAmount = foodAmount;
    numBookings++;

    cout << "Booking created successfully.\n";
}

/**
 * @brief Displays all existing bookings in a tabular format.
 */
void BookingManager::displayAll() {
    if (numBookings == 0) {
        cout << "No bookings available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "| Booking ID | Ticket Amount | Food Amount    |\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < numBookings; i++) {
        cout << "| " << setw(10) << bookings[i].id << " | "
             << setw(13) << bookings[i].ticketAmount << " | "
             << setw(12) << bookings[i].foodAmount << " |\n";
    }
    cout << "------------------------------------------------\n";
}

/**
 * @brief Finds the index of a booking by ID.
 * @param id Booking ID to search for.
 * @return Index of the booking if found, -1 otherwise.
 */
int BookingManager::findIndexById(int id) {
    for (int i = 0; i < numBookings; i++) {
        if (bookings[i].id == id) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Edits an existing booking by ID.
 */
void BookingManager::editById() {
    int id;
    cout << "Enter Booking ID to edit: ";
    cin >> id;

    int index = findIndexById(id);
    if (index == -1) {
        cout << "Error: Booking ID not found.\n";
        return;
    }

    cout << "Current Details - Ticket Amount: " << bookings[index].ticketAmount 
         << ", Food Amount: " << bookings[index].foodAmount << "\n";

    cout << "Enter New Ticket Amount: ";
    cin >> bookings[index].ticketAmount;
    cout << "Enter New Food Amount: ";
    cin >> bookings[index].foodAmount;

    cout << "Booking updated successfully.\n";
}

/**
 * @brief Deletes an existing booking by ID.
 */
void BookingManager::deleteById() {
    int id;
    cout << "Enter Booking ID to delete: ";
    cin >> id;

    int index = findIndexById(id);
    if (index == -1) {
        cout << "Error: Booking ID not found.\n";
        return;
    }

    // Shift data to fill the gap
    for (int i = index; i < numBookings - 1; i++) {
        bookings[i] = bookings[i + 1];
    }
    numBookings--;

    cout << "Booking deleted successfully.\n";
}

BookingManager::BookingManager() {
    numBookings = 0;
}
// *****Menu.cpp*****
void printMenu() {
    cout << "\n=== Movie Ticket Booking Management System ===\n";
    cout << "1. Create Booking\n";
    cout << "2. Display All Bookings\n";
    cout << "3. Edit Booking\n";
    cout << "4. Delete Booking\n";
    cout << "5. Exit\n";
}