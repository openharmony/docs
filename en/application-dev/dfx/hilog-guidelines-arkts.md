# Using HiLog (ArkTS)

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @suxunquan-->
<!--Designer: @milkbread123-->
<!--Tester: @yufeifei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=a8c53dc5daa36369fc6c8d63a66370d1710e95f5 translatedAt=2026-07-31T01:31:24.701Z pushedAt=2026-07-31T07:28:11.065Z -->

During application development, you can log from application's key code. Through logs, you can find out how the application is running. For example, the logs can tell you whether the application is running properly, and whether the code execution sequence and logic branch are correct.

To print logs, you can use HiLog or Console APIs. This topic focuses on how to use HiLog APIs. For details about the Console APIs, see [Console](../reference/common/js-apis-logs.md).

## Available APIs

HiLog defines five log levels: DEBUG, INFO, WARN, ERROR, and FATAL, and provides corresponding methods to output logs at different levels. The following table lists the APIs. For details, see [@ohos.hilog](../reference/apis-performance-analysis-kit/js-apis-hilog.md).

| API| Description|
| -------- | -------- |
| isLoggable(domain: number, tag: string, level: LogLevel) | Checks whether logs of the specified domain, tag, and level can be printed.|
| debug(domain: number, tag: string, format: string, ...args: any[]) | Outputs logs at the DEBUG level. Used only for app/service debugging.<br>In the DevEco Studio terminal window or cmd, run the command "hdc shell hilog -b D" to set the log level to DEBUG. |
| info(domain: number, tag: string, format: string, ...args: any[]) | Outputs INFO logs, which provide prevalent, highlighting events related to key service processes.|
| warn(domain: number, tag: string, format: string, ...args: any[]) | Outputs WARN logs, which indicate issues that have little impact on the system.|
| error(domain: number, tag: string, format: string, ...args: any[]) | Outputs ERROR logs, which indicate program or functional errors.|
| fatal(domain: number, tag: string, format: string, ...args: any[]) | Outputs FATAL logs, which indicate program or functionality crashes that cannot be rectified.|
| setMinLogLevel(level: LogLevel) | Sets the minimum log level for app log printing to block low-level log printing.<br>**Note:** This API is supported since API version 15. |
| setLogLevel(level: LogLevel, prefer: PreferStrategy) | Sets the minimum log level for the current app process. You can configure different preference strategies.<br>**Note:** This API is supported since API version 21. |
| setOutputType(type: OutputType) | Sets the output type of hilog. You can select different log output modes.<br>**Note:** This API is supported since API version 26.0.0. |
| setOutputTypeByDomainID(type: OutputType, domainIDs: Array&lt;number&gt;, isExclude: boolean) | Sets the output type of hilog based on domain IDs. You can select different log output modes.<br>**Note:** This API is supported since API version 26.0.0. |
| getOutputType() | Returns the current output type of hilog.<br>**Note:** This API is supported since API version 26.0.0. |
| clean() | Deletes all hilog logs in the sandbox.<br>**Note:** This API is supported since API version 26.0.0. |
| flush() | Force flushes logs from the buffer to disk.<br>**Note:** This API is supported since API version 26.0.0. |
| getLogFile(latestSeconds: number) | Returns the list of hilog log file paths in the sandbox for a specified recent time period.<br>**Note:** This API is supported since API version 26.0.0. |
| getOutputDir() | Returns the path of hilog logs in the sandbox.<br>**Note:** This API is supported since API version 26.0.0. |

> **NOTE**
>
> If the set log level is lower than the [global log level](hilog.md#displaying-and-setting-log-levels), the **setMinLogLevel()** setting does not take effect.
>
> In the debug applications, the **setMinLogLevel()** and **setLogLevel()** functions do not take effect.

### Parameters

- **domain**: service domain of logs. The value range is 0x0000 to 0xFFFF. You can define the value as required.

- **tag**: log identifier. It can be any string. You are advised to use this parameter to identify the class or service behavior of a method call. A tag can contain a maximum of 31 bytes. If a tag exceeds this limit, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.

- **level**: log level. For details about the value, see [LogLevel](../reference/apis-performance-analysis-kit/js-apis-hilog.md#loglevel).

- **prefer**: preference strategy. For details about the values, see [PreferStrategy](../reference/apis-performance-analysis-kit/js-apis-hilog.md#preferstrategy21).

- **format**: format of the log to output. The value is a string in the "%{private flag}specifier" format.

- **type**: output type of hilog. For valid values, see [OutputType](../reference/apis-performance-analysis-kit/js-apis-hilog.md#outputtype).

- **domainIDs**: list of domains for which the output type is set. The value ranges from 0x0000 to 0xFFFF.

- **isExclude**: whether **domainIDs** takes effect for the specified output type. The value **true** means that the domains in the **domainIDs** list are excluded and the setting takes effect only for domains not in the list. The value **false** means that the setting takes effect only for the domains in the list.

- **latestSeconds**: time period from the current moment, in seconds. The value must be greater than 0.

  | Private Flag| Description| 
  | -------- | -------- |
  | private | The output is **\<private>**, which indicates that the log information is invisible.| 
  | public | The log information is displayed.| 
  | Not specified| The default value **\<private>** is used.| 

  | Specifier| Description| Example|
  | -------- | -------- | -------- |
  | d/i | Prints logs of the **number** and **bigint** types.| 123 |
  | s | Prints logs of the **string**, **undefined**, **boolean**, and **null** types.| "123" |
  | o/O | Supports printing the object, undefined, and null types.<br>This capability is available since API version 20. | { 'name': "Jack", 'age': 22 } |

  You can set multiple parameters in the **format** string, for example, **%{public}s World**, where **%{public}s** indicates a variable of the string type and its value is defined by **args**. 

  The debug application does not have a privacy control mechanism. Parameters can be displayed in plaintext when any of the preceding private flags is used to print logs.

- **args**: parameters of the types specified by **specifier** in **format**. This parameter can be left blank. The number and type of parameters must match **specifier**.

> **NOTE**
>
> - The domain and tag specified in **isLoggable()** must be the same as those of the logging API.
>
> - The log level specified in **isLoggable()** must match that of the logging API.
>
> - **isLoggable()** returns **true** if the specified logs can be printed; returns **false** otherwise.
>
>   For [debug applications](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916), logs of all levels can be printed.
>
>   For [release applications](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-hvigor-compilation-options-customizing-guide#section192461528194916), logs are printed only if the log level is not lower than the global log level.
>   During debugging, you can change the log level. For details, see [Displaying and Setting Log Levels](hilog.md#displaying-and-setting-log-levels).

## Constraints

The maximum size of a log file is 4096 bytes. Excess content will be discarded.

## How to Develop

Add a tap event to the button so that a log is printed when the button is tapped.

1. Create a project, with **Empty Ability** as the template.

2. In the project configuration page, select **Stage** for **Model**. If the **Model** option is not available, no configuration is required, and **Stage** is used by default.

3. In the **Project** window, choose **entry** > **src** > **main** > **ets** > **pages**, open the **Index.ets** file, and add two buttons to print logs when tapped.

   The sample code is as follows:

   <!-- @[HiLog_ArkTS](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/PerformanceAnalysisKit/Hilog/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { hilog } from '@kit.PerformanceAnalysisKit';
   // ...
   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         Column() {
           // Add a hilog button to respond to user taps.
           Button($r('app.string.HiLogArkTS_Button'))
             .type(ButtonType.Capsule)
             .margin({
               top: 20
             })
             .backgroundColor('#0D9FFB')
             .width('40%')
             .height('5%')
             // Bind the onClick event to the button. When the button is tapped, a log is printed. Note that the release HAP package cannot print DEBUG-level logs by default.
             .onClick(() => {
               //isLoggable checks whether the domainID and tag meet the current log level for printing. It is recommended to check the return value.
               let ret = hilog.isLoggable(0xFF00, 'testTag', hilog.LogLevel.INFO);
               if (ret) {
                 hilog.info(0xFF00, 'testTag',
                 'A log with a domainID of 0xFF00 and a label of testTag can print logs at the Info level or higher.');
               }
               hilog.info(0xFF00, 'testTag', '%{public}s World %{public}d', 'hello', 3);
               class Person {
                 constructor(name: string, age: number) {
                   this.name = name;
                   this.age = age;
                 }
                 public name: string;
                 public age:  number;
               }
               let peter: Person = new Person('peter', 15);
               hilog.info(0xFF00, 'testTag', 'peter is %{public}o', peter);
               // Set the minimum log printing level for the app. After the setting is complete, logs below the WARN level cannot be printed.
               hilog.setMinLogLevel(hilog.LogLevel.WARN);
               hilog.info(0xFF00, 'testTag', 'this is an info level log');
               hilog.error(0xFF00, 'testTag', 'this is an error level log');
               // Set the minimum log printing level for the app's PREFER_OPEN_LOG policy. After the setting is complete, logs at or above the INFO level can be printed.
               hilog.setLogLevel(hilog.LogLevel.INFO, hilog.PreferStrategy.PREFER_OPEN_LOG);
               hilog.info(0xFF00, 'testTag', 'this is an another info level log');
               hilog.error(0xFF00, 'testTag', 'this is an another error level log');
             })
           // Add a sandbox log button to respond to user taps.
           Button($r('app.string.SandboxLogArkTS_Button'))
             .type(ButtonType.Capsule)
             .margin({
               top: 20
             })
             .backgroundColor('#0D9FFB')
             .width('40%')
             .height('5%')
             // Bind the onClick event to the button. When the button is tapped, a log is printed. Note that the release HAP package cannot print DEBUG-level logs by default.
             .onClick(() => {
               // Set the log output type to SHARE_SANDBOX_WITH_CONSOLE to output logs to both the public sandbox and the console.
               hilog.setOutputType(hilog.OutputType.SHARE_SANDBOX_WITH_CONSOLE);
               let lastType = hilog.getOutputType();
               hilog.info(0xFF00, 'testTag', 'current log type:%{public}d', lastType);
               let dir = hilog.getOutputDir();
               hilog.info(0xFF00, 'testTag', 'current log dir:%{public}s', dir);
               hilog.info(0xFF00, 'testTag', 'hilog_info_test');
               hilog.debug(0xFF00, 'testTag', 'hilog_debug_test');
               hilog.warn(0xFF00, 'testTag', 'hilog_warn_test');
               hilog.fatal(0xFF00, 'testTag', 'hilog_fatal_test');
               hilog.error(0xFF00, 'testTag', 'hilog_error_test');
               // Obtain log files written within the last 2 minutes in the sandbox directory.
               let logs = hilog.getLogFile(120);
               hilog.info(0xFF00, 'testTag', 'current log files:%{public}s', logs.toString());
               // Flush the sandbox logs to the disk.
               hilog.flush();
             })
   // ...
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

   For example, output an INFO log in the following format: 

   ```txt
   '%{public}s World %{public}d'
   ```

   *%{public}s* indicates a string, and *%{public}d* indicates an integer. Both of them are displayed in plaintext.

   To output objects, use the following format string:

   ```txt
   'peter is %{public}o'
   ```

   The variadic parameter **%{public}o** is a public object.

4. Run the project on a real device, and click the **Next** button on the app/service.

5. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria.

   Specifically, select the current device and process, set the log level to **Debug**, and enter **testTag** in the search box. Then, only the logs that meet the filter criteria are displayed.

   Tap the **HiLogArkTS** button to view HiLog logs.

   <!--RP3-->

   The log output is as follows:

   ```txt
   08-05 06:32:35.928   10753-10753   A0ff00/testTag                  com.samples.hilog     I     A log with a domainID of 0xFF00 and a label of testTag can print logs at the Info level or higher.
   08-05 06:32:35.928   10753-10753   A0ff00/testTag                  com.samples.hilog     I     hello World 3
   08-05 06:32:35.928   10753-10753   A0ff00/testTag                  com.samples.hilog     I     peter is {"name":"peter","age":15}
   08-05 06:32:35.928   10753-10753   A0ff00/testTag                  com.samples.hilog     E     this is an error level log
   08-05 06:32:35.928   10753-10753   A0ff00/testTag                  com.samples.hilog     I     this is an another info level log
   08-05 06:32:35.928   10753-10753   A0ff00/testTag                  com.samples.hilog     E     this is an another error level log
   ```

   <!--RP3End-->

6. Tap the **SandboxLog** button, set the search content to **testTag**, and the current log dir printed in the console is the path of the current sandbox.

7. View the latest log file generated in the sandbox.

   The content of the sandbox log is as follows:

   ```txt
   08-05 06:32:35.928 10753 10753 I A0ff00/testTag: current log type:4
   08-05 06:32:35.928 10753 10753 I A0ff00/testTag: current log dir:/data/storage/el2/log/hiapplog
   08-05 06:32:35.929 10753 10753 I A0ff00/testTag: hilog_info_test
   08-05 06:32:35.929 10753 10753 D A0ff00/testTag: hilog_debug_test
   08-05 06:32:35.929 10753 10753 W A0ff00/testTag: hilog_warn_test
   08-05 06:32:35.929 10753 10753 F A0ff00/testTag: hilog_fatal_test
   08-05 06:32:35.929 10753 10753 E A0ff00/testTag: hilog_error_test
   08-05 06:32:35.930 10753 10753 I A0ff00/testTag: current log files:hiapplog.10753.001.20170805-063235.log
   ```

<!--RP1-->
<!--RP1End-->