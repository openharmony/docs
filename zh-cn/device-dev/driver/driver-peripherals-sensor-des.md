# SENSOR<a name="ZH-CN_TOPIC_0000001078401780"></a>

- [概述](##概述)
  - [功能简介](###功能简介)
  - [基本概念](###基本概念)
  - [运作机制](###运作机制)
  
- [开发指导](##开发指导)
  - [场景介绍](###场景介绍)
  - [接口说明](#section188213414114)
  - [开发步骤](#section7893102915819)
  - [调测验证](#section106021256121219)
  

## 概述

### 功能简介

Sensor驱动模型屏蔽硬件器件差异，为上层Sensor服务系统提供稳定的Sensor基础能力接口，包括Sensor列表查询、Sensor启停、Sensor订阅及取消订阅，Sensor参数配置等功能；Sensor设备驱动的开发是基于HDF驱动框架基础上，结合操作系统适配层（OSAL）和平台驱动接口（比如I2C/SPI/UART总线等平台资源）能力，屏蔽不同操作系统和平台总线资源差异，实现Sensor驱动“一次开发，多系统部署”的目标。Sensor驱动模型如[图1](#fig10451455446)所示：<a name="section3634112111"></a>

**图 1**  Sensor驱动模型图<a name="fig10451455446"></a>  
![Sensor驱动模型图](figures/Sensor%E9%A9%B1%E5%8A%A8%E6%A8%A1%E5%9E%8B%E5%9B%BE.png)

### 基本概念

目前根据sensorId将Sensor分为医学类Sensor、传统类Sensor两种。

- 医学类Sensor：已订阅的sensorId枚举值在128-160范围的为医学类Sensor。

- 传统类Sensor：已订阅的sensorId枚举值不在128-160范围的为传统类Sensor。

### 运作机制

通过介绍Sensor驱动模型的加载以及运行流程，对模型内部关键组件以及关联组件之间的关系进行了划分，整体加载流程如[图2](#Sensor驱动运行图)所示：

**图 2** Sensor驱动运行图

![Sensor驱动运行图](figures/Sensor%E9%A9%B1%E5%8A%A8%E8%BF%90%E8%A1%8C%E5%9B%BE.png)

Sensor驱动模型以标准系统Hi3516DV300产品中的加速度传感器驱动为例，介绍整个驱动加载及运行流程：

1. 从device info HCS 的Sensor Host读取Sensor设备管理配置信息。
2. HDF配置框架从HCB数据库解析Sensor设备管理配置信息，并关联对应设备驱动。
3. 加载并初始化Sensor设备管理驱动。
4. Sensor设备管理驱动向HDI发布Sensor基础能力接口。
5. 从device info HCS 的Sensor Host读取加速度传感器驱动配置信息。
6. 加载加速度传感器抽象驱动，调用初始化接口，完成Sensor器件驱动资源分配和数据处理队列创建。
7. 从accel_xxx_config HCS读取加速度传感器差异化驱动配置和私有化配置信息。
8. 加速度传感器差异化驱动，调用通用配置解析接口，完成器件属性信息解析，器件寄存器解析。
9. 加速度传感器差异化驱动完成器件探测，并分配加速度传感器配置资源，完成加速度传感器差异化接口注册。
10. 加速度传感器探测成功之后，加速度传感器差异化驱动通知加速度传感器抽象驱动，注册加速度传感器设备到Sensor设备管理中。

## 开发指导

### 场景介绍

- 通过重力和陀螺仪传感器数据，能感知设备倾斜和旋转量，提高用户在游戏场景中的体验。
- 通过接近光传感器数据，感知距离遮挡物的距离，使设备能够自动亮灭屏，达到防误触目的。例如：通话时，当靠近手机时，关闭屏幕，达到降低功耗的作用。
- 通过气压计传感器数据，可以准确的判断设备当前所处的海拔。
- 通过环境光传感器数据，设备能够实现背光自动调节。
- 通过霍尔传感器数据，设备可以实现皮套功能，皮套合上，手机上开一个小窗口，可降低功耗。

### 接口说明<a name="section188213414114"></a>

Sensor驱动模型对外开放的API接口能力如下：

- 提供Sensor HDI（Hardware  Driver  Interface）能力接口，简化服务开发。
- 提供Sensor驱动模型能力接口：
  - 依赖HDF驱动框架实现Sensor器件驱动的注册，加载，去注册，器件探测等能力。
  - 提供同一类型Sensor器件驱动归一接口, 寄存器配置解析操作接口，总线访问抽象接口，平台抽象接口。
- 提供开发者实现的能力接口：依赖HDF驱动框架的HCS（HDF  Configuration  Source）配置管理，根据同类型Sensor差异化配置，实现Sensor器件参数序列化配置和器件部分操作接口，简化Sensor器件驱动开发。

Sensor驱动模型对外开放的API接口能力的具体实现参考[表1](#table203963834718)：

**表 1**  Sensor驱动模型对外API接口功能介绍

<a name="table203963834718"></a>

<table><thead align="left"><tr id="row173964834716"><th class="cellrowborder" valign="top" width="8.260000000000002%" id="mcps1.2.4.1.1"><p id="p17401913133218"><a name="p17401913133218"></a><a name="p17401913133218"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="45.4%" id="mcps1.2.4.1.2"><p id="p20921103144918"><a name="p20921103144918"></a><a name="p20921103144918"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="46.339999999999996%" id="mcps1.2.4.1.3"><p id="p109216317495"><a name="p109216317495"></a><a name="p109216317495"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row4397198154712"><td class="cellrowborder" valign="top" width="8.260000000000002%" headers="mcps1.2.4.1.1 "><p id="p8437193673211"><a name="p8437193673211"></a><a name="p8437193673211"></a>查询操作</p>
</td>
<td class="cellrowborder" valign="top" width="45.4%" headers="mcps1.2.4.1.2 "><p id="p11001322173912"><a name="p11001322173912"></a><a name="p11001322173912"></a>int32_t <strong id="b935414557240"><a name="b935414557240"></a><a name="b935414557240"></a>GetAllSensors</strong>(struct SensorInformation **sensorInfo, int32_t *count)</p>
</td>
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p199227318499"><a name="p199227318499"></a><a name="p199227318499"></a>获取系统中注册的所有传感器信息，一组完整传感器信息包括传感器名字、设备厂商、固件版本号、硬件版本号、传感器类型编号、传感器标识、最大量程、精度、功耗。</p>
</td>
</tr>
<tr id="row1839716854716"><td class="cellrowborder" rowspan="5" valign="top" width="8.260000000000002%" headers="mcps1.2.4.1.1 "><p id="p06071477324"><a name="p06071477324"></a><a name="p06071477324"></a>配置操作</p>
</td>
<td class="cellrowborder" valign="top" width="45.4%" headers="mcps1.2.4.1.2 "><p id="p38874252376"><a name="p38874252376"></a><a name="p38874252376"></a>int32_t <strong id="b199602219271"><a name="b199602219271"></a><a name="b199602219271"></a>Enable</strong>(int32_t sensorId)</p>
</td>
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p5922331114916"><a name="p5922331114916"></a><a name="p5922331114916"></a>使能指定传感器设备，只有数据订阅者使能传感器后，才能获取订阅的传感器数据。</p>
</td>
</tr>
<tr id="row6397138134713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6923143184914"><a name="p6923143184914"></a><a name="p6923143184914"></a>int32_t <strong id="b84601875330"><a name="b84601875330"></a><a name="b84601875330"></a>Disable</strong>(int32_t sensorId)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p139231531184912"><a name="p139231531184912"></a><a name="p139231531184912"></a>去使能指定传感器设备。</p>
</td>
</tr>
<tr id="row43981283476"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p992473112496"><a name="p992473112496"></a><a name="p992473112496"></a>int32_t <strong id="b16691194511438"><a name="b16691194511438"></a><a name="b16691194511438"></a>SetBatch</strong>(iint32_t sensorId, int64_t samplingInterval, int64_t reportInterval)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14924203134910"><a name="p14924203134910"></a><a name="p14924203134910"></a>设置指定传感器的数据采样间隔和数据上报间隔。</p>
</td>
</tr>
<tr id="row439813812472"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p170411511281"><a name="p170411511281"></a><a name="p170411511281"></a>int32_t <strong id="b170414153284"><a name="b170414153284"></a><a name="b170414153284"></a>SetMode</strong>(int32_t sensorId, int32_t mode)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107051159281"><a name="p107051159281"></a><a name="p107051159281"></a>设置指定传感器的工作模式，不同的工作模式，上报数据方式不同。</p>
</td>
</tr>
<tr id="row123998813470"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p492513120494"><a name="p492513120494"></a><a name="p492513120494"></a>int32_t <strong id="b7501191019330"><a name="b7501191019330"></a><a name="b7501191019330"></a>SetOption</strong>(int32_t sensorId, uint32_t option)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5926031124914"><a name="p5926031124914"></a><a name="p5926031124914"></a>设置指定传感器量程，精度等可选配置。</p>
</td>
</tr>
<tr id="row939914814478"><td class="cellrowborder" rowspan="2" valign="top" width="8.260000000000002%" headers="mcps1.2.4.1.1 "><p id="p1039815743211"><a name="p1039815743211"></a><a name="p1039815743211"></a>数据订阅操作</p>
</td>
<td class="cellrowborder" valign="top" width="45.4%" headers="mcps1.2.4.1.2 "><p id="p11530101054411"><a name="p11530101054411"></a><a name="p11530101054411"></a>int32_t <strong id="b0569161217334"><a name="b0569161217334"></a><a name="b0569161217334"></a>Register</strong>(int32_t groupId, RecordDataCallback cb);</p>
</td>
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p892633118493"><a name="p892633118493"></a><a name="p892633118493"></a>订阅者根据不同groupId注册传感器数据回调函数，系统会将获取到的传感器数据上报给订阅者。</p>
</td>
</tr>
<tr id="row10716713314"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p196491214133110"><a name="p196491214133110"></a><a name="p196491214133110"></a>int32_t <strong id="b13758151483317"><a name="b13758151483317"></a><a name="b13758151483317"></a>Unregister</strong>(int32_t groupId, RecordDataCallback cb)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5817133119"><a name="p5817133119"></a><a name="p5817133119"></a>订阅者根据groupId和回调函数注销对应订阅者的传感器数据回调函数。</p>
</td>
</tr>
</tbody>
</table>


Sensor驱动模型对驱动开发者开放的功能接口，驱动开发者无需实现，直接使用，参考[表2](#table1156812588320)：

 **表2** Sensor驱动模型对驱动开发者开放的功能接口列表

<a name="table1156812588320"></a>

<table><thead align="left"><tr id="row756817584327"><th class="cellrowborder" valign="top" width="8.550855085508552%" id="mcps1.2.4.1.1"><p id="p7568125873219"><a name="p7568125873219"></a><a name="p7568125873219"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="45.53455345534553%" id="mcps1.2.4.1.2"><p id="p1756812582328"><a name="p1756812582328"></a><a name="p1756812582328"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="45.91459145914592%" id="mcps1.2.4.1.3"><p id="p35681558183210"><a name="p35681558183210"></a><a name="p35681558183210"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row756875811329"><td class="cellrowborder" rowspan="3" valign="top" width="8.550855085508552%" headers="mcps1.2.4.1.1 "><p id="p5974193991911"><a name="p5974193991911"></a><a name="p5974193991911"></a>设备管理操作接口</p>
</td>
<td class="cellrowborder" valign="top" width="45.53455345534553%" headers="mcps1.2.4.1.2 "><p id="p18569158173210"><a name="p18569158173210"></a><a name="p18569158173210"></a>int32_t <strong id="b4994112595516"><a name="b4994112595516"></a><a name="b4994112595516"></a>AddSensorDevice</strong>(const struct SensorDeviceInfo *deviceInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="45.91459145914592%" headers="mcps1.2.4.1.3 "><p id="p356935816328"><a name="p356935816328"></a><a name="p356935816328"></a>添加当前类型的传感器设备到传感器设备管理。</p>
</td>
</tr>
<tr id="row195691858113219"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1156945883215"><a name="p1156945883215"></a><a name="p1156945883215"></a>int32_t <strong id="b1736762975518"><a name="b1736762975518"></a><a name="b1736762975518"></a>DeleteSensorDevice</strong>(const struct SensorBasicInfo *sensorBaseInfo)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p2569145833214"><a name="p2569145833214"></a><a name="p2569145833214"></a>删除传感器设备管理里指定的传感器设备。</p>
</td>
</tr>
<tr id="row15699589321"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6569105811328"><a name="p6569105811328"></a><a name="p6569105811328"></a>int32_t <strong id="b1174510321555"><a name="b1174510321555"></a><a name="b1174510321555"></a>ReportSensorEvent</strong>(const struct SensorReportEvent *events)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15691858193220"><a name="p15691858193220"></a><a name="p15691858193220"></a>上报指定类型传感器的数据到用户侧。</p>
</td>
</tr>
<tr id="row17569145814329"><td class="cellrowborder" rowspan="2" valign="top" width="8.550855085508552%" headers="mcps1.2.4.1.1 "><p id="p10589113932619"><a name="p10589113932619"></a><a name="p10589113932619"></a>Sensor抽象总线</p>
</td>
<td class="cellrowborder" valign="top" width="45.53455345534553%" headers="mcps1.2.4.1.2 "><p id="p145705585322"><a name="p145705585322"></a><a name="p145705585322"></a>int32_t <strong id="b15560203515558"><a name="b15560203515558"></a><a name="b15560203515558"></a>ReadSensor</strong>(struct SensorBusCfg *busCfg, uint16_t regAddr, uint8_t *data, uint16_t dataLen)</p>
</td>
<td class="cellrowborder" valign="top" width="45.91459145914592%" headers="mcps1.2.4.1.3 "><p id="p1657018586322"><a name="p1657018586322"></a><a name="p1657018586322"></a>按照配置的总线方式，读取传感器寄存器配置数据。</p>
</td>
</tr>
<tr id="row28712021112011"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p38722218200"><a name="p38722218200"></a><a name="p38722218200"></a>int32_t <strong id="b573774595514"><a name="b573774595514"></a><a name="b573774595514"></a>WriteSensor</strong>(struct SensorBusCfg *busCfg, uint8_t *writeData, uint16_t len)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p6872112112201"><a name="p6872112112201"></a><a name="p6872112112201"></a>按照配置的总线方式，将传感器配置数据写入寄存器。</p>
</td>
</tr>
<tr id="row19401042245"><td class="cellrowborder" valign="top" width="8.550855085508552%" headers="mcps1.2.4.1.1 "><p id="p694020492417"><a name="p694020492417"></a><a name="p694020492417"></a>通用配置操作接口</p>
</td>
<td class="cellrowborder" valign="top" width="45.53455345534553%" headers="mcps1.2.4.1.2 "><p id="p1794064142418"><a name="p1794064142418"></a><a name="p1794064142418"></a>int32_t <strong id="b1740939195611"><a name="b1740939195611"></a><a name="b1740939195611"></a>SetSensorRegCfgArray</strong>(struct SensorBusCfg *busCfg, const struct SensorRegCfgGroupNode *group);</p>
</td>
<td class="cellrowborder" valign="top" width="45.91459145914592%" headers="mcps1.2.4.1.3 "><p id="p49409417249"><a name="p49409417249"></a><a name="p49409417249"></a>根据传感器总线类型信息，下发寄存器分组配置。</p>
</td>
</tr>
<tr id="row1494015418246"><td class="cellrowborder" rowspan="5" valign="top" width="8.550855085508552%" headers="mcps1.2.4.1.1 "><p id="p185291624202618"><a name="p185291624202618"></a><a name="p185291624202618"></a>配置解析操作接口</p>
<p id="p978482418524"><a name="p978482418524"></a><a name="p978482418524"></a></p>
</td>
<td class="cellrowborder" valign="top" width="45.53455345534553%" headers="mcps1.2.4.1.2 "><p id="p994194132410"><a name="p994194132410"></a><a name="p994194132410"></a>int32_t <strong id="b109631149171514"><a name="b109631149171514"></a><a name="b109631149171514"></a>GetSensorBaseConfigData</strong>(const struct DeviceResourceNode *node, struct SensorCfgData *config)</p>
</td>
<td class="cellrowborder" valign="top" width="45.91459145914592%" headers="mcps1.2.4.1.3 "><p id="p79411640248"><a name="p79411640248"></a><a name="p79411640248"></a>根据传感器设备HCS资源配置，获取传感器信息，总线配置信息，属性配置等基本配置信息，并初始化对应的基本配置数据结构体。</p>
</td>
</tr>
<tr id="row1171817565518"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7718165615113"><a name="p7718165615113"></a><a name="p7718165615113"></a>int32_t <strong id="b14392155271515"><a name="b14392155271515"></a><a name="b14392155271515"></a>ParseSensorRegConfig</strong>(struct SensorCfgData *config)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p171885685120"><a name="p171885685120"></a><a name="p171885685120"></a>根据传感器设备HCS资源配置，解析寄存器分组信息，并初始化配置数据结构体。</p>
</td>
</tr>
<tr id="row394144192414"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p99411144241"><a name="p99411144241"></a><a name="p99411144241"></a>void <strong id="b1322165619152"><a name="b1322165619152"></a><a name="b1322165619152"></a>ReleaseSensorAllRegConfig</strong>(struct SensorCfgData *config)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17941154152419"><a name="p17941154152419"></a><a name="p17941154152419"></a>释放传感器配置数据结构体里分配的资源。</p>
</td>
</tr>
<tr id="row10589154102611"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4557141217521"><a name="p4557141217521"></a><a name="p4557141217521"></a>int32_t <strong id="b1206195914157"><a name="b1206195914157"></a><a name="b1206195914157"></a>GetSensorBusHandle</strong>(struct SensorBusCfg *busCfg)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p953821245219"><a name="p953821245219"></a><a name="p953821245219"></a>获取传感器总线句柄信息。</p>
</td>
</tr>
<tr id="row6784142455212"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p478492410522"><a name="p478492410522"></a><a name="p478492410522"></a>int32_t <strong id="b9443344101610"><a name="b9443344101610"></a><a name="b9443344101610"></a>ReleaseSensorBusHandle</strong>(struct SensorBusCfg *busCfg)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1878422485212"><a name="p1878422485212"></a><a name="p1878422485212"></a>释放传感器句柄信息。</p>
</td>
</tr>
</tbody>
</table>



Sensor驱动模型要求驱动开发者实现的接口功能，参考[表3](#table1083014911336)：

**表 3**  Sensor驱动模型要求驱动开发者实现的接口列表

<a name="table1083014911336"></a>

<table><thead align="left"><tr id="row208301997332"><th class="cellrowborder" valign="top" width="8.41084108410841%" id="mcps1.2.4.1.1"><p id="p1777364318152"><a name="p1777364318152"></a><a name="p1777364318152"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="45.77457745774577%" id="mcps1.2.4.1.2"><p id="p5773174317157"><a name="p5773174317157"></a><a name="p5773174317157"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="45.81458145814582%" id="mcps1.2.4.1.3"><p id="p1777319437155"><a name="p1777319437155"></a><a name="p1777319437155"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1880425111572"><td class="cellrowborder" rowspan="8" valign="top" width="8.41084108410841%" headers="mcps1.2.4.1.1 "><p id="p598171454520"><a name="p598171454520"></a><a name="p598171454520"></a>基本功能操作</p>
</td>
<td class="cellrowborder" valign="top" width="45.77457745774577%" headers="mcps1.2.4.1.2 "><p id="p880485195711"><a name="p880485195711"></a><a name="p880485195711"></a>int32_t <strong id="b16497123107"><a name="b16497123107"></a><a name="b16497123107"></a>init</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" width="45.81458145814582%" headers="mcps1.2.4.1.3 "><p id="p1480465165710"><a name="p1480465165710"></a><a name="p1480465165710"></a>传感器设备探测成功后，需要对传感器设备初始化配置。</p>
</td>
</tr>
<tr id="row178311493339"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p208318963320"><a name="p208318963320"></a><a name="p208318963320"></a>int32_t <strong id="b189921571402"><a name="b189921571402"></a><a name="b189921571402"></a>Enable</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p68310953312"><a name="p68310953312"></a><a name="p68310953312"></a>根据当前传感器设备的HCS配置，下发传感器设备使能操作组的寄存器配置。</p>
</td>
</tr>
<tr id="row0831129153318"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p0831169183314"><a name="p0831169183314"></a><a name="p0831169183314"></a>int32_t <strong id="b13541291106"><a name="b13541291106"></a><a name="b13541291106"></a>Disable</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p138314912336"><a name="p138314912336"></a><a name="p138314912336"></a>根据当前传感器设备的HCS配置，下发传感器设备去使能操作组的寄存器配置。</p>
</td>
</tr>
<tr id="row178311093334"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p583118920338"><a name="p583118920338"></a><a name="p583118920338"></a>int32_t <strong id="b111117118017"><a name="b111117118017"></a><a name="b111117118017"></a>SetBatch</strong>(int64_t samplingInterval, int64_t reportInterval)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p08311903315"><a name="p08311903315"></a><a name="p08311903315"></a>根据数据采样率和数据上报间隔，配置当前传感器设备的数据上报线程处理时间。</p>
</td>
</tr>
<tr id="row1356419421422"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9565174218421"><a name="p9565174218421"></a><a name="p9565174218421"></a>int32_t <strong id="b13702551143412"><a name="b13702551143412"></a><a name="b13702551143412"></a>SetMode</strong>(int32_t mode)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p356524224213"><a name="p356524224213"></a><a name="p356524224213"></a>配置当前传感器设备数据上报方式。</p>
</td>
</tr>
<tr id="row12565104264215"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p17565104210429"><a name="p17565104210429"></a><a name="p17565104210429"></a>int32_t <strong id="b96811512011"><a name="b96811512011"></a><a name="b96811512011"></a>SetOption</strong>(uint32_t option)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4565104214213"><a name="p4565104214213"></a><a name="p4565104214213"></a>根据可选配置、下发量程和精度等寄存器配置。</p>
</td>
</tr>
<tr id="row380240111218"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1181184016120"><a name="p1181184016120"></a><a name="p1181184016120"></a>void <strong id="b1613451717016"><a name="b1613451717016"></a><a name="b1613451717016"></a>ReadSensorData</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p7815401121"><a name="p7815401121"></a><a name="p7815401121"></a>实现传感器的数据读取函数。</p>
</td>
</tr>
</tbody>
</table>



接口实现参考[开发步骤](#section7893102915819)章节。

### 开发步骤<a name="section7893102915819"></a>
1. 基于HDF驱动框架，按照驱动Driver Entry程序，完成加速度抽象驱动开发，主要由Bind、Init、Release、Dispatch函数接口实现。

   - 加速度传感器驱动入口函数实现

     ```c
     /* 注册加速度计传感器入口数据结构体对象 */
     struct HdfDriverEntry g_sensorAccelDevEntry = {
         .moduleVersion = 1, //加速度计传感器模块版本号
         .moduleName = "HDF_SENSOR_ACCEL", //加速度计传感器模块名，要与device_info.hcs文件里的加速度计moduleName字段值一样
         .Bind = BindAccelDriver, // 加速度计传感器绑定函数
         .Init = InitAccelDriver, // 加速度计传感器初始化函数
         .Release = ReleaseAccelDriver, // 加速度计传感器资源释放函数
     };
     
     /* 调用HDF_INIT将驱动入口注册到HDF框架中，在加载驱动时HDF框架会先调用Bind函数,再调用Init函数加载该驱动，当Init调用异常时，HDF框架会调用Release释放驱动资源并退出 */
     HDF_INIT(g_sensorAccelDevEntry);
     ```

   - 加速度传感器驱动操作接口实现

     ```c
     /* 加速度计传感器驱动对外提供的服务绑定到HDF框架 */
     int32_t AccelBindDriver(struct HdfDeviceObject *device)
     {
         CHECK_NULL_PTR_RETURN_VALUE(device, HDF_ERR_INVALID_PARAM);
     
         struct AccelDrvData *drvData = (struct AccelDrvData *)OsalMemCalloc(sizeof(*drvData));
         if (drvData == NULL) {
             HDF_LOGE("%s: Malloc accel drv data fail!", __func__);
             return HDF_ERR_MALLOC_FAIL;
         }
     
         drvData->ioService.Dispatch = DispatchAccel;
         drvData->device = device;
         device->service = &drvData->ioService;
         g_accelDrvData = drvData;
         return HDF_SUCCESS;
     }
     
     /* 注册加速度计传感器驱动归一化的接口函数 */
     static int32_t InitAccelOps(struct SensorCfgData *config, struct SensorDeviceInfo *deviceInfo)
     {
         CHECK_NULL_PTR_RETURN_VALUE(config, HDF_ERR_INVALID_PARAM);
     
         deviceInfo->ops.Enable = SetAccelEnable;
         deviceInfo->ops.Disable = SetAccelDisable;
         deviceInfo->ops.SetBatch = SetAccelBatch;
         deviceInfo->ops.SetMode = SetAccelMode;
         deviceInfo->ops.SetOption = SetAccelOption;
     
         if (memcpy_s(&deviceInfo->sensorInfo, sizeof(deviceInfo->sensorInfo),
             &config->sensorInfo, sizeof(config->sensorInfo)) != EOK) {
             HDF_LOGE("%s: Copy sensor info failed", __func__);
             return HDF_FAILURE;
         }
     
         return HDF_SUCCESS;
     }
     /* 提供给差异化驱动的初始化接口，完成加速度器件基本配置信息解析（加速度信息，加速度总线配置，加速度器件探测寄存器配置），器件探测，器件寄存器解析 */
     static int32_t InitAccelAfterDetected(struct SensorCfgData *config)
     {
         struct SensorDeviceInfo deviceInfo;
         CHECK_NULL_PTR_RETURN_VALUE(config, HDF_ERR_INVALID_PARAM);
         /* 初始化加速度计接口函数 */
         if (InitAccelOps(config, &deviceInfo) != HDF_SUCCESS) {
             HDF_LOGE("%s: Init accel ops failed", __func__);
             return HDF_FAILURE;
         }
         /* 注册加速度计设备到传感器管理模块 */
         if (AddSensorDevice(&deviceInfo) != HDF_SUCCESS) {
             HDF_LOGE("%s: Add accel device failed", __func__);
             return HDF_FAILURE;
         }
         /* 器件寄存器解析 */
         if (ParseSensorRegConfig(config) != HDF_SUCCESS) {
             HDF_LOGE("%s: Parse sensor register failed", __func__);
             (void)DeleteSensorDevice(&config->sensorInfo);
             ReleaseSensorAllRegConfig(config);
             return HDF_FAILURE;
         }
         return HDF_SUCCESS;
     }
     struct SensorCfgData *AccelCreateCfgData(const struct DeviceResourceNode *node)
     {
         ……
         /* 如果探测不到器件在位，返回进行下个器件探测 */
         if (drvData->detectFlag) {
             HDF_LOGE("%s: Accel sensor have detected", __func__);
             return NULL;
         }
         if (drvData->accelCfg == NULL) {
             HDF_LOGE("%s: Accel accelCfg pointer NULL", __func__);
             return NULL;
         }
         /* 设备基本配置信息解析 */
         if (GetSensorBaseConfigData(node, drvData->accelCfg) != HDF_SUCCESS) {
             HDF_LOGE("%s: Get sensor base config failed", __func__);
             goto BASE_CONFIG_EXIT;
         }
         /* 如果探测不到器件在位，返回进行下个器件探测 */
         if (DetectSensorDevice(drvData->accelCfg) != HDF_SUCCESS) {
             HDF_LOGI("%s: Accel sensor detect device no exist", __func__);
             drvData->detectFlag = false;
             goto BASE_CONFIG_EXIT;
         }
         drvData->detectFlag = true;
         /* 器件寄存器解析 */
         if (InitAccelAfterDetected(drvData->accelCfg) != HDF_SUCCESS) {
             HDF_LOGE("%s: Accel sensor detect device no exist", __func__);
             goto INIT_EXIT;
         }
         return drvData->accelCfg;
         ……
     }
     /* 加速度计传感器驱动初始化入口函数，主要功能为对传感器私有数据的结构体对象进行初始化，传感器HCS数据配置对象空间分配，传感器HCS数据配置初始化入口函数调用，传感器设备探测是否在位功能，传感器数据上报定时器创建，传感器归一化接口注册，传感器设备注册功能 */ 
     int32_t AccelInitDriver(struct HdfDeviceObject *device)
     {
         ……
         /* 工作队列资源初始化 */
         if (InitAccelData(drvData) != HDF_SUCCESS) {
             HDF_LOGE("%s: Init accel config failed", __func__);
             return HDF_FAILURE;
         }
         /* 分配加速度配置信息资源 */
         drvData->accelCfg = (struct SensorCfgData *)OsalMemCalloc(sizeof(*drvData->accelCfg));
         if (drvData->accelCfg == NULL) {
             HDF_LOGE("%s: Malloc accel config data failed", __func__);
             return HDF_FAILURE;
         }
         /* 注册寄存器分组信息 */
         drvData->accelCfg->regCfgGroup = &g_regCfgGroup[0];
         ……
         return HDF_SUCCESS;
     }
     /* 释放驱动初始化时分配的资源 */
     void AccelReleaseDriver(struct HdfDeviceObject *device)
     {
         CHECK_NULL_PTR_RETURN(device);
         struct AccelDrvData *drvData = (struct AccelDrvData *)device->service;
         CHECK_NULL_PTR_RETURN(drvData);
         /* 器件在位，释放已分配资源 */
         if (drvData->detectFlag) {
             AccelReleaseCfgData(drvData->accelCfg);
         }
         OsalMemFree(drvData->accelCfg);
         drvData->accelCfg = NULL;
         /* 器件在位，销毁工作队列资源 */
         HdfWorkDestroy(&drvData->accelWork);
         HdfWorkQueueDestroy(&drvData->accelWorkQueue);
         OsalMemFree(drvData);
     }
     ```

2. 完成加速度传感器驱动的设备信息配置。

   加速度传感器模型使用HCS作为配置描述源码，HCS配置字段请参考[配置管理](driver-hdf-manage.md)介绍。

   ```
   /* 加速度计传感器设备HCS配置 */
   device_sensor_accel :: device {
       device0 :: deviceNode {
           policy = 1; // 驱动服务发布的策略
           priority = 110; // 驱动启动优先级（0-200），值越大优先级越低，建议配置为100，优先级相同则不保证device的加载顺序
           preload = 0; // 驱动按需加载字段，0表示加载，2表示不加载
           permission = 0664; // 驱动创建设备节点权限
           moduleName = "HDF_SENSOR_ACCEL"; // 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致
           serviceName = "sensor_accel"; // 驱动对外发布服务的名称，必须唯一
           deviceMatchAttr = "hdf_sensor_accel_driver"; // 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值相等
       }
   } 
   ```

3. 完成加速度传感器抽象驱动内部接口开发，包括Enable、Disable、SetBatch、SetMode、SetOption、AccelCreateCfgData、AccelReleaseCfgData、AccelRegisterChipOps接口实现。

   ```c
   /* 不使用函数暂时置空 */
   static int32_t SetAccelInfo(struct SensorBasicInfo *info)
   {
       (void)info;
   
       return HDF_ERR_NOT_SUPPORT;
   }
   /* 下发使能寄存器组的配置 */
   static int32_t SetAccelEnable(void)
   {
       int32_t ret;
       struct AccelDrvData *drvData = AccelGetDrvData();
   
       CHECK_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
       CHECK_NULL_PTR_RETURN_VALUE(drvData->accelCfg, HDF_ERR_INVALID_PARAM);
   
       if (drvData->enable) {
           HDF_LOGE("%s: Accel sensor is enabled", __func__);
           return HDF_SUCCESS;
       }
   
       ret = SetSensorRegCfgArray(&drvData->accelCfg->busCfg, drvData->accelCfg->regCfgGroup[SENSOR_ENABLE_GROUP]);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Accel sensor enable config failed", __func__);
           return ret;
       }
   
       ret = OsalTimerCreate(&drvData->accelTimer, SENSOR_TIMER_MIN_TIME, AccelTimerEntry, (uintptr_t)drvData);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Accel create timer failed[%d]", __func__, ret);
           return ret;
       }
   
       ret = OsalTimerStartLoop(&drvData->accelTimer);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Accel start timer failed[%d]", __func__, ret);
           return ret;
       }
       drvData->enable = true;
   
       return HDF_SUCCESS;
   }
   /* 下发去使能寄存器组的配置 */
   static int32_t SetAccelDisable(void)
   {
       int32_t ret;
       struct AccelDrvData *drvData = AccelGetDrvData();
   
       CHECK_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
       CHECK_NULL_PTR_RETURN_VALUE(drvData->accelCfg, HDF_ERR_INVALID_PARAM);
   
       if (!drvData->enable) {
           HDF_LOGE("%s: Accel sensor had disable", __func__);
           return HDF_SUCCESS;
       }
   
       ret = SetSensorRegCfgArray(&drvData->accelCfg->busCfg, drvData->accelCfg->regCfgGroup[SENSOR_DISABLE_GROUP]);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Accel sensor disable config failed", __func__);
           return ret;
       }
   
       ret = OsalTimerDelete(&drvData->accelTimer);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Accel delete timer failed", __func__);
           return ret;
       }
       drvData->enable = false;
   
       return HDF_SUCCESS;
   }
   /* 配置传感器采样率和数据上报间隔 */
   static int32_t SetAccelBatch(int64_t samplingInterval, int64_t interval)
   {
       (void)interval;
   
       struct AccelDrvData *drvData = NULL;
   
       drvData = AccelGetDrvData();
       CHECK_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
   
       drvData->interval = samplingInterval;
   
       return HDF_SUCCESS;
   }
   /* 设置传感器工作模式，当前支持实时模式 */
   static int32_t SetAccelMode(int32_t mode)
   {
       return (mode == SENSOR_WORK_MODE_REALTIME) ? HDF_SUCCESS : HDF_FAILURE;
   }
   
   static int32_t SetAccelOption(uint32_t option)
   {
       (void)option;
       return HDF_SUCCESS;
   }
   /* 设置传感器可选配置 */
   static int32_t SetAccelOption(uint32_t option)
   {
       (void)option;
       return HDF_ERR_NOT_SUPPORT;
   }
   ```

4. 基于HDF驱动框架，按照驱动Driver Entry程序，完成加速度传感器差异化驱动开发，主要由Bind、Init、Release、Dispatch函数接口实现。

   ```c
   /* 加速度计传感器差异化驱动消息交互 */
   static int32_t DispatchBMI160(struct HdfDeviceIoClient *client,
       int cmd, struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       (void)client;
       (void)cmd;
       (void)data;
       (void)reply;
   
       return HDF_SUCCESS;
   }
   /* 加速度计传感器差异化驱动对外提供的服务绑定到HDF框架 */
   int32_t Bmi160BindDriver(struct HdfDeviceObject *device)
   {
       CHECK_NULL_PTR_RETURN_VALUE(device, HDF_ERR_INVALID_PARAM);
   
       struct Bmi160DrvData *drvData = (struct Bmi160DrvData *)OsalMemCalloc(sizeof(*drvData));
       if (drvData == NULL) {
           HDF_LOGE("%s: Malloc Bmi160 drv data fail", __func__);
           return HDF_ERR_MALLOC_FAIL;
       }
   
       drvData->ioService.Dispatch = DispatchBMI160;
       drvData->device = device;
       device->service = &drvData->ioService;
       g_bmi160DrvData = drvData;
   
       return HDF_SUCCESS;
   }
   /* 加速度计传感器差异化驱动初始化 */
   int32_t Bmi160InitDriver(struct HdfDeviceObject *device)
   {
       int32_t ret;
       struct AccelOpsCall ops;
   
       CHECK_NULL_PTR_RETURN_VALUE(device, HDF_ERR_INVALID_PARAM);
       struct Bmi160DrvData *drvData = (struct Bmi160DrvData *)device->service;
       CHECK_NULL_PTR_RETURN_VALUE(drvData, HDF_ERR_INVALID_PARAM);
   
       ret = InitAccelPreConfig();
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Init  BMI160 bus mux config", __func__);
           return HDF_FAILURE;
       }
   
       drvData->sensorCfg = AccelCreateCfgData(device->property);
       if (drvData->sensorCfg == NULL || drvData->sensorCfg->root == NULL) {
           HDF_LOGD("%s: Creating accelcfg failed because detection failed", __func__);
           return HDF_ERR_NOT_SUPPORT;
       }
   
       ops.Init = NULL;
       ops.ReadData = ReadBmi160Data;
       ret = AccelRegisterChipOps(&ops);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Register BMI160 accel failed", __func__);
           return HDF_FAILURE;
       }
   
       ret = InitBmi160(drvData->sensorCfg);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: Init BMI160 accel failed", __func__);
           return HDF_FAILURE;
       }
   
       return HDF_SUCCESS;
   }
   /* 释放驱动初始化时分配的资源 */
   void Bmi160ReleaseDriver(struct HdfDeviceObject *device)
   {
   	......
       if (drvData->sensorCfg != NULL) {
           AccelReleaseCfgData(drvData->sensorCfg);
           drvData->sensorCfg = NULL;
       }
       OsalMemFree(drvData);
   }
   /* 加速度传感器差异化驱动对应的HdfDriverEntry对象 */
   struct HdfDriverEntry g_accelBmi160DevEntry = {
       .moduleVersion = 1,
       .moduleName = "HDF_SENSOR_ACCEL_BMI160",
       .Bind = Bmi160BindDriver,
       .Init = Bmi160InitDriver,
       .Release = Bmi160ReleaseDriver,
   };
   HDF_INIT(g_accelBmi160DevEntry);
   ```

5. 完成加速度传感器差异化驱动中差异化接口ReadData函数实现。

   ```c
   int32_t ReadBmi160Data(struct SensorCfgData *data)
   {
       int32_t ret;
       struct AccelData rawData = { 0, 0, 0 };
       int32_t tmp[ACCEL_AXIS_NUM];
       struct SensorReportEvent event;
       (void)memset_s(&event, sizeof(event), 0, sizeof(event));
       ret = ReadBmi160RawData(data, &rawData, &event.timestamp);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: BMI160 read raw data failed", __func__);
           return HDF_FAILURE;
       }
       event.sensorId = SENSOR_TAG_ACCELEROMETER;
       event.option = 0;
       event.mode = SENSOR_WORK_MODE_REALTIME;
       ……
       ret = ReportSensorEvent(&event);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("%s: BMI160 report data failed", __func__);
       }
       return ret;
   }
   ```

>![](../public_sys-resources/icon-note.gif) **说明：** 
>
>- 传感器驱动模型已经提供一部分能力集，包括驱动设备管理能力、抽象总线和平台操作接口能力、通用配置操作接口能力、配置解析操作接口能力，接口参考[表2](#table1156812588320)。
>
>- 需要开发人员实现部分有：传感器部分操作接口（[表3](#table1083014911336))和传感器HCS差异化数据配置。
> - 驱动基本功能验证。

### 调测验证<a name="section106021256121219"></a>

驱动开发完成后，在传感器单元测试里面开发自测试用例，验证驱动基本功能。测试环境采用开发者自测试平台。

```
static int32_t g_sensorDataFlag = 0; //标识是否上报传感器数据
static const struct SensorInterface *g_sensorDev = nullptr; //保持获取的传感器接口实例地址

/* 订阅者注册数据上报函数 */
static int SensorTestDataCallback(struct SensorEvents *event)
{
    if (event == nullptr) {
        return -1;
    }
    float *data = (float*)event->data;
    printf("time [%lld] sensor id [%d] x-[%f] y-[%f] z-[%f]\n\r", event->timestamp,
        event->sensorId, (*data), *(data + 1), *(data + g_axisZ));
    if (*data > 1e-5) {
        g_sensorDataFlag = 1;
    }
    return 0;
}
/* 用例执行前，初始化传感器接口实例 */
void HdfSensorTest::SetUpTestCase()
{
    g_sensorDev = NewSensorInterfaceInstance();
    if (g_sensorDev == nullptr) {
        printf("test sensorHdi get Module instace failed\n\r");
    }
}
/* 用例资源释放 */
void HdfSensorTest::TearDownTestCase()
{
    if (g_sensorDev != nullptr) {
        FreeSensorInterfaceInstance();
        g_sensorDev = nullptr;
    }
}
/* 传感器驱动测试验证 */
HWTEST_F(HdfSensorTest,TestAccelDriver_001, TestSize.Level0)
{
    int32_t sensorInterval = 1000000000; // 数据采样率单位纳秒
    int32_t pollTime = 5; // 数据采样时间单位秒
    int32_t accelSensorId = 1; // 加速度传感器类型标识为1
    int32_t count = 0;
    int ret;
    struct SensorInformation *sensorInfo = nullptr;

    ret = g_sensorDev->Register(0, TraditionSensorTestDataCallback)
    EXPECT_EQ(SENSOR_NULL_PTR, ret);

    ret = g_sensorDev->GetAllSensors(&sensorInfo, &count);
    EXPECT_EQ(0, ret);
    if (sensorInfo == nullptr) {
        EXPECT_NE(nullptr, sensorInfo);
        return;
    }
    /* 打印获取的传感器列表 */
    for (int i = 0; i < count; i++) {
        printf("get sensoriId[%d], info name[%s]\n\r", sensorInfo[i]->sensorId, sensorInfo[i]->sensorName);
    }
    ret = g_sensorDev->Enable(accelSensorId);
    EXPECT_EQ(0, ret);
    g_sensorDataFlag = 0;

    ret = g_sensorDev->SetBatch(accelSensorId, sensorInterval, pollTime);
    EXPECT_EQ(0, ret);
    /* 在时间pollTime内，观察输出打印数据 */
    OsalSleep(pollTime);
    EXPECT_EQ(1, g_sensorDataFlag);

    ret = g_sensorDev->Disable(accelSensorId);
    g_sensorDataFlag = 0;
    EXPECT_EQ(0, ret);

    ret = g_sensorDev->Unregister(0, TraditionSensorTestDataCallback);
    EXPECT_EQ(0, ret);
}
```

