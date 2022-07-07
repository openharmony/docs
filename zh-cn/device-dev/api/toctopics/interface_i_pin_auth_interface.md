# IPinAuthInterface<a name="ZH-CN_TOPIC_0000001343200749"></a>

## **概述**<a name="section1808358240083932"></a>

**所属模块:**

[HdfPinAuth](_hdf_pin_auth.md)

## **汇总**<a name="section1735486492083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table634478303083932"></a>
<table><thead align="left"><tr id="row1001633218083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p372905460083932"><a name="p372905460083932"></a><a name="p372905460083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p248580556083932"><a name="p248580556083932"></a><a name="p248580556083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row858935328083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1823663745083932"><a name="p1823663745083932"></a><a name="p1823663745083932"></a><a href="interface_i_pin_auth_interface.md#a247893f9249790a08050f7eb10be8991">GetExecutorList</a> ([out] <a href="interface_i_executor.md">IExecutor</a>[] executorList)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p666515747083932"><a name="p666515747083932"></a><a name="p666515747083932"></a>获取执行器列表，口令认证服务进程启动进行初始化操作时通过该接口获取口令认证驱动支持的执行器列表。 <a href="interface_i_pin_auth_interface.md#a247893f9249790a08050f7eb10be8991">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1768986310083932"></a>

定义获取口令认证驱动的执行器列表接口。

**Since：**

3.2

**Version:**

1.0

## **成员函数说明**<a name="section2145614057083932"></a>

## GetExecutorList\(\)<a name="a247893f9249790a08050f7eb10be8991"></a>

```
IPinAuthInterface::GetExecutorList ([out] IExecutor[] executorList)
```

**描述：**

获取执行器列表，口令认证服务进程启动进行初始化操作时通过该接口获取口令认证驱动支持的执行器列表。

**参数：**

<a name="table1345486569083932"></a>
<table><thead align="left"><tr id="row1836095390083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2032721144083932"><a name="p2032721144083932"></a><a name="p2032721144083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p631497725083932"><a name="p631497725083932"></a><a name="p631497725083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1584604330083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1685424274083932p0"><a name="entry1685424274083932p0"></a><a name="entry1685424274083932p0"></a>executorList</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1128169314083932p0"><a name="entry1128169314083932p0"></a><a name="entry1128169314083932p0"></a>执行器对象列表<a href="interface_i_executor.md">IExecutor</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

