#include<iostream>

#include"./../headers/floor_main.h"
#include"./../headers/ui_common.h"

class Controller { 
    public: 
        void Create() {
            uiCommon.TitleBar("Admin App > Floor Management > Create Floor");
            uiCommon.PressAnyKey(true);        
        }

        void Edit() {

        }

        void Delete() {

        }

        void DisplayAll() {

        }
};

int ReadFloorMenu() {
    int choice;
    
    uiCommon.TitleBar("Admin App > Floor Management");

    std::cout << "1 - Create Floor" << std::endl;
    std::cout << "2 - Edit Floor" << std::endl;
    std::cout << "3 - Delete Floor" << std::endl;
    std::cout << "4 - Display All Floors" << std::endl;
    std::cout << "5 - Go Back" << std::endl;
    std::cout << "Your choice:"; std::cin >> choice;
    
    uiCommon.Line('~');

    return choice;
}

void ManageFloor() { 
    int choice;

    do { 
        choice = ReadFloorMenu();
        switch(choice) {
            case 1:
                {
                    // controller.Create();
                } break;
            case 2:
                {
                    // controller.DisplayOne();
                } break;
            case 3:
                {
                    // controller.DisplayAll();
                } break;
            case 4:
                {

                } break;
        }
    } while(5 != choice);
}