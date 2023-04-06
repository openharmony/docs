# HiSysEvent Tool Usage


## Overview

The HiSysEvent tool is a command line tool preconfigured in the **/system/bin** directory of the system. You can use this tool to subscribe to real-time system events or query historical system vents.

## Subscribing to Real-Time System Events

- Command for subscribing to real-time system events:

    ```shell
    hisysevent -r
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -r | Subscription to real-time system events based on the default settings. When this option is specified, any real-time system event will be printed on the console.|

- Command for enabling the debugging mode:

    ```shell
    hisysevent -r -d
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -d | Subscribes to real-time system events in debugging mode.|

- Command for subscribing to real-time system events by event tag:

    ```shell
    hisysevent -r -t <tag> [-c [WHOLE_WORD|PREFIX|REGULAR]]
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -t | Event tag used to filter subscribed real-time system events.|
    | -c | Matching rule for event tags. The options can be **WHOLE_WORD**, **PREFIX**, or **REGULAR**.|

    Example:

    ```shell
    # hisysevent -r -t "STA" -c PREFIX
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963670809,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805200750","HAPPEN_TIME":1501963670809,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"4973863135535405472","info_":""}
    # hisysevent -r -t "STAw{0,6}" -c REGULAR
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963793206,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805200953","HAPPEN_TIME":1501963793206,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"16367997008075110557","info_":""}
    # hisysevent -r -t "STA\w+" -c REGULAR
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963863393,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201103","HAPPEN_TIME":1501963863393,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"5522352691813553392","info_":""}
    ```

- Command for subscribing to real-time system events by event domain and event name:

    ```shell
    hisysevent -r -o <domain> -n <eventName> [-c [WHOLE_WORD|PREFIX|REGULAR]]
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -o | Event domain used to filter subscribed real-time system events.|
    | -n | Event name used to filter subscribed real-time system events.|
    | -c | Matching rule for event domains and event names. The options can be **WHOLE_WORD**, PREFIX, or **REGULAR**.|

    Example:

    ```shell
    # hisysevent -r -o "RELIABILITY" -n "APP_FREEZE"
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963989773,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201309","HAPPEN_TIME":1501963989773,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"16367997008075110557","info_":""}
    # hisysevent -r -o "RELIABI\w{0,8}" -n "APP_FREEZE" -c REGULAR
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964144383,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201544","HAPPEN_TIME":1501964144383,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"13456525196455104060","info_":""}
    # hisysevent -r -o "RELIABI\w+" -c REGULAR
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964193466,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201633","HAPPEN_TIME":1501964193466,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"12675246910904037271","info_":""}
    ```

    > **NOTE**
    > If **-t**, **-o**, and **-n** are specified, the system checks whether the configured event tag is null. If the event tag is not null, the system filters system events based on the matching rules for the event tag. Otherwise, the system filters system events based on the matching rules for the event domain and event name.

- Command for subscribing to real-time system events by event type:

    ```shell
    hisysevent -r -g [FAULT|STATISTIC|SECURITY|BEHAVIOR]
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -g | Type of the system events to be subscribed to. The option can be **FAULT**, **STATISTIC**, **SECURITY**, or **BEHAVIOR**.|

    Example:

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


## Querying Historical System Events

- Command for querying historical system events:

    ```shell
    hisysevent -l
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -l | Query of historical system events based on the default settings. A maximum of 10,000 system events will be returned.|

- Command for querying historical system events within the specified period of time:

    ```shell
    hisysevent -l -s <begin time> -e <end time>
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -s | Original start timestamp for querying historical system events. Only system events generated after the start time are returned.|
    | -e | Original end timestamp for querying historical system events. Only system events generated before the end time are returned.|

    Example:

    ```shell
    # hisysevent -l -s 1501964222980 -e 1501964222996
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964222980,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201702","HAPPEN_TIME":1501964222980,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"10435592800188571430","info_":""}
    {"domain_":"GRAPHIC","name_":"NO_DRAW","type_":1,"time_":1501964222980,"tz_":"+0000","pid_":1505,"tid_":1585,"uid_":10002,"PID":1505,"UID":10002,"ABILITY_NAME":"","MSG":"It took 1957104259905ns to draw, UI took 0ns to draw, RSRenderThread took 8962625ns to draw, RSRenderThread dropped 0 UI Frames","level_":"MINOR","id_":"1708287249901948387","info_":"isResolved,eventId:0"}
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964222994,"tz_":"+0000","pid_":623,"tid_":1445,"uid_":1201,"SUB_EVENT_TYPE":"NO_DRAW","EVENT_TIME":"20170805201702","MODULE":"NO_DRAW","PNAME":"NO_DRAW","REASON":"NO_DRAW","DIAG_INFO":"","STACK":"SUMMARY:\n","HIVIEW_LOG_FILE_PATHS":["/data/log/faultlog/faultlogger/appfreeze-NO_DRAW-10002-20170805201702"],"DOMAIN":"GRAPHIC","STRING_ID":"NO_DRAW","PID":1505,"UID":10002,"PACKAGE_NAME":"NO_DRAW","PROCESS_NAME":"","MSG":"It took 1956945826265ns to draw, UI took 0ns to draw, RSRenderThread took 9863293ns to draw, RSRenderThread dropped 0 UI Frames\n","level_":"CRITICAL","tag_":"STABILITY","id_":"10448522101019619655","info_":""}
    ```

- Command for querying historical system events within the specified period of time:

    ```shell
    hisysevent -l -S <begin time> -E <end time>
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -S | Original start timestamp for querying historical system events. Only system events generated after the start time are returned.|
    | -E | Original end timestamp for querying historical system events. Only system events generated after the start time are returned.|

    Example:

    ```shell
    # hisysevent -l -S "2023-01-05 14:12:50" -E "2023-01-05 14:12:51"
    {"domain_":"GRAPHIC","name_":"JANK_FRAME_SKIP","type_":1,"time_":1672899170022,"tz_":"+0800","pid_":1499,"tid_":1573,"uid_":20010037,"PID":1499,"UID":20010037,"ABILITY_NAME":"com.ohos.launcher","MSG":"It took 587948726ns to draw, UI took 483016382ns to draw, RSRenderThread took 96616051ns to draw, RSRenderThread dropped 0 UI Frames","level_":"MINOR","id_":"11351278822867091090","info_":"","seq_":307}
    {"domain_":"AAFWK","name_":"START_ABILITY_ERROR","type_":1,"time_":1672899170108,"tz_":"+0800","pid_":550,"tid_":1127,"uid_":5523,"USER_ID":-1,"BUNDLE_NAME":"com.ohos.wallpaper","MODULE_NAME":"","ABILITY_NAME":"WallpaperExtAbility","ERROR_CODE":2097152,"level_":"MINOR","tag_":"ability","id_":"53589395004188308060","info_":"","seq_":313}
    {"domain_":"GRAPHIC","name_":"JANK_FRAME_SKIP","type_":1,"time_":1672899170305,"tz_":"+0800","pid_":1293,"tid_":1632,"uid_":10006,"PID":1293,"UID":10006,"ABILITY_NAME":"com.ohos.systemui","MSG":"It took 309597490ns to draw, UI took 92364718ns to draw, RSRenderThread took 205874105ns to draw, RSRenderThread dropped 1 UI Frames","level_":"MINOR","id_":"14843220972178010722","info_":"","seq_":314}
    {"domain_":"GRAPHIC","name_":"JANK_FRAME_SKIP","type_":1,"time_":1672899170350,"tz_":"+0800","pid_":1293,"tid_":1632,"uid_":10006,"PID":1293,"UID":10006,"ABILITY_NAME":"com.ohos.systemui","MSG":"It took 259782859ns to draw, UI took 33909753ns to draw, RSRenderThread took 44849879ns to draw, RSRenderThread dropped 5 UI Frames","level_":"MINOR","id_":"66610006717219916560","info_":"","seq_":315}
    {"domain_":"AAFWK","name_":"CONNECT_SERVICE_ERROR","type_":1,"time_":1672899170733,"tz_":"+0800","pid_":550,"tid_":1127,"uid_":5523,"USER_ID":100,"BUNDLE_NAME":"com.ohos.wallpaper","MODULE_NAME":"","ABILITY_NAME":"WallpaperExtAbility","ERROR_CODE":2097152,"level_":"MINOR","tag_":"ability","id_":"10040008376311927188","info_":"","seq_":317}
    {"domain_":"COMMONEVENT","name_":"PUBLISH","type_":2,"time_":1672899170063,"tz_":"+0800","pid_":550,"tid_":937,"uid_":5523,"USER_ID":-1,"PUBLISHER_BUNDLE_NAME":"","PID":0,"UID":1101,"EVENT_NAME":"usual.event.SCREEN_ON","level_":"MINOR","id_":"80996758983032931610","info_":"","seq_":308}
    ```

- Command for setting the maximum number of historical events that can be queried:

    ```shell
    hisysevent -l -m <max hisysevent count>
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -m | Maximum number of historical system events that can be queried. The number of returned system events is not more than the value of this parameter.|

    Example:

    ```shell
    # hisysevent -l -s 1501964222980 -e 1501964222996 -m 1
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964222980,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201702","HAPPEN_TIME":1501964222980,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"10435592800188571430","info_":""}
    ```

- Command for querying historical system events by event domain and event name:

    ```shell
    hisysevent -l -o <domain> -n <eventName> [-c WHOLE_WORD]
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -o | Event domain based on which historical system events are queried.|
    | -n | Event name based on which historical system events are queried.|
    | -c | Rule for matching the domain and name of historical system events. The option can only be **WHOLE_WORD**.|

    Example:

    ```shell
    # hisysevent -l -n "APP_FREEZE"
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963989773,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201309","HAPPEN_TIME":1501963989773,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"16367997008075110557","info_":""}
    # hisysevent -l -o "RELIABILITY"
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963989773,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201544","HAPPEN_TIME":1501963989773,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"13456525196455104060","info_":""}
    # hisysevent -l -o "RELIABILITY" -n "APP_FREEZE" -c WHOLE_WORD
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501963989773,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201633","HAPPEN_TIME":1501963989773,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"12675246910904037271","info_":""}
    ```

- Command for querying historical system events by event type:

    ```shell
    hisysevent -l -g [FAULT|STATISTIC|SECURITY|BEHAVIOR]
    ```

    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -g | Type of the historical system events to be queried. The option can be **FAULT**, **STATISTIC**, **SECURITY**, or **BEHAVIOR**.|

    Example:

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

## System Event Validity Check

- Enabling system event validity check

    ```shell
    hisysevent -v
    ```
	
    Description of command options:

    | Option| Description|
    | -------- | -------- |
    | -v | Used with the **-r** and **-l** commands. If system event validity check is enabled, invalid content contained in system events will be highlighted in red.|

    Example:

    ```shell
    # hisysevent -v -l -s 1501964222980 -e 1501964222996
    # The **HAPPEN_TIME** and **VERSION** fields are not configured in the YAML file for the **APP_FREEZE** event that belongs to the **RELIABILITY** domain. Therefore, the two fields are highlighted in red.
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964222980,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805201702","HAPPEN_TIME":1501964222980,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"10435592800188571430","info_":""}
    # hisysevent -v -r -o "RELIABILITY" -n "APP_FREEZE"
    {"domain_":"RELIABILITY","name_":"APP_FREEZE","type_":1,"time_":1501964644584,"pid_":1505,"uid_":10002,"FAULT_TYPE":"4","MODULE":"com.ohos.screenlock","REASON":"NO_DRAW","SUMMARY":"SUMMARY:\n","LOG_PATH":"/data/log/faultlog/faultlogger/appfreeze-com.ohos.screenlock-10002-20170805202404","HAPPEN_TIME":1501964644584,"VERSION":"1.0.0","level_":"CRITICAL","tag_":"STABILITY","id_":"11097868872446282676","info_":""}
    ```
