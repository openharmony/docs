# sensor\_type.h<a name="ZH-CN_TOPIC_0000001290721040"></a>

## **概述**<a name="section656842705083931"></a>

**所属模块:**

[Sensor](_sensor.md)

## **汇总**<a name="section591134303083931"></a>

## 类<a name="nested-classes"></a>

<a name="table1484434522083931"></a>
<table><thead align="left"><tr id="row827735701083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1386578626083931"><a name="p1386578626083931"></a><a name="p1386578626083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p745158041083931"><a name="p745158041083931"></a><a name="p745158041083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1129397648083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p346059097083931"><a name="p346059097083931"></a><a name="p346059097083931"></a><a href="_sensor_information.md">SensorInformation</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1195568018083931"><a name="p1195568018083931"></a><a name="p1195568018083931"></a>定义传感器基本信息。 <a href="_sensor_information.md">更多...</a></p>
</td>
</tr>
<tr id="row113106668083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423243337083931"><a name="p423243337083931"></a><a name="p423243337083931"></a><a href="_sensor_events.md">SensorEvents</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p644027320083931"><a name="p644027320083931"></a><a name="p644027320083931"></a>上报传感器数据结构。 <a href="_sensor_events.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 宏定义<a name="define-members"></a>

<a name="table450872802083931"></a>
<table><thead align="left"><tr id="row1431280741083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1213567397083931"><a name="p1213567397083931"></a><a name="p1213567397083931"></a>宏定义</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p906840848083931"><a name="p906840848083931"></a><a name="p906840848083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1399386811083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1424880744083931"><a name="p1424880744083931"></a><a name="p1424880744083931"></a><a href="_sensor.md#ga4d85ccd1dc1681bcfc7a779b6c76f3b8">SENSOR_NAME_MAX_LEN</a>   32</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p4881224113516"><a name="p4881224113516"></a><a name="p4881224113516"></a>Sensor名称的最大长度</p>
</td>
</tr>
<tr id="row1637678587083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1269002219083931"><a name="p1269002219083931"></a><a name="p1269002219083931"></a><a href="_sensor.md#section452718671414">SENSOR_VERSION_MAX_LEN</a>   16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p0180194016355"><a name="p0180194016355"></a><a name="p0180194016355"></a>Sensor版本号的最大长度</p>
</td>
</tr>
</tbody>
</table>

## 类型定义<a name="typedef-members"></a>

<a name="table1879276338083931"></a>
<table><thead align="left"><tr id="row1028280272083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1390176782083931"><a name="p1390176782083931"></a><a name="p1390176782083931"></a>类型定义</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p672209887083931"><a name="p672209887083931"></a><a name="p672209887083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row692681014083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1957784334083931"><a name="p1957784334083931"></a><a name="p1957784334083931"></a>(<a href="_sensor.md#ga2e0b32ff63dbdaf778e4d7dd4d6bb932">RecordDataCallback</a>) (const struct <a href="_sensor_events.md">SensorEvents</a> *)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p495877214083931"><a name="p495877214083931"></a><a name="p495877214083931"></a>传感器上报数据回调函数的定义，传感器服务用户在订阅传感器时， 需要注册上报数据回调函数，传感器使能后，传感器服务用户可以接受到传感器数据，详见<a href="_sensor_interface.md">SensorInterface</a>。 <a href="_sensor.md#ga2e0b32ff63dbdaf778e4d7dd4d6bb932">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 枚举<a name="enum-members"></a>

<a name="table494679114083931"></a>
<table><thead align="left"><tr id="row1976258685083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2118132322083931"><a name="p2118132322083931"></a><a name="p2118132322083931"></a>枚举</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p83089850083931"><a name="p83089850083931"></a><a name="p83089850083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1809062260083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2011871743083931"><a name="p2011871743083931"></a><a name="p2011871743083931"></a><a href="_sensor.md#gaa348cf223e558076864814ee88920cec">SensorStatus</a> {   <a href="_sensor.md#ggaa348cf223e558076864814ee88920ceca6fe3474c6df06ef2bd1d3fb84fc57827">SENSOR_SUCCESS</a> = 0, <a href="_sensor.md#ggaa348cf223e558076864814ee88920cecafc02a48cdab506c10ef1c5c66600ae71">SENSOR_FAILURE</a> = -1, <a href="_sensor.md#ggaa348cf223e558076864814ee88920cecacbf62f7bd2738d9be4b81e603c4f3bd5">SENSOR_NOT_SUPPORT</a> = -2, <a href="_sensor.md#ggaa348cf223e558076864814ee88920ceca0728f44385b2cb32a5c01e1370e6f2d7">SENSOR_INVALID_PARAM</a> = -3,   <a href="_sensor.md#ggaa348cf223e558076864814ee88920cecaeb19761a981ab03ce5144ed0b4c7a48c">SENSOR_INVALID_SERVICE</a> = -4, <a href="_sensor.md#p431372085818">SENSOR_NULL_PTR</a> = -5 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p794037736083931"><a name="p794037736083931"></a><a name="p794037736083931"></a>定义传感器模块返回值类型。 <a href="_sensor.md#gaa348cf223e558076864814ee88920cec">更多...</a></p>
</td>
</tr>
<tr id="row860621016083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p394900368083931"><a name="p394900368083931"></a><a name="p394900368083931"></a><a href="_sensor.md#gaea6a2a57db175118e08189b73f8f3da5">SensorTypeTag</a> {   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a3f8e3e31e6a356192f150019309925ee">SENSOR_TYPE_NONE</a> = 0, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5abd9779b04292b5e8054485b10fccb99c">SENSOR_TYPE_ACCELEROMETER</a> = 1, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5adc01250dcba5642d294f74ba4d115c28">SENSOR_TYPE_GYROSCOPE</a> = 2, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a93f36cca60373938f2410162b16b531e">SENSOR_TYPE_PHOTOPLETHYSMOGRAPH</a> = 3,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a2d8e52264648743ae154b99eef141607">SENSOR_TYPE_ELECTROCARDIOGRAPH</a> = 4, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a717a301be1664d4cd1ea543ca0653325">SENSOR_TYPE_AMBIENT_LIGHT</a> = 5, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a74438e3f4f1f8cb1e97ccebbd1096fe8">SENSOR_TYPE_MAGNETIC_FIELD</a> = 6, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a3ed11be057d851a8ee1db6d946b0e69b">SENSOR_TYPE_CAPACITIVE</a> = 7,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ab9ec86561c555fe323e6a45508e20ca8">SENSOR_TYPE_BAROMETER</a> = 8, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a1931d9687ccbd0aac063417fc0d7b4f6">SENSOR_TYPE_TEMPERATURE</a> = 9, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a7a343ec270d2bd5b96b4748fb4300665">SENSOR_TYPE_HALL</a> = 10, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a875d96bbe6c91eb906e47bbda4250dfe">SENSOR_TYPE_GESTURE</a> = 11,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a47912cab9ef79bbe4eb20538a88ce59c">SENSOR_TYPE_PROXIMITY</a> = 12, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a09fbc658c0f86f34e08513ef355870f5">SENSOR_TYPE_HUMIDITY</a> = 13, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a5e792e48a4eb7b53561af8e511dba943">SENSOR_TYPE_MEDICAL_BEGIN</a> = 128, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ad53330afd8a904e115774ffc04f2e89e">SENSOR_TYPE_MEDICAL_END</a> = 160,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a618cf39cdc6bac1ffe31ba2ad488ca53">SENSOR_TYPE_PHYSICAL_MAX</a> = 255, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5af2ccaca19bdabe513c45c058003ed596">SENSOR_TYPE_ORIENTATION</a> = 256, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ac7d364262029cc21bc865577d5288a1e">SENSOR_TYPE_GRAVITY</a> = 257, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a914a1f090dcc61586318fd4eb4cb1384">SENSOR_TYPE_LINEAR_ACCELERATION</a> = 258,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ac407aca03c7ce72ea55e52f40477561b">SENSOR_TYPE_ROTATION_VECTOR</a> = 259, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a7d9456395f361833de2ee3ef12a1af2a">SENSOR_TYPE_AMBIENT_TEMPERATURE</a> = 260, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a492db205ab694c3954f4b46fa6a999af">SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED</a> = 261, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5af8302206e90774d69fb272ee50e6607b">SENSOR_TYPE_GAME_ROTATION_VECTOR</a> = 262,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ad123a39ee0525c760755a4b40e5dc638">SENSOR_TYPE_GYROSCOPE_UNCALIBRATED</a> = 263, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a3a4ce3aad51d07a5475c3fb1de90ec80">SENSOR_TYPE_SIGNIFICANT_MOTION</a> = 264, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a443b13dc20beadc7821db8df7682cd58">SENSOR_TYPE_PEDOMETER_DETECTION</a> = 265, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a0cef311260d7668885a937ee1ee8d5d8">SENSOR_TYPE_PEDOMETER</a> = 266,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a80a8adf73ab45b0eaaeb24fa3c5351f0">SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR</a> = 277, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a4d4febf14d8366d19661d7b1acb5ff91">SENSOR_TYPE_HEART_RATE</a> = 278, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a23a60d20eeedd90de69b27ffa4a764ac">SENSOR_TYPE_DEVICE_ORIENTATION</a> = 279, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a0ca37fde34accc45f3065c635480a718">SENSOR_TYPE_WEAR_DETECTION</a> = 280,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a730bd9013ab8fea3bbfae66f4c6a6129">SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED</a> = 281, <a href="_sensor.md#p876144152111">SENSOR_TYPE_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1005640818083931"><a name="p1005640818083931"></a><a name="p1005640818083931"></a>定义传感器类型标识。 <a href="_sensor.md#gaea6a2a57db175118e08189b73f8f3da5">更多...</a></p>
</td>
</tr>
<tr id="row386972568083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2102910183083931"><a name="p2102910183083931"></a><a name="p2102910183083931"></a><a href="_sensor.md#ga985dcd359f32f3cdfbaecb98f1f436e7">SensorAccuracyType</a> {   <a href="_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a1f1bc8e9ccbc83cb0cb107a795fd85f7">SENSOR_NO_ACCURACY</a> = 0, <a href="_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a6c2ad64f15e8d0ba24f8b573bc0f19ed">SENSOR_LOW_ACCURACY</a> = 1, <a href="_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a9083140f63420c7b109c5ae8f009a8dd">SENSOR_MEDIUM_ACCURACY</a> = 2, <a href="_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a8a8e8f15654a31f9df91bb0561f55574">SENSOR_HIGH_ACCURACY</a> = 3,   <a href="_sensor.md#p945419536162">SENSOR_MAX_ACCURACY</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1244881173083931"><a name="p1244881173083931"></a><a name="p1244881173083931"></a>传感器的精度类型。 <a href="_sensor.md#ga985dcd359f32f3cdfbaecb98f1f436e7">更多...</a></p>
</td>
</tr>
<tr id="row46480557083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337550218083931"><a name="p337550218083931"></a><a name="p337550218083931"></a><a href="_sensor.md#ga4b389f271110480ce20fcc0763cf6d20">SensorRangeType</a> { <a href="_sensor.md#gga4b389f271110480ce20fcc0763cf6d20a8b81d07987b7a203ef04579c60c07986">SENSOR_RANGE_LEVEL1</a> = 0, <a href="_sensor.md#gga4b389f271110480ce20fcc0763cf6d20a39dd36b72a88ef8bdccdddc9225e21a1">SENSOR_RANGE_LEVEL2</a> = 1, <a href="_sensor.md#gga4b389f271110480ce20fcc0763cf6d20a7fee94e695411165b4e1f7b75ce5d52e">SENSOR_RANGE_LEVEL3</a> = 2, <a href="_sensor.md#p165901247205">SENSOR_RANGE_LEVEL_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1590154178083931"><a name="p1590154178083931"></a><a name="p1590154178083931"></a>传感器的量程级别。 <a href="_sensor.md#ga4b389f271110480ce20fcc0763cf6d20">更多...</a></p>
</td>
</tr>
<tr id="row1213112609083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1703625691083931"><a name="p1703625691083931"></a><a name="p1703625691083931"></a><a href="_sensor.md#ga066f4ffeb31a1f4cb3ed357736e0afab">SensorModeType</a> {   <a href="_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afabae36be092f02cd01eb5bf1c8ae23af73d">SENSOR_MODE_DEFAULT</a> = 0, <a href="_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afaba5db5e8c1a702aca7ecc751532ecfa69d">SENSOR_MODE_REALTIME</a> = 1, <a href="_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afaba9d264027423bdee89167c3c8f4c71322">SENSOR_MODE_ON_CHANGE</a> = 2, <a href="_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afabac0967e6c4ef5004fda5f26f061fec6ee">SENSOR_MODE_ONE_SHOT</a> = 3,   <a href="_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afaba3f4f9b49ae7fe1fb89cd3bff398c7f0f">SENSOR_MODE_FIFO_MODE</a> = 4, <a href="_sensor.md#p4932820101810">SENSOR_MODE_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1310202531083931"><a name="p1310202531083931"></a><a name="p1310202531083931"></a>传感器的工作模式。 <a href="_sensor.md#ga066f4ffeb31a1f4cb3ed357736e0afab">更多...</a></p>
</td>
</tr>
<tr id="row788711411083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337932517083931"><a name="p337932517083931"></a><a name="p337932517083931"></a><a href="_sensor.md#ga588325c4c22f56d09cda6e54df0d9a6c">SensorGroupType</a> { <a href="_sensor.md#gga588325c4c22f56d09cda6e54df0d9a6ca8cc091715416b86fd2eff0a875a76c64">TRADITIONAL_SENSOR_TYPE</a> = 0, <a href="_sensor.md#gga588325c4c22f56d09cda6e54df0d9a6cab8f846ffbc84b2a2275a88707f350a47">MEDICAL_SENSOR_TYPE</a> = 1, <a href="_sensor.md#gga588325c4c22f56d09cda6e54df0d9a6cafdec26032d6c10626eb07a0812fe1d94">SENSOR_GROUP_TYPE_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p635805879083931"><a name="p635805879083931"></a><a name="p635805879083931"></a>枚举传感器的硬件服务组。 <a href="_sensor.md#ga588325c4c22f56d09cda6e54df0d9a6c">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section750162758083931"></a>

定义传感器模块所使用的传感器类型，传感器信息，传感器数据结构等数据类型。

**Since：**

2.2

**Version：**

1.0

