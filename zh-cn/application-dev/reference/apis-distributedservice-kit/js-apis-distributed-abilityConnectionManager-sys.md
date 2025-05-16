# @ohos.distributedsched.abilityConnectionManager (应用多端协同管理)(系统接口)

abilityConnectionManager模块提供了应用协同接口管理能力。设备组网成功（需登录同账号、双端打开蓝牙）后，系统应用和三方应用可以跨设备拉起同应用的一个[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)，拉起并连接成功后可实现跨设备数据传输，包括字符串、[ArrayBuffer](../../arkts-utils/arraybuffer-object.md)字节流、图片、传输流。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块为系统接口。

## 导入模块

```js
import { abilityConnectionManager } from '@kit.DistributedServiceKit';
```

## abilityConnectionManager.on('collaborateEvent')

on(type:&nbsp;'collaborateEvent',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;CollaborateEventInfo&gt;):&nbsp;void

注册collaborateEvent事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   表示事件回调类型，支持的事件类型为'collaborateEvent'，完成`collaborateEvent()`调用，触发该事件。   |
| sessionId | number  | 是    | 表示创建的协同会话ID。    |
| callback | Callback&lt;[CollaborateEventInfo](js-apis-distributed-abilityConnectionManager.md#CollaborateEventInfo)&gt; | 是    | 表示注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.on("collaborateEvent", sessionId, (callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session collaborateEvent, eventType is', callbackInfo.eventType);
  });
  ```

## abilityConnectionManager.on('receiveImage')

on(type:&nbsp;'receiveImage',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

注册receiveImage事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   表示事件回调类型，支持的事件类型为'receiveImage'，完成`sendImage()`调用，触发该事件。   |
| sessionId | number  | 是    | 表示创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](js-apis-distributed-abilityConnectionManager.md#eventcallbackinfo)&gt; | 是    | 表示注册的回调函数。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  abilityConnectionManager.on("receiveImage", sessionId, (callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session receiveImage, sessionId is', callbackInfo.sessionId);
  });
  ```

## abilityConnectionManager.off('collaborateEvent')

off(type:&nbsp;'collaborateEvent',&nbsp;sessionId:&nbsp;number,&nbsp;callback?:&nbsp;Callback&lt;CollaborateEventInfo&gt;):&nbsp;void

取消collaborateEvent事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   表示事件回调类型，支持的事件类型为'collaborateEvent'。    |
| sessionId | number  | 是    | 表示创建的协同会话ID。    |
| callback | Callback&lt;[CollaborateEventInfo](js-apis-distributed-abilityConnectionManager.md#CollaborateEventInfo)&gt; | 否    | 表示注册的回调函数。如果传入该参数，则关闭该监听。如果未传入该参数，则取消所有'collaborateEvent'事件监听。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.off("collaborateEvent", sessionId);
  ```

## abilityConnectionManager.off('receiveImage')

off(type:&nbsp;'receiveImage',&nbsp;sessionId:&nbsp;number,&nbsp;callback?:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

取消receiveImage事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   表示事件回调类型，支持的事件类型为'receiveImage'。    |
| sessionId | number  | 是    | 表示创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](js-apis-distributed-abilityConnectionManager.md#eventcallbackinfo)&gt; | 否    | 表示注册的回调函数。如果传入该参数，则关闭该监听。如果未传入该参数，则取消所有'receiveImage'事件监听。    |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  abilityConnectionManager.off("receiveImage", sessionId);
  ```

## abilityConnectionManager.sendImage

sendImage(sessionId:&nbsp;number,&nbsp;image:&nbsp;image.PixelMap,&nbsp;quality?:&nbsp;number):&nbsp;Promise&lt;void&gt;

应用连接成功并创建传输流后，设备A或设备B可向对端设备发送图片。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 表示协同会话ID。 |
| image | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是    | 表示图片信息。 |
| quality | number | 否    | 表示图像压缩质量（取值范围为0到100，默认值为30）。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;void&gt; | 无返回结果的promise对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { photoAccessHelper } from '@kit.MediaLibraryKit';
  import { image } from '@kit.ImageKit';
  import { fileIo as fs } from '@kit.CoreFileKit';

  try {
    let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
    photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new photoAccessHelper.PhotoViewPicker();
    photoPicker.select(photoSelectOptions).then((photoSelectResult) => {
      if (!photoSelectResult) {
        hilog.error(0x0000, 'testTag', 'photoSelectResult = null');
      return;
      }

      let file = fs.openSync(photoSelectResult.photoUris[0], fs.OpenMode.READ_ONLY);
      hilog.info(0x0000, 'testTag', 'file.fd:' + file.fd);

      let sessionId = 100;
      let imageSourceApi: image.ImageSource = image.createImageSource(file.fd);
      if (imageSourceApi) {
        imageSourceApi.createPixelMap().then((pixelMap) => {
          abilityConnectionManager.sendImage(sessionId, pixelMap)
        });
      } else {
        hilog.info(0x0000, 'testTag', 'imageSourceApi is undefined');
      }
    })
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'photoPicker failed with error: ' + JSON.stringify(error));
  }
  ```

## abilityConnectionManager.createStream

createStream(sessionId:&nbsp;number,&nbsp;param:&nbsp;StreamParam):&nbsp;Promise&lt;number&gt;

应用连接成功后，设备A或设备B可创建传输流，发送图片和视频流。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 表示协同会话ID。 |
| param | [StreamParam](#streamparam) | 是    | 表示传输流的配置信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;number&gt; | 返回number结果的promise对象。number为创建结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[分布式设备管理错误码](./errorcode-device-manager.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 32300001      | Only one stream can be created for the current session.|
| 32300003      | Bitrate not supported.|
| 32300004      | Color space not supported.|

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'startStream');
  let sessionId = 100;
  abilityConnectionManager.createStream(sessionId ,{name: 'receive', role: 0}).then(async (streamId) => {
    let surfaceParam: abilityConnectionManager.SurfaceParam = {
      width: 640,
      height: 480,
      format: 1
    }
    let surfaceId = abilityConnectionManager.getSurfaceId(streamId, surfaceParam);
    hilog.info(0x0000, 'testTag', 'surfaceId is'+surfaceId);
    AppStorage.setOrCreate<string>('surfaceId', surfaceId);
    abilityConnectionManager.startStream(streamId);
  })
  ```

## abilityConnectionManager.setSurfaceId

setSurfaceId(sessionId:&nbsp;number,&nbsp;surfaceId:&nbsp;string,&nbsp;param:&nbsp;SurfaceParam):&nbsp;void

设置传输流与Surface的绑定关系。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 表示协同会话ID。 |
| surfaceId | string | 是    | 表示Surface的唯一标识符。 |
| param | [SurfaceParam](#surfaceparam) | 是    | 表示Surface的配置参数。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'setSurfaceId');
  let sessionId = 100;
  abilityConnectionManager.createStream(sessionId ,{name: 'receive', role: 0}).then(async (streamId) => {
    let surfaceParam: abilityConnectionManager.SurfaceParam = {
      width: 640,
      height: 480,
      format: 1
    }
    let surfaceId = abilityConnectionManager.getSurfaceId(streamId, surfaceParam);
    abilityConnectionManager.setSurfaceId(streamId, surfaceId, surfaceParam);
  })
  ```

## abilityConnectionManager.getSurfaceId

getSurfaceId(sessionId:&nbsp;number,&nbsp;param:&nbsp;SurfaceParam):&nbsp;string

获取指定传输流绑定的Surface的唯一标识符。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 表示协同会话ID。 |
| param | [SurfaceParam](#surfaceparam) | 是    | 表示Surface的配置参数。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| string | Surface的唯一标识符。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'getSurfaceId');
  let sessionId = 100;
  abilityConnectionManager.createStream(sessionId ,{name: 'receive', role: 0}).then(async (streamId) => {
    let surfaceParam: abilityConnectionManager.SurfaceParam = {
      width: 640,
      height: 480,
      format: 1
    }
    let surfaceId = abilityConnectionManager.getSurfaceId(streamId, surfaceParam);
  })
  ```

## abilityConnectionManager.updateSurfaceParam

updateSurfaceParam(sessionId:&nbsp;number,&nbsp;param:&nbsp;SurfaceParam):&nbsp;void

更新与传输流绑定的Surface的配置信息。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 表示协同会话ID。 |
| param | [SurfaceParam](#surfaceparam) | 是    | 表示Surface的配置参数。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  hilog.info(0x0000, 'testTag', 'updateSurfaceParam');
  let sessionId = 100;
  abilityConnectionManager.createStream(sessionId ,{name: 'receive', role: 0}).then(async (streamId) => {
    let surfaceParam: abilityConnectionManager.SurfaceParam = {
      width: 640,
      height: 480,
      format: 1
    }
    abilityConnectionManager.updateSurfaceParam(streamId, surfaceParam);
  })
  ```

## abilityConnectionManager.destroyStream

destroyStream(sessionId:&nbsp;number):&nbsp;void

发送图片和视频流等业务结束后，创建传输流的应用应及时销毁传输流，否则会增加系统功耗。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 表示协同会话ID。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API.|
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  hilog.info(0x0000, 'testTag', 'destroyStream called');
  abilityConnectionManager.destroyStream(sessionId)
  ```

## abilityConnectionManager.startStream

startStream(sessionId:&nbsp;number):&nbsp;void

启动指定传输流。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 表示协同会话ID。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[分布式设备管理错误码](./errorcode-device-manager.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 32300002      | The stream at the receive end is not started. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  hilog.info(0x0000, 'testTag', 'startStream called');
  abilityConnectionManager.startStream(sessionId)
  ```

## abilityConnectionManager.stopStream

stopStream(sessionId:&nbsp;number):&nbsp;void

停止指定传输流。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 表示协同会话ID。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202      | Permission verification failed. A non-system application calls a system API.|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

  ```ts
  import { abilityConnectionManager } from '@kit.DistributedServiceKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let sessionId = 100;
  hilog.info(0x0000, 'testTag', 'stopStream called');
  abilityConnectionManager.stopStream(sessionId)
  ```

## CollaborateEventInfo

协作事件信息。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称       | 类型   | 可读   | 可写   | 必填   | 说明      |
| -------- | ------ | ---- | ---- | ---- | ------- |
| eventType | [CollaborateEventType](#collaborateeventtype) | 是    | 否    | 是    | 表示协作事件的类型。 |
| eventMsg | string | 是    | 否    | 否    | 表示协作事件的协作消息。 |

## StreamParam

流传输配置的参数。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称       | 类型    | 可读   | 可写   | 必填   | 说明          |
| -------- | ------ | ---- | ---- | ---- | ----------- |
| name  | string   | 是    | 否    | 是    |   表示流传输的名称（接收端必须与发送端一致）。 |
| role  | [StreamRole](#streamrole)     | 是    | 否    | 是    |   表示流传输的方式（可以是接收流或发送流）。 |
| bitrate  | number   | 是    | 否    | 否    |   表示视频比特率（仅在发送端有效，默认值为80000）。 |
| colorSpaceConversionTarget  | [colorSpaceManager.ColorSpace](../apis-arkgraphics2d/js-apis-colorSpaceManager.md#colorspace)     | 是    | 否    | 否    |  表示转换的目标色彩空间。 |

## SurfaceParam

Surface配置参数。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称       | 类型   | 可读   | 可写   | 必填   | 说明      |
| -------- | ------ | ---- | ---- | ---- | ------- |
| width | number | 是    | 否    | 是    | 表示编码宽度。必须在流启动前设置，流启动后到停止前均无法更新。如需更新需要将流停止后重新配置。 |
| height | number | 是    | 否    | 是   | 表示编码长度。必须在流启动前设置，流启动后到停止前均无法更新。如需更新需要将流停止后重新配置。 |
| format | [VideoPixelFormat](#videopixelformat) | 是    | 否    | 否    | 表示视频像素格式，此选项必须在发送端配置。 |
| rotation | number | 是    | 否    | 否    | 表示视频的旋转角度（取值范围为{0, 90, 180, 270}，默认值为0）。 |
| flip | [FlipOptions](#flipoptions) | 是    | 否    | 否    | 表示视频是否反转。 |

## CollaborateEventType

协作事件的类型的枚举。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 枚举值 | 描述 |
| -------- | -------- |
| SEND_FAILURE   | 表示发送任务失败。 |
| COLOR_SPACE_CONVERSION_FAILURE | 表示色彩空间转换失败。 |

## FlipOptions

翻转选项的枚举。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 枚举值 | 描述 |
| -------- | -------- |
| HORIZONTAL   | 表示水平翻转。 |
| VERTICAL | 表示垂直翻转。 |

## StreamRole

流传输的方式。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 枚举值 | 描述 |
| -------- | -------- |
| SOURCE  | 表示流是发送流。 |
| SINK  | 表示流是接收流。 |

## VideoPixelFormat

视频像素格式的枚举。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 枚举值 | 描述 |
| -------- | -------- |
| UNKNOWN   | 表示未知的像素格式。 |
| NV12  | 表示NV12，YUV420半平面格式。 |
| NV21  | 表示NV21，YUV420半平面格式。 |

## ConnectOptions

应用连接时所需的连接选项。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称          | 类型    | 只读   | 可选   | 说明          |
| ----------- | ------- | ---- | ---- | ----------- |
| needSendStream    | boolean  | 否    | 否    | true表示需要发送流，false表示不需要发送流。    |
| needReceiveStream    | boolean  | 否    | 否    | true表示需要接收流，false表示不需要接收流。     |

## EventCallbackInfo

回调方法的接收信息。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称       | 类型    | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| image  | image.PixelMap | 是    | 否    |   表示接收的图片。 |

## StartOptionParams

启动选项参数的枚举。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration
 
| 名称|  值 | 说明 |
|-------|-------|-------|
| START_IN_BACKGROUND | 1 |表示将对端应用启动至后台。|
