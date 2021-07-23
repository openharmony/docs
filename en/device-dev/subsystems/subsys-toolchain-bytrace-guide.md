# bytrace Usage Guidelines<a name="EN-US_TOPIC_0000001083359811"></a>

-   [Overview](#section11388623181619)
-   [How to Develop](#section1595564317164)
-   [Usage Example](#section667273201818)

## Overview<a name="section11388623181619"></a>

bytrace is a tool for you to trace processes and analyze performance. It encapsulates and extends the kernel ftrace and supports event tracking in the user space. With bytrace, you can open a user-space or kernel-space label you want to view \(run the  **bytrace -l**  command to query all the supported labels\) and run the  **--trace\_begin**  and  **-o filename**  \(or  **--output filename**\) commands to capture traces and dump them to a specified file.

## How to Develop<a name="section1595564317164"></a>

bytrace supports the following commands:

**Table  1**  Commands

<a name="table16802195914247"></a>
<table><thead align="left"><tr id="row14804759142412"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1280465972411"><a name="p1280465972411"></a><a name="p1280465972411"></a>Option</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p380414595249"><a name="p380414595249"></a><a name="p380414595249"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1714512123414"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1915412133419"><a name="p1915412133419"></a><a name="p1915412133419"></a>-h, --help</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p6156126341"><a name="p6156126341"></a><a name="p6156126341"></a>Views the help text for bytrace.</p>
</td>
</tr>
<tr id="row13804135982416"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p18051959152410"><a name="p18051959152410"></a><a name="p18051959152410"></a>-b <em id="i35979186184"><a name="i35979186184"></a><a name="i35979186184"></a>n</em>, --buffer_size <em id="i144491624181811"><a name="i144491624181811"></a><a name="i144491624181811"></a>n</em></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p0805165932419"><a name="p0805165932419"></a><a name="p0805165932419"></a>Sets the size of the buffer (KB) for storing and reading traces. The default buffer size is 2048 KB.</p>
</td>
</tr>
<tr id="row580519592245"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p880510591241"><a name="p880510591241"></a><a name="p880510591241"></a>-t <em id="i8668143912203"><a name="i8668143912203"></a><a name="i8668143912203"></a>n</em>, --time <em id="i841433614202"><a name="i841433614202"></a><a name="i841433614202"></a>n</em></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1480517591245"><a name="p1480517591245"></a><a name="p1480517591245"></a>Sets the bytrace uptime in seconds, which depends on the time required for analysis.</p>
</td>
</tr>
<tr id="row4806175913247"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p980655912242"><a name="p980655912242"></a><a name="p980655912242"></a>--trace_clock <em id="i19464452217"><a name="i19464452217"></a><a name="i19464452217"></a>clock</em></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p11806959142416"><a name="p11806959142416"></a><a name="p11806959142416"></a>Sets the type of the clock for adding a timestamp to a trace, which can be <strong id="b13396101413368"><a name="b13396101413368"></a><a name="b13396101413368"></a>boot</strong> (default), <strong id="b14612918183619"><a name="b14612918183619"></a><a name="b14612918183619"></a>global</strong>, <strong id="b045562173610"><a name="b045562173610"></a><a name="b045562173610"></a>mono</strong>, <strong id="b1132132453612"><a name="b1132132453612"></a><a name="b1132132453612"></a>uptime</strong>, or <strong id="b9888326133616"><a name="b9888326133616"></a><a name="b9888326133616"></a>perf</strong>.</p>
</td>
</tr>
<tr id="row1280635917242"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p180715591244"><a name="p180715591244"></a><a name="p180715591244"></a>--trace_begin</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p480795916243"><a name="p480795916243"></a><a name="p480795916243"></a>Starts capturing traces.</p>
</td>
</tr>
<tr id="row1580717599245"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p38073598242"><a name="p38073598242"></a><a name="p38073598242"></a>--trace_dump</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p148077595245"><a name="p148077595245"></a><a name="p148077595245"></a>Dumps traces to a specified position (console where you run this command by default).</p>
</td>
</tr>
<tr id="row180811592242"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11808165922419"><a name="p11808165922419"></a><a name="p11808165922419"></a>--trace_finish</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p18809559182420"><a name="p18809559182420"></a><a name="p18809559182420"></a>Stops capturing traces and dumps traces to a specified position (console where you run this command by default).</p>
</td>
</tr>
<tr id="row2809185972420"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2080925922418"><a name="p2080925922418"></a><a name="p2080925922418"></a>-l, --list_categories</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p38091159142414"><a name="p38091159142414"></a><a name="p38091159142414"></a>Lists the bytrace categories supported by the device.</p>
</td>
</tr>
<tr id="row1880912598248"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1681014595244"><a name="p1681014595244"></a><a name="p1681014595244"></a>--overwrite</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p12810165914248"><a name="p12810165914248"></a><a name="p12810165914248"></a>Sets the action to take when the buffer is full. If this option is used, the latest traces are discarded; if this option is not used, the earliest traces are discarded (default).</p>
</td>
</tr>
<tr id="row1181015992414"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p168101859152415"><a name="p168101859152415"></a><a name="p168101859152415"></a>-o <em id="i1367232742113"><a name="i1367232742113"></a><a name="i1367232742113"></a>filename</em>, --output <em id="i4305133012219"><a name="i4305133012219"></a><a name="i4305133012219"></a>filename</em></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p9810559132410"><a name="p9810559132410"></a><a name="p9810559132410"></a>Outputs traces to a specified file.</p>
</td>
</tr>
<tr id="row8810155982415"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p381145912410"><a name="p381145912410"></a><a name="p381145912410"></a>-z</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1281117592249"><a name="p1281117592249"></a><a name="p1281117592249"></a>Compresses a captured trace.</p>
</td>
</tr>
</tbody>
</table>

## Usage Example<a name="section667273201818"></a>

The following are some examples of bytrace commands:

-   Run the following command to query supported labels:

```
bytrace -l  
```

Alternatively, you can run the following command:

```
bytrace --list_categories
```

-   Run the following command to capture traces whose label is ability, with the buffer size set to 4096 KB and bytrace uptime set to 10s:

```
bytrace -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

-   Run the following command to set the clock type for traces to  **mono**:

```
bytrace --trace_clock mono -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

-   Run the following command to compress the captured trace:

```
bytrace -z -b 4096 -t 10 --overwrite ability > /data/mytrace.ftrace
```

