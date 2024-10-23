#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
    if(argc != 4){
        printf("usage: %s VARIABLENAME VARIABLEVALUE COMMAND\n", argv[0]);
        exit(1);
    }
    // Set the environment variable
    if (setenv(argv[1], argv[2], 1) != 0) {
        perror("setenv failed");
        return 1;
    }

    // Print confirmation
    printf("Environment variable %s set to %s\n", argv[1], argv[2]);
    system(argv[3]);

    return 0;
}
