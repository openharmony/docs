# Native API Symbols That May Fail to Call Due to Permission Control

Before using the following interfaces, ensure that the application entity has the corresponding permission.

| Symbol| Possible Cause|
| --- | --- |
| mlockall | usr namespace isolation or lack of CAP_IPC_LOCK privilege |
| swapon | usr namespace isolation |
| swapoff | usr namespace isolation |
| stime | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| settimeofday | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| adjtime | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| clock_settime | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| klogctl | usr namespace isolation or lack of CAP_SYS_ADMIN/CAP_SYSLOG privilege |
