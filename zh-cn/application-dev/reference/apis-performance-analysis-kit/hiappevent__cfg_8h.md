# hiappevent_cfg.h


## 概述

定义事件打点配置函数的所有配置项名称。

如果您想要对应用事件打点功能进行配置，您可以直接使用配置项常量。

示例代码：

```
bool res = OH_HiAppEvent_Configure(MAX_STORAGE, "100M");
```

**引用文件：** &lt;hiappevent/hiappevent_cfg.h&gt;

**起始版本：** 8

**相关模块：**[HiAppEvent](_hi_app_event.md)


## 汇总


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| [DISABLE](_hi_app_event.md#disable)&nbsp;&nbsp;&nbsp;"disable" | 事件打点开关。默认值为false。true：关闭打点功能，false：不关闭打点功能。  | 
| [MAX_STORAGE](_hi_app_event.md#max_storage)&nbsp;&nbsp;&nbsp;"max_storage" | 事件文件目录存储配额大小。默认值为“10M”。  | 
