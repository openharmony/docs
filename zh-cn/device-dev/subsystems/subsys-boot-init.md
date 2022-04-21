# init启动引导组件


## 功能说明

init启动引导组件负责在系统启动阶段启动关键服务进程。 若用户需要新增随开机自启动的系统服务，可添加新的配置文件xxx.cfg，系统会自动分析对应的cfg文件，并按照cfg文件启动对应的服务。

- init启动引导的配置文件
  init启动引导组件配置文件包含了所有需要由init进程启动的系统关键服务的服务名、可执行文件路径、权限和其他信息，烧写单板后可在“/etc/“目录下找到，文件名称为init.cfg，采用json格式，文件大小目前限制在100KB以内。

  init进程启动后读取/etc/init.cfg，然后解析其json格式内容，并根据解析结果依次加载系统服务。

  各模块需要添加关键服务时，也可以添加模块对应的cfg文件，编译时拷贝文件到/system/etc/init目录下，init进程会解析改cfg文件，并启动对应的服务。

- init服务启动控制(仅标准系统以上提供)
  init会根据用户的服务配置，把服务分成三类，在不同的阶段进行启动。

  - “boot”类型：对应系统中需要优先启动的服务，这类服务在init完成init阶段后启动。
  - “normal”类型：默认配置，对应系统中的普通服务，这类服务在init命令执行完成后启动。
  - “condition”类型：对应有特殊要求的服务，可以直接通过start xxx 命令执行启动，一般在条件job或者在init的某个阶段使用命令启动。

  服务间或服务与命令之间存在依赖关系，需要通过"condition"描述服务，例如：

  
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
        "d-caps" : ["OHOS_DMS"]
        "jobs" : {
            "on-boot" : "boot",
            "on-start" : "services:service1_start",
            "on-stop" : "services:service1_stop",
            "on-restart" : "services:service1_restart"
       }
    },
  ```

- init服务并行控制(仅标准系统以上提供)
  init提供服务并行处理能力，启动服务在不同的阶段执行job的能力。

  - “on-start”：在服务进程被fock后执行，不同服务的on-start job可以并行执行（在服务的子进程中执行，只对改进程产生影响）。
  - “on-stop”：在服务停止时执行。
  - “on-restart”：在服务重启时执行。

- init 按需启动(仅标准系统以上提供)
  由init管理的服务支持按需启动，按需启动的服务不会在系统启动过程中主动被拉起，而是当某些事件发生时才会被init按需拉起，触发服务启动的事件可能是被init监听的相关socket有消息上报、samgr收到客户端的请求需要拉起SA服务等情况。

  "ondemand" ：按需启动服务的标志，一个服务配置了该属性值为true的时候，服务不再需要配置start命令来拉起，而是被监听的相应事件发生时才会被拉起。

  - SA进程按需启动
     1. 应用请求SA句柄时samgr需识别SA所属进程是否可动态拉起。
     2. 如需拉起，则需阻塞请求，等init拉起SA进程并注册SA后再返回所请求的SA句柄。
  - socket进程按需启动
     1. init在pre-fork阶段为socket类进程创建好socket，init中监听创建好的socket上的网络事件。
     2. socket上有报文事件后，init拉起socket进程进行报文处理，init进程取消socket数据的监听，由socket进程处理。
     3. socket进程无报文处理后，可以自动退出，退出后init回收该子进程并重新监听socket网络数据。
  - 热插拔服务进程按需启动  进程可根据系统参数的变化进行热插拔事件按需启动处理。

- init 进程启动&amp;回收能力增强
  进程启动时，支持在配置文件中配置服务进程的绑核、优先级、MAC信息以及AccessToken信息。

  - init提供修改\*.cfg配置文件， 为服务进程提供cpu绑核功能。
  - init提供修改\*.cfg配置文件， 为服务进程提供优先级设置。
  - init提供修改\*.cfg配置文件， 为服务提供设置AccessToken, 为系统服务进程设置其分布式Capability能力（仅标准系统以上提供）。
  - init提供修改\*.cfg配置文件， 为服务提供抑制机制。

- init FD代持(仅标准系统以上提供)
  FD代持是按需启动的一个辅助扩展机制，按需启动进程可以保持退出前的fd状态句柄不丢失。按需启动进程退出前可将fd发送给init代持，再次启动后再从init获取fd。

  init提供了相关接口供服务调用，服务进程退出前调用接口将fd通过支持IPC通信的socket发送给init代持，待该服务重新启动时，init将持有的该服务相关的fd句柄通过同样的方式返回给服务。

- init job
  init提供job能力，一个job就是一组命令的集合。job可以在init.cfg中配置，也可以在模块的自定义cfg中配置。init解析程序会把相同名字job的命令合并到一个job中。同一名字的job只能保证init.cfg中的命令优先执行，其他cfg间的命令执行顺序不保证。

  - 普通job：一般是init启动的固定阶段，如“pre-init“，”init“，”post-init“等，这类job在init启动的固定阶段执行。
  - 自定义job：用户自定义的job，这类job按照一定的规则进行触发。
     - job：用户任意定义，可以通过trigger命令执行。
     - 控制job(仅标准系统以上提供)：按条件触发处理的能力。在job中可以设置触发条件，当对应的属性值满足设置的条件时，就会触发job执行。触发条件支持&amp;&amp;和||操作，可以根据不同的属性就行组合。


## 开发指导

1. 配置jobs数组。
   init启动引导组件将系统启动分为三个阶段：

   - “pre-init”阶段：启动系统服务之前需要先执行的操作，例如挂载文件系统、创建文件夹、修改权限等。
   - “init”阶段：系统服务启动阶段。
   - “post-init”阶段：系统服务启动完后还需要执行的操作。

     
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
   | -------- | -------- |
   | pre-init | 最先执行的job，如果开发者的进程在启动之前需要首先执行一些操作（例如创建文件夹），可以把操作放到pre-init中先执行。 |
   | init | 中间执行的job，例如服务启动。 |
   | post-init | 最后被执行的job，如果开发者的进程在启动完成之后需要有一些处理（如驱动初始化后再挂载设备），可以把这类操作放到该job执行。单个job最多支持30条命令（当前仅支持start/mkdir/chmod/chown/mount/loadcfg），命令名称和后面的参数（参数长度≤128字节）之间有且只能有一个空格。 |

     **表2** 命令集说明
   
   | 命令 | 命令格式和示例 | 说明 |
   | -------- | -------- | -------- |
   | mkdir | mkdir&nbsp;目标文件夹<br/>如：mkdir&nbsp;/storage/myDirectory | 创建文件夹命令，mkdir和目标文件夹之间有且只能有一个空格。 |
   | chmod | chmod&nbsp;权限&nbsp;目标<br/>如：chmod&nbsp;0600&nbsp;/storage/myFile.txt<br/>chmod&nbsp;0750&nbsp;/storage/myDir | 修改权限命令，chmod权限目标之间间隔有且仅有一个空格，权限必须为0xxx格式。 |
   | chown | chown&nbsp;uid&nbsp;gid&nbsp;目标<br/>如：chown&nbsp;900&nbsp;800&nbsp;/storage/myDir<br/>chown&nbsp;100&nbsp;100&nbsp;/storage/myFile.txt | 修改属组命令，chown&nbsp;uid&nbsp;gid目标之间间隔有且仅有一个空格。 |
   | mount | mount&nbsp;fileSystemType&nbsp;src&nbsp;dst&nbsp;flags&nbsp;data<br/>如：mount&nbsp;vfat&nbsp;/dev/mmcblk0&nbsp;/sdc&nbsp;rw,umask=000<br/>mount&nbsp;jffs2&nbsp;/dev/mtdblock3&nbsp;/storage&nbsp;nosuid | 挂载命令，各参数之间有且仅有一个空格。flags当前仅支持nodev、noexec、nosuid、rdonly，data为可选字段。 |
   | start | start&nbsp;serviceName<br/>如：start&nbsp;foundation<br/>start&nbsp;shell | 启动服务命令，start后面跟着service名称，该service名称必须能够在services数组中找到。 |
   | loadcfg | loadcfg&nbsp;filePath<br/>如：loadcfg&nbsp;/patch/fstab.cfg | 加载其他cfg文件命令。后面跟着的目标文件大小不得超过50KB，且目前仅支持加载/patch/fstab.cfg，其他文件路径和文件名均不支持。/patch/fstab.cfg文件的每一行都是一条命令，命令类型和格式必须符合本表格描述，命令条数不得超过20条。 |

2. 配置services数组，service集合（数组形式），包含了init进程需要启动的所有系统服务（最多支持100个）。
  
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
           "d-caps" : ["OHOS_DMS"]
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

     **表3** service字段说明
   
   | 字段名 | 说明 |
   | -------- | -------- |
   | name | 当前服务的服务名，须确保非空且长度&lt;=32字节。 |
   | path | 当前服务的可执行文件全路径和参数，数组形式。须确保第一个数组元素为可执行文件路径、数组元素个数&lt;=20、每个元素为字符串形式以及每个字符串长度&lt;=64字节。 |
   | uid | 当前服务进程的uid值。 |
   | gid | 当前服务进程的gid值。 |
   | once | 当前服务进程是否为一次性进程：<br/>1：一次性进程，当该进程退出时，init不会重新启动该服务进程<br/>0&nbsp;:&nbsp;常驻进程，当该进程退出时，init收到SIGCHLD信号并重新启动该服务进程；<br/>注意，对于常驻进程，若在4分钟之内连续退出5次，第5次退出时init将不会再重新拉起该服务进程。 |
   | importance | 标准系统中：服务进程优先级，&nbsp;取值范围[-20，&nbsp;19];小型系统中：0&nbsp;:&nbsp;非重要进程1&nbsp;:&nbsp;重要进程 |
   | caps | 当前服务所需的capability值，根据安全子系统已支持的capability，评估所需的capability，遵循最小权限原则配置（当前最多可配置100个值）。 |
   | critical | critical服务启动失败后，&nbsp;需要M秒内重新拉起，&nbsp;拉起失败N次后，&nbsp;直接重启系统，&nbsp;N默认为4，&nbsp;M默认20。（仅标准系统以上提供&nbsp;"critical"&nbsp;:&nbsp;[0,&nbsp;2,&nbsp;10];&nbsp;类型为int型数组)。<br/>0：不使能；<br/>1：使能。 |
   | cpucore | 服务需要的绑定的cpu核心数，&nbsp;类型为int型数组。 |
   | d-caps | 分布式能力&nbsp;(仅标准系统以上提供)。 |
   | apl | 能力特权级别：system_core,&nbsp;normal,&nbsp;system_basic。&nbsp;默认system_core&nbsp;(仅标准系统以上提供)。 |
   | start-mode | 服务的启动模式，具体描述：init服务启动控制(仅标准系统以上提供)。 |
   | jobs | 当前服务在不同阶段可以执行的job。具体说明可以看：init服务并行控制(仅标准系统以上提供)。 |

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
      "critical" : [ 0, 15, 5],
      "ondemand" : true,
      "start-mode" : "condition"
     }]
   ```
   **表4**socket字段说明
   |字段名 | 说明 |
   | -------- | -------- |
   |name|当前socket的命名，不要求必须与服务同名，与服务名同样须满足非空且长度<=32字节。|
   |family|socket所属的地址族，目前支持的为服务创建的socket有AF_UNIX和AF_NETLINK族。|
   |type|socket的类型，目前支持的类型有基于连接的SOCK_SEQPACKET和SOCK_STREAM，还有基于UDP无连接的SOCK_DGRAM。|
   |protocol|socket通信遵循的协议类型，在无特殊需求的情况下，该值可配置为default缺省值，因为socket接口会自动根据socket地址族和类型选择合适的协议。此处除了default，还支持了NETLINK_KOBJECT_UEVENT协议类型。|
   |permissions|socket节点文件的权限。此项配置仅对如AF_UNIX地址族等有实体节点文件的socket类型有效。|
   |uid|socket节点文件的用户ID。此项配置仅对如AF_UNIX地址族等有实体节点文件的socket类型有效。|
   |gid|socket节点文件的组ID。此项配置仅对如AF_UNIX地址族等有实体节点文件的socket类型有效。|
   |option|socket的可选配置。在调用setsockopt接口时传入设置，目前支持的option选项有SOCKET_OPTION_PASSCRED、SOCKET_OPTION_RCVBUFFORCE、SOCK_CLOEXEC和SOCK_NONBLOCK。|
   
   **表5** 接口介绍
   
   | 函数名 | 函数解释 | 参数解释 |
   | -------- | -------- | -------- |
   | int&nbsp;\*ServiceGetFd(const&nbsp;char&nbsp;\*service<br/>Name,&nbsp;size_t&nbsp;\*outfdCount) | 获取init代持的fd | 返回值：成功返回fd数组指针，失败返回NULL。备注：需手动释放<br/>参数：<br/>serviceName:&nbsp;服务名<br/>outfdCount:&nbsp;返回的fd数组长度 |
   | int&nbsp;ServiceSaveFd(const&nbsp;char&nbsp;\*service<br/>Name,&nbsp;int&nbsp;\*fds,&nbsp;int&nbsp;fdCount) | 请求init代持fd | 返回值：成功返回0，失败返回-1<br/>参数：<br/>serviceName:&nbsp;服务名<br/>fds:&nbsp;需要init代持的fd数组指针<br/>fdCount:&nbsp;fd数组长度 |
   | int&nbsp;ServiceControlWithExtra(const&nbsp;char&nbsp;\*<br/>serviceName,&nbsp;int&nbsp;action,&nbsp;const&nbsp;char&nbsp;\*<br/>extArgv[],&nbsp;int&nbsp;extArgc) | 配置服务参数 | 返回值：成功返回0，失败返回-1<br/>参数:<br/>serviceName:&nbsp;服务名<br/>action:&nbsp;服务行为（"start",&nbsp;"stop",&nbsp;"restart"）<br/>extArgv:&nbsp;参数数组<br/>extArgc:&nbsp;参数个数 |
   | int&nbsp;ServiceControl(const&nbsp;char&nbsp;\*serviceName,<br/>&nbsp;int&nbsp;action) | 控制服务行为 | 返回值：成功返回0，失败返回-1<br/>参数：<br/>serviceName:&nbsp;服务名<br/>action:&nbsp;服务行为（"start"，&nbsp;"stop",&nbsp;"restart") |


## 开发实例

init启动引导程序，此处以要新增一个名为MySystemApp的系统服务为例进行说明，使用如下配置：


```
{
    "jobs" : [{
    "name" : "pre-init",
    "cmds" : [
        "mkdir /storage/MyDir",      // MySystemApp服务启动之前需要先创建文件夹，因此放在 “pre-init”中进行
       "chmod 0600 /storage/MyDir",          // MySystemApp服务要求该文件加只有本用户和属组才可读写，因此需要修改权限
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

内核Log打印 "Service ' xxx '(pid = xxx) is not valid or request with unexpected process(pid = xxx)"。。

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
