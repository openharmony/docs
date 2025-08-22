# 格物开发指导
<!--Kit: Kernel Enhance Kit-->
<!--Subsystem: Kernel-->
<!--Owner: @gatieme-->
<!--Designer: @tanyihua-->
<!--Tester: @panny060-->
<!--Adviser: @fang-jinxu-->
## 场景介绍

从API version 20开始支持。端侧推理场景具有保障用户数据隐私、部署成本低、时延低、不受网络影响的高可用性等优点。但是，相比于云侧推理而言，端侧推理也面临着更大的挑战，因为端侧设备的内存资源受限、算力受限、对功耗敏感，并且还需要在运行端侧推理业务时保障用户体验、不卡顿。为了应对端侧推理的这些挑战，格物服务提供QoS感知的推理加速和资源管理优化能力。本文将指导开发者使用格物接口。

## 接口

### 错误码

`OH_QoS_GewuErrorCode`枚举型作为格物的错误码类型，各函数接口返回的错误码含义见接口描述。

### 会话句柄

会话句柄用于会话的管理。通过`OH_QoS_GewuSession`成功创建会话时可获得会话句柄，可用于提交/中止请求和销毁会话。

```C
typedef unsigned int OH_QoS_GewuSession;
```

### 请求句柄

请求句柄用于请求的管理。通过`OH_QoS_GewuSubmitRequest`成功提交请求时可获得请求句柄，可用于中止请求。

```C
typedef unsigned int OH_QoS_GewuRequest;
```

### 函数

| 函数名                      | 简介                       |
| --------------------------- | -------------------------- |
| `OH_QoS_GewuCreateSession`  | 创建会话                   |
| `OH_QoS_GewuDestroySession` | 销毁会话                   |
| `OH_QoS_GewuSubmitRequest`  | 提交请求                   |
| `OH_QoS_GewuAbortRequest`   | 中止请求                   |

**`OH_QoS_GewuCreateSession`**

描述

`OH_QoS_GewuCreateSession`接口用于创建会话。

该接口异步处理请求，即该接口只是发起创建会话，并不会等到会话资源分配完成、模型加载完成才返回。格物优化端侧推理资源管理，可以动态按需加载资源。

会话对象的生命周期从`OH_QoS_GewuCreateSession`函数返回开始，到调用`OH_QoS_GewuDestroySession`为止。

声明

```C
typedef struct {
    OH_QoS_GewuSession session;
    OH_QoS_GewuErrorCode error;
} OH_QoS_GewuCreateSessionResult;

OH_QoS_GewuCreateSessionResult OH_QoS_GewuCreateSession(const char* attributes);
```

参数

* `const char* attributes`参数表示会话属性的json字符串。该json字符串支持以下字段：
    * "model": string 表示会话使用的模型的路径。

`attributes` json字符串例子：

```json
{
    "model": "/data/storage/el2/base/files/qwen2/"
}
```

返回值

如果创建会话成功，返回值`OH_QoS_GewuCreateSessionResult`里的`error`为`OH_QOS_GEWU_OK`，而`session`为创建出来的会话句柄。
如果创建会话失败，返回值`OH_QoS_GewuCreateSessionResult`里的`error`为错误原因，其中`OH_QOS_GEWU_NOMEM`表示没有足够的内存创建会话。

**`OH_QoS_GewuDestroySession`**

描述

`OH_QoS_GewuDestroySession`接口用于销毁会话。

建议用户应当等待至所有请求都已完成或中止，然后再调用该接口来销毁会话。如果调用该接口时还有正在进行的请求，那些请求将会被中止，且用户不会再收到回复。注意，在调用完该接口后，会话对象无法再被使用。

声明

```C
OH_QoS_GewuErrorCode OH_QoS_GewuDestroySession(OH_QoS_GewuSession session);
```

参数

* `OH_QoS_GewuSession session`参数为要销毁的会话的句柄。

返回值

如果会话销毁成功，返回值为`OH_QOS_GEWU_OK`。
如果会话销毁失败，返回值为错误原因，其中`OH_QOS_GEWU_NOENT`表示找不到会话。

**`OH_QoS_GewuSubmitRequest`**

描述

`OH_QoS_GewuSubmitRequest`接口用于提交请求。该接口异步执行请求，即该接口只是发起请求，并不直接返回结果，该接口返回时请求可能尚未开始执行。请求的结果通过调用用户提供的回调返回给用户。

声明

```C
typedef struct {
    OH_QoS_GewuRequest request;
    OH_QoS_GewuErrorCode error;
} OH_QoS_GewuSubmitRequestResult;

typedef void (*OH_QoS_GewuOnResponse)(void* context, const char* response);

OH_QoS_GewuSubmitRequestResult OH_QoS_GewuSubmitRequest(OH_QoS_GewuSession session, const char* request,
    OH_QoS_GewuOnResponse callback, void* context);
```

参数

`OH_QoS_GewuSubmitRequest`函数的各参数如下：

* `OH_QoS_GewuSession session`参数是会话句柄，表示请求要提交到哪个会话。
* `const char* request`参数为请求的json字符串，支持以下字段：
    * "messages": array. 表示消息的数组其中每个元素支持以下字段：
        * "role": string. 消息的角色类型。其中"developer"表示开发者或系统提供的指示，"user"表示用户输入，"assistant"表示模型生成结果。
        * "content": string. 消息内容。
    * "stream": boolean or null. 是否使能流式推理，默认为非流式。
* `OH_QoS_GewuOnResponse callback`参数为请求的回调函数。
* `void* context`参数为用户提供的上下文指针，用于传递给回调函数。一般用法中，用户代码可通过该参数找到与收到的回复对应的请求，从而进行相应的处理。

另外，`OH_QoS_GewuOnResponse`回调函数的各参数如下：

* `void* context`参数是调用`OH_QoS_GewuSubmitRequest`时传进来的`context`指针。
* `const char* response`参数是回复的json字符串，包含以下字段：
    * "message": 回复消息，包含以下字段：
        * "role": string. 消息的角色类型，应为"assistant"。
        * "content": string. 消息内容。
    * "finish_reason": string or null. 停止原因，可能的值如下：
        * null: 表示没有停止。流式推理中会有多次回复，只有最后一次回复有非空的"finish_reason"。而非流式推理只有一次回复，且"finish_reason"非空。
        * "stop": 正常停止。
        * "abort": 用户主动提前中止。
        * "length": token数超过限制。

返回值

如果提交请求成功，返回值`OH_QoS_GewuSubmitRequestResult`里的`error`为`OH_QOS_GEWU_OK`，`request`为请求句柄。
如果提交请求失败，返回值`OH_QoS_GewuSubmitRequestResult`里的`error`为错误原因，其中`OH_QOS_GEWU_NOMEM`表示没有足够的内存处理该请求。

**`OH_QoS_GewuAbortRequest`**

描述

`OH_QoS_GewuAbortRequest`接口用于提前中止请求。

正常情况下，用户调用`OH_QoS_GewuSubmitRequest`接口提交请求后，等待至推理完成（即收到`"finish_reason"`不为空的回复），不需要调用`OH_QoS_GewuAbortRequest`接口。
只有当用户希望提前中止推理请求的时候，才需要调用`OH_QoS_GewuAbortRequest`接口。

成功调用该函数后，用户不会再收到该请求的回复，且该请求句柄无法再被使用。

声明

```C
OH_QoS_GewuErrorCode OH_QoS_GewuAbortRequest(OH_QoS_GewuSession session, OH_QoS_GewuRequest request);
```

参数

* `OH_QoS_GewuSession session`参数为请求所述的会话的句柄。
* `OH_QoS_GewuRequest request`参数为要中止的请求的句柄。

返回值

如果请求中止成功，返回值为`OH_QOS_GEWU_OK`。
如果请求中止失败，返回值为错误原因，其中`OH_QOS_GEWU_NOENT`表示找不到请求。


## 示例

示例如下:

```CPP
#include <future>
#define LOG_TAG "DEMO"
#include <hilog/log.h>
#include <nlohmann/json.hpp>
#include <qos/qos.h>
#include <string>

#define DEMO_LOGD(fmt, ...) OH_LOG_DEBUG(LOG_APP, fmt, ##__VA_ARGS__)
#define DEMO_LOGI(fmt, ...) OH_LOG_INFO(LOG_APP, fmt, ##__VA_ARGS__)
#define DEMO_LOGW(fmt, ...) OH_LOG_WARN(LOG_APP, fmt, ##__VA_ARGS__)
#define DEMO_LOGE(fmt, ...) OH_LOG_ERROR(LOG_APP, fmt, ##__VA_ARGS__)

using json = nlohmann::json;

/* 用于保存聊天状态 */
struct ChatContext {
public:
    ChatContext()
    {
        future = promise.get_future();
    }

    void Join()
    {
        assert(future.valid());
        std::string stopReasonStr = future.get();
        DEMO_LOGI("stopReasonStr=%s", stopReasonStr.c_str());
    }

    std::promise<std::string> promise;
    std::future<std::string> future;
    std::string responseContent;
    bool earlyAbort = false;
};

/* 接收到推理结果时的回调函数 */
void OnChatResponse(void *context, const char *response)
{
    ChatContext *chatContext = static_cast<ChatContext *>(context);
    if (chatContext->earlyAbort) {
        DEMO_LOGD("ignore response after early abort");
        return;
    }
    try {
        json responseJson = json::parse(response);
        chatContext->responseContent += responseJson.at("message").at("content").get<std::string>();
        json finishReasonJson = responseJson.at("finish_reason");
        if (!finishReasonJson.is_null()) {
            /* finish */
            std::string finishReasonStr = finishReasonJson.get<std::string>();
            chatContext->promise.set_value(finishReasonStr);
        } else if (chatContext->responseContent.find("\n") != std::string::npos) {
            /* customized stop */
            chatContext->promise.set_value("customized");
            chatContext->earlyAbort = true;
        } else {
            /* continue */
            ;
        }
    } catch (json::exception &e) {
        DEMO_LOGE("failed to parse response: %s", e.what());
    }
}

int Demo(void)
{
    DEMO_LOGI("Demo starts");
    json attrJson = {
        /* 模型文件位置，根据实际情况修改 */
        {"model", "/data/storage/el2/base/files/qwen2-awq"},
    };
    std::string attrStr = attrJson.dump(4);

    /* 创建会话 */
    OH_QoS_GewuCreateSessionResult createResult = OH_QoS_GewuCreateSession(attrStr.c_str());
    if (createResult.error != OH_QOS_GEWU_OK) {
        DEMO_LOGE("failed to create session, error=%d", (int)createResult.error);
        return -1;
    }
    OH_QoS_GewuSession session = createResult.session;

    /* 创建并提交请求 */
    ChatContext context;
    json requestJson = {
        {"messages", json::array({
            {{"role", "developer"}, {"content", "You are a helpful assistant"}},
            {{"role", "user"}, {"content", "What is LLM?"}},
        })},
        {"stream", true},
    };
    std::string requestStr = requestJson.dump(4);
    OH_QoS_GewuSubmitRequestResult submitResult = OH_QoS_GewuSubmitRequest(session, requestStr.c_str(),
                                                                           OnChatResponse, &context);
    if (submitResult.error != OH_QOS_GEWU_OK) {
        DEMO_LOGE("failed to submit request, error=%d", (int)submitResult.error);
        return -1;
    }
    OH_QoS_GewuRequest request = submitResult.request;
    context.Join();

    /* 提前中止请求 */
    if (context.earlyAbort) {
        OH_QoS_GewuErrorCode error = OH_QoS_GewuAbortRequest(session, request);
        if (error != OH_QOS_GEWU_OK) {
            DEMO_LOGE("failed to abort request, error=%d", (int)error);
            return -1;
        }
    }

    /* 打印结果 */
    DEMO_LOGI("response: %s", context.responseContent.c_str());

    /* 销毁会话 */
    OH_QoS_GewuErrorCode error = OH_QoS_GewuDestroySession(session);
    if (error != OH_QOS_GEWU_OK) {
        DEMO_LOGE("failed to destroy session, error=%d", (int)error);
        return -1;
    }
    return 0;
}
```
