# touch


## Command Function<a name="section17541924112716"></a>

-   This command is used to create an empty file in a specified directory.
-   If this command is executed to create an existing file, the execution will be successful but the timestamp will not be updated.

## Syntax<a name="section866182711274"></a>

touch \[_filename_\]

## Parameters<a name="section268912296270"></a>

**Table  1**  Parameter description

<a name="table1635mcpsimp"></a>
<table><thead align="left"><tr id="row1642mcpsimp"><th class="cellrowborder" valign="top" width="20.73%" id="mcps1.2.4.1.1"><p id="p1653mcpsimp"><a name="p1653mcpsimp"></a><a name="p1653mcpsimp"></a><strong id="b132581435193918"><a name="b132581435193918"></a><a name="b132581435193918"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52.44%" id="mcps1.2.4.1.2"><p id="p1655mcpsimp"><a name="p1655mcpsimp"></a><a name="p1655mcpsimp"></a><strong id="b88661537163918"><a name="b88661537163918"></a><a name="b88661537163918"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="26.83%" id="mcps1.2.4.1.3"><p id="p1657mcpsimp"><a name="p1657mcpsimp"></a><a name="p1657mcpsimp"></a><strong id="b164851738193910"><a name="b164851738193910"></a><a name="b164851738193910"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1323618419461"><td class="cellrowborder" valign="top" width="20.73%" headers="mcps1.2.4.1.1 "><p id="p1229443463"><a name="p1229443463"></a><a name="p1229443463"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="52.44%" headers="mcps1.2.4.1.2 "><p id="p1122915417465"><a name="p1122915417465"></a><a name="p1122915417465"></a>Displays the parameters supported by the <strong id="b39321953125917"><a name="b39321953125917"></a><a name="b39321953125917"></a>touch</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="26.83%" headers="mcps1.2.4.1.3 "><p id="p152291464613"><a name="p152291464613"></a><a name="p152291464613"></a>N/A</p>
</td>
</tr>
<tr id="row82356419461"><td class="cellrowborder" valign="top" width="20.73%" headers="mcps1.2.4.1.1 "><p id="p322913424613"><a name="p322913424613"></a><a name="p322913424613"></a>filename</p>
</td>
<td class="cellrowborder" valign="top" width="52.44%" headers="mcps1.2.4.1.2 "><p id="p162291494614"><a name="p162291494614"></a><a name="p162291494614"></a>Specifies the name of the file to create.</p>
</td>
<td class="cellrowborder" valign="top" width="26.83%" headers="mcps1.2.4.1.3 "><p id="p182291242462"><a name="p182291242462"></a><a name="p182291242462"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section412093332714"></a>

-   The  **touch**  command creates an empty file that is readable and writeable.
-   You can use the  **touch**  command to create multiple files at a time.

    >![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
    >If you run the  **touch**  command to create a file in a directory storing important system resources, unexpected results such as a system breakdown may occur. For example, if you run the  **touch uartdev-0**  command in the  **/dev**  directory, the system may stop responding.


## Example<a name="section414434814354"></a>

Run the following commands:

-   touch file.c
-   touch testfile1 testfile2 testfile3

## Output<a name="section1028419515711"></a>

Example 1: creating the  **file.c**  file

```
OHOS:/tmp$ ls
OHOS:/tmp$ touch file.c
OHOS:/tmp$ ls
file.c
OHOS:/tmp$ ll
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 file.c*
```

Example 2: creating three files \(**testfile1**,  **testfile2**, and  **testfile3**\)

```
*OHOS:/tmp$
OHOS:/tmp$ touch testfile1 testfile2 testfile3
OHOS:/tmp$ ll
total 0
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile1*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile2*
-rwxrwxrwx 1 0 0 0 1979-12-31 00:00 testfile3*
OHOS:/tmp$
```

