# HiLog_Lite开发指导


## 概述

HiLog_Lite是针对轻量系统类设备（参考内存≥128KiB）、小型系统类设备（参考内存≥1MiB）的hilog框架，实现了日志的打印、输出和流控功能。


## 接口说明

C语言接口：

  
```
HILOG_DEBUG(mod, fmt, ...)
HILOG_INFO/HILOG_WARN/HILOG_ERROR/HILOG_FATAL
```

  
  **表1** 接口参数说明

| 参数名 | 是否必填 | 参数类型 | 参数说明 | 
| -------- | -------- | -------- | -------- |
| mod | 是 | uint8 | 模块/服务的ID。<br/>统一规划分配，最大支持64个，其中第三方APP统一使用HILOG_MODULE_APP作为模块ID。 | 
| fmt | 是 | char&nbsp;\* | 格式化输出字符串。<br/>1.&nbsp;最大支持6个可变参数，不支持%s。<br/>2.&nbsp;格式化后的单条日志最大长度128字节，超过将无法打印。 | 
| 可变参 | 否 | int32 | 仅支持数字类型，最大支持6个变参。 | 


## 开发实例

以下引用samgr_lite模块使用hilog_lite框架作为实例。

1. 添加模块ID，在“base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog_lite/hiview_log.h”的类型定义结构体中添加HILOG_MODULE_SAMGR定义。
     
   ```
   typedef enum {
       ...
       HILOG_MODULE_SAMGR,
       ...
   } HiLogModuleType;
   ```

2. 注册模块，在“base/hiviewdfx/hilog_lite/frameworks/mini/hiview_log.c”的HiLogInit函数中添加注册代码。
     
   ```
   HiLogRegisterModule(HILOG_MODULE_SAMGR, "SAMGR");
   ```

3. 在GN文件中添加头文件依赖，文件路径为：“foundation/systemabilitymgr/samgr_lite/samgr/BUILD.gn”。
     
   ```
   include_dirs = [
        "//base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog_lite",
   ]
   ```

4. 源文件“foundation/systemabilitymgr/samgr_lite/samgr/source/message.c”中引用头文件并调用接口。
     
   ```
   #include <log.h>
   uint32 *SAMGR_SendSharedRequest(const Identity *identity, const Request *request, uint32 *token, Handler handler)
   {
       ...
       if (err != EC_SUCCESS) {
   	HILOG_ERROR(HILOG_MODULE_SAMGR, "SharedSend [%p] failed(%d)!", identity->queueId, err);
           (void)FreeReference(&exchange);
       }
       ...
   }
   ```
