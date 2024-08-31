# @ohos.accessibility.config (系统辅助功能配置)(系统接口)

本模块提供系统辅助功能的配置，包括辅助扩展的启用与关闭、高对比度文字显示、鼠标键、无障碍字幕配置等。

> **说明：**
>
> - 本模块首批接口从 API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块

```ts
import { config } from '@kit.AccessibilityKit';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.BarrierFree.Accessibility.Core

| 名称                                 | 类型                                                                                         | 可读 | 可写 | 说明                                                        |
|------------------------------------|--------------------------------------------------------------------------------------------| -------- | -------- |-----------------------------------------------------------|
| highContrastText                   | [Config](#config)\<boolean>                                                                | 是 | 是 | 表示高对比度文字功能启用状态。                                           |
| invertColor                        | [Config](#config)\<boolean>                                                                | 是 | 是 | 表示颜色反转功能启用状态。                                             |
| daltonizationState<sup>11+</sup>   | [Config](#config)\<boolean>                                                                | 是 | 是 | 表示颜色滤镜功能启动状态。配合daltonizationColorFilter使用。                |
| daltonizationColorFilter           | [Config](#config)&lt;[DaltonizationColorFilter](#daltonizationcolorfilter)&gt;             | 是 | 是 | 表示颜色滤镜功能配置。                                               |
| contentTimeout                     | [Config](#config)\<number>                                                                 | 是 | 是 | 表示内容显示建议时长配置。取值 0~5000，单位为毫秒。                             |
| animationOff                       | [Config](#config)\<boolean>                                                                | 是 | 是 | 表示关闭动画功能启用状态。                                             |
| brightnessDiscount                 | [Config](#config)\<number>                                                                 | 是 | 是 | 表示亮度折扣系统配置。取值 0~1.0。                                      |
| mouseKey                           | [Config](#config)\<boolean>                                                                | 是 | 是 | 表示鼠标键功能启用状态。                                              |
| mouseAutoClick                     | [Config](#config)\<number>                                                                 | 是 | 是 | 表示鼠标自动点击功能启用状态。取值 0~5000，单位为毫秒。                           |
| shortkey                           | [Config](#config)\<boolean>                                                                | 是 | 是 | 表示辅助扩展快捷键功能启用状态。                                          |
| shortkeyTarget                     | [Config](#config)\<string>                                                                 | 是 | 是 | 表示辅助扩展快捷键的目标配置。取值为辅助应用的名称，格式为：'bundleName/abilityName'。   |
| captions                           | [Config](#config)\<boolean>                                                                | 是 | 是 | 表示辅助字幕功能启用状态。                                             |
| captionsStyle                      | [Config](#config)\<[accessibility.CaptionsStyle](js-apis-accessibility.md#captionsstyle8)> | 是 | 是 | 表示辅助字幕的配置。                                                |
| audioMono<sup>10+</sup>            | [Config](#config)\<boolean>                                                                | 是 | 是 | 表示音频单声道的配置。                                               |
| audioBalance<sup>10+</sup>         | [Config](#config)\<number>                                                                 | 是 | 是 | 表示左右声道音量平衡的配置。取值 -1.0~1.0。                                |
| shortkeyMultiTargets<sup>11+</sup> | [Config](#config)&lt;Array\<string>&gt;                                                    | 是 | 是 | 表示辅助扩展快捷键的列表配置。取值为辅助应用的名称，格式为：['bundleName/abilityName']。 |
| clickResponseTime<sup>11+</sup>    | [Config](#config)&lt;[ClickResponseTime](#clickresponsetime11)&gt;                         | 是 | 是 | 表示点击持续时间功能配置。                                             |
| ignoreRepeatClick<sup>11+</sup>    | [Config](#config)\<boolean>                                                                | 是 | 是 | 表示忽略重复点击功能启用状态。配合repeatClickInterval使用。                   |
| repeatClickInterval<sup>11+</sup>  | [Config](#config)&lt;[RepeatClickInterval](#repeatclickinterval11)&gt;                     | 是 | 是 | 表示忽略重复点击功能配置。                                             |

boolean返回值的含义：True表示开启，False表示关闭。
[]()
## enableAbility

enableAbility(name: string, capability: Array&lt;accessibility.Capability&gt;): Promise&lt;void&gt;;

需要权限：ohos.permission.WRITE_ACCESSIBILITY_CONFIG

启用辅助扩展，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型                                                                           | 必填 | 说明 |
| -------- |------------------------------------------------------------------------------| -------- | -------- |
| name | string                                                                       | 是 | 辅助应用的名称，格式为：'bundleName/abilityName'。 |
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | 是 | 辅助应用的能力属性。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300001 | Invalid bundle name or ability name.  |
| 9300002 | Target ability already enabled. |

**示例：**

```ts
import { accessibility, config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';
let capability: accessibility.Capability[] = ['retrieve'];

config.enableAbility(name, capability).then(() => {
  console.info(`Succeeded  in enable ability, name is ${name}, capability is ${capability}`);
}).catch((err: BusinessError) => {
  console.error(`failed to enable ability, Code is ${err.code}, message is ${err.message}`);
});
```

## enableAbility

enableAbility(name: string, capability: Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt;, callback: AsyncCallback&lt;void&gt;): void;

需要权限：ohos.permission.WRITE_ACCESSIBILITY_CONFIG

启用辅助扩展，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型                                                                              | 必填 | 说明 |
| -------- |---------------------------------------------------------------------------------| -------- | -------- |
| name | string                                                                          | 是 | 辅助应用的名称，格式为：'bundleName/abilityName'。 |
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | 是 | 辅助应用的能力属性。 |
| callback | AsyncCallback&lt;void&gt;                                                       | 是 | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300001 | Invalid bundle name or ability name.  |
| 9300002 | Target ability already enabled. |

**示例：**

```ts
import { accessibility, config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';
let capability: accessibility.Capability[] = ['retrieve'];

config.enableAbility(name, capability, (err: BusinessError) => {
  if (err) {
    console.error(`failed to enable ability, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in enable ability, name is ${name}, capability is ${capability}`); 
});
```

## disableAbility

disableAbility(name: string): Promise&lt;void&gt;;

需要权限：ohos.permission.WRITE_ACCESSIBILITY_CONFIG

关闭辅助扩展，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 辅助应用的名称，格式为：'bundleName/abilityName'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300001 | Invalid bundle name or ability name.  |

**示例：**

```ts
import { accessibility, config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';

config.disableAbility(name).then(() => {
  console.info(`Succeeded in disable ability, name is ${name}`);
}).catch((err: BusinessError) => {
  console.error(`failed to disable ability, Code is ${err.code}, message is ${err.message}`);
})
```

## disableAbility

disableAbility(name: string, callback: AsyncCallback&lt;void&gt;): void;

需要权限：ohos.permission.WRITE_ACCESSIBILITY_CONFIG

关闭辅助扩展，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 辅助应用的名称，格式为：'bundleName/abilityName'。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300001 | Invalid bundle name or ability name.  |

**示例：**

```ts
import { accessibility, config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';

config.disableAbility(name, (err: BusinessError) => {
  if (err) {
    console.error(`failed to enable ability, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in disable, name is ${name}`);
});
```

## on('enabledAccessibilityExtensionListChange')

on(type: 'enabledAccessibilityExtensionListChange', callback: Callback&lt;void&gt;): void;

需要权限：ohos.permission.READ_ACCESSIBILITY_CONFIG

添加启用的辅助扩展的列表变化监听，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 参数固定为enabledAccessibilityExtensionListChange，监听启用的辅助扩展的列表变化。 |
| callback | Callback&lt;void&gt; | 是 | 回调函数，在启用的辅助扩展的列表变化时通过此函数进行通知。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

config.on('enabledAccessibilityExtensionListChange', () => {
  console.info('subscribe enabled accessibility extension list change state success');
});
```

## off('enabledAccessibilityExtensionListChange')

off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback&lt;void&gt;): void;

需要权限：ohos.permission.READ_ACCESSIBILITY_CONFIG

取消启用的辅助扩展的列表变化监听，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type |  string | 是 | 参数固定为enabledAccessibilityExtensionListChange，监听启用的辅助扩展的列表变化。 |
| callback | Callback&lt;void&gt; | 否 | 取消指定callback对象的事件响应。需与on('enabledAccessibilityExtensionListChange')的callback一致。缺省时，表示注销所有已注册事件。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

config.off('enabledAccessibilityExtensionListChange', () => {
  console.info('Unsubscribe enabled accessibility extension list change state success');
});
```

## on('installedAccessibilityListChange')<sup>12+</sup>

on(type: 'installedAccessibilityListChange', callback: Callback&lt;void&gt;): void;

需要权限：ohos.permission.READ_ACCESSIBILITY_CONFIG

添加已安装的辅助扩展的列表变化监听，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 参数固定为installedAccessibilityListChange，监听已安装的辅助扩展的列表变化。 |
| callback | Callback&lt;void&gt; | 是 | 回调函数，在已安装的辅助扩展的列表变化时通过此函数进行通知。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

config.on('installedAccessibilityListChange', () => {
  console.info('subscribe installed accessibility extension list change state success');
});
```

## off('installedAccessibilityListChange')<sup>12+</sup>

off(type: 'installedAccessibilityListChange', callback?: Callback&lt;void&gt;): void;

需要权限：ohos.permission.READ_ACCESSIBILITY_CONFIG

取消已安装的辅助扩展的列表变化监听，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type |  string | 是 | 参数固定为installedAccessibilityListChange，监听已安装的辅助扩展的列表变化。 |
| callback | Callback&lt;void&gt; | 否 | 取消指定callback对象的事件响应。需与on('installedAccessibilityListChange')的callback一致。缺省时，表示注销所有已注册事件。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

config.off('installedAccessibilityListChange', () => {
  console.info('Unsubscribe installed accessibility extension list change state success');
});
```

## Config

用于属性的设置、获取与监听。

### set

set(value: T): Promise&lt;void&gt;;

需要权限：ohos.permission.WRITE_ACCESSIBILITY_CONFIG

设置属性，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 设置的属性值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let value: boolean = true;

config.highContrastText.set(value).then(() => {
  console.info(`Succeeded in set highContrastText value is ${value}`);
}).catch((err: BusinessError) => {
  console.error(`failed to set highContrastText, Code is ${err.code}, message is ${err.message}`);
});
```

### set

set(value: T, callback: AsyncCallback&lt;void&gt;): void;

需要权限：ohos.permission.WRITE_ACCESSIBILITY_CONFIG

设置属性，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 设置的属性值。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let value: boolean = true;

config.highContrastText.set(value, (err: BusinessError) => {
  if (err) {
    console.error(`failed to set highContrastText, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in set highContrastText, value is ${value}`);
});
```

### get

get(): Promise&lt;T&gt;;

获取属性，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;T&gt; | Promise对象，返回对应属性值。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

config.highContrastText.get().then((data: boolean) => {
  console.info(`Succeeded in get highContrastText, data is ${data}`);
}).catch((err: BusinessError) => {
  console.error(`failed to get highContrastText, Code is ${err.code}, message is ${err.message}`);
});
```

### get

get(callback: AsyncCallback&lt;T&gt;): void;

获取属性，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;T&gt; | 是 | 回调函数，返回属性值。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

config.highContrastText.get((err: BusinessError, data: boolean) => {
  if (err) {
    console.error(`failed to get highContrastText, Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in get highContrastText, data is ${data}`);
});
```

### on

on(callback: Callback&lt;T&gt;): void;

需要权限：ohos.permission.READ_ACCESSIBILITY_CONFIG

添加属性变化监听，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | 是 | 回调函数，在属性变化时通过此函数进行通知。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

config.highContrastText.on((data: boolean) => {
  console.info(`subscribe highContrastText success, result: ${JSON.stringify(data)}`);
});
```

### off

off(callback?: Callback&lt;T&gt;): void;

需要权限：ohos.permission.READ_ACCESSIBILITY_CONFIG

取消属性变化监听，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | 否 | 取消指定callback对象的事件响应。需与on()的callback一致。缺省时，表示注销所有已注册事件。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

config.highContrastText.off((data: boolean) => {
  console.info(`Unsubscribe highContrastText success, result: ${JSON.stringify(data)}`);
});
```

## DaltonizationColorFilter

用于不同弱视类型的校正颜色滤镜。  
颜色滤镜功能开启时（[daltonizationState](#属性)设置为true)，颜色滤镜的配置(即设置的DaltonizationColorFilter的值)生效；颜色滤镜功能关闭时（[daltonizationState](#属性)设置为false)，显示为正常类型<sup>11+</sup>。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 说明 |
| -------- | -------- |
| Normal | 表示正常类型。 |
| Protanomaly | 表示红色弱视类型。 |
| Deuteranomaly | 表示绿色弱视类型。 |
| Tritanomaly  | 表示蓝色弱视类型。 |

## ClickResponseTime<sup>11+</sup>

用于不同时间长短的点击重复时间。  

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称          | 说明         |
|-------------|------------|
| Short       | 表示短 (默认)。  |
| Medium      | 表示中。       |
| Long        | 表示长。       |

## RepeatClickInterval<sup>11+</sup>

用于不同时间间隔的忽略重复点击。  
忽略重复点击功能开启时（[ignoreRepeatClick](#属性)设置为true)，忽略重复点击的配置(即设置的RepeatClickInterval的值)生效；忽略重复点击功能关闭时（[ignoreRepeatClick](#属性)设置为false)，显示为正常类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称       | 说明    |
|----------|-------|
| Shortest | 表示最短。 |
| Short    | 表示短。  |
| Medium   | 表示中。  |
| Long     | 表示长。  |
| Longest  | 表示最长。 |

