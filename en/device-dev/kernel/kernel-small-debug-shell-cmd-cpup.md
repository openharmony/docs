# cpup


## Command Function<a name="section1842161614217"></a>

This command is used to query the CPU usage \(CPU percent\) of the system.

## Syntax<a name="section5629527427"></a>

cpup \[_mode_\] \[_taskID_\]

## Parameters<a name="section133651361023"></a>

**Table  1**  Parameter description

<a name="table3774mcpsimp"></a>
<table><thead align="left"><tr id="row3780mcpsimp"><th class="cellrowborder" valign="top" width="16%" id="mcps1.2.4.1.1"><p id="p3782mcpsimp"><a name="p3782mcpsimp"></a><a name="p3782mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="56.99999999999999%" id="mcps1.2.4.1.2"><p id="p3784mcpsimp"><a name="p3784mcpsimp"></a><a name="p3784mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p3786mcpsimp"><a name="p3786mcpsimp"></a><a name="p3786mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row3787mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.4.1.1 "><p id="p3789mcpsimp"><a name="p3789mcpsimp"></a><a name="p3789mcpsimp"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="56.99999999999999%" headers="mcps1.2.4.1.2 "><a name="ul1530071303413"></a><a name="ul1530071303413"></a><ul id="ul1530071303413"><li>Displays the CPU usage of the system within the last 10 seconds by default.</li><li><strong id="b13709113084810"><a name="b13709113084810"></a><a name="b13709113084810"></a>0</strong>: displays the CPU usage within the last 10 seconds.</li><li><strong id="b10788133319480"><a name="b10788133319480"></a><a name="b10788133319480"></a>1</strong>: displays the CPU usage within the last 1 second.</li><li>Other value: displays the total CPU usage since the system is started.</li></ul>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p3794mcpsimp"><a name="p3794mcpsimp"></a><a name="p3794mcpsimp"></a>[0,0xFFFFFFFF]</p>
</td>
</tr>
<tr id="row3795mcpsimp"><td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.4.1.1 "><p id="p3797mcpsimp"><a name="p3797mcpsimp"></a><a name="p3797mcpsimp"></a>taskID</p>
</td>
<td class="cellrowborder" valign="top" width="56.99999999999999%" headers="mcps1.2.4.1.2 "><p id="p3799mcpsimp"><a name="p3799mcpsimp"></a><a name="p3799mcpsimp"></a>Specifies the task ID.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p3802mcpsimp"><a name="p3802mcpsimp"></a><a name="p3802mcpsimp"></a>[0,0xFFFFFFFF]</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section156611948521"></a>

-   If no parameter is specified, the CPU usage of the system within the last 10 seconds is displayed.
-   If only  **mode**  is specified, the CPU usage within the specified period is displayed.
-   If both  **mode**  and  **taskID**  are specified, the CPU usage of the specified task within the given period is displayed.

## Example<a name="section68501605319"></a>

Run  **cpup 1 5**.

## Output<a name="section19871522144219"></a>

CPU usage of task 5 in the last one second:

```
OHOS # cpup 1 5pid 5 

CpuUsage in 1s: 0.0
```

