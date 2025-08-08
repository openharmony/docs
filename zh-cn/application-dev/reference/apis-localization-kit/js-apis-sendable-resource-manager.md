# @ohos.sendableResourceManager (资源管理)

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--SE: @buda_wy-->
<!--TSE: @lpw_work-->

资源管理导入sendableResourceManager模块，通过调用[resourceToSendableResource](#sendableresourcemanagerresourcetosendableresource)和[sendableResourceToResource](#sendableresourcemanagersendableresourcetoresource)方法可以将[Resource](#resource)对象和[SendableResource](#sendableresource)对象进行互转。

Resource对象通过转换为SendableResource对象后，可以被[Sendable类](../../arkts-utils/arkts-sendable.md)持有。Sendable类在跨线程传输后，取出持有的SendableResource对象转为Resource对象，作为参数获取资源。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import sendableResourceManager from '@ohos.sendableResourceManager';
```

## sendableResourceManager.resourceToSendableResource

resourceToSendableResource(resource: Resource): SendableResource

将Resource对象转换为SendableResource对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                            |
| -------- | ---------------------------------------- | ---- | ----------------------------- |
| resource | [Resource](#resource) | 是    | Resource对象。 |

**返回值：**

| 类型     | 说明          |
| ------ | ---------------------------- |
| [SendableResource](#sendableresource)  | 转换后的SendableResource对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.                 |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a test string resource."
      }
    ]
  }
  ```
  ```js
import sendableResourceManager from '@ohos.sendableResourceManager';
import { BusinessError } from '@ohos.base';

try {
    let sendableResource: sendableResourceManager.SendableResource = sendableResourceManager.resourceToSendableResource($r('app.string.test'));
} catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`resourceToSendableResource failed, error code: ${code}, message: ${message}.`);
}
  ```

## sendableResourceManager.sendableResourceToResource

sendableResourceToResource(resource: SendableResource): Resource

将SendableResource对象转换为Resource对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Global.ResourceManager

**参数：** 

| 参数名      | 类型                                       | 必填   | 说明                            |
| -------- | ---------------------------------------- | ---- | ----------------------------- |
| resource | [SendableResource](#sendableresource) | 是    | SendableResource对象。 |

**返回值：**

| 类型     | 说明          |
| ------ | ---------------------------- |
| [Resource](#resource) | 转换后的Resource对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.                 |

**示例：**
  ```json
  // 资源文件路径: src/main/resources/base/element/string.json
  {
    "string": [
      {
        "name": "test",
        "value": "I'm a test string resource."
      }
    ]
  }
  ```
  ```js
import sendableResourceManager from '@ohos.sendableResourceManager';
import { BusinessError } from '@ohos.base';

try {
    let resource: sendableResourceManager.Resource = sendableResourceManager.sendableResourceToResource(sendableResourceManager.resourceToSendableResource($r('app.string.test')));
} catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`resourceToSendableResource failed, error code: ${code}, message: ${message}.`);
}
  ```

## Resource

type Resource = _Resource

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 类型    | 说明   |
| ------  | ---- | 
|[_Resource](js-apis-resource.md#resource-1)| 表示Resource资源信息。|

## SendableResource

type SendableResource = _SendableResource

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 类型         | 说明     |
| ---------- | ------ | 
| [_SendableResource](js-apis-sendableResource.md#sendableresource-1)|表示SendableResource资源信息。|