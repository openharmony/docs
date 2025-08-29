# Viewing HiTraceMeter Logs

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @qq_437963121-->
<!--Designer: @MontSaintMichel-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## Viewing Logs on DevEco Studio

In DevEco Studio Profiler, you can display HiTraceMeter logs to analyze the CPU usage and thread running status of applications and services and view the CPU consumption in a specified period. For details, see [CPU Activity Analysis: CPU](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-session-cpu).


## Viewing Logs Using Command Line Tools

1. Set up the environment for OpenHarmony Device Connector (hdc). For details, see [Environment Setup](hdc.md#environment-setup).

2. In the **Terminal** window of DevEco Studio or the CLI on the host, run the **hdc shell** command to connect to the device, and run the [HiTrace](hitrace.md) command on the device to enable the HiTraceMeter logging service.

   ```shell
   PS D:\xxx\xxx> hdc shell
   $ hitrace --trace_begin app
   ```

3. Run the program that enables the HiTraceMeter logging on the device.

4. Use HiTrace to collect trace information in text format and save the trace file to the **/data/local/tmp/** directory of the device. For details, see [Capturing Text Trace Data in Snapshot Mode](hitrace.md#capturing-text-trace-data-in-snapshot-mode).

5. Exit the device, enter the host, and export the HiTraceMeter text logs to the current directory. (Change the file name **trace.ftrace** in the following command based on the file name set during collection.)

   ```shell
   $ exit
   PS D:\xxx\xxx> hdc file recv /data/local/tmp/trace.ftrace ./
   ```

6. You can search for keywords such as the logging name in the HiTraceMeter logs to check whether the logging is successful.

7. Display and analyze the HiTraceMeter text file.

   - Import the log file to DevEco Studio for analysis.

      In DevEco Studio Profiler, select **Open File** to import the HiTraceMeter log file. 

      For details, see [CPU Activity Analysis: CPU](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-insight-session-cpu).
   - Use [Smartperf_Host](https://gitee.com/openharmony/developtools_smartperf_host) for analysis. You can download the tool from [developtools_smartperf_host Release](https://gitee.com/openharmony/developtools_smartperf_host/releases).


## User-Mode Trace Format


### User-Mode Trace Format Before API version 19

| Trace Type| Format When HiTraceChain is Enabled| Format When HiTraceChain is Disabled|
| -------- | -------- | -------- |
| Start a synchronous trace logging| B\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name | B\|PID\|H:name |
| Stop a synchronous trace logging| E\|PID\| | E\|PID\| |
| Start an asynchronous trace logging| S\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name taskId | S\|PID\|H:name taskId |
| Stop an asynchronous trace logging| F\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name taskId | F\|PID\|H:name taskId |
| Log an integer trace| C\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name count | C\|PID\|H:name count |

> **NOTE**
>
> The maximum length of a user-mode trace is 512 characters. Excess characters will be truncated.


**Fields**


- **B/E/S/F/C**

  - **B**: Starts a synchronous trace logging.
  - **E**: Stops a synchronous trace logging.
  - **S**: Starts an asynchronous trace logging.
  - **F**: Stops an asynchronous trace logging.
  - **C**: Logs an integer trace.

- **PID**

  Process ID.

- **[ChainId,SpanId,ParentSpanId]\#**

  When HiTraceChain is enabled, **HiTraceId** is recorded in the trace logging and separated from the **name** field using the hashtag (\#).

  When HiTraceChain is not enabled, this field is not included in the trace logs.

  - **ChainId**: Chain ID of **HiTraceId**.
  - **SpanId**: Span ID of **HiTraceId**.
  - **ParentSpanId**: Parent span ID of **HiTraceId**.

- **name**

  Logging name or integer variable name.

- **taskId**

  Asynchronous trace ID, which is used together with the **name** field to match the start and stop of an asynchronous trace logging.

  Use a space to separate **taskId** and **name**.

- **count**

  Integer value.

  Use a space to separate **count** and **name**.


### User-Mode Trace Format Since API Version 19

Vertical bars (|) are used as separators for fields. For subsequent new fields, use the **| + Field** format to add them to the end of the current user-mode trace format.

| Trace Type| Format When HiTraceChain is Enabled| Format When HiTraceChain is Disabled|
| -------- | -------- | -------- |
| Start a synchronous trace logging| B\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name\|%level%tag\|customArgs | B\|PID\|H:name\|%level%tag\|customArgs |
| Stop a synchronous trace logging| E\|PID\|%level%tag | E\|PID\|%level%tag |
| Start an asynchronous trace logging| S\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name\|taskId\|%level%tag\|customCategory\|customArgs | S\|PID\|H:name\|taskId\|%level%tag\|customCategory\|customArgs |
| Stop an asynchronous trace logging| F\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name\|taskId\|%level%tag | F\|PID\|H:name\|taskId\|%level%tag |
| Log an integer trace| C\|PID\|H:[ChainId,SpanId,ParentSpanId]\#name\|count\|%level%tag | C\|PID\|H:name\|count\|%level%tag |

> **NOTE**
>
> The maximum length of a user-mode trace is 512 characters. It is recommended that the total length of **name**, **customCategory**, and **customArgs** be less than or equal to 420 characters to avoid truncation.


**Fields**


- **B/E/S/F/C**

  - **B**: Starts a synchronous trace logging.
  - **E**: Stops a synchronous trace logging.
  - **S**: Starts an asynchronous trace logging.
  - **F**: Stops an asynchronous trace logging.
  - **C**: Logs an integer trace.

- **PID**

  Process ID.

- **[ChainId,SpanId,ParentSpanId]\#**

  When HiTraceChain is enabled, **HiTraceId** is recorded in the trace logging and separated from the **name** field using the hashtag (\#).

  When HiTraceChain is not enabled, this field is not included in the trace logs.

  - **ChainId**: Chain ID of **HiTraceId**.
  - **SpanId**: Span ID of **HiTraceId**.
  - **ParentSpanId**: Parent span ID of **HiTraceId**.

- **name**

  Logging name or integer variable name.

- **taskId**

  Asynchronous trace ID, which is used together with the **name** field to match the start and stop of an asynchronous trace logging.

- **count**

  Integer value.

- **%level**

  The **level** field passed through the logging API, indicating the logging level. The value can be **D**, **I**, **C**, or **M**.

  For the mapping between the **level** field and **%level**, see [HiTraceOutputLevel](#hitraceoutputlevel).

  > **NOTE**
  >
  > Before API version 19, the trace logging API does not have the **level** field. By default, the trace logging level is **COMMERCIAL**.

- **%tag**

  Tag type of the trace logging, which is represented by a two-digit number. The value can contain multiple two-digit numbers in ascending order. For example, **B|1314|H:TestFunction|I3062** indicates that the trace logging belongs to the **HITRACE_TAG_OHOS** and **HITRACE_TAG_APP** tags.

  For details about the mapping between tag names, tag values, and **%tag**, see [HiTraceMeter Tags](#hitracemeter-tags).

  > **NOTE**
  >
  > The NDK C/C++ and ArkTs/JS HiTraceMeter performance logging APIs do not have fields corresponding to **%tag**. They are application logging APIs, whose tag name is **HITRACE_TAG_APP** and the corresponding **%tag** value in the user-mode trace is **62**.

- **customCategory**

  Custom category name.

  In the trace analysis tool, asynchronous traces with the same category name in the same process are displayed in the same lane.

- **customArgs**

  Custom key-value pair, in the format of **key=value**. Multiple key-value pairs are separated by commas (,), for example, **key1=value1,key2=value2**.

  In the trace analysis tool, the parsing results of **customArgs** that meet the format requirements are displayed in key-value pairs.


**NOTE**


In practice, if the **customCategory** and **customArgs** fields are not required, pass empty strings. (The two fields are involved only in the APIs for starting the synchronous trace logging and asynchronous trace logging.)


The following describes whether the two fields are empty strings in the user-mode trace format when HiTraceChain is disabled. For details about how to use HiTraceChain, see [Using HiTraceChain](hitracechain-intro.md).


In trace logging APIs earlier than API version 19, the two fields are considered as empty strings by default.


- Synchronous trace logging start API

  - **customArgs** is not an empty string.

     ```text
     B|PID|H:name|%level%tag|customArgs
     ```

  - **customArgs** is an empty string.

     ```text
     B|PID|H:name|%level%tag
     ```

- Asynchronous trace logging start API

  - **customCategory** and **customArgs** are not empty strings.

     ```text
     S|PID|H:name|taskId|%level%tag|customCategory|customArgs
     ```

  - **customCategory** is an empty string, and **customArgs** is not an empty string.

     ```text
     S|PID|H:name|taskId|%level%tag||customArgs
     ```

  - **customCategory** is not an empty string, and **customArgs** is an empty string.

     ```text
     S|PID|H:name|taskId|%level%tag|customCategory
     ```

  - **customCategory** and **customArgs** are both empty strings.

     ```text
     S|PID|H:name|taskId|%level%tag
     ```


### HiTraceMeter Tags

| Name| Value| %tag |
| -------- | -------- | -------- |
| HITRACE_TAG_ALWAYS | 1ULL &lt;&lt; 0 | 00 |
| HITRACE_TAG_COMMERCIAL | 1ULL &lt;&lt; 5 | 05 |
| HITRACE_TAG_DRM | 1ULL &lt;&lt; 6 | 06 |
| HITRACE_TAG_SECURITY | 1ULL &lt;&lt; 7 | 07 |
| HITRACE_TAG_ANIMATION | 1ULL &lt;&lt; 9 | 09 |
| HITRACE_TAG_PUSH | 1ULL &lt;&lt; 10 | 10 |
| HITRACE_TAG_VIRSE | 1ULL &lt;&lt; 11 | 11 |
| HITRACE_TAG_MUSL | 1ULL &lt;&lt; 12 | 12 |
| HITRACE_TAG_FFRT | 1ULL &lt;&lt; 13 | 13 |
| HITRACE_TAG_CLOUD | 1ULL &lt;&lt; 14 | 14 |
| HITRACE_TAG_DEV_AUTH | 1ULL &lt;&lt; 15 | 15 |
| HITRACE_TAG_COMMONLIBRARY | 1ULL &lt;&lt; 16 | 16 |
| HITRACE_TAG_HDCD | 1ULL &lt;&lt; 17 | 17 |
| HITRACE_TAG_HDF | 1ULL &lt;&lt; 18 | 18 |
| HITRACE_TAG_USB | 1ULL &lt;&lt; 19 | 19 |
| HITRACE_TAG_INTERCONNECTION | 1ULL &lt;&lt; 20 | 20 |
| HITRACE_TAG_DLP_CREDENTIAL | 1ULL &lt;&lt; 21 | 21 |
| HITRACE_TAG_ACCESS_CONTROL | 1ULL &lt;&lt; 22 | 22 |
| HITRACE_TAG_NET | 1ULL &lt;&lt; 23 | 23 |
| HITRACE_TAG_NWEB | 1ULL &lt;&lt; 24 | 24 |
| HITRACE_TAG_HUKS | 1ULL &lt;&lt; 25 | 25 |
| HITRACE_TAG_USERIAM | 1ULL &lt;&lt; 26 | 26 |
| HITRACE_TAG_DISTRIBUTED_AUDIO | 1ULL &lt;&lt; 27 | 27 |
| HITRACE_TAG_DLSM | 1ULL &lt;&lt; 28 | 28 |
| HITRACE_TAG_FILEMANAGEMENT | 1ULL &lt;&lt; 29 | 29 |
| HITRACE_TAG_OHOS | 1ULL &lt;&lt; 30 | 30 |
| HITRACE_TAG_ABILITY_MANAGER | 1ULL &lt;&lt; 31 | 31 |
| HITRACE_TAG_ZCAMERA | 1ULL &lt;&lt; 32 | 32 |
| HITRACE_TAG_ZMEDIA | 1ULL &lt;&lt; 33 | 33 |
| HITRACE_TAG_ZIMAGE | 1ULL &lt;&lt; 34 | 34 |
| HITRACE_TAG_ZAUDIO | 1ULL &lt;&lt; 35 | 35 |
| HITRACE_TAG_DISTRIBUTEDDATA | 1ULL &lt;&lt; 36 | 36 |
| HITRACE_TAG_MDFS | 1ULL &lt;&lt; 37 | 37 |
| HITRACE_TAG_GRAPHIC_AGP | 1ULL &lt;&lt; 38 | 38 |
| HITRACE_TAG_ACE | 1ULL &lt;&lt; 39 | 39 |
| HITRACE_TAG_NOTIFICATION | 1ULL &lt;&lt; 40 | 40 |
| HITRACE_TAG_MISC | 1ULL &lt;&lt; 41 | 41 |
| HITRACE_TAG_MULTIMODALINPUT | 1ULL &lt;&lt; 42 | 42 |
| HITRACE_TAG_SENSORS | 1ULL &lt;&lt; 43 | 43 |
| HITRACE_TAG_MSDP | 1ULL &lt;&lt; 44 | 44 |
| HITRACE_TAG_DSOFTBUS | 1ULL &lt;&lt; 45 | 45 |
| HITRACE_TAG_RPC | 1ULL &lt;&lt; 46 | 46 |
| HITRACE_TAG_ARK | 1ULL &lt;&lt; 47 | 47 |
| HITRACE_TAG_WINDOW_MANAGER | 1ULL &lt;&lt; 48 | 48 |
| HITRACE_TAG_ACCOUNT_MANAGER | 1ULL &lt;&lt; 49 | 49 |
| HITRACE_TAG_DISTRIBUTED_SCREEN | 1ULL &lt;&lt; 50 | 50 |
| HITRACE_TAG_DISTRIBUTED_CAMERA | 1ULL &lt;&lt; 51 | 51 |
| HITRACE_TAG_DISTRIBUTED_HARDWARE_FWK | 1ULL &lt;&lt; 52 | 52 |
| HITRACE_TAG_GLOBAL_RESMGR | 1ULL &lt;&lt; 53 | 53 |
| HITRACE_TAG_DEVICE_MANAGER | 1ULL &lt;&lt; 54 | 54 |
| HITRACE_TAG_SAMGR | 1ULL &lt;&lt; 55 | 55 |
| HITRACE_TAG_POWER | 1ULL &lt;&lt; 56 | 56 |
| HITRACE_TAG_DISTRIBUTED_SCHEDULE | 1ULL &lt;&lt; 57 | 57 |
| HITRACE_TAG_DEVICE_PROFILE | 1ULL &lt;&lt; 58 | 58 |
| HITRACE_TAG_DISTRIBUTED_INPUT | 1ULL &lt;&lt; 59 | 59 |
| HITRACE_TAG_BLUETOOTH | 1ULL &lt;&lt; 60 | 60 |
| HITRACE_TAG_ACCESSIBILITY_MANAGER | 1ULL &lt;&lt; 61 | 61 |
| HITRACE_TAG_APP | 1ULL &lt;&lt; 62 | 62 |


### HiTraceOutputLevel

| Enum Name (C/C++)| Enum Name (ArkTS/JS)| Value| %level |
| -------- | -------- | -------- | -------- |
| HITRACE_LEVEL_DEBUG | DEBUG | 0 | D |
| HITRACE_LEVEL_INFO | INFO | 1 | I |
| HITRACE_LEVEL_CRITICAL | CRITICAL | 2 | C |
| HITRACE_LEVEL_COMMERCIAL | COMMERCIAL | 3 | M |
| HITRACE_LEVEL_MAX | MAX | 3 | M |
