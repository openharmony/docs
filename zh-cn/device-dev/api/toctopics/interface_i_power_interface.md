# IPowerInterface<a name="ZH-CN_TOPIC_0000001290721088"></a>

## **概述**<a name="section2135665948083932"></a>

**所属模块:**

[Power](power.md)

## **汇总**<a name="section835578652083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1057775135083932"></a>
<table><thead align="left"><tr id="row834118573083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1653944856083932"><a name="p1653944856083932"></a><a name="p1653944856083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1019114186083932"><a name="p1019114186083932"></a><a name="p1019114186083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1216580238083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1962034711083932"><a name="p1962034711083932"></a><a name="p1962034711083932"></a><a href="interface_i_power_interface.md#a3c2ae453ab3e4d198a91884dbc1cf417">RegisterCallback</a> ([in] <a href="interface_i_power_hdi_callback.md">IPowerHdiCallback</a> ipowerHdiCallback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p281094170083932"><a name="p281094170083932"></a><a name="p281094170083932"></a>注册休眠/唤醒状态的回调。 <a href="interface_i_power_interface.md#a3c2ae453ab3e4d198a91884dbc1cf417">更多...</a></p>
</td>
</tr>
<tr id="row246004605083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1666803799083932"><a name="p1666803799083932"></a><a name="p1666803799083932"></a><a href="interface_i_power_interface.md#a14e960e7b5e15b2a4cda6ce0a355609f">StartSuspend</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p145917812083932"><a name="p145917812083932"></a><a name="p145917812083932"></a>执行设备休眠操作。 <a href="interface_i_power_interface.md#a14e960e7b5e15b2a4cda6ce0a355609f">更多...</a></p>
</td>
</tr>
<tr id="row5395574083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p906525807083932"><a name="p906525807083932"></a><a name="p906525807083932"></a><a href="interface_i_power_interface.md#af15f8d73eccdbd4fbeb7b126789cdf8f">StopSuspend</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p570063684083932"><a name="p570063684083932"></a><a name="p570063684083932"></a>执行设备唤醒操作。 <a href="interface_i_power_interface.md#af15f8d73eccdbd4fbeb7b126789cdf8f">更多...</a></p>
</td>
</tr>
<tr id="row1164373037083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p868707429083932"><a name="p868707429083932"></a><a name="p868707429083932"></a><a href="interface_i_power_interface.md#a6a9c73e6d9ea39814a3e3a0cef291021">ForceSuspend</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p856918535083932"><a name="p856918535083932"></a><a name="p856918535083932"></a>执行设备强制休眠操作。 <a href="interface_i_power_interface.md#a6a9c73e6d9ea39814a3e3a0cef291021">更多...</a></p>
</td>
</tr>
<tr id="row2121625806083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1741505390083932"><a name="p1741505390083932"></a><a name="p1741505390083932"></a><a href="interface_i_power_interface.md#a592a4cc39a496b3541c4182ca80925d7">SuspendBlock</a> ([in] String name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1510228368083932"><a name="p1510228368083932"></a><a name="p1510228368083932"></a>打开运行锁，阻止休眠。 <a href="interface_i_power_interface.md#a592a4cc39a496b3541c4182ca80925d7">更多...</a></p>
</td>
</tr>
<tr id="row742723282083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1800229018083932"><a name="p1800229018083932"></a><a name="p1800229018083932"></a><a href="interface_i_power_interface.md#acbc8f3934a195ed9551153bef9ccf07a">SuspendUnblock</a> ([in] String name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2039609119083932"><a name="p2039609119083932"></a><a name="p2039609119083932"></a>关闭运行锁，取消阻止休眠。 <a href="interface_i_power_interface.md#acbc8f3934a195ed9551153bef9ccf07a">更多...</a></p>
</td>
</tr>
<tr id="row934007568083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821269735083932"><a name="p1821269735083932"></a><a name="p1821269735083932"></a><a href="interface_i_power_interface.md#a5dc6cd5faf3a9cf1bd5dd9eb47816a95">PowerDump</a> ([out] String info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1640714748083932"><a name="p1640714748083932"></a><a name="p1640714748083932"></a>获取电源的Dump信息。 <a href="interface_i_power_interface.md#a5dc6cd5faf3a9cf1bd5dd9eb47816a95">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section231243962083932"></a>

休眠/唤醒操作、订阅休眠/唤醒状态、运行锁管理的接口。

服务获取此对象后，可以调用相关的接口对设备进行休眠/唤醒、订阅休眠/唤醒状态和管理运行锁。

**Since：**

3.1

## **成员函数说明**<a name="section243584172083932"></a>

## ForceSuspend\(\)<a name="a6a9c73e6d9ea39814a3e3a0cef291021"></a>

```
IPowerInterface::ForceSuspend ()
```

**描述：**

执行设备强制休眠操作。

**返回：**

HDF\_SUCCESS 表示操作成功。

## PowerDump\(\)<a name="a5dc6cd5faf3a9cf1bd5dd9eb47816a95"></a>

```
IPowerInterface::PowerDump ([out] String info)
```

**描述：**

获取电源的Dump信息。

**参数：**

<a name="table883095788083932"></a>
<table><thead align="left"><tr id="row503813434083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p823596830083932"><a name="p823596830083932"></a><a name="p823596830083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p134745647083932"><a name="p134745647083932"></a><a name="p134745647083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1144154979083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry201551036083932p0"><a name="entry201551036083932p0"></a><a name="entry201551036083932p0"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1414811783083932p0"><a name="entry1414811783083932p0"></a><a name="entry1414811783083932p0"></a>输出参数，电源的Dump信息。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示操作成功。

## RegisterCallback\(\)<a name="a3c2ae453ab3e4d198a91884dbc1cf417"></a>

```
IPowerInterface::RegisterCallback ([in] IPowerHdiCallback ipowerHdiCallback)
```

**描述：**

注册休眠/唤醒状态的回调。

**参数：**

<a name="table452985761083932"></a>
<table><thead align="left"><tr id="row534810520083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1361674658083932"><a name="p1361674658083932"></a><a name="p1361674658083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p716847787083932"><a name="p716847787083932"></a><a name="p716847787083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row308160512083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1766467458083932p0"><a name="entry1766467458083932p0"></a><a name="entry1766467458083932p0"></a>ipowerHdiCallback</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1894621645083932p0"><a name="entry1894621645083932p0"></a><a name="entry1894621645083932p0"></a>输入参数，服务注册的回调。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示注册成功。

**参见：**

[IPowerHdiCallback](interface_i_power_hdi_callback.md)

## StartSuspend\(\)<a name="a14e960e7b5e15b2a4cda6ce0a355609f"></a>

```
IPowerInterface::StartSuspend ()
```

**描述：**

执行设备休眠操作。

**返回：**

HDF\_SUCCESS 表示操作成功。

## StopSuspend\(\)<a name="af15f8d73eccdbd4fbeb7b126789cdf8f"></a>

```
IPowerInterface::StopSuspend ()
```

**描述：**

执行设备唤醒操作。

**返回：**

HDF\_SUCCESS 表示操作成功。

## SuspendBlock\(\)<a name="a592a4cc39a496b3541c4182ca80925d7"></a>

```
IPowerInterface::SuspendBlock ([in] String name)
```

**描述：**

打开运行锁，阻止休眠。

**参数：**

<a name="table1221968053083932"></a>
<table><thead align="left"><tr id="row129156938083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p195127481083932"><a name="p195127481083932"></a><a name="p195127481083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p189864695083932"><a name="p189864695083932"></a><a name="p189864695083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1384210785083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1367629668083932p0"><a name="entry1367629668083932p0"></a><a name="entry1367629668083932p0"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1594948154083932p0"><a name="entry1594948154083932p0"></a><a name="entry1594948154083932p0"></a>输入参数，运行锁的名称。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示操作成功。

## SuspendUnblock\(\)<a name="acbc8f3934a195ed9551153bef9ccf07a"></a>

```
IPowerInterface::SuspendUnblock ([in] String name)
```

**描述：**

关闭运行锁，取消阻止休眠。

**参数：**

<a name="table1395564205083932"></a>
<table><thead align="left"><tr id="row1046613034083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1592217904083932"><a name="p1592217904083932"></a><a name="p1592217904083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p79322862083932"><a name="p79322862083932"></a><a name="p79322862083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row605803721083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1912644490083932p0"><a name="entry1912644490083932p0"></a><a name="entry1912644490083932p0"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry946828994083932p0"><a name="entry946828994083932p0"></a><a name="entry946828994083932p0"></a>输入参数，运行锁的名称。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

HDF\_SUCCESS 表示操作成功。

