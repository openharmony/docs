# 查看HiTraceMeter日志


## 在DevEco Studio上使用

开发者可使用DevEco Studio Profiler的CPU Insight，查看应用/服务的CPU使用率和线程的运行状态，了解指定时间段内的CPU资源消耗情况，查看系统的关键打点，具体使用指导请参考<!--RP1-->[CPU活动分析：CPU分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-insight-session-cpu-V5)<!--RP1End-->。

## 通过命令行工具使用

1. 执行hilog -b D，修改日志打印级别。

2. 执行hilog |grep hitrace即可查看hitrace相关日志。
