#include<iostream>
#include<thread>
#include<shared_mutex>
#include<mutex>
#include<chrono>
#include<vector>
long TIMES = 5000000L;
long count = 0;

std::shared_mutex mt;

void counter() {
    for(long I = 1; I <= TIMES; I++) {
        {
            std::unique_lock<std::shared_mutex> lock(mt);
            count++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void displayCount(int id) {
    for(long I = 1; I <= TIMES; I++) {
        {
            std::shared_lock<std::shared_mutex> lock(mt);
            std::cout << "At " << id << ":" << count << std::endl; 
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}



int main() {
    std::thread thrCounter(counter);
    std::vector<std::thread> thrDisplays;
    for(int I = 1; I <= 3; I++) {
        //thrDisplays.push_back(std::thread(displayCount, 101))
        thrDisplays.emplace_back(displayCount, 100 + I);
    }
    
    /*std::thread thrDisplay1(displayCount, 101);
    std::thread thrDisplay2(displayCount, 102);
    std::thread thrDisplay3(displayCount, 103);
    */
    
    thrCounter.join();
    for(int I = 1; I <= 3; I++) {
        thrDisplays[I].join();
    }
    /*
    thrDisplay1.join();
    thrDisplay2.join();
    thrDisplay3.join();
    */
    return 0;
}