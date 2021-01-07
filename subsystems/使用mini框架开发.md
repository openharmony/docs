# 使用mini框架开发<a name="ZH-CN_TOPIC_0000001063393902"></a>

-   [接口说明](#section183731439142417)
-   [使用mini框架实例](#section153112047155419)

mini框架是一套简单小巧的DFX设计，对外提供日志记录功能。

## 接口说明<a name="section183731439142417"></a>

```
HILOG_DEBUG(mod, fmt, ...)
HILOG_INFO(mod, fmt, ...)
HILOG_WARN(mod, fmt, ...)
HILOG_ERROR(mod, fmt, ...)
HILOG_FATAL(mod, fmt, ...)
```

接口参数说明：

<a name="table998125624816"></a>
<table><thead align="left"><tr id="row10981135611481"><th class="cellrowborder" valign="top" width="11.57%" id="mcps1.1.5.1.1"><p id="p11981145674811"><a name="p11981145674811"></a><a name="p11981145674811"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="11.83%" id="mcps1.1.5.1.2"><p id="p39821456124810"><a name="p39821456124810"></a><a name="p39821456124810"></a>是否必填</p>
</th>
<th class="cellrowborder" valign="top" width="15.21%" id="mcps1.1.5.1.3"><p id="p139822056104811"><a name="p139822056104811"></a><a name="p139822056104811"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="61.39%" id="mcps1.1.5.1.4"><p id="p3982145618482"><a name="p3982145618482"></a><a name="p3982145618482"></a>参数说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row209821456144818"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.1.5.1.1 "><p id="p20982125616483"><a name="p20982125616483"></a><a name="p20982125616483"></a>mod</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.1.5.1.2 "><p id="p1298245634810"><a name="p1298245634810"></a><a name="p1298245634810"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p1198295634817"><a name="p1198295634817"></a><a name="p1198295634817"></a>uint8</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p id="p0982145634817"><a name="p0982145634817"></a><a name="p0982145634817"></a>模块/服务的ID。</p>
<p id="p1982155664820"><a name="p1982155664820"></a><a name="p1982155664820"></a>统一规划分配，最大支持64个，其中第三方APP统一使用HILOG_MODULE_APP作为模块ID。</p>
</td>
</tr>
<tr id="row1898225611489"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.1.5.1.1 "><p id="p9982656164812"><a name="p9982656164812"></a><a name="p9982656164812"></a>fmt</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.1.5.1.2 "><p id="p998255616484"><a name="p998255616484"></a><a name="p998255616484"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p18982256194818"><a name="p18982256194818"></a><a name="p18982256194818"></a>char *</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p id="p2982165664818"><a name="p2982165664818"></a><a name="p2982165664818"></a>格式化输出字符串。</p>
<a name="ol19982256164816"></a><a name="ol19982256164816"></a><ol id="ol19982256164816"><li>最大支持6个可变参数，不支持%s。</li><li>格式化后的单条日志最大长度128字节，超过将无法打印。</li></ol>
</td>
</tr>
<tr id="row16982105613488"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.1.5.1.1 "><p id="p1898225604813"><a name="p1898225604813"></a><a name="p1898225604813"></a>可变参</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.1.5.1.2 "><p id="p1698217568486"><a name="p1698217568486"></a><a name="p1698217568486"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p189834566489"><a name="p189834566489"></a><a name="p189834566489"></a>int32</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p id="p9983175654814"><a name="p9983175654814"></a><a name="p9983175654814"></a>仅支持数字类型，最大支持6个变参。</p>
</td>
</tr>
</tbody>
</table>

1.  添加模块ID

    在interfaces/kits/hilog\_lite/hiview\_log.h的HiLogModuleType中添加HILOG\_MODULE\_A定义。

    ```
    typedef enum {
        /** DFX */    
        HILOG_MODULE_HIVIEW = 0,    
        /** System Module A */    
        HILOG_MODULE_A,    
        /** Maximum number of modules */
        HILOG_MODULE_MAX
    } HiLogModuleType;
    ```

2.  注册模块

    在模块的初始化流程中添加如下代码，注册模块到日志框架中：

    ```
    HiLogRegisterModule(HILOG_MODULE_A, "A");
    ```

3.  调整DFX框架静态配置

    根据需要调整如下文件的g\_hiviewConfig全局参数配置。默认情况下不用修改，日志默认输出到串口。

    ```
    utils/lite/hiview_config.c
    ```

    <a name="table15664428164516"></a>
    <table><thead align="left"><tr id="row07061028154510"><th class="cellrowborder" valign="top" width="25.180000000000003%" id="mcps1.1.3.1.1"><p id="p10706128184514"><a name="p10706128184514"></a><a name="p10706128184514"></a>配置项</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.82%" id="mcps1.1.3.1.2"><p id="p11706928194520"><a name="p11706928194520"></a><a name="p11706928194520"></a>取值及含义</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8706828154511"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p19706112824514"><a name="p19706112824514"></a><a name="p19706112824514"></a>outputOption</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p9706528104512"><a name="p9706528104512"></a><a name="p9706528104512"></a>日志的输出方式。取值如下：</p>
    <a name="ul113982579190"></a><a name="ul113982579190"></a><ul id="ul113982579190"><li>OUTPUT_OPTION_DEBUG日志不进行跨任务调度直接输出到串口，仅适合临时调测使用。</li><li>OUTPUT_OPTION_FLOW日志流式输出到串口（默认设置）。</li><li>OUTPUT_OPTION_TEXT_FILE 日志输出为文本文件。</li></ul>
    </td>
    </tr>
    <tr id="row1270720281453"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p137071528164516"><a name="p137071528164516"></a><a name="p137071528164516"></a>level</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p177071428154510"><a name="p177071428154510"></a><a name="p177071428154510"></a>日志的输出级别，仅输出大于等于该级别的日志。取值如下：</p>
    <a name="ul1021772614515"></a><a name="ul1021772614515"></a><ul id="ul1021772614515"><li>HILOG_LV_DEBUG（默认设置）</li><li>HILOG_LV_INFO</li><li>HILOG_LV_WARN</li><li>HILOG_LV_ERROR</li><li>HILOG_LV_FATAL</li></ul>
    </td>
    </tr>
    <tr id="row17707142814513"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p11707192814517"><a name="p11707192814517"></a><a name="p11707192814517"></a>logSwitch</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p870711281452"><a name="p870711281452"></a><a name="p870711281452"></a>流水日志功能开关。编译前关闭不影响log组件初始化，默认打开。取值如下：</p>
    <a name="ul1698616567457"></a><a name="ul1698616567457"></a><ul id="ul1698616567457"><li>HIVIEW_FEATURE_ON</li><li>HIVIEW_FEATURE_OFF</li></ul>
    </td>
    </tr>
    <tr id="row6708132813453"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p1570813280453"><a name="p1570813280453"></a><a name="p1570813280453"></a>dumpSwitch</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p970852810459"><a name="p970852810459"></a><a name="p970852810459"></a>dump功能开关。编译前关闭则不再初始化DUMP组件，默认关闭。取值如下：</p>
    <a name="ul122703764613"></a><a name="ul122703764613"></a><ul id="ul122703764613"><li>HIVIEW_FEATURE_ON</li><li>HIVIEW_FEATURE_OFF</li></ul>
    </td>
    </tr>
    <tr id="row87081282452"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p11708128124511"><a name="p11708128124511"></a><a name="p11708128124511"></a>eventSwitch</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p17708202834519"><a name="p17708202834519"></a><a name="p17708202834519"></a>事件功能开关。编译前关闭则不再初始化Event组件，默认关闭。取值如下：</p>
    <a name="ul845720186469"></a><a name="ul845720186469"></a><ul id="ul845720186469"><li>HIVIEW_FEATURE_ON</li><li>HIVIEW_FEATURE_OFF</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

4.  在模块的Build.gn文件中添加头文件依赖

    ```
     include_dirs = [
          "//base/hiviewdfx/interfaces/kits/hilog_lite",
     ]
    ```

5.  日志打印

    在需要打印日志的.c文件中增加头文件依赖\#include "log.h"，并调用如下接口：

    ```
    HILOG_DEBUG(HILOG_MODULE_A, "log test: %d", 88);
    ```


## 使用mini框架实例<a name="section153112047155419"></a>

以下引用samgr\_lite模块使用mini框架作为实例。

1.  添加模块ID，在base/hiviewdfx/interfaces/kits/hilog\_lite/hiview\_log.h的类型定义结构体中添加HILOG\_MODULE\_SAMGR定义。

    ```
    typedef enum {
        ...
        HILOG_MODULE_SAMGR,
        ...
    } HiLogModuleType;
    ```

2.  注册模块，在base/hiviewdfx/frameworks/hilog\_lite/mini/hiview\_log.c的HiLogInit函数中添加注册代码。

    ```
    HiLogRegisterModule(HILOG_MODULE_SAMGR, "SAMGR");
    ```

3.  在GN文件中添加头文件依赖，文件路径为：foundation/distributedschedule/services/samgr\_lite/samgr/source/BUILD.gn

    ```
     include_dirs = [
          "//base/hiviewdfx/interfaces/kits/hilog_lite",
     ]
    ```

4.  源文件foundation/distributedschedule/services/samgr\_lite/samgr/source/message.c中引用头文件并调用接口。

    ```
    #include <log.h>
    uint32 *SAMGR_SendSharedRequest(const Identity *identity, const Request *request, uint32 *token, Handler handler)
    {
        ...
        if (err != EC_SUCCESS) {
            HILOG_ERROR(HILOG_MODULE_SAMGR, "SharedSend [%p] failed(%d)!", identity->queueId, err);
            (void)FreeReference(&exchange);
        }
        ...
    }
    ```


