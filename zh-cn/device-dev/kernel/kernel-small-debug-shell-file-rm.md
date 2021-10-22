# rm<a name="ZH-CN_TOPIC_0000001134006266"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section05)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

rm命令用来删除文件或文件夹。

## 命令格式<a name="section02"></a>

rm \[_-fv_\] _FILE or rm_ \[_-rv_\] \[_PATH_ | _filename_\]...

## 参数说明<a name="section03"></a>

**表 1**  参数说明

<a name="table1507mcpsimp"></a>
<table><thead align="left"><tr id="row1513mcpsimp"><th class="cellrowborder" valign="top" width="22.220000000000002%" id="mcps1.2.4.1.1"><p id="p1515mcpsimp"><a name="p1515mcpsimp"></a><a name="p1515mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="51.519999999999996%" id="mcps1.2.4.1.2"><p id="p1517mcpsimp"><a name="p1517mcpsimp"></a><a name="p1517mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="26.26%" id="mcps1.2.4.1.3"><p id="p1519mcpsimp"><a name="p1519mcpsimp"></a><a name="p1519mcpsimp"></a>取值范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row1520mcpsimp"><td class="cellrowborder" valign="top" width="22.220000000000002%" headers="mcps1.2.4.1.1 "><p id="p1522mcpsimp"><a name="p1522mcpsimp"></a><a name="p1522mcpsimp"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.2.4.1.2 "><p id="p1524mcpsimp"><a name="p1524mcpsimp"></a><a name="p1524mcpsimp"></a>删除空目录或非空目录。</p>
</td>
<td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.2.4.1.3 "><p id="p1526mcpsimp"><a name="p1526mcpsimp"></a><a name="p1526mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1520mcpsimp"><td class="cellrowborder" valign="top" width="22.220000000000002%" headers="mcps1.2.4.1.1 "><p id="p1522mcpsimp"><a name="p1522mcpsimp"></a><a name="p1522mcpsimp"></a>-f</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.2.4.1.2 "><p id="p1524mcpsimp"><a name="p1524mcpsimp"></a><a name="p1524mcpsimp"></a>强制删除：不需要确认，删除不存的文件在也不报错。</p>
</td>
<td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.2.4.1.3 "><p id="p1526mcpsimp"><a name="p1526mcpsimp"></a><a name="p1526mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1520mcpsimp"><td class="cellrowborder" valign="top" width="22.220000000000002%" headers="mcps1.2.4.1.1 "><p id="p1522mcpsimp"><a name="p1522mcpsimp"></a><a name="p1522mcpsimp"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.2.4.1.2 "><p id="p1524mcpsimp"><a name="p1524mcpsimp"></a><a name="p1524mcpsimp"></a>显示删除的过程。</p>
</td>
<td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.2.4.1.3 "><p id="p1526mcpsimp"><a name="p1526mcpsimp"></a><a name="p1526mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1527mcpsimp"><td class="cellrowborder" valign="top" width="22.220000000000002%" headers="mcps1.2.4.1.1 "><p id="p1529mcpsimp"><a name="p1529mcpsimp"></a><a name="p1529mcpsimp"></a>PATH/filename</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.2.4.1.2 "><p id="p1531mcpsimp"><a name="p1531mcpsimp"></a><a name="p1531mcpsimp"></a>要删除文件或文件夹的名称，支持输入路径。</p>
</td>
<td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.2.4.1.3 "><p id="p1533mcpsimp"><a name="p1533mcpsimp"></a><a name="p1533mcpsimp"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section04"></a>

-   rm命令能同时删除多个文件或文件夹。
-   rm -r命令可以删除非空目录。
-   删除不存在的文件会报错。

## 使用实例<a name="section05"></a>

举例：

1.  输入rm testfile
2.  输入rm -r testpath/

## 输出说明<a name="section06"></a>

**示例 1**  用 rm 命令删除文件 testfile

```shell
OHOS:/$ ls
bin  etc  proc    storage  testfile  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ rm testfile
OHOS:/$ ls
bin  etc  proc    storage  userdata  vendor
dev  lib  sdcard  system   usr
```

**示例 2**  用 rm -r 删除非空目录 testpath

```shell
OHOS:/$ ls
bin  etc  proc    storage  testpath  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ rm -r testpath/
OHOS:/$ ls
bin  etc  proc    storage  userdata  vendor
dev  lib  sdcard  system   usr
```
