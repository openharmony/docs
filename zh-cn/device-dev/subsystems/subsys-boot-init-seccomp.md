# Seccomp策略使能开发指导
## 概述
### 功能简介
Seccomp（Secure computing mode）是Linux kernel支持的一种安全机制。在Linux系统中，大量的系统调用可以不受限制地向用户态程序开放，但用户态程序并不需要所有的系统调用，此时不安全的代码如果滥用系统调用会对系统造成威胁。例如，一个进程中存在安全漏洞，攻击者可以运行一段Shellcode去触发正常执行中不会触发的系统调用，从而导致提权或者私密信息被窃取。针对这类安全隐患，Seccomp机制通过限制程序可使用的系统调用范围，来减少系统的暴露面，提高安全性。

### 运作机制
1. 基本机制

    Seccomp策略以策略文件的形式存在。在编译构建时，首先相关脚本解析策略文件来生成含BPF指令策略的源文件，然后编译成策略动态库。最后，用户态进程启动过程中，使用Seccomp系统调用将BPF指令策略加载到内核中。

2. 基本特点
    - 子进程继承父进程的Seccomp策略。
    - 在进程运行时Seccomp策略被加载到内核后，以单向链表的形式存在于内存中，且内容不能被修改。
    - 进程可多次设置Seccomp策略。进程在执行系统调用时，内核会遍历单向链表中每个节点的策略，比较每个节点策略的返回值，最后得到优先级最高的返回值。


### 约束与限制
- 支持标准系统，且标准系统的内核已开启下列选项。产品的内核选项配置文件路径为//kernel/linux/config/{linux_version}/arch/{target_cpu}/configs/。
    ```shell
    CONFIG_HAVE_ARCH_SECCOMP=y
    CONFIG_HAVE_ARCH_SECCOMP_FILTER=y
    CONFIG_SECCOMP=y
    CONFIG_SECCOMP_FILTER=y
    ```

- 特性限制：
    - 非特权进程Seccomp策略遵循基线黑名单机制。
    - 若进程需使用基线黑名单系统调用，则要在特权进程策略文件中声明。
    - 所有应用进程使能同一个Seccomp策略。
    - 大部分系统服务进程使能同一个Seccomp策略。
    - 支持init进程孵化的Native service进程使能个性化Seccomp策略。

## 产品使能Seccomp机制
### 场景介绍
产品可根据自身对安全性的要求，需要使能Seccomp机制来限制进程可使用的系统调用范围。按照下面的开发步骤，系统可使能Seccomp的基本功能与基本策略。其基本功能满足[约束与限制](#约束与限制)中的特性限制，基本策略文件说明见[策略文件说明](#策略文件说明)。
### 开发步骤
1. 在vendor/产品厂商/产品名/config.json添加以下字段。
    ```c
    "build_seccomp": true
    ```
    产品配置文件添加build_seccomp字段的示例如下：
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
2. 产品代码进行全量编译，生成镜像。
    ```
    ./build.sh --product-name 产品名称 --ccache --build-target make_all --target-cpu 指定CPU
    ```
3. 设备烧写镜像。

### 调测验证 
查看应用进程与系统服务进程是否使能Seccomp机制。
1. 使用Shell命令获取目标进程的进程号target pid。
    ```
    ps -ef | grep xxx
    ```
    显示信息示例如下，其中1686为target pid。
    ```
    media         1686     1 0 08:16:12 ?     00:00:00 xxx
    root          1869  1678 4 10:32:29 pts/0 00:00:00 grep xxx
    ```

2. 查看进程状态信息来判断Seccomp机制是否使能。
    ```shell
    cat /proc/[target pid]/status | grep Seccomp
    ```
    显示信息示例如下。
    ```
    Seccomp:        2
    Seccomp_filters:        1
    ```
    **表1**  Seccomp使能状态说明
    |  字段  |  说明  |
    |  ---  |  ---  |
    |  Seccomp  |  - 0：未使能；<br>- 1：使能，为严格模式，只允许使用read/write/exit/sigreturn四个系统调用；<br>- 2：使能，filter模式，可通过加载BPF指令集合来使能自定义策略。  |
    |  Seccomp_filters  |  进程设置Seccomp策略的个数。 |

## 进程使能个性化Seccomp策略
### 场景介绍
产品已使能Seccomp基本策略的情况下，某个init孵化的Native service进程可以根据实际需要使能自定义的个性化Seccomp策略，以适配进程自身所需的安全要求，此时其它Native service进程的Seccomop策略不变。
### 开发步骤
1. 统计32位架构与64架构位需要使用的系统调用，先使用[统计系统调用方法](#统计系统调用方法)的静态分析方法与Strace统计方法，得到Seccomp初始策略。
2. 编写策略文件，见[普通策略文件编写规则](#普通策略文件编写规则)。
3. 编写编译BUILD.gn。

    1.  在业务子系统代码仓内存放编写完成的策略文件，创建BUILD.gn。例如，在业务代码仓创建seccomp_policy文件夹，在该文件中创建策略文件与BUILD.gn。
            
        ```shell
        //path/to/code/seccomp_policy
        ├── BUILD.gn
        └── example.seccomp.policy
        ```
    2. 为了解析策略文件以及构建策略动态库，在BUILD.gn中需要使用ohos_prebuilt_seccomp模板声明进程的Seccomp策略文件路径等内容。ohos_prebuilt_seccomp模板在//base/startup/init/services/modules/seccomp/scripts/seccomp_policy_fixer.gni中定义，下表为该模板的字段说明。
    
        **表2**  ohos_prebuilt_seccomp模板字段说明
        |  字段  |  说明  |
        |  ---  |  ---  |
        |  sources  |  必填，策略配置文件的路径。 |
        |  filtername  |  必填，该内容与进程[引导启动配置文件](subsys-boot-init-cfg.md)中的services name保持一致，否则会使能失败。该字段决定了动态库的名称。例如，将filtername设置为xxx，则编译生成的策略动态库名称为libxxx_filter.z.so。  |
        |  process_type  |  必填，根据使能进程类型填写不同的字符串。若使能的进程为init孵化的进程，则该字段赋值"system"；若是应用进程，则该字段赋值"app"。 |
        |  part_name  |  必填，部件名。  |
        |  subsystem_name  |  必填，子系统名。  |
        |  install_enable  |  必填，是否安装到镜像，为true。  |
        |  install_images  |  必填，安装的镜像位置。  |
    
        示例
        ```python
        #引入模板文件
        import("//base/startup/init/services/modules/seccomp/scripts/seccomp_policy_fixer.gni")

        #使用gn模板
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
    3. 在其它BUILD.gn中添加上xxxx_seccomp_filter的编译目标。
        ```python
        if (build_seccomp) {
            deps += [ "path:xxxx_seccomp_filter" ]
        }
        ```
4. 构建策略动态库libxxx_filter.z.so。
    ```shell
    ./build.sh --product-name 产品名称 --ccache --build-target xxxx_seccomp_filter --target-cpu 指定CPU
    ```
    若构建报错，且报错提示信息含以下内容，则该进程需要使用基线黑名单里的系统调用。所以将xx系统调用声明在privileged_process.seccomp.policy中，规则见[特权进程声明名单编写规则](#特权进程声明名单编写规则)。添加声明后，重复此步动作直到编译成功。
    ```shell
    xx of allow list is in block list
    ```
5. 利用hdc工具将策略动态库推入设备中，并重启。
    ```shell
    # 根据安装的镜像位置，推入不同的库路径，例如，安装镜像为system，系统架构为32位，则策略动态库的路径为/system/lib/seccomp/
    hdc shell mount -rw -o remount /
    hdc file send /path/to/libxxx_filter.z.so /path/to/lib(or lib64)/seccomp/
    hdc shell reboot
    ```
6. 使用[Audit统计](#audit统计)对Seccomp策略进行查漏补缺，重复执行4-6步直到进程能正常运行。

### 调测验证
1. 若目标进程原先未使能Seccomp机制，则[查看目标进程的Seccomp状态](#调测验证)来判断其是否使能。
2. 若进程被终止，且内核日志里有相关Audit审计日志，则说明Seccomp策略已使能，但统计的策略名单不完整。Audit审计日志示例在[Audit统计](#audit统计)章节中。
3. 若进程未被终止，则进程注释Seccomp策略文件中uid设置相关的系统调用（例如，setuid）。重新进行编译策略动态库、推库以及重启进程，查看该进程是否会被Seccomp机制终止。若进程被终止，则说明Seccomp策略已使能。

## 常见问题
### 如何确定进程终止的是Seccomp机制引起的
**现象描述**

当发生一定条件时进程被终止，但不确定该情况是否是由Seccomp机制引起。

**解决方法**

以下为两种解决方法。

- 查看进程的崩溃栈回溯的内容，若内容中显示的原因信号为SIGSYS，则是Seccomp机制引起。利用Shell查看崩溃回溯的内容。
    ```shell
    cat /data/log/faultlog/faultlogger/进程的崩溃栈回溯日志
    ```
    示例信息
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
- 查看Seccomp机制关闭后进程是否依旧被终止。若Seccomp机制被关闭后进程能正常运行，则进程终止由Seccomp机制引起。

    Seccomp机制默认打开，当设备操作模式为root模式时，利用Shell命令行设置系统参数关闭整个系统的Seccomp机制。
    ```shell
    # 设置相关系统参数关闭Seccomp机制后重启
    param set persist.init.debug.seccomp.enable 0; reboot
    # 设置相关系统参数开启Seccomp机制后重启
    param set persist.init.debug.seccomp.enable 1; reboot
    ```

## 参考
### Seccomp代码目录结构
```
base/startup/init/services/modules/seccomp
├── BUILD.gn
├── gen_syscall_name_nrs.c
├── scripts
│   ├── generate_code_from_policy.py        # 策略文件的解析脚本
│   ├── seccomp_policy_fixer.gni            # 生成策略动态库的gn模板定义
│   └── tools                               # 存放辅助统计系统调用脚本
├── seccomp_policy                          # 存放基础策略文件的文件夹
│   ├── app.blocklist.seccomp.policy
│   ├── app.seccomp.policy
│   ├── privileged_process.seccomp.policy
│   ├── renderer.seccomp.policy
│   ├── spawn.seccomp.policy
│   ├── system.blocklist.seccomp.policy
│   └── system.seccomp.policy
├── seccomp_policy.c                        # Seccomp实现核心源码
└── seccomp_policy_static.c                 # Seccomp插件化源码
```

### 策略文件说明
- 存放位置在//base/startup/init/services/modules/seccomp/seccomp_policy中
- 策略基础文件

    **表3**  策略文件说明
    |  策略文件  |  说明  |
    |  ---  |  ---  |
    |  system.seccomp.policy  | 大部分系统服务进程使能的Seccomp策略。 |
    |  system.blocklist.seccomp.policy  | 系统进程的系统调用基线黑名单，即非特权进程禁止使用的系统调用名单。 |
    |  app.seccomp.policy  | 所有应用进程使能的Seccomp策略。 |
    |  app.blocklist.seccomp.policy  | 应用进程的系统调用基线黑名单，即应用进程禁止使用的系统调用名单。 |
    |  spawn.seccomp.policy  | appspawn进程与nwebspawn进程使能的Seccomp策略。 |
    |  renderer.seccomp.policy  | 由nwebspawn孵化的渲染进程使能的Seccomp策略。 |
    |  privileged_process.seccomp.policy  | 特权进程声明名单，即某些进程需使用基线黑名单系统调用时，可在此文件中声明进程标识符与需使用的基线黑名单。 |

### 普通策略文件编写规则
- 若要声明配置项，以“@”加配置项的形式书写，例如，@returnValue。
- 配置项的下一行开始到下一个配置项开始之前为配置项内容。
- 若要在文件中增加注释，在行首添加“#”。
- 目前支持的架构为arm/arm64。
- 系统调用与架构用“;”隔开，all表示支持的所有架构会使用该系统调用。
- 除了returnValue字段，其它都是选填项。

**表4**  策略文件配置项说明

|  配置项  |  说明  | 规则  |
|  ---  |  ---  |  --  |
|  returnValue  |  返回值  |  必填，范围为：<br>- LOG：宽容模式，只记录Audit日志，不会终止进程；<br>- TRAP：终止进程，且可交给faultloggerd处理；<br>- KILL_PROCESS：终止进程。 <br>- KILL_THREAD：终止线程。  |
|  headFiles  |  头文件，用于声明allowListWithArgs与priorityWithArgs字段中出现的宏。 |  格式上：用""、<>来包含头文件名称，例如 <abc.h>、"cde.h" 默认有的头文件：<linux/filter.h>、<stddef.h>、<linux/seccomp.h>、<audit.h>。  |
|  priority  |  频繁使用的系统调用白名单  |  在策略中优先判断，用于提高性能。  |
|  priorityWithArgs  |  频繁使用的带参数限制的系统调用白名单  |  在策略中优先判断，用于提高性能。  |
|  allowList  |  白名单  |  进程允许的系统调用。  |
|  allowListWithArgs  |  带参数限制白名单  |  其中系统调用名称与参数限制说明用“:”隔开，判断符号可用<、<=、>、>=、==、!=、&，逻辑符号可用&&、\|\|。<br>系统调用的第几个参数，使用argn表示，n的范围为0~5。判断语句用“if”开头，else语句结尾。语句结束后需声明返回值，判断语句与返回值使用“;”隔开。<br>声明返回值的样式为“return xxx”，xxx的范围与returnValue一致。若有多重判断条件，判断条件之间可使用elif隔开。 |
|  blockList  |  黑名单  |  在解析策略过程中，生成BPF指令前会检查白名单中的系统调用会不会存在于黑名单中。若存在，则会出现解析错误的信息。 |
|  selfDefineSyscall  |  自定义系统调用  |  填写的内容为数字。  |

举例说明example.seccomp.policy。

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

### 特权进程声明名单编写规则
- 若要声明配置项，以“@”+配置项的形式书写，例如，@allowBlockList。
- 配置项的下一行开始到下一个配置项开始之前为配置项内容。
- 若要在文件中增加注释，在行首添加“#”。
- 目前支持的架构为arm/arm64。
- 系统调用与架构用“;”隔开，all表示支持的所有架构会使用该系统调用。

**表5**  特权进程策略文件配置项说明
|  配置项  |  说明  | 规则  |
|  ---  |  ---  |  --  |
|  privilegedProcessName  |  进程名标识符  |  native service进程的启动引导文件中services内容中name对应的字符串 |
|  allowBlockList  |  可使用的基线黑名单  |  填写系统调用与架构 |

举例，以下表示process1和process2进程需要使用基线黑名单中的swapon系统调用。
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

### 统计系统调用方法
**表6**  统计方法对比说明
|  统计方法  |  基本方法  |  优点  |  缺点  |
|  ---  |  ---  |  ---  |  ---  |
|  <div style="width: 50pt">静态分析  | <div style="width: 300pt">分析ELF反汇编代码得到调用关系，统计调用libc库的接口集合，解析libc库得到libc接口与系统调用号的调用关系，从而得到ELF文件使用的系统调用号。 |  <div style="width: 100pt">可以统计到异常分支的系统调用。  |  <div style="width: 100pt">不支持解析指针函数的调用关系。  |
|  Strace工具统计  | 设备运行时，使用Strace跟踪业务进程。跟踪过程中会将系统调用的执行记录下来。收集日志后使用脚本解析日志生成Seccomp策略文件。 |  操作简单。  |  代码分支全部覆盖才能完整统计使用的系统调用。  |
|  Audit统计  | 进程使能Seccomp策略后，Seccomp机制会拦截非法系统调用，在内核日志生成含系统调用号信息的Audit日志。收集日志后使用脚本解析日志生成Seccomp策略文件。 |  可对上面两个方法进行查漏补缺。  |  日志有丢失的风险。<br>代码分支全部覆盖才能完整统计使用的系统调用。  |

#### 静态分析
1. 环境准备。
    1. 准备linux环境。
    2. 下载交叉编译器arm-linux-musleabi与aarch64-linux-musl。
        ```shell
        wget https://musl.cc/arm-linux-musleabi-cross.tgz
        wget https://musl.cc/aarch64-linux-musl-cross.tgz

        tar -zxvf arm-linux-musleabi-cross.tgz
        tar -zxvf aarch64-linux-musl-cross.tgz

        # 将执行工具路径加入环境变量。
        export PATH=$PATH:/path/to/arm-linux-musleabi-cross/bin
        export PATH=$PATH:/path/to/aarch64-linux-musl-cross/bin
        ```

    3. 下载OpenHarmony源代码，见[下载说明](../get-code/sourcecode-acquire.md)。

2. 通过编译seccomp_filter得到静态分析的依赖文件libsyscall_to_nr_arm与libsyscall_to_nr_arm64。

    seccomp_filter在base/startup/init/services/modules/seccomp/BUILD.gn中声明，用于构建Seccomp的基础策略动态库。依赖文件最终会生成在//out/产品名称/gen/base/startup/init/services/modules/seccomp/gen_system_filter/路径中。
    ```shell
    ./build.sh --product-name 产品名称 --ccache --build-target seccomp_filter --target-cpu 指定CPU

    # 将统计所依赖的文件复制到工具文件夹以备使用
    cp out/产品名称/gen/base/startup/init/services/modules/seccomp/gen_system_filter/libsyscall_to_nr_arm* base/startup/init/services/modules/seccomp/scripts/tools/
    ```

3. 复制generate_code_from_policy.py到统计系统调用工具的文件夹内。该脚本存在于//base/startup/init/services/modules/seccomp/scripts/路径下。
    ```shell
    # 进入OpenHarmony代码根目录
    cd /root/to/OpenHarmonyCode;
    # 进入generate_code_from_policy.py所在目录
    cd base/startup/init/services/modules/seccomp/scripts/;
    # 复制generate_code_from_policy.py
    cp generate_code_from_policy.py tools/;
    ```

4. 编译业务代码相关的ELF文件，由于32位架构的ELF文件反汇编代码跳转机制较复杂，故统一编译成64位ELF文件用来解析函数调用关系。
    ```shell
    ./build.sh --product-name 产品文件 --ccache --target-cpu arm64 --build-target 目标文件
    ```

5. 若此前未进行全量编译，且第4步依赖的动态库未在//out文件夹下，则通过执行以下命令将业务依赖的相关动态库复制到//out目录下。以下为参考操作，若还依赖其它动态库，请自行复制。
    ```shell
    # 先进入代码根目录
    cd /root/to/OpenHarmonyCode
    # 在out/产品名称/lib.unstripped/下创建aarch64-linux-ohos文件夹存放依赖的动态库
    mkdir out/产品名称/lib.unstripped/aarch64-linux-ohos
    # 复制相关动态库到out目录下
    cp prebuilts/clang/ohos/${host_platform_dir}/llvm/lib/clang/${clang_version}/lib/aarch64-linux-ohos/*.so out/产品名称/lib.unstripped/aarch64-linux-ohos/
    cp prebuilts/clang/ohos/${host_platform_dir}/${clang_version}/llvm/lib/aarch64-linux-ohos/*.so out/产品名称/lib.unstripped/aarch64-linux-ohos/
    ```

6. 修改collect_elf_syscall.py脚本文件，将objdump与readelf工具的路径从空修改为工具在linux环境下的绝对路径。脚本文件存放在base/startup/init/services/modules/seccomp/scripts/tools/下。objdump与readelf工具存放在//prebuilts文件夹内部。
    ```python
    #modified the path of objdump and readelf path
    def get_obj_dump_path():
        obj_dump_path = '/path/to/llvm-objdump'
        return obj_dump_path


    def get_read_elf_path():
        read_elf_path = '/path/to/llvm-readelf'
        return read_elf_path
    ```

7. 使用脚本解析生成对应的策略文件xxx.seccomp.policy。

    **表7**  collect_elf_syscall.py的参数说明
    |  参数  |  说明  |
    |  ---  |  ---  |
    |  --src-elf-path  | ELF文件所在文件夹，例如，~/ohcode/out/rk3568，不以'/'结尾。|
    |  --elf-name| ELF文件名，例如，libmedia_service.z.so。|
    |  --src-syscall-path  |  libsyscall_to_nr_arm或libsyscall_to_nr_arm64，与--target-cpu架构对应。  |
    |  --target-cpu  |  架构号，表示需要统计系统调用的对应架构，该参数影响解析何种架构的libc文件，arm或arm64。  |
    |  --filter-name  | 生成的策略文件名名称，例如，输入值为test，生成的文件名为test.seccomp.policy。  |
    
    使用collect_elf_syscall.py解析ELF文件。

        ```
        # 产品以rk3568，ELF文件以libmedia_service.z.so为示例
        python3 collect_elf_syscall.py --src-elf-path ~/ohcode/out/rk3568 --elf-name libmedia_service.z.so --src-syscall-path libsyscall_to_nr_arm64 --target-cpu arm64 --filter-name media_service
        ```

        xxx.seccomp.policy结果示例。
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

#### Strace统计
1. 使用arm-linux-musleabi与aarch64-linux-musl交叉编译器分别构建32位与64的Strace工具。
2. [跟踪业务进程](#跟踪业务进程)，得到Strace日志。
3. 利用脚本[解析Strace日志](#解析strace日志文件)，得到Seccomp策略文件。
##### 跟踪业务进程
1. 在init仓代码中进行嵌入式修改，修改文件为//base/startup/init/services/init/init_common_service.c，在执行SetSystemseccompPolicy函数设置Seccomp策略前增加以下内容。以下为修改内容。其中行首符号为“+”，则该行为新增内容，若符号为“-”，则是需删除的内容，“xxxx”与进程[引导启动配置文件](subsys-boot-init-cfg.md)中的Services name保持一致。
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
2. 修改文件后进行全量编译，并烧写镜像。
3. 关闭SElinux机制，将Strace工具推入设备中。
    ```shell
    hdc shell setenforce 0
    hdc shell mount -rw -o remount /
    hdc file send /path/to/strace /system/bin/
    hdc shell chmod a+x /system/bin/strace
    ```
4. 创建存放Strace日志的的文件夹。
    ```shell
    hdc shell mkdir -p /data/strace
    ```
5. 终止业务进程，令其重启。可使用以下命令，xxx为业务进程名。
    ```shell
    kill -9 $(pidof xxx)
    ```
6. 对设备进行相关业务操作，尽量使代码全量覆盖。
7. 从设备中/data/strace文件夹取出Strace日志到解析脚本的路径下。
    ```shell
    hdc file recv /data/strace /path/to/base/startup/init/services/modules/seccomp/scripts/tools/
    ```

##### 解析Strace日志文件
1. 将解析日志时所依赖的文件复制到Strace日志文件夹，该依赖文件为[静态分析](#静态分析)第2步的产物。
    ```shell
    cp out/产品名称/gen/base/startup/init/services/modules/seccomp/gen_system_filter/libsyscall_to_nr_arm* base/startup/init/services/modules/seccomp/scripts/tools/strace/
    ```
 
2. 使用脚本解析生成对应的策略文件xxx.seccomp.policy。

    脚本strace_log_analysis.py在//base/startup/init/services/modules/seccomp/scripts/tools/路径下
    
    **表8**  strace_log_analysis.py的参数说明
    |  参数  |  说明  |
    |  ---  |  ---  |
    |  --src-path  | 日志文件所在文件夹，需含libsyscall_to_nr_arm与libsyscall_to_nr_arm64例如，./strace，不以'/'结尾。|
    |  --target-cpu  |  架构号，与跟踪进程的对应的架构一致，arm或arm64。  |
    |  --filter-name  | 生成的策略文件名名称，例如，输入值为test，生成的文件名为test.seccomp.policy。  |

    使用strace_log_analysis.py解析Strace日志。
    ```shell
    cd base/startup/init/services/modules/seccomp/scripts/tools;
    python3 strace_log_analysis.py --src-path strace --target-cpu 指定CPU --filter-name xxx
    ```
    xxx.seccomp.policy结果示例
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

#### Audit统计
1. 使能初始Seccomp策略，使能方法见[进程使能个性化Seccomp策略](#进程使能个性化seccomp策略)章节的开发步骤。
2. 获取日志。
    1. 利用Shell命令创建存放日志的文件夹。
        ```shell
        mkdir -p /data/audit
        ```
    2. 利用Shell命令获取内核日志中与Seccomp相关的Audit日志，存放的日志以“.audit.log”结尾。
        ```shell
        cat /proc/kmsg | grep type=1326 > /data/audit/media_service.audit.log
        ```
3. 进行业务相关操作与触发段错误操作。
    1. 执行触发段错误的方法：在业务代码加入以下代码，并在某处调用TriggerSegmentFault，对镜像重新进行构建及烧写。
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
    2. 设备启动后，利用Shell临时关闭SElinux，并终止业务进程，该进程会自动重启。
        ```shell
        setenforce 0
        ```

4. 利用hdc命令从设备的/data/audit文件夹取出Audit日志到解析脚本的路径下。
    ```shell
    hdc file recv /data/audit /path/to/base/startup/init/services/modules/seccomp/scripts/tools/
    ```
5. 解析Audit日志。
    
    Audit日志示例：
    ```shell
    <5>[  198.963101] audit: type=1326 audit(1659528178.748:27): auid=4294967295 uid=0 gid=1000 ses=4294967295 subj=u:r:appspawn:s0 pid=2704 comm="config_dialog_s" exe="/system/bin/appspawn" sig=31 arch=40000028 syscall=208 compat=1 ip=0xf7b79400 code=0x80000000
    ```
    **表9**  Audit日志关键字段说明
    |  参数  |  说明  |
    |  ---  |  ---  |
    |  type  |  类型，值为1326说明是seccomop类型日志。  |
    |  sig  |  信号量，31为SIGSYS，表示Seccomp发生拦截时给进程发出的信号。  |
    |  arch  |  架构标识，值为40000028表示arm，值为c00000b7表示arm64。  |
    |  syscall  |  系统调用号。  |
    |  compat  |  1表示为兼容模式，即arm64的内核使用了arm的系统调用。 |


    1. 将解析日志时所依赖的文件复制到日志文件夹以备使用，该依赖文件为[静态分析](#静态分析)第2步的产物。
        ```shell
        cp out/产品名称/gen/base/startup/init/services/modules/seccomp/gen_system_filter/libsyscall_to_nr_arm* base/startup/init/services/modules/seccomp/scripts/tools/audit/
        ```
    2. 使用audit_log_analysis.py脚本解析日志生成xxx.seccomp.policy。工具路径在//base/startup/init/services/modules/seccomp/scripts/tools/下。

        **表10**  audit_log_analysis.py的参数说明
        |  参数  |  说明  |
        |  ---  |  ---  |
        |  --src-path  | 日志文件所在文件夹，需含libsyscall_to_nr_arm与libsyscall_to_nr_arm64。例如，./audit，不以'/'结尾。|
        |  --filter-name  | 生成的策略文件名名称，例如，输入值为test，生成的文件名为test.seccomp.policy。 |

        ```shell
        cd base/startup/init/services/modules/seccomp/scripts/tools
        python3 audit_log_analysis.py --src-path audit --filter-name xxx
        ```

### 合并多个策略文件
[统计系统调用](#统计系统调用方法)的执行过程中，可能会生成多个策略文件，这些策略文件中系统调用可能会有重复或者乱序。通过以下步骤可将多个策略文件进行合并、去重，按照arm64/arm顺序，系统调用号从小到大排序。

**表11**  merge_policy.py的参数说明
|  参数  |  说明  |
|  ---  |  ---  |
|  --src-files  | 需处理的文件，需含libsyscall_to_nr_arm与libsyscall_to_nr_arm64。 |
|  --filter-name  | 生成的策略文件名名称，例如，输入值为test，生成的文件名为test.seccomp.policy。  |
1. 将合并文件所依赖的文件复制到日志文件夹以备使用。
    ```shell
    cp out/产品名称/gen/base/startup/init/services/modules/seccomp/gen_system_filter/libsyscall_to_nr_arm* base/startup/init/services/modules/seccomp/scripts/tools/
    ```
2. 使用merge_policy.py将policy1.seccomp.policy，policy2.seccomp.policy策略文件合并成xxxx.seccomp.policy。
    ```shell
    python3 merge_policy.py --src-files libsyscall_to_nr_arm --src-files libsyscall_to_nr_arm64 --src-files policy1.seccomp.policy --src-files policy2.seccomp.policy --filter-name xxxx
    ```