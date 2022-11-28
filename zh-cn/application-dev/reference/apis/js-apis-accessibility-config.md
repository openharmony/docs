# 系统辅助功能配置

本模块提供系统辅助功能的配置，包括辅助扩展的启用与关闭、高对比度文字显示、鼠标键、无障碍字幕配置等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从 API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块

```ts
import config from '@ohos.accessibility.config';
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| highContrastText | [Config](#config)\<boolean>| 是 | 是 | 表示高对比度文字功能启用状态。 |
| invertColor | [Config](#config)\<boolean>| 是 | 是 | 表示颜色反转功能启用状态。 |
| daltonizationColorFilter | [Config](#config)&lt;[DaltonizationColorFilter](#daltonizationcolorfilter)&gt;| 是 | 是 | 表示颜色滤镜功能配置。 |
| contentTimeout | [Config](#config)\<number>| 是 | 是 | 表示内容显示建议时长配置。取值 0~5000，单位为毫秒。 |
| animationOff | [Config](#config)\<boolean>| 是 | 是 | 表示关闭动画功能启用状态。 |
| brightnessDiscount | [Config](#config)\<number>| 是 | 是 | 表示亮度折扣系统配置。取值 0~1.0。 |
| mouseKey | [Config](#config)\<boolean>| 是 | 是 | 表示鼠标键功能启用状态。 |
| mouseAutoClick | [Config](#config)\<number>| 是 | 是 | 表示鼠标自动点击功能启用状态。取值 0~5000，单位为毫秒。 |
| shortkey | [Config](#config)\<boolean>| 是 | 是 | 表示辅助扩展快捷键功能启用状态。 |
| shortkeyTarget | [Config](#config)\<string>| 是 | 是 | 表示辅助扩展快捷键的目标配置。取值为辅助应用的名称，格式为：'bundleName/abilityName'。 |
| captions | [Config](#config)\<boolean>| 是 | 是 | 表示辅助字幕功能启用状态。 |
| captionsStyle | [Config](#config)\<[accessibility.CaptionsStyle](js-apis-accessibility.md#captionsstyle8)>| 是 | 是 | 表示辅助字幕的配置。 |

## enableAbility

enableAbility(name: string, capability: Array&lt;accessibility.Capability&gt;): Promise&lt;void&gt;;

启用辅助扩展，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 辅助应用的名称，格式为：'bundleName/abilityName'。 |
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | 是 | 辅助应用的能力属性。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300001 | Invalid bundle name or ability name.  |
| 9300002 | Target ability already enabled. |

**示例：**

```ts
import accessibility from '@ohos.accessibility';
let name = 'com.ohos.example/axExtension';
let capability : accessibility.Capability[] = ['retrieve'];
try {
    config.enableAbility(name, capability).then(() => {
      console.info('enable ability succeed');
    }).catch((err) => {
      console.error('failed to enable ability, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to enable ability, because ' + JSON.stringify(exception));
};
```

## enableAbility

enableAbility(name: string, capability: Array&lt;accessibility.Capability&gt;, callback: AsyncCallback&lt;void&gt;): void;

启用辅助扩展，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 辅助应用的名称，格式为：'bundleName/abilityName'。 |
| capability | Array&lt;[accessibility.Capability](js-apis-accessibility.md#capability)&gt; | 是 | 辅助应用的能力属性。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300001 | Invalid bundle name or ability name.  |
| 9300002 | Target ability already enabled. |

**示例：**

```ts
import accessibility from '@ohos.accessibility';
let name = 'com.ohos.example/axExtension';
let capability : accessibility.Capability[] = ['retrieve'];
try {
    config.enableAbility(name, capability, (err) => {
        if (err) {
            console.error('failed to enable ability, because ' + JSON.stringify(err));
            return;
        }
        console.info('enable ability succeed');
    });
} catch (exception) {
    console.error('failed to enable ability, because ' + JSON.stringify(exception));
};
```

## disableAbility

disableAbility(name: string): Promise&lt;void&gt;;

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

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300001 | Invalid bundle name or ability name.  |

**示例：**

```ts
let name = 'com.ohos.example/axExtension';
try {
    config.disableAbility(name).then(() => {
      console.info('disable ability succeed');
    }).catch((err) => {
      console.error('failed to disable ability, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to disable ability, because ' + JSON.stringify(exception));
};
```

## disableAbility

disableAbility(name: string, callback: AsyncCallback&lt;void&gt;): void;

关闭辅助扩展，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 辅助应用的名称，格式为：'bundleName/abilityName'。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[无障碍子系统错误码](../errorcodes/errorcode-accessibility.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------- |
| 9300001 | Invalid bundle name or ability name.  |

**示例：**

```ts
let name = 'com.ohos.example/axExtension';
try {
    config.disableAbility(name, (err, data) => {
        if (err) {
            console.error('failed to enable ability, because ' + JSON.stringify(err));
            return;
        }
        console.info('disable succeed');
    });
} catch (exception) {
    console.error('failed to enable ability, because ' + JSON.stringify(exception));
};
```

## on('enabledAccessibilityExtensionListChange')

on(type: 'enabledAccessibilityExtensionListChange', callback: Callback&lt;void&gt;): void;

添加启用的辅助扩展的列表变化监听，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 参数固定为enabledAccessibilityExtensionListChange，监听启用的辅助扩展的列表变化。 |
| callback | Callback&lt;void&gt; | 是 | 回调函数，在启用的辅助扩展的列表变化时通过此函数进行通知。 |

**示例：**

```ts
try {
    config.on('enabledAccessibilityExtensionListChange', () => {
        console.info('subscribe enabled accessibility extension list change state success');
    });
} catch (exception) {
    console.error('failed to subscribe enabled accessibility extension list change state, because ' +
    JSON.stringify(exception));
};
```

## off('enabledAccessibilityExtensionListChange')

off(type: 'enabledAccessibilityExtensionListChange', callback?: Callback&lt;void&gt;): void;

取消启用的辅助扩展的列表变化监听，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type |  string | 是 | 参数固定为enabledAccessibilityExtensionListChange，监听启用的辅助扩展的列表变化。 |
| callback | Callback&lt;void&gt; | 否 | 要取消的监听回调函数。 |

**示例：**

```ts
try {
    config.off('enabledAccessibilityExtensionListChange', () => {
        console.info('Unsubscribe enabled accessibility extension list change state success');
    });
} catch (exception) {
    console.error('failed to Unsubscribe enabled accessibility extension list change state, because ' +
    JSON.stringify(exception));
};
```

## Config

用于属性的设置、获取与监听。

### set

set(value: T): Promise&lt;void&gt;;

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

**示例：**

```ts
let value = true;
try {
    config.highContrastText.set(value).then(() => {
        console.info('set highContrastText succeed');
    }).catch((err) => {
        console.error('failed to set highContrastText, because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to set config, because ' + JSON.stringify(exception));
};
```

### set

set(value: T, callback: AsyncCallback&lt;void&gt;): void;

设置属性，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 设置的属性值。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

```ts
let value = true;
try {
    config.highContrastText.set(value, (err, data) => {
        if (err) {
            console.error('failed to set highContrastText, because ' + JSON.stringify(err));
            return;
        }
        console.info('set highContrastText succeed');
    });
} catch (exception) {
    console.error('failed to set config, because ' + JSON.stringify(exception));
};
```

### get

get(): Promise&lt;T&gt;;

获取属性，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;T&gt; | Promise对象，返回对应属性值。 |

**示例：**

```ts
let value;
config.highContrastText.get().then((data) => {
    value = data;
    console.info('get highContrastText success');
}).catch((err) => {
    console.error('failed to get highContrastText, because ' + JSON.stringify(err));
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

**示例：**

```ts
let value;
config.highContrastText.get((err, data) => {
    if (err) {
        console.error('failed to get highContrastText, because ' + JSON.stringify(err));
        return;
    }
    value = data;
    console.info('get highContrastText success');
});
```

### on

on(callback: Callback&lt;T&gt;): void;

添加属性变化监听，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | 是 | 回调函数，在属性变化时通过此函数进行通知。 |

**示例：**

```ts
try {
    config.highContrastText.on((data) => {
        console.info('subscribe highContrastText success, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed subscribe highContrastText, because ' + JSON.stringify(exception));
}
```

### off

off(callback?: Callback&lt;T&gt;): void;

取消属性变化监听，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | Callback&lt;T&gt; | 否 | 要取消的监听回调函数。 |

**示例：**

```ts
config.highContrastText.off((data) => {
    console.info('Unsubscribe highContrastText success, result: ' + JSON.stringify(data));
});
```

## DaltonizationColorFilter

用于不同弱视类型的校正颜色滤镜。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| Normal | 表示正常类型。 |
| Protanomaly | 表示红色弱视类型。 |
| Deuteranomaly | 表示绿色弱视类型。 |
| Tritanomaly  | 表示蓝色弱视类型。 |
