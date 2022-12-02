# vmm


## 命令功能

查看进程的虚拟内存使用情况。


## 命令格式

- vmm [_-a / -h / --help_]

- vmm [_pid_]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| -a | 输出所有进程的虚拟内存使用情况。 | N/A | 
| -h&nbsp;\|&nbsp;--help | 命令格式说明。 | N/A | 
| pid | 进程ID，说明指定进程的虚拟内存使用情况。 | [0, 63] | 


## 使用指南

命令缺省输出所有进程的虚拟内存使用情况。


## 使用实例

举例：输入vmm 3


## 输出说明

**示例** PID为3的进程虚拟内存使用信息

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

**表2** 进程基本信息

| 输出 | 说明 | 
| -------- | -------- |
| PID | 进程ID | 
| aspace | 进程虚拟内存控制块地址信息 | 
| name | 进程名 | 
| base | 虚拟内存起始地址 | 
| size | 虚拟内存大小 | 
| pages | 已使用的物理页数量 | 

**表3** 虚拟内存区间信息

| 输出 | 说明 | 
| -------- | -------- |
| region | 虚拟区间控制块地址信息 | 
| name | 虚拟区间类型 | 
| base | 虚拟区间起始地址 | 
| size | 虚拟区间大小 | 
| mmu_flags | 虚拟区间mmu映射属性 | 
| pages | 已使用的物理页数量（包括共享内存部分） | 
| pg/ref | 已使用的物理页数量 | 
