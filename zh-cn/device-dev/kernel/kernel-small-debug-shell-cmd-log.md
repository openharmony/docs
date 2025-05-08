# log

## 命令功能

log命令用于修改&amp;查询日志配置。

## 命令格式

log level [_levelNum_]

## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| levelNum | 配置日志打印等级。 | [0, 5] | 

## 使用指南

- 该命令依赖于LOSCFG_SHELL_LK，使用时通过menuconfig在配置项中开启"Enable Shell lk"：
  Debug ---&gt; Enable a Debug Version ---&gt; Enable Shell ---&gt; Enable Shell lK。

- log level命令用于配置日志的打印等级，包括6个等级。
  TRACE_EMG = 0,

  TRACE_COMMON = 1,

  TRACE_ERROR = 2,

  TRACE_WARN = 3,

  TRACE_INFO = 4,

  TRACE_DEBUG = 5。

  若level不在有效范围内，会打印提示信息。


- 开源小型系统源码设置level 为4或者5会有超多打印。

## 使用实例

举例：输入log level 3。

## 输出说明

**示例** 设置当前日志打印级别为3。

```
OHOS # log level 3
Set current log level WARN
```
