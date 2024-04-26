# 移植启动恢复子系统


启动恢复子系统负责在内核启动之后到应用启动之前的系统关键进程和服务的启动过程的功能。


## 移植指导

针对轻量系统主要提供了各服务和功能的启动入口标识。在SAMGR启动时，会调用bootstrap标识的入口函数，并启动系统服务。

适配完成后，调用OHOS_SystemInit()接口，即可启动系统。

路径：“base/startup/bootstrap_lite/services/source/system_init.c”

  
```
void OHOS_SystemInit(void)
{
    MODULE_INIT(bsp);           //执行.zinitcall.bspX.init段中的函数
    MODULE_INIT(device);        //执行.zinitcall.deviceX.init段中的函数
    MODULE_INIT(core);          //执行.zinitcall.coreX.init段中的函数
    SYS_INIT(service);          //执行.zinitcall.sys.serviceX.init段中的函数
    SYS_INIT(feature);          //执行.zinitcall.sys.featureX.init段中的函数
    MODULE_INIT(run);           //执行.zinitcall.runX.init段中的函数
    SAMGR_Bootstrap();          //SAMGR服务初始化
}
```


## 移植实例

1. 在“config.json”中添加启动子系统。

   路径：“vendor/MyVendorCompany/MyProduct/config.json”

   修改如下：

     
   ```
   {
       "subsystem": "startup",
       "components": [
           { "component": "bootstrap_lite", "features":[] },
           { "component": "syspara_lite", "features":[] }
       ]
   },
   ```

   在startup子系统中有部分部件（如：syspara_lite等），会依赖“$ohos_product_adapter_dir/utils”中的模块。其中“ohos_product_adapter_dir”就是在config.json文件中配置的“product_adapter_dir”，我们通常配置其为“vendor/MyVendorCompany/MyProduct/hals”。

1. 添加zinitcall以及run定义。
   在厂商ld链接脚本中.text段中，添加如下代码：

     
   ```
       __zinitcall_bsp_start = .;
       KEEP (*(.zinitcall.bsp0.init))
       KEEP (*(.zinitcall.bsp1.init))
       KEEP (*(.zinitcall.bsp2.init))
       KEEP (*(.zinitcall.bsp3.init))
       KEEP (*(.zinitcall.bsp4.init))
       __zinitcall_bsp_end = .;
       __zinitcall_device_start = .;
       KEEP (*(.zinitcall.device0.init))
       KEEP (*(.zinitcall.device1.init))
       KEEP (*(.zinitcall.device2.init))
       KEEP (*(.zinitcall.device3.init))
       KEEP (*(.zinitcall.device4.init))
       __zinitcall_device_end = .;
       __zinitcall_core_start = .;
       KEEP (*(.zinitcall.core0.init))
       KEEP (*(.zinitcall.core1.init))
       KEEP (*(.zinitcall.core2.init))
       KEEP (*(.zinitcall.core3.init))
       KEEP (*(.zinitcall.core4.init))
       __zinitcall_core_end = .;
       __zinitcall_sys_service_start = .;
       KEEP (*(.zinitcall.sys.service0.init))
       KEEP (*(.zinitcall.sys.service1.init))
       KEEP (*(.zinitcall.sys.service2.init))
       KEEP (*(.zinitcall.sys.service3.init))
       KEEP (*(.zinitcall.sys.service4.init))
       __zinitcall_sys_service_end = .;
       __zinitcall_sys_feature_start = .;
       KEEP (*(.zinitcall.sys.feature0.init))
       KEEP (*(.zinitcall.sys.feature1.init))
       KEEP (*(.zinitcall.sys.feature2.init))
       KEEP (*(.zinitcall.sys.feature3.init))
       KEEP (*(.zinitcall.sys.feature4.init))
       __zinitcall_sys_feature_end = .;
       __zinitcall_run_start = .;
       KEEP (*(.zinitcall.run0.init))
       KEEP (*(.zinitcall.run1.init))
       KEEP (*(.zinitcall.run2.init))
       KEEP (*(.zinitcall.run3.init))
       KEEP (*(.zinitcall.run4.init))
       __zinitcall_run_end = .;
       __zinitcall_app_service_start = .;  //SAMGR执行.zinitcall.app.serviceX.init段中的函数
       KEEP (*(.zinitcall.app.service0.init))
       KEEP (*(.zinitcall.app.service1.init))
       KEEP (*(.zinitcall.app.service2.init))
       KEEP (*(.zinitcall.app.service3.init))
       KEEP (*(.zinitcall.app.service4.init))
       __zinitcall_app_service_end = .;
       __zinitcall_app_feature_start = .; //SAMGR执行.zinitcall.app.featureX.init段中的函数
       KEEP (*(.zinitcall.app.feature0.init))
       KEEP (*(.zinitcall.app.feature1.init))
       KEEP (*(.zinitcall.app.feature2.init))
       KEEP (*(.zinitcall.app.feature3.init))
       KEEP (*(.zinitcall.app.feature4.init))
       __zinitcall_app_feature_end = .;
       __zinitcall_test_start = .;
       KEEP (*(.zinitcall.test0.init))
       KEEP (*(.zinitcall.test1.init))
       KEEP (*(.zinitcall.test2.init))
       KEEP (*(.zinitcall.test3.init))
       KEEP (*(.zinitcall.test4.init))
       __zinitcall_test_end = .;
       __zinitcall_exit_start = .;
       KEEP (*(.zinitcall.exit0.init))
       KEEP (*(.zinitcall.exit1.init))
       KEEP (*(.zinitcall.exit2.init))
       KEEP (*(.zinitcall.exit3.init))
       KEEP (*(.zinitcall.exit4.init))
       __zinitcall_exit_end = .;
   ```

1. 芯片SDK创建任务。
   配置任务参数，系统启动后，启动任务，示例如下：

     
   ```
   void mainTask(void) {
      //厂商自定义功能
       OHOS_SystemInit();        //启动子系统初始化
       printf("MainTask running...\n");
   }
    
   void main(VOID) {
      //硬件初始化，printf输出重定向到debug串口等
       if (LOS_KernelInit() == 0) {            //ohos内核初始化
           task_init_param.usTaskPrio = 10;    //任务优先级
           task_init_param.pcName = "mainTask"; //任务进程名
           task_init_param.pfnTaskEntry = (TSK_ENTRY_FUNC)mainTask; //任务入口函数
           task_init_param.uwStackSize = 8192;          //任务栈大小
           LOS_TaskCreate(&tid, &task_init_param);      //创建任务
           LOS_Start();                                 //启动任务
       }
       else {
           printf("[BUG] LOS_KernelInit fail\n");
       }
       printf("[BUG] reach to unexpected code\n");
       while (1);
   }
   ```
