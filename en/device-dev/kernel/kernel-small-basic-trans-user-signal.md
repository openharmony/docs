# Signal


## Basic Concepts<a name="section172788254307"></a>

Signal is a common inter-process asynchronous communication mechanism. It uses software-simulated interrupt signals. When a process needs to communicate with another process, it sends a signal to the kernel. The kernel then transfers the signal to the destination process. The destination process does not need to wait for the signal.

## Working Principles<a name="section1249693812301"></a>

The following table describes the APIs available for signal operations.

**Table  1**  Signal operation process and APIs \(user-mode APIs\)

<a name="table1316220185211"></a>
<table><thead align="left"><tr id="row191622182021"><th class="cellrowborder" valign="top" width="27.09270927092709%" id="mcps1.2.4.1.1"><p id="p13162121815218"><a name="p13162121815218"></a><a name="p13162121815218"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="26.49264926492649%" id="mcps1.2.4.1.2"><p id="p12162618623"><a name="p12162618623"></a><a name="p12162618623"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="46.41464146414641%" id="mcps1.2.4.1.3"><p id="p16162118427"><a name="p16162118427"></a><a name="p16162118427"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row04981218910"><td class="cellrowborder" rowspan="2" valign="top" width="27.09270927092709%" headers="mcps1.2.4.1.1 "><p id="p6462616696"><a name="p6462616696"></a><a name="p6462616696"></a>Registering the signal callback</p>
</td>
<td class="cellrowborder" valign="top" width="26.49264926492649%" headers="mcps1.2.4.1.2 "><p id="p164931214913"><a name="p164931214913"></a><a name="p164931214913"></a>signal</p>
</td>
<td class="cellrowborder" valign="top" width="46.41464146414641%" headers="mcps1.2.4.1.3 "><p id="p8504121996"><a name="p8504121996"></a><a name="p8504121996"></a>Registers the main signal entry, and registers and unregisters the callback function of a signal.</p>
</td>
</tr>
<tr id="row5449183942119"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p5450153922110"><a name="p5450153922110"></a><a name="p5450153922110"></a>sigaction</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1945083962113"><a name="p1945083962113"></a><a name="p1945083962113"></a>Same as <strong id="b1076755712371"><a name="b1076755712371"></a><a name="b1076755712371"></a>signal</strong>. This API is added with configuration options related to signal transmission. Currently, only some parameters in the <strong id="b18458105019218"><a name="b18458105019218"></a><a name="b18458105019218"></a>SIGINFO</strong> structure are supported.</p>
</td>
</tr>
<tr id="row7162101814216"><td class="cellrowborder" rowspan="5" valign="top" width="27.09270927092709%" headers="mcps1.2.4.1.1 "><p id="p37331032985"><a name="p37331032985"></a><a name="p37331032985"></a>Sending signals</p>
</td>
<td class="cellrowborder" valign="top" width="26.49264926492649%" headers="mcps1.2.4.1.2 "><p id="p816311185217"><a name="p816311185217"></a><a name="p816311185217"></a>kill</p>
</td>
<td class="cellrowborder" rowspan="5" align="left" valign="top" width="46.41464146414641%" headers="mcps1.2.4.1.3 "><p id="p161632181721"><a name="p161632181721"></a><a name="p161632181721"></a>Sends a signal to a process or sends messages to a thread in a process, and sets signal flags for threads in a process.</p>
</td>
</tr>
<tr id="row129182420243"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p149191745248"><a name="p149191745248"></a><a name="p149191745248"></a>pthread_kill</p>
</td>
</tr>
<tr id="row1026214719240"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1226313762411"><a name="p1226313762411"></a><a name="p1226313762411"></a>raise</p>
</td>
</tr>
<tr id="row05632094242"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p45643914245"><a name="p45643914245"></a><a name="p45643914245"></a>alarm</p>
</td>
</tr>
<tr id="row3241512122417"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p324211202414"><a name="p324211202414"></a><a name="p324211202414"></a>abort</p>
</td>
</tr>
<tr id="row101631818620"><td class="cellrowborder" valign="top" width="27.09270927092709%" headers="mcps1.2.4.1.1 "><p id="p146111936887"><a name="p146111936887"></a><a name="p146111936887"></a>Triggering a callback</p>
</td>
<td class="cellrowborder" valign="top" width="26.49264926492649%" headers="mcps1.2.4.1.2 "><p id="p71633181125"><a name="p71633181125"></a><a name="p71633181125"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="46.41464146414641%" headers="mcps1.2.4.1.3 "><p id="p1126941694213"><a name="p1126941694213"></a><a name="p1126941694213"></a>Triggered by a system call or an interrupt. Before the switching between the kernel mode and user mode, the specified function in user mode is entered, and the corresponding callbacks are processed. After that, the original user-mode program continues to run.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The signal mechanism enables communication between user-mode programs. The user-mode POSIX APIs listed in the above table are recommended.
>Register a callback function.
>```
>void *signal(int sig, void (*func)(int))(int);
>```
>a. Signal 31 is used to register the handling entry of the process callback. Repeated registration is not allowed.
>b. Signals 0 to 30 are used to register and unregister callbacks.
>Register a callback.
>```
>int sigaction(int, const struct sigaction *__restrict, struct sigaction *__restrict);
>```
>You can obtain and modify the configuration of signal registration. Currently, only the  **SIGINFO**  options are supported. For details, see the description of the  **sigtimedwait**  API.
>Transmit a signal.
>a. Among the default signal-receiving behaviors, the process does not support  **STOP**,  **COTINUE**, and  **COREDUMP**  defined in the POSIX standard.
>b. The  **SIGSTOP**,  **SIGKILL**, and  **SIGCONT**  signals cannot be shielded.
>c. If a process killed is not reclaimed by its parent process, the process becomes a zombie process.
>d. A process will not call back the signal received until the process is scheduled.
>e. When a process is killed,  **SIGCHLD**  is sent to its parent process. The signal sending action cannot be canceled.
>f. A process in the DELAY state cannot be woken up by a signal.

