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
    return 0;
}
int testProcesses() {
    return 0;
}
int main() {
    return testTwoChilds();
}

