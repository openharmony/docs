# log


## Command Function

This command is used to set and query log configuration.


## Syntax

log level [_levelNum_]



## Parameters

**Table 1** Parameter description

| Parameter| Description| Value Range|
| -------- | -------- | -------- |
| levelNum | Specifies the level of logs to print.| [0, 5] |


## Usage Guidelines

- This command can be used only after **LOSCFG_SHELL_LK** is enabled. Before using this command, set **Enable Shell lk** to **Yes** on **menuconfig**.
  **Debug** ---&gt; **Enable a Debug Version** ---&gt; **Enable Shell** ---&gt; **Enable Shell lK**

- The **log level** command sets the log level, which can be any of the following:
  TRACE_EMG = 0,

  TRACE_COMMON = 1,

  TRACE_ERROR = 2,

  TRACE_WARN = 3,

  TRACE_INFO = 4,

  TRACE_DEBUG = 5

  If the log level specified is not within the value range, a message will be displayed.


- If the log level is set to **4** or **5** in the source code of an OpenHarmony small system, a large number of logs will be printed.


## Example

Run **log level 3**.


## Output

The log print level is set to WARN.


```
OHOS # log level 3
Set current log level WARN
```
