# swtmr


## Command Function<a name="section166171064814"></a>

This command is used to query information about system software timers.

## Syntax<a name="section424011111682"></a>

swtmr \[_ID_\]

## Parameters<a name="section1268410459465"></a>

**Table  1**  Parameter description

<a name="table517mcpsimp"></a>
<table><thead align="left"><tr id="row523mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p525mcpsimp"><a name="p525mcpsimp"></a><a name="p525mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p527mcpsimp"><a name="p527mcpsimp"></a><a name="p527mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p529mcpsimp"><a name="p529mcpsimp"></a><a name="p529mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row530mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p532mcpsimp"><a name="p532mcpsimp"></a><a name="p532mcpsimp"></a>ID</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p534mcpsimp"><a name="p534mcpsimp"></a><a name="p534mcpsimp"></a>Specifies the ID of a software timer.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p536mcpsimp"><a name="p536mcpsimp"></a><a name="p536mcpsimp"></a>[0,0xFFFFFFFF]</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section169806213815"></a>

-   If no parameter is specified, information about all software timers is displayed.
-   If the  **ID**  parameter is specified, information about the specified software timer is displayed.

## Example<a name="section16676026389"></a>

Run the following commands:

-   swtmr
-   swtmr 1

## Output<a name="section1541991614710"></a>

Example 1: information about all software timers

```
OHOS # swtmr
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000000  Ticking  Period   100      77      0x40802a50  0x4037b8a0
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000001  Ticking  Period   1000     876     0x00000000  0x4037fc04
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000002  Ticking  Period   100      76      0x00000000  0x403727f4
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000016  Ticking  NSD      10       6       0x8021e000  0x401fe7d8
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000079  Ticking  NSD      30000    1749    0x406189d8  0x40160e1c
```

Example 2: information about software timer 1

```
OHOS # swtmr 1
SwTmrID     State    Mode    Interval  Count   Arg         handlerAddr
----------  -------  ------- --------- ------- ----------  --------
0x00000001  Ticking  Period   1000     841     0x00000000  0x4037fc04
```

**Table  2**  Output

<a name="table551mcpsimp"></a>
<table><thead align="left"><tr id="row556mcpsimp"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p558mcpsimp"><a name="p558mcpsimp"></a><a name="p558mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p560mcpsimp"><a name="p560mcpsimp"></a><a name="p560mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row561mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p563mcpsimp"><a name="p563mcpsimp"></a><a name="p563mcpsimp"></a>SwTmrID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p565mcpsimp"><a name="p565mcpsimp"></a><a name="p565mcpsimp"></a>ID of the software timer</p>
</td>
</tr>
<tr id="row566mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p568mcpsimp"><a name="p568mcpsimp"></a><a name="p568mcpsimp"></a>State</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p570mcpsimp"><a name="p570mcpsimp"></a><a name="p570mcpsimp"></a>Status of the software timer</p>
<p id="p88402543474"><a name="p88402543474"></a><a name="p88402543474"></a>The value can be <strong id="b164905263633836"><a name="b164905263633836"></a><a name="b164905263633836"></a>UnUsed</strong>, <strong id="b138979237833836"><a name="b138979237833836"></a><a name="b138979237833836"></a>Created</strong>, or <strong id="b3849463233836"><a name="b3849463233836"></a><a name="b3849463233836"></a>Ticking</strong>.</p>
</td>
</tr>
<tr id="row571mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p573mcpsimp"><a name="p573mcpsimp"></a><a name="p573mcpsimp"></a>Mode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p575mcpsimp"><a name="p575mcpsimp"></a><a name="p575mcpsimp"></a>Mode of the software timer</p>
<p id="p657320204499"><a name="p657320204499"></a><a name="p657320204499"></a>The value can be <strong id="b201632419733836"><a name="b201632419733836"></a><a name="b201632419733836"></a>Once</strong>, <strong id="b45281151733836"><a name="b45281151733836"></a><a name="b45281151733836"></a>Period</strong>, or <strong id="b73443815433836"><a name="b73443815433836"></a><a name="b73443815433836"></a>NSD</strong> (one-shot timer that will not be automatically deleted after the timer has expired).</p>
</td>
</tr>
<tr id="row576mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p578mcpsimp"><a name="p578mcpsimp"></a><a name="p578mcpsimp"></a>Interval</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p580mcpsimp"><a name="p580mcpsimp"></a><a name="p580mcpsimp"></a>Number of ticks for the software timer</p>
</td>
</tr>
<tr id="row581mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p583mcpsimp"><a name="p583mcpsimp"></a><a name="p583mcpsimp"></a>Count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p585mcpsimp"><a name="p585mcpsimp"></a><a name="p585mcpsimp"></a>Number of times that the software timer has been used</p>
</td>
</tr>
<tr id="row586mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p588mcpsimp"><a name="p588mcpsimp"></a><a name="p588mcpsimp"></a>Arg</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p590mcpsimp"><a name="p590mcpsimp"></a><a name="p590mcpsimp"></a>Input parameter</p>
</td>
</tr>
<tr id="row591mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p593mcpsimp"><a name="p593mcpsimp"></a><a name="p593mcpsimp"></a>handlerAddr</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p595mcpsimp"><a name="p595mcpsimp"></a><a name="p595mcpsimp"></a>Address of the callback</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The  **ID**  value can be in decimal or hexadecimal format.
>-   If the  **ID**  value is within the range of \[0,  _Number of current software timers - 1_\], the status of the specified software timer is returned. For other values, an error message is displayed.

