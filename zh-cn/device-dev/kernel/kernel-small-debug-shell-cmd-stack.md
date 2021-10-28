# stack<a name="ZH-CN_TOPIC_0000001179845921"></a>

-   [命令功能](#section445335110416)
-   [命令格式](#section1795712553416)
-   [参数说明](#section92544592410)
-   [使用指南](#section104151141252)
-   [使用实例](#section11545171957)
-   [输出说明](#section075617368542)

## 命令功能<a name="section445335110416"></a>

查看系统各堆栈使用情况。

## 命令格式<a name="section1795712553416"></a>

stack

## 参数说明<a name="section92544592410"></a>

无。

## 使用指南<a name="section104151141252"></a>

无。

## 使用实例<a name="section11545171957"></a>

输入：stack

## 输出说明<a name="section075617368542"></a>

**示例 1**  系统堆栈使用情况

```shell
OHOS # stack

 stack name    cpu id     stack addr     total size   used size
 ----------    ------     ---------      --------     --------
  svc_stack      1        0x405c4000     0x2000       0x484
  svc_stack      0        0x405c6000     0x2000       0xae4
  exc_stack      1        0x405c8000     0x1000       0x0
  exc_stack      0        0x405c9000     0x1000       0x0
```

**表 1**  输出说明

<a name="table633mcpsimp"></a>
<table><thead align="left"><tr id="row638mcpsimp"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p640mcpsimp"><a name="p640mcpsimp"></a><a name="p640mcpsimp"></a>输出</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p642mcpsimp"><a name="p642mcpsimp"></a><a name="p642mcpsimp"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row643mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p645mcpsimp"><a name="p645mcpsimp"></a><a name="p645mcpsimp"></a>stack name</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p647mcpsimp"><a name="p647mcpsimp"></a><a name="p647mcpsimp"></a>系统堆栈名</p>
</td>
</tr>
<tr id="row648mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p650mcpsimp"><a name="p650mcpsimp"></a><a name="p650mcpsimp"></a>cpu id</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p652mcpsimp"><a name="p652mcpsimp"></a><a name="p652mcpsimp"></a>cpu 号</p>
</td>
</tr>
<tr id="row653mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p655mcpsimp"><a name="p655mcpsimp"></a><a name="p655mcpsimp"></a>stack addr</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p657mcpsimp"><a name="p657mcpsimp"></a><a name="p657mcpsimp"></a>栈地址</p>
</td>
</tr>
<tr id="row658mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p660mcpsimp"><a name="p660mcpsimp"></a><a name="p660mcpsimp"></a>total size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p662mcpsimp"><a name="p662mcpsimp"></a><a name="p662mcpsimp"></a>堆栈大小</p>
</td>
</tr>
<tr id="row10101624938"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p610724734"><a name="p610724734"></a><a name="p610724734"></a>used size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1510024539"><a name="p1510024539"></a><a name="p1510024539"></a>堆栈实际使用大小</p>
</td>
</tr>
</tbody>
</table>
