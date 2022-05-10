# 唤醒词识别SDK的开发示例


1. 在//foundation/ai/engine /interfaces/kits目录中添加唤醒词识别SDK的API接口定义，该接口可用三方应用进行调用。如下代码片段即为唤醒词识别定义的API接口示例，其相关代码参考路径为：//foundation/ai/engine/interfaces/kits/asr/keyword_spotting。
     
   ```
   class KWSSdk {
   public:
       KWSSdk();
       virtual ~KWSSdk();
   
       // 定义创建唤醒词检测工具包的方法。
       int32_t Create();
   
       // 定义同步执行唤醒词检测任务的方法。
       int32_t SyncExecute(const Array<int16_t> &audioInput);
   
       // 定义设置唤醒词检测回调器的方法。
       int32_t SetCallback(const std::shared_ptr<KWSCallback> &callback);
   
       // 定义销毁唤醒词工具包的方法，释放与插件的会话信息。
       int32_t Destroy();
   };
   ```

2. 在//foundation/ai/engine/services/client/algorithm_sdk目录中增加SDK中API接口的具体实现，调用client端提供的接口，实现算法插件能力的使用。如下代码片段即为唤醒词识别的API接口中create方法的具体实现示例，更多详细代码可参考：//foundation/ai/engine/services/client/algorithm_sdk/asr/keyword_spotting。
     
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
       // 调用client端提供的接口AieClientInit，实现初始化引擎服务，激活跨进程调用
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
       // 调用client端提供的接口AieClientPrepare，实现加载算法插件
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

   上述代码为API接口的具体实现，从上述示例的代码中，SDK中create接口的具体实现即为上述示例代码中create方法，该方法调用了AI引擎框架client端开放接口AieClientInit，AieClientPrepare，从而实现与server端建立连接及加载算法模型的能力。

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
   > SDK调用AI引擎client端接口应遵循AieClientInit-&gt;AieClientPrepare-&gt;AieClientSyncProcess/AieClientAsyncProcess-&gt;AieClientRelease-&gt;AieClientDestroy顺序，否则调用接口会返回错误码。
