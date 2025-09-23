# LLDB
## Overview
Low Level Debugger (LLDB) is a next-generation, high-performance debugger. Provides functions such as breakpoint setting, variable viewing and modification, memory operation, thread control, expression calculation, and stack backtracking, and supports cross-platform and plug-in extension.

The LLDB tool in OpenHarmony is evolved based on [llvm15.0.4](https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.4). It is the default debugger of the HUAWEI DevEco Studio toolchain and supports debugging of C and C++ applications.

For details, visit the [LLDB official website](https://lldb.llvm.org/).

## **Features**

The LLDB debugger has the following features:
- **Powerful debugging functions**: Breakpoint setting, variable viewing and modification, memory operations, thread control, expression calculation, and stack backtracking are supported.
- **Cross-platform support**: Windows, Linux x86_64, OHOS, and Mac platforms.
- **Plugin scalability**: Plugins can be extended for developers to customize based on requirements.

## How to Obtain
Obtain the OpenHarmony SDK from the following website: http://ci.openharmony.cn/workbench/cicd/dailybuild

Find LLDB in the **\ohos-sdk\[system]\native\llvm** directory of the SDK, where **system** can be **windows**, **linux**, or **darwin**.

- Path of the executable file of the lldb client (Windows):
    ```bash
    \ohos-sdk\windows\native\llvm\bin\lldb.exe
    ```

## Functions

The following lists some functions supported by LLDB. For more functions and related commands, see [LLDB Usage Guide](https://gitee.com/openharmony/third_party_llvm-project/blob/master/lldb/README.md) and [LLDB official manual](https://lldb.llvm.org/use/map.html#). The LLDB tools on the Windows, Linux x86_64, and Mac platforms are slightly different.

- Logging

```bash
# Recording Complete Debugging Sessions to a File
(lldb) log enable -F -T -p -f d:\lldb.log lldb all
(lldb) log enable -F -T -p -f d:\lldbgdbremote.log gdb-remote all
# Example: Filtering Out Only Breakpoint Events
(lldb) log enable -f /tmp/breakpoints.log lldb break
# View the current log configuration.
(lldb) log list
```

- Breakpoint management

```bash
# Setting Function Breakpoints (Fuzzy Match Supported)
(lldb) breakpoint -f main.cpp -l 266
# Sets a conditional breakpoint (triggered when x is greater than 100).
(lldb) breakpoint set -f main.cpp -l 20 -c '(x > 100)'
# List all the breakpoints.
(lldb) breakpoint list
# Temporarily Disabling Breakpoints
(lldb) breakpoint disable 1
```

- Watchpoint management

```bash
# Monitoring variable changes
(lldb) watchpoint set variable global_var
# Monitoring Memory Address Changes
(lldb) watchpoint set expression -w write -- 0x7ffeefbff5d8
# Viewing the Watchpoint List
(lldb) watchpoint list
```
- Expression processing

```bash
# Create variable
(lldb)print int $value1 = 7
(lldb)expression int $value2 = 7
# Print a variable value.
(lldb) print $value1
(lldb) expression $value2
# Calculate a variable.
(lldb) expression $value1 * 3
# Formatted output (hexadecimal display)
(lldb) p/x 12345
```

- Viewing variables

```bash
# Views the initialized local variables of the current frame.
(lldb) frame variable
# Viewing Global and Static Variables
(lldb) frame variable -g
# Check the register.
(lldb) register read
```

- Process/Thread management

```bash
# Displaying Thread Backtracking (All Threads)
(lldb) thread backtrace all
# Step over
(lldb) thread step-over (or next)
# Jump out of the currently selected frame (step out)
(lldb) thread step-out (or finish)
```

- Assembly processing

```bash
# Check the register.
(lldb) register read
# Modify the PC register.
(lldb) register write pc `$pc+8`
# Check the assembly instruction of the current stack frame.
(lldb) disassemble --frame (or dis -f)
# Check the assembly instruction of the main function.
(lldb) disassemble -name main
# The assembly executes the program step by step (without entering the function body).
(lldb) nexti
# Assembly single-step execution program, step in (entering the function body)
(lldb) stepi
```

- Obtaining source code information

```bash
(lldb) source list
```

- Signal processing

```bash
# Printing Backtracking During Signal Capture
(lldb) process handle SIGSEGV -s true
# Check the current signal processing configuration.
(lldb) process handle
```

- Attaching to a process

```bash
# Attach to PID (debugging permission required)
(lldb) process attach -p 1234
```

## Environment Setup
- Local Debugging
	- You can directly perform debugging on the device without using DevEco IDE.
    - Select the static lldb path and transfer it to the device using HDC.
    ```bash
    hdc file send \ohos-sdk\[system]\native\llvm\lib\clang\[version]\bin\aarch64-linux-ohos\lldb /data/local/tmp/debugserver
	 ```
   -  Select the LLDB server path (based on the CPU architecture of the device) and use HDC to transfer the file to the device.
    
    ```bash
    hdc file send \ohos-sdk\[system]\native\llvm\lib\clang\[version]\bin\aarch64-linux-ohos\lldb-server /data/local/tmp/debugserver
    ```
- Remote Debugging (Main Debugging Mode)
	- One-click debugging
    	- Download HUAWEI IDE and perform one-click debugging using DevEco Studio.
        - OpenHarmony devices can be connected to Windows and Mac, and native C++ applications can be debugged.
        - Use the debugging function of DevEco Studio. You do not need to manually push lldb or lldb-server.
    - Manual commissioning:
       - If you need to manually perform remote debugging (without using DevEco Studio), for example, debugging binary files, ensure that lldb-server is installed on the device and lldb is installed on the PC.
       - Prepare lldb-server. You are advised to use DevEco IDE to push lldb-server. For manual push, select the lldb-server path and use HDC to transfer the file to the device.
        ```bash
        hdc file send \ohos-sdk\[system]\native\llvm\lib\clang\[version]\bin\aarch64-linux-ohos\lldb-server /data/local/tmp/debugserver
        ```
        - Prepare the LLDB on the PC. For example, use lldb.exe in the Windows operating system. Later, use the LLDB to remotely connect to the lldb-server on the OH device for debugging.

## Local Debugging

### Using LLDB to Start and Debug an Application

   The following walks you through on how to debug an executable file named **a.out** in the Linux x86_64 environment. The file contains debugging information and is generated by the Clang compiler, which is of the same version as LLDB.
   Source file: hello.cpp
```cpp
#include <iostream>
using namespace std;
int main() {
    cout << "hello world!" << endl;
    return 0;
}
```
Compilation
```cpp
<clang distribution>/bin/clang++ --target=aarch64-linux-ohos --sysroot=<sysroot distribution> -g hello.cpp -o a.out
```
   1. Obtain the executable file **a.out**.
   2. Run the hdc shell command to enter the interactive command environment of the mobile phone and go to the lldb directory.
   3. Run LLDB and specify the file to debug as **a.out**.

      ```shell
      ./lldb a.out
      ```

   4. Set breakpoints at the **main** function in the code.

      ```shell
      (lldb) b main
      ```

   5. Run the application, and it stops at the first breakpoint.

      ```shell
      (lldb) run
      ```

   6. Continue to run the application.

      ```shell
      (lldb) continue
      ```

   7. List all the breakpoints.

      ```shell
      (lldb) breakpoint list
      ```

   8. Show the arguments and local variables of the current frame.

      ```shell
      (lldb) frame variable
      ```

   9. Run debugging commands as required to continue debugging.

   10. Exit debugging.

          ```shell
          (lldb) quit
          ```

Using LLDB to debug a started application

The following walks you through on how to debug an executable file named **a.out** in the Linux x86_64 environment. The file contains debugging information and is generated by the Clang compiler, which is of the same version as LLDB.
Source file: hello.cpp

```cpp
#include <iostream>
using namespace std;
int main() {
    int i = 0, j = 5, sum = 0;
    cout << "Please input a number of type int" << endl;
    cin >> i;
    cout << i;
    sum = i + j;
    cout << sum << endl;
    return 0;
}
```

Compilation

```cpp
<clang distribution>/bin/clang++ --target=aarch64-linux-ohos --sysroot=<sysroot distribution> -g hello.cpp -o a.out
```

1. Run the hdc shell command to enter the interactive command environment and go to the lldb directory.
2. Start the application on Command Line Interface (CLI) 1. (The message "Please input a number of type int" is displayed.)
   ```shell
   ./a.out
   ```

3. Run LLDB on CLI 2.
   ```shell
   ./lldb
   ```

4. Attach to the application.

   ```shell
   (lldb) process attach --name a.out
   ```

5. Set a breakpoint in line 10 of **hello.cpp**.

   ```shell
   (lldb) breakpoint set --file hello.cpp --line 10
   ```

6. On CLI 1, enter a number of the int type.

   ```shell
   88
   ```

7. Continue to run the application on CLI 2. The application stops at the breakpoint.

   ````shell
   (lldb) continue
   ````

8. Run debugging commands as required to continue debugging.

9. Detach from the application.

   ```shell
   (lldb) detach
   ```

10. Exit debugging.

    ```shell
    (lldb) quit
    ```

> **NOTE**
>
> Steps attach and set breakpoints can be performed in different sequences.


## Remote Debugging

> **NOTE**
> - Remote debugging refers to cross-device debugging using LLDB. This section describes how to debug OpenHarmony apps across platforms.
> - During remote debugging, **lldb-server** and **lldb** must be used together.
> - The remote debugging procedures for Windows, Linux x86_64, and macOS are the same.
>

### Remote Debugging

The following walks you through on how to remotely debug an executable file named **a.out** by connecting to an ARM-based OpenHarmony device (for example, RK3568 development board) on the Windows platform.

> **NOTE**
>
> In the command below, **/data/local/tmp** indicates the specified directory on the device.
>
> **8080** is the listening port, which can be customized.
>
> You must have the execute permission on the **lldb-server** and **a.out** files of the device.
>
Source file: hello.cpp
```cpp
#include <iostream>
using namespace std;
int main() {
    cout << "hello world!" << endl;
    return 0;
}
```

Compilation
```bash
<clang distribution>/bin/clang++ --target=aarch64-linux-ohos --sysroot=<sysroot distribution> -g hello.cpp -o a.out
```

1. Open CLI 1 and disable SELinux.
   ```shell
   hdc shell setenforce 0
   ```

2. Open CLI 1 and push **lldb-server** and **a.out** to the device. (**a.out** is generated when you compile **hello.cpp** using the Clang compiler.)

   ```shell
   hdc file send lldb-server /data/local/tmp
   hdc file send a.out /data/local/tmp
   ```

3. Run **lldb-server**.

   ```shell
   hdc shell ./data/local/tmp/lldb-server p --server --listen "*:8080"
   ```

4. Open CLI 2 and run the binary file **lldb**.

   ```shell
   ./lldb
   ```

5. Select and connect to the remote device on the LLDB CLI.

   ```shell
   (lldb) platform select remote-ohos
   (lldb) platform connect connect://localhost:8080 
   ```

6. Specify the binary file **a.out** on the device to be debugged.

   ```shell
   (lldb) target create /data/local/tmp/a.out
   ```

7. Set breakpoints at the **main** function in the code.

   ```shell
   (lldb) b main
   ```

8. Start the application.

   ```shell
   (lldb) run
   ```

9. Display source code for the current target process.

   ```shell
   (lldb) source list
   ```

10. Run debugging commands as required to continue debugging.

11. Exit debugging.

    ```shell
    (lldb) quit
    ```

## FAQs
- When the run command is executed in the LLDB debugging environment, if the console returns `error: 'A' packet returned an error: 8` or a similar error code, the debugger cannot create a debugging process. This exception usually indicates that the debugger cannot create a debugging process due to insufficient permission. You are advised to perform the following steps:

   (1) Check whether debugging authorization has been enabled for the target device.

   The verification method is `Developer options` in the device settings. If it is not enabled, enable it and try again.

   (2) Check whether the current user has the debugging permission on the target process.

   The user can only debug applications but cannot debug executable files.

- When lldb-server is run, the error message " `Permission denied`" is displayed. Generally, this problem occurs because the lldb-server does not have executable files. In this case, add the permission.
