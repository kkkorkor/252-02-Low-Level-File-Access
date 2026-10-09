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

    out = open("file.out", O_WRONLY|O_CREAT, S_IWOTH);

    while( nread = read(in, buffer, sizeof(buffer)) > 0 ){
        ssize_t written = 0;
        while(written < nread){
            ssize_t n = write(out, buffer + written, nread - written); //write data in file
            if(n <= 0){
                perror("write");
                close(in);
                close(out);
                return 1;
            }

            written += n;             
        }
        

    }
    printf("Read file successful\n");
    
    //find size of file using lseek
    off_t fileSize; //off_t is var that keep file's size
    lseek(in, 0, SEEK_END); //go to EOF, cuz it will tell all #byte fron start
    printf("file.in  size = %lld\n", (long long)fileSize); //%lld - long long is also long but more #byte

    

    
    close(in);

}