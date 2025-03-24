# 查看HiTraceMeter日志

## 通过DevEco Studio可视化界面查看

开发者可使用 DevEco Studio Profiler 的 CPU Insight 功能，可视化展示 HiTraceMeter 日志内容，分析应用/服务的 CPU 使用率和线程的运行状态，查看指定时间段内程序在 CPU 上的执行耗时情况，具体使用指导请参考[CPU活动分析：CPU分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-insight-session-cpu-V5)。

## 通过命令行工具查看

1. 根据 hdc 命令行工具指导，完成[环境准备](hdc.md#环境准备)，可以使用 `hdc shell` 命令正常连接设备。

2. 在 DevEco Studio 的 Terminal 窗口或主机命令行窗口执行 `hdc shell` 命令连接设备，在设备上执行 [hitrace](hitrace.md) 命令开启 HiTraceMeter 日志抓取服务。

   ```shell
   PS D:\xxx\xxx> hdc shell
   # hitrace --trace_begin app
   ```

3. 在设备上运行包含 HiTraceMeter 打点的相关程序。

4. 转储 HiTraceMeter 文本日志，该日志中包含步骤 3 中的 HiTraceMeter 打点信息。

   - 默认将日志打印在窗口中。

   ```shell
   # hitrace --trace_dump
   ```

   - 可提供文件名将日志保存至文件中，文件路径只能是 `/data/local/tmp/`，其他路径无权限。

   ```shell
   # hitrace --trace_dump -o /data/local/tmp/trace.ftrace
   ```

5. 在设备上执行 hitrace 命令结束 HiTraceMeter 日志抓取服务。

   ```shell
   # hitrace --trace_finish
   ```

6. 退出设备，进入主机，将设备中 HiTraceMeter 文本日志导出到当前目录。

   ```shell
   # exit
   PS D:\xxx\xxx> hdc file recv /data/local/tmp/trace.ftrace ./
   ```

7. 可在 HiTraceMeter 文本日志中搜索打点名称等关键字查看打点是否成功。

8. HiTraceMeter 文本日志可视化分析。

   - 导入 DevEco Studio 进行分析，具体参考[CPU活动分析：CPU分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-insight-session-cpu-V5)文档，在 DevEco Studio Profiler 的会话区选择“Open File”，将 HiTraceMeter 文本日志导入 DevEco Studio 进行分析。
   - 通过 [HiSmartPerf](https://gitee.com/openharmony/developtools_smartperf_host) 工具进行分析，工具下载链接[developtools_smartperf_host 发行版](https://gitee.com/openharmony/developtools_smartperf_host/releases)。

