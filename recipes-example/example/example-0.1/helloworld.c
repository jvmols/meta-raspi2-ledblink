#include <stdio.h>

int main(int argc, char **argv)
{
    printf("Hello World!\n");

    system("echo \"none\" > /sys/class/leds/led0/trigger");
    system("echo 1 > /sys/class/leds/led0/brightness");

    return 0;
}
