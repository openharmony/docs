# 任务超时检测

<!--Kit: Performance Analysis Kit-->
<!--Subsystem: HiviewDFX-->
<!--Owner: @rr_cn-->
<!--Designer: @peterhuangyu-->
<!--Tester: @gcw_KuLfPSbe-->
<!--Adviser: @foryourself-->

## 简介

开发者在开发应用时，某一段业务逻辑期望执行一定时间，如果该业务逻辑执行时长超过预期时间，即为任务超时。

任务超时检测主要包括主线程超时检测和任务执行超时检测，二者均可使用HiCollie实现自定义时长来对开发者选择的业务逻辑进行主动检测，主线程超时也可采用默认时长进行检测。详见：[HiCollie使用指导](hicollie-guidelines-ndk.md)。

> **说明：**
>
> [AppFreeze（应用冻屏）检测](appfreeze-guidelines.md)相比任务超时检测，主要是由系统侧提供检测周期性检测逻辑，无需开发者感知和适配。

## 主线程超时检测

### 检测原理

1. 触发流程
   主线程超时150ms~450ms，触发采样调用栈流程；主线程超时450ms，触发采集trace流程。

   150ms &lt; 主线程处理时长 &lt; 450ms：主线程超时采样栈。**同一个应用的PID一个生命周期仅会触发一次主线程超时事件采样栈。开发者选项打开，一小时一次。应用启动10s内不进行检测。**

   主线程处理时长 > 450ms：主线程超时采样Trace。**同一个应用的UID一天仅会触发一次主线程超时事件采样trace。**

   主线程处理时长 = 450ms：不触发任何采样逻辑。

   > **注意：**
   >
   > 启动主线程超时检测抓取trace的功能的前提：**开发者使用nolog版本，开发者模式处于关闭状态**；
   >
   > log和nolog版本：在手机中，点击设置——搜索关键字“关于本机”——软件版本进行查看。log版本会以log结尾；
   >
   > 关闭开发者模式后，可能无法使用DevEco Studio。因此，可以提前安装应用，再关闭开发者模式。

2. 抓栈时机
   主线程处理事件超时后，开始执行周期性任务检测，每隔150ms检测主线程是否再次发生超时事件（1 &lt;= 检测次数 &lt;= 2），共三种情况：

   （1）第一次检测发现超时事件，开始执行堆栈采样，每隔150ms采样一次，共采样10次堆栈，第11次收集堆栈并上报事件，结束检测。

   ![sample_stack_1](figures/sample_stack_1.png)

   （2）第一轮检测未发生超时事件，第二轮检测发现超时事件，开始执行堆栈采样，每隔150ms采样一轮，共采样10次堆栈，第11轮收集堆栈并上报事件，结束检测。

   ![sample_stack_2](figures/sample_stack_2.png)

   （3）两轮检测均未发现超时事件，结束检测。

   ![sample_stack_3](figures/sample_stack_3.png)

3. trace采集时机

   主线程超时抓Trace调用录制函数后，每隔150ms检测主线程是否再次发生超时事件（检测次数 = 20），其中，只要在20个间隔检测时，有一次主线程事件超时150ms，3s检测结束后落盘trace。

   （1）20次检测均未发生主线程超时150ms事件，无trace文件生成。

   ![dump-trace1](figures/dump-trace1.PNG)

   （2）20次检测至少有一次发生主线程超时150ms事件，生成trace文件。

### 日志获取

主线程超时日志保存在应用沙箱目录下，可通过以下方式获取

**方式一：通过HiAppEvent接口订阅**

HiAppEvent给开发者提供了故障订阅接口，详见[HiAppEvent介绍](hiappevent-intro.md)。参考[订阅主线程超时事件（ArkTS）](hiappevent-watcher-mainthreadjank-events-arkts.md)或[订阅主线程超时事件（C/C++）](hiappevent-watcher-mainthreadjank-events-ndk.md)完成主线程超时事件订阅，并通过事件的[external_log](hiappevent-watcher-mainthreadjank-events.md#事件字段说明)字段读取故障日志文件名。

### 日志规格

1. 日志老化规格
   一般情况，栈文件的大小为7-10KB，trace大小为1-5MB。应用沙箱内的watchdog目录最大保存10M内容，超出后，会自动触发此目录老化机制，按照文件名顺序最多删除100文件。目录地址：/data/storage/el2/log/watchdog/。

2. 采样栈规格
   抓栈功能目前只支持ARM64架构，抓栈结果为解析后的混合栈信息，包含native帧和JS帧。

   抓栈结果部分示例如下：

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

   每次抓栈拷贝16KB主线程调用栈信息进行回栈解析，所以每一次抓栈结果最多可以展示进程16KB调用信息，共进行10次，重复栈帧会聚合在一起，不同调用层次通过行缩进进行区分，最终以树型方式进行展示。当抓栈失败（如主线程阻塞在内核或信号被屏蔽等情况）时，将会输出“/proc/self/wchan”文件内容。

   展示结果中每一行表示一个栈信息，每一行栈帧信息所表示的意义可以按如下方式解读：

   native帧格式如下：

   ```text
   9 #02 pc 000090a9 /system/bin/appspawn(main+396)(55679d09bcdea35bb1e0d4e1d9a3e58f)
   ^  ^       ^               ^              ^                   ^ 
   1  2       3               4              5                   6
   
   1 表示采样到此帧的次数。
   2 表示帧的调用层级，行缩进大小与该层级对应，所有同一层级帧采样到的次数和不大于10次，#00采样次数和为10（设置采样的次数）。
   3 为native帧PC值。
   4 表示调用的文件路径。
   5 调用的函数名及代码行偏移。
   6 so文件md5值。
   ```

   JS帧格式如下：

   ```text
   1 #23 at wait2 (/entry/build/default/cache/default/XXX/entry/src/main/ets/pages/Index.js:16:12)
   ^  ^    ^               ^
   1  2    3               4
   
   1 表示采样到此帧的次数，同样最大为采样次数。
   2 表示帧的调用层级，与native帧意义相同。
   3 表示调用函数名wait2。
   4 表示调用函数所在的路径，文件及行列号。
   ```

3. 采样trace规格
   trace文件大小约为1-5M左右。trace文件可以通过[HiSmartPerf](https://gitee.com/openharmony/developtools_smartperf_host)工具进行可视化分析。工具下载链接：[developtools_smartperf_host官方发行版](https://gitee.com/openharmony/developtools_smartperf_host/releases)。

   trace文件说明参考：[web端加载trace说明](https://gitee.com/openharmony/developtools_smartperf_host/blob/master/smartperf_host/ide/src/doc/md/quickstart_systemtrace.md)。

## 任务执行超时检测

### 检测原理

**概述**：业务逻辑超出预期时间即为任务超时。

**检测原理**：开发者自定义超时时间，随后在执行业务逻辑时，如果业务逻辑超出预期时间即为任务执行超时。

检测原理如下图：

![zh-cn_image_0000002326273258](figures/zh-cn_image_0000002326273258.png)

### 日志获取

任务执行超时日志可通过以下方式获取：

**方式一：通过HiAppEvent接口订阅**

HiAppEvent给开发者提供了故障订阅接口，详见[HiAppEvent介绍](hiappevent-intro.md)。参考[订阅任务执行超时事件（ArkTS）](hiappevent-watcher-apphicollie-events-arkts.md)或[订阅任务执行超时事件（C/C++）](hiappevent-watcher-apphicollie-events-ndk.md)完成任务执行超时事件订阅，并通过事件的[external_log](hiappevent-watcher-apphicollie-events.md#事件字段说明)字段读取故障日志文件名。

### 日志规格

任务执行超时事件日志规格与应用冻屏日志相同，可详见[应用冻屏日志规格](appfreeze-guidelines.md#日志规格)。
