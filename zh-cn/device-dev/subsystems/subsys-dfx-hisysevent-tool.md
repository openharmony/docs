# HiSysEvent工具


## 概述

目前在系统的/system/bin目录下预置了hisysevent工具，开发者可以通过此工具实时订阅HiSysEvent事件及查询历史HiSysEvent事件。


## 实时订阅HiSysEvent事件相关命令

- 实时订阅HiSysEvent事件的基础命令：

  
```
hisysevent -r
```

选项说明：

  | 选项名称 | 功能说明 | 
| -------- | -------- |
| -r | 以缺省设置实时订阅HiSysEvent事件，在此种订阅方式下有任何实时HiSysEvent事件产生，都会在控制台上打印此HiSysEvent事件 | 

- 打开调试模式：

  
```
hisysevent -r -d
```

选项说明：

  | 选项名称 | 功能说明 | 
| -------- | -------- |
| -d | 在调试模式下实时订阅HiSysEvent事件 | 

- 通过事件标签方式实时订阅HiSysEvent事件：

  
```
hisysevent -r -t <tag> [-c [WHOLE_WORD|PREFIX|REGULAR]]
```

选项说明：

  | 选项名称 | 功能说明 | 
| -------- | -------- |
| -t | 设置实时订阅的HiSysEvent事件标签，用来过滤订阅的HiSysEvent事件。 | 
| -c | 设置实时订阅的HiSysEvent事件标签匹配规则，有“WHOLE_WORD”、“PREFIX”、“REGULAR”三种匹配规则。 | 

命令实例：

  
```
# hisysevent -r -t "TAG" -c PREFIX   {"domain_":"ARKUI","name_":"UI_BLOCK_6S","type_":1,"time_":1501940269812,"tz_":"+0000","tag_":"TAG1","pid_":1428,"tid_":1452,"uid_":10001,"level_":"CRITICAL","info_":""}
# hisysevent -r -t "TAw{0,1}" -c REGULAR {"domain_":"WINDOWMANAGER","name_":"NO_FOCUS_WINDOW","type_":1,"time_":1501940269802,"tz_":"+0000","tag_":"TAG","pid_":1428,"tid_":1433,"uid_":10001,"level_":"CRITICAL","info_":""}   {"domain_":"ARKUI","name_":"UI_BLOCK_6S","type_":1,"time_":1501940269812,"tz_":"+0000","tag_":"TAG1","pid_":1428,"tid_":1452,"uid_":10001,"level_":"CRITICAL","info_":""}
# hisysevent -r -t "TAw+" -c REGULAR    {"domain_":"WINDOWMANAGER","name_":"NO_FOCUS_WINDOW","type_":1,"time_":1501940269802,"tz_":"+0000","tag_":"TAG","pid_":1428,"tid_":1433,"uid_":10001,"level_":"CRITICAL","info_":""}   {"domain_":"ARKUI","name_":"UI_BLOCK_6S","type_":1,"time_":1501940269812,"tz_":"+0000","tag_":"TAG1","pid_":1428,"tid_":1452,"uid_":10001,"level_":"CRITICAL","info_":""}
```

- 通过事件领域及事件名称的方式实时订阅HiSysEvent事件：

  
```
hisysevent -r -o <domain> -n <eventName> [-c [WHOLE_WORD|PREFIX|REGULAR]]
```

选项说明：

  | 选项名称 | 功能说明 | 
| -------- | -------- |
| -o | 设置实时订阅的HiSysEvent事件领域，用来过滤订阅的HiSysEvent事件。 | 
| -n | 设置实时订阅的HiSysEvent事件名称，用来过滤订阅的HiSysEvent事件。 | 
| -c | 设置实时订阅的HiSysEvent事件领域及事件名称的匹配规则，有“WHOLE_WORD”、“PREFIX”、“REGULAR”三种匹配规则。 | 

命令实例：

  
```
# hisysevent -r -o "DOMAINA" -n "EVENTNAMEA"
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":1501940269802,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
# hisysevent -r -o "DOMAw{0,10}" -n "EVENTw+" -c REULAR
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":1501940269802,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}  {"domain_":"DOMAINABC","name_":"EVENTNAMEABC","type_":1,"time_":1501940269938,"tz_":"+0000","pid_":1428,"tid_":1336,"uid_":10002,"level_":"CRITICAL","info_":""}
# hisysevent -r -o "DOMAw{0,10}" -c REGULAR
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":1501940269802,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}   {"domain_":"DOMAINABC","name_":"EVENTNAMEABC","type_":1,"time_":1501940269938,"tz_":"+0000","pid_":1428,"tid_":1336,"uid_":10002,"level_":"CRITICAL","info_":""}
{"domain_":"DOMAINABC","name_":"EVENTNAMEB","type_":1,"time_":1501940279938,"tz_":"+0000","pid_":1428,"tid_":1344,"uid_":10002,"level_":"CRITICAL","info_":""}
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 当同时通过-t、-o及-n指定了相关订阅规则参数设置，则判断设置的事件标签是否为空，若不为空，则使用事件标签规则进行订阅，否则使用事件领域及事件名称订阅规则进行订阅。


## 查询历史HiSysEvent事件相关命令

- 查询历史HiSysEvent事件的基础命令：

  
```
hisysevent -l
```

选项说明：

  | 选项名称 | 功能说明 | 
| -------- | -------- |
| -l | 以缺省设置查询历史HiSysEvent事件，此次查询会返回最近不多于1000条的HiSysEvent事件。 | 

- 通过设置开始/结束时间，过滤查询历史HiSysEvent事件的结果的命令：

  
```
hisysevent -l -s <begin time> -e <end time>
```

选项说明：

  | 选项名称 | 功能说明 | 
| -------- | -------- |
| -s | 设置查询历史HiSysEvent事件的开始时间，此次查询只会返回不早于该时间点的HiSysEvent事件。 | 
| -e | 设置查询历史HiSysEvent事件的结束时间，此次查询只会返回不晚于该时间点的HiSysEvent事件。 | 

命令实例：

  
```
# hisysevent -l -s 20207388633 -e 20207389000
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388633,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388634,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388900,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207389000,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
```

- 通过设置最大数量值，限制查询历史HiSysEvent事件的数量：

  
```
hisysevent -l -m <max hisysevent count>
```

选项说明：

  | 选项名称 | 功能说明 | 
| -------- | -------- |
| -m | 设置查询历史HiSysEvent事件的数量，有效值范围[0,1000]，此次查询返回的HiSysEvent事件数目不会多于此值。 | 

命令实例：

  
```
# hisysevent -l -s 20207388633 -e 20207389000 -m 3
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388634,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388900,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207389000,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
# hisysevent -l -m 2
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388633,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
{"domain_":"DOMAINA","name_":"EVENTNAMEA","type_":1,"time_":20207388634,"tz_":"+0000","pid_":1428,"tid_":1333,"uid_":10002,"level_":"CRITICAL","info_":""}
```
