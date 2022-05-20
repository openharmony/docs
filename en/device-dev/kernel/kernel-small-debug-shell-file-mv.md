# mv


## Command Function<a name="section201149459368"></a>

This command is used to move files.

## Syntax<a name="section579813484364"></a>

mv \[_-fivn_\]  _SOURCE... DEST_

## Parameters<a name="section168065311366"></a>

**Table  1**  Parameter description

<a name="table1845mcpsimp"></a>
<table><thead align="left"><tr id="row1851mcpsimp"><th class="cellrowborder" valign="top" width="20.84%" id="mcps1.2.4.1.1"><p id="p1853mcpsimp"><a name="p1853mcpsimp"></a><a name="p1853mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52.16%" id="mcps1.2.4.1.2"><p id="p1855mcpsimp"><a name="p1855mcpsimp"></a><a name="p1855mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p1857mcpsimp"><a name="p1857mcpsimp"></a><a name="p1857mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row20678165916440"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p126571859174418"><a name="p126571859174418"></a><a name="p126571859174418"></a>-help</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p1165745918447"><a name="p1165745918447"></a><a name="p1165745918447"></a>Displays help information.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p165725913441"><a name="p165725913441"></a><a name="p165725913441"></a>N/A</p>
</td>
</tr>
<tr id="row12678159174418"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p166571959164412"><a name="p166571959164412"></a><a name="p166571959164412"></a>-f</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p8657859134412"><a name="p8657859134412"></a><a name="p8657859134412"></a>Forcibly overwrites the target file.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1965775904419"><a name="p1965775904419"></a><a name="p1965775904419"></a>N/A</p>
</td>
</tr>
<tr id="row126781259104418"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p5657115954414"><a name="p5657115954414"></a><a name="p5657115954414"></a>-i</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p7657105917445"><a name="p7657105917445"></a><a name="p7657105917445"></a>Provides a prompt before moving a file that would overwrite an existing file. Enter <strong id="b886564463218"><a name="b886564463218"></a><a name="b886564463218"></a>y</strong> to overwrite the file or enter <strong id="b16826758113218"><a name="b16826758113218"></a><a name="b16826758113218"></a>n</strong> to cancel the operation.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1165795924415"><a name="p1165795924415"></a><a name="p1165795924415"></a>N/A</p>
</td>
</tr>
<tr id="row186773599442"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p86571059114410"><a name="p86571059114410"></a><a name="p86571059114410"></a>-n</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p36572059164415"><a name="p36572059164415"></a><a name="p36572059164415"></a>Do not overwrite any existing file or directory.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1965715944417"><a name="p1965715944417"></a><a name="p1965715944417"></a>N/A</p>
</td>
</tr>
<tr id="row66771159124413"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p15657185964416"><a name="p15657185964416"></a><a name="p15657185964416"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p166571759124418"><a name="p166571759124418"></a><a name="p166571759124418"></a>This parameter does not take effect although it is supported by the latest Toybox code.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p12657059184418"><a name="p12657059184418"></a><a name="p12657059184418"></a>N/A</p>
</td>
</tr>
<tr id="row11677145964419"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p2657205924414"><a name="p2657205924414"></a><a name="p2657205924414"></a>SOURCE</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p3657205924416"><a name="p3657205924416"></a><a name="p3657205924416"></a>Specifies the path of the source file.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1365775904419"><a name="p1365775904419"></a><a name="p1365775904419"></a>This command cannot be used to move a directory. It can be used to move multiple files at a time.</p>
</td>
</tr>
<tr id="row1267615917447"><td class="cellrowborder" valign="top" width="20.84%" headers="mcps1.2.4.1.1 "><p id="p1658459144411"><a name="p1658459144411"></a><a name="p1658459144411"></a>DEST</p>
</td>
<td class="cellrowborder" valign="top" width="52.16%" headers="mcps1.2.4.1.2 "><p id="p265810599448"><a name="p265810599448"></a><a name="p265810599448"></a>Specifies the destination file path.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p7658105914449"><a name="p7658105914449"></a><a name="p7658105914449"></a>Both a directory and a file are supported.</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section19190125723612"></a>

-   **SOURCE**  supports wildcard characters \* and ?. The asterisk \(\*\) indicates any number of characters, and the question mark \(?\) represents a single character.  **DEST**  does not support wildcard characters. If the specified  **SOURCE**  matches multiple files,  **DEST**  must be a directory.
-   If  **DEST**  is a directory, this directory must exist. In this case, the destination file is named after the source file.
-   If  **DEST**  is a file, the directory for this file must exist.
-   If the destination file already exists, it will be overwritten.

## Example<a name="section10383416372"></a>

Run the following commands:

-   mv -i test.txt testpath/
-   mv test?.txt testpath/ \(Move  **test3.txt**,  **testA.txt**, and  **test\_.txt**\)

## Output<a name="section131601649114511"></a>

Example 1: moving a file

```
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

Example 2: moving files using wildcards

```
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

