#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd;
    const char* myFiFo = "/tmp/BLAH";
    char buffer[1024];

    /* open, read and display the message from the FIFO */
    fd = open(myFiFo, O_RDONLY);
    read(fd, buffer, 1024);
    std::cout << "They say " << buffer << " !" << std::endl;
    close(fd);

    while(true) { }

    return(0);
}
