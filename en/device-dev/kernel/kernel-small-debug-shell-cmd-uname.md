# uname

## Command Function<a name="section107697383115"></a>

This command is used to display the name, version creation time, system name, and version information of the current operating system.

## Syntax<a name="section162824341116"></a>

uname \[_-a | -s | -r | -m | -n | -v | --help_\]

**Table  1**  Parameters

<a name="table909mcpsimp"></a>
<table><thead align="left"><tr id="row914mcpsimp"><th class="cellrowborder" valign="top" width="33.989999999999995%" id="mcps1.2.3.1.1"><p id="p916mcpsimp"><a name="p916mcpsimp"></a><a name="p916mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="66.01%" id="mcps1.2.3.1.2"><p id="p918mcpsimp"><a name="p918mcpsimp"></a><a name="p918mcpsimp"></a>Parameters</p>
</th>
</tr>
</thead>
<tbody><tr id="row7659172561412"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p9648112519147"><a name="p9648112519147"></a><a name="p9648112519147"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p1664862551411"><a name="p1664862551411"></a><a name="p1664862551411"></a>Displays help information.</p>
</td>
</tr>
<tr id="row365962510147"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p26489259149"><a name="p26489259149"></a><a name="p26489259149"></a>No parameter</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p186484252141"><a name="p186484252141"></a><a name="p186484252141"></a>Displays the operating system name by default.</p>
</td>
</tr>
<tr id="row12659142511413"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p156481253140"><a name="p156481253140"></a><a name="p156481253140"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p864872512145"><a name="p864872512145"></a><a name="p864872512145"></a>Displays all information.</p>
</td>
</tr>
<tr id="row365917254143"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p136481625131417"><a name="p136481625131417"></a><a name="p136481625131417"></a>-s</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p1064852514149"><a name="p1064852514149"></a><a name="p1064852514149"></a>Displays the operating system name.</p>
</td>
</tr>
<tr id="row196591425101413"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p364814255144"><a name="p364814255144"></a><a name="p364814255144"></a>-r</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p1564872515145"><a name="p1564872515145"></a><a name="p1564872515145"></a>Displays the kernel release version.</p>
</td>
</tr>
<tr id="row10659202591419"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p11648162520146"><a name="p11648162520146"></a><a name="p11648162520146"></a>-m</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p136489251143"><a name="p136489251143"></a><a name="p136489251143"></a>Displays the operating system architecture name.</p>
</td>
</tr>
<tr id="row126582025111417"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p13648102551411"><a name="p13648102551411"></a><a name="p13648102551411"></a>-n</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p6648132512141"><a name="p6648132512141"></a><a name="p6648132512141"></a>Displays the network domain name of the host.</p>
</td>
</tr>
<tr id="row3658925151415"><td class="cellrowborder" valign="top" width="33.989999999999995%" headers="mcps1.2.3.1.1 "><p id="p9648152501414"><a name="p9648152501414"></a><a name="p9648152501414"></a>-v</p>
</td>
<td class="cellrowborder" valign="top" width="66.01%" headers="mcps1.2.3.1.2 "><p id="p46489250149"><a name="p46489250149"></a><a name="p46489250149"></a>Displays version information.</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section2652124861114"></a>

-   The  **uname**  command displays the name of the current operating system by default.
-   Except  **--help**  and  **-a**, other parameters can be used together.  **uname -a**  is equivalent to  **uname -srmnv**.

## Example<a name="section0107995132"></a>

Run the following commands:

-   uname -a
-   uname -ms

## Output<a name="section1215113245511"></a>

Example 1: all information of the operating system

```
OHOS:/$ uname -a
LiteOS hisilicon  _IP Address_  Huawei LiteOS _IP Address_  Oct 21 2021 17:39:32 Cortex-A7
OHOS:/$
```

Example 2: operating system name and architecture

```
OHOS:/$ uname -ms
LiteOS Cortex-A7
OHOS:/$
```

