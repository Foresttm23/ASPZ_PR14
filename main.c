#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    int counter = 0;
    const int interval_ms = 100;
    const int duration_ms = 5000;

    struct timeval start, now;
    gettimeofday(&start, NULL);

    while (1) {
        gettimeofday(&now, NULL);
        long elapsed_ms = (now.tv_sec - start.tv_sec) * 1000 + (now.tv_usec - start.tv_usec) / 1000;

        if (elapsed_ms >= duration_ms) {
            break;
        }

        printf("100ms counter: %d\n", counter++);
        usleep(interval_ms * 1000);
    }

    printf("Stopped after 5s\n");
    return 0;
}
