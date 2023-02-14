# kill


## Command Function

This command is used to send a signal to a process to terminate the abnormal application.


## Syntax

kill [-l [_signo_] | _-s signo_ | _-signo_] *pid...*


## Parameters

**Table 1** Parameter description

| Parameter  | Description                  | Value Range   |
| ------ | -------------------------- | ----------- |
| --help | Displays the parameters supported by the **kill** command.| N/A         |
| -l     | Lists the names and numbers of signals.      | N/A         |
| -s     | Sends a signal.                  | N/A         |
| signo  | Specifies the signal number.                  | [1, 30]      |
| pid    | Specifies the process ID.                  | [1, MAX_INT] |

> **NOTICE**<br>
> The value range of **signo** is [0, 64]. The recommended value range is [1, 30], and other values in the value range are reserved.


## Usage Guidelines

- The **signo** and **pid** parameters are mandatory.

- The **pid** value range varies depending on the system configuration. For example, if the maximum **pid** value supported by the system is **256**, this value range is [1, 256].

## Note

The **kill** command is not supported by the shell. mksh supports it. To switch to mksh, run **cd bin;** and **./mksh**.

## Example

- Query the process list before killing process 42.

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

- Send signal 9 (the default action of **SIGKILL** is to immediately terminate the process) to process 42 test_demo (a user-mode process). Then, check the current process list. The commands **kill -s 9 42** and **kill -9 42** have the same effect.

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

- Run the **kill -100 31** command.


## Output

The command output is as follows:

Example 1: The signal is successfully sent to process 42.


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

**Unknown signal '(null)'** is displayed because the **signo** value **100** exceeds the value range [0, 64].
