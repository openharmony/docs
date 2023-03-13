# Native Api Symbols That May Invoke Failed Because of Permission Control

| Symbols | Possiable Reason |
| --- | --- |
| mlockall | usr namespace isolation or lack of CAP_IPC_LOCK privilege |
| swapon | usr namespace isolation |
| swapoff | usr namespace isolation |
| stime | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| settimeofday | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| adjtime | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| clock_settime | usr namespace isolation or lack of CAP_SYS_TIME privilege |
| klogctl | usr namespace isolation or lack of CAP_SYS_ADMIN/CAP_SYSLOG privilege |