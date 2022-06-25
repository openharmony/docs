# HiSysEvent Tool Usage<a name="EN-US_TOPIC_0000001231614021"></a>

## Overview<a name="section1886702718521"></a>

The HiSysEvent tool is a command line tool preconfigured in the **/system/bin** directory of the system. You can use this tool to subscribe to real-time system events or query historical system vents.

## Subscribing to Real-Time System Events<a name="section1210623418527"></a>

-   Command for subscribing to real-time system events:

    ```
    hisysevent -r
    ```

    Description of command options:

    | Option| Description|
    | -------- | --------- |
    | -r&nbsp;        | Subscribes to real-time system events based on the default settings. When this option is specified, any real-time system event will be printed on the console.|

-   Command for enabling the debugging mode:

    ```
    hisysevent -r -d
    ```

    Description of command options:

    | Option| Description|
    | -------- | --------- |
    | -d       | Subscribes to real-time system events in debugging mode.|

-   Command for subscribing to real-time system events by event tag:

    ```
    hisysevent -r -t <tag> [-c [WHOLE_WORD|PREFIX|REGULAR]]
    ```

    Description of command options:

    | Option| Description|
    | -------- | --------- |
    | -t&nbsp;        | Event tag used to filter subscribed real-time system events.|
    | -c&nbsp;        | Matching rule for event tags. The options can be **WHOLE_WORD**, **PREFIX**, or **REGULAR**.|

    Example:

    ```
    # hisysevent -r -t "TAG" -c PREFIX
    {"domain_":"ARKUI","name_":"UI_BLOCK_6S","type_":1,"time_":1501940269812,"tz_":"+0000","tag_":"TAG1","pid_":1428,"tid_":1452,"uid_":10001,"level_":"CRITICAL","info_":""}
    # hisysevent -r -t "TA\w{0,1}" -c REGULAR
    {"domain_":"WINDOWMANAGER","name_":"NO_FOCUS_WINDOW","type_":1,"time_":1501940269802,"tz_":"+0000","tag_":"TAG","pid_":1428,"tid_":1433,"uid_":10001,"level_":"CRITICAL","info_":""}
    {"domain_":"ARKUI","name_":"UI_BLOCK_6S","type_":1,"time_":1501940269812,"tz_":"+0000","tag_":"TAG1","pid_":1428,"tid_":1452,"uid_":10001,"level_":"CRITICAL","info_":""}
    # hisysevent -r -t "TA\w+" -c REGULAR
    {"domain_":"WINDOWMANAGER","name_":"NO_FOCUS_WINDOW","type_":1,"time_":1501940269802,"tz_":"+0000","tag_":"TAG","pid_":1428,"tid_":1433,"uid_":10001,"level_":"CRITICAL","info_":""}
    {"domain_":"ARKUI","name_":"UI_BLOCK_6S","type_":1,"time_":1501940269812,"tz_":"+0000","tag_":"TAG1","pid_":1428,"tid_":1452,"uid_":10001,"level_":"CRITICAL","info_":""}
    ```

-   Command for subscribing to real-time system events by event domain and event name:

    ```
    hisysevent -r -o <domain> -n <eventName> [-c [WHOLE_WORD|PREFIX|REGULAR]]
    ```

    Description of command options:

    | Option| Description|
    | -------- | --------- |
    | -o       | Event domain used to filter subscribed real-time system events.|
    | -n       | Event name used to filter subscribed real-time system events.|
    | -c       | Matching rule for event domains and event names. The options can be **WHOLE_WORD**, **PREFIX**, or **REGULAR**.|

    Example:

    ```
    # hisysevent -r -o "DOMAINA" -n "EVENTNAMEA"
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":1501940269802,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    # hisysevent -r -o "DOMA\w{0,10}" -n "EVENT\w+" -c REULAR
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":1501940269802,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    {"domain_":"DOMAINABC","name_":"EVENTNAMEABC","type_":1,"time_":1501940269938,"tz_":"+0000","pid_":1428,"tid_":1336,"uid_":10002,"level_":"CRITICAL","info_":""}
    # hisysevent -r -o "DOMA\w{0,10}" -c REGULAR
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":1501940269802,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    {"domain_":"DOMAINABC","name_":"EVENTNAMEABC","type_":1,"time_":1501940269938,"tz_":"+0000","pid_":1428,"tid_":1336,"uid_":10002,"level_":"CRITICAL","info_":""}
    {"domain_":"DOMAINABC","name_":"EVENTNAMEB","type_":1,"time_":1501940279938,"tz_":"+0000","pid_":1428,"tid_":1344,"uid_":10002,"level_":"CRITICAL","info_":""}
    ```

    >![](../public_sys-resources/icon-note.gif) **NOTE:**
    >If **-t**, **-o**, and **-n** are specified, the system checks whether the configured event tag is null. If the event tag is not null, the system filters system events based on the matching rules for the event tag. Otherwise, the system filters system events based on the matching rules for the event domain and event name.

## Querying Historical System Events<a name="section1210623418539"></a>

-   Command for querying historical system events:

    ```
    hisysevent -l
    ```

    Description of command options:

    | Option| Description|
    | -------- | --------- |
    | -l       | Queries historical system events based on the default settings. A maximum of 1,000 latest system events will be returned.|

-   Command for querying historical system events within the specified period of time:

    ```
    hisysevent -l -s <begin time> -e <end time>
    ```

    Description of command options:

    | Option| Description|
    | -------- | --------- |
    | -s       | Start time for querying historical system events. Only system events generated after the start time are returned.|
    | -e       | End time for querying historical system events. Only system events generated before the end time are returned.|

    Example:

    ```
    # hisysevent -l -s 20207388633 -e 20207389000
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388633,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388634,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388900,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207389000,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    ```

-   Command for setting the maximum number of historical events that can be queried:

    ```
    hisysevent -l -m <max hisysevent count>
    ```

    Description of command options:

    | Option| Description|
    | -------- | --------- |
    | -m       | Maximum number of historical system events that can be queried. The value ranges from **0** to **1000**. The number of returned system events is not more than the value of this parameter.|

    Example:

    ```
    # hisysevent -l -s 20207388633 -e 20207389000 -m 3
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388634,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388900,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207389000,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    # hisysevent -l -m 2
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388633,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    {"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388634,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
    ```

