# 屏幕

本模块提供管理屏幕的一些基础能力，包括获取屏幕对象，监听屏幕变化，创建和销毁虚拟屏幕等。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> 本模块接口为系统接口。

## 导入模块

```js
import screen from '@ohos.screen';
```

## screen.getAllScreens

getAllScreens(callback: AsyncCallback&lt;Array&lt;Screen&gt;&gt;): void

获取所有的屏幕，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                   |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Screen](#screen)&gt;&gt; | 是   | 回调函数。返回当前获取的屏幕对象集合。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
let screenClass = null;
screen.getAllScreens((err, data) => {
    if (err.code) {
        console.error('Failed to get all screens. Cause:  ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in getting all screens. Data:' + JSON.stringify(data));
    screenClass = data[0];
});
```

## screen.getAllScreens

getAllScreens(): Promise&lt;Array&lt;Screen&gt;&gt;

获取所有的屏幕，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：** 

| 类型                                          | 说明                                      |
| --------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Screen](#screen)&gt;&gt; | Promise对象。返回当前获取的屏幕对象集合。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
let screenClass = null;
let promise = screen.getAllScreens();
promise.then((data) => {
    screenClass = data[0];
    console.log('Succeeded in getting all screens. Data:'+ JSON.stringify(data));
}).catch((err) => {
    console.log('Failed to get all screens. Cause: ' + JSON.stringify(err));
});
```

## screen.on('connect' | 'disconnect' | 'change')

on(eventType: 'connect' | 'disconnect' | 'change', callback: Callback&lt;number&gt;): void

开启屏幕状态变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型                   | 必填 | 说明                                                         |
| --------- | ---------------------- | ---- | ------------------------------------------------------------ |
| eventType | string                 | 是   | 监听事件。<br/>-eventType为"connect"表示屏幕连接事件。<br/>-eventType为"disconnect"表示断开屏幕连接事件。<br/>-eventType为"change"表示屏幕状态改变事件。 |
| callback  | Callback&lt;number&gt; | 是   | 回调函数。返回屏幕的id。                                     |

**示例：**

```js
try {
    let callback = (data) => {
        console.info('Succeeded in registering the callback for screen changes. Data: ' + JSON.stringify(data))
    };
    screen.on('connect', callback);
} catch (exception) {
    console.error('Failed to register the callback for screen changes. Code: ' + JSON.stringify(exception));
};
```

## screen.off('connect' | 'disconnect' | 'change')

off(eventType: 'connect' | 'disconnect' | 'change', callback?: Callback&lt;number&gt;): void

关闭屏幕状态变化的监听。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型                   | 必填 | 说明                                                         |
| --------- | ---------------------- | ---- | ------------------------------------------------------------ |
| eventType | string                 | 是   | 监听事件。<br/>-eventType为"connect"表示屏幕连接事件。<br/>-eventType为"disconnect"表示断开屏幕连接事件。<br/>-eventType为"change"表示屏幕状态改变事件。 |
| callback  | Callback&lt;number&gt; | 否   | 回调函数。返回屏幕的id。                                     |

**示例：**

```js
try {
    let callback = (data) => {
        console.info('Succeeded in unregistering the callback for screen changes. Data: ' + JSON.stringify(data))
    };
    screen.off('connect', callback);
} catch (exception) {
    console.error('Failed to register the callback for screen changes. Code: ' + JSON.stringify(exception));
};
```

## screen.makeExpand

makeExpand(options:Array&lt;ExpandOption&gt;, callback: AsyncCallback&lt;number&gt;): void

将屏幕设置为扩展模式，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                             |
| -------- | ------------------------------------------ | ---- | -------------------------------- |
| options  | Array&lt;[ExpandOption](#expandoption)&gt; | 是   | 设置扩展屏幕的参数集合。         |
| callback | Callback&lt;number&gt;                     | 是   | 回调函数。返回扩展屏幕的群组id。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
try {
    let groupId = null;
    screen.makeExpand([{screenId: 0, startX: 0, startY: 0}, {screenId: 1, startX: 1080, startY: 0}], (err, data) => {
      if (err.code) {
        console.error('Failed to expand the screen. Code:' + JSON.stringify(err));
        return;
      }
      groupId = data;
      console.info('Succeeded in expanding the screen. Data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to expand the screen. Code: ' + JSON.stringify(exception));
};
```

## screen.makeExpand

makeExpand(options:Array&lt;ExpandOption&gt;): Promise&lt;number&gt;

将屏幕设置为扩展模式，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                       | 必填 | 说明                     |
| ------- | ------------------------------------------ | ---- | ------------------------ |
| options | Array&lt;[ExpandOption](#expandoption)&gt; | 是   | 设置扩展屏幕的参数集合。 |

**返回值：**

| 类型                  | 说明                                |
| --------------------- | ----------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回扩展屏幕的群组id。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
try {
    screen.makeExpand([{screenId: 0, startX: 0, startY: 0}, {screenId: 1, startX: 1080, startY: 0}]).then((data) => {
      console.info('Succeeded in expanding the screen. Data: ' + JSON.stringify(data));
    }).catch((err) => {
      console.error('Failed to expand the screen. Code:' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to expand the screen. Code: ' + JSON.stringify(exception));
};
```

## screen.makeMirror

makeMirror(mainScreen:number, mirrorScreen:Array&lt;number&gt;, callback: AsyncCallback&lt;number&gt;): void

将屏幕设置为镜像模式，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                        | 必填 | 说明              |
| ------------ | --------------------------- | ---- |-----------------|
| mainScreen   | number                      | 是   | 主屏幕id。          |
| mirrorScreen | Array&lt;number&gt;         | 是   | 镜像屏幕id集合。       |
| callback     | AsyncCallback&lt;number&gt; | 是   | 回调函数。返回镜像屏幕的群组id。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
let mainScreenId = 0;
let mirrorScreenIds = [1, 2, 3];
try {
    screen.makeMirror(mainScreenId, mirrorScreenIds, (err, data) => {
      if (err.code) {
        console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in setting screen mirroring. Data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(exception));
};
```

## screen.makeMirror

makeMirror(mainScreen:number, mirrorScreen:Array&lt;number&gt;): Promise&lt;number&gt;

将屏幕设置为镜像模式，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                | 必填 | 说明        |
| ------------ | ------------------- | ---- |-----------|
| mainScreen   | number              | 是   | 主屏幕id。    |
| mirrorScreen | Array&lt;number&gt; | 是   | 镜像屏幕id集合。 |

**返回值：**

| 类型                  | 说明                                |
| --------------------- | ----------------------------------- |
| Promise&lt;number&gt; | Promise对象。返回镜像屏幕的群组id。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
let mainScreenId = 0;
let mirrorScreenIds = [1, 2, 3];
try {
    screen.makeMirror(mainScreenId, mirrorScreenIds).then((data) => {
      console.info('Succeeded in setting screen mirroring. Data: ' + JSON.stringify(data));
    }).catch((err) => {
      console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(exception));
};
```

## screen.createVirtualScreen

createVirtualScreen(options:VirtualScreenOption, callback: AsyncCallback&lt;Screen&gt;): void

创建虚拟屏幕，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限**：ohos.permission.CAPTURE_SCREEN，如果VirtualScreenOption.surfaceId有效，此权限是必需的。仅系统应用可用。

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                               |
| -------- | ------------------------------------------- | ---- | ---------------------------------- |
| options  | [VirtualScreenOption](#virtualscreenoption) | 是   | 用于创建虚拟屏幕的参数。           |
| callback | AsyncCallback&lt;[Screen](#screen)&gt;      | 是   | 回调函数，返回创建的虚拟屏幕对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
let screenClass = null;
try {
    screen.createVirtualScreen({
      name: 'screen01',
      width: 1080,
      height: 2340,
      density: 2,
      surfaceId: ''
    }, (err, data) => {
      if (err.code) {
        console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));
        return;
      }
      screenClass = data;
      console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.createVirtualScreen

createVirtualScreen(options:VirtualScreenOption): Promise&lt;Screen&gt;

创建虚拟屏幕，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限**：ohos.permission.CAPTURE_SCREEN，如果VirtualScreenOption.surfaceId有效，此权限是必需的。仅系统应用可用。

**参数：** 

| 参数名  | 类型                                        | 必填 | 说明                     |
| ------- | ------------------------------------------- | ---- | ------------------------ |
| options | [VirtualScreenOption](#virtualscreenoption) | 是   | 用于创建虚拟屏幕的参数。 |

**返回值：**

| 类型                             | 说明                                  |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Screen](#screen)&gt; | Promise对象。返回创建的虚拟屏幕对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
let screenClass = null;
try {
    screen.createVirtualScreen({
      name: 'screen01',
      width: 1080,
      height: 2340,
      density: 2,
      surfaceId: ''
    }).then((data) => {
      screenClass = data;
      console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));
    }).catch((err) => {
      console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.destroyVirtualScreen

destroyVirtualScreen(screenId:number, callback: AsyncCallback&lt;void&gt;): void

销毁虚拟屏幕，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| screenId | number                    | 是   | 屏幕的id。                                                   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当销毁虚拟屏幕成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------- |
| 1400002 | Unauthorized operation. |

**示例：**

```js
let screenId = 1;
try {
    screen.destroyVirtualScreen(screenId, (err,data) => {
      if (err.code) {
        console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in destroying the virtual screen.');
    });
} catch (exception) {
    console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.destroyVirtualScreen

destroyVirtualScreen(screenId:number): Promise&lt;void&gt;

销毁虚拟屏幕，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| screenId | number | 是   | 屏幕的id。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------- |
| 1400002 | Unauthorized operation. |

**示例：**

```js
let screenId = 1;
try {
    screen.destroyVirtualScreen(screenId).then((data) => {
      console.info('Succeeded in destroying the virtual screen.');
    }).catch((err) => {
      console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.setVirtualScreenSurface

setVirtualScreenSurface(screenId:number, surfaceId: string, callback: AsyncCallback&lt;void&gt;): void

设置虚拟屏幕的surface，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限**：ohos.permission.CAPTURE_SCREEN，仅系统应用可用。

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| screenId  | number                    | 是   | 屏幕的id。                                                   |
| surfaceId | string                    | 是   | surface的id。                                                |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。当设置虚拟屏幕surface成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
let screenId = 1;
let surfaceId = '2048';
try {
  screen.setVirtualScreenSurface(screenId, surfaceId, (err,data) => {
    if (err.code) {
      console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(err));
      return;
    }
    console.info('Succeeded in setting the surface for the virtual screen.');
  });
} catch (exception) {
    console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.setVirtualScreenSurface

setVirtualScreenSurface(screenId:number, surfaceId: string): Promise&lt;void&gt;

设置虚拟屏幕的surface，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限**：ohos.permission.CAPTURE_SCREEN，仅系统应用可用。

**参数：**

| 参数名    | 类型   | 必填 | 说明          |
| --------- | ------ | ---- | ------------- |
| screenId  | number | 是   | 屏幕的id。    |
| surfaceId | string | 是   | surface的id。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 1400001 | Invalid display or screen. |

**示例：**

```js
let screenId = 1;
let surfaceId = '2048';
try {
    screen.setVirtualScreenSurface(screenId, surfaceId).then((data) => {
      console.info('Succeeded in setting the surface for the virtual screen.');
    }).catch((err) => {
      console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(exception));
};
```

## screen.isScreenRotationLocked

isScreenRotationLocked(): Promise&lt;boolean&gt;

查询当前自动转屏是否锁定，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                   | 说明                                  |
| ---------------------- | ------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前自动转屏处于锁定状态；返回false表示当前自动转屏不处于锁定状态。 |

**示例：**

```js
screen.isScreenRotationLocked().then((isLocked) => {
  console.info('Succeeded in getting the screen rotation lock status. isLocked:'+ JSON.stringify(isLocked));
}).catch((err) => {
  console.error('Failed to get the screen rotation lock status. Cause:' + JSON.stringify(err));
});
```

## screen.isScreenRotationLocked

isScreenRotationLocked(callback: AsyncCallback&lt;boolean&gt;): void

查询当前自动转屏是否锁定，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型                          | 必填 | 说明                                                         |
| --------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前自动转屏处于锁定状态；返回false表示当前自动转屏不处于锁定状态。 |

**示例：**

```js
screen.isScreenRotationLocked((err, isLocked) => {
  if (err.code) {
    console.error('Failed to get the screen rotation lock status. Cause:' + JSON.stringify(err));
    return;
  }
  console.info('Succeeded in getting the screen rotation lock status. isLocked:' + JSON.stringify(isLocked));
});
```

## screen.setScreenRotationLocked

setScreenRotationLocked(isLocked: boolean): Promise&lt;void&gt;

设置自动转屏开关是否锁定，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明          |
| --------- | ------ | ---- | ------------- |
| isLocked  | boolean | 是   | 自动转屏开关是否锁定。true为锁定，false为未锁定. |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let isLocked = false;
try {
    screen.setScreenRotationLocked(isLocked).then((data) => {
      console.info('Succeeded in unlocking auto rotate');
    }).catch((err) => {
      console.error('Failed to unlock auto rotate. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to unlock auto rotate. Code: ' + JSON.stringify(exception));
};
```

## screen.setScreenRotationLocked

setScreenRotationLocked(isLocked: boolean, callback: AsyncCallback&lt;void&gt;): void

设置自动转屏开关是否锁定，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| isLocked  | boolean                   | 是   | 自动转屏开关是否锁定。true为锁定，false为未锁定.                 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。当设置自动转屏是否锁定成功，err为undefined，否则为错误对象。 |

**示例：**

```js
let isLocked = false;
try {
    screen.setScreenRotationLocked(isLocked, (err, data) => {
      if (err.code) {
        console.error('Failed to unlock auto rotate. Cause:' + JSON.stringify(err));
        return;
      }
      console.info('Succeeded in unlocking auto rotate.');
    });
} catch (exception) {
    console.error('Failed to unlock auto rotate. Code: ' + JSON.stringify(exception));
};
```

## ExpandOption

扩展屏幕的参数。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称     | 参数类型 | 可读 | 可写 | 说明                |
| -------- | -------- | ---- | ---- | ------------------- |
| screenId | number   | 是   | 是   | 屏幕的id。          |
| startX   | number   | 是   | 是   | 屏幕的起始X轴坐标。 |
| startY   | number   | 是   | 是   | 屏幕的起始Y轴坐标。 |

## VirtualScreenOption

创建虚拟屏幕的参数。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称      | 参数类型 | 可读 | 可写 | 说明                      |
| --------- | -------- | ---- | ---- | ------------------------- |
| name      | string   | 是   | 是   | 指定虚拟屏幕的名称。      |
| width     | number   | 是   | 是   | 指定虚拟屏幕的宽度。      |
| height    | number   | 是   | 是   | 指定虚拟屏幕的高度。      |
| density   | number   | 是   | 是   | 指定虚拟屏幕的密度。      |
| surfaceId | string   | 是   | 是   | 指定虚拟屏幕的surfaceId。 |

## Screen

屏幕实例。

下列API示例中都需先使用[getAllScreens()](#screengetallscreens)、[createVirtualScreen()](#screencreatevirtualscreen)中的任一方法获取到Screen实例，再通过此实例调用对应方法。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称              | 参数类型                                       | 可读 | 可写 | 说明                   |
| ----------------- | ---------------------------------------------- | ---- | ---- | ---------------------- |
| id                | number                                         | 是   | 否   | 屏幕的id。             |
| parent            | number                                         | 是   | 否   | 屏幕所属群组的id。     |
| supportedModeInfo | Array&lt;[ScreenModeInfo](#screenmodeinfo)&gt; | 是   | 否   | 屏幕支持的模式集合。   |
| activeModeIndex   | number                                         | 是   | 否   | 当前屏幕所处模式索引。 |
| orientation       | [Orientation](#orientation)                     | 是   | 否   | 屏幕方向。             |

### setOrientation

setOrientation(orientation: Orientation, callback: AsyncCallback&lt;void&gt;): void

设置屏幕方向，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名      | 类型                        | 必填 | 说明                                                         |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| orientation | [Orientation](#orientation) | 是   | 屏幕方向。                                                   |
| callback    | AsyncCallback&lt;void&gt;   | 是   | 回调函数。当设置屏幕方向成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```js
try {
    screenClass.setOrientation(screen.Orientation.VERTICAL, (err, data) => {
        if (err.code) {
            console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting the vertical orientation. data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(exception));
};
```

### setOrientation

setOrientation(orientation: Orientation): Promise&lt;void&gt;

设置屏幕方向，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名      | 类型                        | 必填 | 说明       |
| ----------- | --------------------------- | ---- | ---------- |
| orientation | [Orientation](#orientation) | 是   | 屏幕方向。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```js
try {
    let promise = screenClass.setOrientation(screen.Orientation.VERTICAL);
    promise.then((data) => {
        console.info('Succeeded in setting the vertical orientation. Data: ' + JSON.stringify(data));
    }).catch((err) => {
        console.error('Failed to set the vertical orientation. Cause: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(exception));
};
```

### setScreenActiveMode

setScreenActiveMode(modeIndex: number, callback: AsyncCallback&lt;void&gt;): void

设置屏幕当前显示模式，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| modeIndex | number                    | 是   | 模式索引。                                                   |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。当设置屏幕当前显示模式成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```js
let modeIndex = 0;
try {
    screenClass.setScreenActiveMode(modeIndex, (err, data) => {
        if (err.code) {
            console.error('Failed to set screen active mode 0. Code: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeeded in setting screen active mode 0. data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to set screen active mode 0. Code: ' + JSON.stringify(exception));
};
```

### setScreenActiveMode

setScreenActiveMode(modeIndex: number): Promise&lt;void&gt;

设置屏幕当前显示模式，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名    | 类型   | 必填 | 说明       |
| --------- | ------ | ---- | ---------- |
| modeIndex | number | 是   | 模式索引。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```js
let modeIndex = 0;
try {
    let promise = screenClass.setScreenActiveMode(modeIndex);
      promise.then((data) => {
          console.info('Succeeded in setting screen active mode 0. Data: ' + JSON.stringify(data));
      }).catch((err) => {
          console.error('Failed to set screen active mode 0. Code: ' + JSON.stringify(err));
      });
} catch (exception) {
    console.error('Failed to set screen active mode 0. Code: ' + JSON.stringify(exception));
};
```

### setDensityDpi

setDensityDpi(densityDpi: number, callback: AsyncCallback&lt;void&gt;): void;

设置屏幕的像素密度，使用callback异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名     | 类型                      | 必填 | 说明                                                         |
| ---------- | ------------------------- | ---- | ------------------------------------------------------------ |
| densityDpi | number                    | 是   | 像素密度。支持的输入范围为80-640。                           |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。当设置屏幕的像素密度成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```js
let densityDpi = 320;
try {
    screenClass.setDensityDpi(densityDpi, (err, data) => {
        if (err.code) {
            console.error('Failed to set the pixel density of the screen to 320. Code: ' + JSON.stringify(err));
            return;
        }
        console.info('Succeed in setting the pixel density of the screen to 320. data: ' + JSON.stringify(data));
    });
} catch (exception) {
    console.error('Failed to set the pixel density of the screen to 320. Code: ' + JSON.stringify(exception));
};
```

### setDensityDpi

setDensityDpi(densityDpi: number): Promise&lt;void&gt;

设置屏幕的像素密度，使用Promise异步回调。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 参数名     | 类型   | 必填 | 说明                               |
| ---------- | ------ | ---- | ---------------------------------- |
| densityDpi | number | 是   | 像素密度。支持的输入范围为80-640。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[屏幕错误码](../errorcodes/errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 1400003 | This display manager service works abnormally. |

**示例：**

```js
let densityDpi = 320;
try {
    let promise = screenClass.setDensityDpi(densityDpi);
    promise.then((data) => {
        console.info('Succeeded in setting the pixel density of the screen to 320. Data: ' + JSON.stringify(data));
    }).catch((err) => {
        console.error('Failed to set the pixel density of the screen to 320. Code: ' + JSON.stringify(err));
    });
} catch (exception) {
    console.error('Failed to set the pixel density of the screen to 320. Code: ' + JSON.stringify(exception));
};
```

## Orientation

屏幕方向枚举。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称               | 值   | 说明                             |
| ------------------ | ---- | -------------------------------- |
| UNSPECIFIED        | 0    | 表示未指定屏幕方向，由系统指定。 |
| VERTICAL           | 1    | 表示指定屏幕为垂直方向。         |
| HORIZONTAL         | 2    | 表示指定屏幕为水平方向。         |
| REVERSE_VERTICAL   | 3    | 表示指定屏幕为反向垂直方向。     |
| REVERSE_HORIZONTAL | 4    | 表示指定屏幕为反向水平方向。     |

## ScreenModeInfo

屏幕显示模式信息。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称        | 参数类型 | 可读 | 可写 | 说明                                               |
| ----------- | -------- | ---- | ---- | -------------------------------------------------- |
| id          | number   | 是   | 是   | 模式id，所支持的模式由具体设备分辨率和刷新率决定。 |
| width       | number   | 是   | 是   | 屏幕的宽度。                                       |
| height      | number   | 是   | 是   | 屏幕的高度。                                       |
| refreshRate | number   | 是   | 是   | 屏幕的刷新率。                                     |