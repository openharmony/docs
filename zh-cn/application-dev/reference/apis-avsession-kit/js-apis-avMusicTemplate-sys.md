# @ohos.multimedia.avMusicTemplate (音频模板)(系统接口)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_gyH0B0hP-->
<!--Designer: @ccfriend-->
<!--Tester: @chen-gong1-->
<!--Adviser: @w_Machine_cc-->

音频模板控制相关接口，可用于向接入播控中心的媒体应用查询数据，进行统一风格的页面展示，并下发页面操作指令。

该模块提供如下功能：

[AVMusicTemplateDescriptor](#avmusictemplatedescriptor)：音频模板描述，包含音频模板唯一标识，应用的包名和用户ID信息。

> **说明：**
>
> - 本模块首批接口从API version 23开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.avMusicTemplate (音频模板)](arkts-apis-avMusicTemplate.md)。
> - 本模块仅适用于API version 23及以上版本的Car设备。

## 导入模块

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';
```

## avMusicTemplate.createAVMusicTemplateController

createAVMusicTemplateController(sessionId: string): AVMusicTemplateController

创建音频模板控制器，返回音频模板控制器对象。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名    | 类型   | 必填 | 说明                          |
| --------- | ------ | ---- | ----------------------------- |
| sessionId | string | 是   | AVSession 对象唯一的会话标识。 |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [AVMusicTemplateController](arkts-apis-avMusicTemplate-AVMusicTemplateController.md) | 音频模板控制器实例，用于与接入音频模板的媒体应用进行数据交互。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[音频模板错误码](errorcode-avmusictemplate.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verify failed.                                    |
| 202      | Not System App.                                              |
| 801      | Capability not supported.function createAVMusicTemplateController can not work correctly due to limited device capabilities. |
| 35000002 | Failed to create the AVMusicTemplate controller.             |
| 35000005 | AVMusicTemplate does not exist.                              |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private controller: avMusicTemplate.AVMusicTemplateController | undefined = undefined;
  private currentBundleName: string | undefined = undefined;
  private templateCreateCallback: Callback<avMusicTemplate.AVMusicTemplateDescriptor> =
    (descriptor: avMusicTemplate.AVMusicTemplateDescriptor) => {
      if (this.isInvalid(descriptor)) {
        console.warn(TAG, 'templateCreateCallback: descriptor is invalid');
        return;
      }
      console.info(TAG, `templateCreateCallback, bundleName: ${descriptor.bundleName}`);
      this.createController(descriptor.sessionId, descriptor.bundleName);
    };
  private templateDestroyCallback: Callback<avMusicTemplate.AVMusicTemplateDescriptor> =
    (descriptor: avMusicTemplate.AVMusicTemplateDescriptor) => {
      if (this.isInvalid(descriptor)) {
        console.warn(TAG, 'templateDestroyCallback: descriptor is invalid');
        return;
      }
      if (this.isStringEmpty(this.currentBundleName)) {
        console.warn(TAG, 'templateDestroyCallback: current bundleName is empty');
        return;
      }
      if (this.currentBundleName !== descriptor.bundleName) {
        console.warn(TAG, 'templateDestroyCallback: not current bundleName');
        return;
      }
      this.unregisterListener();
      this.destroyController();
    };

  /**
   * 通过getAllAVMusicTemplateDescriptors获取模板描述并创建控制器。
   */
  public createAvMusicTemplateController(bundleName: string) {
    if (this.isStringEmpty(bundleName)) {
      console.warn(TAG, 'createAvMusicTemplateController: bundleName is empty');
      return;
    }
    this.currentBundleName = bundleName;
    try {
      // 该方法需要权限ohos.permission.MANAGE_MEDIA_RESOURCES。
      let descriptors: avMusicTemplate.AVMusicTemplateDescriptor[] = avMusicTemplate.getAllAVMusicTemplateDescriptors();
      if (this.isEmptyArray(descriptors)) {
        console.info(TAG, 'createAvMusicTemplateController: descriptors is empty');
        return;
      }
      for (let descriptor of descriptors) {
        if (descriptor === null || descriptor === undefined) {
          console.warn(TAG, 'createAvMusicTemplateController: descriptor is invalid continue');
          continue;
        }
        if (this.currentBundleName === descriptor.bundleName) {
          this.createController(descriptor.sessionId, descriptor.bundleName);
          return;
        }
      }
    } catch (e) {
      console.error(TAG, `getAllAVMusicTemplateDescriptors failed, errCode: ${e?.code}`);
    }
  };

  private isInvalid<T>(obj: T): boolean {
    return obj === undefined || obj === null;
  }

  private isStringEmpty(str: string | undefined): boolean {
    return str === undefined || str === null || str.trim().length === 0;
  }

  private isEmptyArray<T>(array: T[]): boolean {
    return this.isInvalid(array) || array.length <= 0;
  }

  /**
   * 注册模板监听。
   */
  public registerAVMusicTemplateListener() {
    try {
      // 该方法需要权限ohos.permission.MANAGE_MEDIA_RESOURCES。
      avMusicTemplate.onAVMusicTemplateCreate(this.templateCreateCallback);

      // 该方法需要权限ohos.permission.MANAGE_MEDIA_RESOURCES。
      avMusicTemplate.onAVMusicTemplateDestroy(this.templateDestroyCallback);
    } catch (e) {
      console.error(TAG, `registerAVMusicTemplateListener: errCode: ${e?.code}`);
    }
  }

  private createController(sessionId: string, bundleName: string) {
    if (this.currentBundleName === null || this.currentBundleName === undefined) {
      console.warn(TAG, 'createController: currentBundleName is invalid');
      return;
    }
    if (sessionId === null || sessionId === undefined) {
      console.warn(TAG, 'createController: sessionId is invalid');
      return;
    }
    if (bundleName === null || bundleName === undefined) {
      console.warn(TAG, 'createController: bundleName is invalid');
      return;
    }
    if (this.currentBundleName !== bundleName) {
      console.warn(TAG, 'createController: not current bundleName');
      return;
    }
    if (this.controller != undefined) {
      console.warn(TAG, 'createController: controller not undefined');
      return;
    }
    try {
      this.controller = avMusicTemplate.createAVMusicTemplateController(sessionId);
      console.info(TAG, 'Succeeded in creating controller.');
    } catch (e) {
      console.error(TAG, `createController: errCode: ${e?.code}`);
    }
  }

  /**
   * 注销监听。
   */
  public unregisterListener() {
    // 注销用户信息改变的监听。
    this.controller?.offUserInfoChange();

    // 注销对话框命令改变的监听。
    this.controller?.offDialogCommandChange();

    // 注销当前单曲改变的监听。
    this.controller?.offCurrentSingleChange();

    // 注销媒体实体改变的监听。
    this.controller?.offMediaEntitiesChange();

    // 注销标签页内容改变的监听。
    this.controller?.offTabContentChange();

    // 注销播放列表改变的监听。
    this.controller?.offPlaylistChange();

    // 注销下载媒体状态改变的监听。
    this.controller?.offDownloadMediaEntityStatusChange();

    // 注销自定义元素改变的监听。
    this.controller?.offCustomElementsChange();

    // 注销设置改变的监听。
    this.controller?.offSettingsChange();

    // 注销上报执行动作的监听。
    this.controller?.offReportExecuteAction();

    // 注销通知媒体中心拉起指定三方应用界面的信息的监听。
    this.controller?.offExtensionAbilityChange();
  }

  /**
   * 销毁控制器。
   */
  public destroyController() {
    console.info(TAG, 'destroyController')
    this.controller?.destroy();
    this.controller = undefined;
    this.currentBundleName = undefined;
  }

  /**
   * 注销模板监听。
   */
  public unregisterAVMusicTemplateListener() {
    try {
      avMusicTemplate.offAVMusicTemplateCreate();
      avMusicTemplate.offAVMusicTemplateDestroy();
    } catch (e) {
      console.error(TAG, `unregisterAVMusicTemplateListener: errCode: ${e?.code}`);
    }
  }
}
```

## avMusicTemplate.getAllAVMusicTemplateDescriptors

getAllAVMusicTemplateDescriptors(userId?: number): AVMusicTemplateDescriptor[]

获取所有的音频模板描述，返回音频模板描述的集合。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名 | 类型 | 必填 | 说明     |
| ------ | ---- | ---- | -------- |
| userId | number  | 否   | 用户ID。可选参数，不传入时为空。 |

**返回值：**

| 类型                                                      | 说明                 |
| --------------------------------------------------------- | -------------------- |
| [AVMusicTemplateDescriptor](#avmusictemplatedescriptor)[] | 音频模板描述的集合。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verify failed.                                    |
| 202      | Not System App.                                              |
| 801      | Capability not supported.function getAllAVMusicTemplateDescriptors can not work correctly due to limited device capabilities. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private currentBundleName: string | undefined = undefined;

  /**
   * 创建模板。
   */
  public createAvMusicTemplateController(bundleName: string) {
    if (this.isStringEmpty(bundleName)) {
      console.warn(TAG, 'createAvMusicTemplateController: bundleName is empty');
      return;
    }
    this.currentBundleName = bundleName;
    try {
      // 该方法需要权限ohos.permission.MANAGE_MEDIA_RESOURCES。
      let descriptors: avMusicTemplate.AVMusicTemplateDescriptor[] = avMusicTemplate.getAllAVMusicTemplateDescriptors();
    } catch (e) {
      console.error(TAG, `getAllAVMusicTemplateDescriptors failed, errCode: ${e?.code}`);
    }
  };

  private isStringEmpty(str: string | undefined): boolean {
    return str === undefined || str === null || str.trim().length === 0;
  }
}
```

## avMusicTemplate.onAVMusicTemplateCreate

onAVMusicTemplateCreate(callback: Callback&lt;AVMusicTemplateDescriptor&gt;): void

注册音频模板创建的监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                 |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------- |
| callback | Callback<[AVMusicTemplateDescriptor](#avmusictemplatedescriptor)> | 是   | 回调函数，参数为音频模板描述。用于监听音频模板创建事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verify failed.                                    |
| 202      | Not System App.                                              |
| 801      | Capability not supported.function onAVMusicTemplateCreate can not work correctly due to limited device capabilities. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private templateCreateCallback: Callback<avMusicTemplate.AVMusicTemplateDescriptor> =
    (descriptor: avMusicTemplate.AVMusicTemplateDescriptor) => {
      if (this.isInvalid(descriptor)) {
        console.warn(TAG, 'templateCreateCallback: descriptor is invalid');
        return;
      }
      console.info(TAG, `templateCreateCallback, bundleName: ${descriptor.bundleName}`);
    };

  private isInvalid<T>(obj: T): boolean {
    return obj === undefined || obj === null;
  }

  /**
   * 注册模板监听。
   */
  public registerAVMusicTemplateListener() {
    try {
      // 该方法需要权限ohos.permission.MANAGE_MEDIA_RESOURCES。
      avMusicTemplate.onAVMusicTemplateCreate(this.templateCreateCallback);
    } catch (e) {
      console.error(TAG, `registerAVMusicTemplateListener: errCode: ${e?.code}`);
    }
  }
}
```

## avMusicTemplate.offAVMusicTemplateCreate

offAVMusicTemplateCreate(callback?: Callback&lt;AVMusicTemplateDescriptor&gt;): void

注销音频模板创建监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | Callback<[AVMusicTemplateDescriptor](#avmusictemplatedescriptor)> | 否   | 回调函数，参数为音频模板描述。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verify failed.                                    |
| 202      | Not System App.                                              |
| 801      | Capability not supported.function offAVMusicTemplateCreate can not work correctly due to limited device capabilities. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  /**
   * 反注册模板监听。
   */
  public unregisterAVMusicTemplateListener() {
    try {
      avMusicTemplate.offAVMusicTemplateCreate();
    } catch (e) {
      console.error(TAG, `unregisterAVMusicTemplateListener: errCode: ${e?.code}`);
    }
  }
}
```

## avMusicTemplate.onAVMusicTemplateDestroy

onAVMusicTemplateDestroy(callback: Callback&lt;AVMusicTemplateDescriptor&gt;): void

注册音频模板销毁监听。使用callback异步回调。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                         |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------- |
| callback | Callback<[AVMusicTemplateDescriptor](#avmusictemplatedescriptor)> | 是   | 回调函数，参数为音频模板描述。用于监听音频模板销毁事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verify failed.                                    |
| 202      | Not System App.                                              |
| 801      | Capability not supported.function onAVMusicTemplateDestroy can not work correctly due to limited device capabilities. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  private templateDestroyCallback: Callback<avMusicTemplate.AVMusicTemplateDescriptor> =
    (descriptor: avMusicTemplate.AVMusicTemplateDescriptor) => {
    };

  /**
   * 注册模板监听。
   */
  public registerAVMusicTemplateListener() {
    try {
      // 该方法需要权限ohos.permission.MANAGE_MEDIA_RESOURCES。
      avMusicTemplate.onAVMusicTemplateDestroy(this.templateDestroyCallback);
    } catch (e) {
      console.error(TAG, `registerAVMusicTemplateListener: errCode: ${e?.code}`);
    }
  }
}
```

## avMusicTemplate.offAVMusicTemplateDestroy

offAVMusicTemplateDestroy(callback?: Callback&lt;AVMusicTemplateDescriptor&gt;): void

注销音频模板销毁监听。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_MEDIA_RESOURCES

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | Callback<[AVMusicTemplateDescriptor](#avmusictemplatedescriptor)> | 否   | 回调函数，参数为音频模板描述。不填该参数则注销该类型对应的所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verify failed.                                    |
| 202      | Not System App.                                              |
| 801      | Capability not supported.function offAVMusicTemplateDestroy can not work correctly due to limited device capabilities. |

**示例：**

```ts
import { avMusicTemplate } from '@kit.AVSessionKit';

const TAG: string = 'ControllerManager';

export class ControllerManager {
  /**
   * 反注册模板监听。
   */
  public unregisterAVMusicTemplateListener() {
    try {
      avMusicTemplate.offAVMusicTemplateDestroy();
    } catch (e) {
      console.error(TAG, `unregisterAVMusicTemplateListener: errCode: ${e?.code}`);
    }
  }
}
```

## AVMusicTemplateDescriptor

音频模板描述。包含音频模板唯一标识，应用的包名和用户ID。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.AVSession.AVMusicTemplate

| 名称       | 类型   | 只读 | 可选 | 说明               |
| ---------- | ------ | ---- | ---- | ------------------ |
| sessionId  | string | 否   | 否   | 音频模板唯一标识。 |
| bundleName | string | 否   | 否   | 应用的包名。       |
| userId     | number | 否   | 否   | 用户ID。           |
