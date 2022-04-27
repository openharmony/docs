# init启动引导组件

## 功能说明

init启动引导组件负责在系统启动阶段启动关键服务进程。 若用户需要新增随开机自启动的系统服务，可添加新的配置文件xxx.cfg，系统会自动分析对应的cfg文件，并按照cfg文件启动对应的服务。

- init启动引导的配置文件

  init启动引导组件配置文件包含了所有需要由init进程启动的系统关键服务的服务名、可执行文件路径、权限和其他信息，烧写单板后可在“/etc/“目录下找到，文件名称为init.cfg，采用json格式，文件大小目前限制在100KB以内。

  init进程启动后读取/etc/init.cfg，然后解析其json格式内容，并根据解析结果依次加载系统服务。

  各模块需要配置或添加关键服务时，可以在对应模块的cfg文件进行配置，编译过程中会将配置后的文件拷贝到/system/etc/init目录下，单板中可在"/etc/init/"目录下查找到对应的cfg文件，

  对于单板中/etc/init下存在的cfg文件，init进程会逐一解析，下面分别介绍一下init扫描cfg文件的规则和cfg文件内容的具体组成格式。

  - cfg文件扫描规则

    对于标准系统和小型系统，cfg文件扫描是共用一个相同的接口，接口代码如下：
    ```
    void ReadConfig(void)
    {
        // parse cfg
        if (InChargerMode() == 1) {
            ParseInitCfg(INIT_CONFIGURATION_FILE, NULL);
            ReadFileInDir(OTHER_CHARGE_PATH, ".cfg", ParseInitCfg, NULL);
        } else if (InUpdaterMode() == 0) {
            ParseInitCfg(INIT_CONFIGURATION_FILE, NULL);
            ReadFileInDir(OTHER_CFG_PATH, ".cfg", ParseInitCfg, NULL);
            ReadFileInDir("/vendor/etc/init", ".cfg", ParseInitCfg, NULL);
        } else {
            ReadFileInDir("/etc", ".cfg", ParseInitCfg, NULL);
        }
    }
    ```
    以下是这段代码中的宏定义：

    ```
    #define INIT_CONFIGURATION_FILE "/etc/init.cfg"

    #define OTHER_CHARGE_PATH "/system/etc/charge"

    #define OTHER_CFG_PATH "/system/etc/init"
    ```
    对于充电模式和升级模式下cfg的扫描此处不作详细说明，我们关注正常系统启动时init扫描cfg文件的规则。
    1. 对于/etc/init.cfg文件，是应当最先解析，因此直接调用解析接口解析该文件。
    2. 对于/etc/init目录（note：/etc是指向/system/etc的一个符号链接，可以把它们看作是等价的），init进程会遍历该目录下的文件，匹配文件的后缀名，匹配到cfg文件时就会调用解析接口对该文件进行解析。
    3. init还会遍历/vendor/etc/init目录下的cfg文件并进行解析，这个目录下的cfg文件应当是与硬件平台相关的。

  - cfg文件的组成格式

    下面展示一个cfg文件的框架：
    ```
    {
        "import" : [
                "/etc/init.xxx.cfg",
                "/vendor/etc/init.${ohos.boot.hardware}.cfg"
        ],
        "jobs" : [{
                "name" : "example-stage",
                "cmds" : [
                    "write /example/file 0",
                    "start example"
                ]
            }
        ],
        "services" : [{
                "name" : "example",
                "path" : ["/system/bin/example"],
            }
        ]
    }
    ```
    前面已经提到，cfg文件是json格式的文本文件。对于启动组件来说，init进程能够解析的cfg文件中的内容主要包括3种json对象，其对象名分别为"import", "jobs", "services"。下面逐一讲解这3个部分。

    1. "import": 导入其他cfg文件。一个cfg文件中导入的其他cfg文件，会在当前cfg文件解析完成后，按顺序继续解析。
    2. "jobs": 带名字的命令组。一个job被执行时，会按照先后顺序逐条执行"cmds"中的命令。触发执行job的方式在下文中有详细介绍。
    3. "services": 服务。最简单的服务可以只有一个名字和一个可执行文件路径。一个服务的基本运行逻辑是在init进程中fork一个子进程，然后在子进程中执行路径中的可执行文件。服务是启动组件中的核心内容，cfg中服务的配置还包括了各种各样的属性，服务的控制方式也涵盖了多方面的内容，这些都将在下文中展开详细的叙述。

- init服务启动控制(仅标准系统以上提供)<a name = "section56901555918">

  init会根据用户的服务配置，把服务分成三类，在不同的阶段进行启动。

  - “boot”类型：对应系统中需要优先启动的服务，该类服务在“init”阶段启动。
  - “normal”类型：默认配置，对应系统中的普通服务，该类服务在“post-init"阶段启动。
  - “condition”类型：表示服务按照条件启动。对有特殊要求的服务，可以直接通过start xxx 命令执行启动，一般在条件“job”或者在“init”的某个阶段使用命令启动。

  服务间或服务与命令之间存在依赖关系，需要通过"condition"描述服务，配置参考如下：
    ```
    "services" : [{
        "name" : "serviceName",
        "start-mode" : "condition",
    },
    ```
- init服务并行控制(仅标准系统以上提供)<a name="section56901555919"></a>

  init提供服务并行处理能力，启动服务在不同的阶段执行job的能力。

  - “on-start”：在服务进程被fork后执行，不同服务的on-start job可以并行执行（在服务的子进程中执行，只对该进程产生影响）。
  - “on-stop”：在服务停止时执行。
  - "on-restart"：在服务重启时执行。

  配置参考如下：
    ```
  "services" : [{
        "name" : "serviceName",
        "jobs" : {
            "on-boot" : "boot",
            "on-start" : "services:serviceName_start",
            "on-stop" : "services:serviceName_stop",
            "on-restart" : "services:serviceName_restart"
       }
    },
    ```

- init 按需启动(仅标准系统以上提供) <a name="section56901555920">

  由init管理的服务支持按需启动，按需启动的服务不会在系统启动过程中主动被拉起，而是当某些事件发生时才会被init按需拉起，触发服务启动的事件可能是被init监听的相关socket有消息上报、samgr收到客户端的请求需要拉起SA服务等情况。

  "ondemand"：按需启动服务的标志，一个服务配置了该属性值为true的时候，服务不再需要配置start命令来拉起，而是被监听的相应事件发生时才会被拉起。

  “ondemand”配置参考如下：
    ```
    "services" : [{
      "name" : "serviceName",
      "ondemand" : true,
  }]
  ```

  - SA进程按需启动
     1. 应用请求SA句柄时samgr需识别SA所属进程是否可动态拉起。
     2. 如需拉起，则需阻塞请求，等init拉起SA进程并注册SA后再返回所请求的SA句柄。
  - socket进程按需启动
     1. init进程在pre-fork阶段为socket类进程创建好socket，init进程中监听创建好的socket上的网络事件。
     2. socket上有报文事件后，init进程拉起socket进程进行报文处理，init进程取消socket数据的监听，由socket进程处理。
     3. socket进程无报文处理后，可以自动退出，退出后init进程回收该子进程并重新监听socket网络数据。
  - 热插拔服务进程按需启动  进程可根据系统参数的变化进行热插拔事件按需启动处理。

- init 进程启动&amp;回收能力增强

  进程启动时，支持在配置文件中配置服务进程的绑核、优先级、MAC信息以及AccessToken信息。

  - init提供修改\*.cfg配置文件， 为服务进程提供cpu绑核功能。
  - init提供修改\*.cfg配置文件， 为服务进程提供优先级设置。
  - init提供修改\*.cfg配置文件， 为服务提供MAC信息设置，即服务的SELinux标签。
  - init提供修改\*.cfg配置文件， 为服务提供设置AccessToken, 为系统服务进程设置其分布式Capability能力（仅标准系统以上提供）。
  - init提供修改\*.cfg配置文件， 为服务提供抑制机制。

  服务进程启动&回收能力增强配置，如下：
    ```
    "services" : [{
        "name" : "serviceName",
        "importance" : 1,           // 服务进程提供优先级设置
        "cpucore" : [0],            // 服务进程提供cpu绑核功能
        "critical" : [1, 5, 10],    // 服务提供抑制机制
        "apl" : "normal",           // 系统服务进程设置其分布式Capability能力
        "d-caps" : ["OHOS_DMS"],    // 系统服务进程设置其分布式Capability能力
        "secon" : "u:r:distributedsche:s0" / 服务的SELinux标签， "u:r:distributedsche:s0"为要设置的SELinux标签信息
    },
    ```
- init FD代持(仅标准系统以上提供)

  FD代持是按需启动的一个辅助扩展机制，按需启动进程可以保持退出前的fd状态句柄不丢失。按需启动进程退出前可将fd发送给init代持，再次启动后再从init获取fd。

  init提供了相关接口供服务调用，服务进程退出前调用接口将fd通过支持IPC通信的socket发送给init代持，待该服务重新启动时，init将持有的该服务相关的fd句柄通过同样的方式返回给服务。相关接口参考：[FD代持接口介绍](#table14737791479)。

- init job

  init提供job能力，一个job就是一组命令的集合。job可以在init.cfg中配置，也可以在模块的自定义cfg中配置。init解析程序会把相同名字job的命令合并到一个job中。同一名字的job只能保证init.cfg中的命令优先执行，其他cfg间的命令执行顺序不保证。

  - 普通job：一般是init启动的固定阶段，如“pre-init“，“init”，“post-init”等，这类job在init启动的固定阶段执行。
  - 自定义job：用户自定义的job，这类job按照一定的规则进行触发。
     - job：用户任意定义，可以通过trigger命令执行。
     - 控制job(仅标准系统以上提供)：按条件触发处理的能力。在job中可以设置触发条件，当对应的属性值满足设置的条件时，就会触发job执行。触发条件支持&amp;&amp;和||操作，可以根据不同的属性自行组合。

 - bootchart 插件

   bootchart是一个用于linux启动过程性能分析的开源工具软件，在系统中自动收集CPU占用率、磁盘吞吐率、进程等信息，并以图形方式显示分析结果，可用作指导优化系统启动过程。begetctl命令参考：[begetctl命令说明](#table14737791480)

    如下所示：

    预制条件：
      1. 准备bootchart测试环境：linux操作系统下安装python及pycairo
       pip install pycairo
      2. 在linux解压：bootchart-master.tar
      tar -zxvf  bootchart-master.tar

    执行步骤：
      1. 启动系统
      2. 执行命令行：begetctl bootchart enable
      3. 重启系统
      4. 执行命令行：begetctl bootchart stop
      5. 执行命令行：begetctl bootchart disable
      6. 在/data/bootchart目录下导出如下文件：<br>
        header<br>
        proc_diskstats.log<br>
        proc_ps.log<br>
        proc_stat.log<br>
       并存放在bootchart文件夹
      7. 使用命令：tar -zcvf bootchart.tgz * 进行打包（只支持linux版本）并将该打包文件拷贝到linux：bootchart-master目录下
      8. 运行：<br>
        在bootchart-master目录下运行<br>
        python3 pybootchartgui.py -f pdf bootchart.tgz<br>

      预期结果：<br>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在bootchart-master目录下生成bootchart.pdf

## 开发指导

1. 配置jobs数组。
   init启动引导组件将系统启动分为三个阶段：

   - “pre-init”阶段：启动系统服务之前需要先执行的操作，例如挂载文件系统、创建文件夹、修改权限等。
   - “init”阶段：系统服务启动阶段。
   - “post-init”阶段：系统服务启动完成后还需要执行的操作。

    ```
    "jobs" : [{
             "name" : "pre-init",
             "cmds" : [
                 "mkdir /testdir",
                 "chmod 0700 /testdir",
                 "chown 99 99 /testdir",
                 "mount vfat /dev/mmcblk0p0 /testdir2 noexec nosuid" // mount命令，格式为：mount 文件系统类型 source target flags data
             ]
             }, {
                 "name" : "init",
                 "cmds" : [
                     "start service1",
                     ]
                 }, {
                     "name" : "post-init",
                     "cmds" : []
                 }
             ]
    ```

    **表1** 执行job介绍
   | job名 | 说明 |
   | :-------- | :-------- |
   | pre-init | 最先执行的job，如果开发者的进程在启动之前需要首先执行一些操作（例如创建文件夹），可以把操作放到pre-init中先执行。 |
   | init | 中间执行的job，例如服务启动。 |
   | post-init | 最后被执行的job，如果开发者的进程在启动完成之后需要有一些处理（如驱动初始化后再挂载设备），可以把这类操作放到该job执行。单个job最多支持30条命令（当前仅支持start/mkdir/chmod/chown/mount/loadcfg），命令名称和后面的参数（参数长度≤128字节）之间有且只能有一个空格。 |

     **表2** 命令集说明
   | 命令 | 命令格式和示例 | 说明 | 支持系统类型 |
   | -------- | -------- | -------- | -------- |
   | mkdir | mkdir&nbsp;目标文件夹<br/>如：mkdir&nbsp;/storage/myDirectory | 创建文件夹命令，mkdir和目标文件夹之间有且只能有一个空格。 | small&amp;standard |
   | chmod | chmod&nbsp;权限&nbsp;目标<br/>如：chmod&nbsp;0600&nbsp;/storage/myFile.txt<br/>chmod&nbsp;0750&nbsp;/storage/myDir | 修改权限命令，chmod权限目标之间间隔有且仅有一个空格，权限必须为0xxx格式。 | small&amp;standard |
   | chown | chown&nbsp;uid&nbsp;gid&nbsp;目标<br/>如：chown&nbsp;900&nbsp;800&nbsp;/storage/myDir<br/>chown&nbsp;100&nbsp;100&nbsp;/storage/myFile.txt | 修改属组命令，chown&nbsp;uid&nbsp;gid目标之间间隔有且仅有一个空格。 | small&amp;standard |
   | mount | mount&nbsp;fileSystemType&nbsp;src&nbsp;dst&nbsp;flags&nbsp;data<br/>如：mount&nbsp;vfat&nbsp;/dev/mmcblk0&nbsp;/sdc&nbsp;rw,umask=000<br/>mount&nbsp;jffs2&nbsp;/dev/mtdblock3&nbsp;/storage&nbsp;nosuid | 挂载命令，各参数之间有且仅有一个空格。flags当前仅支持nodev、noexec、nosuid、rdonly，data为可选字段。 | small&amp;standard |
   | start | start&nbsp;serviceName<br/>如：start&nbsp;foundation<br/>start&nbsp;shell | 启动服务命令，start后面跟着service名称，该service名称必须能够在services数组中找到。 | small&amp;standard |
   | export | export key value<br>如：export TEST /data/test | 设置环境变量命令。后面跟两个参数，第一个参数是环境变量名，第二个参数是环境变量值。| small&amp;standard |
   | rm | rm filename<br>如：rm /data/testfile | 删除文件命令。后面跟一个参数，即文件的绝对路径。 | small&amp;standard |
   | rmdir | rmdir dirname<br>如：rmdir /data/testdir | 删除目录命令。后面跟一个参数，即目录的绝对路径。 | small&amp;standard | write | write filename value<br>如：write /data/testfile 0 | 写文件命令。后面跟两个参数，第一个参数是文件的绝对路径，第二个参数是要写入文件的字符串。 | small&amp;standard |
   | stop | stop servicename<br>如：stop console | 关闭服务命令。后面跟一个参数，即要关闭的服务名。 | small&amp;standard |
   | copy | copy oldfile newfile<br>如：copy /data/old /data/new | 拷贝文件命令。后面跟两个参数，第一个参数是原文件绝对路径，第二个参数是新文件绝对路径。 | small&amp;standard |
   | reset | reset servicename<br>如：reset console | 重启服务命令。后面跟一个参数，即要重启的服务名。目前reset命令的策略是，如果一个服务没有启动，则该命令会将其拉起，如果一个服务处于运行状态，则该命令会将其关闭后重启。| small&amp;standard |
   | reboot | reboot (subsystem)<br>如：reboot updater | 重启系统命令。后面可以跟一个参数，也可以没有参数，当没有参数时执行该命令，将会使设备重启到当前系统，当后面跟参数时，参数应当是子系统的名字，例如,reboot updater，将会重启进入updater子系统。 | small&amp;standard |
   | sleep | sleep time<br>如：sleep 5 | 睡眠命令。后面可以跟一个参数，该参数是睡眠时间。 | small&amp;standard |
   | domainname | domainname name<br>如：domainname localdomain | 设置域名 | small&amp;standard |
   | hostname | hostname name<br>如：hostname localhost | 设置主机名命令。 | small&amp;standard |
   | wait | wait PID<br>如：wait pid | 等待命令。| small&amp;standard |
   | setrlimit | setrlimit resource curValue maxValue<br>如：| 设定资源使用限制命令。 | small&amp;standard |
   | write | write path content<br>如：write /proc/sys/kernel/sysrq 0 | 写文件命令。 | small&amp;standard |
   | exec | exec 可执行文件路径 可执行文件传的参数<br>如：exec /system/bin/udevadm trigger | 系统调用命令。 | small&amp;standard |
   | mknode |mknod name { b \| c } Major Minor<br>如mknod path b 0644 1 9| 建立一个目录项和一个特殊文件的对应索引节点。 参考mknod命令 |standard |
   | makedev | makedev major minor<br>如：makedev -v update | 创建静态的设备节点命令，通常位于/dev目录下。| standard |
   | symlink | symlink path1 path2<br>如：symlink /proc/self/fd/0 /dev/stdin | 符号链接命令。 | standard |
   | trigger | trigger jobName<br>如：trigger early-fs | 触发job执行的命令。 | standard |
   | insmod | insmod ko文件<br>如：insmod xxx.ko| 内核模块文件载入命令。 | standard |
   | setparam | setparam paramname paramvalue<br>如：setparam sys.usb.config hdc| 设置系统参数。| standard |
   | load_persist_params | load persist params<br>如：load_persist_params&nbsp;| 加载persist参数。load_persist_params命令后有且仅有一个空格 | standard | 
   | load_param | load params<br>如：load_param /data/test.normal.para| 将文件里的param加载到内存。| standard |
   | load_access_token_id | 如：load_access_token_id&nbsp;| 将access token信息写入data/service/el0/access_token/nativetoken.json文件，load_access_token_id后有且只有一个空格。| standard |
   | ifup | ifup 激活网络接口<br>如：ifup eth0 | 激活指定的网络接口。| standard |
   | mount_fstab | mount_fstab fstab.test<br>如：mount_fstab /vendor/etc/fstab.test| 按照fstab挂载分区的命令。 | standard |
   | umount_fstab | umount_fstab  fstab.test<br>如：umount_fstab  /vendor/etc/fstab.test | 按照fstab卸载分区的命令。 | standard |
   | restorecon | restorecon file or dir<br>如：restorecon /file | 重新加载selinux 的context。 | standard |
   | stopAllServices | stopAllServices [bool]<br>如：stopAllServices false 或 stopAllServices | 停止所有服务。 | standard |
   | umount |umount path<br>如：umount /vendor | 卸载已经挂载的硬件设备 。 | standard |
   | sync | 如：sync&nbsp; | 同步写入数据到磁盘。sync后有且仅有一个空格。| standard |
   | timer_start | timer_start serviceName<br>如：timer_start console | 启动服务计时器。 | standard |
   | timer_stop | timer_stop serviceName<br>如：timer_stop console | 停止服务计时器。 | standard |
   | init_global_key | init_global_key path 如：init_global_key /data | data分区文件加密key初始化。| standard |
   | init_main_user | 如：init_main_user| 主用户目录加密。| standard |
   | mkswap | mkswap file<br>如：mkswap /swapfile1 | 在一个文件或者设备上建立交换分区。 | standard |
   | swapon | swapon file <br>如：swapon /swapfile1| 激活交换空间 | standard |
   | loadcfg | loadcfg&nbsp;filePath<br/>如：loadcfg&nbsp;/patch/fstab.cfg | 加载其他cfg文件命令。后面跟着的目标文件大小不得超过50KB，且目前仅支持加载/patch/fstab.cfg，其他文件路径和文件名均不支持。/patch/fstab.cfg文件的每一行都是一条命令，命令类型和格式必须符合本表格描述，命令条数不得超过20条。 | small |

2.  配置services数组，service集合（数组形式），包含了init进程需要启动的所有系统服务。

    ```
    "services" : [{
        "name" : "service1",
        "path" : ["/bin/process1", "param1", "param2"],
        "uid" : 1,
        "gid" : 1,
        "once" : 0,
        "importance" : 1,
        "caps" : [0, 1, 2, 5],
        "start-mode" : "condition",
        "cpucore" : [0],
        "critical" : [0, 5, 10],
        "apl" : "normal",
        "d-caps" : ["OHOS_DMS"],
        "jobs" : {
            "on-boot" : "boot",
            "on-start" : "services:service1_start",
            "on-stop" : "services:service1_stop",
            "on-restart" : "services:service1_restart"
       }
    }, {
        "name" : "service2",
        "path" : "/bin/process2",
        "uid" : 2,
        "gid" : 2,
        "once" : 1,
        "importance" : 0,
        "caps" : [ ]，
        "cpucore" : 0,
        "critical" : [ ],
        "apl" : "normal",
        "d-caps" : [ ]
    }]
    ```

    **表3**  service字段说明<a name="table14737791471"></a>

    | 字段名 | 字段说明 | 字段解释 | 支持系统类型 |
    | ---------- |-------- | --------| --------|
    | name          | 当前服务的服务名。 |  类型：字符串； 服务名非空且长度<=32字节。| small&amp;standard |
    | path          | 当前服务的可执行文件全路径和参数，数组形式。 | 确保第一个数组元素为可执行文件路径、数组元素个数<=20。 <br> 每个元素为字符串形式以及每个字符串长度<=64字节。| small&amp;standard |
    | uid           | 当前服务进程的uid值。 | 类型：int | small&amp;standard |
    | gid           | 当前服务进程的gid值。 | 类型：int | small&amp;standard |
    | once          | 当前服务进程是否为一次性进程。 | 1：一次性进程，当该进程退出时，init不会重新启动该服务进程。 <br> 0 : 常驻进程，当该进程退出时，init收到SIGCHLD信号并重新启动该服务进程。 | small&amp;standard |
    | importance    | 当前服务优先级 | 标准系统中:<br> &emsp; &emsp;服务优先级取值范围 [-20， 19]，超出为无效设置。<br> 小型系统中：<br> &emsp; &emsp;0 : 非重要进程 <br> &emsp;  &emsp;非0 : 重要进程 | small&amp;standard |
    | caps          | 当前服务所需的capability值，根据安全子系统已支持的capability，评估所需的capability，遵循最小权限原则配置。| 类型：数字或者字符串数组，在配置数字时，按linux标准的capability进行配置。字符串时，使用标准定义的宏的名字进行配置。 | small&amp;standard |
    | critical      | 为服务提供抑制机制，服务在配置时间 T 内，频繁重启次数超过设置次数 N 重启系统。 | 标准系统中<br> &emsp; &emsp;类型：int型数组，如："critical" : [M, N, T]<br> &emsp; &emsp; M：使能标志位（0：不使能；1：使能）， N：频繁拉起服务次数， T：时间(单位：秒)。<br> &emsp; &emsp; M > 0; N > 0 <br> 小型系统中 & 标准系统中：<br> &emsp; &emsp;类型：int，如："critical" : M<br> &emsp; &emsp; M：使能标志位（0：不使能；1：使能）<br> &emsp; &emsp;默认拉起服务次数：4次， 时间：20秒。 | small&amp;standard |
    | cpucore      | 服务需要的绑定的cpu核心数 | 类型：int型数组， 如"cpucore" : [N1, N2, ...], N1， N2均为需要绑定的cpu核索引<br> 如单核设备 cpucore : [0] | small&amp;standard |
    | d-caps       | 服务分布式能力（仅标准系统以上提供）。| 类型：字符串数组， 如 "d-caps" : ["OHOS_DMS"] | standard |
    | apl          | 服务能力特权级别（仅标准系统以上提供）。 | 类型：字符串， 如 "apl" : "system_core"。<br> 目前支持"system_core"（默认值）, "normal", "system_basic"。 | standard |
    | start-mode   | 服务的启动模式（仅标准系统以上提供）。 | 类型：字符串， 如 "start-mode" : "condition"。<br>目前支持"boot", "normal", "condition"。具体说明参考：[init服务启动控制](#section56901555918) | standard |
    | jobs         | 当前服务在不同阶段可以执行的job。 | 具体说明参考：[init服务并行控制](#section56901555919) | small&amp;standard |
    | ondemand     | 按需启动服务的标志。 | 类型：bool，如"ondemand" : true，小型系统只在Linux内核上支持。具体说明参考：[init服务按需启动](#section56901555920)| small&amp;standard |
    | disable | 预留字段，无实际意义。 | | small&amp;standard |
3. 服务中socket配置和按需启动。

    服务中支持配置 "socket" 属性，该属性以一个JSON对象的格式配置。配置有 "socket" 属性的服务，init将会为其创建socket，以是否为按需启动服务来区分其创建的时机。
    - 按需启动的服务，init会在解析到该服务时，根据解析到的socket配置进行创建。
    - 正常启动的服务，init会在拉起该服务时，执行服务可执行文件之前创建其配置的socket。

    无论服务是否按需启动，其真正被拉起后，都需要通过特定接口获取init为其创建的socket句柄，进而接手该socket的管理，成为服务自有的socket。
    除以上socket的配置和创建流程，对于按需启动的服务，init还有不同行为。当init在创建根据服务的socket配置创建完socket后，将会判断服务的ondemand属性是否为true（按需启动服务），若是则会调用接口对socket进行轮询监听，直到socket有消息上报，此时将停止监听并拉起对应服务，由服务接管该socket并处理消息。

   下面以ueventd服务为例介绍服务中socket和按需启动的配置以及各字段的含义。

   ```
   "services" : [{
      "name" : "ueventd",
      "path" : ["/system/bin/ueventd"],
      "socket" : [{
          "name" : "ueventd",
          "family" : "AF_NETLINK",
          "type" : "SOCK_DGRAM",
          "protocol" : "NETLINK_KOBJECT_UEVENT",
          "permissions" : "0660",
          "uid" : "system",
          "gid" : "system",
          "option" : [
              "SOCKET_OPTION_PASSCRED",
              "SOCKET_OPTION_RCVBUFFORCE",
              "SOCK_CLOEXEC",
              "SOCK_NONBLOCK"
          ]
      }],
      "critical" : [ 0, 5, 15],
      "ondemand" : true,
      "start-mode" : "condition"
     }]
   ```

   **表4**  socket字段说明
   |字段名 | 说明 |
   | -------- | -------- |
   |name|当前socket的命名，不要求必须与服务同名，与服务名同样须满足非空且长度<=32字节。|
   |family|socket所属的地址族，目前支持的为服务创建的socket有AF_UNIX和AF_NETLINK族。|
   |type|socket的类型，目前支持的类型有基于连接的SOCK_SEQPACKET和SOCK_STREAM，还有基于UDP无连接的SOCK_DGRAM。|
   |protocol|socket通信遵循的协议类型，在无特殊需求的情况下，该值可配置为default缺省值，因为socket接口会自动根据socket地址族和类型选择合适的协议。此处除了default，并且支持NETLINK_KOBJECT_UEVENT协议类型。|
   |permissions|socket节点文件的权限。此项配置仅对如AF_UNIX地址族等有实体节点文件的socket类型有效。|
   |uid|socket节点文件的用户ID。此项配置仅对如AF_UNIX地址族等有实体节点文件的socket类型有效。|
   |gid|socket节点文件的组ID。此项配置仅对如AF_UNIX地址族等有实体节点文件的socket类型有效。|
   |option|socket的可选配置。在调用setsockopt接口时传入设置，目前支持的option选项有SOCKET_OPTION_PASSCRED、SOCKET_OPTION_RCVBUFFORCE、SOCK_CLOEXEC和SOCK_NONBLOCK。|

    **表5**  FD代持接口介绍<a name="table14737791479"></a>

   | 函数名     | 函数解释 |参数解释  |
   | ----------  |  ----------  |--------|
   | int *ServiceGetFd(const char *serviceName, size_t *outfdCount) | 获取init代持的fd | 返回值：成功返回fd数组指针，失败返回NULL。备注：需手动释放<br>参数：<br> serviceName: 服务名<br>outfdCount: 返回的fd数组长度 |
   | int ServiceSaveFd(const char *serviceName, int *fds, int fdCount) | 请求init代持fd | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 <br> fds: 需要init代持的fd数组指针<br>fdCount: fd数组长度
   | int ServiceSaveFdWithPoll(const char *serviceName, int *fds, int fdCount)  | 使用poll方式，请求fd代持 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 <br> fds: fd代持数组指针  <br> fdCount 数组长度

    **表6**  服务控制接口介绍

   | 函数名     | 函数解释 |参数解释  |
   | :----------  |  :----------  |:--------|
   | int ServiceControlWithExtra(const char *serviceName, int action, const char *extArgv[], int extArgc) | 配置服务参数 | 返回值：成功返回0，失败返回-1 <br> 参数: <br> serviceName: 服务名 <br> action: 服务行为（"start", "stop", "restart"） <br> extArgv: 参数数组 <br> extArgc: 参数个数 |
   | int ServiceControl(const char *serviceName, int action)  | 控制服务行为 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 <br> action: 服务行为（"start"， "stop", "restart") |
   | int ServiceWaitForStatus(const char *serviceName, ServiceStatus status, int waitTimeout) | 等待服务状态 | 返回值：成功返回0， 失败返回-1。<br> 参数：<br>serviceName: 服务名 <br> status: 返回服务状态 <br> 超时时间 |
   | int ServiceSetReady(const char *serviceName) | 设置服务准备 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 |
   | int StartServiceByTimer(const char *serviceName, uint64_t timeout) | 定时启动服务 | 返回值：成功返回0，失败返回-1 <br> 参数: <br> serviceName: 服务名 <br> timeout: 超时时间 |
   | int StopServiceTimer(const char *serviceName)  | 停止服务计时器 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 |

    **表7**  begetctl 命令说明<a name="table14737791480"></a>

   | 命令 | 命令格式和示例 | 说明 |
   | :----------  |  :----------  |:--------|
   | init group test [stage] | init group test | statge参见ServiceStatus |
   | param ls [-r] [name] | 显示系统参数，例如：<br>查看usb系统参数：begetctl param ls persist.sys.usb    | 无 |
   | param get [name] | 获取系统参数信息，例如：<br>begetctl param get 或 param get | 无 |
   | param set name value| 设置系统参数，例如：<br>begetctl param set ohos.servicectrl.display 1 或 param set ohos.servicectrl.display 1| 无 |
   | param wait name [value] [timeout] | 等待系统参数，例如：<br>begetctl param wait persist.sys.usb.config hdc 或 param wait persist.sys.usb.config hdc | timeout默认值：30 |
   | param dump [verbose] | dump 系统参数信息，例如：<br>begetctl param dump 或 param dump| 无 |
   | param shell [name] | 进入Parameter shell，例如：<br>begetctl param shell 或 param shell| 无 |
   | timer_stop servicename | 停止服务计时器，例如：<br>begetctl timer_stop appspawn | servicename长度不超过96字符 |
   | timer_start servicename timeout | 启动服务计时器，例如：<br>begetctl timer_start appspawn | servicename长度不超过96；timeout默认值：10 |
   | start_service servicename | 启动服务，例如：<br>begetctl start_service appspawn 或 start_service appspawn | 无 |
   | stop_service servicename | 停止服务，例如：<br>begetctl stop_service appspawn 或 stop_service appspawn | 无 |
   | service_control start servicename | 启动服务，例如：<br>begetctl service_control start appspawn 或 service_control start appspawn | 无 |
   | service_control stop servicename | 停止服务，例如：<br>begetctl service_control stop appspawn 或 service_control stop appspawn  | 无 |
   | misc_daemon --write_logo xxx.rgb | 写入开机logo，例如：<br>begetctl misc_daemon --write_logo logo.rgb 或 misc_daemon --write_logo logo.rgb| rgb文件最大不超过1024*2038，仅支持hi3516dv300 |
   | reboot | 重启系统，例如：<br>begetctl reboot 或 reboot|无 |
   | reboot shutdown | 关闭系统，例如：<br>begetctl reboot shutdown 或 reboot shutdown |无 |
   | reboot suspend | 暂停系统，例如：<br>begetctl reboot suspend 或 reboot suspend | 无 |
   | reboot updater | 重新启动并进入updater，例如：<br>begetctl reboot updater 或 reboot updater | 无 |
   | reboot updater[:options] | 重新启动并进入updater，例如：<br>begetctl reboot updater 或 reboot updater | 无 |
   | reboot flashd | 重新启动并进入flashd，例如：<br>begetctl reboot flashd 或 reboot flashd | 无 |
   | reboot flashd[:options] | 重新启动并进入flashd，例如：<br>begetctl reboot flashd 或 reboot flashd | 无 |
   | reboot charing | 重新启动并进入charing，例如：<br>begetctl reboot charing 或 reboot charing| 无 |
   | reboot loader | 重新启动并进入烧写模式，例如：<br>begetctl reboot loader 或 reboot loader | 无 |
   | bootchart stop | 停止图形分析，例如：<br>begetctl bootchart stop | 仅支持rk3568|
   | bootchart start | 开始图形分析，例如：<br>begetctl bootchart start | 无 |
   | bootchart disable | 图形分析不使能，例如：<br>begetctl bootchart disable | 无 |
   | bootchart enable | 图形分析使能，例如：<br>begetctl bootchart enable | 无 |

## 开发实例

init启动引导程序，此处以要新增一个名为MySystemApp的系统服务为例进行说明，使用如下配置：

  ```
{
    "jobs" : [{
    "name" : "pre-init",
    "cmds" : [
        "mkdir /storage/MyDir",      // MySystemApp服务启动之前需要先创建文件夹，因此放在 “pre-init”中进行
       "chmod 0600 /storage/MyDir",          // MySystemApp服务要求该文件夹只有本用户和属组才可读写，因此需要修改权限
       "chown 10 10 /storage/MyDir"
      ]
}, {
       "name" : "init",
       "cmds" : [
           "start MySystemApp"         // 在“init”中启动该系统服务
        ]
}, {
     "name" : "post-init",
     "cmds" : []                     // MySystemApp系统服务启动后无需进行其他操作，因此不用配置“post-init”
   }
],
    "services" : [{
        "name" : "MySystemApp",       //  系统服务名称
        "path" : ["/bin/MySystemAppExe", "param1", "param2", "param3"],    // MySystemApp系统服务的可执行文件路径为"/bin/MySystemAppExe"，其启动需要传入三个参数，分别是"param1"、"param2"和"param3
        "uid" : 20,         //  MySystemApp系统服务的uid是20
        "gid" : 20,         //  MySystemApp系统服务的gid是20
        "once" : 0,         //  MySystemApp系统服务的非一次性进程，即如果MySystemApp系统服务因任何原因退出，init进程需要将其重新拉起
        "importance" : 0,    //  MySystemApp系统服务不是关键系统进程，即如果MySystemApp系统服务因任何原因退出，init进程无需重启单板
        "caps" : [],           //  MySystemApp系统服务不需要任何capability权限（即MySystemApp系统服务不涉及与capability相关的操作）
        "start-mode" : "condition",
        "critical": [1, 2, 10],   //MySystemApp系统服务的critical配置，需传入三个参数， 分别为使能：1， 执行次数：2， 执行时间：10
        "cpucore" : [0, 1],  // 设备为双核， 且都绑定cpu
        "apl" : "system_core",
        "d-caps" : ["OHOS_DMS"],
        "jobs" : {
            "on-boot" : "boot",
            "on-start" : "services:MySystemApp_start",
            "on-stop" : "services:MySystemApp_stop",
            "on-restart" : "services:MySystemApp_restart"
        }
     }
     ]
}
  ```

完成配置后，编译出包烧写单板：

1. 启动后使用task -a（liteos-a版本）或ps命令（linux版本）查看是否MySystemApp系统服务进程已启动。

2. 使用kill命令将上述新增的MySystemApp进程杀死，观察该进程是否会被重新拉起（此处应该为重新拉起）。

3. 使用kill命令将上述新增的MySystemApp进程杀死，观察是否会导致单板重启（此处应该为不重启）。


## 常见问题


### 服务不存在

**现象描述**

内核Log打印 "Failed get servName"。

**原因分析**

kernel log 的输出，都是由init 打印。在init 中查找对应的代码位置。发现是服务不存在。

**解决方法**

1. 确认服务是否在cfg中正确配置。

2. 服务的cfg文件是否正常加载。

3. cfg文件格式是否正确。


### 请求其他服务代持fd，init有报错

**现象描述**

内核Log打印 "Service ' xxx '(pid = xxx) is not valid or request with unexpected process(pid = xxx)"。

**原因分析**

kernel log 的输出，都是由init 打印。在init 中查找对应的代码位置。发现是其他服务代持fd。

**解决方法**

只支持代持本服务的fd， 不允许让其他服务代持fd。


### 服务没有配置ondemand 选项

**现象描述**

内核Log打印 "service : %s had started already"。

**原因分析**

kernel log 的输出，都是由init 打印。在init 中查找对应的代码位置。发现是服务没有配置ondemand。

**解决方法**

服务对应的.cfg文件正确配置如： "ondemand" : true。
