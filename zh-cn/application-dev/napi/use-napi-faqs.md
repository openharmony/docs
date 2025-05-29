# Node-API常见问题

## ArkTS/JS侧import xxx from libxxx.so后，使用xxx报错显示undefined/not callable或明确的Error message

1. 排查.cpp文件在注册模块时的模块名称与so的名称匹配一致。
   如模块名为entry，则so的名字为libentry.so，napi_module中nm_modname字段应为entry，大小写与模块名保持一致。

2. 排查so是否加载成功。
   应用启动时过滤模块加载相关日志，重点搜索"dlopen"关键字，确认是否有相关报错信息；常见加载失败原因有权限不足、so文件不存在以及so已拉入黑名单等，可根据以下关键错误日志确认问题。其中，多线程场景(worker、taskpool等)下优先检查模块实现中nm_modname是否与模块名一致，区分大小写。

3. 排查依赖的so是否加载成功。
   确定所依赖的其它so是否打包到应用中以及是否有权限打开。常见加载失败原因有权限不足、so文件不存在等，可根据以下关键错误日志确认问题。

4. 排查模块导入方式与so路径是否对应。
   若JS侧导入模块的形式为： import xxx from '\@ohos.yyy.zzz'，则该so将在/system/lib/module/yyy中找libzzz.z.so或libzzz_napi.z.so，若so不存在或名称无法对应，则报错日志中会出现dlopen相关日志。

   注意，32位系统路径为/system/lib，64位系统路径为/system/lib64。

| **已知关键错误日志** | **修改建议** |
| -------- | -------- |
| module $SO is not allowed to load in restricted runtime. | $SO表示模块名。该模块不在受限worker线程的so加载白名单，不允许加载，建议用户删除该模块。 |
| module $SO is in blocklist, loading prohibited. | $SO表示模块名。受卡片或者Extension管控，该模块在黑名单内，不允许加载，建议用户删除该模块。 |
| load module failed. $ERRMSG. | 动态库加载失败。$ERRMSG表示加载失败原因，一般常见原因是so文件不存在、依赖的so文件不存在或者符号未定义，需根据加载失败原因具体分析。 |
| try to load abc file from $FILEPATH failed. | 通常加载动态库和abc文件为二选一：如果是要加载动态库并且加载失败，该告警可以忽略；如果是要加载abc文件，则该错误打印的原因是abc文件不存在，$FILEPATH表示模块路径。 |

5. 如果有明确的Error message，可以通过Error message判断当前问题。

| **Error message** | **修改建议** |
| -------- | -------- |
| First attempt: $ERRMSG. | 首先加载后缀不拼接'_napi'的模块名为'xxx'的so，如果加载失败会有该错误信息，$ERRMSG表示具体加载时的错误信息。 |
| Second attempt: $ERRMSG. | 第二次加载后缀拼接'_napi'的模块名为'xxx_napi'的so，如果加载失败会有该错误信息，$ERRMSG表示具体加载时的错误信息。 |
| try to load abc file from xxx failed. | 第三次加载名字为'xxx'的abc文件，如果加载失败会有该错误信息。 |
| module xxx is not allowed to load in restricted runtime. | 该模块不允许在受限运行时中使用，xxx表示模块名，建议用户删除该模块。 |
| module xxx is in blocklist, loading prohibited. | 该模块不允许在当前extension下使用，xxx表示模块名，建议用户删除该模块。 |

## 接口执行结果非预期，日志显示occur exception need return

部分Node-API接口在调用结束前会进行检查，检查虚拟机中是否存在JS异常。如果存在异常，则会打印出occur exception need return日志，并打印出检查点所在的行号，以及对应的Node-API接口名称。

解决此类问题有以下两种思路：

- 若该异常开发者不关心，可以选择直接清除。
  可直接使用napi接口napi_get_and_clear_last_exception，清理异常。调用时机：在打印occur exception need return日志的接口之前调用。

- 将该异常继续向上抛到ArkTS层，在ArkTS层进行捕获。
  发生异常时，可以选择走异常分支， 确保不再走多余的Native逻辑 ，直接返回到ArkTS层。

## napi_value和napi_ref的生命周期有何区别

- native_value由HandleScope管理，一般开发者不需要自己加HandleScope（uv_queue_work的complete callback除外）。

- napi_ref由开发者自己管理，需要手动delete。

## Node-API接口返回值不是napi_ok时，如何排查定位

Node-API接口正常执行后，会返回一个napi_ok的状态枚举值，若napi接口返回值不为napi_ok，可从以下几个方面进行排查。

- Node-API接口执行前一般会进行入参校验，首先进行的是判空校验。在代码中体现为：

  ```cpp
  CHECK_ENV： env判空校验
  CHECK_ARG：其它入参判空校验
  ```

- 某些Node-API接口还有入参类型校验。比如napi_get_value_double接口是获取JS number对应的C double值，首先就要保证的是：JS value类型为number，因此可以看到相关校验。

  ```cpp
  RETURN_STATUS_IF_FALSE(env, nativeValue->TypeOf() == NATIVE_NUMBER, napi_number_expected);
  ```

- 还有一些接口会对其执行结果进行校验。比如napi_call_function这个接口，其功能是执行一个JS function，当JS function中出现异常时，Node-API将会返回napi_pending_exception的状态值。

  ```cpp
  auto resultValue = engine->CallFunction(nativeRecv, nativeFunc, nativeArgv, argc);
  RETURN_STATUS_IF_FALSE(env, resultValue != nullptr, napi_pending_exception)
  ```

- 还有一些状态值需要根据相应Node-API接口具体分析：确认具体的状态值，分析这个状态值在什么情况下会返回，再排查具体出错原因。

## napi_threadsafe_function内存泄漏，应该如何处理

`napi_threadsafe_function`（下文简称tsfn）在使用时，常常会调用 `napi_acquire_threadsafe_function` 来更改tsfn的引用计数，确保tsfn不会意外被释放。但在使用完成后，应该及时使用 `napi_tsfn_release` 模式调用 `napi_release_threadsafe_function` 方法，以确保在所有调用回调都执行完成后，其引用计数能回归到调用 `napi_acquire_threadsafe_function` 方法之前的水平。当其引用计数归为0时，tsfn才能正确的被释放。

当在env即将退出，但tsfn的引用计数未被归零时，应该使用 `napi_tsfn_abort` 模式调用 `napi_release_threadsafe_function` 方法，确保在env释放后不再对tsfn进行持有及使用。在env退出后，继续持有tsfn进行使用，是一种未定义的行为，可能会触发崩溃。

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
  为构造一个env生命周期小于native生命周期的场景,
  本文需要使用worker, taskpool 或 napi_create_ark_runtime 等方法,
  创建非主线程的ArkTS运行环境，并人为的提前结束掉该线程
*/


// 定义一个数据结构，模拟存储tsfn的场景
class MyTsfnContext {
public:
// 因使用了napi方法, MyTsfnContext 应当只在js线程被构造
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

// tsfn 发送到 js 线程执行的回调
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

以下内容为主线程逻辑，主要用作创建worker线程和通知worker执行任务

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

以下内容为Worker线程逻辑，主要用以触发Native任务

```ts
// worker.ets
import worker, { ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@ohos.worker';
import napiModule from 'libentry.so'; // libentry.so: napi 库的模块名称

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {
    const action: string | undefined = e.data?.action;
    if (action === 'tsfn-demo') {
        // 触发 c++ 层的 tsfn demo
        napiModule.myTsfnDemo();
        // 通知主线程结束 worker
        workerPort.postMessage({action: 'kill'});
    };
}
```

## napi_get_uv_event_loop接口错误码说明

在OpenHarmony中，对使用非法的napi_env作为`napi_get_uv_event_loop`入参的行为加入了额外的参数校验，这一行为将直接反映到该接口的返回值上。该接口返回值详情如下：

1. 当env且（或）loop为nullptr时，返回`napi_invalid_arg`。
2. 当env为有效的napi_env且loop为合法指针，返回`napi_ok`。
3. 当env不是有效的napi_env（如已释放的env），返回`napi_generic_failure`。

常见错误场景示例如下：

```c++
napi_value NapiInvalidArg(napi_env env, napi_callback_info)
{
    napi_status status = napi_ok;
    status = napi_get_uv_event_loop(env, nullptr); // loop为nullptr, napi_invalid_arg
    if (status == napi_ok) {
        // do something
    }

    uv_loop_s* loop = nullptr;
    status = napi_get_uv_event_loop(nullptr, &loop); // env为nullptr, napi_invalid_arg
    if (status == napi_ok) {
        // do something
    }

    status = napi_get_uv_event_loop(nullptr, nullptr); // env, loop均为nullptr, napi_invalid_arg
    if (status == napi_ok) {
        // do something
    }

    return nullptr;
}

napi_value NapiGenericFailure(napi_env env, napi_callback_info)
{
    std::thread([]() {
        napi_env env = nullptr;
        napi_create_ark_runtime(&env); // 通常情况下，需要对该接口返回值进行判断
        // napi_destroy_ark_runtime 会将指针置空，拷贝一份用以构造问题场景
        napi_env copiedEnv = env;
        napi_destroy_ark_runtime(&env);
        uv_loop_s* loop = nullptr;
        napi_status status = napi_get_uv_event_loop(copiedEnv, &loop); // env无效, napi_generic_failure
        if (status == napi_ok) {
            // do something
        }
    }).detach();;
}
```
