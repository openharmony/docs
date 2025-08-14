# Connectivity Kit术语

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## A
### A2DP
Advanced Audio Distribution Profile，即高级音频分发协议。支持传输高品质音频。例如：使用蓝牙耳机听音乐。
### ACL
Asynchronous Connectionless link，即异步无连接链路。在蓝牙子系统中，表示设备间物理链路的连接情况。
## B
### BLE
Bluetooth Low Energy，即低功耗蓝牙。从蓝牙4.0开始支持的协议，相比于传统蓝牙，是支持低功耗、长续航的蓝牙通信技术。
### BR
Basic Rate，即蓝牙基础率。是一种蓝牙无线通信技术，用来表示传统蓝牙，主要用于文件和音频流的传输场景。
### Bluetooth SIG
Bluetooth Special Interest Group，即蓝牙技术联盟，发布蓝牙技术规范的组织。开发者可以在其官方网站获取详细的蓝牙技术文档。
## C
### Characteristic
GATT服务（Service）的核心数据单元，可进行数据读写，通过UUID唯一标识。
## D
### Descriptor
GATT特征值（Characteristic）的数据单元，用于描述特征值的附加信息和属性，可进行数据读写，通过UUID唯一标识。
## E
### EDR
Enhanced Data Rate，即蓝牙增强数据率。是蓝牙BR的增强版本，有更高的数据传输速率，和BR统称为传统蓝牙。
## G
### GATT
Generic Attribute Profile，即通用属性协议。是低功耗蓝牙（BLE）的核心协议，定义了基于服务（Service）、特征值（Characteristic）和描述符（Descriptor）进行蓝牙通信和传输数据的机制。
## H
### HFP
Hand Free Profile，即免提协议。用于实现蓝牙设备间的免提通话，支持双向语音通话和控制等功能。
### HID
Human Interface Device Profile，即人机接口协议，为经典蓝牙设计。可用于实现蓝牙无线人机交互设备连接间的低延迟双向通信。例如：键盘、鼠标、游戏手柄等设备与主机（如手机、平板和PC）间传输数据。
### HOGP
HID over GATT Profile，基于低功耗蓝牙的GATT协议实现的HID规范，将传统HID功能移植到BLE设备上复用，兼容键盘、鼠标、自拍杆等BLE设备的HID交互逻辑。
## M
### MAP
Message Access Profile，即消息访问协议。可用于实现蓝牙设备间的消息同步，支持短信、邮件等数据传输。
### MTU
Maximum Transmission Unit，即最大传输单元。表示网络中单次传输的最大数据包大小，单位是字节。
## O
### OPP
Object Push Profile，即对象推送协议。基于通用对象交换协议（Generic Object Exchange Profile，GOEP）构建，可用于实现设备间数据（如图片、文档等）传输。
## P
### PAN
Personal Area Network，即蓝牙个人局域网协议。支持设备间网络共享。
### PBAP
Phone Book Access Profile，即蓝牙电话簿访问协议。可用于实现蓝牙设备间的电话簿数据同步，支持联系人、通话记录等数据传输。
### Profile
在蓝牙子系统中，一般特指某种蓝牙技术协议或者能力。例如：A2DP、HFP和HID协议等。
## R
### RSSI
Received Signal Strength Indicator，是无线通信中用于量化接收端信号强度的指标，单位是dBm。
## S
### Service
在蓝牙协议中，一般特指GATT协议中的服务。是一种包含多个特征值和所依赖的其他服务的数据结构，表示BLE设备的一种能力，通过UUID唯一标识。
### SPP
Serial Port Profile，即串口通信协议。可用于实现蓝牙设备间通信连接和传输数据。
## U
### UUID
Universally Unique Identifier，即通用唯一标识，是一个128比特的数据格式。在蓝牙技术中，可用于标识不同的Profile协议，也可用于GATT协议中的服务、特征值和描述符。