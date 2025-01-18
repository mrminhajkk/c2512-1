#pragma once
#include<ui_settings.h>
#include<string>
#include<iostream>

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
            std::cout << "Press any key to continuee..."; 
            std::cin.get();
            if(beforeNumber) {
                std::cin.get();
            }
        }
};

extern UiCommon uiCommon;