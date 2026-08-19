# Gewu Service Development

<!--Kit: Kernel Enhance Kit-->
<!--Subsystem: Kernel-->
<!--Owner: @gatieme-->
<!--Designer: @tanyihua-->
<!--Tester: @panny060-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=84e5c687623c619df721fa927b62d6782396d98d translatedAt=2026-08-04T13:30:05.315Z pushedAt=2026-08-05T08:04:01.830Z -->

## When to Use

This capability is supported since API version 20. On-device inference helps protect user data privacy, lowers deployment costs, reduces latency, and provides high availability without relying on network connections. However, compared with cloud-side inference, on-device inference faces greater challenges because end-side devices have limited memory and compute resources, are sensitive to power consumption, and must keep the user experience smooth while running on-device inference services. To address these challenges, the Gewu service provides QoS-aware inference acceleration and resource management optimization. This section guides you in using the Gewu APIs.

## Available APIs

### Error Codes

The `OH_QoS_GewuErrorCode` enum is used as the error code type of Gewu. For the meaning of the error codes returned by each function API, see the corresponding API description.

### Session Handle

A session handle is used for session management. It is obtained when a session is successfully created via `OH_QoS_GewuCreateSession`, and can be used to submit/abort requests and destroy the session.

```C
typedef unsigned int OH_QoS_GewuSession;
```

### Request Handle

A request handle is used for request management. It is obtained when a request is successfully submitted via `OH_QoS_GewuSubmitRequest`, and can be used to abort the request.

```C
typedef unsigned int OH_QoS_GewuRequest;
```

### Functions

| Function Name               | Description                |
| --------------------------- | -------------------------- |
| `OH_QoS_GewuCreateSession`  | Creates a session             |
| `OH_QoS_GewuDestroySession` | Destroys a session            |
| `OH_QoS_GewuSubmitRequest`  | Submits a request             |
| `OH_QoS_GewuAbortRequest`   | Aborts a request              |

**`OH_QoS_GewuCreateSession`**

**Description**

The `OH_QoS_GewuCreateSession` API is used to create a session.

This API processes requests asynchronously. That is, the API only initiates session creation and returns before session resource allocation and model loading are complete. Gewu optimizes on-device inference resource management and can dynamically load resources on demand.

The lifecycle of a session object begins when the `OH_QoS_GewuCreateSession` function returns and ends when `OH_QoS_GewuDestroySession` is called.

**Declaration**

```C
typedef struct {
    OH_QoS_GewuSession session;
    OH_QoS_GewuErrorCode error;
} OH_QoS_GewuCreateSessionResult;

OH_QoS_GewuCreateSessionResult OH_QoS_GewuCreateSession(const char* attributes);
```

**Parameters**

`const char* attributes`: JSON string of session attributes. This JSON string supports the following field:

    * **"model"**: string, indicating the path of the model used by the session.

Example of the `attributes` JSON string:

```json
{
    "model": "/data/storage/el2/base/files/qwen2/"
}
```

**Returns**

If the session is created successfully, the `error` field in the returned `OH_QoS_GewuCreateSessionResult` is `OH_QOS_GEWU_OK`, and `session` is the handle of the created session.

If session creation fails, the `error` field in the returned `OH_QoS_GewuCreateSessionResult` indicates the cause of the error. `OH_QOS_GEWU_NOMEM` indicates that there is not enough memory to create the session.

**`OH_QoS_GewuDestroySession`**

**Description**

The `OH_QoS_GewuDestroySession` API is used to destroy a session.

Users are advised to wait until all requests are complete or aborted before calling this API to destroy the session. If there are still ongoing requests when this API is called, those requests will be aborted and users will not receive responses for them. Note that after this API is called, the session object can no longer be used.

**Declaration**

```C
OH_QoS_GewuErrorCode OH_QoS_GewuDestroySession(OH_QoS_GewuSession session);
```

**Parameters**

* `OH_QoS_GewuSession session`: handle of the session to be destroyed.

**Returns**

If the session is destroyed successfully, the return value is `OH_QOS_GEWU_OK`.

If the session destruction fails, the return value indicates the error cause, where `OH_QOS_GEWU_NOENT` indicates that the session was not found.

**`OH_QoS_GewuSubmitRequest`**

**Description**

The `OH_QoS_GewuSubmitRequest` API is used to submit a request. This API executes the request asynchronously. That is, the API only initiates the request and does not directly return the result. The request may not have started when this API returns. The request result is returned to the user through the callback provided by the user.

**Declaration**

```C
typedef struct {
    OH_QoS_GewuRequest request;
    OH_QoS_GewuErrorCode error;
} OH_QoS_GewuSubmitRequestResult;

typedef void (*OH_QoS_GewuOnResponse)(void* context, const char* response);

OH_QoS_GewuSubmitRequestResult OH_QoS_GewuSubmitRequest(OH_QoS_GewuSession session, const char* request,
    OH_QoS_GewuOnResponse callback, void* context);
```

**Parameters**

The parameters of `OH_QoS_GewuSubmitRequest` are as follows:

* `OH_QoS_GewuSession session`: session handle, indicating the session to which the request is to be submitted.

* `const char* request`: JSON string of the request, which supports the following fields:

    * **"messages"**: array, indicating an array of messages. Each element supports the following fields:

        * **"role"**: string, indicating the role type of the message. "developer" indicates instructions provided by the developer or system, "user" indicates user input, and "assistant" indicates model-generated results.

        * **"content"**: string, indicating the message content.

    * **"stream"**: boolean or null, indicating whether to enable streaming inference. **true** enables streaming inference. **false** or **null** enables non-streaming inference.

* `OH_QoS_GewuOnResponse callback`: callback function for the request.

* `void* context`: context pointer provided by the user and passed to the callback function. In common usage, user code can use this parameter to find the request corresponding to the received response and perform corresponding processing.

The parameters of the `OH_QoS_GewuOnResponse` callback function are as follows:

* `void* context`: `context` pointer passed in when `OH_QoS_GewuSubmitRequest` is called.

* `const char* response`: JSON string of the response, which contains the following fields:

    * **"message"**: response message, containing the following fields:

        * **"role"**: string, indicating the role type of the message. The value should be **"assistant"**.

        * **"content"**: string, indicating the message content.

    * **"finish_reason"**: string or null, indicating the stop reason. The possible values are as follows:

        * null: indicates that inference has not stopped. In streaming inference, multiple responses are returned, and only the last response has a non-empty **"finish_reason"**. In non-streaming inference, only one response is returned, and "finish_reason" is non-empty.

        * **"stop"**: stopped normally.

        * **"abort"**: proactively aborted by the user.

        * **"length"**: the number of tokens exceeds the limit.

**Returns**

If the request is submitted successfully, the `error` field in the returned `OH_QoS_GewuSubmitRequestResult` is `OH_QOS_GEWU_OK`, and `request` is the request handle.

If the request fails to be submitted, the `error` field in the returned `OH_QoS_GewuSubmitRequestResult` indicates the cause of the error. `OH_QOS_GEWU_NOMEM` indicates that there is not enough memory to process the request.

**`OH_QoS_GewuAbortRequest`**

**Description**

The `OH_QoS_GewuAbortRequest` API is used to abort a request early.

Normally, after calling `OH_QoS_GewuSubmitRequest` to submit a request, users wait until inference is complete, that is, until a response with a non-empty `"finish_reason"` is received. In this case, `OH_QoS_GewuAbortRequest` does not need to be called.

Call `OH_QoS_GewuAbortRequest` only when users want to abort an inference request early.

After this function is called successfully, users will not receive any more responses for this request, and the request handle can no longer be used.

**Declaration**

```C
OH_QoS_GewuErrorCode OH_QoS_GewuAbortRequest(OH_QoS_GewuSession session, OH_QoS_GewuRequest request);
```

**Parameters**

* `OH_QoS_GewuSession session`: handle of the session to which the request belongs.

* `OH_QoS_GewuRequest request`: handle of the request to be aborted.

**Returns**

If the request is aborted successfully, the return value is `OH_QOS_GEWU_OK`.

If the request fails to be aborted, the return value indicates the cause of the error. `OH_QOS_GEWU_NOENT` indicates that the request cannot be found.

## Example

The example is as follows:

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

/* Used to save chat state */
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

/* Callback function when an inference result is received */
void OnChatResponse(void *context, const char *response)
{
    ChatContext *chatContext = static_cast<ChatContext *>(context);
    if (chatContext->earlyAbort) {
        DEMO_LOGD("ignore response after early abort");
        return;
    }
    try {
        json responseJson = json::parse(response);
        std::string role = responseJson.at("message").at("role").get<std::string>();
        if (role != "assistant") {
            DEMO_LOGW("Discarding invalid response due to incorrect role");
            return;
        }
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
        /* Modify model file location according to the actual situation */
        {"model", "/data/storage/el2/base/files/qwen2-awq"},
    };
    std::string attrStr = attrJson.dump(4);

    /* Create a session */
    OH_QoS_GewuCreateSessionResult createResult = OH_QoS_GewuCreateSession(attrStr.c_str());
    if (createResult.error != OH_QOS_GEWU_OK) {
        DEMO_LOGE("failed to create session, error=%d", (int)createResult.error);
        return -1;
    }
    OH_QoS_GewuSession session = createResult.session;

    /* Create and submit a request */
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
        OH_QoS_GewuDestroySession(session);
        return -1;
    }
    OH_QoS_GewuRequest request = submitResult.request;
    context.Join();

    /* Abort the request early */
    if (context.earlyAbort) {
        OH_QoS_GewuErrorCode error = OH_QoS_GewuAbortRequest(session, request);
        if (error != OH_QOS_GEWU_OK) {
            DEMO_LOGE("failed to abort request, error=%d", (int)error);
            OH_QoS_GewuDestroySession(session);
            return -1;
        }
    }

    /* Print the result */
    DEMO_LOGI("response: %s", context.responseContent.c_str());

    /* Destroy the session */
    OH_QoS_GewuErrorCode error = OH_QoS_GewuDestroySession(session);
    if (error != OH_QOS_GEWU_OK) {
        DEMO_LOGE("failed to destroy session, error=%d", (int)error);
        return -1;
    }
    return 0;
}
```

> **NOTE**
>
> The demo code uses the third-party nlohmann/json library to simplify JSON parsing and construction. nlohmann/json is a modern C++ JSON library that provides an intuitive and concise way to process JSON data.
> Its design concept is to make JSON operations feel as natural as using STL containers.
> You can download the json.hpp file and place it in the include directory of the project. No additional library file needs to be linked.