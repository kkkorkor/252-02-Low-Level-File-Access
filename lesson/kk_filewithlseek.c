#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h> //for open()
#include <sys/stat.h> 

int main(){
    int in, out;
    char buffer[512]; //keep data temporary 512 bytes
    ssize_t nread; //#bytes that actually read

    in = open("file.in", O_RDONLY|O_CREAT, S_IRUSR);
    if(in == -1){
        perror("open");
        return 1;
    }

    nread = read(in, buffer, nread);
    if(nread == -1){
        perror("read");
        return 1;
    }

    write(out, buffer, nread); //write data in file

    printf("Read file successful\n");
    close(in);

}