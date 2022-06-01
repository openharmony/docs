# 网络管理开发概述

网络管理模块主要提供以下功能：

- [HTTP数据请求](http-request.md)：通过HTTP发起一个数据请求。
- [WebSocket连接](websocket-connection.md)：使用WebSocket建立服务器与客户端的双向连接。
- [Socket连接](socket-connection.md)：通过Socket进行数据传输。

## 约束与限制

使用网络管理模块的相关功能时，需要请求相应的权限。

| 权限名                           | 说明                                   |
| -------------------------------- | -------------------------------------- |
| ohos.permission.GET_NETWORK_INFO | 获取网络连接信息。                     |
| ohos.permission.SET_NETWORK_INFO | 修改网络连接状态。                     |
| ohos.permission.INTERNET         | 允许程序打开网络套接字，进行网络连接。 |

