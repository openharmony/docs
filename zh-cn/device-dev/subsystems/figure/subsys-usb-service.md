# USB<a name="ZH-CN_TOPIC_0000001052857350"></a>

-   [概述](#section175431838101617)

-   [USB服务架构](#section350923483241)
    -   [架构说明](#section350923485516)
    -   [生命周期](#section894546131154)

-   [主要功能介绍](#section951321854211)
    -   [USB设备管理列表](#section951321855211)
    -   [Function管理](#section951321856212)
    -   [USB设备权限管理](#section951321857213)

-   [接口说明](#section83365421647)
    -   [Host部分](#section83365421658)
    -   [Device部分](#section83365421669)
    -   [Port部分](#section83365421670)

-   [开发实例](#section54626568156)


## 概述<a name="section175431838101617"></a>

  USB设备分为Host设备（主机设备）和Device设备（从设备）。用户可通过Port Service来根据实际业务把运行OpenHarmony的设备切换为Host设备或者Device设备。目前在Host模式下，支持获取USB设备列表，USB设备权限管理，控制\批量的同异步数据传输等，在Device模式下，支持HDC（调试）、ACM（串口）、ECM（网口）等Function功能的切换。

## USB服务架构<a name="section350923483241"></a>

  USB服务系统分为USB FWK/API、USB Service、USB HDI、USB HAL四个部分。

  USB服务架构如下图所示:

  ![](figure/USB服务架构图.png "USB服务架构图")

## 架构说明<a name="section350923485516"></a>

### 架构原则
-   ### 结构性原则
    1.  可伸缩性:
    保证可维护性、灵活性，比如当需求发生变化时，只需要修改软件的一部分，不会影响到其他部分的代码，降低了层 与层之间的耦合度.
    2.  可扩展性:
    在对现有系统影响最小的情况下，同时能保持可持续扩展和稳定提升的能力.
    按照可扩展性的定义，一个具备良好可扩展性的架构设计应当符合开闭原则：对扩展开发，对修改关闭.
    3.  组件化:
    把重复的代码提取出来合并成为一个个组件，方便调用和复用，减少代码量.
    4.  模块化:
    将Host、Device、Port的功能按模块进行设计和开发，可独立管理.
    5.  配置化:
    将每个模块放入配置文件中进行配置管理，通过配置文件的修改来实现模块的增删.

-   ### 结构性原则
    1.  分层设计：
    将将功能进行有序的分组：层间关系的形成要遵循一定的规则。通过分层，可以限制子系统间的依赖关系，使系统以更松散的方式耦合，从而更易于维护。

### 外部接口描述
-   ### USBDevice:
    此类表示连接 鸿蒙设备的USB设备.
-   ### USBInterface:
    表示 USBDevice上的接口的类.
-   ### USBEndpoint:
    表示 USBInterface上的端点的类.
-   ### USBConfig:
    表示USBDevice的配置说明类，是对Device信息的补充.
-   ### UsbDevicePipe:
    此类用于向 USB 设备发送和接收数据和控制消息.
-   ### UsbRequest:
    此类用于生成一个USB请求包，用于同步或异步数据传输.

### 用例场景

USB设备建立连接之后，根据内核的识别判定调用USB Host Service或是USB Device Service。对应的用例场景分别如下

-   ### USB Host Service:
    获取USB设备列表、判断设备的权限、设备连接、数据传输（包括同步、异步两种模式），如下图所示:

![](figure/USB-Host_Service.png "USB Host Service")

-   ### USB Device Service:
    获取functions、设置functions 等场景，如下图所示:

![](figure/USB-Device_Service.png "USB Host Service")

USB Port Service的关键用例包括：Port信息的获取、设置Port角色，如下图所示:

![](figure/USB-Port_Service.png "USB Host Service")

### 交互场景

-   ### USB Host Service交互场景
1.  USB设备插拔:
    
    内核检测USB插入事件并通过Notify发出通知到HAL，HAL层通过回调处理通知消息，增加USB设备到USB设备列表.
    内核检测USB插入事件并通过Notify发出通知到HAL，HAL层通过回调处理通知消息，从USB设备列表中删除USB设备.

![](figure/USB插拔事件通知.png "USB插拔事件通知")

2.  数据收发:

    USB Device与Host端连接后，Host端获取Deivice信息，从DeviceList中找到对应的Device，执行OpenDevice并生成对应的Pipe，同步情况下调用Pipe的收发接口进行数据收发。异步的情况下通过Pipe生成一个Request对象，通过Request对象的queue方法进行异步数据收发.

-   ### USB Device Service交互场景
1.  设置functions:

    可以根据用户传递的function功能值将设备设置为acm(串口)、ecm(网口)、hdc(调试)功能，可以是单
    function功能，也可以是复合function功能。

2.  获取functions:

    获取当前设备functions功能值.

-   ### USB Port Service交互场景
1.  获取port列表:

    获取当前设备支持的port列表，每一个port对应设备的usb接口，每个port的id唯一.

2.  获取port支持的模式:

    根据portId 获取当前port支持的mode。支持的mode：host、device.

3.  设置port角色:

    给指定的port 设置电源role和数据role。电源role支持：source、sink；数据role支持：host、device.

4.  更新port信息:

    系统开始时或者设置port角色完成时，usbd会发消息通知到usb service层当前的的port信息，并且执行更新操作.

- ### USB FWK/API
    基于USB Service服务，使用NAPI技术，向上提供JS接口。

- ### USB Service
    使用C++代码实现，包含Host、Device、Port三个模块。基于HDI的接口，主要实现USB设备的列表管理、Function 管理、Port管理、USB设备权限管理等功能。

- ### USB HDI
    基于HAL层，向上提供C++接口。

- ### USB HAL
    使用C代码实现，基于Host SDK和Device SDK，封装了对USB设备的基本操作，同时通过HDF框架接收内核上报的信息。

## 生命周期<a name="section894546131154"></a>

  USB Service作为系统服务随系统启动、停止。
- ### OS INIT: 
    操作系统初始化阶段

- ### USB Service Start:
    USB Service的初始化阶段，进行一些初始化操作，初始化之后将USB Service挂起，等待事件触发和调用

- ### USB Service Active:
    USB Service的执行和调用阶段，具体描述为USB的插入触发了USB通知，并进行USB设备连接，创建数据连接通道，进行数据传输等一系列操作

- ### USB Service Background:
    当所有的USB设备被拔出之后，USB Service不再处理USB业务，在后台挂起，等待下一次的USB插入之后触发USB Service Active，或者在操作系统关机的时候进行销毁处理

- ### USB Service Stop:
    操作系统关机的时候，销毁USB Service

Service的生命周期如下图：

![](figure/Service生命周期.png "Service生命周期")

## 主要功能介绍<a name="section951321854211"></a>

- ### USB设备列表管理<a name="sectiong951321855211"></a>

  USB插拔事件通过订阅/发布的消息机制通知到Host Service，改变Device Map中的Device数量。应用层通过API接口调用从 Device Map中获取所有的Device设备列表。

    USB设备管理如下图：

![](figure/USB设备列表管理.png "USB设备列表管理")

- ### Function管理<a name="section951321856212"></a>

  Function Manager中定义好支持的function 列表。通过调用接口设置functions 和 获取当前functions，且能实现string和number的转换。
  HDC是通过修改SystemParameter实现加载和卸载；ACM和ECM是通过给ACM服务和ECM服务（基于HDF框架）发消息来实现加载和卸载。

    Function管理如下图:

![](figure/Function管理.png "Function管理")

- ### USB设备权限管理<a name="section951321857213"></a>

  当APP调用USB设备操作接口时，Host Service 使用设备唯一标识，在管理的权限列表中查询该设备是否有访问权限，若有权限，会执行操作，否则将返回权限不足信息。
  当APP无此设备的使用权限时，App可以调用权限申请接口（RequestRight），会在权限列表中加入App与设备对应的权限信息，后续进行USB操作时将正常执行。

    USB设备权限管理如下图:

![](figure/USB设备权限管理.png "USB设备权限管理")

## 接口说明<a name="section83365421647"></a>

- ### Host部分<a name="section83365421658"></a>

<a name="table1513255710559"></a>
<table><thead align="left"><tr id="row171321857155517"><th class="cellrowborder" valign="top" width="10.721072107210723%" id="mcps1.2.4.1.1"><p id="p6132957115511"><a name="p6132957115511"></a><a name="p6132957115511"></a>头文件</p>
</th>
<th class="cellrowborder" valign="top" width="66.36663666366637%" id="mcps1.2.4.1.2"><p id="p14132125715552"><a name="p14132125715552"></a><a name="p14132125715552"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.912291229122914%" id="mcps1.2.4.1.3"><p id="p18132205755516"><a name="p18132205755516"></a><a name="p18132205755516"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row13132357165514"><td class="cellrowborder" rowspan="16" valign="top" width="10.721072107210723%" headers="mcps1.2.4.1.1 "><p id="p15132185775510"><a name="p15132185775510"></a><a name="p15132185775510"></a>usb_srv_client.h</p>
<p id="p18132157175510"><a name="p18132157175510"></a><a name="p18132157175510"></a></p>
<p id="p2133757135510"><a name="p2133757135510"></a><a name="p2133757135510"></a></p>
</td>
<td class="cellrowborder" valign="top" width="66.36663666366637%" headers="mcps1.2.4.1.1 "><p id="p1213365714550"><a name="p1213365714550"></a><a name="p1213365714550"></a>int32_t OpenDevice(const UsbDevice &device, USBDevicePipe &pip);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p201331557185512"><a name="p201331557185512"></a><a name="p201331557185512"></a>打开USB设备，建立连接</p>
</td>
</tr>
<tr id="row171331657185514"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p913305715553"><a name="p913305715553"></a><a name="p913305715553"></a>int32_t HasRight(std::string deviceName);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p161332570553"><a name="p161332570553"></a><a name="p161332570553"></a>判断是否有权访问设备</p>
</td>
</tr>
<tr id="row41331557165518"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6133145713559"><a name="p6133145713559"></a><a name="p6133145713559"></a>int32_t RequestRight(std::string deviceName);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p131331557175510"><a name="p131331557175510"></a><a name="p131331557175510"></a>请求给定软件包的临时权限以访问设备</p>
</td>
</tr>
<tr id="row77021769584"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p77031566584"><a name="p77031566584"></a><a name="p77031566584"></a>int32_t GetDevices(std::vector<UsbDevice> &deviceList);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1470315695811"><a name="p1470315695811"></a><a name="p1470315695811"></a>获取USB设备列表</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>int32_t ClaimInterface(USBDevicePipe &pip, const UsbInterface &interface, bool force);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>打开接口，并申明独占接口，必须在数据传输前执行</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int32_t ReleaseInterface(USBDevicePipe &pip, const UsbInterface &interface);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>关闭接口，释放接口的占用，在停止数据传输后执行</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>int32_t BulkTransfer(USBDevicePipe &pip, const USBEndpoint &endpoint, std::vector<uint8_t> &vdata, int32_t timeout);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>在给定端点上执行批量数据传输， 返回读取或发送的数据长度，通过端点方向确定读取或发送数据</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int32_t ControlTransfer(USBDevicePipe &pip, const UsbCtrlTransfer &ctrl, std::vector<uint8_t> &vdata);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>对此设备执行端点零的控制事务，传输方向由请求类型决定</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>int32_t SetConfiguration(USBDevicePipe &pip, const USBConfig &config);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>设置设备当前使用的配置，通过配置值进行指定</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int32_t SetInterface(USBDevicePipe &pipe, const UsbInterface &interface);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>设置指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>int32_t GetRawDescriptors(std::vector<uint8_t> &vdata);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>获取原始的USB描述符</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int32_t GetFileDescriptor();</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>获取文件描述符</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>bool Close(const USBDevicePipe &pip);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>关闭设备，释放与设备相关的所有系统资源</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int32_t PipeRequestWait(USBDevicePipe &pip, int64_t timeout, UsbRequest &req);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>获取异步传输结果</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>int32_t RequestInitialize(UsbRequest &request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>初始化异步数据传输request</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int32_t RequestFree(UsbRequest &request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>释放异步数据传输request</p>
</td>
</tr>
<tr id="row1513316577554"><td class="cellrowborder" rowspan="27" valign="top" headers="mcps1.2.4.1.1 ">
<td class="cellrowborder" valign="top" width="66.36663666366637%" headers="mcps1.2.4.1.2 "><p id="p105259109581"><a name="p105259109581"></a><a name="p105259109581"></a>int32_t RequestAbort(UsbRequest &request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.3 "><p id="p752531095814"><a name="p752531095814"></a><a name="p752531095814"></a>取消待处理的数据请求</p>
</td>
</tr>
<tr id="row172902161193"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16290141681918"><a name="p16290141681918"></a><a name="p16290141681918"></a>int32_t RequestQueue(UsbRequest &request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1929141611198"><a name="p1929141611198"></a><a name="p1929141611198"></a>将指定的端点进行异步数据发送或者接收请求，数据传输方向由端点方向决定</p>
</td>
</tr>
</tbody>
</table>

- ### Device部分<a name="section83365421669"></a>

<a name="table1513255710559"></a>
<table><thead align="left"><tr id="row171321857155517"><th class="cellrowborder" valign="top" width="10.721072107210723%" id="mcps1.2.4.1.1"><p id="p6132957115511"><a name="p6132957115511"></a><a name="p6132957115511"></a>头文件</p>
</th>
<th class="cellrowborder" valign="top" width="66.36663666366637%" id="mcps1.2.4.1.2"><p id="p14132125715552"><a name="p14132125715552"></a><a name="p14132125715552"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.912291229122914%" id="mcps1.2.4.1.3"><p id="p18132205755516"><a name="p18132205755516"></a><a name="p18132205755516"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row13132357165514"><td class="cellrowborder" rowspan="16" valign="top" width="10.721072107210723%" headers="mcps1.2.4.1.1 "><p id="p15132185775510"><a name="p15132185775510"></a><a name="p15132185775510"></a>usb_srv_client.h</p>
<p id="p18132157175510"><a name="p18132157175510"></a><a name="p18132157175510"></a></p>
<p id="p2133757135510"><a name="p2133757135510"></a><a name="p2133757135510"></a></p>
</td>
<td class="cellrowborder" valign="top" width="66.36663666366637%" headers="mcps1.2.4.1.1 "><p id="p1213365714550"><a name="p1213365714550"></a><a name="p1213365714550"></a>int32_t GetCurrentFunctions(int32_t &funcs);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p201331557185512"><a name="p201331557185512"></a><a name="p201331557185512"></a>获取设备模式下的当前USB功能列表的数字组合掩码</p>
</td>
</tr>
<tr id="row171331657185514"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p913305715553"><a name="p913305715553"></a><a name="p913305715553"></a>int32_t SetCurrentFunctions(int32_t funcs);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p161332570553"><a name="p161332570553"></a><a name="p161332570553"></a>在设备模式下设置当前的USB功能列表</p>
</td>
</tr>
<tr id="row41331557165518"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6133145713559"><a name="p6133145713559"></a><a name="p6133145713559"></a>int32_t UsbFunctionsFromString(std::string funcs);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p131331557175510"><a name="p131331557175510"></a><a name="p131331557175510"></a>将给定的功能列表描述字符串转换为功能列表的数字组合掩码</p>
</td>
</tr>
<tr id="row77021769584"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p77031566584"><a name="p77031566584"></a><a name="p77031566584"></a>std::string UsbFunctionsToString(int32_t funcs);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1470315695811"><a name="p1470315695811"></a><a name="p1470315695811"></a>将给定的功能列表的数字组合掩码转换为功能列表描述字符串</p>
</td>
</tr>
</tbody>
</table>

- ### Port部分<a name="section83365421670"></a>

<a name="table1513255710559"></a>
<table><thead align="left"><tr id="row171321857155517"><th class="cellrowborder" valign="top" width="10.721072107210723%" id="mcps1.2.4.1.1"><p id="p6132957115511"><a name="p6132957115511"></a><a name="p6132957115511"></a>头文件</p>
</th>
<th class="cellrowborder" valign="top" width="66.36663666366637%" id="mcps1.2.4.1.2"><p id="p14132125715552"><a name="p14132125715552"></a><a name="p14132125715552"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="22.912291229122914%" id="mcps1.2.4.1.3"><p id="p18132205755516"><a name="p18132205755516"></a><a name="p18132205755516"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row13132357165514"><td class="cellrowborder" rowspan="16" valign="top" width="10.721072107210723%" headers="mcps1.2.4.1.1 "><p id="p15132185775510"><a name="p15132185775510"></a><a name="p15132185775510"></a>usb_srv_client.h</p>
<p id="p18132157175510"><a name="p18132157175510"></a><a name="p18132157175510"></a></p>
<p id="p2133757135510"><a name="p2133757135510"></a><a name="p2133757135510"></a></p>
</td>
<td class="cellrowborder" valign="top" width="66.36663666366637%" headers="mcps1.2.4.1.1 "><p id="p1213365714550"><a name="p1213365714550"></a><a name="p1213365714550"></a>int32_t GetSupportedModes(int32_t portId, int32_t &supportedModes);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p201331557185512"><a name="p201331557185512"></a><a name="p201331557185512"></a>获取指定的端口支持的模式列表的组合掩码</p>
</td>
</tr>
<tr id="row171331657185514"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p913305715553"><a name="p913305715553"></a><a name="p913305715553"></a>int32_t SetPortRole(int32_t portId, int32_t powerRole, int32_t dataRole);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p161332570553"><a name="p161332570553"></a><a name="p161332570553"></a>设置指定的端口支持的角色模式，包含充电角色、数据传输角色</p>
</td>
</tr>
<tr id="row41331557165518"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6133145713559"><a name="p6133145713559"></a><a name="p6133145713559"></a>int32_t GetPorts(std::vector<UsbPort> &usbPorts);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p131331557175510"><a name="p131331557175510"></a><a name="p131331557175510"></a>获取物理USB端口描述信息列表</p>
</td>
</tr>
</tbody>
</table>

## 开发实例<a name="section54626568156"></a>

1.  获取usb service实例

    ```
    static UsbSrvClient &g_usbClient = UsbSrvClient::GetInstance();
    ```

2.  获取usb设备列表

    ```
    std::vector<UsbDevice> deviceList;
    int32_t ret = g_usbClient.GetDevices(deviceList);
    ```

3.  打开设备

    ```
    USBDevicePipe pip;
    int32_t ret = g_usbClient.OpenDevice(dev, pip);
    ```

4.  打开接口

    ```
    g_usbClient.ClaimInterface(pip, interface, force);
    interface为deviceList中device的interface。
    ```

5.  数据传输

    ```
    g_usbClient.BulkTransfer(pipe, endpoint, vdata, timeout);
    ```
    pipe为打开设备后的数据传输通道，endpoint为device中数据传输的端点，vdata是需要传输或读取的二进制数据块，timeout为传输超时时长

6.  关闭接口

    关闭设备释放资源

    ```
    g_usbClient.ReleaseInterface(pipe, interface);
    g_usbClient.Close(pipe);
    ```
