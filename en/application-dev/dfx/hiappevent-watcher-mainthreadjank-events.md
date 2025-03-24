# Main Thread Jank Event Overview

HiAppEvent provides APIs for subscribing to main thread jank events.

- [Subscribing to Main Thread Jank Events (ArkTS)](hiappevent-watcher-mainthreadjank-events-arkts.md)
- [Subscribing to Main Thread Jank Events (C/C++)](hiappevent-watcher-mainthreadjank-events-ndk.md)

The **params** parameter in the event information is described as follows.

**params**

| Name   | Type  | Description                      |
| ------- | ------ | ------------------------- |
| time     | number | Event triggering time, in ms.|
| bundle_version | string | Application version.|
| bundle_name | string | Application name.|
| pid | number | Process ID of the application.|
| uid | number | User ID of the application.|
| begin_time | number | Begin time of a task in the main thread.|
| end_time | number | End time of a task in the main thread.|
| external_log| string[] | Path of the generated log files. If the directory files exceed the threshold (for details, see **log_over_limit**), new log files may fail to be written. Therefore, delete the log files immediately after they are processed.|
| log_over_limit| boolean | Whether the size of generated log files and existing log files exceeds the upper limit (10 MB). The value **true** indicates that the upper limit is exceeded and logs fail to be written. The value **false** indicates that the upper limit is not exceeded.|

## Main Thread Jank Event Time Specifications

1. Begin time

    Stack sampling triggered by main thread Jank (150 ms < Main thread processing time < 450 ms): For the processes with the same PID, the call stack sampling for a main thread jank event can be triggered only once..

    Trace sampling triggered by main thread jank (Main thread processing time > 450 ms): For the processes with the same PID, the trace sampling for a main thread jank event can be triggered only once in a day. 

    > **NOTE**
    >
    > To enable the main thread checker to collect tracing data when a task times out, ensure that the nolog version is used and **Developer Options** is disabled
    >
    > You can go to **Settings** > **About phone** to check the software version. The log version ends with **log**.
    >
    > When **Developer Options** is disabled, DevEco Studio may be unavailable. Therefore, you are advised to install the application before disabling **Developer Options**.

2. Stack capture time

    When the main thread jank event occurs, the main thread checker starts to check whether the jank event occurs again every 155 ms (1 ≤ number of check times ≤ 2). There are three cases:

    (1) If a jank event is detected during the first check, the main thread checker starts stack sampling every 155 ms for 10 times. The stack sampling data is collected and an event is reported at the next interval. Then the check ends. 

    ![Stack capture time example 1](figures/dump-stack1.PNG)

    (2) If a jank event is detected during the second check, the main thread checker starts stack sampling every 155 ms for 10 times. The stack sampling data is collected and an event is reported at the next interval. Then the check ends. 

    ![Stack capture time example 2](figures/dump-stack2.PNG)

    (3) If no jank event is detected in the two checks, the check ends.

    ![Stack capture time example 3](figures/dump-stack3.PNG)

3. Trace capture time 

   After the function is called to capture tracing data, the main thread checker checks for a main thread jank event every 150 ms for 20 times. If a main thread jank event occurs in any of the 20 checks, the check ends in 3s and the tracing data is stored.

   (1) No main thread jank event is detected.

   ![Trace capture example](figures/dump-trace1.PNG)

   (2) At least one main thread jank event is detected.

   ![Trace capture example](figures/dump-trace2.PNG)

## Main Thread Jank Event Specifications

1. Log aging

    Generally, the size of a stack file is 7 KB to 10 KB, and the size of a trace file is 3 MB to 6 MB. The **watchdog** directory in the application sandbox can hold files up to10 MB. If the total file size exceeds the limit, the user needs to manually delete files. The path to **watchdog** is **/data/app/el2/100/log/*app_bundle_name*/watchdog**.

2. You can obtain the log path from **external_logs**.

3. Currently, stack capturing supports only the ARM64 architecture. The stack capture result contains both native frames and JS frames parsed.

   An example of the stack capture result is as follows:

    ```text
    9 #00 pc 0000757c /system/bin/appspawn(55679d09bcdea35bb1e0d4e1d9a3e58f)
        9 #01 pc 000731c0 /system/lib/ld-musl-aarch64.so.1(add9e521e4eaf5cb009d4260f3b69ccd)
            9 #02 pc 000090a9 /system/bin/appspawn(main+396)(55679d09bcdea35bb1e0d4e1d9a3e58f)
                9 #03 pc 0000ab5d /system/bin/appspawn(AppSpawnRun+100)(55679d09bcdea35bb1e0d4e1d9a3e58f)
                    9 #04 pc 0000e7f1 /system/lib/chipset-pub-sdk/libbegetutil.z.so(RunLoop_+200)(52ace27d827ad482439bf32cc75bb17b)
                    ......
                                            9 #21 pc 00107aec /system/lib/ld-musl-aarch64.so.1(__pthread_cond_timedwait+628)(add9e521e4eaf5cb009d4260f3b69ccd)
    1 #00 pc 00032e67 /system/lib/platformsdk/libmmi-util.z.so(OHOS::MMI::UDSSocket::OnReadPackets(OHOS::MMI::CircleStreamBuffer&, std::__h::function<void (OHOS::MMI::NetPacket&)>)+158)(99e56bc765f9208f7b7ba8b268886a59)
        1 #01 pc 0000312e5 /system/lib/platformsdk/libmmi-client.z.so(OHOS::MMI::ClientMsgHandler::OnMsgHandler(OHOS::MMI::UDSClient const&, OHOS::MMI::NetPacket&)+340)(66ac85e964777ae89f0c26c339093cd1)
            1 #02 pc 0003016b /system/lib/platformsdk/libmmi-client.z.so(OHOS::MMI::ClientMsgHandler::OnPointerEvent(OHOS::MMI::UDSClient const&, OHOS::MMI::NetPacket&)+1222)(66ac85e964777ae89f0c26c339093cd1)
                1 #03 pc 0003b96b /system/lib/platformsdk/libmmi-client.z.so(OHOS::MMI::InputManagerImpl::OnPointerEvent(std::__h::shared_ptr<OHOS::MMI::PointerEvent>)+1370)(66ac85e964777ae89f0c26c339093cd1)
                    1 #04 pc 00095903 /system/lib/platformsdk/libwm.z.so(OHOS::Rosen::InputEventListener::OnInputEvent(std::__h::shared_ptr<OHOS::MMI::PointerEvent>) const+478)(9c40c5f416d6f830435126998fbcad42)
                    ......
                                            1 #21 pc 003f5c55 /system/lib/platformsdk/libark_jsruntime.so(4e6a2651ec80a7f639233f414d6486fe)
                                                1 #22 at anonymous (/entry/build/default/cache/default/default@CompileArkTS/esmodule/debug/entry/src/main/ets/pages/Index.js:67:17)
                                                    1 #23 at wait2 (/entry/build/default/cache/default/default@CompileArkTS/esmodule/debug/entry/src/main/ets/pages/Index.js:16:12)
                                                    ......
    ```

   Each time a stack is sampled, 16 KB of the call stack information of the main thread is captured for backtrace analysis. Therefore, each stack capture result contains a maximum of 16 KB call information of the process. The stack sampling is performed 10 times in total. The captured data is displayed in a tree view, with repeated stack frames aggregated and different call layers distinguished by line indentation. If the stack fails to be captured (for example, the main thread is blocked in the kernel or signals are masked), the content of the **/proc/self/wchan** file is output.

   In the result, each row indicates a piece of stack information. The meaning of a row of stack frame information can be interpreted as follows:

   Native frame:

    ```text
    9 #02 pc 000090a9 /system/bin/appspawn(main+396)(55679d09bcdea35bb1e0d4e1d9a3e58f)
    ^  ^       ^               ^              ^                   ^ 
    1  2       3               4              5                   6

    1 indicates the number of times that the frame is sampled.
    2 indicates the call level of the frame. The line indentation size corresponds to this level. The number of sampling times of all frames at the same level cannot be greater than 10. The number of sampling times of #00 is 10 (sampling times specified).
    3 indicates the Program Counter (PC) value of the native frame.
    4 indicates the path of the called file.
    5 indicates the name of the called function and code line offset (available in unstripped version, and may not available in stripped version).
    6 indicates the MD5 value of the .so file.
    ```

   JS frame:

    ```text
    1 #23 at wait2 (/entry/build/default/cache/default/XXX/entry/src/main/ets/pages/Index.js:16:12)
    ^  ^    ^               ^
    1  2    3               4

    1 indicates the number of times that the frame is sampled. The maximum value is the sampling times.
    2 indicates the call level of the frame, which is the same as that of the native frame.
    3 indicates the name of the called function, which is **wait2**.
    4 indicates the path, file, row number, and column number of the called function.
    ```

4. Trace specifications

    The size of a trace file is 1 MB to 5 MB. You can parse the trace file using [SmartPerf](https://www.smartperf.host).

    After a trace file is imported, the page displays the time axis, CPU usage, CPU load, IPC method calling, and process, thread, and method calling information from the top down. In this way, the data is displayed from the event dimension.

    For details about how to use trace files, see [How to Load Trace Files on the Web Client](https://gitee.com/openharmony/developtools_smartperf_host/blob/master/ide/src/doc/md/quickstart_systemtrace.md).

