# init运行时日志规范化
## 概述
### 功能简介
日志的基本功能就是记录init启动中的关键节点，以及定位故障问题。

### 基本概念
基于日志可以定位故障问题，可以查看各子系统启动时长，命令执行时长等；可以查看不同模块的日志tag，如param、uevent、module等；输出关键阶段日志，如第一阶段启动日志、required partition设备节点、uevent创建日志、服务启动日志等；日志等级可控，根据需要输出不同级别日志，目前日志级别分为INIT_DEBUG,
INIT_INFO,INIT_WARN,INIT_ERROR,INIT_FATAL。

- 日志输出原理

  init日志采用内核的dmesg log，即int fd = open("/dev/kmsg", ...)，同时将stdin、stdout、stderr重定向到/dev/null，即关闭标准输入输出。设置基础的log等级g_logLevel，当调用的log等级大于等于g_logLevel才会打印出log。

### 约束与限制
对于标准版本log采用dmesg log，对于非标准版本的liteos L1版本log采用hilog接口，对于L0版本采用printf接口。

## 开发指导
### 场景介绍
init log主要应用在init的启动过程中，启动相关模块（param、ueventd、module等）中，以及对外提供的begetutils接口中。

### 参数说明

**表1** log接口说明
   | 接口 | 接口格式和示例 | 说明 |
   | -------- | -------- | -------- |
   | INIT_LOGV | INIT_LOGV("Add %s to job %s", service->name, jobName); | 输出debug log |
   | INIT_LOGI | INIT_LOGI("Start init first stage."); | 输出info log |
   | INIT_LOGW | INIT_LOGW("initialize signal handler failed"); | 输出warning log |
   | INIT_LOGE | INIT_LOGE("Failed to format other opt"); | 输出err log |
   | INIT_LOGF | INIT_LOGF("Failed to init system"); | 输出fatal log |
   | INIT_ERROR_CHECK | INIT_ERROR_CHECK(ctx != NULL, return NULL, "Failed to get cmd args "); | 判断 ctx != NULL 不成立的情况下输出log，同时执行 return NULL |
   | INIT_INFO_CHECK | INIT_INFO_CHECK(sockopt != NULL, return SERVICE_FAILURE, "Failed to malloc for service %s", service->name); | 判断 sockopt != NULL 不成立的情况下输出log，同时执行 return SERVICE_FAILURE |
   | INIT_WARNING_CHECK | INIT_WARNING_CHECK(argsCount <= SPACES_CNT_IN_CMD_MAX, argsCount = SPACES_CNT_IN_CMD_MAX, "Too much arguments for command, max number is %d", SPACES_CNT_IN_CMD_MAX); | 判断 argsCount <= SPACES_CNT_IN_CMD_MAX 不成立的情况下输出log，同时执行 argsCount = SPACES_CNT_IN_CMD_MAX |
   | INIT_CHECK | INIT_CHECK(arg != NULL, return NULL); | 判断arg != NULL 不成立的情况下执行 return NULL |
   | INIT_CHECK_RETURN_VALUE | INIT_CHECK_RETURN_VALUE(errno == 0, -1); | 判断errno == 0 不成立的情况下执行 return -1 |
   | INIT_CHECK_ONLY_RETURN | INIT_CHECK_ONLY_RETURN(cmd != NULL); | 判断cmd != NULL 不成立的情况下执行 return |
   | INIT_CHECK_ONLY_ELOG | INIT_CHECK_ONLY_ELOG(execv(argv[0], argv) == 0, "execv %s failed! err %d.", argv[0], errno); | 判断execv(argv[0], argv) == 0 不成立的情况下只打印log "execv %s failed! err %d." |

**表2** 关键日志说明
   | 日志内容 | 说明 |
   | -------- | -------- |
   | INIT_LOGI("Start init first stage."); | 当前处理init第一阶段启动，第一阶段包括创建基础的设备节点，以及mount基础的required分区（system、chipset等）|
   | INIT_LOGI("Start init second stage."); | 开始第二阶段启动，包括解析配置文件、拉起服务等等 |
   | INIT_LOGI("Handle required partitionName %s", uevent->partitionName); | 创建关键的required 设备节点 |
   | BEGET_LOGI("Mount %s to %s successful", item->deviceName, item->mountPoint); | fstab文件系统分区挂载成功 |
   | INIT_LOGI("Service %s(pid %d) started", service->name, pid); | 提示init拉起服务成功 |
   | INIT_LOGE("Child process %s(pid %d) exit with code : %d",
   service == NULL ? "Unknown" : service->name, sigPID, sigPID, WTERMSIG(procStat)); | 提示服务异常退出 |
   | INIT_LOGE("Child process %s(pid %d) exit with code : %d",
   service == NULL ? "Unknown" : service->name, sigPID, WEXITSTATUS(procStat)); | 提示服务正常退出 |

**表3** log等级设置命令
   | 命令 | 提示 | 说明 |
   | -------- | -------- | -------- |
   | setloglevel | Command list:setloglevel level  --set init log level 0:debug, 1:info, 2:warning, 3:err, 4:fatal | 设置init log等级在0~4之间 |
   | setloglevel 3 | Success to set log level by param "persist.init.debug.loglevel" 3. | 说明成功设置log等级为3：err |
   | getloglevel | Success to get init log level: 3 from param "persist.init.debug.loglevel" | 获取当前log level为3：err |
