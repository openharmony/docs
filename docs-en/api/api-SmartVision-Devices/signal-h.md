# signal.h<a name="EN-US_TOPIC_0000001055707982"></a>

-   [Overview](#section1739101607165629)
-   [Summary](#section1415792769165629)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section1739101607165629"></a>

**Related Modules:**

[IPC](ipc.md)

**Description:**

Provides signal operation functions and structures, including changing the signal processing mode and the process signal mask set. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1415792769165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1909203759165629"></a>
<table><thead align="left"><tr id="row1841914817165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p885879492165629"><a name="p885879492165629"></a><a name="p885879492165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p762905107165629"><a name="p762905107165629"></a><a name="p762905107165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1509091208165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p652761796165629"><a name="p652761796165629"></a><a name="p652761796165629"></a><a href="sigaltstack.md">sigaltstack</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2124446306165629"><a name="p2124446306165629"></a><a name="p2124446306165629"></a>Describes a signal stack. </p>
</td>
</tr>
<tr id="row859577152165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p91203717165629"><a name="p91203717165629"></a><a name="p91203717165629"></a><a href="__ucontext.md">__ucontext</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1562822218165629"><a name="p1562822218165629"></a><a name="p1562822218165629"></a>Describes the user execution context. </p>
</td>
</tr>
<tr id="row554049337165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1154340659165629"><a name="p1154340659165629"></a><a name="p1154340659165629"></a><a href="__sigset_t.md">__sigset_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1174825612165629"><a name="p1174825612165629"></a><a name="p1174825612165629"></a>Defines the data type of a signal set. </p>
</td>
</tr>
<tr id="row638548551165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2109573228165629"><a name="p2109573228165629"></a><a name="p2109573228165629"></a><a href="sigval.md">sigval</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p108243514165629"><a name="p108243514165629"></a><a name="p108243514165629"></a>Describes signal values in different cases. </p>
</td>
</tr>
<tr id="row1598469753165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p920897761165629"><a name="p920897761165629"></a><a name="p920897761165629"></a><a href="__si_fields.md">__si_fields</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1272745244165629"><a name="p1272745244165629"></a><a name="p1272745244165629"></a>Describes signal information. </p>
</td>
</tr>
<tr id="row1568492984165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p385396560165629"><a name="p385396560165629"></a><a name="p385396560165629"></a><a href="sigaction.md">sigaction</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p264536070165629"><a name="p264536070165629"></a><a name="p264536070165629"></a>Describes the signal processing actions and related attributes. </p>
</td>
</tr>
<tr id="row71848234165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1517348643165629"><a name="p1517348643165629"></a><a name="p1517348643165629"></a><a href="sigevent.md">sigevent</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1570738159165629"><a name="p1570738159165629"></a><a name="p1570738159165629"></a>Describes asynchronous notifications. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table902510643165629"></a>
<table><thead align="left"><tr id="row565332225165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p204679004165629"><a name="p204679004165629"></a><a name="p204679004165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2091675995165629"><a name="p2091675995165629"></a><a name="p2091675995165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row402479565165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1679490965165629"><a name="p1679490965165629"></a><a name="p1679490965165629"></a><a href="ipc.md#gaf6a71c97263725437f59ceb16241fd32">SA_NOCLDSTOP</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p955171611165629"><a name="p955171611165629"></a><a name="p955171611165629"></a>Stops a child process without sending the <a href="ipc.md#ga0e63521a64cc8bc2b91d36a87d32c9f8">SIGCHLD</a> signal. </p>
</td>
</tr>
<tr id="row1000862693165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p278985862165629"><a name="p278985862165629"></a><a name="p278985862165629"></a><a href="ipc.md#gae4c1aad864ef72e4a2cce74b1b8a5a0b">SA_NOCLDWAIT</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p159130139165629"><a name="p159130139165629"></a><a name="p159130139165629"></a>Sets the <a href="ipc.md#ga0e63521a64cc8bc2b91d36a87d32c9f8">SIGCHLD</a> flag to prevent zombie processes. </p>
</td>
</tr>
<tr id="row604897062165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1809170530165629"><a name="p1809170530165629"></a><a name="p1809170530165629"></a><a href="ipc.md#ga59b4c0774aace526b10b6d737075a790">SA_SIGINFO</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1200339412165629"><a name="p1200339412165629"></a><a name="p1200339412165629"></a>Transfers the <strong id="b208341718165629"><a name="b208341718165629"></a><a name="b208341718165629"></a>siginfo_t</strong> structure with the signal. </p>
</td>
</tr>
<tr id="row1260170828165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1149878068165629"><a name="p1149878068165629"></a><a name="p1149878068165629"></a><a href="ipc.md#ga322c220e296393958ab4238145a0d273">SA_ONSTACK</a>   0x08000000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p113181160165629"><a name="p113181160165629"></a><a name="p113181160165629"></a>Uses the signal stack specified by <a href="sigaltstack.md">sigaltstack</a> for signal processing. </p>
</td>
</tr>
<tr id="row1867753797165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1782543941165629"><a name="p1782543941165629"></a><a name="p1782543941165629"></a><a href="ipc.md#ga74ef0a27afcf55b6cd6d35cf0fa5d427">SA_RESTART</a>   0x10000000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p511225583165629"><a name="p511225583165629"></a><a name="p511225583165629"></a>Obtains the restart signal. </p>
</td>
</tr>
<tr id="row1268105220165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p789824541165629"><a name="p789824541165629"></a><a name="p789824541165629"></a><a href="ipc.md#gabec4abd80d73397fc2f78f57f178565f">SA_NODEFER</a>   0x40000000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583134278165629"><a name="p1583134278165629"></a><a name="p1583134278165629"></a>The signals being processed are not masked during signal processing. </p>
</td>
</tr>
<tr id="row662026098165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p219403004165629"><a name="p219403004165629"></a><a name="p219403004165629"></a><a href="ipc.md#ga8d5fb4f35858d31035e7354c1d4048ea">SA_RESETHAND</a>   0x80000000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1250050722165629"><a name="p1250050722165629"></a><a name="p1250050722165629"></a>The default processing mode is restored after the signal processing is complete. </p>
</td>
</tr>
<tr id="row1554597020165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p991000796165629"><a name="p991000796165629"></a><a name="p991000796165629"></a><a href="ipc.md#gaae6a742a8c5acf12caba1d148dd03f10">MINSIGSTKSZ</a>   2048</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p228238674165629"><a name="p228238674165629"></a><a name="p228238674165629"></a>Defines the minimum size of the replaceable signal stack. </p>
</td>
</tr>
<tr id="row230696527165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1236993492165629"><a name="p1236993492165629"></a><a name="p1236993492165629"></a><a href="ipc.md#ga8a433a10420a0c51355da26cfcab2131">SIGSTKSZ</a>   8192</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p266306136165629"><a name="p266306136165629"></a><a name="p266306136165629"></a>Defines the size of a signal stack. </p>
</td>
</tr>
<tr id="row1392315689165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2035077168165629"><a name="p2035077168165629"></a><a name="p2035077168165629"></a><a href="ipc.md#ga275020780cb70a8b0cba8db5accc5d19">_NSIG</a>   65</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1628639659165629"><a name="p1628639659165629"></a><a name="p1628639659165629"></a>Number of supported signals. </p>
</td>
</tr>
<tr id="row853856031165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080425785165629"><a name="p2080425785165629"></a><a name="p2080425785165629"></a><a href="ipc.md#ga15d5d2dce732343eece4e11ac487e003">_NSIG_BPW</a>   <a href="utils.md#ga0bf2a26a1f15f79f80319edbaa5cc9a5">__BITS_PER_LONG</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1205408994165629"><a name="p1205408994165629"></a><a name="p1205408994165629"></a>Number of bits occupied by a word. </p>
</td>
</tr>
<tr id="row1450412959165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p80397420165629"><a name="p80397420165629"></a><a name="p80397420165629"></a><a href="ipc.md#gacd9297a3ab78048b3f46055fc7739c17">_NSIG_WORDS</a>   (<a href="ipc.md#ga275020780cb70a8b0cba8db5accc5d19">_NSIG</a> / <a href="ipc.md#ga15d5d2dce732343eece4e11ac487e003">_NSIG_BPW</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1720705996165629"><a name="p1720705996165629"></a><a name="p1720705996165629"></a>Number of words required by all signals. </p>
</td>
</tr>
<tr id="row1675664001165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p807125889165629"><a name="p807125889165629"></a><a name="p807125889165629"></a><a href="ipc.md#ga136c64ec2d1306de745e39d6aee362ca">SIGHUP</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1007688974165629"><a name="p1007688974165629"></a><a name="p1007688974165629"></a>Hangs up a process. </p>
</td>
</tr>
<tr id="row321933798165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p903870404165629"><a name="p903870404165629"></a><a name="p903870404165629"></a><a href="ipc.md#ga487309e3e9e0527535644115204a639a">SIGINT</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1243713387165629"><a name="p1243713387165629"></a><a name="p1243713387165629"></a>Interrupts a process from keyboard. </p>
</td>
</tr>
<tr id="row843940254165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1306977584165629"><a name="p1306977584165629"></a><a name="p1306977584165629"></a><a href="ipc.md#ga62045b465be11891160d53c10861b16c">SIGQUIT</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1130290412165629"><a name="p1130290412165629"></a><a name="p1130290412165629"></a>Exits a process from keyboard. A core file is generated. </p>
</td>
</tr>
<tr id="row1972634654165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1446340902165629"><a name="p1446340902165629"></a><a name="p1446340902165629"></a><a href="ipc.md#ga4c9c5284f8c8d146bd7a93d25017fc62">SIGILL</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1150806616165629"><a name="p1150806616165629"></a><a name="p1150806616165629"></a>Illegal instruction. </p>
</td>
</tr>
<tr id="row1654364221165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p830332710165629"><a name="p830332710165629"></a><a name="p830332710165629"></a><a href="ipc.md#gaa2beb906ab1b46676e63823f4e773c38">SIGTRAP</a>   5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1535225527165629"><a name="p1535225527165629"></a><a name="p1535225527165629"></a>Breakpoint, used for debugging. </p>
</td>
</tr>
<tr id="row1248003762165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2094879887165629"><a name="p2094879887165629"></a><a name="p2094879887165629"></a><a href="ipc.md#gaa86c630133e5b5174ac970227b273446">SIGABRT</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p647725092165629"><a name="p647725092165629"></a><a name="p647725092165629"></a>Abnormal termination. </p>
</td>
</tr>
<tr id="row1805377725165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p601135053165629"><a name="p601135053165629"></a><a name="p601135053165629"></a><a href="ipc.md#gab12271d5e5911f8a85dc7c3f0e2364c7">SIGIOT</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1026619782165629"><a name="p1026619782165629"></a><a name="p1026619782165629"></a>Equivalent to <a href="ipc.md#gaa86c630133e5b5174ac970227b273446">SIGABRT</a>. </p>
</td>
</tr>
<tr id="row1384756526165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1229082462165629"><a name="p1229082462165629"></a><a name="p1229082462165629"></a><a href="ipc.md#gaead3d488474201acf18c4b63d91edc3c">SIGBUS</a>   7</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p391646168165629"><a name="p391646168165629"></a><a name="p391646168165629"></a>Invalid address access. </p>
</td>
</tr>
<tr id="row36122350165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1485127602165629"><a name="p1485127602165629"></a><a name="p1485127602165629"></a><a href="ipc.md#ga7fbba29aec3e4a8daae12935299df92d">SIGFPE</a>   8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1605243741165629"><a name="p1605243741165629"></a><a name="p1605243741165629"></a>Floating-point exceptions. </p>
</td>
</tr>
<tr id="row1076994720165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1732793824165629"><a name="p1732793824165629"></a><a name="p1732793824165629"></a><a href="ipc.md#gaddd8dcd406ce514ab3b4f576a5343d42">SIGKILL</a>   9</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p336930686165629"><a name="p336930686165629"></a><a name="p336930686165629"></a>Forcibly stops a process. </p>
</td>
</tr>
<tr id="row763053792165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1654036565165629"><a name="p1654036565165629"></a><a name="p1654036565165629"></a><a href="ipc.md#ga944a8250e34bfd7991123abd3436d8c0">SIGUSR1</a>   10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1813809773165629"><a name="p1813809773165629"></a><a name="p1813809773165629"></a>User-defined signal 1. </p>
</td>
</tr>
<tr id="row370002541165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1921942083165629"><a name="p1921942083165629"></a><a name="p1921942083165629"></a><a href="ipc.md#gae20b4f7171a09516ea73c9d2745bd596">SIGSEGV</a>   11</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1769019796165629"><a name="p1769019796165629"></a><a name="p1769019796165629"></a>Illegal memory access. </p>
</td>
</tr>
<tr id="row671894040165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p659823301165629"><a name="p659823301165629"></a><a name="p659823301165629"></a><a href="ipc.md#gabaaa61abe503c43481e35e21b0b5a031">SIGUSR2</a>   12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1060650337165629"><a name="p1060650337165629"></a><a name="p1060650337165629"></a>User-defined signal 2. </p>
</td>
</tr>
<tr id="row1189357427165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p147158651165629"><a name="p147158651165629"></a><a name="p147158651165629"></a><a href="ipc.md#ga57e9c8c5fa13bf86bc779a9f6f408b7c">SIGPIPE</a>   13</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1623383127165629"><a name="p1623383127165629"></a><a name="p1623383127165629"></a>The pipe is broken. </p>
</td>
</tr>
<tr id="row1043485098165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1109733900165629"><a name="p1109733900165629"></a><a name="p1109733900165629"></a><a href="ipc.md#gaa6946723c6b7a86ec3c33caaf832840b">SIGALRM</a>   14</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1468025588165629"><a name="p1468025588165629"></a><a name="p1468025588165629"></a>Timer signal. </p>
</td>
</tr>
<tr id="row813788852165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1908255958165629"><a name="p1908255958165629"></a><a name="p1908255958165629"></a><a href="ipc.md#ga682182a5e5f38fd61f4311501e9dac5d">SIGTERM</a>   15</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1319475693165629"><a name="p1319475693165629"></a><a name="p1319475693165629"></a>Termination signal. </p>
</td>
</tr>
<tr id="row2042785894165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p447568190165629"><a name="p447568190165629"></a><a name="p447568190165629"></a><a href="ipc.md#ga03612fcda4ab9671dfa7051e7b666fb6">SIGSTKFLT</a>   16</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1800061798165629"><a name="p1800061798165629"></a><a name="p1800061798165629"></a>Coprocessor stack error. </p>
</td>
</tr>
<tr id="row1755457115165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p68139125165629"><a name="p68139125165629"></a><a name="p68139125165629"></a><a href="ipc.md#ga0e63521a64cc8bc2b91d36a87d32c9f8">SIGCHLD</a>   17</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p879672846165629"><a name="p879672846165629"></a><a name="p879672846165629"></a>Child process terminated or stopped. </p>
</td>
</tr>
<tr id="row1980876987165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1746589563165629"><a name="p1746589563165629"></a><a name="p1746589563165629"></a><a href="ipc.md#ga024f43063003e753afc6cca1acd6e104">SIGCONT</a>   18</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p5947900165629"><a name="p5947900165629"></a><a name="p5947900165629"></a>Resumes a suspended process. </p>
</td>
</tr>
<tr id="row588716265165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1387086026165629"><a name="p1387086026165629"></a><a name="p1387086026165629"></a><a href="ipc.md#ga069e358bc9a864b7dc4fed2440eda14c">SIGSTOP</a>   19</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1497318444165629"><a name="p1497318444165629"></a><a name="p1497318444165629"></a>Suspends a process. </p>
</td>
</tr>
<tr id="row1436625540165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p346337056165629"><a name="p346337056165629"></a><a name="p346337056165629"></a><a href="ipc.md#gabe65c086e01f0d286b7a785a7e3cdd1a">SIGTSTP</a>   20</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p979046388165629"><a name="p979046388165629"></a><a name="p979046388165629"></a>Stops a process by entering the command on the terminal. </p>
</td>
</tr>
<tr id="row669152090165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1427181675165629"><a name="p1427181675165629"></a><a name="p1427181675165629"></a><a href="ipc.md#ga2c146e34a6b5a78dfba41cded3331181">SIGTTIN</a>   21</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p661802185165629"><a name="p661802185165629"></a><a name="p661802185165629"></a>Input required by the background process. </p>
</td>
</tr>
<tr id="row1001309309165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1141595983165629"><a name="p1141595983165629"></a><a name="p1141595983165629"></a><a href="ipc.md#ga782864287613e2c5c030411fa9c5e9b1">SIGTTOU</a>   22</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1800588254165629"><a name="p1800588254165629"></a><a name="p1800588254165629"></a>Output required by the background process. </p>
</td>
</tr>
<tr id="row1856579664165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1685710524165629"><a name="p1685710524165629"></a><a name="p1685710524165629"></a><a href="ipc.md#gad9ff13149e36144a4ea28788948c34dd">SIGURG</a>   23</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1627255697165629"><a name="p1627255697165629"></a><a name="p1627255697165629"></a>Urgent socket condition. </p>
</td>
</tr>
<tr id="row468664711165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1300921667165629"><a name="p1300921667165629"></a><a name="p1300921667165629"></a><a href="ipc.md#ga7265cbba4972503c1c30a2e52a929874">SIGXCPU</a>   24</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p546048098165629"><a name="p546048098165629"></a><a name="p546048098165629"></a>CPU time limit exceeded. </p>
</td>
</tr>
<tr id="row386819269165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168294998165629"><a name="p168294998165629"></a><a name="p168294998165629"></a><a href="ipc.md#ga75440a7aa885a1052dfd3b4393fd9baa">SIGXFSZ</a>   25</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p224015434165629"><a name="p224015434165629"></a><a name="p224015434165629"></a>File size limit exceeded. </p>
</td>
</tr>
<tr id="row24538518165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1776013123165629"><a name="p1776013123165629"></a><a name="p1776013123165629"></a><a href="ipc.md#ga71403d2f5240e409e213060ea3301851">SIGVTALRM</a>   26</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p645486956165629"><a name="p645486956165629"></a><a name="p645486956165629"></a>Virtual timer, used to calculate the CPU occupation time of a process. </p>
</td>
</tr>
<tr id="row497456275165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p988715513165629"><a name="p988715513165629"></a><a name="p988715513165629"></a><a href="ipc.md#gab6bd2a2ff7e58d45965ef257f96dfe65">SIGPROF</a>   27</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p743175785165629"><a name="p743175785165629"></a><a name="p743175785165629"></a>Calculates the CPU time occupied by a process and the system calling time. </p>
</td>
</tr>
<tr id="row1404177304165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1427612027165629"><a name="p1427612027165629"></a><a name="p1427612027165629"></a><a href="ipc.md#ga13ba0e7c4365813312eb4566907bce4f">SIGWINCH</a>   28</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1747350454165629"><a name="p1747350454165629"></a><a name="p1747350454165629"></a>Window size change. </p>
</td>
</tr>
<tr id="row495497641165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1767317392165629"><a name="p1767317392165629"></a><a name="p1767317392165629"></a><a href="ipc.md#ga929c5eace94ce2e099c6fa732450ce86">SIGIO</a>   29</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1574919018165629"><a name="p1574919018165629"></a><a name="p1574919018165629"></a>Input/Output. </p>
</td>
</tr>
<tr id="row1316049867165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1549748929165629"><a name="p1549748929165629"></a><a name="p1549748929165629"></a><a href="ipc.md#ga1614264a836d6a5642554775ef0134d0">SIGPOLL</a>   <a href="ipc.md#ga929c5eace94ce2e099c6fa732450ce86">SIGIO</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1465521294165629"><a name="p1465521294165629"></a><a name="p1465521294165629"></a>Equivalent to <a href="ipc.md#ga929c5eace94ce2e099c6fa732450ce86">SIGIO</a>. </p>
</td>
</tr>
<tr id="row610512673165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p889899193165629"><a name="p889899193165629"></a><a name="p889899193165629"></a><a href="ipc.md#ga633dbd7dca7d839e6af0299bd4713f0a">SIGPWR</a>   30</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p221732521165629"><a name="p221732521165629"></a><a name="p221732521165629"></a>Power failure. </p>
</td>
</tr>
<tr id="row28248125165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p99452969165629"><a name="p99452969165629"></a><a name="p99452969165629"></a><a href="ipc.md#ga8bacf9eb18fd539099c1bb4666c45d60">SIGSYS</a>   31</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1130865590165629"><a name="p1130865590165629"></a><a name="p1130865590165629"></a>Non-existent system call. </p>
</td>
</tr>
<tr id="row1117230525165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1323660103165629"><a name="p1323660103165629"></a><a name="p1323660103165629"></a><a href="ipc.md#ga11e925ada5a97c7bbb6b88de8ed543b4">SIGUNUSED</a>   31</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1336748029165629"><a name="p1336748029165629"></a><a name="p1336748029165629"></a>Equivalent to <a href="ipc.md#ga8bacf9eb18fd539099c1bb4666c45d60">SIGSYS</a>. </p>
</td>
</tr>
<tr id="row1171171282165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1313334934165629"><a name="p1313334934165629"></a><a name="p1313334934165629"></a><a href="ipc.md#gae89f9a1282bd2d1b2a2b310c12ea16a5">SIGRTMIN</a>   32</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p641554593165629"><a name="p641554593165629"></a><a name="p641554593165629"></a>Start of a reliable signal. </p>
</td>
</tr>
<tr id="row725963611165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p800411887165629"><a name="p800411887165629"></a><a name="p800411887165629"></a><a href="ipc.md#ga5336d2c76af22b10373e3dd28fb3b0f0">SIGRTMAX</a>   <a href="ipc.md#ga275020780cb70a8b0cba8db5accc5d19">_NSIG</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1631254576165629"><a name="p1631254576165629"></a><a name="p1631254576165629"></a>End of a reliable signal. </p>
</td>
</tr>
<tr id="row1143470763165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1558824896165629"><a name="p1558824896165629"></a><a name="p1558824896165629"></a><a href="ipc.md#ga93598c2382d6b05a1ff33edd21a1dcd0">SA_THIRTYTWO</a>   0x02000000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1721320408165629"><a name="p1721320408165629"></a><a name="p1721320408165629"></a>Transfers signals in a 32-bit mode even if the task runs in a 26-bit mode. </p>
</td>
</tr>
<tr id="row954497537165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1666817352165629"><a name="p1666817352165629"></a><a name="p1666817352165629"></a><a href="ipc.md#ga43c1d5510c7bedd95c0e4deac99e1729">SA_NOMASK</a>   <a href="ipc.md#gabec4abd80d73397fc2f78f57f178565f">SA_NODEFER</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1054429562165629"><a name="p1054429562165629"></a><a name="p1054429562165629"></a>Signals being processed are not masked during signal processing. </p>
</td>
</tr>
<tr id="row724137129165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p204454140165629"><a name="p204454140165629"></a><a name="p204454140165629"></a><a href="ipc.md#ga40c57ae45831edc27ae9ff933b11aa50">SA_ONESHOT</a>   <a href="ipc.md#ga8d5fb4f35858d31035e7354c1d4048ea">SA_RESETHAND</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p742029368165629"><a name="p742029368165629"></a><a name="p742029368165629"></a>The default processing mode is restored after the signal processing is complete. </p>
</td>
</tr>
<tr id="row399677963165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p115482462165629"><a name="p115482462165629"></a><a name="p115482462165629"></a><a href="ipc.md#ga927f6ae16379576d638006c7498ac5d7">SIG_BLOCK</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289399997165629"><a name="p289399997165629"></a><a name="p289399997165629"></a>Defines the function behaviors such as <a href="ipc.md#gae11d1cbeb529d0050ab5600fe4b5fef9">sigprocmask()</a> and <a href="ipc.md#ga8ca5be75c386a4aacd17be00721bf0f8">pthread_sigmask()</a>, which are used to add signals to the mask set. </p>
</td>
</tr>
<tr id="row1352528798165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116118407165629"><a name="p116118407165629"></a><a name="p116118407165629"></a><a href="ipc.md#ga5fcd73313a63dac2cc7eb3b654215250">SIG_UNBLOCK</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2117648412165629"><a name="p2117648412165629"></a><a name="p2117648412165629"></a>Defines the function behaviors such as <a href="ipc.md#gae11d1cbeb529d0050ab5600fe4b5fef9">sigprocmask()</a> and <a href="ipc.md#ga8ca5be75c386a4aacd17be00721bf0f8">pthread_sigmask()</a>, which are used to remove signals from the mask set. </p>
</td>
</tr>
<tr id="row980438771165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p445681762165629"><a name="p445681762165629"></a><a name="p445681762165629"></a><a href="ipc.md#ga37750b78b7ae75fe02ad26e70f6cc845">SIG_SETMASK</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1463622306165629"><a name="p1463622306165629"></a><a name="p1463622306165629"></a>Defines the function behaviors such as <a href="ipc.md#gae11d1cbeb529d0050ab5600fe4b5fef9">sigprocmask()</a> and <a href="ipc.md#ga8ca5be75c386a4aacd17be00721bf0f8">pthread_sigmask()</a>, which are used to set the mask set. </p>
</td>
</tr>
<tr id="row1850044327165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1801468538165629"><a name="p1801468538165629"></a><a name="p1801468538165629"></a><a href="ipc.md#ga0fa971487344a463a7f0545c9c9ef2bf">SIG_HOLD</a>   ((void (*)(int)) 2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1938548930165629"><a name="p1938548930165629"></a><a name="p1938548930165629"></a>Defines the function behaviors such as <strong id="b1567509420165629"><a name="b1567509420165629"></a><a name="b1567509420165629"></a>sigset()</strong> and adds a specified signal to the process signal mask without changing the current processing mode of the signal. </p>
</td>
</tr>
<tr id="row1518829048165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2069928812165629"><a name="p2069928812165629"></a><a name="p2069928812165629"></a><a href="ipc.md#ga51d2f3aecb6f42d152e5f319e6b178b9">sa_handler</a>   __sa_handler.sa_handler</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1799532826165629"><a name="p1799532826165629"></a><a name="p1799532826165629"></a>Defines the simplified writing used to indicate the <strong id="b1658835938165629"><a name="b1658835938165629"></a><a name="b1658835938165629"></a>__sa_handler.sa_handler</strong> field in <a href="sigaction.md">sigaction</a>. </p>
</td>
</tr>
<tr id="row317197615165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1778390153165629"><a name="p1778390153165629"></a><a name="p1778390153165629"></a><a href="ipc.md#ga14be6197399829e41a778070ecebd9a3">sa_sigaction</a>   __sa_handler.sa_sigaction</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p32519772165629"><a name="p32519772165629"></a><a name="p32519772165629"></a>Defines the simplified writing used to indicate the <strong id="b2143376287165629"><a name="b2143376287165629"></a><a name="b2143376287165629"></a>__sa_handler.sa_sigaction</strong> field in <a href="sigaction.md">sigaction</a>. </p>
</td>
</tr>
<tr id="row1345788207165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1647117965165629"><a name="p1647117965165629"></a><a name="p1647117965165629"></a><a href="ipc.md#ga06d5881eeb84e6ac35f5b801c380dbb6">SIGEV_SIGNAL</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1471082013165629"><a name="p1471082013165629"></a><a name="p1471082013165629"></a>Sets the notification method in <a href="sigevent.md">sigevent</a>: signal notification. </p>
</td>
</tr>
<tr id="row1239595075165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p74413366165629"><a name="p74413366165629"></a><a name="p74413366165629"></a><a href="ipc.md#gaced9a66610d9d61756999ce4f103740e">SIGEV_NONE</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p271786268165629"><a name="p271786268165629"></a><a name="p271786268165629"></a>Sets the notification method in <a href="sigevent.md">sigevent</a>: no notification. </p>
</td>
</tr>
<tr id="row1312520800165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p172227022165629"><a name="p172227022165629"></a><a name="p172227022165629"></a><a href="ipc.md#ga29ccb6a17fa90a1357b478f62af7fca0">SIGEV_THREAD</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p388993732165629"><a name="p388993732165629"></a><a name="p388993732165629"></a>Sets the notification method in <a href="sigevent.md">sigevent</a>: thread notification. </p>
</td>
</tr>
<tr id="row316175401165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p549732628165629"><a name="p549732628165629"></a><a name="p549732628165629"></a><a href="ipc.md#ga3c330fbddd84bf34e65af370b11998d6">SIG_ERR</a>   ((__sighandler_t)-1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1465477523165629"><a name="p1465477523165629"></a><a name="p1465477523165629"></a>Defines the value returned when a function such as <a href="ipc.md#gaf0f8ed40d30773bdb68e858ef0139b58">signal()</a> fails. </p>
</td>
</tr>
<tr id="row966270859165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p968513919165629"><a name="p968513919165629"></a><a name="p968513919165629"></a><a href="ipc.md#ga27d5dc561093d6243542e6a2465bc0f8">SIG_DFL</a>   ((__sighandler_t)0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962423476165629"><a name="p962423476165629"></a><a name="p962423476165629"></a>Defines the default signal processing mode. </p>
</td>
</tr>
<tr id="row961390532165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p196350514165629"><a name="p196350514165629"></a><a name="p196350514165629"></a><a href="ipc.md#gacf0e499b0ac946b366b4f47a3b3e8b9e">SIG_IGN</a>   ((__sighandler_t)1)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2126472637165629"><a name="p2126472637165629"></a><a name="p2126472637165629"></a>Defines the signal processing mode in which the signal is ignored. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table11769769165629"></a>
<table><thead align="left"><tr id="row115970073165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1145731127165629"><a name="p1145731127165629"></a><a name="p1145731127165629"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p994159499165629"><a name="p994159499165629"></a><a name="p994159499165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2141034521165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168874743165629"><a name="p168874743165629"></a><a name="p168874743165629"></a><a href="ipc.md#ga1a2cdfb5c67c69b7aaab293b0946593b">ucontext_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p120079510165629"><a name="p120079510165629"></a><a name="p120079510165629"></a> typedef struct <a href="__ucontext.md">__ucontext</a> </p>
<p id="p1735354217165629"><a name="p1735354217165629"></a><a name="p1735354217165629"></a>Describes the user execution context. </p>
</td>
</tr>
<tr id="row1088400697165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2017696389165629"><a name="p2017696389165629"></a><a name="p2017696389165629"></a><a href="ipc.md#ga754cdc0bcfffe07baa426dc252c9101a">sighandler_t</a>) (int)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p736998448165629"><a name="p736998448165629"></a><a name="p736998448165629"></a> typedef void(* </p>
<p id="p1088322282165629"><a name="p1088322282165629"></a><a name="p1088322282165629"></a>Function pointer of signal handler. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table283485309165629"></a>
<table><thead align="left"><tr id="row329669560165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p655189797165629"><a name="p655189797165629"></a><a name="p655189797165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1561069100165629"><a name="p1561069100165629"></a><a name="p1561069100165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1736373848165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1745856283165629"><a name="p1745856283165629"></a><a name="p1745856283165629"></a><a href="ipc.md#ga4539db972bcf3dd8c8b429af0dc3789d">kill</a> (<a href="utils.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, int sig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p494800068165629"><a name="p494800068165629"></a><a name="p494800068165629"></a>int </p>
<p id="p277152651165629"><a name="p277152651165629"></a><a name="p277152651165629"></a>Sends a signal to a specified process. </p>
</td>
</tr>
<tr id="row66207867165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2030689927165629"><a name="p2030689927165629"></a><a name="p2030689927165629"></a><a href="ipc.md#ga5925352f90eb589393274fa0376d7def">sigemptyset</a> (sigset_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p745480444165629"><a name="p745480444165629"></a><a name="p745480444165629"></a>int </p>
<p id="p2045912645165629"><a name="p2045912645165629"></a><a name="p2045912645165629"></a>Clears all signals in a specified signal set. </p>
</td>
</tr>
<tr id="row735546580165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1576291069165629"><a name="p1576291069165629"></a><a name="p1576291069165629"></a><a href="ipc.md#ga88d7bbc77ea1569ee21c90db549ea023">sigfillset</a> (sigset_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2052946966165629"><a name="p2052946966165629"></a><a name="p2052946966165629"></a>int </p>
<p id="p1177484107165629"><a name="p1177484107165629"></a><a name="p1177484107165629"></a>Adds all signals to a specified signal set. </p>
</td>
</tr>
<tr id="row1724280565165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p25808530165629"><a name="p25808530165629"></a><a name="p25808530165629"></a><a href="ipc.md#gae412e6a5436a6c28424b0173251d349c">sigaddset</a> (sigset_t *set, int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p463300346165629"><a name="p463300346165629"></a><a name="p463300346165629"></a>int </p>
<p id="p1447252832165629"><a name="p1447252832165629"></a><a name="p1447252832165629"></a>Adds a signal to a specified signal set. </p>
</td>
</tr>
<tr id="row880348799165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1982698832165629"><a name="p1982698832165629"></a><a name="p1982698832165629"></a><a href="ipc.md#gab0025e4f32ce2737c40cc0074cc6d7d2">sigdelset</a> (sigset_t *set, int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p704988371165629"><a name="p704988371165629"></a><a name="p704988371165629"></a>int </p>
<p id="p1249709096165629"><a name="p1249709096165629"></a><a name="p1249709096165629"></a>Delete a signal from a specified signal set. </p>
</td>
</tr>
<tr id="row56845610165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1000290026165629"><a name="p1000290026165629"></a><a name="p1000290026165629"></a><a href="ipc.md#ga63693cc65f43d772729b588b453fe1ef">sigismember</a> (const sigset_t *set, int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p516235306165629"><a name="p516235306165629"></a><a name="p516235306165629"></a>int </p>
<p id="p2043954973165629"><a name="p2043954973165629"></a><a name="p2043954973165629"></a>Checks whether a signal is in the signal set. </p>
</td>
</tr>
<tr id="row1484400232165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1995726873165629"><a name="p1995726873165629"></a><a name="p1995726873165629"></a><a href="ipc.md#gae11d1cbeb529d0050ab5600fe4b5fef9">sigprocmask</a> (int how, const sigset_t *__restrict set, sigset_t *__restrict oldset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1753447704165629"><a name="p1753447704165629"></a><a name="p1753447704165629"></a>int </p>
<p id="p1652251227165629"><a name="p1652251227165629"></a><a name="p1652251227165629"></a>Changes the signal mask of the calling thread. </p>
</td>
</tr>
<tr id="row419998218165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p228634408165629"><a name="p228634408165629"></a><a name="p228634408165629"></a><a href="ipc.md#gae5f92586ad50092a7813465eeef792c0">sigsuspend</a> (const sigset_t *mask)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1490895528165629"><a name="p1490895528165629"></a><a name="p1490895528165629"></a>int </p>
<p id="p828217568165629"><a name="p828217568165629"></a><a name="p828217568165629"></a>Sets <strong id="b1124749730165629"><a name="b1124749730165629"></a><a name="b1124749730165629"></a>mask</strong> as the signal mask set of the current process and suspends the process until a signal processing action is triggered. </p>
</td>
</tr>
<tr id="row584505138165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1410143144165629"><a name="p1410143144165629"></a><a name="p1410143144165629"></a><a href="ipc.md#ga5263ce0feb3eb0934bc56ab81cae8ddb">sigaction</a> (int signum, const struct <a href="sigaction.md">sigaction</a> *__restrict act, struct <a href="sigaction.md">sigaction</a> *__restrict oldact)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1533640528165629"><a name="p1533640528165629"></a><a name="p1533640528165629"></a>int </p>
<p id="p1685817143165629"><a name="p1685817143165629"></a><a name="p1685817143165629"></a>Checks or changes the processing action associated with a specified signal. Do not use the process creation function or thread creation function in the registered callback processing function. Otherwise, the process is abnormal. For example, do not use the <strong id="b898662640165629"><a name="b898662640165629"></a><a name="b898662640165629"></a>fork</strong> or <strong id="b1767408674165629"><a name="b1767408674165629"></a><a name="b1767408674165629"></a>pthread_create</strong> function. </p>
</td>
</tr>
<tr id="row862752306165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p916007185165629"><a name="p916007185165629"></a><a name="p916007185165629"></a><a href="ipc.md#ga7b91eecad5998acd6162fde3ab530d7a">sigpending</a> (sigset_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p346737266165629"><a name="p346737266165629"></a><a name="p346737266165629"></a>int </p>
<p id="p410692277165629"><a name="p410692277165629"></a><a name="p410692277165629"></a>Obtains the signal suspended by the current thread. </p>
</td>
</tr>
<tr id="row722514428165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p182818684165629"><a name="p182818684165629"></a><a name="p182818684165629"></a><a href="ipc.md#ga900d91a9635b965dbbae6b3cee2d2a2b">sigwait</a> (const sigset_t *__restrict set, int *__restrict sig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1882620043165629"><a name="p1882620043165629"></a><a name="p1882620043165629"></a>int </p>
<p id="p1832147587165629"><a name="p1832147587165629"></a><a name="p1832147587165629"></a>Suspends the calling thread and waits for the signal. </p>
</td>
</tr>
<tr id="row1253351172165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1017263407165629"><a name="p1017263407165629"></a><a name="p1017263407165629"></a><a href="ipc.md#ga786f18a8e5b7eceed0ddcdc722f3340b">sigwaitinfo</a> (const sigset_t *__restrict set, siginfo_t *__restrict info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p376717791165629"><a name="p376717791165629"></a><a name="p376717791165629"></a>int </p>
<p id="p2089611309165629"><a name="p2089611309165629"></a><a name="p2089611309165629"></a>Suspends the calling thread and waits for the signal, with a timeout period specified. </p>
</td>
</tr>
<tr id="row795920592165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p299225483165629"><a name="p299225483165629"></a><a name="p299225483165629"></a><a href="ipc.md#ga155a526c3da5ffd1a79ba2925bdd278a">sigtimedwait</a> (const sigset_t *__restrict set, siginfo_t *__restrict info, const struct <a href="timespec.md">timespec</a> *__restrict timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p665331915165629"><a name="p665331915165629"></a><a name="p665331915165629"></a>int </p>
<p id="p873107102165629"><a name="p873107102165629"></a><a name="p873107102165629"></a>Suspends the calling thread and waits for the signal, with a timeout period specified. </p>
</td>
</tr>
<tr id="row539589803165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2015354363165629"><a name="p2015354363165629"></a><a name="p2015354363165629"></a><a href="ipc.md#ga8ca5be75c386a4aacd17be00721bf0f8">pthread_sigmask</a> (int how, const sigset_t *__restrict set, sigset_t *__restrict oldset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1962089865165629"><a name="p1962089865165629"></a><a name="p1962089865165629"></a>int </p>
<p id="p1566246300165629"><a name="p1566246300165629"></a><a name="p1566246300165629"></a>Checks or changes the signal mask of the calling thread. </p>
</td>
</tr>
<tr id="row1128684782165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1403368044165629"><a name="p1403368044165629"></a><a name="p1403368044165629"></a><a href="ipc.md#gada1fed9730b224a68e768e5f2eac53ff">psignal</a> (int signum, const char *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p762104138165629"><a name="p762104138165629"></a><a name="p762104138165629"></a>void </p>
<p id="p883090586165629"><a name="p883090586165629"></a><a name="p883090586165629"></a>Prints signal information. </p>
</td>
</tr>
<tr id="row856940333165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1388856027165629"><a name="p1388856027165629"></a><a name="p1388856027165629"></a><a href="ipc.md#ga95a78da8c44db11c7031b678504d0b34">sigpause</a> (int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p842022274165629"><a name="p842022274165629"></a><a name="p842022274165629"></a>int </p>
<p id="p634996632165629"><a name="p634996632165629"></a><a name="p634996632165629"></a>Deletes the signal specified by <strong id="b1008995746165629"><a name="b1008995746165629"></a><a name="b1008995746165629"></a>signum</strong> from the signal mask of the calling process and suspends the process until the signal is received. </p>
</td>
</tr>
<tr id="row402415032165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p827225153165629"><a name="p827225153165629"></a><a name="p827225153165629"></a><a href="ipc.md#ga4378a40ea3370c436d4e46c7a2a58172">sighold</a> (int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1241034067165629"><a name="p1241034067165629"></a><a name="p1241034067165629"></a>int </p>
<p id="p588010941165629"><a name="p588010941165629"></a><a name="p588010941165629"></a>Adds the signal specified by <strong id="b675097797165629"><a name="b675097797165629"></a><a name="b675097797165629"></a>signum</strong> to the signal mask of the calling process. </p>
</td>
</tr>
<tr id="row515368987165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p341753463165629"><a name="p341753463165629"></a><a name="p341753463165629"></a><a href="ipc.md#ga96c4aed60b8b727709887e1fae0f5bea">sigrelse</a> (int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p699516891165629"><a name="p699516891165629"></a><a name="p699516891165629"></a>int </p>
<p id="p1706280305165629"><a name="p1706280305165629"></a><a name="p1706280305165629"></a>Deletes the signal specified by <strong id="b1484710675165629"><a name="b1484710675165629"></a><a name="b1484710675165629"></a>signum</strong> from the signal mask of the calling process. </p>
</td>
</tr>
<tr id="row1370176983165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p109873116165629"><a name="p109873116165629"></a><a name="p109873116165629"></a><a href="ipc.md#gac41035aa05cb4523ae93e8a6d55f9453">sigisemptyset</a> (const sigset_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1560599786165629"><a name="p1560599786165629"></a><a name="p1560599786165629"></a>int </p>
<p id="p2089306979165629"><a name="p2089306979165629"></a><a name="p2089306979165629"></a>Checks whether the signal set is empty. </p>
</td>
</tr>
<tr id="row1730197423165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1250003524165629"><a name="p1250003524165629"></a><a name="p1250003524165629"></a><a href="ipc.md#ga1a0d037b7fd84fb392a4c2ffc6c3525c">sigorset</a> (sigset_t *dest, const sigset_t *left, const sigset_t *right)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2117918324165629"><a name="p2117918324165629"></a><a name="p2117918324165629"></a>int </p>
<p id="p306459426165629"><a name="p306459426165629"></a><a name="p306459426165629"></a>Adds the union set of <strong id="b1307469527165629"><a name="b1307469527165629"></a><a name="b1307469527165629"></a>left</strong> and <strong id="b445840879165629"><a name="b445840879165629"></a><a name="b445840879165629"></a>right</strong> to <strong id="b1620842412165629"><a name="b1620842412165629"></a><a name="b1620842412165629"></a>dest</strong>. </p>
</td>
</tr>
<tr id="row20599211165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p199438074165629"><a name="p199438074165629"></a><a name="p199438074165629"></a><a href="ipc.md#ga2a0910ff9d18931a05b995143dc4576e">sigandset</a> (sigset_t *dest, const sigset_t *left, const sigset_t *right)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1132568608165629"><a name="p1132568608165629"></a><a name="p1132568608165629"></a>int </p>
<p id="p1590809655165629"><a name="p1590809655165629"></a><a name="p1590809655165629"></a>Adds the intersection of <strong id="b274051016165629"><a name="b274051016165629"></a><a name="b274051016165629"></a>left</strong> and <strong id="b89952220165629"><a name="b89952220165629"></a><a name="b89952220165629"></a>right</strong> to <strong id="b1745836900165629"><a name="b1745836900165629"></a><a name="b1745836900165629"></a>dest</strong>. </p>
</td>
</tr>
<tr id="row793889640165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1416421202165629"><a name="p1416421202165629"></a><a name="p1416421202165629"></a><a href="ipc.md#gaf0f8ed40d30773bdb68e858ef0139b58">signal</a> (int signum, <a href="ipc.md#ga754cdc0bcfffe07baa426dc252c9101a">sighandler_t</a> handler)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031366820165629"><a name="p2031366820165629"></a><a name="p2031366820165629"></a><a href="ipc.md#ga754cdc0bcfffe07baa426dc252c9101a">sighandler_t</a> </p>
<p id="p1211368570165629"><a name="p1211368570165629"></a><a name="p1211368570165629"></a>Changes the processing action of a specified signal. Do not use the process creation function or thread creation function in the registered callback processing function. Otherwise, the process is abnormal. For example, do not use the <strong id="b487091601165629"><a name="b487091601165629"></a><a name="b487091601165629"></a>fork</strong> or <strong id="b1598479178165629"><a name="b1598479178165629"></a><a name="b1598479178165629"></a>pthread_create</strong> function. </p>
</td>
</tr>
<tr id="row392779340165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p487448452165629"><a name="p487448452165629"></a><a name="p487448452165629"></a><a href="ipc.md#ga350675984ca13ce9b056e69098bda5c6">raise</a> (int signum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1826352865165629"><a name="p1826352865165629"></a><a name="p1826352865165629"></a>int </p>
<p id="p717215093165629"><a name="p717215093165629"></a><a name="p717215093165629"></a>Sends a signal to the calling process. </p>
</td>
</tr>
</tbody>
</table>

