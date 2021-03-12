# 唤醒词识别插件的开发示例<a name="ZH-CN_TOPIC_0000001090714913"></a>

1.  在//foundation/ai/engine/services/server/plugin的目录中添加唤醒词识别插件的接口定义，并实现AI能力的调用。如下代码片段即实现唤醒词识别的算法插件的接口定义。更多插件开发的相关代码参考路径如下：//foundation/ai/engine/services/server/plugin/asr/keyword\_spotting

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

    上述代码实现server提供的IPlugin接口。唤醒词识别的sample中调用的client端接口与插件中的接口对应关系及其实现功能如表[1](#table567211582104)所示。

    **表 1**  唤醒词识别中client端接口与插件接口对应关系

    <a name="table567211582104"></a>
    <table><thead align="left"><tr id="row867275851017"><th class="cellrowborder" valign="top" width="21.3021302130213%" id="mcps1.2.4.1.1"><p id="p1167245817103"><a name="p1167245817103"></a><a name="p1167245817103"></a>client端定义的接口</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.44194419441944%" id="mcps1.2.4.1.2"><p id="p767216585109"><a name="p767216585109"></a><a name="p767216585109"></a>插件中定义的接口</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.25592559255926%" id="mcps1.2.4.1.3"><p id="p9672358191015"><a name="p9672358191015"></a><a name="p9672358191015"></a>功能</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7672175861020"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p12672758161010"><a name="p12672758161010"></a><a name="p12672758161010"></a>AieClientPrepare</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p567265814109"><a name="p567265814109"></a><a name="p567265814109"></a>Prepare</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p5672105816102"><a name="p5672105816102"></a><a name="p5672105816102"></a>提供推理算法插件初始化功能，以唤醒词识别为例：加载唤醒词识别模型，将固定位置（/sdcard/wenwen_inst.wk）模型加载至内存。</p>
    </td>
    </tr>
    <tr id="row8672115841015"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p1167255891016"><a name="p1167255891016"></a><a name="p1167255891016"></a>AieClientSyncProcess</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p8672958101011"><a name="p8672958101011"></a><a name="p8672958101011"></a>SyncProcess</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p767275811010"><a name="p767275811010"></a><a name="p767275811010"></a>提供同步执行推理算法的能力，以唤醒词识别为例：实现同步执行音频推理算法，判断音频中是否存在唤醒词。</p>
    </td>
    </tr>
    <tr id="row9672058151013"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p116733583101"><a name="p116733583101"></a><a name="p116733583101"></a>AieClientAsyncProcess</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p46731658121014"><a name="p46731658121014"></a><a name="p46731658121014"></a>AsyncProcess</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p56731758151018"><a name="p56731758151018"></a><a name="p56731758151018"></a>提供异步执行推理算法的能力，当前唤醒词识别场景不涉及，但开发者可根据具体场景自行实现。</p>
    </td>
    </tr>
    <tr id="row14673135851010"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p56733585103"><a name="p56733585103"></a><a name="p56733585103"></a>AieClientSetOption</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p4673358171013"><a name="p4673358171013"></a><a name="p4673358171013"></a>SetOption</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p76731158121018"><a name="p76731158121018"></a><a name="p76731158121018"></a>提供手动设置算法相关配置项，如置信度阈值、时延等超参数的能力，当前唤醒词识别场景未涉及。开发者可视具体场景自行实现。</p>
    </td>
    </tr>
    <tr id="row16673125812100"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p166735581101"><a name="p166735581101"></a><a name="p166735581101"></a>AieClientGetOption</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p3673105811106"><a name="p3673105811106"></a><a name="p3673105811106"></a>GetOption</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p106732581109"><a name="p106732581109"></a><a name="p106732581109"></a>提供获取算法相关配置项，以唤醒词识别为例：获取唤醒词模型中输入输出的规模，输入规模即为唤醒词识别模型要求输入的MFCC特征的维度（固定值：4000），输出规模即为结果的置信度得分维度（固定值：2）。</p>
    </td>
    </tr>
    <tr id="row667335817101"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p96730585105"><a name="p96730585105"></a><a name="p96730585105"></a>AieClientRelease</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p76732586102"><a name="p76732586102"></a><a name="p76732586102"></a>Release</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p467318586105"><a name="p467318586105"></a><a name="p467318586105"></a>提供卸载算法模型功能，以唤醒词识别为例：实现卸载相关模型，并将特征处理器中的动态内存清理。</p>
    </td>
    </tr>
    </tbody>
    </table>

    注意：

    1.接口AieClientInit、AieClientDestroy分别用于与server端建立和断开连接，未调用到插件算法中，因此插件中无需定义与之对应的接口。

    2.唤醒词识别插件需要使用PLUGIN\_INTERFACE\_IMPL语句对外暴露函数指针，否则插件将无法被正常加载使用。

    ```
    PLUGIN_INTERFACE_IMPL(KWSPlugin);
    ```


