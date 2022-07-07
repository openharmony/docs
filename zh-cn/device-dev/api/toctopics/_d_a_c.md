# DAC<a name="ZH-CN_TOPIC_0000001290561116"></a>

## **汇总**<a name="section236578849083931"></a>

## 文件<a name="files"></a>

<a name="table2042706022083931"></a>
<table><thead align="left"><tr id="row594931075083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1048334923083931"><a name="p1048334923083931"></a><a name="p1048334923083931"></a>文件</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2023842690083931"><a name="p2023842690083931"></a><a name="p2023842690083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row127346582083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1278477049083931"><a name="p1278477049083931"></a><a name="p1278477049083931"></a><a href="dac__if_8h.md">dac_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p913863093083931"><a name="p913863093083931"></a><a name="p913863093083931"></a>声明标准DAC接口函数。</p>
</td>
</tr>
</tbody>
</table>

## 类<a name="nested-classes"></a>

<a name="table1437882488083931"></a>
<table><thead align="left"><tr id="row1189042871083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p542488678083931"><a name="p542488678083931"></a><a name="p542488678083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p338606298083931"><a name="p338606298083931"></a><a name="p338606298083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row316759261083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1196223683083931"><a name="p1196223683083931"></a><a name="p1196223683083931"></a><a href="_dac_io_msg.md">DacIoMsg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1499454272083931"><a name="p1499454272083931"></a><a name="p1499454272083931"></a>DAC设备信息传输结构体 <a href="_dac_io_msg.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table894431076083931"></a>
<table><thead align="left"><tr id="row1323269168083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1282097405083931"><a name="p1282097405083931"></a><a name="p1282097405083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1800885083083931"><a name="p1800885083083931"></a><a name="p1800885083083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row383664813083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1445812864083931"><a name="p1445812864083931"></a><a name="p1445812864083931"></a><a href="_d_a_c.md#gacf3c353a85e1fe5f1244b5a2899d358d">DacOpen</a> (uint32_t number)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p281659721083931"><a name="p281659721083931"></a><a name="p281659721083931"></a>获取DAC控制器的句柄。 <a href="_d_a_c.md#gacf3c353a85e1fe5f1244b5a2899d358d">更多...</a></p>
</td>
</tr>
<tr id="row1298504899083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p17154174083931"><a name="p17154174083931"></a><a name="p17154174083931"></a><a href="_d_a_c.md#ga18777f73a55de3684bc3c711bbe676aa">DacClose</a> (DevHandle handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1986762187083931"><a name="p1986762187083931"></a><a name="p1986762187083931"></a>释放DAC控制器的句柄。 <a href="_d_a_c.md#ga18777f73a55de3684bc3c711bbe676aa">更多...</a></p>
</td>
</tr>
<tr id="row1382839832083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1065158650083931"><a name="p1065158650083931"></a><a name="p1065158650083931"></a><a href="_d_a_c.md#ga57a778e69c19f30563ab18d4eb388267">DacWrite</a> (DevHandle handle, uint32_t channel, uint32_t val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p75812818083931"><a name="p75812818083931"></a><a name="p75812818083931"></a>启动DAC设备进行传输，将目标值写入指定的DAC通道。 <a href="_d_a_c.md#ga57a778e69c19f30563ab18d4eb388267">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 变量<a name="var-members"></a>

<a name="table857078817083931"></a>
<table><thead align="left"><tr id="row1797986371083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p298921708083931"><a name="p298921708083931"></a><a name="p298921708083931"></a>变量 名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2046719788083931"><a name="p2046719788083931"></a><a name="p2046719788083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row98747439083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1787779300083931"><a name="p1787779300083931"></a><a name="p1787779300083931"></a><a href="_d_a_c.md#ga2b09b4422dd82b4bc5765a2d7400efa9">DacIoMsg::number</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry402440303083931p0"><a name="entry402440303083931p0"></a><a name="entry402440303083931p0"></a>DAC设备号</p>
</td>
</tr>
<tr id="row119861772083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p393186270083931"><a name="p393186270083931"></a><a name="p393186270083931"></a><a href="_d_a_c.md#ga6876a97aed6959653f89896e6a5863b4">DacIoMsg::channel</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry770801866083931p0"><a name="entry770801866083931p0"></a><a name="entry770801866083931p0"></a>DAC设备通道号</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section2130124688083931"></a>

提供数模转换器 \(DAC\) 接口。

该模块允许驱动程序在DAC控制器上执行操作以访问DAC通道上的设备，包括创建和销毁DAC控制器句柄和写入数据。

**Since：**

3.1

## **函数说明**<a name="section791269659083931"></a>

## DacClose\(\)<a name="ga18777f73a55de3684bc3c711bbe676aa"></a>

```
void DacClose (DevHandle handle)
```

**描述：**

释放DAC控制器的句柄。

如果不再需要访问DAC控制器，则应调用该函数关闭其句柄，以释放未使用的内存资源。

**参数：**

<a name="table783706401083931"></a>
<table><thead align="left"><tr id="row1598542661083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1175631947083931"><a name="p1175631947083931"></a><a name="p1175631947083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1121743740083931"><a name="p1121743740083931"></a><a name="p1121743740083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row293761716083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry820294763083931p0"><a name="entry820294763083931p0"></a><a name="entry820294763083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1642756896083931p0"><a name="entry1642756896083931p0"></a><a name="entry1642756896083931p0"></a>表示指向DAC控制器的设备句柄的指针。</p>
</td>
</tr>
</tbody>
</table>

**Since：**

3.1

## DacOpen\(\)<a name="gacf3c353a85e1fe5f1244b5a2899d358d"></a>

```
DevHandle DacOpen (uint32_t number)
```

**描述：**

获取DAC控制器的句柄。

您必须在访问DAC设备之前调用此函数。

**参数：**

<a name="table288055425083931"></a>
<table><thead align="left"><tr id="row1436092014083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1123247356083931"><a name="p1123247356083931"></a><a name="p1123247356083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2123041653083931"><a name="p2123041653083931"></a><a name="p2123041653083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row70527935083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry574773487083931p0"><a name="entry574773487083931p0"></a><a name="entry574773487083931p0"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry853146126083931p0"><a name="entry853146126083931p0"></a><a name="entry853146126083931p0"></a>表示DAC控制器ID。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DAC控制器的DevHandle指针 表示操作成功。

NULL 表示操作失败。

**Since：**

3.1

## DacWrite\(\)<a name="ga57a778e69c19f30563ab18d4eb388267"></a>

```
int32_t DacWrite (DevHandle handle, uint32_t channel, uint32_t val )
```

**描述：**

启动DAC设备进行传输，将目标值写入指定的DAC通道。

**参数：**

<a name="table119746331083931"></a>
<table><thead align="left"><tr id="row1085540121083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p892492855083931"><a name="p892492855083931"></a><a name="p892492855083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p180002059083931"><a name="p180002059083931"></a><a name="p180002059083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row797320083083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1904910765083931p0"><a name="entry1904910765083931p0"></a><a name="entry1904910765083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1936060671083931p0"><a name="entry1936060671083931p0"></a><a name="entry1936060671083931p0"></a>表示通过DacOpen获取的DAC控制器设备句柄的指针。</p>
</td>
</tr>
<tr id="row1229098099083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1742364133083931p0"><a name="entry1742364133083931p0"></a><a name="entry1742364133083931p0"></a>channel</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1478174521083931p0"><a name="entry1478174521083931p0"></a><a name="entry1478174521083931p0"></a>表示DAC传输消息所通过的通道。</p>
</td>
</tr>
<tr id="row820468065083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry776083303083931p0"><a name="entry776083303083931p0"></a><a name="entry776083303083931p0"></a>val</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry317789737083931p0"><a name="entry317789737083931p0"></a><a name="entry317789737083931p0"></a>表示设定的目标值。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

负值 表示操作失败。

**Since：**

3.1

## **变量说明**<a name="section257192192083931"></a>

## channel<a name="ga6876a97aed6959653f89896e6a5863b4"></a>

```
uint32_t DacIoMsg::channel
```

**描述：**

DAC设备通道号

## number<a name="ga2b09b4422dd82b4bc5765a2d7400efa9"></a>

```
uint32_t DacIoMsg::number
```

**描述：**

DAC设备号

