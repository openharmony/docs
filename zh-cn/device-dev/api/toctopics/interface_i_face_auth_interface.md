# IFaceAuthInterface<a name="ZH-CN_TOPIC_0000001291040584"></a>

## **概述**<a name="section911720243083932"></a>

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md)

## **汇总**<a name="section565958056083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table2028630030083932"></a>
<table><thead align="left"><tr id="row56289075083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1185397417083932"><a name="p1185397417083932"></a><a name="p1185397417083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1164567722083932"><a name="p1164567722083932"></a><a name="p1164567722083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1379586475083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707288109083932"><a name="p1707288109083932"></a><a name="p1707288109083932"></a><a href="interface_i_face_auth_interface.md#a47e9a276baeecc558a93a46330a5230e">GetExecutorList</a> ([out] <a href="interface_i_executor.md">IExecutor</a>[] executorList)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p488140584083932"><a name="p488140584083932"></a><a name="p488140584083932"></a>获取执行器列表，人脸认证服务进程启动进行初始化操作时通过该接口获取人脸认证驱动支持的执行器列表。 <a href="interface_i_face_auth_interface.md#a47e9a276baeecc558a93a46330a5230e">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section678895831083932"></a>

定义获取人脸认证驱动的执行器列表接口。

**Since：**

3.2

**Version:**

1.0

## **成员函数说明**<a name="section1393392109083932"></a>

## GetExecutorList\(\)<a name="a47e9a276baeecc558a93a46330a5230e"></a>

```
IFaceAuthInterface::GetExecutorList ([out] IExecutor[] executorList)
```

**描述：**

获取执行器列表，人脸认证服务进程启动进行初始化操作时通过该接口获取人脸认证驱动支持的执行器列表。

**参数：**

<a name="table375009970083932"></a>
<table><thead align="left"><tr id="row41911963083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1814791380083932"><a name="p1814791380083932"></a><a name="p1814791380083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1584173786083932"><a name="p1584173786083932"></a><a name="p1584173786083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row952593900083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry34062956083932p0"><a name="entry34062956083932p0"></a><a name="entry34062956083932p0"></a>executorList</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1687721953083932p0"><a name="entry1687721953083932p0"></a><a name="entry1687721953083932p0"></a>执行器对象列表<a href="interface_i_executor.md">IExecutor</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

