# sensor\_if.h<a name="ZH-CN_TOPIC_0000001343000825"></a>

## **概述**<a name="section1222626078083931"></a>

**所属模块:**

[Sensor](_sensor.md)

## **汇总**<a name="section656130133083931"></a>

## 类<a name="nested-classes"></a>

<a name="table1975864998083931"></a>
<table><thead align="left"><tr id="row132492418083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1929124481083931"><a name="p1929124481083931"></a><a name="p1929124481083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p725861232083931"><a name="p725861232083931"></a><a name="p725861232083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1254333771083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1622798036083931"><a name="p1622798036083931"></a><a name="p1622798036083931"></a><a href="_sensor_interface.md">SensorInterface</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p308455397083931"><a name="p308455397083931"></a><a name="p308455397083931"></a>提供sensor设备基本控制操作接口。 <a href="_sensor_interface.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table1479411604083931"></a>
<table><thead align="left"><tr id="row1482140130083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p678896505083931"><a name="p678896505083931"></a><a name="p678896505083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1395535738083931"><a name="p1395535738083931"></a><a name="p1395535738083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1252312381083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927721137083931"><a name="p927721137083931"></a><a name="p927721137083931"></a><a href="_sensor.md#ga953c149967473431c86ea7f274fe8717">NewSensorInterfaceInstance</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1301686363083931"><a name="p1301686363083931"></a><a name="p1301686363083931"></a>创建传感器接口实例。 <a href="_sensor.md#ga953c149967473431c86ea7f274fe8717">更多...</a></p>
</td>
</tr>
<tr id="row991455523083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p191161329083931"><a name="p191161329083931"></a><a name="p191161329083931"></a><a href="_sensor.md#ga7e455c6893ae86b37cc23a75f0f9e299">FreeSensorInterfaceInstance</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p55676285083931"><a name="p55676285083931"></a><a name="p55676285083931"></a>释放传感器接口实例。 <a href="_sensor.md#ga7e455c6893ae86b37cc23a75f0f9e299">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section594495789083931"></a>

Sensor模块对外通用的接口声明文件，提供获取传感器设备信息、订阅/去订阅传感器数据、 使能/去使能传感器、设置传感器模式、设置传感器精度，量程等可选配置接口定义。

**Since：**

2.2

**Version：**

1.0

