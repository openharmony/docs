# su

## Command Function<a name="section297810431676"></a>

This command is used to switch the user account.

## Syntax<a name="section157131147876"></a>

su \[_uid_\] \[_gid_\]

## Parameters<a name="section04145521671"></a>

**Table  1**  Parameter description

<a name="table1049mcpsimp"></a>
<table><thead align="left"><tr id="row1055mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p1057mcpsimp"><a name="p1057mcpsimp"></a><a name="p1057mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="51.93%" id="mcps1.2.4.1.2"><p id="p1059mcpsimp"><a name="p1059mcpsimp"></a><a name="p1059mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="27.07%" id="mcps1.2.4.1.3"><p id="p1061mcpsimp"><a name="p1061mcpsimp"></a><a name="p1061mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row1062mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1064mcpsimp"><a name="p1064mcpsimp"></a><a name="p1064mcpsimp"></a>uid</p>
</td>
<td class="cellrowborder" valign="top" width="51.93%" headers="mcps1.2.4.1.2 "><p id="p14138191243"><a name="p14138191243"></a><a name="p14138191243"></a>Specifies the ID of the target user.</p>
</td>
<td class="cellrowborder" valign="top" width="27.07%" headers="mcps1.2.4.1.3 "><a name="ul14151675449"></a><a name="ul14151675449"></a><ul id="ul14151675449"><li>Left blank</li><li>[0,60000]</li></ul>
</td>
</tr>
<tr id="row172161126124218"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p12217026154215"><a name="p12217026154215"></a><a name="p12217026154215"></a>gid</p>
</td>
<td class="cellrowborder" valign="top" width="51.93%" headers="mcps1.2.4.1.2 "><p id="p48748461789"><a name="p48748461789"></a><a name="p48748461789"></a>Specifies the ID of the target user group.</p>
</td>
<td class="cellrowborder" valign="top" width="27.07%" headers="mcps1.2.4.1.3 "><a name="ul10433713134417"></a><a name="ul10433713134417"></a><ul id="ul10433713134417"><li>Left blank</li><li>[0,60000]</li></ul>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section14615155610719"></a>

-   If no parameter is specified, the  **su**  command switches to user  **root**  by default. The  **uid**  and  **gid**  for user  **root**  are both  **0**.
-   If  **uid**  and  **gid**  are specified, this command allows commands to be executed as the user with the specified  **uid**  and  **gid**.
-   If the input parameter is out of the range, an error message will be printed.

## Example<a name="section13338150985"></a>

Run  **su 1000 1000**.

## Output<a name="section125021924194613"></a>

Switching to the user with both  **uid**  and  **gid**  of  **1000**:

```
OHOS # ls
Directory /data/system/param:
-rw-r--r-- 0 u:0 g:0 hello_1.txt
OHOS # su 1000 1000
OHOS # touch hello 2.txt
OHOS # ls
Directory /data/system/param:
-rw-r--r-- O u:1000 g:1000 hello 2.txt
-гw-r--r-- 0 u:0 g:0 hello_1.txt
```

