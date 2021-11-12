# kill<a name="ZH-CN_TOPIC_0000001179965835"></a>

-   [命令功能](#section01)
-   [命令格式](#section02)
-   [参数说明](#section03)
-   [使用指南](#section04)
-   [使用实例](#section05)
-   [输出说明](#section06)

## 命令功能<a name="section01"></a>

命令用于发送特定信号给指定进程。

## 命令格式<a name="section02"></a>

kill \[-l \[_signo_\]  |  _-s signo_ |  _-signo_\]  _pid..._

## 参数说明<a name="section03"></a>

**表 1**  参数说明

<a name="table438mcpsimp"></a>
<table><thead align="left"><tr id="row444mcpsimp"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="p446mcpsimp"><a name="p446mcpsimp"></a><a name="p446mcpsimp"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="51.92%" id="mcps1.2.4.1.2"><p id="p448mcpsimp"><a name="p448mcpsimp"></a><a name="p448mcpsimp"></a>参数说明</p>
</th>
<th class="cellrowborder" valign="top" width="27.08%" id="mcps1.2.4.1.3"><p id="p450mcpsimp"><a name="p450mcpsimp"></a><a name="p450mcpsimp"></a>取值范围</p>
</th>
</tr>
</thead>
<tbody><tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2500105121818"><a name="p2500105121818"></a><a name="p2500105121818"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>查看kill命令支持的参数列表</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>N/A</p>
</td>
</tr>
<tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2500105121818"><a name="p2500105121818"></a><a name="p2500105121818"></a>-l</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>列出信号名称和编号。</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>N/A</p>
</td>
</tr>
<tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2500105121818"><a name="p2500105121818"></a><a name="p2500105121818"></a>-s</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>发送信号</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>N/A</p>
</td>
</tr>
<tr id="row451mcpsimp"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p2500105121818"><a name="p2500105121818"></a><a name="p2500105121818"></a>signo</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p1149945111817"><a name="p1149945111817"></a><a name="p1149945111817"></a>信号ID。</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p749810571812"><a name="p749810571812"></a><a name="p749810571812"></a>[1,30]</p>
</td>
</tr>
<tr id="row113001232165611"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p18301173213562"><a name="p18301173213562"></a><a name="p18301173213562"></a>pid</p>
</td>
<td class="cellrowborder" valign="top" width="51.92%" headers="mcps1.2.4.1.2 "><p id="p1730143212569"><a name="p1730143212569"></a><a name="p1730143212569"></a>进程ID。</p>
</td>
<td class="cellrowborder" valign="top" width="27.08%" headers="mcps1.2.4.1.3 "><p id="p1301193275618"><a name="p1301193275618"></a><a name="p1301193275618"></a>[1,MAX_INT]</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-notice.gif) **须知：** 
>signo有效范围为\[0,64\]，建议取值范围为\[1,30\]，其余为保留内容。

## 使用指南<a name="section04"></a>

- 必须指定发送的信号编号及进程号。

- 进程编号取值范围根据系统配置变化，例如系统最大支持pid为256，则取值范围缩小为\[1-256\]。


## 使用实例<a name="section05"></a>

- 查看当前进程列表，查看需要杀死的进程PID（42）。

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
   10     5    5       101 Pending  0x11ec000 0x2f9000    0x206047      0.93  com.huawei.launcher
   12     1   12         0 Pending   0x4d4000 0x112000     0xe0882      0.0   deviceauth_service
   13     1   13         0 Pending   0x34f000  0xbd000     0x51799      0.0   sensor_service
   14     1   14         2 Pending   0x34e000  0xb3000     0x52184      0.0   ai_server
   15     1   15         0 Pending   0x61f000 0x13b000    0x168071      0.45  softbus_server
   42     8   42         2 Pending   0x1c1000  0x3a000     0x1106a      0.9   test_demo
   43     8   43         2 Running   0x1d7000  0x3a000     0x1e577      0.0   toybox
```

发送信号9（SIGKILL默认行为为立即终止进程）给42号进程**test\_demo**（用户态进程）：**kill -s 9 42**（kill -9 42效果相同），并查看当前进程列表，42号进程已终止。

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
   10     5    5       101 Pending  0x11ec000 0x2f9000    0x206561      0.93  com.huawei.launcher
   12     1   12         0 Pending   0x4d4000 0x112000     0xe0d9c      0.0   deviceauth_service
   13     1   13         0 Pending   0x34f000  0xbd000     0x51cb3      0.0   sensor_service
   14     1   14         2 Pending   0x34e000  0xb3000     0x5269e      0.0   ai_server
   15     1   15         0 Pending   0x61f000 0x13b000    0x16858b      0.51  softbus_server
   45     8   45         2 Running   0x1d7000  0x3a000     0x1e9f5      0.0   toybox
```

- 发送不存在的信号值 kill -100 31

## 输出说明<a name="section06"></a>

发送成功或失败输出结果如下。

**示例 1**  发送信号给指定进程

```shell
OHOS:/$ kill -s 9 42
OHOS:/$
[1] + Killed               ./nfs/test_demo
```

信号发送成功会显示的提示进程已被杀死。

**示例 2**  信号发送失败

```shell
OHOS:/$ kill -100 31
kill: Unknown signal '(null)'
```

信号发送失败，示例2所示原因为信号发送命令参数无效，请排查信号编号及进程编号是否有效。

