# kill


## 命令功能

kill命令用于发送特定信号给指定进程，让它去终结不正常的应用。


## 命令格式

kill [-l [_signo_] | _-s signo_ | _-signo_] _pid..._


## 参数说明

**表1** 参数说明

| 参数   | 参数说明                   | 取值范围    |
| ------ | -------------------------- | ----------- |
| --help | 查看kill命令支持的参数列表 | N/A         |
| -l     | 列出信号名称和编号。       | N/A         |
| -s     | 发送信号                   | N/A         |
| signo  | 信号ID。                   | [1, 30]      |
| pid    | 进程ID。                   | [1, MAX_INT] |

> ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
> signo有效范围为[0, 64]，建议取值范围为[1, 30]，其余为保留内容。


## 使用指南

- 必须指定发送的信号编号及进程号。

- 进程编号取值范围根据系统配置变化，例如系统最大支持pid为256，则取值范围缩小为[1, 256]。

## 特殊说明

kill命令以及参数 shell端暂不支持。切换mksh版本可全支持，方法：cd bin; ./mksh。

## 使用实例

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
     10     5    5       101 Pending  0x11ec000 0x2f9000    0x206047      0.93  com.example.launcher
     12     1   12         0 Pending   0x4d4000 0x112000     0xe0882      0.0   deviceauth_service
     13     1   13         0 Pending   0x34f000  0xbd000     0x51799      0.0   sensor_service
     14     1   14         2 Pending   0x34e000  0xb3000     0x52184      0.0   ai_server
     15     1   15         0 Pending   0x61f000 0x13b000    0x168071      0.45  softbus_server
     42     8   42         2 Pending   0x1c1000  0x3a000     0x1106a      0.9   test_demo
     43     8   43         2 Running   0x1d7000  0x3a000     0x1e577      0.0   toybox
  ```

- 发送信号9（SIGKILL默认行为为立即终止进程）给42号进程test_demo（用户态进程）：kill -s 9 42（kill -9 42效果相同），并查看当前进程列表，42号进程已终止。

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
     10     5    5       101 Pending  0x11ec000 0x2f9000    0x206561      0.93  com.example.launcher
     12     1   12         0 Pending   0x4d4000 0x112000     0xe0d9c      0.0   deviceauth_service
     13     1   13         0 Pending   0x34f000  0xbd000     0x51cb3      0.0   sensor_service
     14     1   14         2 Pending   0x34e000  0xb3000     0x5269e      0.0   ai_server
     15     1   15         0 Pending   0x61f000 0x13b000    0x16858b      0.51  softbus_server
     45     8   45         2 Running   0x1d7000  0x3a000     0x1e9f5      0.0   toybox
  ```

- 发送不存在的信号值 kill -100 31


## 输出说明

发送成功或失败输出结果如下。

**示例1** 发送信号给指定进程


```
OHOS:/$ kill -s 9 42
OHOS:/$
[1] + Killed               ./nfs/test_demo
```

信号发送成功会显示的提示进程已被杀死。

**示例2** 信号发送失败


```
OHOS:/$ kill -100 31
kill: Unknown signal '(null)'
```

信号发送失败，示例2所示原因为信号发送命令参数无效，请排查信号编号及进程编号是否有效。