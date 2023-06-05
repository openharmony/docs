# Native API中由于权限管控可能调用失败的符号列表

使用如下接口请确保应用实体有相应的权限。

| 符号名 | 调用失败可能的原因 |
| --- | --- |
| mlockall | usr namespace isolation or lack of CAP_IPC_LOCK privilege |
| swapon | usr namespace isolation |
| swapoff | usr namespace isolation |
| stime | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| settimeofday | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| adjtime | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| clock_settime | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| klogctl | usr namespace isolation or lack of CAP_SYS_ADMIN/CAP_SYSLOG privilege |