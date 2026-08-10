# 蓝牙服务开发概述

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @chengguohong; @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## 概述
蓝牙技术是一种无线通信技术，可以在短距离内传输数据，该技术规范由蓝牙技术联盟（Bluetooth Special Interest Group, SIG）制定。可以用于连接手机、耳机、音箱、键盘、鼠标、打印机等各种设备。目前蓝牙有两种常见的技术分类：传统蓝牙（BR/EDR）和低功耗蓝牙（BLE）。

蓝牙的实现原理是基于无线电技术的短距离通信协议，使用2.4GHz频段的无线电波进行通信，使用频率跳跃技术（Frequency Hopping Spread Spectrum，FHSS）来避免与其他无线设备的干扰。在通信过程中，蓝牙设备会发送和接收数据包，并且使用不同的蓝牙协议来控制通信流程和数据传输。

## 传统蓝牙
蓝牙基础率/增强数据率（Basic Rate/Enhanced Data Rate，BR/EDR），也被称为传统蓝牙。蓝牙EDR技术是蓝牙BR技术的增强版本，有更高的数据传输速率，比BR快2\~3倍，最高可达2\~3Mbps。在理想条件下，通信范围约100米。

传统蓝牙提供了多样化且成熟的技术协议。例如：高级音频分发、免提通话、个人局域网、电话簿访问等协议。利用这些技术，使得传统蓝牙可以满足许多不同应用场景下的多样化需求。例如：使用蓝牙耳机、音响等设备听音乐，通过车载访问手机电话本、短信等数据，实现设备间的数据共享。

## 低功耗蓝牙
低功耗蓝牙（Bluetooth Low Energy, BLE）是从蓝牙4.0开始支持的技术。相比于传统蓝牙，BLE在保障一定的传输速率情况下，具备更低功耗的特点，广泛使用于续航要求较高的蓝牙设备中。其最高传输速率可达1Mbps，通信范围通常为10米左右。

相比于传统蓝牙，BLE以其低功耗的特点，广泛应用于穿戴设备、智能家居和物联网传感器等领域。

## 蓝牙设备地址类型

在蓝牙服务开发过程中，涉及两种维度的地址类型定义。

![bluetooth address type](figures/bt_address_type.png)

**图1** 蓝牙设备地址类型

- 蓝牙子系统定义的地址类型。蓝牙设备的实际MAC地址属于用户的隐私信息，在发现设备的过程中，蓝牙子系统会给每个蓝牙外设分配一个虚拟MAC地址，并保存该虚拟MAC地址和外设实际MAC地址的映射关系。

- 蓝牙协议定义的地址类型。蓝牙协议定义的蓝牙设备地址类型主要可以分为两大类：Public Address和Random Address。传统蓝牙使用的是Public Address，低功耗蓝牙可以使用Public Address和Random Address。其中，Random Address又包括Static Random Address和Private Random Address两种类型。Private Random Address可以继续分为Non-resolvable Private Address和Resolvable Private Address两种类型。每种地址类型介绍如下：

| 类型                | 说明     |
| ------------------ |  ------ |
| Public Address       | 公共设备地址，该类型地址由IEEE组织分配并保证唯一性，永久不变。|
| Static Random Address       | 静态随机地址，该类型地址在蓝牙设备上电初始化时随机生成，本次上电周期内不会改变。|
| Resolvable Private Address      | 可解析私有地址，该类型地址通过一组地址解析密钥（Identity Resolving Key, IRK）生成，会定期（蓝牙协议建议15分钟更新一次）发生变化。若一个蓝牙设备A拥有另一个蓝牙设备B的IRK，即可通过解析设备B的可解析私有地址来识别设备B。|
| Non-resolvable Private Address       | 不可解析私有地址，该类型地址是完全随机的临时地址，会定期（蓝牙协议建议15分钟更新一次）发生变化，难以追踪。|

## 设备角色

在蓝牙设备的配对和连接过程中，根据设备在连接建立阶段所表现出的主动或被动行为，可以将其定义为中心设备（Central）和外围设备（Peripheral）两种角色。

在传统蓝牙中，通过查询来发现周围设备，并主动发起配对和连接的设备称为中心设备，响应其他设备的查询并接受配对和连接请求的设备称为外围设备。

在低功耗蓝牙中，扫描其他设备并主动发起连接的设备称为中心设备，发送广播并接受其他设备连接请求的设备称为外围设备。

<!--RP1-->

<!--RP1End-->