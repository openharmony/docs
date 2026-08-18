# @ohos.multimodalAwareness.metadataBinding (记忆链接)
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: Msdp-->
<!--Owner: @codexu62-->
<!--Designer: @yuxiaoyang-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @hu-zhiqiong-->

本模块提供记忆链接能力调用，包括编码内容传递、订阅事件和取消订阅事件。记忆链接允许系统应用获取第三方应用的编码内容，支持实时事件监听和回调机制，适用于系统应用请求（如截图）并获取应用链接数据的场景，通过跨应用数据传递提升用户体验。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块
```ts
import { metadataBinding } from '@kit.MultimodalAwarenessKit';
```

## metadataBinding.submitMetadata
submitMetadata(metadata: string): void

第三方应用将需要编码的内容传递给接口服务，接口服务将内容传递给调用编码接口的系统应用或服务。本接口由第三方应用调用，供系统应用订阅获取数据。系统应用需先通过on('operationSubmitMetadata')方法订阅事件，才能接收到编码内容。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.MultimodalAwareness.MetadataBinding

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| metadata     | string                           | 是   | 需要编码的内容。字符串长度不超过128Bytes。 |

**错误码**：  

以下错误码的详细介绍请参见[记忆链接错误码](errorcode-metadataBinding.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 32100001 | Internal handling failed. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { metadataBinding } from '@kit.MultimodalAwarenessKit';

let metadata: string = 'sample metadata';
try {
  metadataBinding.submitMetadata(metadata);
} catch (error) {
  const err: BusinessError = error as BusinessError;
  console.error(`Failed to submit metadata. Code: ${err.code}, message: ${err.message}`);
}
```

## metadataBinding.on('operationSubmitMetadata')
on(type: 'operationSubmitMetadata', bundleName: string, callback: Callback&lt;number&gt;): void 

订阅系统应用请求获取编码内容的事件。当系统应用（如截图）请求获取应用的编码内容时触发该事件，应用注册回调后，事件发生时通过回调通知应用。调用on()方法订阅事件后，必须在不再需要监听事件时调用off()方法取消订阅，释放监听资源。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.MultimodalAwareness.MetadataBinding  

**参数**： 

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
|type| string|是|事件类型，固定传入'operationSubmitMetadata'，表示系统应用获取编码内容。|
|bundleName|string|是|应用包名，用于标识注册订阅事件的第三方应用。在事件发生时，系统将通过此包名识别并通知对应的注册应用。需确保传入的包名为有效的应用包名。|
|callback|Callback&lt;number&gt;|是|回调函数，用于返回事件码。当事件值为1时表示截图事件，目前仅支持截图事件，取值范围：1（截图事件）。注意：回调函数应快速执行，避免阻塞UI线程。| 

**错误码**：

以下错误码的详细介绍请参见[记忆链接错误码](errorcode-metadataBinding.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 32100001 | Internal handling failed. |
| 32100004 | Subscribe Failed. Possible causes: 1. Abnormal system capability. 2. IPC communication abnormality. 3. Algorithm loading exception. |

**示例：**  
```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { metadataBinding } from '@kit.MultimodalAwarenessKit';

let bundleName: string = 'com.example.app';
try {
  metadataBinding.on('operationSubmitMetadata', bundleName, (event: number) => {
    if (event == 1) {
      console.info('The screenshot request is received and the app link is obtained');
    }
  });
} catch (error) {
  const err = error as BusinessError;
  console.error(`Failed to register operationSubmitMetadata event. Code: ${err.code}, message: ${err.message}`);
}
```


## metadataBinding.off('operationSubmitMetadata')
off(type: 'operationSubmitMetadata', bundleName: string, callback?: Callback&lt;number&gt;): void

取消订阅系统获取编码内容的事件。需先调用on('operationSubmitMetadata')方法订阅事件，未订阅时调用不产生效果。取消订阅后，应用将不再接收编码内容传递事件。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.MultimodalAwareness.MetadataBinding  

**参数**：

| 参数名   | 类型                             | 必填 | 说明                                                         |
| -------- | -------------------------------- | ---- | ------------------------------------------------------------ |
|type|string|是| 事件类型，固定传入'operationSubmitMetadata'，表示系统应用获取编码内容。             |
|bundleName|string|是| 应用包名，标识注册应用的包名，需与订阅时传入的包名一致。|
|callback|Callback&lt;number&gt;|否| 回调函数，用于返回事件码。需要取消监听的回调函数，需与订阅时传入的回调函数一致。建议在订阅时保存回调函数引用，在取消订阅时使用同一引用。若不填，则取消当前监听该事件的所有回调函数。 |

**错误码**：  

以下错误码的详细介绍请参见[记忆链接错误码](errorcode-metadataBinding.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 32100001 | Internal handling failed. |
| 32100005 | Unsubscribe Failed. Possible causes: 1. Abnormal system capability. 2. IPC communication abnormality. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { metadataBinding } from '@kit.MultimodalAwarenessKit';

let bundleName: string = 'com.example.app';
try {
  metadataBinding.off('operationSubmitMetadata', bundleName);
} catch (error) {
 const err = error as BusinessError;
 console.error(`Failed to unsubscribe operationSubmitMetadata event. Code: ${err.code}, message: ${err.message}`);
}
```