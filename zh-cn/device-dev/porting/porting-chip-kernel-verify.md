# 内核移植验证


在工程device目录下添加编译main.c示例程序文件，此示例程序的主要目的是：LOS_KernelInit完成之后，创建两个任务，循环调度延时并打印日志信息，通过此方法可以验证系统是否可正常调度以及时钟是否正常。

```
VOID TaskSampleEntry2(VOID) // 任务2的入口函数
{
    while(1) {
      LOS_TaskDelay(10000);
      printf("taskSampleEntry2 running...\n");
    }
}

VOID TaskSampleEntry1(VOID) // 任务1的入口函数
{
    while(1) {
      LOS_TaskDelay(2000);
      printf("taskSampleEntry1 running...\n");
    }
}

UINT32 TaskSample(VOID)
{
    UINT32 uwRet;
    UINT32 taskID1,taskID2;
    TSK_INIT_PARAM_S stTask1={0};
    stTask1.pfnTaskEntry = (TSK_ENTRY_FUNC)TaskSampleEntry1;
    stTask1.uwStackSize  = 0X1000;
    stTask1.pcName       = "taskSampleEntry1";
    stTask1.usTaskPrio   = 6; //stTask1的任务优先级设定，不同于stTask2
    uwRet = LOS_TaskCreate(&taskID1, &stTask1);

    stTask1.pfnTaskEntry = (TSK_ENTRY_FUNC)TaskSampleEntry2;
    stTask1.uwStackSize  = 0X1000;
    stTask1.pcName       = "taskSampleEntry2";
    stTask1.usTaskPrio   = 7;
    uwRet = LOS_TaskCreate(&taskID2, &stTask1);

    return LOS_OK;
}

LITE_OS_SEC_TEXT_INIT int main(void)
{
    UINT32 ret;
    UartInit(); // 硬件串口配置，通过串口输出调试日志，实际函数名根据单板实现不一样而不一样。
    printf("\n\rhello world!!\n\r");
    ret = LOS_KernelInit(); 
    TaskSample();
    if (ret == LOS_OK) {
        LOS_Start(); // 开始系统调度，循环执行stTask1/stTask2任务，串口输出任务日志
    }
    while (1) {
        __asm volatile("wfi");
    }
}
```


第一个任务运行正常后，说明最小系统的核心流程基本OK；由于xts用例框架对外依赖较多，主要是utils、bootstrap的链接脚本和编译框架，暂时无法支撑内核单独跑xts；此处略过内核测试套的测试，可以通过[XTS测试套](../porting/porting-chip-board-xts.md)来覆盖最小系统是否完整移植成功。
