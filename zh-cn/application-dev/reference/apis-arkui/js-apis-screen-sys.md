# @ohos.screen (屏幕)(系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk-->
<!--Designer: @logn; @wulong158-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

本模块提供管理屏幕的一些基础能力，包括获取屏幕对象，监听屏幕变化，创建和销毁虚拟屏幕等。适用于多屏显示管理、投屏应用等场景，可帮助开发者统一管理所有[物理屏](../../displaymanager/display-terminology.md#物理屏)，提升多屏协同体验和显示能力。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> - 本模块接口为系统接口。
> 
> - 针对系统能力SystemCapability.Window.SessionManager，请先使用[canIUse()](../common/js-apis-syscap.md#caniuse)接口判断当前设备是否支持此syscap及对应接口。

## 导入模块

```ts
import { screen } from '@kit.ArkUI';
```

## screen.getAllScreens

getAllScreens(callback: AsyncCallback&lt;Array&lt;Screen&gt;&gt;): void

获取所有的屏幕对象，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                   |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Screen](#screen)&gt;&gt; | 是   | 回调函数。返回当前获取的屏幕对象集合。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenClass: screen.Screen | null = null;
// 获取所有屏幕对象
screen.getAllScreens((err: BusinessError, data: Array<screen.Screen>) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to get all screens. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting all screens. Data: ${JSON.stringify(data)}`);
  if (data.length > 0) {
    screenClass = data[0];
  }
});
```

## screen.getAllScreens

getAllScreens(): Promise&lt;Array&lt;Screen&gt;&gt;

获取所有的屏幕对象，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：** 

| 类型                                          | 说明                                      |
| --------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Screen](#screen)&gt;&gt; | Promise对象。返回当前获取的屏幕对象集合。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenClass: screen.Screen | null = null;
// 获取所有屏幕对象
let promise: Promise<Array<screen.Screen>> = screen.getAllScreens();
promise.then((data: Array<screen.Screen>) => {
  if(data.length > 0){
    screenClass = data[0];
  }
  console.info(`Succeeded in getting all screens. Data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get all screens. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.getAllScreens

getAllScreens(callback: AsyncCallback&lt;Array&lt;Screen&gt;&gt;, isNeedUnused?: boolean): void

获取所有的屏幕对象，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                   |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[Screen](#screen)&gt;&gt; | 是   | 回调函数。返回当前获取的屏幕对象集合。 |
| isNeedUnused | boolean | 否   | 是否需要提供未使用的屏幕对象。true表示返回值会提供未使用的屏幕对象，false表示不提供未使用的屏幕对象。<br>默认值为：false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenClass: screen.Screen | null = null;
// 获取所有屏幕对象
screen.getAllScreens((err: BusinessError, data: Array<screen.Screen>) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to get all screens. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting all screens. Data: ${JSON.stringify(data)}`);
  if (data.length > 0) {
    screenClass = data[0];
  }
}, true);
```

## screen.getAllScreens

getAllScreens(isNeedUnused?: boolean): Promise&lt;Array&lt;Screen&gt;&gt;

获取所有的屏幕对象，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                   |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| isNeedUnused | boolean | 否   | 是否需要提供未使用的屏幕对象。true表示返回值会提供未使用的屏幕对象，false表示不提供未使用的屏幕对象。<br>默认值为：false。 |

**返回值：** 

| 类型                                          | 说明                                      |
| --------------------------------------------- | ----------------------------------------- |
| Promise&lt;Array&lt;[Screen](#screen)&gt;&gt; | Promise对象。返回当前获取的屏幕对象集合。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenClass: screen.Screen | null = null;
// 获取所有屏幕对象
let promise: Promise<Array<screen.Screen>> = screen.getAllScreens(true);
promise.then((data: Array<screen.Screen>) => {
  if(data.length > 0){
    screenClass = data[0];
  }
  console.info(`Succeeded in getting all screens. Data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get all screens. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.on('connect' | 'disconnect' | 'change')

on(eventType: 'connect' | 'disconnect' | 'change', callback: Callback&lt;number&gt;): void

开启屏幕状态变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型                   | 必填 | 说明                                                        |
| --------- | ---------------------- | ---- | ----------------------------------------------------------- |
| eventType | string                 | 是   | 监听事件类型。<br>-"connect"：屏幕连接事件。<br>-"disconnect"：断开屏幕连接事件。<br>-"change"：屏幕状态改变事件。 |
| callback  | Callback&lt;number&gt; | 是   | 回调函数。返回屏幕的ID，该参数为整数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
let callback: Callback<number> = (data: number) => {
  console.info(`Succeeded in registering the callback for screen changes. Data: ${data}`);
};
// 开启屏幕连接事件的监听
screen.on('connect', callback);
```

## screen.off('connect' | 'disconnect' | 'change')

off(eventType: 'connect' | 'disconnect' | 'change', callback?: Callback&lt;number&gt;): void

关闭屏幕状态变化的监听。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型                   | 必填 | 说明                                                         |
| --------- | ---------------------- | ---- | ------------------------------------------------------------ |
| eventType | string                 | 是   | 监听事件类型。<br>-"connect"：屏幕连接事件。<br>-"disconnect"：断开屏幕连接事件。<br>-"change"：屏幕状态改变事件。 |
| callback  | Callback&lt;number&gt; | 否   | 回调函数。返回屏幕的ID，该参数为整数。若无此参数，则取消该eventType监听的所有回调函数。                                     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
let callback: Callback<number> = (data: number) => {
  console.info(`Succeeded in unregistering the callback for screen changes. Data: ${data}`);
};
// 关闭传入的callback监听
screen.off('connect', callback);
// 如果通过on注册多个callback，同时关闭所有callback监听
screen.off('connect');
```

## screen.makeMirror

makeMirror(mainScreen:number, mirrorScreen:Array&lt;number&gt;, callback: AsyncCallback&lt;number&gt;): void

将屏幕设置为镜像模式，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                        | 必填 | 说明                 |
| ------------ | --------------------------- | ---- |--------------------|
| mainScreen   | number                      | 是   | 主屏幕ID，该参数仅支持整数输入。  |
| mirrorScreen | Array&lt;number&gt;         | 是   | 镜像屏幕ID集合，其中ID应为整数。 |
| callback     | AsyncCallback&lt;number&gt; | 是   | 回调函数。返回镜像屏幕的群组ID，其中ID为整数。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 屏幕ID需通过getAllScreens()获取
let mainScreenId: number = 0; // 主屏ID
let mirrorScreenIds: Array<number> = [1, 2, 3]; // 镜像屏ID集合
// 设置屏幕为镜像模式
screen.makeMirror(mainScreenId, mirrorScreenIds, (err: BusinessError, data: number) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to set screen mirroring. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in setting screen mirroring. Data: ${data}`);
});
```

## screen.makeMirror

makeMirror(mainScreen:number, mirrorScreen:Array&lt;number&gt;): Promise&lt;number&gt;

将屏幕设置为镜像模式，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                | 必填 | 说明                 |
| ------------ | ------------------- | ---- |--------------------|
| mainScreen   | number              | 是   | 主屏幕ID，该参数仅支持整数输入。  |
| mirrorScreen | Array&lt;number&gt; | 是   | 镜像屏幕ID集合。其中ID应为整数。 |

**返回值：**

| 类型                  | 说明                              |
| --------------------- |---------------------------------|
| Promise&lt;number&gt; | Promise对象。返回镜像屏幕的群组ID，其中ID为整数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 屏幕ID需通过getAllScreens()获取
let mainScreenId: number = 0; // 主屏ID
let mirrorScreenIds: Array<number> = [1, 2, 3]; // 镜像屏ID集合
// 设置屏幕为镜像模式
screen.makeMirror(mainScreenId, mirrorScreenIds).then((data: number) => {
  console.info(`Succeeded in setting screen mirroring. Data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set screen mirroring. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.stopMirror<sup>10+</sup>

stopMirror(mirrorScreen:Array&lt;number&gt;, callback: AsyncCallback&lt;void&gt;): void

停止屏幕的镜像模式，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                      |
| ------------ | --------------------------- | --- |-----------------------------------------|
| mirrorScreen | Array&lt;number&gt;         | 是   | 镜像屏幕ID集合，ID应为整数。mirrorScreen数组大小不应超过1000。 |
| callback     | AsyncCallback&lt;void&gt; | 是   | 回调函数。当停止屏幕镜像模式成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 屏幕ID需通过getAllScreens()获取
let mirrorScreenIds: Array<number> = [1, 2, 3]; // 镜像屏ID集合
// 停止屏幕镜像模式
screen.stopMirror(mirrorScreenIds, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to stop mirror screens. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in stopping mirror screens.');
});
```

## screen.stopMirror<sup>10+</sup>

stopMirror(mirrorScreen:Array&lt;number&gt;): Promise&lt;void&gt;

停止屏幕的镜像模式，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------------ | ------------------- | --- |--------------------|
| mirrorScreen | Array&lt;number&gt; | 是   | 镜像屏幕ID集合，其中ID应为整数。mirrorScreen数组大小不应超过1000。 |

**返回值：**

| 类型 | 说明 |
| --------------------- | ----------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 屏幕ID需通过getAllScreens()获取
let mirrorScreenIds: Array<number> = [1, 2, 3]; // 镜像屏ID集合
// 停止屏幕镜像模式
screen.stopMirror(mirrorScreenIds).then(() => {
  console.info('Succeeded in stopping mirror screens.');
}).catch((err: BusinessError) => {
  console.error(`Failed to stop mirror screens. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.makeUnique<sup>18+</sup>

makeUnique(uniqueScreen: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

将屏幕设置为异源模式，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**设备行为差异：** 该接口在Phone设备、PC/2in1设备、Tablet设备中可正常调用，在Wearable设备中报801错误码，在其他设备中不生效也不报错。

**参数：**

| 参数名    | 类型   | 必填 | 说明          |
| --------- | ------ | ---- | ------------- |
| uniqueScreen  | Array&lt;number&gt; | 是   | 异源屏幕ID集合。其中ID应为大于0的整数，否则返回401错误码。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise对象。返回异源屏幕的屏幕ID集合，其中ID为大于0的整数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 屏幕ID需通过getAllScreens()获取
let uniqueScreenIds: Array<number> = [1001, 1002, 1003]; // 异源屏ID集合
// 设置屏幕为异源模式
screen.makeUnique(uniqueScreenIds).then((data: Array<number>) => {
  console.info('Succeeded in making unique screens.');
}).catch((err: BusinessError) => {
  console.error(`Failed to make unique screens. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.createVirtualScreen

createVirtualScreen(options:VirtualScreenOption, callback: AsyncCallback&lt;Screen&gt;): void

创建虚拟屏幕，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限**：ohos.permission.CAPTURE_SCREEN

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                               |
| -------- | ------------------------------------------- | ---- | ---------------------------------- |
| options  | [VirtualScreenOption](#virtualscreenoption) | 是   | 用于创建虚拟屏幕的参数。           |
| callback | AsyncCallback&lt;[Screen](#screen)&gt;      | 是   | 回调函数，返回创建的虚拟屏幕对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenClass: screen.Screen | null = null;
class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
  supportsFocus ?: boolean = true;
}

let option: VirtualScreenOption = { 
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: '',
  supportsFocus: false
}; // 创建虚拟屏幕的参数
// 创建虚拟屏幕
screen.createVirtualScreen(option, (err: BusinessError, data: screen.Screen) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to create the virtual screen. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  screenClass = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
});
```

## screen.createVirtualScreen

createVirtualScreen(options:VirtualScreenOption): Promise&lt;Screen&gt;

创建虚拟屏幕，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限**：ohos.permission.CAPTURE_SCREEN

**参数：** 

| 参数名  | 类型                                        | 必填 | 说明                     |
| ------- | ------------------------------------------- | ---- | ------------------------ |
| options | [VirtualScreenOption](#virtualscreenoption) | 是   | 用于创建虚拟屏幕的参数。 |

**返回值：**

| 类型                             | 说明                                  |
| -------------------------------- | ------------------------------------- |
| Promise&lt;[Screen](#screen)&gt; | Promise对象。返回创建的虚拟屏幕对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let screenClass: screen.Screen | null = null;
class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
  supportsFocus ?: boolean = true;
}

let option: VirtualScreenOption = { 
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: '',
  supportsFocus: false
}; // 创建虚拟屏幕的参数

// 创建虚拟屏幕
screen.createVirtualScreen(option).then((data: screen.Screen) => {
  screenClass = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.destroyVirtualScreen

destroyVirtualScreen(screenId:number, callback: AsyncCallback&lt;void&gt;): void

销毁虚拟屏幕，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| screenId | number                    | 是   | 屏幕的ID，该参数仅支持整数输入。                                                   |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当销毁虚拟屏幕成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |
| 1400002 | Unauthorized operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 屏幕ID需通过getAllScreens()获取或从createVirtualScreen()返回值获取
let screenId: number = 1; // 虚拟屏ID
// 销毁虚拟屏幕
screen.destroyVirtualScreen(screenId, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to destroy the virtual screen. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in destroying the virtual screen.');
});
```

## screen.destroyVirtualScreen

destroyVirtualScreen(screenId:number): Promise&lt;void&gt;

销毁虚拟屏幕，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| screenId | number | 是   | 屏幕的ID，该参数仅支持整数输入。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |
| 1400002 | Unauthorized operation. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 屏幕ID需通过getAllScreens()获取或从createVirtualScreen()返回值获取
let screenId: number = 1; // 虚拟屏ID
// 销毁虚拟屏幕
screen.destroyVirtualScreen(screenId).then(() => {
  console.info('Succeeded in destroying the virtual screen.');
}).catch((err: BusinessError) => {
  console.error(`Failed to destroy the virtual screen. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.setVirtualScreenSurface

setVirtualScreenSurface(screenId:number, surfaceId: string, callback: AsyncCallback&lt;void&gt;): void

设置虚拟屏幕的surface，表示虚拟屏幕内容显示在对应surface上。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限**：ohos.permission.CAPTURE_SCREEN，仅系统应用可用。

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| screenId  | number                    | 是   | 屏幕的ID，该参数仅支持整数输入。                                                   |
| surfaceId | string                    | 是   | 代表虚拟屏幕的surface标识符，surfaceId值可自行定义，由用户指定某一实际存在的surface对应的surfaceId。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。当设置虚拟屏幕surface成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
// Index.ets
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  xComponentController: XComponentController = new XComponentController();

  setVirtualScreenSurface = () => {
    let screenId: number = 1;
    let surfaceId = this.xComponentController.getXComponentSurfaceId();
    // 设置虚拟屏幕的surface
    screen.setVirtualScreenSurface(screenId, surfaceId, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the surface for the virtual screen. Code: ${err.code}, message: ${err.message}`);
      return;
    }
      console.info('Succeeded in setting the surface for the virtual screen.');
    });
  }
  build() {
    RelativeContainer() {
      XComponent({
        type: XComponentType.SURFACE,
        controller: this.xComponentController
      })
      Button('setSurface')
        .onClick((event: ClickEvent) => {
          this.setVirtualScreenSurface();
      }).width('100%')
      .height(20)
    }
    .width('100%')
    .height('100%')
  }
}
```

## screen.setVirtualScreenSurface

setVirtualScreenSurface(screenId:number, surfaceId: string): Promise&lt;void&gt;

设置虚拟屏幕的surface，表示虚拟屏幕内容显示在对应surface上。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**需要权限**：ohos.permission.CAPTURE_SCREEN，仅系统应用可用。

**参数：**

| 参数名    | 类型   | 必填 | 说明          |
| --------- | ------ | ---- | ------------- |
| screenId  | number | 是   | 屏幕的ID，该参数仅支持整数输入。    |
| surfaceId | string | 是   | 代表虚拟屏幕的surface标识符，surfaceId值可自行定义，由用户指定某一实际存在的surface对应的surfaceId。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
// Index.ets
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  xComponentController: XComponentController = new XComponentController();

  setVirtualScreenSurface = () => {
    let screenId: number = 1;
    let surfaceId = this.xComponentController.getXComponentSurfaceId();
    // 设置虚拟屏幕的surface
    screen.setVirtualScreenSurface(screenId, surfaceId).then(() => {
      console.info('Succeeded in setting the surface for the virtual screen.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to set the surface for the virtual screen. Code: ${err.code}, message: ${err.message}`);
    });
  }
  build() {
    RelativeContainer() {
      XComponent({
        type: XComponentType.SURFACE,
        controller: this.xComponentController
      })
      Button('setSurface')
        .onClick((event: ClickEvent) => {
          this.setVirtualScreenSurface();
      }).width('100%')
      .height(20)
    }
    .width('100%')
    .height('100%')
  }
}
```

## screen.setScreenPrivacyMaskImage<sup>19+</sup>

setScreenPrivacyMaskImage(screenId:number, image?: image.PixelMap): Promise&lt;void&gt;

设置屏幕的隐私蒙版图片，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名    | 类型   | 必填 | 说明          |
| --------- | ------ | ---- | ------------- |
| screenId  | number | 是   | 屏幕的ID，该参数仅支持正整数输入。    |
| image | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md) | 否   | 屏幕的隐私蒙版图片，不传入则使用默认隐私蒙版图片。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 801     | Capability not supported. Failed to call the API due to limited device capabilities. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

const color: ArrayBuffer = new ArrayBuffer(96); // 96为需要创建的像素buffer大小，取值为：height * width *4
let options: image.InitializationOptions = { editable: true, pixelFormat: image.PixelMapFormat.RGBA_8888, size: { height: 4, width: 6 } }
image.createPixelMap(color, options).then((pixelMap: image.PixelMap) => {
  console.info('Succeeded in creating pixelmap.');
  // 屏幕ID需通过getAllScreens()获取
  let screenId: number = 1; // 屏幕ID
  // 设置屏幕的隐私蒙版图片
  screen.setScreenPrivacyMaskImage(screenId, pixelMap).then(() => {
    console.info('Succeeded in setting the privacy mask image for the screen.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the privacy mask image for the screen. Code: ${err.code}, message: ${err.message}`);
  });
}).catch((error: BusinessError) => {
  console.error(`Failed to create pixelmap. Code: ${error.code}, message: ${error.message}`);
});
```

## screen.isScreenRotationLocked

isScreenRotationLocked(): Promise&lt;boolean&gt;

查询当前自动转屏是否锁定，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**返回值：**

| 类型                   | 说明                                  |
| ---------------------- | ------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。返回true表示当前自动转屏处于锁定状态；返回false表示当前自动转屏不处于锁定状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 查询当前自动转屏是否锁定
screen.isScreenRotationLocked().then((isLocked: boolean) => {
  console.info(`Succeeded in getting the screen rotation lock status. isLocked: ${isLocked}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get the screen rotation lock status. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.isScreenRotationLocked

isScreenRotationLocked(callback: AsyncCallback&lt;boolean&gt;): void

查询当前自动转屏是否锁定，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型                          | 必填 | 说明                                                         |
| --------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback  | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回true表示当前自动转屏处于锁定状态；返回false表示当前自动转屏不处于锁定状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 查询当前自动转屏是否锁定
screen.isScreenRotationLocked((err: BusinessError, isLocked: boolean) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to get the screen rotation lock status. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting the screen rotation lock status. isLocked: ${isLocked}`);
});
```

## screen.setScreenRotationLocked

setScreenRotationLocked(isLocked: boolean): Promise&lt;void&gt;

设置自动转屏开关是否锁定，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**设备行为差异：** 仅在支持跟随sensor旋转的设备中生效，其他设备调用不生效不报错。

**参数：**

| 参数名    | 类型   | 必填 | 说明          |
| --------- | ------ | ---- | ------------- |
| isLocked  | boolean | 是   | 自动转屏开关是否锁定。true为锁定，false为未锁定。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isLocked: boolean = false;
// 设置自动转屏开关为未锁定
screen.setScreenRotationLocked(isLocked).then(() => {
  console.info('Succeeded in unlocking auto rotate');
}).catch((err: BusinessError) => {
  console.error(`Failed to unlock auto rotate. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.setScreenRotationLocked

setScreenRotationLocked(isLocked: boolean, callback: AsyncCallback&lt;void&gt;): void

设置自动转屏开关是否锁定，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**设备行为差异：** 仅在支持跟随sensor旋转的设备中生效，其他设备调用不生效不报错。

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| isLocked  | boolean                   | 是   | 自动转屏开关是否锁定。true为锁定，false为未锁定。                 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。当设置自动转屏是否锁定成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let isLocked: boolean = false;
// 设置自动转屏开关为未锁定
screen.setScreenRotationLocked(isLocked, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to unlock auto rotate. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in unlocking auto rotate.');
});
```

## screen.setMultiScreenMode<sup>13+</sup>

setMultiScreenMode(primaryScreenId: number, secondaryScreenId: number, secondaryScreenMode: MultiScreenMode): Promise&lt;void&gt;

设置扩展屏幕的显示模式（镜像/扩展），使用Promise异步回调。primaryScreenId和secondaryScreenId均为0时，仅在扩展屏显示。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                 | 必填 | 说明                |
| ------------ | ------------------- | ---- |--------------------|
| primaryScreenId   | number           | 是  | 主屏的ID，该参数应为非负整数。如果输入的数字包含小数部分，向下取整。|
| secondaryScreenId | number           | 是  | 扩展屏幕的ID，该参数应为非负整数。如果输入的数字包含小数部分，向下取整。|
| secondaryScreenMode | [MultiScreenMode](#multiscreenmode13)  | 是  | 扩展屏幕的显示模式。|

**返回值：**

| 类型               | 说明                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 屏幕ID需通过getAllScreens()获取
let primaryScreenId: number = 0; // 主屏ID
let secondaryScreenId: number = 12; // 扩展屏ID
let screenMode: screen.MultiScreenMode = screen.MultiScreenMode.SCREEN_MIRROR;
// 设置扩展屏幕的显示模式为镜像模式
screen.setMultiScreenMode(primaryScreenId, secondaryScreenId, screenMode).then(() => {
  console.info('Succeeded in setting multi screen mode. Data: ');
}).catch((err: BusinessError) => {
  console.error(`Failed to set multi screen mode. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.setMultiScreenRelativePosition<sup>13+</sup>

setMultiScreenRelativePosition(mainScreenOptions: MultiScreenPositionOptions, secondaryScreenOptions: MultiScreenPositionOptions): Promise&lt;void&gt;

仅在扩展模式下，设置主屏和扩展屏幕的位置信息，使用Promise异步回调。通过设置startX和startY坐标，可确定各屏幕在虚拟显示空间中的相对位置，实现屏幕排列布局。例如，设置扩展屏幕的startX为主屏幕宽度值，可实现扩展屏幕位于主屏幕右侧的布局。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                 | 必填 | 说明               |
| ------------ | ------------------- | ---- |--------------------|
| mainScreenOptions      | [MultiScreenPositionOptions](#multiscreenpositionoptions13)  | 是  | 主屏的位置信息。|
| secondaryScreenOptions | [MultiScreenPositionOptions](#multiscreenpositionoptions13)  | 是  | 扩展屏幕的位置信息。|

**返回值：**

| 类型                | 说明                       |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 屏幕ID需通过getAllScreens()获取
let mainScreenOptions: screen.MultiScreenPositionOptions = {
  id : 0,  // 主屏ID
  startX : 0,
  startY : 0
}; // 主屏的位置信息

let secondaryScreenOptions: screen.MultiScreenPositionOptions = {
  id : 12,  // 扩展屏ID
  startX : 1000,
  startY : 1000
}; // 扩展屏幕的位置信息

// 设置主屏和扩展屏幕的位置信息
screen.setMultiScreenRelativePosition(mainScreenOptions, secondaryScreenOptions).then(() => {
  console.info('Succeeded in setting multi screen relative position.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set multi screen relative position. Code: ${err.code}, message: ${err.message}`);
});
```
## screen.resizeVirtualScreen<sup>24+</sup>

resizeVirtualScreen(screenId: number, width: number, height: number): Promise&lt;void&gt;

修改指定虚拟屏的尺寸，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Window.SessionManager

**参数：**

| 参数名      | 类型        | 必填 | 说明                                                        |
| ---------- | ----------- | ---  |------------------------------------------------------------|
| screenId   | number      | 是   | 要修改的虚拟屏的屏幕ID，取值范围为[1000, 2147483647]的正整数，超出有效范围时返回错误码1400004。 |
| width      | number      | 是   | 虚拟屏的新宽度，单位为px，取值范围为[1, 65536]的正整数，超出有效范围时返回错误码1400004。  |
| height     | number      | 是   | 虚拟屏的新高度，单位为px，取值范围为[1, 65536]的正整数，超出有效范围时返回错误码1400004。  |

**返回值：**

| 类型                  | 说明                              |
| --------------------- |---------------------------------|
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 801     | Capability not supported. Function can not work because the current device does not support this ability. |
| 1400001 | Invalid display or screen. |
| 1400003 | This display manager service works abnormally. |
| 1400004 | Parameter error. Possible cause: 1. Invalid parameter range. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 虚拟屏ID需从createVirtualScreen()返回值获取
let screenId: number = 1000; // 虚拟屏ID
let width: number = 1920;
let height: number = 1080;
// 修改虚拟屏的尺寸
screen.resizeVirtualScreen(screenId, width, height).then(() => {
  console.info(`Succeeded in resizing virtual screen: screenId=${screenId}, width=${width}, height=${height}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set screen area mirroring. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.makeMirrorWithRegion<sup>19+</sup>

makeMirrorWithRegion(mainScreen:number, mirrorScreen:Array&lt;number&gt;, mainScreenRegion:Rect): Promise&lt;number&gt;

将屏幕的某一矩形区域设置为镜像模式，使用Promise异步回调。调用该接口后，不建议再进行屏幕的旋转/折叠，否则可能导致镜像内容异常。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名       | 类型                | 必填 | 说明                 |
| ------------ | ------------------- | ---- |--------------------|
| mainScreen   | number              | 是   | 主屏幕ID，该参数仅支持正整数输入。  |
| mirrorScreen | Array&lt;number&gt; | 是   | 镜像屏幕ID集合。其中ID应为正整数。  |
| mainScreenRegion | [Rect](#rect19) | 是   | 主屏创建镜像的矩形区域。         |

**返回值：**

| 类型                  | 说明                              |
| --------------------- |---------------------------------|
| Promise&lt;number&gt; | Promise对象。返回镜像屏幕的群组ID，其中ID为正整数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 屏幕ID需通过getAllScreens()获取
let mainScreenId: number = 0; // 主屏ID
let mirrorScreenIds: Array<number> = [1, 2, 3]; // 镜像屏ID集合
// 主屏创建镜像的矩形区域
let mainScreenRegion: screen.Rect = {
  left : 0,
  top : 0,
  width : 1920,
  height : 1080
};
// 将屏幕的某一矩形区域设置为镜像模式
screen.makeMirrorWithRegion(mainScreenId, mirrorScreenIds, mainScreenRegion).then((data: number) => {
  console.info(`Succeeded in setting screen mirroring. Data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to set screen area mirroring. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.makeExpand<sup>(deprecated)</sup>

makeExpand(options:Array&lt;ExpandOption&gt;, callback: AsyncCallback&lt;number&gt;): void

将屏幕设置为扩展模式，使用callback异步回调。

> **说明：**
> 
> 从API version 9开始支持，从API version 20开始废弃。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                         |
| -------- | ------------------------------------------ | ---- |----------------------------|
| options  | Array&lt;[ExpandOption](#expandoption)&gt; | 是   | 设置扩展屏幕的参数集合。               |
| callback | AsyncCallback&lt;number&gt;                     | 是   | 回调函数。返回扩展屏幕的群组ID，其中ID为整数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let groupId: number | null = null;
class ExpandOption {
  screenId: number = 0;
  startX: number = 0;
  startY: number = 0;
}
let mainScreenOption: ExpandOption = { screenId: 0, startX: 0, startY: 0 };
let otherScreenOption: ExpandOption = { screenId: 1, startX: 1080, startY: 0 };
let expandOptionArray : ExpandOption[] = [ mainScreenOption, otherScreenOption ];
// 将屏幕设置为扩展模式
screen.makeExpand(expandOptionArray, (err: BusinessError, data: number) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to expand the screen. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  groupId = data;
  console.info(`Succeeded in expanding the screen. Data: ${data}`);
});
```

## screen.makeExpand<sup>(deprecated)</sup>

makeExpand(options:Array&lt;ExpandOption&gt;): Promise&lt;number&gt;

将屏幕设置为扩展模式，使用Promise异步回调。

> **说明：**
> 
> 从API version 9开始支持，从API version 20开始废弃。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名  | 类型                                       | 必填 | 说明                     |
| ------- | ------------------------------------------ | ---- | ------------------------ |
| options | Array&lt;[ExpandOption](#expandoption)&gt; | 是   | 设置扩展屏幕的参数集合。 |

**返回值：**

| 类型                  | 说明                              |
| --------------------- |---------------------------------|
| Promise&lt;number&gt; | Promise对象。返回扩展屏幕的群组ID，其中ID为整数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class ExpandOption {
  screenId: number = 0;
  startX: number = 0;
  startY: number = 0;
}
let mainScreenOption: ExpandOption = { screenId: 0, startX: 0, startY: 0 };
let otherScreenOption: ExpandOption = { screenId: 1, startX: 1080, startY: 0 };
let expandOptionArray : ExpandOption[] = [ mainScreenOption, otherScreenOption ];
// 将屏幕设置为扩展模式
screen.makeExpand(expandOptionArray).then((data: number) => {
  console.info(`Succeeded in expanding the screen. Data: ${data}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to expand the screen. Code: ${err.code}, message: ${err.message}`);
});
```

## screen.stopExpand<sup>(deprecated)</sup>

stopExpand(expandScreen:Array&lt;number&gt;, callback: AsyncCallback&lt;void&gt;): void

停止屏幕的扩展模式，使用callback异步回调。

> **说明：**
> 
> 从API version 10开始支持，从API version 20开始废弃。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                                      |
| ------------ | --------------------------- | --- |-----------------------------------------|
| expandScreen | Array&lt;number&gt;         | 是   | 扩展屏幕ID集合，其中ID为整数。 expandScreen数组大小不应超过1000。  |
| callback     | AsyncCallback&lt;void&gt; | 是   | 回调函数。当停止屏幕扩展模式成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let expandScreenIds: Array<number> = [1, 2, 3]; // 扩展屏幕ID集合
// 停止屏幕的扩展模式
screen.stopExpand(expandScreenIds, (err: BusinessError) => {
  const errCode: number = err.code;
  if (errCode) {
    console.error(`Failed to stop expand screens. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in stopping expand screens.');
});
```

## screen.stopExpand<sup>(deprecated)</sup>

stopExpand(expandScreen:Array&lt;number&gt;): Promise&lt;void&gt;

停止屏幕的扩展模式，使用Promise异步回调。

> **说明：**
> 
> 从API version 10开始支持，从API version 20开始废弃。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明                 |
| ------------ | ------------------- | --- |--------------------|
| expandScreen | Array&lt;number&gt; | 是   | 扩展屏幕ID集合，其中ID为整数。expandScreen数组大小不应超过1000。 |

**返回值：**

| 类型 | 说明 |
| --------------------- | ----------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 1400001 | Invalid display or screen. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let expandScreenIds: Array<number> = [1, 2, 3]; // 扩展屏幕ID集合
// 停止屏幕的扩展模式
screen.stopExpand(expandScreenIds).then(() => {
  console.info('Succeeded in stopping expand screens.');
}).catch((err: BusinessError) => {
  console.error(`Failed to stop expand screens. Code: ${err.code}, message: ${err.message}`);
});
```

## ExpandOption

扩展屏幕的参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称     | 类型 | 只读 | 可选 | 说明                |
| -------- | -------- | ---- | ---- | ------------------- |
| screenId | number   | 否   | 否   | 屏幕的ID，该参数应为整数。          |
| startX   | number   | 否   | 否   | 屏幕的起始X轴坐标，该参数应为整数。 |
| startY   | number   | 否   | 否   | 屏幕的起始Y轴坐标，该参数应为整数。 |

## MultiScreenMode<sup>13+</sup>

屏幕模式枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称              | 值  | 说明                            |
| ------------------ | ---- | -------------------------------- |
| SCREEN_MIRROR      | 0    | 表示屏幕为镜像模式。 |
| SCREEN_EXTEND      | 1    | 表示屏幕为扩展模式。 |

## MultiScreenPositionOptions<sup>13+</sup>

屏幕位置信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称    | 类型     | 只读 | 可选  | 说明                |
| -------- | -------- | ---- | ---- | ------------------- |
| id       | number   | 否   | 否   | 屏幕的ID，该参数应为非负整数，否则会作为非法参数报错。|
| startX   | number   | 否   | 否   | 屏幕的起始X轴坐标。以两块屏幕外接矩形的左上顶点为原点，向右为正方向。该参数应为非负整数，否则会作为非法参数报错。 |
| startY   | number   | 否   | 否   | 屏幕的起始Y轴坐标。以两块屏幕外接矩形的左上顶点为原点，向下为正方向。该参数应为非负整数，否则会作为非法参数报错。 |

## VirtualScreenOption

创建虚拟屏幕的参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称      | 类型 | 只读 | 可选 | 说明                       |
| --------- | -------- | ---- | ---- |--------------------------|
| name      | string   | 否   | 否   | 指定虚拟屏幕的名称。               |
| width     | number   | 否   | 否   | 指定虚拟屏幕的宽度，单位为px，该参数应为整数。 |
| height    | number   | 否   | 否   | 指定虚拟屏幕的高度，单位为px，该参数应为整数。 |
| density   | number   | 否   | 否   | 指定虚拟屏幕的密度，该参数为浮点数。 |
| surfaceId | string   | 否   | 否   | 指定虚拟屏幕的surfaceId。        |
| supportsFocus<sup>22+</sup> | boolean | 否 | 是  | 指定虚拟屏幕是否可获得焦点。true表示可获焦，false表示不可获焦，默认值为true。 |
| userId<sup>24+</sup> | number | 否 | 是  | 指定虚拟屏幕的用户ID，该参数为整数。默认值为-1。<br>**设备行为差异：** 该参数仅在Car设备中生效，其他设备不生效也不报错。 |

## Screen

[物理屏](../../displaymanager/display-terminology.md#物理屏)屏幕实例。

下列API示例中都需先使用[getAllScreens()](#screengetallscreens)、[createVirtualScreen()](#screencreatevirtualscreen)中的任一方法获取到Screen实例，再通过此实例调用对应方法。

### 属性

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core


| 名称              | 类型                                       | 只读 | 可选 | 说明                                                          |
| ----------------- | ---------------------------------------------- | ---- | ---- |-------------------------------------------------------------|
| id                | number                                         | 是   | 否   | 屏幕的ID，该参数为整数。                           |
| rsId<sup>21+</sup> |number | 是 | 否 | 屏幕端口的ID，该参数为整数。|
| parent            | number                                         | 是   | 否   | 屏幕所属群组的ID，该参数为整数。             |
| supportedModeInfo | Array&lt;[ScreenModeInfo](#screenmodeinfo)&gt; | 是   | 否   | 屏幕支持的模式集合。   |
| activeModeIndex   | number                                         | 是   | 否   | 当前屏幕所处模式索引。模式索引的当前值和值的范围，会根据屏幕当前分辨率、刷新率和设备硬件差异产生变化。该参数为整数。 |
| orientation       | [Orientation](#orientation)                     | 是   | 否   | 屏幕方向。       |
| sourceMode<sup>10+</sup> | [ScreenSourceMode](#screensourcemode10)            | 是   | 否   | 屏幕来源模式。     |
| serialNumber<sup>15+</sup> | string        | 是   | 是   | 扩展屏幕的序列号，默认返回为空字符串。 |
| densityDpi | number        | 是   | 是   | 屏幕的物理像素密度，即每英寸的像素数。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |
| isInUse | boolean        | 是   | 是   | 标识屏幕的使用状态。true表示屏幕使用中；false表示屏幕未使用；默认值为true。<br>**起始版本：** 26.0.0<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

### setOrientation

setOrientation(orientation: Orientation, callback: AsyncCallback&lt;void&gt;): void

设置屏幕方向，使用callback异步回调。当设置的方向符合[应用旋转策略](../../quick-start/module-configuration-file.md#abilities标签)（可通过配置module.json5文件中abilities标签的orientation字段设置应用旋转策略）时，屏幕方向才会发生改变；当设置方向不符合应用旋转策略时，屏幕方向不会发生变化，且接口不会抛异常。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**设备行为差异：**

- 针对Phone、Tablet设备：在[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下调用不生效不报错；在非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下可正常调用，对于部分设备对屏幕有强约束（由产品配置决定），无需旋转的，调用此接口不生效。
- 针对PC/2in1设备：折叠屏设备处于悬停态时，调用此接口不生效不报错。其他情况可正常调用生效。
- 针对其他设备：接口行为未定义，不保证屏幕方向发生变化。

**参数：**

| 参数名      | 类型                        | 必填 | 说明                                                         |
| ----------- | --------------------------- | ---- | ------------------------------------------------------------ |
| orientation | [Orientation](#orientation) | 是   | 屏幕方向。orientation值必须来自Orientation枚举方向。                |
| callback    | AsyncCallback&lt;void&gt;   | 是   | 回调函数。当设置屏幕方向成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
  supportsFocus ?: boolean = true;
}

let option: VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: '',
  supportsFocus: false
};

// 创建虚拟屏幕
screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
  // 设置屏幕方向为垂直方向
  screenClass.setOrientation(screen.Orientation.VERTICAL, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the vertical orientation. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the vertical orientation.');
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code: ${err.code}, message: ${err.message}`);
});
```

### setOrientation

setOrientation(orientation: Orientation): Promise&lt;void&gt;

设置屏幕方向，使用Promise异步回调。当设置的方向符合[应用旋转策略](../../quick-start/module-configuration-file.md#abilities标签)（可通过配置module.json5文件中abilities标签的orientation字段设置应用旋转策略）时，屏幕方向才会发生改变；当设置方向不符合应用旋转策略时，屏幕方向不会发生变化，且接口不会抛异常。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**设备行为差异：**

- 针对Phone、Tablet设备：在[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下调用不生效不报错；在非[自由窗口](../../windowmanager/window-terminology.md#freeform-window自由窗口)状态下可正常调用，对于部分设备对屏幕有强约束（由产品配置决定），无需旋转的，调用此接口不生效。
- 针对PC/2in1设备：折叠屏设备处于悬停态时，调用此接口不生效不报错。其他情况可正常调用生效。
- 针对其他设备：接口行为未定义，不保证屏幕方向发生变化。

**参数：**

| 参数名      | 类型                        | 必填 | 说明       |
| ----------- | --------------------------- | ---- | ---------- |
| orientation | [Orientation](#orientation) | 是   | 屏幕方向。orientation值必须来自Orientation枚举方向。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
  supportsFocus ?: boolean = true;
}

let option: VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: '',
  supportsFocus: false
};

// 创建虚拟屏幕
screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
  // 设置屏幕方向为垂直方向
  let promise: Promise<void> = screenClass.setOrientation(screen.Orientation.VERTICAL);
  promise.then(() => {
    console.info('Succeeded in setting the vertical orientation.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the vertical orientation. Code: ${err.code}, message: ${err.message}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code: ${err.code}, message: ${err.message}`);
});
```

### setOrientation

setOrientation(orientation: Orientation, orientationOptions?: OrientationOptions): Promise\<void>

设置屏幕方向，使用Promise异步回调。

可通过orientationOptions参数指定旋转时是否带有动画、是否忽略系统窗口的旋转锁定。

不传入orientationOptions参数时，接口行为与`setOrientation(orientation: Orientation): Promise<void>`相同。

当设置的方向符合应用旋转策略（可通过配置module.json5文件中abilities标签的orientation字段设置应用旋转策略）时，屏幕方向才会发生改变；当设置方向不符合应用旋转策略时，屏幕方向不会发生变化，且接口不会抛出异常。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**设备行为差异：**

仅支持有线连接的外接显示器作为[扩展屏](../../displaymanager/display-terminology.md#扩展屏)时设置屏幕方向。在其他屏幕上调用，或该外接显示器作为[镜像屏](../../displaymanager/display-terminology.md#镜像屏)时，返回1400001错误码。

**参数：**

| 参数名      | 类型                        | 必填 | 说明       |
| ----------- | --------------------------- | ---- | ---------- |
| orientation | [Orientation](#orientation) | 是   | 屏幕方向。 |
| orientationOptions | [OrientationOptions](#orientationoptions) | 否 | 设置屏幕旋转时的可选参数。默认带动画旋转屏幕，不忽略旋转锁定。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise\<void> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 1400001 | Invalid display or screen. Possible cause: The screen is not a wired external display in extended mode. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let orientationOptions : screen.OrientationOptions = {
  needAnimation: true,
  ignoreRotationLock: false,
};

let screenClass: screen.Screen | null = null;
// 获取所有屏幕对象
let screensPromise: Promise<Array<screen.Screen>> = screen.getAllScreens();
screensPromise.then((data: Array<screen.Screen>) => {
  if (data.length > 0) {
    screenClass = data[0];
    // 设置屏幕方向为垂直方向，带动画且不忽略旋转锁定
    let promise: Promise<void> = screenClass.setOrientation(screen.Orientation.VERTICAL, orientationOptions);
    promise.then(() => {
      console.info('Succeeded in setting the vertical orientation with orientationOptions.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to set the vertical orientation with orientationOptions. Code: ${err.code}, message: ${err.message}`);
    });
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to get all screens. Code: ${err.code}, message: ${err.message}`);
});
```

### setScreenActiveMode

setScreenActiveMode(modeIndex: number, callback: AsyncCallback&lt;void&gt;): void

设置屏幕当前显示模式，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型                      | 必填 | 说明                                                         |
| --------- | ------------------------- | ---- | ------------------------------------------------------------ |
| modeIndex | number                    | 是   | 模式索引。模式索引的当前值和值的范围，会根据屏幕当前分辨率、刷新率和设备硬件差异产生变化，该参数仅支持整数输入。索引为screen中[ScreenModeInfo](#screenmodeinfo)属性的模式ID。 |
| callback  | AsyncCallback&lt;void&gt; | 是   | 回调函数。当设置屏幕当前显示模式成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
  supportsFocus ?: boolean = true;
}

let option: VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: '',
  supportsFocus: false
};

// 创建虚拟屏幕
screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
  let modeIndex: number = 0;
  // 设置屏幕当前显示模式
  screenClass.setScreenActiveMode(modeIndex, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set screen active mode 0. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the screen active mode 0.');
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code: ${err.code}, message: ${err.message}`);
});
```

### setScreenActiveMode

setScreenActiveMode(modeIndex: number): Promise&lt;void&gt;

设置屏幕当前显示模式，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名    | 类型   | 必填 | 说明       |
| --------- | ------ | ---- | ---------- |
| modeIndex | number | 是   | 模式索引。模式索引的当前值和值的范围，会根据屏幕当前分辨率、刷新率和设备硬件差异产生变化，该参数仅支持整数输入。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
  supportsFocus ?: boolean = true;
}

let option: VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: '',
  supportsFocus: false
};

// 创建虚拟屏幕
screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
  let modeIndex: number = 0;
  // 设置屏幕当前显示模式
  let promise: Promise<void> = screenClass.setScreenActiveMode(modeIndex);
  promise.then(() => {
    console.info('Succeeded in setting screen active mode 0.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set screen active mode 0. Code: ${err.code}, message: ${err.message}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code: ${err.code}, message: ${err.message}`);
});
```

### setDensityDpi

setDensityDpi(densityDpi: number, callback: AsyncCallback&lt;void&gt;): void;

设置屏幕的像素密度，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明                                       |
| ---------- | ------------------------- | ---- |------------------------------------------|
| densityDpi | number                    | 是   | 像素密度。支持的输入范围为[80, 640]，该参数仅支持整数输入。       |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调函数。当设置屏幕的像素密度成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let densityDpi: number = 320;
class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
  supportsFocus ?: boolean = true;
}

let option: VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: '',
  supportsFocus: false
};

// 创建虚拟屏幕
screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  console.info(`Succeeded in creating the virtual screen. Data: ${JSON.stringify(data)}`);
  // 设置屏幕的像素密度
  screenClass.setDensityDpi(densityDpi, (err: BusinessError) => {
    const errCode: number = err.code;
    if (errCode) {
      console.error(`Failed to set the pixel density of the screen to 320. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeeded in setting the density dpi.');
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code: ${err.code}, message: ${err.message}`);
});
```

### setDensityDpi

setDensityDpi(densityDpi: number): Promise&lt;void&gt;

设置屏幕的像素密度，使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明                                 |
| ---------- | ------ | ---- |------------------------------------|
| densityDpi | number | 是   | 像素密度。支持的输入范围为[80, 640]，该参数仅支持整数输入。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[屏幕错误码](errorcode-display.md)。

| 错误码ID | 错误信息 |
| ------- | -------------------------------------------- |
| 202     | Permission verification failed. A non-system application calls a system API. |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 1400003 | This display manager service works abnormally. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let densityDpi: number = 320;
class VirtualScreenOption {
  name : string = '';
  width : number =  0;
  height : number = 0;
  density : number = 0;
  surfaceId : string = '';
  supportsFocus ?: boolean = true;
}

let option: VirtualScreenOption = {
  name: 'screen01',
  width: 1080,
  height: 2340,
  density: 2,
  surfaceId: '',
  supportsFocus: false
};

// 创建虚拟屏幕
screen.createVirtualScreen(option).then((data: screen.Screen) => {
  let screenClass: screen.Screen = data;
  // 设置屏幕的像素密度
  let promise: Promise<void> = screenClass.setDensityDpi(densityDpi);
  promise.then(() => {
    console.info('Succeeded in setting the pixel density of the screen to 320.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to set the pixel density of the screen to 320. Code: ${err.code}, message: ${err.message}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to create the virtual screen. Code: ${err.code}, message: ${err.message}`);
});
```

## Orientation

屏幕方向枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称               | 值   | 说明                             |
| ------------------ | ---- | -------------------------------- |
| UNSPECIFIED        | 0    | 表示未指定屏幕方向，由系统指定。 |
| VERTICAL           | 1    | 表示指定屏幕为垂直方向。         |
| HORIZONTAL         | 2    | 表示指定屏幕为水平方向。         |
| REVERSE_VERTICAL   | 3    | 表示指定屏幕为反向垂直方向。     |
| REVERSE_HORIZONTAL | 4    | 表示指定屏幕为反向水平方向。     |

## ScreenSourceMode<sup>10+</sup>

屏幕显示内容来源模式枚举。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称               | 值   | 说明                             |
| ------------------ | ---- | -------------------------------- |
| SCREEN_MAIN         | 0    | 表示屏幕为默认主屏。 |
| SCREEN_MIRROR       | 1    | 表示屏幕内容来自镜像。         |
| SCREEN_EXTEND       | 2    | 表示屏幕内容来自扩展。         |
| SCREEN_ALONE        | 3    | 表示屏幕为未指定来源。     |

## ScreenModeInfo

屏幕显示模式信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称        | 类型 | 只读 | 可选 | 说明                                               |
| ----------- | -------- | ---- | ---- | -------------------------------------------------- |
| id          | number   | 否   | 否   | 模式ID，所支持的模式由具体设备分辨率和刷新率决定，该参数为整数。 | 
| width       | number   | 否   | 否   | 屏幕的宽度，单位为px，该参数为整数。                                |
| height      | number   | 否   | 否   | 屏幕的高度，单位为px，该参数为整数。                                |
| refreshRate | number   | 否   | 否   | 屏幕的刷新率，单位为Hz，该参数为整数。                                     |

## Rect<sup>19+</sup>

矩形信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称        | 类型 | 只读 | 可选 | 说明                                               |
| ----------- | -------- | ---- | ---- | -------------------------------------------------- |
| left    | number   | 否   | 否   | 矩形左上角顶点的X轴坐标，单位为px，该参数应为整数。 |
| top     | number   | 否   | 否   | 矩形左上角顶点的Y轴坐标，单位为px，该参数应为整数。 |
| width   | number   | 否   | 否   | 矩形的宽度，单位为px，该参数应为整数。             |
| height  | number   | 否   | 否   | 矩形的高度，单位为px，该参数应为整数。             |

## OrientationOptions

设置屏幕方向的可选参数。

**起始版本：** 26.0.0

**模型约束：** 此字段仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.WindowManager.WindowManager.Core

| 名称        | 类型 | 只读 | 可选 | 说明                                               |
| ----------- | -------- | ---- | ---- | -------------------------------------------------- |
| needAnimation          | boolean   | 否   | 是   |  是否带动画旋转。true表示带动画旋转屏幕，false表示不带动画旋转屏幕。默认值为true。 | 
| ignoreRotationLock     | boolean   | 否   | 是   |  是否忽略旋转锁定。true表示即使某些系统窗口锁定屏幕旋转，也允许屏幕旋转；false表示当系统窗口锁定屏幕旋转时，不允许屏幕旋转。默认值为false。<br> **设备行为差异：** 该字段仅在PC/2in1设备（非折叠PC）和其他设备的[电脑模式](../../windowmanager/window-terminology.md#pc-mode电脑模式)下生效，在其他设备中调用不生效不报错。|
