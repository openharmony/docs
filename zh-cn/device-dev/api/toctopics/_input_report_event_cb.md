# InputReportEventCb<a name="ZH-CN_TOPIC_0000001291040588"></a>

## **概述**<a name="section2123438795083932"></a>

**所属模块:**

[Input](_input.md)

## **汇总**<a name="section632706432083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1718656798083932"></a>
<table><thead align="left"><tr id="row701525110083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1584615083083932"><a name="p1584615083083932"></a><a name="p1584615083083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1555641664083932"><a name="p1555641664083932"></a><a name="p1555641664083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2040333846083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p768787655083932"><a name="p768787655083932"></a><a name="p768787655083932"></a>( <a href="_input_report_event_cb.md#a405001c916a55bff9923ec1cd4ce736e">ReportEventPkgCallback</a> )(const <a href="_event_package.md">EventPackage</a> **pkgs, uint32_t count, uint32_t devIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1159400791083932"><a name="p1159400791083932"></a><a name="p1159400791083932"></a>输入事件数据上报的回调函数 <a href="_input_report_event_cb.md#a405001c916a55bff9923ec1cd4ce736e">更多...</a></p>
</td>
</tr>
<tr id="row1891080473083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1900798264083932"><a name="p1900798264083932"></a><a name="p1900798264083932"></a>( <a href="_input_report_event_cb.md#a654146e1be13af75a868af9911d7bb8c">ReportHotPlugEventCallback</a> )(const HotPlugEvent *event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p27036012083932"><a name="p27036012083932"></a><a name="p27036012083932"></a>热插拔事件上报的回调函数 <a href="_input_report_event_cb.md#a654146e1be13af75a868af9911d7bb8c">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section668807560083932"></a>

此结构体定义了输入事件回调函数并提供给input服务使用。

## **类成员变量说明**<a name="section135507455083932"></a>

## ReportEventPkgCallback<a name="a405001c916a55bff9923ec1cd4ce736e"></a>

```
void(* InputReportEventCb::ReportEventPkgCallback) (const EventPackage **pkgs, uint32_t count, uint32_t devIndex)
```

**描述：**

输入事件数据上报的回调函数

**参数：**

<a name="table371789981083932"></a>
<table><thead align="left"><tr id="row1000187886083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1214060945083932"><a name="p1214060945083932"></a><a name="p1214060945083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1014436371083932"><a name="p1014436371083932"></a><a name="p1014436371083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1776532266083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1837157263083932p0"><a name="entry1837157263083932p0"></a><a name="entry1837157263083932p0"></a>eventData</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1917709343083932p0"><a name="entry1917709343083932p0"></a><a name="entry1917709343083932p0"></a>驱动上报的input事件数据。</p>
</td>
</tr>
<tr id="row1832143995083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry445588651083932p0"><a name="entry445588651083932p0"></a><a name="entry445588651083932p0"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry415173146083932p0"><a name="entry415173146083932p0"></a><a name="entry415173146083932p0"></a>Input事件数据包的个数。</p>
</td>
</tr>
<tr id="row879625937083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1272565291083932p0"><a name="entry1272565291083932p0"></a><a name="entry1272565291083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1112493522083932p0"><a name="entry1112493522083932p0"></a><a name="entry1112493522083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备。</p>
</td>
</tr>
</tbody>
</table>

## ReportHotPlugEventCallback<a name="a654146e1be13af75a868af9911d7bb8c"></a>

```
void(* InputReportEventCb::ReportHotPlugEventCallback) (const HotPlugEvent *event)
```

**描述：**

热插拔事件上报的回调函数

**参数：**

<a name="table829874232083932"></a>
<table><thead align="left"><tr id="row1877761300083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1291554935083932"><a name="p1291554935083932"></a><a name="p1291554935083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1883389654083932"><a name="p1883389654083932"></a><a name="p1883389654083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row577505250083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1127819767083932p0"><a name="entry1127819767083932p0"></a><a name="entry1127819767083932p0"></a>event</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1231238202083932p0"><a name="entry1231238202083932p0"></a><a name="entry1231238202083932p0"></a>上报的热插拔事件数据</p>
</td>
</tr>
</tbody>
</table>

