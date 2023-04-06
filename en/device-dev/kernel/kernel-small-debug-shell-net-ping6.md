# ping6


## Command Function

This command is used to test an IPv6 network connection.


## Syntax

ping6 *[-c count] [-I interface / sourceAddress] destination*


## Parameters

**Table 1** Parameter description

| Parameter                 | Description                           | Value Range|
| --------------------- | ----------------------------------- | -------- |
| -c&nbsp;count         | Specifies the number of execution times. If this parameter is not specified, the default value is **4**.| [1, 65535]  |
| -I&nbsp;interface     | Specifies the NIC for performing the ping operation. | N/A      |
| -I&nbsp;sourceAddress | Specifies the source IPv6 address.       | N/A      |
| destination           | Specifies the IP address of the destination host.                     | N/A      |


## Usage Guidelines

- If the destination IPv6 address is unreachable, "Request Timed Out" will be displayed.

- If no route is available to the destination IPv6 address, "Destinatin Host Unreachable" will be displayed.

- This command can be used only after the TCP/IP stack is enabled.

## Note

Currently, the shell does not support this command.

## Example

- ping6 2001:a:b:c:d:e:f:b

- ping6 -c 3 2001:a:b:c:d:e:f:b

- ping6 -I eth0 2001:a:b:c:d:e:f:b

- ping6 -I 2001:a:b:c:d:e:f:d 2001:a:b:c:d:e:f:b


## Output

1. Output of **ping6 2001:a:b:c:d:e:f:b**:

   ```
   OHOS # ping6 2001:a:b:c:d:e:f:b PING 2001:A:B:C:D:E:F:B with 56 bytes of data.
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=1 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=2 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=3 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=4 time<1 ms
   --- 2001:a:b:c:d:e:f:b/64 ping statistics ---
   4 packets transmitted, 4 received, 0.00% packet loss, time 20ms
   rtt min/avg/max = 0/0.00/0 ms
   ```

2. Output of **ping6 -c 3 2001:a:b:c:d:e:f:b**:

   ```
   OHOS # ping6 -c 3 2001:a:b:c:d:e:f:b    PING 2001:A:B:C:D:E:F:B with 56 bytes of data.
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=1 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=2 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=3 time<1 ms
   --- 2001:a:b:c:d:e:f:b/64 ping statistics ---
   3 packets transmitted, 3 received, 0.00% packet loss, time 20ms
   rtt min/avg/max = 0/0.00/0 ms
   ```

3. Output of **ping6 -I eth0 2001:a:b:c:d:e:f:b**:

   ```
   OHOS # ping6 -I eth0 2001:a:b:c:d:e:f:b PING 2001:A:B:C:D:E:F:B with 56 bytes of data.
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=1 time=10 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=2 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=3 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=4 time<1 ms
   --- 2001:a:b:c:d:e:f:b/64 ping statistics ---
   4 packets transmitted, 4 received, 0.00% packet loss, time 30msrtt min/avg/max = 0/2.50/10 ms
   ```

4. Output of **ping6 -I 2001:a:b:c:d:e:f:d 2001:a:b:c:d:e:f:b**:

   ```
   OHOS # ping6 -I 2001:a:b:c:d:e:f:d 2001:a:b:c:d:e:f:b PING 2001:A:B:C:D:E:F:B with 56 bytes of data.
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=1 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=2 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=3 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=4 time<1 ms
   --- 2001:a:b:c:d:e:f:b/64 ping statistics ---
   4 packets transmitted, 4 received, 0.00% packet loss, time 20msrtt min/avg/max = 0/0.00/0 ms
   ```
