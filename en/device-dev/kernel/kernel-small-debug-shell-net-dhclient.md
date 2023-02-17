# dhclient


## Command Function

This command is used to set and query **dhclient** parameters.


## Syntax

- dhclient &lt;*netif name*&gt;

- dhclient -x &lt;*netif name*&gt;


## Parameters

**Table 1** Parameter description

| Parameter                           | Description                                    | Value Range        |
| ------------------------------- | -------------------------------------------- | ---------------- |
| -h&nbsp;\|&nbsp;--help          | Displays parameters supported by the **dhclient** command and their usage.| N/A              |
| &lt;netif&nbsp;name&gt;         | Enables Dynamic Host Configuration Protocol (DHCP) for a network interface card (NIC).                    | NIC name, **eth0**|
| -x&nbsp;&lt;netif&nbsp;name&gt; | Disables DHCP for a NIC.                    | NIC name, **eth0**|


## Usage Guidelines

Run the following commands:

- dhclient eth0

- dhclient -x eth0

## Note

Currently, the shell does not support this command.

## Example

Example 1: Enable DHCP for eth0.


```
OHOS:/$ dhclient eth0
OHOS:/$ ifconfig
lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
        ip6: ::1/64
        HWaddr 00 MTU:0 Running Link UP
eth0    ip:192.168.1.10 netmask:255.255.255.0 gateway:192.168.1.1
        HWaddr 42:da:81:bc:58:94 MTU:1500 Running Default Link UP
OHOS:/$
```


Example 2: Disable DHCP for eth0.


```
OHOS:/$ dhclient -x eth0
NetifStatusCallback(eth0): nsc event: 0xf0
OHOS:/$ ifconfig
lo      ip:127.0.0.1 netmask:255.0.0.0 gateway:127.0.0.1
        ip6: ::1/64
        HWaddr 00 MTU:0 Running Link UP
eth0    ip:0.0.0.0 netmask:0.0.0.0 gateway:0.0.0.0
        HWaddr 42:da:81:bc:58:94 MTU:1500 Running Default Link UP
```
