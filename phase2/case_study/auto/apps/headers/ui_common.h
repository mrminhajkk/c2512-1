#pragma once
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
        };

        Input in;
};

extern UiCommon uiCommon;