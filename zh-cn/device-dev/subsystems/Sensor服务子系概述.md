# Sensor服务子系概述<a name="ZH-CN_TOPIC_0000001092893507"></a>

-   [简介](#section667413271505)
-   [接口说明](#section7255104114110)

## 简介<a name="section667413271505"></a>

Sensor服务子系统提供了轻量级传感器服务基础框架，您可以使用该框架接口实现传感器列表查询、传感器控制、传感器订阅去订阅等功能。轻量级传感器服务框架如下图所示：

**图1**  Sensor服务框架图

![](figures/zh-cn_image_0000001077724150.png)

-   Sensor API：提供传感器的基础API，主要包含查询传感器的列表、订阅/取消传感器数据、执行控制命令等，简化应用开发。
-   Sensor Framework：主要实现传感器的订阅管理、数据通道的创建、销毁等，实现与传感器服务层的通信。
-   Sensor Service：主要实现HDF层数据接收、解析、分发，对设备传感器的管理，数据上报管理以及传感器权限管控等。

## 接口说明<a name="section7255104114110"></a>

**表 1**  Sensor服务框架API接口功能介绍

<a name="table203963834718"></a>
<table><thead align="left"><tr id="row173964834716"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p20921103144918"><a name="p20921103144918"></a><a name="p20921103144918"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="25.722572257225725%" id="mcps1.2.4.1.2"><p id="p109216317495"><a name="p109216317495"></a><a name="p109216317495"></a>接口说明</p>
</th>
<th class="cellrowborder" valign="top" width="40.94409440944094%" id="mcps1.2.4.1.3"><p id="p1192112316497"><a name="p1192112316497"></a><a name="p1192112316497"></a>参数要求</p>
</th>
</tr>
</thead>
<tbody><tr id="row4397198154712"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p11001322173912"><a name="p11001322173912"></a><a name="p11001322173912"></a>int32_t <strong id="b792815314396"><a name="b792815314396"></a><a name="b792815314396"></a>GetAllSensors</strong>(SensorInfo **sensorInfo, int32_t *count)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p199227318499"><a name="p199227318499"></a><a name="p199227318499"></a><strong id="b59221831174918"><a name="b59221831174918"></a><a name="b59221831174918"></a>作用</strong>：获取系统中所有传感器的信息。</p>
<p id="p9922153110492"><a name="p9922153110492"></a><a name="p9922153110492"></a><strong id="b2922183114917"><a name="b2922183114917"></a><a name="b2922183114917"></a>返回值</strong>：0表示成功，其他返回值表示失败。</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p4922173116498"><a name="p4922173116498"></a><a name="p4922173116498"></a><strong id="b633817407478"><a name="b633817407478"></a><a name="b633817407478"></a>sensorInfo</strong>(NOT NULL)：输出系统中所有传感器的信息；</p>
<p id="p18922931134919"><a name="p18922931134919"></a><a name="p18922931134919"></a><strong id="b8845650154711"><a name="b8845650154711"></a><a name="b8845650154711"></a>count</strong>(NOT NULL)：输出系统中所有传感器的数量。</p>
</td>
</tr>
<tr id="row1839716854716"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p38874252376"><a name="p38874252376"></a><a name="p38874252376"></a>int32_t <strong id="b17835184513919"><a name="b17835184513919"></a><a name="b17835184513919"></a>SubscribeSensor</strong>(int32_t sensorTypeId, SensorUser *user)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p14922113114914"><a name="p14922113114914"></a><a name="p14922113114914"></a><strong id="b2922133194911"><a name="b2922133194911"></a><a name="b2922133194911"></a>作用</strong>：订阅传感器数据，系统会将获取到的传感器数据上报给订阅者。</p>
<p id="p5922331114916"><a name="p5922331114916"></a><a name="p5922331114916"></a><strong id="b49221631154911"><a name="b49221631154911"></a><a name="b49221631154911"></a>返回值</strong>： 0为成功，其他返回值表示失败。</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p17922183120490"><a name="p17922183120490"></a><a name="p17922183120490"></a><strong id="b383183812561"><a name="b383183812561"></a><a name="b383183812561"></a>sensorTypeId</strong>：唯一标识一个传感器类型;</p>
<p id="p8922193154917"><a name="p8922193154917"></a><a name="p8922193154917"></a><strong id="b15825101814564"><a name="b15825101814564"></a><a name="b15825101814564"></a>user</strong>(NOT NULL)：传感器的用户，用于从传感器获取数据，一般一个用户只属于一个传感器。</p>
</td>
</tr>
<tr id="row6397138134713"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p6923143184914"><a name="p6923143184914"></a><a name="p6923143184914"></a>int32_t <strong id="b338673044313"><a name="b338673044313"></a><a name="b338673044313"></a>UnsubscribeSensor</strong>(int32_t sensorTypeId, SensorUser *user)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p792383116495"><a name="p792383116495"></a><a name="p792383116495"></a><strong id="b592313144920"><a name="b592313144920"></a><a name="b592313144920"></a>作用</strong>：去订阅传感器数据，系统将取消传感器数据上报给订阅者。</p>
<p id="p139231531184912"><a name="p139231531184912"></a><a name="p139231531184912"></a><strong id="b3923113134918"><a name="b3923113134918"></a><a name="b3923113134918"></a>返回值</strong>：0为成功，其他返回值表示失败。</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p178981446572"><a name="p178981446572"></a><a name="p178981446572"></a><strong id="b48981147570"><a name="b48981147570"></a><a name="b48981147570"></a>sensorTypeId</strong>：唯一标识一个传感器类型;</p>
<p id="p178988410573"><a name="p178988410573"></a><a name="p178988410573"></a><strong id="b5898194105710"><a name="b5898194105710"></a><a name="b5898194105710"></a>user</strong>(NOT NULL)：传感器的用户，用于从传感器获取数据，一般一个用户只属于一个传感器。</p>
</td>
</tr>
<tr id="row43981283476"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p992473112496"><a name="p992473112496"></a><a name="p992473112496"></a>int32_t <strong id="b16691194511438"><a name="b16691194511438"></a><a name="b16691194511438"></a>SetBatch</strong>(int32_t sensorTypeId, SensorUser *user, int64_t samplingInterval, int64_t reportInterval)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p14924831124913"><a name="p14924831124913"></a><a name="p14924831124913"></a><strong id="b1292416313494"><a name="b1292416313494"></a><a name="b1292416313494"></a>作用</strong>：设置传感器的数据采样间隔和数据上报间隔</p>
<p id="p14924203134910"><a name="p14924203134910"></a><a name="p14924203134910"></a><strong id="b16924123134910"><a name="b16924123134910"></a><a name="b16924123134910"></a>返回值</strong>：0为成功，其他返回值表示失败。</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p189243318494"><a name="p189243318494"></a><a name="p189243318494"></a><strong id="b20906161712597"><a name="b20906161712597"></a><a name="b20906161712597"></a>sensorTypeId</strong>：唯一标识一个传感器类型;</p>
<p id="p167364493594"><a name="p167364493594"></a><a name="p167364493594"></a><strong id="b2736849195911"><a name="b2736849195911"></a><a name="b2736849195911"></a>user</strong>(NOT NULL)：传感器的用户，用于从传感器获取数据，一般一个用户只属于一个传感器;</p>
<p id="p1692403115493"><a name="p1692403115493"></a><a name="p1692403115493"></a><strong id="b1866310191589"><a name="b1866310191589"></a><a name="b1866310191589"></a>samplingInterval</strong>：传感器数据采样间隔，单位纳秒;</p>
<p id="p392443174917"><a name="p392443174917"></a><a name="p392443174917"></a><strong id="b851892113817"><a name="b851892113817"></a><a name="b851892113817"></a>reportInterval</strong>：传感器数据上报间隔，单位纳秒。</p>
</td>
</tr>
<tr id="row439813812472"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17925631194911"><a name="p17925631194911"></a><a name="p17925631194911"></a>int32_t <strong id="b12311455154316"><a name="b12311455154316"></a><a name="b12311455154316"></a>ActivateSensor</strong>(int32_t sensorTypeId, SensorUser *user)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p1892583174920"><a name="p1892583174920"></a><a name="p1892583174920"></a><strong id="b129251231104917"><a name="b129251231104917"></a><a name="b129251231104917"></a>作用</strong>：使能一个传感器订阅用户。</p>
<p id="p16925113119497"><a name="p16925113119497"></a><a name="p16925113119497"></a><strong id="b592515316496"><a name="b592515316496"></a><a name="b592515316496"></a>返回值</strong>：0为成功，其他返回值表示失败。</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p59255313493"><a name="p59255313493"></a><a name="p59255313493"></a><strong id="b556385111910"><a name="b556385111910"></a><a name="b556385111910"></a>sensorTypeId</strong>：唯一标识一个传感器类型；</p>
<p id="p1692517314499"><a name="p1692517314499"></a><a name="p1692517314499"></a><strong id="b187561853496"><a name="b187561853496"></a><a name="b187561853496"></a>user</strong>(NOT NULL)：传感器的用户，用于从传感器获取数据，一般一个用户只属于一个传感器。</p>
</td>
</tr>
<tr id="row123998813470"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p492513120494"><a name="p492513120494"></a><a name="p492513120494"></a>int32_t <strong id="b1612146204413"><a name="b1612146204413"></a><a name="b1612146204413"></a>DeactivateSensor</strong>(int32_t sensorTypeId, SensorUser *user)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p12925143118492"><a name="p12925143118492"></a><a name="p12925143118492"></a><strong id="b10925163114496"><a name="b10925163114496"></a><a name="b10925163114496"></a>作用</strong>：去使能一个传感器订阅用户</p>
<p id="p5926031124914"><a name="p5926031124914"></a><a name="p5926031124914"></a><strong id="b17926331124911"><a name="b17926331124911"></a><a name="b17926331124911"></a>返回值</strong>：0为成功，其他返回值表示失败。</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p1692683112499"><a name="p1692683112499"></a><a name="p1692683112499"></a><strong id="b4896161619112"><a name="b4896161619112"></a><a name="b4896161619112"></a>sensorTypeId</strong>：唯一标识一个传感器类型；</p>
<p id="p1081949113"><a name="p1081949113"></a><a name="p1081949113"></a><strong id="b1629389111"><a name="b1629389111"></a><a name="b1629389111"></a>user</strong>(NOT NULL)：传感器的用户，用于从传感器获取数据，一般一个用户只属于一个传感器。</p>
</td>
</tr>
<tr id="row939914814478"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p11530101054411"><a name="p11530101054411"></a><a name="p11530101054411"></a>int32_t <strong id="b1999420216444"><a name="b1999420216444"></a><a name="b1999420216444"></a>SetMode</strong>(int32_t sensorTypeId, SensorUser *user, int32_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="25.722572257225725%" headers="mcps1.2.4.1.2 "><p id="p892633118493"><a name="p892633118493"></a><a name="p892633118493"></a><strong id="b1926113164920"><a name="b1926113164920"></a><a name="b1926113164920"></a>作用</strong>：设置传感器的工作模式</p>
<p id="p1927031114910"><a name="p1927031114910"></a><a name="p1927031114910"></a><strong id="b1492733110494"><a name="b1492733110494"></a><a name="b1492733110494"></a>返回值</strong>：0为成功，其他返回值表示失败。</p>
</td>
<td class="cellrowborder" valign="top" width="40.94409440944094%" headers="mcps1.2.4.1.3 "><p id="p119277312492"><a name="p119277312492"></a><a name="p119277312492"></a><strong id="b142625231515"><a name="b142625231515"></a><a name="b142625231515"></a>sensorTypeId</strong>：唯一标识一个传感器类型；</p>
<p id="p159271031184915"><a name="p159271031184915"></a><a name="p159271031184915"></a><strong id="b05739545156"><a name="b05739545156"></a><a name="b05739545156"></a>user</strong>(NOT NULL)：传感器的用户，用于从传感器获取数据，一般一个用户只属于一个传感器；</p>
<p id="p0927173154916"><a name="p0927173154916"></a><a name="p0927173154916"></a><strong id="b3914356101520"><a name="b3914356101520"></a><a name="b3914356101520"></a>mode</strong>：传感器的数据上报模式。</p>
</td>
</tr>
</tbody>
</table>

