#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 12345

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    struct ifreq ifr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); // Using SOCK_DGRAM for demonstration; change as needed
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Specify the network interface to bind to
    strncpy(ifr.ifr_name, "eno1", IFNAMSIZ); // Set the interface name (e.g., "eno1")
    if (setsockopt(sockfd, SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof(ifr)) < 0) {
        perror("setsockopt(SO_BINDTODEVICE) failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // Bind to all interfaces on the specified network interface
    servaddr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Socket successfully bound to interface eno1 and port %d\n", PORT);

    // Perform socket operations here...

    // Close the socket
    close(sockfd);
    return 0;
}
