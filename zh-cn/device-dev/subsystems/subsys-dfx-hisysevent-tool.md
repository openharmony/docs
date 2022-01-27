# HiSysEvent工具使用指导<a name="ZH-CN_TOPIC_0000001231614021"></a>

-   [概述](#section1886702718521)
-   [订阅实时HiSysEvent事件相关命令](#section1210623418527)
-   [查询历史HiSysEvent事件相关命令](#section1210623418539)

## 概述<a name="section1886702718521"></a>

目前在系统的/system/bin目录下预置了hisysevent工具，开发者可以通过此工具订阅实时系统事件及查询历史HiSysEvent事件。

## 订阅实时HiSysEvent事件相关命令<a name="section1210623418527"></a>

实时订阅HiSysEvent事件的基础命令：

**hisysevent -r**

选项说明：

| 选项名称 | 功能说明  |
| -------- | --------- |
| -r&nbsp;        | 以缺省设置实时订阅HiSysEvent事件，在此种订阅方式下有任何实时HiSysEvent事件产生，都会在控制台上打印此HiSysEvent事件 | 

打开调试模式：

**hisysevent -r -d**

选项说明：

| 选项名称 | 功能说明  |
| -------- | --------- |
| -d       | 在调试模式下实时订阅HiSysEvent事件 | 

通过事件标签方式订阅实时系统事件：

**hisysevnet -r -t \<tag\> \[-c \[WHOLE_WORD|PREFIX|REGULAR\]\]**

选项说明：

| 选项名称 | 功能说明  |
| -------- | --------- |
| -t&nbsp;        | 设置实时订阅的HiSysEvent事件标签，用来过滤订阅的HiSysEvent事件 |
| -c&nbsp;        | 设置实时订阅的HiSysEvent事件标签匹配规则，有“WHOLE_WORD”、“PREFIX”、“REGULAR”三种匹配规则|

4. 通过事件领域及事件名称的方式订阅实时系统事件：

**hisysevent -r -o \<domain\> -n \<eventName\> \[-c \[WHOLE_WORD|PREFIX|REGULAR\]\]**

| 选项名称 | 功能说明  |
| -------- | --------- |
| -o       | 设置实时订阅的HiSysEvent事件领域，用来过滤订阅的HiSysEvent事件 |
| -n       | 设置实时订阅的HiSysEvent事件名称，用来过滤订阅的HiSysEvent事件|
| -c       | 设置实时订阅的HiSysEvent事件领域及事件名称的匹配规则，有“WHOLE_WORD”、“PREFIX”、“REGULAR”三种匹配规则|

>![](../public_sys-resources/icon-note.gif) **说明：** 
>当同时通过-t、-o及-n指定了相关订阅规则参数设置，则判断设置的事件标签是否为空，若不为空，则使用事件标签规则进行订阅，否则使用事件领域及事件名称订阅规则进行订阅。

    

## 查询历史HiSysEvent事件相关命令<a name="section1210623418539"></a>

查询历史HiSysEvent事件的基础命令：

**hisysevent -l**

选项说明：

| 选项名称 | 功能说明  |
| -------- | --------- |
| -l       | 以缺省设置查询历史HiSysEvent事件，此次查询会返回所有落盘的HiSysEvent事件 | 

通过设置开始/结束时间，过滤查询历史HiSysEvent事件的结果的命令：

**hisysevent -l -s \<begin time\> -e \<end time\>**

选项说明：

| 选项名称 | 功能说明  |
| -------- | --------- |
| -s       | 设置查询历史HiSysEvent事件的开始时间，此次查询只会返回不早于该时间点的HiSysEvent事件 |
| -e       | 设置查询历史HiSysEvent事件的结束时间，此次查询只会返回不晚于该时间点的HiSysEvent事件 |

通过设置最大数量值，限制查询历史HiSysEvent事件的数量：

**hisysevent -l -m \<max hisysevent count\>**

选项说明：

| 选项名称 | 功能说明  |
| -------- | --------- |
| -m       | 设置查询历史HiSysEvent事件的数量，此次查询返回的HiSysEvent事件数目不会多于此值 |