# Using HiLog to Print Logs (ArkTS)


During application development, you can log from your application's key code. You can find out how your application is running through logs. For example, the logs can tell you whether the application is running correctly, whether the code running time sequence is normal, and whether the running logic and branch is normal).


To print logs, you can call HiLog or console APIs. This document covers HiLog APIs. For details about the console APIs, see [console](../reference/common/js-apis-logs.md).


## Available APIs

HiLog defines five log levels: DEBUG, INFO, WARN, ERROR, and FATAL, and provides the following APIs to output logs at different levels. For details, see [hilog](../reference/apis-performance-analysis-kit/js-apis-hilog.md).

| API| Description| 
| -------- | -------- |
| isLoggable(domain: number, tag: string, level: LogLevel) | Checks whether logs are printable based on the specified service domain, log tag, and log level.|
| debug(domain: number, tag: string, format: string, ...args: any[]) | Outputs debug-level logs. This level of log only applies to information for debugging purposes.<br>To set the output log level to **DEBUG**, run the **hdc shell hilogcat** command in the CLI or in the **Terminal** window of DevEco Studio.|
| info(domain: number, tag: string, format: string, ...args: any[]) | Outputs info-level logs. This level of log includes informative messages.|
| warn(domain: number, tag: string, format: string, ...args: any[]) | Outputs warn-level logs. This level of log signifies potential issues that may lead to errors or unexpected behavior.|
| error(domain: number, tag: string, format: string, ...args: any[]) | Outputs error-level logs. This level of log indicates errors.|
| fatal(domain: number, tag: string, format: string, ...args: any[]) | Outputs fatal-level logs. This level of log tells that a critical condition or unrecoverable error occurs.|

### Parameters

> **NOTE**
> 
> - The domain and tag specified in **isLoggable()** must be the same as those used in the logging API.
> 
> - The level specified in **isLoggable()** must match the logging API.

- **domain**: service domain of logs. The value range is 0x0000 to 0xFFFF. You can define the value as required.

- **tag**: log identifier. It can be any string. You are advised to use this parameter to identify the class or service behavior of a method call.

- **level**: log level. For details about the value, see [LogLevel](../reference/apis-performance-analysis-kit/js-apis-hilog.md#loglevel).

- **format**: format in which logs are output. The value is a string in the "%{private flag}specifier" format.
  | Privacy Flag| Description|
  | -------- | -------- |
  | private | Parameters are displayed as **\<private>** in printed logs.|
  | public | Parameters are displayed in plaintext as they are in printed logs.|
  | -| If no private flag is specified, the default value **private** is used.|

  | Specifier| Description| Example|
  | -------- | -------- | -------- |
  | d/i | Prints logs of the **number** and **bigint** types.| 123 |
  | s | Prints logs of the **string**, **undefined**, **bool**, and **null** types.| "123" |

  You can set several parameters in the format string. For example, **%s** in the format string **%s World** identifies a variable of the string type, whose value is defined in **args**.

  To enable parameters identified by **{private}** to be displayed as they are, run **hilog -p off**.

- **args**: the parameter list corresponding to the parameter type specified in the format string. There can be no or multiple parameters in the list. The number and type of parameters must be mapped to the identifiers in the format string.

## Constraints

A log contains a maximum of 4096 bytes. If this limit is exceeded, excess content will be discarded.

## Example

This example shows how to log each click on the added button.

1. Create a project, with **Empty Ability** as the template.

2. On the project configuration page, set **Model** to **Stage**.

3. In the **Project** window, choose **entry** > **src** > **main** > **ets** > **pages**, open the **Index.ets** file, add a button, and enable logging upon a click on the button.
   The sample code is as follows:

   ```ts
   // Index.ets
   
   import hilog from '@ohos.hilog';
   
   @Entry
   @Component
   struct Index {
     build() {
       Row() {
         Column() {
           // Add a button to respond to user clicks.
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
           // Bind the onClick event to the button and print logs when the button is clicked.
           .onClick(() => {
             hilog.isLoggable(0xFF00, "testTag", hilog.LogLevel.INFO);    
             hilog.info(0xFF00, "testTag", "%{public}s World %{public}d", "hello", 3);
           })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

   The following is sample code for outputting an info-level log:

   ```txt
   "%{public}s World %{public}d"
   ```

   where **%{public}s** indicates a string whose privacy flag is **public**, and **%{public}d** an integer whose privacy flag is **public**.

4. Run the project on a real device, and touch **Next** on the app/service screen on the device.

5. At the bottom of DevEco Studio, switch to the **Log** tab and set the filter criteria.
   Specifically, select the current device and process, set the log level to **Verbose**, and enter **testTag** in the search box. Only the logs that meet the filter criteria are displayed in the window.

   In this example, the printed log is "hello World 3."
