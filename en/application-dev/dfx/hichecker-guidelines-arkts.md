# Using HiChecker (ArkTS)

## Overview

HiChecker is provided to check issues that may be easily ignored during application development. Such issues include time-consuming thread calling and ability resource leakage in application processes. The issues are recorded in logs or lead to process crashes explicitly so that you can find and rectify them.

## Basic Concepts

**Rule constants**: HiChecker uses constants to indicate existing alarm rules or check rules. A constant indicates a rule. You can add or delete rules using HiChecker APIs.

## Working Principles

1. The application calls HiChecker APIs to add, remove, query, and modify rules. \n
2. When a time-consuming call or ability resource leakage occurs, HiChecker reports an event based on the rule triggered.

## Constraints

- Currently, the alarm rules support only logs (default) and application crashes. 
- HiChecker supports stack unwinding in C but not in JavaScript. 

## Available APIs

The check APIs are provided by the HiChecker module. For details about the APIs, see [HiChecker](../reference/apis-performance-analysis-kit/js-apis-hichecker.md).

| API| Description|
| -------- | -------- |
| hichecker.addCheckRule(rule: bigint) | Adds a rule.|
| hichecker.removeCheckRule(rule: bigint) | Removes a rule.|
| hichecker.containsCheckRule(rule: bigint) | Queries a rule.|

## How to Develop

After the application startup execution page is loaded, the check starts. After the service is complete, the check stops.

1. Create an ArkTS application project. In the **Project** window, click **entry > src > main > ets > entryability** to open the **EntryAbility.ets** file. After the page is loaded, call the HiChecker to add check rules. The sample code is as follows:

   ```ts
   import { window } from '@kit.ArkUI';
   import { image } from '@kit.ImageKit';
   import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';
   import { hichecker, hilog } from '@kit.PerformanceAnalysisKit';
   
   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
       // Add a check rule. For details about the rule, see HiChecker.
       hichecker.addCheckRule(hichecker.RULE_CAUTION_PRINT_LOG|hichecker.RULE_THREAD_CHECK_SLOW_PROCESS);
       let filePath: string = this.context.cacheDir + '/test.JPG';
       const imageSourceApi: image.ImageSource = image.createImageSource(filePath);
       const imagePackerApi = image.createImagePacker();
       let packOpts: image.PackingOption = { format:"image/jpeg", quality:98 };
       imagePackerApi.packing(imageSourceApi, packOpts);
       // The preceding codes trigger the check rule through the image subsystem.
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
       // Main window is destroyed, and UI related resources are released.
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
     }
   
     onForeground() {
       // Ability is brought to foreground.
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
     }
   
     onBackground() {
       // Ability is back to background.
       hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
     }
   }
   ```
   
2. Run the following commands in sequence in the shell:

   ```shell
   hdc shell
   hilog|grep -i hichecker
   ```

   After the HAP is installed, the check begins. If the following call stack information is displayed in the shell window, the check is successful (The call stack triggers the check rule).

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
