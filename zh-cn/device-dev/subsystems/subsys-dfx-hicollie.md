# HiCollie开发指导


## 概述

HiCollie提供了软件看门狗功能。针对系统服务死锁、应用主线程阻塞，用户业务流程超时等故障，HiCollie提供了一套统一的用于故障检测和故障日志生成的框架，提供软件超时故障日志，辅助定位软件超时问题。


## 接口说明

  **表1** XCollieChecker接口

| 接口名称 | 描述 |
| -------- | -------- |
| virtual void CheckBlock() | 接口功能：卡死检测回调函数。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：无。 |
| virtual void CheckThreadBlock() | 接口功能：线程卡死检测回调函数。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：无。 |


  **表2** XCollie接口

| 接口名称 | 描述 |
| -------- | -------- |
| void RegisterXCollieChecker(const sptr&lt;XCollieChecker&gt; &amp;checker, unsigned int type) | 接口功能：线程卡死检测回调函数注册。<br/>输入参数：<br/>- **checker**：XCollieChecker实例指针。<br/>- **type**：卡死检测类型，取值设置为**XCOLLIE_THREAD**。<br/>输出参数：无。<br/>返回值：无。 |
| int SetTimer(const std::string &amp;name, unsigned int timeout, std::function&lt;void(void*)&gt; func, void *arg, unsigned int flag) | 接口功能：添加定时器。<br/>输入参数：<br/>- **name**：定时器名称。<br/>- **timeout**：超时时间，单位为秒。<br/>- **func**：超时回调函数。<br/>- **arg**：超时回调函数参数指针。<br/>- **flag**：定时器操作类型。<br/>  XCOLLIE_FLAG_DEFAULT：其他三个选项功能之和<br/>  XCOLLIE_FLAG_NOOP：仅调用超时回调函数<br/>  XCOLLIE_FLAG_LOG：生成超时故障日志<br/>  XCOLLIE_FLAG_RECOVERY：进程退出<br/>输出参数：无。<br/>返回值：成功返回定时器标识，失败返回 **-1**。 |
| bool UpdateTimer(int id, unsigned int timeout) | 接口功能：更新定时器。<br/>输入参数：<br/>- **id**：定时器标识。<br/>- **timeout**：超时时间，单位为秒。<br/>输出参数：无。<br/>返回值：成功返回**true**，失败返回**false**。 |
| void CancelTimer(int id) | 接口功能：取消定时器。<br/>输入参数：<br/>- **id**：定时器标识。<br/>输出参数：无。<br/>返回值：无。 |


## 开发实例


### 线程卡死监控开发实例

线程卡死监控功能需要开发者实现两个卡死检测回调函数，XCollieChecker类的CheckBlock和CheckThreadBlock接口函数。实现了该回调函数之后，开发者还需要通过XCollie类的RegisterXCollieChecker函数，将该回调函数的类实例成功注册。卡死监控线程会定时执行全部已成功注册的回调函数，检查线程逻辑完成标志位，判定已经成功注册的线程逻辑是否被卡死。

1. 源代码开发
     包含头文件：
     
   ```
   #include "xcollie.h"
   ```

   在业务代码中使用：

   
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

2. 编译设置，在BUILD.gn里增加子系统SDK依赖：
   
   ```
   external_deps = [ "hiviewdfx:libxcollie" ]
   ```


### 超时监控开发实例

单个进程通过SetTimer接口函数添加定时器最多可以设置128个，超过上限则添加定时器操作会失败。

1. 源代码开发
     包含头文件：
     
   ```
   #include "xcollie.h"
   ```

     在业务代码中使用（添加/更新/取消）：
   
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

2. 编译设置，在BUILD.gn里增加子系统SDK依赖：
   
   ```
   external_deps = [ "hiviewdfx:libxcollie" ]
   ```
