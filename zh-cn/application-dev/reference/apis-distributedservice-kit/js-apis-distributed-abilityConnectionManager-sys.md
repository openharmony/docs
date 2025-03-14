# @ohos.abilityConnectionManager (应用多端协同管理)(系统接口)

abilityConnectionManager模块提供了应用协同接口管理能力。设备组网成功（需登录同账号、双端打开蓝牙）后，系统应用和三方应用可以跨设备拉起同应用的一个[UIAbility](../apis-ability-kit/js-apis-app-ability-uiAbility.md)，拉起并连接成功后可实现跨设备数据传输，包括字符串、[ArrayBuffer](../../arkts-utils/arraybuffer-object.md)字节流、图片、传输流。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { abilityConnectionManager } from '@kit.DistributedServiceKit';
```

## abilityConnectionManager.on

on(type:&nbsp;'receiveData'&nbsp;|&nbsp;'receiveImage',&nbsp;sessionId:&nbsp;number,&nbsp;callback:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

注册receiveData、receiveImage事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件包括：<br/>\- `'receiveData'`：完成`sendData()`调用，触发该事件。<br/>\- `'receiveImage'`：完成`sendImage()`调用，触发该事件。   |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](js-apis-distributed-abilityConnectionManager.md#eventcallbackinfo)&gt; | 是    | 注册的回调函数。    |

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

  abilityConnectionManager.on("receiveData", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session receiveData, sessionId is', callbackInfo.sessionId);
  });

  abilityConnectionManager.on("receiveImage", this.sessionId,(callbackInfo) => {
    hilog.info(0x0000, 'testTag', 'session receiveImage, sessionId is', callbackInfo.sessionId);
  });

  ```

## abilityConnectionManager.off

off(type:&nbsp;'receiveData'&nbsp;|&nbsp;'receiveImage',&nbsp;sessionId:&nbsp;number,&nbsp;callback?:&nbsp;Callback&lt;EventCallbackInfo&gt;):&nbsp;void

取消receiveData、receiveImage事件的回调监听。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                    | 必填   | 说明    |
| --------- | ------------------------------------- | ---- | ----- |
| type | string  | 是    |   事件回调类型，支持的事件包括：<br/>\- `'receiveData'`：完成`sendData()`调用，触发该事件。<br/>\- `'receiveImage'`：完成`sendImage()`调用，触发该事件。    |
| sessionId | number  | 是    | 创建的协同会话ID。    |
| callback | Callback&lt;[EventCallbackInfo](js-apis-distributed-abilityConnectionManager.md#eventcallbackinfo)&gt; | 否    | 注册的回调函数。    |

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

  abilityConnectionManager.off("receiveData", this.sessionId);
  abilityConnectionManager.off("receiveImage", this.sessionId);
  ```


## abilityConnectionManager.sendData

sendData(sessionId:&nbsp;number,&nbsp;data:&nbsp;ArrayBuffer):&nbsp;Promise&lt;void&gt;;

应用连接成功后，设备A或设备B可向对端设备发送[ArrayBuffer](../../arkts-utils/arraybuffer-object.md)字节流。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 协同会话ID。 |
| data | [ArrayBuffer](../../arkts-utils/arraybuffer-object.md) | 是    | 字节流信息。 |

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

  let textEncoder = util.TextEncoder.create("utf-8");
  const arrayBuffer  = textEncoder.encodeInto("data send success");

  abilityConnectionManager.sendData(this.sessionId, arrayBuffer.buffer).then(() => {
    hilog.info(0x0000, 'testTag', "sendMessage success");
  }).catch(() => {
    hilog.info(0x0000, 'testTag', "sendMessage failed");
  })
  ```

## abilityConnectionManager.sendImage

sendImage(sessionId:&nbsp;number,&nbsp;image:&nbsp;image.PixelMap):&nbsp;Promise&lt;void&gt;;

应用连接成功并创建传输流后，设备A或设备B可向对端设备发送图片。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 协同会话ID。 |
| image | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是    | 图片信息。 |

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
  import CameraService from '../model/CameraService';
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

      let imageSourceApi: image.ImageSource = image.createImageSource(file.fd);
      if (imageSourceApi) {
        imageSourceApi.createPixelMap().then((pixelMap) => {
          abilityConnectionManager.sendImage(this.sessionId, pixelMap)
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

createStream(sessionId:&nbsp;number,&nbsp;param:&nbsp;StreamParam):&nbsp;Promise&lt;number&gt;;

应用连接成功后，设备A或设备B可创建传输流，发送图片和视频流。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

**系统API**：此接口为系统接口。

**参数：**

| 参数名       | 类型                                      | 必填   | 说明    |
| --------- | --------------------------------------- | ---- | ----- |
| sessionId | number | 是    | 协同会话ID。 |
| param | [StreamParam](#streamparam) | 是    | 传输流的配置信息。 |

**返回值：**

| 类型                  | 说明               |
| ------------------- | ---------------- |
| Promise&lt;number&gt; | 返回number结果的promise对象。 |

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

  hilog.info(0x0000, 'testTag', 'startStream');
  abilityConnectionManager.createStream(sessionId ,{name: 'receive', role: 0}).then(async (streamId) => {
    let surfaceParam: abilityConnectionManager.SurfaceParam = {
      width: 640,
      height: 480,
      format: 1
    }
    let surfaceId = abilityConnectionManager.getSurfaceId(streamId, surfaceParam);
    hilog.info(0x0000, 'testTag', 'surfaceId is'+surfaceId);
    AppStorage.setOrCreate<string>('surfaceId', surfaceId);
    await CameraService.initCamera(surfaceId, 0);
    abilityConnectionManager.startStream(streamId);
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
| sessionId | number | 是    | 协同会话ID。 |

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

  hilog.info(0x0000, 'testTag', 'destroyStream called');
  abilityConnectionManager.destroyStream(sessionId)
  ```

## StreamParam

流传输配置的参数。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 名称       | 类型    | 可读   | 可写   | 说明          |
| -------- | ------ | ---- | ---- | ----------- |
| name  | string   | 是    | 否    |   流传输的名称（接收端必须与发送端一致）。 |
| role  | [StreamRole](#streamrole)     | 是    | 否    |   流传输的方式（可以是接收流或发送流）。 |

## StreamRole

流传输的方式。

**系统能力**：SystemCapability.DistributedSched.AppCollaboration

| 枚举值 | 描述 | 
| -------- | -------- |
| SOURCE  | 表示流是发送流。 | 
| SINK  | 表示流是接收流。 |