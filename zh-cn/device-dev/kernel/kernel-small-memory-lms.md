# LMS调测


## 基本概念

LMS全称为Lite Memory Sanitizer，是一种实时检测内存操作合法性的调测工具。LMS能够实时检测缓冲区溢出（buffer overflow），释放后使用（use after free) 和重复释放（double free), 在异常发生的第一时间通知操作系统，结合backtrace等定位手段，能准确定位到产生内存问题的代码行，极大提升内存问题定位效率。

OpenHarmony LiteOS-A内核的LMS模块提供下面几种功能：

- 支持多内存池检测；

- 支持LOS_MemAlloc、LOS_MemAllocAlign、LOS_MemRealloc申请出的内存检测；

- 支持安全函数的访问检测（默认开启）；

- 支持libc 高频函数的访问检测，包括：memset、memcpy、memmove、strcat、strcpy、strncat、strncpy。


## 运行机制

LMS使用影子内存映射标记系统内存的状态，一共可标记为三个状态：可读写，不可读写，已释放。影子内存存放在内存池的尾部。

- 内存从堆上申请后，会将数据区的影子内存设置为“可读写”状态，并将头节点区的影子内存设置为“不可读写”状态。

- 内存在堆上被释放时，会将被释放内存的影子内存设置为“已释放”状态。

- 编译代码时，会在代码中的读写指令前插入检测函数，对地址的合法性进行检验。主要是检测访问内存的影子内存的状态值，若检测到影子内存为不可读写，则会报溢出错误；若检测到影子内存为已释放，则会报释放后使用错误。

- 在内存释放时，会检测被释放地址的影子内存状态值，若检测到影子内存非可读写，则会报重复释放错误。


## 接口说明


### 内核态

OpenHarmony LiteOS-A内核的LMS模块提供下面几种功能，接口详细信息可以查看[API](https://gitee.com/openharmony/kernel_liteos_a/blob/master/kernel/include/los_lms.h)参考。

  **表1** LMS模块接口说明

| 功能分类 | 接口名 | 描述 |
| -------- | -------- | -------- |
| 添加指定内存池被检测 | LOS_LmsCheckPoolAdd | 将指定内存池的地址范围添加到LMS的内存检测链表上，当访问的地址在链表范围内时，LMS才进行合法性校验；且LOS_MemInit接口会调用该接口，默认将初始化的内存池挂入到检测链表中。 |
| 删除指定内存池不被检测 | LOS_LmsCheckPoolDel | 不检测指定内存池地址范围内的合法性校验。 |
| 使能指定内存段锁保护 | LOS_LmsAddrProtect | 为某段内存地址上锁，设置为不可读写，一旦访问则报错。 |
| 去能指定内存段锁保护 | LOS_LmsAddrDisableProtect | 为某段内存地址解锁，设置为可读写。 |


### 用户态

用户态仅提供LMS检测库，不提供对外接口。


## 开发指导


### 内核态开发流程

开启LMS调测的典型流程如下：

1. 配置LMS模块相关宏。
   配置LMS控制宏LOSCFG_KERNEL_LMS，默认关，在kernel/liteos_a目录下执行 make update_config命令配置"Kernel-&gt;Enable Lite Memory Sanitizer"中打开YES：

     | 宏 | menuconfig选项 | 含义 | 取值 |
   | -------- | -------- | -------- | -------- |
   | LOSCFG_KERNEL_LMS | Enable&nbsp;Lms&nbsp;Feature | Lms模块的裁剪开关 | YES/NO |
   | LOSCFG_LMS_MAX_RECORD_POOL_NUM | Lms&nbsp;check&nbsp;pool&nbsp;max&nbsp;num | LMS支持的检测内存池最大个数 | INT |
   | LOSCFG_LMS_LOAD_CHECK | Enable&nbsp;lms&nbsp;read&nbsp;check | LMS内存读检测的裁剪开关 | YES/NO |
   | LOSCFG_LMS_STORE_CHECK | Enable&nbsp;lms&nbsp;write&nbsp;check | LMS内存写检测的裁剪开关 | YES/NO |
   | LOSCFG_LMS_CHECK_STRICT | Enable&nbsp;lms&nbsp;strict&nbsp;check,&nbsp;byte-by-byte | LMS内存逐字节严格检测的裁剪开关 | YES/NO |

2. 在被检测模块的编译脚本中，修改编译选项。
   增加LMS检测编译选项-fsanitize=kernel-address。为避免编译器优化，增加-O0编译选项。

     gcc与clang编译选项存在差异，参照如下示例：

   ```
   if ("$ohos_build_compiler_specified" == "gcc") {
       cflags_c = [
       "-O0",
       "-fsanitize=kernel-address",
       ]
   } else {
       cflags_c = [
       "-O0",
       "-fsanitize=kernel-address",
       "-mllvm",
       "-asan-instrumentation-with-call-threshold=0",
       "-mllvm",
       "-asan-stack=0",
       "-mllvm",
       "-asan-globals=0",
       ]
   }
   ```

3. 重新编译，查看串口输出。如果检测到内存问题，会输出检测结果。


#### 内核态编程实例

本实例实现如下功能：

1. 创建一个用于Lms测试的任务。

2. 构造内存溢出错误和释放后使用错误。

3. 添加-fsanitize=kernel-address后编译执行，观察输出结果。


#### 内核态示例代码

  该示例代码的测试函数可以加在 kernel /liteos_a/testsuites /kernel /src /osTest.c  中的 TestTaskEntry 中进行测试。
  实例代码如下：

```c
#define PAGE_SIZE       (0x1000U)
#define INDEX_MAX       20
UINT32 g_lmsTestTaskId;
char g_testLmsPool[2 * PAGE_SIZE];
STATIC VOID testPoolInit(void)
{
    UINT32 ret = LOS_MemInit(g_testLmsPool, 2 * PAGE_SIZE);
    if (ret != 0) {
        PRINT_ERR("%s failed, ret = 0x%x\n", __FUNCTION__, ret);
        return;
    }
}
static VOID LmsTestOsmallocOverflow(VOID)
{
    PRINTK("\n######%s start ######\n", __FUNCTION__);
    UINT32 i;
    CHAR *str = (CHAR *)LOS_MemAlloc(g_testLmsPool, INDEX_MAX);
    PRINTK("str[%2d]=0x%2x ", INDEX_MAX, str[INDEX_MAX]); /* trigger heap overflow at str[INDEX_MAX] */
    PRINTK("\n######%s stop ######\n", __FUNCTION__);
}
static VOID LmsTestUseAfterFree(VOID)
{
    PRINTK("\n######%s start ######\n", __FUNCTION__);
    UINT32 i;
    CHAR *str = (CHAR *)LOS_MemAlloc(g_testLmsPool, INDEX_MAX);
    (VOID)LOS_MemFree(g_testLmsPool, str);
    PRINTK("str[%2d]=0x%2x ", 0, str[0]); /* trigger use after free at str[0] */
    PRINTK("\n######%s stop ######\n", __FUNCTION__);
}
VOID LmsTestCaseTask(VOID)
{
    testPoolInit();
    LmsTestOsmallocOverflow();
    LmsTestUseAfterFree();
}
UINT32 Example_Lms_test(VOID)
{
    UINT32 ret;
    TSK_INIT_PARAM_S lmsTestTask;
    /* 创建用于lms测试的任务 */
    memset(&lmsTestTask, 0, sizeof(TSK_INIT_PARAM_S));
    lmsTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)LmsTestCaseTask;
    lmsTestTask.pcName       = "TestLmsTsk";    /* 测试任务名称 */
    lmsTestTask.uwStackSize  = 0x800; // 0x800: lms test task stack size
    lmsTestTask.usTaskPrio   = 5; // 5: lms test task priority
    lmsTestTask.uwResved   = LOS_TASK_STATUS_DETACHED;
    ret = LOS_TaskCreate(&g_lmsTestTaskId, &lmsTestTask);
    if (ret != LOS_OK) {
        PRINT_ERR("LmsTestTask create failed .\n");
        return LOS_NOK;
    }
    return LOS_OK;
}
LOS_MODULE_INIT(Example_Lms_test, LOS_INIT_LEVEL_KMOD_EXTENDED);
```


#### 内核态结果验证

  输出结果如下：

```
######LmsTestOsmallocOverflow start ######
[ERR][KProcess:LmsTestCaseTask]*  Kernel Address Sanitizer Error Detected Start *
[ERR][KProcess:LmsTestCaseTask]Heap buffer overflow error detected
[ERR][KProcess:LmsTestCaseTask]Illegal READ address at: [0x4157a3c8]
[ERR][KProcess:LmsTestCaseTask]Shadow memory address: [0x4157be3c : 4]  Shadow memory value: [2]
OsBackTrace fp = 0x402c0f88
runTask->taskName = LmsTestCaseTask
runTask->taskID = 2
***backtrace begin***
traceback fp fixed, trace using   fp = 0x402c0fd0
traceback 0 -- lr = 0x400655a4    fp = 0x402c0ff8
traceback 1 -- lr = 0x40065754    fp = 0x402c1010
traceback 2 -- lr = 0x40044bd0    fp = 0x402c1038
traceback 3 -- lr = 0x40004e14    fp = 0xcacacaca
[LMS] Dump info around address [0x4157a3c8]:
        [0x4157a3a0]:  00  00  00  00  00  00  00  00 | [0x4157be3a |  0]:  1  1
        [0x4157a3a8]:  ba  dc  cd  ab  00  00  00  00 | [0x4157be3a |  4]:  2  2
        [0x4157a3b0]:  20  00  00  80  00  00  00  00 | [0x4157be3b |  0]:  2  0
        [0x4157a3b8]:  00  00  00  00  00  00  00  00 | [0x4157be3b |  4]:  0  0
        [0x4157a3c0]:  00  00  00  00  00  00  00  00 | [0x4157be3c |  0]:  0  0
        [0x4157a3c8]: [ba] dc  cd  ab  a8  a3  57  41 | [0x4157be3c |  4]: [2] 2
        [0x4157a3d0]:  2c  1a  00  00  00  00  00  00 | [0x4157be3d |  0]:  2  3
        [0x4157a3d8]:  00  00  00  00  00  00  00  00 | [0x4157be3d |  4]:  3  3
        [0x4157a3e0]:  00  00  00  00  00  00  00  00 | [0x4157be3e |  0]:  3  3
        [0x4157a3e8]:  00  00  00  00  00  00  00  00 | [0x4157be3e |  4]:  3  3
        [0x4157a3f0]:  00  00  00  00  00  00  00  00 | [0x4157be3f |  0]:  3  3
[ERR][KProcess:LmsTestCaseTask]*  Kernel Address Sanitizer Error Detected End *
str[20]=0xffffffba
######LmsTestOsmallocOverflow stop ######
###### LmsTestUseAfterFree start ######
[ERR][KProcess:LmsTestCaseTask]*  Kernel Address Sanitizer Error Detected Start *
[ERR][KProcess:LmsTestCaseTask]Use after free error detected
[ERR][KProcess:LmsTestCaseTask]Illegal READ address at: [0x4157a3d4]
[ERR][KProcess:LmsTestCaseTask]Shadow memory address: [0x4157be3d : 2]  Shadow memory value: [3]
OsBackTrace fp = 0x402c0f90
runTask->taskName = LmsTestCaseTask
runTask->taskID = 2
***backtrace begin***
traceback fp fixed, trace using   fp = 0x402c0fd8
traceback 0 -- lr = 0x40065680    fp = 0x402c0ff8
traceback 1 -- lr = 0x40065758    fp = 0x402c1010
traceback 2 -- lr = 0x40044bd0    fp = 0x402c1038
traceback 3 -- lr = 0x40004e14    fp = 0xcacacaca
[LMS] Dump info around address [0x4157a3d4]:
        [0x4157a3a8]:  ba  dc  cd  ab  00  00  00  00 | [0x4157be3a |  4]:  2  2
        [0x4157a3b0]:  20  00  00  80  00  00  00  00 | [0x4157be3b |  0]:  2  0
        [0x4157a3b8]:  00  00  00  00  00  00  00  00 | [0x4157be3b |  4]:  0  0
        [0x4157a3c0]:  00  00  00  00  00  00  00  00 | [0x4157be3c |  0]:  0  0
        [0x4157a3c8]:  ba  dc  cd  ab  a8  a3  57  41 | [0x4157be3c |  4]:  2  2
        [0x4157a3d0]:  2c  1a  00  00 [00] 00  00  00 | [0x4157be3d |  0]:  2 [3]
        [0x4157a3d8]:  00  00  00  00  00  00  00  00 | [0x4157be3d |  4]:  3  3
        [0x4157a3e0]:  00  00  00  00  00  00  00  00 | [0x4157be3e |  0]:  3  3
        [0x4157a3e8]:  ba  dc  cd  ab  c8  a3  57  41 | [0x4157be3e |  4]:  2  2
        [0x4157a3f0]:  0c  1a  00  00  00  00  00  00 | [0x4157be3f |  0]:  2  3
        [0x4157a3f8]:  00  00  00  00  00  00  00  00 | [0x4157be3f |  4]:  3  3
[ERR][KProcess:LmsTestCaseTask]*  Kernel Address Sanitizer Error Detected End *
str[ 0]=0x 0
######LmsTestUseAfterFree stop ######
```

输出的关键信息包括：

- 错误类型：
  - Heap buffer overflow堆内存越界
  - Use after free 释放后使用

- 错误操作：
  - Illegal Read非法读
  - Illegal Write非法写
  - Illegal Double free重复释放

- 上下文：
  - 当前任务信息（taskName， taskId）
  - 回溯栈(backtrace)

- 出错地址的内存信息：
  - 内存的值、及对应影子内存的值
  - 内存地址：内存值| [影子内存地址 | 影子内存字节内偏移]:影子内存值
  - 影子内存值：0（可读可写）、3（已释放）、2（红区）、1（填充值）。


### 用户态开发流程

在待检测的app编译脚本中，添加如下参数即可， 完整示例可参见 [/kernel/liteos_a/apps/lms/BUILD.gn](https://gitee.com/openharmony/kernel_liteos_a/blob/master/apps/lms/BUILD.gn)。


```
if ("$ohos_build_compiler_specified" == "gcc") {
        cflags_c = [
        "-O0",
        "-fsanitize=kernel-address",
        "-funwind-tables",
        "-fasynchronous-unwind-tables",
        ]
    } else {
        cflags_c = [
            "-O0",
            "-fsanitize=kernel-address",
            "-mllvm",
            "-asan-instrumentation-with-call-threshold=0",
            "-mllvm",
            "-asan-stack=0",
            "-mllvm",
            "-asan-globals=0",
            "-funwind-tables",
            "-fasynchronous-unwind-tables",
        ]
  }
  ldflags = [
    "-rdynamic",
    "-lunwind",
    "-lusrlms",
    "-Wl,--wrap=realloc",
    "-Wl,--wrap=calloc",
    "-Wl,--wrap=malloc",
    "-Wl,--wrap=free",
    "-Wl,--wrap=valloc",
    "-Wl,--wrap=aligned_alloc",
    "-Wl,--wrap=memset",
    "-Wl,--wrap=memcpy",
    "-Wl,--wrap=memmove",
    "-Wl,--wrap=strcpy",
    "-Wl,--wrap=strcat",
  ]
  deps = [ "//kernel/liteos_a/kernel/extended/lms/usr:usrlmslib" ]
```


#### 用户态编程实例

本实例实现如下功能：

1. 构造内存溢出错误和释放后使用错误。

2. 添加对应编译选项后，重新编译执行。


#### 用户态示例代码

  实例代码如下：

```c
static void BufWriteTest(void *buf, int start, int end)
{
    for (int i = start; i <= end; i++) {
        ((char *)buf)[i] = 'a';
    }
}
static void BufReadTest(void *buf, int start, int end)
{
    char tmp;
    for (int i = start; i <= end; i++) {
        tmp = ((char *)buf)[i];
    }
}
static void LmsMallocTest(void)
{
    printf("\n-------- LmsMallocTest Start --------\n");
    char *buf = (char *)malloc(16); // 16: buffer size for test
    BufReadTest(buf, -1, 16);
    free(buf);
    printf("\n-------- LmsMallocTest End --------\n");
}
static void LmsFreeTest(void)
{
    printf("\n-------- LmsFreeTest Start --------\n");
    char *buf = (char *)malloc(16); // 16: buffer size for test
    free(buf);
    BufReadTest(buf, 1, 1);
    free(buf);
    printf("\n-------- LmsFreeTest End --------\n");
}
int main(int argc, char * const * argv)
{
    printf("\n############### Lms Test start ###############\n");
    char *tmp = (char *)malloc(5000); // 5000: temp buffer size
    LmsMallocTest();
    LmsFreeTest();
    printf("\n############### Lms Test End ###############\n");
}
```


#### 用户态结果验证

  输出结果如下：

```
*  Lite Memory Sanitizer Error Detected  *
Heap buffer overflow error detected!
Illegal READ address at: [0x1f8b3edf]
Shadow memory address: [0x3d34d3ed : 6]  Shadow memory value: [2]
Accessible heap addr     0
Heap red zone            2
Heap freed buffer        3
Dump info around address [0x1f8b3edf]:
        [0x1f8b3eb8]:  74  55  8b  1f  74  55  8b  1f | [0x3d34d3eb |  4]:  0  0
        [0x1f8b3ec0]:  f8  9c  8b  1f  00  00  00  00 | [0x3d34d3ec |  0]:  0  0
        [0x1f8b3ec8]:  00  00  00  00  9c  fc  fc  fc | [0x3d34d3ec |  4]:  0  0
        [0x1f8b3ed0]:  21  00  00  00  41  00  00  00 | [0x3d34d3ed |  0]:  0  0
        [0x1f8b3ed8]:  60  55  8b  1f  60  55  8b [1f]| [0x3d34d3ed |  4]:  2 [2]
        [0x1f8b3ee0]:  50  4e  0b  00  00  00  00  00 | [0x3d34d3ee |  0]:  0  0
        [0x1f8b3ee8]:  09  00  00  00  00  00  00  00 | [0x3d34d3ee |  4]:  0  0
        [0x1f8b3ef0]:  00  00  00  00  08  03  09  00 | [0x3d34d3ef |  0]:  2  2
        [0x1f8b3ef8]:  00  00  00  00  00  00  00  00 | [0x3d34d3ef |  4]:  2  2
*  Lite Memory Sanitizer Error Detected End *
Backtrace() returned 5 addresses
    #01: <LMS_ReportError+0x284>[0x4d6c] -> ./sample_usr_lms
    #02: <(null)+0x2004074>[0x4074] -> ./sample_usr_lms
    #03: <(null)+0x2003714>[0x3714] -> ./sample_usr_lms
    #04: <main+0x40>[0x363c] -> ./sample_usr_lms
    #05: <(null)+0x1f856f30>[0x56f30] -> /lib/libc.so
-------- LMS_malloc_test End --------
*  Lite Memory Sanitizer Error Detected  *
Use after free error detected!
Illegal Double free address at: [0x1f8b3ee0]
Shadow memory address: [0x3d34d3ee : 0]  Shadow memory value: [3]
Accessible heap addr     0
Heap red zone            2
Heap freed buffer        3
Dump info around address [0x1f8b3ee0]:
        [0x1f8b3ec0]:  f8  9c  8b  1f  00  00  00  00 | [0x3d34d3ec |  0]:  0  0
        [0x1f8b3ec8]:  00  00  00  00  fc  fd  fc  fc | [0x3d34d3ec |  4]:  0  0
        [0x1f8b3ed0]:  21  00  00  00  20  01  00  00 | [0x3d34d3ed |  0]:  0  0
        [0x1f8b3ed8]:  60  55  8b  1f  60  55  8b  1f | [0x3d34d3ed |  4]:  2  2
        [0x1f8b3ee0]: [20] 60  9a  1f  40  61  9a  1f | [0x3d34d3ee |  0]: [3] 3
        [0x1f8b3ee8]:  60  62  9a  1f  80  63  9a  1f | [0x3d34d3ee |  4]:  3  3
        [0x1f8b3ef0]:  20  40  8b  1f  20  20  8b  1f | [0x3d34d3ef |  0]:  3  3
        [0x1f8b3ef8]:  00  00  00  00  00  00  00  00 | [0x3d34d3ef |  4]:  3  3
        [0x1f8b3f00]:  00  00  00  00  00  00  00  00 | [0x3d34d3f0 |  0]:  3  3
*  Lite Memory Sanitizer Error Detected End *
Backtrace() returned 5 addresses
    #01: <LMS_ReportError+0x284>[0x4d6c] -> ./sample_usr_lms
    #02: <LMS_free+0xcc>[0x5548] -> ./sample_usr_lms
    #03: <(null)+0x2003fc4>[0x3fc4] -> ./sample_usr_lms
    #04: <main+0x68>[0x3664] -> ./sample_usr_lms
    #05: <(null)+0x1f856f30>[0x56f30] -> /lib/libc.so
-------- LMS_free_test End --------
```

输出的Backtrace中包含地址所在的文件名，用户需查找对应文件中地址对应的代码行号。
