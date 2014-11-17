#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    const char* myFiFo = "/tmp/BLAH";

    /* create the FIFO */
    mkfifo(myFiFo, 0666);

    /* white "Hi" to the FIFO */

    fd = open(myFiFo, O_WRONLY);
    write(fd, "Monkey", sizeof("Monkey"));
    close(fd);

    /* remove the FIFO */
    unlink(myFiFo);

    return 0;
}
