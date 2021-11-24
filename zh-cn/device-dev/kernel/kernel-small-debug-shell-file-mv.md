# mv<a name="ZH-CN_TOPIC_0000001133846432"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section05)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

移动文件

## 命令格式<a name="section02"></a>

mv \[_-fivn_\] _SOURCE... DEST_

## 参数说明<a name="section03"></a>

**表 1**  参数说明

<a name="table1130mcpsimp"></a>
<table><thead align="left"><tr id="row1136mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1138mcpsimp"><a name="p1138mcpsimp"></a><a name="p1138mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1140mcpsimp"><a name="p1140mcpsimp"></a><a name="p1140mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1142mcpsimp"><a name="p1142mcpsimp"></a><a name="p1142mcpsimp"></a>取值范围</p>
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
<tr id="row3838mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p3840mcpsimp"><a name="p3840mcpsimp"></a><a name="p3840mcpsimp"></a>-f</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.2 "><p id="p3842mcpsimp"><a name="p3842mcpsimp"></a><a name="p3842mcpsimp"></a>通过删除目标文件强制复制。</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.3 "><p id="p3844mcpsimp"><a name="p3844mcpsimp"></a><a name="p3844mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row3838mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p3840mcpsimp"><a name="p3840mcpsimp"></a><a name="p3840mcpsimp"></a>-i</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p3842mcpsimp"><a name="p3842mcpsimp"></a><a name="p3842mcpsimp"></a>若指定移动的源目录或文件与目标中目录或文件同名，则会先询问是否覆盖旧文件，输入 y 直接覆盖，输入 n 取消该操作。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p3844mcpsimp"><a name="p3844mcpsimp"></a><a name="p3844mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row3838mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p3840mcpsimp"><a name="p3840mcpsimp"></a><a name="p3840mcpsimp"></a>-n</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p3842mcpsimp"><a name="p3842mcpsimp"></a><a name="p3842mcpsimp"></a>不要覆盖任何已存在的文件或目录。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p3844mcpsimp"><a name="p3844mcpsimp"></a><a name="p3844mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row3838mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p3840mcpsimp"><a name="p3840mcpsimp"></a><a name="p3840mcpsimp"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p3842mcpsimp"><a name="p3842mcpsimp"></a><a name="p3842mcpsimp"></a>目前本参数toybox官方最新代码虽然支持，但同样也不生效。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p3844mcpsimp"><a name="p3844mcpsimp"></a><a name="p3844mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1143mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1145mcpsimp"><a name="p1145mcpsimp"></a><a name="p1145mcpsimp"></a>SOURCE</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1147mcpsimp"><a name="p1147mcpsimp"></a><a name="p1147mcpsimp"></a>源文件路径。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1149mcpsimp"><a name="p1149mcpsimp"></a><a name="p1149mcpsimp"></a>目前只支持文件,不支持目录；支持多文件同时移动。</p>
</td>
</tr>
<tr id="row1150mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1152mcpsimp"><a name="p1152mcpsimp"></a><a name="p1152mcpsimp"></a>DEST</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1154mcpsimp"><a name="p1154mcpsimp"></a><a name="p1154mcpsimp"></a>目的文件路径。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1156mcpsimp"><a name="p1156mcpsimp"></a><a name="p1156mcpsimp"></a>支持目录以及文件。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section04"></a>

-   源文件路径支持“\*”和“？”通配符，“\*”代表任意多个字符，“？”代表任意单个字符。目的路径不支持通配符。当源路径可匹配多个文件时，目的路径必须为目录。
-   目的路径为目录时，该目录必须存在。此时目的文件以源文件命名。
-   目的路径为文件时，所在目录必须存在。
-   目的文件已存在则会覆盖。

## 使用实例<a name="section05"></a>

举例：

- mv -i test.txt testpath/

- mv test?.txt testpath/ （移动 test3.txt  testA.txt  test_.txt）


## 输出说明<a name="section06"></a>

**示例 1**  显示结果如下

```shell
OHOS:/$ touch test.txt
OHOS:/$ mkdir testpath
OHOS:/$ touch testpath/test.txt
OHOS:/$ mv -i test.txt testpath/
mv: overwrite 'testpath//test.txt' (Y/n):y
OHOS:/$ ls
bin  etc  proc    storage  testpath  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ cp testpath/test.txt ./
OHOS:/$ ls
bin  etc  proc    storage  test.txt  userdata  vendor
dev  lib  sdcard  system   testpath  usr
OHOS:/$ mv -i test.txt testpath/
mv: overwrite 'testpath//test.txt' (Y/n):n
OHOS:/$ ls
bin  etc  proc    storage  test.txt  userdata  vendor
dev  lib  sdcard  system   testpath  usr
```

**示例 2**  通配符使用

```shell
OHOS:/$ ls
bin  etc  proc    storage  test.txt   testA.txt  testpath  usr
dev  lib  sdcard  system   test3.txt  test_.txt  userdata  vendor
OHOS:/$ mv test?.txt testpath/
OHOS:/$ ls
bin  etc  proc    storage  test.txt  userdata  vendor
dev  lib  sdcard  system   testpath  usr
OHOS:/$ ls testpath/
test.txt  test3.txt  testA.txt  test_.txt
```
