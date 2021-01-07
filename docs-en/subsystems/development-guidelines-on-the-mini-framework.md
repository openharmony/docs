# Development Guidelines on the mini Framework<a name="EN-US_TOPIC_0000001063393902"></a>

-   [Available APIs](#section183731439142417)
-   [Use Case](#section153112047155419)

The mini framework adopts a simple and compact DFX design that provides the logging function.

## Available APIs<a name="section183731439142417"></a>

```
HILOG_DEBUG(mod, fmt, ...)
HILOG_INFO(mod, fmt, ...)
HILOG_WARN(mod, fmt, ...)
HILOG_ERROR(mod, fmt, ...)
HILOG_FATAL(mod, fmt, ...)
```

The following table lists parameters of the preceding APIs.

<a name="table998125624816"></a>
<table><thead align="left"><tr id="row10981135611481"><th class="cellrowborder" valign="top" width="11.57%" id="mcps1.1.5.1.1"><p id="p11981145674811"><a name="p11981145674811"></a><a name="p11981145674811"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="11.83%" id="mcps1.1.5.1.2"><p id="p39821456124810"><a name="p39821456124810"></a><a name="p39821456124810"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="15.21%" id="mcps1.1.5.1.3"><p id="p139822056104811"><a name="p139822056104811"></a><a name="p139822056104811"></a>Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="61.39%" id="mcps1.1.5.1.4"><p id="p3982145618482"><a name="p3982145618482"></a><a name="p3982145618482"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row209821456144818"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.1.5.1.1 "><p id="p20982125616483"><a name="p20982125616483"></a><a name="p20982125616483"></a>mod</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.1.5.1.2 "><p id="p1298245634810"><a name="p1298245634810"></a><a name="p1298245634810"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p1198295634817"><a name="p1198295634817"></a><a name="p1198295634817"></a>uint8</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p id="p0982145634817"><a name="p0982145634817"></a><a name="p0982145634817"></a>Module or service ID.</p>
<p id="p1982155664820"><a name="p1982155664820"></a><a name="p1982155664820"></a>IDs are planned and assigned in a unified manner. A maximum of 64 IDs are supported. Third-party applications use <strong id="b1367151118101"><a name="b1367151118101"></a><a name="b1367151118101"></a>HILOG_MODULE_APP</strong> as their module ID.</p>
</td>
</tr>
<tr id="row1898225611489"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.1.5.1.1 "><p id="p9982656164812"><a name="p9982656164812"></a><a name="p9982656164812"></a>fmt</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.1.5.1.2 "><p id="p998255616484"><a name="p998255616484"></a><a name="p998255616484"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p18982256194818"><a name="p18982256194818"></a><a name="p18982256194818"></a>char *</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p id="p2982165664818"><a name="p2982165664818"></a><a name="p2982165664818"></a>Format specifier for output.</p>
<a name="ol19982256164816"></a><a name="ol19982256164816"></a><ol id="ol19982256164816"><li>A maximum of six variable parameters are supported. <strong id="b1465118167236"><a name="b1465118167236"></a><a name="b1465118167236"></a>%s</strong> is not supported.</li><li>The maximum length of a formatted log record is 128 bytes. If the maximum length is exceeded, the log cannot be printed.</li></ol>
</td>
</tr>
<tr id="row16982105613488"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.1.5.1.1 "><p id="p1898225604813"><a name="p1898225604813"></a><a name="p1898225604813"></a>Variable parameters</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.1.5.1.2 "><p id="p1698217568486"><a name="p1698217568486"></a><a name="p1698217568486"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p189834566489"><a name="p189834566489"></a><a name="p189834566489"></a>int32</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p id="p9983175654814"><a name="p9983175654814"></a><a name="p9983175654814"></a>Only numeric types are supported. A maximum of six variable parameters are allowed.</p>
</td>
</tr>
</tbody>
</table>

1.  Add the module ID.

    Define  **HILOG\_MODULE\_A**  in  **HiLogModuleType**  of  **interfaces/kits/hilog\_lite/hiview\_log.h**.

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

2.  Register the module.

    Add the following code during the module initialization to register the module with the logging framework:

    ```
    HiLogRegisterModule(HILOG_MODULE_A, "A");
    ```

3.  Modify the static configuration of the DFX framework.

    Modify  **g\_hiviewConfig**  in the following file as required. By default, modification is not required and logs are output to the serial port.

    ```
    utils/lite/hiview_config.c
    ```

    <a name="table15664428164516"></a>
    <table><thead align="left"><tr id="row07061028154510"><th class="cellrowborder" valign="top" width="25.180000000000003%" id="mcps1.1.3.1.1"><p id="p10706128184514"><a name="p10706128184514"></a><a name="p10706128184514"></a>Configuration Item</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.82%" id="mcps1.1.3.1.2"><p id="p11706928194520"><a name="p11706928194520"></a><a name="p11706928194520"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8706828154511"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p19706112824514"><a name="p19706112824514"></a><a name="p19706112824514"></a>outputOption</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p9706528104512"><a name="p9706528104512"></a><a name="p9706528104512"></a>Log output mode. The value can be:</p>
    <a name="ul113982579190"></a><a name="ul113982579190"></a><ul id="ul113982579190"><li><strong id="b158115185206"><a name="b158115185206"></a><a name="b158115185206"></a>OUTPUT_OPTION_DEBUG</strong>: Logs are directly output to the serial port without cross-task scheduling. This value is used only for temporary debugging.</li><li><strong id="b961064410200"><a name="b961064410200"></a><a name="b961064410200"></a>OUTPUT_OPTION_FLOW</strong> (default value): Logs are output as data flow to the serial port.</li><li><strong id="b43331155112013"><a name="b43331155112013"></a><a name="b43331155112013"></a>OUTPUT_OPTION_TEXT_FILE</strong>: Logs are output as text files.</li></ul>
    </td>
    </tr>
    <tr id="row1270720281453"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p137071528164516"><a name="p137071528164516"></a><a name="p137071528164516"></a>level</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p177071428154510"><a name="p177071428154510"></a><a name="p177071428154510"></a>Log level for output. Only the logs whose levels are higher than or equal to the level specified by this parameter can be output. The value can be:</p>
    <a name="ul1021772614515"></a><a name="ul1021772614515"></a><ul id="ul1021772614515"><li>HILOG_LV_DEBUG (default value)</li><li>HILOG_LV_INFO</li><li>HILOG_LV_WARN</li><li>HILOG_LV_ERROR</li><li>HILOG_LV_FATAL</li></ul>
    </td>
    </tr>
    <tr id="row17707142814513"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p11707192814517"><a name="p11707192814517"></a><a name="p11707192814517"></a>logSwitch</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p870711281452"><a name="p870711281452"></a><a name="p870711281452"></a>Logging switch. This switch is turned on by default. The <strong id="b164378447225"><a name="b164378447225"></a><a name="b164378447225"></a>log</strong> component can be successfully initialized even if this switch is turned off before compilation. The value can be:</p>
    <a name="ul1698616567457"></a><a name="ul1698616567457"></a><ul id="ul1698616567457"><li>HIVIEW_FEATURE_ON</li><li>HIVIEW_FEATURE_OFF</li></ul>
    </td>
    </tr>
    <tr id="row6708132813453"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p1570813280453"><a name="p1570813280453"></a><a name="p1570813280453"></a>dumpSwitch</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p970852810459"><a name="p970852810459"></a><a name="p970852810459"></a>Dumping switch. This switch is turned off by default. If the default setting is retained before compilation, the <strong id="b19591628162312"><a name="b19591628162312"></a><a name="b19591628162312"></a>DUMP</strong> component will not be initialized. The value can be:</p>
    <a name="ul122703764613"></a><a name="ul122703764613"></a><ul id="ul122703764613"><li>HIVIEW_FEATURE_ON</li><li>HIVIEW_FEATURE_OFF</li></ul>
    </td>
    </tr>
    <tr id="row87081282452"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p11708128124511"><a name="p11708128124511"></a><a name="p11708128124511"></a>eventSwitch</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p17708202834519"><a name="p17708202834519"></a><a name="p17708202834519"></a>Event output switch. This switch is turned off by default. If the default setting is retained before compilation, the <strong id="b86242510254"><a name="b86242510254"></a><a name="b86242510254"></a>Event</strong> component will not be initialized. The value can be:</p>
    <a name="ul845720186469"></a><a name="ul845720186469"></a><ul id="ul845720186469"><li>HIVIEW_FEATURE_ON</li><li>HIVIEW_FEATURE_OFF</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

4.  Add the header file dependencies to the  **Build.gn**  file of the module.

    ```
     include_dirs = [
          "//base/hiviewdfx/interfaces/kits/hilog_lite",
     ]
    ```

5.  Print logs.

    Add  **\#include "log.h"**  in the .c file where logs need to be printed, and then call the following function:

    ```
    HILOG_DEBUG(HILOG_MODULE_A, "log test: %d", 88);
    ```


## Use Case<a name="section153112047155419"></a>

The following steps describe how the  **samgr\_lite**  module \(an example\) uses the mini framework.

1.  Add the module ID, and define  **HILOG\_MODULE\_SAMGR**  in the type definition structure in  **base/hiviewdfx/interfaces/kits/hilog\_lite/hiview\_log.h**.

    ```
    typedef enum {
        ...
        HILOG_MODULE_SAMGR,
        ...
    } HiLogModuleType;
    ```

2.  Register the module. Specifically, add the registration code in  **HiLogInit**  of  **base/hiviewdfx/frameworks/hilog\_lite/mini/hiview\_log.c**.

    ```
    HiLogRegisterModule(HILOG_MODULE_SAMGR, "SAMGR");
    ```

3.  Include the header file dependencies in the  **foundation/distributedschedule/services/samgr\_lite/samgr/source/BUILD.gn**  file.

    ```
     include_dirs = [
          "//base/hiviewdfx/interfaces/kits/hilog_lite",
     ]
    ```

4.  Reference the header file in the source code file  **foundation/distributedschedule/services/samgr\_lite/samgr/source/message.c**  and call the related functions.

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


