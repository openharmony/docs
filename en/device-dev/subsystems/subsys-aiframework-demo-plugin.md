# KWS Plug-in<a name="EN-US_TOPIC_0000001090714913"></a>

1.  Add the API of the KWS plug-in to the **//foundation/ai/engine/services/server/plugin** directory. This API is used to call AI capabilities. The following code snippet is an example API implementation of the KWS plug-in. The reference code is available at the **//foundation/ai/engine/services/server/plugin/asr/keyword\_spotting** directory.

    ```
    #include "plugin/i_plugin.h
    class KWSPlugin : public IPlugin {
    public:
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
    };
    ```

    The preceding code implements the **IPlugin** API provided by the server. The following table shows the mapping between the client APIs and the plug-in APIs.

   **Table 1** Mapping between the client APIs and the plug-in APIs

| Client API | Plug-in API | Description |
| ---------- | ----------- | ----------- |
| AieClientPrepare | Prepare | Initializes the inference algorithm plug-in. For KWS, this API loads the KWS model from the fixed location (/sdcard/wenwen_inst.wk) to the memory. |
| AieClientSyncProcess | SyncProcess | Executes the inference algorithm synchronously. For KWS, this API synchronously executes the audio inference algorithm to determine whether the specified wakeup keyword exists in the audio. |
| AieClientAsyncProcess | AsyncProcess | Executes the inference algorithm asynchronously. Currently, this API is not used in KWS. However, you can implement the API based on your use case. |
| AieClientSetOption | SetOption | Sets algorithm-related configuration items, such as the confidence threshold and delay. Currently, this API is not used in KWS. However, you can implement the API based on your use case. |
| AieClientGetOption | GetOption | Obtains algorithm-related configuration items. For KWS, this API can obtain the input and output scale of the KWS model. The input scale is the MFCC feature (fixed value: 4000) required by the KWS model, and the output scale is the confidence (fixed value: 2) of the result. |
| AieClientRelease | Release | Releases the algorithm model. For KWS, this API releases the specified algorithm model and clears the dynamic memory in the feature processor. |

>![](../public_sys-resources/icon-note.gif)**NOTE** 
>-  The **AieClientInit** and **AieClientDestroy** APIs are used to connect to and disconnect from the server, respectively. They are not called in the plug-in algorithm and therefore do not need to be defined in the plug-in.
>-  The KWS plug-in needs to use the **PLUGIN\_INTERFACE\_IMPL** statement to expose the function pointer. Otherwise, the plug-in cannot be properly loaded.
    
  
    ```
    PLUGIN_INTERFACE_IMPL(KWSPlugin);
    ```