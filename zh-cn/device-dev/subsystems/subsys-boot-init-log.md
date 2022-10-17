# init运行时日志规范化
## 概述
### 功能简介
日志的基本功能就是记录init启动中的关键节点，以及定位故障问题。
- 基于日志可以定位故障问题，可以查看各子系统启动时长，命令执行时长等。
- 可以查看不同模块的日志tag，如param、uevent、module等。
- 输出关键阶段日志，如第一阶段启动日志、required partition设备节点、uevent创建日志、服务启动日志等。
- 日志等级可控，根据需要输出不同级别日志，目前日志级别分为INIT_DEBUG,
INIT_INFO,INIT_WARN,INIT_ERROR,INIT_FATAL。

### 基本概念

init日志根据OpenHarmony版本不同实现方式不同。
- 对于OpenHarmony标准版本，init日志采用内核的dmesg log实现。
- 对于OpenHarmony liteos L1版本init日志采用hilog接口实现。
- 对于OpenHarmony liteos L0版本init日志采用printf接口实现。

### 约束与限制
无

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

   1. 调用接口打印日志

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

  2. 通过命令设置日志等级

     通过命令begetctl setloglevel level，其中level对应log的等级0~4，即INIT_DEBUG，INIT_INFO，INIT_WARN，INIT_ERROR，INIT_FATAL。
  
     设置完成之后init的g_logLevel等级立即生效，上述log接口中log等级大于等于g_logLevel才会打印日志。例如：begetctl setloglevel 3，即设置log等级为INIT_ERROR，则上述的log接口中只有INIT_LOGE、INIT_LOGF才会打印log。

     系统重启之后在init.cfg中"load_persist_params "命令之后生效设置的log等级。
   
