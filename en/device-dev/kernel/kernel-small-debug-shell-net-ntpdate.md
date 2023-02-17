# ntpdate


## Command Function

This command is used to synchronize system time from the server.


## Syntax

ntpdate [_SERVER_IP1_] [_SERVER_IP2_]...


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
| SERVER_IP | Specifies the IP address of the NTP server.| N/A |


## Usage Guidelines

Run the **ntpdate [_SERVER_IP1_] [_SERVER_IP2_]...** command to obtain and display the time of the first server with a valid IP address.


## Example

Run **ntpdate 192.168.1.3 **to update the system time.


## Output


```
OHOS # ntpdate 192.168.1.3
time server 192.168.1.3: Mon Jun 13 09:24:25 2016
```

If the time zone of the board is different from that of the server, the displayed time may be several hours different from the server time obtained.
