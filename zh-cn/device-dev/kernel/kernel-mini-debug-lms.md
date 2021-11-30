# LMS调测

- [基本概念](#section1)

- [运行机制](#section2)

- [接口说明](#section3)

- [开发指导](#section4)

    - [开发流程](#section4.1.1)

    - [编程实例](#section4.1.2)

    - [实例代码](#section4.1.3)

    - [结果验证](#section4.1.4)


## 基本概念 <a name = "section1"></a>
LMS全称为Lite Memory Sanitizer，是一种实时检测内存操作合法性的调测工具。LMS能够实时检测缓冲区溢出（buffer overflow），释放后使用（use after free) 和重复释放（double Free), 在异常发生的第一时间通知操作系统，结合backtrace等定位手段，能准确定位到产生内存问题的代码行，极大提升内存问题定位效率。

## 运行机制<a name = "section2"></a>
LMS使用影子内存映射标记系统内存的状态，一共可标记为三个状态：可读写，不可读写，已释放。影子内存存放在内存池的尾部。

- 内存从堆上申请后，会将数据区的影子内存设置为“可读写”状态，并将头结点区的影子内存设置为“不可读写”状态。

- 内存在堆上被释放时，会将被释放内存的影子内存设置为“已释放”状态。

- 编译代码时，会在代码中的读写指令前插入检测函数，对地址的合法性进行检验。主要是检测访问内存的影子内存的状态值，若检测到影子内存为不可读写，则会报溢出错误；若检测到影子内存为已释放，则会报释放后使用错误。

- 在内存释放时，会检测被释放地址的影子内存状态值，若检测到影子内存非可读写，则会报重复释放错误。

## 接口说明<a name = "section3"></a>

OpenHarmony LiteOS-M内核的LMS模块提供下面几种功能，接口详细信息可以查看[API](https://gitee.com/openharmony/kernel_liteos_m/blob/master/components/lms/los_lms.h)参考。


1. 支持多内存池检测；

2. 支持LOS_MemAlloc、LOS_MemAllocAlign、LOS_MemRealloc申请出的内存检测；

3. 支持安全函数的访问检测（默认开启）；

4. 支持libc 高频函数的访问检测，包括：memset、memcpy、memmove、strcat、strcpy、strncat、strncpy。

5. 可动态设置的功能如下：

**表 1** LMS模块接口说明
<a name="lmsApi"></a>
<table><thead align="left"><tr id="row0"><th class="cellrowborder" valign="top" width="30%" id="mcps1.2.4.1.1"><p id="p0"><a name="p0"></a><a name="p0"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="28%" id="mcps1.2.4.1.2"><p id="p1"><a name="p1"></a><a name="p1"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="57.34573457345735%" id="mcps1.2.4.1.3"><p id="p2"><a name="p2"></a><a name="p2"></a>描述</p>
</th>
<tr id="row6"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15"><a name="p15"></a><a name="p15"></a>添加指定内存池被检测</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p16"><a name="p16"></a><a name="p16"></a>LOS_LmsCheckPoolAdd</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.3 "><p id="p17"><a name="p17"></a><a name="p17"></a>将指定内存池的地址范围添加到LMS的内存检测链表上，当访问的地址在链表范围内时，LMS才进行合法性校验；且LOS_MemInit接口会调用该接口，默认将初始化的内存池挂入到检测链表中。</p>
</td>
</tr>
<tr id="row7"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18"><a name="p18"></a><a name="p18"></a>删除指定内存池不被检测</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19"><a name="p19"></a><a name="p19"></a>LOS_LmsCheckPoolDel</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.3 "><p id="p20"><a name="p20"></a><a name="p20"></a>不检测指定内存池地址范围内的合法性校验。</p>
</td>
</tr>
<tr id="row7"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18"><a name="p18"></a><a name="p18"></a>使能指定内存段锁保护</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19"><a name="p19"></a><a name="p19"></a>LOS_LmsAddrProtect</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.3 "><p id="p20"><a name="p20"></a><a name="p20"></a>为某段内存地址上锁，设置为不可读写，一旦访问则报错。</p>
</td>
</tr>
<tr id="row7"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18"><a name="p18"></a><a name="p18"></a>去能指定内存段锁保护</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19"><a name="p19"></a><a name="p19"></a>LOS_LmsAddrDisableProtect</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.3 "><p id="p20"><a name="p20"></a><a name="p20"></a>为某段内存地址解锁，设置为可读写。</p>
</td>
</tr>
</tbody>
</table>


## 开发指导<a name = "section4"></a>

### 开发流程<a name = "section4.1.1"></a>

开启LMS调测的典型流程如下：

1. 配置LMS模块相关宏。

    配置LMS控制宏LOSCFG_KERNEL_LMS，默认关，在kernel/liteos_a目录下执行 make update_config命令配置"Kernel->Enable Lite Memory Sanitizer"中打开：

    | 配置项                         | menuconfig选项                                               | 含义                                                         | 设置值 |
    | ------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------ |
    | LOSCFG_KERNEL_LMS            | Enable Lms Feature                                         | Lms模块的裁剪开关                                          | YES/NO |
    | LOSCFG_LMS_MAX_RECORD_POOL_NUM   | Lms check pool max num                               | LMS支持的检测内存池最大个数                                      | INT |
    | LOSCFG_LMS_LOAD_CHECK    | Enable lms read check                                | LMS内存读检测的裁剪开关                                      | YES/NO |
    | LOSCFG_LMS_STORE_CHECK   | Enable lms write check                | LMS内存写检测的裁剪开关 | YES/NO |
    | LOSCFG_LMS_CHECK_STRICT    | Enable lms strict check, byte-by-byte | LMS内存逐字节严格检测的裁剪开关                              | YES/NO |

2. 在被检测模块的编译脚本中，增加LMS检测编译选项-fsanitize=kernel-address。

3. 为避免编译器优化，增加-O0编译选项。

4. gcc与clang编译选项存在差异，参照如下示例：

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

5. 重新编译，查看串口输出。如果检测到内存问题，会输出检测结果。

### 编程实例<a name = "section4.1.2"></a>

   本实例实现如下功能：

   1. 创建一个用于Lms测试的任务。

   2. 构造内存溢出错误和释放后使用错误。
   
   3. 添加-fsanitize=kernel-address后编译执行，观察输出结果

### 示例代码<a name = "section4.1.3"></a>

实例代码如下：

```C
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
    LOS_MemFree(g_testLmsPool, str);
    PRINTK("str[%2d]=0x%2x ", 0, str[0]); /* trigger use after free at str[0] */
    PRINTK("\n######%s stop ######\n", __FUNCTION__);
}

VOID LmsTestCaseTask(VOID)
{ 
    testPoolInit();
    LmsTestOsmallocOverflow();
    LmsTestUseAfterFree();
}

UINT32 Example_Lms_test(VOID){
    UINT32 ret;    
    TSK_INIT_PARAM_S lmsTestTask;    
    /* 创建用于lms测试的任务 */    
    memset(&lmsTestTask, 0, sizeof(TSK_INIT_PARAM_S));    
    lmsTestTask.pfnTaskEntry = (TSK_ENTRY_FUNC)LmsTestCaseTask;
    lmsTestTask.pcName       = "TestLmsTsk";    /* 测试任务名称 */    				     
    lmsTestTask.uwStackSize  = 0x800;    
    lmsTestTask.usTaskPrio   = 5;    
    lmsTestTask.uwResved   = LOS_TASK_STATUS_DETACHED;    
    ret = LOS_TaskCreate(&g_lmsTestTaskId, &lmsTestTask);    
    if(ret != LOS_OK){        
        PRINT_ERR("LmsTestTask create failed .\n");        
        return LOS_NOK;    
    } 
    return LOS_OK;
}
```

### 结果验证<a name = "section4.1.4"></a>

输出结果如下：

```c
######LmsTestOsmallocOverflow start ######
[ERR]*****  Kernel Address Sanitizer Error Detected Start *****
[ERR]Heap buffer overflow error detected
[ERR]Illegal READ address at: [0x4157a3c8]
[ERR]Shadow memory address: [0x4157be3c : 4]  Shadow memory value: [2]
OsBackTrace fp = 0x402c0f88
runTask->taskName = LmsTestCaseTask
runTask->taskID = 2
*******backtrace begin*******
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
[ERR]*****  Kernel Address Sanitizer Error Detected End *****
str[20]=0xffffffba
######LmsTestOsmallocOverflow stop ######

###### LmsTestUseAfterFree start ######
[ERR]*****  Kernel Address Sanitizer Error Detected Start *****
[ERR]Use after free error detected
[ERR]Illegal READ address at: [0x4157a3d4]
[ERR]Shadow memory address: [0x4157be3d : 2]  Shadow memory value: [3]
OsBackTrace fp = 0x402c0f90
runTask->taskName = LmsTestCaseTask
runTask->taskID = 2
*******backtrace begin*******
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
[ERR]*****  Kernel Address Sanitizer Error Detected End *****
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
