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
| 命令 | 命令格式和示例 | 说明 |
| :----------  |  :----------  |:--------|
| init group test [stage] | init group test | stage参见ServiceStatus。 |
| param ls [-r] [name] | 显示系统参数，例如：<br>查看USB系统参数：begetctl param ls persist.sys.usb    | 无 |
| param get [name] | 获取系统参数信息，例如：<br>begetctl param get 或 param get | 无 |
| param set name value| 设置系统参数，例如：<br>begetctl param set ohos.servicectrl.display 1 或 param set ohos.servicectrl.display 1| 无 |
| param wait name [value] [timeout] | 等待系统参数，例如：<br>begetctl param wait persist.sys.usb.config hdc 或 param wait persist.sys.usb.config hdc | timeout默认值：30秒 |
| param dump [verbose] | dump 系统参数信息，例如：<br>begetctl param dump 或 param dump| 无 |
| param shell [name] | 进入Parameter shell，例如：<br>begetctl param shell 或 param shell| 无 |
| timer_stop servicename | 停止服务计时器，例如：<br>begetctl timer_stop appspawn | servicename长度不超过96字符 |
| timer_start servicename timeout | 启动服务计时器，例如：<br>begetctl timer_start appspawn | servicename长度不超过96；timeout默认值：10毫秒  |
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
| reboot charge | 重新启动并进入charge，例如：<br>begetctl reboot charge 或 reboot charge | 无 |
| reboot loader | 重新启动并进入烧写模式，例如：<br>begetctl reboot loader 或 reboot loader | 无 |
| bootchart stop | 停止图形分析，例如：<br>begetctl bootchart stop | 仅支持rk3568|
| bootchart start | 开始图形分析，例如：<br>begetctl bootchart start | 无 |
| bootchart disable | 图形分析不使能，例如：<br>begetctl bootchart disable | 无 |
| bootchart enable | 图形分析使能，例如：<br>begetctl bootchart enable | 无 |
| sandbox -s service_name | 服务进沙盒，例如：<br>sandbox -s foundation | 无 |
| sandbox -p process_name | 进程进沙盒，例如：<br>sandbox -p /bin/sh | 无 |
| sandbox -n sandbox_name | 进入配置的system或者chipset沙盒，例如：<br>sandbox -n system | 无 |
| sandbox -h | sandbox command help | 无 |
| partitionslot getslot | 获取当前活动slot，例如：<br>begetctl partitionslot getslot 或 partitionslot getslot | 无 | 
| partitionslot getsuffix slot | 获取当前匹配slot，例如：<br>begetctl partitionslot getsuffix 1 或 partitionslot getsuffix 1 | 无 |
| partitionslot setactive slot | 设置活动slot，例如：<br>begetctl partitionslot setactive 1 或 partitionslot setactive 1 | 无 |
| partitionslot setunboot slot | 设置非活动slot，例如：<br>begetctl partitionslot setunboot 1 或 partitionslot setunboot 1 | 无 |
| modulectl uninstall moduleName | 卸载动态插件，例如：<br>modulectl uninstall bootchart | 无 |
| modulectl install moduleName | 安装动态插件，例如：<br>modulectl install bootchart | 无 |
| modulectl list | 动态插件列表，例如：<br>begetctl modulectl list | 无 |
| setloglevel level | 设置log等级为info，例如：<br>begetctl setloglevel 1 | log等级设置范围0~4 |
| getloglevel | 获取当前init的log等级，例如：<br>begetctl getloglevel | 无 |
| bootevent disable | 关闭bootevent插件功能，例如：<br>bootevent disable | 无 |
| bootevent enable | 开启bootevent插件功能，例如：<br>begetctl 关闭bootevent插件功能 | 无 |
| dump_service parameter_service trigger | 命令行展示所有trigger信息，例如：<br>begetctl dump_service parameter_service trigger | 无 |
| dump_service all | 命令行展示所有服务的信息，例如：<br>begetctl dump_service all | 无 |
| dump_service serviceName | 命令行展示单个服务信息，例如：<br>begetctl dump_service param_watcher | 无 |
| dump api | 命令行展示init接口信息，例如：<br>begetctl dump api | 无 |


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
  1. 准备bootchart测试环境：linux操作系统下安装python及pycairo pip install pycairo
  2. 在linux解压bootchart-master.tar

     tar -zxvf  bootchart-master.tar

  执行步骤：
  1. 启动系统。
  2. 执行命令行：begetctl bootchart enable
  3. 重启系统。
  4. 执行命令行：begetctl bootchart stop
  5. 执行命令行：begetctl bootchart disable
  6. 在/data/bootchart目录下导出如下文件并存放在bootchart文件夹：<br>
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