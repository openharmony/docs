# @ohos.sendableResourceManager (资源管理)

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @liule_123-->
<!--Designer: @buda_wy-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->

本模块提供[Resource](#resource)对象与[SendableResource](#sendableresource)对象之间的相互转换功能。SendableResource实现了[ISendable](../../arkts-utils/arkts-sendable.md#isendable)接口，支持跨线程传输。跨线程传输后，SendableResource对象可以再转换为Resource对象，作为参数传递给[资源管理](./js-apis-resource-manager.md)接口以获取资源。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { sendableResourceManager } from '@kit.LocalizationKit';
```

## sendableResourceManager.resourceToSendableResource

resourceToSendableResource(resource: Resource): SendableResource

将Resource对象转换为可用于跨线程传输的SendableResource对象。

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
| 401 | Parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.                 |

**示例：**
```json5
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
import { sendableResourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

将跨线程传输的SendableResource对象转换为Resource对象。

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
| 401 | Parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed.                 |

**示例：**
```json5
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
import { sendableResourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let resource: sendableResourceManager.Resource = sendableResourceManager.sendableResourceToResource(sendableResourceManager.resourceToSendableResource($r('app.string.test')));
} catch (error) {
    let code = (error as BusinessError).code;
    let message = (error as BusinessError).message;
    console.error(`sendableResourceToResource failed, error code: ${code}, message: ${message}.`);
}
```

## Resource

type Resource = _Resource

表示资源相关信息，包括应用包名、应用模块名、资源ID、资源类型和其他资源参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 类型    | 说明   |
| ------  | ---- | 
|[_Resource](js-apis-resource.md#resource-1)| 表示Resource资源信息。|

## SendableResource

type SendableResource = _SendableResource

表示跨线程传输的Sendable资源相关信息，包括应用包名、应用模块名、资源ID、资源类型和其他资源参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Global.ResourceManager

| 类型         | 说明     |
| ---------- | ------ | 
| [_SendableResource](js-apis-sendableResource.md#sendableresource-1)|表示SendableResource资源信息。|