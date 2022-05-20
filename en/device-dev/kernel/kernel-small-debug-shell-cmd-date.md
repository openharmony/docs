# date

## Command Function<a name="section56472016338"></a>

This command is used to query the system date and time.

## Syntax<a name="section16635112512316"></a>

-   date
-   date --help
-   date +\[_Format_\]
-   date -u

## Parameters<a name="section15896030039"></a>

**Table  1**  Parameter description

<a name="table3825mcpsimp"></a>
<table><thead align="left"><tr id="row3831mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p3833mcpsimp"><a name="p3833mcpsimp"></a><a name="p3833mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.4.1.2"><p id="p3835mcpsimp"><a name="p3835mcpsimp"></a><a name="p3835mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="28.999999999999996%" id="mcps1.2.4.1.3"><p id="p3837mcpsimp"><a name="p3837mcpsimp"></a><a name="p3837mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row14667120409"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p5628123402"><a name="p5628123402"></a><a name="p5628123402"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.4.1.2 "><p id="p1162201234017"><a name="p1162201234017"></a><a name="p1162201234017"></a>Displays help information.</p>
</td>
<td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.4.1.3 "><p id="p11621412194011"><a name="p11621412194011"></a><a name="p11621412194011"></a>N/A</p>
</td>
</tr>
<tr id="row1566191264014"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p186211254017"><a name="p186211254017"></a><a name="p186211254017"></a>+Format</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.4.1.2 "><p id="p26216124407"><a name="p26216124407"></a><a name="p26216124407"></a>Prints the date and time in the specified <strong id="b115041849185916"><a name="b115041849185916"></a><a name="b115041849185916"></a>Format</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.4.1.3 "><p id="p46251220409"><a name="p46251220409"></a><a name="p46251220409"></a>Placeholders listed in <strong id="b36588246116"><a name="b36588246116"></a><a name="b36588246116"></a>--help</strong></p>
</td>
</tr>
<tr id="row1766111218401"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p146291274011"><a name="p146291274011"></a><a name="p146291274011"></a>-u</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.4.1.2 "><p id="p136291219403"><a name="p136291219403"></a><a name="p136291219403"></a>Displays UTC instead of the current time zone.</p>
</td>
<td class="cellrowborder" valign="top" width="28.999999999999996%" headers="mcps1.2.4.1.3 "><p id="p5628129407"><a name="p5628129407"></a><a name="p5628129407"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section116361036636"></a>

-   If no parameter is specified, the system UTC date and time are displayed by default.
-   The  **--help**,  **+Format**, and  **-u**  parameters are mutually exclusive.
-   Currently, this command cannot be used to set the time or date.

## Example<a name="section021711411237"></a>

Run  **date +%Y--%m--%d**.

## Output<a name="section17950184414312"></a>

System date in the specified format:

```
OHOS:/$ date +%Y--%m--%d
1970--01--01
```

