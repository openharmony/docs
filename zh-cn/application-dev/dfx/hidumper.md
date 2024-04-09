# hidumper

HiDumper为开发、测试人员提供统一的系统信息获取工具，可帮助使用者分析，定位问题。

## 前置条件

- 根据hdc命令行工具指导，完成[环境准备](hdc.md#环境准备)。

- 正常连接设备。

## 命令行说明

| 选项 | 说明 |
| -------- | -------- |
| -h  | 帮助命令。 |
| -lc | 系统信息集群列表。 |
| -ls | 系统能力列表。 |
| -c | 所有系统信息集群。 |
| -s | 所有系统能力。 |
| -e | 崩溃历史记录的故障日志。 |
| --net | 导出网络信息。 |
| --storage | 导出存储信息。 |
| -p | 进程信息，包括进程和线程的列表和信息。 |
| --cpuusage [pid] | 按进程和类别转储CPU使用率；如果指定pid，则转储指定pid的类别使用率。 |
| --cpufreq | dump每个核的真实CPU频率。 |
| --mem [pid] | dump总内存占用率；如果指定pid，则dump指定pid的内存占用率。 |
| --mem-smaps pid [-v] | 在/proc/pid/smaps中显示统计信息，使用-v指定更多详细信息。 |
| --zip | 将输出压缩到/data/log/hidumper。 |

## 常用命令

1. 查看帮助命令。

   ```
   hidumper -h
   ```

   **使用样例：**

   ![](figures/hidumper-h.png)

2. 查看设备中指定pid的内存信息，命令格式如下：

   ```
   hidumper --mem pid
   ```

   **使用样例：**

   ![](figures/hidumper-mem-pid.png)

   **Graph字段统计方式为：计算/proc/process_dmabuf_info节点下该进程使用的内存大小。**
   
3. 查看设备中所有pid的内存信息，命令格式如下：

   ```
   hidumper --mem
   ```

   **使用样例：**

   ![](figures/hidumper-mem.png)

4. 按进程和类别转储CPU使用率，命令格式如下：

   ```
   hidumper --cpuusage
   ```

   **使用样例：**

   ![](figures/hidumper-cpuusage.png)

5. 转储指定pid的类别使用率，命令格式如下：

   ```
   hidumper --cpuusage pid
   ```

   **使用样例：**

   ![](figures/hidumper-cpuusage-pid.png)

6. 获取id为3301的元能力的帮助，命令格式如下：

   ```
   hidumper -s 3301 -a "-h" 
   ```

   **使用样例：**

   ![](figures/hidumper-s-3301.png)

7. 获取RenderService的使用帮助，命令格式如下：

   ```
   hidumper -s RenderService -a "h" 
   ```

   **使用样例：**

   ![](figures/hidumper-renderservice-h.png)

8. 获取对应surface的刷新帧率，可以使用以下命令，返回值为surface刷新帧对应的时间戳。

   ```
   hidumper -s RenderService -a "surface_name fps" 
   ```

   **使用样例：**

   ![](figures/hidumper-renderservice-fps.png)
