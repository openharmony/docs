# Creating and Destroying JSVMs Using JSVM-API

## When to Use

Use **createJsCore** to create a JavaScript virtual machine (JSVM), which a runtime environment for executing JS code. The **createJsCore** returns a core ID, which uniquely identifies a VM. 

Use **evaluateJS** to run JS code in the VM of the specified core ID and define a promise in the JS code and run the function asynchronously.

Use **releaseJsCore** to release a JSVM.

## Example

Create multiple JS runtime environments and run JS code.

  ```cpp
#include <map>
#include <mutex>
#include <deque>
using namespace std;
// Define a map to manage each independent VM.
static map<int, JSVM_VM *> g_vmMap;
static map<int, JSVM_Env *> g_envMap;
static map<int, JSVM_CallbackStruct *> g_callBackStructMap;
static uint32_t ENVTAG_NUMBER = 0;
static std::mutex envMapLock;

class Task {
public:
    virtual ~Task() = default;
    virtual void Run() = 0;
};
static map<int, deque<Task *>> g_taskQueueMap;

// Customize Consoleinfo.
static JSVM_Value Consoleinfo(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 1;
    JSVM_Value args[1];
    char log[256] = "";
    size_t log_length;
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));

    JSVM_CALL(OH_JSVM_GetValueStringUtf8(env, args[0], log, 255, &log_length));
    log[255] = 0;
    OH_LOG_INFO(LOG_APP, "JSVM API TEST: %{public}s", log);
    return nullptr;
}

// Create a promise method, which is used to create a promise in JS code.
static JSVM_Value CreatePromise(JSVM_Env env, JSVM_CallbackInfo info) {
    OH_LOG_INFO(LOG_APP, "JSVM API TEST: CreatePromise start");
    int envID = -1;
    // Obtain envID of the current env.
    for (auto it = g_envMap.begin(); it != g_envMap.end(); ++it) {
        if (*it->second == env) {
            envID = it->first;
            break;
        }
    }
    if (envID == -1) {
        OH_LOG_ERROR(LOG_APP, "JSVM API TEST: CreatePromise envID faild");
        return nullptr;
    }
    JSVM_Value promise;
    JSVM_Deferred deferred;
    JSVM_CALL(OH_JSVM_CreatePromise(env, &deferred, &promise));
    // Define a ReadTask class to add deferred of the promise object to the execution queue.
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

// Customize the Add method.
static JSVM_Value Add(JSVM_Env env, JSVM_CallbackInfo info) {
    size_t argc = 2;
    JSVM_Value args[2];
    JSVM_CALL(OH_JSVM_GetCbInfo(env, info, &argc, args, NULL, NULL));
    double num1, num2;
    JSVM_CALL(OH_JSVM_GetValueDouble(env, args[0], &num1));
    JSVM_CALL(OH_JSVM_GetValueDouble(env, args[1], &num2));
    JSVM_Value sum = nullptr;
    JSVM_CALL(OH_JSVM_CreateDouble(env, num1 + num2, &sum));
    return sum;
}

// Customize the AssertEqual method.
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
    size_t size;
    CHECK_RET(OH_JSVM_GetValueStringUtf8(env, value, nullptr, 0, &size));
    char resultStr[size + 1];
    CHECK_RET(OH_JSVM_GetValueStringUtf8(env, value, resultStr, size + 1, &size));
    result = resultStr;
    return 0;
}

// Provide an external interface for creating the JSVM and return the unique ID.
static int CreateJsCore(uint32_t *result) {
    OH_LOG_INFO(LOG_APP, "JSVM CreateJsCore START");
    g_taskQueueMap[ENVTAG_NUMBER] = deque<Task *>{};

    if (g_aa == 0) {
        JSVM_InitOptions init_options;
        memset(&init_options, 0, sizeof(init_options));
        CHECK(OH_JSVM_Init(&init_options) == JSVM_OK);
        g_aa++;
    }
    std::lock_guard<std::mutex> lock_guard(envMapLock);

    // VM instance.
    g_vmMap[ENVTAG_NUMBER] = new JSVM_VM;
    JSVM_CreateVMOptions options;
    JSVM_VMScope vmScope;
    memset(&options, 0, sizeof(options));
    CHECK(OH_JSVM_CreateVM(&options, g_vmMap[ENVTAG_NUMBER]) == JSVM_OK);
    CHECK(OH_JSVM_OpenVMScope(*g_vmMap[ENVTAG_NUMBER], &vmScope) == JSVM_OK);

    // New environment.
    g_envMap[ENVTAG_NUMBER] = new JSVM_Env;
    g_callBackStructMap[ENVTAG_NUMBER] = new JSVM_CallbackStruct[4];

    // Register the pointers to the native callbacks and data provided by the user and expose them to JS code through JSVM-API.
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
                            g_envMap[ENVTAG_NUMBER]) == JSVM_OK);
    CHECK(OH_JSVM_CloseVMScope(*g_vmMap[ENVTAG_NUMBER], vmScope) == JSVM_OK);

    OH_LOG_INFO(LOG_APP, "JSVM CreateJsCore END");
    *result = ENVTAG_NUMBER;
    ENVTAG_NUMBER++;
    return 0;
}

// Provide an external interface for releasing the JSVM based on envId.
static int ReleaseJsCore(uint32_t coreEnvId) {
    OH_LOG_INFO(LOG_APP, "JSVM ReleaseJsCore START");
    CHECK(g_envMap.count(coreEnvId) != 0 && g_envMap[coreEnvId] != nullptr);

    std::lock_guard<std::mutex> lock_guard(envMapLock);

    CHECK(OH_JSVM_DestroyEnv(*g_envMap[coreEnvId]) == JSVM_OK);
    g_envMap[coreEnvId] = nullptr;
    g_envMap.erase(coreEnvId);
    CHECK(OH_JSVM_DestroyVM(*g_vmMap[coreEnvId]) == JSVM_OK);
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
// Provide an external interface for running the JS code in the JSVM identified by a core ID.
static int EvaluateJS(uint32_t envId, const char *source, std::string &res) {
    OH_LOG_INFO(LOG_APP, "JSVM EvaluateJS START");

    CHECK(g_envMap.count(envId) != 0 && g_envMap[envId] != nullptr);

    JSVM_Env env = *g_envMap[envId];
    JSVM_VM vm = *g_vmMap[envId];
    JSVM_VMScope vmScope;
    JSVM_EnvScope envScope;
    JSVM_HandleScope handleScope;
    JSVM_Value result;

    std::lock_guard<std::mutex> lock_guard(mutexLock);
    {
        // Create a JSVM environment.
        CHECK_RET(OH_JSVM_OpenVMScope(vm, &vmScope));
        CHECK_RET(OH_JSVM_OpenEnvScope(*g_envMap[envId], &envScope));
        CHECK_RET(OH_JSVM_OpenHandleScope(*g_envMap[envId], &handleScope));

        // Call the test function through the script.
        JSVM_Script script;
        JSVM_Value jsSrc;
        CHECK_RET(OH_JSVM_CreateStringUtf8(env, source, JSVM_AUTO_LENGTH, &jsSrc));
        CHECK_RET(OH_JSVM_CompileScript(env, jsSrc, nullptr, 0, true, nullptr, &script));
        CHECK_RET(OH_JSVM_RunScript(env, script, &result));

        JSVM_ValueType type;
        CHECK_RET(OH_JSVM_Typeof(env, result, &type));
        OH_LOG_INFO(LOG_APP, "JSVM API TEST type: %{public}d", type);
        // Execute tasks in the current env event queue.
        while (!g_taskQueueMap[envId].empty()) {
            auto task = g_taskQueueMap[envId].front();
            g_taskQueueMap[envId].pop_front();
            task->Run();
            delete task;
        }

        if (type == JSVM_STRING) {
            CHECK(fromOHStringValue(env, result, res) != -1);
        } else if (type == JSVM_BOOLEAN) {
            bool ret = false;
            CHECK_RET(OH_JSVM_GetValueBool(env, result, &ret));
            ret ? res = "true" : res = "false";
        } else if (type == JSVM_NUMBER) {
            int32_t num;
            CHECK_RET(OH_JSVM_GetValueInt32(env, result, &num));
            res = std::to_string(num);
        } else if (type == JSVM_OBJECT) {
            JSVM_Value objResult;
            CHECK_RET(OH_JSVM_JsonStringify(env, result, &objResult));
            CHECK(fromOHStringValue(env, objResult, res) != -1);
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

    // Create the first VM and bind the TS callback.
    uint32_t coreId1;
    CHECK(CreateJsCore(&coreId1) == 0);
    OH_LOG_INFO(LOG_APP, "TEST coreId: %{public}d", coreId1);
    // Run JS code in the first VM.
    std::string result1;
    CHECK(EvaluateJS(coreId1, source1, result1) == 0);
    OH_LOG_INFO(LOG_APP, "TEST evaluateJS: %{public}s", result1.c_str());

    // Create the second VM and bind it with the TS callback.
    uint32_t coreId2;
    CHECK(CreateJsCore(&coreId2) == 0);
    OH_LOG_INFO(LOG_APP, "TEST coreId: %{public}d", coreId2);
    // Run JS code in the second VM.
    std::string result2;
    CHECK(EvaluateJS(coreId2, source2, result2) == 0);
    OH_LOG_INFO(LOG_APP, "TEST evaluateJS: %{public}s", result2.c_str());

    // Release the first VM.
    CHECK(ReleaseJsCore(coreId1) == 0);
    // Release the second VM.
    CHECK(ReleaseJsCore(coreId2) == 0);
    OH_LOG_INFO(LOG_APP, "Test NAPI end");

    return 0;
}
  ```
