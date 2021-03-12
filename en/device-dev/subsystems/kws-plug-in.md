# KWS Plug-in<a name="EN-US_TOPIC_0000001090714913"></a>

1.  Add the API of the KWS plug-in to the  **//foundation/ai/engine/services/server/plugin**  directory. This API is used to call AI capabilities. The following code snippet is an example API implementation of the KWS plug-in. The reference code is available at the  **//foundation/ai/engine/services/server/plugin/asr/keyword\_spotting**  directory.

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

    The preceding code implements the  **IPlugin**  API provided by the server.  [Table 1](#table567211582104)  shows the mapping between the client APIs and the plug-in APIs.

    **Table  1**  Mapping between the client APIs and the plug-in APIs

    <a name="table567211582104"></a>
    <table><thead align="left"><tr id="row867275851017"><th class="cellrowborder" valign="top" width="21.3021302130213%" id="mcps1.2.4.1.1"><p id="p1167245817103"><a name="p1167245817103"></a><a name="p1167245817103"></a>Client API</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.44194419441944%" id="mcps1.2.4.1.2"><p id="p767216585109"><a name="p767216585109"></a><a name="p767216585109"></a>Plug-in API</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.25592559255926%" id="mcps1.2.4.1.3"><p id="p9672358191015"><a name="p9672358191015"></a><a name="p9672358191015"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row7672175861020"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p12672758161010"><a name="p12672758161010"></a><a name="p12672758161010"></a>AieClientPrepare</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p567265814109"><a name="p567265814109"></a><a name="p567265814109"></a>Prepare</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p5672105816102"><a name="p5672105816102"></a><a name="p5672105816102"></a>Initializes the inference algorithm plug-in. For KWS, this API loads the KWS model from the fixed location (<strong id="b138031131115020"><a name="b138031131115020"></a><a name="b138031131115020"></a>/sdcard/wenwen_inst.wk</strong>) to the memory.</p>
    </td>
    </tr>
    <tr id="row8672115841015"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p1167255891016"><a name="p1167255891016"></a><a name="p1167255891016"></a>AieClientSyncProcess</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p8672958101011"><a name="p8672958101011"></a><a name="p8672958101011"></a>SyncProcess</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p767275811010"><a name="p767275811010"></a><a name="p767275811010"></a>Executes the inference algorithm synchronously. For KWS, this API synchronously executes the audio inference algorithm to determine whether the specified wakeup keyword exists in the audio.</p>
    </td>
    </tr>
    <tr id="row9672058151013"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p116733583101"><a name="p116733583101"></a><a name="p116733583101"></a>AieClientAsyncProcess</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p46731658121014"><a name="p46731658121014"></a><a name="p46731658121014"></a>AsyncProcess</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p56731758151018"><a name="p56731758151018"></a><a name="p56731758151018"></a>Executes the inference algorithm asynchronously. Currently, this API is not used in KWS. However, you can implement the API based on your use case.</p>
    </td>
    </tr>
    <tr id="row14673135851010"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p56733585103"><a name="p56733585103"></a><a name="p56733585103"></a>AieClientSetOption</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p4673358171013"><a name="p4673358171013"></a><a name="p4673358171013"></a>SetOption</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p76731158121018"><a name="p76731158121018"></a><a name="p76731158121018"></a>Sets algorithm-related configuration items, such as the confidence threshold and delay. Currently, this API is not used in KWS. However, you can implement the API based on your use case.</p>
    </td>
    </tr>
    <tr id="row16673125812100"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p166735581101"><a name="p166735581101"></a><a name="p166735581101"></a>AieClientGetOption</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p3673105811106"><a name="p3673105811106"></a><a name="p3673105811106"></a>GetOption</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p106732581109"><a name="p106732581109"></a><a name="p106732581109"></a>Obtains algorithm-related configuration items. For KWS, this API can obtain the input and output scale of the KWS model. The input scale is the MFCC feature (fixed value: 4000) required by the KWS model, and the output scale is the confidence (fixed value: 2) of the result.</p>
    </td>
    </tr>
    <tr id="row667335817101"><td class="cellrowborder" valign="top" width="21.3021302130213%" headers="mcps1.2.4.1.1 "><p id="p96730585105"><a name="p96730585105"></a><a name="p96730585105"></a>AieClientRelease</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.44194419441944%" headers="mcps1.2.4.1.2 "><p id="p76732586102"><a name="p76732586102"></a><a name="p76732586102"></a>Release</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.25592559255926%" headers="mcps1.2.4.1.3 "><p id="p467318586105"><a name="p467318586105"></a><a name="p467318586105"></a>Releases the algorithm model. For KWS, this API releases the specified algorithm model and clears the dynamic memory in the feature processor.</p>
    </td>
    </tr>
    </tbody>
    </table>

    Note:

    1. The  **AieClientInit**  and  **AieClientDestroy**  APIs are used to connect to and disconnect from the server, respectively. They are not called in the plug-in algorithm and therefore do not need to be defined in the plug-in.

    2. The KWS plug-in needs to use the  **PLUGIN\_INTERFACE\_IMPL**  statement to expose the function pointer. Otherwise, the plug-in cannot be properly loaded.

    ```
    PLUGIN_INTERFACE_IMPL(KWSPlugin);
    ```


