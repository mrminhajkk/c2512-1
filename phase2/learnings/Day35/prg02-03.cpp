// using anonymous pipe 
//      reading : sun pipe (read pipe)      : roomOne to roomTwo 
//      writing : moon pipe (write pipe)    : roomTwo to roomOne
// chat app : develop 
// roomOne, roomTwo | roomOne is initiator 
// strategy: [a] two childs [b] parent-child [c] two prcoesses 
// single word based communication 
#include<iostream>
#include<unistd.h>
#include<cstring>
#include <sys/wait.h>
#include <fstream>

void roomOne(int& moonReadFd, int& sunWriteFd) {
    while(true) {
        char text[1024];
        std::cout << "(roomOne app) roomOne:"; std::cin >> text;
        write(sunWriteFd, text, strlen(text) + 1);
        if(strcmp(text, "END") == 0) {
            break;
        }
        //roomTwo waiting....
        read(moonReadFd, text, 1024);
        std::cout << "(roomOne app) roomTwo:" << text << std::endl;
        if(strcmp(text, "END") == 0) {
            break;
        }
    }
    close(sunWriteFd);
    close(moonReadFd);
}

void roomTwo(int& sunReadFd, int& moonWriteFd) {
    while(true) {
        char text[1024];
        //roomOne waiting....
        read(sunReadFd, text, 1024);
        std::cout << "(roomTwo app) roomOne:" << text << std::endl;
        if(strcmp(text, "END") == 0) {
            break;
        }
        //
        std::cout << "(roomTwo app) roomTwo:"; std::cin >> text;
        write(moonWriteFd, text, strlen(text) + 1);
        if(strcmp(text, "END") == 0) {
            break;
        }        
    }
    close(moonWriteFd);
    close(sunReadFd);
}

int testTwoChilds() {
    std::cout << "----------------------Two Childs---------------------------" << std::endl;
    int sun_fd[2];
    int moon_fd[2];
    if(pipe(sun_fd) == -1 || pipe(moon_fd)==-1) {
        perror("pipe");
        std::cout << "Pipes cannot be created" << std::endl;
        return 1;
    }

    auto& [sun_read_fd, sun_write_fd] = sun_fd;
    auto& [moon_read_fd, moon_write_fd] = moon_fd;

    pid_t pid = -1;
    {
        pid = fork(); 
        if(0 == pid) {
            close(moon_write_fd);
            close(sun_read_fd);
            roomOne(moon_read_fd, sun_write_fd);
            return 0;
        }
    }

    {
        pid = fork(); 
        if(0 == pid) {
            close(sun_write_fd);
            close(moon_read_fd);
            roomTwo(sun_read_fd, moon_write_fd);
            return 0;
        }
    }

    wait(nullptr);
    return 0;
}
int testParentChild() {
    std::cout << "----------------------Parent Child---------------------------" << std::endl;
    int sun_fd[2];
    int moon_fd[2];
    if(pipe(sun_fd) == -1 || pipe(moon_fd)==-1) {
        perror("pipe");
        std::cout << "Pipes cannot be created" << std::endl;
        return 1;
    }

    auto& [sun_read_fd, sun_write_fd] = sun_fd;
    auto& [moon_read_fd, moon_write_fd] = moon_fd;

    pid_t pid = -1;
    {
        pid = fork(); 
        if(0 == pid) {
            close(sun_write_fd);
            close(moon_read_fd);
            roomTwo(sun_read_fd, moon_write_fd);   
            return 0;
        }
    }

    close(moon_write_fd);
    close(sun_read_fd);
    roomOne(moon_read_fd, sun_write_fd);
           
    wait(nullptr);

    return 0;
}
int testProcesses() {
    std::cout << "----------------------Two Processes (Run Room Rwo First)---------------------------" << std::endl;
    std::cout << "!!!           NOT WORKING AS EXPECTED                         " << std::endl;
    int choice;
    std::cout << "1-Room One\n2-Room Two\nYour Choice:"; std::cin >> choice;

    int sun_fd[2];
    int moon_fd[2];

    if(choice == 1) {        
        int sun_read_fd {}, sun_write_fd {};
        int moon_read_fd {}, moon_write_fd {};

        std::ifstream input("pipe.txt"); 
        input >> sun_read_fd;
        input >> sun_write_fd;
        input >> moon_read_fd;
        input >> moon_write_fd;
        input.close();

        close(moon_write_fd);
        close(sun_read_fd);
        roomOne(moon_read_fd, sun_write_fd);
    } else {
        if(pipe(sun_fd) == -1 || pipe(moon_fd)==-1) {
            perror("pipe");
            std::cout << "Pipes cannot be created" << std::endl;
            return 1;
        }

        auto& [sun_read_fd, sun_write_fd] = sun_fd;
        auto& [moon_read_fd, moon_write_fd] = moon_fd;

        std::ofstream out("pipe.txt",std::ios::trunc); 
        out << sun_read_fd << std::endl;
        out << sun_write_fd << std::endl;
        out << moon_read_fd << std::endl;
        out << moon_write_fd << std::endl;
        out.close();        

        close(sun_write_fd);
        close(moon_read_fd);
        roomTwo(sun_read_fd, moon_write_fd);
    }
    wait(nullptr);
    return 0;
}
int main() {
    int menu;
    std::cout << "1-Two Child Process\n2-Parent and Child Process\n3-Two Process\nYour Choice:"; std::cin >> menu;

    switch(menu) {
        case 1: testTwoChilds(); break;
        case 2: testParentChild(); break;
        case 3: testProcesses(); break;
    }
    
    return 0;
}

