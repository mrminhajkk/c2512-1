#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unistd.h>
#include <cstring>

using identity_t = std::string;
using years_t = short;
using field_size_t = short;

class Doctor {
    private:
        identity_t id;
        years_t yearsOfExperience;
    public: 
        Doctor(identity_t id, years_t yearsOfExperience) : id(id), yearsOfExperience(yearsOfExperience) { }
        years_t getYearsOfExperience() { return this->yearsOfExperience; }
};

years_t findSum(years_t* years, field_size_t size) {
    years_t sum = 0;
    for(int I = 0; I < size; I++) {
        sum += years[I];
    }
    return sum;
}

void server(int read_pipe_fd, int write_pipe_fd)
{
    const int BUFFER_SIZE = 1024;
    int buffer[BUFFER_SIZE];

    read(read_pipe_fd, buffer, BUFFER_SIZE);
    field_size_t size;
    memcpy((char*)&size, buffer, sizeof(field_size_t));
    years_t years[size];
    memcpy((char*)years, (char*)(buffer + sizeof(field_size_t)),sizeof(years_t)*size);
    
    years_t sum = findSum(years, size); 
    memcpy(buffer, (char*)(&sum), sizeof(years_t));
    write(write_pipe_fd, buffer, BUFFER_SIZE);

    close(read_pipe_fd);
    close(write_pipe_fd);
}

void client(std::vector<Doctor>& doctors, int read_pipe_fd, int write_pipe_fd)
{
    const int BUFFER_SIZE = 1024;
    int buffer[BUFFER_SIZE];

    field_size_t size = doctors.size();
    years_t years[size];
    
    for(int I = 0; I < size; I++) {
        years[I++] = doctors[I].getYearsOfExperience();
    }
    
    memcpy(buffer, (char*)(&size), sizeof(field_size_t));    
    memcpy(buffer + sizeof(field_size_t), (char*)(years), sizeof(years_t) * size);
    write(write_pipe_fd, buffer, BUFFER_SIZE);

    years_t sum; 
    read(read_pipe_fd, buffer, BUFFER_SIZE);
    memcpy((char*)(&sum), buffer, sizeof(years_t));

    close(write_pipe_fd);
    close(read_pipe_fd);

    std::cout << "sum = " << sum << std::endl;
}

int main() {
    std::vector<Doctor> doctors {        
        Doctor("D001", 5),
        Doctor("D002", 4),
        Doctor("D003", 3),
        Doctor("D004", 2),
        Doctor("D005", 1)
    };

    int client_to_server_fd[2];
    int server_to_client_fd[2];

    if(pipe(client_to_server_fd) == -1 || 
       pipe(server_to_client_fd) == -1) {
        std::cout << "pipe error" << std::endl;
        return 1;
    }

    auto& [server_read_pipe_fd, client_write_pipe_fd] = client_to_server_fd;
    auto& [client_read_pipe_fd, server_write_pipe_fd] = server_to_client_fd;

    pid_t pid = -1;
    {
        pid = fork();
        if(0 == pid) {
            close(server_write_pipe_fd);
            close(server_read_pipe_fd);
            client(doctors, client_read_pipe_fd, client_write_pipe_fd);
            return 0;
        }
    }

    close(client_read_pipe_fd);
    close(client_write_pipe_fd);
    server(server_read_pipe_fd, server_write_pipe_fd);
    return 0;
}