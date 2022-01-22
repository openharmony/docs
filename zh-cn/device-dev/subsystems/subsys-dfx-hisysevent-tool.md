# HiSysEvent工具使用指导<a name="ZH-CN_TOPIC_0000001231614021"></a>

-   [概述](#section1886702718521)
-   [使用指导](#section1210623418527)

## 概述<a name="section1886702718521"></a>

目前系统预制了HiSysEvent小工具，可以通过命令行参数，设置查询条件，查询满足要求的HiSysEvent系统事件，支撑开发者在开发过程中是否打点成功，以及故障定位时系统所发生的事件等研发场景。

## 使用指导<a name="section1210623418527"></a>

1.  HiSysEvent工具的参数：

    工具预置在/system/bin目录下，命令可以在任意目录执行。

    ```
    hisysevent [-r [-d | -c [WHOLE_WORD|PREFIX|REGULAR] -t <tag> | -c [WHOLE_WORD|PREFIX|REGULAR] -o <domain> -n <eventName> ]
        | -l [-s <time> -e <time> -m <count>]]
    -r    subscribe on empty domain, eventname and tag
    -r -c [WHOLE_WORD|PREFIX|REGULAR] -t <tag>, subscribe on tag
    -r -c [WHOLE_WORD|PREFIX|REGULAR] -o <domain> -n <eventName>, subscribe on domain and event name
    -r -d set debug mode, both options must appear at the same time.
    -l -s <begin time> -e <end time> -m <max hisysevent count>
        get history hisysevent log, begin time should not be earlier than end time.
    ```

2.  订阅实时HiSysEvent事件的命令：

    ```
    hisysevent -r
    ```

    当有实时HiSysEvent事件发生，会在控制台上打印该HiSysEvent事件。

    ```
    hisysevent -r -c [WHOLE_WORD|PREFIX|REGULAR] -t <tag>
    ```

    通过事件标签规则订阅实时HiSysEvent事件，当有与指定的事件标签以指定的匹配类型匹配的实时HiSysEvent事件发生，会在控制台上打印该HiSysEvent事件。
        -c用来指定匹配规则，包括“全词匹配”、“前缀匹配”以及“正则匹配”三种模式，如果没有-c，则默认使用全词匹配模式。
        -t用来指定字符串和HiSysEvent事件的标签进行匹配，如果没有-t，则使用空字符串。

	```
    hisysevent -r -c [WHOLE_WORD|PREFIX|REGULAR] -o <domain> -n <eventName>
    ```

    通过事件领域及事件名称规则订阅实时HiSysEvent事件，当有与指定的的事件领域及事件名称以指定的匹配类型匹配的实时HiSysEvent事件发生，会在控制台上打印该HiSysEvent事件。
        -c 用来指定匹配规则，包括“全词匹配”、“前缀匹配”以及“正则匹配”三种模式，如果没有-c，则默认使用全词匹配类型。
        -o 用来指定事件领域，如果没有-o，则使用空字符串。
        -n 用来指定事件名称，如果没有-n，则使用空字符串。

    当同时通过-t、-o及-n指定了相关订阅规则参数设置，则判断设置的事件标签是否为空，若不为空，则使用事件标签规则进行订阅，否则使用事件领域及事件名称订阅规则进行订阅。

3.  查询历史HiSysEvent事件的命令：

    ```
    hisysevent -l -s <begin time> -e <end time> -m <max hisysevent count>
    ```

    其中-s和-e分别指定了事件生成的开始时间和结束时间，如果没有-s或者-e，代表查询时间无下限/无上限。

    -m参数制定了本次查询最多返回的时间条数。


