#include "kernel.h"

void kernel_main()
{
    char *video_mem = (char *)(0xB8000);
    video_mem[0] = 'C';
    video_mem[1] = 2;
    video_mem[2] = 'A';
    video_mem[3] = 2;
}