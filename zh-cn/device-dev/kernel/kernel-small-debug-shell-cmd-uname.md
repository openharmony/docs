# uname<a name="ZH-CN_TOPIC_0000001179965843"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [使用指南](#section03)
-   [使用实例](#section04)
-   [输出说明](#section05)

## 命令功能<a name="section01"></a>

uname命令用于显示当前操作系统的名称，版本创建时间，系统名称，版本信息等。

## 命令格式<a name="section02"></a>

uname \[_-a | -s | -r | -m | -n | -v | --help_\]

**表 1**  参数说明

<a name="table909mcpsimp"></a>
<table><thead align="left"><tr id="row914mcpsimp"><th class="cellrowborder" valign="top" width="34%" id="mcps1.2.3.1.1"><p id="p916mcpsimp"><a name="p916mcpsimp"></a><a name="p916mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="66%" id="mcps1.2.3.1.2"><p id="p918mcpsimp"><a name="p918mcpsimp"></a><a name="p918mcpsimp"></a>参数说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row944mcpsimp"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.3.1.1 "><p id="p946mcpsimp"><a name="p946mcpsimp"></a><a name="p946mcpsimp"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="66%" headers="mcps1.2.3.1.2 "><p id="p948mcpsimp"><a name="p948mcpsimp"></a><a name="p948mcpsimp"></a>显示uname指令格式提示。</p>
</td>
</tr>
<tr id="row119816412718"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.3.1.1 "><p id="p1384693214813"><a name="p1384693214813"></a><a name="p1384693214813"></a>无参数</p>
</td>
<td class="cellrowborder" valign="top" width="66%" headers="mcps1.2.3.1.2 "><p id="p18199114113719"><a name="p18199114113719"></a><a name="p18199114113719"></a>默认显示操作系统名称。</p>
</td>
</tr>
<tr id="row919mcpsimp"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.3.1.1 "><p id="p921mcpsimp"><a name="p921mcpsimp"></a><a name="p921mcpsimp"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="66%" headers="mcps1.2.3.1.2 "><p id="p923mcpsimp"><a name="p923mcpsimp"></a><a name="p923mcpsimp"></a>显示全部信息。</p>
</td>
</tr>
<tr id="row929mcpsimp"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.3.1.1 "><p id="p931mcpsimp"><a name="p931mcpsimp"></a><a name="p931mcpsimp"></a>-s</p>
</td>
<td class="cellrowborder" valign="top" width="66%" headers="mcps1.2.3.1.2 "><p id="p933mcpsimp"><a name="p933mcpsimp"></a><a name="p933mcpsimp"></a>显示操作系统名称。</p>
</td>
</tr>
<tr id="row929mcpsimp"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.3.1.1 "><p id="p931mcpsimp"><a name="p931mcpsimp"></a><a name="p931mcpsimp"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="66%" headers="mcps1.2.3.1.2 "><p id="p933mcpsimp"><a name="p933mcpsimp"></a><a name="p933mcpsimp"></a>显示内核发行版本。</p>
</td>
</tr>
<tr id="row934mcpsimp"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.3.1.1 "><p id="p936mcpsimp"><a name="p936mcpsimp"></a><a name="p936mcpsimp"></a>-m</p>
</td>
<td class="cellrowborder" valign="top" width="66%" headers="mcps1.2.3.1.2 "><p id="p938mcpsimp"><a name="p938mcpsimp"></a><a name="p938mcpsimp"></a>显示系统架构名称。</p>
</td>
</tr>
<tr id="row924mcpsimp"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.3.1.1 "><p id="p926mcpsimp"><a name="p926mcpsimp"></a><a name="p926mcpsimp"></a>-n</p>
</td>
<td class="cellrowborder" valign="top" width="66%" headers="mcps1.2.3.1.2 "><p id="p928mcpsimp"><a name="p928mcpsimp"></a><a name="p928mcpsimp"></a>显示主机的网络域名称。</p>
</td>
</tr>
<tr id="row934mcpsimp"><td class="cellrowborder" valign="top" width="34%" headers="mcps1.2.3.1.1 "><p id="p936mcpsimp"><a name="p936mcpsimp"></a><a name="p936mcpsimp"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="66%" headers="mcps1.2.3.1.2 "><p id="p938mcpsimp"><a name="p938mcpsimp"></a><a name="p938mcpsimp"></a>显示版本信息。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section03"></a>

- uname用于显示当前操作系统名称。

- 除参数--help和-a以外，其他参数可以相互搭配使用；uname -a 等价于 uname -srmnv。


## 使用实例<a name="section04"></a>

举例：

- uname -a
- uname -ms

## 输出说明<a name="section05"></a>

**示例 1** 查看系统详细信息

```shell
OHOS:/$ uname -a
Huawei LiteOS hisilicon 2.0.0.37 Huawei LiteOS 2.0.0.37 Oct 21 2021 17:39:32 Cortex-A7
OHOS:/$
```

**示例 2** 只查看操作系统名称和系统架构名称

```shell
OHOS:/$ uname -ms
Huawei LiteOS Cortex-A7
OHOS:/$
```
