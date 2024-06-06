# Analyzing JS Crash (Process Crash)

When an application crashes dues to a JS exception, it throws the exception and generates a JS crash log file. You can view the log to locate the problematic code and analyze the cause of the crash.

Read on to find out how to obtain and analyze process crash logs.

## How to Obtain

The process crash log is a type of fault log managed together with the app freeze and JS application crash logs by the FaultLogger module. You can obtain process crash logs in any of the following methods:

- Method 1: DevEco Studio

    DevEco Studio collects process crash logs from the device-specific **/data/log/faultlog/faultlogger/** directory to FaultLog.

- Method 2: faultLogger APIs

    The FaultLogger module provides APIs to query various fault information. For details, see [@ohos.faultLogger](../reference/apis-performance-analysis-kit/js-apis-faultLogger.md).
- Method 3: Shell

    You can find fault logs in the device-specific **/data/log/faultlog/faultlogger/** directory. The log files are named in the format of jscrash-process name-process UID-time (seconds level). They contain information such as the device name, system version, and process crash call stack.

    ![](figures/jscrash.png)
## Process Crash Log Analysis

Regardless of the method you use for obtaining logs, you can identify the crash cause, mostly application issues, based on the error message and stack trace in the logs.

The following describes the fields in the process crash log.

```
Build info:ALN-AL00 4.1.0.30(SP4C00E30R4P8log) <- Version information
Module name:com.example.myapplication <- Module name
Version:1.0.0 <- Version number
Pid:579 <- Process ID
Uid:0 <- User ID
Reason:TypeError <- Cause
Error message:Cannot read property c of undefined <- Error message
Cannot get SourceMap info, dump raw stack: <- The JS stack failed to parse the row number and column number through the SourceMap.
SourceCode:
        var a = b.c;   <- Location of the problematic code
                ^
Stacktrace:
    at onPageShow (entry/src/main/ets/pages/Index.ets:7:13)  <- Call stack of the problematic code
           ^                                      ^
         Function name and row and column numbers of the problematic code
```

## Log Analysis

Log analysis may be performed in either of the following cases:

- Case 1: A hyperlink is provided to go to the problematic code, and it works.

  If the link or offset address in the stack trace information in the fault log points to a line of code of the current project, a hyperlink is provided. You can click the hyperlink in DevEco Studio to go to the code line.

- Case 2: The hyperlink provided to go to the problematic code does not work.

  If the "Cannot get Source Map info, dump raw stack" message is displayed, the JS stack fails to obtain the row and column numbers for the problematic code. In this case, clicking the provided hyperlink in the log in DevEco Studio navigates you to an incorrect position or displays an error that indicates the position does not exist.

  When an error occurs during the running of application code, the error stack information is printed. If the TS stack fails to obtain the row and column numbers for ArkTS code, the suffix of the error stack is still ets. You need to compile the intermediate product in the **build** directory to generate TS code and locate the corresponding line of problematic code in JS.
