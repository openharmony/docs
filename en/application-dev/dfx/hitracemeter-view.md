# Viewing HiTraceMeter Logs


## Viewing Logs on DevEco Studio

In the CPU Insight of DevEco Studio Profiler, you can view the CPU usage and thread running status of applications and services, learn about the CPU consumption in the specified period and key loggings of the system. For details, see <!--RP1-->[CPU Analysis](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-insight-session-cpu-0000001532306157-V5)<!--RP1End-->.

## Viewing Logs Using a Command Line Tool

1. Run the **hilog -b D** command to set the log level.

2. Run the **hilog |grep hitrace** command to view HiTrace logs.
