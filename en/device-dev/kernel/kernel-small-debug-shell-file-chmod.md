# chmod

## Command Function<a name="section13992936121418"></a>

This command is used to change file operation permissions.

## Syntax<a name="section63342439147"></a>

chmod \[_mode_\] \[_filename_\]

## Parameter Description<a name="section894414671411"></a>

**Table  1**  Parameters

<a name="table1049mcpsimp"></a>
<table><thead align="left"><tr id="row1055mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1057mcpsimp"><a name="p1057mcpsimp"></a><a name="p1057mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1059mcpsimp"><a name="p1059mcpsimp"></a><a name="p1059mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1061mcpsimp"><a name="p1061mcpsimp"></a><a name="p1061mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row2981144101719"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p20916441173"><a name="p20916441173"></a><a name="p20916441173"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p3911344161713"><a name="p3911344161713"></a><a name="p3911344161713"></a>Specifies the permissions for a file or directory. The value is an octal number, representing the permission of <strong id="b11602834153114"><a name="b11602834153114"></a><a name="b11602834153114"></a>User</strong> (owner), <strong id="b032113853120"><a name="b032113853120"></a><a name="b032113853120"></a>Group</strong> (group), or <strong id="b1980114418310"><a name="b1980114418310"></a><a name="b1980114418310"></a>Others</strong> (other groups).</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1591744161719"><a name="p1591744161719"></a><a name="p1591744161719"></a>[0,777]</p>
</td>
</tr>
<tr id="row15985440173"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p99124461717"><a name="p99124461717"></a><a name="p99124461717"></a>filename</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p149134481719"><a name="p149134481719"></a><a name="p149134481719"></a>Specifies the file name.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p0911144181712"><a name="p0911144181712"></a><a name="p0911144181712"></a>An existing file</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section182415221419"></a>

-   Specify  **mode**  to change file permissions.
-   For the files created on the FAT file system, the file permission attributes are the same as those of the mounted nodes. Currently, the node permissions include only user read and write. The  **group**  and  **others**  permissions do not take effect. In addition, only the user read and write permissions can be modified. The read and write permissions are  **rw**  and  **ro**  only. There is no such restriction for other file systems.

## Example<a name="section8518195718147"></a>

Change the permissions on the  **hello-harmony.txt**  file to  **644**  and  **777**.

## Output<a name="section127391818158"></a>

Modifying the permissions on the  **hello-harmony.txt**  file in the  **/dev**  directory:

```
OHOS:/dev$ chmod 644 hello-harmony.txt
OHOS:/dev$ ll hello-harmony.txt
-rw-r--r-- 0 0 0 0 1970-01-01 00:00 hello-harmony.txt
OHOS:/dev$ chmod 777 hello-harmony.txt
OHOS:/dev$ ll hello-harmony.txt
-rwxrwxrwx 0 0 0 0 1970-01-01 00:00 hello-harmony.txt
```

