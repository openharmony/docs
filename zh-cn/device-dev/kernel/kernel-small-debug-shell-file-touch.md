# touch<a name="ZH-CN_TOPIC_0000001134006268"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section405)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

-   touch命令用来在指定的目录下创建一个不存在的空文件。
-   touch命令操作已存在的文件会成功，不会更新时间戳。

## 命令格式<a name="section02"></a>

touch \[_filename_\] 

## 参数说明<a name="section03"></a>

**表 1**  参数说明

<a name="table1635mcpsimp"></a>

<table><thead align="left"><tr id="row1642mcpsimp"><th class="cellrowborder" valign="top" width="20.73%" id="mcps1.2.4.1.1"><p id="p1653mcpsimp"><a name="p1653mcpsimp"></a><a name="p1653mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="52.44%" id="mcps1.2.4.1.2"><p id="p1655mcpsimp"><a name="p1655mcpsimp"></a><a name="p1655mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="26.83%" id="mcps1.2.4.1.3"><p id="p1657mcpsimp"><a name="p1657mcpsimp"></a><a name="p1657mcpsimp"></a>取值范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2500105121818"><a name="p2500105121818"></a><a name="p2500105121818"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>查看touch命令支持的参数列表</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>N/A</p>
</td>
</tr>
<tr id="row1684mcpsimp"><td class="cellrowborder" valign="top" width="20.73%" headers="mcps1.2.4.1.1 "><p id="p1686mcpsimp"><a name="p1686mcpsimp"></a><a name="p1686mcpsimp"></a>filename</p>
</td>
<td class="cellrowborder" valign="top" width="52.44%" headers="mcps1.2.4.1.2 "><p id="p1688mcpsimp"><a name="p1688mcpsimp"></a><a name="p1688mcpsimp"></a>需要创建文件的名称。</p>
</td>
<td class="cellrowborder" valign="top" width="26.83%" headers="mcps1.2.4.1.3 "><p id="p1690mcpsimp"><a name="p1690mcpsimp"></a><a name="p1690mcpsimp"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section04"></a>

-   touch命令用来创建一个空文件，该文件可读写。
-   使用touch命令允许一次创建多个文件。

    >![](../public_sys-resources/icon-notice.gif) **须知：** 
    >在系统重要资源路径下使用touch命令创建文件，会对系统造成死机等未知影响，如在/dev路径下执行touch uartdev-0，会产生系统卡死现象。

## 使用实例<a name="section05"></a>

举例：

- touch file.c
- touch testfile1 testfile2 testfile3

## 输出说明<a name="section06"></a>

**示例 1**  创建一个名为 file.c 的文件

```shell
OHOS:/tmp$ ls
OHOS:/tmp$ touch file.c
OHOS:/tmp$ ls
file.c
OHOS:/tmp$ ll
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 file.c*
```

**示例 2** 同时创建三个文件

```shell
OHOS:/tmp$ touch testfile1 testfile2 testfile3
OHOS:/tmp$ ll
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile1*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile2*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile3*
OHOS:/tmp$
```
