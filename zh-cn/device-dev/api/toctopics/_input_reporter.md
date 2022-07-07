# InputReporter<a name="ZH-CN_TOPIC_0000001343321025"></a>

## **概述**<a name="section1355559515083932"></a>

**所属模块:**

[Input](_input.md)

## **汇总**<a name="section937984929083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1964525104083932"></a>
<table><thead align="left"><tr id="row1733577628083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1164238717083932"><a name="p1164238717083932"></a><a name="p1164238717083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p91677191083932"><a name="p91677191083932"></a><a name="p91677191083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1311456163083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1209409173083932"><a name="p1209409173083932"></a><a name="p1209409173083932"></a>( <a href="_input_reporter.md#a8cbea98a78a293bc8ab6f41c6adeb675">RegisterReportCallback</a> )(uint32_t devIndex, <a href="_input_report_event_cb.md">InputReportEventCb</a> *callback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1039765403083932"><a name="p1039765403083932"></a><a name="p1039765403083932"></a>注册对应设备的回调函数 <a href="_input_reporter.md#a8cbea98a78a293bc8ab6f41c6adeb675">更多...</a></p>
</td>
</tr>
<tr id="row817748391083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1378778303083932"><a name="p1378778303083932"></a><a name="p1378778303083932"></a>( <a href="_input_reporter.md#a8c10af61e0c73c91292b806a7ea1d069">UnregisterReportCallback</a> )(uint32_t devIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1178967110083932"><a name="p1178967110083932"></a><a name="p1178967110083932"></a>注销对应设备的回调函数 <a href="_input_reporter.md#a8c10af61e0c73c91292b806a7ea1d069">更多...</a></p>
</td>
</tr>
<tr id="row262083753083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1085171069083932"><a name="p1085171069083932"></a><a name="p1085171069083932"></a>( <a href="_input_reporter.md#a69802255ac001b7debf25a89b0097ac4">RegisterHotPlugCallback</a> )(<a href="_input_report_event_cb.md">InputReportEventCb</a> *callback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1447838237083932"><a name="p1447838237083932"></a><a name="p1447838237083932"></a>注册Input设备的热插拔回调函数 <a href="_input_reporter.md#a69802255ac001b7debf25a89b0097ac4">更多...</a></p>
</td>
</tr>
<tr id="row130692438083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1231887897083932"><a name="p1231887897083932"></a><a name="p1231887897083932"></a>( <a href="_input_reporter.md#a3057e2e0a13c8ba1cb0b3ea2fd029812">UnregisterHotPlugCallback</a> )(void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1850277139083932"><a name="p1850277139083932"></a><a name="p1850277139083932"></a>注销Input设备的热插拔回调函数 <a href="_input_reporter.md#a3057e2e0a13c8ba1cb0b3ea2fd029812">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section304373657083932"></a>

提供input设备数据上报相关的接口。

此类接口包含input设备的数据上报回调函数的注册和注销。

## **类成员变量说明**<a name="section1823708376083932"></a>

## RegisterHotPlugCallback<a name="a69802255ac001b7debf25a89b0097ac4"></a>

```
int32_t(* InputReporter::RegisterHotPlugCallback) (InputReportEventCb *callback)
```

**描述：**

注册Input设备的热插拔回调函数

input服务通过此接口注册回调函数到hdi中，所有Input设备由此函数进行热插拔事件上报

**参数：**

<a name="table223396773083932"></a>
<table><thead align="left"><tr id="row673456388083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2075474524083932"><a name="p2075474524083932"></a><a name="p2075474524083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p364440816083932"><a name="p364440816083932"></a><a name="p364440816083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1737413356083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry897805697083932p0"><a name="entry897805697083932p0"></a><a name="entry897805697083932p0"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1546443121083932p0"><a name="entry1546443121083932p0"></a><a name="entry1546443121083932p0"></a>回调函数的函数指针</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## RegisterReportCallback<a name="a8cbea98a78a293bc8ab6f41c6adeb675"></a>

```
int32_t(* InputReporter::RegisterReportCallback) (uint32_t devIndex, InputReportEventCb *callback)
```

**描述：**

注册对应设备的回调函数

input服务通过此接口注册数据回调函数到hdi中，hdi通过此回调函数上报input事件

**参数：**

<a name="table995953734083932"></a>
<table><thead align="left"><tr id="row1736805221083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p828475387083932"><a name="p828475387083932"></a><a name="p828475387083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p402374357083932"><a name="p402374357083932"></a><a name="p402374357083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1251314958083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry13803423083932p0"><a name="entry13803423083932p0"></a><a name="entry13803423083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1845379233083932p0"><a name="entry1845379233083932p0"></a><a name="entry1845379233083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备</p>
</td>
</tr>
<tr id="row526325097083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1031995218083932p0"><a name="entry1031995218083932p0"></a><a name="entry1031995218083932p0"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry55406751083932p0"><a name="entry55406751083932p0"></a><a name="entry55406751083932p0"></a>回调函数的函数指针</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## UnregisterHotPlugCallback<a name="a3057e2e0a13c8ba1cb0b3ea2fd029812"></a>

```
int32_t(* InputReporter::UnregisterHotPlugCallback) (void)
```

**描述：**

注销Input设备的热插拔回调函数

**参数：**

<a name="table1556636798083932"></a>
<table><thead align="left"><tr id="row518199855083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1955123666083932"><a name="p1955123666083932"></a><a name="p1955123666083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p464548207083932"><a name="p464548207083932"></a><a name="p464548207083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row233958660083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry366137052083932p0"><a name="entry366137052083932p0"></a><a name="entry366137052083932p0"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry402215268083932p0"><a name="entry402215268083932p0"></a><a name="entry402215268083932p0"></a>-</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

## UnregisterReportCallback<a name="a8c10af61e0c73c91292b806a7ea1d069"></a>

```
int32_t(* InputReporter::UnregisterReportCallback) (uint32_t devIndex)
```

**描述：**

注销对应设备的回调函数

**参数：**

<a name="table193347554083932"></a>
<table><thead align="left"><tr id="row519113870083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1089783373083932"><a name="p1089783373083932"></a><a name="p1089783373083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p383762930083932"><a name="p383762930083932"></a><a name="p383762930083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2031433438083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry288208991083932p0"><a name="entry288208991083932p0"></a><a name="entry288208991083932p0"></a>devIndex</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry132160504083932p0"><a name="entry132160504083932p0"></a><a name="entry132160504083932p0"></a>Input设备索引，用于标志多个input设备，取值从0开始，最多支持32个设备</p>
</td>
</tr>
</tbody>
</table>

**返回：**

Returns INPUT\_SUCCESS 表示执行成功。

Returns 其他值表示执行失败，具体错误码查看**RetSatus**。

