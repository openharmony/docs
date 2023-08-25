# AI

## Introduction

The AI subsystem is the part of OpenHarmony that provides native distributed AI capabilities. At the heart of the subsystem is a unified AI engine framework, which implements quick integration of AI algorithm plug-ins. The framework consists of the plug-in management, module management, and communication management modules, fulfilling lifecycle management and on-demand deployment of AI algorithms. Under this framework, AI algorithm APIs will be standardized to facilitate distributed calling of AI capabilities. In addition, unified inference APIs will be provided to adapt to different inference framework hierarchies.

**Figure  1**  AI engine framework<a name="fig17296164711526"></a>  
![](figures/ai-engine-framework.png "ai-engine-framework")

## Directory Structure

```
/foundation/ai/engine                        # Home directory of the AI subsystem
├── interfaces
│  └── kits                                  # External APIs of the AI subsystem
└── services
│  ├── client                                # Client module of the AI subsystem
│  │  ├── client_executor                    # Executor of the client module
│  │  └── communication_adapter              # Communication adaptation layer for the client module, with extension supported
│  ├── common                                # Common tools and protocol modules of the AI subsystem
│  │  ├── platform
│  │  ├── protocol
│  │  └── utils
│  └── server                                # Server module of the AI subsystem
│  │  ├── communication_adapter              # Communication adaptation layer for the server module, with extension supported
│  │  ├── plugin
│  │     ├── asr
│  │        └── keyword_spotting             # ASR algorithm plug-in reference: keyword spotting
│  │     └── cv
│  │        └── image_classification         # CV algorithm plug-in reference: image classification
│  │  ├── plugin_manager
│  │  └── server_executor                    # Executor of the server module
```

## Constraints

* **Programming language**: C/C++

* **Operating system**: OpenHarmony mini- and small-system

* **Others**: The System Ability Manager \(Samgr\) has been started and is running properly.

## Usage

1.  Compile the AI subsystem.

    The source code for lightweight AI framework is available at  **//foundation/ai/engine/services**.

    The compilation procedure is as follows:

    1. Set the compilation path.

    ```
    hb set -root dir (root dir is the root directory of the project code.)
    ```

    2. Specify the product for compilation. \(After the product list is displayed using the following command, move to the desired product with arrow keys and press  **Enter**.\)

    ```
    hb set -p
    ```

    3. Start compilation.

    ```
    hb build -f (Use this command if you want to compile the entire repository.)
    hb build ai_engine (Use this command if you want to compile only the ai_engine module.)
    ```

    >**Note**: For details about the hb configuration, see the readme of the build\_lite subsystem.

2.  Develop the plug-in, with keyword spotting as an example.

    Directory: //foundation/ai/engine/services/server/plugin/asr/keyword\_spotting

    >**Note**: The plug-in must implement the  **IPlugin**  and  **IPluginCallback**  APIs provided by the server.

    ```
    #include "plugin/i_plugin.h
    class KWSPlugin : public IPlugin {       // Inherits the public base class of the IPlugin API for Keywords Spotting Plugin (KWSPlugin).
        KWSPlugin();
        ~KWSPlugin();
    
        const long long GetVersion() const override;
        const char* GetName() const override;
        const char* GetInferMode() const override;
    
        int32_t Prepare(long long transactionId, const DataInfo &amp;amp;inputInfo, DataInfo &amp;amp;outputInfo) override;
        int32_t SetOption(int optionType, const DataInfo &amp;amp;inputInfo) override;
        int32_t GetOption(int optionType, const DataInfo &amp;amp;inputInfo, DataInfo &amp;amp;outputInfo) override;
        int32_t SyncProcess(IRequest *request, IResponse *&amp;amp;response) override;
        int32_t AsyncProcess(IRequest *request, IPluginCallback*callback) override;
        int32_t Release(bool isFullUnload, long long transactionId, const DataInfo &amp;amp;inputInfo) override;
        .
        .
        .
    };
    ```

    >**Note**: Depending on the algorithm in use, you only need to implement the  **SyncProcess**  or  **AsyncProcess**  API. Use an empty function as a placeholder for the other API. In this example, the KWS plug-in uses the synchronous algorithm. Therefore, you need to implement  **SyncProcess**  API and use an empty function as a placeholder for the  **SyncProcess**  API.

    ```
    #include "aie_log.h"
    #include "aie_retcode_inner.h"
    .
    .
    .
    
    const long long KWSPlugin::GetVersion() const
    {
        return ALGOTYPE_VERSION_KWS;
    }
    
    const char *KWSPlugin::GetName() const
    {
        return ALGORITHM_NAME_KWS.c_str();
    }
    
    const char *KWSPlugin::GetInferMode() const
    {
        return DEFAULT_INFER_MODE.c_str();
    }
    .
    .
    .
    int32_t KWSPlugin::AsyncProcess(IRequest *request, IPluginCallback *callback)
    {
        return RETCODE_SUCCESS;
    }
    ```

3.  Develop the SDK, with keyword spotting as an example.

    Directory: //foundation/ai/engine/services/client/algorithm\_sdk/asr/keyword\_spotting

    Keyword spotting SDK:

    ```
    class KWSSdk {
    public:
        KWSSdk();
        virtual ~KWSSdk();
    
        /**
         * @brief Create a new session with KWS Plugin
         *
         * @return Returns KWS_RETCODE_SUCCESS(0) if the operation is successful,
         *         returns a non-zero value otherwise.
         */
        int32_t Create();
    
        /**
         * @brief Synchronously execute keyword spotting once
         *
         * @param audioInput pcm data.
         * @return Returns KWS_RETCODE_SUCCESS(0) if the operation is successful,
         *         returns a non-zero value otherwise.
         */
        int32_t SyncExecute(const Array<int16_t> &audioInput);
    
        /**
         * @brief Asynchronously execute keyword spotting once
         *
         * @param audioInput pcm data.
         * @return Returns KWS_RETCODE_SUCCESS(0) if the operation is successful,
         *         returns a non-zero value otherwise.
         */
        int32_t AsyncExecute(const Array<int16_t> &audioInput);
    
        /**
         * @brief Set callback
         *
         * @param callback Callback function that will be called during the process.
         * @return Returns KWS_RETCODE_SUCCESS(0) if the operation is successful,
         *         returns a non-zero value otherwise.
         */
        int32_t SetCallback(const std::shared_ptr<KWSCallback> &callback);
    
        /**
         * @brief Destroy the created session with KWS Plugin
         *
         * @return Returns KWS_RETCODE_SUCCESS(0) if the operation is successful,
         *         returns a non-zero value otherwise.
         */
        int32_t Destroy();
    }
    ```

    >**Note**: The sequence for the SDK to call client APIs of the AI engine is as follows: AieClientInit -\> AieClientPrepare -\> AieClientSyncProcess/AieClientAsyncProcess -\> AieClientRelease -\> AieClientDestroy. An exception will be thrown if the call sequence is violated. In addition, all these APIs must be called. Otherwise, a memory leakage may occur.

    ```
    int32_t KWSSdk::KWSSdkImpl::Create()
    {
        if (kwsHandle_ != INVALID_KWS_HANDLE) {
            HILOGE("[KWSSdkImpl]The SDK has been created");
            return KWS_RETCODE_FAILURE;
        }
        if (InitComponents() != RETCODE_SUCCESS) {
            HILOGE("[KWSSdkImpl]Fail to init sdk components");
            return KWS_RETCODE_FAILURE;
        }
        int32_t retCode = AieClientInit(configInfo_, clientInfo_, algorithmInfo_, nullptr);
        if (retCode != RETCODE_SUCCESS) {
            HILOGE("[KWSSdkImpl]AieClientInit failed. Error code[%d]", retCode);
            return KWS_RETCODE_FAILURE;
        }
        if (clientInfo_.clientId == INVALID_CLIENT_ID) {
            HILOGE("[KWSSdkImpl]Fail to allocate client id");
            return KWS_RETCODE_FAILURE;
        }
        DataInfo inputInfo = {
            .data = nullptr,
            .length = 0,
        };
        DataInfo outputInfo = {
            .data = nullptr,
            .length = 0,
        };
        retCode = AieClientPrepare(clientInfo_, algorithmInfo_, inputInfo, outputInfo, nullptr);
        if (retCode != RETCODE_SUCCESS) {
            HILOGE("[KWSSdkImpl]AieclientPrepare failed. Error code[%d]", retCode);
            return KWS_RETCODE_FAILURE;
        }
        if (outputInfo.data == nullptr || outputInfo.length <= 0) {
            HILOGE("[KWSSdkImpl]The data or length of output info is invalid");
            return KWS_RETCODE_FAILURE;
        }
        MallocPointerGuard<unsigned char> pointerGuard(outputInfo.data);
        retCode = PluginHelper::UnSerializeHandle(outputInfo, kwsHandle_);
        if (retCode != RETCODE_SUCCESS) {
            HILOGE("[KWSSdkImpl]Get handle from inputInfo failed");
            return KWS_RETCODE_FAILURE;
        }
        return KWS_RETCODE_SUCCESS;
    }
    
    int32_t KWSSdk::KWSSdkImpl::SyncExecute(const Array<uint16_t> &audioInput)
    {
        intptr_t newHandle = 0;
        Array<int32_t> kwsResult = {
            .data = nullptr,
            .size = 0
        };
        DataInfo inputInfo = {
            .data = nullptr,
            .length = 0
        };
        DataInfo outputInfo = {
            .data = nullptr,
            .length = 0
        };
        int32_t retCode = PluginHelper::SerializeInputData(kwsHandle_, audioInput, inputInfo);
        if (retCode != RETCODE_SUCCESS) {
            HILOGE("[KWSSdkImpl]Fail to serialize input data");
            callback_->OnError(KWS_RETCODE_SERIALIZATION_ERROR);
            return RETCODE_FAILURE;
        }
        retCode = AieClientSyncProcess(clientInfo_, algorithmInfo_, inputInfo, outputInfo);
        if (retCode != RETCODE_SUCCESS) {
            HILOGE("[KWSSdkImpl]AieClientSyncProcess failed. Error code[%d]", retCode);
            callback_->OnError(KWS_RETCODE_PLUGIN_EXECUTION_ERROR);
            return RETCODE_FAILURE;
        }
        if (outputInfo.data == nullptr || outputInfo.length <= 0) {
            HILOGE("[KWSSdkImpl] The data or length of outputInfo is invalid. Error code[%d]", retCode);
            callback_->OnError(KWS_RETCODE_NULL_PARAM);
            return RETCODE_FAILURE;
        }
        MallocPointerGuard<unsigned char> pointerGuard(outputInfo.data);
        retCode = PluginHelper::UnSerializeOutputData(outputInfo, newHandle, kwsResult);
        if (retCode != RETCODE_SUCCESS) {
            HILOGE("[KWSSdkImpl]UnSerializeOutputData failed. Error code[%d]", retCode);
            callback_->OnError(KWS_RETCODE_UNSERIALIZATION_ERROR);
            return retCode;
        }
        if (kwsHandle_ != newHandle) {
            HILOGE("[KWSSdkImpl]The handle[%lld] of output data is not equal to the current handle[%lld]",
                (long long)newHandle, (long long)kwsHandle_);
            callback_->OnError(KWS_RETCODE_PLUGIN_SESSION_ERROR);
            return RETCODE_FAILURE;
        }
        callback_->OnResult(kwsResult);
        return RETCODE_SUCCESS;
    }
    
    int32_t KWSSdk::KWSSdkImpl::Destroy()
    {
        if (kwsHandle_ == INVALID_KWS_HANDLE) {
            return KWS_RETCODE_SUCCESS;
        }
        DataInfo inputInfo = {
            .data = nullptr,
            .length = 0
        };
        int32_t retCode = PluginHelper::SerializeHandle(kwsHandle_, inputInfo);
        if (retCode != RETCODE_SUCCESS) {
            HILOGE("[KWSSdkImpl]SerializeHandle failed. Error code[%d]", retCode);
            return KWS_RETCODE_FAILURE;
        }
        retCode = AieClientRelease(clientInfo_, algorithmInfo_, inputInfo);
        if (retCode != RETCODE_SUCCESS) {
            HILOGE("[KWSSdkImpl]AieClientRelease failed. Error code[%d]", retCode);
            return KWS_RETCODE_FAILURE;
        }
        retCode = AieClientDestroy(clientInfo_);
        if (retCode != RETCODE_SUCCESS) {
            HILOGE("[KWSSdkImpl]AieClientDestroy failed. Error code[%d]", retCode);
            return KWS_RETCODE_FAILURE;
        }
        mfccProcessor_ = nullptr;
        pcmIterator_ = nullptr;
        callback_ = nullptr;
        kwsHandle_ = INVALID_KWS_HANDLE;
        return KWS_RETCODE_SUCCESS;
    }
    ```

4.  Develop a sample application.

    Call the  **Create**  API.

    ```
    bool KwsManager::PreparedInference()
    {
        if (capturer_ == nullptr) {
            printf("[KwsManager] only load plugin after AudioCapturer ready\n");
            return false;
        }
        if (plugin_ != nullptr) {
            printf("[KwsManager] stop created InferencePlugin at first\n");
            StopInference();
        }
        plugin_ = std::make_shared<KWSSdk>();
        if (plugin_ == nullptr) {
            printf("[KwsManager] fail to create inferencePlugin\n");
            return false;
        }
        if (plugin_->Create() != SUCCESS) {
            printf("[KwsManager] KWSSdk fail to create.\n");
            return false;
        }
        std::shared_ptr<KWSCallback> callback = std::make_shared<MyKwsCallback>();
        if (callback == nullptr) {
            printf("[KwsManager] new Callback failed.\n");
            return false;
        }
        plugin_->SetCallback(callback);
        return true;
    }
    ```

    Call the  **SyncExecute**  API.

    ```
    void KwsManager::ConsumeSamples()
    {
        uintptr_t sampleAddr = 0;
        size_t sampleSize = 0;
        int32_t retCode = SUCCESS;
        while (status_ == RUNNING) {
            {
                std::lock_guard<std::mutex> lock(mutex_);
                if (cache_ == nullptr) {
                    printf("[KwsManager] cache_ is nullptr.\n");
                    break;
                }
                sampleSize = cache_->GetCapturedBuffer(sampleAddr);
            }
            if (sampleSize == 0 || sampleAddr == 0) {
                continue;
            }
            Array<int16_t> input = {
                .data = (int16_t *)(sampleAddr),
                .size = sampleSize >> 1
            };
            {
                std::lock_guard<std::mutex> lock(mutex_);
                if (plugin_ == nullptr) {
                    printf("[KwsManager] cache_ is nullptr.\n");
                    break;
                }
                if ((retCode = plugin_->SyncExecute(input)) != SUCCESS) {
                    printf("[KwsManager] SyncExecute KWS failed with retCode = [%d]\n", retCode);
                    continue;
                }
            }
        }
    }
    ```

    Call the  **Destroy**  API.

    ```
    void KwsManager::StopInference()
    {
        printf("[KwsManager] StopInference\n");
        if (plugin_ != nullptr) {
            int ret = plugin_->Destroy();
            if (ret != SUCCESS) {
                printf("[KwsManager] plugin_ destroy failed.\n");
            }
            plugin_ = nullptr;
        }
    }
    ```


## Repositories Involved

[AI subsystem](https://gitee.com/openharmony/docs/blob/master/en/readme/ai.md)

[ai_engine](https://gitee.com/openharmony/ai_engine)

## Dependency Repositories

[build\_lite](https://gitee.com/openharmony/build_lite/blob/master/README.md)

[systemabilitymgr\_samgr\_lite](https://gitee.com/openharmony/systemabilitymgr_samgr_lite/blob/master/README.md)

[startup\_init\_lite](https://gitee.com/openharmony/startup_init_lite/blob/master/README.md)

## Reference

[AI Framework Development Guide](https://gitee.com/openharmony/docs/blob/master/en/device-dev/subsystems/subsys-ai-aiframework-devguide.md)


