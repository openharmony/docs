# Porting the Startup Subsystem


The startup subsystem is responsible for starting key system processes and services after the kernel is started and before applications are started.


## Procedure

For the mini system, the startup entry identifiers of services and functions are provided. When SAMGR is started, the entry function identified by bootstrap is called and system services are started.

After the adaptation is complete, call the **OHOS_SystemInit()** API to start the system.

Path: **base/startup/bootstrap_lite/services/source/system_init.c**

  
```
void OHOS_SystemInit(void)
{
    MODULE_INIT(bsp);           // Execute the function in the .zinitcall.bspX.init section.
    MODULE_INIT(device);        // Execute the function in the .zinitcall.deviceX.init section.
    MODULE_INIT(core);          // Execute the function in the .zinitcall.coreX.init section.
    SYS_INIT(service);          // Execute the function in the .zinitcall.sys.serviceX.init section.
    SYS_INIT(feature);          // Execute the function in the .zinitcall.sys.featureX.init section.
    MODULE_INIT(run);           // Execute the function in the .zinitcall.runX.init section.
    SAMGR_Bootstrap();          // Initialize the SAMGR service.
}
```


## Example

1. Add the startup subsystem to the **config.json** file.

   Path: **vendor/MyVendorCompany/MyProduct/config.json**

   The sample code is as follows:

     
   ```
   {
       subsystem": "startup",
       components": [
           { "component": "bootstrap_lite", "features":[] },
           { "component": "syspara_lite", "features":[] }
       ]
   },
   ```

   Some components (such as syspara_lite) in the startup subsystem depend on the modules in **$ohos_product_adapter_dir/utils**. In the preceding information, **ohos_product_adapter_dir** is the value of **product_adapter_dir** configured in the **config.json** file. Generally, **ohos_product_adapter_dir** is set to **vendor/MyVendorCompany/MyProduct/hals**.

1. Add the **zinitcall** and **run** definitions.

   Add the following code to the **.text** section in the vendor **.ld** linking script:

     
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
       __zinitcall_app_service_start = .; // SAMGR executes the function in the .zinitcall.app.featureX.init section.
       KEEP (*(.zinitcall.app.service0.init))
       KEEP (*(.zinitcall.app.service1.init))
       KEEP (*(.zinitcall.app.service2.init))
       KEEP (*(.zinitcall.app.service3.init))
       KEEP (*(.zinitcall.app.service4.init))
       __zinitcall_app_service_end = .;
       __zinitcall_app_feature_start = .; // SAMGR executes the function in the .zinitcall.app.featureX.init section.
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

1. The chip SDK creates a task.

   Set task parameters. After the system is started, start the task. The following is an example:

     
   ```
   void mainTask(void) {
      // Vendor-defined function
       OHOS_SystemInit();        // Initialize the startup subsystem.
       printf("MainTask running...\n");
   }
    
   void main(VOID) {
      // Initialize the hardware and redirect the printf output to the debug serial port.
       if (LOS_KernelInit() == 0) {            // Initialize the kernel.
           task_init_param.usTaskPrio = 10;    // Task priority.
           task_init_param.pcName = "mainTask"; // Task process name.
           task_init_param.pfnTaskEntry = (TSK_ENTRY_FUNC)mainTask; // Task entry function.
           task_init_param.uwStackSize = 8192;          // Size of the task stack.
           LOS_TaskCreate(&tid, &task_init_param);      // Create a task.
           LOS_Start();                                 // Start the task.
       }
       else {
           printf("[BUG] LOS_KernelInit fail\n");
       }
       printf("[BUG] reach to unexpected code\n");
       while (1);
   }
   ```
