#include <net/if.h>
#include <arpa/inet.h>

#include <stddef.h>

typedef struct {
    char interface_name[IFNAMSIZ];
    char ip_address[INET_ADDRSTRLEN];
    char subnet_mask[INET_ADDRSTRLEN];
    char mac_address[18]; // MAC address in string format (xx:xx:xx:xx:xx:xx)
} NetworkInterfaceInfo;

typedef struct {
    char name[MAX_COMMAND_LEN];             // Interface name in the router (Ethernet0, FastEthernet1, etc.) [MAX_COMMAND_LEN should be 255]
    char interface_name[IFNAMSIZ];          // Interface name in the system (eth0, enp0s3, etc.)
    char ip_address[INET_ADDRSTRLEN];       // IP address of the interface
    char subnet_mask[INET_ADDRSTRLEN];      // Subnet mask of the interface
    char mac_address[18];                   // MAC address of the interface (xx:xx:xx:xx:xx:xx)
    int is_shutdown;                        // Interface status (up or down)
    int is_dhcp_enabled;                    // DHCP status (enabled or disabled)
    char dhcp_range_start[INET_ADDRSTRLEN]; // DHCP range start IP address
    char dhcp_range_end[INET_ADDRSTRLEN];   // DHCP range end IP address
} EthernetInterface;

// Function prototypes
NetworkInterfaceInfo *get_network_interfaces(int *count);
void free_network_interfaces(NetworkInterfaceInfo *interfaces);
