# Sensor<a name="ZH-CN_TOPIC_0000001343000805"></a>

## **汇总**<a name="section1183553705083931"></a>

## 文件<a name="files"></a>

<a name="table16175084083931"></a>
<table><thead align="left"><tr id="row1746890506083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1845926165083931"><a name="p1845926165083931"></a><a name="p1845926165083931"></a>文件</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p709428204083931"><a name="p709428204083931"></a><a name="p709428204083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1100015487083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1017790150083931"><a name="p1017790150083931"></a><a name="p1017790150083931"></a><a href="sensor__if_8h.md">sensor_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1835246481083931"><a name="p1835246481083931"></a><a name="p1835246481083931"></a>Sensor模块对外通用的接口声明文件，提供获取传感器设备信息、订阅/去订阅传感器数据、 使能/去使能传感器、设置传感器模式、设置传感器精度，量程等可选配置接口定义。</p>
</td>
</tr>
<tr id="row1187338864083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p553987337083931"><a name="p553987337083931"></a><a name="p553987337083931"></a><a href="sensor__type_8h.md">sensor_type.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p237215163083931"><a name="p237215163083931"></a><a name="p237215163083931"></a>定义传感器模块所使用的传感器类型，传感器信息，传感器数据结构等数据类型。</p>
</td>
</tr>
</tbody>
</table>

## 类<a name="nested-classes"></a>

<a name="table121127265083931"></a>
<table><thead align="left"><tr id="row1933817687083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1512591749083931"><a name="p1512591749083931"></a><a name="p1512591749083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1469677577083931"><a name="p1469677577083931"></a><a name="p1469677577083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row507729428083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1622798036083931"><a name="p1622798036083931"></a><a name="p1622798036083931"></a><a href="_sensor_interface.md">SensorInterface</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p308455397083931"><a name="p308455397083931"></a><a name="p308455397083931"></a>提供sensor设备基本控制操作接口。 <a href="_sensor_interface.md">更多...</a></p>
</td>
</tr>
<tr id="row88628562083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p346059097083931"><a name="p346059097083931"></a><a name="p346059097083931"></a><a href="_sensor_information.md">SensorInformation</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1195568018083931"><a name="p1195568018083931"></a><a name="p1195568018083931"></a>定义传感器基本信息。 <a href="_sensor_information.md">更多...</a></p>
</td>
</tr>
<tr id="row1346152190083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423243337083931"><a name="p423243337083931"></a><a name="p423243337083931"></a><a href="_sensor_events.md">SensorEvents</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p644027320083931"><a name="p644027320083931"></a><a name="p644027320083931"></a>上报传感器数据结构。 <a href="_sensor_events.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 宏定义<a name="define-members"></a>

<a name="table133186306083931"></a>
<table><thead align="left"><tr id="row1691735948083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p616537653083931"><a name="p616537653083931"></a><a name="p616537653083931"></a>宏定义</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1176601000083931"><a name="p1176601000083931"></a><a name="p1176601000083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1245942446083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p557368173083931"><a name="p557368173083931"></a><a name="p557368173083931"></a><a href="_sensor.md#ga4d85ccd1dc1681bcfc7a779b6c76f3b8">SENSOR_NAME_MAX_LEN</a>   32</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17996103010361"><a name="p17996103010361"></a><a name="p17996103010361"></a>Sensor名称的最大长度。</p>
</td>
</tr>
<tr id="row234013908083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1929224455083931"><a name="p1929224455083931"></a><a name="p1929224455083931"></a><em id="gac8cd573ba2e0e7c27c6f155b2ae0cf55"><a name="gac8cd573ba2e0e7c27c6f155b2ae0cf55"></a><a name="gac8cd573ba2e0e7c27c6f155b2ae0cf55"></a></em><a href="#section452718671414">SENSOR_VERSION_MAX_LEN</a>   16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p53831510123611"><a name="p53831510123611"></a><a name="p53831510123611"></a>Sensor版本号的最大长度。</p>
</td>
</tr>
</tbody>
</table>

## 类型定义<a name="typedef-members"></a>

<a name="table591325702083931"></a>
<table><thead align="left"><tr id="row1397361304083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1304889295083931"><a name="p1304889295083931"></a><a name="p1304889295083931"></a>类型定义</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1097305489083931"><a name="p1097305489083931"></a><a name="p1097305489083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1505508355083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1213572447083931"><a name="p1213572447083931"></a><a name="p1213572447083931"></a>(<a href="_sensor.md#ga2e0b32ff63dbdaf778e4d7dd4d6bb932">RecordDataCallback</a>) (const struct <a href="_sensor_events.md">SensorEvents</a> *)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p230824630083931"><a name="p230824630083931"></a><a name="p230824630083931"></a>传感器上报数据回调函数的定义，传感器服务用户在订阅传感器时， 需要注册上报数据回调函数，传感器使能后，传感器服务用户可以接受到传感器数据，详见<a href="_sensor_interface.md">SensorInterface</a>。 <a href="_sensor.md#ga2e0b32ff63dbdaf778e4d7dd4d6bb932">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 枚举<a name="enum-members"></a>

<a name="table1233704658083931"></a>
<table><thead align="left"><tr id="row626810218083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p896178655083931"><a name="p896178655083931"></a><a name="p896178655083931"></a>枚举</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2087738749083931"><a name="p2087738749083931"></a><a name="p2087738749083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1602606572083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283022426083931"><a name="p283022426083931"></a><a name="p283022426083931"></a><a href="_sensor.md#gaa348cf223e558076864814ee88920cec">SensorStatus</a> {   <a href="_sensor.md#ggaa348cf223e558076864814ee88920ceca6fe3474c6df06ef2bd1d3fb84fc57827">SENSOR_SUCCESS</a> = 0, <a href="_sensor.md#ggaa348cf223e558076864814ee88920cecafc02a48cdab506c10ef1c5c66600ae71">SENSOR_FAILURE</a> = -1, <a href="_sensor.md#ggaa348cf223e558076864814ee88920cecacbf62f7bd2738d9be4b81e603c4f3bd5">SENSOR_NOT_SUPPORT</a> = -2, <a href="_sensor.md#ggaa348cf223e558076864814ee88920ceca0728f44385b2cb32a5c01e1370e6f2d7">SENSOR_INVALID_PARAM</a> = -3,   <a href="_sensor.md#ggaa348cf223e558076864814ee88920cecaeb19761a981ab03ce5144ed0b4c7a48c">SENSOR_INVALID_SERVICE</a> = -4, <a href="#p431372085818">SENSOR_NULL_PTR</a> = -5 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1380849733083931"><a name="p1380849733083931"></a><a name="p1380849733083931"></a>定义传感器模块返回值类型。 <a href="_sensor.md#gaa348cf223e558076864814ee88920cec">更多...</a></p>
</td>
</tr>
<tr id="row1744652607083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p178671552083931"><a name="p178671552083931"></a><a name="p178671552083931"></a><a href="_sensor.md#gaea6a2a57db175118e08189b73f8f3da5">SensorTypeTag</a> {   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a3f8e3e31e6a356192f150019309925ee">SENSOR_TYPE_NONE</a> = 0, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5abd9779b04292b5e8054485b10fccb99c">SENSOR_TYPE_ACCELEROMETER</a> = 1, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5adc01250dcba5642d294f74ba4d115c28">SENSOR_TYPE_GYROSCOPE</a> = 2, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a93f36cca60373938f2410162b16b531e">SENSOR_TYPE_PHOTOPLETHYSMOGRAPH</a> = 3,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a2d8e52264648743ae154b99eef141607">SENSOR_TYPE_ELECTROCARDIOGRAPH</a> = 4, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a717a301be1664d4cd1ea543ca0653325">SENSOR_TYPE_AMBIENT_LIGHT</a> = 5, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a74438e3f4f1f8cb1e97ccebbd1096fe8">SENSOR_TYPE_MAGNETIC_FIELD</a> = 6, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a3ed11be057d851a8ee1db6d946b0e69b">SENSOR_TYPE_CAPACITIVE</a> = 7,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ab9ec86561c555fe323e6a45508e20ca8">SENSOR_TYPE_BAROMETER</a> = 8, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a1931d9687ccbd0aac063417fc0d7b4f6">SENSOR_TYPE_TEMPERATURE</a> = 9, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a7a343ec270d2bd5b96b4748fb4300665">SENSOR_TYPE_HALL</a> = 10, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a875d96bbe6c91eb906e47bbda4250dfe">SENSOR_TYPE_GESTURE</a> = 11,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a47912cab9ef79bbe4eb20538a88ce59c">SENSOR_TYPE_PROXIMITY</a> = 12, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a09fbc658c0f86f34e08513ef355870f5">SENSOR_TYPE_HUMIDITY</a> = 13, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a5e792e48a4eb7b53561af8e511dba943">SENSOR_TYPE_MEDICAL_BEGIN</a> = 128, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ad53330afd8a904e115774ffc04f2e89e">SENSOR_TYPE_MEDICAL_END</a> = 160,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a618cf39cdc6bac1ffe31ba2ad488ca53">SENSOR_TYPE_PHYSICAL_MAX</a> = 255, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5af2ccaca19bdabe513c45c058003ed596">SENSOR_TYPE_ORIENTATION</a> = 256, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ac7d364262029cc21bc865577d5288a1e">SENSOR_TYPE_GRAVITY</a> = 257, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a914a1f090dcc61586318fd4eb4cb1384">SENSOR_TYPE_LINEAR_ACCELERATION</a> = 258,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ac407aca03c7ce72ea55e52f40477561b">SENSOR_TYPE_ROTATION_VECTOR</a> = 259, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a7d9456395f361833de2ee3ef12a1af2a">SENSOR_TYPE_AMBIENT_TEMPERATURE</a> = 260, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a492db205ab694c3954f4b46fa6a999af">SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED</a> = 261, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5af8302206e90774d69fb272ee50e6607b">SENSOR_TYPE_GAME_ROTATION_VECTOR</a> = 262,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5ad123a39ee0525c760755a4b40e5dc638">SENSOR_TYPE_GYROSCOPE_UNCALIBRATED</a> = 263, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a3a4ce3aad51d07a5475c3fb1de90ec80">SENSOR_TYPE_SIGNIFICANT_MOTION</a> = 264, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a443b13dc20beadc7821db8df7682cd58">SENSOR_TYPE_PEDOMETER_DETECTION</a> = 265, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a0cef311260d7668885a937ee1ee8d5d8">SENSOR_TYPE_PEDOMETER</a> = 266,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a80a8adf73ab45b0eaaeb24fa3c5351f0">SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR</a> = 277, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a4d4febf14d8366d19661d7b1acb5ff91">SENSOR_TYPE_HEART_RATE</a> = 278, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a23a60d20eeedd90de69b27ffa4a764ac">SENSOR_TYPE_DEVICE_ORIENTATION</a> = 279, <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a0ca37fde34accc45f3065c635480a718">SENSOR_TYPE_WEAR_DETECTION</a> = 280,   <a href="_sensor.md#ggaea6a2a57db175118e08189b73f8f3da5a730bd9013ab8fea3bbfae66f4c6a6129">SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED</a> = 281, <a href="#p876144152111">SENSOR_TYPE_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1707583137083931"><a name="p1707583137083931"></a><a name="p1707583137083931"></a>定义传感器类型标识。 <a href="_sensor.md#gaea6a2a57db175118e08189b73f8f3da5">更多...</a></p>
</td>
</tr>
<tr id="row1285288625083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p564581035083931"><a name="p564581035083931"></a><a name="p564581035083931"></a><a href="_sensor.md#ga985dcd359f32f3cdfbaecb98f1f436e7">SensorAccuracyType</a> {   <a href="_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a1f1bc8e9ccbc83cb0cb107a795fd85f7">SENSOR_NO_ACCURACY</a> = 0, <a href="_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a6c2ad64f15e8d0ba24f8b573bc0f19ed">SENSOR_LOW_ACCURACY</a> = 1, <a href="_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a9083140f63420c7b109c5ae8f009a8dd">SENSOR_MEDIUM_ACCURACY</a> = 2, <a href="_sensor.md#gga985dcd359f32f3cdfbaecb98f1f436e7a8a8e8f15654a31f9df91bb0561f55574">SENSOR_HIGH_ACCURACY</a> = 3,   <a href="#p945419536162">SENSOR_MAX_ACCURACY</a><strong id="b418011615553"><a name="b418011615553"></a><a name="b418011615553"></a> </strong>}</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p409017850083931"><a name="p409017850083931"></a><a name="p409017850083931"></a>传感器的精度类型。 <a href="_sensor.md#ga985dcd359f32f3cdfbaecb98f1f436e7">更多...</a></p>
</td>
</tr>
<tr id="row761797042083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1982560559083931"><a name="p1982560559083931"></a><a name="p1982560559083931"></a><a href="_sensor.md#ga4b389f271110480ce20fcc0763cf6d20">SensorRangeType</a> { <a href="_sensor.md#gga4b389f271110480ce20fcc0763cf6d20a8b81d07987b7a203ef04579c60c07986">SENSOR_RANGE_LEVEL1</a> = 0, <a href="_sensor.md#gga4b389f271110480ce20fcc0763cf6d20a39dd36b72a88ef8bdccdddc9225e21a1">SENSOR_RANGE_LEVEL2</a> = 1, <a href="_sensor.md#gga4b389f271110480ce20fcc0763cf6d20a7fee94e695411165b4e1f7b75ce5d52e">SENSOR_RANGE_LEVEL3</a> = 2, <a href="#p165901247205">SENSOR_RANGE_LEVEL_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1732842670083931"><a name="p1732842670083931"></a><a name="p1732842670083931"></a>传感器的量程级别。 <a href="_sensor.md#ga4b389f271110480ce20fcc0763cf6d20">更多...</a></p>
</td>
</tr>
<tr id="row814864904083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1684182240083931"><a name="p1684182240083931"></a><a name="p1684182240083931"></a><a href="_sensor.md#ga066f4ffeb31a1f4cb3ed357736e0afab">SensorModeType</a> {   <a href="_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afabae36be092f02cd01eb5bf1c8ae23af73d">SENSOR_MODE_DEFAULT</a> = 0, <a href="_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afaba5db5e8c1a702aca7ecc751532ecfa69d">SENSOR_MODE_REALTIME</a> = 1, <a href="_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afaba9d264027423bdee89167c3c8f4c71322">SENSOR_MODE_ON_CHANGE</a> = 2, <a href="_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afabac0967e6c4ef5004fda5f26f061fec6ee">SENSOR_MODE_ONE_SHOT</a> = 3,   <a href="_sensor.md#gga066f4ffeb31a1f4cb3ed357736e0afaba3f4f9b49ae7fe1fb89cd3bff398c7f0f">SENSOR_MODE_FIFO_MODE</a> = 4, <a href="#p4932820101810">SENSOR_MODE_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p607938207083931"><a name="p607938207083931"></a><a name="p607938207083931"></a>传感器的工作模式。 <a href="_sensor.md#ga066f4ffeb31a1f4cb3ed357736e0afab">更多...</a></p>
</td>
</tr>
<tr id="row419006202083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1057259586083931"><a name="p1057259586083931"></a><a name="p1057259586083931"></a><a href="_sensor.md#ga588325c4c22f56d09cda6e54df0d9a6c">SensorGroupType</a> { <a href="_sensor.md#gga588325c4c22f56d09cda6e54df0d9a6ca8cc091715416b86fd2eff0a875a76c64">TRADITIONAL_SENSOR_TYPE</a> = 0, <a href="_sensor.md#gga588325c4c22f56d09cda6e54df0d9a6cab8f846ffbc84b2a2275a88707f350a47">MEDICAL_SENSOR_TYPE</a> = 1, <a href="_sensor.md#gga588325c4c22f56d09cda6e54df0d9a6cafdec26032d6c10626eb07a0812fe1d94">SENSOR_GROUP_TYPE_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p265191894083931"><a name="p265191894083931"></a><a name="p265191894083931"></a>枚举传感器的硬件服务组。 <a href="_sensor.md#ga588325c4c22f56d09cda6e54df0d9a6c">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table1428583492083931"></a>
<table><thead align="left"><tr id="row472948697083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p690832379083931"><a name="p690832379083931"></a><a name="p690832379083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p388865562083931"><a name="p388865562083931"></a><a name="p388865562083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2014797344083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p922025810083931"><a name="p922025810083931"></a><a name="p922025810083931"></a><a href="_sensor.md#ga953c149967473431c86ea7f274fe8717">NewSensorInterfaceInstance</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p951328478083931"><a name="p951328478083931"></a><a name="p951328478083931"></a>创建传感器接口实例。 <a href="_sensor.md#ga953c149967473431c86ea7f274fe8717">更多...</a></p>
</td>
</tr>
<tr id="row2083593315083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p267728149083931"><a name="p267728149083931"></a><a name="p267728149083931"></a><a href="_sensor.md#ga7e455c6893ae86b37cc23a75f0f9e299">FreeSensorInterfaceInstance</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p386841971083931"><a name="p386841971083931"></a><a name="p386841971083931"></a>释放传感器接口实例。 <a href="_sensor.md#ga7e455c6893ae86b37cc23a75f0f9e299">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1415399220083931"></a>

传感器设备驱动对传感器服务提供通用的接口能力。

模块提供传感器服务对传感器驱动访问统一接口，服务获取驱动对象或者代理后， 通过其提供的各类方法，以传感器id区分访问不同类型传感器设备，实现获取传感器设备信息、订阅/去订阅传感器数据、 使能/去使能传感器、设置传感器模式、设置传感器精度、量程等可选配置等。

**Since：**

2.2

**Version：**

1.0

## **宏定义说明**<a name="section388467404083931"></a>

## SENSOR\_NAME\_MAX\_LEN<a name="ga4d85ccd1dc1681bcfc7a779b6c76f3b8"></a>

```
#define SENSOR_NAME_MAX_LEN   32
```

**描述：**

Sensor名称的最大长度。

## SENSOR\_VERSION\_MAX\_LEN<a name="section452718671414"></a>

```
#define SENSOR_VERSION_MAX_LEN  16
```

**描述：**

Sensor版本号的最大长度。

## **类型定义说明**<a name="section2044683042083931"></a>

## RecordDataCallback<a name="ga2e0b32ff63dbdaf778e4d7dd4d6bb932"></a>

```
typedef int32_t(* RecordDataCallback) (const struct SensorEvents *)
```

**描述：**

传感器上报数据回调函数的定义，传感器服务用户在订阅传感器时， 需要注册上报数据回调函数，传感器使能后，传感器服务用户可以接受到传感器数据，详见[SensorInterface](_sensor_interface.md)。

## **枚举类型说明**<a name="section1338392842083931"></a>

## SensorAccuracyType<a name="ga985dcd359f32f3cdfbaecb98f1f436e7"></a>

```
enum SensorAccuracyType
```

**描述：**

传感器的精度类型。

<a name="table1719583764083931"></a>
<table><thead align="left"><tr id="row158216326083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1758277812083931"><a name="p1758277812083931"></a><a name="p1758277812083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p260732722083931"><a name="p260732722083931"></a><a name="p260732722083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1631257089083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1028971251083931p0"><a name="entry1028971251083931p0"></a><a name="entry1028971251083931p0"></a><strong id="gga985dcd359f32f3cdfbaecb98f1f436e7a1f1bc8e9ccbc83cb0cb107a795fd85f7"><a name="gga985dcd359f32f3cdfbaecb98f1f436e7a1f1bc8e9ccbc83cb0cb107a795fd85f7"></a><a name="gga985dcd359f32f3cdfbaecb98f1f436e7a1f1bc8e9ccbc83cb0cb107a795fd85f7"></a></strong>SENSOR_NO_ACCURACY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1944095467083931"><a name="p1944095467083931"></a><a name="p1944095467083931"></a>无精度类型。</p>
</td>
</tr>
<tr id="row1782083949083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry494410003083931p0"><a name="entry494410003083931p0"></a><a name="entry494410003083931p0"></a><strong id="gga985dcd359f32f3cdfbaecb98f1f436e7a6c2ad64f15e8d0ba24f8b573bc0f19ed"><a name="gga985dcd359f32f3cdfbaecb98f1f436e7a6c2ad64f15e8d0ba24f8b573bc0f19ed"></a><a name="gga985dcd359f32f3cdfbaecb98f1f436e7a6c2ad64f15e8d0ba24f8b573bc0f19ed"></a></strong>SENSOR_LOW_ACCURACY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1454377161713"><a name="p1454377161713"></a><a name="p1454377161713"></a>低精度类型。</p>
<p id="p177981047192016"><a name="p177981047192016"></a><a name="p177981047192016"></a></p>
</td>
</tr>
<tr id="row230120688083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1654682737083931p0"><a name="entry1654682737083931p0"></a><a name="entry1654682737083931p0"></a><strong id="gga985dcd359f32f3cdfbaecb98f1f436e7a9083140f63420c7b109c5ae8f009a8dd"><a name="gga985dcd359f32f3cdfbaecb98f1f436e7a9083140f63420c7b109c5ae8f009a8dd"></a><a name="gga985dcd359f32f3cdfbaecb98f1f436e7a9083140f63420c7b109c5ae8f009a8dd"></a></strong>SENSOR_MEDIUM_ACCURACY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1953718630083931"><a name="p1953718630083931"></a><a name="p1953718630083931"></a>中等精度类型。</p>
<p id="p17798847142019"><a name="p17798847142019"></a><a name="p17798847142019"></a></p>
</td>
</tr>
<tr id="row729789488083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry927596552083931p0"><a name="entry927596552083931p0"></a><a name="entry927596552083931p0"></a><strong id="gga985dcd359f32f3cdfbaecb98f1f436e7a8a8e8f15654a31f9df91bb0561f55574"><a name="gga985dcd359f32f3cdfbaecb98f1f436e7a8a8e8f15654a31f9df91bb0561f55574"></a><a name="gga985dcd359f32f3cdfbaecb98f1f436e7a8a8e8f15654a31f9df91bb0561f55574"></a></strong>SENSOR_HIGH_ACCURACY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1664082127083931"><a name="p1664082127083931"></a><a name="p1664082127083931"></a>高精度类型。</p>
<p id="p5799144718209"><a name="p5799144718209"></a><a name="p5799144718209"></a></p>
</td>
</tr>
<tr id="row14541532165"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p945419536162"><a name="p945419536162"></a><a name="p945419536162"></a>SENSOR_MAX_ACCURACY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1542049191083931"><a name="p1542049191083931"></a><a name="p1542049191083931"></a>最大精度类型。</p>
<p id="p167991847162018"><a name="p167991847162018"></a><a name="p167991847162018"></a></p>
</td>
</tr>
</tbody>
</table>

## SensorGroupType<a name="ga588325c4c22f56d09cda6e54df0d9a6c"></a>

```
enum SensorGroupType
```

**描述：**

枚举传感器的硬件服务组。

<a name="table525975437083931"></a>
<table><thead align="left"><tr id="row2073639451083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p856324832083931"><a name="p856324832083931"></a><a name="p856324832083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1743136996083931"><a name="p1743136996083931"></a><a name="p1743136996083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1758395607083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1043945506083931p0"><a name="entry1043945506083931p0"></a><a name="entry1043945506083931p0"></a><strong id="gga588325c4c22f56d09cda6e54df0d9a6ca8cc091715416b86fd2eff0a875a76c64"><a name="gga588325c4c22f56d09cda6e54df0d9a6ca8cc091715416b86fd2eff0a875a76c64"></a><a name="gga588325c4c22f56d09cda6e54df0d9a6ca8cc091715416b86fd2eff0a875a76c64"></a></strong>TRADITIONAL_SENSOR_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p803139093083931"><a name="p803139093083931"></a><a name="p803139093083931"></a>传统传感器类型，传感器ID枚举值范围为128-160。</p>
<p id="p10810154712019"><a name="p10810154712019"></a><a name="p10810154712019"></a></p>
</td>
</tr>
<tr id="row1113468034083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry447274138083931p0"><a name="entry447274138083931p0"></a><a name="entry447274138083931p0"></a><strong id="gga588325c4c22f56d09cda6e54df0d9a6cab8f846ffbc84b2a2275a88707f350a47"><a name="gga588325c4c22f56d09cda6e54df0d9a6cab8f846ffbc84b2a2275a88707f350a47"></a><a name="gga588325c4c22f56d09cda6e54df0d9a6cab8f846ffbc84b2a2275a88707f350a47"></a></strong>MEDICAL_SENSOR_TYPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p408496163083931"><a name="p408496163083931"></a><a name="p408496163083931"></a>医疗传感器类型，传感器ID枚举值范围不在128-160之间。</p>
<p id="p1381013475209"><a name="p1381013475209"></a><a name="p1381013475209"></a></p>
</td>
</tr>
<tr id="row674461349083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2046450608083931p0"><a name="entry2046450608083931p0"></a><a name="entry2046450608083931p0"></a><strong id="gga588325c4c22f56d09cda6e54df0d9a6cafdec26032d6c10626eb07a0812fe1d94"><a name="gga588325c4c22f56d09cda6e54df0d9a6cafdec26032d6c10626eb07a0812fe1d94"></a><a name="gga588325c4c22f56d09cda6e54df0d9a6cafdec26032d6c10626eb07a0812fe1d94"></a></strong>SENSOR_GROUP_TYPE_MAX</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p678706999083931"><a name="p678706999083931"></a><a name="p678706999083931"></a>最大传感器类型。</p>
<p id="p2810174722014"><a name="p2810174722014"></a><a name="p2810174722014"></a></p>
</td>
</tr>
</tbody>
</table>

## SensorModeType<a name="ga066f4ffeb31a1f4cb3ed357736e0afab"></a>

```
enum SensorModeType
```

**描述：**

传感器的工作模式。

<a name="table1397101693083931"></a>
<table><thead align="left"><tr id="row522262342083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1597310322083931"><a name="p1597310322083931"></a><a name="p1597310322083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1605723966083931"><a name="p1605723966083931"></a><a name="p1605723966083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1519460007083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry778636892083931p0"><a name="entry778636892083931p0"></a><a name="entry778636892083931p0"></a><strong id="gga066f4ffeb31a1f4cb3ed357736e0afabae36be092f02cd01eb5bf1c8ae23af73d"><a name="gga066f4ffeb31a1f4cb3ed357736e0afabae36be092f02cd01eb5bf1c8ae23af73d"></a><a name="gga066f4ffeb31a1f4cb3ed357736e0afabae36be092f02cd01eb5bf1c8ae23af73d"></a></strong>SENSOR_MODE_DEFAULT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p4769470083931"><a name="p4769470083931"></a><a name="p4769470083931"></a>传感器默认工作模式状态。</p>
<p id="p17820174716206"><a name="p17820174716206"></a><a name="p17820174716206"></a></p>
</td>
</tr>
<tr id="row503986892083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1479635589083931p0"><a name="entry1479635589083931p0"></a><a name="entry1479635589083931p0"></a><strong id="gga066f4ffeb31a1f4cb3ed357736e0afaba5db5e8c1a702aca7ecc751532ecfa69d"><a name="gga066f4ffeb31a1f4cb3ed357736e0afaba5db5e8c1a702aca7ecc751532ecfa69d"></a><a name="gga066f4ffeb31a1f4cb3ed357736e0afaba5db5e8c1a702aca7ecc751532ecfa69d"></a></strong>SENSOR_MODE_REALTIME</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p186673428186"><a name="p186673428186"></a><a name="p186673428186"></a>传感器实时工作模式状态，一组数据上报一次。</p>
</td>
</tr>
<tr id="row937411744083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1991644509083931p0"><a name="entry1991644509083931p0"></a><a name="entry1991644509083931p0"></a><strong id="gga066f4ffeb31a1f4cb3ed357736e0afaba9d264027423bdee89167c3c8f4c71322"><a name="gga066f4ffeb31a1f4cb3ed357736e0afaba9d264027423bdee89167c3c8f4c71322"></a><a name="gga066f4ffeb31a1f4cb3ed357736e0afaba9d264027423bdee89167c3c8f4c71322"></a></strong>SENSOR_MODE_ON_CHANGE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2023176185083931"><a name="p2023176185083931"></a><a name="p2023176185083931"></a>传感器实时工作模式状态，状态变更上报一次。</p>
<p id="p68202047102018"><a name="p68202047102018"></a><a name="p68202047102018"></a></p>
</td>
</tr>
<tr id="row919270530083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry295324827083931p0"><a name="entry295324827083931p0"></a><a name="entry295324827083931p0"></a><strong id="gga066f4ffeb31a1f4cb3ed357736e0afabac0967e6c4ef5004fda5f26f061fec6ee"><a name="gga066f4ffeb31a1f4cb3ed357736e0afabac0967e6c4ef5004fda5f26f061fec6ee"></a><a name="gga066f4ffeb31a1f4cb3ed357736e0afabac0967e6c4ef5004fda5f26f061fec6ee"></a></strong>SENSOR_MODE_ONE_SHOT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2147156361083931"><a name="p2147156361083931"></a><a name="p2147156361083931"></a>传感器实时工作模式状态，只上报一次。</p>
<p id="p17820104717204"><a name="p17820104717204"></a><a name="p17820104717204"></a></p>
</td>
</tr>
<tr id="row939992555083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2092703602083931p0"><a name="entry2092703602083931p0"></a><a name="entry2092703602083931p0"></a><strong id="gga066f4ffeb31a1f4cb3ed357736e0afaba3f4f9b49ae7fe1fb89cd3bff398c7f0f"><a name="gga066f4ffeb31a1f4cb3ed357736e0afaba3f4f9b49ae7fe1fb89cd3bff398c7f0f"></a><a name="gga066f4ffeb31a1f4cb3ed357736e0afaba3f4f9b49ae7fe1fb89cd3bff398c7f0f"></a></strong>SENSOR_MODE_FIFO_MODE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p682461771083931"><a name="p682461771083931"></a><a name="p682461771083931"></a>传感器缓存工作模式状态，根据配置的缓存大小上报。</p>
<p id="p10820174722011"><a name="p10820174722011"></a><a name="p10820174722011"></a></p>
</td>
</tr>
<tr id="row2932120141810"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p4932820101810"><a name="p4932820101810"></a><a name="p4932820101810"></a>SENSOR_MODE_MAX</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1656594274083931"><a name="p1656594274083931"></a><a name="p1656594274083931"></a>传感器最大类型标识。</p>
<p id="p4820134742015"><a name="p4820134742015"></a><a name="p4820134742015"></a></p>
</td>
</tr>
</tbody>
</table>

## SensorRangeType<a name="ga4b389f271110480ce20fcc0763cf6d20"></a>

```
enum SensorRangeType
```

**描述：**

传感器的量程级别。

<a name="table1834387356083931"></a>
<table><thead align="left"><tr id="row1059795879083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p952407779083931"><a name="p952407779083931"></a><a name="p952407779083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p360282886083931"><a name="p360282886083931"></a><a name="p360282886083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1791388304083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry884579717083931p0"><a name="entry884579717083931p0"></a><a name="entry884579717083931p0"></a><strong id="gga4b389f271110480ce20fcc0763cf6d20a8b81d07987b7a203ef04579c60c07986"><a name="gga4b389f271110480ce20fcc0763cf6d20a8b81d07987b7a203ef04579c60c07986"></a><a name="gga4b389f271110480ce20fcc0763cf6d20a8b81d07987b7a203ef04579c60c07986"></a></strong>SENSOR_RANGE_LEVEL1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p564623762083931"><a name="p564623762083931"></a><a name="p564623762083931"></a>量程级别1。</p>
</td>
</tr>
<tr id="row181128226083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry280649472083931p0"><a name="entry280649472083931p0"></a><a name="entry280649472083931p0"></a><strong id="gga4b389f271110480ce20fcc0763cf6d20a39dd36b72a88ef8bdccdddc9225e21a1"><a name="gga4b389f271110480ce20fcc0763cf6d20a39dd36b72a88ef8bdccdddc9225e21a1"></a><a name="gga4b389f271110480ce20fcc0763cf6d20a39dd36b72a88ef8bdccdddc9225e21a1"></a></strong>SENSOR_RANGE_LEVEL2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1940304218205"><a name="p1940304218205"></a><a name="p1940304218205"></a>量程级别2。</p>
<p id="p20832647182013"><a name="p20832647182013"></a><a name="p20832647182013"></a></p>
</td>
</tr>
<tr id="row1421063281083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry527982740083931p0"><a name="entry527982740083931p0"></a><a name="entry527982740083931p0"></a><strong id="gga4b389f271110480ce20fcc0763cf6d20a7fee94e695411165b4e1f7b75ce5d52e"><a name="gga4b389f271110480ce20fcc0763cf6d20a7fee94e695411165b4e1f7b75ce5d52e"></a><a name="gga4b389f271110480ce20fcc0763cf6d20a7fee94e695411165b4e1f7b75ce5d52e"></a></strong>SENSOR_RANGE_LEVEL3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1186047549083931"><a name="p1186047549083931"></a><a name="p1186047549083931"></a>量程级别3。</p>
<p id="p8832154742020"><a name="p8832154742020"></a><a name="p8832154742020"></a></p>
</td>
</tr>
<tr id="row15589182442012"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p165901247205"><a name="p165901247205"></a><a name="p165901247205"></a>SENSOR_RANGE_LEVEL_MAX</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1838042187083931"><a name="p1838042187083931"></a><a name="p1838042187083931"></a>量程最大级别。</p>
<p id="p10832347122016"><a name="p10832347122016"></a><a name="p10832347122016"></a></p>
</td>
</tr>
</tbody>
</table>

## SensorStatus<a name="gaa348cf223e558076864814ee88920cec"></a>

```
enum SensorStatus
```

**描述：**

定义传感器模块返回值类型。

<a name="table1087112463083931"></a>
<table><thead align="left"><tr id="row1398566460083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p921433197083931"><a name="p921433197083931"></a><a name="p921433197083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1672241010083931"><a name="p1672241010083931"></a><a name="p1672241010083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1464877131083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1451676188083931p0"><a name="entry1451676188083931p0"></a><a name="entry1451676188083931p0"></a><strong id="ggaa348cf223e558076864814ee88920ceca6fe3474c6df06ef2bd1d3fb84fc57827"><a name="ggaa348cf223e558076864814ee88920ceca6fe3474c6df06ef2bd1d3fb84fc57827"></a><a name="ggaa348cf223e558076864814ee88920ceca6fe3474c6df06ef2bd1d3fb84fc57827"></a></strong>SENSOR_SUCCESS</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1865436158083931"><a name="p1865436158083931"></a><a name="p1865436158083931"></a>传感器执行成功。</p>
<p id="p1484244710207"><a name="p1484244710207"></a><a name="p1484244710207"></a></p>
</td>
</tr>
<tr id="row650921423083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1271825747083931p0"><a name="entry1271825747083931p0"></a><a name="entry1271825747083931p0"></a><strong id="ggaa348cf223e558076864814ee88920cecafc02a48cdab506c10ef1c5c66600ae71"><a name="ggaa348cf223e558076864814ee88920cecafc02a48cdab506c10ef1c5c66600ae71"></a><a name="ggaa348cf223e558076864814ee88920cecafc02a48cdab506c10ef1c5c66600ae71"></a></strong>SENSOR_FAILURE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p360511378598"><a name="p360511378598"></a><a name="p360511378598"></a>传感器执行失败。</p>
<p id="p1170134316596"><a name="p1170134316596"></a><a name="p1170134316596"></a></p>
</td>
</tr>
<tr id="row206475844083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry5346918083931p0"><a name="entry5346918083931p0"></a><a name="entry5346918083931p0"></a><strong id="ggaa348cf223e558076864814ee88920cecacbf62f7bd2738d9be4b81e603c4f3bd5"><a name="ggaa348cf223e558076864814ee88920cecacbf62f7bd2738d9be4b81e603c4f3bd5"></a><a name="ggaa348cf223e558076864814ee88920cecacbf62f7bd2738d9be4b81e603c4f3bd5"></a></strong>SENSOR_NOT_SUPPORT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1004994237083931"><a name="p1004994237083931"></a><a name="p1004994237083931"></a>传感器不支持。</p>
<p id="p58422047152011"><a name="p58422047152011"></a><a name="p58422047152011"></a></p>
</td>
</tr>
<tr id="row639377389083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry286216855083931p0"><a name="entry286216855083931p0"></a><a name="entry286216855083931p0"></a><strong id="ggaa348cf223e558076864814ee88920ceca0728f44385b2cb32a5c01e1370e6f2d7"><a name="ggaa348cf223e558076864814ee88920ceca0728f44385b2cb32a5c01e1370e6f2d7"></a><a name="ggaa348cf223e558076864814ee88920ceca0728f44385b2cb32a5c01e1370e6f2d7"></a></strong>SENSOR_INVALID_PARAM</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1632292308083931"><a name="p1632292308083931"></a><a name="p1632292308083931"></a>传感器无效参数。</p>
<p id="p48429473205"><a name="p48429473205"></a><a name="p48429473205"></a></p>
</td>
</tr>
<tr id="row1014789169083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry853862721083931p0"><a name="entry853862721083931p0"></a><a name="entry853862721083931p0"></a><strong id="ggaa348cf223e558076864814ee88920cecaeb19761a981ab03ce5144ed0b4c7a48c"><a name="ggaa348cf223e558076864814ee88920cecaeb19761a981ab03ce5144ed0b4c7a48c"></a><a name="ggaa348cf223e558076864814ee88920cecaeb19761a981ab03ce5144ed0b4c7a48c"></a></strong>SENSOR_INVALID_SERVICE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36803827083931"><a name="p36803827083931"></a><a name="p36803827083931"></a>传感器无效服务。</p>
<p id="p884218475208"><a name="p884218475208"></a><a name="p884218475208"></a></p>
</td>
</tr>
<tr id="row1431320206584"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p431372085818"><a name="p431372085818"></a><a name="p431372085818"></a>SENSOR_NULL_PTR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1175084580083931"><a name="p1175084580083931"></a><a name="p1175084580083931"></a>传感器空指针。</p>
<p id="p7842047172016"><a name="p7842047172016"></a><a name="p7842047172016"></a></p>
</td>
</tr>
</tbody>
</table>

## SensorTypeTag<a name="gaea6a2a57db175118e08189b73f8f3da5"></a>

```
enum SensorTypeTag
```

**描述：**

定义传感器类型标识。

<a name="table34109640083931"></a>
<table><thead align="left"><tr id="row1437710018083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1675860586083931"><a name="p1675860586083931"></a><a name="p1675860586083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p873571094083931"><a name="p873571094083931"></a><a name="p873571094083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1855416084083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1470591171083931p0"><a name="entry1470591171083931p0"></a><a name="entry1470591171083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a3f8e3e31e6a356192f150019309925ee"><a name="ggaea6a2a57db175118e08189b73f8f3da5a3f8e3e31e6a356192f150019309925ee"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a3f8e3e31e6a356192f150019309925ee"></a></strong>SENSOR_TYPE_NONE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1935202681083931"><a name="p1935202681083931"></a><a name="p1935202681083931"></a>空传感器类型，用于测试。</p>
<p id="p1385310477204"><a name="p1385310477204"></a><a name="p1385310477204"></a></p>
</td>
</tr>
<tr id="row1445284490083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1661194790083931p0"><a name="entry1661194790083931p0"></a><a name="entry1661194790083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5abd9779b04292b5e8054485b10fccb99c"><a name="ggaea6a2a57db175118e08189b73f8f3da5abd9779b04292b5e8054485b10fccb99c"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5abd9779b04292b5e8054485b10fccb99c"></a></strong>SENSOR_TYPE_ACCELEROMETER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1261224514223"><a name="p1261224514223"></a><a name="p1261224514223"></a>加速度传感器。</p>
</td>
</tr>
<tr id="row361724586083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry399583663083931p0"><a name="entry399583663083931p0"></a><a name="entry399583663083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5adc01250dcba5642d294f74ba4d115c28"><a name="ggaea6a2a57db175118e08189b73f8f3da5adc01250dcba5642d294f74ba4d115c28"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5adc01250dcba5642d294f74ba4d115c28"></a></strong>SENSOR_TYPE_GYROSCOPE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p687162681083931"><a name="p687162681083931"></a><a name="p687162681083931"></a>陀螺仪传感器。</p>
<p id="p1285344752010"><a name="p1285344752010"></a><a name="p1285344752010"></a></p>
</td>
</tr>
<tr id="row1911771658083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry731622882083931p0"><a name="entry731622882083931p0"></a><a name="entry731622882083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a93f36cca60373938f2410162b16b531e"><a name="ggaea6a2a57db175118e08189b73f8f3da5a93f36cca60373938f2410162b16b531e"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a93f36cca60373938f2410162b16b531e"></a></strong>SENSOR_TYPE_PHOTOPLETHYSMOGRAPH</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p770632597083931"><a name="p770632597083931"></a><a name="p770632597083931"></a>心率传感器。</p>
<p id="p198530476203"><a name="p198530476203"></a><a name="p198530476203"></a></p>
</td>
</tr>
<tr id="row1740320997083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1924735053083931p0"><a name="entry1924735053083931p0"></a><a name="entry1924735053083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a2d8e52264648743ae154b99eef141607"><a name="ggaea6a2a57db175118e08189b73f8f3da5a2d8e52264648743ae154b99eef141607"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a2d8e52264648743ae154b99eef141607"></a></strong>SENSOR_TYPE_ELECTROCARDIOGRAPH</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1556687828083931"><a name="p1556687828083931"></a><a name="p1556687828083931"></a>心电传感器。</p>
<p id="p3854184702019"><a name="p3854184702019"></a><a name="p3854184702019"></a></p>
</td>
</tr>
<tr id="row640218382083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry355064512083931p0"><a name="entry355064512083931p0"></a><a name="entry355064512083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a717a301be1664d4cd1ea543ca0653325"><a name="ggaea6a2a57db175118e08189b73f8f3da5a717a301be1664d4cd1ea543ca0653325"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a717a301be1664d4cd1ea543ca0653325"></a></strong>SENSOR_TYPE_AMBIENT_LIGHT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1140722066083931"><a name="p1140722066083931"></a><a name="p1140722066083931"></a>环境光传感器。</p>
<p id="p2085424717200"><a name="p2085424717200"></a><a name="p2085424717200"></a></p>
</td>
</tr>
<tr id="row1563803584083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry951422621083931p0"><a name="entry951422621083931p0"></a><a name="entry951422621083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a74438e3f4f1f8cb1e97ccebbd1096fe8"><a name="ggaea6a2a57db175118e08189b73f8f3da5a74438e3f4f1f8cb1e97ccebbd1096fe8"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a74438e3f4f1f8cb1e97ccebbd1096fe8"></a></strong>SENSOR_TYPE_MAGNETIC_FIELD</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p35454756083931"><a name="p35454756083931"></a><a name="p35454756083931"></a>地磁传感器。</p>
<p id="p585411474204"><a name="p585411474204"></a><a name="p585411474204"></a></p>
</td>
</tr>
<tr id="row1848864829083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2084307901083931p0"><a name="entry2084307901083931p0"></a><a name="entry2084307901083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a3ed11be057d851a8ee1db6d946b0e69b"><a name="ggaea6a2a57db175118e08189b73f8f3da5a3ed11be057d851a8ee1db6d946b0e69b"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a3ed11be057d851a8ee1db6d946b0e69b"></a></strong>SENSOR_TYPE_CAPACITIVE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885316405083931"><a name="p885316405083931"></a><a name="p885316405083931"></a>电容传感器。</p>
<p id="p16854447142016"><a name="p16854447142016"></a><a name="p16854447142016"></a></p>
</td>
</tr>
<tr id="row1751942671083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1213323461083931p0"><a name="entry1213323461083931p0"></a><a name="entry1213323461083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5ab9ec86561c555fe323e6a45508e20ca8"><a name="ggaea6a2a57db175118e08189b73f8f3da5ab9ec86561c555fe323e6a45508e20ca8"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5ab9ec86561c555fe323e6a45508e20ca8"></a></strong>SENSOR_TYPE_BAROMETER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1747519113083931"><a name="p1747519113083931"></a><a name="p1747519113083931"></a>气压计传感器。</p>
<p id="p17854447192010"><a name="p17854447192010"></a><a name="p17854447192010"></a></p>
</td>
</tr>
<tr id="row1546308754083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry17284080083931p0"><a name="entry17284080083931p0"></a><a name="entry17284080083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a1931d9687ccbd0aac063417fc0d7b4f6"><a name="ggaea6a2a57db175118e08189b73f8f3da5a1931d9687ccbd0aac063417fc0d7b4f6"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a1931d9687ccbd0aac063417fc0d7b4f6"></a></strong>SENSOR_TYPE_TEMPERATURE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1205027963083931"><a name="p1205027963083931"></a><a name="p1205027963083931"></a>温度传感器。</p>
<p id="p28541147142019"><a name="p28541147142019"></a><a name="p28541147142019"></a></p>
</td>
</tr>
<tr id="row1745212220083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1657835294083931p0"><a name="entry1657835294083931p0"></a><a name="entry1657835294083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a7a343ec270d2bd5b96b4748fb4300665"><a name="ggaea6a2a57db175118e08189b73f8f3da5a7a343ec270d2bd5b96b4748fb4300665"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a7a343ec270d2bd5b96b4748fb4300665"></a></strong>SENSOR_TYPE_HALL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2033085996083931"><a name="p2033085996083931"></a><a name="p2033085996083931"></a>霍尔传感器。</p>
<p id="p10854194742019"><a name="p10854194742019"></a><a name="p10854194742019"></a></p>
</td>
</tr>
<tr id="row1147787062083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry279326165083931p0"><a name="entry279326165083931p0"></a><a name="entry279326165083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a875d96bbe6c91eb906e47bbda4250dfe"><a name="ggaea6a2a57db175118e08189b73f8f3da5a875d96bbe6c91eb906e47bbda4250dfe"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a875d96bbe6c91eb906e47bbda4250dfe"></a></strong>SENSOR_TYPE_GESTURE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1251197207083931"><a name="p1251197207083931"></a><a name="p1251197207083931"></a>手势传感器。</p>
<p id="p1285414719207"><a name="p1285414719207"></a><a name="p1285414719207"></a></p>
</td>
</tr>
<tr id="row1345135089083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry957577635083931p0"><a name="entry957577635083931p0"></a><a name="entry957577635083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a47912cab9ef79bbe4eb20538a88ce59c"><a name="ggaea6a2a57db175118e08189b73f8f3da5a47912cab9ef79bbe4eb20538a88ce59c"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a47912cab9ef79bbe4eb20538a88ce59c"></a></strong>SENSOR_TYPE_PROXIMITY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p24970562083931"><a name="p24970562083931"></a><a name="p24970562083931"></a>接近光传感器。</p>
<p id="p128541047182018"><a name="p128541047182018"></a><a name="p128541047182018"></a></p>
</td>
</tr>
<tr id="row1530982116083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1502081905083931p0"><a name="entry1502081905083931p0"></a><a name="entry1502081905083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a09fbc658c0f86f34e08513ef355870f5"><a name="ggaea6a2a57db175118e08189b73f8f3da5a09fbc658c0f86f34e08513ef355870f5"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a09fbc658c0f86f34e08513ef355870f5"></a></strong>SENSOR_TYPE_HUMIDITY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1666986814083931"><a name="p1666986814083931"></a><a name="p1666986814083931"></a>湿度传感器。</p>
<p id="p198541847162017"><a name="p198541847162017"></a><a name="p198541847162017"></a></p>
</td>
</tr>
<tr id="row1790086342083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1631733514083931p0"><a name="entry1631733514083931p0"></a><a name="entry1631733514083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a5e792e48a4eb7b53561af8e511dba943"><a name="ggaea6a2a57db175118e08189b73f8f3da5a5e792e48a4eb7b53561af8e511dba943"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a5e792e48a4eb7b53561af8e511dba943"></a></strong>SENSOR_TYPE_MEDICAL_BEGIN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1003881895083931"><a name="p1003881895083931"></a><a name="p1003881895083931"></a>医疗传感器ID枚举值范围的开始。</p>
<p id="p148554474207"><a name="p148554474207"></a><a name="p148554474207"></a></p>
</td>
</tr>
<tr id="row776688336083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry577370366083931p0"><a name="entry577370366083931p0"></a><a name="entry577370366083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5ad53330afd8a904e115774ffc04f2e89e"><a name="ggaea6a2a57db175118e08189b73f8f3da5ad53330afd8a904e115774ffc04f2e89e"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5ad53330afd8a904e115774ffc04f2e89e"></a></strong>SENSOR_TYPE_MEDICAL_END</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86061542083931"><a name="p86061542083931"></a><a name="p86061542083931"></a>医疗传感器ID枚举值范围的结束。</p>
<p id="p188551847162016"><a name="p188551847162016"></a><a name="p188551847162016"></a></p>
</td>
</tr>
<tr id="row1254936253083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry657867538083931p0"><a name="entry657867538083931p0"></a><a name="entry657867538083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a618cf39cdc6bac1ffe31ba2ad488ca53"><a name="ggaea6a2a57db175118e08189b73f8f3da5a618cf39cdc6bac1ffe31ba2ad488ca53"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a618cf39cdc6bac1ffe31ba2ad488ca53"></a></strong>SENSOR_TYPE_PHYSICAL_MAX</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p684239861083931"><a name="p684239861083931"></a><a name="p684239861083931"></a>物理传感器最大类型。</p>
<p id="p1485514714209"><a name="p1485514714209"></a><a name="p1485514714209"></a></p>
</td>
</tr>
<tr id="row269108655083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry646771171083931p0"><a name="entry646771171083931p0"></a><a name="entry646771171083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5af2ccaca19bdabe513c45c058003ed596"><a name="ggaea6a2a57db175118e08189b73f8f3da5af2ccaca19bdabe513c45c058003ed596"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5af2ccaca19bdabe513c45c058003ed596"></a></strong>SENSOR_TYPE_ORIENTATION</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p13033163083931"><a name="p13033163083931"></a><a name="p13033163083931"></a>方向传感器。</p>
<p id="p08551947182012"><a name="p08551947182012"></a><a name="p08551947182012"></a></p>
</td>
</tr>
<tr id="row36118914083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry262640525083931p0"><a name="entry262640525083931p0"></a><a name="entry262640525083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5ac7d364262029cc21bc865577d5288a1e"><a name="ggaea6a2a57db175118e08189b73f8f3da5ac7d364262029cc21bc865577d5288a1e"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5ac7d364262029cc21bc865577d5288a1e"></a></strong>SENSOR_TYPE_GRAVITY</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1039535972083931"><a name="p1039535972083931"></a><a name="p1039535972083931"></a>重力传感器。</p>
<p id="p138552470203"><a name="p138552470203"></a><a name="p138552470203"></a></p>
</td>
</tr>
<tr id="row775938621083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1048663455083931p0"><a name="entry1048663455083931p0"></a><a name="entry1048663455083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a914a1f090dcc61586318fd4eb4cb1384"><a name="ggaea6a2a57db175118e08189b73f8f3da5a914a1f090dcc61586318fd4eb4cb1384"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a914a1f090dcc61586318fd4eb4cb1384"></a></strong>SENSOR_TYPE_LINEAR_ACCELERATION</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1518949625083931"><a name="p1518949625083931"></a><a name="p1518949625083931"></a>线性加速度传感器。</p>
<p id="p3855144710209"><a name="p3855144710209"></a><a name="p3855144710209"></a></p>
</td>
</tr>
<tr id="row1441781048083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1994812023083931p0"><a name="entry1994812023083931p0"></a><a name="entry1994812023083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5ac407aca03c7ce72ea55e52f40477561b"><a name="ggaea6a2a57db175118e08189b73f8f3da5ac407aca03c7ce72ea55e52f40477561b"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5ac407aca03c7ce72ea55e52f40477561b"></a></strong>SENSOR_TYPE_ROTATION_VECTOR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p672229245083931"><a name="p672229245083931"></a><a name="p672229245083931"></a>旋转矢量传感器。</p>
<p id="p5855247102013"><a name="p5855247102013"></a><a name="p5855247102013"></a></p>
</td>
</tr>
<tr id="row1243437808083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry853868479083931p0"><a name="entry853868479083931p0"></a><a name="entry853868479083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a7d9456395f361833de2ee3ef12a1af2a"><a name="ggaea6a2a57db175118e08189b73f8f3da5a7d9456395f361833de2ee3ef12a1af2a"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a7d9456395f361833de2ee3ef12a1af2a"></a></strong>SENSOR_TYPE_AMBIENT_TEMPERATURE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p430716337083931"><a name="p430716337083931"></a><a name="p430716337083931"></a>环境温度传感器</p>
<p id="p148551847162016"><a name="p148551847162016"></a><a name="p148551847162016"></a></p>
</td>
</tr>
<tr id="row771529600083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry306726029083931p0"><a name="entry306726029083931p0"></a><a name="entry306726029083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a492db205ab694c3954f4b46fa6a999af"><a name="ggaea6a2a57db175118e08189b73f8f3da5a492db205ab694c3954f4b46fa6a999af"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a492db205ab694c3954f4b46fa6a999af"></a></strong>SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p499403235083931"><a name="p499403235083931"></a><a name="p499403235083931"></a>未校准磁场传感器。</p>
<p id="p185514712207"><a name="p185514712207"></a><a name="p185514712207"></a></p>
</td>
</tr>
<tr id="row43468789083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry938164642083931p0"><a name="entry938164642083931p0"></a><a name="entry938164642083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5af8302206e90774d69fb272ee50e6607b"><a name="ggaea6a2a57db175118e08189b73f8f3da5af8302206e90774d69fb272ee50e6607b"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5af8302206e90774d69fb272ee50e6607b"></a></strong>SENSOR_TYPE_GAME_ROTATION_VECTOR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p691244890083931"><a name="p691244890083931"></a><a name="p691244890083931"></a>游戏旋转矢量传感器。</p>
<p id="p085514772010"><a name="p085514772010"></a><a name="p085514772010"></a></p>
</td>
</tr>
<tr id="row698152899083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1962752011083931p0"><a name="entry1962752011083931p0"></a><a name="entry1962752011083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5ad123a39ee0525c760755a4b40e5dc638"><a name="ggaea6a2a57db175118e08189b73f8f3da5ad123a39ee0525c760755a4b40e5dc638"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5ad123a39ee0525c760755a4b40e5dc638"></a></strong>SENSOR_TYPE_GYROSCOPE_UNCALIBRATED</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p969711117083931"><a name="p969711117083931"></a><a name="p969711117083931"></a>未校准陀螺仪传感器。</p>
<p id="p98551047102010"><a name="p98551047102010"></a><a name="p98551047102010"></a></p>
</td>
</tr>
<tr id="row1938308730083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry274598530083931p0"><a name="entry274598530083931p0"></a><a name="entry274598530083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a3a4ce3aad51d07a5475c3fb1de90ec80"><a name="ggaea6a2a57db175118e08189b73f8f3da5a3a4ce3aad51d07a5475c3fb1de90ec80"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a3a4ce3aad51d07a5475c3fb1de90ec80"></a></strong>SENSOR_TYPE_SIGNIFICANT_MOTION</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p239976198083931"><a name="p239976198083931"></a><a name="p239976198083931"></a>大幅度动作传感器。</p>
<p id="p085518476206"><a name="p085518476206"></a><a name="p085518476206"></a></p>
</td>
</tr>
<tr id="row647604550083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry675624283083931p0"><a name="entry675624283083931p0"></a><a name="entry675624283083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a443b13dc20beadc7821db8df7682cd58"><a name="ggaea6a2a57db175118e08189b73f8f3da5a443b13dc20beadc7821db8df7682cd58"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a443b13dc20beadc7821db8df7682cd58"></a></strong>SENSOR_TYPE_PEDOMETER_DETECTION</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p495090196083931"><a name="p495090196083931"></a><a name="p495090196083931"></a>计步器检测传感器。</p>
<p id="p1285594742020"><a name="p1285594742020"></a><a name="p1285594742020"></a></p>
</td>
</tr>
<tr id="row1712513806083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1357138436083931p0"><a name="entry1357138436083931p0"></a><a name="entry1357138436083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a0cef311260d7668885a937ee1ee8d5d8"><a name="ggaea6a2a57db175118e08189b73f8f3da5a0cef311260d7668885a937ee1ee8d5d8"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a0cef311260d7668885a937ee1ee8d5d8"></a></strong>SENSOR_TYPE_PEDOMETER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1588399533083931"><a name="p1588399533083931"></a><a name="p1588399533083931"></a>计步器传感器。</p>
<p id="p18856114712015"><a name="p18856114712015"></a><a name="p18856114712015"></a></p>
</td>
</tr>
<tr id="row1034491472083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1154369401083931p0"><a name="entry1154369401083931p0"></a><a name="entry1154369401083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a80a8adf73ab45b0eaaeb24fa3c5351f0"><a name="ggaea6a2a57db175118e08189b73f8f3da5a80a8adf73ab45b0eaaeb24fa3c5351f0"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a80a8adf73ab45b0eaaeb24fa3c5351f0"></a></strong>SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1046014164083931"><a name="p1046014164083931"></a><a name="p1046014164083931"></a>地磁旋转矢量传感器。</p>
<p id="p11856184713209"><a name="p11856184713209"></a><a name="p11856184713209"></a></p>
</td>
</tr>
<tr id="row1076306923083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry886367842083931p0"><a name="entry886367842083931p0"></a><a name="entry886367842083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a4d4febf14d8366d19661d7b1acb5ff91"><a name="ggaea6a2a57db175118e08189b73f8f3da5a4d4febf14d8366d19661d7b1acb5ff91"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a4d4febf14d8366d19661d7b1acb5ff91"></a></strong>SENSOR_TYPE_HEART_RATE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2073158359083931"><a name="p2073158359083931"></a><a name="p2073158359083931"></a>心率传感器。</p>
<p id="p1685614714205"><a name="p1685614714205"></a><a name="p1685614714205"></a></p>
</td>
</tr>
<tr id="row1979641526083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1517371160083931p0"><a name="entry1517371160083931p0"></a><a name="entry1517371160083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a23a60d20eeedd90de69b27ffa4a764ac"><a name="ggaea6a2a57db175118e08189b73f8f3da5a23a60d20eeedd90de69b27ffa4a764ac"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a23a60d20eeedd90de69b27ffa4a764ac"></a></strong>SENSOR_TYPE_DEVICE_ORIENTATION</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1935384446083931"><a name="p1935384446083931"></a><a name="p1935384446083931"></a>设备方向传感器。</p>
<p id="p2085612474208"><a name="p2085612474208"></a><a name="p2085612474208"></a></p>
</td>
</tr>
<tr id="row1697639594083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry811262475083931p0"><a name="entry811262475083931p0"></a><a name="entry811262475083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a0ca37fde34accc45f3065c635480a718"><a name="ggaea6a2a57db175118e08189b73f8f3da5a0ca37fde34accc45f3065c635480a718"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a0ca37fde34accc45f3065c635480a718"></a></strong>SENSOR_TYPE_WEAR_DETECTION</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2109014710083931"><a name="p2109014710083931"></a><a name="p2109014710083931"></a>佩戴检测传感器。</p>
<p id="p18856134711203"><a name="p18856134711203"></a><a name="p18856134711203"></a></p>
</td>
</tr>
<tr id="row1302944270083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry664668519083931p0"><a name="entry664668519083931p0"></a><a name="entry664668519083931p0"></a><strong id="ggaea6a2a57db175118e08189b73f8f3da5a730bd9013ab8fea3bbfae66f4c6a6129"><a name="ggaea6a2a57db175118e08189b73f8f3da5a730bd9013ab8fea3bbfae66f4c6a6129"></a><a name="ggaea6a2a57db175118e08189b73f8f3da5a730bd9013ab8fea3bbfae66f4c6a6129"></a></strong>SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1420283723083931"><a name="p1420283723083931"></a><a name="p1420283723083931"></a>未校准加速度传感器。</p>
<p id="p8856154742012"><a name="p8856154742012"></a><a name="p8856154742012"></a></p>
</td>
</tr>
<tr id="row7762410215"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p876144152111"><a name="p876144152111"></a><a name="p876144152111"></a>SENSOR_TYPE_MAX</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p185647297083931"><a name="p185647297083931"></a><a name="p185647297083931"></a>传感器类型最大个数。</p>
<p id="p9856184713207"><a name="p9856184713207"></a><a name="p9856184713207"></a></p>
</td>
</tr>
</tbody>
</table>

## **函数说明**<a name="section1675391510083931"></a>

## FreeSensorInterfaceInstance\(\)<a name="ga7e455c6893ae86b37cc23a75f0f9e299"></a>

```
int32_t FreeSensorInterfaceInstance (void )
```

**描述：**

释放传感器接口实例。

**返回：**

如果释放实例成功，则返回0。

如果释放实例失败，则返回负值。

**Since：**

2.2

**Version：**

1.0

## NewSensorInterfaceInstance\(\)<a name="ga953c149967473431c86ea7f274fe8717"></a>

```
const struct SensorInterface* NewSensorInterfaceInstance (void )
```

**描述：**

创建传感器接口实例。

**参数：**

<a name="table994571232083931"></a>
<table><thead align="left"><tr id="row85330695083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p759051969083931"><a name="p759051969083931"></a><a name="p759051969083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p53589515083931"><a name="p53589515083931"></a><a name="p53589515083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row826427189083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1070415608083931p0"><a name="entry1070415608083931p0"></a><a name="entry1070415608083931p0"></a>sensorId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry541068419083931p0"><a name="entry541068419083931p0"></a><a name="entry541068419083931p0"></a>表示传感器ID。有关详细信息，详见<a href="_sensor.md#gaea6a2a57db175118e08189b73f8f3da5">SensorTypeTag</a>。</p>
</td>
</tr>
<tr id="row549733275083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1468402383083931p0"><a name="entry1468402383083931p0"></a><a name="entry1468402383083931p0"></a>cb</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1455431724083931p0"><a name="entry1455431724083931p0"></a><a name="entry1455431724083931p0"></a>表示要注册的回调函数。有关详细信息，详见<a href="_sensor.md#ga2e0b32ff63dbdaf778e4d7dd4d6bb932">RecordDataCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果创建实例成功，则返回非零值。

如果创建实例失败，则返回负值。

**Since：**

2.2

**Version：**

1.0

