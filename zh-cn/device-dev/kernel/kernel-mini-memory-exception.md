# 异常调测


## 基本概念

OpenHarmony LiteOS-M提供异常接管调测手段，帮助开发者定位分析问题。异常接管是操作系统对运行期间发生的异常情况进行处理的一系列动作，例如打印异常发生时异常类型、发生异常时的系统状态、当前函数的调用栈信息、CPU现场信息、任务调用堆栈等信息。


## 运行机制

栈帧用于保存函数调用过程中的函数参数、变量、返回值等信息。调用函数时，会创建子函数的栈帧，同时将函数入参、局部变量、寄存器入栈。栈帧从高地址向低地址生长。以ARM32 CPU架构为例，每个栈帧中都会保存PC、LR、SP和FP寄存器的历史值。LR链接寄存器（Link Register）指向函数的返回地址，FP帧指针寄存器（Frame Point）指向当前函数的父函数的栈帧起始地址。利用FP寄存器可以得到父函数的栈帧，从栈帧中获取父函数的FP，就可以得到祖父函数的栈帧，以此类推，可以追溯程序调用栈，得到函数间的调用关系。

当系统发生异常时，系统打印异常函数的栈帧中保存的寄存器内容，以及父函数、祖父函数的栈帧中的LR链接寄存器、FP帧指针寄存器内容，用户就可以据此追溯函数间的调用关系，定位异常原因。

堆栈分析原理如下图所示，实际堆栈信息根据不同CPU架构有所差异，此处仅做示意。

  **图1** 堆栈分析原理示意图
  ![zh-cn_image_0000001132936268](figures/zh-cn_image_0000001132936268.png)

图中不同颜色的寄存器表示不同的函数。可以看到函数调用过程中，寄存器的保存。通过FP寄存器，栈回溯到异常函数的父函数，继续按照规律对栈进行解析，推出函数调用关系，方便用户定位问题。


## 接口说明

OpenHarmony LiteOS-M内核的回溯栈模块提供下面几种功能，接口详细信息可以查看API参考。

  **表1** 回溯栈模块接口

| 功能分类 | 接口名 | 
| -------- | -------- |
| 回溯栈接口 | LOS_BackTrace：打印调用处的函数调用栈关系。<br/>LOS_RecordLR：在无法打印的场景，用该接口获取调用处的函数调用栈关系。 | 


## 使用指导


### 开发流程

开启异常调测的典型流程如下：

1. 配置异常接管相关宏。
     需要在target_config.h头文件中修改配置：
     | 配置项 | 含义 | 设置值 | 
   | -------- | -------- | -------- |
   | LOSCFG_BACKTRACE_DEPTH | 函数调用栈深度，默认15层 | 15 | 
   | LOSCFG_BACKTRACE_TYPE | 回溯栈类型:<br/>0：表示关闭该功能；<br/>1：表示支持Cortex-m系列硬件的函数调用栈解析；<br/>2：表示用于Risc-v系列硬件的函数调用栈解析； | 根据工具链类型设置1或2 | 

1. 使用示例中有问题的代码，编译、运行工程，在串口终端中查看异常信息输出。示例代码模拟异常代码，实际产品开发时使用异常调测机制定位异常问题。
     本示例演示异常输出，包含1个任务，该任务入口函数模拟若干函数调用，最终调用一个模拟异常的函数。代码实现如下：
     
   ```
   #include <stdio.h>
   #include "los_config.h"
   #include "los_interrupt.h"
   #include "los_task.h"
   
   UINT32 g_taskExcId;
   #define TSK_PRIOR 4
   
   /* 模拟异常函数 */
   	
   UINT32 Get_Result_Exception_0(UINT16 dividend){
       UINT32 divisor = 0;
       UINT32 result = dividend / divisor;
       return result;
   }
   
   UINT32 Get_Result_Exception_1(UINT16 dividend){
       return Get_Result_Exception_0(dividend);
   }
   
   UINT32 Get_Result_Exception_2(UINT16 dividend){
       return Get_Result_Exception_1(dividend);
   }
   
   UINT32 Example_Exc(VOID)
   {
       UINT32 ret;
   
       printf("Enter Example_Exc Handler.\r\n");
   
       /* 模拟函数调用 */
       ret = Get_Result_Exception_2(TSK_PRIOR);
       printf("Divided result =%u.\r\n", ret);
   
       printf("Exit Example_Exc Handler.\r\n");
       return ret;
   }
   
   
   /* 任务测试入口函数，创建一个会发生异常的任务 */
   UINT32 Example_Exc_Entry(VOID)
   {
       UINT32 ret;
       TSK_INIT_PARAM_S initParam;
   
       /* 锁任务调度，防止新创建的任务比本任务高而发生调度 */
       LOS_TaskLock();
   
       printf("LOS_TaskLock() Success!\r\n");
   
       initParam.pfnTaskEntry = (TSK_ENTRY_FUNC)Example_Exc;
       initParam.usTaskPrio = TSK_PRIOR;
       initParam.pcName = "Example_Exc";
       initParam.uwStackSize = LOSCFG_SECURE_STACK_DEFAULT_SIZE;
       /* 创建高优先级任务，由于锁任务调度，任务创建成功后不会马上执行 */
       ret = LOS_TaskCreate(&g_taskExcId, &initParam);
       if (ret != LOS_OK) {
           LOS_TaskUnlock();
   
           printf("Example_Exc create Failed!\r\n");
           return LOS_NOK;
       }
   
       printf("Example_Exc create Success!\r\n");
   
       /* 解锁任务调度，此时会发生任务调度，执行就绪队列中最高优先级任务 */
       LOS_TaskUnlock();
   
       return LOS_OK;
   }
   ```

1. 上述代码串口终端输出异常信息如下：
     
   ```
   entering kernel init...
   LOS_TaskLock() Success!
   Example_Exc create Success!
   Entering scheduler
   Enter Example_Exc Handler.
   *Exception Information**
   Type      = 10
   ThrdPid   = 4
   Phase     = exc in task
   FaultAddr = 0xabababab
   Current task info:
   Task name = Example_Exc
   Task ID   = 4
   Task SP   = 0x200051ac
   Task ST   = 0x20004ff0
   Task SS   = 0x200
   Exception reg dump:
   PC        = 0x80037da
   LR        = 0x80037fe
   SP        = 0x20005190
   R0        = 0x4
   R1        = 0x40
   R2        = 0x4
   R3        = 0x0
   R4        = 0x4040404
   R5        = 0x5050505
   R6        = 0x6060606
   R7        = 0x20005190
   R8        = 0x8080808
   R9        = 0x9090909
   R10       = 0x10101010
   R11       = 0x11111111
   R12       = 0x12121212
   PriMask   = 0x0
   xPSR      = 0x41000000
   ----- backtrace start -----
   backtrace 0 -- lr = 0x800381a
   backtrace 1 -- lr = 0x8003836
   backtrace 2 -- lr = 0x8005a4e
   backtrace 3 -- lr = 0x8000494
   backtrace 4 -- lr = 0x8008620
   backtrace 5 -- lr = 0x800282c
   backtrace 6 -- lr = 0x80008a0
   backtrace 7 -- lr = 0x80099f8
   backtrace 8 -- lr = 0x800a01a
   backtrace 9 -- lr = 0x800282c
   backtrace 10 -- lr = 0x80008a0
   backtrace 11 -- lr = 0x80099f8
   backtrace 12 -- lr = 0x8009bf0
   backtrace 13 -- lr = 0x8009c52
   backtrace 14 -- lr = 0x80099aa
   ----- backtrace end -----
   
   TID  Priority   Status     StackSize    WaterLine    StackPoint  TopOfStack   EventMask  SemID  name
   ---  --------   --------   ---------    ----------   ----------  ----------   ---------  -----  ----
   0    0    Pend    0x2d0    0x104    0x200029bc    0x200027f0    0x0    0xffff    Swt_Task
   1    31    Ready    0x500    0x44    0x20002f84    0x20002ac8    0x0    0xffff    IdleCore000
   2    6    Ready    0x1000    0x44    0x20003f94    0x20002fd8    0x0    0xffff    TaskSampleEntry1
   3    7    Ready    0x1000    0x44    0x20004f9c    0x20003fe0    0x0    0xffff    TaskSampleEntry2
   4    4    Running    0x200    0xec    0x200051ac    0x20004ff0    0x0    0xffff    Example_Exc
   
   OS exception NVIC dump:
   interrupt enable register, base address: 0xe000e100, size: 0x20
   0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
   interrupt pending register, base address: 0xe000e200, size: 0x20
   0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
   interrupt active register, base address: 0xe000e300, size: 0x20
   0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
   interrupt priority register, base address: 0xe000e400, size: 0xf0
   0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
   0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
   0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
   0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 0x0 
   interrupt exception register, base address: 0xe000ed18, size: 0xc
   0x0 0x0 0xf0f00000 
   interrupt shcsr register, base address: 0xe000ed24, size: 0x4
   0x70008 
   interrupt control register, base address: 0xe000ed04, size: 0x4
   0x400f806 
   
   memory pools check:
   system heap memcheck over, all passed!
   memory pool check end!
   ```


### 定位流程

异常接管一般的定位步骤如下：

1. 打开编译后生成的镜像反汇编（asm）文件。如果默认没有生成，可以使用objdump工具生成，命令为：
     
   ```
    arm-none-eabi-objdump -S -l XXX.elf
   ```

1. 搜索PC指针（指向当前正在执行的指令）在asm中的位置，找到发生异常的函数。
   PC地址指向发生异常时程序正在执行的指令。在当前执行的二进制文件对应的asm文件中，查找PC值0x80037da，找到当前CPU正在执行的指令行，反汇编如下所示：

     
   ```
   UINT32 Get_Result_Exception_0(UINT16 dividend){
    80037c8:	b480      	push	{r7}
    80037ca:	b085      	sub	sp, #20
    80037cc:	af00      	add	r7, sp, #0
    80037ce:	4603      	mov	r3, r0
    80037d0:	80fb      	strh	r3, [r7, #6]
   kernel_liteos_m\targets\cortex-m7_nucleo_f767zi_gcc/Core/Src/exc_example.c:10
       UINT32 divisor = 0;
    80037d2:	2300      	movs	r3, #0
    80037d4:	60fb      	str	r3, [r7, #12]
   kernel_liteos_m\targets\cortex-m7_nucleo_f767zi_gcc/Core/Src/exc_example.c:11
       UINT32 result = dividend / divisor;
    80037d6:	88fa      	ldrh	r2, [r7, #6]
    80037d8:	68fb      	ldr	r3, [r7, #12]
    80037da:	fbb2 f3f3 	udiv	r3, r2, r3
    80037de:	60bb      	str	r3, [r7, #8]
   ```

1. 可以看到:
   1. 异常时CPU正在执行的指令是udiv	r3, r2, r3，其中r3取值为0，导致发生除零异常。
   2. 异常发生在函数Get_Result_Exception_0中。

2. 根据LR值查找异常函数的父函数。
   包含LR值0x80037fe的反汇编如下所示：

     
   ```
   080037ec <Get_Result_Exception_1>:
   Get_Result_Exception_1():
   kernel_liteos_m\targets\cortex-m7_nucleo_f767zi_gcc/Core/Src/exc_example.c:15
   UINT32 Get_Result_Exception_1(UINT16 dividend){
    80037ec:	b580      	push	{r7, lr}
    80037ee:	b082      	sub	sp, #8
    80037f0:	af00      	add	r7, sp, #0
    80037f2:	4603      	mov	r3, r0
    80037f4:	80fb      	strh	r3, [r7, #6]
   kernel_liteos_m\targets\cortex-m7_nucleo_f767zi_gcc/Core/Src/exc_example.c:16
       return Get_Result_Exception_0(dividend);
    80037f6:	88fb      	ldrh	r3, [r7, #6]
    80037f8:	4618      	mov	r0, r3
    80037fa:	f7ff ffe5 	bl	80037c8 <Get_Result_Exception_0>
    80037fe:	4603      	mov	r3, r0
   ```

1. LR值80037fe上一行是bl	80037c8 &lt;Get_Result_Exception_0&gt;，此处调用了异常函数，调用异常函数的父函数为Get_Result_Exception_1()。

2. 重复步骤3，解析异常信息中backtrace start至backtrace end之间的LR值，得到调用产生异常的函数调用栈关系，找到异常原因。
