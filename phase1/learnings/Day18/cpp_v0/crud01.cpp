#include <iostream>
#include <iomanip>

using namespace std;

// *****Const.h*****
// Constants
const int MAX_BOOKINGS = 100;
// *****BookingManager.h*****
void createBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &numBookings);
void displayBookings(const int booking_ids[], const int ticket_amounts[], const int food_amounts[], int numBookings);
int findBookingIndexById(const int booking_ids[], int numBookings, int id);
void editBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int numBookings);
void deleteBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &numBookings);

// *****Menu.h*****
void printMenu();

// *****Main.cpp*****

int main() {
    // Arrays to hold booking details
    int booking_ids[MAX_BOOKINGS] = {0};
    int ticket_amounts[MAX_BOOKINGS] = {0};
    int food_amounts[MAX_BOOKINGS] = {0};
    int numBookings = 0; // Counter for current bookings

    int choice; // User's menu choice

    do {
        printMenu(); // Display menu
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu-driven functionality
        switch (choice) {
            case 1:
                createBooking(booking_ids, ticket_amounts, food_amounts, numBookings);
                break;
            case 2:
                displayBookings(booking_ids, ticket_amounts, food_amounts, numBookings);
                break;
            case 3:
                editBooking(booking_ids, ticket_amounts, food_amounts, numBookings);
                break;
            case 4:
                deleteBooking(booking_ids, ticket_amounts, food_amounts, numBookings);
                break;
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
 * @param booking_ids Array of booking IDs.
 * @param ticket_amounts Array of ticket amounts.
 * @param food_amounts Array of food amounts.
 * @param numBookings Current number of bookings (will be incremented).
 */
void createBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &numBookings) {
    if (numBookings >= MAX_BOOKINGS) {
        cout << "Error: Maximum booking limit reached.\n";
        return;
    }

    int id, ticketAmount, foodAmount;

    cout << "Enter Booking ID: ";
    cin >> id;

    // Ensure booking ID is unique
    if (findBookingIndexById(booking_ids, numBookings, id) != -1) {
        cout << "Error: Booking ID already exists. Please use a unique ID.\n";
        return;
    }

    cout << "Enter Ticket Amount: ";
    cin >> ticketAmount;
    cout << "Enter Food Amount: ";
    cin >> foodAmount;

    // Store the booking details
    booking_ids[numBookings] = id;
    ticket_amounts[numBookings] = ticketAmount;
    food_amounts[numBookings] = foodAmount;
    numBookings++;

    cout << "Booking created successfully.\n";
}

/**
 * @brief Displays all existing bookings in a tabular format.
 * @param booking_ids Array of booking IDs.
 * @param ticket_amounts Array of ticket amounts.
 * @param food_amounts Array of food amounts.
 * @param numBookings Current number of bookings.
 */
void displayBookings(const int booking_ids[], const int ticket_amounts[], const int food_amounts[], int numBookings) {
    if (numBookings == 0) {
        cout << "No bookings available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "| Booking ID | Ticket Amount | Food Amount    |\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < numBookings; i++) {
        cout << "| " << setw(10) << booking_ids[i] << " | "
             << setw(13) << ticket_amounts[i] << " | "
             << setw(12) << food_amounts[i] << " |\n";
    }
    cout << "------------------------------------------------\n";
}

/**
 * @brief Finds the index of a booking by ID.
 * @param booking_ids Array of booking IDs.
 * @param numBookings Current number of bookings.
 * @param id Booking ID to search for.
 * @return Index of the booking if found, -1 otherwise.
 */
int findBookingIndexById(const int booking_ids[], int numBookings, int id) {
    for (int i = 0; i < numBookings; i++) {
        if (booking_ids[i] == id) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Edits an existing booking by ID.
 * @param booking_ids Array of booking IDs.
 * @param ticket_amounts Array of ticket amounts.
 * @param food_amounts Array of food amounts.
 * @param numBookings Current number of bookings.
 */
void editBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int numBookings) {
    int id;
    cout << "Enter Booking ID to edit: ";
    cin >> id;

    int index = findBookingIndexById(booking_ids, numBookings, id);
    if (index == -1) {
        cout << "Error: Booking ID not found.\n";
        return;
    }

    cout << "Current Details - Ticket Amount: " << ticket_amounts[index] 
         << ", Food Amount: " << food_amounts[index] << "\n";

    cout << "Enter New Ticket Amount: ";
    cin >> ticket_amounts[index];
    cout << "Enter New Food Amount: ";
    cin >> food_amounts[index];

    cout << "Booking updated successfully.\n";
}

/**
 * @brief Deletes an existing booking by ID.
 * @param booking_ids Array of booking IDs.
 * @param ticket_amounts Array of ticket amounts.
 * @param food_amounts Array of food amounts.
 * @param numBookings Current number of bookings (will be decremented).
 */
void deleteBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &numBookings) {
    int id;
    cout << "Enter Booking ID to delete: ";
    cin >> id;

    int index = findBookingIndexById(booking_ids, numBookings, id);
    if (index == -1) {
        cout << "Error: Booking ID not found.\n";
        return;
    }

    // Shift data to fill the gap
    for (int i = index; i < numBookings - 1; i++) {
        booking_ids[i] = booking_ids[i + 1];
        ticket_amounts[i] = ticket_amounts[i + 1];
        food_amounts[i] = food_amounts[i + 1];
    }
    numBookings--;

    cout << "Booking deleted successfully.\n";
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