# Connectivity Kit简介

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## Connectivity Kit开发概述

移动终端设备已经深入人民日常生活的方方面面，如连接蓝牙耳机听音乐、连接WIFI上网、使用NFC进行一碰开门等已成为终端用户日常生活中常见的行为。
当用户处于这些丰富的使用场景中时，蓝牙提供基于蓝牙连接的基础能力，如音乐/通话/分享等，WIFI提供基础的无线连接能力，NFC提供基础的靠近刷卡和读卡能力。
对于开发者，设计基础通信的体验服务，可以使应用的使用体验更贴近每个终端用户的日常生活。

### 蓝牙简介

蓝牙技术是一种无线通信技术，可以在短距离内传输数据，该技术规范由蓝牙技术联盟（Bluetooth Special Interest Group, SIG）制定。可以用于连接手机、耳机、音箱、键盘、鼠标、打印机等各种设备。特点是低功耗、低成本、简单易用。

蓝牙模块提供了多种API，适用于不同场景，助力开发者完成蓝牙相关开发。

- **ACCESS模块**<br/>
  提供开启、关闭蓝牙和获取蓝牙开关状态等能力。使用蓝牙其他功能需要通过该模块打开蓝牙，在蓝牙已打开的情况下使用其他功能。具体内容可参考API [@ohos.bluetooth.access](../reference/apis-connectivity-kit/js-apis-bluetooth-access.md)。

- **CONNECTION模块**<br/>
  提供蓝牙设备的发现、配对连接和获取本端及对端设备信息等能力。具体内容可参考API [@ohos.bluetooth.connection](../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md)。

- **BLE模块**<br/>
  提供基于低功耗蓝牙（Bluetooth Low Energy）技术的蓝牙能力，可支持发现设备、发送广播报文、发现服务和传输数据等功能。具体内容可参考API [@ohos.bluetooth.ble](../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md)。

- **SOCKET模块**<br/>
  提供基于串口通信协议（Serial Port Profile，SPP）实现蓝牙设备间通信连接和传输数据的能力。具体内容可参考API [@ohos.bluetooth.socket](../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md)。

- **A2DP模块**<br/>
  提供基于增强音频分发协议（Advanced Audio Distribution Profile，A2DP）实现蓝牙设备间通信连接和传输高品质音频的能力。例如：手机与耳机、音响等设备间传输音频流，实现听音乐的场景。具体内容可参考API [@ohos.bluetooth.a2dp](../reference/apis-connectivity-kit/js-apis-bluetooth-a2dp.md)。

- **HFP模块**<br/>
  提供基于免提协议（Hands-Free Profile，HFP）实现蓝牙设备间通信连接和免提通话的能力，可支持双向语音通话和控制等功能。具体内容可参考API [@ohos.bluetooth.hfp](../reference/apis-connectivity-kit/js-apis-bluetooth-hfp.md)。

- **HID模块**<br/>
  提供基于人机接口协议（Human Interface Device Profile，HID）实现蓝牙设备间通信连接、无线控制和传输的能力。例如：支持键盘、鼠标、游戏手柄等设备与主机（如手机、平板和PC）间的低延迟双向通信。具体内容可参考API [@ohos.bluetooth.hid](../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md)。

- **PAN模块**<br/>
  提供基于个人局域网协议（Personal Area Network，PAN）实现设备间网络共享的能力。例如：手机与PC间的互联网共享。具体内容可参考API [@ohos.bluetooth.pan](../reference/apis-connectivity-kit/js-apis-bluetooth-pan.md)。

- **MAP模块**<br/>
  提供基于消息访问协议（Message Access Profile，MAP）实现设备间消息共享的能力。例如：手机与车载间的短信数据同步。具体内容可参考API [@ohos.bluetooth.map](../reference/apis-connectivity-kit/js-apis-bluetooth-map.md)。

- **PBAP模块**<br/>
  提供基于电话簿访问协议（Phone Book Access Profile）实现设备间电话簿数据共享的能力。例如：手机与车载间的联系人和通话记录的数据同步。具体内容可参考API [@ohos.bluetooth.pbap](../reference/apis-connectivity-kit/js-apis-bluetooth-pbap.md)。

### WLAN简介
无线局域网（Wireless Local Area Networks，WLAN），是通过无线电、红外光信号或者其他技术发送和接收数据的局域网，用户可以通过WLAN实现结点之间无物理连接的网络通讯。常用于用户携带可移动终端的办公、公众环境中。

WLAN系统为用户提供接入WLAN网络功能（STA模式）、点对点的数据传输功能（P2P模式）和热点分享功能（AP模式），让应用可以通过WLAN和其他设备互联互通。

- **STA模式**<br/>
  STA模式即工作站模式，可以理解为某网络中的一个工作站即客户端。当某设备具备该功能时，它可以连到另外的一个路由网络中，如家用路由器，通常用于提供网络的数据上行服务。详情请参考[@ohos.wifiManager API参考](../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

- **P2P模式**<br/>
  P2P模式也是Wi-Fi Direct；Wi-Fi Direct是一种点对点连接技术，它可以在两台STA之间直接建立TCP/IP链接，并不需要AP的参与；其中一台STA会起到传统意义上的AP的作用，称为Group Owner(GO),另外一台station则称为Group Client(GC)，像连接AP一样连接到GO。详情请参考[@ohos.wifiManager API参考](../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

- **AP模式**<br/>
  AP模式为加入无线局域网的成员设备（即客户端）提供下行数据业务，它提供以无线方式组建无线局域网WLAN，相当于WLAN的中心设备。详情请参考[@ohos.wifiManager API参考](../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

### NFC简介
NFC英文全称Near Field Communication，近距离无线通信。NFC服务提供NFC开关控制、NFC标签读写、NFC卡模拟等业务功能。

- **NFC开关**<br/>
  NFC开关模块，提供了打开NFC和关闭NFC功能。打开或关闭NFC的应用程序，需要声明权限"ohos.permission.MANAGE_SECURE_SETTINGS"，该权限只有系统应用才能声明。因此，只有系统应用才能打开或关闭NFC。详情请参考[@ohos.nfc.controller API参考](../reference/apis-connectivity-kit/js-apis-nfcController.md)。

- **NFC标签读写**<br/>
  NFC标签读写模块，提供了NFC标签的发现和分发给应用程序，以及应用程序通过NFC标签读写接口访问NFC标签的能力。应用程序需要按照规定的格式来声明NFC标签读写能力，只有声明后应用程序才能收到NFC标签的分发。详情请参考[@ohos.nfc.tag API参考](../reference/apis-connectivity-kit/js-apis-nfcTag.md)。

- **NFC卡模拟**<br/>
  NFC卡模拟模块，提供了NFC的刷卡业务，电子设备和读卡器触碰完成刷卡。应用程序需要按照规定的格式来声明NFC卡模拟能力，只有声明后应用程序才能够具备刷卡能力。详情请参考[@ohos.nfc.cardEmulation API参考](../reference/apis-connectivity-kit/js-apis-cardEmulation.md)。

### 运作机制

Connectivity能力作为系统为应用提供的一种基础通信服务，需要在应用使用场景中打开相应开关/连接等处理，在业务结束时主动结束连接等。

### 约束与限制

使用设备的相关能力，需要用户主动授权打开开关。否则系统不会向三方应用提供服务。

### 相关实例

针对蓝牙相关的业务，有以下相关实例可供参考：

- [bluetooth](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Bluetooth)