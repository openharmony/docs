# init运行时日志规范化
## 概述
### 功能简介
日志的基本功能就是记录init启动中的关键节点，以及定位故障问题。
- 基于日志可以定位故障问题，可以查看各子系统启动时长，命令执行时长等。
- 可以查看不同模块的日志tag，如param、uevent、module等。
- 输出关键阶段日志，如第一阶段启动日志、required partition设备节点、uevent创建日志、服务启动日志等。
- 日志等级可控，根据需要输出不同级别日志，目前日志级别分为INIT_DEBUG、INIT_INFO、INIT_WARN、INIT_ERROR、INIT_FATAL。

### 基本概念

init日志根据OpenHarmony版本不同实现方式不同。
- 对于OpenHarmony标准系统版本，init日志采用内核的dmesg log实现。
- 对于OpenHarmony LiteOS小型系统版本init日志采用hilog接口实现。
- 对于OpenHarmony LiteOS轻量系统版本init日志采用printf接口实现。

### 日志类型介绍
  Init的日志记录主要分为hilog 和demsg, hilog主要记录系统业务流程相关的日志，demsg 记录内核相关的日志。
### 日志级别的控制
  init 日志级别分为五级,可以通过设置(INIT_DEBUG_LEVEL)persist.init.debug.loglevel参数来控制。

  ```
  InitLogLevel:
    INIT_DEBUG = 0,
    INIT_INFO,
    INIT_WARN,
    INIT_ERROR,
    INIT_FATAL
  ```

  Kmsg 日志级别：

  ```
  "<7>" =====> "DEBUG"
  "<6>" =====> "INFO"
  "<4>" =====> "WARNING"
  "<3>" =====> "ERROR"
  "<3>" =====> "FATAL"
  ```
### 日志控制的关键宏
  INIT_DMESG 控制是否记录内核日志 /dev/kmsg。
  INIT_FILE  控制是否将日志写入文件 /data/init_agent/begetctl.log。
  INIT_AGENT 控制是否走Hilog记录日志。

  关键接口：
  ```
    void EnableInitLog(InitLogLevel level) 使能log
  
    void SetInitLogLevel(InitLogLevel level) 设置log 的级别，控制日志的输出

    void StartupLog(InitLogLevel logLevel, uint32_t domain, const char *tag, const char *fmt, ...) 是init log的入口
  ```
  STARTUP_LOGI 是对StartupLog 定义的宏，在头文件/base/startup/init/interfaces/innerkits/include/beget_ext.h中定义，其他log都是基于STARTUP_LOGI这个宏重定义的：

  - deviceInfo模块(init/device_info/idevice_info.h):
  ```
    DINFO_LOGI
    DINFO_LOGE
    DINFO_LOGV
  ```
  - Paran Js接口模块(init/interfaces/kits/jskits/src/native_parameters_js.h)：
  ```
    PARAM_JS_LOGI
    PARAM_JS_LOGE
    PARAM_JS_LOGV
    PARAM_JS_LOGW
  ```
  - Shell模块(init/services/begetctl/shell/shell_utils.h)：
  ```
    BSH_LOGI
    BSH_LOGE
    BSH_LOGV
  ```
  - LoopEvent模块(init/services/loopevent/utils/le_utils.h)：
  ```
    LE_LOGI
    LE_LOGE
    LE_LOGV
  ```
  - Plugin 模块(init/services/modules/plugin_adapter.h)：
  ```
    PLUGIN_LOGI
    PLUGIN_LOGE
    PLUGIN_LOGV
    PLUGIN_LOGW
  ```
  - Param 模块(init/services/param/include/param_utils.h)：
  ```
    PARAM_LOGI
    PARAM_LOGE
    PARAM_LOGV
    PARAM_LOGW
  ```
  - ParameWatcher 模块(init/services/param/watcher/include/watcher_utils.h)：
  ```
    WATCHER_LOGI
    WATCHER_LOGE
    WATCHER_LOGV
  ```
  - Init 流程部分的log 也是直接基于StartupLog 函数定义的宏，主要有(init/services/log/init_log.h)：
  ```
    INIT_LOGV
    INIT_LOGI
    INIT_LOGW
    INIT_LOGE
    INIT_LOGF
  ```

### 约束与限制
无。

## 开发指导
### 场景介绍
init log主要应用在init的启动过程中，启动相关模块（param、ueventd、module等）中，以及对外提供的begetutils接口中。

### 接口说明

**表1** log接口说明
   | 接口 | 接口格式和示例 | 说明 |
   | -------- | -------- | -------- |
   | INIT_LOGV | INIT_LOGV("Add %s to job %s", service->name, jobName); | 输出debug log。 |
   | INIT_LOGI | INIT_LOGI("Start init first stage."); | 输出info log。 |
   | INIT_LOGW | INIT_LOGW("initialize signal handler failed"); | 输出warning log。 |
   | INIT_LOGE | INIT_LOGE("Failed to format other opt"); | 输出err log。 |
   | INIT_LOGF | INIT_LOGF("Failed to init system"); | 输出fatal log。 |
   | INIT_ERROR_CHECK | INIT_ERROR_CHECK(ctx != NULL, return NULL, "Failed to get cmd args "); | 判断 ctx != NULL 不成立的情况下输出log，同时执行 return NULL。 |
   | INIT_INFO_CHECK | INIT_INFO_CHECK(sockopt != NULL, return SERVICE_FAILURE, "Failed to malloc for service %s", service->name); | 判断 sockopt != NULL 不成立的情况下输出log，同时执行 return SERVICE_FAILURE。 |
   | INIT_WARNING_CHECK | INIT_WARNING_CHECK(argsCount <= SPACES_CNT_IN_CMD_MAX, argsCount = SPACES_CNT_IN_CMD_MAX, "Too much arguments for command, max number is %d", SPACES_CNT_IN_CMD_MAX); | 判断 argsCount <= SPACES_CNT_IN_CMD_MAX 不成立的情况下输出log，同时执行 argsCount = SPACES_CNT_IN_CMD_MAX。 |
   | INIT_CHECK | INIT_CHECK(arg != NULL, return NULL); | 判断arg != NULL 不成立的情况下执行 return NULL。 |
   | INIT_CHECK_RETURN_VALUE | INIT_CHECK_RETURN_VALUE(errno == 0, -1); | 判断errno == 0 不成立的情况下执行 return -1。 |
   | INIT_CHECK_ONLY_RETURN | INIT_CHECK_ONLY_RETURN(cmd != NULL); | 判断cmd != NULL 不成立的情况下执行 return。 |
   | INIT_CHECK_ONLY_ELOG | INIT_CHECK_ONLY_ELOG(execv(argv[0], argv) == 0, "execv %s failed! err %d.", argv[0], errno); | 判断execv(argv[0], argv) == 0 不成立的情况下只打印log "execv %s failed! err %d."。 |

### 开发实例

   1. 调用接口打印日志：

      例如在 //base/startup/init/services/init/standard/init.c中调用接口INIT_LOGI("Start init first stage.")打印日志。
       ```c
       void SystemPrepare(void)
       {
          MountBasicFs();
          CreateDeviceNode();
          LogInit();
          // Make sure init log always output to /dev/kmsg.
          EnableDevKmsg();
          INIT_LOGI("Start init first stage.");
          // Only ohos normal system support
          // two stages of init.
          // If we are in updater mode, only one stage of init.
          if (InUpdaterMode() == 0) {
              StartInitSecondStage();
          }
       }
       ```
      通过dmesg可以查看打印的log，"Start init first stage."。

  2. 通过命令设置日志等级：

     通过命令begetctl setloglevel level，其中level对应log的等级0~4，即INIT_DEBUG，INIT_INFO，INIT_WARN，INIT_ERROR，INIT_FATAL。
  
     设置完成之后init的g_logLevel等级立即生效，上述log接口中log等级大于等于g_logLevel才会打印日志。例如：begetctl setloglevel 3，即设置log等级为INIT_ERROR，则上述的log接口中只有INIT_LOGE、INIT_LOGF才会打印log。

     系统重启之后在init.cfg中"load_persist_params "命令之后生效设置的log等级。
   
