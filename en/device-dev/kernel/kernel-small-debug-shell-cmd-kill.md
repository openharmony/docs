# kill

## Command Function<a name="section366714216619"></a>

This command is used to send a signal to a specified process.

## Syntax<a name="section8833164614615"></a>

kill \[-l \[_signo_\] |  _-s signo_  |  _-signo_\]  _pid..._

## Parameters<a name="section12809111019453"></a>

**Table  1**  Parameter description

<a name="table438mcpsimp"></a>
<table><thead align="left"><tr id="row444mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p446mcpsimp"><a name="p446mcpsimp"></a><a name="p446mcpsimp"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="51.92%" id="mcps1.2.4.1.2"><p id="p448mcpsimp"><a name="p448mcpsimp"></a><a name="p448mcpsimp"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="27.08%" id="mcps1.2.4.1.3"><p id="p450mcpsimp"><a name="p450mcpsimp"></a><a name="p450mcpsimp"></a>Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row6412714183316"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p940219144332"><a name="p940219144332"></a><a name="p940219144332"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p3402191493310"><a name="p3402191493310"></a><a name="p3402191493310"></a>Displays the parameters supported by the <strong id="b277973411569"><a name="b277973411569"></a><a name="b277973411569"></a>kill</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p4402161493316"><a name="p4402161493316"></a><a name="p4402161493316"></a>N/A</p>
</td>
</tr>
<tr id="row114122143330"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p0402314103315"><a name="p0402314103315"></a><a name="p0402314103315"></a>-l</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p640281413313"><a name="p640281413313"></a><a name="p640281413313"></a>Lists the names and numbers of signals.</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p19402191416337"><a name="p19402191416337"></a><a name="p19402191416337"></a>N/A</p>
</td>
</tr>
<tr id="row12412131493314"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p1240220141335"><a name="p1240220141335"></a><a name="p1240220141335"></a>-s</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p8402131411331"><a name="p8402131411331"></a><a name="p8402131411331"></a>Sends signals</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p140211415339"><a name="p140211415339"></a><a name="p140211415339"></a>N/A</p>
</td>
</tr>
<tr id="row1441281443320"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p14402171410332"><a name="p14402171410332"></a><a name="p14402171410332"></a>signo</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p114023144336"><a name="p114023144336"></a><a name="p114023144336"></a>Specifies the signal number.</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p240212145333"><a name="p240212145333"></a><a name="p240212145333"></a>[1,30]</p>
</td>
</tr>
<tr id="row13411714143310"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p5402131463314"><a name="p5402131463314"></a><a name="p5402131463314"></a>pid</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p7402014113310"><a name="p7402014113310"></a><a name="p7402014113310"></a>Specifies the process ID.</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p24021514183317"><a name="p24021514183317"></a><a name="p24021514183317"></a>[1,MAX_INT]</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>The value range of  **signo**  is \[0, 64\]. The recommended value range is \[1, 30\], and other values in the value range are reserved.

## Usage<a name="section15935131220717"></a>

-   The  **signo**  and  **pid**  parameters are mandatory.
-   The  **pid**  value range varies depending on the system configuration. For example, if the maximum  **pid**  value supported by the system is  **256**, this value range is \[1-256\].

## Example<a name="section79281818476"></a>

-   Query the process list before killing process 42.

    ```
    OHOS:/$ ps
      allCpu(%):    4.67 sys,  195.33 idle
      PID  PPID PGID       UID  Status VirtualMem ShareMem PhysicalMem CPUUSE10s  PName
        1    -1    1         0 Pending   0x33b000  0xbb000     0x4db02      0.0   init
        2    -1    2         0 Pending   0xdabc08        0    0xdabc08      1.14  KProcess
        3     1    3         7 Pending   0x72e000 0x1a3000    0x1d24c2      0.0   foundation
        4     1    4         8 Pending   0x362000  0xbb000     0x5c6ff      0.0   bundle_daemon
        5     1    5         1 Pending   0xdfa000 0x2e7000    0x1484f0      0.0   appspawn
        6     1    6         0 Pending   0x688000 0x137000    0x11bca0      0.0   media_server
        7     1    7         0 Pending   0x9d2000 0x103000     0xa1cdf      0.88  wms_server
        8     1    8         2 Pending   0x1f5000  0x48000     0x47dc2      0.2   mksh
       12     1   12         0 Pending   0x4d4000 0x112000     0xe0882      0.0   deviceauth_service
       13     1   13         0 Pending   0x34f000  0xbd000     0x51799      0.0   sensor_service
       14     1   14         2 Pending   0x34e000  0xb3000     0x52184      0.0   ai_server
       15     1   15         0 Pending   0x61f000 0x13b000    0x168071      0.45  softbus_server
       42     8   42         2 Pending   0x1c1000  0x3a000     0x1106a      0.9   test_demo
       43     8   43         2 Running   0x1d7000  0x3a000     0x1e577      0.0   toybox
    ```

-   Send signal 9 \(the default action of  **SIGKILL**  is to immediately terminate the process\) to process 42 test\_demo \(a user-mode process\). Then, check the current process list. The commands  **kill -s 9 42**  and  **kill -9 42**  have the same effect.

    ```
    OHOS:/$ kill -s 9 42
    OHOS:/$
    [1] + Killed               ./nfs/test_demo
    OHOS:/$ ps
      allCpu(%):    4.73 sys,  195.27 idle
      PID  PPID PGID       UID  Status VirtualMem ShareMem PhysicalMem CPUUSE10s  PName
        1    -1    1         0 Pending   0x33b000  0xbb000     0x4e01c      0.0   init
        2    -1    2         0 Pending   0xda5fa4        0    0xda5fa4      1.14  KProcess
        3     1    3         7 Pending   0x72e000 0x1a3000    0x1d29dc      0.0   foundation
        4     1    4         8 Pending   0x362000  0xbb000     0x5cc19      0.0   bundle_daemon
        5     1    5         1 Pending   0xdfa000 0x2e7000    0x148a0a      0.0   appspawn
        6     1    6         0 Pending   0x688000 0x137000    0x11c1ba      0.0   media_server
        7     1    7         0 Pending   0x9d2000 0x103000     0xa21f9      0.89  wms_server
        8     1    8         2 Pending   0x1f5000  0x48000     0x482dc      0.2   mksh
       12     1   12         0 Pending   0x4d4000 0x112000     0xe0d9c      0.0   deviceauth_service
       13     1   13         0 Pending   0x34f000  0xbd000     0x51cb3      0.0   sensor_service
       14     1   14         2 Pending   0x34e000  0xb3000     0x5269e      0.0   ai_server
       15     1   15         0 Pending   0x61f000 0x13b000    0x16858b      0.51  softbus_server
       45     8   45         2 Running   0x1d7000  0x3a000     0x1e9f5      0.0   toybox
    ```

-   Run the  **kill -100 31**  command.

## Output<a name="section12742311179"></a>

**Example 1**: The signal is successfully sent to process 42.

```
OHOS:/$ kill -s 9 42
OHOS:/$
[1] + Killed               ./nfs/test_demo
```

Process 42 is killed.

**Example 2**: The signal fails to be sent to process 31.

```
OHOS:/$ kill -100 31
kill: Unknown signal '(null)'
```

**Unknown signal '\(null\)'**  is displayed because the  **signo**  value  **100**  exceeds the value range \[0, 64\].

