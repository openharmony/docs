# arp


## Command Function

Hosts on an Ethernet communicate with each other using MAC addresses. IP addresses must be converted into MAC addresses to enable communication between hosts on a LAN (Ethernet). To achieve this purpose, the host stores a table containing the mapping between IP addresses and MAC addresses. This table is called an Address Resolution Protocol (ARP) cache table. Before sending an IP packet to a LAN, the host looks up the destination MAC address in the ARP cache table. The ARP cache table is maintained by the TCP/IP stack. You can run the **arp** command to view and modify the ARP cache table.


## Syntax

arp

arp [_-i IF_] -s *IPADDR HWADDR*

arp [_-i IF_] -d *IPADDR*


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
| No parameter| Prints the content of the ARP cache table.| N/A |
| -i&nbsp;IF | Specifies the network port. This parameter is optional.| N/A |
| -s&nbsp;IPADDR<br>HWADDR | Adds an ARP entry. The second parameter is the IP address and MAC address of the other host on the LAN.| N/A |
| -d&nbsp;IPADDR | Deletes an ARP entry.| N/A |


## Usage Guidelines

- The **arp** command is used to query and modify the ARP cache table of the TCP/IP stack. If ARP entries for IP addresses on different subnets are added, the protocol stack returns a failure message.

- This command can be used only after the TCP/IP protocol stack is enabled.


## Example

Run **arp**.

ARP cache table information:

```
OHOS # arp
Address                 HWaddress               Iface       Type
192.168.1.10            E6:2B:99:2C:4B:20       eth0        static
```

**Table 2** Parameter description

| Parameter| Description|
| -------- | -------- |
| Address | IPv4 address of the network device.|
| HWaddress | MAC address of the network device.|
| Iface | Name of the port used by the ARP entry.|
| Type | Whether the ARP entry is dynamic or static. A dynamic ARP entry is automatically created by the protocol stack, and a static ARP entry is added by the user. |
