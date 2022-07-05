# FaultLogger Development


## Overview


### Function

FaultLogger is a maintenance and debugging log framework provided by OpenHarmony. It enables unified detection, log collection, log storage, and log reporting for application, ability, and system service process crashes. It is available for the standard system and the Linux kernel-based small system.

FaultLogger is responsible for fault recording of OpenHarmony. It runs on the following two components based on the service object:

- HiView: serves functional modules at the application layer and native layer. It manages various fault information in the system and provides APIs for modules to query faults.

- FaultLoggerd: serves the crash process. It collects information about abnormal daemon processes in C/C++ and obtains the process call stack.

The following figure shows the process of handling a process crash based on the FaultLogger service.

  **Figure 1** Process crash handling flowchart

![process_crash_handling](figure/process_crash_handling.png)

1. After the signal processor is installed, the **DFX_SignalHandler** function detects and responds to the process crash exception signal.

2. **SignalHandler** forks a child process after detecting the exception signal and runs **ProcessDump** to dump the stack information of the crashed process and thread.

3. **ProcessDump** then writes a log to the temporary storage directory in FaultLoggerd, generating a full crash log.

4. FaultLoggerd reports the fault through the **AddFaultLog()** API provided by HiView. HiView handles the fault, generates a simple crash log, and reports a HiSysEvent.

With this design, a small-system with limited resources can obtain logs for locating crash faults as long as FaultLoggerd is deployed.


### Use Cases

FaultLoggerd provides a lightweight approach for you to locate crash or suspension problems during development and testing.

It is applicable to the following scenarios:

  **Table 1** Application scenarios of the Faultloggerd module

| Scenario| Tool| Usage| 
| -------- | -------- | -------- |
| To understand the function call sequence| DumpCatcher&nbsp;API | See [Using DumpCatcher to Obtain the Call Stack](#using-dumpcatcher-to-obtain-the-call-stack).| 
| Application suspension or high CPU usage| ProcessDump | See [Using ProcessDump to Obtain the Call Stack](#using-processdump-to-obtain-the-call-stack).| 
| Signal crash not handled by the process| Crash log and addr2line tool| See [Locating Faults Based on Crash Logs](#locating-faults-based-on-crash-logs).| 


## Using DumpCatcher to Obtain the Call Stack


### Available APIs

DumpCatcher can capture the call stack of a specified process (thread) on OpenHarmony.

  Table 2 DumpCatcher APIs

| Class| API| Description| 
| -------- | -------- | -------- |
| DfxDumpCatcher | bool&nbsp;DumpCatch(const&nbsp;int&nbsp;pid,&nbsp;const&nbsp;int&nbsp;tid,&nbsp;std::string&amp;&nbsp;msg) | Return value:<br>**true**: Back trace is successful. Related information is stored in the **msg** string object.<br>**false**: Back trace failed.<br>Input arguments:<br>**pid**: target process ID.<br>**tid**: target thread ID. If all threads in the process need to be back traced, set **tid** to **0**.<br>Output argument:<br>**msg**: return message. If back trace is successful, the call stack information is returned through **msg**.| 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> If the PID that calls this API is different from the target PID, the caller must be the **system** or **root** user. To capture the call stack of a process that does not belong to the current user group, ensure that you have permissions to read **/proc/pid/maps** and implement **ptrace** on the peer process.


### Development Example


You can use DumpCatcher to obtain the call stack of a specified process (thread) in your applications. The following uses the **dumpcatcherdemo** module as an example to describe how to use the DumpCatcher API to obtain the call stack.


1. Add the DumpCatcher dependency to the build file. Take /base/hiviewdfx/faultloggerd/example/BUILD.gn as an example. Add the **dfx_dump_catcher.h** file path to **include_dirs** and add the required **//base/hiviewdfx/faultloggerd/interfaces/innerkits/dump_catcher:lib_dfx_dump_catcher** module to **deps**.
     
   ```
   import("//base/hiviewdfx/faultloggerd/faultloggerd.gni")
   import("//build/ohos.gni")
   
   config("dumpcatcherdemo_config") {
     visibility = [ ":*" ]
   
     include_dirs = [
       ".",
       "//utils/native/base/include",
       "//base/hiviewdfx/faultloggerd/interfaces/innerkits/dump_catcher/include/",  # Add the path of the dump_catcher header file.
     ]
   }
   
   ohos_executable("dumpcatcherdemo") {  sources = [ "dump_catcher_demo.cpp" ]  configs = [ ":dumpcatcherdemo_config" ]  deps = [     "//base/hiviewdfx/faultloggerd/interfaces/innerkits/dump_catcher:lib_dfx_dump_catcher", # Add the DumpCatcher module dependency.    "//utils/native/base:utils",  ]  external_deps = [ "hilog_native:libhilog" ]  install_enable = true  part_name = "faultloggerd"  subsystem_name = "hiviewdfx"
   }
   ```

2. Define the header file. Take **/base/hiviewdfx/faultloggerd/example/dump_catcher_demo.h** as an example. In the sample code, the function of the stack depth test is called to construct a call stack with a specified depth.
     
   ```
   #ifndef DUMP_CATCHER_DEMO_H
   #define DUMP_CATCHER_DEMO_H
   
   #include <inttypes.h>
   
   #define NOINLINE __attribute__((noinline))
   
   // Define the macro function to automatically generate a function call chain.
   #define GEN_TEST_FUNCTION(FuncNumA, FuncNumB)          \
       __attribute__((noinline)) int TestFunc##FuncNumA() \
       {                                                  \
           return TestFunc##FuncNumB();                   \
       }
   
   // Call the function of the stack depth test.
   int TestFunc0(void);
   int TestFunc1(void);
   int TestFunc2(void);
   int TestFunc3(void);
   int TestFunc4(void);
   int TestFunc5(void);
   int TestFunc6(void);
   int TestFunc7(void);
   int TestFunc8(void);
   int TestFunc9(void);
   int TestFunc10(void);
   
   #endif // DUMP_CATCHER_DEMO_H
   ```

3. Call the **DumpCatch** API in the source file. Take **/base/hiviewdfx/faultloggerd/example/dump_catcher_demo.cpp** as an example. Include the **dfx_dump_catcher.h** file, declare the **DfxDumpCatcher** object, use the macro function to construct a function call chain, call the **DumpCatch** method, and pass the required process ID and thread ID of the call stack into this method.
     
   ```
   #include "dump_catcher_demo.h"
   
   #include <iostream>
   #include <string>
   #include <unistd.h>
   // Include the dfx_dump_catcher.h file.
   #include "dfx_dump_catcher.h"
   using namespace std;
   
   NOINLINE int TestFunc10(void)
   {
       OHOS::HiviewDFX::DfxDumpCatcher dumplog;
       string msg = "";
       bool ret = dumplog.DumpCatch(getpid(), gettid(), msg);  // Call the DumpCatch API to obtain the call stack.
       if (ret) {
           cout << msg << endl;
       }
       return 0;
   }
   
   // Use the macro function to automatically generate a function call chain.
   GEN_TEST_FUNCTION(0, 1)
   GEN_TEST_FUNCTION(1, 2)
   GEN_TEST_FUNCTION(2, 3)
   GEN_TEST_FUNCTION(3, 4)
   GEN_TEST_FUNCTION(4, 5)
   GEN_TEST_FUNCTION(5, 6)
   GEN_TEST_FUNCTION(6, 7)
   GEN_TEST_FUNCTION(7, 8)
   GEN_TEST_FUNCTION(8, 9)
   GEN_TEST_FUNCTION(9, 10)
   
   int main(int argc, char *argv[])
   {
       TestFunc0();
       return 0;
   }
   ```


## Using ProcessDump to Obtain the Call Stack


### Tool Description

ProcessDump is a command line interface (CLI) based tool for capturing call stacks on OpenHarmony. It uses the **-p** and **-t** parameters to specify the process and thread. After the command is executed, the thread stack information of the specified process is displayed in the CLI window.

  **Table 3** Usage of the CLI-based ProcessDump

| Tool| Path| Command| Description| 
| -------- | -------- | -------- | -------- |
| processdump | /system/bin | -&nbsp;processdump&nbsp;-p&nbsp;[pid]<br>-&nbsp;processdump&nbsp;-p&nbsp;[pid]&nbsp;-t&nbsp;[tid] | **Arguments:**<br>**- -p [pid]**: prints stack information for all threads of the specified process.<br>**- -p [pid] -t [tid]**: prints information for the specified thread of the specified process.<br>**Return value:**<br>If the stack information is parsed successfully, the information is displayed in the standard output. If the stack information fails to be parsed, error information is displayed.| 


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> This tool must be used by the **root** user, or the caller must have the permission to ptrace the target process and read the smaps of the target process.


### Example

Use ProcessDump to print the call stack of the **hiview** process.

  
```
# ps -A | grep hiview
  114 ?        00:00:00 hiview
# processdump -p 114 -t 114
Tid:114, Name:hiview
#00 pc 0000000000089824(00000000b6f44824) /system/lib/ld-musl-arm.so.1(ioctl+68)
#01 pc 000000000002a709(00000000b6c56709) /system/lib/libipc_core.z.so(_ZN4OHOS15BinderConnector11WriteBinderEmPv+16)
#02 pc 000000000002ba75(00000000b6c57a75) /system/lib/libipc_core.z.so(_ZN4OHOS13BinderInvoker18TransactWithDriverEb+224)
#03 pc 000000000002bb37(00000000b6c57b37) /system/lib/libipc_core.z.so(_ZN4OHOS13BinderInvoker13StartWorkLoopEv+22)
#04 pc 000000000002c211(00000000b6c58211) /system/lib/libipc_core.z.so(_ZN4OHOS13BinderInvoker10JoinThreadEb+36)
#05 pc 0000000000038d07(00000000004bcd07) /system/bin/hiview(_ZNSt3__h6vectorINS_9sub_matchINS_11__wrap_iterIPKcEEEENS_9allocatorIS6_EEE8__appendEj+596)
#06 pc 0000000000028655(00000000004ac655) /system/bin/hiview
#07 pc 00000000000c2b08(00000000b6f7db08) /system/lib/ld-musl-arm.so.1(__libc_start_main+116)
#08 pc 00000000000285f4(00000000004ac5f4) /system/bin/hiview
#09 pc 0000000000028580(00000000004ac580) /system/bin/hiview
```


## Locating Faults Based on Crash Logs

You can locate faults based on the crash stack logs generated by FaultLoggerd. This section describes how to use the addr2line tool to locate a crash fault.

1. Find a program crash or construct a crash.
   For example, insert the following code into your code to trigger an invalid memory access fault (SIGSEGV).

     
   ```
   NOINLINE int TriggerSegmentFaultException()
   {
       printf("test TriggerSegmentFaultException \n");
       // Forcibly convert the type to construct a crash.
       int *a = (int *)(&RaiseAbort);
       *a = SIGSEGV;
       return 0;
   }
   ```

2. Obtain the crash function call stack log.
   The process generates a temporary log file in the** /data/log/faultlog/temp** directory due to an exception that is not handled. The naming rule of the temporary log file is as follows:

     
   ```
   cppcrash-pid-time
   ```

   The generated call stack is as follows:

     
   ```
   Pid:816
   Uid:0
   Process name:./crasher
   Reason:Signal:SIGSEGV(SEGV_ACCERR)@0x0042d33d
   Fault thread Info:
   Tid:816, Name:crasher
   r0:0042d33d r1:0000000b r2:1725d4c4 r3:b6f9fa84
   r4:bec97e69 r5:b6fc0268 r6:0042d661 r7:bec97d60
   r8:00000000 r9:00000000 r10:00000000
   fp:bec97d20 ip:00000020 sp:bec97cd0 lr:b6f9fae4 pc:0042d32c
   
   #00 pc 000000000000332c(000000000042d32c) /data/crasher(TriggerSegmentFaultException+15)
   #01 pc 00000000000035c7(000000000042d5c7) /data/crasher(ParseAndDoCrash+277)
   #02 pc 0000000000003689(000000000042d689) /data/crasher(main+39)
   #03 pc 00000000000c3b08(00000000b6fbbb08) /system/lib/ld-musl-arm.so.1(__libc_start_main+116)
   #04 pc 00000000000032f8(000000000042d2f8) /data/crasher(_start_c+112)
   #05 pc 0000000000003284(000000000042d284) /data/crasher(_start+32)
   ```

3. Use the addr2line tool to analyze the call stack.
   Then, parse the line number based on the offset address.

     
   ```
   root:~/OpenHarmony/out/hi3516dv300/exe.unstripped/hiviewdfx/faultloggerd$ addr2line -e crasher 000332c
   base/hiviewdfx/faultloggerd/tools/crasher/dfx_crasher.c:57
   ```

   The crash is caused by assigning a value to an unwritable area. It is in code line 57 in the **dfx_crasher.c** file. You can modify it to avoid the crash.
