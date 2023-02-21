# ifconfig


## Command Function

This command can be used to:

- Query and set parameters of a network interface card (NIC), such as the IP address, network mask, gateway, and MAC address.

- Enable or disable a NIC.


## Syntax

ifconfig [option]

option:

- [_-a_]

- &lt;*interface*&gt; &lt;*address*&gt; [_netmask &lt;mask&gt;_] [_gateway &lt;address&gt;_]

- [_hw ether &lt;address&gt;_] [_mtu &lt;size&gt;_]

- [_inet6 add &lt;address&gt;_]

- [_inet6 del &lt;address&gt;_]

- [_up|down_]


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
|  No parameter| Displays all NIC information, which includes the IP address, network mask, gateway, MAC address, maximum transmission unit (MTUs), and running status of each NIC.| N/A |
| -a | Displays data sent and received by the protocol stack.| N/A |
| interface | Specifies the NIC name, for example, **eth0**.| N/A |
| address | Specifies the IP address, for example, **192.168.1.10**. The NIC name must be specified.| N/A |
| netmask | Specifies the subnet mask, for example, **255.255.255.0**.| N/A |
| gateway | Specifies the gateway, for example, **192.168.1.1**.| N/A |
| hw&nbsp;ether | Specifies the MAC address, for example, **00:11:22:33:44:55**. Currently, only the **ether** hardware type is supported.| N/A |
| mtu | Specifies the MTU size, for example, **1000**.| - IPv4: [68, 1500]<br>- IPv6:[1280, 1500] |
| add | Specifies the IPv6 address, for example, **2001:a:b:c:d:e:f:d**. The NIC name and **inet6** must be specified.| N/A |
| del | Deletes an IPv6 address. You need to specify the NIC name and add the **inet6** option. For details, see the example.| N/A |
| up | Enables the data processing function of the NIC. The NIC name must be specified.| N/A |
| down | Disables the data processing function of the NIC. The NIC name must be specified.| N/A |


## Usage Guidelines

- This command can be used only after the TCP/IP stack is enabled.

- Detecting an IP address conflict takes time. Each time you run the **ifconfig** command to set an IP address, there is a delay of about 2 seconds.


## Example

- ifconfig eth0 192.168.100.31 netmask 255.255.255.0 gateway 192.168.100.1 hw ether 00:49:cb:6c:a1:31

- ifconfig -a

- ifconfig eth0 inet6 add 2001:a:b:c:d:e:f:d

- ifconfig eth0 inet6 del 2001:a:b:c:d:e:f:d


## Output

- Example 1: Set network parameters.

  ```
  OHOS:/$ ifconfig eth0 192.168.100.31 netmask 255.255.255.0 gateway 192.168.100.1 hw ether 00:49:cb:6c:a1:31
  OHOS:/$ ifconfig
  lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
          ip6: ::1/64
          HWaddr 00 MTU:0 Running Link UP
  eth0    ip:192.168.100.31 netmask:255.255.255.0 gateway:192.168.100.1
          HWaddr 00:49:cb:6c:a1:31 MTU:1500 Running Default Link UP
  ```

  

  **Table 2** Parameter description
  
  | Parameter| Description|
  | -------- | -------- |
  | ip | IP address of the board.|
  | netmask | Subnet mask.|
  | gateway | Gateway.|
  | HWaddr | MAC address of the board.|
  | MTU | Maximum transmission unit.|
  | Running/Stop | Whether the NIC is running.|
  | Default | Indicates that the NIC is connected to the default gateway.|
  | Link&nbsp;UP/Down | Connection status of the NIC.|

- Example 2: Obtain protocol stack statistics.

  ```
  OHOS # ifconfig -a
  RX packets:6922  errors:0        ip dropped:4312         link dropped:67         overrun:0       bytes:0 (0.0 B)
  RX packets(ip6):3     errors:0        dropped:0       overrun:0       bytes:0 (0.0 B)
  TX packets:1394  errors:0        link dropped:67         overrun:0       bytes:0(0.0 B)
  TX packets(ip6):3     errors:0        overrun:0       bytes:0(0.0 B)
  ```

  
  
  **Table 3** ifconfig -a parameter description
  
  | Parameter| Description|
  | -------- | -------- |
  | RX&nbsp;packets | Number of normal packets received at the IP layer.|
  | RX&nbsp;error | Number of error packets received at the IP layer. The errors include the length error, verification error, IP option error, and IP header protocol error.|
  | RX&nbsp;dropped | Number of packets discarded at the IP layer. Packets are discarded due to packet errors, packet forwarding failures, and disabled local NICs.|
  | RX&nbsp;overrun | Number of packets that the MAC layer fails to deliver to the upper-layer protocol stack. The failure is caused by resource insufficiency at the protocol stack.|
  | RX&nbsp;bytes | Total length of normal packets received at the IP layer, excluding the length of the fragments that are not reassembled.|
  | TX&nbsp;packets | Number of packets that have been normally sent or forwarded at the IP layer.|
  | TX&nbsp;error | Number of packets that the IP layer fails to send. Packets may fail to be sent because the packets cannot be routed or the packets fail to be processed in the protocol stack.|
  | TX&nbsp;dropped | Number of packets that the MAC layer discards due to delivery failures, for example, the NIC driver fails to process the packets.|
  | TX&nbsp;overrun | Not used currently.|
  | TX&nbsp;bytes | Total length of the packets successfully sent or forwarded at the IP layer.|

- Example 3: Set an IPv6 address.

  ```
  OHOS:/$ ifconfig eth0 inet6 add 2001:a:b:c:d:e:f:d
  NetifStatusCallback(eth0): nsc event: 0x8
  NetifStatusCallback(eth0): nsc status changed: 0
  NetifStatusCallback(eth0): nsc event: 0x200
  NetifStatusCallback(eth0): nsc event: 0x8
  NetifStatusCallback(eth0): nsc status changed: 1
  NetifStatusCallback(eth0): nsc event: 0x200
  NetifStatusCallback(eth0): nsc event: 0x200
  OHOS:/$ ifconfig
  lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
          ip6: ::1/64
          HWaddr 00 MTU:0 Running Link UP
  eth0    ip:192.168.1.10 netmask:255.255.255.0 gateway:192.168.1.1
          ip6: 2001:A:B:C:D:E:F:D/64
          HWaddr 66:2f:e5:bd:24:e6 MTU:1500 Running Default Link UP
  ```

- Example 4: Delete an IPv6 address.

  ```
  OHOS:/$ ifconfig eth0 inet6 del 2001:a:b:c:d:e:f:d
  NetifStatusCallback(eth0): nsc event: 0x200
  OHOS:/$ ifconfig
  lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
          ip6: ::1/64
          HWaddr 00 MTU:0 Running Link UP
  eth0    ip:192.168.1.10 netmask:255.255.255.0 gateway:192.168.1.1
          HWaddr 66:2f:e5:bd:24:e6 MTU:1500 Running Default Link UP
  ```
