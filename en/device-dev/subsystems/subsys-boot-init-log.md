# Log Management

## Overview

### Function Introduction

Basic functions of a log include recording key nodes and troubleshooting faults during the init startup process.
- Logs help troubleshoot faults, check the startup duration of each subsystem, command execution duration, and more.
- Log tags (including **param**, **uevent**, and **module**) for different modules can be viewed.
- Logs can be printed for key phases, for example, the startup of the first phase, a required partition and its device node, **uevent** creation, service startup, and more.
- Log levels are configurable. Available log levels include INIT_DEBUG, INIT_INFO, INIT_WARN, INIT_ERROR, and INIT_FATAL.

### Basic Concepts

The implementation of the init log function varies according to the OpenHarmony version.
- OpenHarmony standard system: The init log function is implemented via **dmesg log** of the Linux kernel.
- For the OpenHarmony LiteOS small system, the init log function is implemented by using the **hilog** API.
- For the OpenHarmony LiteOS mini system, the init log function is implemented by using the **printf** API.

### Log Type
  init logs are classified into hilog and demsg logs. The hilog log records information related to system service processes, and the demsg log records information related to the kernel.
### Log Level
  init logs are classified into five levels, which can be set by the **(INIT_DEBUG_LEVEL)persist.init.debug.loglevel** parameter.

  ```
  InitLogLevel:
    INIT_DEBUG = 0,
    INIT_INFO,
    INIT_WARN,
    INIT_ERROR,
    INIT_FATAL
  ```

  Kmsg log level. The options are as follows:

  ```
  "<7>" =====> "DEBUG"
  "<6>" =====> "INFO"
  "<4>" =====> "WARNING"
  "<3>" =====> "ERROR"
  "<3>" =====> "FATAL"
  ```
### Key Macros for Log Control
  **INIT_DMESG** specifies whether to record kernel logs in **/dev/kmsg**.
  **INIT_FILE** specifies whether to write log information to the **/data/init_agent/begetctl.log** file.
  **INIT_AGENT** specifies whether to use hilog to record log information.

  Key APIs:
  ```
    void EnableInitLog (InitLogLevel level) Enables the init log function.
  
    void SetInitLogLevel(InitLogLevel level) Sets the log level to control log output.

    void StartupLog(InitLogLevel logLevel, uint32_t domain, const char *tag, const char *fmt, ...) Provides an entry to the init log function.
  ```
  **STARTUP_LOGI** is a macro defined for **StartupLog**, which is defined in the **/base/startup/init/interfaces/innerkits/include/beget_ext.h** file. Other logs are redefined based on the **STARTUP_LOGI** macro.

  - deviceInfo module (init/device_info/idevice_info.h):
  ```
    DINFO_LOGI
    DINFO_LOGE
    DINFO_LOGV
  ```
  - Param JS API module (init/interfaces/kits/jskits/src/native_parameters_js.h):
  ```
    PARAM_JS_LOGI
    PARAM_JS_LOGE
    PARAM_JS_LOGV
    PARAM_JS_LOGW
  ```
  - Shell module (init/services/begetctl/shell/shell_utils.h):
  ```
    BSH_LOGI
    BSH_LOGE
    BSH_LOGV
  ```
  - LoopEvent module (init/services/loopevent/utils/le_utils.h):
  ```
    LE_LOGI
    LE_LOGE
    LE_LOGV
  ```
  - Plug-in module (init/services/modules/plugin_adapter.h):
  ```
    PLUGIN_LOGI
    PLUGIN_LOGE
    PLUGIN_LOGV
    PLUGIN_LOGW
  ```
  - Param module (init/services/param/include/param_utils.h):
  ```
    PARAM_LOGI
    PARAM_LOGE
    PARAM_LOGV
    PARAM_LOGW
  ```
  - ParamWatcher module (init/services/param/watcher/include/watcher_utils.h):
  ```
    WATCHER_LOGI
    WATCHER_LOGE
    WATCHER_LOGV
  ```
  - init log module implemented based on the macros defined by **StartupLog** (init/services/log/init_log.h)
  ```
    INIT_LOGV
    INIT_LOGI
    INIT_LOGW
    INIT_LOGE
    INIT_LOGF
  ```

### Constraints
N/A

## How to Develop
### Use Cases
init logs are mainly used to start modules (like **param**, **ueventd**, and **module**) during init startup, and are used in the open API **begetutils**.

### Available APIs

**Table 1** Log APIs
   | API| Format and Example| Description|
   | -------- | -------- | -------- |
   | INIT_LOGV | INIT_LOGV("Add %s to job %s", service->name, jobName); | Prints the log of the DEBUG level.|
   | INIT_LOGI | INIT_LOGI("Start init first stage."); | Prints the log of the INFO level.|
   | INIT_LOGW | INIT_LOGW("initialize signal handler failed"); | Prints the log of the WARN level.|
   | INIT_LOGE | INIT_LOGE("Failed to format other opt"); | Prints the log of the ERROR level.|
   | INIT_LOGF | INIT_LOGF("Failed to init system"); | Prints the log of the FATAL level.|
   | INIT_ERROR_CHECK | INIT_ERROR_CHECK(ctx != NULL, return NULL, "Failed to get cmd args "); | Prints a log and executes **return NULL** when **ctx != NULL** is not true.|
   | INIT_INFO_CHECK | INIT_INFO_CHECK(sockopt != NULL, return SERVICE_FAILURE, "Failed to malloc for service %s", service->name); | Prints a log and executes **return SERVICE_FAILURE** when **sockopt != NULL** is not true.|
   | INIT_WARNING_CHECK | INIT_WARNING_CHECK(argsCount <= SPACES_CNT_IN_CMD_MAX, argsCount = SPACES_CNT_IN_CMD_MAX, "Too much arguments for command, max number is %d", SPACES_CNT_IN_CMD_MAX); | Prints a log and executes **argsCount = SPACES_CNT_IN_CMD_MAX** when **argsCount <= SPACES_CNT_IN_CMD_MAX** is not true.|
   | INIT_CHECK | INIT_CHECK(arg != NULL, return NULL); | Executes **return NULL** when **arg != NULL** is not true.|
   | INIT_CHECK_RETURN_VALUE | INIT_CHECK_RETURN_VALUE(errno == 0, -1); | Executes **return -1** when **errno == 0** is not true.|
   | INIT_CHECK_ONLY_RETURN | INIT_CHECK_ONLY_RETURN(cmd != NULL); | Executes **return** when **cmd != NULL** is not true.|
   | INIT_CHECK_ONLY_ELOG | INIT_CHECK_ONLY_ELOG(execv(argv[0], argv) == 0, "execv %s failed! err %d.", argv[0], errno); | Prints only **log "execv %s failed! err %d."** when **execv(argv[0], argv) == 0** is not true.|

### Development Example

   1. Call an API to print the log.

      For example, call **INIT_LOGI("Start init first stage.")** in **//base/startup/init/services/init/standard/init.c** to print the log.
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
      Run **dmesg** to check the printed log **Start init first stage.**

  2. Set the log level by running the **begetctl setloglevel level** command.

     In the command, set **level** to one of the following log levels: **0** (**INIT_DEBUG**), **1** (**INIT_INFO**), **2** (**INIT_WARN**), **3** (**INIT_ERROR**), and **4** (**INIT_FATAL**).
  
     After the setting is complete, the level set via **g_logLevel** of init takes effect immediately, and log APIs can print logs only when their log levels are higher than or equal to this level. For example, **begetctl setloglevel 3** sets the log level to **INIT_ERROR**. In this case, only **INIT_LOGE** and **INIT_LOGF** will print logs.

     After the system is restarted, the configured log level will take effect after the **load_persist_params** command in the **init.cfg** file is executed.
   
