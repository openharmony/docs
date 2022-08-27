# 鼠标指针

鼠标指针管理模块，用于提供鼠标指针相关属性接口。

> **说明**：
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import pointer from '@ohos.multimodalInput.pointer';
```

## pointer.setPointerVisibele

setPointerVisible(visible: boolean, callback: AsyncCallback&lt;void&gt;): void

设置鼠标指针显示或者隐藏，使用callback方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**参数**：

| 参数     | 类型                      | 必填 | 说明                                                                |
| -------- | ------------------------- | ---- | ------------------------------------------------------------------- |
| visible  | boolean                   | 是   | 鼠标指针显示或者隐藏状态，true: 鼠标指针显示; false: 鼠标指针隐藏。 |
| callback | AysncCallback&lt;void&gt; | 是   | 回调函数，异步返回查询结果。                                        |

**示例**：

```js
pointer.setPointerVisible(true, (err, data) => {
    if (err) {
        console.log(`set pointer visible failed. err=${JSON.stringify(err)}`);
        return;
    }
    console.log(`set pointer visible success.`);
);
```

## pointer.setPointerVisible

setPointerVisible(visible: boolean): Promise&lt;void&gt;

设置鼠标指针显示或者隐藏，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**参数**：

| 参数    | 类型    | 必填 | 说明                                                                |
| ------- | ------- | ---- | ------------------------------------------------------------------- |
| visible | boolean | 是   | 鼠标指针显示或者隐藏状态，true: 鼠标指针显示; false: 鼠标指针隐藏。 |

**返回值**：

| 参数                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于异步获取结果。 |

**示例**：

```js
pointer.setPointerVisible(false).then( data => {
        console.log(`set mouse pointer visible success`);
    }, data => {
    console.log(`set mouse pointer visible failed err=${JSON.stringify(data)}`);
});
```

## pointer.isPointerVisible

isPointerVisible(callback: AsyncCallback&lt;boolean&gt;): void

获取鼠标指针显示或隐藏状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**参数**：

| 参数     | 类型                         | 必填 | 说明                         |
| -------- | ---------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，异步返回查询结果。 |

**示例**：

```js
pointer.isPointerVisible((visible)=>{
    console.log("The mouse pointer visible attributes is " + visible);
});
```

## pointer.isPointerVisible

isPointerVisible(): Promise&lt;boolean&gt;

获取鼠标指针显示或隐藏状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**返回值**：

| 参数                   | 说明                            |
| ---------------------- | ------------------------------- |
| Promise&lt;boolean&gt; | Promise实例，用于异步获取结果。 |

**示例**：

```js
pointer.isPointerVisible().then( data => {
    console.log(`isPointerThen success data=${JSON.stringify(data)}`);
});
```

## pointer.setPointerSpeed<sup>9+</sup>

setPointerSpeed(speed: number, callback: AsyncCallback&lt;void&gt;): void;

设置鼠标移动速度，使用callback方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**参数**：

| 参数     | 类型                      | 必填 | 说明                                                                |
| -------- | ------------------------- | ---- | ------------------------------------------------------------------- |
| speed  | number                   | 是   | 鼠标移动速度设置挡位值1-11，最大值：11，最小值：1，标准值：5           |
| callback | AysncCallback&lt;void&gt; | 是   | 回调函数，异步返回查询结果。                                        |

**示例**：

```js
pointer.setPointerSpeed(5, (err, data) => {
    if (err) {
        console.log(`set pointer speed failed. err=${JSON.stringify(err)}`);
        return;
    }
    console.log(`set pointer speed success.`);
);
```

## pointer.setPointerSpeed<sup>9+</sup>

setPointerSpeed(speed: number): Promise&lt;void&gt;

设置鼠标移动速度，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**参数**：

| 参数    | 类型    | 必填 | 说明                                                                |
| ------- | ------- | ---- | ------------------------------------------------------------------- |
| speed | number | 是   | 鼠标移动速度设置挡位值1-11，最大值：11，最小值：1，标准值：5           |

**返回值**：

| 参数                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于异步获取结果。 |

**示例**：

```js
pointer.setPointerSpeed(5).then( data => {
        console.log(`set pointer speed success`);
    }, err => {
    console.log(`set pointer speed failed err=${JSON.stringify(err)}`);
});
```

## pointer.getPointerSpeed<sup>9+</sup>

getPointerSpeed(callback: AsyncCallback&lt;number&gt;): void

获取当前鼠标移动速度，使用callback方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**参数**：

| 参数     | 类型                         | 必填 | 说明                         |
| -------- | ---------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，异步返回查询结果。 |

**示例**：

```js
pointer.getPointerSpeed((speed)=>{
    console.log("The pointer speed is " + speed);
});
```

## pointer.getPointerSpeed<sup>9+</sup>

getPointerSpeed(): Promise&lt;number&gt;

获取当前鼠标移动速度，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**返回值**：

| 参数                   | 说明                            |
| ---------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise实例，用于异步获取结果。 |

**示例**：

```js
pointer.getPointerSpeed().then( data => {
    console.log(`getPointerSpeed success data=${JSON.stringify(data)}`);
});
```

## pointer.getPointerStyle<sup>9+</sup>

getPointerStyle(windowId: number, callback: AsyncCallback&lt;PointerStyle&gt;): void;

获取鼠标样式类型，使用callback方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**参数**：

| 参数     | 类型                                    | 必填   | 说明                              |
| -------- | ---------------------------------------- | ---- | --------------------------------- |
| windowId | number                                   | 是    | 输入设备的窗口id |
| callback | AsyncCallback&lt;[PointerStyle](#pointerstyle9)&gt; | 是 | 回调函数，异步返回查询结果。|

**示例**：

```js
// 示例获取设备的鼠标样式。
pointer.getPointerStyle(windowId, (ret)=>{
    console.log("The mouse pointer style is: " + ret);
});
```

## pointer.getPointerStyle<sup>9+</sup>

getPointerStyle(windowId: number): Promise&lt;PointerStyle&lt;

获取鼠标样式类型，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**参数**：

| 参数     | 说明                              |
| -------- | --------------------------------- |
| Promise&lt;[PointerStyle](#pointerstyle9)&gt; |Promise实例，用于异步获取结果。|


**示例**：

```js
// 示例获取设备的鼠标样式。
pointer.PointerStyle(windowId).then((ret)=>{
    console.log("The mouse pointer style is: " + ret);
});
```

## pointer.setPointerStyle<sup>9+</sup>

setPointerStyle(windowId: number, pointerStyle: PointerStyle, callback: AsyncCallback&lt;void&lt;): void;

设置鼠标的样式类型，使用callback方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**参数**：

| 参数     | 类型                                     | 必填   | 说明                              |
| -------- | ----------------------------------------| ---- | --------------------------------- |
| windowId | number                                  | 是    | 输入设备的窗口id |
| pointerStyle | [PointerStyle](#pointerstyle9)      | 是    | 鼠标样式id |
| callback | AysncCallback&lt;void&gt; | 是   | 回调函数，异步返回查询结果。|

**示例**：

```js
// 示例设置设备的鼠标样式。
pointer.setPointerStyle(windowId, (err, data) => {
    if (err) {
        console.log(`Set mouse pointer style failed. err=${JSON.stringify(err)}`);
        return;
    }
    console.log(`Set mouse pointer style success.`);
});
```
## pointer.setPointerStyle<sup>9+</sup>

setPointerStyle(windowId: number, pointerStyle: PointerStyle): Promise&lt;void&lt;;

设置鼠标的样式类型，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

**参数**：

| 参数     | 类型                                     | 必填   | 说明                              |
| -------- | ---------------------------------------- | ---- | --------------------------------- |
| windowId | number                                   | 是    | 输入设备的窗口id                   |
| pointerStyle | [PointerStyle](#pointerstyle9)       | 是    | 鼠标样式id                         |
| Promise&lt;void&gt; | void | 是    |Promise实例，用于异步获取结果。  |

**示例**：

```js
// 示例设置设备的鼠标样式。
pointer.setPointerStyle(windowId, pointerStyle).then(data => {
        console.log(`Set mouse pointer style success`);
    }, err => {
    console.log(`Set mouse pointer style failed err=${JSON.stringify(data)}`);
});
```
## PointerStyle<sup>9+</sup>

定义鼠标样式类型。

**系统能力**：SystemCapability.MultimodalInput.Input.Pointer

| 名称                  | 参数类型   | 值    | 说明        |
| ------------------- | ------ | ---- | --------- |
| DEFAULT | number | 0    | 默认 |
| EAST | number | 1    | 向东箭头 |
| WEST | number | 2    | 向西箭头 |
| SOUTH | number | 3    | 向南箭头 |
| NORTH | number | 4    | 向北箭头 |
| WEST_EAST | number | 5    | 向西东箭头 |
| NORTH_SOUTH | number | 6    | 向北南箭头 |
| NORTH_EAST | number | 7    | 向东北箭头 |
| NORTH_WEST | number | 8    | 向西北箭头 |
| SOUTH_EAST | number | 9    | 向东南箭头 |
| SOUTH_WEST | number | 10    | 向西南箭头 |
| NORTH_EAST_SOUTH_WEST | number | 11    | 东北西南调整 |
| NORTH_WEST_SOUTH_EAST | number | 12    | 西北东南调整 |
| CROSS | number | 13    | 准确选择 |
| CURSOR_COPY | number | 14    | 拷贝 |
| CURSOR_FORBID | number | 15    | 不可用 |
| COLOR_SUCKER | number | 16    | 滴管 |
| HAND_GRABBING | number | 17    | 并拢的手 |
| HAND_OPEN | number | 18    | 张开的手 |
| HAND_POINTING | number | 19    | 手形指针 |
| HELP | number | 20    | 帮助选择 |
| MOVE | number | 21    | 移动 |
| RESIZE_LEFT_RIGHT | number | 22    | 内部左右调整 |
| RESIZE_UP_DOWN | number | 23    | 内部上下调整 |
| SCREENSHOT_CHOOSE | number | 24    | 截图十字准星 |
| SCREENSHOT_CURSOR | number | 25    | 截图 |
| TEXT_CURSOR | number | 26    | 文本选择 |
| ZOOM_IN | number | 27    | 放大 |
| ZOOM_OUT | number | 28    | 缩小 |
| MIDDLE_BTN_EAST | number | 29    | 向东滚动 |
| MIDDLE_BTN_WEST | number | 30    | 向西滚动 |
| MIDDLE_BTN_SOUTH | number | 31    | 向南滚动 |
| MIDDLE_BTN_NORTH | number | 32    | 向北滚动 |
| MIDDLE_BTN_NORTH_SOUTH | number | 33    | 向北南滚动 |
| MIDDLE_BTN_NORTH_EAST | number | 34    | 向东北滚动 |
| MIDDLE_BTN_NORTH_WEST | number | 35    | 向西北滚动 |
| MIDDLE_BTN_SOUTH_EAST | number | 36    | 向东南滚动 |
| MIDDLE_BTN_SOUTH_WEST | number | 37    | 向西南滚动 |
| MIDDLE_BTN_NORTH_SOUTH_WEST_EAST | number | 38    | 四向锥形移动 |


