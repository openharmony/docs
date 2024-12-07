# 服务管理
## 概述

服务管理主要通过init解析服务进程配置文件来实现，服务进程配置文件(xxx.cfg)可以根据业务场景按需配置服务，当前支持的增值服务包括启动控制、按需启动、命令执行、定时启动、fd代持、沙盒。

## 服务进程配置文件说明

- 服务进程配置文件名：

    一般命名为：serviceName.cfg(serviceName 为服务进程名，例如：appspawn.cfg)

- 服务进程配置文件格式：

    配置文件基于JSON格式，遵循JSON文件的基本规则

- 服务进程配置文件的内容：

    配置文件内容主要包含以下字段，除必配字段外，其他字段根据服务特性选择性配置。

   **表1**  service配置字段说明

   | 字段名 | 配置要求 |支持系统类型 | 字段说明 | 字段解释 |
   | ---------- | ------- | -------- | --------| --------|
   | name          | 必选 | 小型系统和标准系统  | 当前服务的服务名。(必选) |  类型：字符串； 服务名非空且长度<=32字节。|
   | path          | 必选 | 小型系统和标准系统 | 当前服务的可执行文件全路径和参数，数组形式。 (必选) | 确保第一个数组元素为可执行文件路径、数组元素个数<=20。 <br> 每个元素为字符串形式以及每个字符串长度<=64字节。|
   | uid           | 必选 | 小型系统和标准系统 | 当前服务进程的uid值。 | 类型：int、字符串。 |
   | gid           | 必选 | 小型系统和标准系统 | 当前服务进程的gid值。 | 类型：int、int[]、字符串、字符串数组。 |
   | once          | 可选 | 小型系统和标准系统 | 当前服务进程是否为一次性进程。 | 1：一次性进程，当该进程退出时，init不会重新启动该服务进程。 <br>0 : 常驻进程，当该进程退出时，init收到SIGCHLD信号并重新启动该服务进程。 |
   | importance    | 可选 | 小型系统和标准系统 | <br>标准系统：当前服务优先级<br>小型系统：标记服务重要性 | <br>标准系统中: 服务优先级取值范围 [-20， 19]，数值越小优先级越高，超出为无效设置。<br>小型系统中：0 : 不重启系统；非0 : 重启系统 |
   | caps          | 可选 | 小型系统和标准系统 | 当前服务所需的capability值，根据安全子系统已支持的capability，评估所需的capability，遵循最小权限原则配置。| 类型：数字或者字符串数组，在配置数字时，按linux标准的capability进行配置。字符串时，使用标准定义的宏的名字进行配置。 |
   | critical      | 可选 | 小型系统和标准系统 | 为服务提供抑制机制，服务在配置时间 T 内，频繁重启次数超过设置次数 N 重启系统。 | <br> 类型：int[]，如："critical" : [M, N, T]，<br>其中M：使能标志位（0：不使能；1：使能）， N：频繁拉起服务次数， T：时间(单位：秒)。 默认拉起服务次数：4次， 时间：240秒 。|
   | cpucore      | 可选 | 标准系统 | 服务需要的绑定的CPU核心数 | 类型：int型数组， 如"cpucore" : [N1, N2, ...], N1， N2均为需要绑定的cpu核索引， 如单核设备 cpucore : [0]。 |
   | d-caps       | 可选 | 标准系统 | 服务分布式能力。| 类型：字符串数组， 如 "d-caps" : ["OHOS_DMS"]。 |
   | apl          | 可选 | 标准系统 | 服务能力特权级别。 | 类型：字符串， 如 "apl" : "system_core"。<br> 目前支持"system_core"（默认值）, "normal", "system_basic"。 |
   | start-mode   | 可选 | 标准系统 | 服务的启动模式。 | 类型：字符串， 如 "start-mode" : "condition"。<br>目前支持"boot", "normal", "condition"。具体说明参考：init服务启动控制。 |
   | ondemand     | 可选 | 小型系统和标准系统 | 按需启动服务的标志。 | 类型：bool，如"ondemand" : true，小型系统只在Linux内核上支持。<br>具体说明参考：[init服务按需启动](#section56901555920)。|
   | disable | 可选 | 小型系统和标准系统 | 预留字段，无实际意义。 | 无。 |
   | sandbox | 可选 | 标准系统 | 沙盒功能是否打开。 | 1：打开服务的沙盒功能 （默认值）。<br>0：关闭服务的沙盒功能。 |
   | socket | 可选 | 标准系统 | 配置socket属性相关设置 | 由socket创建流程的服务需配置此项 |
   | env | 可选 | 标准系统 | 配置服务的环境变量 | 类型：键值对型数组 <br>支持同时配置多个环境变量，如：<br>"env" : [{<br> "name" : "SERVICE_NALE", <br>"value" : "ueventd"},{<br> "name" : "TEST",<br> "value" : "test_value" <br>}]|
   | period | 可选 | 标准系统 | 配置服务退出后的定时启动 | 类型：int型，表示定时启动周期, 单位：秒<br>使能后，服务退出后，会启动定时器，定时拉起服务,如："period" : 60，表示服务退出后，60s后定时拉起|

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
  
  - 定时启动

    通过约定时间拉起服务， 若服务已拉起， 则不在重新拉起服务。具体命令参考： **[begetctl命令说明](subsys-boot-init-plugin.md)** 。
    ```
    timer_start servicename timeout
    ```
## 服务进程创建基本流程

### 配置服务进程配置文件

  服务进程代码编写完成后创建serviceName.cfg(serviceName 为服务进程名），并根据服务特性配置文件内容。

  配置文件完成后，需要安装到对应目录，init中在/base/startup/init/services/etc/BUILD.gn文件配置如下：

  ```
  ohos_prebuilt_etc("watchdog.cfg") {
    source = "//base/startup/init/services/etc/watchdog.cfg"
    relative_install_dir = "init"
    part_name = "init"
    subsystem_name = "startup"
  }

  ohos_prebuilt_etc("console.cfg") {
    source = "//base/startup/init/services/etc/console.cfg"
    relative_install_dir = "init"
    part_name = "init"
    subsystem_name = "startup"
  }

  ```

  服务进程及其配置文件创建完成后，需要在对应模块的bundle.json文件中添加其build路径,例如：

  ```
      "build": {
          "group_type": {
              "base_group": [],
              "fwk_group": [],
              "service_group": [
                  "//base/startup/init/ueventd:startup_ueventd",
                  "//base/startup/init/services/etc:ueventd.cfg"
              ]
            },
      }
  ```
### 配置服务进程的DAC权限

  服务进程的DAC权限通过服务进程配置文件的gid, uid项来设置。

  如果新增gid, uid需要在init模块的/init/services/etc/passwd文件和 /init/services/etc/group文件中添加。

  - passwd 文件说明：

  - passwd：每行记录对应一个用户，用户信息以":"作为分隔符，划分七个字段;如

    ```js
    root:x:0:0:::/bin/false
    bin:x:2:2:::/bin/false
    system:x:1000:1000:::/bin/false
    ```

  字段含义
  |     序号   |   字段    |                            含义                              |
  | ---------- | --------- | ------------------------------------------------------------ |
  | 第一个字段 | 用户名    | 用户名仅是为了方便用户记忆，如root，通过UID来识别用户身份，分配用户权限 |
  | 第二个字段 | 密码      | "x"表示此用户设有密码，但不是真正的密码，真正的密码保存在/etc/shadow文件 |
  | 第三个字段 | UID       | 用户ID，每个用户有唯一的UID，系统通过UID识别用户身份<br />UID在0 ~ 65535之间的数，不同范围的数字代表不同的用户身份<br />1. 0-超级用户，代表管理员账号<br />2. 1~499代表系统用户<br />3. >=500代表普通用户 |
  | 第四个字段 | GID       | 表示初始组组ID号，指用户登陆时就拥有这个用户组的相关权限。每个用户的初始组只能有一个，通常将和此用户的用户名相同的组名作为该用户的初始组。 |
  | 第五个字段 | 描述信息  | 表示此用户的意义，多数情况为空。                                               |
  | 第六个字段 | 主目录    | 通常称为用户的主(家)目录，如root的主目录为/root，多数情况为空                          |
  | 第七个字段 | 默认shell | shell是linux的命令解释器，用户和Linux内核之间沟通的桥梁shell命令解释器用于将用户输入的命令转换成系统可识别的机器语言通常情况下，Linux系统默认使用的命令解释器是/bin/bash |

  - group 文件说明：

  - group：每行记录对应一个用户组，用户组信息以":"作为分隔符，划分四个字段;如：

    ```js
    root:x:0:
    bin:x:2:
    system:x:1000:
    servicectrl:x:1050:root,shell,system,samgr,hdf_devmgr,foundation,update
    ```

  字段含义
  |    序号    | 字段      |                         含义                       |
  | ---------- | --------- | -------------------------------------------------- |
  | 第一个字段 | 组名 | 用户组的名称，例如：servicectrl就表示组名为servicectrl |
  | 第二个字段 | 组密码标志 | 和/etc/passwd文件一样，这里的“x”仅仅是密码标志，真正的加密之后的组密码保在/etc/gshdow文件中 |
  | 第三个字段 | GID | 通过GID来区别不同的用户组的 |
  | 第四个字段 | 组中的用户 | 表示的就是这个用户组中到底包含了哪些用户，例如：servicectrl 组的成员有root,shell,system,samgr,hdf_devmgr,foundation,update |

  - 若gid,uid设置为root或system，则需要在对应产品目录下的security_config/high_privilege_process_list.json文件种添加白名单，例如：

  ```
    {
        "high_privilege_process_list": [
            {
                "name": "appspawn",
                "uid": "root",
                "gid": "root"
            },
            {
                "name": "console",
                "uid": "root"
            },
            {
                "name": "testService",
                "uid": "root",
                "gid": "root"
            },
            {
                "name": "media_service",
                "gid": ["root", "system"]
            },
            {
                "name": "misc",
                "uid": "root",
                "gid": "root"
            } ... ...
        ]
    }

  ```
### 配置进程的SELinux权限

- 配置服务进程的SELinux权限

  1、首先可以先不配置selinux 标签，确认服务进程是否可以在permissive时可以启动起来，若可以启动，则无需配置。

  2、若需要配置selinux规则，首先要在服务进程的配置文件中通过“secon”项设置selinux 标签

  3、在selinux模块对服务进程的标签进行定义。具体如下：

  在base/security/selinux_adapter/sepolicy/base/system/file_contexts文件定义执行程序的标签，如：

  ```
    /system/bin/watchdog_service        u:object_r:watchdog_service_exec:s0
    /system/bin/hdcd        u:object_r:hdcd_exec:s0
  ```

  在base/security/selinux_adapter/sepolicy/base/public/type.te文件定义标签的作用域，如：

  ```
    type watchdog_service, sadomain, domain;
    type watchdog_service_exec, exec_attr, file_attr, system_file_attr;
  ```

##  系统进程服务错误码说明

**错误码说明** 

| 枚举               | 枚举值 | 错误信息                 | 说明                    |
| ------------------ | ------ | ------------------------ | ----------------------- |
| INIT_OK            | 0      |                          | 执行成功                |
| INIT_EPARAMETER    | 1      | parameter                | 接口参数无效            |
| INIT_EFORMAT       | 2      | Format string fail       | 字符串格式化错误        |
| INIT_ECFG          | 3      | cfg error                | cfg解析错误             |
| INIT_EPATH         | 4      | Invalid path             | 服务path配置错误        |
| INIT_EFORK         | 5      | Fork fail                | fork子进程失败          |
| INIT_ESANDBOX      | 6      | Create sandbox fail      | 服务进沙盒失败          |
| INIT_EACCESSTOKEN  | 7      | Set access token fail    | 设置access token失败    |
| INIT_ESOCKET       | 8      | Create socket fail       | 创建socket失败          |
| INIT_EFILE         | 9      | Create file fail         | 创建文件失败            |
| INIT_ECONSOLE      | 10     | Open console fail        | 打开console失败         |
| INIT_EHOLDER       | 11     | Publish holder fail      | Publish holder失败      |
| INIT_EBINDCORE     | 12     | Bind core fail           | 绑核失败                |
| INIT_EKEEPCAP      | 13     | Set keep capability fail | 设置keep capability失败 |
| INIT_EGIDSET       | 14     | Set gid fail             | 设置服务gid失败         |
| INIT_ESECCOMP      | 15     | Set SECCOMP fail         | 设置服务安全策略        |
| INIT_EUIDSET       | 16     | Set uid fail             | 设置服务uid失败         |
| INIT_ECAP          | 17     | Set capability fail      | 设置服务capability失败  |
| INIT_EWRITEPID     | 18     | Write pid fail           | pid写入失败             |
| INIT_ECONTENT      | 19     | Set sub content fail     | 设置服务安全上下文失败  |
| INIT_EPRIORITY     | 20     | Set priority fail        | 设置服务优先级失败      |
| INIT_EEXEC_CONTENT | 21     | Set exec content fail    | 设置selinux标签失败     |
| INIT_EEXEC         | 22     | Exec fail                | 执行exec失败            |

## 服务进程配置实例：

### 服务示例代码展示

### 服务示例配置展示

## 接口说明

  **表3**  服务控制接口介绍
| 函数名 | 函数解释 | 参数解释 |
| :----------  |  :----------  |:--------|
| int ServiceControlWithExtra(const char *serviceName, int action, const char *extArgv[], int extArgc) | 配置服务参数 | 返回值：成功返回0，失败返回-1 <br> 参数: <br> serviceName: 服务名 <br> action: 服务行为（"start", "stop", "restart"） <br> extArgv: 参数数组 <br> extArgc: 参数个数 |
| int ServiceControl(const char *serviceName, int action)  | 控制服务行为 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 <br> action: 服务行为（"start"， "stop", "restart") |
| int ServiceWaitForStatus(const char *serviceName, ServiceStatus status, int waitTimeout) | 等待服务状态 | 返回值：成功返回0， 失败返回-1。<br> 参数：<br>serviceName: 服务名 <br> status: 返回服务状态 <br> 超时时间 |
| int ServiceSetReady(const char *serviceName) | 设置服务准备 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 |
| int StartServiceByTimer(const char *serviceName, uint64_t timeout) | 定时启动服务 | 返回值：成功返回0，失败返回-1 <br> 参数: <br> serviceName: 服务名 <br> timeout: 超时时间 |
| int StopServiceTimer(const char *serviceName)  | 停止服务计时器 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 |

  - 服务控制接口为特权接口，因此需要配置DAC和selinux权限，具体如下：

   - 服务控制接口配置DAC，需要修改/base/startup/init/services/etc/group文件，在组servicectrl中添加对应的用户id，例如：

    ```
    servicectrl:x:1050:root,shell,system,samgr,hdf_devmgr
    ```

  - 服务控制接口的selinux配置

    服务控制接口配置selinux，需要在init.te文件中添加该服务接口所需要的selinux权限，例如为init、samgr、hdf_devmgr等服务配置系统参数写权限：

    ```java
    allow { init samgr hdf_devmgr } servicectrl_param:parameter_service { set };
    ```
## 约束与限制

仅限小型系统、标准系统下使用。
## 常见问题

查看[init FAQ](./subsys-boot-init-faqs.md)详细介绍
