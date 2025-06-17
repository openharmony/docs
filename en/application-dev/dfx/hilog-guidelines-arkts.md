# Using HiLog (ArkTS)


During application development, you can log from application's key code. Through logs, you can find out how the application is running. For example, the logs can tell you whether the application is running properly, and whether the code execution sequence and logic branch are correct.


To print logs, you can use HiLog or console APIs. This topic focuses on how to use HiLog APIs. For details about the console APIs, see [console](../reference/common/js-apis-logs.md).


## Available APIs

HiLog defines five log levels (DEBUG, INFO, WARN, ERROR, and FATAL) and provides APIs to output logs of different levels. For details about the APIs, see [HiLog](../reference/apis-performance-analysis-kit/js-apis-hilog.md).

| API| Description| 
| -------- | -------- |
| isLoggable(domain: number, tag: string, level: LogLevel) | Checks whether logs of the specified domain, tag, and level can be printed.|
| debug(domain: number, tag: string, format: string, ...args: any[]) | Outputs DEBUG logs, which are used only for debugging applications and services.<br>To set the log level to **DEBUG**, run the **hdc shell hilog -b D** command in the **Terminal** window of DevEco Studio or in the **cmd** window.|
| info(domain: number, tag: string, format: string, ...args: any[]) | Outputs INFO logs, which provide prevalent, highlighting events related to key service processes.|
| warn(domain: number, tag: string, format: string, ...args: any[]) | Outputs WARN logs, which indicate issues that have little impact on the system.|
| error(domain: number, tag: string, format: string, ...args: any[]) | Outputs ERROR logs, which indicate program or functional errors.|
| fatal(domain: number, tag: string, format: string, ...args: any[]) | Outputs FATAL logs, which indicate program or functionality crashes that cannot be rectified.|
| setMinLogLevel(level: LogLevel) | Sets the minimum log level. When a process prints logs, both the minimum log level and the global log level are verified. Therefore, the minimum log level cannot be lower than the global log level. The default value of [global log level](hilog.md#displaying-and-setting-log-levels) is **Info**.|

### Parameters

> **NOTE**
> 
> - The domain and tag specified in **isLoggable()** must be the same as those of the logging API.
> 
> - The log level specified in **isLoggable()** must match that of the logging API.

- **domain**: service domain of logs. The value range is 0x0000 to 0xFFFF. You can define the value as required.

- **tag**: log identifier. It can be any string. You are advised to use this parameter to identify the class or service behavior of a method call. A tag can contain a maximum of 31 bytes. If a tag contains more than 31 bytes, it will be truncated. Chinese characters are not recommended because garbled characters or alignment problems may occur.

- **level**: log level. For details about the value, see [LogLevel](../reference/apis-performance-analysis-kit/js-apis-hilog.md#loglevel).

- **format**: format of the log to output. The value is a string in the "%{private flag}specifier" format.
  | Private Flag| Description|
  | -------- | -------- |
  | private | The output is **\<private>**, which indicates that the log information is invisible.|
  | public | The log information is displayed.|
  | Not specified| The default value **\<private>** is used.|

  | Specifier| Description| Example|
  | -------- | -------- | -------- |
  | d/i | Prints logs of the **number** and **bigint** types.| 123 |
  | s | Prints logs of the **string**, **undefined**, **boolean**, and **null** types.| "123" |
  | o/O | Prints logs of the **object**, **undefined**, and **null** types.<br>This flag is supported since API version 20.| obj |

  You can set multiple parameters in the **format** string, for example, **%s World**, where **%s** is a variable of the string type and its value is defined by **args**. <!--Del-->

  To display the log masked by {**private**} in debugging, run the **hilog -p off** command.
<!--DelEnd-->

- **args**: parameters of the types specified by **specifier** in **format**. This parameter can be left blank. The number and type of parameters must match **specifier**.

## Constraints

The maximum size of a log file is 4096 bytes. Excess content will be discarded.

## Example

Add a click event in a button, which prints a log when the button is clicked.

1. Create a project, with **Empty Ability** as the template.

2. On the project configuration page, set **Model** to **Stage**.

3. In the **Project** window, choose **entry** > **src** > **main** > **ets** > **pages**, open the **Index.ets** file, add a button to enable a log to be printed when the button is clicked.
   The sample code is as follows:

   ```ts
   // Index.ets
   
   import { hilog } from '@kit.PerformanceAnalysisKit';
   
   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         Column() {
           // Add a button named Next.
           Button() {
             Text('Next')
               .fontSize(30)
               .fontWeight(FontWeight.Bold)
           }
           .type(ButtonType.Capsule)
           .margin({
             top: 20
           })
           .backgroundColor('#0D9FFB')
           .width('40%')
           .height('5%')
           // Add a onClick event with the button to print a log when the button is clicked.
           .onClick(() => {
             hilog.isLoggable(0xFF00, "testTag", hilog.LogLevel.INFO);
             hilog.info(0xFF00, "testTag", "%{public}s World %{public}d", "hello", 3);
             class Person {
                constructor(name: string, age: number) {
                  this.name = name;
                  this.age = age;
                }
                name: string;
                age:  number;
             }
             let peter: Person = new Person("peter", 15);
             hilog.info(0xFF00, "testTag", "peter is %{public}o", peter);
             // Set the minimum log level to Warn.
             hilog.setMinLogLevel(hilog.LogLevel.WARN);
             hilog.info(0x0000, 'testTag', 'this is an info level log');
             hilog.error(0x0000, 'testTag', 'this is an error level log');
           })
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
   The variable parameter *%{public}o* is a public object.

4. Run the project on a real device, and click the **Next** button on the app/service.

5. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria.
   Specifically, select the current device and process, set the log level to **Verbose**, and enter **testTag** in the search box. Then, only the logs that meet the filter criteria are displayed.

   The log result is as follows:
   ```txt
   01-02 08:18:24.947   30988-30988   A0ff00/testTag                  com.example.hilogemo  I     hello World 3
   01-02 08:18:24.947   30988-30988   A0ff00/testTag                  com.example.hilogemo  I     peter is {"name":"peter","age":15}
   01-02 08:18:24.947   30988-30988   A00000/testTag                  com.example.hilogemo  E     this is an error level log
   ```

<!--RP1-->
<!--RP1End-->
