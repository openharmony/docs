# 使用JSVM-API接口创建多个引擎执行JS代码并销毁
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @huanghan18; @suyuehhh; @KasonChan; @string_sz; @diking-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->

## 场景介绍

开发者通过createJsCore方法来创建一个新的JS运行时环境，并通过该方法获得一个CoreID。然后，通过evaluateJS方法使用CoreID对应的运行环境来运行JS代码，在JS代码中创建promise并异步执行函数。最后，使用releaseJsCore方法来销毁CoreID对应的运行环境。

## 使用示例

JSVM-API接口开发流程参考[使用JSVM-API实现JS与C/C++语言交互开发流程](use-jsvm-process.md)，本文仅对接口对应C++相关代码进行展示。

创建多个JS运行时环境并运行JS代码

  ```cpp
#include <map>
#include <mutex>
#include <deque>
using namespace std;
// 定义map管理每个独立vm环境
static map<int, JSVM_VM *> g_vmMap;
static map<int, JSVM_Env *> g_envMap;
static map<int, JSVM_CallbackStruct *> g_callBackStructMap;
static uint32_t ENVTAG_NUMBER = 0;
static std::mutex envMapLock;
static int g_aa = 0;

#define CHECK_COND(cond)                                                                                               \
    do {                                                                                                               \
        if (!(cond)) {                                                                                                 \
            OH_LOG_ERROR(LOG_APP, "jsvm fail file: %{public}s line: %{public}d ret = false", __FILE__, __LINE__);      \
            return -1;                                                                                                 \
        }                                                                                                              \
    } while (0)

class Task {
public:
    virtual ~Task() = default;
    virtual void Run() = 0;
};
static map<int, deque<Task *>> g_taskQueueMap;

// 自定义Consoleinfo方法
static JSVM_Value Consoleinfo(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1];
    char log[256] = "";
    size_t log_length = 0;
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

    JSVM_CALL(OH_JSVM_GetValueStringUtf8(env, args[0], log, 255, &log_length));
    log[255] = 0;
    OH_LOG_INFO(LOG_APP, "JSVM API TEST: %{public}s", log);
    return nullptr;
}

// 自定义创建Promise方法用以在JS代码中创建Promise
static JSVM_Value CreatePromise(JSVM_Env env, JSVM_CallbackInfo info) {
    OH_LOG_INFO(LOG_APP, "JSVM API TEST: CreatePromise start");
    int envID = -1;
    // 通过当前env获取envID
    for (auto it = g_envMap.begin(); it != g_envMap.end(); ++it) {
        if (*it->second == env) {
            envID = it->first;
            break;
        }
    }
    if (envID == -1) {
        OH_LOG_ERROR(LOG_APP, "JSVM API TEST: CreatePromise envID failed");
        return nullptr;
    }
    JSVM_Value promise;
    JSVM_Deferred deferred;
    JSVM_CALL(OH_JSVM_CreatePromise(env, &deferred, &promise));
    // 设计ReadTask类用以将promise对象的deferred加入执行队列
    class ReadTask : public Task {
    public:
        ReadTask(JSVM_Env env, JSVM_Deferred deferred, int envNum) : env_(env), envID_(envNum), deferred_(deferred) {}
        void Run() override {
            // string str = "TEST RUN OH_JSVM_ResolveDeferred";
            int envID = 0;
            for (auto it = g_envMap.begin(); it != g_envMap.end(); ++it) {
                if (*it->second == env_) {
                    envID = it->first;
                    break;
                }
            }
            OH_LOG_INFO(LOG_APP, "JSVM API TEST: CreatePromise %{public}d", envID);
            JSVM_Value result;
            if (OH_JSVM_CreateInt32(env_, envID, &result) != JSVM_OK) {
                return;
            }
            if (OH_JSVM_ResolveDeferred(env_, deferred_, result) != JSVM_OK) {
                return;
            }
        }

    private:
        JSVM_Env env_;
        int envID_;
        JSVM_Deferred deferred_;
    };
    g_taskQueueMap[envID].push_back(new ReadTask(env, deferred, envID));
    OH_LOG_INFO(LOG_APP, "JSVM API TEST: CreatePromise end");
    return promise;
}

// 自定义Add方法
static JSVM_Value Add(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 2;
    JSVM_Value args[2];
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));
    double num1 = 0, num2 = 0;
    JSVM_CALL(OH_JSVM_GetValueDouble(env, args[0], &num1));
    JSVM_CALL(OH_JSVM_GetValueDouble(env, args[1], &num2));
    JSVM_Value sum = nullptr;
    JSVM_CALL(OH_JSVM_CreateDouble(env, num1 + num2, &sum));
    return sum;
}

// 自定义AssertEqual方法
static JSVM_Value AssertEqual(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 2;
    JSVM_Value args[2];
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

    bool isStrictEquals = false;
    JSVM_CALL(OH_JSVM_StrictEquals(env, args[0], args[1], &isStrictEquals));

    if (isStrictEquals) {
        OH_LOG_INFO(LOG_APP, "JSVM API TEST RESULT: PASS");
    } else {
        OH_LOG_INFO(LOG_APP, "JSVM API TEST RESULT: FAILED");
    }
    return nullptr;
}

static int fromOHStringValue(JSVM_Env &env, JSVM_Value &value, std::string &result) {
    size_t size = 0;
    CHECK_RET(OH_JSVM_GetValueStringUtf8(env, value, nullptr, 0, &size));
    char *resultStr = new char[size + 1];
    CHECK_RET(OH_JSVM_GetValueStringUtf8(env, value, resultStr, size + 1, &size));
    result = resultStr;
    delete[] resultStr;
    return 0;
}

// 提供创建JSVM运行环境的对外接口并返回对应唯一ID
static int CreateJsCore(uint32_t *result) {
    OH_LOG_INFO(LOG_APP, "JSVM CreateJsCore START");
    g_taskQueueMap[ENVTAG_NUMBER] = deque<Task *>{};

    if (g_aa == 0) {
        JSVM_InitOptions init_options;
        memset(&init_options, 0, sizeof(init_options));
        CHECK(OH_JSVM_Init(&init_options));
        g_aa++;
    }
    std::lock_guard<std::mutex> lock_guard(envMapLock);

    // 虚拟机实例
    g_vmMap[ENVTAG_NUMBER] = new JSVM_VM;
    JSVM_CreateVMOptions options;
    JSVM_VMScope vmScope;
    memset(&options, 0, sizeof(options));
    CHECK(OH_JSVM_CreateVM(&options, g_vmMap[ENVTAG_NUMBER]));
    CHECK(OH_JSVM_OpenVMScope(*g_vmMap[ENVTAG_NUMBER], &vmScope));

    // 新环境
    g_envMap[ENVTAG_NUMBER] = new JSVM_Env;
    g_callBackStructMap[ENVTAG_NUMBER] = new JSVM_CallbackStruct[4];

    // 注册用户提供的本地函数的回调函数指针和数据，通过JSVM-API暴露给js
    for (int i = 0; i < 4; i++) {
        g_callBackStructMap[ENVTAG_NUMBER][i].data = nullptr;
    }
    g_callBackStructMap[ENVTAG_NUMBER][0].callback = Consoleinfo;
    g_callBackStructMap[ENVTAG_NUMBER][1].callback = Add;
    g_callBackStructMap[ENVTAG_NUMBER][2].callback = AssertEqual;
    g_callBackStructMap[ENVTAG_NUMBER][3].callback = CreatePromise;
    JSVM_PropertyDescriptor descriptors[] = {
        {"consoleinfo", NULL, &g_callBackStructMap[ENVTAG_NUMBER][0], NULL, NULL, NULL, JSVM_DEFAULT},
        {"add", NULL, &g_callBackStructMap[ENVTAG_NUMBER][1], NULL, NULL, NULL, JSVM_DEFAULT},
        {"assertEqual", NULL, &g_callBackStructMap[ENVTAG_NUMBER][2], NULL, NULL, NULL, JSVM_DEFAULT},
        {"createPromise", NULL, &g_callBackStructMap[ENVTAG_NUMBER][3], NULL, NULL, NULL, JSVM_DEFAULT},
    };
    CHECK(OH_JSVM_CreateEnv(*g_vmMap[ENVTAG_NUMBER], sizeof(descriptors) / sizeof(descriptors[0]), descriptors,
                            g_envMap[ENVTAG_NUMBER]));
    CHECK(OH_JSVM_CloseVMScope(*g_vmMap[ENVTAG_NUMBER], vmScope));

    OH_LOG_INFO(LOG_APP, "JSVM CreateJsCore END");
    *result = ENVTAG_NUMBER;
    ENVTAG_NUMBER++;
    return 0;
}

// 对外提供释放JSVM环境接口，通过envId释放对应环境
static int ReleaseJsCore(uint32_t coreEnvId) {
    std::lock_guard<std::mutex> lock_guard(envMapLock);
    
    OH_LOG_INFO(LOG_APP, "JSVM ReleaseJsCore START");
    CHECK_COND(g_envMap.count(coreEnvId) != 0 && g_envMap[coreEnvId] != nullptr);

    CHECK(OH_JSVM_DestroyEnv(*g_envMap[coreEnvId]));
    g_envMap[coreEnvId] = nullptr;
    g_envMap.erase(coreEnvId);
    CHECK(OH_JSVM_DestroyVM(*g_vmMap[coreEnvId]));
    g_vmMap[coreEnvId] = nullptr;
    g_vmMap.erase(coreEnvId);
    delete[] g_callBackStructMap[coreEnvId];
    g_callBackStructMap[coreEnvId] = nullptr;
    g_callBackStructMap.erase(coreEnvId);
    g_taskQueueMap.erase(coreEnvId);

    OH_LOG_INFO(LOG_APP, "JSVM ReleaseJsCore END");
    return 0;
}

static std::mutex mutexLock;
// 对外提供执行JS代码接口，通过coreID在对应的JSVN环境中执行JS代码
static int EvaluateJS(uint32_t envId, const char *source, std::string &res) {
    OH_LOG_INFO(LOG_APP, "JSVM EvaluateJS START");

    CHECK_COND(g_envMap.count(envId) != 0 && g_envMap[envId] != nullptr);

    JSVM_Env env = *g_envMap[envId];
    JSVM_VM vm = *g_vmMap[envId];
    JSVM_VMScope vmScope;
    JSVM_EnvScope envScope;
    JSVM_HandleScope handleScope;
    JSVM_Value result;

    std::lock_guard<std::mutex> lock_guard(mutexLock);
    {
        // 创建JSVM环境
        CHECK_RET(OH_JSVM_OpenVMScope(vm, &vmScope));
        CHECK_RET(OH_JSVM_OpenEnvScope(*g_envMap[envId], &envScope));
        CHECK_RET(OH_JSVM_OpenHandleScope(*g_envMap[envId], &handleScope));

        // 通过script调用测试函数
        JSVM_Script script;
        JSVM_Value jsSrc;
        CHECK_RET(OH_JSVM_CreateStringUtf8(env, source, JSVM_AUTO_LENGTH, &jsSrc));
        CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
        CHECK_RET(OH_JSVM_RunScript(env, script, &result));

        JSVM_ValueType type;
        CHECK_RET(OH_JSVM_Typeof(env, result, &type));
        OH_LOG_INFO(LOG_APP, "JSVM API TEST type: %{public}d", type);
        // Execute tasks in the current env event queue
        while (!g_taskQueueMap[envId].empty()) {
            auto task = g_taskQueueMap[envId].front();
            g_taskQueueMap[envId].pop_front();
            task->Run();
            delete task;
        }

        if (type == JSVM_STRING) {
            CHECK_COND(fromOHStringValue(env, result, res) != -1);
        } else if (type == JSVM_BOOLEAN) {
            bool ret = false;
            CHECK_RET(OH_JSVM_GetValueBool(env, result, &ret));
            ret ? res = "true" : res = "false";
        } else if (type == JSVM_NUMBER) {
            int32_t num = 0;
            CHECK_RET(OH_JSVM_GetValueInt32(env, result, &num));
            res = std::to_string(num);
        } else if (type == JSVM_OBJECT) {
            JSVM_Value objResult;
            CHECK_RET(OH_JSVM_JsonStringify(env, result, &objResult));
            CHECK_COND(fromOHStringValue(env, objResult, res) != -1);
        }
    }
    {
        bool aal = false;
        CHECK_RET(OH_JSVM_PumpMessageLoop(*g_vmMap[envId], &aal));
        CHECK_RET(OH_JSVM_PerformMicrotaskCheckpoint(*g_vmMap[envId]));
        CHECK_RET(OH_JSVM_CloseHandleScope(*g_envMap[envId], handleScope));
        CHECK_RET(OH_JSVM_CloseEnvScope(*g_envMap[envId], envScope));
        CHECK_RET(OH_JSVM_CloseVMScope(*g_vmMap[envId], vmScope));
    }
    OH_LOG_INFO(LOG_APP, "JSVM EvaluateJS END");
    return 0;
}

static int32_t TestJSVM() {
    const char source1[] = "{\
        let a = \"hello World\";\
        consoleinfo(a);\
        const mPromise = createPromise();\
        mPromise.then((result) => {\
          assertEqual(result, 0);\
        });\
        a;\
    };";

    const char source2[] = "{\
        let a = \"second hello\";\
        consoleinfo(a);\
        let b = add(99, 1);\
        assertEqual(100, b);\
        assertEqual(add(99, 1), 100);\
        createPromise().then((result) => {\
            assertEqual(result, 1);\
        });\
        a;\
    };";

    // 创建首个运行环境，并绑定TS回调
    uint32_t coreId1 = 0;
    CHECK_COND(CreateJsCore(&coreId1) == 0);
    OH_LOG_INFO(LOG_APP, "TEST coreId: %{public}d", coreId1);
    // 在首个运行环境中执行JS代码
    std::string result1;
    CHECK_COND(EvaluateJS(coreId1, source1, result1) == 0);
    OH_LOG_INFO(LOG_APP, "TEST evaluateJS: %{public}s", result1.c_str());

    // 创建第二个运行环境，并绑定TS回调
    uint32_t coreId2 = 0;
    CHECK_COND(CreateJsCore(&coreId2) == 0);
    OH_LOG_INFO(LOG_APP, "TEST coreId: %{public}d", coreId2);
    // 在第二个运行环境中执行JS代码
    std::string result2;
    CHECK_COND(EvaluateJS(coreId2, source2, result2) == 0);
    OH_LOG_INFO(LOG_APP, "TEST evaluateJS: %{public}s", result2.c_str());

    // 释放首个运行环境
    CHECK_COND(ReleaseJsCore(coreId1) == 0);
    // 释放第二个运行环境
    CHECK_COND(ReleaseJsCore(coreId2) == 0);
    OH_LOG_INFO(LOG_APP, "Test NAPI end");

    return 0;
}
```
<!-- @[runtime_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/JSVMAPI/JsvmDebug/runtimetask/src/main/cpp/hello.cpp) -->
预计的输出结果：
```
JSVM CreateJsCore START
JSVM CreateJsCore END
TEST coreId: 0
JSVM EvaluateJS START
JSVM API TEST: hello World
JSVM API TEST: CreatePromise start
JSVM API TEST: CreatePromise end
JSVM API TEST type: 4
JSVM API TEST: CreatePromise 0
JSVM API TEST RESULT: PASS
JSVM EvaluateJS END
TEST evaluateJS: hello World
JSVM CreateJsCore START
JSVM CreateJsCore END
TEST coreId: 1
JSVM EvaluateJS START
JSVM API TEST: second hello
JSVM API TEST RESULT: PASS
JSVM API TEST RESULT: PASS
JSVM API TEST: CreatePromise start
JSVM API TEST: CreatePromise end
JSVM API TEST type: 4
JSVM API TEST: CreatePromise 1
JSVM API TEST RESULT: PASS
JSVM EvaluateJS END
TEST evaluateJS: second hello
JSVM ReleaseJsCore START
JSVM ReleaseJsCore END
JSVM ReleaseJsCore START
JSVM ReleaseJsCore END
Test NAPI end
```
