# WLAN服务开发概述

## 概述
无线局域网（Wireless Local Area Networks，WLAN），是通过无线电、红外光信号或者其他技术发送和接收数据的局域网，用户可以通过WLAN实现结点之间无物理连接的网络通讯。常用于用户携带可移动终端的办公、公众环境中。

WLAN系统为用户提供接入WLAN网络功能（STA模式）、点对点的数据传输功能（P2P模式）和热点分享功能（AP模式），让应用可以通过WLAN和其他设备互联互通。

## 实现原理
WLAN的实现原理是通过无线电磁波在空间中传输信息，当前使用的频段是2.4GHz或者5GHz频段。WLAN网络架构分有线侧和无线侧两部分，有线侧是指AP上行到Internet的网络使用以太网协议，无线侧是指STA到AP之间的网络，使用802.11协议。

## 模式介绍
- STA模式（工作站模式）：STA模式即工作站模式，可以理解为某网络中的一个工作站即客户端。当某设备具备该功能时，它可以连到另外的一个路由网络中，如家用路由器，通常用于提供网络的数据上行服务。详情请参考[@ohos.wifiManager API参考](../../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

- P2P模式（Wi-Fi直连）：P2P模式也为Wi-Fi Direct；Wi-Fi Direct 是一种点对点连接技术，它可以在两台 STA 之间直接建立 TCP/IP 链接，并不需要AP的参与；其中一台STA会起到传统意义上的AP的作用，称为Group Owner(GO),另外一台station则称为Group Client(GC)，像连接AP一样连接到GO。详情请参考[@ohos.wifiManager API参考](../../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

- AP模式（热点模式）：AP模式为加入无线局域网的成员设备（即客户端）提供下行数据业务，它提供以无线方式组建无线局域网WLAN，相当于WLAN的中心设备。详情请参考[@ohos.wifiManager API参考](../../reference/apis-connectivity-kit/js-apis-wifiManager.md)。
