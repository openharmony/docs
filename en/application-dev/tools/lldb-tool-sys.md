# LLDB (for System Applications Only)

<!--Kit: ArkTS-->
<!--Subsystem: arkcompiler-->
<!--Owner: @Maxi_241437-->
<!--Designer: @da_wei_li11-->
<!--Tester: @chenhliang-->
<!--Adviser: @k1ngqaquuu-->
<!-- md-trans-meta sourceCommit=e5b97192dbd8772da0547377cfcea671178fb9e9 translatedAt=2026-08-13T03:16:43.040Z pushedAt=2026-08-13T06:30:40.847Z -->

## Overview

Low Level Debugger (LLDB) is a next-generation, high-performance debugger. It can be used to set breakpoints, view and modify variables, perform memory operations, control threads, calculate expressions, backtrack stacks, and support cross-platform and plugin extension.

Developed based on the [llvm15.0.4](https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.4), LLDB is the default debugger in HUAWEI DevEco Studio and supports debugging of C and C++ applications.

For details, visit the [LLDB official website](https://lldb.llvm.org/).

## Features

LLDB has the following features:

- **Powerful debugging functionalities**: LLDB supports breakpoint setting, variable viewing and modification, memory operation, thread control, expression calculation, and stack backtracking.

- **Cross-platform support**: LLDB supports Windows, Linux x86_64, ohos, and macOS.

- **Plugin extension**: LLDB supports plugin extension, which allows you to customize plugins as required.

## How to Obtain

Obtain the OpenHarmony SDK from the following website: http://ci.openharmony.cn/workbench/cicd/dailybuild

Find LLDB in the **\ohos-sdk\[system]\native\llvm** directory of the SDK, where **system** can be **windows**, **linux**, or **darwin**.

- Path of the LLDB client executable file on Windows:

    ```bash
    \ohos-sdk\windows\native\llvm\bin\lldb.exe
    ```

## Functionalities

The following lists some functionalities supported by LLDB. For more commands, see [Introduction to LLDB](https://gitcode.com/openharmony/third_party_llvm-project/blob/master/lldb/README.md) and [GDB to LLDB command map](https://lldb.llvm.org/use/map.html#). LLDB differs slightly on Windows, Linux x86_64, and macOS.

- Logging

```bash
# Record the complete debugging session to a file.
(lldb) log enable -F -T -p -f d:\lldb.log lldb all
(lldb) log enable -F -T -p -f d:\lldbgdbremote.log gdb-remote all
# Example: Filter and record only breakpoint events.
(lldb) log enable -f /tmp/breakpoints.log lldb break
# View the current log configuration.
(lldb) log list
```

- Breakpoint management

```bash
# Set a function breakpoint (fuzzy match is supported).
(lldb) breakpoint -f main.cpp -l 266
# Set a conditional breakpoint, which is triggered when x is greater than or equal to 100.
(lldb) breakpoint set -f main.cpp -l 20 -c '(x > 100)'
# List all the breakpoints.
(lldb) breakpoint list
# Disable the breakpoint temporarily.
(lldb) breakpoint disable 1
```

- Watchpoint management

```bash
# Monitor variable changes.
(lldb) watchpoint set variable global_var
# Monitor memory address changes.
(lldb) watchpoint set expression -w write -- 0x7ffeefbff5d8
# View watchpoint list.
(lldb) watchpoint list
```

- Expression processing

```bash
# Create a variable.
(lldb)print int $value1 = 7
(lldb)expression int $value2 = 7
# Print a variable value.
(lldb) print $value1
(lldb) expression $value2
# Calculate a variable.
(lldb) expression $value1 * 3
# Format the output in hexadecimal.
(lldb) p/x 12345
```

- Viewing variables

```bash
# View initialized local variables of the current frame.
(lldb) frame variable
# View global and static variables.
(lldb) frame variable -g
# View registers.
(lldb) register read
```

- Process/Thread management

```bash
# Display thread backtraces (of all threads).
(lldb) thread backtrace all
# Step over.
(lldb) thread step-over (or next)
# Step out of the current frame.
(lldb) thread step-out (or finish)
```

- Assembly processing

```bash
# View registers.
(lldb) register read
# Change the PC register.
(lldb) register write pc `$pc+8`
# View the assembly instructions of the current stack frame.
(lldb) disassemble --frame (or dis -f)
# View the assembly instructions of the main function.
(lldb) disassemble -name main
# Single-step through assembly instructions and step over function calls.
(lldb) nexti
# Single-step through assembly instructions and step in function calls.
(lldb) stepi
```

- Obtaining source code information

```bash
(lldb) source list
```

- Signal processing

```bash
# Print backtraces when signals are captured.
(lldb) process handle SIGSEGV -s true
# View the current signal processing configuration.
(lldb) process handle
```

- Attaching to a process

```bash
# Attach to a PID, which requires the debugging permission.
(lldb) process attach -p 1234
```

## Environment setup

- Local debugging

   - You can debug your application on the device without using DevEco Studio.

    - Select the static LLDB path and use hdc to transfer it to the device.

    ```bash
    hdc file send \ohos-sdk\[system]\native\llvm\lib\clang\[version]\bin\aarch64-linux-ohos\lldb /data/local/tmp/debugserver
    ```

   -  Select the LLDB server path (select the path based on the device CPU architecture) and use hdc to transfer it to the device.

    ```bash
    hdc file send \ohos-sdk\[system]\native\llvm\lib\clang\[version]\bin\aarch64-linux-ohos\lldb-server /data/local/tmp/debugserver
    ```

- Remote debugging (main debugging mode)

   - One-click debugging:

      - Download HUAWEI DevEco Studio and perform one-click debugging on it.

        - Connect a Windows or macOS computer to an OpenHarmony device and debug native C++ applications.

        - Use the **Debug** functionality of DevEco Studio. You do not need to manually push lldb or lldb-server.

    - Manual debugging:

       - To manually perform remote debugging (not through DevEco Studio), for example, debugging binary files, ensure that the lldb-server exists on the device and the lldb exists on the PC.

       - Set up lldb-server. You are advised to push it using DevEco Studio. To manually push the lldb-server, select the lldb-server path and use hdc to transfer it to the device.

        ```bash
        hdc file send \ohos-sdk\[system]\native\llvm\lib\clang\[version]\bin\aarch64-linux-ohos\lldb-server /data/local/tmp/debugserver
        ```

        - Set up lldb on the PC. For Windows, use lldb.exe, and connect the lldb to the lldb-server on the OpenHarmony device for debugging.

## Local Debugging

### Using LLDB to Start and Debug an Application

   The following walks you through on how to debug an executable file named **a.out** in the Linux x86_64 environment. The file contains debugging information and is generated by the Clang compiler, which is of the same version as LLDB.

   Source file: **hello.cpp**

```cpp
#include <iostream>
using namespace std;
int main() {
    cout << "hello world!" << endl;
    return 0;
}
```

Compilation:

```cpp
<clang distribution>/bin/clang++ --target=aarch64-linux-ohos --sysroot=<sysroot distribution> -g hello.cpp -o a.out
```

   1. Obtain the executable file **a.out**.

   2. Run the **hdc shell** command to enter the interactive command environment of the mobile phone and go to the lldb path.

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

**Using LLDB to Debug a Started Application**

The following walks you through on how to debug an executable file named **a.out** in the mobile phone environment. The file contains debugging information and is generated by the Clang compiler, which is of the same version as LLDB.

Source file: **hello.cpp**

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

Compilation:

```cpp
<clang distribution>/bin/clang++ --target=aarch64-linux-ohos --sysroot=<sysroot distribution> -g hello.cpp -o a.out
```

1. Run the **hdc shell** command to enter the interactive command environment and go to the lldb path.

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
> You can attach to the application and set breakpoints in whichever order you like.

## Remote Debugging

> **NOTE**
> - Remote debugging refers to cross-device debugging using LLDB. The following describes how to debug applications on OpenHarmony devices across platforms.
> - During remote debugging, **lldb-server** and **lldb** must be used together.
> - The remote debugging procedures for Windows, Linux x86_64, and macOS are the same.
>

### Remote Debugging

The following takes remote debugging on the Windows platform by connecting to an OpenHarmony device with ARM architecture (such as the RK3568 development board) as an example.

> **NOTE**
>
> In the command below, **/data/local/tmp** indicates the specified directory on the device.
>
> **8080** is the listening port, which can be customized.
>
> You must have the execute permission on the **lldb-server** and **a.out** files of the device.
>
Source file: **hello.cpp**

```cpp
#include <iostream>
using namespace std;
int main() {
    cout << "hello world!" << endl;
    return 0;
}
```

Compilation:

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

- When the **run** command is executed in the LLDB debugging environment, the console returns **error: 'A' packet returned an error: 8** or a similar error code. What should I do?<br> This usually indicates that the debugger cannot create a debugging process because it has no permission. In this case, you are advised to perform the following steps:

   (1) Check whether **Developer options** is enabled on the target device.

   If not, enable it and try again.

   (2) Check whether the current user has the permission to debug the target process.

   **user** can debug only applications, not executable files.

- What should I do if the error message "Permission denied" is displayed when I run lldb-server?<br>This is typically caused by the lack of executable permissions on the lldb-server binary. Granting execute permissions will resolve the issue.