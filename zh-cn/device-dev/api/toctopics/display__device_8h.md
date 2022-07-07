# display\_device.h<a name="ZH-CN_TOPIC_0000001343120289"></a>

## **概述**<a name="section391355611083931"></a>

**所属模块:**

[Display](_display.md)

## **汇总**<a name="section61172156083931"></a>

## 类<a name="nested-classes"></a>

<a name="table247622302083931"></a>
<table><thead align="left"><tr id="row2139182443083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p438035884083931"><a name="p438035884083931"></a><a name="p438035884083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p186778137083931"><a name="p186778137083931"></a><a name="p186778137083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1117671757083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p12422202083931"><a name="p12422202083931"></a><a name="p12422202083931"></a><a href="_device_funcs.md">DeviceFuncs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1634061864083931"><a name="p1634061864083931"></a><a name="p1634061864083931"></a>显示设备控制接口结构体，定义显示设备控制接口函数指针。 <a href="_device_funcs.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 类型定义<a name="typedef-members"></a>

<a name="table188827900083931"></a>
<table><thead align="left"><tr id="row1093367214083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p378322898083931"><a name="p378322898083931"></a><a name="p378322898083931"></a>类型定义</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2124430442083931"><a name="p2124430442083931"></a><a name="p2124430442083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1939854165083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p175527553083931"><a name="p175527553083931"></a><a name="p175527553083931"></a>(<strong id="b911016586146"><a name="b911016586146"></a><a name="b911016586146"></a>HotPlugCallback</strong>) (uint32_t devId, bool connected, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369183518550"><a name="p1369183518550"></a><a name="p1369183518550"></a>注册热插拔事件回调</p>
</td>
</tr>
<tr id="row1225836872083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1348977380083931"><a name="p1348977380083931"></a><a name="p1348977380083931"></a>(<strong id="b109209471512"><a name="b109209471512"></a><a name="b109209471512"></a>VBlankCallback</strong>) (unsigned int sequence, uint64_t ns, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36917351551"><a name="p36917351551"></a><a name="p36917351551"></a>注册VBlank事件回调。</p>
</td>
</tr>
<tr id="row1544319765083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p737860500083931"><a name="p737860500083931"></a><a name="p737860500083931"></a>(<strong id="b45184158"><a name="b45184158"></a><a name="b45184158"></a>RefreshCallback</strong>) (uint32_t devId, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369135175511"><a name="p1369135175511"></a><a name="p1369135175511"></a>刷新请求回调。</p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table496843330083931"></a>
<table><thead align="left"><tr id="row1267727426083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1578095775083931"><a name="p1578095775083931"></a><a name="p1578095775083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1967832652083931"><a name="p1967832652083931"></a><a name="p1967832652083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row767472461083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1367452957083931"><a name="p1367452957083931"></a><a name="p1367452957083931"></a><a href="_display.md#ga3aba41189809d78958bc6f5cdcee6e56">DeviceInitialize</a> (<a href="_device_funcs.md">DeviceFuncs</a> **funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p789716518083931"><a name="p789716518083931"></a><a name="p789716518083931"></a>实现显示设备控制接口的初始化，申请操作显示设备控制接口的资源，并获取对应的操作接口。 <a href="_display.md#ga3aba41189809d78958bc6f5cdcee6e56">更多...</a></p>
</td>
</tr>
<tr id="row2130699317083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p236758027083931"><a name="p236758027083931"></a><a name="p236758027083931"></a><a href="_display.md#ga5de6eba216f3a97cc5f4d7e5dd174a9f">DeviceUninitialize</a> (<a href="_device_funcs.md">DeviceFuncs</a> *funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1640667005083931"><a name="p1640667005083931"></a><a name="p1640667005083931"></a>取消显示设备控制接口的初始化，释放控制接口使用到的资源。 <a href="_display.md#ga5de6eba216f3a97cc5f4d7e5dd174a9f">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1475895733083931"></a>

显示设备控制接口声明。

**Since：**

1.0

**Version：**

2.0

