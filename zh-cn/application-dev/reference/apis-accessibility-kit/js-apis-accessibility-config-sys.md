# @ohos.accessibility.config (系统辅助功能配置)(系统接口)

<!--Kit: Accessibility Kit-->
<!--Subsystem: BarrierFree-->
<!--Owner: @qiiiiiiian-->
<!--Designer: @z7o-->
<!--Tester: @A_qqq-->
<!--Adviser: @w_Machine_cc-->

本模块提供系统辅助功能的配置，包括辅助扩展的启用与关闭、高对比度文字显示、鼠标键、无障碍字幕配置等。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块

```ts
import { config } from '@kit.AccessibilityKit';
```

## 属性

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称                                 | 类型                                                                                     | 只读 | 可选 | 说明                         |
|------------------------------------|--------------------------------------------------------------------------------------------| -------- | -------- |-----------------------------------------------------------|
| highContrastText                   | [Config](#config)\<boolean>                                                                | 否 | 否 | 表示高对比度文字功能启用状态。true表示已启用高对比度文字功能，false表示未启用高对比度文字功能，默认值为false。                                           |
| invertColor                        | [Config](#config)\<boolean>                                                                | 否 | 否 | 表示颜色反转功能启用状态。true表示已启用颜色反转功能，false表示未启用颜色反转功能，默认值为false。                                             |
| daltonizationState<sup>11+</sup>   | [Config](#config)\<boolean>                                                                | 否 | 否 | 表示色彩校正功能启用状态。配合daltonizationColorFilter使用。true表示已启用色彩校正功能，false表示未启用色彩校正功能，默认值为false。                |
| daltonizationColorFilter           | [Config](#config)&lt;[DaltonizationColorFilter](#daltonizationcolorfilter)&gt;             | 否 | 否 | 表示色彩校正颜色滤镜配置。配合daltonizationState使用，仅当daltonizationState设置为true时，此配置生效。默认值为Normal，表示正常类型。                                               |
| contentTimeout                     | [Config](#config)\<number>                                                                 | 否 | 否 | 表示内容显示建议时长配置，用于设置无障碍提示等内容在屏幕上的持续显示时长。取值范围为0~5000，单位为毫秒。默认值为0。                             |
| animationOff                       | [Config](#config)\<boolean>                                                                | 否 | 否 | 表示关闭动画功能启用状态。true表示已启用关闭动画功能，false表示未启用关闭动画功能，默认值为false。                                             |
| brightnessDiscount                 | [Config](#config)\<number>                                                                 | 否 | 否 | 表示亮度折扣配置，用于按比例调整屏幕显示亮度。取值范围为0~1.0，0表示无亮度折扣（原始亮度），1.0表示最大亮度折扣。默认值为0.0。                                      |
| mouseKey                           | [Config](#config)\<boolean>                                                                | 否 | 否 | 表示鼠标键功能启用状态。true表示已启用鼠标键功能，false表示未启用鼠标键功能，默认值为false。                                              |
| mouseAutoClick                     | [Config](#config)\<number>                                                                 | 否 | 否 | 表示鼠标自动点击操作的配置。取值范围为0~5000，单位为毫秒，0表示不生效，其他值表示鼠标悬停相应的时长即触发自动点击操作，默认值为0。                |
| shortkey                           | [Config](#config)\<boolean>                                                                | 否 | 否 | 表示辅助扩展快捷键功能启用状态。配合shortkeyTarget使用。true表示已启用辅助扩展快捷键功能，false表示未启用辅助扩展快捷键功能，默认值为false。                                          |
| shortkeyTarget                     | [Config](#config)\<string>                                                                 | 否 | 否 | 表示辅助扩展快捷键的目标配置。取值为辅助扩展应用的名称，格式为：'bundleName/abilityName'。格式不正确或名称无效时，设置不生效。   |
| captions                           | [Config](#config)\<boolean>                                                                | 否 | 否 | 表示辅助字幕功能启用状态。true表示已启用辅助字幕功能，false表示未启用辅助字幕功能，默认值为false。                                             |
| captionsStyle                      | [Config](#config)\<[accessibility.CaptionsStyle](js-apis-accessibility.md#captionsstyle8)> | 否 | 否 | 表示辅助字幕样式的配置。                                                |
| audioMono<sup>10+</sup>            | [Config](#config)\<boolean>                                                                | 否 | 否 | 表示单声道音频功能启用状态。true表示已启用单声道音频功能，false表示未启用单声道音频功能，默认值为false。                                            |
| audioBalance<sup>10+</sup>         | [Config](#config)\<number>                                                                 | 否 | 否 | 表示左右声道音量平衡的配置。-1.0表示仅左声道输出；0.0表示左右声道平衡输出；1.0表示仅右声道输出；中间值为左右声道音量的线性比例。取值范围为-1.0~1.0。默认值为0.0。                                |
| shortkeyMultiTargets<sup>11+</sup> | [Config](#config)&lt;Array&lt;string&gt;&gt;                                                    | 否 | 否 | 表示辅助扩展快捷键的多目标列表配置。取值为辅助扩展应用的名称，格式为：['bundleName/abilityName']。格式不正确或名称无效时，设置不生效。 |
| clickResponseTime<sup>11+</sup>    | [Config](#config)&lt;[ClickResponseTime](#clickresponsetime11)&gt;                         | 否 | 否 | 表示点击持续时间功能配置。                                             |
| ignoreRepeatClick<sup>11+</sup>    | [Config](#config)\<boolean>                                                                | 否 | 否 | 表示忽略重复点击功能启用状态。配合repeatClickInterval使用。true表示已启用忽略重复点击功能，false表示未启用忽略重复点击功能，默认值为false。                   |
| repeatClickInterval<sup>11+</sup>  | [Config](#config)&lt;[RepeatClickInterval](#repeatclickinterval11)&gt;                     | 否 | 否 | 表示忽略重复点击的时间间隔配置。配合ignoreRepeatClick使用，仅当ignoreRepeatClick设置为true时，此配置生效。默认值为Shortest，表示最短间隔。                                             |

## config.enableAbility

enableAbility(name: string, capability: Array&lt;accessibility.Capability&gt;): Promise&lt;void&gt;

启用辅助扩展，需与[config.disableAbility](#configdisableability)配对使用。使用Promise异步回调。

与[config.enableAbilityWithCallback](#configenableabilitywithcallback23)相比，本接口仅启用辅助扩展，不监听辅助扩展的连接状态变化；若需要监听辅助扩展断开连接事件，请使用[config.enableAbilityWithCallback](#configenableabilitywithcallback23)。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**
| 参数名 | 类型                                                                           | 必填 | 说明 |
| -------- |------------------------------------------------------------------------------| -------- | -------- |
| name | string                                                                       | 是 | 辅助扩展应用的名称，格式为：'bundleName/abilityName'。 |
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | 是 | 辅助扩展应用的能力属性。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

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
  console.info(`Succeeded in enabling ability, name is ${name}, capability is ${capability}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to enable ability. Code: ${err.code}, message: ${err.message}`);
});
```

## config.enableAbility

enableAbility(name: string, capability: Array&lt;accessibility.Capability&gt;, callback: AsyncCallback&lt;void&gt;): void

启用辅助扩展，需与[config.disableAbility](#configdisableability)配对使用。使用callback异步回调。

与[config.enableAbilityWithCallback](#configenableabilitywithcallback23)相比，本接口仅启用辅助扩展，不监听辅助扩展的连接状态变化；若需要监听辅助扩展断开连接事件，请使用[config.enableAbilityWithCallback](#configenableabilitywithcallback23)。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型                                                                              | 必填 | 说明 |
| -------- |---------------------------------------------------------------------------------| -------- | -------- |
| name | string                                                                          | 是 | 辅助扩展应用的名称，格式为：'bundleName/abilityName'。 |
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | 是 | 辅助扩展应用的能力属性。 |
| callback | AsyncCallback&lt;void&gt;                                                       | 是 | 回调函数。当启用辅助扩展成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

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
    console.error(`Failed to enable ability. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in enabling ability, name is ${name}, capability is ${capability}`); 
});
```

## config.enableAbilityWithCallback<sup>23+</sup>

enableAbilityWithCallback(name: string, capability: Array&lt;accessibility.Capability&gt;, connectCallback: ConnectCallback): Promise&lt;void&gt;

启用辅助扩展，并指定[ConnectCallback](#connectcallback23)作为辅助扩展连接断开事件的回调函数。使用Promise异步回调。

当辅助扩展进程异常断开连接时，将触发ConnectCallback的onDisconnect回调。需与[config.disableAbility](#configdisableability)配对使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                                                           | 必填 | 说明 |
| -------- |------------------------------------------------------------------------------| -------- | -------- |
| name | string                                                                       | 是 | 辅助扩展应用的名称，格式为：'bundleName/abilityName'。 |
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | 是 | 辅助扩展应用的能力属性。 |
| connectCallback | [ConnectCallback](#connectcallback23)                             | 是 | 辅助扩展应用连接断开时调用的回调函数，用于监听辅助扩展的断开连接事件。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300001 | Invalid bundle name or ability name.  |
| 9300002 | Target ability already enabled. |

**示例：**

```ts
import { accessibility, config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';
let capability: accessibility.Capability[] = ['retrieve'];
let connectCallback: config.ConnectCallback = {
  onDisconnect: () => {
    console.info(`Ability is disconnected.`);
  }
};

config.enableAbilityWithCallback(name, capability, connectCallback).then(() => {
  console.info(`Succeeded in enabling ability, name is ${name}, capability is ${capability}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to enable ability. Code: ${err.code}, message: ${err.message}`);
});
```

## config.disableAbility

disableAbility(name: string): Promise&lt;void&gt;

关闭辅助扩展，需与[config.enableAbility](#configenableability)或[config.enableAbilityWithCallback](#configenableabilitywithcallback23)配对使用。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 辅助扩展应用的名称，格式为：'bundleName/abilityName'。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300001 | Invalid bundle name or ability name.  |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';

config.disableAbility(name).then(() => {
  console.info(`Succeeded in disabling ability, name is ${name}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to disable ability. Code: ${err.code}, message: ${err.message}`);
});
```

## config.disableAbility

disableAbility(name: string, callback: AsyncCallback&lt;void&gt;): void

关闭辅助扩展，需与[config.enableAbility](#configenableability)或[config.enableAbilityWithCallback](#configenableabilitywithcallback23)配对使用。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 辅助扩展应用的名称，格式为：'bundleName/abilityName'。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当关闭辅助扩展成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 9300001 | Invalid bundle name or ability name.  |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let name: string = 'com.ohos.example/axExtension';

config.disableAbility(name, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to disable ability. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in disabling, name is ${name}`);
});
```

## config.on('enabledAccessibilityExtensionListChange')

on(type: 'enabledAccessibilityExtensionListChange', callback: Callback&lt;void&gt;): void

添加启用的辅助扩展的列表变化监听。使用callback异步回调。

需与[config.off('enabledAccessibilityExtensionListChange')](#configoffenabledaccessibilityextensionlistchange)配对使用，在不需要监听时调用off取消注册，避免资源泄漏。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.READ_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 参数固定为'enabledAccessibilityExtensionListChange'，指定监听启用的辅助扩展的列表变化事件类型。 |
| callback | Callback&lt;void&gt; | 是 | 回调函数，在启用的辅助扩展的列表变化时通过此函数进行通知。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

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

## config.off('enabledAccessibilityExtensionListChange')

off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback&lt;void&gt;): void

取消启用的辅助扩展的列表变化监听。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.READ_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type |  string | 是 | 参数固定为'enabledAccessibilityExtensionListChange'，指定取消监听的事件类型为启用的辅助扩展的列表变化。 |
| callback | Callback&lt;void&gt; | 否 | 回调函数，取消指定callback对象的事件响应。需与on('enabledAccessibilityExtensionListChange')的callback一致。缺省时，表示注销所有已注册事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

let callback = () => {
  console.info('subscribe enabled accessibility extension list change state success');
};
config.on('enabledAccessibilityExtensionListChange', callback);
config.off('enabledAccessibilityExtensionListChange', callback);
```

## config.on('installedAccessibilityListChange')<sup>12+</sup>

on(type: 'installedAccessibilityListChange', callback: Callback&lt;void&gt;): void

添加已安装的辅助扩展的列表变化监听。使用callback异步回调。

需与[config.off('installedAccessibilityListChange')](#configoffinstalledaccessibilitylistchange12)配对使用，在不需要监听时调用off取消注册，避免资源泄漏。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.READ_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 参数固定为'installedAccessibilityListChange'，监听已安装的辅助扩展的列表变化。 |
| callback | Callback&lt;void&gt; | 是 | 回调函数，在已安装的辅助扩展的列表变化时通过此函数进行通知。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

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

## config.off('installedAccessibilityListChange')<sup>12+</sup>

off(type: 'installedAccessibilityListChange', callback?: Callback&lt;void&gt;): void

取消已安装的辅助扩展的列表变化监听。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.READ_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type |  string | 是 | 参数固定为'installedAccessibilityListChange'，指定取消监听的事件类型为已安装的辅助扩展的列表变化。 |
| callback | Callback&lt;void&gt; | 否 | 回调函数，取消指定callback对象的事件响应。需与on('installedAccessibilityListChange')的callback一致。缺省时，表示注销所有已注册事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

let callback = () => {
  console.info('subscribe installed accessibility extension list change state success');
};
config.on('installedAccessibilityListChange', callback);
config.off('installedAccessibilityListChange', callback);
```
## config.setMagnificationState<sup>20+</sup>

setMagnificationState(state: boolean): void

设置放大效果的启用状态。放大效果依赖放大手势功能，仅在放大手势功能已启用的前提下，本接口的设置才会生效。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| state |  boolean | 是 | 表示放大效果的启用状态。<br>- true：表示启用放大效果。<br>- false：表示关闭放大效果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 801 | Capability not supported. Failed to call the API due to limited device capabilities. |
| 9300007  | Trigger magnification failed. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  config.setMagnificationState(true);
} catch (err) {
  let e = err as BusinessError;
  console.error(`Failed to set magnification. Code: ${e.code}, message: ${e.message}`);
}
```

## config.setSeniorModeStateForApp

setSeniorModeStateForApp(appSeniorModeInfos: Array&lt;AppSeniorModeInfo&gt;): Promise&lt;void&gt;

设置应用“长辈模式”的状态。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型                                                                           | 必填 | 说明 |
| -------- |------------------------------------------------------------------------------| -------- | -------- |
| appSeniorModeInfos | Array&lt;[AppSeniorModeInfo](#appseniormodeinfo)&gt; | 是 | 修改应用的“长辈模式”的状态信息，数组中每个对象包含bundleName、appIndex、seniorModeState三个属性。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300000 | System abnormality.  |
| 9300008 | The appIndex is invalid. Possible causes: 1. The appIndex is out of the valid range. 2. The application corresponding to the appIndex does not exist. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let infos: config.AppSeniorModeInfo[] = [{
  bundleName: 'com.example.myapplication',
  appIndex: 0,
  seniorModeState: true
}];

config.setSeniorModeStateForApp(infos).then(() => {
  console.info(`Succeeded in setting seniorModeState for App.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set seniorModeState for app. Code: ${err.code}, message: ${err.message}`);
});
```

## config.getSeniorModeStateForApp

getSeniorModeStateForApp(bundleName: string, appIndex?: number): Promise&lt;boolean&gt;

查询应用“长辈模式”的状态。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.READ_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型                                                                           | 必填 | 说明 |
| -------- |------------------------------------------------------------------------------| -------- | -------- |
| bundleName | string | 是 | 查询“长辈模式”的应用包名。 |
| appIndex | number | 否 | 应用包的分身索引标识。<br>取值范围：大于等于0的整数。缺省时，appIndex默认为0。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示应用已启用“长辈模式”；返回false表示应用未启用“长辈模式”。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300000 | System abnormality.  |
| 9300008 | The appIndex is invalid. Possible causes: 1. The appIndex is out of the valid range. 2. The application corresponding to the appIndex does not exist. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

config.getSeniorModeStateForApp('com.example.myapplication', 0).then((data: boolean) => {
  console.info(`Succeeded in getting seniorModeState for app, data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get seniorModeState for app. Code: ${err.code}, message: ${err.message}`);
});
```

## config.onSeniorModeStateChangeForApp

onSeniorModeStateChangeForApp(callback: Callback&lt;AppSeniorModeInfo&gt;): void

监听所有应用“长辈模式”的状态变化事件。使用callback异步回调。

> **说明：**
>
> - 注册监听的callback参数应使用具名函数而非匿名函数，否则每次调用时会创建一个新的底层对象，引起内存泄漏问题。
> - 调用此方法后，务必在组件实例销毁前（如aboutToDisappear生命周期中）使用[config.offSeniorModeStateChangeForApp](#configoffseniormodestatechangeforapp)取消监听，否则可能会导致崩溃。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | Callback&lt;[AppSeniorModeInfo](#appseniormodeinfo)&gt; | 是 | 回调函数。返回被修改的应用“长辈模式”信息。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.|
| 202 | Permission verification failed. A non-system application calls a system API.|

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

@Entry
@Component
struct Index {
  callback = (data: config.AppSeniorModeInfo) => {
    console.info(`callback data, name: ${data.bundleName}, appIndex: ${data.appIndex}, seniorModeState: ${data.seniorModeState}`);
  }

  aboutToAppear(): void {
    config.onSeniorModeStateChangeForApp(this.callback);
  }

  aboutToDisappear(): void {
    config.offSeniorModeStateChangeForApp(this.callback);
  }

  build() {
    Column() {
    }
  }
}
```

## config.offSeniorModeStateChangeForApp

offSeniorModeStateChangeForApp(callback?: Callback\<AppSeniorModeInfo>): void

取消监听所有应用“长辈模式”的状态变化事件。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.READ_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| callback | Callback&lt;[AppSeniorModeInfo](#appseniormodeinfo)&gt; | 否   | 回调函数，取消指定callback对象的事件响应。需与[config.onSeniorModeStateChangeForApp](#configonseniormodestatechangeforapp)的callback一致。缺省时，表示注销所有已注册事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

@Entry
@Component
struct Index {
  callback = (data: config.AppSeniorModeInfo) => {
    console.info(`callback data, name: ${data.bundleName}, appIndex: ${data.appIndex}, seniorModeState: ${data.seniorModeState}`);
  }

  aboutToAppear(): void {
    config.onSeniorModeStateChangeForApp(this.callback);
  }

  aboutToDisappear(): void {
    config.offSeniorModeStateChangeForApp(this.callback);
  }

  build() {
    Column() {
    }
  }
}
```

## config.startBlinking

startBlinking(mode: BlinkingMode, scenario: BlinkingScenario): BlinkResultCode

启用闪光灯或屏幕以进行闪烁提醒。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型                                                                           | 必填 | 说明 |
| -------- |------------------------------------------------------------------------------| -------- | -------- |
| mode | [BlinkingMode](#blinkingmode) | 是 | 表示屏幕闪烁或闪光灯闪烁的模式。 |
| scenario | [BlinkingScenario](#blinkingscenario) | 是 | 表示触发闪烁的场景。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [BlinkResultCode](#blinkresultcode) | 接口调用返回的结果码。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300000 | System abnormality.Possible causes: <br>1.Internal operation failed. <br>2.Failed to obtain the required service or client object (null pointer).<br>3.IPC communication failed. <br>4.Failed to obtain the accessibility service proxy.|

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

try {
  let code: config.BlinkResultCode = config.startBlinking(config.BlinkingMode.SINGLE_BLINK, config.BlinkingScenario.ALARM);
  console.info(`Succeeded in startBlinking, result code: ${code}`);
} catch (err) {
  console.error(`Failed to call startBlinking, code is ${err.code}, message is ${err.message}`);
}
```

## config.stopBlinking

stopBlinking(mode: BlinkingMode, scenario: BlinkingScenario): BlinkResultCode

停止闪光灯闪烁或屏幕闪烁。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型                                                                           | 必填 | 说明 |
| -------- |------------------------------------------------------------------------------| -------- | -------- |
| mode | [BlinkingMode](#blinkingmode) | 是 | 表示屏幕闪烁或闪光灯闪烁的模式。 |
| scenario | [BlinkingScenario](#blinkingscenario) | 是 | 表示触发闪烁的场景。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [BlinkResultCode](#blinkresultcode) | 接口调用返回的结果码。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[无障碍子系统错误码](errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 9300000 | System abnormality.Possible causes: <br>1.Internal operation failed. <br>2.Failed to obtain the required service or client object (null pointer).<br>3.IPC communication failed. <br>4.Failed to obtain the accessibility service proxy.|

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

try {
  let code: config.BlinkResultCode = config.stopBlinking(config.BlinkingMode.SINGLE_BLINK, config.BlinkingScenario.ALARM);
  console.info(`Succeeded in stopBlinking, result code: ${code}`);
} catch (err) {
  console.error(`Failed to call stopBlinking, code is ${err.code}, message is ${err.message}`);
}
```

## Config

用于属性的设置、获取与监听。

### set

set(value: T): Promise&lt;void&gt;

设置属性。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 设置的属性值，值类型与对应Config属性的类型一致。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

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
  console.info(`succeeded in setting highContrastText value is ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set highContrastText. Code: ${err.code}, message: ${err.message}`);
});
```

### set

set(value: T, callback: AsyncCallback&lt;void&gt;): void

设置属性。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.WRITE_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 设置的属性值，值类型与对应Config属性的类型一致。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当设置属性成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

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
    console.error(`Failed to set highContrastText. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`succeeded in setting highContrastText, value is ${value}`);
});
```

### get

get(): Promise&lt;T&gt;

获取属性。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;T&gt; | Promise对象，返回对应属性值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

config.highContrastText.get().then((data: boolean) => {
  console.info(`succeeded in getting highContrastText, data is ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get highContrastText. Code: ${err.code}, message: ${err.message}`);
});
```

### get

get(callback: AsyncCallback&lt;T&gt;): void

获取属性。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;T&gt; | 是 | 回调函数。当获取属性成功，err为undefined，data为属性值；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

config.highContrastText.get((err: BusinessError, data: boolean) => {
  if (err) {
    console.error(`Failed to get highContrastText. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`succeeded in getting highContrastText, data is ${data}`);
});
```

### on

on(callback: Callback&lt;T&gt;): void

添加属性变化监听。使用callback异步回调。

需与[off](#off)配对使用，在不需要监听时调用off取消注册，避免资源泄漏。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.READ_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | 是 | 回调函数，在属性变化时通过此函数进行通知。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

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

off(callback?: Callback&lt;T&gt;): void

取消属性变化监听。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.READ_ACCESSIBILITY_CONFIG

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | 否 | 回调函数，取消指定callback对象的事件响应。需与on()的callback一致。缺省时，表示注销所有已注册事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 201  | Permission verification failed. The application does not have the permission required to call the API.  |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { config } from '@kit.AccessibilityKit';

let callback = (data: boolean) => {
  console.info(`subscribe highContrastText success, result: ${JSON.stringify(data)}`);
};
config.highContrastText.on(callback);
config.highContrastText.off(callback);
```

## ConnectCallback<sup>23+</sup>

通过[config.enableAbilityWithCallback](#configenableabilitywithcallback23)接口启用辅助扩展应用时提供的回调函数。辅助扩展应用连接断开时，回调函数将被调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**模型约束：** 此接口仅可在Stage模型下使用。

| 名称         | 类型                                         | 只读 | 可选 | 说明                                     |
| ------------ | -------------------------------------------- | ---- | ---- | ---------------------------------------- |
| onDisconnect | [OnDisconnectCallback](#ondisconnectcallback23) | 否   | 否   | 辅助扩展应用的连接断开时调用的回调函数。 |


## OnDisconnectCallback<sup>23+</sup>

type OnDisconnectCallback = () => void

描述AccessibilityExtensionAbility断开连接的回调接口。

**系统接口：** 此类型为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

**模型约束：** 此类型仅可在Stage模型下使用。


## DaltonizationColorFilter

用于不同色弱类型的校正颜色滤镜。

色彩校正功能启用时（[daltonizationState](#属性)设置为true）配置生效；色彩校正功能未启用时（[daltonizationState](#属性)设置为false）显示为正常类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 说明 |
| -------- | -------- |
| Normal | 表示正常类型。 |
| Protanomaly | 表示红色弱类型。 |
| Deuteranomaly | 表示绿色弱类型。 |
| Tritanomaly  | 表示蓝色弱类型。 |

## ClickResponseTime<sup>11+</sup>

用于不同时间长短的点击持续时间。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称          | 说明         |
|-------------|------------|
| Short       | 表示短（默认）。  |
| Medium      | 表示中。       |
| Long        | 表示长。       |

## RepeatClickInterval<sup>11+</sup>

用于不同时间间隔的忽略重复点击。

忽略重复点击功能启用时（[ignoreRepeatClick](#属性)设置为true）配置生效；忽略重复点击功能未启用时（[ignoreRepeatClick](#属性)设置为false）不生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称       | 说明    |
|----------|-------|
| Shortest | 表示最短。 |
| Short    | 表示短。  |
| Medium   | 表示中。  |
| Long     | 表示长。  |
| Longest  | 表示最长。 |

## AppSeniorModeInfo

“长辈模式”在应用中的状态信息。

**起始版本：** 26.0.0

**模型约束：** 此类型仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.BarrierFree.Accessibility.Core

| 名称         | 类型                                         | 只读 | 可选 | 说明                                     |
| ------------ | -------------------------------------------- | ---- | ---- | ---------------------------------------- |
| bundleName | string | 否   | 否   | 应用包名，用于标识应用，格式如：'com.example.myapplication'。 |
| appIndex | number | 否   | 是   | 应用包的分身索引标识。取值大于等于0的整数，缺省时默认为0。|
| seniorModeState | boolean | 否   | 否   | 应用“长辈模式”启用状态，true表示已启用，false表示未启用。|

## BlinkingMode

表示闪烁模式的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 名称                        | 值   | 说明                     |
| -------------------------- | ---- | ------------------------ |
| SINGLE_BLINK                       |  1 | 表示单次闪烁。         |
| CONTINUOUS_BLINK                |  2 | 表示持续闪烁。         |

## BlinkingScenario

表示闪烁场景的枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 名称                        | 值   | 说明                     |
| -------------------------- | ---- | ------------------------ |
| ALARM                       |  1 | 表示闹钟触发闪烁。         |
| NOTIFICATION                |  2 | 表示通知触发闪烁。         |
| CALL                        |  3 | 表示来电触发闪烁。         |
| TESTING                     |  4 | 表示测试场景触发闪烁。     |

## BlinkResultCode

表示闪烁操作的结果码枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

| 名称                        | 值   | 说明                     |
| -------------------------- | ---- | ------------------------ |
| SUCCESS                         |  0 | 表示闪烁接口执行成功。          |
| ALREADY_FLASHING                |  1 | 表示设备正在闪烁中。       |
| DEVICE_IN_USE                   |  2 | 表示设备正在使用中。     |
| FLASH_BLINKING_UNSUPPORTED      |  3 | 表示设备不支持闪光灯闪烁。   |
| SCREEN_BLINKING_UNSUPPORTED     |  4 | 表示设备不支持屏幕闪烁。     |
| FEATURE_DISABLED                |  5 | 表示闪烁功能开关未开启。 |