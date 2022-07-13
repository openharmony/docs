# 辅助功能

本模块提供辅助功能查询能力，包括获取辅助应用列表、辅助应用启用状态、无障碍字幕配置等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从 API version 7 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```typescript
import accessibility from '@ohos.accessibility';
```

## AbilityState

辅助应用状态类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| enable | 辅助应用已启用。 |
| disable | 辅助应用已禁用。 |
| install | 辅助应用已安装。 |

## AbilityType

无障碍辅助应用类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

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

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| id | number | 是 | 否 | ability&nbsp;id。 |
| name | string | 是 | 否 | ability 名。 |
| bundleName | string | 是 | 否 | 包名。 |
| targetBundleNames<sup>9+</sup> | Array&lt;string&gt; | 是 | 否 | 关注的目标包名。 |
| abilityTypes | Array&lt;[AbilityType](#abilitytype)&gt; | 是 | 否 | 辅助应用类型。 |
| capabilities | Array&lt;[Capability](#capability)&gt; | 是 | 否 | 辅助应用能力列表。 |
| description | string | 是 | 否 | 辅助应用描述。 |
| eventTypes | Array&lt;[EventType](#eventtype)&gt; | 是 | 否 | 辅助应用关注的无障碍事件列表。 |

## Action

应用所支持的目标动作。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

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

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| retrieve | 具有检索窗口内容的能力。 |
| touchGuide | 具有触摸探索模式的能力。 |
| keyEventObserver | 具有过滤按键事件的能力。 |
| zoom | 具有控制显示放大的能力。 |
| gesture | 具有执行手势动作的能力。 |

## CaptionsFontEdgeType<sup>8+</sup>

字幕字体边缘类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Hearing

| 名称 | 描述 |
| -------- | -------- |
| none | 无效果。 |
| raised | 凸起效果。 |
| depressed | 凹陷效果。 |
| uniform | 轮廓效果。 |
| dropShadow | 阴影效果。 |

## CaptionsFontFamily<sup>8+</sup>

字幕字体。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Hearing

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

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Hearing

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| fontFamily | [CaptionsFontFamily](#captionsfontfamily8) | 是 | 否 | 描述字幕字体。 |
| fontScale | number | 是 | 否 | 描述字幕字体缩放系数。 |
| fontColor | number \| string | 是 | 否 | 描述字幕字体颜色。 |
| fontEdgeType | [CaptionsFontEdgeType](#captionsfontedgetype8) | 是 | 否 | 描述字幕字体边缘。 |
| backgroundColor | number \| string | 是 | 否 | 描述字幕背景颜色。 |
| windowColor | number \| string | 是 | 否 | 描述字幕窗口颜色。 |

## CaptionsManager<sup>8+</sup>

字幕配置。

### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| enabled | boolean | 是 | 否 | 表示是否启用字幕配置。 |
| style | [CaptionsStyle](#captionsstyle8) | 是 | 否 | 表示字幕风格。 |

### 方法

下列 API 示例中都需要使用 [accessibility.getCaptionsManager()](#accessibilitygetcaptionsmanager8) 获取 captionsManager 实例，再通过此实例调用对应的方法。

#### on('enableChange')

on(type: 'enableChange', callback: Callback&lt;boolean&gt;): void;

注册字幕配置启用的监听函数。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Hearing

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 监听字幕配置启用状态。 |
  | callback | Callback&lt;boolean&gt; | 是 | 回调函数，在启用状态变化时将状态通过此函数进行通知。 |

- 示例

  ```typescript
  captionsManager.on('enableChange',(data) => {
      console.info('success data:subscribeStateObserver : ' + JSON.stringify(data))
  })
  ```

#### on('styleChange')

on(type: 'styleChange', callback: Callback&lt;CaptionsStyle&gt;): void;

注册字幕风格变化的监听函数。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Hearing

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 监听字幕风格变化。 |
  | callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | 是 | 回调函数，在字幕风格变化时通过此函数进行通知。 |

- 示例

  ```typescript
  captionsManager.on('styleChange',(data) => {
      console.info('success data:subscribeStateObserver : ' + JSON.stringify(data))
  })
  ```
  
#### off('enableChange')

off(type: 'enableChange', callback?: Callback&lt;boolean&gt;): void;

移除字幕配置启用的监听函数。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Hearing

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 监听字幕配置启用状态。 |
  | callback | Callback&lt;boolean&gt; | 否 | 回调函数，在启用状态变化时将状态通过此函数进行通知。 |

- 示例

  ```typescript
  captionsManager.off('enableChange')
  ```

#### off('styleChange')

off(type: 'styleChange', callback?: Callback&lt;CaptionsStyle&gt;): void;

移除字幕风格变化的监听函数。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Hearing

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 字幕风格变化。 |
  | callback | Callback&lt;[CaptionsStyle](#captionsstyle8)&gt; | 否 | 回调函数，在字幕风格变化时通过此函数进行通知。 |

- 示例

  ```typescript
  captionsManager.off('styleChange')
  ```

## EventInfo

界面变更事件。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
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

### 方法

#### constructor

constructor(jsonObject)

构造函数。

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | jsonObject | string | 是 | 创建对象所需要的 JSON 格式字符串。 |

- 示例

  ```typescript
  let eventInfo = new accessibility.EventInfo({"type":"click","bundleName":"com.example.MyApplication","triggerAction":"click"})
  ```

## EventType

无障碍事件类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

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

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| char | 以字符为移动粒度遍历节点文本。 |
| word | 以词为移动粒度遍历节点文本。 |
| line | 以行为移动粒度遍历节点文本。 |
| page | 以页为移动粒度遍历节点文本。 |
| paragraph | 以段落为移动粒度遍历节点文本。 |

## WindowUpdateType

窗口变化类型。

**系统能力**：以下各项对应的系统能力均为 SystemCapability.Barrierfree.Accessibility.Core

| 名称 | 描述 |
| -------- | -------- |
| add | 添加窗口的窗口变化事件。 |
| remove | 一个窗口被删除的窗口变化事件。 |
| bounds | 窗口边界已更改的窗口变化事件。 |
| active | 窗口变为活动或不活动的窗口变化事件。 |
| focus | 窗口焦点发生变化的窗口变化事件。 |

## accessibility.getAbilityLists

getAbilityLists(abilityType: AbilityType, stateType: AbilityState): Promise&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;

查询辅助应用列表。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Core

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | abilityType | [AbilityType](#abilitytype) | 是 | 辅助应用的类型。 |
  | stateType | [AbilityState](#abilitystate) | 是 | 辅助应用的状态。 |

- 返回值：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | 返回辅助应用信息列表。 |

- 示例

  ```typescript
  accessibility.getAbilityLists("spoken", "enable")
      .then((data) => {
          console.info('success data:getAbilityList1 : ' + JSON.stringify(data));
          for (let item of data) {
              console.info(item.id);
              console.info(item.name);
              console.info(item.description);
              console.info(item.abilityTypes);
              console.info(item.eventTypes);
              console.info(item.capabilities);
              console.info(item.packageName);
              console.info(item.filterBundleNames);
              console.info(item.bundleName);
          }
      }).catch((error) => {
          console.error('failed to  getAbilityList1 because ' + JSON.stringify(error));
      })
  ```

## accessibility.getAbilityLists

getAbilityLists(abilityType: AbilityType, stateType: AbilityState,callback: AsyncCallback&lt;Array&lt;AccessibilityAbilityInfo&gt;&gt;): void

查询辅助应用列表。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Core

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | abilityType | [AbilityType](#abilitytype) | 是 | 辅助应用的类型。 |
  | stateType | [AbilityState](#abilitystate) | 是 | 辅助应用的状态。 |
  | callback | AsyncCallback&lt;Array&lt;[AccessibilityAbilityInfo](#accessibilityabilityinfo)&gt;&gt; | 是 | 回调函数，返回辅助应用信息列表。 |

- 示例

  ```typescript
  accessibility.getAbilityLists("visual", "enable", (err, data) => {
      if (err) {
          console.error('failed to getAbilityList2 because ' + JSON.stringify(err));
          return;
      }
      console.info('success data:getAbilityList2 : ' + JSON.stringify(data));
      for (let item of data) {
          console.info(item.id);
          console.info(item.name);
          console.info(item.description);
          console.info(item.abilityTypes);
          console.info(item.eventTypes);
          console.info(item.capabilities);
          console.info(item.packageName);
          console.info(item.filterBundleNames);
          console.info(item.bundleName);
      }
  })
  ```

## accessibility.getCaptionsManager<sup>8+</sup>

getCaptionsManager(): CaptionsManager

获取无障碍字幕配置。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Hearing

- 返回值：

  | 类型 | 说明 |
  | -------- | -------- |
  | [CaptionsManager](#captionsmanager8) | 无障碍字幕配置管理。 |

- 示例

  ```typescript
  captionsManager = accessibility.getCaptionsManager()
  ```

## accessibility.on('accessibilityStateChange' | 'touchGuideStateChange')

on(type: 'accessibilityStateChange' | 'touchGuideStateChange', callback: Callback&lt;boolean&gt;): void

启用辅助应用和触摸浏览功能的状态变化监听。

**系统能力**：以下各项对应的系统能力有所不同，详见下表。

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 监听的事件类型。<br/>-&nbsp;type 为'accessibilityStateChange'时表示监听类型为辅助功能启用状态变化监听；<br/>**系统能力**：SystemCapability.Barrierfree.Accessibility.Core<br/>-&nbsp;type 为'touchGuideStateChange'时表示监听类型为触摸浏览启用状态变化监听。<br/>**系统能力**：SystemCapability.Barrierfree.Accessibility.Vision |
  | callback | Callback&lt;boolean&gt; | 是 | 回调函数，在启用状态变化时将状态通过此函数进行通知。 |

- 示例

  ```typescript
  accessibility.on('accessibilityStateChange',(data) => { 
      console.info('success data:subscribeStateObserver : ' + JSON.stringify(data))
  })
  ```

## accessibility.off('accessibilityStateChange' | 'touchGuideStateChange')

off(type: ‘accessibilityStateChange ’ | ‘touchGuideStateChange’, callback?: Callback&lt;boolean&gt;): void

关闭辅助应用和触摸浏览功能的状态变化监听。

**系统能力**：以下各项对应的系统能力有所不同，详见下表。

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type |  string | 否 | 监听的事件类型。<br/>-&nbsp;type 为'accessibilityStateChange'时表示监听类型为辅助功能启用状态变化监听；<br/>**系统能力**：SystemCapability.Barrierfree.Accessibility.Core<br/>-&nbsp;type 为'touchGuideStateChange'时表示监听类型为触摸浏览启用状态变化监听。<br/>**系统能力**：SystemCapability.Barrierfree.Accessibility.Vision |
  | callback | Callback&lt;boolean&gt; | 否 | 要取消的监听回调函数。 |

- 示例

  ```typescript
  accessibility.off('accessibilityStateChange',(data) => {
      console.info('success data:unSubscribeStateObserver : ' + JSON.stringify(data))
  })
  ```

## accessibility.isOpenAccessibility

isOpenAccessibility(): Promise&lt;boolean&gt;

判断是否启用了辅助功能。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Core

- 返回值：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 如果辅助功能已启用，则返回 true；否则返回 false。 |

- 示例

  ```typescript
  accessibility.isOpenAccessibility()
      .then((data) => {
          console.info('success data:isOpenAccessibility : ' + JSON.stringify(data))
      }).catch((error) => {
          console.error('failed to  isOpenAccessibility because ' + JSON.stringify(error));
      })
  ```

## accessibility.isOpenAccessibility

isOpenAccessibility(callback: AsyncCallback&lt;boolean&gt;): void

判断是否启用了辅助功能。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Core

- 参数

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，如果辅助功能已启用，则返回 true；否则返回 false。 |

- 示例

  ```typescript
  accessibility.isOpenAccessibility((err, data) => {
      if (err) {
          console.error('failed to isOpenAccessibility because ' + JSON.stringify(err));
          return;
      }
      console.info('success data:isOpenAccessibility : ' + JSON.stringify(data))
  })
  ```

## accessibility.isOpenTouchGuide

isOpenTouchGuide(): Promise&lt;boolean&gt;

判断触摸浏览模式是否开启。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Core

- 返回值：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 如果触摸浏览模式已开启，则返回 true；否则返回 false。 |

- 示例

  ```typescript
  accessibility.isOpenTouchGuide()
      .then((data) => {
          console.info('success data:isOpenTouchGuide : ' + JSON.stringify(data))
      }).catch((error) => {
          console.error('failed to  isOpenTouchGuide because ' + JSON.stringify(error));
      })
  ```

## accessibility.isOpenTouchGuide

isOpenTouchGuide(callback: AsyncCallback&lt;boolean&gt;): void

判断触摸浏览模式是否开启。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Core

- 参数

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 回调函数，如果触摸浏览模式已开启，则返回 true；否则返回 false。 |

- 示例

  ```typescript
  accessibility.isOpenTouchGuide((err, data) => {
      if (err) {
          console.error('failed to isOpenTouchGuide because ' + JSON.stringify(err));
          return;
      }
      console.info('success data:isOpenTouchGuide : ' + JSON.stringify(data))
  })
  ```

## accessibility.sendEvent

sendEvent(event: EventInfo): Promise&lt;void&gt;

发送无障碍事件。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Core

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | [EventInfo](#eventinfo) | 是 | 无障碍事件对象。 |

- 返回值：

  | 类型 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | 以 Promise 形式返回结果，如果发送无障碍事件成功，则 data 有数据返回；如果发送无障碍事件失败，则 err 有数据返回。 |

- 示例

  ```typescript
  accessibility.sendEvent(this.eventInfo)
      .then((data) => {
          console.info('success data:sendEvent : ' + JSON.stringify(data))
      }).catch((error) => {
          console.error('failed to  sendEvent because ' + JSON.stringify(error));
      })
  ```

## accessibility.sendEvent

sendEvent(event: EventInfo, callback: AsyncCallback&lt;void&gt;): void

发送无障碍事件。

**系统能力**：SystemCapability.Barrierfree.Accessibility.Core

- 参数：

  | 参数名 | 参数类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | event | [EventInfo](#eventinfo) | 是 | 辅助事件对象。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，如果发送无障碍事件成功，则 AsyncCallback 中 data 有数据返回；如果发送无障碍事件失败，则 AsyncCallback 中 err 有数据返回。 |

- 示例

  ```typescript
  accessibility.sendEvent(this.eventInfo,(err, data) => {
      if (err) {
          console.error('failed to sendEvent because ' + JSON.stringify(err));
          return;
      }   
      console.info('success data:sendEvent : ' + JSON.stringify(data))
  })
  ```
