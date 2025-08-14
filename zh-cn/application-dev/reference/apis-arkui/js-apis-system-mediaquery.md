# @system.mediaquery (媒体查询)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zju_ljz-->
<!--SE: @lanshouren-->
<!--TSE: @liuli0427-->

提供根据不同媒体类型定义不同的样式。


> **说明：**
>
> - 从API Version 7 开始，该接口不再维护，推荐使用新接口[`@ohos.mediaquery`](js-apis-mediaquery.md)。
> - 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块


```ts
import mediaquery from '@system.mediaquery';
```


## mediaquery.matchMedia

matchMedia(condition: string): MediaQueryList

根据媒体查询条件，创建MediaQueryList对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名       | 类型     | 必填   | 说明       |
| --------- | ------ | ---- | -------- |
| condition | string | 是    | 用于查询的条件。 |

**返回值：**

| 参数类型           | 说明                                       |
| -------------- | ---------------------------------------- |
| MediaQueryList | 表示创建MediaQueryList对象的属性，详情见下表 MediaQueryList说明。 |

**示例：**

```ts
let mMediaQueryList = mediaquery.matchMedia('(max-width: 466)');    
```

## MediaQueryEvent

定义MediaQuery事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型    | 必填   | 说明    |
| ------- | ------- | ---- | ----- |
| matches | boolean | 是    | 匹配结果。true表示满足查询条件，false表示不满足查询条件。 |

## MediaQueryList

定义MediaQuery列表信息。

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型    | 必填   | 说明                |
| ------- | ------- | ---- | ----------------- |
| media   | string  | 否    | 序列化媒体查询条件，该参数为只读。 |
| matches | boolean | 是    | 匹配结果。 true表示满足查询条件，false表示不满足查询条件。            |

### onchange

onchange?: (matches: boolean) => void

matches状态变化时的执行函数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型      | 必填   | 说明             |
| ------- | ------- | ---- | -------------- |
| matches | boolean | 是    | matches状态变化时值。true表示满足查询条件，false表示不满足查询条件。 |


### MediaQueryList.addListener

addListener(callback: (event: MediaQueryEvent) => void): void

给MediaQueryList添加回调函数，回调函数应在onShow生命周期之前添加，即需要在onInit或onReady生命周期里添加。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                               | 必填   | 说明             |
| -------- | -------------------------------- | ---- | -------------- |
| callback | (event: MediaQueryEvent) => void | 是    | 匹配条件发生变化的响应函数。 |

**示例：**

```ts
import mediaquery, { MediaQueryEvent } from '@system.mediaquery';
let mMediaQueryList = mediaquery.matchMedia('(max-width: 466)');

function maxWidthMatch(e: MediaQueryEvent): void {
  if(e.matches){
    // do something
  }
}
mMediaQueryList.addListener(maxWidthMatch);
```


### MediaQueryList.removeListener

removeListener(callback: (event: MediaQueryEvent) => void): void

移除MediaQueryList中的回调函数。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名      | 类型                                | 必填   | 说明             |
| -------- | --------------------------------- | ---- | -------------- |
| callback | (event: MediaQueryEvent) => void) | 是    | 匹配条件发生变化的响应函数。 |

**示例：**

```ts
import mediaquery, { MediaQueryEvent } from '@system.mediaquery';
let mMediaQueryList = mediaquery.matchMedia('(max-width: 466)');

function maxWidthMatch(e: MediaQueryEvent): void {
  if(e.matches){
    // do something
  }
}
mMediaQueryList.removeListener(maxWidthMatch);
```