# IExecutorCallback<a name="ZH-CN_TOPIC_0000001290561180"></a>

## **概述**<a name="section1239779147083932"></a>

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md)  |  [HdfPinAuth](_hdf_pin_auth.md)

## **汇总**<a name="section1901650491083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1351704674083932"></a>
<table><thead align="left"><tr id="row653040889083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1550305784083932"><a name="p1550305784083932"></a><a name="p1550305784083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p869932351083932"><a name="p869932351083932"></a><a name="p869932351083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1499808737083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1788894822083932"><a name="p1788894822083932"></a><a name="p1788894822083932"></a><a href="interface_i_executor_callback.md#ae466eb77b9a25d222c8fdc13e4311593">OnResult</a> ([in] int result, [in] unsigned char[] extraInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p729484724083932"><a name="p729484724083932"></a><a name="p729484724083932"></a>定义操作结果回调函数。 <a href="interface_i_executor_callback.md#ae466eb77b9a25d222c8fdc13e4311593">更多...</a></p>
</td>
</tr>
<tr id="row1714218968083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p364949912083932"><a name="p364949912083932"></a><a name="p364949912083932"></a><a href="interface_i_executor_callback.md#a29f61b101c088f29f8fcac2867054563">OnAcquireInfo</a> ([in] int acquire, [in] unsigned char[] extraInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2087216103083932"><a name="p2087216103083932"></a><a name="p2087216103083932"></a>定义操作过程信息反馈回调函数。 <a href="interface_i_executor_callback.md#a29f61b101c088f29f8fcac2867054563">更多...</a></p>
</td>
</tr>
<tr id="row12606867083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p236509236083932"><a name="p236509236083932"></a><a name="p236509236083932"></a><a href="interface_i_executor_callback.md#a96437fd3ae78019f5d631cb5afc1da3a">OnGetData</a> ([in] unsigned long scheduleId, [in] unsigned char[] salt, [in] unsigned long authSubType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1226596014083932"><a name="p1226596014083932"></a><a name="p1226596014083932"></a>定义请求获取口令数据回调函数。 <a href="interface_i_executor_callback.md#a96437fd3ae78019f5d631cb5afc1da3a">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section434337670083932"></a>

定义异步API接口回调，用于返回异步接口的请求处理结果和获取信息。使用细节见[IExecutor](interface_i_executor.md)。

**Since：**

3.2

**Version:**

1.0

## **成员函数说明**<a name="section549392866083932"></a>

## OnAcquireInfo\(\)<a name="a29f61b101c088f29f8fcac2867054563"></a>

```
IExecutorCallback::OnAcquireInfo ([in] int acquire, [in] unsigned char[] extraInfo )
```

**描述：**

定义操作过程信息反馈回调函数。

**参数：**

<a name="table262539478083932"></a>
<table><thead align="left"><tr id="row157489953083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1425273449083932"><a name="p1425273449083932"></a><a name="p1425273449083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2095812733083932"><a name="p2095812733083932"></a><a name="p2095812733083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2077382340083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1528453563083932p0"><a name="entry1528453563083932p0"></a><a name="entry1528453563083932p0"></a>acquire</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry722240093083932p0"><a name="entry722240093083932p0"></a><a name="entry722240093083932p0"></a>提示信息编码<a href="_hdf_face_auth.md#gafe283e29a705391d97054a4b9d5fe007">FaceTipsCode</a>。</p>
</td>
</tr>
<tr id="row390547017083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry586297150083932p0"><a name="entry586297150083932p0"></a><a name="entry586297150083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1724964947083932p0"><a name="entry1724964947083932p0"></a><a name="entry1724964947083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## OnGetData\(\)<a name="a96437fd3ae78019f5d631cb5afc1da3a"></a>

```
IExecutorCallback::OnGetData ([in] unsigned long scheduleId, [in] unsigned char[] salt, [in] unsigned long authSubType )
```

**描述：**

定义请求获取口令数据回调函数。

**参数：**

<a name="table606570715083932"></a>
<table><thead align="left"><tr id="row1678047613083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1632982196083932"><a name="p1632982196083932"></a><a name="p1632982196083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p826169182083932"><a name="p826169182083932"></a><a name="p826169182083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1602502469083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry474154828083932p0"><a name="entry474154828083932p0"></a><a name="entry474154828083932p0"></a>salt</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry709740559083932p0"><a name="entry709740559083932p0"></a><a name="entry709740559083932p0"></a>盐值，用于对口令明文进行单向处理。</p>
</td>
</tr>
<tr id="row1345364134083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1695652709083932p0"><a name="entry1695652709083932p0"></a><a name="entry1695652709083932p0"></a>authSubType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry411846467083932p0"><a name="entry411846467083932p0"></a><a name="entry411846467083932p0"></a>口令子类型，如六位数字PIN码等。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## OnResult\(\)<a name="ae466eb77b9a25d222c8fdc13e4311593"></a>

```
IExecutorCallback::OnResult ([in] int result, [in] unsigned char[] extraInfo )
```

**描述：**

定义操作请求处理结果回调函数。

**参数：**

<a name="table1989500654083932"></a>
<table><thead align="left"><tr id="row169317831083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2082431651083932"><a name="p2082431651083932"></a><a name="p2082431651083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1032428453083932"><a name="p1032428453083932"></a><a name="p1032428453083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1947584168083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry95432508083932p0"><a name="entry95432508083932p0"></a><a name="entry95432508083932p0"></a>result</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry57686257083932p0"><a name="entry57686257083932p0"></a><a name="entry57686257083932p0"></a>操作请求处理结果。</p>
</td>
</tr>
<tr id="row1564967795083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry992004185083932p0"><a name="entry992004185083932p0"></a><a name="entry992004185083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry887600889083932p0"><a name="entry887600889083932p0"></a><a name="entry887600889083932p0"></a>其他相关信息，如用户认证通过时用于返回执行器签发的认证令牌等。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

