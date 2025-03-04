# HiDumper概述


## 功能简介

HiDumper是OpenHarmony为开发、测试人员、IDE工具提供的系统信息获取工具，帮助开发者分析、定位问题。本章节内容适用于标准系统。

## 源码目录说明

  
```
/base/hiviewdfx/hidumper
├── frameworks           # 框架代码
│   ├── native           # 导出功能核心代码
│   │  │── include       # 头文件目录
│   │  │── src           # 源文件目录
│   │      │── common    # 通用功能代码
│   │      │── executor  # 导出过程执行器代码
│   │      │── factory   # 跟进导出项生成导出执行器
│   │      │── manager   # 导出管理核心代码
│   │      │── util      # 工具类源代码
│── sa_profile           # Hidumper sa属性文件
│── services             # Hidumper服务源码
│   │── native           # 服务C++源码
│   │── zidl             # 通讯功能源码目录
│   │   │── include      # 通讯功能头文件
│   │   │── src          # 通讯功能源代码
├── test                 # 测试用例目录
│   ├── unittest         # 单元测试代码
│   ├── moduletest       # 模块级别测试代码
```


## HiDumper使用指导


### 命令参数说明

  **表1** HiDumper命令参数说明

| 选项 | **描述** | 
| -------- | -------- |
| -h | 查看帮助信息。 | 
| -t&nbsp;[timeout] | 超时时间，单位：秒。默认值是30s。如果设置为0表示无超时限定。 | 
| -lc | 查看系统信息簇列表。 | 
| -ls | 查看系统元能力列表。 | 
| -c | 导出系统簇信息。 | 
| -c&nbsp;[base&nbsp;system] | 以base或system标签区分的系统簇信息导出。 | 
| -s | 导出全部系统元能力信息。 | 
| -s&nbsp;[SA0&nbsp;SA1] | 导出SA0、SA1等元能力id对应的元能力信息。 | 
| -s&nbsp;[SA]&nbsp;-a&nbsp;['-h'] | 以-h为参数导出SA指定的系统元能力信息。 | 
| -e | 导出Faultlog模块生成的崩溃日志。 | 
| --net&nbsp;[pid] | 导出网络信息。如果指定了进程的pid，则只获取该进程的网络流量使用信息。 | 
| --storage&nbsp;[pid] | 导出存储信息。如果指定了进程的pid，则只获取该进程的io信息。| 
| -p | 导出进程列表及全部进程信息。 | 
| -p&nbsp;[pid] | 导出指定进程号的进程全部信息。 | 
| --cpuusage&nbsp;[pid] | 导出CPU使用信息。如果指定pid则导出该进程的CPU使用信息。 | 
| --cpufreq | 导出实际的CPU频率。 | 
| --mem&nbsp;[pid] | 导出内存使用信息。如果指定pid则导出该进程的内存使用信息。 | 
| --zip | 将导出信息压缩到固定文件夹下。 | 


### 使用实例

HiDumper可以为开发者导出系统当前基本信息，通过这些基本信息可以定位分析问题。给子服务和元能力传递复杂参数时，参数需要加双引号。

具体步骤如下：

1. 进入设备命令行，输入 hidumper -h 获取基本信息介绍，功能语法介绍。
     
   ```
   hidumper -h
   ```

2. 输入 hidumper -lc 获取系统信息分类列表。
     
   ```
   hidumper -lc
   ```

3. 输入 hidumper -c 获取系统base、system等所有分类信息。
     
   ```
   hidumper -c
   ```

4. 输入 hidumper -c [base | system] 按 base 或 system 分类获取系统簇信息。
     
   ```
   hidumper -c base
   hidumper -c system
   ```

5. 输入 hidumper -ls 命令获取系统中元能力列表。
     
   ```
   hidumper -ls
   ```

6. 输入 hidumper -s 命令获取系统全部元能力信息。
     
   ```
   hidumper -s
   ```

7. 运行 hidumper -s 3301 -a "-h" 命令获取id为3301的元能力的帮助。
     
   ```
   hidumper -s 3301 -a "-h"
   ```

8. 运行 hidumper -s 3008命令获取id为3008的元能力的全部信息。
     
   ```
   hidumper -s 3008
   ```

9. 运行 hidumper -e 命令获取Faultlog模块生成的崩溃历史信息。
     
   ```
   hidumper -e
   ```

10. 运行 hidumper --net [pid] 命令获取网络信息；如果指定了进程的pid，则只获取该进程的网络流量使用信息。
     
    ```
    hidumper --net
    hidumper --net 1024
    ```

11. 运行 hidumper --storage [pid] 命令获取存储相关信息；如果指定了进程的pid，则只获取该进程的io信息。
     
    ```
    hidumper --storage
    hidumper --storage 1024
    ```

12. 运行 hidumper -p 命令获取进程信息，包括进程、线程的列表和信息。
     
    ```
    hidumper -p
    ```

13. 运行 hidumper -p 1024 命令获取pid为1024的进程信息。
     
    ```
    hidumper -p 1024
    ```

14. 运行 hidumper  --cpuusage [pid] 命令获取CPU的使用信息。如果指定了进程的pid，则只获取该进程的CPU使用信息。
     
    ```
    hidumper --cpuusage
    hidumper --cpuusage 1024
    ```

15. 运行 hidumper --cpufreq 命令获取每一个CPU核实际运行的频率。
     
    ```
    hidumper --cpufreq
    ```

16. 运行 hidumper --mem [pid] 命令获取全部的内存使用信息。如果指定进程的pid，只获取该进程的内存使用情况。
     
    ```
    hidumper --mem [pid]
    ```
    当携带pid参数时输出结果中第一列标题的详细说明如下：
    | 名称             | 描述 |
    |----------------|----|
    | GL             | GPU内存   |
    | Graph          | 图形内存  |
    | ark ts heap    | ArkTS堆的内存占用  |
    | guard          | 保护段所占内存   |
    | native heap    | 堆内存   |
    | AnonPage other | 其它没有被映射到文件的页所占内存  |
    | stack          | 栈内存   |
    | .hap           | 应用程序所占内存   |
    | .db            | 进程加载的.db数据文件所占内存   |
    | .so            | 进程加载的.so动态库所占内存   |
    | .ttf           | 进程加载的.ttf字体文件所占内存   |
    | dev            | 进程加载的以/dev开头的文件所占内存   |
    | FilePage other | 其它有被映射到文件的页所占内存   |

17. 运行 hidumper --zip 命令压缩信息数据到/data/dumper目录下。
     
    ```
    hidumper --zip
    ```

18. 运行 hidumper -t timeout 命令设置超时时间，单位：秒。默认值是30s。如果设置为0表示无超时限制。
     
    ```
    hidumper -t [timeout]
    ```

19. 运行 hidumper --mem-smaps pid [-v] 命令获取指定进程内存信息的详细使用情况。
     
    ```
    hidumper --mem-smaps pid [-v]
    ```
