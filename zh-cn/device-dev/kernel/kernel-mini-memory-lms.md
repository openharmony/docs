# LMS调测

## 基本概念

LMS（Lite Memory Sanitizer）是一种实时检测内存操作合法性的调测工具。LMS能够实时检测缓冲区溢出（buffer overflow），释放后使用（use after free) 和重复释放（double free)，在异常发生的第一时间通知操作系统，结合backtrace等定位手段，能准确定位到产生内存问题的代码行，极大提升内存问题定位效率。

OpenHarmony LiteOS-M内核的LMS模块提供下面几种功能：

- 支持多内存池检测。

- 支持LOS_MemAlloc、LOS_MemAllocAlign、LOS_MemRealloc申请出的内存检测。

- 支持安全函数的访问检测（默认开启）。

- 支持libc 高频函数的访问检测，包括：memset、memcpy、memmove、strcat、strcpy、strncat、strncpy。

## 运行机制

LMS使用影子内存映射标记系统内存的状态，一共可标记为三个状态：可读写，不可读写，已释放。影子内存存放在内存池的尾部。

- 内存从堆上申请后，会将数据区的影子内存设置为“可读写”状态，并将头结点区的影子内存设置为“不可读写”状态。

- 内存在堆上被释放时，会将被释放内存的影子内存设置为“已释放”状态。

- 编译代码时，会在代码中的读写指令前插入检测函数，对地址的合法性进行检验。主要是检测访问内存的影子内存的状态值，若检测到影子内存为不可读写，则会报溢出错误；若检测到影子内存为已释放，则会报释放后使用错误。

- 在内存释放时，会检测被释放地址的影子内存状态值，若检测到影子内存非可读写，则会报重复释放错误。

## 接口说明

OpenHarmony LiteOS-M内核的LMS模块提供下面几种功能，接口详细信息可以查看[API](https://gitee.com/openharmony/kernel_liteos_m/blob/master/components/lms/los_lms.h)参考。

  **表1** LMS模块接口说明

| 功能分类 | 接口名 | 描述 | 
| -------- | -------- | -------- |
| 添加指定内存池被检测 | LOS_LmsCheckPoolAdd | 将指定内存池的地址范围添加到LMS的内存检测链表上，当访问的地址在链表范围内时，LMS才进行合法性校验；且LOS_MemInit接口会调用该接口，默认将初始化的内存池挂入到检测链表中。 | 
| 删除指定内存池不被检测 | LOS_LmsCheckPoolDel | 不检测指定内存池地址范围内的合法性校验。 | 
| 使能指定内存段锁保护 | LOS_LmsAddrProtect | 为某段内存地址上锁，设置为不可读写，一旦访问则报错。 | 
| 去能指定内存段锁保护 | LOS_LmsAddrDisableProtect | 为某段内存地址解锁，设置为可读写。 | 

## 开发指导

### 开发流程

开启LMS调测的典型流程如下：

1. 配置LMS模块相关宏。
   配置LMS控制宏LOSCFG_KERNEL_LMS，默认关，在kernel/liteos_m目录下执行 make menuconfig命令配置"Kernel-&gt;Enable Lite Memory Sanitizer"中打开YES（如果没有这个选项，需要先勾选Enable Backtrace）：

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

### 编程实例

本实例实现如下功能：

1. 创建一个用于Lms测试的任务。

2. 构造内存溢出错误和释放后使用错误。

3. 添加-fsanitize=kernel-address后编译执行，观察输出结果。

### 示例代码

  实例代码如下：

  本演示代码在 ./kernel/liteos_m/testsuites/src/osTest.c 中编译验证，在TestTaskEntry中调用验证入口函数Example_Lms_test。

   请按上文避免编译器优化一节内容，修改osTest.c对应的 ./kernel/liteos_m/testsuites/BUILD.gn。

```
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

### 结果验证

  输出结果示例如下 (根据实际运行环境，数据会有差异)：

```
######LmsTestOsmallocOverflow start ######
[ERR][TestLmsTsk]*****  Kernel Address Sanitizer Error Detected Start *****
[ERR][TestLmsTsk]Heap buffer overflow error detected
[ERR][TestLmsTsk]Illegal READ address at: [0x21040414]
[ERR][TestLmsTsk]Shadow memory address: [0x21041e84 : 6]  Shadow memory value: [2]
psp, start = 21057d88, end = 21057e80
taskName = TestLmsTsk
taskID   = 5
----- traceback start -----
traceback 0 -- lr = 0x210099f4
traceback 1 -- lr = 0x2101da6e
traceback 2 -- lr = 0x2101db38
traceback 3 -- lr = 0x2101c494
----- traceback end -----

[LMS] Dump info around address [0x21040414]:

        [0x21040390]:  00  00  00  00  00  00  00  00 | [0x21041e7c |  4]:  1  1
        [0x21040398]:  00  00  00  00  00  00  00  00 | [0x21041e7d |  0]:  1  1
        [0x210403a0]:  00  00  00  00  00  00  00  00 | [0x21041e7d |  4]:  1  1
        [0x210403a8]:  00  00  00  00  00  00  00  00 | [0x21041e7e |  0]:  1  1
        [0x210403b0]:  00  00  00  00  00  00  00  00 | [0x21041e7e |  4]:  1  1
        [0x210403b8]:  00  00  00  00  00  00  00  00 | [0x21041e7f |  0]:  1  1
        [0x210403c0]:  00  00  00  00  00  00  00  00 | [0x21041e7f |  4]:  1  1
        [0x210403c8]:  00  00  00  00  00  00  00  00 | [0x21041e80 |  0]:  1  1
        [0x210403d0]:  00  00  00  00  00  00  00  00 | [0x21041e80 |  4]:  1  1
        [0x210403d8]:  00  00  00  00  00  00  00  00 | [0x21041e81 |  0]:  1  1
        [0x210403e0]:  00  00  00  00  00  00  00  00 | [0x21041e81 |  4]:  1  1
        [0x210403e8]:  00  00  00  00  00  00  00  00 | [0x21041e82 |  0]:  1  1
        [0x210403f0]:  00  00  00  00  00  00  00  00 | [0x21041e82 |  4]:  1  1
        [0x210403f8]:  40  1e  04  21  05  07  00  80 | [0x21041e83 |  0]:  2  2
        [0x21040400]:  00  00  00  00  00  00  00  00 | [0x21041e83 |  4]:  0  0
        [0x21040408]:  00  00  00  00  00  00  00  00 | [0x21041e84 |  0]:  0  0
        [0x21040410]:  00  00  00  00 [f8] 03  04  21 | [0x21041e84 |  4]:  0 [2]
        [0x21040418]:  00  8b  06  00  00  00  00  00 | [0x21041e85 |  0]:  2  3
        [0x21040420]:  00  00  00  00  00  00  00  00 | [0x21041e85 |  4]:  3  3
        [0x21040428]:  00  00  00  00  00  00  00  00 | [0x21041e86 |  0]:  3  3
        [0x21040430]:  00  00  00  00  00  00  00  00 | [0x21041e86 |  4]:  3  3
        [0x21040438]:  00  00  00  00  00  00  00  00 | [0x21041e87 |  0]:  3  3
        [0x21040440]:  00  00  00  00  00  00  00  00 | [0x21041e87 |  4]:  3  3
        [0x21040448]:  00  00  00  00  00  00  00  00 | [0x21041e88 |  0]:  3  3
        [0x21040450]:  00  00  00  00  00  00  00  00 | [0x21041e88 |  4]:  3  3
        [0x21040458]:  00  00  00  00  00  00  00  00 | [0x21041e89 |  0]:  3  3
        [0x21040460]:  00  00  00  00  00  00  00  00 | [0x21041e89 |  4]:  3  3
        [0x21040468]:  00  00  00  00  00  00  00  00 | [0x21041e8a |  0]:  3  3
        [0x21040470]:  00  00  00  00  00  00  00  00 | [0x21041e8a |  4]:  3  3
        [0x21040478]:  00  00  00  00  00  00  00  00 | [0x21041e8b |  0]:  3  3
        [0x21040480]:  00  00  00  00  00  00  00  00 | [0x21041e8b |  4]:  3  3
        [0x21040488]:  00  00  00  00  00  00  00  00 | [0x21041e8c |  0]:  3  3
        [0x21040490]:  00  00  00  00  00  00  00  00 | [0x21041e8c |  4]:  3  3
[ERR][TestLmsTsk]*****  Kernel Address Sanitizer Error Detected End *****
str[20]=0xfffffff8
######LmsTestOsmallocOverflow stop ######

######LmsTestUseAfterFree start ######
[ERR][TestLmsTsk]*****  Kernel Address Sanitizer Error Detected Start *****
[ERR][TestLmsTsk]Use after free error detected
[ERR][TestLmsTsk]Illegal READ address at: [0x2104041c]
[ERR][TestLmsTsk]Shadow memory address: [0x21041e85 : 2]  Shadow memory value: [3]
psp, start = 21057d90, end = 21057e80
taskName = TestLmsTsk
taskID   = 5
----- traceback start -----
traceback 0 -- lr = 0x210099f4
traceback 1 -- lr = 0x2101daec
traceback 2 -- lr = 0x2101db3c
traceback 3 -- lr = 0x2101c494
----- traceback end -----

[LMS] Dump info around address [0x2104041c]:

        [0x21040398]:  00  00  00  00  00  00  00  00 | [0x21041e7d |  0]:  1  1
        [0x210403a0]:  00  00  00  00  00  00  00  00 | [0x21041e7d |  4]:  1  1
        [0x210403a8]:  00  00  00  00  00  00  00  00 | [0x21041e7e |  0]:  1  1
        [0x210403b0]:  00  00  00  00  00  00  00  00 | [0x21041e7e |  4]:  1  1
        [0x210403b8]:  00  00  00  00  00  00  00  00 | [0x21041e7f |  0]:  1  1
        [0x210403c0]:  00  00  00  00  00  00  00  00 | [0x21041e7f |  4]:  1  1
        [0x210403c8]:  00  00  00  00  00  00  00  00 | [0x21041e80 |  0]:  1  1
        [0x210403d0]:  00  00  00  00  00  00  00  00 | [0x21041e80 |  4]:  1  1
        [0x210403d8]:  00  00  00  00  00  00  00  00 | [0x21041e81 |  0]:  1  1
        [0x210403e0]:  00  00  00  00  00  00  00  00 | [0x21041e81 |  4]:  1  1
        [0x210403e8]:  00  00  00  00  00  00  00  00 | [0x21041e82 |  0]:  1  1
        [0x210403f0]:  00  00  00  00  00  00  00  00 | [0x21041e82 |  4]:  1  1
        [0x210403f8]:  40  1e  04  21  05  07  00  80 | [0x21041e83 |  0]:  2  2
        [0x21040400]:  00  00  00  00  00  00  00  00 | [0x21041e83 |  4]:  0  0
        [0x21040408]:  00  00  00  00  00  00  00  00 | [0x21041e84 |  0]:  0  0
        [0x21040410]:  00  00  00  00  f8  03  04  21 | [0x21041e84 |  4]:  0  2
        [0x21040418]:  05  8b  06  00 [00] 00  00  00 | [0x21041e85 |  0]:  2 [3]
        [0x21040420]:  00  00  00  00  00  00  00  00 | [0x21041e85 |  4]:  3  3
        [0x21040428]:  00  00  00  00  00  00  00  00 | [0x21041e86 |  0]:  3  3
        [0x21040430]:  14  04  04  21  00  84  06  00 | [0x21041e86 |  4]:  2  2
        [0x21040438]:  00  00  00  00  00  00  00  00 | [0x21041e87 |  0]:  3  3
        [0x21040440]:  00  00  00  00  00  00  00  00 | [0x21041e87 |  4]:  3  3
        [0x21040448]:  00  00  00  00  00  00  00  00 | [0x21041e88 |  0]:  3  3
        [0x21040450]:  00  00  00  00  00  00  00  00 | [0x21041e88 |  4]:  3  3
        [0x21040458]:  00  00  00  00  00  00  00  00 | [0x21041e89 |  0]:  3  3
        [0x21040460]:  00  00  00  00  00  00  00  00 | [0x21041e89 |  4]:  3  3
        [0x21040468]:  00  00  00  00  00  00  00  00 | [0x21041e8a |  0]:  3  3
        [0x21040470]:  00  00  00  00  00  00  00  00 | [0x21041e8a |  4]:  3  3
        [0x21040478]:  00  00  00  00  00  00  00  00 | [0x21041e8b |  0]:  3  3
        [0x21040480]:  00  00  00  00  00  00  00  00 | [0x21041e8b |  4]:  3  3
        [0x21040488]:  00  00  00  00  00  00  00  00 | [0x21041e8c |  0]:  3  3
        [0x21040490]:  00  00  00  00  00  00  00  00 | [0x21041e8c |  4]:  3  3
        [0x21040498]:  00  00  00  00  00  00  00  00 | [0x21041e8d |  0]:  3  3
[ERR][TestLmsTsk]*****  Kernel Address Sanitizer Error Detected End *****
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
  - 影子内存值：0（可读可写）、3（已释放）、2（红区）、1（填充值）
