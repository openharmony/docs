# netstat


## Command Function

The **netstat** command is a console command and is used for monitoring the TCP/IP network. It can display the actual network connections and the status of each network interface device. This command displays statistics related to TCP and UDP connections and can be used to check the network connection to each port on a device (board).


## Syntax

netstat


## Parameters

None.


## Usage Guidelines

None.

## Note

Currently, the shell does not support this command.

## Example

Run **netstat**.


## Output

**netstat** output information:

```
OHOS # netstat
========== total sockets 128 ======  unused sockets 119 ==========
Proto   Recv-Q      Send-Q      Local Address           Foreign Address         State
tcp     0           0           192.168.1.10:578        192.168.1.3:2049        ESTABLISHED
tcp     0           0           192.168.1.10:58653      0.0.0.0:0               LISTEN
tcp     0           0           192.168.1.10:58652      0.0.0.0:0               LISTEN
tcp     0           0           192.168.1.10:58651      0.0.0.0:0               LISTEN
Proto   Recv-Q      Send-Q      Local Address           Foreign Address
udp     0           0           127.0.0.1:62177         127.0.0.1:62178
udp     0           0           0.0.0.0:5684            0.0.0.0:0
udp     0           0           127.0.0.1:62179         127.0.0.1:62180
udp     0           0           127.0.0.1:62180         127.0.0.1:62179
udp     0           0           127.0.0.1:62178         127.0.0.1:62177
```

**Table 1** Output description

| Parameter                | Description                                                        |
| -------------------- | ------------------------------------------------------------ |
| Proto                | Protocol type.                                                  |
| Recv-Q               | Amount of data that is not read by the user.<br>For Listen TCP, the value indicates the number of TCP connections that have finished the three-way handshake but are not accepted by users. |
| Send-Q               | For a TCP connection, this value indicates the amount of data that has been sent but not acknowledged.<br>For a UDP connection, this value indicates the amount of data buffered before IP address resolution is complete.|
| Local&nbsp;Address   | Local IP address and port number.                                            |
| Foreign&nbsp;Address | Remote IP address and port number.                                            |
| State                | TCP connection status. This parameter is meaningless for UDP.                                |

> **NOTE**<br>
> The command output like "========== total sockets 32 ====== unused sockets 22 BootTime 27 s ==========" indicates that there are 32 sockets in total, 22 sockets are not used, and it has been 27 seconds since the system starts.
