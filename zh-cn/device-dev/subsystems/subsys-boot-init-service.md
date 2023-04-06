# 服务管理
## 概述
### 功能简介
服务配置支持按需配置服务，并根据业务场景，支持多种增值服务。当前支持的增值服务包括启动控制、按需启动、命令执行、定时启动、fd代持、**[沙盒](subsys-boot-init-sandbox.md)**。

### 基本概念

- init服务参数选项列表

  参见[service字段说明](#table14737791471)。

- init服务启动控制(仅标准系统以上提供)<a name = "section56901555918">

  init会根据用户的服务配置，把服务分成三类，在不同的阶段并行启动。

  - “boot”类型：对应系统中需要优先启动的服务，该类服务在“init”阶段启动。
  - “normal”类型：默认配置，对应系统中的普通服务，该类服务在“post-init"阶段启动。
  - “condition”类型：必须通过启动命令启动，通过在jobs中添加“start xxxx”来启动对应服务。

- init服务支持命令执行(仅标准系统以上提供)<a name="section56901555919"></a>

  init提供服务命令执行能力，在服务执行的不同阶段执行不同的命令。

  - "on-start"：在服务进程被fork后在子进程中执行，只对该进程产生影响。
  - "on-stop"：在服务停止时执行，在init进程中执行。
  - "on-restart"：在服务重启时执行，在init进程中执行。

  参考配置如下：
  ```
  "services" : [{
        "name" : "serviceName",
        "path" : ["/system/bin/serviceName"]
        "jobs" : {
            "on-boot" : "boot",
            "on-start" : "services:serviceName_start",
            "on-stop" : "services:serviceName_stop",
            "on-restart" : "services:serviceName_restart"
       }
  },
  ```
  
  通过并行启动和命令执行能力，可以实现进程的并行启动。
  
- init按需启动(仅标准系统以上提供) <a name="section56901555920">

  配置按需启动后，init进程不会启动对应的服务，只有服务被需要时才会被拉起。通过"ondemand"标记来控制服务是否被拉起。

  “ondemand”参考配置如下：
  ```
    "services" : [{
      "name" : "serviceName",
      "path" : ["/system/bin/serviceName"]
      "ondemand" : true
  }]
  ```
    - SA进程按需启动

        具体参考 **[samgr组件(说明3)](https://gitee.com/openharmony/systemabilitymgr_samgr/blob/master/README_zh.md)**。
        
    - socket进程按需启动
        1. init进程在pre-fork阶段为socket类进程创建好socket，init进程中监听创建好的socket上的读写事件。
        2. socket上有读写事件后，init进程拉起socket进程对应的native服务，并取消对socket的监听，将socket交由相应的native服务管理。
        3. native服务无报文处理后，可以自动退出。init进程在回收子进程时会根据服务配置重新监听socket。
  
    - 热插拔服务进程按需启动

      进程可根据系统参数的变化进行热插拔事件按需启动处理。

- init进程启动&amp;回收能力增强

  进程启动时，支持在配置文件中配置服务进程的绑核、优先级、MAC信息以及AccessToken信息。

  - init提供修改\*.cfg配置文件，为服务进程提供CPU绑核功能。
  - init提供修改\*.cfg配置文件，为服务进程提供优先级设置。
  - init提供修改\*.cfg配置文件，为服务提供MAC信息设置，即服务的SELinux标签（需要selinux支持）。
  - init提供修改\*.cfg配置文件，为服务提供设置AccessToken, 为系统服务进程设置其分布式Capability能力（仅标准系统以上提供）。
  - init提供修改\*.cfg配置文件，为服务提供抑制机制。

  服务进程启动&回收能力增强配置，如下：
    ```
    "services" : [{
        "name" : "serviceName",
        "path" : ["/system/bin/serviceName"]
        "importance" : 1,                  // 服务进程提供优先级设置
        "cpucore" : [0],                   // 服务进程提供CPU绑核功能
        "critical" : [1, 5, 10],           // 服务提供抑制机制
        "apl" : "normal",                  // 系统服务进程设置其分布式Capability能力
        "d-caps" : ["OHOS_DMS"],           // 系统服务进程设置其分布式Capability能力
        "secon" : "u:r:distributedsche:s0" // 服务的SELinux标签， "u:r:distributedsche:s0"为要设置的SELinux标签信息
    }
    ```

- 添加selinux标签

  服务配置selinux策略，需要通过"secon"为服务添加selinux标签。例如为watchdog_service添加selinux标签，如下:

    ```
    "services" : [{
              "name" : "watchdog_service",
              "secon" : "u:r:watchdog_service:s0"
    }]
    ```
    对应的需要在selinux中定义此标签，定义方法与配置文件参照selinux指导文档

- init FD代持（仅标准系统以上提供）

  FD代持是按需启动的一个辅助扩展机制，按需启动进程可以保持退出前的fd状态句柄不丢失。按需启动进程退出前可将fd发送给init代持，再次启动后再从init获取fd。

  init提供了相关接口供服务调用，服务进程退出前调用接口将fd通过支持IPC通信的socket发送给init代持，待该服务重新启动时，init将持有的该服务相关的fd句柄通过同样的方式返回给服务。相关接口参考：[FD代持接口介绍](#table14737791479)。
  
- 定时启动

  通过约定时间拉起服务， 若服务已拉起， 则不在重新拉起服务。具体命令参考： **[begetctl命令说明](subsys-boot-init-plugin#参数说明)** 。
  ```
  timer_start servicename timeout
  ```
- 沙盒

  具体参考 **[沙盒指导](subsys-boot-init-sandbox.md)**。

### 约束与限制

仅限小型系统、标准系统下使用。

## 开发指导
### 场景介绍
通过对*.cfg文件的解析， 获取service中的属性， 设置并启动service。

### 参数说明
   **表1**  service字段说明<a name="table14737791471"></a>
   | 字段名 | 支持系统类型 | 字段说明 | 字段解释 |
   | ---------- |-------- | --------| --------|
   | name          | 小型系统和标准系统  | 当前服务的服务名。(必选) |  类型：字符串； 服务名非空且长度<=32字节。|
   | path          | 小型系统和标准系统 | 当前服务的可执行文件全路径和参数，数组形式。 (必选) | 确保第一个数组元素为可执行文件路径、数组元素个数<=20。 <br> 每个元素为字符串形式以及每个字符串长度<=64字节。|
   | uid           | 小型系统和标准系统 | 当前服务进程的uid值。 | 类型：int、字符串。 |
   | gid           | 小型系统和标准系统 | 当前服务进程的gid值。 | 类型：int、int[]、字符串、字符串数组。 |
   | once          | 小型系统和标准系统 | 当前服务进程是否为一次性进程。 | 1：一次性进程，当该进程退出时，init不会重新启动该服务进程。 <br>0 : 常驻进程，当该进程退出时，init收到SIGCHLD信号并重新启动该服务进程。 |
   | importance    | 小型系统和标准系统 | <br>标准系统：当前服务优先级<br>小型系统：标记服务重要性 | <br>标准系统中: 服务优先级取值范围 [-20， 19]，超出为无效设置。<br>小型系统中：0 : 不重启系统；非0 : 重启系统 |
   | caps          | 小型系统和标准系统 | 当前服务所需的capability值，根据安全子系统已支持的capability，评估所需的capability，遵循最小权限原则配置。| 类型：数字或者字符串数组，在配置数字时，按linux标准的capability进行配置。字符串时，使用标准定义的宏的名字进行配置。 |
   | critical      | 标准系统 | 为服务提供抑制机制，服务在配置时间 T 内，频繁重启次数超过设置次数 N 重启系统。 | <br>标准系统中： 类型：int[]，如："critical" : [M, N, T]，<br>其中M：使能标志位（0：不使能；1：使能）， N：频繁拉起服务次数， T：时间(单位：秒)。M > 0; N > 0。 <br> 小型系统中 & 标准系统中：类型：int，如："critical" : M，<br>其中 M：使能标志位（0：不使能；1：使能）。 默认拉起服务次数：4次， 时间：20秒 。|
   | cpucore      | 标准系统 | 服务需要的绑定的CPU核心数 | 类型：int型数组， 如"cpucore" : [N1, N2, ...], N1， N2均为需要绑定的cpu核索引， 如单核设备 cpucore : [0]。 |
   | d-caps       | 标准系统 | 服务分布式能力。| 类型：字符串数组， 如 "d-caps" : ["OHOS_DMS"]。 |
   | apl          | 标准系统 | 服务能力特权级别。 | 类型：字符串， 如 "apl" : "system_core"。<br> 目前支持"system_core"（默认值）, "normal", "system_basic"。 |
   | start-mode   | 标准系统 | 服务的启动模式。 | 类型：字符串， 如 "start-mode" : "condition"。<br>目前支持"boot", "normal", "condition"。具体说明参考：[init服务启动控制](#section56901555918)。 |
   | ondemand     | 小型系统和标准系统 | 按需启动服务的标志。 | 类型：bool，如"ondemand" : true，小型系统只在Linux内核上支持。<br>具体说明参考：[init服务按需启动](#section56901555920)。|
   | disable | 小型系统和标准系统 | 预留字段，无实际意义。 | 无。 |
   | sandbox | 标准系统 | 沙盒功能是否打开。 | 1：打开服务的沙盒功能 （默认值）。<br>0：关闭服务的沙盒功能。 |

   **表2**  socket字段说明
   | 字段名 | 说明 |
   | -------- | -------- |
   | name | 当前socket的命名，不要求必须与服务同名，与服务名同样须满足非空且长度<=32字节。|
   | family | socket所属的地址族，目前支持的为服务创建的socket有AF_UNIX和AF_NETLINK族。|
   | type | socket的类型，目前支持的类型有基于连接的SOCK_SEQPACKET和SOCK_STREAM，还有基于UDP无连接的SOCK_DGRAM。|
   | protocol | socket通信遵循的协议类型，在无特殊需求的情况下，该值可配置为default缺省值，因为socket接口会自动根据socket地址族和类型选择合适的协议。此处除了default，并且支持NETLINK_KOBJECT_UEVENT协议类型。|
   | permissions | socket节点文件的权限。此项配置仅对如AF_UNIX地址族等有实体节点文件的socket类型有效。|
   | uid | socket节点文件的用户ID。此项配置仅对如AF_UNIX地址族等有实体节点文件的socket类型有效。|
   | gid | socket节点文件的组ID。此项配置仅对如AF_UNIX地址族等有实体节点文件的socket类型有效。|
   | option | socket的可选配置。在调用setsockopt接口时传入设置，目前支持的option选项有SOCKET_OPTION_PASSCRED、SOCKET_OPTION_RCVBUFFORCE、SOCK_CLOEXEC和SOCK_NONBLOCK。|

### 接口说明
  **表3**  FD代持接口介绍<a name="table14737791479"></a>
   | 函数名     | 函数解释 | 参数解释  |
   | ---------- |  ----------  |--------|
   | int *ServiceGetFd(const char *serviceName, size_t *outfdCount) | 获取init代持的fd | 返回值：成功返回fd数组指针，失败返回NULL。备注：需手动释放<br>参数：<br> serviceName: 服务名<br>outfdCount: 返回的fd数组长度 |
   | int ServiceSaveFd(const char *serviceName, int *fds, int fdCount) | 请求init代持fd | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 <br> fds: 需要init代持的fd数组指针<br>fdCount: fd数组长度
   | int ServiceSaveFdWithPoll(const char *serviceName, int *fds, int fdCount)  | 使用poll方式，请求fd代持 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 <br> fds: fd代持数组指针  <br> fdCount 数组长度

  **表4**  服务控制接口介绍
   | 函数名 | 函数解释 | 参数解释 |
   | :----------  |  :----------  |:--------|
   | int ServiceControlWithExtra(const char *serviceName, int action, const char *extArgv[], int extArgc) | 配置服务参数 | 返回值：成功返回0，失败返回-1 <br> 参数: <br> serviceName: 服务名 <br> action: 服务行为（"start", "stop", "restart"） <br> extArgv: 参数数组 <br> extArgc: 参数个数 |
   | int ServiceControl(const char *serviceName, int action)  | 控制服务行为 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 <br> action: 服务行为（"start"， "stop", "restart") |
   | int ServiceWaitForStatus(const char *serviceName, ServiceStatus status, int waitTimeout) | 等待服务状态 | 返回值：成功返回0， 失败返回-1。<br> 参数：<br>serviceName: 服务名 <br> status: 返回服务状态 <br> 超时时间 |
   | int ServiceSetReady(const char *serviceName) | 设置服务准备 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 |
   | int StartServiceByTimer(const char *serviceName, uint64_t timeout) | 定时启动服务 | 返回值：成功返回0，失败返回-1 <br> 参数: <br> serviceName: 服务名 <br> timeout: 超时时间 |
   | int StopServiceTimer(const char *serviceName)  | 停止服务计时器 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 |
-  服务控制接口的DAC配置

   服务控制接口配置DAC，需要修改/base/startup/init/services/etc/group文件，在组servicectrl中添加对应的用户id，例如：

   ```java
   servicectrl:x:1050:root,shell,system,samgr,hdf_devmgr
   ```

-  服务控制接口的selinux配置

   服务控制接口配置selinux，需要在init.te文件中添加该服务接口所需要的selinux权限，例如为init、samgr、hdf_devmgr等服务配置系统参数写权限：

   ```java
   allow { init samgr hdf_devmgr } servicectrl_param:parameter_service { set };
   ```

### 开发步骤
   此处以要新增一个名为MySystemApp的系统服务为例进行说明，使用如下配置：

```
{
    "jobs" : [{
    "name" : "pre-init",
    "cmds" : [
        "mkdir /storage/MyDir",       // MySystemApp服务启动之前需要先创建文件夹，因此放在 “pre-init”中进行
        "chmod 0600 /storage/MyDir",  // MySystemApp服务要求该文件夹只有本用户和属组才可读写，因此需要修改权限
        "chown 10 10 /storage/MyDir"
        ]
}, {
      "name" : "init",
      "cmds" : [
          "start MySystemApp"         // 在init中启动该系统服务
      ]
}, {
    "name" : "post-init",
    "cmds" : []                       // MySystemApp系统服务启动后无需进行其他操作，因此不用配置“post-init”
    }
],
    "services" : [{
        "name" : "MySystemApp",       // 系统服务名称
        "path" : ["/bin/MySystemAppExe", "param1", "param2", "param3"],    // MySystemApp系统服务的可执行文件路径为"/bin/MySystemAppExe"，其启动需要传入三个参数，分别是"param1"、"param2"和"param3
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
        "uid" : 20,                   // MySystemApp系统服务的uid是20
        "gid" : 20,                   // MySystemApp系统服务的gid是20
        "once" : 0,                   // MySystemApp系统服务的非一次性进程，即如果MySystemApp系统服务因任何原因退出，init进程需要将其重新拉起
        "importance" : 0,             // MySystemApp系统服务不是关键系统进程，即如果MySystemApp系统服务因任何原因退出，init进程无需重启单板
        "caps" : [],                  // MySystemApp系统服务不需要任何capability权限（即MySystemApp系统服务不涉及与capability相关的操作）
        "start-mode" : "condition",
        "critical": [1, 2, 10],       //MySystemApp系统服务的critical配置，需传入三个参数， 分别为使能：1， 执行次数：2， 执行时间：10
        "cpucore" : [0, 1],           // 设备为双核， 且都绑定cpu
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

kernel日志打印 "Failed get servName"。

**原因分析**

在init中查找对应的代码位置，发现是服务不存在。

**解决方法**

1. 确认服务是否在cfg中正确配置。
2. 服务的cfg文件是否正常加载。
3. cfg文件格式是否正确。

### 请求其他服务代持fd，init有报错

**现象描述**

kernel日志打印 "Service ' xxx '(pid = xxx) is not valid or request with unexpected process(pid = xxx)"。

**原因分析**

kernel日志打印，都是由init 打印。在init中查找对应的代码位置。发现是其他服务代持fd。

**解决方法**

只支持代持本服务的fd，不允许让其他服务代持fd。