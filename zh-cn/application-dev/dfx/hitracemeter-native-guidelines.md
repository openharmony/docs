# 性能打点跟踪开发指导（Native）
## 概述
hiTraceMeter为开发者提供系统性能打点接口。开发者通过在自己的业务逻辑中的关键代码位置调用HiTraceMeter接口提供的API接口，能够有效跟踪进程轨迹、查看系统性能。
> **说明：**
> 仅当开发者使用Native API开发应用时，可参考本开发指导。JS文档请参考[HitraceMeter JS API参考](../reference/apis/js-apis-hitracemeter.md)。API文档请参考[HitraceMeter API参考](./hitracemeter-guidelines.md)。
## 接口说明
| 方法 | 接口描述 | 
| -------- | -------- |
| void OH_HiTrace_StartTrace(const char* name) | 开启一个同步时间片跟踪事件 | 
| void OH_HiTrace_FinishTrace() | 结束一个同步时间片跟踪事件 | 
| void OH_HiTrace_StartAsyncTrace(const char* name, int32_t taskId) | 开启一个异步时间片跟踪事件 | 
| void OH_HiTrace_FinishAsyncTrace(const char* name, int32_t taskId) | 结束一个异步时间片跟踪事件 | 
| void OH_HiTrace_CountTrace(const char* name, int64_t count) | 整数跟踪事件 | 
## 参数解析
| 参数名 | 类型 | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| name   | string | 否   | 要跟踪的数值变量名称。 |
| taskId | number | 否   | 用来表示关联的ID,如果有多个name相同的任务是并行执行的，则每次调用startTrace的taskId不同。 |
| count  | number | 否   | 变量的值。  |
## 开发示例
1.在CMakeLists.txt中新增libhitrace_ndk.z.so链接：
```
target_link_libraries(entry PUBLIC libhitrace_ndk.z.so)
```
2.在源文件中包含hitrace头文件：
```c++
#include "hitrace/trace.h"
```
3.打开hdc shell，使能trace
```shell
# hitrace --trace_begin app
capturing trace...
```
4.进行性能打点，以同步打点为例：
```c++
OH_HiTrace_StartTrace("testHitrace");
OH_HiTrace_FinishTrace();
```
5.dump trace查看结果：
```shell
# hitrace --trace_dump | grep hitraceTest
        <...>-8763      (-----) [002] ... 6425.617353: tracing_mark_write: B|8763|H:hitraceTest
```