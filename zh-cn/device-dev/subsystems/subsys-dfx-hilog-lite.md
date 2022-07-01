# HiLog\_Lite开发指导<a name="ZH-CN_TOPIC_0000001185815838"></a>


## 概述<a name="section775017517390"></a>

HiLog\_Lite是针对轻量系统类设备（参考内存≥128KB）、小型系统类设备（参考内存≥1MB）的hilog框架，实现了日志的打印、输出和流控功能。

## 接口说明<a name="section114412157402"></a>

C语言接口：

```
HILOG_DEBUG(mod, fmt, ...)
HILOG_INFO/HILOG_WARN/HILOG_ERROR/HILOG_FATAL
```

**表 1**  接口参数说明

<a name="table998125624816"></a>
<table><thead align="left"><tr id="row10981135611481"><th class="cellrowborder" valign="top" width="11.57%" id="mcps1.2.5.1.1"><p id="p11981145674811"><a name="p11981145674811"></a><a name="p11981145674811"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="11.83%" id="mcps1.2.5.1.2"><p id="p39821456124810"><a name="p39821456124810"></a><a name="p39821456124810"></a>是否必填</p>
</th>
<th class="cellrowborder" valign="top" width="15.21%" id="mcps1.2.5.1.3"><p id="p139822056104811"><a name="p139822056104811"></a><a name="p139822056104811"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="61.39%" id="mcps1.2.5.1.4"><p id="p3982145618482"><a name="p3982145618482"></a><a name="p3982145618482"></a>参数说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row209821456144818"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.2.5.1.1 "><p id="p20982125616483"><a name="p20982125616483"></a><a name="p20982125616483"></a>mod</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.2.5.1.2 "><p id="p1298245634810"><a name="p1298245634810"></a><a name="p1298245634810"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.2.5.1.3 "><p id="p1198295634817"><a name="p1198295634817"></a><a name="p1198295634817"></a>uint8</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.2.5.1.4 "><p id="p0982145634817"><a name="p0982145634817"></a><a name="p0982145634817"></a>模块/服务的ID。</p>
<p id="p1982155664820"><a name="p1982155664820"></a><a name="p1982155664820"></a>统一规划分配，最大支持64个，其中第三方APP统一使用HILOG_MODULE_APP作为模块ID。</p>
</td>
</tr>
<tr id="row1898225611489"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.2.5.1.1 "><p id="p9982656164812"><a name="p9982656164812"></a><a name="p9982656164812"></a>fmt</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.2.5.1.2 "><p id="p998255616484"><a name="p998255616484"></a><a name="p998255616484"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.2.5.1.3 "><p id="p18982256194818"><a name="p18982256194818"></a><a name="p18982256194818"></a>char *</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.2.5.1.4 "><p id="p2982165664818"><a name="p2982165664818"></a><a name="p2982165664818"></a>格式化输出字符串。</p>
<a name="ol19982256164816"></a><a name="ol19982256164816"></a><ol id="ol19982256164816"><li>最大支持6个可变参数，不支持%s。</li><li>格式化后的单条日志最大长度128字节，超过将无法打印。</li></ol>
</td>
</tr>
<tr id="row16982105613488"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.2.5.1.1 "><p id="p1898225604813"><a name="p1898225604813"></a><a name="p1898225604813"></a>可变参</p>
</td>
<td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.2.5.1.2 "><p id="p1698217568486"><a name="p1698217568486"></a><a name="p1698217568486"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.2.5.1.3 "><p id="p189834566489"><a name="p189834566489"></a><a name="p189834566489"></a>int32</p>
</td>
<td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.2.5.1.4 "><p id="p9983175654814"><a name="p9983175654814"></a><a name="p9983175654814"></a>仅支持数字类型，最大支持6个变参。</p>
</td>
</tr>
</tbody>
</table>

## 开发实例<a name="section1482812550419"></a>

以下引用samgr\_lite模块使用hilog\_lite框架作为实例。

1.  添加模块ID，在“base/hiviewdfx/hilog\_lite/interfaces/native/kits/hilog\_lite/hiview\_log.h“的类型定义结构体中添加HILOG\_MODULE\_SAMGR定义。

    ```
    typedef enum {
        ...
        HILOG_MODULE_SAMGR,
        ...
    } HiLogModuleType;
    ```

2.  注册模块，在“base/hiviewdfx/hilog\_lite/frameworks/mini/hiview\_log.c“的HiLogInit函数中添加注册代码。

    ```
    HiLogRegisterModule(HILOG_MODULE_SAMGR, "SAMGR");
    ```

3.  在GN文件中添加头文件依赖，文件路径为：“foundation/distributedschedule/samgr\_lite/samgr/BUILD.gn“

    ```
     include_dirs = [
          "//base/hiviewdfx/hilog_lite/interfaces/native/kits/hilog_lite",
     ]
    ```

4.  源文件“foundation/distributedschedule/samgr\_lite/samgr/source/message.c“中引用头文件并调用接口。

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


