# mkdir


## Command Function<a name="section1083613274175"></a>

This command is used to create a directory.

## Syntax<a name="section820913118178"></a>

mkdir \[_-vp_\] \[_-m mode_\] \[_dirname..._\]

## Parameters<a name="section1256834121718"></a>

**Table  1**  Parameter description

<a name="table1299mcpsimp"></a>
<table><thead align="left"><tr id="row1305mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1307mcpsimp"><a name="p1307mcpsimp"></a><a name="p1307mcpsimp"></a><strong id="b209289681211447"><a name="b209289681211447"></a><a name="b209289681211447"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1309mcpsimp"><a name="p1309mcpsimp"></a><a name="p1309mcpsimp"></a><strong id="b16886221330"><a name="b16886221330"></a><a name="b16886221330"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1311mcpsimp"><a name="p1311mcpsimp"></a><a name="p1311mcpsimp"></a><strong id="b163527968011447"><a name="b163527968011447"></a><a name="b163527968011447"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row15431344183419"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p85331144163414"><a name="p85331144163414"></a><a name="p85331144163414"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2053354433413"><a name="p2053354433413"></a><a name="p2053354433413"></a>Displays the parameters supported by the <strong id="b1177313015559"><a name="b1177313015559"></a><a name="b1177313015559"></a>mkdir</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p16533144473411"><a name="p16533144473411"></a><a name="p16533144473411"></a>N/A</p>
</td>
</tr>
<tr id="row9543644193413"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p153374418344"><a name="p153374418344"></a><a name="p153374418344"></a>-m</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p9533114416343"><a name="p9533114416343"></a><a name="p9533114416343"></a>Sets the permissions on the directory to create.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p553334414343"><a name="p553334414343"></a><a name="p553334414343"></a>N/A</p>
</td>
</tr>
<tr id="row654224463420"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p853334414347"><a name="p853334414347"></a><a name="p853334414347"></a>-p</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p3533184493418"><a name="p3533184493418"></a><a name="p3533184493418"></a>Creates parent and child directories recursively.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p753313443344"><a name="p753313443344"></a><a name="p753313443344"></a>N/A</p>
</td>
</tr>
<tr id="row454234412343"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p153315440349"><a name="p153315440349"></a><a name="p153315440349"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p453344420349"><a name="p453344420349"></a><a name="p453344420349"></a>Prints detailed information about the directory creation process.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p553313444343"><a name="p553313444343"></a><a name="p553313444343"></a>N/A</p>
</td>
</tr>
<tr id="row17542644203418"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p853394453413"><a name="p853394453413"></a><a name="p853394453413"></a>directory</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p653315443342"><a name="p653315443342"></a><a name="p653315443342"></a>Specifies the directory to create.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1553344410344"><a name="p1553344410344"></a><a name="p1553344410344"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section1294234115172"></a>

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>For the files created on the FAT file system, the file permission attributes are the same as those of the mounted nodes. Currently, the node permissions include only user read and write. The  **group**  and  **others**  permissions do not take effect.
>In addition, only the user read and write permissions can be modified. The read and write permissions are  **rw**  and  **ro**  only. Therefore, when the  **-m**  option is specified in the  **mkdir**  command, only  **777**  and  **555**  permissions are available for the created directory, and the execute permission does not take effect.

## Example<a name="section1113345211713"></a>

Run the following commands:

-   mkdir testpath
-   mkdir -m 777 testpath
-   mkdir -pv testpath01/testpath02/testpath03

## Output<a name="section10142201012"></a>

```
OHOS:/tmp$ mkdir testpath
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath/
```

Example 2: creating a directory with specified permissions

```
OHOS:/tmp$ mkdir -m 777 testpath
OHOS:/tmp$ ll
total 2
drwxrwxrwx 1 0 0 2048 1979-12-31 00:00 testpath/
```

Example 3: creating directories recursively

```
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

