# SENSOR<a name="ZH-CN_TOPIC_0000001078401780"></a>

-   [概述](#section3634112111)
    -   [接口说明](#section188213414114)

-   [开发指导](#section1140943382)
    -   [开发步骤](#section7893102915819)

-   [开发实例](#section257750691)
-   [测试指导](#section106021256121219)

## 概述<a name="section3634112111"></a>

Sensor（传感器）驱动模块为上层Sensor服务系统提供稳定的Sensor基础能力API，包括Sensor列表查询、Sensor启停、Sensor订阅及去订阅，Sensor参数配置等功能；基于HDF（**H**ardware  **D**river  **F**oundation）驱动框架开发的Sensor驱动模型，实现跨操作系统迁移，器件差异配置等功能。Sensor驱动模型如下图1所示：

**图 1**  Sensor驱动模型图<a name="fig10451455446"></a>  
![](figure/Sensor驱动模型图.png "Sensor驱动模型图")

Sensor驱动模型对外开放的API接口能力如下：

-   提供Sensor HDI（**H**ardware  **D**river  **I**nterface）能力接口，简化服务开发。
-   提供Sensor驱动模型能力接口：依赖HDF驱动框架实现Sensor器件驱动的注册，加载，去注册，器件探测等能力，提供同一类型Sensor器件驱动归一接口, 寄存器配置解析操作接口，总线访问抽象接口，平台抽象接口。
-   提供开发者实现的能力接口：依赖HDF驱动框架的HCS\(**H**DF  **C**onfiguration  **S**ource\)配置管理，根据同类型Sensor差异化配置，实现Sensor器件参数序列化配置和器件部分操作接口，简化Sensor器件驱动开发。

### 接口说明<a name="section188213414114"></a>

Sensor驱动模型对HDI开放的API接口功能，参考表1。

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
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p199227318499"><a name="p199227318499"></a><a name="p199227318499"></a>获取系统中注册的所有传感器信息，一种类型传感器信息包括传感器名字、设备厂商、固件版本号、硬件版本号、传感器类型编号、传感器标识、最大量程、精度、功耗。</p>
</td>
</tr>
<tr id="row1839716854716"><td class="cellrowborder" rowspan="5" valign="top" width="8.260000000000002%" headers="mcps1.2.4.1.1 "><p id="p06071477324"><a name="p06071477324"></a><a name="p06071477324"></a>配置操作</p>
</td>
<td class="cellrowborder" valign="top" width="45.4%" headers="mcps1.2.4.1.2 "><p id="p38874252376"><a name="p38874252376"></a><a name="p38874252376"></a>int32_t <strong id="b199602219271"><a name="b199602219271"></a><a name="b199602219271"></a>Enable</strong>(int32_t sensorId)</p>
</td>
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p5922331114916"><a name="p5922331114916"></a><a name="p5922331114916"></a>使能一种传感器设备，只有数据订阅者使能传感器后，才能获取订阅的传感器数据。</p>
</td>
</tr>
<tr id="row6397138134713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6923143184914"><a name="p6923143184914"></a><a name="p6923143184914"></a>int32_t <strong id="b84601875330"><a name="b84601875330"></a><a name="b84601875330"></a>Disable</strong>(int32_t sensorId)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p139231531184912"><a name="p139231531184912"></a><a name="p139231531184912"></a>去使能一种传感器设备。</p>
</td>
</tr>
<tr id="row43981283476"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p992473112496"><a name="p992473112496"></a><a name="p992473112496"></a>int32_t <strong id="b16691194511438"><a name="b16691194511438"></a><a name="b16691194511438"></a>SetBatch</strong>(iint32_t sensorId, int64_t samplingInterval, int64_t reportInterval)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14924203134910"><a name="p14924203134910"></a><a name="p14924203134910"></a>设置一种传感器的数据采样间隔和数据上报间隔。</p>
</td>
</tr>
<tr id="row439813812472"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p170411511281"><a name="p170411511281"></a><a name="p170411511281"></a>int32_t <strong id="b170414153284"><a name="b170414153284"></a><a name="b170414153284"></a>SetMode</strong>(int32_t sensorTypeId, SensorUser *user, int32_t mode)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107051159281"><a name="p107051159281"></a><a name="p107051159281"></a>设置一种传感器的工作模式，不同的工作模式，上报数据方式不同。</p>
</td>
</tr>
<tr id="row123998813470"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p492513120494"><a name="p492513120494"></a><a name="p492513120494"></a>int32_t <strong id="b7501191019330"><a name="b7501191019330"></a><a name="b7501191019330"></a>SetOption</strong>(int32_t sensorId, uint32_t option)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5926031124914"><a name="p5926031124914"></a><a name="p5926031124914"></a>设置一种传感器量程，精度等可选配置。</p>
</td>
</tr>
<tr id="row939914814478"><td class="cellrowborder" rowspan="2" valign="top" width="8.260000000000002%" headers="mcps1.2.4.1.1 "><p id="p1039815743211"><a name="p1039815743211"></a><a name="p1039815743211"></a>数据订阅操作</p>
</td>
<td class="cellrowborder" valign="top" width="45.4%" headers="mcps1.2.4.1.2 "><p id="p11530101054411"><a name="p11530101054411"></a><a name="p11530101054411"></a>int32_t <strong id="b0569161217334"><a name="b0569161217334"></a><a name="b0569161217334"></a>Register</strong>(RecordDataCallback cb)</p>
</td>
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p892633118493"><a name="p892633118493"></a><a name="p892633118493"></a>订阅者注册传感器数据回调函数，系统会将获取到的传感器数据上报给订阅者。</p>
</td>
</tr>
<tr id="row10716713314"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p196491214133110"><a name="p196491214133110"></a><a name="p196491214133110"></a>int32_t <strong id="b13758151483317"><a name="b13758151483317"></a><a name="b13758151483317"></a>Unregister</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5817133119"><a name="p5817133119"></a><a name="p5817133119"></a>订阅者去注册传感器数据回调函数。</p>
</td>
</tr>
<tr id="row15679121655614"><td class="cellrowborder" rowspan="2" valign="top" width="8.260000000000002%" headers="mcps1.2.4.1.1 "><p id="p6596162112564"><a name="p6596162112564"></a><a name="p6596162112564"></a>接口实例</p>
</td>
<td class="cellrowborder" valign="top" width="45.4%" headers="mcps1.2.4.1.2 "><p id="p13679191616561"><a name="p13679191616561"></a><a name="p13679191616561"></a>const struct SensorInterface *<strong id="b292451515"><a name="b292451515"></a><a name="b292451515"></a>NewSensorInterfaceInstance</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" width="46.339999999999996%" headers="mcps1.2.4.1.3 "><p id="p19679181612563"><a name="p19679181612563"></a><a name="p19679181612563"></a>创建传感器接口实例。</p>
</td>
</tr>
<tr id="row9680191675612"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15680111655611"><a name="p15680111655611"></a><a name="p15680111655611"></a>int32_t <strong id="b1144297156"><a name="b1144297156"></a><a name="b1144297156"></a>FreeSensorInterfaceInstance</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p18680916165620"><a name="p18680916165620"></a><a name="p18680916165620"></a>释放传感器接口实例。</p>
</td>
</tr>
</tbody>
</table>

Sensor驱动模型对驱动开发者开放的功能接口，驱动开发者无需实现，直接使用，参考表2：

**表 2**  Sensor驱动模型对驱动开发者开放的功能接口列表

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
<tr id="row195691858113219"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1156945883215"><a name="p1156945883215"></a><a name="p1156945883215"></a>int32_t <strong id="b1736762975518"><a name="b1736762975518"></a><a name="b1736762975518"></a>DeleteSensorDevice</strong>(int32_t sensorId)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p2569145833214"><a name="p2569145833214"></a><a name="p2569145833214"></a>删除传感器设备管理里指定的传感器设备。</p>
</td>
</tr>
<tr id="row15699589321"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6569105811328"><a name="p6569105811328"></a><a name="p6569105811328"></a>int32_t <strong id="b1174510321555"><a name="b1174510321555"></a><a name="b1174510321555"></a>ReportSensorEvent</strong>(const struct SensorReportEvent *events)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15691858193220"><a name="p15691858193220"></a><a name="p15691858193220"></a>上报指定类型传感器的数据到用户侧。</p>
</td>
</tr>
<tr id="row17569145814329"><td class="cellrowborder" rowspan="4" valign="top" width="8.550855085508552%" headers="mcps1.2.4.1.1 "><p id="p10589113932619"><a name="p10589113932619"></a><a name="p10589113932619"></a>Sensor抽象总线和平台操作接口</p>
</td>
<td class="cellrowborder" valign="top" width="45.53455345534553%" headers="mcps1.2.4.1.2 "><p id="p145705585322"><a name="p145705585322"></a><a name="p145705585322"></a>int32_t <strong id="b15560203515558"><a name="b15560203515558"></a><a name="b15560203515558"></a>ReadSensor</strong>(struct SensorBusCfg *busCfg, uint16_t regAddr, uint8_t *data, uint16_t dataLen)</p>
</td>
<td class="cellrowborder" valign="top" width="45.91459145914592%" headers="mcps1.2.4.1.3 "><p id="p1657018586322"><a name="p1657018586322"></a><a name="p1657018586322"></a>按照配置的总线方式，读取传感器寄存器配置数据。</p>
</td>
</tr>
<tr id="row28712021112011"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p38722218200"><a name="p38722218200"></a><a name="p38722218200"></a>int32_t <strong id="b573774595514"><a name="b573774595514"></a><a name="b573774595514"></a>WriteSensor</strong>(struct SensorBusCfg *busCfg, uint8_t *writeData, uint16_t len)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p6872112112201"><a name="p6872112112201"></a><a name="p6872112112201"></a>按照配置的总线方式，传感器配置数据写入寄存器。</p>
</td>
</tr>
<tr id="row1667512682014"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p146751426192014"><a name="p146751426192014"></a><a name="p146751426192014"></a>int32_t <strong id="b4725135865517"><a name="b4725135865517"></a><a name="b4725135865517"></a>CreateSensorThread</strong>(struct OsalThread *thread, OsalThreadEntry threadEntry, char *name, void *entryPara)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p10676112612013"><a name="p10676112612013"></a><a name="p10676112612013"></a>创建指定传感器的定时线程，用于传感器数据上报处理。</p>
</td>
</tr>
<tr id="row1594017462410"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p49401442414"><a name="p49401442414"></a><a name="p49401442414"></a>void <strong id="b17586316565"><a name="b17586316565"></a><a name="b17586316565"></a>DestroySensorThread</strong>(struct OsalThread *thread, uint8_t *status);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p69406415243"><a name="p69406415243"></a><a name="p69406415243"></a>销毁传感器创建的定时线程。</p>
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

Sensor驱动模型要求驱动开发者实现的接口功能，参考表3

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
<td class="cellrowborder" valign="top" width="45.81458145814582%" headers="mcps1.2.4.1.3 "><p id="p1480465165710"><a name="p1480465165710"></a><a name="p1480465165710"></a>传感器器设备探测成功后，需要对传感器器设备初始化配置。</p>
</td>
</tr>
<tr id="row10831296333"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1783115910333"><a name="p1783115910333"></a><a name="p1783115910333"></a>int32_t <strong id="b146831650010"><a name="b146831650010"></a><a name="b146831650010"></a>GetInfo</strong>(struct SensorBasicInfo *info)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4831139153316"><a name="p4831139153316"></a><a name="p4831139153316"></a>从传感器器设备的HCS配置里，获取当前传感器设备的基本信息。</p>
</td>
</tr>
<tr id="row178311493339"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p208318963320"><a name="p208318963320"></a><a name="p208318963320"></a>int32_t <strong id="b189921571402"><a name="b189921571402"></a><a name="b189921571402"></a>Enable</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p68310953312"><a name="p68310953312"></a><a name="p68310953312"></a>根据当前传感器器设备的HCS配置，下发传感器设备使能操作组的寄存器配置。</p>
</td>
</tr>
<tr id="row0831129153318"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p0831169183314"><a name="p0831169183314"></a><a name="p0831169183314"></a>int32_t <strong id="b13541291106"><a name="b13541291106"></a><a name="b13541291106"></a>Disable</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p138314912336"><a name="p138314912336"></a><a name="p138314912336"></a>根据当前传感器器设备的HCS配置，下发传感器设备去使能操作组的寄存器配置。</p>
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
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4565104214213"><a name="p4565104214213"></a><a name="p4565104214213"></a>根据可选配置，下发量程，精度等寄存器配置。</p>
</td>
</tr>
<tr id="row380240111218"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1181184016120"><a name="p1181184016120"></a><a name="p1181184016120"></a>void <strong id="b1613451717016"><a name="b1613451717016"></a><a name="b1613451717016"></a>ReadSensorData</strong>(void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p7815401121"><a name="p7815401121"></a><a name="p7815401121"></a>实现传感器的数据读取函数。</p>
</td>
</tr>
</tbody>
</table>

接口实现参考[SENSOR](#section257750691)章节。

## 开发指导<a name="section1140943382"></a>

Sensor驱动是基于HDF框架、PLATFORM和OSAL基础接口进行开发，不区分操作系统和芯片平台，为不同Sensor器件提供统一的驱动模型。本篇开发指导以加速度计传感器为例，介绍传感器驱动开发。

### 开发步骤<a name="section7893102915819"></a>

1.  加速度计传感器驱动注册。HDF驱动框架会提供统一的驱动管理模型，通过加速计传感器模块配置信息，识别并加载对应模块驱动。
2.  加速度计传感器驱动初始化和去初始化。HDF驱动框架通过init入口函数，依次启动传感器设备驱动加载和分配传感器设备数据配置资源。HDF驱动框架通过release函数，释放驱动加载的资源和配置。
3.  加速度计传感器寄存器组配置解析。不同类型传感器需要在hcs里配置器件对应的HCS配置文件，然后再设备驱动启动过程中探测器件是否在位，然后加载对应的配置文件，生成配置的结构体对象。
4.  加速度计传感器驱动操作接口实现。实现各个类型传感器归一化驱动接口，如init，GetInfo，Enable，Disable，SetBatch，SetMode，SetOption，ReadSensorData等函数，完成传感器驱动配置下发和数据上报功能。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>传感器驱动模型已经提供一部分能力集，包括驱动设备管理能力，抽象总线和平台操作接口能力，通用配置操作接口能力，配置解析操作接口能力，接口参考[表2](#table1156812588320)。需要开发人员实现部分有：1、传感器部分操作接口（[表3](#table1083014911336)）；2、传感器HCS差异化数据配置；3、驱动基本功能验证。

## 开发实例<a name="section257750691"></a>

基于HDF驱动模型，加载启动加速度计传感器驱动，代码形式如下，具体原理可参考[HDF驱动开发指南](driver-hdf-development.md)。加速度传感器选择通讯接口方式为I2C，厂家选择博世BMI160加速度传感器。

1.  加速度计传感器驱动入口注册

-   加速度计传感器驱动入口函数实现

```
/* 注册加速度计传感器入口数据结构体对象 */
struct HdfDriverEntry g_sensorAccelDevEntry = {
    .moduleVersion = 1, /* 加速度计传感器模块版本号 */
    .moduleName = "HDF_SENSOR_ACCEL", /* 加速度计传感器模块名，要与device_info.hcs文件里的加速度计moduleName字段值一样*/
    .Bind = BindAccelDriver, /* 加速度计传感器绑定函数 */
    .Init = InitAccelDriver, /* 加速度计传感器初始化函数 */
    .Release = ReleaseAccelDriver, /* 加速度计传感器资源释放函数 */
};

/* 调用HDF_INIT将驱动入口注册到HDF框架中，在加载驱动时HDF框架会先调用Bind函数,再调用Init函数加载该驱动，当Init调用异常时，HDF框架会调用Release释放驱动资源并退出 */
HDF_INIT(g_sensorAccelDevEntry);
```

-   加速度计传感器设备配置描述

加速度传感器模型使用HCS作为配置描述源码，HCS配置字段详细介绍参考[配置管理](driver-hdf-manage.md)介绍。

```
/* 加速度计传感器设备HCS配置 */
device_sensor_accel :: device {
    device0 :: deviceNode {
        policy = 1; /* policy字段是驱动服务发布的策略 */
        priority = 105; /* 驱动启动优先级（0-200），值越大优先级越低，建议默认配100，优先级相同则不保证device的加载顺序 */
        preload = 2; /* 驱动按需加载字段，0表示加载，2表示不加载 */
        permission = 0664; /* 驱动创建设备节点权限 */
        moduleName = "HDF_SENSOR_ACCEL"; /* 驱动名称，该字段的值必须和驱动入口结构的moduleName值一致 */
        serviceName = "sensor_accel"; /* 驱动对外发布服务的名称，必须唯一 */
        deviceMatchAttr = "hdf_sensor_accel_driver"; /* 驱动私有数据匹配的关键字，必须和驱动私有数据配置表中的match_attr值相等 */
    }
} 
```

1.  加速度计传感器驱动初始化和去初始化

-   初始化入口函数init

```
/* 加速度计传感器驱动对外提供的服务绑定到HDF框架 */
int32_t BindAccelDriver(struct HdfDeviceObject *device)
{
    CHECK_NULL_PTR_RETURN_VALUE(device, HDF_ERR_INVALID_PARAM);

    static struct IDeviceIoService service = {
        .object = {0},
        .Dispatch = DispatchAccel,
    };
    device->service = &service;

    return HDF_SUCCESS;
}
/*在探测到器件在位后，需要调用RegisterAccelChipOps注册差异化适配函数*/
int32_t RegisterAccelChipOps(struct AccelOpsCall *ops)
{
    struct AccelDrvData *drvData = NULL;

    CHECK_NULL_PTR_RETURN_VALUE(ops, HDF_ERR_INVALID_PARAM);

    drvData = AccelGetDrvData();
    drvData->ops.Init = ops->Init;
    drvData->ops.ReadData = ops->ReadData;
    return HDF_SUCCESS;
}
/* 挂载加速度计传感器驱动归一化的接口函数 */
static int32_t InitAccelOps(struct SensorDeviceInfo *deviceInfo)
{
    struct AccelDrvData *drvData = AccelGetDrvData();

    (void)memset_s((void *)deviceInfo, sizeof(*deviceInfo), 0, sizeof(*deviceInfo));
    deviceInfo->ops.GetInfo = SetAccelInfo;
    deviceInfo->ops.Enable = SetAccelEnable;
    deviceInfo->ops.Disable = SetAccelDisable;
    deviceInfo->ops.SetBatch = SetAccelBatch;
    deviceInfo->ops.SetMode = SetAccelMode;
    deviceInfo->ops.SetOption = SetAccelOption;

    if (memcpy_s(&deviceInfo->sensorInfo, sizeof(deviceInfo->sensorInfo),
        &drvData->accelCfg->sensorInfo, sizeof(drvData->accelCfg->sensorInfo)) != EOK) {
        HDF_LOGE("%s: copy sensor info failed", __func__);
        return HDF_FAILURE;
    }
    /* 传感器类型标识可以在数据HCS配置文件里面配置，也可以在此处 */
    drvData->accelCfg->sensorInfo.sensorTypeId = SENSOR_TAG_ACCELEROMETER;
    drvData->accelCfg->sensorInfo.sensorId = SENSOR_TAG_ACCELEROMETER;

    return HDF_SUCCESS;
}
/* 传感器寄存器初始化操作 */
static int32_t InitAccelAfterConfig(void)
{
    struct SensorDeviceInfo deviceInfo;

    if (InitAccelConfig() != HDF_SUCCESS) {
        HDF_LOGE("%s: init accel config failed", __func__);
        return HDF_FAILURE;
    }

    if (InitAccelOps(&deviceInfo) != HDF_SUCCESS) {
        HDF_LOGE("%s: init accel ops failed", __func__);
        return HDF_FAILURE;
    }

    if (AddSensorDevice(&deviceInfo) != HDF_SUCCESS) {
        HDF_LOGE("%s: add accel device failed", __func__);
        return HDF_FAILURE;
    }

    return HDF_SUCCESS;
}
/*通过器件探测函数，挂载器件差异化函数接口*/
static int32_t DetectAccelChip(void)
{
    int32_t num;
    int32_t ret;
    int32_t loop;
    struct AccelDrvData *drvData = AccelGetDrvData();
    CHECK_NULL_PTR_RETURN_VALUE(drvData->accelCfg, HDF_ERR_INVALID_PARAM);

    num = sizeof(g_accelDetectIfList) / sizeof(g_accelDetectIfList[0]);
    for (loop = 0; loop < num; ++loop) {
        if (g_accelDetectIfList[loop].DetectChip != NULL) {
            ret = g_accelDetectIfList[loop].DetectChip(drvData->accelCfg);
            if (ret == HDF_SUCCESS) {
                drvData->detectFlag = true;
                break;
            }
        }
    }

    if (loop == num) {
        HDF_LOGE("%s: detect accel device failed", __func__);
        drvData->detectFlag = false;
        return HDF_FAILURE;
    }
    return HDF_SUCCESS;
}
/* 加速度计传感器驱动初始化入口函数，主要功能为对传感器私有数据的结构体对象进行初始化，传感器HCS数据配置对象空间分配，传感器HCS数据配置初始化入口函数调用，传感器设备探测是否在位功能，传感器数据上报定时器创建，传感器归一化接口挂载，传感器设备注册功能 */
int32_t InitAccelDriver(struct HdfDeviceObject *device)
{
    /* 获取传感器私有数据结构体对象 */
    struct AccelDrvData *drvData = AccelGetDrvData();

   /* 同类型传感器不同厂家设备探测时，判断此类型传感器是否已经在位，若已经在位，无需再继续探测，直接返回 */
    if (drvData->detectFlag) {
        HDF_LOGE("%s: accel sensor have detected", __func__);
        return HDF_SUCCESS;
    }

    CHECK_NULL_PTR_RETURN_VALUE(device, HDF_ERR_INVALID_PARAM);
    /* 分配存放传感器数据配置的私有结构体数据对象，需要在驱动释放时释放分配的资源空间 */
        drvData->accelCfg = (struct SensorCfgData *)OsalMemCalloc(sizeof(*cfg));
        if (drvData->accelCfg == NULL) {
            HDF_LOGE("%s: malloc sensor config data failed", __func__);
            return HDF_FAILURE;
        }
  
    drvData->accelCfg->regCfgGroup = &g_regCfgGroup[0];
    /* 初始化传感器配置数据主要是解析传感器通讯总线配置类型信息，传感器基本信息，传感器属性信息，传感器是否在位信息，寄存器分组信息 */
    if (GetSensorBaseConfigData(device->property, drvData->accelCfg) != HDF_SUCCESS) {
        HDF_LOGE("%s: get sensor base config failed", __func__);
        goto Base_CONFIG_EXIT;
    }

    if (DetectAccelChip() != HDF_SUCCESS) {
        HDF_LOGE("%s: accel sensor detect device no exist", __func__);
        goto DETECT_CHIP_EXIT;
    }
    drvData->detectFlag = true;
    if (ParseSensorRegConfig(drvData->accelCfg) != HDF_SUCCESS) {
        HDF_LOGE("%s: detect sensor device failed", __func__);
        goto REG_CONFIG_EXIT;
    }

    if (InitAccelAfterConfig() != HDF_SUCCESS) {
        HDF_LOGE("%s: init accel after config failed", __func__);
        goto INIT_EXIT;
    }

    HDF_LOGI("%s: init accel driver success", __func__);
    return HDF_SUCCESS;

INIT_EXIT:
    DestroySensorThread(&drvData->thread, &drvData->threadStatus);
    (void)DeleteSensorDevice(SENSOR_TAG_ACCELEROMETER);
REG_CONFIG_EXIT:
    ReleaseSensorAllRegConfig(drvData->accelCfg);
    (void)ReleaseSensorBusHandle(&drvData->accelCfg->busCfg);
DETECT_CHIP_EXIT:
    drvData->detectFlag = false;
BASE_CONFIG_EXIT:
    drvData->accelCfg->root = NULL;
    drvData->accelCfg->regCfgGroup = NULL;
    OsalMemFree(drvData->accelCfg);
    drvData->accelCfg = NULL;
    return HDF_FAILURE;
}

/* 释放驱动初始化时分配的资源 */
void ReleaseAccelDriver(struct HdfDeviceObject *device)
{
    (void)device;
    struct AccelDrvData *drvData = NULL;

    drvData = AccelGetDrvData();
    (void)DestroySensorThread(&drvData->thread, &drvData->threadStatus);
    (void)DeleteSensorDevice(SENSOR_TAG_ACCELEROMETER);
    drvData->detectFlag = false;

    if (drvData->accelCfg != NULL) {
        drvData->accelCfg->root = NULL;
        drvData->accelCfg->regCfgGroup = NULL;
        ReleaseSensorAllRegConfig(drvData->accelCfg);
        (void)ReleaseSensorBusHandle(&drvData->accelCfg->busCfg);
        OsalMemFree(drvData->accelCfg);
        drvData->accelCfg = NULL;
    }

    drvData->initStatus = false;
}
```

1.  加速度计传感器寄存器组配置信息

加速度计传感器数据配置只需要按照模板配置即可，基于模板配置的解析功能已经在**InitSensorConfigData**函数完成，只需初始化时调用即可。如果有新增配置项，需要同步修改此函数。

```
加速度传感器数据配置模板(accel_config.hcs)
root {
    sensorAccelConfig {
        accelChipConfig {
            /* 传感器设备信息模板 */
            template sensorInfo {
                sensorName = "accelerometer"; /* 加速度计名字，字符最大长度16字节 */
                vendorName = "borsh_bmi160"; /* 传感器设备厂商，字符最大长度16字节 */
                firmwareVersion = "1.0"; /* 传感器固件版本号，默认1.0，字符最大长度16字节 */
                hardwareVersion = "1.0"; /* 传感器硬件版本号，默认1.0，字符最大长度16字节 */
                sensorTypeId = 1; /* 传感器类型编号，详见{@link SensorTypeTag} */
                sensorId = 1; /* 传感器的标识号，有传感器驱动开发者定义，推荐用{@link SensorTypeTag}枚举 */
                maxRange = 8; /* 传感器的最大量程,根据开发者需要配置 */
                precision = 0; /* 传感器的精度，与上报数据配合使用，上报数据结构体{@link SensorEvents } */
                power = 230; /* 传感器的功耗 */
            }
            /* 传感器使用的总线类型和配置信息模板 */
            template sensorBusConfig {
                busType = 0; /* 0:i2c 1:spi */ 
                busNum = 6; /* 芯片上分配给传感器的器件号 */ 
                busAddr = 0; /* 芯片上分配给传感器的地址 */
                regWidth = 1; /* 传感器寄存器地址宽度 */
                regBigEndian = 0; /* 传感器寄存器大小端 */ 
            }
            /* 传感器设备属性模板 */
            template sensorAttr {
                chipName = ""; /* 传感器芯片名字 */
                chipIdRegister = 0xf; /* 传感器在位检测寄存器地址 */
                chipIdValue = 0xd1; /* 校验传感器在位检测寄存器值 */
            }
        }
    }
}

/* 根据不同器件硬件差异，修改模板配置，不修改的就会默认采用模板配置 */
root {
    sensorAccelConfig {
        accel_bmi160_chip_config : accelChipConfig {
            match_attr = "hdf_sensor_accel_driver"; /* 需要和加速度传感器设备配置match_attr字段保持一致 */
            accelInfo :: sensorInfo {
                vendorName = "borsh_bmi160";
                sensorTypeId = 1;
                sensorId = 1;
            }
            accelBusConfig :: sensorBusConfig {
                busType = 0; /* i2c通讯方式 */
                busNum = 6;
                busAddr = 0x68;
                regWidth = 1; /* 1字节位宽 */ 
            }
            accelAttr :: sensorAttr {
                chipName = "bmi160";
                chipIdRegister = 0x00;
                chipIdValue = 0xd1;
            }
            accelRegConfig {
                /*  regAddr: 寄存器地址
                    value: 寄存器值
                    mask: 寄存器值的掩码
                    len: 寄存器值的数据长度(字节)
                    delay: 配置寄存器延时(ms)
                    opsType:操作类型 0-无 1-读 2-写 3-读并检查 4-位更新
                    calType: 计算类型 0-无 1-写 2-取反 3-异或 4-左移 5-右移
                    shiftNum: 移动位数
                    debug: 调试开关，0-调试关闭 1-调试打开
                    save: 保存数据开关，0-不保存数据 1-保存数据 
                */
                /* 传感器寄存器操作分组，按照分组进行有序配置 */
                /* 寄存器地址, 寄存器值, 寄存器值的掩码, 寄存器值的数据长度, 配置寄存器延时, 操作类型, 计算类型, 移动位数, 调试开关, 保存开关 */
                /* 初始化寄存器组 */
                initSeqConfig = [
                    0x7e,    0xb6, 0xff,   1,     5,       2,       0,        0,     0,    0,
                    0x7e,    0x10, 0xff,   1,     5,       2,       0,        0,     0,    0
                ];
                /* 使能寄存器组 */
                enableSeqConfig = [
                    0x7e,    0x11, 0xff,   1,     5,       2,       0,        0,     0,    0,
                    0x41,    0x03, 0xff,   1,     0,       2,       0,        0,     0,    0,
                    0x40,    0x08, 0xff,   1,     0,       2,       0,        0,     0,    0
                ];
                /* 去使能寄存器组 */
                disableSeqConfig = [
                    0x7e,    0x10, 0xff,   1,     5,       2,       0,        0,     0,    0
                ];
            }
        }
    }
}
```

1.  加速度计传感器驱动操作接口实现

开发者需要根据每种类型的传感器实现归一化接口。

```
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

    CHECK_NULL_PTR_RETURN_VALUE(drvData->accelCfg, HDF_ERR_INVALID_PARAM);
    ret = SetSensorRegCfgArray(&drvData->accelCfg->busCfg, drvData->accelCfg->regCfgGroup[SENSOR_ENABLE_GROUP]);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: accel sensor disable config failed", __func__);
        return HDF_FAILURE;
    }

    drvData->threadStatus = SENSOR_THREAD_RUNNING;

    return HDF_SUCCESS;
}
/* 下发去使能寄存器组的配置 */
static int32_t SetAccelDisable(void)
{
    int32_t ret;
    struct AccelDrvData *drvData = AccelGetDrvData();

    CHECK_NULL_PTR_RETURN_VALUE(drvData->accelCfg, HDF_ERR_INVALID_PARAM);

    ret = SetSensorRegCfgArray(&drvData->accelCfg->busCfg, drvData->accelCfg->regCfgGroup[SENSOR_DISABLE_GROUP]);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: accel sensor disable config failed", __func__);
        return HDF_FAILURE;
        }

    drvData->threadStatus = SENSOR_THREAD_STOPPED;

    return HDF_SUCCESS;
}
/* 配置传感器采样率和数据上报间隔 */
static int32_t SetAccelBatch(int64_t samplingInterval, int64_t interval)
{
    (void)interval;

    struct AccelDrvData *drvData = AccelGetDrvData();
    drvData->interval = samplingInterval;

    return HDF_SUCCESS;
}
/* 设置传感器工作模式，当前支持实时模式 */
static int32_t SetAccelMode(int32_t mode)
{
    return (mode == SENSOR_WORK_MODE_REALTIME) ? HDF_SUCCESS : HDF_FAILURE;
}
/* 设置传感器可选配置 */
static int32_t SetAccelOption(uint32_t option)
{
    (void)option;
    return HDF_ERR_NOT_SUPPORT;
}
```

-   差异化处理接口

    ```
    /* 器件探测时，如果探测成功，则注册差异化处理函数到accel驱动模型里 */
    int32_t DetectAccelBim160Chip(struct SensorCfgData *data)
    {
        int32_t ret;
        struct AccelOpsCall ops;
        CHECK_NULL_PTR_RETURN_VALUE(data, HDF_ERR_INVALID_PARAM);
    
        if (strcmp(ACCEL_CHIP_NAME_BMI160, data->sensorAttr.chipName) != 0) {
            return HDF_SUCCESS;
        }
        ret = InitAccelPreConfig();
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: init  BMI160 bus mux config", __func__);
            return HDF_FAILURE;
        }
        if (DetectSensorDevice(data) != HDF_SUCCESS) {
            return HDF_FAILURE;
        }
    
       /* 差异化处理函数 */
        ops.Init = InitBmi160;
        ops.ReadData = ReadBmi160Data;
        ret = RegisterAccelChipOps(&ops);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: register BMI160 accel failed", __func__);
            (void)ReleaseSensorBusHandle(&data->busCfg);
            return HDF_FAILURE;
        }
        return HDF_SUCCESS;
    }
    /* 初始化处理函数 */
    static int32_t InitBmi160(struct SensorCfgData *data)
    {
        int32_t ret;
    
        CHECK_NULL_PTR_RETURN_VALUE(data, HDF_ERR_INVALID_PARAM);
        ret = SetSensorRegCfgArray(&data->busCfg, data->regCfgGroup[SENSOR_INIT_GROUP]);
        if (ret != HDF_SUCCESS) {
            HDF_LOGE("%s: bmi160 sensor init config failed", __func__);
            return HDF_FAILURE;
        }
        return HDF_SUCCESS;
    }
    /* 数据处理函数 */
    int32_t ReadBmi160Data(struct SensorCfgData *data)
    {
        int32_t ret;
        struct AccelData  rawData = { 0, 0, 0 };
        int32_t tmp[ACCEL_AXIS_NUM];
        struct SensorReportEvent event;
    
        (void)memset_s(&event, sizeof(event), 0, sizeof(event));
    
        ret = ReadBmi160RawData(data, &rawData, &event.timestamp);
        if (ret != HDF_SUCCESS) {
            return HDF_FAILURE;
        }
    
        event.sensorId = SENSOR_TAG_ACCELEROMETER;
        event.option = 0;
        event.mode = SENSOR_WORK_MODE_REALTIME;
    
        rawData.x = rawData.x * BMI160_ACC_SENSITIVITY_2G;
        rawData.y = rawData.y * BMI160_ACC_SENSITIVITY_2G;
        rawData.z = rawData.z * BMI160_ACC_SENSITIVITY_2G;
    
        tmp[ACCEL_X_AXIS] = (rawData.x * SENSOR_1K_UNIT) / SENSOR_CONVERT_UNIT;
        tmp[ACCEL_Y_AXIS] = (rawData.y * SENSOR_1K_UNIT) / SENSOR_CONVERT_UNIT;
        tmp[ACCEL_Z_AXIS] = (rawData.z * SENSOR_1K_UNIT) / SENSOR_CONVERT_UNIT;
    
        event.dataLen = sizeof(tmp);
        event.data = (uint8_t *)&tmp;
        ret = ReportSensorEvent(&event);
        return ret;
    }
    ```

-   数据处理函数

创建传感器定时器，按照配置的采样率定时采样，并上报给数据订阅者。

```
/* 传感器定时工作线程 */
static int32_t ReadAccelDataThreadWorker(void *arg)
{
    (void)arg;
    int64_t interval;
    struct AccelDrvData *drvData = AccelGetDrvData();

    drvData->threadStatus = SENSOR_THREAD_START;
    while (true) {
        if (drvData->threadStatus == SENSOR_THREAD_RUNNING) {
            if (drvData->ops.ReadData != NULL) {
                (void)drvData->ops.ReadData(drvData->accelCfg);
            }
            interval = OsalDivS64(drvData->interval, (SENSOR_CONVERT_UNIT * SENSOR_CONVERT_UNIT));
            OsalMSleep(interval);
        } else if (drvData->threadStatus == SENSOR_THREAD_DESTROY) {
            break;
        } else {
            OsalMSleep(ACC_DEFAULT_SAMPLING_200_MS / SENSOR_CONVERT_UNIT / SENSOR_CONVERT_UNIT);
        }

        if ((!drvData->initStatus) || (drvData->interval < 0) || drvData->threadStatus != SENSOR_THREAD_RUNNING) {
            continue;
        }
    }

    return HDF_SUCCESS;
}
/* 创建传感器定时器和器件初始化 */
static int32_t InitAccelConfig(void)
{
    int32_t ret;
    struct AccelDrvData *drvData = AccelGetDrvData();

    if (drvData->threadStatus != SENSOR_THREAD_NONE && drvData->threadStatus != SENSOR_THREAD_DESTROY) {
        HDF_LOGE("%s: accel thread have created", __func__);
        return HDF_SUCCESS;
    }

    ret = CreateSensorThread(&drvData->thread, ReadAccelDataThreadWorker, "hdf_sensor_accel", drvData);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: accel create thread failed", __func__);
        drvData->threadStatus = SENSOR_THREAD_NONE;
        return HDF_FAILURE;
    }

    CHECK_NULL_PTR_RETURN_VALUE(drvData->ops.Init, HDF_ERR_INVALID_PARAM);

    ret = drvData->ops.Init(drvData->accelCfg);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: accel create thread failed", __func__);
        drvData->threadStatus = SENSOR_THREAD_NONE;
        return HDF_FAILURE;
    }
    drvData->initStatus = true;
    return HDF_SUCCESS;
}
```

-   主要的数据结构

```
/* 传感器转换单位*/
#define SENSOR_CONVERT_UNIT             1000
#define SENSOR_1K_UNIT                  1024
/* 传感器2g对应灵敏度转换值 */
#define BMI160_ACC_SENSITIVITY_2G       61
/* 传感器数据采样寄存器地址 */
#define BMI160_ACCEL_X_LSB_ADDR              0X12
#define BMI160_ACCEL_X_MSB_ADDR              0X13
#define BMI160_ACCEL_Y_LSB_ADDR              0X14
#define BMI160_ACCEL_Y_MSB_ADDR              0X15
#define BMI160_ACCEL_Z_LSB_ADDR              0X16
#define BMI160_ACCEL_Z_MSB_ADDR              0X17
/* 传感器数据维度 */
enum AccelAxisNum {
    ACCEL_X_AXIS   = 0,
    ACCEL_Y_AXIS   = 1,
    ACCEL_Z_AXIS   = 2,
    ACCEL_AXIS_NUM = 3,
};
/* 传感器每个维度值 */
struct AccelData {
    int32_t x;
    int32_t y;
    int32_t z;
};
/* 传感器私有数据结构体 */
struct AccelDrvData {
    bool detectFlag;
    uint8_t threadStatus;
    uint8_t initStatus;
    int64_t interval;
    struct SensorCfgData *accelCfg;
    struct OsalThread thread;
    struct AccelOpsCall ops;
};
/* 差异化适配函数 */
struct AccelOpsCall {
    int32_t (*Init)(struct SensorCfgData *data);
    int32_t (*ReadData)(struct SensorCfgData *data);
};
```

## 测试指导<a name="section106021256121219"></a>

驱动开发完成后，在传感器单元测试里面开发自测试用例，验证驱动基本功能。测试环境采用开发者自测试平台。

```
/* 标识是否上报传感器数据 */
static int32_t g_sensorDataFlag = 0;
/* 保持获取的传感器接口实例地址 */
static const struct SensorInterface *g_sensorDev = nullptr;

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
    int32_t sensorInterval = 1000000000; /* 数据采样率单位纳秒 */
    int32_t pollTime = 5; /* 数据采样时间单位秒 */
    int32_t accelSensorId = 1; /* 加速度传感器类型标识为1 */
    int32_t count = 0;
    int ret;
    struct SensorInformation *sensorInfo = nullptr;

    ret = g_sensorDev->Register(SensorTestDataCallback)
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

    ret = g_sensorDev->Unregister();
    EXPECT_EQ(0, ret);
}
```

