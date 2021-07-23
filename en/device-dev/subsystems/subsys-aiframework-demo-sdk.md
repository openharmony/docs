# KWS SDK<a name="EN-US_TOPIC_0000001090776709"></a>

1.  Add the API of the KWS SDK to the  **//foundation/ai/engine /interfaces/kits**  directory. This API can be called by third-party applications. The following code snippet is an example API for the KWS SDK. The reference code is available at the  **//foundation/ai/engine /interfaces/kits/asr/keyword\_spotting**  directory.

    ```
    class KWSSdk {
    public:
        KWSSdk();
        virtual ~KWSSdk();
    
        // Create a KWS SDK instance.
        int32_t Create();
    
        // Synchronously execute the KWS task.
        int32_t SyncExecute(const Array<int16_t> &audioInput);
    
        // Set the KWS callback.
        int32_t SetCallback(const std::shared_ptr<KWSCallback> &callback);
    
        // Destroy the KWS SDK instance to release the session engaged with the plug-in.
        int32_t Destroy();
    };
    ```

2.  Add the API implementation of the SDK to the  **//foundation/ai/engine/services/client/algorithm\_sdk**  directory and call the APIs provided by the client to use the algorithm plug-in capabilities. The following code snippet is an example implementation of the  **create**  method in the API of the KWS SDK. For more details, see the reference code at  **//foundation/ai/engine/services/client/algorithm\_sdk/asr/keyword\_spotting**.

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
        // Call the AieClientInit API provided by the client to initialize the engine service and activate IPC call.
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
        // Call the AieClientPrepare API provided by the client to load the algorithm plug-in.
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
    ```

    The preceding code is the specific API implementation. The  **create**  function in the API of the KWS SDK calls the open  **AieClientInit**  and  **AieClientPrepare**  APIs provided by the client to connect to the server and load the algorithm model. For details, see the implementation of the  **create**  method in following sections.

    >![](../public_sys-resources/icon-note.gif) **NOTE:** 
    >The sequence for the SDK to call client APIs:  **AieClientInit**  -\>  **AieClientPrepare**  -\>  **AieClientSyncProcess**  or  **AieClientAsyncProcess**  -\>  **AieClientRelease**  -\>  **AieClientDestroy**. An exception will be thrown if the call sequence is violated. 


