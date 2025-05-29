# ping6

## 命令功能

ping6用于测试IPv6网络连接是否正常。


## 命令格式

ping6 _[-c count] [-I interface / sourceAddress] destination_


## 参数说明

**表1** 参数说明

| 参数                  | 参数说明                            | 取值范围 |
| --------------------- | ----------------------------------- | -------- |
| -c&nbsp;count         | 执行的次数，不带本参数则默认为4次。 | [1, 65535]  |
| -I&nbsp;interface     | 指定网卡执行IPv6&nbsp;ping操作。    | N/A      |
| -I&nbsp;sourceAddress | 指定源IPv6地址执行ping操作。        | N/A      |
| destination           | 目标主机地址。                      | N/A      |


## 使用指南

- 如果目的IPv6地址不可达，会显示请求超时。

- 如果显示发送错误，说明没有到目的IPV6的路由。

- 命令需要启动TCP/IP协议栈后才能使用。

## 特殊说明

shell端暂不支持。

## 使用实例

- ping6 2001:a:b:c:d:e:f:b

- ping6 -c 3 2001:a:b:c:d:e:f:b

- ping6 -I eth0 2001:a:b:c:d:e:f:b

- ping6 -I 2001:a:b:c:d:e:f:d 2001:a:b:c:d:e:f:b


## 输出说明

1. 输入`ping6 2001:a:b:c:d:e:f:b`。

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

2. 输入 `ping6 -c 3 2001:a:b:c:d:e:f:b`   指定3次进行网络测试。

   ```
   OHOS # ping6 -c 3 2001:a:b:c:d:e:f:b    PING 2001:A:B:C:D:E:F:B with 56 bytes of data.
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=1 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=2 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=3 time<1 ms
   --- 2001:a:b:c:d:e:f:b/64 ping statistics ---
   3 packets transmitted, 3 received, 0.00% packet loss, time 20ms
   rtt min/avg/max = 0/0.00/0 ms
   ```

3. 输入 `ping6 -I eth0 2001:a:b:c:d:e:f:b`  使用指定网卡接口eth0测试IPv6。

   ```
   OHOS # ping6 -I eth0 2001:a:b:c:d:e:f:b PING 2001:A:B:C:D:E:F:B with 56 bytes of data.
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=1 time=10 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=2 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=3 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=4 time<1 ms
   --- 2001:a:b:c:d:e:f:b/64 ping statistics ---
   4 packets transmitted, 4 received, 0.00% packet loss, time 30msrtt min/avg/max = 0/2.50/10 ms
   ```

4. 输入 `ping6 -I 2001:a:b:c:d:e:f:d 2001:a:b:c:d:e:f:b`   使用指定的源IPv6地址2001:a:b:c:d:e:f:d进行测试。

   ```
   OHOS # ping6 -I 2001:a:b:c:d:e:f:d 2001:a:b:c:d:e:f:b PING 2001:A:B:C:D:E:F:B with 56 bytes of data.
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=1 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=2 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=3 time<1 ms
   56 bytes from 2001:A:B:C:D:E:F:B : icmp_seq=4 time<1 ms
   --- 2001:a:b:c:d:e:f:b/64 ping statistics ---
   4 packets transmitted, 4 received, 0.00% packet loss, time 20msrtt min/avg/max = 0/0.00/0 ms
   ```