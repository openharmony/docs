# UI相关应用无响应常见问题

本文档收集整理了一些常见的会导致应用无响应的ArkUI API错误用法，旨在帮助开发者了解这些错误用法，从而避免在实际应用开发过程中犯类似错误。

## 网络图片使用syncLoad同步下载

**问题现象**

应用无响应，系统生成相应的AppFreeze问题日志，日志中有如下主线程调用栈：

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

**可能原因**

应用设置的`syncLoad`接口用于同步下载网络图片，系统将在主线程中加载图片。在网络条件不佳时，可能会导致任务阻塞。

**解决措施**

网络图片加载不应设置`syncLoad=true`。

**参考链接**

相关接口详见[syncLoad](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md#syncload8)。


## 在UI主线程执行耗时任务

**问题现象**

应用无响应，系统生成相应的AppFreeze日志，日志中有如下非主线程调用栈：

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

**可能原因**

该现象表示正在向主线程抛出同步任务。需要等待主线程执行完该任务后，才能继续执行后续逻辑。通常，这种情况是由于主线程正在执行一个大粒度的任务，与当前堆栈无关。

**解决措施**

该堆栈常见于多个进程的IPC互锁过程中，此处仅为互锁环的一部分，且无法直接打破。需要从其他角度解决互锁问题，比如分析等待的目标线程在处理什么任务，是否耗时任务，或是其它同步等待任务。
