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
