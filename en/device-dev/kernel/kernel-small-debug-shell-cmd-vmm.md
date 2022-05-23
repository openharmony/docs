# vmm

## Command Function<a name="section445335110416"></a>

This command is used to query the virtual memory used by a process.

## Syntax<a name="section1795712553416"></a>

-   vmm \[_-a / -h / --help_\]
-   vmm \[_pid_\]

## Parameters<a name="section92544592410"></a>

**Table  1**  Parameter description

<a name="table3900mcpsimp"></a>
<table><thead align="left"><tr id="row3906mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p3908mcpsimp"><a name="p3908mcpsimp"></a><a name="p3908mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52%" id="mcps1.2.4.1.2"><p id="p3910mcpsimp"><a name="p3910mcpsimp"></a><a name="p3910mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="27%" id="mcps1.2.4.1.3"><p id="p3912mcpsimp"><a name="p3912mcpsimp"></a><a name="p3912mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row3913mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p17944444181717"><a name="p17944444181717"></a><a name="p17944444181717"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p209441344121716"><a name="p209441344121716"></a><a name="p209441344121716"></a>Displays the virtual memory usage of all processes.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p3919mcpsimp"><a name="p3919mcpsimp"></a><a name="p3919mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row3920mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1944124412171"><a name="p1944124412171"></a><a name="p1944124412171"></a>-h | --help</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1494494441713"><a name="p1494494441713"></a><a name="p1494494441713"></a>Displays help information.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p3926mcpsimp"><a name="p3926mcpsimp"></a><a name="p3926mcpsimp"></a>N/A</p>
</td>
</tr>
<tr id="row3934mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p5945444181720"><a name="p5945444181720"></a><a name="p5945444181720"></a>pid</p>
</td>
<td class="cellrowborder" valign="top" width="52%" headers="mcps1.2.4.1.2 "><p id="p1594515442177"><a name="p1594515442177"></a><a name="p1594515442177"></a>Specifies the ID of the process to query.</p>
</td>
<td class="cellrowborder" valign="top" width="27%" headers="mcps1.2.4.1.3 "><p id="p3940mcpsimp"><a name="p3940mcpsimp"></a><a name="p3940mcpsimp"></a>[0,63]</p>
</td>
</tr>
</tbody>
</table>

## Usage<a name="section104151141252"></a>

By default, this command displays the virtual memory usage of all processes.

## Example<a name="section11545171957"></a>

Run  **vmm 3**.

## Output<a name="section075617368542"></a>

Virtual memory usage of process 3:

```
OHOS # vmm 3
 PID    aspace     name       base       size     pages
 ----   ------     ----       ----       -----     ----
 3    0x408c0118 foundation 0x01000000 0x3e000000     800
         region      name                base       size       mmu_flags      pages   pg/ref
         ------      ----                ----       ----       ---------      -----   -----
         0x408cb364  /bin/foundation                  0x06da3000 0x00001000  CH US RD          1       1
         0x408cb80c  /bin/foundation                  0x06da4000 0x00001000  CH US RD EX       1       1
         0x408cb720  /bin/foundation                  0x06da5000 0x00001000  CH US RD          1       1
         0x408cb9a8  /bin/foundation                  0x06da6000 0x00001000  CH US RD WR       1       1
         0x413efde4  HEAP                             0x12b43000 0x00015000  CH US RD WR      19      19
         0x408c3d34  /lib/libc.so                     0x23b08000 0x0004a000  CH US RD         25       2
         0x408cbd44  /lib/libc.so                     0x23b52000 0x00068000  CH US RD EX      58      10
         0x408c3dc0  /lib/libc.so                     0x23bba000 0x00002000  CH US RD WR       2       2
         0x408cc128  /lib/libc.so                     0x23bbc000 0x00002000  CH US RD WR       2       2
         0x408d1634  MMAP                             0x23bbe000 0x00005000  CH US RD WR       5       5
         0x408c4e10  VDSO                             0x23bc3000 0x00002000  CH US RD EX       2       2
         0x408dbaec  /lib/libc++.so                   0x23bc5000 0x00046000  CH US RD         51       5
         0x408deba8  /lib/libc++.so                   0x23c0b000 0x0009f000  CH US RD EX      29      10
         0x408debf4  /lib/libc++.so                   0x23caa000 0x00006000  CH US RD          6       6
         0x408c3ce0  /lib/libc++.so                   0x23cb0000 0x00001000  CH US RD WR       1       1
```

**Table  2**  Basic process information

<a name="table17136143042317"></a>
<table><thead align="left"><tr id="row1113611307232"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p17137173017232"><a name="p17137173017232"></a><a name="p17137173017232"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p171371302230"><a name="p171371302230"></a><a name="p171371302230"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row11371230202317"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p0137630122313"><a name="p0137630122313"></a><a name="p0137630122313"></a>PID</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p513793016233"><a name="p513793016233"></a><a name="p513793016233"></a>Process ID</p>
</td>
</tr>
<tr id="row61371630112315"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p18137133019236"><a name="p18137133019236"></a><a name="p18137133019236"></a>aspace</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p9137130122311"><a name="p9137130122311"></a><a name="p9137130122311"></a>Address of the virtual memory control block</p>
</td>
</tr>
<tr id="row613793015232"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12137230172311"><a name="p12137230172311"></a><a name="p12137230172311"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p19137193018235"><a name="p19137193018235"></a><a name="p19137193018235"></a>Process name</p>
</td>
</tr>
<tr id="row1613763019237"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1413723015233"><a name="p1413723015233"></a><a name="p1413723015233"></a>base</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1613783082319"><a name="p1613783082319"></a><a name="p1613783082319"></a>Start address of the virtual memory</p>
</td>
</tr>
<tr id="row141376308237"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p101371730162319"><a name="p101371730162319"></a><a name="p101371730162319"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p18137143092313"><a name="p18137143092313"></a><a name="p18137143092313"></a>Size of virtual memory</p>
</td>
</tr>
<tr id="row19137163072316"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16137183013235"><a name="p16137183013235"></a><a name="p16137183013235"></a>pages</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p5137130142314"><a name="p5137130142314"></a><a name="p5137130142314"></a>Number of used physical pages</p>
</td>
</tr>
</tbody>
</table>

**Table  3**  Virtual memory region information

<a name="table1195314682418"></a>
<table><thead align="left"><tr id="row14953144632413"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1195314617242"><a name="p1195314617242"></a><a name="p1195314617242"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p13953174614243"><a name="p13953174614243"></a><a name="p13953174614243"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18953114610242"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p09531746132417"><a name="p09531746132417"></a><a name="p09531746132417"></a>region</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1795344642412"><a name="p1795344642412"></a><a name="p1795344642412"></a>Address of the control block in the virtual memory region</p>
</td>
</tr>
<tr id="row1795384682411"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p199531846112417"><a name="p199531846112417"></a><a name="p199531846112417"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p19539466245"><a name="p19539466245"></a><a name="p19539466245"></a>Name of the virtual memory region</p>
</td>
</tr>
<tr id="row99531446132410"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p139531946132417"><a name="p139531946132417"></a><a name="p139531946132417"></a>base</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p139536468242"><a name="p139536468242"></a><a name="p139536468242"></a>Start address of the virtual memory region</p>
</td>
</tr>
<tr id="row79531046122418"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11953546102418"><a name="p11953546102418"></a><a name="p11953546102418"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p89531246142419"><a name="p89531246142419"></a><a name="p89531246142419"></a>Size of the virtual memory region</p>
</td>
</tr>
<tr id="row1295315464240"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7953154602419"><a name="p7953154602419"></a><a name="p7953154602419"></a>mmu_flags</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p395464620242"><a name="p395464620242"></a><a name="p395464620242"></a>MMU mapping attribute of the virtual memory region</p>
</td>
</tr>
<tr id="row10954154692413"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1195484642410"><a name="p1195484642410"></a><a name="p1195484642410"></a>pages</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p29541546112416"><a name="p29541546112416"></a><a name="p29541546112416"></a>Number of used physical pages, including that of the shared memory</p>
</td>
</tr>
<tr id="row1395411463246"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p14954146152418"><a name="p14954146152418"></a><a name="p14954146152418"></a>pg/ref</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10954164642419"><a name="p10954164642419"></a><a name="p10954164642419"></a>Number of used physical pages</p>
</td>
</tr>
</tbody>
</table>

