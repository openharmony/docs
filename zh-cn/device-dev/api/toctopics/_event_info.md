# EventInfo<a name="ZH-CN_TOPIC_0000001343321009"></a>

## **概述**<a name="section1816737286083932"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section1670525847083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table754776890083932"></a>
<table><thead align="left"><tr id="row647549443083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1647884917083932"><a name="p1647884917083932"></a><a name="p1647884917083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1053421803083932"><a name="p1053421803083932"></a><a name="p1053421803083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1067178687083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2145542952083932"><a name="p2145542952083932"></a><a name="p2145542952083932"></a><a href="_event_info.md#ab79480318bdffc175a5cfa705998173f">appData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1512549934083932p0"><a name="entry1512549934083932p0"></a><a name="entry1512549934083932p0"></a>设置回调时给入的上层实例。</p>
</td>
</tr>
<tr id="row917536097083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p741696794083932"><a name="p741696794083932"></a><a name="p741696794083932"></a><a href="_event_info.md#a4f702f83e145d14de75727772ec83337">appDataLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p13656330352"><a name="p13656330352"></a><a name="p13656330352"></a>appData字节数。</p>
</td>
</tr>
<tr id="row306906531083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1448762069083932"><a name="p1448762069083932"></a><a name="p1448762069083932"></a><a href="_event_info.md#ad1f4a8de8d4715cef24ebfb6d86faac0">data1</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2082114026083932p0"><a name="entry2082114026083932p0"></a><a name="entry2082114026083932p0"></a>事件上报携带的数据1。</p>
</td>
</tr>
<tr id="row2022893646083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1367620222083932"><a name="p1367620222083932"></a><a name="p1367620222083932"></a><a href="_event_info.md#a574d276b22b84e7ddd5e743d5b634d9f">data2</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1056884383512"><a name="p1056884383512"></a><a name="p1056884383512"></a>事件上报携带的数据2。</p>
</td>
</tr>
<tr id="row1172507711083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1349915996083932"><a name="p1349915996083932"></a><a name="p1349915996083932"></a><a href="_event_info.md#a932a69747b17cdf3bf405857b1ceb07c">eventData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry54657598083932p0"><a name="entry54657598083932p0"></a><a name="entry54657598083932p0"></a>事件上报携带的数据信息。</p>
</td>
</tr>
<tr id="row1669213183083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1173368821083932"><a name="p1173368821083932"></a><a name="p1173368821083932"></a><a href="_event_info.md#aad73d6841bcfb5b56ab1d8c5cca6fa48">eventDataLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2145273817083932p0"><a name="entry2145273817083932p0"></a><a name="entry2145273817083932p0"></a>eventData字节数。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section705146803083932"></a>

定义事件上报信息。

## **类成员变量说明**<a name="section770733169083932"></a>

## appData<a name="ab79480318bdffc175a5cfa705998173f"></a>

```
int8_t* EventInfo::appData
```

**描述：**

设置回调时给入的上层实例

## appDataLen<a name="a4f702f83e145d14de75727772ec83337"></a>

```
uint32_t EventInfo::appDataLen
```

**描述：**

appData字节数

## data1<a name="ad1f4a8de8d4715cef24ebfb6d86faac0"></a>

```
uint32_t EventInfo::data1
```

**描述：**

事件上报携带的数据1

## data2<a name="a574d276b22b84e7ddd5e743d5b634d9f"></a>

```
uint32_t EventInfo::data2
```

**描述：**

事件上报携带的数据2

## eventData<a name="a932a69747b17cdf3bf405857b1ceb07c"></a>

```
int8_t* EventInfo::eventData
```

**描述：**

事件上报携带的数据信息

## eventDataLen<a name="aad73d6841bcfb5b56ab1d8c5cca6fa48"></a>

```
uint32_t EventInfo::eventDataLen
```

**描述：**

eventData字节数

