# init Run Log Standardization
## Overview
### Introduction
Basic functions of a log include recording key nodes and troubleshooting faults during the init startup process.
- Logs help troubleshoot faults, check the startup duration of each subsystem, command execution duration, and more.

- Log tags (including **param**, **uevent**, and **module**) for different modules can be viewed.

- Logs can be printed for key phases, for example, the startup of the first phase, a required partition and its device node, **uevent** creation, service startup, and more.

- Logs can be printed according to the specified log level. Currently, the following log levels are available: **INIT_DEBUG**, **INIT_INFO**, **INIT_WARN**, **INIT_ERROR**, and **INIT_FATAL**.

### Basic Concepts

The implementation of init logs varies according to the OpenHarmony version.
- OpenHarmony standard: The init log is implemented via **dmesg log** of the Linux kernel.
- OpenHarmony LiteOS L1: The init log is implemented via **hilog**.
- OpenHarmony LiteOS L0: The init log is implemented via **printf**.

### Constraints
None

## How to Develop
### Use Cases
init logs are mainly used to start modules (like **param**, **ueventd**, and **module**) during init startup, and are used in the open API **begetutils**.

### Available APIs

**Table 1** Log APIs
| API                   | Format and Example                                              | Description                                                        |
| ----------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| INIT_LOGV               | INIT_LOGV("Add %s to job %s", service->name, jobName);       | Prints the log of the DEBUG level.                                             |
| INIT_LOGI               | INIT_LOGI("Start init first stage.");                        | Prints the log of the INFO level.                                              |
| INIT_LOGW               | INIT_LOGW("initialize signal handler failed");               | Prints the log of the WARN level.                                           |
| INIT_LOGE               | INIT_LOGE("Failed to format other opt");                     | Prints the log of the ERROR level.                                               |
| INIT_LOGF               | INIT_LOGF("Failed to init system");                          | Prints the log of the FATAL level.                                             |
| INIT_ERROR_CHECK        | INIT_ERROR_CHECK(ctx != NULL, return NULL, "Failed to get cmd args "); | Prints a log and executes **return NULL** when **ctx != NULL** is not true.|
| INIT_INFO_CHECK         | INIT_INFO_CHECK(sockopt != NULL, return SERVICE_FAILURE, "Failed to malloc for service %s", service->name); | Prints a log and executes **return SERVICE_FAILURE** when **sockopt != NULL** is not true.|
| INIT_WARNING_CHECK      | INIT_WARNING_CHECK(argsCount <= SPACES_CNT_IN_CMD_MAX, argsCount = SPACES_CNT_IN_CMD_MAX, "Too much arguments for command, max number is %d", SPACES_CNT_IN_CMD_MAX); | Prints a log and executes **argsCount = SPACES_CNT_IN_CMD_MAX** when **argsCount <= SPACES_CNT_IN_CMD_MAX** is not true.|
| INIT_CHECK              | INIT_CHECK(arg != NULL, return NULL);                        | Executes **return NULL** when **arg != NULL** is not true.            |
| INIT_CHECK_RETURN_VALUE | INIT_CHECK_RETURN_VALUE(errno == 0, -1);                     | Executes **return -1** when **errno == 0** is not true.               |
| INIT_CHECK_ONLY_RETURN  | INIT_CHECK_ONLY_RETURN(cmd != NULL);                         | Executes **return** when **cmd != NULL** is not true.                 |
| INIT_CHECK_ONLY_ELOG    | INIT_CHECK_ONLY_ELOG(execv(argv[0], argv) == 0, "execv %s failed! err %d.", argv[0], errno); | Prints only **log "execv %s failed! err %d."** when **execv(argv[0], argv) == 0** is not true.|

### Development Example

   1. Call an API to print the log.

      For example, call **INIT_LOGI("Start init first stage.")** in **//base/startup/init/services/init/standard/init.c** to print the log.
       ```c
       void SystemPrepare(void)
       {
          MountBasicFs();
          CreateDeviceNode();
          LogInit();
          // Make sure init logs are always printed to /dev/kmsg.
          EnableDevKmsg();
          INIT_LOGI("Start init first stage.");
          // Only the OpenHarmony standard system supports
          // two stages of init.
          // In updater mode, only one stage of init is supported.
          if (InUpdaterMode() == 0) {
              StartInitSecondStage();
          }
       }
       ```
      Run **dmesg** to check the printed log **Start init first stage.**

  2. Set the log level by using the begetctl command.

     The command is **begetctl setloglevel level**, where **level** indicates one of the following log levels: **0** (**INIT_DEBUG**), **1** (**INIT_INFO**), **2** (**INIT_WARN**), **3** (**INIT_ERROR**), and **4** (**INIT_FATAL**).

     After the setting is complete, the level set via **g_logLevel** of init takes effect immediately, and log APIs can print logs only when their log levels are higher than or equal to this level. For example, **begetctl setloglevel 3** sets the log level to **INIT_ERROR**. In this case, only **INIT_LOGE** and **INIT_LOGF** will print logs.

     After the system is restarted, the configured log level will take effect after the **load_persist_params** command in the **init.cfg** file is executed.
