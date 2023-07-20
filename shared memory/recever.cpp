#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main()
{
    // kích thu?c (trong byte) c?a shared memory object
    const int SIZE = 4096;
    // tên c?a shared memory object
    const char* name = "OS";
    // file descriptor c?a shared memory object
    int shm_fd;
    // con tr? t?i shared memory object
    void* ptr;
    // m? shared memory object
    shm_fd = shm_open(name, O_RDONLY, 0666);
    // memory map shared memory object
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    // d?c d? li?u t? shared memory object
    printf("%s\n", (char*)ptr);
    // unmap shared memory d? ti?n trình khác có th? truy c?p
    munmap(ptr, SIZE);
    return 0;
}
