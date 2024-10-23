# hitrace

HiTrace为开发者提供业务流程调用链跟踪的维测接口。通过使用该接口所提供的功能，帮助开发者迅速获取指定业务流程调用链的运行日志，定位跨设备、跨进程、跨线程的故障问题。

## 前置条件

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 正常连接设备。

## 命令行说明

| 命令 | 含义说明 |
| -------- | -------- |
| -h  | 帮助命令。 |
| -l | 查看tag列表。 |
| --trace_begin | 开始捕获trace。 |
| --trace_finish | 结束捕获trace。 |
| --trace_dump | 导出trace信息。 |
| -b N | 设置用于存储和读取trace的缓冲区大小(buffer size KB)。默认的缓冲区大小为2048 KB。 |
| -t N | 设置hitrace运行时长，单位为秒（默认为5秒），取决于分析所需的时间。 |
| -o | 文件名指定目标文件的名称（默认为stdout）。 |
| -z | 压缩捕获的跟踪。 |
| --trace_clock | 设置向trace添加时间戳的时钟类型，可以是引导（默认）、全局、单声道、正常运行时间或性能。 |
| --trace_finish_nodump | 停止捕获trace时不打印trace信息。 |
| --start_bgsrv | 开启快照模式trace采集服务。 |
| --dump_bgsrv | 触发快照模式trace输出到文件。 |
| --stop_bgsrv | 关闭快照模式trace采集服务。 |

> **说明**
>
> 快照模式定义为固定trace标签的trace采集服务，默认情况不落盘，开发者可通过 `--dump_bgsrv` 命令触发当前时刻的trace转储，trace为二进制格式，文件默认生成在 `/data/log/hitrace` 目录下，文件命名格式为`trace-YYMMDDHHmmSS@[BOOT_TIME].sys`。可通过[smpartperf在线工具](https://www.smartperf.host)进行查看。

## 常用命令

在hdc shell执行如下命令：

1. 查看hitrace包含的tag：`hitrace -l`。

   ![](figures/hitrace-l.png)

2. 开始抓指定tag的trace：`hitrace --trace_begin app`。

   ![](figures/hitrace-begin-app.png)

3. 结束抓trace：`hitrace --trace_finish` 、 `hitrace --trace_finish -o /data/local/tmp/test.ftrace`。默认将trace信息打印在命令行窗口，若添加输出路径，trace信息将导出至对应的文件中。

   ![](figures/hitrace-finish.png)

4. 设置抓trace的一些信息：`hitrace -b 10240 -t 10 -o /data/local/tmp/test2.ftrace app ability`。

   ![](figures/hitrace-b.png)

   - 设置缓冲区大小为10240KB；
   - 设置抓trace时间为10s；
   - 设置抓完trace后文件存储在/data/local/tmp/test1.htrace中；
   - 抓取app/ability两个tag的trace；

5. 导出trace信息：`hitrace --trace_dump` 、 `hitrace --trace_dump -o /data/local/tmp/test3.ftrace`。默认将信息显示在命令行窗口，若添加输出路径，trace信息将导出至对应的文件中。

   ![](figures/hitrace-dump.png)

   也可根据关键词打印trace信息，使用命令`hitrace --trace_dump |grep \*\*\*`即可。

6. 开启快照模式trace采集服务：`hitrace --start_bgsrv`。

   ![](figures/hitrace-start_bgsrv.png)

7. 快照模式导出trace：hitrace --dump_bgsrv。

   默认将trace信息保存至/data/log/hitrace/文件夹下，文件命名格式为`trace-YYMMDDHHmmSS@[BOOT_TIME].sys`，抓到的是二进制trace。可通过[smpartperf在线工具](https://www.smartperf.host)进行查看。

   ![](figures/hitrace-dump_bgsrv.png)

8. 关闭快照模式trace采集服务：`hitrace --stop_bgsrv`。

   ![](figures/hitrace-stop_bgsrv.png)
