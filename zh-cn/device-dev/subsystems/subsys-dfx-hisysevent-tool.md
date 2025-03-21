# HiSysEvent工具


## 概述

目前在系统的/system/bin目录下预置了hisysevent工具，开发者可以通过此工具实时订阅HiSysEvent事件及查询历史HiSysEvent事件。

## 实时订阅HiSysEvent事件相关命令

- 实时订阅HiSysEvent事件的基础命令：

    ```shell
    hisysevent -r
    ```

    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -r | 以缺省设置实时订阅HiSysEvent事件，在此种订阅方式下有任何实时HiSysEvent事件产生，都会在控制台上打印此HiSysEvent事件。 |


- 通过事件标签方式实时订阅HiSysEvent事件：

    ```shell
    hisysevent -r -t <tag> [-c [WHOLE_WORD|PREFIX|REGULAR]]
    ```

    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -t | 设置实时订阅的HiSysEvent事件标签，用来过滤订阅的HiSysEvent事件。 |
    | -c | 设置实时订阅的HiSysEvent事件标签匹配规则，有“WHOLE_WORD”、“PREFIX”、“REGULAR”三种匹配规则。 |

    命令实例：

    ```shell
    # hisysevent -r -t "STA" -c PREFIX
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963670809,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805200750","HAPPEN_TIME":1501963670809,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"4973863135535405472","info_":""}
    # hisysevent -r -t "STAw{0,6}" -c REGULAR
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963793206,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805200953","HAPPEN_TIME":1501963793206,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"16367997008075110557","info_":""}
    # hisysevent -r -t "STA\w+" -c REGULAR
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963863393,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201103","HAPPEN_TIME":1501963863393,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"5522352691813553392","info_":""}
    ```

- 通过事件领域及事件名称的方式实时订阅HiSysEvent事件：

    ```shell
    hisysevent -r -o <domain> -n <eventName> [-c [WHOLE_WORD|PREFIX|REGULAR]]
    ```

    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -o | 设置实时订阅的HiSysEvent事件领域，用来过滤订阅的HiSysEvent事件。 |
    | -n | 设置实时订阅的HiSysEvent事件名称，用来过滤订阅的HiSysEvent事件。 |
    | -c | 设置实时订阅的HiSysEvent事件领域及事件名称的匹配规则，有“WHOLE_WORD”、“PREFIX”、“REGULAR”三种匹配规则。 |

    命令实例：

    ```shell
    # hisysevent -r -o "RELIABILITY" -n "APP_FREEZE"
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963989773,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201309","HAPPEN_TIME":1501963989773,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"16367997008075110557","info_":""}
    # hisysevent -r -o "RELIABI\w{0,8}" -n "APP_FREEZE" -c REGULAR
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964144383,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201544","HAPPEN_TIME":1501964144383,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"13456525196455104060","info_":""}
    # hisysevent -r -o "RELIABI\w+" -c REGULAR
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964193466,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201633","HAPPEN_TIME":1501964193466,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"12675246910904037271","info_":""}
    ```

    > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
    > 当同时通过-t、-o及-n指定了相关订阅规则参数设置，则判断设置的事件标签是否为空，若不为空，则使用事件标签规则进行订阅，否则使用事件领域及事件名称订阅规则进行订阅。

- 通过事件类型的方式实时订阅HiSysEvent事件：

    ```shell
    hisysevent -r -g [FAULT|STATISTIC|SECURITY|BEHAVIOR]
    ```

    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -g | 设置实时订阅的HiSysEvent事件类型，用来过滤订阅的HiSysEvent事件，有“FAULT”、“STATISTIC”、“SECURITY”及“BEHAVIOR”四种事件类型。 |

    命令实例：

    ```shell
    # hisysevent -r -o "RELIABILITY" -n "APP_FREEZE" -g FAULT
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963989773,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201309","HAPPEN_TIME":1501963989773,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"16367997008075110557","info_":""}
    # hisysevent -r -o "POWER\w{0,8}" -n "POWER_RUNNINGLOCK" -c REGULAR -g STATISTIC
    {"domain_":"POWER","name_":"POWER_RUNNINGLOCK","type_":2,"time_":1667485283785,"tz_":"+0000","pid_":538,"tid_":684,"uid_":5523,"PID":360,"UID":1001,"STATE":0,"TYPE":1,"NAME":"telRilRequestRunningLock","LOG_LEVEL":2,"TAG":"DUBAI_TAG_RUNNINGLOCK_REMOVE","MESSAGE":"token=25956496","level_":"MINOR","tag_":"PowerStats","id_":"11994072552538324655","info_":""}
    # hisysevent -r -o "ACCOU\w+" -c REGULAR -g SECURITY
    {"domain_":"ACCOUNT","name_":"PERMISSION_EXCEPTION","type_":3,"time_":1667484405993,"tz_":"+0000","pid_":614,"tid_":614,"uid_":3058,"CALLER_UID":1024,"CALLER_PID":523,"PERMISSION_NAME":"ohos.permission.MANAGE_LOCAL_ACCOUNTS","level_":"CRITICAL","tag_":"security","id_":"15077995598140341422","info_":""}
    # hisysevent -r -o MULTIMODALINPUT -g BEHAVIOR
    {"domain_":"MULTIMODALINPUT","name_":"Z_ORDER_WINDOW_CHANGE","type_":4,"time_":1667549852735,"tz_":"+0000","pid_":2577,"tid_":2588,"uid_":6696,"OLD_ZORDER_FIRST_WINDOWID":-1,"NEW_ZORDER_FIRST_WINDOWID":2,"OLD_ZORDER_FIRST_WINDOWPID":-1,"NEW_ZORDER_FIRST_WINDOWPID":1458,"MSG":"The ZorderFirstWindow changing succeeded","level_":"MINOR","tag_":"PowerStats","id_":"16847308118559691400","info_":""}
    ```


## 查询历史HiSysEvent事件相关命令

- 查询历史HiSysEvent事件的基础命令：

    ```shell
    hisysevent -l
    ```

    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -l | 以缺省设置查询历史HiSysEvent事件，此次查询会返回不多于10000条的HiSysEvent事件。 |

- 通过设置开始/结束原始时间戳，过滤查询历史HiSysEvent事件的结果的命令：

    ```shell
    hisysevent -l -s <begin time> -e <end time>
    ```

    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -s | 设置查询历史HiSysEvent事件的开始原始时间戳，此次查询只会返回不早于该时间点的HiSysEvent事件。 |
    | -e | 设置查询历史HiSysEvent事件的结束原始时间戳，此次查询只会返回不晚于该时间点的HiSysEvent事件。 |

    命令实例：

    ```shell
    # hisysevent -l -s 1501964222980 -e 1501964222996
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964222980,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201702","HAPPEN_TIME":1501964222980,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"10435592800188571430","info_":""}
    {"domain_":"GRAPHIC","name_":"NO_DRAW","type_":1,"time_":1501964222980,"tz_":"+0000","pid_":1505,"tid_":1585,"uid_":10002,"PID":1505,"UID":10002,"ABILITY_NAME":"","MSG":"It took 1957104259905ns to draw, UI took 0ns to draw, RSRenderThread took 8962625ns to draw, RSRenderThread dropped 0 UI Frames","level_":"MINOR","id_":"1708287249901948387","info_":"isResolved,eventId:0"}
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964222994,"tz_":"+0000","pid_":623,"tid_":1445,"uid_":1201,"SUB_EVENT_TYPE":"NO_DRAW","EVENT_TIME":"20170805201702","MODULE":"NO_DRAW","PNAME":"NO_DRAW","REASON":"NO_DRAW","DIAG_INFO":"","STACK":"SUMMARY:\n","HIVIEW_LOG_FILE_PATHS":["/data/log/faultlog/faultlogger/appfreeze-NO_DRAW-10002-20170805201702"],"DOMAIN":"GRAPHIC","STRING_ID":"NO_DRAW","PID":1505,"UID":10002,"PACKAGE_NAME":"NO_DRAW","PROCESS_NAME":"","MSG":"It took 1956945826265ns to draw, UI took 0ns to draw, RSRenderThread took 9863293ns to draw, RSRenderThread dropped 0 UI Frames\n","level_":"CRITICAL","tag_":"STABILITY","id_":"10448522101019619655","info_":""}
    ```

- 通过设置开始/结束格式化时间，过滤查询历史HiSysEvent事件的结果的命令：

    ```shell
    hisysevent -l -S <begin time> -E <end time>
    ```

    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -S | 设置查询历史HiSysEvent事件的开始格式化时间，此次查询只会返回不早于该时间点的HiSysEvent事件。 |
    | -E | 设置查询历史HiSysEvent事件的结束格式化时间，此次查询只会返回不晚于该时间点的HiSysEvent事件。 |

    命令实例：

    ```shell
    # hisysevent -l -S "2023-01-05 14:12:50" -E "2023-01-05 14:12:51"
    {"domain_":"GRAPHIC","name_":"JANK_FRAME_SKIP","type_":1,"time_":1672899170022,"tz_":"+0800","pid_":1499,"tid_":1573,"uid_":20010037,"PID":1499,"UID":20010037,"ABILITY_NAME":"com.ohos.launcher","MSG":"It took 587948726ns to draw, UI took 483016382ns to draw, RSRenderThread took 96616051ns to draw, RSRenderThread dropped 0 UI Frames","level_":"MINOR","id_":"11351278822867091090","info_":"","seq_":307}
    {"domain_":"AAFWK","name_":"START_ABILITY_ERROR","type_":1,"time_":1672899170108,"tz_":"+0800","pid_":550,"tid_":1127,"uid_":5523,"USER_ID":-1,"BUNDLE_NAME":"com.ohos.wallpaper","MODULE_NAME":"","ABILITY_NAME":"WallpaperExtAbility","ERROR_CODE":2097152,"level_":"MINOR","tag_":"ability","id_":"53589395004188308060","info_":"","seq_":313}
    {"domain_":"GRAPHIC","name_":"JANK_FRAME_SKIP","type_":1,"time_":1672899170305,"tz_":"+0800","pid_":1293,"tid_":1632,"uid_":10006,"PID":1293,"UID":10006,"ABILITY_NAME":"com.ohos.systemui","MSG":"It took 309597490ns to draw, UI took 92364718ns to draw, RSRenderThread took 205874105ns to draw, RSRenderThread dropped 1 UI Frames","level_":"MINOR","id_":"14843220972178010722","info_":"","seq_":314}
    {"domain_":"GRAPHIC","name_":"JANK_FRAME_SKIP","type_":1,"time_":1672899170350,"tz_":"+0800","pid_":1293,"tid_":1632,"uid_":10006,"PID":1293,"UID":10006,"ABILITY_NAME":"com.ohos.systemui","MSG":"It took 259782859ns to draw, UI took 33909753ns to draw, RSRenderThread took 44849879ns to draw, RSRenderThread dropped 5 UI Frames","level_":"MINOR","id_":"66610006717219916560","info_":"","seq_":315}
    {"domain_":"AAFWK","name_":"CONNECT_SERVICE_ERROR","type_":1,"time_":1672899170733,"tz_":"+0800","pid_":550,"tid_":1127,"uid_":5523,"USER_ID":100,"BUNDLE_NAME":"com.ohos.wallpaper","MODULE_NAME":"","ABILITY_NAME":"WallpaperExtAbility","ERROR_CODE":2097152,"level_":"MINOR","tag_":"ability","id_":"10040008376311927188","info_":"","seq_":317}
    {"domain_":"COMMONEVENT","name_":"PUBLISH","type_":2,"time_":1672899170063,"tz_":"+0800","pid_":550,"tid_":937,"uid_":5523,"USER_ID":-1,"PUBLISHER_BUNDLE_NAME":"","PID":0,"UID":1101,"EVENT_NAME":"usual.event.SCREEN_ON","level_":"MINOR","id_":"80996758983032931610","info_":"","seq_":308}
    ```

- 通过设置最大数量值，限制查询历史HiSysEvent事件的数量：

    ```shell
    hisysevent -l -m <max hisysevent count>
    ```

    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -m | 设置查询历史HiSysEvent事件的数量，此次查询会返回最多不超过指定数量的HiSysEvent事件。 |

    命令实例：

    ```shell
    # hisysevent -l -s 1501964222980 -e 1501964222996 -m 1
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964222980,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201702","HAPPEN_TIME":1501964222980,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"10435592800188571430","info_":""}
    ```

- 通过事件领域及事件名称的方式查询历史HiSysEvent事件：

    ```shell
    hisysevent -l -o <domain> -n <eventName> [-c WHOLE_WORD]
    ```

    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -o | 设置查询历史HiSysEvent事件领域，用来过滤查询的HiSysEvent事件。 |
    | -n | 设置查询历史HiSysEvent事件名称，用来过滤查询的HiSysEvent事件。 |
    | -c | 设置查询历史HiSysEvent事件领域及事件名称的匹配规则，查询只支持“WHOLE_WORD”匹配规则。 |

    命令实例：

    ```shell
    # hisysevent -l -n "APP_FREEZE"
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963989773,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201309","HAPPEN_TIME":1501963989773,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"16367997008075110557","info_":""}
    # hisysevent -l -o "RELIABILITY"
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963989773,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201544","HAPPEN_TIME":1501963989773,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"13456525196455104060","info_":""}
    # hisysevent -l -o "RELIABILITY" -n "APP_FREEZE" -c WHOLE_WORD
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963989773,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201633","HAPPEN_TIME":1501963989773,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"12675246910904037271","info_":""}
    ```

- 通过事件类型的方式查询历史HiSysEvent事件：

    ```shell
    hisysevent -l -g [FAULT|STATISTIC|SECURITY|BEHAVIOR]
    ```

    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -g | 设置查询历史HiSysEvent事件类型，用来过滤查询的HiSysEvent事件，有“FAULT”、“STATISTIC”、“SECURITY”及“BEHAVIOR”四种事件类型。 |

    命令实例：

    ```shell
    # hisysevent -l -o "RELIABILITY" -g FAULT
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963989773,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201309","HAPPEN_TIME":1501963989773,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"16367997008075110557","info_":""}
    # hisysevent -l -n "POWER_RUNNINGLOCK" -c WHOLE_WORD -g STATISTIC
    {"domain_":"POWER","name_":"POWER_RUNNINGLOCK","type_":2,"time_":1667485283785,"tz_":"+0000","pid_":538,"tid_":684,"uid_":5523,"PID":360,"UID":1001,"STATE":0,"TYPE":1,"NAME":"telRilRequestRunningLock","LOG_LEVEL":2,"TAG":"DUBAI_TAG_RUNNINGLOCK_REMOVE","MESSAGE":"token=25956496","level_":"MINOR","tag_":"PowerStats","id_":"11994072552538324655","info_":""}
    # hisysevent -l -g SECURITY
    {"domain_":"ACCOUNT","name_":"PERMISSION_EXCEPTION","type_":3,"time_":1667484405993,"tz_":"+0000","pid_":614,"tid_":614,"uid_":3058,"CALLER_UID":1024,"CALLER_PID":523,"PERMISSION_NAME":"ohos.permission.MANAGE_LOCAL_ACCOUNTS","level_":"CRITICAL","tag_":"security","id_":"15077995598140341422","info_":""}
    # hisysevent -l -o MULTIMODALINPUT -g BEHAVIOR
    {"domain_":"MULTIMODALINPUT","name_":"Z_ORDER_WINDOW_CHANGE","type_":4,"time_":1667549852735,"tz_":"+0000","pid_":2577,"tid_":2588,"uid_":6696,"OLD_ZORDER_FIRST_WINDOWID":-1,"NEW_ZORDER_FIRST_WINDOWID":2,"OLD_ZORDER_FIRST_WINDOWPID":-1,"NEW_ZORDER_FIRST_WINDOWPID":1458,"MSG":"The ZorderFirstWindow changing succeeded","level_":"MINOR","tag_":"PowerStats","id_":"16847308118559691400","info_":""}
    ```

## 系统事件合法性校验模式

- 打开系统事件合法性校验模式

    ```shell
    hisysevent -v
    ```
	
    选项说明：

    | 选项名称 | 功能说明 |
    | -------- | -------- |
    | -v | 配合订阅命令-r及查询命令-l使用，当打开事件合法性校验模式，系统事件包含的非法内容会红色高亮显示。 |

    命令实例：

    ```shell
    # hisysevent -v -l -s 1501964222980 -e 1501964222996
    # 因为HAPPEN_TIME与VERSION没有在事件领域RELIABILITY所属的事件名称APP_FREEZE下进行yaml文件配置，属于非法内容，所以这两个键会被高亮显示为红色.
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964222980,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201702","HAPPEN_TIME":1501964222980,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"10435592800188571430","info_":""}
    # hisysevent -v -r -o "RELIABILITY" -n "APP_FREEZE"
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964644584,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805202404","HAPPEN_TIME":1501964644584,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"11097868872446282676","info_":""}
    ```
