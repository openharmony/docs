# 命令行参数方式


对用户态进程进行内存相关的检查时，除了接口调用方式还可以通过命令行方式进行内存统计、内存泄漏或内存完整性检查。

```
--mwatch：初始化内存调测功能，注册信号。内存调测信息将从串口输出；
--mrecord <f_path>：初始化内存调测功能，注册信号。内存调测信息将保存至f_path文件，若f_path创建失败，则内存调测信息将从串口输出
```


在待调测的进程未退出时可使用信号机制获取对应信息:

```
kill -35 <pid> # 查看线程级堆内存占用
kill -36 <pid> # 检查是否存在堆内存泄漏
kill -37 <pid> # 检查堆内存头节点是否完整
```


## 示例代码

代码功能：构造内存问题利用命令行方式进行内存调测。


```
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_LEAK_SIZE  0x300

void func(void) {
    char *ptr = malloc(MALLOC_LEAK_SIZE);
    memset(ptr, '3', MALLOC_LEAK_SIZE);
}

int main()
{
    char *ptr = malloc(MALLOC_LEAK_SIZE);
    memset(ptr, '1', MALLOC_LEAK_SIZE);
    func();
    while (1);
}
```


## 编译

参考[接口调用一节](../kernel/kernel-small-debug-user-guide-use-api.md#编译)。


## 使用mwatch参数命令


```
OHOS # ./mem_check --mwatch // 利用task命令可以查到mem_check进程的pid为4
OHOS # 
OHOS # kill -35 4 // 查看堆内存统计信息
OHOS # 
==PID:4== Heap memory statistics(bytes):
    [Check point]:
        #00: <arm_signal_process+0x5c>[0x58dfc] -> /lib/libc.so

    [TID: 18, Used: 0x640]

==PID:4== Total heap: 0x640 byte(s), Peak: 0x640 byte(s)

OHOS # kill -36 4 // 检查是否存在堆内存泄漏
OHOS # 
==PID:4== Detected memory leak(s):
    [Check point]:
        #00: <check_leak+0x1c4>[0x2da4c] -> /lib/libc.so
        #01: <arm_signal_process+0x5c>[0x58dfc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <main+0x14>[0x724] -> mem_check
        #01: <(null)+0x2555a9dc>[0x219dc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <func+0x14>[0x6ec] -> mem_check
        #01: <main+0x30>[0x740] -> mem_check
        #02: <(null)+0x2555a9dc>[0x219dc] -> /lib/libc.so

==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).

OHOS # kill -37 4 // 检查堆内存头节点的完整性
OHOS # 
Check heap integrity ok!
```


## 调用栈解析

将调测信息保存至test.txt文件中，利用脚本进行解析，获取内存泄漏的具体行号。


```
$ ./parse_mem_info.sh test.txt mem_check
Compiler is [gcc/llvm]: llvm
Now using addr2line ...

==PID:4== Detected memory leak(s):
    [Check point]:
        #00: <check_leak+0x1c4>[0x2da4c] -> /lib/libc.so
        #01: <arm_signal_process+0x5c>[0x58dfc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <main+0x14>[0x724] at /usr1/xxx/TEST_ELF/mem_check.c:14
        #01: <(null)+0x2555a9dc>[0x219dc] -> /lib/libc.so

    [TID:18 Leak:0x320 byte(s)] Allocated from:
        #00: <func+0x14>[0x6ec] at /usr1/xxx/TEST_ELF/mem_check.c:8
        #01: <main+0x30>[0x740] at /usr1/xxx/TEST_ELF/mem_check.c:19
        #02: <(null)+0x2555a9dc>[0x219dc] -> /lib/libc.so

==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).
```


## 使用mrecord参数命令

1. 执行用户程序并指定记录内存调测信息的文件路径
  
   ```
   OHOS # ./mem_check --mrecord /storage/check.txt
   ```

2. 利用kill -35 &lt;pid&gt;统计内存信息，该信息将会输出到文件中，使用cat命令查看
  
   ```
   OHOS # kill -35 4
   OHOS # Memory statistics information saved in /storage/pid(4)_check.txt
   
   OHOS # cat /storage/pid(4)_check.txt
   
   ==PID:4== Heap memory statistics(bytes):
       [Check point]:
           #00: <arm_signal_process+0x5c>[0x5973c] -> /lib/libc.so
   
       [TID: 18, Used: 0x640]
   
   ==PID:4== Total heap: 0x640 byte(s), Peak: 0x640 byte(s)
   ```

3. 利用kill -36 &lt;pid&gt;校验内存完整性，该信息将会输出到文件中，使用cat命令查看
  
   ```
   OHOS # kill -36 4
   OHOS # Leak check information saved in /storage/pid(4)_check.txt
   
   OHOS # cat /storage/pid(4)_check.txt
   
   ==PID:4== Heap memory statistics(bytes):
       [Check point]:
           #00: <arm_signal_process+0x5c>[0x5973c] -> /lib/libc.so
   
       [TID: 18, Used: 0x640]
   
   ==PID:4== Total heap: 0x640 byte(s), Peak: 0x640 byte(s)
   
   ==PID:4== Detected memory leak(s):
       [Check point]:
           #00: <check_leak+0x1c4>[0x2e38c] -> /lib/libc.so
           #01: <arm_signal_process+0x5c>[0x5973c] -> /lib/libc.so
   
       [TID:18 Leak:0x320 byte(s)] Allocated from:
           #00: <main+0x14>[0x724] -> mem_check
           #01: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
   
       [TID:18 Leak:0x320 byte(s)] Allocated from:
           #00: <func+0x14>[0x6ec] -> mem_check
           #01: <main+0x30>[0x740] -> mem_check
           #02: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
   
   ==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).
   ```

4. 利用kill -9 &lt;pid&gt;杀掉当前进程，进程退出后会默认校验内存完整性，该信息将会输出到文件中，使用cat命令查看
  
   ```
   OHOS # kill -9 4
   OHOS # Leak check information saved in /storage/pid(4)_check.txt
   
   Check heap integrity ok!
   
   OHOS # cat /storage/pid(4)_check.txt
   OHOS # 
   ==PID:4== Heap memory statistics(bytes):
       [Check point]:
           #00: <arm_signal_process+0x5c>[0x5973c] -> /lib/libc.so
   
       [TID: 18, Used: 0x640]
   
   ==PID:4== Total heap: 0x640 byte(s), Peak: 0x640 byte(s)
   
   ==PID:4== Detected memory leak(s):
       [Check point]:
           #00: <check_leak+0x1c4>[0x2e38c] -> /lib/libc.so
           #01: <arm_signal_process+0x5c>[0x5973c] -> /lib/libc.so
   
       [TID:18 Leak:0x320 byte(s)] Allocated from:
           #00: <main+0x14>[0x724] -> mem_check
           #01: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
   
       [TID:18 Leak:0x320 byte(s)] Allocated from:
           #00: <func+0x14>[0x6ec] -> mem_check
           #01: <main+0x30>[0x740] -> mem_check
           #02: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
   
   ==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).
   
   ==PID:4== Detected memory leak(s):
       [Check point]:
           #00: <check_leak+0x1c4>[0x2e38c] -> /lib/libc.so
           #01: <exit+0x28>[0x11b2c] -> /lib/libc.so
   
       [TID:18 Leak:0x320 byte(s)] Allocated from:
           #00: <main+0x14>[0x724] -> mem_check
           #01: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
   
       [TID:18 Leak:0x320 byte(s)] Allocated from:
           #00: <func+0x14>[0x6ec] -> mem_check
           #01: <main+0x30>[0x740] -> mem_check
           #02: <(null)+0x1fdd231c>[0x2231c] -> /lib/libc.so
   
   ==PID:4== SUMMARY: 0x640 byte(s) leaked in 2 allocation(s).
   ```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 上述连续记录的信息会逐步追加到初始化时所指定的文件中，故最后cat文件时，文件中还包含历史记录的信息内容。
