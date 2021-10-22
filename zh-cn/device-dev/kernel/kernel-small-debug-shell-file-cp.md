# cp<a name="ZH-CN_TOPIC_0000001133846484"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section05)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

拷贝文件，创建一份副本。

## 命令格式<a name="section02"></a>

cp --help

cp \[_SOURCEFILE_\] \[_DESTFILE_\]

## 参数说明<a name="section03"></a>

**表 1**  参数说明

<a name="table1130mcpsimp"></a>
<table><thead align="left"><tr id="row1136mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1138mcpsimp"><a name="p1138mcpsimp"></a><a name="p1138mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.2"><p id="p1140mcpsimp"><a name="p1140mcpsimp"></a><a name="p1140mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.3"><p id="p1142mcpsimp"><a name="p1142mcpsimp"></a><a name="p1142mcpsimp"></a>取值范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row3838mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p3840mcpsimp"><a name="p3840mcpsimp"></a><a name="p3840mcpsimp"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.2 "><p id="p3842mcpsimp"><a name="p3842mcpsimp"></a><a name="p3842mcpsimp"></a>使用帮助。</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.3 "><p id="p3844mcpsimp"><a name="p3844mcpsimp"></a><a name="p3844mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1143mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1145mcpsimp"><a name="p1145mcpsimp"></a><a name="p1145mcpsimp"></a>SOURCEFILE</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.2 "><p id="p1147mcpsimp"><a name="p1147mcpsimp"></a><a name="p1147mcpsimp"></a>源文件路径。</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.3 "><p id="p1149mcpsimp"><a name="p1149mcpsimp"></a><a name="p1149mcpsimp"></a>目前只支持文件,不支持目录；支持多文件同时拷贝。</p>
</td>
</tr>
<tr id="row1150mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1152mcpsimp"><a name="p1152mcpsimp"></a><a name="p1152mcpsimp"></a>DESTFILE</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.2 "><p id="p1154mcpsimp"><a name="p1154mcpsimp"></a><a name="p1154mcpsimp"></a>目的文件路径。</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.3 "><p id="p1156mcpsimp"><a name="p1156mcpsimp"></a><a name="p1156mcpsimp"></a>支持目录以及文件。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section04"></a>

-   同一路径下，源文件与目的文件不能重名。
-   源文件必须存在，且不为目录。
-   源文件路径支持“\*”和“？”通配符，“\*”代表任意多个字符，“？”代表任意单个字符。目的路径不支持通配符。当源路径可匹配多个文件时，目的路径必须为目录。
-   目的路径为目录时，该目录必须存在。此时目的文件以源文件命名。
-   目的路径为文件时，所在目录必须存在。此时拷贝文件的同时为副本重命名。
-   目的文件不存在时创建新文件，已存在则覆盖。

> ![](../public_sys-resources/icon-notice.gif) **须知：**
>
> 拷贝系统重要资源时，会对系统造成死机等重大未知影响，如用于拷贝/dev/uartdev-1 文件时，会产生系统卡死现象。

## 使用实例<a name="section05"></a>

举例：cp hello-OHOS.txt hello-harmony.txt ./tmp/

## 输出说明<a name="section06"></a>

**示例 1**  显示结果如下

```shell
OHOS:/$ ls
bin  hello-OHOS.txt     proc     system    vendor
dev  hello-harmony.txt  sdcard   userdata
etc  lib                storage  usr
OHOS:/$ mkdir tmp
OHOS:/$ cp hello-OHOS.txt hello-harmony.txt tmp/
OHOS:/$ ll tmp
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 hello-OHOS.txt*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 hello-harmony.txt*
```
