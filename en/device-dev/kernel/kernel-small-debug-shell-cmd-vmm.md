# vmm


## Command Function

This command is used to query the virtual memory used by a process.


## Syntax

- vmm [_-a / -h / --help_]

- vmm [_pid_]


## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range| 
| -------- | -------- | -------- |
| -a | Displays the virtual memory usage of all processes.| N/A | 
| -h&nbsp;\|&nbsp;--help | Displays help information.| N/A | 
| pid | Specifies the ID of the process to query.| [0, 63] | 


## Usage Guidelines

By default, this command displays the virtual memory usage of all processes.


## Example

Run **vmm 3**.


## Output

Virtual memory usage of process 3:

```
OHOS # vmm 3
 PID    aspace     name       base       size     pages
 ----   ------     ----       ----       -----     ----
 3    0x408c0118 foundation 0x01000000 0x3e000000     800
         region      name                base       size       mmu_flags      pages   pg/ref
         ------      ----                ----       ----       ---------      -----   -----
         0x408cb364  /bin/foundation                  0x06da3000 0x00001000  CH US RD          1       1
         0x408cb80c  /bin/foundation                  0x06da4000 0x00001000  CH US RD EX       1       1
         0x408cb720  /bin/foundation                  0x06da5000 0x00001000  CH US RD          1       1
         0x408cb9a8  /bin/foundation                  0x06da6000 0x00001000  CH US RD WR       1       1
         0x413efde4  HEAP                             0x12b43000 0x00015000  CH US RD WR      19      19
         0x408c3d34  /lib/libc.so                     0x23b08000 0x0004a000  CH US RD         25       2
         0x408cbd44  /lib/libc.so                     0x23b52000 0x00068000  CH US RD EX      58      10
         0x408c3dc0  /lib/libc.so                     0x23bba000 0x00002000  CH US RD WR       2       2
         0x408cc128  /lib/libc.so                     0x23bbc000 0x00002000  CH US RD WR       2       2
         0x408d1634  MMAP                             0x23bbe000 0x00005000  CH US RD WR       5       5
         0x408c4e10  VDSO                             0x23bc3000 0x00002000  CH US RD EX       2       2
         0x408dbaec  /lib/libc++.so                   0x23bc5000 0x00046000  CH US RD         51       5
         0x408deba8  /lib/libc++.so                   0x23c0b000 0x0009f000  CH US RD EX      29      10
         0x408debf4  /lib/libc++.so                   0x23caa000 0x00006000  CH US RD          6       6
         0x408c3ce0  /lib/libc++.so                   0x23cb0000 0x00001000  CH US RD WR       1       1
```

**Table 2** Basic process information

| Parameter| Description| 
| -------- | -------- |
| PID | Process ID.| 
| aspace | Address of the virtual memory control block.| 
| name | Process name.| 
| base | Start address of the virtual memory.| 
| size | Total Virtual Memory.| 
| pages | Number of used physical pages.| 

**Table 3** Virtual memory interval information

| Parameter| Description| 
| -------- | -------- |
| region | Address of the control block in the virtual memory region.| 
| name | Name of the virtual memory region.| 
| base | Start address of the virtual memory region.| 
| size | Size of the virtual memory region.| 
| mmu_flags | MMU mapping attribute of the virtual memory region.| 
| pages | Number of used physical pages, including that of the shared memory.| 
| pg/ref | Number of used physical pages.| 
