# 插件

## 概述
### 基本概念
 - begetctl介绍

   具体参考[begetctl命令](#table14737791480)。
 - bootchart 插件

   bootchart是一个用于linux启动过程性能分析的开源工具软件，在系统中自动收集CPU占用率、磁盘吞吐率、进程等信息，并以图形方式显示分析结果，可用作指导优化系统启动过程。begetctl命令参考：[begetctl命令](#table14737791480)。
 - bootevent 插件

   bootevent是一个记录init进程及各个服务的启动关键事件的插件，记录内容包括事件名称，关联事件的服务的启动时间，事件发生时间。导出文件支持tracing解析，可用作指导优化系统启动过程。

### 约束与限制

bootchart和bootevent只支持标准系统， begetctl 支持小型系统和标准系统。

## 开发指导
### 参数说明
 **表1**  begetctl 命令说明<a name="table14737791480"></a>
| 命令 | 说明 | 格式和示例|
| :----------  |  :----------  |:-------------- |
| init group test [stage] | init moduletest 测试用 | stage参见[ServiceStatus](#section001) |
| param ls [-r] [name] | 显示系统参数dac和selinux信息<br> -r： 展示所有参数信息 <br> name：展示指定参数信息 | begetctl param ls xxx.xxx 或 <br>param ls xxx.xxx<br>例如：<br>begetctl param ls persist.sys.usb |
| param get [name] | 获取系参数统值 | begetctl param get xxxx.xxx 或 <br>param get xxxx.xxx<br>例如：<br>param get const.product.name|
| param set name value| 设置系统参数值 |begetctl param set xxxx.xxx value 或<br> param set xxxx.xxx value <br>例如：<br>begetctl param set ohos.servicectrl.display 1 |
| param wait name [value] [timeout] | 等待参数被设置成某值<br> timeout默认值：30秒| begetctl param wait xxx.xxx value 或<br> wait xxx.xxx value <br>例如：<br>param wait xx.sss 1 |
| param dump [verbose] | dump 系统参数信息|begetctl param dump <br>或 param dump |
| param shell [name] | 进入Parameter shell|begetctl param shell <br>或 param shell |
| param save | 持久化workspace中的所有带持久化标记的参数|begetctl param save <br>或 param save |
| dump api | dump 显示init 系统参数接口信息|begetctl dump api |
| getloglevel | 获取当前init的log等级<br>读取persist.init.debug.loglevel<br>0:debug<br> 1:info<br> 2:warning<br> 3:err<br> 4:fatal|begetctl getloglevel |
| setloglevel level | 设置log等级为info <br>log等级设置范围0~4<br> 0:debug<br>1:info<br> 2:warning<br> 3:err<br>4:fatal|begetctl setloglevel 1 |
| timer_stop servicename | 停止服务计时器<br>servicename长度不超过96字符|begetctl timer_stop servicename | begetctl timer_stop appspawn |
| timer_start servicename timeout | 启动服务计时器<br>servicename长度不超过96<br>timeout默认值：10毫秒 |begetctl timer_start servicename | begetctl timer_start appspawn|
| start_service servicename | 启动服务| begetctl start_service servicename 或<br>start_service servicename|begetctl start_service appspawn |
| stop_service servicename | 停止服务|begetctl stop_service servicename 或<br> stop_service servicename|begetctl stop_service appspawn |
| service_control start servicename | 启动服务|begetctl service_control start servicename 或<br> service_control start servicename|begetctl service_control start appspawn |
| service_control stop servicename | 停止服务|begetctl service_control stop servicename 或<br> service_control stop servicename|begetctl service_control stop appspawn |
| sandbox -b pid | 进入native应用沙盒 | begetctl sandbox -b pid|
| sandbox -p process_name | 进程进沙盒| begetctl sandbox -p /bin/sh |
| sandbox -n sandbox_name | 进入配置的system或者chipset沙盒| begetctl sandbox -n system|
| sandbox -s service_name | 服务进沙盒| begetctl sandbox -s service_name |
| sandbox -h | 展示sandbox 命令帮助信息| begetctl sandbox -h |
| modulectl uninstall moduleName | 卸载动态插件| begetctl modulectl uninstall moduleName <br>例如:<br>卸载bootchart：<br> begetctl modulectl uninstall bootchart |
| modulectl install moduleName | 安装动态插件|begetctl modulectl install moduleName <br>例如:<br>安装bootchart：<br>begetctl modulectl install bootchart |
| modulectl list | 查询动态插件列表|begetctl modulectl list |
| misc_daemon --write_logo xxx.rgb | 写入开机logo<br>rgb文件最大不超过1024*2038，仅支持hi3516dv300|begetctl misc_daemon --write_logo logo.rgb 或<br> misc_daemon --write_logo logo.rgb|
| reboot | 重启系统|begetctl reboot 或<br> reboot|
| reboot shutdown[:options] | 关闭系统|begetctl reboot shutdown 或<br> reboot shutdown |
| reboot suspend | 暂停系统|begetctl reboot suspend 或<br> reboot suspend |
| reboot updater | 重新启动并进入updater|begetctl reboot updater 或<br> reboot updater |
| reboot updater[:options] | 重新启动并进入updater|begetctl reboot updater 或<br> reboot updater |
| reboot flashd | 重新启动并进入flashd|begetctl reboot flashd 或<br> reboot flashd |
| reboot flashd[:options] | 重新启动并进入flashd|begetctl reboot flashd 或<br> reboot flashd |
| reboot charge | 重新启动并进入charge|begetctl reboot charge 或<br> reboot charge |
| reboot loader | 重新启动并进入烧写模式|begetctl reboot loader 或<br> reboot loader |
| bootevent disable | 关闭bootevent插件功能|begetctl bootevent disable |
| bootevent enable | 开启bootevent插件功能|begetctl bootevent enable |
| dump_service parameter_service trigger | 命令行展示所有trigger信息|begetctl dump_service parameter_service trigger |
| dump_service all | 命令行展示所有服务的信息|begetctl dump_service all |
| dump_service serviceName | 命令行展示单个服务信息|begetctl dump_service param_watcher |
| dump_service loop | dump loop 中fd信息 |begetctl dump_service loop|
| bootchart stop | 停止图形分析，仅支持rk3568|begetctl bootchart stop |
| bootchart start | 开始图形分析|begetctl bootchart start |
| bootchart disable | 图形分析不使能|begetctl bootchart disable |
| bootchart enable | 图形分析使能|begetctl bootchart enable |
| dac uid username | 查询username 对应的uid|begetctl dac uid username <br>例如:<br>begetctl dac uid root|
| dac gid groupname | groupname 对应的gid以及组成员|begetctl dac gid groupname <br>例如:<br> begetctl dac gid shell |
| get log level | 获取当前init的log等级<br>读取persist.init.debug.loglevel<br>0:debug<br> 1:info<br> 2:warning<br> 3:err<br> 4:fatal|begetctl get log level |
| set log level | 设置log等级为info <br>log等级设置范围0~4<br> 0:debug<br>1:info<br> 2:warning<br> 3:err<br>4:fatal|begetctl set log level 1 |
| appspawn_time | 查询应用孵化的最大最小时间 | begetctl appspawn_time <br>例如：<br>begetctl appspawn_time|
| dump_nwebspawn | dump nwebspawn 应用信息|begetctl dump_nwebspawn <br>例如：<br>打开备忘录<br>begetctl dump_nwebspawn |
| dump_appspawn | dump appspawn 应用信息|begetctl dump_appspawn<br>例如：<br>begetctl dump_appspawn|

- <a name = "section001"> **ServiceStatus**
```
typedef enum {
    SERVICE_IDLE = 0, // service add
    SERVICE_STARTING, // service start
    SERVICE_STARTED, // 2 service ok running
    SERVICE_READY, // 3 service ok running
    SERVICE_STOPPING,
    SERVICE_STOPPED, // 5
    SERVICE_ERROR,
    SERVICE_SUSPENDED,
    SERVICE_FREEZED,
    SERVICE_DISABLED,
    SERVICE_CRITICAL
} ServiceStatus;
```
### 开发步骤
  新增一个插件， 以bootchart为例：
1. 安装so文件， 定义单独文件，实现下面函数。 
      ```c
      static int bootchartEarlyHook(int stage, int prio, void *cookie)
      {
          char enable[4] = {}; // 4 enable size
          uint32_t size = sizeof(enable);
          SystemReadParam("persist.init.bootchart.enabled", enable, &size);
          if (strcmp(enable, "1") != 0) {
              PLUGIN_LOGI("bootchart disabled.");
              return 0;
          }
          InitModuleMgrInstall("libbootchart");
          PLUGIN_LOGI("bootchart enabled.");
          return 0;
      }
      
      MODULE_CONSTRUCTOR(void)
      {
          // Depends on parameter service
          InitAddPostPersistParamLoadHook(0, bootchartEarlyHook);
      }
      ```     
2. 编译成静态库libbootchart_static，并加入static_modules组。
      ```
      group("static_modules") {
        if (!defined(ohos_lite)) {
          deps = [ ":libbootchart_static" ]
        }
      }
      ```
      
3. 初始化bootchart插件， 可以安装插件命令。
      ```c
      static int BootchartInit(void)
      {
          if (g_executorId == -1) {
              g_executorId = AddCmdExecutor("bootchart", DoBootchartCmd);
              PLUGIN_LOGI("BootchartInit executorId %d", g_executorId);
          }
          return 0;
      }
      
      MODULE_CONSTRUCTOR(void)
      {
          PLUGIN_LOGI("DoBootchartStart now ...");
          BootchartInit();
      }
      ```
4. 退出bootchart插件。
      ```c
      MODULE_DESTRUCTOR(void)
      {
          PLUGIN_LOGI("DoBootchartStop now ...");
          DoBootchartStop();
          BootchartExit();
      }
      ```
5. 执行bootchart命令。
    ```c
    static int DoBootchartCmd(int id, const char *name, int argc, const char **argv)
    {
        PLUGIN_LOGI("DoBootchartCmd argc %d %s", argc, name);
        ...
        return 0;
    }
    ```

### 开发实例
#### bootchart 使用示例
  预制条件：
  1. 准备bootchart测试环境：linux操作系统下安装python及pycairo pip install pycairo。
  2. 在linux解压bootchart-master.tar。

     tar -zxvf  bootchart-master.tar

  执行步骤：
  1. 启动系统。
  2. 执行命令行：begetctl bootchart enable。
  3. 重启系统。
  4. 执行命令行：begetctl bootchart stop。
  5. 执行命令行：begetctl bootchart disable。
  6. 在/data/service/el0/startup/init/目录下导出如下文件并存放在bootchart文件夹：<br>
        header<br>
        proc_diskstats.log<br>
        proc_ps.log<br>
        proc_stat.log<br>
  7. 使用tar -zcvf bootchart.tgz * 命令进行打包（只支持linux版本）并将该打包文件拷贝到linux：bootchart-master目录下。
  8. 在bootchart-master目录下运行命令：
      ```
      python3 pybootchartgui.py -f pdf bootchart.tgz
      ```

  预期结果：
        <br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;在bootchart-master目录下生成bootchart.pdf。
#### bootevent 使用示例
1. 在服务的cfg文件中配置bootevent事件,支持配置一个或多个bootevent事件。

    配置单个bootevent事件:
    ```json
    bootevents : "bootevent.xxxbootevent",
    ```
    配置多个bootevent事件:
    ```json
    bootevents : ["bootevent.xxxbootevent1", "bootevent.xxxbootevent2.xxx"],
    ```
> **注意：** 配置的bootevent事件必须以“bootevent.”开始。
2. 服务代码中发送bootevent事件。

    服务自身代码中调用init提供的SetParameter接口发送bootevent事件,例如发送上一步骤中设置的XXXbootevent1事件：
    ```c
    SetParameter("bootevent.XXXbootevent1", "true");
    ```
3. 命令行启用bootevent功能。

    - 执行begetctl bootevent enable命令后再次启动系统，bootevent功能开启。
    - 执行begetctl bootevent disable命令后再次启动系统，bootevent功能关闭。
4. 导出文件支持trace分析。

    - 导出的bootevent文件目录：/data/service/el0/startup/init/。
    - 导出文件命名规则：“时间戳.bootevent”。
    - 导出的bootevent信息文件可以通过trace分析工具进行可视化展示。