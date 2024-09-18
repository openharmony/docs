# Connectivity Kit简介

## Connectivity Kit开发概述

移动终端设备已经深入人民日常生活的方方面面，如连接蓝牙耳机听音乐、连接WIFI上网、使用NFC进行一碰开门等已成为终端用户日常生活中常见的行为。
当用户处于这些丰富的使用场景中时，蓝牙提供基于蓝牙连接的基础能力，如音乐/通话/分享等，WIFI提供基础的无线连接能力，NFC提供基础的靠近刷卡和读卡能力。
对于开发者，设计基础通信的体验服务，可以使应用的使用体验更贴近每个终端用户的日常生活。

### 蓝牙简介

蓝牙技术是一种无线通信技术，可以在短距离内传输数据。可以用于连接手机、耳机、音箱、键盘、鼠标、打印机等各种设备。特点是低功耗、低成本、简单易用。目前已经发展到了第五代，支持更高的数据传输速率和更广的覆盖范围。
下面简介几种常见的蓝牙涉及的模块：

- **ACCESS接入模块**<br/>
  蓝牙接入模块，提供了开关蓝牙以及获取蓝牙开关状态等接口功能。使用蓝牙功能需要通过该模块打开蓝牙，在蓝牙开关状态正确的条件下使用其他功能。
  详情请参考[@ohos.bluetooth.access API参考](../reference/apis-connectivity-kit/js-apis-bluetooth-access.md)。

- **CONNECTION连接模块**<br/>
  蓝牙连接模块，提供了设备发现、配对连接、获取本端及外设信息的接口功能。使用和外设交互的功能，需要使用该模块提供的能力和外设配对、连接成功，才能继续进行后续的数据传输等功能。
  详情请参考[@ohos.bluetooth.connection API参考](../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md)。

- **BLE模块（低功耗蓝牙）**<br/>
  BLE是Bluetooth Low Energy的缩写，意为“低功耗蓝牙”。它是一种能够在低功耗情况下进行通信的蓝牙技术，与传统蓝牙相比，BLE的功耗更低，适用于需要长时间运行的低功耗设备，如智能手表、健康监测设备、智能家居等。
  详情请参考[@ohos.bluetooth.ble API参考](../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md)。

- **SOCKET模块（串口协议）**<br/>
  SPP是Serial Port Profile（串口协议）的缩写，是一种蓝牙协议，用于在蓝牙设备之间建立串行通信连接。通过SPP，蓝牙设备可以像使用串口一样进行数据传输，例如传输文件、文本等。
  详情请参考[@ohos.bluetooth.socket API参考](../reference/apis-connectivity-kit/js-apis-bluetooth-socket.md)。

- **A2DP模块（高级音频分发配置文件）**<br/>
  A2DP是Advanced Audio Distribution Profile的缩写，即高级音频分发配置文件。它是一种蓝牙协议，允许无线传输高品质音频流，例如音乐或语音通话，同时支持双向通信，因此可以用于耳机、扬声器、汽车音响等设备。
  详情请参考[@ohos.bluetooth.a2dp API参考](../reference/apis-connectivity-kit/js-apis-bluetooth-a2dp.md)。

- **HFP模块（免提模式）**<br/>
  HFP模块是指蓝牙耳机或车载蓝牙设备中的Hands-Free Profile，即“免提模式”。HFP允许用户通过蓝牙连接手机或其他蓝牙设备，实现免提通话和语音控制等功能。
  详情请参考[@ohos.bluetooth.hfp API参考](../reference/apis-connectivity-kit/js-apis-bluetooth-hfp.md)。

- **HID模块（人机接口设备）**<br/>
  HID是Human Interface Device的缩写，即人机接口设备。在蓝牙中，HID模块是一种允许用户通过蓝牙连接键盘、鼠标、游戏手柄等人机接口设备的模块。用户可以通过HID模块将这些设备连接到蓝牙主机上，实现无线控制和输入。
  详情请参考[@ohos.bluetooth.hid API参考](../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md)。

- **PAN模块（个人区域网络）**<br/>
  PAN（Personal Area Network）是个人区域网络的缩写，是一种无线通信技术，用于将设备连接到一个小范围的网络中。例如可以将手机、电脑、打印机等设备连接到一个PAN网络中，实现文件的共享和打印。
  详情请参考[@ohos.bluetooth.pan API参考](../reference/apis-connectivity-kit/js-apis-bluetooth-pan.md)。

相关开发指南可参考：[蓝牙开发指南](./bluetooth/bluetooth-overview.md)。

### WLAN简介
无线局域网（Wireless Local Area Networks，WLAN），是通过无线电、红外光信号或者其他技术发送和接收数据的局域网，用户可以通过WLAN实现结点之间无物理连接的网络通讯。常用于用户携带可移动终端的办公、公众环境中。

WLAN系统为用户提供接入WLAN网络功能（STA模式）、点对点的数据传输功能（P2P模式）和热点分享功能（AP模式），让应用可以通过WLAN和其他设备互联互通。

- **STA模式**<br/>
  STA模式即工作站模式，可以理解为某网络中的一个工作站即客户端。当某设备具备该功能时，它可以连到另外的一个路由网络中，如家用路由器，通常用于提供网络的数据上行服务。
  详情请参考[@ohos.wifiManager API参考](../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

- **P2P模式**<br/>
  P2P模式也为Wi-Fi Direct；Wi-Fi Direct 是一种点对点连接技术，它可以在两台 STA 之间直接建立 TCP/IP 链接，并不需要AP的参与；其中一台STA会起到传统意义上的AP的作用，称为Group Owner(GO),另外一台station则称为Group Client(GC)，像连接AP一样连接到GO。
  详情请参考[@ohos.wifiManager API参考](../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

- **AP模式**<br/>
  AP模式为加入无线局域网的成员设备（即客户端）提供下行数据业务，它提供以无线方式组建无线局域网WLAN，相当际WLAN的中心设备。
  详情请参考[@ohos.wifiManager API参考](../reference/apis-connectivity-kit/js-apis-wifiManager.md)。

### NFC简介
NFC英文全称Near Field Communication，近距离无线通信。NFC服务提供NFC开关控制、NFC标签读写、NFC卡模拟等业务功能。

- **NFC开关**<br/>
  NFC开关模块，提供了打开NFC和关闭NFC功能。打开或关闭NFC的应用程序，需要声明权限"ohos.permission.MANAGE_SECURE_SETTINGS"，该权限只有系统应用才能声明。因此，只有系统应用才能打开或关闭NFC。
  详情请参考[@ohos.nfc.controller API参考](../reference/apis-connectivity-kit/js-apis-nfcController.md)。

- **NFC标签读写**<br/>
  NFC标签读写模块，提供了NFC标签的发现和分发给应用程序，以及应用程序通过NFC标签读写接口访问NFC标签的能力。应用程序需要按照规定的格式来声明NFC标签读写能力，只有声明后应用程序才能收到NFC标签的分发。
  详情请参考[@ohos.nfc.tag API参考](../reference/apis-connectivity-kit/js-apis-nfcTag.md)。

- **NFC卡模拟**<br/>
  NFC卡模拟模块，提供了NFC的刷卡业务，电子设备和读卡器触碰完成刷卡。应用程序需要按照规定的格式来声明NFC卡模拟能力，只有声明后应用程序才能够具备刷卡能力。
  详情请参考[@ohos.nfc.cardEmulation API参考](../reference/apis-connectivity-kit/js-apis-cardEmulation.md)。

### 运作机制

Connectivity能力作为系统为应用提供的一种基础通信服务，需要在应用使用场景中打开相应开关/连接等处理，在业务结束时主动结束连接等。

### 约束与限制

使用设备的相关能力，需要用户主动授权打开开关。否则系统不会向三方应用提供服务。

### 相关实例

针对蓝牙相关的业务，有以下相关实例可供参考：

- [`bluetooth`](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/Bluetooth)