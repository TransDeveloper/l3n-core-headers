#include <net/if.h>
#include <arpa/inet.h>

#include <stddef.h>

typedef struct {
    char interface_name[IFNAMSIZ];
    char ip_address[INET_ADDRSTRLEN];
    char subnet_mask[INET_ADDRSTRLEN];
    char mac_address[18]; // MAC address in string format (xx:xx:xx:xx:xx:xx)
} NetworkInterfaceInfo;

// Function prototypes
NetworkInterfaceInfo *get_network_interfaces(int *count);
void free_network_interfaces(NetworkInterfaceInfo *interfaces);
