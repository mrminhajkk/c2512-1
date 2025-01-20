#include "user_main.h"  // Include the header file to define the class and methods
#include "./../headers/ui_common.h"  // Assuming ui_common.h is where uiCommon is defined
#include <cstdlib>
#include <ctime>
#include <regex>

// Define the static methods in the UserController class

void UserController::Read(std::string& name,
                           std::string& email,
                           std::string& phone,
                           std::string& password,
                           std::string& confirmPassword,
                           std::string& carNumber,
                           std::string& carModel,
                           std::string& carType) {
    name = uiCommon.in.Str("Enter name:");

    do {
        email = uiCommon.in.Str("Enter email:");

        // Simulate 1/10 probability for "Email already exists"
        if (std::rand() % 10 == 0) {
            std::cout << "Email already exists. Please try again." << std::endl;
            continue;
        }

        std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        if (std::regex_match(email, emailRegex)) {
            break;
        }
        std::cout << "Invalid email format. Please try again." << std::endl;
    } while (true);

    do {
        phone = uiCommon.in.Str("Enter phone number:");
        std::regex phoneRegex(R"(^\d{10}$)");
        if (std::regex_match(phone, phoneRegex)) {
            break;
        }
        std::cout << "Invalid phone number. It should be 10 digits." << std::endl;
    } while (true);

    do {
        password = uiCommon.in.Str("Enter password:");
        confirmPassword = uiCommon.in.Str("Confirm password:");
        if (password == confirmPassword) {
            break;
        }
        std::cout << "Passwords do not match. Please try again." << std::endl;
    } while (true);

    carNumber = uiCommon.in.Str("Enter car number:");
    carModel = uiCommon.in.Str("Enter car model:");
    carType = uiCommon.in.Str("Enter car type (e.g., SUV, Sedan):");
}

void UserController::DisplayAndEdit(std::string& name,
                                    std::string& email,
                                    std::string& phone,
                                    std::string& password,
                                    std::string& carNumber,
                                    std::string& carModel,
                                    std::string& carType) {
    int choice;
    do {
        // Display current details
        std::cout << "\nCurrent Details:" << std::endl;
        std::cout << "1 - Name: " << name << std::endl;
        std::cout << "2 - Email: " << email << std::endl;
        std::cout << "4 - Phone: " << phone << std::endl;
        std::cout << "8 - Password: " << password << std::endl;
        std::cout << "16 - Car Number: " << carNumber << std::endl;
        std::cout << "32 - Car Model: " << carModel << std::endl;
        std::cout << "64 - Car Type: " << carType << std::endl;
        std::cout << "\nEnter the sum of option numbers to edit (e.g., 3 to edit Name and Password):" << std::endl;

        choice = uiCommon.in.Int("Enter the combination of options you want to edit (or 0 to finish): ");

        if (choice == 0) {
            std::cout << "Finished editing details." << std::endl;
            break;
        }

        // Process the options using bitwise operations
        if (choice & 1) { // Check if Name is selected (1)
            name = uiCommon.in.Str("Enter new name:");
        }
        if (choice & 2) { // Check if Email is selected (2)
            email = uiCommon.in.Str("Enter new email:");
        }
        if (choice & 4) { // Check if Phone is selected (4)
            phone = uiCommon.in.Str("Enter new phone number:");
        }
        if (choice & 8) { // Check if Password is selected (8)
            password = uiCommon.in.Str("Enter new password:");
        }
        if (choice & 16) { // Check if Car Number is selected (16)
            carNumber = uiCommon.in.Str("Enter new car number:");
        }
        if (choice & 32) { // Check if Car Model is selected (32)
            carModel = uiCommon.in.Str("Enter new car model:");
        }
        if (choice & 64) { // Check if Car Type is selected (64)
            carType = uiCommon.in.Str("Enter new car type (e.g., SUV, Sedan):");
        }

    } while (choice != 0);
}

void UserController::Create() {
    uiCommon.TitleBar("User Registration");

    std::string name, email, phone, password, confirmPassword, carNumber, carModel, carType;

    // Read user details
    Read(name, email, phone, password, confirmPassword, carNumber, carModel, carType);

    // Display and allow editing of details
    DisplayAndEdit(name, email, phone, password, carNumber, carModel, carType);

    // Save the user details (logic for saving can be implemented here)
    std::cout << "\nUser is registered successfully with the following details:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Car Number: " << carNumber << std::endl;
    std::cout << "Car Model: " << carModel << std::endl;
    std::cout << "Car Type: " << carType << std::endl;

    uiCommon.PressAnyKey(true);
}
void ManageUser() {
    std::srand(std::time(nullptr)); // Seed the random number generator
    UserController controller;
    controller.Create(); // Directly invoke the Create function for user registration
}#include<iostream>
#include<sstream>
#include<string>

#include"./../headers/admin_main.h"
#include"./../headers/ui_common.h"

class AdminController { 
    public: 
        static void Read(std::string& name,
            std::string& email,
            std::string& password,
            std::string& phone,
            int role, 
            int flags = 31) {

            
            if((flags & 1) != 0) {
                name = uiCommon.in.Str("Enter name:");
            }

            if((flags & 2) != 0) {
                do {
                    email = uiCommon.in.Str("Enter email:");
                    if(!uiCommon.in.exist()) {
                        break;
                    }
                    std::cout << "Email exist." << std::endl;
                } while(true);
            }
            if((flags & 4) != 0) {
                password = uiCommon.in.Str("Enter password:");
            }
            if((flags & 8) != 0) {
                phone = uiCommon.in.Str("Enter phone:");
            }
            if((flags & 16) != 0) {
                role = 1; // 1 - admin
            }
        }

        void Create() {
            uiCommon.TitleBar("Admin App > Admin Management > Create admin");
            int flags = 31;
            std::string name;
            std::string email;
            std::string password;
            std::string phone;
            int role = 0; 
            
            do {
                Read(name, email, password, phone, role, flags);
                int proceedOption; 

                std::stringstream soutput; 
                soutput << "1 - edit `name`." << std::endl; 
                soutput << "2 - edit `email`." << std::endl; 
                soutput << "4 - edit `password`." << std::endl; 
                soutput << "8 - edit `phone`." << std::endl; 
                soutput << "3 - edit `phone` and `email`." << std::endl; 
                soutput << "91 - Proceed to create admin." << std::endl;
                soutput << "\tYour choice:"; 
                proceedOption = uiCommon.in.Int(soutput.str());

                if(91 == proceedOption) {
                    //set to biz object
                    break;
                }
                flags = proceedOption;
            } while(true);
            std::cout << "Admin is created successfully." << std::endl;
            uiCommon.PressAnyKey(true);        
        }

        void Edit() {
            uiCommon.TitleBar("Admin App > Admin Management > Edit Admin");
            uiCommon.PressAnyKey(true); 
        }

        void Delete() {
            uiCommon.TitleBar("Admin App > Admin Management > Delete Admin");
            uiCommon.PressAnyKey(true); 
        }

        void DisplayAll() {
            uiCommon.TitleBar("Admin App > Admin Management > List of Admins");
            uiCommon.PressAnyKey(true); 
        }
};

static int ReadAdminMenu() {
    int choice;
    
    uiCommon.TitleBar("Admin App > Admin Management");

    std::stringstream soutput;
    soutput << "1 - Create Admin" << std::endl;
    soutput << "2 - Edit Admin" << std::endl;
    soutput << "3 - Delete Admin" << std::endl;
    soutput << "4 - Display All Admins" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void ManageAdmin() { 
    AdminController controller;
    
    int choice;

    do { 
        choice = ReadAdminMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
                controller.Delete();
            } break;
            case 4: {
                controller.DisplayAll();
            } break;
        }
    } while(99 != choice);
}#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "./../headers/app_main.h"
#include "./../headers/user_main.h"
#include "./../headers/admin_main.h"

UiCommon uiCommon;

// Simulated user data
std::unordered_map<std::string, std::string> userCredentials = {
    {"admin", "admin123"}, // Admin credentials
    {"user", "user123"}    // User credentials
};

// Function to validate login credentials
std::string ValidateLogin(const std::string& name, const std::string& password) {
    auto it = userCredentials.find(name);
    if (it != userCredentials.end() && it->second == password) {
        return name == "admin" ? "admin" : "user";
    }
    return "";
}

// Function to display the app menu
static int ReadAppMenu() {
    int choice;

    uiCommon.TitleBar("Driver App");

    std::stringstream soutput;
    soutput << "1 - Driver Registration" << std::endl;
    soutput << "2 - Login" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:";
    choice = uiCommon.in.Int(soutput.str());

    uiCommon.Line('~');
    uiCommon.PressAnyKey(true);
    return choice;
}

// Function to manage the app
void ManageApp() {
    int choice;

    do {
        choice = ReadAppMenu();
        switch (choice) {
            case 1: { // Driver Registration
                ManageUser();
            } break;

            case 2: { // Login
                std::string name, password;

                uiCommon.TitleBar("Login");
                std::cout << "Enter Name: ";
                std::cin >> name;
                std::cout << "Enter Password: ";
                std::cin >> password;

                std::string role = ValidateLogin(name, password);

                if (role == "admin") {
                    std::cout << "Login successful! Redirecting to Admin Dashboard..." << std::endl;
                    ManageAdmin();
                } else if (role == "user") {
                    std::cout << "Login successful! Redirecting to User Dashboard..." << std::endl;
                    ManageUser();
                } else {
                    std::cout << "Invalid credentials. Please try again." << std::endl;
                }

                uiCommon.PressAnyKey(true);
            } break;

            case 99: {
                std::cout << "Exiting the application. Goodbye!" << std::endl;
            } break;

            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
            } break;
        }
    } while (choice != 99);
}

// Entry point for the app
void AppMain() {
    ManageApp();
}#include<iostream>
#include<sstream>
#include<string>

#include"./../headers/floor_main.h"
#include"./../headers/ui_common.h"

class FloorController { 
    public: 
        static void Read(std::string& floorNumber, int flags = 3) {
            if((flags & 1) != 0) {
                std::cout << "Floor Number:"; std::cin >> floorNumber;
            }
        }

        void Create() {
            uiCommon.TitleBar("Admin App > Floor Management > Create floor");
            int flags = 3;
            std::string floorNumber;
            
            do {
                Read(floorNumber, flags);
                int proceedOption; 

                std::stringstream soutput; 
                soutput << "1 - edit `floor number`." << std::endl; 
                soutput << "91 - Proceed to create floor." << std::endl;
                soutput << "\tYour choice:"; 
                proceedOption = uiCommon.in.Int(soutput.str());

                if(91 == proceedOption) {
                    //set to biz object
                    break;
                }
                flags = proceedOption;
            } while(true);
            std::cout << "Floor is created successfully." << std::endl;
            uiCommon.PressAnyKey(true);        
        }

        void Edit() {
            uiCommon.TitleBar("Admin App > Floor Management > Edit floor");
            uiCommon.PressAnyKey(true); 
        }

        void Delete() {
            uiCommon.TitleBar("Admin App > Floor Management > Delete floor");
            uiCommon.PressAnyKey(true); 
        }

        void DisplayAll() {
            uiCommon.TitleBar("Admin App > Floor Management > List of floors");
            uiCommon.PressAnyKey(true); 
        }
};

static int ReadFloorMenu() {
    int choice;
    
    uiCommon.TitleBar("Admin App > Floor Management");

    std::stringstream soutput;
    soutput << "1 - Create Floor" << std::endl;
    soutput << "2 - Edit Floor" << std::endl;
    soutput << "3 - Delete Floor" << std::endl;
    soutput << "4 - Display All Floors" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void ManageFloor() { 
    FloorController controller;
    
    int choice;

    do { 
        choice = ReadFloorMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
                controller.Delete();
            } break;
            case 4: {
                controller.DisplayAll();
            } break;
        }
    } while(99 != choice);
}