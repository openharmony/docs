# 内存泄漏相关问题汇总
<!--Kit: NDK-->
<!--Subsystem: arkcompiler-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @shilei123-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @fang-jinxu-->

## 当前是否有机制来检查是否有泄漏的napi_ref

- 具体问题：napi_create_reference可以创建对js对象的引用，保持js对象不释放，正常来说使用完需要使用napi_delete_reference进行释放，但怕漏delete导致js对象内存泄漏，当前是否有机制来检查/测试是否有泄漏的napi_ref？  
- 检测方式：  
可使用 DevEco Studio（IDE）提供的 Allocation 工具进行检测。  
[基础内存分析：Allocation分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-insight-session-allocations)  
napi_create_reference这个接口内部实现会new一个C++对象，因此，如果忘记使用napi_delete_reference接口，那这个new出来的C++对象也会泄漏，这时候就可以用Allocation工具来进行检测，这个工具会把未释放的对象的分配栈都打印出来，如果napi_ref泄漏了，可以在分配栈上看出来  

## napi开发过程中遇见内存泄漏问题要怎么定位解决

点击按钮时内存增加，即使主动触发GC也无法回收。如何在Node-API开发过程中定位和解决内存泄漏问题？

- 解决建议：  
需先了解Node-API生命周期机制，相关材料如下：  
[使用Node-API接口进行生命周期相关开发](use-napi-life-cycle.md)  
使用Node-API时导致内存泄漏的常见原因：  
1. napi_value不在napi_handle_scope管理中，导致napi_value持有的ArkTS对象无法释放，该问题常见于直接使用uv_queue_work的场景中。解决方法是添加napi_open_handle_scope和napi_close_handle_scope接口。
此类泄漏可通过snapshot分析定位原因，泄漏的ArkTS对象distance为1，即不知道被谁持有，这种情况下一般就是被native（napi_value是个指针，指向native持有者）持有了，且napi_value不在napi_handle_scope范围内，可参考[易错API的使用规范](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-stability-coding-standard-api#section1219614634615)   
2. 使用 `napi_create_reference` 为 ArkTS 对象创建了强引用（`initial_refcount` 参数大于 0），且一直未删除，导致 ArkTS 对象无法被回收。`napi_create_reference` 接口内部会创建一个 C++ 对象，因此这种泄漏通常表现为ArkTS对象与Native对象的双重泄漏。可以使用 Allocation 工具捕获Native对象泄漏栈，检查是否存在 `napi_create_reference` 相关的栈帧。  
[基础内存分析：Allocation分析](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-insight-session-allocations)  

3. 被其它存活的ArkTS对象持有时，使用snapshot查看泄漏对象的持有者。  

## napi_threadsafe_function内存泄漏应该如何处理

`napi_threadsafe_function`（下文简称tsfn）在使用时，常常会调用 `napi_acquire_threadsafe_function` 来更改tsfn的引用计数，确保tsfn不会意外被释放。但在使用完成后，应该及时使用 `napi_tsfn_release` 模式调用 `napi_release_threadsafe_function` 方法，以确保在所有调用回调都执行完成后，其引用计数能回归到调用 `napi_acquire_threadsafe_function` 方法之前的水平。当其引用计数归为0时，tsfn才能正确的被释放。

当env即将退出，但tsfn的引用计数未归零时，应使用 `napi_tsfn_abort` 模式调用 `napi_release_threadsafe_function` 方法，确保env释放后不再持有或使用tsfn。env退出后继续持有tsfn将导致未定义行为，可能引发崩溃。

如下代码将展示通过注册 `env_cleanup` 钩子函数的方式，以确保在env退出后不再继续持有tsfn。

```cpp
//napi_init.cpp
#include <hilog/log.h> // hilog, 输出日志, 需链接 libhilog_ndk.z.so
#include <thread> // 创建线程
#include <unistd.h> // 线程休眠

// 定义输出日志的标签和域
#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x2342
#define LOG_TAG "MY_TSFN_DEMO"

/*
  为构建一个 env 生命周期短于 native 生命周期的场景,
  本示例需要使用worker, taskpool 或 napi_create_ark_runtime 等方法,
  创建非主线程的ArkTS运行环境，并人为的提前结束掉该线程
*/


// 定义一个数据结构，模拟存储tsfn的场景
class MyTsfnContext {
public:
// 因使用了Node-API方法, MyTsfnContext 应当只在ArkTS线程被构造
MyTsfnContext(napi_env env, napi_value workName) {
    // 注册env销毁钩子函数
    napi_add_env_cleanup_hook(env, Cleanup, this);
    // 创建线程安全函数
    if (napi_create_threadsafe_function(env, nullptr, nullptr, workName, 1, 1, this,
            TsfnFinalize, this, TsfnCallJs, &tsfn_) != napi_ok) {
        OH_LOG_INFO(LOG_APP, "tsfn is created failed");
        return;
    };
};

~MyTsfnContext() { OH_LOG_INFO(LOG_APP, "MyTsfnContext is deconstructed"); };

napi_threadsafe_function GetTsfn() {
    std::unique_lock<std::mutex> lock(mutex_);
    return tsfn_;
}

bool Acquire() {
    if (GetTsfn() == nullptr) {
        return false;
    };
    return (napi_acquire_threadsafe_function(GetTsfn()) == napi_ok);
};

bool Release() {
    if (GetTsfn() == nullptr) {
        return false;
    };
    return (napi_release_threadsafe_function(GetTsfn(), napi_tsfn_release) == napi_ok);
};

bool Call(void *data) {
    if (GetTsfn() == nullptr) {
        return false;
    };
    return (napi_call_threadsafe_function(GetTsfn(), data, napi_tsfn_blocking) == napi_ok);
};

private:
// 保护多线程读写tsfn的准确性
std::mutex mutex_;
napi_threadsafe_function tsfn_ = nullptr;

// napi_add_env_cleanup_hook 回调
static void Cleanup(void *data) {
    MyTsfnContext *that = reinterpret_cast<MyTsfnContext *>(data);
    napi_threadsafe_function tsfn = that->GetTsfn();
    std::unique_lock<std::mutex> lock(that->mutex_);
    that->tsfn_ = nullptr;
    lock.unlock();
    OH_LOG_WARN(LOG_APP, "cleanup is called");
    napi_release_threadsafe_function(tsfn, napi_tsfn_abort);
};

// tsfn 释放时的回调
static void TsfnFinalize(napi_env env, void *data, void *hint) {
    MyTsfnContext *ctx = reinterpret_cast<MyTsfnContext *>(data);
    OH_LOG_INFO(LOG_APP, "tsfn is released");
    napi_remove_env_cleanup_hook(env, MyTsfnContext::Cleanup, ctx);
    // cleanup 提前释放线程安全函数, 为避免UAF, 将释放工作交给调用方
    if (ctx->GetTsfn() != nullptr) {
        OH_LOG_INFO(LOG_APP, "ctx is released");
        delete ctx;
    }
};

// tsfn 发送到 ArkTS 线程执行的回调
static void TsfnCallJs(napi_env env, napi_value func, void *context, void *data) {
    MyTsfnContext *ctx = reinterpret_cast<MyTsfnContext *>(context);
    char *str = reinterpret_cast<char *>(data);
    OH_LOG_INFO(LOG_APP, "tsfn is called, data is: \"%{public}s\"", str);
    // 业务逻辑已省略
};
};

// 该方法需注册到模块Index.d.ts, 注册名为 myTsfnDemo, 接口描述如下
// export const myTsfnDemo: () => void;
napi_value MyTsfnDemo(napi_env env, napi_callback_info info) {
    OH_LOG_ERROR(LOG_APP, "MyTsfnDemo is called");
    napi_value workName = nullptr;
    napi_create_string_utf8(env, "MyTsfnWork", NAPI_AUTO_LENGTH, &workName);
    MyTsfnContext *myContext = new MyTsfnContext(env, workName);
    if (myContext->GetTsfn() == nullptr) {
        OH_LOG_ERROR(LOG_APP, "failed to create tsfn");
        delete myContext;
        return nullptr;
    };
    char *data0 = new char[]{"Im call in ArkTS Thread"};
    if (!myContext->Call(data0)) {
        OH_LOG_INFO(LOG_APP, "call tsfn failed");
    };

    // 创建一个线程，模拟异步场景
    std::thread(
        [](MyTsfnContext *myCtx) {
            if (!myCtx->Acquire()) {
                OH_LOG_ERROR(LOG_APP, "acquire tsfn failed");
                return;
            };
            char *data1 = new char[]{"Im call in std::thread"};
            // 非必要操作, 仅用于异步流程tsfn仍有效
            if (!myCtx->Call(data1)) {
                OH_LOG_ERROR(LOG_APP, "call tsfn failed");
            };
            // 休眠 5s, 模拟耗时场景, env退出后, 异步任务仍未执行完成
            sleep(5);
            // 此时异步任务已执行完成, 但tsfn已被释放并置为 nullptr
            char *data2 = new char[]{"Im call after work"};
            if (!myCtx->Call(data2) && !myCtx->Release()) {
                OH_LOG_ERROR(LOG_APP, "call and release tsfn failed");
                delete myCtx;
            }
        },
        myContext)
        .detach();
    return nullptr;
};
```

以下内容为主线程逻辑，主要用于创建 worker 线程并通知其执行任务。

```ts
// 主线程 Index.ets
import worker, { MessageEvents } from '@ohos.worker';

const mWorker = new worker.ThreadWorker('../workers/Worker');
mWorker.onmessage = (e: MessageEvents) => {
    const action: string | undefined = e.data?.action;
    if (action === 'kill') {
        mWorker.terminate();
    }
}

// 触发方式的注册已省略
mWorker.postMessage({action: 'tsfn-demo'});

```

以下内容为Worker线程逻辑，主要用于触发Native任务。

```ts
// worker.ets
import worker, { ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@ohos.worker';
import napiModule from 'libentry.so'; // libentry.so: Node-API 库的模块名称

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {
    const action: string | undefined = e.data?.action;
    if (action === 'tsfn-demo') {
        // 触发 C++ 层的 tsfn demo
        napiModule.myTsfnDemo();
        // 通知主线程结束 worker
        workerPort.postMessage({action: 'kill'});
    };
}
```