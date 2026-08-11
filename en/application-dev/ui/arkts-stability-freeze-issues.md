# Common UI Application Freezing Issues

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @caoruihong-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=6a7a9695d382ab21344e9751f365130fa72ffa09 translatedAt=2026-08-04T06:38:10.428Z pushedAt=2026-08-04T08:30:28.291Z -->

This document summarizes common ArkUI API misuse scenarios that may cause application freezes, and provides guidance to help you avoid similar issues during development.

## Using syncLoad for Network Image Downloads

**Symptom**

The application becomes unresponsive, and the AppFreeze log shows a main thread call stack such as:

```cpp
#00 pc 00000000001b5904 /system/lib/ld-musl-aarch64.so.1(__timedwait_cp+192)
#01 pc 00000000001b7908 /system/lib/ld-musl-aarch64.so.1(__pthread_cond_timedwait+188)
#02 pc 00000000000c11c0 /system/lib64/libc++.so(std::__h::condition_variable::__do_timed_wait(std::__h::unique_lock<std::__h::mutex>&, std::__h::chrono::time_point<std::__h::chrono::system_clock, std::__h::chrono::duration<long long, std::__h::ratio<1l, 1000000000l>>>)+108)
#03 pc 0000000000019ed0 /system/lib64/platformsdk/libace_network.z.so(std::__h::cv_status std::__h::condition_variable::wait_for<long long, std::__h::ratio<1l, 1000000000l>>(std::__h::unique_lock<std::__h::mutex>&, std::__h::chrono::duration<long long, std::__h::ratio<1l, 1000000000l>> const&)+92)
#04 pc 0000000000019e5c /system/lib64/platformsdk/libace_network.z.so
#05 pc 000000000001bc10 /system/lib64/platformsdk/libace_network.z.so(OHOS::Ace::DownloadManagerImpl::HandleDownloadResult(bool, OHOS::Ace::DownloadCallback&&, std::__h::shared_ptr<OHOS::Ace::DownloadCondition> const&, int, std::__h::basic_string<char, std::__h::char_traits<char>, std::__h::allocator<char>> const&)+248)
#06 pc 0000000000018564 /system/lib64/platformsdk/libace_network.z.so(OHOS::Ace::DownloadManagerImpl::DownloadSync(OHOS::Ace::DownloadCallback&&, std::__h::basic_string<char, std::__h::char_traits<char>, std::__h::allocator<char>> const&, int, int)+1096)
#07 pc 000000000096f4a8 /system/lib64/platformsdk/libace_compatible.z.so(OHOS::Ace::NG::ImageLoadingContext::PerformDownload()+448)
```

**Possible Causes**

Enabling **syncLoad** for network image downloads forces synchronous loading, which blocks the main thread. Under poor network conditions, this can result in prolonged blocking and application freezes.

**Solution**

Do not set **syncLoad** to **true** when loading images from the network.

**Reference**

[syncLoad](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md#syncload8)

## Executing Time-Consuming Tasks on the Main UI Thread

**Symptom**

The application becomes unresponsive, and the AppFreeze log shows a non-main thread call stack such as:

```cpp
#00 pc 00000000001b9a7c /system/lib/ld-musl-aarch64.so.1(__timedwait_cp+148)
#01 pc 00000000001bbacc /system/lib/ld-musl-aarch64.so.1(pthread_cond_timedwait+168)
#02 pc 00000000000c115c /system/lib64/libc++.so(std::__h::condition_variable::wait(std::__h::unique_lock<std::__h::mutex>&)+20)
#03 pc 00000000000c1d1c /system/lib64/libc++.so(std::__h::__assoc_sub_state::__sub_wait(std::__h::unique_lock<std::__h::mutex>&)+48)
#04 pc 0000000000baf2e4 /system/lib64/platformsdk/libace_compatible.z.so(std::__h::__assoc_state<int>::copy()+64)
#05 pc 0000000000baf0e0 /system/lib64/platformsdk/libace_compatible.z.so(OHOS::Ace::CancelableCallback<void ()>::WaitUntilComplete(std::__h::chrono::duration<long long, std::__h::ratio<1l, 1000l>>)+120)
#06 pc 0000000000baed68 /system/lib64/platformsdk/libace_compatible.z.so
#07 pc 0000000000bae640 /system/lib64/platformsdk/libace_compatible.z.so(OHOS::Ace::TaskExecutor::PostSyncTask(std::__h::function<void ()>&&, OHOS::Ace::TaskExecutor::TaskType, std::__h::basic_string<char, std::__h::char_traits<char>, std::__h::allocator<char>> const&, OHOS::Ace::PriorityType) const+220)
#08 pc 000000000107d9d0 /system/lib64/platformsdk/libace_compatible.z.so
```

**Possible Causes**

Synchronous tasks are dispatched to the main thread, which must complete them before continuing. This often occurs when the main thread executes coarse-grained tasks unrelated to the current stack, typically involving IPC interlocks across multiple processes.

**Solution**

This stack trace is part of an interlock chain that cannot be resolved directly. To address the issue, try the following: Analyze what the target thread is waiting for. Determine whether the task is time-consuming or involves synchronous waiting. Resolve the underlying cause from other points in the interlock chain.