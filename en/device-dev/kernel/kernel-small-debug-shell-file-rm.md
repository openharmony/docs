# rm


## Command Function<a name="section181141523142613"></a>

This command is used to delete a file or folder.

## Syntax<a name="section8800926132619"></a>

rm \[_-fv_\]  _FILE or rm_  \[_-rv_\] \[_PATH_  |  _filename_\]...

## Parameters<a name="section15476229152617"></a>

**Table  1**  Parameter description

<a name="table1507mcpsimp"></a>
<table><thead align="left"><tr id="row1513mcpsimp"><th class="cellrowborder" valign="top" width="22.220000000000002%" id="mcps1.2.4.1.1"><p id="p1515mcpsimp"><a name="p1515mcpsimp"></a><a name="p1515mcpsimp"></a><strong id="b8231115224817"><a name="b8231115224817"></a><a name="b8231115224817"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="51.519999999999996%" id="mcps1.2.4.1.2"><p id="p1517mcpsimp"><a name="p1517mcpsimp"></a><a name="p1517mcpsimp"></a><strong id="b1599275514488"><a name="b1599275514488"></a><a name="b1599275514488"></a>Description</strong></p>
</th>
<th class="cellrowborder" valign="top" width="26.26%" id="mcps1.2.4.1.3"><p id="p1519mcpsimp"><a name="p1519mcpsimp"></a><a name="p1519mcpsimp"></a><strong id="b186611453114810"><a name="b186611453114810"></a><a name="b186611453114810"></a>Value Range</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row231513373307"><td class="cellrowborder" valign="top" width="22.220000000000002%" headers="mcps1.2.4.1.1 "><p id="p73091437173016"><a name="p73091437173016"></a><a name="p73091437173016"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.2.4.1.2 "><p id="p630917373307"><a name="p630917373307"></a><a name="p630917373307"></a>Deletes empty or non-empty directories.</p>
</td>
<td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.2.4.1.3 "><p id="p1430943753016"><a name="p1430943753016"></a><a name="p1430943753016"></a>N/A</p>
</td>
</tr>
<tr id="row1231583773013"><td class="cellrowborder" valign="top" width="22.220000000000002%" headers="mcps1.2.4.1.1 "><p id="p19309203763010"><a name="p19309203763010"></a><a name="p19309203763010"></a>-f</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.2.4.1.2 "><p id="p53092373308"><a name="p53092373308"></a><a name="p53092373308"></a>Deletes a file or directory forcibly without confirmation. No error will be reported when a file that does not exist is to be deleted.</p>
</td>
<td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.2.4.1.3 "><p id="p8309937153018"><a name="p8309937153018"></a><a name="p8309937153018"></a>N/A</p>
</td>
</tr>
<tr id="row331513719302"><td class="cellrowborder" valign="top" width="22.220000000000002%" headers="mcps1.2.4.1.1 "><p id="p5309103733013"><a name="p5309103733013"></a><a name="p5309103733013"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.2.4.1.2 "><p id="p1830913711300"><a name="p1830913711300"></a><a name="p1830913711300"></a>Displays the deletion process.</p>
</td>
<td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.2.4.1.3 "><p id="p230933703015"><a name="p230933703015"></a><a name="p230933703015"></a>N/A</p>
</td>
</tr>
<tr id="row173147371301"><td class="cellrowborder" valign="top" width="22.220000000000002%" headers="mcps1.2.4.1.1 "><p id="p14309143753012"><a name="p14309143753012"></a><a name="p14309143753012"></a>PATH/filename</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.2.4.1.2 "><p id="p193091637183016"><a name="p193091637183016"></a><a name="p193091637183016"></a>Specifies the name of the file or directory to delete. The value can be a path.</p>
</td>
<td class="cellrowborder" valign="top" width="26.26%" headers="mcps1.2.4.1.3 "><p id="p10309173711309"><a name="p10309173711309"></a><a name="p10309173711309"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section10578163215262"></a>

-   The  **rm**  command can be used to delete multiple files or folders at a time.
-   You can run  **rm -r**  to delete a non-empty directory.
-   If the  **rm**  command without  **-f**  is used to delete a file that does not exist, an error will be reported.

## Example<a name="section18548133511263"></a>

Run the following commands:

-   rm testfile
-   rm -r testpath/

## Output<a name="section1565323814265"></a>

Example 1: deleting  **testfile**

```
OHOS:/$ ls
bin  etc  proc    storage  testfile  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ rm testfile
OHOS:/$ ls
bin  etc  proc    storage  userdata  vendor
dev  lib  sdcard  system   usr
```

Example 2: deleting  **testpath**, a non-empty directory

```
OHOS:/$ ls
bin  etc  proc    storage  testpath  usr
dev  lib  sdcard  system   userdata  vendor
OHOS:/$ rm -r testpath/
OHOS:/$ ls
bin  etc  proc    storage  userdata  vendor
dev  lib  sdcard  system   usr
```

