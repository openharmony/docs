# Gewu Development
<!--Kit: Kernel Enhance Kit-->
<!--Subsystem: Kernel-->
<!--Owner: @gatieme-->
<!--Designer: @tanyihua-->
<!--Tester: @panny060-->
<!--Adviser: @fang-jinxu-->
## Scenario

The feature is supported since API version 20. On-device inference ensures user data privacy, low deployment costs, low latency, and high availability without being affected by networks. However, compared with cloud inference, on-device inference faces greater challenges such as limited memory resources, limited computing power, and sensitivity to power consumption. In addition, it needs to ensure user experience and prevent frame freezing when running services. To address these challenges, Gewu provides QoS-aware inference acceleration and resource management optimization. This topic describes how to use Gewu APIs.

## APIs

### Error Codes

**OH_QoS_GewuErrorCode** is an enumeration type of Gewu error codes. For details about the error codes returned by each function, see the API description.

### Session Handles

Session handles are used to manage sessions. You can obtain a session handle by successfully creating a session through **OH_QoS_GewuSession**. The session handle can be used to submit or abort a request and destroy a session.

```C
typedef unsigned int OH_QoS_GewuSession;
```

### Request Handles

Request handles are used to manage requests. You can obtain a request handle by successfully submitting a request through **OH_QoS_GewuSubmitRequest**. The request handle can be used to abort a request.

```C
typedef unsigned int OH_QoS_GewuRequest;
```

### Functions

| Name                     | Description                      |
| --------------------------- | -------------------------- |
| `OH_QoS_GewuCreateSession`  | Creates a session.                  |
| `OH_QoS_GewuDestroySession` | Destroys a session.                  |
| `OH_QoS_GewuSubmitRequest`  | Submits a request.                  |
| `OH_QoS_GewuAbortRequest`   | Aborts a request.                  |

**`OH_QoS_GewuCreateSession`**

**Description**

Creates a session asynchronously.

That is, this API only initiates a session creation request and does not wait until the session resource allocation and model loading are complete. Gewu optimizes on-device inference resource management and enables dynamic on-demand resource loading.

The lifecycle of a session object starts from the return of the **OH_QoS_GewuCreateSession** function and ends when the **OH_QoS_GewuDestroySession** function is called.

**Declaration**

```C
typedef struct {
    OH_QoS_GewuSession session;
    OH_QoS_GewuErrorCode error;
} OH_QoS_GewuCreateSessionResult;

OH_QoS_GewuCreateSessionResult OH_QoS_GewuCreateSession(const char* attributes);
```

**Parameters**

* The **const char* attributes** parameter indicates the JSON string of the session attribute. It supports the following fields:
    * **"model": string**: Path of the model used by the session.

Example of the JSON string of `attributes`:

```json
{
    "model": "/data/storage/el2/base/files/qwen2/"
}
```

**Return Value**

If the session is created successfully, the value of **error** in the return value **OH_QoS_GewuCreateSessionResult** is **OH_QOS_GEWU_OK**, and the value of **session** is the created session handle.
If the session fails to be created, the value of **error** in the return value **OH_QoS_GewuCreateSessionResult** is the cause of the error. **OH_QOS_GEWU_NOMEM** indicates that no sufficient memory is available for creating the session.

**`OH_QoS_GewuDestroySession`**

**Description**

Destroys a session.

You are advised to wait until all requests are complete or aborted before calling this API. If there are ongoing requests when this API is called, the requests will be aborted, and you will not receive responses. Note that after this API is called, the session object cannot be used.

**Declaration**

```C
OH_QoS_GewuErrorCode OH_QoS_GewuDestroySession(OH_QoS_GewuSession session);
```

**Parameters**

* **OH_QoS_GewuSession session**: Handle to the session to be destroyed.

**Return Value**

If the session is destroyed successfully, the return value is **OH_QOS_GEWU_OK**.
If the session fails to be destroyed, the return value is the cause of the error. **OH_QOS_GEWU_NOENT** indicates that the session cannot be found.

**`OH_QoS_GewuSubmitRequest`**

**Description**

Submits a request asynchronously. That is, this API only initiates a request but does not directly return a result. When this API returns, the request may not be executed. The result is returned through your callback.

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

The parameters of the **OH_QoS_GewuSubmitRequest** function are as follows:

* **OH_QoS_GewuSession session**: Session handle, indicating the session to which the request is submitted.
* **const char* request**: JSON string of the request. The following fields are supported:
    * **"messages": array**: Array of messages, where each element supports the following fields:
        * **"role": string**: Role type of the message. **developer** indicates indications provided by developers or the system, **user** indicates user input, and **assistant** indicates the result generated by the model.
        * **"content": string**: Message content.
    * **"stream": boolean or null**: Whether to enable stream inference. The default value is non-stream.
* **OH_QoS_GewuOnResponse callback**: callback of the request.
* **void* context**: context pointer provided by yourself, which is passed to the callback. In common cases, your code can find the request corresponding to the received response through this parameter for further processing.

The parameters of the **OH_QoS_GewuOnResponse** callback are as follows:

* **void* context**: **context** pointer passed in when **OH_QoS_GewuSubmitRequest** is called.
* **const char* response**: JSON string of the response, which contains the following fields:
    * **"message"**: response message, which contains the following fields:
        * **"role": string**: Role of the message, which should be **assistant**.
        * **"content": string**: Message content.
    * **"finish_reason": string or null**: Stop reason, which can be:
        * **null**: The request is not stopped. In streaming inference, there are multiple responses, and only the last response has a non-empty **finish_reason**. For non-streaming inference, there is only one response, and **finish_reason** is not empty.
        * **"stop"**: The request is stopped normally.
        * **"abort"**: The request is stopped by the user in advance.
        * **"length"**: The number of tokens exceeds the upper limit.

**Return Value**

If the request is submitted successfully, the value of **error** in **OH_QoS_GewuSubmitRequestResult** is **OH_QOS_GEWU_OK**, and the value of **request** is the request handle.
If the request fails to be submitted, the value of **error** in **OH_QoS_GewuSubmitRequestResult** is the cause of the error. **OH_QOS_GEWU_NOMEM** indicates that memory is insufficient for processing the request.

**`OH_QoS_GewuAbortRequest`**

**Description**

Aborts a request in advance.

In normal cases, after calling the **OH_QoS_GewuSubmitRequest** API to submit a request, you only need to wait until the inference is complete (that is, the response where **finish_reason** is not empty is received); you do not need to call the **OH_QoS_GewuAbortRequest** API.
You need to call the **OH_QoS_GewuAbortRequest** API only when you want to abort an inference request in advance.

After this function is successfully called, you will not receive any response to the request, and the request handle cannot be used.

**Declaration**

```C
OH_QoS_GewuErrorCode OH_QoS_GewuAbortRequest(OH_QoS_GewuSession session, OH_QoS_GewuRequest request);
```

**Parameters**

* **OH_QoS_GewuSession session**: Handle to the request session.
* **OH_QoS_GewuRequest request**: Handle to the request to be aborted.

**Return Value**

If the request is aborted successfully, the return value is **OH_QOS_GEWU_OK**.
If the request fails to be aborted, the return value is the cause of the error. **OH_QOS_GEWU_NOENT** indicates that the request cannot be found.


## Examples

The following is an example:

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

/* Used to save the chat status */
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

/* Callback triggered when the inference result is received */
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
        /* Path of the model file. Change it with the actual path. */
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
        return -1;
    }
    OH_QoS_GewuRequest request = submitResult.request;
    context.Join();

    /* Abort the request in advance */
    if (context.earlyAbort) {
        OH_QoS_GewuErrorCode error = OH_QoS_GewuAbortRequest(session, request);
        if (error != OH_QOS_GEWU_OK) {
            DEMO_LOGE("failed to abort request, error=%d", (int)error);
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
