# jobs管理
## 概述
### 功能简介
jobs是init组件下cfg文件中的一组命令构成的集合, 最多添加4096个job。 jobs可以在 **[cfg](subsys-boot-init-cfg.md)** 文件中配置，通常在init启动过程中执行，服务于service的正常启动或特定基础功能的初始化。

### 基本概念
job可以在init.cfg中配置，也可以在模块的自定义cfg中配置。init解析程序会把相同名字job的命令合并到一个job中。同一名字的job只能保证init.cfg中的命令优先执行，其他cfg间的命令执行顺序不保证。
- 基本jobs

  init启动的固定阶段，如“pre-init“，“init”，“post-init”，这类job在init启动的固定阶段执行。
  - pre-init：init前置阶段，其他服务所依赖的，类似于ueventd、watchdog、hilogd等的关键服务会在这一阶段启动，data分区的挂载也在这一阶段进行。
  - init：init进程的主要阶段，这一阶段除了大量命令的执行，同时也是init分组并行启动boot组（第一组）服务的启动阶段，一些关乎系统功能的重要服务会在这一阶段被拉起。
  - post-init：这一阶段主要是通过trigger命令触发其他阶段执行，可以把所有被触发的阶段看作一个个的小阶段，也可以把它们统一看作post-init阶段，这一阶段会执行大量命令，并且它还是init分组并行启动normal组（第二组）服务的启动阶段，cfg中配置的大部分服务都是在这一阶段被拉起的。

- 自定义jobs(仅标准系统以上提供)

  这类job按照一定的规则进行触发，用户根据需要定义的命令集合，通过trigger命令触发执行。

- 条件jobs(仅标准系统以上提供)

  用户通过在jobs中添加condition配置，在条件满足时触发命令执行。

  条件是系统参数值的组合，支持&& 、||等操作, 并且支持*匹配任意值。

  一般情况可按如下示例配置：

  ```
  "condition" : "sys.usb.config = none && sys.usb.configfs = 0",
  ```

  如果特殊情况需要在boot阶段对参数做检查可按下面示例配置：

  ```
  "condition" : "boot && const.debuggable=1",
  ```

  并且jobs在定义命令时，按照下面的规则"param:xxx"命名, 可以根据不同的属性自行组合。

### 约束与限制
在标准系统下有系统参数模块的支持，支持基本jobs、条件jobs、自定义jobs。在小型系统中只支持基本jobs。

## 开发指导
### 场景介绍
job就是命令集合，jobs管理就是对要执行的一组命令集合进行管理， 一组命令集合最多添加4096个命令。在init启动过程中，jobs的执行为服务的正常运行提供支持。

### 参数说明

   **表1** 命令集说明
   | 命令 | 命令格式和示例 | 说明 |
   | -------- | -------- | -------- |
   | mkdir | mkdir 目标文件夹 [mode] [owner] [group]<br/>如：mkdir /storage/myDirectory<br>mkdir /storage/myDirectory 0755 root root| 创建文件夹命令，mkdir和目标文件夹之间有且只能有一个空格。<br>系统类型：小型系统和标准系统 |
   | chmod | chmod&nbsp;权限&nbsp;目标<br/>如：chmod&nbsp;0600&nbsp;/storage/myFile.txt<br/>chmod&nbsp;0750&nbsp;/storage/myDir | 修改权限命令，chmod权限目标之间间隔有且仅有一个空格，权限必须为0xxx格式。<br>系统类型：小型系统和标准系统|
   | chown | chown&nbsp;uid&nbsp;gid&nbsp;目标<br/>如：chown&nbsp;900&nbsp;800&nbsp;/storage/myDir<br/>chown&nbsp;100&nbsp;100&nbsp;/storage/myFile.txt | 修改属组命令，chown&nbsp;uid&nbsp;gid目标之间间隔有且仅有一个空格。<br>系统类型：小型系统和标准系统 |
   | mount | mount&nbsp;fileSystemType&nbsp;src&nbsp;dst&nbsp;flags&nbsp;[data]<br/>如：mount&nbsp;vfat&nbsp;/dev/mmcblk0&nbsp;/sdc&nbsp;rw,umask=000<br/>mount&nbsp;jffs2&nbsp;/dev/mtdblock3&nbsp;/storage&nbsp;nosuid | 挂载命令，各参数之间有且仅有一个空格。flags参考base/startup/init/services/init/init_common_cmds.c中mountFlagMap函数mountFlagMap[]，data为可选字段。<br>系统类型：小型系统和标准系统 |
   | start | start&nbsp;serviceName<br/>如：start&nbsp;foundation| 启动服务命令，start后面跟着service名称，该service名称必须能够在services数组中找到。<br>系统类型：小型系统和标准系统 |
   | export | export key value<br>如：export TEST /data/test | 设置环境变量命令。后面跟两个参数，第一个参数是环境变量名，第二个参数是环境变量值。<br>系统类型：小型系统和标准系统 |
   | rm | rm filename<br>如：rm /data/testfile | 删除文件命令。后面跟一个参数，即文件的绝对路径。<br>系统类型：小型系统和标准系统 |
   | rmdir | rmdir dirname<br>如：rmdir /data/testdir | 删除目录命令。后面跟一个参数，即目录的绝对路径。 <br>系统类型：小型系统和标准系统 |
   | write | write filename value<br>如：write /data/testfile 0 | 写文件命令。后面跟两个参数，第一个参数是文件的绝对路径，第二个参数是要写入文件的字符串。 <br>系统类型：小型系统和标准系统 |
   | stop | stop serviceName<br>如：stop console | 关闭服务命令。后面跟一个参数，即要关闭的服务名。<br>系统类型：小型系统和标准系统 |
   | copy | copy oldfile newfile<br>如：copy /data/old /data/new | 拷贝文件命令。后面跟两个参数，第一个参数是原文件绝对路径，第二个参数是新文件绝对路径。<br>系统类型：小型系统和标准系统 |
   | reset | reset serviceName<br>如：reset console | 重置服务命令。后面跟一个参数，即要重启的服务名。目前reset命令的策略是，如果一个服务没有启动，则该命令会将其拉起，如果一个服务处于运行状态，则该命令会将其关闭后重启。<br>系统类型：小型系统和标准系统 |
   | reboot | reboot [subsystem]<br>如：reboot updater | 重启系统命令。后面可以跟一个参数，也可以没有参数，当没有参数时执行该命令，将会使设备重启到当前系统，当后面跟参数时，参数应当是子系统的名字，例如,reboot updater，将会重启进入updater子系统。<br>系统类型：小型系统和标准系统 |
   | sleep | sleep time<br>如：sleep 5 | 睡眠命令。后面可以跟一个参数，该参数是睡眠时间， 限制睡眠时间在5秒内。<br>sleep命令谨慎使用。<br>系统类型：小型系统和标准系统 |
   | domainname | domainname name<br>如：domainname localdomain | 设置域名。<br>系统类型：小型系统和标准系统 |
   | hostname | hostname name<br>如：hostname localhost | 设置主机名命令。<br>系统类型：小型系统和标准系统 |
   | wait | wait filepath [time]<br>如：wait /data/testfile 或 wait /data/testfile 5| 等待命令，等待时间不超过5秒。<br>系统类型：小型系统和标准系统 |
   | setrlimit | setrlimit resource curValue maxValue<br>如：setrlimit RLIMIT_CPU 10 100| 设定资源使用限制命令。<br>系统类型：小型系统和标准系统 |
   | write | write path content<br>如：write /proc/sys/kernel/sysrq 0 | 写文件命令。<br>系统类型：小型系统和标准系统 |
   | exec | exec 可执行文件路径 可执行文件传的参数<br>如： exec /system/bin/mkdir /data/test.txt | 系统调用命令。<br>系统类型：小型系统和标准系统 |
   | syncexec | syncexec 可执行文件路径 可执行文件传的参数<br>如:syncexec /system/bin/udevadm trigger| 同步执行，syncexec 会调用wait等待子进程结束。参数个数不超过10个。<br>系统类型：标准系统
   | mknode |mknode name { b \| c } Major Minor<br>如mknode path b 0644 1 9| 建立一个目录项和一个特殊文件的对应索引节点。<br>系统类型：标准系统 |
   | makedev | makedev major minor<br>如：makedev -v update | 创建静态的设备节点命令，通常位于/dev目录下。<br>系统类型：标准系统 |
   | symlink | symlink target link_name<br>如：symlink /proc/self/fd/0 /dev/stdin | 符号链接命令。<br>系统类型：标准系统 |
   | trigger | trigger jobName<br>如：trigger early-fs | 触发job执行的命令。<br>系统类型：标准系统 |
   | insmod | insmod [-f] [options]<br>如：insmod xxx.ko| 内核模块文件载入命令。<br>系统类型：标准系统 |
   | setparam | setparam paramName paramValue<br>如：setparam sys.usb.config hdc| 设置系统参数。<br>系统类型：标准系统 |
   | load_persist_params | load persist params<br>如：load_persist_params&nbsp;| 加载persist参数。load_persist_params命令后有且仅有一个空格。<br>系统类型：标准系统 |
   | load_param | load params<br>如：load_param /data/test.normal.para| 将文件里的param加载到内存。<br>系统类型：标准系统 |
   | load_access_token_id | 如：load_access_token_id&nbsp;| 将access token信息写入data/service/el0/access_token/nativetoken.json文件，load_access_token_id后有且只有一个空格。<br>系统类型：标准系统 |
   | ifup | ifup 激活网络接口<br>如：ifup eth0 | 激活指定的网络接口。<br>系统类型：标准系统 |
   | mount_fstab | mount_fstab fstab.test<br>如：mount_fstab /vendor/etc/fstab.test| 按照fstab挂载分区的命令。<br>系统类型：标准系统 |
   | umount_fstab | umount_fstab  fstab.test<br>如：umount_fstab  /vendor/etc/fstab.test | 按照fstab卸载分区的命令。<br>系统类型：标准系统 |
   | restorecon | restorecon file or dir<br>如：restorecon /file | 重新加载selinux 的context。<br>系统类型：标准系统 |
   | stopAllServices | stopAllServices [bool]<br>如：stopAllServices false 或 stopAllServices | 停止所有服务，最长响应时间默认10毫秒。<br>系统类型：标准系统 |
   | umount |umount path<br>如：umount /vendor | 卸载已经挂载的硬件设备 。<br>系统类型：标准系统 |
   | sync | 如：sync&nbsp; | 同步写入数据到磁盘。sync后有且仅有一个空格。<br>系统类型：标准系统 |
   | timer_start | timer_start serviceName<br>如：timer_start console | 启动服务计时器。<br>系统类型：标准系统 |
   | timer_stop | timer_stop serviceName<br>如：timer_stop console | 停止服务计时器。<br>系统类型：标准系统 |
   | init_global_key | init_global_key path<br>如：init_global_key /data | data分区文件加密key初始化。<br>系统类型：标准系统 |
   | init_main_user | 如：init_main_user| 主用户目录加密。<br>系统类型：标准系统 |
   | mkswap | mkswap file<br>如：mkswap /swapfile1 | 在一个文件或者设备上建立交换分区。<br>系统类型：标准系统 |
   | swapon | swapon file <br>如：swapon /swapfile1| 激活交换空间。<br>系统类型：标准系统 |
   | mksandbox | mksandbox fileName<br>如：mksandbox system | 创建沙盒。<br>系统类型：标准系统 |
   | loadcfg | loadcfg&nbsp;filePath<br/>如：loadcfg&nbsp;/patch/fstab.cfg | 加载其他cfg文件命令。后面跟着的目标文件大小不得超过50KB，且目前仅支持加载/patch/fstab.cfg，其他文件路径和文件名均不支持。/patch/fstab.cfg文件的每一行都是一条命令，命令类型和格式必须符合本表格描述，命令条数不得超过20条。<br>系统类型：小型系统 |

### 接口说明
jobs管理属于init启动过程中的一环，是一个流程化的功能，是完全服务于init启动过程的，并不对其他组件提供任何功能接口，其运行逻辑契合cfg中命令组的管理，无法对其他类型管理提供帮助。下述主要介绍其在init当中的调用逻辑。

**表2** job解析接口说明
| 函数名 | 函数解释 | 支持系统类型 |
|:--------|:-----|:------|
|void ParseAllJobs(const cJSON *fileRoot)|jobs解析总入口。| 小型系统和标准系统 |
|static void ParseJob(const cJSON *jobItem, Job *resJob)|校验job是否已存在，解析cmds下命令的功能。| 小型系统 |
|int GetCmdLinesFromJson(const cJSON *root, CmdLines **cmdLines)| 解析job中cmds命令。当前小型系统使用，标准系统由于涉及trigger<br/>功能和condition条件启动功能，并未使用该接口进行命令解析。| 小型系统和标准系统 |
|int ParseTriggerConfig(const cJSON *fileRoot, <br>int (*checkJobValid)(const char *jobName))|解析job中Trigger命令。| 标准系统 |
|static int ParseTrigger_(const TriggerWorkSpace *workSpace,<br>const cJSON *triggerItem, <br/>int (*checkJobValid)(const char *jobName))|获取job名称，condition属性以及cmds命令组的功能，解析到的<br/>job以hash表的形式存储，而命令的保存则使用了队列结构。| 标准系统 |

**表3** job触发接口说明
| 函数名 | 函数解释 | 支持系统类型 |
|:--------|:-----|:------|
|void PostTrigger(EventType type, const char *content, uint32_t contentLen)|校验名称的有效性并发送触发job事件的功能。| 标准系统 |
|static void SendTriggerEvent(int type, const char *content, uint32_t contentLen)|通过系统参数进行整机控制以及服务的启动与停止等。| 标准系统 |
|static void DoTriggerCmd(const struct CmdArgs *ctx)|trigger命令执行接口。| 标准系统 |
|void DoTriggerExec(const char *triggerName)|仅标准系统可用。通过参数中的job名称找到对应命令组，<br>并将命令推入执行队列依次执行。| 标准系统 |
|void DoJob(const char *jobName)|通过jobName匹配对应job，调用DoCmdByIndex<br>执行其中的命令。| 小型系统 |
|void DoCmdByIndex(int index, const char *cmdContent)|拼接参数与命令。| 小型系统和标准系统 |

### 开发实例
下述为cfg文件中jobs配置模板，可验证jobs管理的功能。
```
{
    "jobs" : [{     // 基本job
            "name" : "stage1",
            "cmds" : [
                "start service1",
                "mkdir dir1"
            ]
        }, {        // 条件job
            "name" : "param:test.name1=0",
            "condition" : "test.name1=0",
            "cmds" : [
                "chmod 0755 dir1",
                "chown root root dir1"
            ]
        }, {        // 自定义job
            "name" : "param:test.name2=*",
            "condition" : "test.name2=*",
            "cmds" : [
                "chmod 0644 dir1",
                "chown system system dir1"
            ]
        }
    ]
}
```
以上展示了三种job配置的方式，下面对其中的配置差别分别进行介绍：

1. "name"和"cmds"是一个job中的必选项，并且"cmds"中应当包含系统支持的命令，否则就是浪费资源的无意义配置。

2. "condition"是一个job中的可选属性，这一属性的配置代表着该job是一个条件触发的job，不通过代码或trigger命令在固定阶段触发执行，而是在condition中的条件满足后才被触发执行。

3. job的命名需满足一定的规则，对于条件是系统参数的job，以"param:"为前缀。

4. 一个新的job命名需要在其他可执行的job命令组中通过trigger命令触发才可执行，提供的默认trigger命令执行阶段是post-init阶段。

5. 一个已经存在的job名称仍可以在不同文件中继续使用，相同名称的job将会被视为同一job，通过trigger触发时其中的命令合并执行。

6. 条件执行job的condition配置通常是系统参数，可以指定某个系统参数被设定为某个值时该job触发执行，也可以使用"*"符号，代表只要该系统参数被设置，不论为何值，条件都满足，该job可以被触发执行。

7. 在小型系统中，jobs中的post-init 部分不支持trigger命令。