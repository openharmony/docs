# Gewu Development Guide
<!--Kit: Kernel Enhance Kit-->
<!--Subsystem: Kernel-->
<!--Owner: @gatieme-->
<!--Designer: @tanyihua-->
<!--Tester: @panny060-->
<!--Adviser: @fang-jinxu-->
## When to Use

The feature is supported since API version 20. The on-device inference scenario has advantages such as ensuring user data privacy, low deployment costs, low latency, and high availability that is not affected by a network. However, compared with cloud-based inference, on-device inference also faces greater challenges because on-device devices have limited memory resources and computing power and are sensitive to power consumption. In addition, user experience and no frame freezing need to be ensured when on-device inference services are running. To cope with these challenges of on-device inference, the grid service provides QoS-aware inference acceleration and resource management optimization capabilities. This document describes how to use the grid object API.

## APIs

### Error Codes

The `OH_QoS_GewuErrorCode` enumeration type is used as the error code type of the grid. For details about the error codes returned by each function interface, see the interface description.

### Session Handle

Session handles are used for session management. When a session is successfully created using `OH_QoS_GewuSession`, the session handle can be obtained for submitting or terminating a request and destroying the session.

```C
typedef unsigned int OH_QoS_GewuSession;
```

### Request Handle

Request handles are used to manage requests. When a request is successfully submitted using `OH_QoS_GewuSubmitRequest`, a request handle can be obtained to terminate the request.

```C
typedef unsigned int OH_QoS_GewuRequest;
```

### Functions

| Name                     | Description                      |
| --------------------------- | -------------------------- |
| `OH_QoS_GewuCreateSession`  | Creates a session.                  |
| `OH_QoS_GewuDestroySession` | Destroys this session.                  |
| `OH_QoS_GewuSubmitRequest`  | Submit the request.                  |
| `OH_QoS_GewuAbortRequest`   | Abort request                  |

**`OH_QoS_GewuCreateSession`**

Description

The `OH_QoS_GewuCreateSession` interface is used to create a session.

This API asynchronously processes requests. That is, this API only initiates session creation and does not return a response after session resource allocation and model loading are complete. On-device inference resource management is optimized to dynamically load resources on demand.

The lifecycle of a session object starts when the `OH_QoS_GewuCreateSession` function is returned and ends when the `OH_QoS_GewuDestroySession` function is called.

Statement

```C
typedef struct {
    OH_QoS_GewuSession session;
    OH_QoS_GewuErrorCode error;
} OH_QoS_GewuCreateSessionResult;

OH_QoS_GewuCreateSessionResult OH_QoS_GewuCreateSession(const char* attributes);
```

Parameters

* The `const char* attributes` parameter indicates the JSON string of the session attribute. The JSON string supports the following fields:
    * "model": string Path of the model used by the session.

The following is an example of the JSON string of `attributes`:

```json
{
    "model": "/data/storage/el2/base/files/qwen2/"
}
```

Return value

If the session is successfully created, `error` in `OH_QoS_GewuCreateSessionResult` is `OH_QOS_GEWU_OK`, and `session` is the handle of the created session.
If a session fails to be created, `error` in `OH_QoS_GewuCreateSessionResult` indicates the error cause, and `OH_QOS_GEWU_NOMEM` indicates that the memory is insufficient for creating a session.

**`OH_QoS_GewuDestroySession`**

Description

The `OH_QoS_GewuDestroySession` interface is used to destroy a session.

You are advised to wait until all requests are completed or terminated before invoking this interface to destroy the session. If there are ongoing requests when this interface is called, the requests will be terminated and the user will not receive any response. Note that the session object cannot be used after this interface is called.

Statement

```C
OH_QoS_GewuErrorCode OH_QoS_GewuDestroySession(OH_QoS_GewuSession session);
```

Parameters

* The `OH_QoS_GewuSession session` parameter indicates the handle of the session to be destroyed.

Return value

If the session is successfully destroyed, the return value is `OH_QOS_GEWU_OK`.
If the session fails to be destroyed, the return value is the error cause. In the return value, `OH_QOS_GEWU_NOENT` indicates that the session cannot be found.

**`OH_QoS_GewuSubmitRequest`**

Description

The `OH_QoS_GewuSubmitRequest` interface is used to submit requests. This interface is used to asynchronously execute requests. That is, this interface only initiates requests but does not directly return results. When this interface returns results, the requests may not be executed. The request result is returned to the user by calling the callback provided by the user.

Statement

```C
typedef struct {
    OH_QoS_GewuRequest request;
    OH_QoS_GewuErrorCode error;
} OH_QoS_GewuSubmitRequestResult;

typedef void (*OH_QoS_GewuOnResponse)(void* context, const char* response);

OH_QoS_GewuSubmitRequestResult OH_QoS_GewuSubmitRequest(OH_QoS_GewuSession session, const char* request,
    OH_QoS_GewuOnResponse callback, void* context);
```

Parameters

The parameters of the `OH_QoS_GewuSubmitRequest` function are as follows:

* The `OH_QoS_GewuSession session` parameter is the session handle, indicating the session to which the request is submitted.
* The `const char* request` parameter is the JSON string of the request. The following fields are supported:
    * "messages": array. Message array. Each element in the array supports the following fields:
        * "role": string. Role type of a message. "developer" indicates the instruction provided by the developer or system, "user" indicates the user input, and "assistant" indicates the model generation result.
        * "content": string. Message content.
    * "stream": boolean or null. Whether to enable streaming inference. Non-streaming inference is used by default.
* The `OH_QoS_GewuOnResponse callback` parameter is the callback function of the request.
* The `void* context` parameter is the context pointer provided by the user and is transferred to the callback function. Generally, the user code can use this parameter to find the request corresponding to the received reply and process the request accordingly.

In addition, the parameters of the `OH_QoS_GewuOnResponse` callback function are as follows:

* The `void* context` parameter is the `context` pointer transferred when `OH_QoS_GewuSubmitRequest` is called.
* The `const char* response` parameter is the JSON string of the response, which contains the following fields:
    * "message": reply message, including the following fields:
        * "role": string. Role type of the message. The value must be assistant.
        * "content": string. Message content.
    * "finish_reason": string or null. Stop reason. Possible values are as follows:
        * null: The process is not stopped. In streaming inference, there are multiple replies. Only the last reply has a non-empty "finish_reason." For non-streaming inference, there is only one response, and "finish_reason" is not empty.
        * "stop": The service is stopped normally.
        * "abort": The user proactively terminates the task in advance.
        * "length": The number of tokens exceeds the upper limit.

Return value

If the request is successfully submitted, `error` in `OH_QoS_GewuSubmitRequestResult` is `OH_QOS_GEWU_OK`, and `request` is the request handle.
If the request fails to be submitted, `error` in `OH_QoS_GewuSubmitRequestResult` indicates the error cause, and `OH_QOS_GEWU_NOMEM` indicates that the memory is insufficient to process the request.

**`OH_QoS_GewuAbortRequest`**

Description

The `OH_QoS_GewuAbortRequest` interface is used to terminate a request in advance.

In normal cases, after calling the `OH_QoS_GewuSubmitRequest` API to submit a request, you do not need to call the `OH_QoS_GewuAbortRequest` API until the inference is complete (that is, a response indicating that `"finish_reason"` is not empty is received).
The `OH_QoS_GewuAbortRequest` API needs to be called only when you want to terminate the inference request in advance.

After this function is successfully called, the user does not receive the response to the request, and the request handle cannot be used.

Statement

```C
OH_QoS_GewuErrorCode OH_QoS_GewuAbortRequest(OH_QoS_GewuSession session, OH_QoS_GewuRequest request);
```

Parameters

* The `OH_QoS_GewuSession session` parameter is a handle of the session to which the request belongs.
* The `OH_QoS_GewuRequest request` parameter indicates the handle of the request to be aborted.

Return value

If the request is aborted successfully, the return value is `OH_QOS_GEWU_OK`.
If the request fails to be aborted, the return value is the error cause, where `OH_QOS_GEWU_NOENT` indicates that the request cannot be found.


## Example

Examples:

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

/*Used to store the chat status*/
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

/* Callback function when the inference result is received */
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
        /* Path of the model file. Change it based on the site requirements. */
        {"model", "/data/storage/el2/base/files/qwen2-awq"},
    };
    std::string attrStr = attrJson.dump(4);

    /*Create a session.*/
    OH_QoS_GewuCreateSessionResult createResult = OH_QoS_GewuCreateSession(attrStr.c_str());
    if (createResult.error != OH_QOS_GEWU_OK) {
        DEMO_LOGE("failed to create session, error=%d", (int)createResult.error);
        return -1;
    }
    OH_QoS_GewuSession session = createResult.session;

    /* Create and submit a request. */
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

    /* Abort the request in advance. */
    if (context.earlyAbort) {
        OH_QoS_GewuErrorCode error = OH_QoS_GewuAbortRequest(session, request);
        if (error != OH_QOS_GEWU_OK) {
            DEMO_LOGE("failed to abort request, error=%d", (int)error);
            return -1;
        }
    }

    /*Print the result.*/
    DEMO_LOGI("response: %s", context.responseContent.c_str());

    /*Destroy the session.*/
    OH_QoS_GewuErrorCode error = OH_QoS_GewuDestroySession(session);
    if (error != OH_QOS_GEWU_OK) {
        DEMO_LOGE("failed to destroy session, error=%d", (int)error);
        return -1;
    }
    return 0;
}
```
