# Seccomp Policy Development

## Overview

### Introduction

Secure computing mode (Seccomp) is a security mechanism provided by the Linux kernel. In the Linux system, a large number of system calls can be opened to user-mode programs without any restrictions. However, not all of these system calls are necessarily needed for user-mode programs. In this case, abuse of system calls can lead to system threats. For example, if a process has a security vulnerability, an attacker can run a shellcode segment to trigger system calls that are not triggered during normal execution, resulting in privilege escalation or private information leakage. To prevent such security risks, Seccomp limits the scope of system calls that can be used by programs, so as to reduce system exposure and improve security.

### Operating Mechanism

1. Basic mechanism

    Seccomp policies exist in the form of policy files. During compilation and building, a policy file is parsed to generate a source file that contains the BPF instruction policies, and then the source file is compiled into a dynamic policy library. During startup of a user-mode process, Seccomp system calls are invoked to load the BPF instruction policies into the kernel through the dynamic policy library.

2. Basic features
    - A child process inherits the Seccomp policies of its parent process.
    - After a Seccomp policy is loaded to the kernel during process running, the policy exists in the memory as a singly linked list and cannot be modified.
    - Seccomp policies can be set for a process for multiple times. When a process executes a system call, the kernel traverses the policies specified for the nodes in the singly linked list, and then compares the policies to obtain the policy with the highest priority.


### Constraints

- System restrictions<br>The system used must be a standard system, and the options listed below must be enabled in the kernel. You can find the kernel option configuration file of the product in **//kernel/linux/config/{linux_version}/arch/{target_cpu}/configs/**.
    ```shell
    CONFIG_HAVE_ARCH_SECCOMP=y
    CONFIG_HAVE_ARCH_SECCOMP_FILTER=y
    CONFIG_SECCOMP=y
    CONFIG_SECCOMP_FILTER=y
    ```

- Feature restrictions
    - The Seccomp policy for non-privileged processes complies with the baseline blocklist mechanism.
    - If a process needs to use system calls in the baseline blocklist, the system calls must be declared in the privileged process policy file.
    - The same Seccomp policy is enabled for all application processes.
    - The same Seccomp policy is enabled for most of system service processes.
    - Personalized Seccomp policies can be enabled for the native service processes incubated by the init process.

## Enabling Seccomp

### When to Use

To meet product security requirements, you can enable Seccomp to limit the scope of system calls that can be invoked by processes. The development procedure below describes how to enable the basic functions and policies of Seccomp. Note that the basic functions must meet the feature restrictions described in [Constraints](#constraints). For details about the basic policy file, see [Policy File Overview](#policy-file-overview).

### How to Develop

1. Add the following field to **vendor/Product vendor/Product name/config.json**:
    ```c
    "build_seccomp": true
    ```
    The following is an example of adding the **build_seccomp** field to the product configuration file:
    ```c
    {
        "product_name": "MyProduct",
        "version": "3.0",
        "type": "standard",
        "target_cpu": "arm",
        "ohos_version": "OpenHarmony 1.0",
        "device_company": "MyProductVendor",
        "board": "MySOC",
        "enable_ramdisk": true,
        "build_seccomp": true
        "subsystems": [
        {
            "subsystem": "ace",
            "components": [
            { "component": "ace_engine_lite","features":[""] }
            ]
        },
        ...
        ]
    }
    ```
2. Perform a full build on the product code to generate an image.
    ```
    ./build.sh --product-name *product name* --ccache --build-target make_all --target-cpu *specified CPU*
    ```
3. Burn the image into the device.

### Debugging and Verification

Check whether Seccomp is enabled for application processes and system service processes.
1. Run the shell command to obtain the process ID (that is, **target pid**) of the target process.
    ```
    ps -ef | grep xxx
    ```
    Information similar to the following is displayed, in which **target pid** is **1686**:
    ```
    media         1686     1 0 08:16:12 ?     00:00:00 xxx
    root          1869  1678 4 10:32:29 pts/0 00:00:00 grep xxx
    ```

2. Check the process status to determine whether Seccomp is enabled.
    ```shell
    cat /proc/[target pid]/status | grep Seccomp
    ```
    Information similar to the following is displayed:
    ```
    Seccomp:        2
    Seccomp_filters:        1
    ```
    **Table 1** Description of the Seccomp status
    |  Parameter |  Description |
    |  ---  |  ---  |
    |  Seccomp  |  - **0**: disabled.<br>- **1**: enabled with the strict mode. Only the read, write, exit, and sigreturn system calls are allowed.<br>- **2**: enabled with the filter mode. The customized policies can be enabled by loading BPF instruction sets. |
    |  Seccomp_filters  |  Number of Seccomp policies set for a process. |

## Customizing Seccomp Policies for a Process

### When to Use

If the basic Seccomp policy has been enabled for a product, you can customize Seccomp policies for native service processes incubated by the init process to adapt to diversified security requirements. In this case, the Seccomp policies of other native service processes remain unchanged.

### How to Develop

1. Collect statistics on the system calls required by the 32-bit and 64-bit systems by using the static analysis and Strace statistics methods described in [System Call Statistic Methods](#system-call-statistic-methods). In this way, you will obtain the initial Seccomp policy.
2. Write a policy file. For details, see [How to Write a Common Policy File](#how-to-write-a-common-policy-file).
3. Write and build the **BUILD.gn** file.

    1.  Store the policy file in the code repository of the service subsystem and create a **BUILD.gn** file. For example, create the **seccomp_policy** folder in the service code repository, and create the policy file and **BUILD.gn** file in the folder.
            
        ```shell
        //path/to/code/seccomp_policy
        ├── BUILD.gn
        └── example.seccomp.policy
        ```
    2. To parse the policy file and build the policy dynamic library, use the **ohos_prebuilt_seccomp** template to declare the Seccomp policy file path of the process in the **BUILD.gn** file. The **ohos_prebuilt_seccomp** template is defined in the **//base/startup/init/services/modules/seccomp/scripts/seccomp_policy_fixer.gni** file. The following table describes the parameters in the template.
    
        **Table 2** Parameters in the ohos_prebuilt_seccomp template
        |  Parameter |  Description |
        |  ---  |  ---  |
        |  sources  |  Path of the policy configuration file, mandatory.|
        |  filtername  |  Filter name, mandatory. The value must be the same as the value of **Services name** in the [boot configuration file](subsys-boot-init-cfg.md) of the process. Otherwise, the attempt to enable Seccomp will fail. This parameter determines the name of the dynamic policy library generated after the build. For example, if **filtername** is set to **xxx**, the name of the dynamic policy library is **libxxx_filter.z.so**. |
        |  process_type  |  Process type, mandatory. If the process is one incubated by the init process, set this parameter to **system**; if the process is an application process, set this parameter to **app**.|
        |  part_name  |  Part name, mandatory. |
        |  subsystem_name  |  Subsystem name, mandatory. |
        |  install_enable  |  Option specifying whether to install the policy file to the image, mandatory. Set the value to **true**. |
        |  install_images  |  Installation location in the image, mandatory. |
    
        Example
        ```python
        #Import the template file.
        import("//base/startup/init/services/modules/seccomp/scripts/seccomp_policy_fixer.gni")

        #Use the ohos_prebuilt_seccomp template.
        ohos_prebuilt_seccomp("xxxx_seccomp_filter") {
            sources = [ "xxxx.seccomp.policy" ]
            
            filtername = "xxx"

            process_type = "system"

            part_name = "xx_part_name"
            subsystem_name = "x_subsystem_name"

            install_enable = true
            install_images = [ "xxxxx" ]
        }
        ```
    3. Add the build target of **xxxx_seccomp_filter** to other **BUILD.gn** files.
        ```python
        if (build_seccomp) {
            deps += [ "path:xxxx_seccomp_filter" ]
        }
        ```
4. Build the dynamic policy library **libxxx_filter.z.so**.
    ```shell
    ./build.sh --product-name *product name* --ccache --build-target xxxx_seccomp_filter --target-cpu *specified CPU*
    ```
    If an error message that contains the following information is reported, the process needs to use the system calls in the baseline blocklist. In such a case, you need to declare the corresponding system call in **privileged_process.seccomp.policy**. For details, see [How to Write a Privileged Process Policy File](#how-to-write-a-privileged-process-policy-file). After the declaration is done, try again until the build is successful.
    ```shell
    xx of allow list is in block list
    ```
5. Use the hdc tool to push the dynamic policy library to the device and restart the device.
    ```shell
    # Push an appropriate library path based on the installation location in the image. For example, if the image is **system** and the system architecture is 32-bit, the path of the dynamic policy library is **/system/lib/seccomp/**.
    hdc shell mount -rw -o remount /
    hdc file send /path/to/libxxx_filter.z.so /path/to/lib(or lib64)/seccomp/
    hdc shell reboot
    ```
6. Use the [audit statistics](#audit-statistics) method to check and supplement the Seccomp policies. Repeat steps 4 to 6 until the process can run properly.

### Debugging and Verification

1. If Seccomp is not enabled for the target process, [check the Seccomp status](#debugging-and-verification) of the target process.
2. If the process is terminated and audit log information is present in the kernel logs, the Seccomp policy is enabled but the policy list is incomplete. You can find an example audit log in [Audit Statistics](#audit-statistics).
3. If the process is not terminated, comment out the system calls (for example, **setuid**) related to the specified uid in the Seccomp policy file. Rebuild the dynamic policy library, push the library to the image, and restart the process. Then, check whether the process is terminated by Seccomp. If the process is terminated, Seccomp has been enabled.

## FAQs

### How do I determine whether a process termination is caused by Seccomp?

**Symptom**

If a process is terminated under certain conditions, how do I determine whether the issue is caused by Seccomp?

**Solution**

Use either of the following methods:

- Check the crash stack backtrace log of the process. If the signal in the log is **SIGSYS**, the process termination is caused by the Seccomp mechanism. To view the crash stack backtrace content, run the following shell command:
    ```shell
    cat /data/log/faultlog/faultlogger/crash stack backtrace log
    ```
    Example output:
    ```shell
    Generated by HiviewDFX@OpenHarmony
    ================================================================
    Device info:xxx
    Build info:xxx
    Module name:xxx
    Pid:xxxx
    Uid:xxxxx
    Reason:Signal:SIGSYS(UNKNOWN)
    ...
    ```
- Check whether the process is still terminated after Seccomp is disabled. If the process runs properly after Seccomp is disabled, the process termination is caused by Seccomp.

    Seccomp is enabled by default. When the device operation mode is set to **root**, you can run the shell command to set the corresponding system parameter to disable Seccomp of the entire system.
    ```shell
    # Set the system parameter to disable Seccomp and restart the process.
    param set persist.init.debug.seccomp.enable 0; reboot
    # Set the system parameter to enable Seccomp and restart the process.
    param set persist.init.debug.seccomp.enable 1; reboot
    ```

## Reference

### Seccomp source code directory
```
base/startup/init/services/modules/seccomp
├── BUILD.gn
├── gen_syscall_name_nrs.c
├── scripts
│   ├── generate_code_from_policy.py        # Policy file parsing script
│   ├── seccomp_policy_fixer.gni            # Template definition in the BUILD.gn file for generating the dynamic policy library
│   └── tools                               # Scripts for collecting system call statistics
├── seccomp_policy                          # Basic policy files
│   ├── app.blocklist.seccomp.policy
│   ├── app.seccomp.policy
│   ├── privileged_process.seccomp.policy
│   ├── renderer.seccomp.policy
│   ├── spawn.seccomp.policy
│   ├── system.blocklist.seccomp.policy
│   └── system.seccomp.policy
├── seccomp_policy.c                        # Core Seccomp implementation code
└── seccomp_policy_static.c                 # Seccomp plug-in code
```

### Policy File Overview

- Location<br>Basic policy files are stored in **//base/startup/init/services/modules/seccomp/seccomp_policy**.
- Basic policy files

    **Table 3** Description of policy files
    |  Policy File |  Description |
    |  ---  |  ---  |
    |  system.seccomp.policy  | Seccomp policy enabled for most of system service processes.|
    |  system.blocklist.seccomp.policy  | System call baseline blocklist for system processes, that is, the list of system calls that cannot be invoked by non-privileged processes.|
    |  app.seccomp.policy  | Seccomp policy enabled for all application processes.|
    |  app.blocklist.seccomp.policy  | System call baseline blocklist for application processes, that is, the list of system calls that cannot be invoked by application processes.|
    |  spawn.seccomp.policy  | Seccomp policy enabled for the appspawn and nwebspawn processes.|
    |  renderer.seccomp.policy  | Seccomp policy enabled for the rendering processes incubated by the nwebspawn process.|
    |  privileged_process.seccomp.policy  | Privileged process policy file. If certain processes need to use the system calls on the baseline blocklist, you need to declare the corresponding process identifiers and baseline blocklists in this file.|

### How to Write a Common Policy File

- To declare a configuration item, write **@** followed by the configuration item, for example, **@returnValue**.
- Add the content of a configuration item from the next line of this configuration item to the beginning of the next configuration item.
- To comment out a line, add a pound sign (#) at the beginning of this line.
- Set the system architecture to **arm** or **arm64**. Only these two system architectures are supported currently.
- Separate system calls from the system architecture by a semicolon (;). The value **all** indicates that the system calls will be used by all supported system architectures.
- Set other parameters as needed. Except **returnValue**, all the other parameters are optional.

**Table 4** Configuration items in the policy file

|  Item |  Description | Configuration Rule |
|  ---  |  ---  |  --  |
|  returnValue  |  Return value. |  This parameter is mandatory. Value range:<br>- **LOG**: tolerant mode, in which only audit logs are recorded and the process is not terminated.<br>- **TRAP**: a mode in which the process is terminated and can be passed on to the faultloggerd process.<br>- **KILL_PROCESS**: a mode in which the process is terminated.<br>- **KILL_THREAD**: a mode in which the thread is terminated. |
|  headFiles  |  Header file, which is used to declare the macros in the **allowListWithArgs** and **priorityWithArgs** parameters.|  Use **""** and **<>** to include the file name, for example, **<abc.h>** and **"cde.h"**. The default header files are **<linux/filter.h>**, **<stddef.h>**, **<linux/seccomp.h>**, and **<audit.h>**. |
|  priority  |  Allowlist of frequently used system calls. |  System calls on the list are treated with a higher priority to improve the performance. |
|  priorityWithArgs  |  Allowlist of frequently used system calls with arguments. |  System calls on the list are treated with a higher priority to improve the performance. |
|  allowList  |  Allowlist |  List of system calls that can be invoked by a process. |
|  allowListWithArgs  |  List of system calls with arguments that can be invoked by a process. |  Separate the system call name and argument by a colon (:). Supported relational operators include **<**, **<=**, **>**, **>=**, **==**, **!=**, and **&**, and supported logical operators include **&&** and \.|\|.<br>Use **arg***n* to specify the SN of the argument in the system. The value of **n** ranges from **0** to **5**. A judgment statement starts with **if** and ends with **else**. Declare the return value after the statement ends, and use a semicolon (;) to separate the judgment statement from the return value.<br>The return value must be in the format of **return xxx**, where the value range of **xxx** is the same as that of **returnValue**. If there are multiple conditions in the judgment statement, separate them with **elif**.|
|  blockList  |  Blocklist of system calls. |  Before generating BPF instructions during policy file parsing, the system checks whether the system calls on the allowlist exist in the blocklist. If yes, a parsing error occurs.|
|  selfDefineSyscall  |  Customized system call. |  Set the value of this parameter to a number. |

Example: example.seccomp.policy

```
@returnValue
TRAP

@headFiles
"time.h"

@priority
ioctl;all

@allowList
openat;all
close;all
lseek;all
read;all
write;all
setresuid;arm64
setresgid;arm64
setresuid32;arm
setresgid32;arm

@allowListWithArgs
clock_getres:if arg0 >= CLOCK_REALTIME && arg0 <= CLOCK_BOOTTIME; return ALLOW; else return TRAP;all

@blockList
swapon;all

@selfDefineSyscall
787
```

### How to Write a Privileged Process Policy File

- To declare a configuration item, write **@** followed by the configuration item, for example, **@allowBlockList**.
- Add the content of a configuration item from the next line of this configuration item to the beginning of the next configuration item.
- To comment out a line, add a pound sign (#) at the beginning of this line.
- Set the system architecture to **arm** or **arm64**. Only these two system architectures are supported currently.
- Separate system calls from the system architecture by a semicolon (;). The value **all** indicates that the system calls will be used by all supported system architectures.

**Table 5** Configuration items in the privileged process policy file
|  Item |  Description | Configuration Rule |
|  ---  |  ---  |  --  |
|  privilegedProcessName  |  Process name identifier. |  Character string corresponding to **name** in the **services** parameter in the boot file of the native service process.|
|  allowBlockList  |  Available baseline blocklist. |  Fill in the system call and the system architecture.|

The following example shows how to enable process1 and process2 to use the swapon system call in the baseline blocklist.
```
@privilegedProcessName
process1

@allowBlockList
swapon;all

@privilegedProcessName
process2

@allowBlockList
swapon;all
```

### System Call Statistic Methods

**Table 6** Comparison of statistic methods
|  Statistic Method |  Description |  Advantage |  Disadvantage |
|  ---  |  ---  |  ---  |  ---  |
|  <div style="width: 50pt">Static analysis | <div style="width: 300pt">Analyze the ELF disassembly code to obtain the call relationship, collect statistics on the APIs that call the libc library, and then parse the LibC library to obtain the call relationship between the LibC APIs and the system call numbers. In this way, you will obtain the system call numbers used by the ELF file.|  <div style="width: 100pt">Statistics collection is supported for system calls in abnormal branches. |  <div style="width: 100pt">Parsing of call relationship is not supported for pointer functions. |
|  Strace statistics | Use Strace to trace service processes when the device is running. During the trace, the invoked system calls are recorded into logs. Collect the logs after the trace is complete, and use a script to parse the logs and generate a Seccomp policy file.|  Easy to use. |  System calls can be completely collected only when all code branches are traversed. |
|  Audit statistics | After the Seccomp policy is enabled for a process, Seccomp intercepts invalid system calls and records audit log information containing the system call numbers into kernel logs. Collect the logs after the trace is complete, and use a script to parse the logs and generate a Seccomp policy file.|  This method can be used as a supplement to the preceding methods. |  Logs may be lost.<br>System calls can be completely collected only when all code branches are traversed. |

#### Static Analysis

1. Prepare the environment.
    1. Prepare a Linux environment.
    2. Download the cross compilers arm-linux-musleabi and aarch64-linux-musl.
        ```shell
        wget https://musl.cc/arm-linux-musleabi-cross.tgz
        wget https://musl.cc/aarch64-linux-musl-cross.tgz

        tar -zxvf arm-linux-musleabi-cross.tgz
        tar -zxvf aarch64-linux-musl-cross.tgz

        # Add the tool execution path to the environment variable.
        export PATH=$PATH:/path/to/arm-linux-musleabi-cross/bin
        export PATH=$PATH:/path/to/aarch64-linux-musl-cross/bin
        ```

    3. Download the OpenHarmony source code. For details, see [Obtaining Source Code](../get-code/sourcecode-acquire.md).

2. Compile **seccomp_filter** to obtain the dependency files **libsyscall_to_nr_arm** and **libsyscall_to_nr_arm64**.

    **seccomp_filter** is declared in **base/startup/init/services/modules/seccomp/BUILD.gn** and is used to build the basic dynamic policy library of Seccomp. After the compilation is complete, dependency files are generated in **//out/Product name /gen/base/startup/init/services/modules/seccomp/gen_system_filter/**.
    ```shell
    ./build.sh --product-name *product name* --ccache --build-target seccomp_filter --target-cpu *specified CPU*

    # Copy the dependency files to the tool folder for later use.
    cp out/*product name* /gen/base/startup/init/services/modules/seccomp/gen_system_filter/libsyscall_to_nr_arm* base/startup/init/services/modules/seccomp/scripts/tools/
    ```

3. Copy the **generate_code_from_policy.py** script file to the tool folder. This script file is available at **//base/startup/init/services/modules/seccomp/scripts/**.
    ```shell
    # Go to the root directory of the OpenHarmony source code.
    cd /root/to/OpenHarmonyCode;
    # Go to the directory where the **generate_code_from_policy.py** script file is located.
    cd base/startup/init/services/modules/seccomp/scripts/;
    # Copy the **generate_code_from_policy.py** script file.
    cp generate_code_from_policy.py tools/;
    ```

4. Compile ELF files related to the service code. In the 32-bit architecture, the implementation of disassembly code redirection for ELF files is complex. Therefore, ELF files are all compiled into 64-bit ELF files to parse the function call relationship.
    ```shell
    ./build.sh --product-name *product file* --ccache --target-cpu arm64 --build-target *target file*
    ```

5. If full build has not been performed before and the dependent dynamic libraries for step 4 are not in the **//out** directory, copy the related dynamic libraries to the **//out** directory. The following code is for reference only. If other dynamic libraries are involved, copy them in a similar way.
    ```shell
    # Go to the root directory of the source code.
    cd /root/to/OpenHarmonyCode
    # Create the **aarch64-linux-ohos** folder in **out/*product name*/lib.unstripped/** to store the dependent dynamic libraries.
    mkdir out/*product name*/lib.unstripped/aarch64-linux-ohos
    # Copy the related dynamic libraries to the //out directory.
    cp prebuilts/clang/ohos/${host_platform_dir}/llvm/lib/clang/${clang_version}/lib/aarch64-linux-ohos/*.so out/*product name*/lib.unstripped/aarch64-linux-ohos/
    cp prebuilts/clang/ohos/${host_platform_dir}/${clang_version}/llvm/lib/aarch64-linux-ohos/*.so out/*product name*/lib.unstripped/aarch64-linux-ohos/
    ```

6. Modify the **collect_elf_syscall.py** script file, and change the paths of the objdump and readelf tools to their absolute paths in the Linux environment. This script file is available at **base/startup/init/services/modules/seccomp/scripts/tools/**. The **objdump** and **readelf** tools available at **//prebuilts**.
    ```python
    #modified the path of objdump and readelf path
    def get_obj_dump_path():
        obj_dump_path = '/path/to/llvm-objdump'
        return obj_dump_path


    def get_read_elf_path():
        read_elf_path = '/path/to/llvm-readelf'
        return read_elf_path
    ```

7. Use the **collect_elf_syscall.py** script file to parse and generate the corresponding policy file **xxx.seccomp.policy**.

    **Table 7** Parameters in the collect_elf_syscall.py script file
    |  Parameter |  Description |
    |  ---  |  ---  |
    |  --src-elf-path  | Folder where the ELF file is located, for example, **~/ohcode/out/rk3568**. Do not end the value with a slash (/).|
    |  --elf-name| ELF file name, for example, **libmedia_service.z.so**.|
    |  --src-syscall-path  |  **libsyscall_to_nr_arm** or **libsyscall_to_nr_arm64**, which corresponds to the architecture specified by **--target-cpu**. |
    |  --target-cpu  |  CPU architecture, that is, the architecture for which system calls are collected. This parameter determines the architecture for libC file parsing. Its value can be **arm** or **arm64**. |
    |  --filter-name  | Name of the generated policy file. For example, if the input value is **test**, the generated file name is **test.seccomp.policy**. |
    
    Use **collect_elf_syscall.py** to parse ELF files.

        ```
        # The following example considers **rk3568** as the product and **libmedia_service.z.so** as the ELF file.
        python3 collect_elf_syscall.py --src-elf-path ~/ohcode/out/rk3568 --elf-name libmedia_service.z.so --src-syscall-path libsyscall_to_nr_arm64 --target-cpu arm64 --filter-name media_service
        ```

        Example result of xxx.seccomp.policy 
        ```
        @allowList
        getcwd;arm64
        eventfd2;arm64
        epoll_create1;arm64
        epoll_ctl;arm64
        dup;arm64
        dup3;arm64
        fcntl;arm64
        ioctl;arm64
        ...
        ```

#### Strace Statistics

1. Use the cross compilers arm-linux-musleabi and aarch64-linux-musl to build the Strace tool for the 32-bit and 64-bit architectures, respectively.
2. [Trace the service process](#tracing-the-service-process) to obtain the Strace logs.
3. [Parse Strace logs](#parsing-strace-logs) by using scripts to obtain the Seccomp policy file.

##### Tracing the Service Process

1. Modify the embedded code in the init repository. Specifically, add the following content to **//base/startup/init/services/init/init_common_service.c** before executing the **SetSystemseccompPolicy** function to set the Seccomp policy.  If the line starts with a plus sign (+), the line is added; if the line starts with a hyphen (-), the line is deleted. **xxxx** must be the same as the value of **Services name** in the [boot configuration file](subsys-boot-init-cfg.md) of the process.
    ```c
    --- a/services/init/init_common_service.c
    +++ b/services/init/init_common_service.c
    @@ -155,7 +155,19 @@ static int SetPerms(const Service *service)
        // set seccomp policy before setuid
        INIT_ERROR_CHECK(SetSystemseccompPolicy(service) == SERVICE_SUCCESS, return SERVICE_FAILURE,
            "set seccomp policy failed for service %s", service->name);
    -
    +    if (strncmp(service->name, "xxxx", strlen("xxxx")) == 0) {
    +        pid_t pid = getpid();
    +        pid_t pid_child = fork();
    +        if (pid_child == 0) {
    +            char pidStr[9] = {0};
    +            sprintf_s(pidStr, 6, "%d", pid);
    +            if (execl("/system/bin/strace", "/system/bin/strace", "-p", (const char *)pidStr, "-ff", "-o", "/data/strace/xxxx.strace.log", NULL) !=0 ) {
    +                INIT_LOGE("strace failed");
    +            }
    +        }
    +        sleep(5);
    +    }
        if (service->servPerm.uID != 0) {
            if (setuid(service->servPerm.uID) != 0) {
                INIT_LOGE("setuid of service: %s failed, uid = %d", service->name, service->servPerm.uID);
    ```
2. Perform a full build, and burn the image.
3. Disable SElinux, and push Strace to the device.
    ```shell
    hdc shell setenforce 0
    hdc shell mount -rw -o remount /
    hdc file send /path/to/strace /system/bin/
    hdc shell chmod a+x /system/bin/strace
    ```
4. Create a folder for storing Strace logs.
    ```shell
    hdc shell mkdir -p /data/strace
    ```
5. Terminate the service process, and restart it. In the following command, **xxx** indicates the service process name.
    ```shell
    kill -9 $(pidof xxx)
    ```
6. Perform service operations on the device. Make sure that all code is covered.
7. Obtain Strace logs from **/data/strace** on the device, and save them to the directory where the parsing script is located.
    ```shell
    hdc file recv /data/strace /path/to/base/startup/init/services/modules/seccomp/scripts/tools/
    ```

##### Parsing Strace Logs

1. Copy the dependency files to the Strace log folder for later use. The dependency files are those generated in step 2 in [Static Analysis](#static-analysis).
    ```shell
    cp out/*product name* /gen/base/startup/init/services/modules/seccomp/gen_system_filter/libsyscall_to_nr_arm* base/startup/init/services/modules/seccomp/scripts/tools/strace/
    ```
 
2. Use the **strace_log_analysis.py** script file to parse and generate the corresponding policy file **xxx.seccomp.policy**.

    The script file is available at **//base/startup/init/services/modules/seccomp/scripts/tools/**.
    
    **Table 8** Parameters in the strace_log_analysis.py script file
    |  Parameter |  Description |
    |  ---  |  ---  |
    |  --src-path  | Folder for storing log files. It must contain **libsyscall_to_nr_arm** and **libsyscall_to_nr_arm64**. The folder name must not end with a slash (/), for example, **./strace**.|
    |  --target-cpu  |  CPU architecture, which is the same as that of the traced process. Its value can be **arm** or **arm64**. |
    |  --filter-name  | Name of the generated policy file. For example, if the input value is **test**, the generated file name is **test.seccomp.policy**. |

    Use the **strace_log_analysis.py** script file to parse Strace logs.
    ```shell
    cd base/startup/init/services/modules/seccomp/scripts/tools;
    python3 strace_log_analysis.py --src-path strace --target-cpu *specified CPU* --filter-name xxx
    ```
    Example result of xxx.seccomp.policy 
    ```
    @allowList
    getcwd;arm64
    eventfd2;arm64
    epoll_create1;arm64
    epoll_ctl;arm64
    dup;arm64
    dup3;arm64
    fcntl;arm64
    ioctl;arm64
    ...
    ```

#### Audit Statistics

1. Enable the initial Seccomp policy. For details, see [Customizing Seccomp Policies for a Process](#customizing-seccomp-policies-for-a-process).
2. Obtain logs.
    1. Create a folder for storing logs.
        ```shell
        mkdir -p /data/audit
        ```
    2. Obtain Seccomp-related audit log information from kernel logs. The logs end with **.audit.log**.
        ```shell
        cat /proc/kmsg | grep type=1326 > /data/audit/media_service.audit.log
        ```
3. Perform service-related operations and segment fault triggering operations.
    1. To trigger a segment fault, add the following code to the service code to call **TriggerSegmentFault** at a certain point to rebuild and burn the image:
        ```c
        static void TriggerSegmentFault(void)
        {
            pid_t pid_child = fork();
            if (pid_child == 0) {
                char *test = (char *)0x1234;
                *test = 1;
            }
        }
        ```
    2. After the device is started, run the following shell command to temporarily shut down SELinux and terminate the service process. The process then automatically restarts.
        ```shell
        setenforce 0
        ```

4. Run the hdc command to obtain audit logs from the **/data/audit** on of the device, and save them to the directory where the parsing script is located.
    ```shell
    hdc file recv /data/audit /path/to/base/startup/init/services/modules/seccomp/scripts/tools/
    ```
5. Parse the audit logs.
    
    Example audit log:
    ```shell
    <5>[  198.963101] audit: type=1326 audit(1659528178.748:27): auid=4294967295 uid=0 gid=1000 ses=4294967295 subj=u:r:appspawn:s0 pid=2704 comm="config_dialog_s" exe="/system/bin/appspawn" sig=31 arch=40000028 syscall=208 compat=1 ip=0xf7b79400 code=0x80000000
    ```
    **Table 9** Key parameters in audit logs
    |  Parameter |  Description |
    |  ---  |  ---  |
    |  type  |  Type. The value **1326** indicates that the log is of the Seccomp type. |
    |  sig  |  Semaphore. The value **31** indicates **SIGSYS**, which is the signal sent to the process when Seccomp interception occurs. |
    |  arch  |  Architecture ID. The value **40000028** indicates **arm**, and the value **c00000b7** indicates **arm64**. |
    |  syscall  |  System call ID. |
    |  compat  |  The value **1** indicates the compatibility mode, that is, the arm64 kernel uses arm system calls.|


    1. Copy the dependency files to the log folder for later use. The dependency files are those generated in step 2 in [Static Analysis](#static-analysis).
        ```shell
        cp out/*product name* /gen/base/startup/init/services/modules/seccomp/gen_system_filter/libsyscall_to_nr_arm* base/startup/init/services/modules/seccomp/scripts/tools/audit/
        ```
    2. Run the **audit_log_analysis.py** script to parse logs and generate **xxx.seccomp.policy**. The tool is available at **//base/startup/init/services/modules/seccomp/scripts/tools/**.

        **Table 10** Parameters in the audit_log_analysis.py script file
        |  Parameter |  Description |
        |  ---  |  ---  |
        |  --src-path  | Folder for storing log files. It must contain **libsyscall_to_nr_arm** and **libsyscall_to_nr_arm64**. The folder name must not end with a slash (/), for example, **./audit**.|
        |  --filter-name  | Name of the generated policy file. For example, if the input value is **test**, the generated file name is **test.seccomp.policy**.|

        ```shell
        cd base/startup/init/services/modules/seccomp/scripts/tools
        python3 audit_log_analysis.py --src-path audit --filter-name xxx
        ```

### Combining Multiple Policy Files

During [colltatistics on system calls](#system-call-statistic-methods), multiple policy files may be generated. In these policy files, system calls may be repeated or disordered. To solve these problems, you can combine policy files to sort system calls by arm64/arm and by system call number in ascending order.

**Table 11** Parameters in the merge_policy.py script file
|  Parameter |  Description |
|  ---  |  ---  |
|  --src-files  | Files to be processed, including **libsyscall_to_nr_arm** and **libsyscall_to_nr_arm64**.|
|  --filter-name  | Name of the generated policy file. For example, if the input value is **test**, the generated file name is **test.seccomp.policy**. |
1. Copy the dependency files to the log folder for later use.
    ```shell
    cp out/*product name* /gen/base/startup/init/services/modules/seccomp/gen_system_filter/libsyscall_to_nr_arm* base/startup/init/services/modules/seccomp/scripts/tools/
    ```
2. Run the **merge_policy.py** script to merge **policy1.seccomp.policy** and **policy2.seccomp.policy** into **xxxx.seccomp.policy**.
    ```shell
    python3 merge_policy.py --src-files libsyscall_to_nr_arm --src-files libsyscall_to_nr_arm64 --src-files policy1.seccomp.policy --src-files policy2.seccomp.policy --filter-name xxxx
    ```
