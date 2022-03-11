# init启动引导组件<a name="ZH-CN_TOPIC_0000001062722441"></a>

-   [功能说明](#section56901555916)
      - [init启动引导的配置文件](#section56901555917)
      - [init服务启动控制(仅标准系统以上提供)](#section56901555918)
      - [init服务并行控制(仅标准系统以上提供)](#section56901555919)
      - [init 按需启动(仅标准系统以上提供)](#section56901555920)
      - [init 进程启动&回收能力增强](#section56901555921)
      - [init FD代持(仅标准系统以上提供)](#section56901555922)
      - [init job](#section56901555923)
-   [开发指导](#section56901555924)
-   [开发实例](#section56901555925)
-   [常见问题](#section56901555926)
      -  [服务不存在](#section56901555927)
      -  [请求其他服务代持fd，init有报错](#section56901555928)
      -  [服务没有配置ondemand 选项](#section56901555929)

## 功能说明<a name="section56901555916">

  init启动引导组件负责在系统启动阶段启动关键服务进程。 若用户需要新增随开机自启动的系统服务，可添加新的配置文件xxx.cfg，系统会自动分析对应的cfg文件，并按照cfg文件启动对应的服务。

- init启动引导的配置文件<a name="section56901555917"></a>

   init启动引导组件配置文件包含了所有需要由init进程启动的系统关键服务的服务名、可执行文件路径、权限和其他信息，烧写单板后可在“/etc/“目录下找到，文件名称为init.cfg，采用json格式，文件大小目前限制在100KB以内。

  init进程启动后读取/etc/init.cfg，然后解析其json格式内容，并根据解析结果依次加载系统服务。

  各模块需要添加关键服务时，也可以添加模块对应的cfg文件，编译时拷贝文件到/system/etc/init目录下，init进程会解析改cfg文件，并启动对应的服务。

- init服务启动控制(仅标准系统以上提供)<a name="section56901555918"></a>

  init会根据用户的服务配置，把服务分成三类，在不同的阶段进行启动。

  - “boot”类型：对应系统中需要优先启动的服务，这类服务在init完成init阶段后启动。
  - “normal”类型：默认配置，对应系统中的普通服务，这类服务在init命令执行完成后启动。
  - "condition"类型：对应有特殊要求的服务，可以直接通过start xxx 命令执行启动，一般在条件job或者在init的某个阶段使用命令启动。

- init服务并行控制(仅标准系统以上提供)<a name="section56901555919"></a>

  init提供服务并行处理能力，启动服务在不同的阶段执行job的能力。

  - “on-start”：在服务进程被fock后执行，不同服务的on-start job可以并行执行（在服务的子进程中执行，只对改进程产生影响）。
  - “on-stop”：在服务停止时执行。
  - "on-restart"：在服务重启时执行。

- init 按需启动(仅标准系统以上提供)<a name="section56901555920"></a>

  由init管理的服务支持按需启动，按需启动的服务不会在系统启动过程中主动被拉起，而是当某些事件发生时才会被init按需拉起，触发服务启动的事件可能是被init监听的相关socket有消息上报、samgr收到客户端的请求需要拉起SA服务等情况。

  "ondemand" 属性是按需启动的服务的标志，一个服务配置了该属性值为true的时候，服务不再需要配置start命令来拉起，而是被监听的相应事件发生时才会被拉起。

  - SA进程按需启动
    1. 应用请求SA句柄时samgr需识别SA所属进程是否可动态拉起
    2. 如需拉起，则需阻塞请求，等init拉起SA进程并注册SA后再返回所请求的SA句柄

  - socket进程按需启动
    1. init在pre-fork阶段为socket类进程创建好socket，init中监听创建好的socket上的网络事件
    2. socket上有报文事件后，init拉起socket进程进行报文处理，init进程取消socket数据的监听，由socket进程处理
    3. socket进程无报文处理后，可以自动退出，退出后init回收该子进程并重新监听socket网络数据

  - 热插拔服务进程按需启动
    1. ueventd的监听到热插拔事件后，可触发系统参数变化，业务进程可根据系统参数的变化进行热插拔事件按需启动处理。

- init 进程启动&回收能力增强 <a name="section56901555921"></a>

  进程启动时，支持在配置文件中配置服务进程的绑核、优先级、MAC信息以及AccessToken信息。

  - init提供修改*.cfg配置文件， 为服务进程提供cpu绑核功能
  - init提供修改*.cfg配置文件， 为服务进程提供优先级设置
  - init提供修改*.cfg配置文件， 为服务提供设置AccessToken, 为系统服务进程设置其分布式Capability能力（仅标准系统以上提供）。
  - init提供修改*.cfg配置文件， 为服务提供抑制机制。

- init FD代持(仅标准系统以上提供)<a name="section56901555922"></a>

  FD代持是按需启动的一个辅助扩展机制，按需启动进程可以保持退出前的fd状态句柄不丢失。按需启动进程退出前可将fd发送给init代持，再次启动后再从init获取fd。

  init提供了相关接口供服务调用，服务进程退出前调用接口将fd通过支持IPC通信的socket发送给init代持，待该服务重新启动时，init将持有的该服务相关的fd句柄通过同样的方式返回给服务。

- init job<a name="section56901555923"></a>

  init提供job能力，一个job就是一组命令的集合。job可以在init.cfg中配置，也可以在模块的自定义cfg中配置。init解析程序会把相同名字job的命令合并到一个job中。同一名字的job只能保证init.cfg中的命令优先执行，其他cfg间的命令执行顺序不保证。

  - 普通job：一般是init启动的固定阶段，如“pre-init“，”init“，”post-init“等，这类job在init启动的固定阶段执行。

  - 自定义job：用户自定义的job，这类job按照一定的规则进行触发。
    - job：用户任意定义，可以通过trigger命令执行。
    - 控制job(仅标准系统以上提供)：按条件触发处理的能力。在job中可以设置触发条件，当对应的属性值满足设置的条件时，就会触发job执行。触发条件支持&&和||操作，可以根据不同的属性就行组合。

## 开发指导<a name="section56901555924"></a>

  1. 配置jobs数组。

      init启动引导组件将系统启动分为三个阶段，这三个阶段：

      -   “pre-init”阶段：启动系统服务之前需要先执行的操作，例如挂载文件系统、创建文件夹、修改权限等。
      -   “init”阶段：系统服务启动阶段。
      -   “post-init”阶段：系统服务启动完后还需要执行的操作。

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

**表 1**  执行job介绍 <a name="table1801509284"></a>
<table><thead align="left"><tr id="row680703289"><th class="cellrowborder" valign="top" width="13.4%" id="mcps1.2.3.1.1"><p id="p11805012282"><a name="p11805012282"></a><a name="p11805012282"></a>job名</p>
    </th>
<th class="cellrowborder" valign="top" width="86.6%" id="mcps1.2.3.1.2"><p id="p2811605289"><a name="p2811605289"></a><a name="p2811605289"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row178140112810"><td class="cellrowborder" valign="top" width="13.4%" headers="mcps1.2.3.1.1 "><p id="p6811809281"><a name="p6811809281"></a><a name="p6811809281"></a>pre-init</p>
    </td>
    <td class="cellrowborder" valign="top" width="86.6%" headers="mcps1.2.3.1.2 "><p id="p18115019284"><a name="p18115019284"></a><a name="p18115019284"></a>最先执行的job，如果开发者的进程在启动之前需要首先执行一些操作（例如创建文件夹），可以把操作放到pre-init中先执行。</p>
    </td>
    </tr>
    <tr id="row381120182817"><td class="cellrowborder" valign="top" width="13.4%" headers="mcps1.2.3.1.1 "><p id="p148116002812"><a name="p148116002812"></a><a name="p148116002812"></a>init</p>
    </td>
    <td class="cellrowborder" valign="top" width="86.6%" headers="mcps1.2.3.1.2 "><p id="p14818016288"><a name="p14818016288"></a><a name="p14818016288"></a>中间执行的job，例如服务启动。</p>
    </td>
    </tr>
    <tr id="row181100162813"><td class="cellrowborder" valign="top" width="13.4%" headers="mcps1.2.3.1.1 "><p id="p3811804281"><a name="p3811804281"></a><a name="p3811804281"></a>post-init</p>
    </td>
    <td class="cellrowborder" valign="top" width="86.6%" headers="mcps1.2.3.1.2 "><p id="p18116016285"><a name="p18116016285"></a><a name="p18116016285"></a>最后被执行的job，如果开发者的进程在启动完成之后需要有一些处理（如驱动初始化后再挂载设备），可以把这类操作放到该job执行。单个job最多支持30条命令（当前仅支持start/mkdir/chmod/chown/mount/loadcfg），命令名称和后面的参数（参数长度≤128字节）之间有且只能有一个空格。</p>
    </td>
    </tr>
    </tbody>
    </table>

**表 2**  命令集说明 <a name="table122681439144112"></a>
<table><thead align="left"><tr id="row826873984116"><th class="cellrowborder" valign="top" width="10.15%" id="mcps1.2.4.1.1"><p id="p826833919412"><a name="p826833919412"></a><a name="p826833919412"></a>命令</p>
    </th>
<th class="cellrowborder" valign="top" width="51.83%" id="mcps1.2.4.1.2"><p id="p3381142134118"><a name="p3381142134118"></a><a name="p3381142134118"></a>命令格式和示例</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.019999999999996%" id="mcps1.2.4.1.3"><p id="p1268539154110"><a name="p1268539154110"></a><a name="p1268539154110"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row142681039124116"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p2083714604313"><a name="p2083714604313"></a><a name="p2083714604313"></a>mkdir</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p143811842154111"><a name="p143811842154111"></a><a name="p143811842154111"></a>mkdir 目标文件夹</p>
    <p id="p4377174213435"><a name="p4377174213435"></a><a name="p4377174213435"></a>如：mkdir /storage/myDirectory</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p56817536457"><a name="p56817536457"></a><a name="p56817536457"></a>创建文件夹命令，mkdir和目标文件夹之间有且只能有一个空格。</p>
    </td>
    </tr>
    <tr id="row1268133919413"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p97961563461"><a name="p97961563461"></a><a name="p97961563461"></a>chmod</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p20381144234118"><a name="p20381144234118"></a><a name="p20381144234118"></a>chmod 权限 目标</p>
    <p id="p6334213124413"><a name="p6334213124413"></a><a name="p6334213124413"></a>如：chmod 0600 /storage/myFile.txt</p>
    <p id="p1748214543444"><a name="p1748214543444"></a><a name="p1748214543444"></a>chmod 0750 /storage/myDir</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p2023822074614"><a name="p2023822074614"></a><a name="p2023822074614"></a>修改权限命令，chmod权限目标之间间隔有且仅有一个空格，权限必须为0xxx格式。</p>
    </td>
    </tr>
    <tr id="row7268143918416"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p8255346174610"><a name="p8255346174610"></a><a name="p8255346174610"></a>chown</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p238114423418"><a name="p238114423418"></a><a name="p238114423418"></a>chown uid gid 目标</p>
    <p id="p1118592184518"><a name="p1118592184518"></a><a name="p1118592184518"></a>如：chown 900 800 /storage/myDir</p>
    <p id="p1235374884510"><a name="p1235374884510"></a><a name="p1235374884510"></a>chown 100 100 /storage/myFile.txt</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p18408185817467"><a name="p18408185817467"></a><a name="p18408185817467"></a>修改属组命令，chown uid gid目标之间间隔有且仅有一个空格。</p>
    </td>
    </tr>
    <tr id="row109751379478"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p1017823174717"><a name="p1017823174717"></a><a name="p1017823174717"></a>mount</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p10381124244117"><a name="p10381124244117"></a><a name="p10381124244117"></a>mount fileSystemType src dst flags data</p>
    <p id="p572019493485"><a name="p572019493485"></a><a name="p572019493485"></a>如：mount vfat /dev/mmcblk0 /sdc rw,umask=000</p>
    <p id="p7381173625313"><a name="p7381173625313"></a><a name="p7381173625313"></a>mount jffs2 /dev/mtdblock3 /storage nosuid</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p11976107144710"><a name="p11976107144710"></a><a name="p11976107144710"></a>挂载命令，各参数之间有且仅有一个空格。flags当前仅支持nodev、noexec、nosuid、rdonly，data为可选字段。</p>
    </td>
    </tr>
    <tr id="row1334911198482"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p1214153117480"><a name="p1214153117480"></a><a name="p1214153117480"></a>start</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p133816420411"><a name="p133816420411"></a><a name="p133816420411"></a>start serviceName</p>
    <p id="p2036714132541"><a name="p2036714132541"></a><a name="p2036714132541"></a>如：start foundation</p>
    <p id="p115951820185412"><a name="p115951820185412"></a><a name="p115951820185412"></a>start shell</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p4350121915488"><a name="p4350121915488"></a><a name="p4350121915488"></a>启动服务命令，start后面跟着service名称，该service名称必须能够在services数组中找到。</p>
    </td>
    </tr>
    <tr id="row96921442712"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p1693642018"><a name="p1693642018"></a><a name="p1693642018"></a>loadcfg</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p1969364211116"><a name="p1969364211116"></a><a name="p1969364211116"></a>loadcfg filePath</p>
    <p id="p1858112368211"><a name="p1858112368211"></a><a name="p1858112368211"></a>如：loadcfg /patch/fstab.cfg</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p13986141320510"><a name="p13986141320510"></a><a name="p13986141320510"></a>加载其他cfg文件命令。后面跟着的目标文件大小不得超过50KB，且目前仅支持加载/patch/fstab.cfg，其他文件路径和文件名均不支持。/patch/fstab.cfg文件的每一行都是一条命令，命令类型和格式必须符合本表格描述，命令条数不得超过20条。</p>
    </td>
    </tr>
    </tbody>
    </table>

  2.  配置services数组，service集合（数组形式），包含了init进程需要启动的所有系统服务（最多支持100个）。

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

**表 3**  service字段说明<a name="table14737791471"></a>

<table><thead align="left"><tr id="row273839577"><th class="cellrowborder" valign="top" width="16.64%" id="mcps1.2.3.1.1"><p id="p107382095711"><a name="p107382095711"></a><a name="p107382095711"></a>字段名</p>
    </th>
    <th class="cellrowborder" valign="top" width="83.36%" id="mcps1.2.3.1.2"><p id="p17738189277"><a name="p17738189277"></a><a name="p17738189277"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17386911716"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p17384912710"><a name="p17384912710"></a><a name="p17384912710"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p1173818913714"><a name="p1173818913714"></a><a name="p1173818913714"></a>当前服务的服务名，须确保非空且长度&lt;=32字节。</p>
    </td>
    </tr>
    <tr id="row1473810916714"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p127381991571"><a name="p127381991571"></a><a name="p127381991571"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p1073815910717"><a name="p1073815910717"></a><a name="p1073815910717"></a>当前服务的可执行文件全路径和参数，数组形式。须确保第一个数组元素为可执行文件路径、数组元素个数&lt;=20、每个元素为字符串形式以及每个字符串长度&lt;=64字节。</p>
    </td>
    </tr>
    <tr id="row77381291271"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p77381391770"><a name="p77381391770"></a><a name="p77381391770"></a>uid</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p107387920711"><a name="p107387920711"></a><a name="p107387920711"></a>当前服务进程的uid值。</p>
    </td>
    </tr>
    <tr id="row127381591673"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p47388919715"><a name="p47388919715"></a><a name="p47388919715"></a>gid</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p12738691479"><a name="p12738691479"></a><a name="p12738691479"></a>当前服务进程的gid值。</p>
    </td>
    </tr>
    <tr id="row188301014171116"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p183112146115"><a name="p183112146115"></a><a name="p183112146115"></a>once</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p18548317195715"><a name="p18548317195715"></a><a name="p18548317195715"></a>当前服务进程是否为一次性进程：</p>
    <p id="p103571840105812"><a name="p103571840105812"></a><a name="p103571840105812"></a>1：一次性进程，当该进程退出时，init不会重新启动该服务进程</p>
    <p id="p5831191431116"><a name="p5831191431116"></a><a name="p5831191431116"></a>0 : 常驻进程，当该进程退出时，init收到SIGCHLD信号并重新启动该服务进程；</p>
    <p id="p378912714010"><a name="p378912714010"></a><a name="p378912714010"></a>注意，对于常驻进程，若在4分钟之内连续退出5次，第5次退出时init将不会再重新拉起该服务进程。</p>
    </td>
    </tr>
    <tr id="row386110321155"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p14861113212156"><a name="p14861113212156"></a><a name="p14861113212156"></a>importance</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p166448210816"><a name="p166448210816"></a><a name="p166448210816"></a>当前服务进程优先级， 取值范围[19, -20]</p>
    </td>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>caps</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>当前服务所需的capability值，根据安全子系统已支持的capability，评估所需的capability，遵循最小权限原则配置（当前最多可配置100个值）。</p>
    </td>
    </tr>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>critical</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>critical服务启动失败后， 需要M秒内重新拉起， 拉起失败N次后， 直接重启系统， N默认为4， M默认20。（仅标准系统以上提供 "critical" : [0, 2, 10]; 类型为int型数组)<a name="section56901555917"></a><a name="section56901555917"></a></p>
    <p id="p8572182712811"><a name="p8572182712811"></a><a name="p8572182712811"></a>0：不使能；</p>
    <p id="p11861032111517"><a name="p11861032111517"></a><a name="p11861032111517"></a>1：使能。</p>
    </td>
    </tr>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>cpucore</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>服务需要的绑定的cpu核心数， 类型为int型数组<a name="section56901555917"></a><a name="section56901555917"></a></p>
    </td>
    </tr>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>d-caps</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>分布式能力 (仅标准系统以上提供)<a name="section56901555917"></a><a name="section56901555917"></a></p>
    </td>
    </tr>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>apl</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>能力特权级别：system_core, normal, system_basic。 默认system_core (仅标准系统以上提供)<a name="section56901555917"></a><a name="section56901555917"></a></p>
    </td>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>start-mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>服务的启动模式，具体描述：init服务启动控制(仅标准系统以上提供)<a name="section56901555917"></a><a name="section56901555917"></a></p>
    </td>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>jobs</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>当前服务在不同阶段可以执行的job。具体说明可以看：init服务并行控制(仅标准系统以上提供)<a name="section56901555917"></a></p>
    </td>
    </tr>
    </tbody>
    </table>

  **表 4**  接口介绍

  | 函数名     | 函数解释 |参数解释  |
  | :----------  |  :----------  |:--------|
  | int *ServiceGetFd(const char *serviceName, size_t *outfdCount) | 获取init代持的fd | 返回值：成功返回fd数组指针，失败返回NULL。备注：需手动释放<br>参数：<br> serviceName: 服务名<br>outfdCount: 返回的fd数组长度 |
  | int ServiceSaveFd(const char *serviceName, int *fds, int fdCount) | 请求init代持fd | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 <br> fds: 需要init代持的fd数组指针<br>fdCount: fd数组长度
  | int ServiceControlWithExtra(const char *serviceName, int action, const char *extArgv[], int extArgc) | 配置服务参数 | 返回值：成功返回0，失败返回-1 <br> 参数: <br> serviceName: 服务名 <br> action: 服务行为（"start", "stop", "restart"） <br> extArgv: 参数数组 <br> extArgc: 参数个数
  | int ServiceControl(const char *serviceName, int action)  | 控制服务行为 | 返回值：成功返回0，失败返回-1 <br> 参数：<br> serviceName: 服务名 <br> action: 服务行为（"start"， "stop", "restart")

## 开发实例<a name="section56901555925"></a>

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

1.  启动后使用task -a（liteos-a版本）或ps命令（linux版本）查看是否MySystemApp系统服务进程已启动。
2.  使用kill命令将上述新增的MySystemApp进程杀死，观察该进程是否会被重新拉起（此处应该为重新拉起）。
3.  使用kill命令将上述新增的MySystemApp进程杀死，观察是否会导致单板重启（此处应该为不重启）。

## 常见问题<a name="section56901555926"></a>

### 服务不存在<a name="section56901555927"></a>

-   **现象描述**

    内核Log打印 "Failed get servName"

-   **解决方法**
    1. 确认服务是否在cfg中正确配置
    2. 服务的cfg文件是否正常加载
    3. cfg文件格式是否正确

### 请求其他服务代持fd，init有报错<a name="section56901555928"></a>

-   **现象描述**

    内核Log打印 "Service \' xxx \'(pid = xxx) is not valid or request with unexpected process(pid = xxx)"

-   **解决方法**
    只支持代持本服务的fd， 不允许让其他服务代持fd

### 服务没有配置ondemand 选项<a name="section56901555929"></a>

-   **现象描述**
     内核Log打印 "service : %s had started already"

-   **解决方法**
     服务对应的.cfg文件正确配置如： "ondemand" : true