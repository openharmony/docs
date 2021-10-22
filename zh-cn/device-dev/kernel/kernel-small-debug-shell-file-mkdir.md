# mkdir<a name="ZH-CN_TOPIC_0000001133846486"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section05)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

mkdir命令用来创建一个目录。

## 命令格式<a name="section02"></a>

mkdir \[_-vp_\] \[_-m mode_\] \[_dirname..._\]

## 参数说明<a name="section03"></a>

**表 1**  参数说明

<a name="table1299mcpsimp"></a>
<table><thead align="left"><tr id="row1305mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1307mcpsimp"><a name="p1307mcpsimp"></a><a name="p1307mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1309mcpsimp"><a name="p1309mcpsimp"></a><a name="p1309mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1311mcpsimp"><a name="p1311mcpsimp"></a><a name="p1311mcpsimp"></a>取值范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2500105121818"><a name="p2500105121818"></a><a name="p2500105121818"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>查看mkdir命令支持的参数列表</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>N/A</p>
</td>
</tr>
<tr id="row1312mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1314mcpsimp"><a name="p1314mcpsimp"></a><a name="p1314mcpsimp"></a>-m</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1316mcpsimp"><a name="p1316mcpsimp"></a><a name="p1316mcpsimp"></a>设置即将创建目录的权限。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1318mcpsimp"><a name="p1318mcpsimp"></a><a name="p1318mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1312mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1314mcpsimp"><a name="p1314mcpsimp"></a><a name="p1314mcpsimp"></a>-p</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1316mcpsimp"><a name="p1316mcpsimp"></a><a name="p1316mcpsimp"></a>递归逐级创建父子目录。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1318mcpsimp"><a name="p1318mcpsimp"></a><a name="p1318mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1312mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1314mcpsimp"><a name="p1314mcpsimp"></a><a name="p1314mcpsimp"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1316mcpsimp"><a name="p1316mcpsimp"></a><a name="p1316mcpsimp"></a>打印创建目录过程中的详细信息。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1318mcpsimp"><a name="p1318mcpsimp"></a><a name="p1318mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row1312mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1314mcpsimp"><a name="p1314mcpsimp"></a><a name="p1314mcpsimp"></a>directory</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1316mcpsimp"><a name="p1316mcpsimp"></a><a name="p1316mcpsimp"></a>需要创建的目录。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1318mcpsimp"><a name="p1318mcpsimp"></a><a name="p1318mcpsimp"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section04"></a>

-   mkdir后加所需要创建的目录名会在当前目录下创建目录。
-   mkdir后加路径，再加上需要创建的目录名，即在指定目录下创建目录。
-   mkdir后加参数，提供目录权限定制，目录逐级创建等功能。

> ![](../public_sys-resources/icon-notice.gif) **须知：**
>
> fatfs文件系统所有创建的文件和其挂载节点的权限属性保持一致，目前节点的权限只有用户读写权限，group和others权限不生效，
>
> 且只有读写位可设置，有rw和ro两种，因此mkdir在附加-m参数时，创建的目录权限仅有777和555两种，可执行权限也不生效。

## 使用实例<a name="section05"></a>

举例：

- mkdir testpath
- mkdir -m 777 testpath
- mkdir -pv testpath01/testpath02/testpath03

## 输出说明<a name="section06"></a>

**示例 1** 创建默认文件

```shell
OHOS:/tmp$ mkdir testpath
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath/
```

**示例 2** 创建指定mode的目录

```shell
OHOS:/tmp$ mkdir -m 777 testpath
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath/
```

**示例 3** 逐级创建目录

```shell
OHOS:/tmp$ mkdir -pv testpath01/testpath02/testpath03
mkdir: created directory 'testpath01'
mkdir: created directory 'testpath01/testpath02'
mkdir: created directory 'testpath01/testpath02/testpath03'
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath01/
OHOS:/tmp$ ll testpath01/
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath02/
OHOS:/tmp$ ll testpath01/testpath02/
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath03/
```
