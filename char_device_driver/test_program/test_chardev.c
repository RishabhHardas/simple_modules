#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    static int fd = 0;
    int ret = 0;

    char buff[16] = {0};

    //open char device
    fd = open("/dev/hello_char", O_RDWR);
    if (fd == -1) {
        printf("Failed to open device!\n");
    }

    //Read the char device
    ret = read(fd, buff, 10);

    //write to the device
    ret = write(fd, "Hello", 6);

    //close device
    close(fd);
}
