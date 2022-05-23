# oom

## Command Function<a name="section366714216619"></a>

This command is used to query and set the low memory threshold and the PageCache reclaim threshold.

## Syntax<a name="section8833164614615"></a>

oom

oom -i \[_interval_\]

oom -m \[_mem byte_\]

oom -r \[_mem byte_\]

oom -h | --help

## Parameters<a name="section12809111019453"></a>

**Table  1**  Parameter description

<a name="table438mcpsimp"></a>
<table><thead align="left"><tr id="row444mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p446mcpsimp"><a name="p446mcpsimp"></a><a name="p446mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p448mcpsimp"><a name="p448mcpsimp"></a><a name="p448mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p450mcpsimp"><a name="p450mcpsimp"></a><a name="p450mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p5196112612119"><a name="p5196112612119"></a><a name="p5196112612119"></a>-i [interval]</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>Sets the interval (in ms) for checking the Out Of Memory (OOM) thread task.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>100 to 10000</p>
</td>
</tr>
<tr id="row18583553793"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p95841853292"><a name="p95841853292"></a><a name="p95841853292"></a>-m [mem byte]</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p2058485315912"><a name="p2058485315912"></a><a name="p2058485315912"></a>Sets the low memory threshold (in MB).</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p1584105318917"><a name="p1584105318917"></a><a name="p1584105318917"></a>0 (disables the low memory check) to 1</p>
</td>
</tr>
<tr id="row17926124131218"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p49266245128"><a name="p49266245128"></a><a name="p49266245128"></a>-r [mem byte]</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p159263241121"><a name="p159263241121"></a><a name="p159263241121"></a>Sets the PageCache reclaim threshold.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p692642412121"><a name="p692642412121"></a><a name="p692642412121"></a>Ranging from the low memory threshold to the maximum available system memory</p>
</td>
</tr>
<tr id="row1176110379557"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p4762113745519"><a name="p4762113745519"></a><a name="p4762113745519"></a>-h | --help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p9762113775517"><a name="p9762113775517"></a><a name="p9762113775517"></a>Displays help information.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p7762133765511"><a name="p7762133765511"></a><a name="p7762133765511"></a>N/A</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section15935131220717"></a>

If no parameter is specified, this command displays the current OOM configuration.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>If the system memory is insufficient, the system displays a message indicating the insufficiency.

## Example<a name="section387104374416"></a>

Run the following commands:

-   oom
-   oom -i 100

## Output<a name="section12742311179"></a>

Example 1: displaying OOM configuration

```
OHOS:/$ oom
[oom] oom loop task status: enabled
      oom low memory threshold: 0x80000(byte)
      oom reclaim memory threshold: 0x500000(byte)
      oom check interval: 100(microsecond)
```

Information displayed when the system memory is insufficient:

```
T:20 Enter:IT MEM 00M 001
[oom] OS is in low memory state
total physical memory: 0x1bcf000(byte), used: 0x1b50000(byte) ,free: 0x7f000(byte), low memory threshold: 0x80000(byte)
[oom] candidate victim process init pid: 1, actual phy mem byte:82602
[oom] candidate victim process shell pid: 3, actual phy mem byte:14950e
[oom] candidate victim process testsuits app pid: 4, actual phy mem byte:1334598
[oom] candidate victim process UserProcess12 pid: 12, actual phy mem byte:25951558
[oom] max phy mem used process UserProcess12 pid: 12, actual phy mem 25951558
################excFrom: User!####################
data abort fsr:0x817, far:0x225af000
Abort caused by a write instruction. Translation fault, page
excType: data abort
processName    = UserProcess12
processID      = 12
process aspace = 0х01000000 -> 0х3f000000
taskName       = threado
taskID         = 22
task user stack = 0х20e17000 -> 0х20e21000
pc   = 0x93969dc in /usr/bin/testsuits app ---> 0x19f9dc
ulr  = 0x93969cc in /usr/bin/testsuits app ---> 0x19f9cc
usp  = 0х20e20c68fp = 0x20e20c8c
R0   = 0х20e35000
R1   = 0x225af000
R2   = 0x0
R3   = 0х28e35000
R4   = 0х0
R5   = 0х9500000
R6   = 0х14
R7   = 0х97822c4
R8   = 0x970cfa8
R9   = 0x9090909
R10  = 0xa0a0a0a
R11  = 0x20e20c8c
R12  = 0х0
CPSR = 0х80000010
*******backtrace beain*******
traceback 0 -- lr = 0x9242e1c fp = 0х20e20cc4 lr in /usr/bin/testsuits apr 0x4be1c
traceback 1 -- 1r = 0х92430cc fp = 0x20e20cdc lr in /usr/bin/testsuits app --> 0x4c0cc
traceback 2 -- 1r = 0x9396ab0 fp = 0x20e20cec lr in /usr/bin/testsuits app -> 0х19fab0
traceback 3 -- lr = 0x9393eb4 fp = 0x20e20cf4 lr in /usr/bin/testsuits ap --> 0x19ceb4
traceback 4 -- lr = 0x92427d4 fp = 0x20e20d44 lr in /usr/bin/testsuits app --> 0x4b7d4
traceback 5 -- 1r = 0x20c4df50 fp = 0хb0b0b0b 1r in /1ib/libc.so - -> 0x62f50
```

Example 2: setting the OOM check interval to 100 ms

```
OHOS:/$ oom -i 100
[oom] set oom check interval (100)ms successful
```

**Table  2**  Output

<a name="table487mcpsimp"></a>
<table><thead align="left"><tr id="row492mcpsimp"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p494mcpsimp"><a name="p494mcpsimp"></a><a name="p494mcpsimp"></a>Output</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p496mcpsimp"><a name="p496mcpsimp"></a><a name="p496mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row502mcpsimp"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p583513382179"><a name="p583513382179"></a><a name="p583513382179"></a>[oom] OS is in low memory state</p>
<p id="p636114453553"><a name="p636114453553"></a><a name="p636114453553"></a>total physical memory: 0x1bcf000(byte), used: 0x1b50000(byte), free: 0x7f000(byte), low memory threshold: 0x80000(byte)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p19833143819174"><a name="p19833143819174"></a><a name="p19833143819174"></a>The operating system has low memory.</p>
<p id="p83883291587"><a name="p83883291587"></a><a name="p83883291587"></a>The available physical memory in the operating system is <strong id="b15343050123397"><a name="b15343050123397"></a><a name="b15343050123397"></a>0x1bcf000</strong> bytes, <strong id="b18697901323397"><a name="b18697901323397"></a><a name="b18697901323397"></a>0x1b50000</strong> bytes have been used, and <strong id="b3252944373397"><a name="b3252944373397"></a><a name="b3252944373397"></a>0x7f000</strong> bytes are available. The current low memory threshold is <strong id="b13811086363397"><a name="b13811086363397"></a><a name="b13811086363397"></a>0x80000</strong> bytes.</p>
</td>
</tr>
<tr id="row1990234224612"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p3902144294612"><a name="p3902144294612"></a><a name="p3902144294612"></a>[oom] candidate victim process init pid: 1, actual phy mem byte: 82602</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p13903144284610"><a name="p13903144284610"></a><a name="p13903144284610"></a>Memory usage of each process. The physical memory occupied by the <strong id="b143686319910"><a name="b143686319910"></a><a name="b143686319910"></a>init</strong> process is 82602 bytes.</p>
</td>
</tr>
<tr id="row520212272335"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p172038278339"><a name="p172038278339"></a><a name="p172038278339"></a>[oom] candidate victim process UserProcess12 pid: 12, actual phy mem byte: 25951558</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p112034276331"><a name="p112034276331"></a><a name="p112034276331"></a>The actual memory used by the <strong id="b16405477923397"><a name="b16405477923397"></a><a name="b16405477923397"></a>UserProcess12</strong> process is <strong id="b10952024983397"><a name="b10952024983397"></a><a name="b10952024983397"></a>25951558</strong> bytes.</p>
</td>
</tr>
<tr id="row3273195033416"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p184989213512"><a name="p184989213512"></a><a name="p184989213512"></a>[oom] max phy mem used process UserProcess12 pid: 12, actual phy mem: 25951558</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p112741750143417"><a name="p112741750143417"></a><a name="p112741750143417"></a>The process that uses the most memory currently is <strong id="b17770979863397"><a name="b17770979863397"></a><a name="b17770979863397"></a>UserProcess12</strong>.</p>
</td>
</tr>
<tr id="row16442089365"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p045148153618"><a name="p045148153618"></a><a name="p045148153618"></a>excFrom: User!</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p6452818367"><a name="p6452818367"></a><a name="p6452818367"></a>The system memory is low, and the <strong id="b4088490143397"><a name="b4088490143397"></a><a name="b4088490143397"></a>UserProcess12</strong> process fails to apply for memory and exits.</p>
</td>
</tr>
</tbody>
</table>

