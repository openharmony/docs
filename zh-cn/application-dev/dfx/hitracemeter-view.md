# 查看HiTraceMeter日志

## 通过DevEco Studio可视化界面查看

使用DevEco Studio Profiler的CPU Insight功能，可视化展示HiTraceMeter日志内容，分析应用或服务的CPU使用率和线程运行状态，查看指定时间段内程序在CPU上的执行耗时。具体使用指导请参考[CPU活动分析：CPU分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-insight-session-cpu)。

## 通过命令行工具查看

1. 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)，确保可以使用 `hdc shell` 命令正常连接设备。

2. 在DevEco Studio的Terminal窗口或主机命令行窗口执行 `hdc shell` 命令连接设备，然后在设备上执行[hitrace](hitrace.md)命令，开启HiTraceMeter日志抓取服务。

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

3. 在设备上运行包含HiTraceMeter打点的相关程序。

4. 转储HiTraceMeter文本日志，该日志包含步骤3中生成的HiTraceMeter打点信息。

   - 默认将日志打印在窗口中。

   ```shell
   $ hitrace --trace_dump
   ```

   - 可提供文件名将日志保存至文件中，文件路径只能是 `/data/local/tmp/`，其他路径无权限。

   ```shell
   $ hitrace --trace_dump -o /data/local/tmp/trace.ftrace
   ```

5. 在设备上执行hitrace命令，停止HiTraceMeter日志抓取服务。

   ```shell
   $ hitrace --trace_finish
   ```

6. 退出设备，进入主机，导出设备中的HiTraceMeter文本日志到当前目录。

   ```shell
   $ exit
   PS D:\xxx\xxx> hdc file recv /data/local/tmp/trace.ftrace ./
   ```

7. 搜索HiTraceMeter文本日志中的打点名称等关键字，查看打点是否成功。

8. HiTraceMeter支持文本日志的可视化分析。

   - 导入DevEco Studio进行分析。
     在DevEco Studio Profiler的会话区选择“Open File”，将HiTraceMeter文本日志导入DevEco Studio。
     具体分析可参考[CPU活动分析：CPU分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-insight-session-cpu)文档。
   - 通过[HiSmartPerf](https://gitee.com/openharmony/developtools_smartperf_host)工具进行分析，工具下载链接[developtools_smartperf_host 发行版](https://gitee.com/openharmony/developtools_smartperf_host/releases)。
