# init启动引导组件<a name="ZH-CN_TOPIC_0000001062722441"></a>

-   [init启动引导的配置文件](#section56901555917)
-   [开发指导](#section15371931131117)
-   [开发实例](#section173413113565)

init启动引导组件负责在系统启动阶段启动关键服务进程。 若用户需要新增随开机自启动的系统服务，可将新增服务加入配置文件init.cfg中。

## init启动引导的配置文件<a name="section56901555917"></a>

init启动引导组件配置文件包含了所有需要由init进程启动的系统关键服务的服务名、可执行文件路径、权限和其他信息，该文件位于代码仓库“vendor/huawei/camera/init\_configs/“目录，烧写单板后可在“/etc/“目录下找到，文件名称为init.cfg，采用json格式，文件大小目前限制在100KB以内。

init进程启动后读取/etc/init.cfg，然后解析其json格式内容，并根据解析结果依次加载系统服务。

## 开发指导<a name="section15371931131117"></a>

1.  配置jobs数组。

    init启动引导组件将系统启动分为三个阶段：

    -   “pre-init”阶段：启动系统服务之前需要先执行的操作，例如挂载文件系统、创建文件夹、修改权限等。
    -   “init”阶段：系统服务启动阶段。
    -   “post-init”阶段：系统服务启动完后还需要执行的操作。

    上述每个阶段用一个job表示，一个job对应一个命令集合，init通过依次执行每个job中的命令来完成系统初始化。job执行顺序：先执行“pre-init”，再执行“init”，最后执行“post-init”。

    ```
        "jobs" : [{
                "name" : "pre-init",      
                "cmds" : [                               
                    "mkdir /testdir",      
                    "chmod 0700 /testdir", 
                    "chown 99 99 /testdir",
                    "mkdir /testdir2",
                    "mount vfat /dev/mmcblk0p0 /testdir2 noexec nosuid" // mount命令，格式为：mount 文件系统类型 source target flags data
                 ]
            }, {
                "name" : "init",          
                "cmds" : [
                    "start service1",     
                    "start service2"      
                 ]
            }, {
                 "name" : "post-init",  
                 "cmds" : []
            }
        ],
    ```

    **表 1**  执行job介绍

    <a name="table1801509284"></a>
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
    <td class="cellrowborder" valign="top" width="86.6%" headers="mcps1.2.3.1.2 "><p id="p18116016285"><a name="p18116016285"></a><a name="p18116016285"></a>最后被执行的job，如果开发者的进程在启动完成之后需要有一些处理（如驱动初始化后再挂载设备），可以把这类操作放到该job执行。</p>
    </td>
    </tr>
    </tbody>
    </table>

    单个job最多支持30条命令（当前仅支持start/mkdir/chmod/chown/mount/loadcfg），命令名称和后面的参数（参数长度≤128字节）之间有且只能有一个空格。

    **表 2**  命令集说明

    <a name="table122681439144112"></a>
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
                "caps" : [0, 1, 2, 5]           
        }, {
                "name" : "service2",            
                "path" : "/bin/process2",
                "uid" : 2,
                "gid" : 2,
                "once" : 1,
                "importance" : 0,
                "caps" : [ ]
            }
        ]
    ```

    **表 3**  service字段说明

    <a name="table14737791471"></a>
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
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p166448210816"><a name="p166448210816"></a><a name="p166448210816"></a>当前服务进程是否为关键系统进程：</p>
    <p id="p8572182712811"><a name="p8572182712811"></a><a name="p8572182712811"></a>0：非关键系统进程，当该进程退出时，init不会将系统复位重启；</p>
    <p id="p11861032111516"><a name="p11861032111516"></a><a name="p11861032111516"></a>1：关键系统进程，当该进程退出时，init将系统复位重启。</p>
    </td>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>caps</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>当前服务所需的capability值，根据安全子系统已支持的capability，评估所需的capability，遵循最小权限原则配置（当前最多可配置100个值）。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 开发实例<a name="section173413113565"></a>

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
        "caps" : []           //  MySystemApp系统服务不需要任何capability权限（即MySystemApp系统服务不涉及与capability相关的操作）
     }
     ]
}
```

完成配置后，编译出包烧写单板：

1.  启动后使用task -a（liteos-a版本）或ps命令（linux版本）查看是否MySystemApp系统服务进程已启动。
2.  使用kill命令将上述新增的MySystemApp进程杀死，观察该进程是否会被重新拉起（此处应该为重新拉起）。
3.  使用kill命令将上述新增的MySystemApp进程杀死，观察是否会导致单板重启（此处应该为不重启）。

