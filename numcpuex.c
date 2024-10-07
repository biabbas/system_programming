#include <stdio.h>
#include <unistd.h>

int main() {
    long num_processors;
    num_processors = sysconf(_SC_NPROCESSORS_CONF);

    if (num_processors == -1) {
        perror("sysconf error");
        return 1;
    }

    printf("Number of processors configured: %ld\n", num_processors);

    return 0;
}
