# Network Kit简介

Network Kit（网络服务）主要提供以下功能：

- [HTTP数据请求](http-request.md)：通过HTTP发起一个数据请求。
- [WebSocket连接](websocket-connection.md)：使用WebSocket建立服务器与客户端的双向连接。
- [Socket连接](socket-connection.md)：通过Socket进行数据传输。
- [网络连接管理](net-connection-manager.md)：网络连接管理提供管理网络一些基础能力，包括WiFi/蜂窝/Ethernet等多网络连接优先级管理、网络质量评估、订阅默认/指定网络连接状态变化、查询网络连接信息、DNS解析等功能。
- [MDNS管理](net-mdns.md)：MDNS即多播DNS（Multicast DNS），提供局域网内的本地服务添加、移除、发现、解析等能力。<!--Del-->
- [网络共享](net-sharing.md)：分享设备已有网络给其他连接设备，支持Wi-Fi热点共享、蓝牙共享和USB共享，同时提供网络共享状态、共享流量查询功能。
- [以太网连接](net-ethernet.md)：以太网连接主要提供有线网络能力，提供设置有线网络的IP地址，子网掩码，网关，DNS等信息。
<!--DelEnd-->

<!--RP1-->
<!--RP1End-->

## 约束与限制

使用网络管理模块的相关功能时，需要请求相应的权限。
在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[访问控制-声明权限](../security/AccessToken/declare-permissions.md)声明对应权限。

| 权限名                           | 说明                                   |
| -------------------------------- | -------------------------------------- |
| ohos.permission.GET_NETWORK_INFO | 获取网络连接信息。                     |
| ohos.permission.INTERNET         | 允许程序打开网络套接字，进行网络连接。 |

