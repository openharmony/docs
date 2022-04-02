# HiCollie开发指导


## 概述

HiCollie提供了软件看门狗功能。针对系统服务死锁、应用主线程阻塞，用户业务流程超时等故障，HiCollie提供了一套统一的用于故障检测和故障日志生成的框架，提供软件超时故障日志，辅助定位软件超时问题。


## 接口说明

  **表1** C++接口功能描述表

| 所属类 | 接口定义 | 描述 | 
| -------- | -------- | -------- |
| XCollieChecker类接口 | virtual&nbsp;void&nbsp;CheckBlock() | 接口功能：卡死检测回调函数。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：无。 | 
| XCollieChecker类接口 | virtual&nbsp;void&nbsp;CheckThreadBlock() | 接口功能：线程卡死检测回调函数。<br/>输入参数：无。<br/>输出参数：无。<br/>返回值：无。 | 
| XCollie类接口 | void&nbsp;RegisterXCollieChecker(const&nbsp;sptr&amp;lt;XCollieChecker&amp;gt;&nbsp;&amp;checker,&nbsp;unsigned&nbsp;int&nbsp;type) | 接口功能：线程卡死检测回调函数注册。<br/>输入参数：<br/>-&nbsp;checker：XCollieChecker实例指针。<br/>-&nbsp;type：卡死检测类型，取值设置为XCOLLIE_THREAD。<br/>输出参数：无。<br/>返回值：无。 | 
| XCollie类接口 | int&nbsp;SetTimer(const&nbsp;std::string&nbsp;&amp;name,&nbsp;unsigned&nbsp;int&nbsp;timeout,&nbsp;std::function&amp;lt;void&nbsp;(void&nbsp;_)&amp;gt;&nbsp;func,&nbsp;void&nbsp;_arg,&nbsp;unsigned&nbsp;int&nbsp;flag) | 接口功能：添加定时器。<br/>输入参数：<br/>-&nbsp;name：定时器名称。<br/>-&nbsp;timeout：超时时间，单位为秒。<br/>-&nbsp;func：超时回调函数。<br/>-&nbsp;arg：超时回调函数参数指针。<br/>-&nbsp;flag：定时器操作类型。<br/>&nbsp;&nbsp;XCOLLIE_FLAG_DEFAULT&nbsp;&nbsp;//&nbsp;其他三个选项功能之和<br/>&nbsp;&nbsp;XCOLLIE_FLAG_NOOP&nbsp;//&nbsp;仅调用超时回调函数<br/>&nbsp;&nbsp;XCOLLIE_FLAG_LOG&nbsp;//&nbsp;&nbsp;生成超时故障日志<br/>&nbsp;&nbsp;XCOLLIE_FLAG_RECOVERY&nbsp;//&nbsp;&nbsp;进程退出<br/>输出参数：无。<br/>返回值：成功返回定时器标识，失败返回-1。 | 
| XCollie类接口 | bool&nbsp;UpdateTimer(int&nbsp;id,&nbsp;unsigned&nbsp;int&nbsp;timeout) | 接口功能：更新定时器。<br/>输入参数：<br/>-&nbsp;id：定时器标识。<br/>-&nbsp;timeout：超时时间，单位为秒。<br/>输出参数：无。<br/>返回值：成功返回true，失败返回false。 | 
| XCollie类接口 | void&nbsp;CancelTimer(int&nbsp;id) | 接口功能：取消定时器。<br/>输入参数：定时器标识。<br/>输出参数：无。<br/>返回值：无。 | 


## 效果

日志打印：

  
```
timeout: TimeoutTimer start at 1611040305 to check 1s ago

----------StacktraceCatcher CurrentTime:2021-01-19 15:11:45 Unexecuted(-1)(LogType:Stacktrace Pid:27689 Process:XCollieTimeoutModuleTest)----------


----- pid 27689 at 2021-01-19 15:11:45 -----
Cmd line: ./XCollieTimeoutModuleTest
ABI: 'arm64'

"XCollieTimeoutM" sysTid=27689
    #01 pc 00000000000174cc  /data/test/XCollieTimeoutModuleTest
```


## 开发实例


### C++接口开发实例


### 线程卡死监控

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


### 超时监控

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
