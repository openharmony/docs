# Kernel Porting Verification<a name="EN-US_TOPIC_0000001153842844"></a>

Add the sample program file  **main.c**  to the  **device**  directory of the project and compile the file. After LOS\_KernelInit is complete, this sample program will create two tasks that loop the  **LOS\_TaskDelay**  function and print the log information cyclically. In this way, you can check whether system scheduling and the clock work properly.

```
VOID TaskSampleEntry2(VOID) // Entry function of task 2
{
    while(1) {
      LOS_TaskDelay(10000);
      printf("taskSampleEntry2 running...\n");
    }
}

VOID TaskSampleEntry1(VOID) // Entry function of task 1
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
    stTask1.usTaskPrio   = 6; // Set the priority of stTask1, which is different from that of stTask2.
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
    UartInit(); // Configure the hardware serial port and output the debug log over this serial port. The actual function name varies with the board.
    printf("\n\rhello world!!\n\r");
    ret = LOS_KernelInit(); 
    TaskSample();
    if (ret == LOS_OK) {
        LOS_Start(); // Start system scheduling, execute stTask1/stTask2 cyclically, and output task logs over the serial port.
    }
    while (1) {
        __asm volatile("wfi");
    }
}
```

If the first task is executed properly, the core process of the minimum system is valid. Due to the XTS framework's dependency on the link scripts of Utils and Bootstrap as well as the building framework, testing the kernel by executing the XTS is not supported. You can test whether the minimum system is completely ported in  [XTS](porting-chip-board-xts.md).

