# LLDB工具
## 概述
LLDB（Low Level Debugger）是新一代高性能调试器。具备断点设置、变量查看与修改、内存操作、线程控制、表达式计算、堆栈回溯等功能，并支持跨平台和插件扩展。

当前OpenHarmony中的LLDB工具是在[llvm15.0.4](https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.4)基础上适配演进出来的，是HUAWEI DevEco Studio工具链中默认的调试器，支持调试C和C++应用程序。

详细说明参考[LLDB官方文档](https://lldb.llvm.org/)。

## 功能特点

LLDB调试器具备以下功能特点：
- **强大的调试功能**：支持断点设置、变量查看与修改、内存操作、线程控制、表达式计算、堆栈回溯等。
- **跨平台支持**：适用于Windows、Linux x86_64、ohos和Mac平台。
- **插件扩展性**：支持插件扩展，方便开发者根据需求进行定制。

## 工具获取路径
通过OpenHarmony的SDK获取，获取路径：http://ci.openharmony.cn/workbench/cicd/dailybuild。

lldb工具在SDK中的路径为`\ohos-sdk\[system]\native\llvm`，其中system可选windows/linux/darwin。

- lldb客户端 (Windows系统) 执行文件路径：
    ```bash
    \ohos-sdk\windows\native\llvm\bin\lldb.exe
    ```

## 功能列表

此处列举LLDB调试器支持的部分功能，更多命令参考：[LLDB工具使用指导](https://gitee.com/openharmony/third_party_llvm-project/blob/master/lldb/README_zh.md)和[LLDB官网手册](https://lldb.llvm.org/use/map.html#)。Windows、Linux x86_64和Mac平台的LLDB工具有些许差异，以实际应用为准。

- 记录日志

```bash
# 记录完整调试会话到文件
(lldb) log enable -F -T -p -f d:\lldb.log lldb all
(lldb) log enable -F -T -p -f d:\lldbgdbremote.log gdb-remote all
# 示例：过滤只记录断点事件
(lldb) log enable -f /tmp/breakpoints.log lldb break
# 查看当前日志配置
(lldb) log list
```

- 断点管理

```bash
# 设置函数断点（支持模糊匹配）
(lldb) breakpoint -f main.cpp -l 266
# 设置条件断点（当x>100时触发）
(lldb) breakpoint set -f main.cpp -l 20 -c '(x > 100)'
# 列出所有断点
(lldb) breakpoint list
# 临时禁用断点
(lldb) breakpoint disable 1
```

- 观察点管理

```bash
# 监控变量变化
(lldb) watchpoint set variable global_var
# 监控内存地址变化
(lldb) watchpoint set expression -w write -- 0x7ffeefbff5d8
# 查看观察点列表
(lldb) watchpoint list
```
- 表达式处理

```bash
# 创建变量
（lldb）print int $value1 = 7
（lldb）expression int $value2 = 7
# 打印变量值
(lldb) print $value1
(lldb) expression $value2
# 变量运算
(lldb) expression $value1 * 3
# 格式化输出（16进制显示）
(lldb) p/x 12345
```

- 查看变量

```bash
# 查看当前帧的已初始化的局部变量
(lldb) frame variable
# 查看全局变量和静态变量
(lldb) frame variable -g
# 查看寄存器
(lldb) register read
```

- 进程/线程管理

```bash
# 显示线程回溯（所有线程）
(lldb) thread backtrace all
# 单步跳过（Step over）
(lldb) thread step-over (或next)
# 跳出当前选定的帧（步出）
(lldb) thread step-out (或finish)
```

- 汇编处理

```bash
# 查看寄存器
(lldb) register read
# 更改pc寄存器
(lldb) register write pc `$pc+8`
# 查看当前堆栈帧的汇编指令
(lldb) disassemble --frame (或 dis -f )
# 查看main函数的汇编指令
(lldb) disassemble -name main
# 汇编单步执行程序，步过（不进入函数体）
(lldb) nexti
# 汇编单步执行程序，步入（进入函数体）
(lldb) stepi
```

- 源码信息获取

```bash
(lldb) source list
```

- 信号处理

```bash
# 捕获信号时打印回溯
(lldb) process handle SIGSEGV -s true
# 查看当前信号处理配置
(lldb) process handle
```

- attach进程

```bash
# 附加到PID（需调试权限）
(lldb) process attach -p 1234
```

## 环境准备
- 本地调试
   ■ 无需DevEco IDE，直接设备端调试
   ■ 选择静态化lldb路径并使用hdc传输到设备：
    ```bash
    
    hdc file send \ohos-sdk\[system]\native\llvm\lib\clang\[version]\bin\aarch64-linux-ohos\lldb /data/local/tmp/debugserver
    ```
   ■ 选择lldb server路径（根据设备CPU架构选择）并使用hdc传输到设备：
    ```bash
    hdc file send \ohos-sdk\[system]\native\llvm\lib\clang\[version]\bin\aarch64-linux-ohos\lldb-server /data/local/tmp/debugserver
    ```
- 远程调试（主要调试方式）
      * 一键调试：
          ■ 下载HUAWEI IDE，根据IDE的调试方法即可进行一键调试：通过DevEco Studio调试。
          ■ 支持Windows/Mac连接OpenHarmony设备，支持调试Native C++应用。
          ■ 直接使用DevEco Studio的Debug功能即可，无需手动推送lldb或lldb-server。
    * 手动调试：
      ■ 如需要手动进行远程调试（不通过DevEco Studio），如调试二进制等，则需要保证设备上有lldb-server，PC上有lldb
      ■ 准备lldb-server，建议使用DevEco IDE推送。如手动推送，选择lldb-server路径并使用hdc传输到设备：
      ```bash
      hdc file send \ohos-sdk\[system]\native\llvm\lib\clang\[version]\bin\aarch64-linux-ohos\lldb-server /data/local/tmp/debugserver
      ```
      ■ PC上准备lldb，如windows系统则使用lldb.exe, 稍后将使用lldb与OH设备上的lldb-server远程连接进行调试。

## 使用指导-本地调试

### 使用LLDB工具启动并调试应用

   此处以在Linux x86_64环境下，调试一个使用Clang编译器生成的、带有调试信息的可执行文件a.out为例。
   源文件：hello.cpp
```cpp
#include <iostream>
using namespace std;
int main() {
    cout << "hello world!" <<endl;
    return 0;
}
```
编译：
```cpp
<clang distribution>/bin/clang++ --target=aarch64-linux-ohos --sysroot=<sysroot distribution> -g hello.cpp -o a.out
```
   1. 获取到与LLDB同一版本的clang编译器生成的带有调试信息的可执行文件a.out。
   2. 使用hdc shell进入手机交互命令环境，进入lldb路径。
   3. 运行LLDB工具，并指定要调试的文件为a.out。

      ```shell
      ./lldb a.out
      ```

   4. 在代码中main函数处设置断点。

      ```shell
      (lldb) b main
      ```

   5. 运行应用，使其停在断点处。

      ```shell
      (lldb) run
      ```

   6. 继续运行应用。

      ```shell
      (lldb) continue
      ```

   7. 列出所有断点。

      ```shell
      (lldb) breakpoint list
      ```

   8. 显示当前帧的参数和局部变量。

      ```shell
      (lldb) frame variable
      ```

   9. 按需执行调试命令进行后续调试操作。

   10. 退出调试。

          ```shell
          (lldb) quit
          ```

#### 使用LLDB工具调试已经启动的应用。

此处以在手机环境调试一个使用clang编译器生成的带有调试信息和用户输入的可执行文件a.out为例。
源文件：hello.cpp

```cpp
#include <iostream>
using namespace std;
int main() {
    int i = 0, j = 5, sum = 0;
    cout << "Please input a number of type int" <<endl;
    cin >> i;
    cout << i;
    sum = i + j;
    cout << sum <<endl;
    return 0;
}
```

编译：

```cpp
<clang distribution>/bin/clang++ --target=aarch64-linux-ohos --sysroot=<sysroot distribution> -g hello.cpp -o a.out
```

1. 使用hdc shell进入交互命令环境，进入lldb路径。
2. 在命令行窗口1启动应用。（窗口会返回一条信息“Please input a number of type int”。）
   ```shell
   ./a.out
   ```

3. 在命令行窗口2运行LLDB工具。
   ```shell
   ./lldb
   ```

4. attach应用。

   ```shell
   (lldb) process attach --name a.out
   ```

5. 在`hello.cpp`的第10行设置断点。

   ```shell
   (lldb) breakpoint set --file hello.cpp --line 12
   ```

6. 在命令行窗口1，输入一个int类型的数。

   ```shell
   88
   ```

7. 在命令行窗口2继续运行应用，使应用停在断点处。

   ````shell
   (lldb) continue
   ````

8. 按需执行调试命令进行后续调试操作。

9. detach应用。

   ```shell
   (lldb) detach
   ```

10. 退出调试。

    ```shell
    (lldb) quit
    ```

> **说明：**
>
> 步骤attach应用和设置断点可以调换顺序执行。


## 使用指导-远程调试

> **说明：**
> - 远程调试是指使用lldb进行跨端调试。本章节主要针对开发者跨平台调试OpenHarmony设备的应用进行说明。
> - 远程调试时需要lldb-server和lldb配合使用。
> - Windows，Linux x86_64和Mac远程调试步骤一致。
>

### 远程调试

此处以在Windows平台连接arm架构OpenHarmony设备（如：RK3568开发板）进行远程调试为例。

> **说明：**
>
> 其中/data/local/tmp为设备上指定的目录。
>
> 8080为监听端口，可自定义。
>
> 请确保设备上的lldb-server和a.out有可执行权限。
>
源文件：hello.cpp
```cpp
#include <iostream>
using namespace std;
int main() {
    cout << "hello world!" <<endl;
    return 0;
}
```

编译：
```bash
<clang distribution>/bin/clang++ --target=aarch64-linux-ohos --sysroot=<sysroot distribution> -g hello.cpp -o a.out
```

1. 打开命令行窗口1，关闭SELinux。
   ```shell
   hdc shell setenforce 0
   ```

2. 打开命令行窗口1，将lldb-server和可执行文件a.out推送到设备。（a.out是使用clang编译器编译hello.cpp生成的。）

   ```shell
   hdc file send lldb-server /data/local/tmp
   hdc file send a.out /data/local/tmp
   ```

3. 运行lldb-server。

   ```shell
   hdc shell ./data/local/tmp/lldb-server p --server --listen "*:8080"
   ```

4. 打开命令行窗口2，运行二进制文件lldb。

   ```shell
   ./lldb
   ```

5. 在LLDB命令行窗口进行远端选择与连接。

   ```shell
   (lldb) platform select remote-ohos
   (lldb) platform connect connect://localhost:8080 
   ```

6. 指定要调试的设备上的二进制文件a.out。

   ```shell
   (lldb) target create /data/local/tmp/a.out
   ```

7. 在代码中main函数处设置断点。

   ```shell
   (lldb) b main
   ```

8. 启动应用。

   ```shell
   (lldb) run
   ```

9. 查看当前目标进程的源码。

   ```shell
   (lldb) source list
   ```

10. 按需执行调试命令进行后续调试操作。

11. 退出调试。

    ```shell
    (lldb) quit
    ```

## FAQ
- 当在LLDB调试环境中执行run命令时，若控制台返回"error: 'A' packet returned an error: 8"或类似错误代码，此问题通常表明调试器无法创建调试进程。
该异常现象主要由权限不足引发，建议通过以下步骤排查：

    1）验证目标设备是否已开启调试授权；

    验证方式为设备上设置中的”开发者选项”，如果没有开启，开启后再尝试调试。

     2）确认当前用户是否具有目标进程的调试权限。

    user用户只能调试应用，不能调试可执行文件。

- 运行lldb-server，报错“Permission denied”。一般是lldb-server无可执行文件导致的，添加权限即可。