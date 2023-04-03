# ping


## Command Function

This command is used to test an IPv4 connection.


## Syntax

ping *[-4] [-c cnt] [-f] [-i interval] [-q] [-s size] &lt;IP&gt;*


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range| 
| -------- | -------- | -------- |
| --help | Displays the parameters supported by the **ping** command.| N/A | 
| -4 | Forcibly pings the destination address using the IPv4 protocol.| 0-65500 | 
| -c&nbsp;CNT | Specifies the number of execution times. The default value is **3**.| 1-65535 | 
| -f | Pings an IPv4 address in implicit mode. The default parameter configuration is equivalent to **-c 15 -i 0.2**.| N/A | 
| -i&nbsp;interval | Specifies the interval (in ms) for sending a ping packet.| 1-200 | 
| -q | Implicitly pings an IPv4 address. If the host is still alive, the ping stops after **true** is returned.| N/A | 
| -s&nbsp;SIZE | Specifies the size of a ping packet, in bytes. The default size is **56** bytes.| 0-4088 | 
| IP | Specifies the IPv4 address of the network to test.| N/A | 


## Usage Guidelines

- The **ping** command is used to check whether the destination IP address is reachable.

- If the destination IP address is unreachable, the system displays a message indicating that the request times out.

- If no route is available to the destination IP address, an error message is displayed.

- This command can be used only after the TCP/IP protocol stack is enabled.


## Example

Run **ping 192.168.1.3**.


## Output

Ping a TFTP server IP address.

```
OHOS:/$ ping 192.168.1.3
Ping 192.168.1.3 (192.168.1.3): 56(84) bytes.
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=0 ms
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=1 ms
84 bytes from 192.168.1.3: icmp_seq=0 ttl=0 time=0 ms
--- 192.168.1.3 ping statistics ---
3 packets transmitted, 3 received, 0% packet loss
round-trip min/avg/max = 0/0/0 ms
```
