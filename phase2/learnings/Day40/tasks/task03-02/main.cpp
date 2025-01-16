// array of doctors
// IPC client-server communcation
//      client: requests the findSum of array of doctors (each doctor is of fixed sized) 
//      server: 
//          request: receives array of doctors
//          response:sends sum
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unistd.h>
#include <cstring>

using identity_t = char[20];//std::string;
using years_t = short;
using field_size_t = short;

class Doctor {
    private:
        identity_t id;
        years_t yearsOfExperience;
    public: 
        Doctor(const identity_t id, years_t yearsOfExperience) : yearsOfExperience(yearsOfExperience) { 
            strcpy(this->id, id);
        }
        years_t getYearsOfExperience() { return this->yearsOfExperience; }
};

years_t findSum(std::vector<Doctor>& doctors) {
    years_t sum = 0;
    for(auto doctor : doctors) {
        sum += doctor.getYearsOfExperience();
    }
    return sum;
}

void server(int read_pipe_fd, int write_pipe_fd)
{
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];

    read(read_pipe_fd, buffer, BUFFER_SIZE);
    field_size_t size;
    memcpy((char*)&size, buffer, sizeof(field_size_t));
    std::vector<Doctor> doctors(size, Doctor("",0));
    memcpy((char*)(doctors.data()), (char*)(buffer + sizeof(field_size_t)),sizeof(Doctor)*size);
    
    years_t sum = findSum(doctors); 
    memcpy(buffer, (char*)(&sum), sizeof(years_t));
    write(write_pipe_fd, buffer, BUFFER_SIZE);

    close(read_pipe_fd);
    close(write_pipe_fd);
}

void client(std::vector<Doctor>& doctors, int read_pipe_fd, int write_pipe_fd)
{
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];

    field_size_t size = doctors.size();    
    memcpy(buffer, (char*)(&size), sizeof(field_size_t));    
    memcpy(buffer + sizeof(field_size_t), (char*)(doctors.data()), sizeof(Doctor) * size);
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