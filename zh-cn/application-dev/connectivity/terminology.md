# Connectivity Kit术语

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## A
### A2DP
Advanced Audio Distribution Profile，即增强音频分发协议。支持传输高品质音频。例如：使用蓝牙耳机听音乐。该协议定义了2种角色：[A2DP Source](#a2dp-source)和[A2DP Sink](#a2dp-sink)。
### A2DP Sink
[A2DP](#a2dp)协议中的音频接收设备，负责解码并播放音频。典型设备如：蓝牙耳机、音箱等。
### A2DP Source
[A2DP](#a2dp)协议中的音频源设备端，负责编码并发送音频数据。典型设备如：手机、平板等。
### ACL
Asynchronous Connectionless Link，即异步无连接链路。在蓝牙子系统中，表示设备间物理链路的连接情况。
## B
### BLE
Bluetooth Low Energy，即低功耗蓝牙。从蓝牙4.0开始支持的协议，相比于传统蓝牙，是支持低功耗、长续航的蓝牙通信技术。
### BR
Basic Rate，即蓝牙基础率。是一种蓝牙无线通信技术，用来表示传统蓝牙，主要用于文件和音频流的传输场景。
### Bluetooth SIG
Bluetooth Special Interest Group，即蓝牙技术联盟，发布蓝牙技术规范的组织。开发者可以在其官网获取详细的蓝牙技术文档。
## C
### Characteristic
[GATT](#gatt)服务（[Service](#service)）的核心数据单元，可进行数据读写，通过[UUID](#uuid)标识。
## D
### Descriptor
[GATT](#gatt)特征值（[Characteristic](#characteristic)）的数据单元，用于描述特征值的附加信息和属性，可进行数据读写，通过[UUID](#uuid)标识。
## E
### EDR
Enhanced Data Rate，即蓝牙增强数据率。是蓝牙[BR](#br)的增强版本，具有更高的数据传输速率，和BR统称为传统蓝牙。
## G
### GATT
Generic Attribute Profile，即通用属性协议。是[BLE](#ble)的核心协议，定义了基于服务（[Service](#service)）、特征值（[Characteristic](#characteristic)）和描述符（[Descriptor](#descriptor)）进行蓝牙通信和传输数据的机制。
## H
### HF
Hands-Free unit，即[HFP](#hfp)协议中的免提设备。是蓝牙通话音频中的远程控制端‌，提供物理交互界面（如按钮）及音频输入/输出（如麦克风、扬声器）。典型设备如：蓝牙耳机、车载蓝牙等。
### HFP
Hands-Free Profile，即免提协议。用于实现蓝牙设备间的免提通话，支持双向语音通话和控制等功能。该协议定义了2种角色：[HFP AG](#hfp-ag)和[HF](#hf)。
### HFP AG
Hands-Free Audio Gateway，即[HFP](#hfp)协议中的音频网关。是蓝牙通话音频中的音频处理中心，负责通话控制（如执行接听/挂断指令）、管理音频输入/输出等功能。典型设备如：手机、平板等。
### HID
Human Interface Device Profile，即人机接口协议，为传统蓝牙设计。可用于实现蓝牙无线人机交互设备连接间的低延迟双向通信。例如：键盘、鼠标、游戏手柄等设备与主机（如手机、平板）间传输数据。该协议定义了2种角色：[HID Host](#hid-host)和[HID Device](#hid-device)。
### HID Device
[HID](#hid)设备，是向[HID Host](#hid-host)设备提供人机数据输入/输出的设备。典型设备如：鼠标、键盘等。
### HID Host
[HID](#hid)主机设备，负责处理和接收[HID Device](#hid-device)的输入数据，并执行对应操作。典型设备如：手机、平板等。
### HOGP
HID over GATT Profile，基于低功耗蓝牙的GATT协议实现的HID规范，将传统HID功能移植到BLE设备上复用，兼容键盘、鼠标、自拍杆等BLE设备的HID交互逻辑。
## L
### L2CAP
Logical Link Control and Adaptation Protocal，即逻辑链路控制和适配协议。可支持上层协议和应用的多种传输需求，提供面向连接和无连接的数据服务，并提供多路复用，分段和重组操作。
## M
### MAP
Message Access Profile，即消息访问协议。可用于实现蓝牙设备间的消息同步，支持短信、邮件等数据传输。该协议定义了2种角色：[MCE](#mce)和[MSE](#mse)。
### MCE
Message Client Equipment，即[MAP](#map)协议中的消息客户端，可查看和管理[MSE](#mse)的消息。典型设备如：车载蓝牙。
### MSE
Message Server Equipment，即[MAP](#map)协议中的消息服务端，存储原始消息数据（如短信或邮件）。典型设备如‌：手机。
### MTU
Maximum Transmission Unit，即最大传输单元。表示网络中单次传输的最大数据包大小，单位是字节。
## N
### NAP
Network Access Point，即[PAN](#pan)协议中的网络接入点，充当网关设备，提供互联网接入或本地网络共享功能。典型设备如：手机、平板等。
## O
### OPP
Object Push Profile，即对象推送协议。基于通用对象交换协议（Generic Object Exchange Profile，GOEP）构建，可用于实现设备间数据（如图片、文档等）传输。
## P
### PAN
Personal Area Network，即蓝牙个人局域网协议。支持设备间网络共享。在该协议中，[NAP](#nap)和[PANU](#panu)是两种核心角色。
### PANU
Personal Area Network User，即[PAN](#pan)协议中的个人局域网用户，作为客户端设备，主动连接[NAP](#nap)以获取网络服务。
### PBAP
Phone Book Access Profile，即蓝牙电话簿访问协议。可用于实现蓝牙设备间的电话簿数据同步，支持联系人、通话记录等数据传输。该协议定义了2种角色：[PCE](#pce)和[PSE](#pse)。
### PCE
Phone Book Client Equipment，即[PBAP](#pbap)协议中的电话簿客户端，作为数据请求方，可获取[PSE](#pse)的电话簿数据。典型设备如：车载蓝牙。
### PSE
Phone Book Server Equipment，即[PBAP](#pbap)协议中的电话簿服务端，存储原始电话簿数据（如联系人和通话记录）。典型设备如：手机。
### Profile
在蓝牙子系统中，一般特指某种蓝牙技术协议或者能力。例如：[A2DP](#a2dp)、[HFP](#hfp)和[HID](#hid)协议等。
### PSM
Protocol/Service Multiplexer，即协议/服务多路复用器。用于标识[L2CAP](#l2cap)层上的不同服务或协议。
## R
### RFCOMM
Radio Frequency Communication，即无线电频率通信协议。用于模拟传统的RS232串行通信（一种常见的有线数据传输标准），提供一种简单可靠的数据传输方式，支持多个同时连接的通道。
### RSSI
Received Signal Strength Indicator，是无线通信中用于量化接收端信号强度的指标，单位是dBm。
## S
### Service
在蓝牙协议中，一般特指[GATT](#gatt)协议中的服务。是一种包含多个特征值和所依赖的其他服务的数据结构，表示[BLE](#ble)设备的一种能力，通过[UUID](#uuid)标识。
### SPP
Serial Port Profile，即串口通信协议。可用于实现蓝牙设备间通信连接和传输数据。
## U
### UUID
Universally Unique Identifier，即通用唯一标识，是一个128比特的数据格式。在蓝牙技术中，可用于标识不同的[Profile](#profile)协议，也可用于[GATT](#gatt)协议中的服务、特征值和描述符。