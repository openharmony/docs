# ScheduleInfo<a name="ZH-CN_TOPIC_0000001290561212"></a>

## **概述**<a name="section1639201977083932"></a>

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)

## **汇总**<a name="section1024883231083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1668976915083932"></a>
<table><thead align="left"><tr id="row99875254083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p337068329083932"><a name="p337068329083932"></a><a name="p337068329083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p675735709083932"><a name="p675735709083932"></a><a name="p675735709083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1066992384083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p295105433083932"><a name="p295105433083932"></a><a name="p295105433083932"></a><a href="_schedule_info.md#ae61cb543911b60d392ffe62a55ea5269">scheduleId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p939019363314"><a name="p939019363314"></a><a name="p939019363314"></a>调度ID，用于标识一次操作请求的执行器调度过程。</p>
</td>
</tr>
<tr id="row379808183083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1438749819083932"><a name="p1438749819083932"></a><a name="p1438749819083932"></a><a href="_schedule_info.md#a0443852034b2068ee4818b681beec3e9">templateIds</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p84621173333"><a name="p84621173333"></a><a name="p84621173333"></a>模版ID列表。</p>
</td>
</tr>
<tr id="row1130997886083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1467663596083932"><a name="p1467663596083932"></a><a name="p1467663596083932"></a><a href="_schedule_info.md#a38b64950c7a30898d990f702a0cf8b5c">authType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1417766036083932p0"><a name="entry1417766036083932p0"></a><a name="entry1417766036083932p0"></a>用户认证凭据类型。</p>
</td>
</tr>
<tr id="row1432192844083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2015112967083932"><a name="p2015112967083932"></a><a name="p2015112967083932"></a><a href="_schedule_info.md#a09bd6d21d90ba9319cf0cf19bd2201de">executorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2134897341083932p0"><a name="entry2134897341083932p0"></a><a name="entry2134897341083932p0"></a>执行器类型。</p>
</td>
</tr>
<tr id="row1715641930083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p737401870083932"><a name="p737401870083932"></a><a name="p737401870083932"></a><a href="_schedule_info.md#a51d1852471f43b1b68de0b75a9b85ccf">scheduleMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1987509403083932p0"><a name="entry1987509403083932p0"></a><a name="entry1987509403083932p0"></a>调度模式，支持注册、认证和识别模式。</p>
</td>
</tr>
<tr id="row1129336311083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p581717781083932"><a name="p581717781083932"></a><a name="p581717781083932"></a><a href="_schedule_info.md#a7807372de2d1a9e02a7c8daac6dab609">executors</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry958484226083932p0"><a name="entry958484226083932p0"></a><a name="entry958484226083932p0"></a>执行器信息列表。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section798763833083932"></a>

调度信息。

**Since：**

3.2

**Version：**

1.0

## **类成员变量说明**<a name="section687455000083932"></a>

## authType<a name="a38b64950c7a30898d990f702a0cf8b5c"></a>

```
enum AuthType ScheduleInfo::authType
```

**描述：**

用户认证凭据类型。

## executors<a name="a7807372de2d1a9e02a7c8daac6dab609"></a>

```
struct ExecutorInfo [] ScheduleInfo::executors
```

**描述：**

执行器信息列表。

## executorType<a name="a09bd6d21d90ba9319cf0cf19bd2201de"></a>

```
unsigned int ScheduleInfo::executorType
```

**描述：**

执行器类型。

## scheduleId<a name="ae61cb543911b60d392ffe62a55ea5269"></a>

```
unsigned long ScheduleInfo::scheduleId
```

**描述：**

调度ID，用于标识一次操作请求的执行器调度过程。

## scheduleMode<a name="a51d1852471f43b1b68de0b75a9b85ccf"></a>

```
unsigned int ScheduleInfo::scheduleMode
```

**描述：**

调度模式，支持注册、认证和识别模式。

## templateIds<a name="a0443852034b2068ee4818b681beec3e9"></a>

```
unsigned long [] ScheduleInfo::templateIds
```

**描述：**

模版id列表。

