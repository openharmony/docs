# chmod<a name="ZH-CN_TOPIC_0000001179845927"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section05)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

chmod用于修改文件操作权限。

## 命令格式<a name="section02"></a>

chmod \[_mode_\] \[_filename_\]

## 参数说明<a name="section03"></a>

**表 1**  参数说明

<a name="table1049mcpsimp"></a>
<table><thead align="left"><tr id="row1055mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1057mcpsimp"><a name="p1057mcpsimp"></a><a name="p1057mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1059mcpsimp"><a name="p1059mcpsimp"></a><a name="p1059mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1061mcpsimp"><a name="p1061mcpsimp"></a><a name="p1061mcpsimp"></a>取值范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row1062mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1064mcpsimp"><a name="p1064mcpsimp"></a><a name="p1064mcpsimp"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p13519122819294"><a name="p13519122819294"></a><a name="p13519122819294"></a>文件或文件夹权限，用8进制表示对应User、Group、及Other（拥有者、群组、其他组）的权限。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p182181026104214"><a name="p182181026104214"></a><a name="p182181026104214"></a>[0,777]</p>
</td>
</tr>
<tr id="row172161126124218"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p12217026154215"><a name="p12217026154215"></a><a name="p12217026154215"></a>filename</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p4218826194210"><a name="p4218826194210"></a><a name="p4218826194210"></a>文件路径。</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p13872195215290"><a name="p13872195215290"></a><a name="p13872195215290"></a>已存在的文件。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section04"></a>

- 在需要修改的文件名前加上文件权限值就可以修改该文件的权限值。
- fatfs文件系统所有创建的文件和挂载节点的权限属性保持一致，目前节点的权限只有用户读写权限，group和others权限不生效；且只允许修改用户读写权限，读写权限只有rw和ro两种。其他文件系统无限制。

## 使用实例<a name="section05"></a>

举例：chmod 644 hello-harmony.txt ;  chmod 777 hello-harmony.txt

## 输出说明<a name="section06"></a>

**示例 1**  修改/dev目录下 hello-harmony.txt 文件的权限

```shell
OHOS:/dev$ chmod 644 hello-harmony.txt
OHOS:/dev$ ll hello-harmony.txt
-rw-r--r-- 0 0 0 0 1970-01-01 00:00 hello-harmony.txt
OHOS:/dev$ chmod 777 hello-harmony.txt
OHOS:/dev$ ll hello-harmony.txt
-rwxrwxrwx 0 0 0 0 1970-01-01 00:00 hello-harmony.txt
```

