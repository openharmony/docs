# 使用HiChecker检测问题（ArkTS）

## 简介

HiChecker可以作为应用开发阶段使用的检测工具，用于检测代码运行过程中部分易忽略的问题，如应用线程出现耗时调用、应用进程中元能力资源泄露等问题。开发者可以通过日志记录或进程crash等形式查看具体问题并进行修改，提升应用的使用体验

## 基本概念

**规则常量**：HiChecker使用常量来表示已有的告警规则或者检测规则，一个常量表示一种规则，可以通过HiChecker的接口控制规则的添加和删除。

## 实现原理

1. 应用程序通过HiChecker函数接口控制规则的增删查改。

2. 子系统有耗时调用或者Ability资源泄露时通过HiChecker通知有对应规则的事件发生，HiChecker检测条件满足时做对应的操作。

## 约束与限制

- 支持应用增加、删除不同的告警通知规则，目前支持记录流水日志（默认），应用崩溃两种规则。
- 相关检测条件满足时，支持Native回栈到关键触发点，暂不支持JS回栈。

## 接口说明

检测模式接口由HiChecker模块提供，详细API请参考[检测模式API参考](../reference/apis-performance-analysis-kit/js-apis-hichecker.md)。

| 接口名 | 描述 |
| -------- | -------- |
| hichecker.addCheckRule(rule: bigint) | 需要添加的规则 |
| hichecker.removeCheckRule(rule: bigint) | 需要删除的规则 |
| hichecker.containsCheckRule(rule: bigint) | 需要查询的规则 |

## 开发步骤

在应用启动执行页面加载后，开始检测；完成业务之后，停止检测。

1. 新建一个ArkTS应用工程，在“Project”窗口点击“entry &gt; src &gt; main &gt; ets &gt; entryability ”，打开工程中的“EntryAbility.ets”文件；在页面执行加载后，在自己的业务中调用HiChecker的接口，添加检测规则， 示例代码如下：

   ```ts
   import { window } from '@kit.ArkUI';
   import { image } from '@kit.ImageKit';
   import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';
   import { hichecker, hilog } from '@kit.PerformanceAnalysisKit';
   
   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       // 添加检测规则，规则意义见检测模式API参考
       hichecker.addCheckRule(hichecker.RULE_CAUTION_PRINT_LOG|hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);
       let filePath: string = this.context.cacheDir + '/test.JPG';
       const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
       const imagePackerApi = image.createImagePacker();
       let packOpts: image.PackingOption = { format:"image/jpeg", quality:98 };
       imagePackerApi.packing(imageSourceApi, packOpts);
       // 以上5行通过image子系统触发检测规则
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreateend');
     }
   
     onDestroy() {
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
     }
   
     onWindowStageCreate(windowStage: window.WindowStage) {
       // Main window is created, set main page for this ability
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
   
       windowStage.loadContent('pages/Index', (err, data) => {
         if (err.code) {
           hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
           return;
         }
         hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
       });
     }
   
     onWindowStageDestroy() {
       // Main window is destroyed, release UI related resources
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
     }
   
     onForeground() {
       // Ability has brought to foreground
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
     }
   
     onBackground() {
       // Ability has back to background
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
     }
   }
   ```
   
2. 在shell中依次执行如下命令：

   ```shell
   hdc shell
   hilog|grep -i hichecker
   ```

   安装hap后运行，shell窗口有如下调用栈信息说明检测成功（调用栈为触发检测规则时的调用栈）

   ```shell
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: StackTrace:
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #00 pc 00003d33 /system/lib/chipset-pub-sdk/libbacktrace_local.so(OHOS::HiviewDFX::GetBacktrace(std::__h::basic_string<char, std::__h::char_traits<char>, std::__h::allocator<char>>&, bool, unsigned int)+90)(7c7c81050ce2a86bf0a22943c25773db)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #01 pc 00003a57 /system/lib/chipset-pub-sdk/libdfx_dumpcatcher.z.so(OHOS::HiviewDFX::DfxDumpCatcher::DoDumpCurrTid(unsigned int, std::__h::basic_string<char, std::__h::char_traits<char>, std::__h::allocator<char>>&, unsigned int)+26)(8e2b59ecc6cc00dd2135f9d84c23a724)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #02 pc 000042a1 /system/lib/chipset-pub-sdk/libdfx_dumpcatcher.z.so(OHOS::HiviewDFX::DfxDumpCatcher::DoDumpLocalLocked(int, int, std::__h::basic_string<char, std::__h::char_traits<char>, std::__h::allocator<char>>&, unsigned int)+40)(8e2b59ecc6cc00dd2135f9d84c23a724)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #03 pc 0000452d /system/lib/chipset-pub-sdk/libdfx_dumpcatcher.z.so(OHOS::HiviewDFX::DfxDumpCatcher::DumpCatch(int, int, std::__h::basic_string<char, std::__h::char_traits<char>, std::__h::allocator<char>>&, unsigned int, bool)+188)(8e2b59ecc6cc00dd2135f9d84c23a724)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #04 pc 00002cd7 /system/lib/platformsdk/libhichecker.so(OHOS::HiviewDFX::HiChecker::NotifySlowProcess(std::__h::basic_string<char, std::__h::char_traits<char>, std::__h::allocator<char>> const&)+90)(03f34822b1baca8c33fb87a2cd1817cd)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #05 pc 0004045d /system/lib/platformsdk/libimage_napi.z.so(f765998ba1f5185405f9735d86b0c7b7)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #06 pc 00040f43 /system/lib/platformsdk/libimage_napi.z.so(f765998ba1f5185405f9735d86b0c7b7)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #07 pc 0002b0c5 /system/lib/platformsdk/libace_napi.z.so(panda::JSValueRef ArkNativeFunctionCallBack<true>(panda::JsiRuntimeCallInfo*)+448)(a84fbb767fd826946623779c608395bf)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #08 pc 001e7597 /system/lib/platformsdk/libark_jsruntime.so(panda::ecmascript::EcmaInterpreter::RunInternal(panda::ecmascript::JSThread*, unsigned char const*, unsigned long long*)+14710)(106c552f6ce4420b9feac95e8b21b792)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #09 pc 001e043b /system/lib/platformsdk/libark_jsruntime.so(panda::ecmascript::EcmaInterpreter::Execute(panda::ecmascript::EcmaRuntimeCallInfo*)+986)(106c552f6ce4420b9feac95e8b21b792)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #10 pc 0029ec99 /system/lib/platformsdk/libark_jsruntime.so(panda::ecmascript::JSFunction::Call(panda::ecmascript::EcmaRuntimeCallInfo*)+388)(106c552f6ce4420b9feac95e8b21b792)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #11 pc 0034b14b /system/lib/platformsdk/libark_jsruntime.so(panda::FunctionRef::CallForNapi(panda::ecmascript::EcmaVM const*, panda::JSValueRef*, panda::JSValueRef* const*, int)+918)(106c552f6ce4420b9feac95e8b21b792)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #12 pc 0003d343 /system/lib/platformsdk/libace_napi.z.so(napi_call_function+198)(a84fbb767fd826946623779c608395bf)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #13 pc 000283e1 /system/lib/platformsdk/libuiabilitykit_native.z.so(OHOS::AbilityRuntime::JsUIAbility::CallObjectMethod(char const*, napi_value__* const*, unsigned int, bool, bool)+648)(118b2c16051d37927837ed0ce7874f1d)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #14 pc 00027c0d /system/lib/platformsdk/libuiabilitykit_native.z.so(OHOS::AbilityRuntime::JsUIAbility::OnStart(OHOS::AAFwk::Want const&, OHOS::sptr<OHOS::AAFwk::SessionInfo>)+616)(118b2c16051d37927837ed0ce7874f1d)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #15 pc 000548fd /system/lib/platformsdk/libuiabilitykit_native.z.so(OHOS::AbilityRuntime::UIAbilityImpl::Start(OHOS::AAFwk::Want const&, OHOS::sptr<OHOS::AAFwk::SessionInfo>)+396)(118b2c16051d37927837ed0ce7874f1d)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #16 pc 0005549d /system/lib/platformsdk/libuiabilitykit_native.z.so(OHOS::AbilityRuntime::UIAbilityImpl::HandleAbilityTransaction(OHOS::AAFwk::Want const&, OHOS::AAFwk::LifeCycleStateInfo const&, OHOS::sptr<OHOS::AAFwk::SessionInfo>)+764)(118b2c16051d37927837ed0ce7874f1d)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #17 pc 000359b3 /system/lib/platformsdk/libability_thread.z.so(OHOS::AbilityRuntime::UIAbilityThread::HandleAbilityTransaction(OHOS::AAFwk::Want const&, OHOS::AAFwk::LifeCycleStateInfo const&, OHOS::sptr<OHOS::AAFwk::SessionInfo>)+466)(889aa126c2fb643cd2ec6dbd64adddd1)
   08-05 23:11:07.206  1799  1799 I C02d0b/HICHECKER: #18 pc 00039c2d /system/lib/platformsdk/libability_thread.z.so(889aa126c2fb643cd2ec6dbd64adddd1)
   ```
