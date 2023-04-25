# HiCollie Development


## Overview

HiCollie provides the software watchdog function. It provides a unified framework for fault detection and fault log generation to help you locate software timeout faults resulting from system service deadlock, application main thread blocking, and service process timeout. 


## Available APIs

  **Table 1** Description of XCollieChecker APIs

| API| Description|
| -------- | -------- |
| virtual void CheckBlock() | Provides the callback of the suspension detection result.<br>Input arguments: none<br>Output arguments: none<br>Return value: none|
| virtual void CheckThreadBlock() | Provides the callback of the thread suspension detection result.<br>Input arguments: none<br>Output arguments: none<br>Return value: none|


  **Table 2** Description of XCollie APIs

| API| Description|
| -------- | -------- |
| void RegisterXCollieChecker(const sptr&lt;XCollieChecker&gt; &amp;checker, unsigned int type) | Registers the callback of the thread suspension detection result.<br>Input arguments:<br>- **checker**: pointer to the XCollieChecker instance.<br>- **type**: suspension detection type. Set it to **XCOLLIE_THREAD**.<br>Output arguments: none<br>Return value: none|
| int SetTimer(const std::string &amp;name, unsigned int timeout, std::function&lt;void(void*)&gt; func, void *arg, unsigned int flag) | Adds timers.<br>Input arguments:<br>- **name**: timer name.<br>- **timeout**: timeout duration, in seconds.<br>- **func**: timeout callback.<br>- **arg**: pointer to the timeout callback.<br>- **flag**: timer operation type.<br>    - **XCOLLIE_FLAG_DEFAULT**: default flag, which is the combination of the other three options.<br>    - **XCOLLIE_FLAG_NOOP**: Calls only the timeout callback.<br>    - **XCOLLIE_FLAG_LOG**: Generates a timeout fault log.<br>    - **XCOLLIE_FLAG_RECOVERY**: Exits the process.<br>Output arguments: none<br>Return value: timer ID if the operation is successful; **-1** otherwise.|
| bool UpdateTimer(int id, unsigned int timeout) | Updates timers.<br>Input arguments:<br>- **id**: timer ID.<br>- **timeout**: timeout duration, in seconds.<br>Output arguments: none<br>Return value: **true** if the operation is successful; **false** otherwise.|
| void CancelTimer(int id) | Cancels a timer.<br>Input arguments:<br>- **id**: timer ID.<br>Output arguments: none<br>Return value: none|


## How to Develop


### Thread Suspension Monitoring

This function requires you to implement two callback functions: **CheckBlock** and **CheckThreadBlock** of the **XCollieChecker** class. After the callbacks are implemented, you need to use the **RegisterXCollieChecker** function of the **XCollie** class to register their instances. The suspension monitoring thread periodically executes all successfully registered callbacks, checks the thread logic completion flag, and determines whether the service logic of any registered thread is suspended.

1. Develop the source code.
     Include the **xcollie** header file in the source file.
     
   ```
   #include "xcollie.h"
   ```

   Add the following code to the service code:

   
   ```
   void MyXCollieChecker::CheckLock()
   {
       /* time consuming job */
   }
       
   void MyXCollieChecker::CheckThreadBlock()
   {
       /* time consuming job */
   }
       
   sptr<XCollieChecker> checker = new MyXCollieChecker("MyXCollieChecker");
   XCollie::GetInstance().RegisterXCollieChecker(checker, 
       (XCOLLIE_LOCK | XCOLLIE_THREAD));
   ......
   ```

2. Configure compilation information. Specifically, add the subsystem SDK dependency to **BUILD.gn**.
   
   ```
   external_deps = [ "hiviewdfx:libxcollie" ]
   ```


### Timeout Monitoring

You can add a maximum of 128 timers for a single process by using the **SetTimer** function. Adding timers will fail if the number of timers has reached the upper limit.

1. Develop the source code.
     Include the **xcollie** header file in the source file.
     
   ```
   #include "xcollie.h"
   ```

     Add the code to add, update, and cancel timers.
   
   ```
   std::function<void(void *)> callback = [](void *args)
   {
       /* dump helpful information */
   };
       
   int id = XCollie::GetInstance().SetTimer("MyXCollieTimer", 10, callback ,nullptr, XCOLLIE_FLAG_LOG);
   /* time consuming job */
   XCollie::GetInstance().UpdateTimer(id, 5);
   /* time consuming job */
   XCollie::GetInstance().CancelTimer(id);
   ......
   ```

2. Configure compilation information. Specifically, add the subsystem SDK dependency to **BUILD.gn**.
   
   ```
   external_deps = [ "hiviewdfx:libxcollie" ]
   ```
