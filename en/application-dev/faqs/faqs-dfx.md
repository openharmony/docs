# DFX Development


## How do I flush HiLog information to disks? (API 9)

**Solution**

Run the **hilog -w start -f ckTest -l 1M -n 5 -m zlib -j 11** command.

The log file is saved in the **/data/log/hilog/** directory.

**Parameters:**

```
-**-w**: Starts a log flushing task. **start** means to start the task, and **stop** means to stop the task.
-**-f**: Sets the log file name.
-**-l**: Sets the size of a single log file. The unit can be B, KB, MB, or GB.
-**-n**: Sets the maximum number of log files. When the number of log files exceeds the specified value, the earliest log file will be overwritten. The value range is [2,1000].
-**-m**: Specifies the log file compression algorithm.
-**-j**: Specifies the task ID. The value ranges from **10** to **0xffffffffff**.
For more details about parameters, run the **hilog --help** command.
```


## How do I print only HiLog information of the current application? (API 9)

**Solution**

Use the hilog command line tool to filter the logs of the current application.

**hilog -T xxx**: filtering logs by tag.

**hilog –D xxx**: filtering logs by domain.

**hilog -e**: matching log content based on the tag, domain, and pid by using regular expressions. Multi-layered filtering, combination filtering, and reverse filtering are supported.


## How do I locate the fault when the application crashes? (API 9)

**Solution**

Method 1: Locate the crash-related code based on the service log.

Method 2: View the error information in the crash file. The crash file is located at **/data/log/faultlog/faultlogger/**.


## Is HiLog or console recommended for log printing? How do I set the domain if HiLog is used? (API 9)

The console encapsulates the HiLog system with the default parameter configuration. It is mainly used in the application development and debugging phase.

HiLog is recommended because it supports log classification and processing in a unified manner. For details, see [@ohos.hilog (HiLog)](../reference/apis-performance-analysis-kit/js-apis-hilog.md).

The value of the **domain** parameter in the HiLog API ranges from **0x0** to **0xFFFF**. You are advised to customize the value as required.


## What is the maximum length of a log record when HiLog Is used? Is it configurable? (API 9)

The maximum length of a log record is 1,024 characters, and it is not changeable.


## What is the purpose of using private in printing of formatted logs? (API 9)

**Symptom**

**private** is displayed in HiLog information when format parameters are of the %d or %s type in C++.

**Solution**

When format parameters such as **%d** and **%s** are directly used, the standard system uses **private** to replace the actual data for printing by default to prevent data leakage. To print the actual data, replace **%d** with **%{public}d** or replace **%s** with **%{public}s**.


## What should I do if the hilog.debug log cannot be printed? (API 9)

**Solution**

Run **hdc std shell hilog -b D** to turn on the debugging switch.


## Can I separate multiple strings by spaces in the tag parameter of the HiLog API? (API 9)

Yes.


## How does HiLog print the log information marked with the \{private\} tag? (API 9)

**Solution**

To print the log information marked with the \{private\} tag, run the command to disable the privacy mode: hdc shell hilog -p off


## What are the cash log collection and performance troubleshooting functions provided by the HiLog system? (API 9)

**Symptom**

How do I use the cash log collection and performance troubleshooting functions provided by the HiLog system?

**Solution**

FaultLogger: collects crash logs. For details, see [FaultLogger](../reference/apis-performance-analysis-kit/js-apis-faultLogger.md).

HiChecker: detects potential faults. For details, see [HiChecker](../reference/apis-performance-analysis-kit/js-apis-hichecker.md).

hiTraceMeter: implements performance tracing. For details, see [hiTraceMeter](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md).


## How do I control log output? (API 9)

**Symptom**

The output log varies according to environment requirements.

**Solution**

You can run the following command to adjust the log level to print the desired logs:  

hdc shell hilog -L &lt;D/I/W/E/F&gt;


## Is there a limit on the tag length of HiLog? (API 9)

The length of the entire tag is 32.


## How do I view the appfreeze information in the logs? (API 9)

Try the following procedure:

1. Check the reason for the event. Fault location methods and examples are provided specifically to different reasons.

2. Check the MSG information.

3. Check the application stack information in OpenStacktraceCatcher as well as the HiLog information for the operation that leads to the event.

4. Check the PeerBinderCatcher process to see if the current process is suspended by the peer binder. If there is a synchronous wait related to the current process, the corresponding PeerBinder Stacktrace information will be logged. It contains the stack information of the peer process that leads to suspension of the current process.

5. Check the CPU usage of system processes and the memory usage of the current process.

## How do I view stack traces for error logs generated in ArkCompiler? (API version 10)

**Solution**

To view stack traces for exceptions thrown during native code execution, run the following commands:

Enable backtrace:

```bash
hdc shell param set persist.ark.properties 0x125c
hdc shell reboot
```  
Restore defaults:

```bash
hdc shell param set persist.ark.properties 0x105c
hdc shell reboot
```  

## How do I view ArkTS parameters and switches of hdc? (API version 10)

**Solution**

To view all ArkTS parameters and switches of hdc, run **hdc shell ark** in the command line interface.
