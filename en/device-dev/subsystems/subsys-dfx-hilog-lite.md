# HiLog\_Lite Development<a name="EN-US_TOPIC_0000001185815838"></a>

## Overview<a name="section775017517390"></a>

HiLog\_Lite is the HiLog framework for Mini-System Devices \(reference memory ≥ 128 KiB\) and Small-System Devices \(reference memory ≥ 1 MiB\). It implements functions such as log printing, log output, and flow control.

## Available APIs<a name="section114412157402"></a>

HiLog\_lite provides the following C APIs:

```
HILOG_DEBUG(mod, fmt, ...)
HILOG_INFO/HILOG_WARN/HILOG_ERROR/HILOG_FATAL
```

**Table  1**  Parameters of C APIs

<a name="table998125624816"></a>
<table><thead align="left"><tr id="row10981135611481"><th class="cellrowborder" valign="top" width="11.57%" id="mcps1.2.5.1.1"><p id="p11981145674811"><a name="p11981145674811"></a><a name="p11981145674811"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="11.83%" id="mcps1.2.5.1.2"><p id="p39821456124810"><a name="p39821456124810"></a><a name="p39821456124810"></a>Mandatory?</p>
</th>
<th class="cellrowborder" valign="top" width="15.21%" id="mcps1.2.5.1.3"><p id="p139822056104811"><a name="p139822056104811"></a><a name="p139822056104811"></a>Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="61.39%" id="mcps1.2.5.1.4"><p id="p3982145618482"><a name="p3982145618482"></a><a name="p3982145618482"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row209821456144818"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.2.5.1.1 "><p id="p20982125616483"><a name="p20982125616483"></a><a name="p20982125616483"></a>mod</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.2.5.1.2 "><p id="p1298245634810"><a name="p1298245634810"></a><a name="p1298245634810"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.2.5.1.3 "><p id="p1198295634817"><a name="p1198295634817"></a><a name="p1198295634817"></a>uint8</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.2.5.1.4 "><p id="p0982145634817"><a name="p0982145634817"></a><a name="p0982145634817"></a>Indicates the module or service ID.</p>
<p id="p1982155664820"><a name="p1982155664820"></a><a name="p1982155664820"></a>IDs are planned and assigned in a unified manner. A maximum of 64 IDs are supported. Third-party applications use <strong id="b14339112165018"><a name="b14339112165018"></a><a name="b14339112165018"></a>HILOG_MODULE_APP</strong> as their module ID.</p>
</td>
</tr>
<tr id="row1898225611489"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.2.5.1.1 "><p id="p9982656164812"><a name="p9982656164812"></a><a name="p9982656164812"></a>fmt</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.2.5.1.2 "><p id="p998255616484"><a name="p998255616484"></a><a name="p998255616484"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.2.5.1.3 "><p id="p18982256194818"><a name="p18982256194818"></a><a name="p18982256194818"></a>char *</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.2.5.1.4 "><p id="p2982165664818"><a name="p2982165664818"></a><a name="p2982165664818"></a>Indicates the format specifier for output.</p>
<a name="ol19982256164816"></a><a name="ol19982256164816"></a><ol id="ol19982256164816"><li>A maximum of six variable parameters are supported. <strong id="b774813235502"><a name="b774813235502"></a><a name="b774813235502"></a>%s</strong> is not supported.</li><li>The maximum length of a formatted log record is 128 bytes. If the maximum length is exceeded, the log cannot be printed.</li></ol>
</td>
</tr>
<tr id="row16982105613488"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.2.5.1.1 "><p id="p1898225604813"><a name="p1898225604813"></a><a name="p1898225604813"></a>Variable parameters</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.2.5.1.2 "><p id="p1698217568486"><a name="p1698217568486"></a><a name="p1698217568486"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.2.5.1.3 "><p id="p189834566489"><a name="p189834566489"></a><a name="p189834566489"></a>int32</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.2.5.1.4 "><p id="p9983175654814"><a name="p9983175654814"></a><a name="p9983175654814"></a>Only numeric types are supported. A maximum of six variable parameters are allowed.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section1482812550419"></a>

The following provides an example of how the Samgr\_Lite module uses the HiLog\_Lite framework.

1.  Add the module ID, and define  **HILOG\_MODULE\_SAMGR**  in the  **HiLogModuleType**  structure in  **base/hiviewdfx/hilog\_lite/interfaces/native/kits/hilog\_lite/hiview\_log.h**.

    ```
    typedef enum {
        ...
        HILOG_MODULE_SAMGR,
        ...
    } HiLogModuleType;
    ```

2.  Register the module. Specifically, add the registration code to the  **HiLogInit**  function in  **base/hiviewdfx/hilog\_lite/frameworks/mini/hiview\_log.c**.

    ```
    HiLogRegisterModule(HILOG_MODULE_SAMGR, "SAMGR");
    ```

3.  Add the header file dependencies to the  **foundation/systemabilitymgr/samgr\_lite/samgr/BUILD.gn**  file.

    ```
     include_dirs = [
          "//base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog_lite",
     ]
    ```

4.  Reference the header file in the  **foundation/systemabilitymgr/samgr\_lite/samgr/source/message.c**  file and call the related APIs.

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


