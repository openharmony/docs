# Native API Symbols That May Fail to Be Invoked Due to Permission Control

| Symbol| Possible Cause|
| --- | --- |
| mlockall | User namespace isolation or lack of the CAP_IPC_LOCK privilege.|
| swapon | User namespace isolation. |
| swapoff | User namespace isolation. |
| stime | User namespace isolation or lack of the CAP_SYS_TIME privilege.|
| settimeofday | User namespace isolation or lack of the CAP_SYS_TIME privilege.|
| adjtime | User namespace isolation or lack of the CAP_SYS_TIME privilege.|
| clock_settime | User namespace isolation or lack of the CAP_SYS_TIME privilege.|
| klogctl | User namespace isolation or lack of the CAP_SYS_ADMIN/CAP_SYSLOG privilege.|
