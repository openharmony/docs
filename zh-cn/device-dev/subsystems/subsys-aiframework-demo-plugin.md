# 唤醒词识别插件的开发示例


在代码路径//foundation/ai/engine/services/server/plugin中添加唤醒词识别插件的接口定义（IPlugin），并实现AI能力的调用。如下代码片段即实现唤醒词识别的算法插件的接口定义。更多插件开发的相关代码参考路径如下：//foundation/ai/engine/services/server/plugin/asr/keyword_spotting
     
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

     上述代码实现server提供的IPlugin接口。唤醒词识别的sample中调用的client端接口与插件中的接口对应关系及其实现功能如下表所示。
     **表1** 唤醒词识别中client端接口与插件中的接口对应关系
   
   | client端定义的接口 | 插件中定义的接口 | 功能 | 
   | -------- | -------- | -------- |
   | AieClientPrepare | Prepare | 提供推理算法插件初始化功能，例如：加载唤醒词识别模型，将固定位置（/sdcard/wenwen_inst.wk）模型加载至内存。 | 
   | AieClientSyncProcess | SyncProcess | 提供同步执行推理算法的能力，例如：实现同步执行音频推理算法，判断音频中是否存在唤醒词。 | 
   | AieClientAsyncProcess | AsyncProcess | 提供异步执行推理算法的能力，当前唤醒词识别场景不涉及，但开发者可根据具体场景自行实现。 | 
   | AieClientSetOption | SetOption | 提供手动设置算法相关配置项，如置信度阈值、时延等超参数的能力。当前唤醒词识别场景未涉及，开发者可视具体场景自行实现。 | 
   | AieClientGetOption | GetOption | 提供获取算法相关配置项，以唤醒词识别为例：获取唤醒词模型中输入输出的规模，输入规模即为唤醒词识别模型要求输入的MFCC特征的维度（固定值：4000），输出规模即为结果的置信度得分维度（固定值：2）。 | 
   | AieClientRelease | Release | 提供卸载算法模型功能，以唤醒词识别为例：实现卸载相关模型，并清理特征处理器中的动态内存。 | 

   注意：

   1.接口AieClientInit、AieClientDestroy分别用于与server端建立和断开连接，未调用到插件算法中，因此插件中无需定义与之对应的接口。

   2.唤醒词识别插件需要使用PLUGIN_INTERFACE_IMPL语句对外暴露函数指针，否则插件将无法被正常加载使用。

     
   ```
   PLUGIN_INTERFACE_IMPL(KWSPlugin);
   ```
