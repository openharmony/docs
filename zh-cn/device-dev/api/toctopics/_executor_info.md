# ExecutorInfo<a name="ZH-CN_TOPIC_0000001343200733"></a>

## **概述**<a name="section218549362083932"></a>

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md)  |  [HdfPinAuth](_hdf_pin_auth.md)  |  [HdfUserAuth](_hdf_user_auth.md)

## **汇总**<a name="section1286334200083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1721010279083932"></a>
<table><thead align="left"><tr id="row1843890041083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1925332735083932"><a name="p1925332735083932"></a><a name="p1925332735083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1992352536083932"><a name="p1992352536083932"></a><a name="p1992352536083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row682054229083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2093617268083932"><a name="p2093617268083932"></a><a name="p2093617268083932"></a><a href="_executor_info.md#a90a92740244896077204309761943939">sensorId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2954142434318"><a name="p2954142434318"></a><a name="p2954142434318"></a>传感器ID，不同传感器在人脸/口令认证驱动内的唯一标识。</p>
</td>
</tr>
<tr id="row1785359692083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1180998005083932"><a name="p1180998005083932"></a><a name="p1180998005083932"></a><a href="_executor_info.md#a6107187920c858b042ad3a7d8d312857">executorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p25911129104015"><a name="p25911129104015"></a><a name="p25911129104015"></a>执行器类型，根据执行器支持的能力/算法类型进行分类。</p>
</td>
</tr>
<tr id="row2026551639083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p160739336083932"><a name="p160739336083932"></a><a name="p160739336083932"></a><a href="_executor_info.md#a1d198c20ddd591ca862a628ec96546b5">index</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1414684296083932p0"><a name="entry1414684296083932p0"></a><a name="entry1414684296083932p0"></a>用户认证框架的执行器索引。</p>
</td>
</tr>
<tr id="row2028642554083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1034067511083932"><a name="p1034067511083932"></a><a name="p1034067511083932"></a><a href="_executor_info.md#ae9fb779c24ff2196267468c8d3a8fba8">executorRole</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry447920746083932p0"><a name="entry447920746083932p0"></a><a name="entry447920746083932p0"></a>执行器角色ExecutorRole。</p>
</td>
</tr>
<tr id="row860408877083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448173081083932"><a name="p448173081083932"></a><a name="p448173081083932"></a><a href="_executor_info.md#ac698911748505ba32273f1256a5802ab">authType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2109698300083932p0"><a name="entry2109698300083932p0"></a><a name="entry2109698300083932p0"></a>用户认证凭据类型。</p>
</td>
</tr>
<tr id="row1401365774083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1110639886083932"><a name="p1110639886083932"></a><a name="p1110639886083932"></a><a href="_executor_info.md#aa3276c19392a32bfd22f454909b8766a">esl</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1274006959083932p0"><a name="entry1274006959083932p0"></a><a name="entry1274006959083932p0"></a>执行器安全等级。</p>
</td>
</tr>
<tr id="row296659625083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1413013088083932"><a name="p1413013088083932"></a><a name="p1413013088083932"></a><a href="_executor_info.md#a3e694be74a2af743f7a338335ac7034a">publicKey</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p144746545411"><a name="p144746545411"></a><a name="p144746545411"></a>执行器公钥，用于校验该执行器私钥签名的信息。</p>
</td>
</tr>
<tr id="row856124540083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p791617026083932"><a name="p791617026083932"></a><a name="p791617026083932"></a><a href="_executor_info.md#a4d931bafb69a23ca6a65a27ad3c14a0b">extraInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p42684364218"><a name="p42684364218"></a><a name="p42684364218"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
<tr id="row1153995369083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p737241274083932"><a name="p737241274083932"></a><a name="p737241274083932"></a><a href="_executor_info.md#a9f023e452c10263ee7015c5933d5874f">info</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p3711013194218"><a name="p3711013194218"></a><a name="p3711013194218"></a>执行器注册信息ExecutorRegisterInfo。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section471723383083932"></a>

执行器信息。

**Since：**

3.2

**Version：**

1.0

## **类成员变量说明**<a name="section1701606567083932"></a>

## authType<a name="ac698911748505ba32273f1256a5802ab"></a>

```
enum AuthType ExecutorInfo::authType
```

**描述：**

用户认证凭据类型。

## esl<a name="aa3276c19392a32bfd22f454909b8766a"></a>

```
enum ExecutorSecureLevel ExecutorInfo::esl
```

**描述：**

执行器安全等级ExecutorSecureLevel。

## executorRole<a name="ae9fb779c24ff2196267468c8d3a8fba8"></a>

```
enum ExecutorRole ExecutorInfo::executorRole
```

**描述：**

执行器角色ExecutorRole。

## executorType<a name="a6107187920c858b042ad3a7d8d312857"></a>

```
unsigned int ExecutorInfo::executorType
```

**描述：**

执行器类型，根据执行器支持的能力/算法类型进行分类。

## extraInfo<a name="a4d931bafb69a23ca6a65a27ad3c14a0b"></a>

```
unsigned char [] ExecutorInfo::extraInfo
```

**描述：**

其他相关信息，用于支持信息扩展。

## index<a name="a1d198c20ddd591ca862a628ec96546b5"></a>

```
unsigned long ExecutorInfo::index
```

**描述：**

用户认证框架的执行器索引。

## info<a name="a9f023e452c10263ee7015c5933d5874f"></a>

```
struct ExecutorRegisterInfo ExecutorInfo::info
```

**描述：**

执行器注册信息ExecutorRegisterInfo。

## publicKey<a name="a3e694be74a2af743f7a338335ac7034a"></a>

```
unsigned char [] ExecutorInfo::publicKey
```

**描述：**

执行器公钥，用于校验该执行器私钥签名的信息。

## sensorId<a name="a90a92740244896077204309761943939"></a>

```
unsigned short ExecutorInfo::sensorId
```

**描述：**

传感器ID，不同传感器在人脸认证驱动内的唯一标识。

传感器ID，不同传感器在口令认证驱动内的唯一标识。

