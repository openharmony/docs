# @ohos.accessibility (辅助功能)

本模块提供辅助功能查询能力，包括获取辅助应用列表、辅助应用启用状态、无障碍字幕配置等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从 API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import accessibility from '@ohos.accessibility';
```

## AbilityState

辅助应用状态类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| enable | 辅助应用已启用。 |
| disable | 辅助应用已禁用。 |
| install | 辅助应用已安装。 |

## AbilityType

无障碍辅助应用类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| audible | 表示具有听觉反馈。 |
| generic | 表示具有通用反馈。 |
| haptic | 表示具有触觉反馈。 |
| spoken  | 表示具有语音反馈。 |
| visual | 表示具有视觉反馈。 |
| all<sup>9+</sup> | 表示以上所有类别。 |

## AccessibilityAbilityInfo

辅助应用信息。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

### 属性

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| id | string | 是 | 否 | ability&nbsp;id。 |
| name | string | 是 | 否 | ability 名。 |
| bundleName | string | 是 | 否 | 包名。 |
| targetBundleNames<sup>9+</sup> | Array&lt;string&gt; | 是 | 否 | 关注的目标包名。 |
| abilityTypes | Array&lt;[AbilityType](#abilitytype)&gt; | 是 | 否 | 辅助应用类型。 |
| capabilities | Array&lt;[Capability](#capability)&gt; | 是 | 否 | 辅助应用能力列表。 |
| description | string | 是 | 否 | 辅助应用描述。 |
| eventTypes | Array&lt;[EventType](#eventtype)&gt; | 是 | 否 | 辅助应用关注的无障碍事件列表。 |

## Action

应用所支持的目标动作。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| click | 表示点击操作。 |
| longClick | 表示长按操作。 |
| scrollForward | 表示向前滚动操作。 |
| scrollBackward | 表示向后滚动操作。 |
| focus | 表示获得焦点操作。 |
| clearFocus | 表示清除焦点操作。 |
| clearSelection | 表示清除选择操作。 |
| accessibilityFocus | 表示获得无障碍焦点操作。 |
| clearAccessibilityFocus | 表示清除无障碍焦点操作。 |
| cut | 表示剪切操作。 |
| copy | 表示复制操作。 |
| paste | 表示粘贴操作。 |
| select | 表示选择操作。 |
| setText | 表示设置文本操作。 |
| delete | 表示删除操作。 |
| setSelection | 表示选择操作。 |

## Capability

辅助应用能力类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| retrieve | 具有检索窗口内容的能力。 |
| touchGuide | 具有触摸探索模式的能力。 |
| keyEventObserver | 具有过滤按键事件的能力。 |
| zoom | 具有控制显示放大的能力。 |
| gesture | 具有执行手势动作的能力。 |

## CaptionsFontEdgeType<sup>8+</sup>

字幕字体边缘类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Hearing

| 名称 | 描述 |
| -------- | -------- |
| none | 无效果。 |
| raised | 凸起效果。 |
| depressed | 凹陷效果。 |
| uniform | 轮廓效果。 |
| dropShadow | 阴影效果。 |

## CaptionsFontFamily<sup>8+</sup>

字幕字体。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Hearing

| 名称 | 描述 |
| -------- | -------- |
| default | 默认字体。 |
| monospacedSerif | 等宽 Serif 字体。 |
| serif | Serif 字体。 |
| monospacedSansSerif | 等宽 Sans Serif 字体。 |
| sansSerif | Sans Serif 字体。 |
| casual | 非正式字体。 |
| cursive | 手写字体。 |
| smallCapitals | 小型大写字母字体。 |

## CaptionsStyle<sup>8+</sup>

字幕风格。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Hearing

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| fontFamily | [CaptionsFontFamily](#captionsfontfamily8) | 是 | 否 | 描述字幕字体。 |
| fontScale | number | 是 | 否 | 描述字幕字体缩放系数。 |
| fontColor | number \| string | 是 | 否 | 描述字幕字体颜色。 |
| fontEdgeType | [CaptionsFontEdgeType](#captionsfontedgetype8) | 是 | 否 | 描述字幕字体边缘。 |
| backgroundColor | number \| string | 是 | 否 | 描述字幕背景颜色。 |
| windowColor | number \| string | 是 | 否 | 描述字幕窗口颜色。 |

## CaptionsManager<sup>8+</sup>

字幕配置管理，在调用CaptionsManager的方法前，需要先通过 [accessibility.getCaptionsManager()](#accessibilitygetcaptionsmanager8)获取 CaptionsManager实例。

**系统能力**：以下各项对应的系统能力均为SystemCapability.BarrierFree.Accessibility.Hearing

### 属性

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| enabled | boolean | 是 | 否 | 表示是否启用字幕配置。 |
| style | [CaptionsStyle](#captionsstyle8) | 是 | 否 | 表示字幕风格。 |

### on('enableChange')

on(type: 'enableChange', callback: Callback&lt;boolean&gt;): void;

监听字幕配置启用状态变化事件，使用callback异步回调。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听的事件名，固定为‘enableChange’，即字幕配置启用状态变化事件。 |
| callback | Callback&lt;boolean&gt; | 是 | 回调函数，在启用状态变化时将状态通过此函数进行通知。 |

**示例：**

```ts
let captionsManager = accessibility.getCaptionsManager();
try {
    captionsManager.on('enableChange', (data) => {
        console.info('subscribe caption manager enable state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to subscribe caption manager enable state change, because ' + JSON.stringify(exception));
}
```

### on('styleChange')

on(type: 'styleChange', callback: Callback&lt;CaptionsStyle&gt;): void;

监听字幕风格变化事件，使用callback异步回调。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听的事件名，固定为‘styleChange’，即字幕风格变化事件。 |
| callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | 是 | 回调函数，在字幕风格变化时通过此函数进行通知。 |

**示例：**

```ts
let captionStyle;
let captionsManager = accessibility.getCaptionsManager();
try {
    captionsManager.on('styleChange', (data) => {
        captionStyle = data;
        console.info('subscribe caption manager style state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to subscribe caption manager style state change, because ' + JSON.stringify(exception));
}
```
  
### off('enableChange')

off(type: 'enableChange', callback?: Callback&lt;boolean&gt;): void;

取消监听字幕配置启用状态变化事件，使用callback异步回调。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取消监听的事件名，固定为‘enableChange’，即字幕配置启用状态变化事件。 |
| callback | Callback&lt;boolean&gt; | 否 | 回调函数，在字幕配置启用状态变化时将状态通过此函数进行通知。 |

**示例：**

```ts
let captionsManager = accessibility.getCaptionsManager();
try {
    captionsManager.off('enableChange', (data) => {
        console.info('Unsubscribe caption manager enable state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to Unsubscribe caption manager enable state change, because ' + JSON.stringify(exception));
}
```

### off('styleChange')

off(type: 'styleChange', callback?: Callback&lt;CaptionsStyle&gt;): void;

取消字幕风格变化监听事件，使用callback异步回调。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取消监听的事件名，固定为‘styleChange’，即字幕风格变化事件。 |
| callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | 否 | 回调函数，在字幕风格变化时通过此函数进行通知。 |

**示例：**

```ts
let captionStyle;
let captionsManager = accessibility.getCaptionsManager();
try {
    captionsManager.off('styleChange', (data) => {
        captionStyle = data;
        console.info('Unsubscribe caption manager style state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to Unsubscribe caption manager style state change, because ' + JSON.stringify(exception));
}
```

## EventInfo

界面变更事件。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

### 属性

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| type | [EventType](#eventtype) | 是 | 是 | 无障碍事件类型。 |
| windowUpdateType | [WindowUpdateType](#windowupdatetype) | 是 | 是 | 窗口变化类型。 |
| bundleName | string | 是 | 是 | 目标应用名。 |
| componentType | string | 是 | 是 | 事件源组件类型，如按钮、图表。 |
| pageId | number | 是 | 是 | 事件源的页面 ID。 |
| description | string | 是 | 是 | 事件描述。 |
| triggerAction | [Action](#action) | 是 | 是 | 触发事件的 Action。 |
| textMoveUnit | [TextMoveUnit](#textmoveunit) | 是 | 是 | 文本移动粒度。 |
| contents | Array&lt;string&gt; | 是 | 是 | 内容列表。 |
| lastContent | string | 是 | 是 | 最新内容。 |
| beginIndex | number | 是 | 是 | 画面显示条目的开始序号。 |
| currentIndex | number | 是 | 是 | 当前条目序号。 |
| endIndex | number | 是 | 是 | 画面显示条目的结束序号。 |
| itemCount | number | 是 | 是 | 条目总数。 |

### constructor

constructor(jsonObject)

构造函数。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| jsonObject | string | 是 | 创建对象所需要的 JSON 格式字符串。 |

**示例：**

  ```ts
  let eventInfo = new accessibility.EventInfo({
    'type':'click',
    'bundleName':'com.example.MyApplication',
    'triggerAction':'click'
  });
  ```

## EventType

无障碍事件类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| click | 描述点击组件的事件。 |
| longClick | 描述长按组件的事件。 |
| select | 描述选择组件的事件。 |
| focus | 描述组件获得焦点的事件。 |
| textUpdate | 描述组件文本已更改的事件。 |
| hoverEnter | 描述悬停进入组件的事件。 |
| hoverExit | 描述悬停离开组件的事件。 |
| scroll | 描述滚动视图的事件。 |
| textSelectionUpdate | 描述选定文本已更改的事件。 |
| accessibilityFocus | 描述获得无障碍焦点的事件。 |
| accessibilityFocusClear | 描述清除无障碍焦点的事件。 |

## TextMoveUnit

文本无障碍导航移动粒度。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| char | 以字符为移动粒度遍历节点文本。 |
| word | 以词为移动粒度遍历节点文本。 |
| line | 以行为移动粒度遍历节点文本。 |
| page | 以页为移动粒度遍历节点文本。 |
| paragraph | 以段落为移动粒度遍历节点文本。 |

## WindowUpdateType

窗口变化类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.BarrierFree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| add | 添加窗口的窗口变化事件。 |
| remove | 一个窗口被删除的窗口变化事件。 |
| bounds | 窗口边界已更改的窗口变化事件。 |
| active | 窗口变为活动或不活动的窗口变化事件。 |
| focus | 窗口焦点发生变化的窗口变化事件。 |

## accessibility.getAbilityLists<sup>(deprecated)</sup>

getAbilityLists(abilityType: AbilityType, stateType: AbilityState): Promise&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;

查询辅助应用列表，使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。
> 推荐使用[getAccessibilityExtensionList()](#accessibilitygetaccessibilityextensionlist9)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| abilityType | [AbilityType](#abilitytype) | 是 | 辅助应用的类型。 |
| stateType | [AbilityState](#abilitystate) | 是 | 辅助应用的状态。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | Promise对象，返回辅助应用信息列表。 |

**示例：**

```ts
let abilityType = 'spoken';
let abilityState = 'enable';
let abilityList: accessibility.AccessibilityInfo[];
try {
    accessibility.getAbilityLists(abilityType, abilityState).then((data) => {
        for (let item of data) {
            console.info(item.id);
            console.info(item.name);
            console.info(item.description);
            console.info(item.bundleName);
            extensionList.push(item);
        }
        console.info('get accessibility extension list success');
    }).catch((err) => {
        console.error('failed to get accessibility extension list because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to get accessibility extension list because ' + JSON.stringify(exception));
}
```

## accessibility.getAbilityLists<sup>(deprecated)</sup>

getAbilityLists(abilityType: AbilityType, stateType: AbilityState,callback: AsyncCallback&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;): void

查询辅助应用列表，使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。
> 推荐使用[getAccessibilityExtensionList()](#accessibilitygetaccessibilityextensionlist9-1)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| abilityType | [AbilityType](#abilitytype) | 是 | 辅助应用的类型。 |
| stateType | [AbilityState](#abilitystate) | 是 | 辅助应用的状态。 |
| callback | AsyncCallback&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | 是 | 回调函数，返回辅助应用信息列表。 |

**示例：**

```ts
let abilityType = 'spoken';
let abilityState = 'enable';
let abilityList: accessibility.AccessibilityInfo[];
try {
    accessibility.getAbilityLists(abilityType, abilityState, (err, data) => {
        if (err) {
            console.error('failed to get accessibility extension list because ' + JSON.stringify(err));
            return;
        }
        for (let item of data) {
            console.info(item.id);
            console.info(item.name);
            console.info(item.description);
            console.info(item.bundleName);
            abilityList.push(item);
        }
        console.info('get accessibility extension list success');
    }).catch((err) => {
        console.error('failed to get accessibility extension list because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to get accessibility extension list because ' + JSON.stringify(exception));
}
```

## accessibility.getAccessibilityExtensionList<sup>9+</sup>

getAccessibilityExtensionList(abilityType: AbilityType, stateType: AbilityState): Promise&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;

查询辅助应用列表，使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| abilityType | [AbilityType](#abilitytype) | 是 | 辅助应用的类型。 |
| stateType | [AbilityState](#abilitystate) | 是 | 辅助应用的状态。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | Promise对象，返回辅助应用信息列表。 |

**示例：**

```ts
let abilityType : accessibility.AbilityType = 'spoken';
let abilityState : accessibility.AbilityState = 'enable';
let extensionList: accessibility.AccessibilityAbilityInfo[] = [];
try {
    accessibility.getAccessibilityExtensionList(abilityType, abilityState).then((data) => {
        for (let item of data) {
            console.info(item.id);
            console.info(item.name);
            console.info(item.description);
            console.info(item.bundleName);
            extensionList.push(item);
        }
        console.info('get accessibility extension list success');
    }).catch((err) => {
        console.error('failed to get accessibility extension list because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to get accessibility extension list because ' + JSON.stringify(exception));
}
```

## accessibility.getAccessibilityExtensionList<sup>9+</sup>

getAccessibilityExtensionList(abilityType: AbilityType, stateType: AbilityState, callback: AsyncCallback&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;): void

查询辅助应用列表，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| abilityType | [AbilityType](#abilitytype) | 是 | 辅助应用的类型。 |
| stateType | [AbilityState](#abilitystate) | 是 | 辅助应用的状态。 |
| callback | AsyncCallback&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | 是 | 回调函数，返回辅助应用信息列表。 |

**示例：**

```ts
let abilityType : accessibility.AbilityType = 'spoken';
let abilityState : accessibility.AbilityState = 'enable';
let extensionList: accessibility.AccessibilityAbilityInfo[] = [];
try {
    accessibility.getAccessibilityExtensionList(abilityType, abilityState, (err, data) => {
        if (err) {
            console.error('failed to get accessibility extension list because ' + JSON.stringify(err));
            return;
        }
        for (let item of data) {
            console.info(item.id);
            console.info(item.name);
            console.info(item.description);
            console.info(item.bundleName);
            extensionList.push(item);
        }
        console.info('get accessibility extension list success');
    });
} catch (exception) {
    console.error('failed to get accessibility extension list because ' + JSON.stringify(exception));
}
```

## accessibility.getCaptionsManager<sup>8+</sup>

getCaptionsManager(): CaptionsManager

获取无障碍字幕配置管理实例。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Hearing

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [CaptionsManager](#captionsmanager8) | 无障碍字幕配置管理。 |

**示例：**

```ts
let captionsManager = accessibility.getCaptionsManager();
```

## accessibility.on('accessibilityStateChange')

on(type: 'accessibilityStateChange', callback: Callback&lt;boolean&gt;): void

监听辅助应用启用状态变化事件，使用callback异步回调。

**系统能力**：以下各项对应的系统能力有所不同，详见下表。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听的事件名，固定为‘accessibilityStateChange’，即辅助应用启用状态变化事件。 |
| callback | Callback&lt;boolean&gt; | 是 | 回调函数，在辅助应用启用状态变化时将状态通过此函数进行通知。 |

**示例：**

```ts
try {
    accessibility.on('accessibilityStateChange', (data) => {
        console.info('subscribe accessibility state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to subscribe accessibility state change, because ' + JSON.stringify(exception));
}
```

## accessibility.on('touchGuideStateChange')

on(type: 'touchGuideStateChange', callback: Callback&lt;boolean&gt;): void

监听触摸浏览功能启用状态变化事件，使用callback异步回调。

**系统能力**：以下各项对应的系统能力有所不同，详见下表。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 监听的事件名，固定为‘touchGuideStateChange’，即触摸浏览启用状态变化事件。 |
| callback | Callback&lt;boolean&gt; | 是 | 回调函数，在触摸浏览启用状态变化时将状态通过此函数进行通知。 |

**示例：**

```ts
try {
    accessibility.on('touchGuideStateChange', (data) => {
        console.info('subscribe touch guide state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to subscribe touch guide state change, because ' + JSON.stringify(exception));
}
```

## accessibility.off('accessibilityStateChange')

off(type: 'accessibilityStateChange', callback?: Callback&lt;boolean&gt;): void

取消监听辅助应用启用状态变化事件，使用callback异步回调。

**系统能力**：以下各项对应的系统能力有所不同，详见下表。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type |  string | 否 | 取消监听的事件名，固定为‘accessibilityStateChange’，即辅助应用启用状态变化事件。 |
| callback | Callback&lt;boolean&gt; | 否 | 回调函数，在辅助应用启用状态变化时将状态通过此函数进行通知。 |

**示例：**

```ts
try {
    accessibility.off('accessibilityStateChange', (data) => {
        console.info('Unsubscribe accessibility state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to Unsubscribe accessibility state change, because ' + JSON.stringify(exception));
}
```

## accessibility.off('touchGuideStateChange')

off(type: 'touchGuideStateChange', callback?: Callback&lt;boolean&gt;): void

取消监听触摸浏览启用状态变化事件，使用callback异步回调。

**系统能力**：以下各项对应的系统能力有所不同，详见下表。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type |  string | 否 | 取消监听的事件名，固定为‘touchGuideStateChange’，即触摸浏览启用状态变化事件。 |
| callback | Callback&lt;boolean&gt; | 否 | 回调函数，在触摸浏览启用状态变化时将状态通过此函数进行通知。 |

**示例：**

```ts
try {
    accessibility.off('touchGuideStateChange', (data) => {
        console.info('Unsubscribe touch guide state change, result: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('failed to Unsubscribe touch guide state change, because ' + JSON.stringify(exception));
}
```

## accessibility.isOpenAccessibility

isOpenAccessibility(): Promise&lt;boolean&gt;

判断是否启用了辅助功能, 使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象，如果辅助功能已启用，则返回 true；否则返回 false。 |

**示例：**

```ts
accessibility.isOpenAccessibility().then((data) => {
    console.info('success data:isOpenAccessibility : ' + JSON.stringify(data))
}).catch((err) => {
    console.error('failed to  isOpenAccessibility because ' + JSON.stringify(err));
});
```

## accessibility.isOpenAccessibility

isOpenAccessibility(callback: AsyncCallback&lt;boolean&gt;): void

判断是否启用了辅助功能，使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，如果辅助功能已启用，则返回 true；否则返回 false。 |

**示例：**

```ts
accessibility.isOpenAccessibility((err, data) => {
    if (err) {
        console.error('failed to isOpenAccessibility because ' + JSON.stringify(err));
        return;
    }
    console.info('success data:isOpenAccessibility : ' + JSON.stringify(data))
});
```

## accessibility.isOpenTouchGuide

isOpenTouchGuide(): Promise&lt;boolean&gt;

判断触摸浏览模式是否开启, 使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Vision

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise对象，如果触摸浏览模式已开启，则返回 true；否则返回 false。 |

**示例：**

```ts
accessibility.isOpenTouchGuide().then((data) => {
    console.info('success data:isOpenTouchGuide : ' + JSON.stringify(data))
}).catch((err) => {
    console.error('failed to  isOpenTouchGuide because ' + JSON.stringify(err));
});
```

## accessibility.isOpenTouchGuide

isOpenTouchGuide(callback: AsyncCallback&lt;boolean&gt;): void

判断触摸浏览模式是否开启, 使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Vision

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，如果触摸浏览模式已开启，则返回 true；否则返回 false。 |

**示例：**

```ts
accessibility.isOpenTouchGuide((err, data) => {
    if (err) {
        console.error('failed to isOpenTouchGuide because ' + JSON.stringify(err));
        return;
    }
    console.info('success data:isOpenTouchGuide : ' + JSON.stringify(data))
});
  ```

## accessibility.sendEvent<sup>(deprecated)</sup>

sendEvent(event: EventInfo): Promise&lt;void&gt;

发送无障碍事件, 使用Promise异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。
> 推荐使用[sendAccessibilityEvent()](#accessibilitysendaccessibilityevent9)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | [EventInfo](#eventinfo) | 是 | 无障碍事件对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
let eventInfo = new accessibility.EventInfo({
  'type':'click',
  'bundleName':'com.example.MyApplication',
  'triggerAction':'click'
});
accessibility.sendEvent(eventInfo).then(() => {
    console.info('send event success');
}).catch((err) => {
    console.error('failed to sendEvent because ' + JSON.stringify(err));
});
```

## accessibility.sendEvent<sup>(deprecated)</sup>

sendEvent(event: EventInfo, callback: AsyncCallback&lt;void&gt;): void

发送无障碍事件, 使用callback异步回调。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃。
> 推荐使用[sendAccessibilityEvent()](#accessibilitysendaccessibilityevent9-1)。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | [EventInfo](#eventinfo) | 是 | 辅助事件对象。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，如果发送无障碍事件失败，则 AsyncCallback中err有数据返回。 |

**示例：**

```ts
let eventInfo = new accessibility.EventInfo({
  'type':'click',
  'bundleName':'com.example.MyApplication',
  'triggerAction':'click'
});
accessibility.sendEvent(eventInfo, (err, data) => {
    if (err) {
        console.error('failed to sendEvent because ' + JSON.stringify(err));
        return;
    }
    console.info('sendEvent success');
});
```

## accessibility.sendAccessibilityEvent<sup>9+</sup>

sendAccessibilityEvent(event: EventInfo): Promise&lt;void&gt;

发送无障碍事件, 使用Promise异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | [EventInfo](#eventinfo) | 是 | 无障碍事件对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
let eventInfo = new accessibility.EventInfo({
    'type':'click',
    'bundleName':'com.example.MyApplication',
    'triggerAction':'click'
});
try {
    accessibility.sendAccessibilityEvent(eventInfo).then(() => {
        console.info('send event success');
    }).catch((err) => {
        console.error('failed to send event because ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('failed to send event because ' + JSON.stringify(exception));
}
```

## accessibility.sendAccessibilityEvent<sup>9+</sup>

sendAccessibilityEvent(event: EventInfo, callback: AsyncCallback&lt;void&gt;): void

发送无障碍事件, 使用callback异步回调。

**系统能力**：SystemCapability.BarrierFree.Accessibility.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| event | [EventInfo](#eventinfo) | 是 | 辅助事件对象。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，如果发送无障碍事件失败，则 AsyncCallback中err有数据返回。 |

**示例：**

```ts
let eventInfo = new accessibility.EventInfo({
    'type':'click',
    'bundleName':'com.example.MyApplication',
    'triggerAction':'click'
});
try {
    accessibility.sendEvent(eventInfo, (err, data) => {
        if (err) {
            console.error('failed to send event because ' + JSON.stringify(err));
            return;
        }
        console.info('send event success');
    });
} catch (exception) {
    console.error('failed to send event because ' + JSON.stringify(exception));
}
```
