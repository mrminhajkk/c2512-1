#pragma once
#include "ui_common.h"
void AppMain();void ManageAdmin();void ManageFloor();#pragma once
#include <termios.h>
#include <unistd.h>

#include<iostream>
#include<limits>

#include<string>

#include "ui_settings.h"

class UiCommon {
    public:
        void Clear() {  
#if CLRSCR_METHOD == 1
            std::cout << "\033[2J\033[1;1H"; 
#else 
            system("clear");
#endif
        }
        void Line(char ch) {
            for(int I =0; I < 80; I++) {
                std::cout << ch;
            }
            std::cout << std::endl;
        }
        void Title(std::string title) {
            std::cout << title << std::endl;
        }
        void TitleBar(std::string title, char lineCh='-') {
            Clear();
            Line(lineCh);
            Title(title);
            Line(lineCh);
        }
        void PressAnyKey(bool beforeNumber = false) {
            std::cout << "Press any key to continue..."; 
            std::cin.get();
            if(beforeNumber) {
                std::cin.get();
            }
        }

        class Input {
            public:
                Input() {
                    srand(static_cast<unsigned>(time(0)));
                }
                std::string Str(std::string caption = "") {
                    std::cout << caption;

                    std::string str;
                    std::cin >> str;
                    return str;
                }
                int Int(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stoi(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Int(caption);
                    }
                }
                float Float(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stof(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Float(caption);
                    }
                }
                double Double(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stod(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Double(caption);
                    }
                }
                int giveMeNumber(int start, int end)
                {	
                    const int MAX_SIZE = end - start + 1;
                    int num = rand() % MAX_SIZE;
                    num += start;
                    return num;
                }
                bool exist() {
                    int num = giveMeNumber(1,10);
                    return (num == 1);
                }
        };

        Input in;
};

extern UiCommon uiCommon;#pragma once
#define CLRSCR_METHOD 2 // 1 - ANSI Escape Codes 2- system "clear"
#ifndef USER_MAIN_H
#define USER_MAIN_H

#include <string>
#include <iostream>
#include <regex>

class UserController {
public:
    // Function to read user data
    static void Read(std::string& name,
                     std::string& email,
                     std::string& phone,
                     std::string& password,
                     std::string& confirmPassword,
                     std::string& carNumber,
                     std::string& carModel,
                     std::string& carType);

    // Function to display and edit user data
    static void DisplayAndEdit(std::string& name,
                                std::string& email,
                                std::string& phone,
                                std::string& password,
                                std::string& carNumber,
                                std::string& carModel,
                                std::string& carType);

    // Function to create a user (handles registration)
    void Create();
};

#endif // USER_MAIN_H
void ManageUser();#include<iostream>
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