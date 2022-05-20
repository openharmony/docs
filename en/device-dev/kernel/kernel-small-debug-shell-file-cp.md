# cp

## Command Function<a name="section6841203041513"></a>

This command is used to create a copy for a file.

## Syntax<a name="section24286359150"></a>

cp \[_SOURCEFILE_\] \[_DESTFILE_\]

## Parameters<a name="section558617385152"></a>

**Table  1**  Parameter description

<a name="table1130mcpsimp"></a>
<table><thead align="left"><tr id="row1136mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1138mcpsimp"><a name="p1138mcpsimp"></a><a name="p1138mcpsimp"></a><strong id="b203611832412"><a name="b203611832412"></a><a name="b203611832412"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p1140mcpsimp"><a name="p1140mcpsimp"></a><a name="p1140mcpsimp"></a><strong id="b1170512342014"><a name="b1170512342014"></a><a name="b1170512342014"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1142mcpsimp"><a name="p1142mcpsimp"></a><a name="p1142mcpsimp"></a><strong id="b173835351418"><a name="b173835351418"></a><a name="b173835351418"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row217620816236"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p181687832310"><a name="p181687832310"></a><a name="p181687832310"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p181687882317"><a name="p181687882317"></a><a name="p181687882317"></a>Displays help information.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p18168118182312"><a name="p18168118182312"></a><a name="p18168118182312"></a>N/A</p>
</td>
</tr>
<tr id="row1417648122313"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p516816822316"><a name="p516816822316"></a><a name="p516816822316"></a>SOURCEFILE</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p81686862314"><a name="p81686862314"></a><a name="p81686862314"></a>Specifies the path of the source file.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1016811862312"><a name="p1016811862312"></a><a name="p1016811862312"></a>This command does not support copy of a directory, but supports copy of multiple files at a time.</p>
</td>
</tr>
<tr id="row191761384231"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p13168880235"><a name="p13168880235"></a><a name="p13168880235"></a>DESTFILE</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p9168789231"><a name="p9168789231"></a><a name="p9168789231"></a>Specifies the destination file path.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p316810810235"><a name="p316810810235"></a><a name="p316810810235"></a>Both a directory and a file are supported.</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section16128156162"></a>

-   The name of the source file cannot be the same as that of the destination file in the same path.
-   **SOURCEFILE**  must exist and cannot be a directory.
-   **SOURCEFILE**  supports wildcard characters \* and ?. The asterisk \(\*\) indicates any number of characters, and the question mark \(?\) represents a single character.  **DESTFILE**  does not support wildcard characters. If  **SOURCEFILE**  specifies multiple files,  **DESTFILE**  must be a directory.
-   If  **DESTFILE**  specifies a directory, this directory must exist. In this case, the destination file is named after the source file.
-   If  **DESTFILE**  specifies a file, the directory for this file must exist. In this case, the file copy is renamed.
-   If the destination file does not exist, a new file is created. If the destination file already exists, the existing file is overwritten.

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>When important system resources are copied, unexpected results such as a system breakdown may occur. For example, when the  **/dev/uartdev-1**  file is copied, the system may stop responding.

## Example<a name="section19354171211618"></a>

Run  **cp hello-OHOS.txt hello-harmony.txt ./tmp/**.

## Output<a name="section16754183195914"></a>

Copying  **hello-OHOS.txt**  and  **hello-harmony.txt**  to  **/tmp/**:

```
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

