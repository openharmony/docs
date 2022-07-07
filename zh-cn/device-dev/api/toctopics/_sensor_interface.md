# SensorInterface<a name="ZH-CN_TOPIC_0000001343200777"></a>

## **概述**<a name="section956461134083932"></a>

**所属模块:**

[Sensor](_sensor.md)

## **汇总**<a name="section1465893294083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1126676113083932"></a>
<table><thead align="left"><tr id="row226353405083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1501529344083932"><a name="p1501529344083932"></a><a name="p1501529344083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p671769055083932"><a name="p671769055083932"></a><a name="p671769055083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row747716657083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p535623213083932"><a name="p535623213083932"></a><a name="p535623213083932"></a>( <a href="_sensor_interface.md#af8d462c7bc12cb9a075baa375556b1ef">GetAllSensors</a> )([out] struct <a href="_sensor_information.md">SensorInformation</a> **sensorInfo, [out] int32_t *count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p105592100083932"><a name="p105592100083932"></a><a name="p105592100083932"></a>获取当前系统中所有类型的传感器信息。 <a href="_sensor_interface.md#af8d462c7bc12cb9a075baa375556b1ef">更多...</a></p>
</td>
</tr>
<tr id="row383961038083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p294774142083932"><a name="p294774142083932"></a><a name="p294774142083932"></a>( <a href="_sensor_interface.md#ae613d8ebbf436f4460e3989590e2ce8d">Enable</a> )([in] int32_t sensorId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295674663083932"><a name="p1295674663083932"></a><a name="p1295674663083932"></a>根据传感器设备类型标识使能传感器信息列表里存在的设备，只有数据订阅者使能传感器后，才能获取订阅的传感器数据。 <a href="_sensor_interface.md#ae613d8ebbf436f4460e3989590e2ce8d">更多...</a></p>
</td>
</tr>
<tr id="row546657462083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p332491661083932"><a name="p332491661083932"></a><a name="p332491661083932"></a>( <a href="_sensor_interface.md#aff572600c8a47a5a3670d03ff44a697d">Disable</a> )([in] int32_t sensorId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2078653755083932"><a name="p2078653755083932"></a><a name="p2078653755083932"></a>根据传感器设备类型标识去使能传感器信息列表里存在的设备。 <a href="_sensor_interface.md#aff572600c8a47a5a3670d03ff44a697d">更多...</a></p>
</td>
</tr>
<tr id="row38491707083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1422660927083932"><a name="p1422660927083932"></a><a name="p1422660927083932"></a>( <a href="_sensor_interface.md#a6066d0eb9f3743797438bbbbdaa38272">SetBatch</a> )([in] int32_t sensorId, [in] int64_t samplingInterval, [in] int64_t reportInterval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p333100288083932"><a name="p333100288083932"></a><a name="p333100288083932"></a>设置指定传感器的数据采样间隔和数据上报间隔。 <a href="_sensor_interface.md#a6066d0eb9f3743797438bbbbdaa38272">更多...</a></p>
</td>
</tr>
<tr id="row2097134260083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1410111596083932"><a name="p1410111596083932"></a><a name="p1410111596083932"></a>( <a href="_sensor_interface.md#a375dfc82cd9a4e998d7948de7c57aa6b">SetMode</a> )([in] int32_t sensorId, [in] int32_t mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p185597135083932"><a name="p185597135083932"></a><a name="p185597135083932"></a>设置指定传感器的数据上报模式，不同的工作模式，上报数据的方式不同。 <a href="_sensor_interface.md#a375dfc82cd9a4e998d7948de7c57aa6b">更多...</a></p>
</td>
</tr>
<tr id="row1481986347083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1600222819083932"><a name="p1600222819083932"></a><a name="p1600222819083932"></a>( <a href="_sensor_interface.md#aac8716c2decd5fd52a140efcc7137db7">SetOption</a> )([in] int32_t sensorId, [in] uint32_t option)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1714208220083932"><a name="p1714208220083932"></a><a name="p1714208220083932"></a>设置指定传感器量程、精度等可选配置。 <a href="_sensor_interface.md#aac8716c2decd5fd52a140efcc7137db7">更多...</a></p>
</td>
</tr>
<tr id="row1402417072083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p893816627083932"><a name="p893816627083932"></a><a name="p893816627083932"></a>( <a href="_sensor_interface.md#aa4ad96bd698ca365eaff7e11a8b463f3">Register</a> )([in] int32_t groupId, [in] <a href="_sensor.md#ga2e0b32ff63dbdaf778e4d7dd4d6bb932">RecordDataCallback</a> cb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p259705760083932"><a name="p259705760083932"></a><a name="p259705760083932"></a>订阅者注册传感器数据回调函数，系统会将获取到的传感器数据上报给订阅者。 <a href="_sensor_interface.md#aa4ad96bd698ca365eaff7e11a8b463f3">更多...</a></p>
</td>
</tr>
<tr id="row787986887083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2133752973083932"><a name="p2133752973083932"></a><a name="p2133752973083932"></a>( <a href="_sensor_interface.md#ad65e49504acacf8428bb90fe2230d843">Unregister</a> )([in] int32_t groupId, [in] <a href="_sensor.md#ga2e0b32ff63dbdaf778e4d7dd4d6bb932">RecordDataCallback</a> cb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p186893987083932"><a name="p186893987083932"></a><a name="p186893987083932"></a>订阅者去注册传感器数据回调函数。 <a href="_sensor_interface.md#ad65e49504acacf8428bb90fe2230d843">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section759170926083932"></a>

提供sensor设备基本控制操作接口。

结构体提供获取传感器设备信息、订阅/去订阅传感器数据、使能/去使能传感器、设置传感器模式、设置传感器精度、量程等可选配置接口定义。

## **类成员变量说明**<a name="section1665840533083932"></a>

## Disable<a name="aff572600c8a47a5a3670d03ff44a697d"></a>

```
int32_t(* SensorInterface::Disable) ([in] int32_t sensorId)
```

**描述：**

根据传感器设备类型标识去使能传感器信息列表里存在的设备。

**参数：**

<a name="table116767825083932"></a>
<table><thead align="left"><tr id="row1584501983083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2054916521083932"><a name="p2054916521083932"></a><a name="p2054916521083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1619419183083932"><a name="p1619419183083932"></a><a name="p1619419183083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row964073332083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1780617069083932p0"><a name="entry1780617069083932p0"></a><a name="entry1780617069083932p0"></a>sensorId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1284628598083932p0"><a name="entry1284628598083932p0"></a><a name="entry1284628598083932p0"></a>唯一标识一个传感器设备类型，详见<a href="_sensor.md#gaea6a2a57db175118e08189b73f8f3da5">SensorTypeTag</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## Enable<a name="ae613d8ebbf436f4460e3989590e2ce8d"></a>

```
int32_t(* SensorInterface::Enable) ([in] int32_t sensorId)
```

**描述：**

根据传感器设备类型标识使能传感器信息列表里存在的设备，只有数据订阅者使能传感器后，才能获取订阅的传感器数据。

**参数：**

<a name="table51373402083932"></a>
<table><thead align="left"><tr id="row1195103780083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p661395390083932"><a name="p661395390083932"></a><a name="p661395390083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p981533710083932"><a name="p981533710083932"></a><a name="p981533710083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2133373806083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1295739377083932p0"><a name="entry1295739377083932p0"></a><a name="entry1295739377083932p0"></a>sensorId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry213083615083932p0"><a name="entry213083615083932p0"></a><a name="entry213083615083932p0"></a>唯一标识一个传感器设备类型，详见<a href="_sensor.md#gaea6a2a57db175118e08189b73f8f3da5">SensorTypeTag</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## GetAllSensors<a name="af8d462c7bc12cb9a075baa375556b1ef"></a>

```
int32_t(* SensorInterface::GetAllSensors) ([out] struct SensorInformation **sensorInfo,[out] int32_t *count)
```

**描述：**

获取当前系统中所有类型的传感器信息。

**参数：**

<a name="table80620047083932"></a>
<table><thead align="left"><tr id="row1396727188083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p354887677083932"><a name="p354887677083932"></a><a name="p354887677083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p539018314083932"><a name="p539018314083932"></a><a name="p539018314083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row923754062083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry296476273083932p0"><a name="entry296476273083932p0"></a><a name="entry296476273083932p0"></a>sensorInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2133074365083932p0"><a name="entry2133074365083932p0"></a><a name="entry2133074365083932p0"></a>输出系统中注册的所有传感器信息，一种类型传感器信息包括传感器名字、设备厂商、 固件版本号、硬件版本号、传感器类型编号、传感器标识、最大量程、精度、功耗，详见<a href="_sensor_information.md">SensorInformation</a>。</p>
</td>
</tr>
<tr id="row1265609593083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry690261581083932p0"><a name="entry690261581083932p0"></a><a name="entry690261581083932p0"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1219582481083932p0"><a name="entry1219582481083932p0"></a><a name="entry1219582481083932p0"></a>输出系统中注册的传感器数量。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## Register<a name="aa4ad96bd698ca365eaff7e11a8b463f3"></a>

```
int32_t(* SensorInterface::Register) ([in] int32_t groupId,[in] RecordDataCallback cb)
```

**描述：**

订阅者注册传感器数据回调函数，系统会将获取到的传感器数据上报给订阅者。

**参数：**

<a name="table664384472083932"></a>
<table><thead align="left"><tr id="row1260775893083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p809848106083932"><a name="p809848106083932"></a><a name="p809848106083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2133831790083932"><a name="p2133831790083932"></a><a name="p2133831790083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2016602092083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2048693316083932p0"><a name="entry2048693316083932p0"></a><a name="entry2048693316083932p0"></a>groupId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1688268437083932p0"><a name="entry1688268437083932p0"></a><a name="entry1688268437083932p0"></a>传感器组ID。 sensorId枚举值范围为128-160，表示已订阅医疗传感器服务，只需成功订阅一次，无需重复订阅。 sensorId枚举值范围不在128-160之间，这意味着传统传感器已订阅，只需成功订阅一次，无需重复订阅。</p>
</td>
</tr>
<tr id="row367158242083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry174737210083932p0"><a name="entry174737210083932p0"></a><a name="entry174737210083932p0"></a>cb</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1900306637083932p0"><a name="entry1900306637083932p0"></a><a name="entry1900306637083932p0"></a>要注册的回调函数，详见<a href="_sensor.md#ga2e0b32ff63dbdaf778e4d7dd4d6bb932">RecordDataCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果注册回调函数成功，则返回0。

如果注册回调函数失败，则返回负数。

## SetBatch<a name="a6066d0eb9f3743797438bbbbdaa38272"></a>

```
int32_t(* SensorInterface::SetBatch) ([in] int32_t sensorId,[in] int64_t samplingInterval,[in] int64_t reportInterval)
```

**描述：**

设置指定传感器的数据采样间隔和数据上报间隔。

**参数：**

<a name="table1859264467083932"></a>
<table><thead align="left"><tr id="row9715113083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2109596995083932"><a name="p2109596995083932"></a><a name="p2109596995083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1253714790083932"><a name="p1253714790083932"></a><a name="p1253714790083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row962504448083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry572807766083932p0"><a name="entry572807766083932p0"></a><a name="entry572807766083932p0"></a>sensorId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry250129191083932p0"><a name="entry250129191083932p0"></a><a name="entry250129191083932p0"></a>唯一标识一个传感器设备类型，详见<a href="_sensor.md#gaea6a2a57db175118e08189b73f8f3da5">SensorTypeTag</a>。</p>
</td>
</tr>
<tr id="row876313274083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1427313331083932p0"><a name="entry1427313331083932p0"></a><a name="entry1427313331083932p0"></a>samplingInterval</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1338560847083932p0"><a name="entry1338560847083932p0"></a><a name="entry1338560847083932p0"></a>设置指定传感器的数据采样间隔，单位纳秒。</p>
</td>
</tr>
<tr id="row1837270150083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1135771693083932p0"><a name="entry1135771693083932p0"></a><a name="entry1135771693083932p0"></a>reportInterval</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry641329896083932p0"><a name="entry641329896083932p0"></a><a name="entry641329896083932p0"></a>表示传感器数据上报间隔，单位纳秒。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## SetMode<a name="a375dfc82cd9a4e998d7948de7c57aa6b"></a>

```
int32_t(* SensorInterface::SetMode) ([in] int32_t sensorId,[in] int32_t mode)
```

**描述：**

设置指定传感器的数据上报模式，不同的工作模式，上报数据的方式不同。

**参数：**

<a name="table1255872665083932"></a>
<table><thead align="left"><tr id="row1711682482083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p11366161083932"><a name="p11366161083932"></a><a name="p11366161083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p150628850083932"><a name="p150628850083932"></a><a name="p150628850083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1440547950083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry246629086083932p0"><a name="entry246629086083932p0"></a><a name="entry246629086083932p0"></a>sensorId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry486448250083932p0"><a name="entry486448250083932p0"></a><a name="entry486448250083932p0"></a>唯一标识一个传感器设备类型，详见<a href="_sensor.md#gaea6a2a57db175118e08189b73f8f3da5">SensorTypeTag</a>。</p>
</td>
</tr>
<tr id="row1829840099083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry956151507083932p0"><a name="entry956151507083932p0"></a><a name="entry956151507083932p0"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2056241204083932p0"><a name="entry2056241204083932p0"></a><a name="entry2056241204083932p0"></a>传感器的数据上报模式，详见<a href="_sensor.md#ga066f4ffeb31a1f4cb3ed357736e0afab">SensorModeType</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果设置传感器数据报告模式成功，则返回0。

如果设置传感器数据报告模式失败，则返回负数。

## SetOption<a name="aac8716c2decd5fd52a140efcc7137db7"></a>

```
int32_t(* SensorInterface::SetOption) ([in] int32_t sensorId,[in] uint32_t option)
```

**描述：**

设置指定传感器量程、精度等可选配置。

**参数：**

<a name="table995748353083932"></a>
<table><thead align="left"><tr id="row335643233083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1217928074083932"><a name="p1217928074083932"></a><a name="p1217928074083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1270029496083932"><a name="p1270029496083932"></a><a name="p1270029496083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row257680381083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1549690994083932p0"><a name="entry1549690994083932p0"></a><a name="entry1549690994083932p0"></a>sensorId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1057520175083932p0"><a name="entry1057520175083932p0"></a><a name="entry1057520175083932p0"></a>唯一标识一个传感器设备类型，详见<a href="_sensor.md#gaea6a2a57db175118e08189b73f8f3da5">SensorTypeTag</a>。</p>
</td>
</tr>
<tr id="row75520429083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry843769790083932p0"><a name="entry843769790083932p0"></a><a name="entry843769790083932p0"></a>option</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1611823220083932p0"><a name="entry1611823220083932p0"></a><a name="entry1611823220083932p0"></a>传感器的量程、精度等配置。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果设置参数成功，则返回0。

如果设置参数失败，则返回负数。

## Unregister<a name="ad65e49504acacf8428bb90fe2230d843"></a>

```
int32_t(* SensorInterface::Unregister) ([in] int32_t groupId,[in] RecordDataCallback cb)
```

**描述：**

订阅者去注册传感器数据回调函数。

**参数：**

<a name="table218740949083932"></a>
<table><thead align="left"><tr id="row1272211550083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1346713678083932"><a name="p1346713678083932"></a><a name="p1346713678083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1305281678083932"><a name="p1305281678083932"></a><a name="p1305281678083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row749403029083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry157705210083932p0"><a name="entry157705210083932p0"></a><a name="entry157705210083932p0"></a>groupId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1835414128083932p0"><a name="entry1835414128083932p0"></a><a name="entry1835414128083932p0"></a>传感器组ID。 sensorId枚举值范围为128-160，表示已订阅医疗传感器服务。只需成功取消订阅一次，无需重复取消订阅。 sensorId枚举值范围不在128-160之间，这意味着传统传感器已订阅。并且成功取消订阅。</p>
</td>
</tr>
<tr id="row740872862083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2076479060083932p0"><a name="entry2076479060083932p0"></a><a name="entry2076479060083932p0"></a>cb</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1771615187083932p0"><a name="entry1771615187083932p0"></a><a name="entry1771615187083932p0"></a>要注册的回调函数，详见<a href="_sensor.md#ga2e0b32ff63dbdaf778e4d7dd4d6bb932">RecordDataCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果取消注册回调函数成功，则返回0。

如果取消注册回调函数失败，则返回负数。

