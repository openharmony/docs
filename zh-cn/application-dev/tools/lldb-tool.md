# LLDB工具
## 概述
LLDB（Low Level Debugger）是新一代高性能调试器。详细说明参考[LLDB官方文档](https://lldb.llvm.org/)。

当前OpenHarmony中的LLDB工具是在[llvm15.0.4](https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.4)基础上适配演进出来的工具，是HUAWEI DevEco Studio工具中默认的调试器，支持调试C和C++应用。

## 工具获取
通过OpenHarmony的SDK获取，获取路径：http://ci.openharmony.cn/workbench/cicd/dailybuild 。

lldb工具在SDK中的路径为`\ohos-sdk\[system]\native\llvm`，其中system可选windows/linux/darwin。

以Windows平台为例，解压SDK后，lldb.exe的存放路径为`\ohos-sdk\windows\native\llvm\bin`。

## 功能列表

此处列举LLDB调试器支持的部分功能，更多功能与相关命令可见：[LLDB工具使用指导](https://gitee.com/openharmony/third_party_llvm-project/blob/master/lldb/README_zh.md)和[LLDB官网手册](https://lldb.llvm.org/use/map.html#)。

- 记录日志

- 断点管理

- 观察点管理

- 表达式处理

- 查看变量

- 进程/线程管理

- 汇编处理

- 源码信息获取

- 信号处理

- 进程启动

- attach进程

## 应用场景

### 本地调试

- Linux x86_64本地调试。

  LLDB支持在Linux x86_64环境上调试C和C++应用。

- Mac桌面本地调试。

  LLDB支持在Mac桌面（包括Mac x86_64和M1系统）调试C和C++应用。

### 远程调试

- 基于HUAWEI DevEco Studio的远程调试。

  LLDB支持基于HUAWEI DevEco Studio在Windows和Mac桌面连接OpenHarmony设备或模拟器远程调试Native C++应用，即使用HUAWEI DevEco Studio的Debug调试功能。

- 桌面连接OpenHarmony设备远程调试。

  LLDB支持在Windows、Mac桌面和Linux x86_64环境直连OpenHarmony设备远程调试C和C++应用。

## 使用指导

### 本地调试

> **说明：**
>
> Linux x86_64或Mac本地调试步骤一致。	

**使用步骤**

- 使用LLDB工具启动应用并进行调试。

   此处以在Linux x86_64环境调试一个使用clang编译器生成的带有调试信息的可执行文件a.out为例。

   1. 获取到与LLDB同一版本的clang编译器生成的带有调试信息的可执行文件a.out。

   2. 运行LLDB工具，并指定要调试的文件为a.out。

      ```lldb
      ./lldb a.out
      ```

   3. 在代码中main函数处设置断点。

      ```lldb
      (lldb) b main
      ```

   4. 运行应用，使其停在断点处。

      ```lldb
      (lldb) run
      ```

   5. 继续运行应用。

      ```lldb
      (lldb) continue
      ```

   6. 列出所有断点。

      ```lldb
      (lldb) breakpoint list
      ```

   7. 显示当前帧的参数和局部变量。

      ```lldb
      (lldb) frame variable
      ```

   8. 按需执行调试命令进行后续调试操作。

   9. 退出调试。

      ```lldb
      (lldb) quit
      ```

- 使用LLDB工具调试已经启动的应用。

   此处以在Mac环境调试一个使用clang编译器生成的带有调试信息的带用户输入的可执行文件a.out为例。
   
   1. 在命令行窗口1启动应用。（窗口会返回一条信息“Please input a number of type int”）
      ```shell
      ./a.out
      ```
   
   2. 在命令行窗口2运行LLDB工具。
      ```shell
      ./lldb
      ```
   
   3. attach应用。
   
      ```lldb
      (lldb) process attach --name a.out
      ```
   
   4. 在`hello.cpp`的第10行设置断点
   
      ```lldb
      (lldb) breakpoint set --file hello.cpp --line 12
      ```
   
   5. 在命令行窗口1，输入一个int类型的数。
   
      ```shell
      88
      ```
   
   6. 在命令行窗口2继续运行应用，使应用停在断点处。
   
      ````lldb
      (lldb) continue
      ````
   
   7. 按需执行调试命令进行后续调试操作。
   
   8. detach应用。
   
      ```lldb
      (lldb) detach
      ```
   
   9. 退出调试。
   
      ```lldb
      (lldb) quit
      ```
   
   > **说明：**
   >
   > 步骤3和4可以调换顺序执行。


### 远程调试

> **说明：**
>
> - 远程调试时需要lldb-server和lldb配合使用。
> - Windows，Linux x86_64和Mac远程调试步骤一致。
>

**使用步骤**

此处以在Windows平台连接arm架构OpenHarmony设备（如：RK3568开发板）进行远程调试为例。

> **说明：**
>
> 其中/data/local/tmp为设备上指定的目录。
>
> 8080为监听端口，可自定义。
>
> 请确保设备上的lldb-server和a.out有可执行权限。
>

1. 打开命令行窗口1，将lldb-server和可执行文件a.out推送到设备。（a.out是使用clang编译器编译hello.cpp生成的。）

   ```shell
   hdc file send lldb-server /data/local/tmp
   hdc file send a.out /data/local/tmp
   ```

2. 运行lldb-server。

   ```shell
   hdc shell ./data/local/tmp/lldb-server p --server --listen "*:8080"
   ```

3. 打开命令行窗口2，运行二进制文件lldb。

   ```shell
   ./lldb
   ```

4. 在LLDB命令行窗口进行远端选择与连接。

   ```lldb
   (lldb) platform select remote-ohos
   (lldb) platform connect connect://localhost:8080 
   ```

5. 指定要调试的设备上的二进制文件a.out。

   ```lldb
   (lldb) target create /data/local/tmp/a.out
   ```

6. 在代码中main函数处设置断点。

   ```lldb
   (lldb) b main
   ```

7. 启动应用。

   ```lldb
   (lldb) run
   ```

8. 查看当前目标进程的源码。

   ```lldb
   (lldb) source list
   ```

9. 按需执行调试命令进行后续调试操作。

10. 退出调试。

    ```lldb
    (lldb) quit
    ```
