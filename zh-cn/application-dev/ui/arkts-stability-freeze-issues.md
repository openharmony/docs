# UI相关应用无响应问题案例

本文档收集整改了一些常见的会导致应用无响应的ArkUI API错误用法，旨在帮助开发者了解一些常见的会导致应用无响应问题的错误用法，从而避免在实际应用开发过中犯类似错误。

## 1、网络图片使用syncLoad同步下载

### 典型案例

**问题现象**

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

**问题原因**

应用设置了对网络图片进行同步下载的接口（syncLoad），系统就会在主线程进行图片加载，如果是网络不好的情况下，可能造成任务阻塞。

### 接口文档

[syncLoad](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md#syncload8)

### 最佳实践

网络图片不要使用设置syncLoad=true


## 2、在UI主线程执行耗时任务

### 典型案例

**问题现象**

在非主线程出现如下堆栈

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

**问题原因**

这个说明正在往主线程抛同步任务，需要等待主线程执行完该任务才能执行后续的逻辑，这种只需要看主线程在做什么任务就可以了，一般是有个大粒度任务在主线程执行导致的，与该堆栈完全没有关系。

### 最佳实践

该堆栈也经常出现在多个进程ipc互锁的过程，这里只是互锁的一个环，而且是不可打破的，需要从其他角度去打破互锁环。
