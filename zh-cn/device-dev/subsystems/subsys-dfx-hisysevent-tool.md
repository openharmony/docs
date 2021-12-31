# HiSysEvent工具使用指导<a name="ZH-CN_TOPIC_0000001231614021"></a>

-   [概述](#section1886702718521)
-   [使用指导](#section1210623418527)

## 概述<a name="section1886702718521"></a>

目前系统预制了HiSysEvent小工具，可以通过命令行参数，设置查询条件，查询满足要求的HiSysEvent系统事件，支撑开发者在开发过程中是否打点成功，以及故障定位时系统所发生的事件等研发场景。

## 使用指导<a name="section1210623418527"></a>

1.  HiSysEvent工具的参数：

    工具预置在/system/bin目录下，命令可以在任意目录执行。

    ```
    hisysevent [-r | -l [-s <time> -e <time> -m <count>]]
    -r    get real hisysevent log.
    -l -s <begin time> -e <end time> -m <max hisysevent count>
    get history hisysevent log, begin time should not be earlier than end time.
    ```

2.  查询实时HiSysEvent事件的命令：

    ```
    hisysevent -r
    ```

    当实时HiSysEvent事件过来的时候，会在控制台上打印一条HiSysEvent事件。

3.  查询历史HiSysEvent事件的命令：

    ```
    hisysevent -l -s <begin time> -e <end time> -m <max hisysevent count>
    ```

    其中-s和-e分别指定了事件生成的开始时间和结束时间，如果没有-s或者-e，代表查询时间无下限/无上限。

    -m参数制定了本次查询最多返回的时间条数。


