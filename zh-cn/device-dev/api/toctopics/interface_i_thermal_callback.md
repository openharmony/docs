# IThermalCallback<a name="ZH-CN_TOPIC_0000001343200753"></a>

## **概述**<a name="section1852202003083932"></a>

**所属模块:**

[Thermal](thermal.md)

## **汇总**<a name="section1645464940083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1114570889083932"></a>
<table><thead align="left"><tr id="row702581117083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2118285303083932"><a name="p2118285303083932"></a><a name="p2118285303083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1847971972083932"><a name="p1847971972083932"></a><a name="p1847971972083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row413395850083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1948308405083932"><a name="p1948308405083932"></a><a name="p1948308405083932"></a><a href="interface_i_thermal_callback.md#a18f63bf4cb6abd7bb1d59a1ed34b53d8">OnThermalDataEvent</a> ([in] struct <a href="_hdf_thermal_callback_info.md">HdfThermalCallbackInfo</a> event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1854751545083932"><a name="p1854751545083932"></a><a name="p1854751545083932"></a>设备发热状态变化的回调方法。 <a href="interface_i_thermal_callback.md#a18f63bf4cb6abd7bb1d59a1ed34b53d8">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section310379721083932"></a>

订阅设备发热状态的回调。

服务创建此回调对象后，可以调用IThermalInterface的接口注册回调，从而订阅设备发热状态的变化。

**Since：**

3.1

## **成员函数说明**<a name="section111943700083932"></a>

## OnThermalDataEvent\(\)<a name="a18f63bf4cb6abd7bb1d59a1ed34b53d8"></a>

```
IThermalCallback::OnThermalDataEvent ([in] struct HdfThermalCallbackInfo event)
```

**描述：**

设备发热状态变化的回调方法。

当设备发热状态发生变化时，将通过此方法的参数返回给服务。

**参数：**

<a name="table2017496743083932"></a>
<table><thead align="left"><tr id="row858177675083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1586976455083932"><a name="p1586976455083932"></a><a name="p1586976455083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p161917373083932"><a name="p161917373083932"></a><a name="p161917373083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1435293485083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1767602016083932p0"><a name="entry1767602016083932p0"></a><a name="entry1767602016083932p0"></a>event</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1228406744083932p0"><a name="entry1228406744083932p0"></a><a name="entry1228406744083932p0"></a>输入参数，设备发热信息，包括器件类型、器件温度。</p>
</td>
</tr>
</tbody>
</table>

**参见：**

[HdfThermalCallbackInfo](_hdf_thermal_callback_info.md)

