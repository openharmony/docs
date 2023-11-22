# @ohos.screen    
本模块提供管理屏幕的一些基础能力，包括获取屏幕对象，监听屏幕变化，创建和销毁虚拟屏幕等。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import screen from '@ohos.screen'    
```  
    
## getAllScreens    
获取所有的屏幕。  
 **调用形式：**     
    
- getAllScreens(callback: AsyncCallback\<Array\<Screen>>): void    
起始版本： 9    
- getAllScreens(): Promise\<Array\<Screen>>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回当前获取的屏幕对象集合。 |  
| Promise<Array<Screen>> | Promise对象。返回当前获取的屏幕对象集合。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 1400001 | Invalid display or screen. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let screenClass: screen.Screen | null = null;  
screen.getAllScreens((err: BusinessError, data: Array<screen.Screen>) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to get all screens. Cause:  ' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in getting all screens. Data:' + JSON.stringify(data));  
  screenClass = data[0];  
});  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let screenClass: screen.Screen | null = null;  
let promise: Promise<Array<screen.Screen>> = screen.getAllScreens();  
promise.then((data: Array<screen.Screen>) => {  
  screenClass = data[0];  
  console.log('Succeeded in getting all screens. Data:' + JSON.stringify(data));  
}).catch((err: BusinessError) => {  
  console.log('Failed to get all screens. Cause: ' + JSON.stringify(err));  
});  
    
```    
  
    
## on('connect' | 'disconnect' | 'change')    
开启屏幕状态变化的监听  
 **调用形式：**     
    
- on(eventType: 'connect' | 'disconnect' | 'change', callback: Callback\<number>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventType | string | true | 监听事件。<br/>-eventType为"connect"表示屏幕连接事件。<br/>-eventType为"disconnect"表示断开屏幕连接事件。<br/>-eventType为"change"表示屏幕状态改变事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回屏幕的id，该参数应为整数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let callback: Callback<number> = (data: number) => {  
    console.info('Succeeded in registering the callback for screen changes. Data: ' + JSON.stringify(data))  
  };  
  screen.on('connect', callback);  
} catch (exception) {  
  console.error('Failed to register the callback for screen changes. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
## off('connect' | 'disconnect' | 'change')    
关闭屏幕状态变化的监听。  
 **调用形式：**     
    
- off(eventType: 'connect' | 'disconnect' | 'change', callback?: Callback\<number>): void    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| eventType | string | true | 监听事件。<br/>-eventType为"connect"表示屏幕连接事件。<br/>-eventType为"disconnect"表示断开屏幕连接事件。<br/>-eventType为"change"表示屏幕状态改变事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回屏幕的id，该参数应为整数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
try {  
  let callback: Callback<number> = (data: number) => {  
    console.info('Succeeded in unregistering the callback for screen changes. Data: ' + JSON.stringify(data))  
  };  
  screen.off('connect', callback);  
} catch (exception) {  
  console.error('Failed to register the callback for screen changes. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
## makeExpand    
将屏幕设置为扩展模式，使用callback异步回调。  
 **调用形式：**     
    
- makeExpand(options: Array\<ExpandOption>, callback: AsyncCallback\<number>): void    
起始版本： 9    
- makeExpand(options: Array\<ExpandOption>): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | Array<ExpandOption> | true | 设置扩展屏幕的参数集合。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回扩展屏幕的群组id，其中id应为整数。 |  
| Promise<number> | Promise对象。返回扩展屏幕的群组id，其中id应为整数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1400001 | Invalid display or screen. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let groupId: number | null = null;  
  class ExpandOption {  
    screenId: number = 0;  
    startX: number = 0;  
    startY: number = 0;  
  }  
  let mainScreenOption: ExpandOption = { screenId: 0, startX: 0, startY: 0 };  
  let otherScreenOption: ExpandOption = { screenId: 1, startX: 1080, startY: 0 };  
  let expandOptionArray : ExpandOption[] = [ mainScreenOption, otherScreenOption ];  
  screen.makeExpand(expandOptionArray, (err: BusinessError, data: number) => {  
    const errCode: number = err.code;  
    if (errCode) {  
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
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  class ExpandOption {  
    screenId: number = 0;  
    startX: number = 0;  
    startY: number = 0;  
  }  
  let mainScreenOption: ExpandOption = { screenId: 0, startX: 0, startY: 0 };  
  let otherScreenOption: ExpandOption = { screenId: 1, startX: 1080, startY: 0 };  
  let expandOptionArray : ExpandOption[] = [ mainScreenOption, otherScreenOption ];  
  screen.makeExpand(expandOptionArray).then((  
    data: number) => {  
    console.info('Succeeded in expanding the screen. Data: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.error('Failed to expand the screen. Code:' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to expand the screen. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
## stopExpand<sup>(10+)</sup>    
停止屏幕的扩展模式  
 **调用形式：**     
    
- stopExpand(expandScreen: Array\<number>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- stopExpand(expandScreen: Array\<number>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| expandScreen | Array<number> | true | 扩展屏幕id集合，其中id应为整数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当停止屏幕扩展模式成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1400001 | Invalid display or screen. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let expandScreenIds: Array<number> = [1, 2, 3];  
  screen.stopExpand(expandScreenIds, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to stop expand screens. Code:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in stopping expand screens.');  
  });  
} catch (exception) {  
  console.error('Failed to stop expand screens. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let expandScreenIds: Array<number> = [1, 2, 3];  
  screen.stopExpand(expandScreenIds).then(() => {  
    console.info('Succeeded in stopping expand screens.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to stop expand screens. Code:' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to stop expand screens. Code:' + JSON.stringify(exception));  
};  
    
```    
  
    
## makeMirror    
将屏幕设置为镜像模式  
 **调用形式：**     
    
- makeMirror(mainScreen: number, mirrorScreen: Array\<number>, callback: AsyncCallback\<number>): void    
起始版本： 9    
- makeMirror(mainScreen: number, mirrorScreen: Array\<number>): Promise\<number>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mainScreen | number | true | 主屏幕id，该参数仅支持整数输入。 |  
| mirrorScreen | Array<number> | true |  镜像屏幕id集合，其中id应为整数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回镜像屏幕的群组id，其中id应为整数。 |  
| Promise<number> | Promise对象。返回镜像屏幕的群组id，其中id应为整数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1400001 | Invalid display or screen. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let mainScreenId: number = 0;  
let mirrorScreenIds: Array<number> = [1, 2, 3];  
try {  
  screen.makeMirror(mainScreenId, mirrorScreenIds, (err: BusinessError, data: number) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting screen mirroring. Data: ' + JSON.stringify(data));  
  });  
} catch (exception) {  
  console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let mainScreenId: number = 0;  
let mirrorScreenIds: Array<number> = [1, 2, 3];  
try {  
  screen.makeMirror(mainScreenId, mirrorScreenIds).then((data: number) => {  
    console.info('Succeeded in setting screen mirroring. Data: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set screen mirroring. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
## stopMirror<sup>(10+)</sup>    
停止屏幕的镜像模式  
 **调用形式：**     
    
- stopMirror(mirrorScreen: Array\<number>, callback: AsyncCallback\<void>): void    
起始版本： 10    
- stopMirror(mirrorScreen: Array\<number>): Promise\<void>    
起始版本： 10  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mirrorScreen | Array<number> | true | 镜像屏幕id集合，其中id应为整数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当停止屏幕镜像模式成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1400001 |  |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let mirrorScreenIds: Array<number> = [1, 2, 3];  
  screen.stopMirror(mirrorScreenIds, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to stop mirror screens. Code:' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in stopping mirror screens.');  
  });  
} catch (exception) {  
  console.error('Failed to stop mirror screens. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  let mirrorScreenIds: Array<number> = [1, 2, 3];  
  screen.stopMirror(mirrorScreenIds).then(() => {  
    console.info('Succeeded in stopping mirror screens.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to stop mirror screens. Code:' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to stop mirror screens. Code:' + JSON.stringify(exception));  
};  
    
```    
  
    
## createVirtualScreen    
创建虚拟屏幕  
 **调用形式：**     
    
- createVirtualScreen(options: VirtualScreenOption, callback: AsyncCallback\<Screen>): void    
起始版本： 9    
- createVirtualScreen(options: VirtualScreenOption): Promise\<Screen>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core  
 **需要权限：** ohos.permission.CAPTURE_SCREEN    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | VirtualScreenOption | true | 用于创建虚拟屏幕的参数。      |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回创建的虚拟屏幕对象。 |  
| Promise<Screen> | Promise对象。返回创建的虚拟屏幕对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 1400001 | Invalid display or screen. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let screenClass: screen.Screen | null = null;  
try {  
  class VirtualScreenOption {  
    name : string = '';  
    width : number =  0;  
    height : number = 0;  
    density : number = 0;  
    surfaceId : string = '';  
  }  
  
  let option : VirtualScreenOption = {   
    name: 'screen01',  
    width: 1080,  
    height: 2340,  
    density: 2,  
    surfaceId: ''  
  };  
  screen.createVirtualScreen(option, (err: BusinessError, data: screen.Screen) => {  
    const errCode: number = err.code;  
    if (errCode) {  
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
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let screenClass: screen.Screen | null = null;  
try {  
  class VirtualScreenOption {  
    name : string = '';  
    width : number =  0;  
    height : number = 0;  
    density : number = 0;  
    surfaceId : string = '';  
  }  
  
  let option : VirtualScreenOption = {   
    name: 'screen01',  
    width: 1080,  
    height: 2340,  
    density: 2,  
    surfaceId: ''  
  };  
  
  screen.createVirtualScreen(option).then((data: screen.Screen) => {  
    screenClass = data;  
    console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));  
  }).catch((err: BusinessError) => {  
    console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
## destroyVirtualScreen    
销毁虚拟屏幕  
 **调用形式：**     
    
- destroyVirtualScreen(screenId: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- destroyVirtualScreen(screenId: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| screenId | number | true | 屏幕的id，该参数仅支持整数输入。    |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当销毁虚拟屏幕成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1400002 | Unauthorized operation. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let screenId: number = 1;  
try {  
  screen.destroyVirtualScreen(screenId, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in destroying the virtual screen.');  
  });  
} catch (exception) {  
  console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let screenId: number = 1;  
try {  
  screen.destroyVirtualScreen(screenId).then(() => {  
    console.info('Succeeded in destroying the virtual screen.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to destroy the virtual screen. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
## setVirtualScreenSurface    
设置虚拟屏幕的surface  
 **调用形式：**     
    
- setVirtualScreenSurface(screenId: number, surfaceId: string, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setVirtualScreenSurface(screenId: number, surfaceId: string): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core  
 **需要权限：** ohos.permission.CAPTURE_SCREEN    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| screenId | number | true | 屏幕的id，该参数仅支持整数输入。 |  
| surfaceId | string | true | surface的id。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置虚拟屏幕surface成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 1400001 | Invalid display or screen. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let screenId: number = 1;  
let surfaceId: string = '2048';  
try {  
  screen.setVirtualScreenSurface(screenId, surfaceId, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
      console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(err));  
      return;  
    }  
    console.info('Succeeded in setting the surface for the virtual screen.');  
  });  
} catch (exception) {  
  console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let screenId: number = 1;  
let surfaceId: string = '2048';  
try {  
  screen.setVirtualScreenSurface(screenId, surfaceId).then(() => {  
    console.info('Succeeded in setting the surface for the virtual screen.');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the surface for the virtual screen. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
## isScreenRotationLocked    
查询当前自动转屏是否锁定  
 **调用形式：**     
    
- isScreenRotationLocked(callback: AsyncCallback\<boolean>): void    
起始版本： 9    
- isScreenRotationLocked(): Promise\<boolean>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。返回true表示当前自动转屏处于锁定状态；返回false表示当前自动转屏不处于锁定状态。 |  
| Promise<boolean> | Promise对象。返回true表示当前自动转屏处于锁定状态；返回false表示当前自动转屏不处于锁定状态。 |  
    
 **示例代码1：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
screen.isScreenRotationLocked().then((isLocked: boolean) => {  
  console.info('Succeeded in getting the screen rotation lock status. isLocked:' + JSON.stringify(isLocked));  
}).catch((err: BusinessError) => {  
  console.error('Failed to get the screen rotation lock status. Cause:' + JSON.stringify(err));  
});  
    
```    
  
    
 **示例代码2：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
screen.isScreenRotationLocked((err: BusinessError, isLocked: boolean) => {  
  const errCode: number = err.code;  
  if (errCode) {  
    console.error('Failed to get the screen rotation lock status. Cause:' + JSON.stringify(err));  
    return;  
  }  
  console.info('Succeeded in getting the screen rotation lock status. isLocked:' + JSON.stringify(isLocked));  
});  
    
```    
  
    
## setScreenRotationLocked    
设置自动转屏开关是否锁定  
 **调用形式：**     
    
- setScreenRotationLocked(isLocked: boolean, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setScreenRotationLocked(isLocked: boolean): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isLocked | boolean | true | 自动转屏开关是否锁定。true为锁定，false为未锁定. |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置自动转屏是否锁定成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isLocked: boolean = false;  
try {  
  screen.setScreenRotationLocked(isLocked).then(() => {  
    console.info('Succeeded in unlocking auto rotate');  
  }).catch((err: BusinessError) => {  
    console.error('Failed to unlock auto rotate. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to unlock auto rotate. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
 **示例代码2：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let isLocked: boolean = false;  
try {  
  screen.setScreenRotationLocked(isLocked, (err: BusinessError) => {  
    const errCode: number = err.code;  
    if (errCode) {  
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
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| screenId | number | false | true | 屏幕的id，该参数应为整数。     |  
| startX | number | false | true | 屏幕的起始X轴坐标，该参数应为整数。 |  
| startY | number | false | true | 屏幕的起始Y轴坐标，该参数应为整数。 |  
    
## VirtualScreenOption    
创建虚拟屏幕的参数。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | true | 指定虚拟屏幕的名称。  |  
| width | number | false | true |  指定虚拟屏幕的宽度，单位为像素，该参数应为整数。 |  
| height | number | false | true | 指定虚拟屏幕的高度，单位为像素，该参数应为整数。 |  
| density | number | false | true | 指定虚拟屏幕的密度，该参数为浮点数。  |  
| surfaceId | string | false | true | 指定虚拟屏幕的surfaceId。 |  
    
## ScreenSourceMode<sup>(10+)</sup>    
屏幕显示内容来源模式枚举。    
    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SCREEN_MAIN | 0 | 表示屏幕为默认主屏。 |  
| SCREEN_MIRROR | 1 | 表示屏幕内容来自镜像。 |  
| SCREEN_EXTEND | 2 | 表示屏幕内容来自扩展。  |  
| SCREEN_ALONE | 3 | 表示屏幕为未指定来源。 |  
    
## Screen    
屏幕实例。  
  
下列API示例中都需先使用[getAllScreens()](#screengetallscreens)、[createVirtualScreen()](#screencreatevirtualscreen)中的任一方法获取到Screen实例，再通过此实例调用对应方法。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
### 属性    
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| id | number | true | true | 屏幕的id，该参数应为整数。     |  
| parent | number | true | true | 屏幕所属群组的id，该参数应为整数。 |  
| supportedModeInfo | Array<ScreenModeInfo> | true | true | 屏幕支持的模式集合。 |  
| activeModeIndex | number | true | true | 当前屏幕所处模式索引。模式索引的当前值和值的范围，会根据屏幕当前分辨率、刷新率和设备硬件差异产生变化。该参数应为整数。 |  
| orientation | Orientation | true | true | 屏幕方向。 |  
| sourceMode<sup>(10+)</sup> | ScreenSourceMode | true | true | 屏幕来源模式。 |  
    
### setOrientation    
设置屏幕方向  
 **调用形式：**     
    
- setOrientation(orientation: Orientation, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setOrientation(orientation: Orientation): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| orientation | Orientation | true |  屏幕方向。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置屏幕方向成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
  try {  
    class VirtualScreenOption {  
      name : string = '';  
      width : number =  0;  
      height : number = 0;  
      density : number = 0;  
      surfaceId : string = '';  
    }  
  
    let option : VirtualScreenOption = {  
      name: 'screen01',  
      width: 1080,  
      height: 2340,  
      density: 2,  
      surfaceId: ''  
    };  
  
    screen.createVirtualScreen(option).then((data: screen.Screen) => {  
      let screenClass: screen.Screen = data;  
      console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));  
      screenClass.setOrientation(screen.Orientation.VERTICAL, (err: BusinessError) => {  
        const errCode: number = err.code;  
        if (errCode) {  
          console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(err));  
          return;  
        }  
        console.info('Succeeded in setting the vertical orientation.');  
      });  
    }).catch((err: BusinessError) => {  
      console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));  
    });  
  } catch (exception) {  
    console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(exception));  
  };  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
  try {  
    class VirtualScreenOption {  
      name : string = '';  
      width : number =  0;  
      height : number = 0;  
      density : number = 0;  
      surfaceId : string = '';  
    }  
  
    let option : VirtualScreenOption = {  
      name: 'screen01',  
      width: 1080,  
      height: 2340,  
      density: 2,  
      surfaceId: ''  
    };  
  
    screen.createVirtualScreen(option).then((data: screen.Screen) => {  
      let screenClass: screen.Screen = data;  
      console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));  
      let promise: Promise<void> = screenClass.setOrientation(screen.Orientation.VERTICAL);  
      promise.then(() => {  
        console.info('Succeeded in setting the vertical orientation.');  
      }).catch((err: BusinessError) => {  
        console.error('Failed to set the vertical orientation. Cause: ' + JSON.stringify(err));  
      });  
    }).catch((err: BusinessError) => {  
      console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));  
    });  
  } catch (exception) {  
    console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(exception));  
  };  
    
```    
  
    
### setScreenActiveMode    
设置屏幕当前显示模式  
 **调用形式：**     
    
- setScreenActiveMode(modeIndex: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setScreenActiveMode(modeIndex: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| modeIndex | number | true | 模式索引。模式索引的当前值和值的范围，会根据屏幕当前分辨率、刷新率和设备硬件差异产生变化，该参数仅支持整数输入。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置屏幕当前显示模式成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  class VirtualScreenOption {  
    name : string = '';  
    width : number =  0;  
    height : number = 0;  
    density : number = 0;  
    surfaceId : string = '';  
  }  
  
  let option : VirtualScreenOption = {  
    name: 'screen01',  
    width: 1080,  
    height: 2340,  
    density: 2,  
    surfaceId: ''  
  };  
  
  screen.createVirtualScreen(option).then((data: screen.Screen) => {  
    let screenClass: screen.Screen = data;  
    console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));  
    let modeIndex: number = 0;  
    screenClass.setScreenActiveMode(modeIndex, (err: BusinessError) => {  
      const errCode: number = err.code;  
      if (errCode) {  
        console.error('Failed to set screen active mode 0. Code: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('Succeeded in setting the vertical orientation.');  
    });  
  }).catch((err: BusinessError) => {  
    console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
try {  
  class VirtualScreenOption {  
    name : string = '';  
    width : number =  0;  
    height : number = 0;  
    density : number = 0;  
    surfaceId : string = '';  
  }  
  
  let option : VirtualScreenOption = {  
    name: 'screen01',  
    width: 1080,  
    height: 2340,  
    density: 2,  
    surfaceId: ''  
  };  
  
  screen.createVirtualScreen(option).then((data: screen.Screen) => {  
    let screenClass: screen.Screen = data;  
    console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));  
    let modeIndex: number = 0;  
    let promise: Promise<void> = screenClass.setScreenActiveMode(modeIndex);  
    promise.then(() => {  
      console.info('Succeeded in setting screen active mode 0.');  
    }).catch((err: BusinessError) => {  
      console.error('Failed to set screen active mode 0. Code: ' + JSON.stringify(err));  
    });  
  }).catch((err: BusinessError) => {  
    console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
### setDensityDpi    
设置屏幕的像素密度  
 **调用形式：**     
    
- setDensityDpi(densityDpi: number, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setDensityDpi(densityDpi: number): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| densityDpi | number | true | 像素密度。支持的输入范围为[80, 640]，该参数仅支持整数输入。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置屏幕的像素密度成功，err为undefined，否则为错误对象。 |  
| Promise<void> | 无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 1400003 | This display manager service works abnormally. |  
    
 **示例代码1：**   
示例（callback）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let densityDpi: number = 320;  
try {  
  class VirtualScreenOption {  
    name : string = '';  
    width : number =  0;  
    height : number = 0;  
    density : number = 0;  
    surfaceId : string = '';  
  }  
  
  let option : VirtualScreenOption = {  
    name: 'screen01',  
    width: 1080,  
    height: 2340,  
    density: 2,  
    surfaceId: ''  
  };  
  
  screen.createVirtualScreen(option).then((data: screen.Screen) => {  
    let screenClass: screen.Screen = data;  
    console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));  
    screenClass.setDensityDpi(densityDpi, (err: BusinessError) => {  
      const errCode: number = err.code;  
      if (errCode) {  
        console.error('Failed to set the pixel density of the screen to 320. Code: ' + JSON.stringify(err));  
        return;  
      }  
      console.info('Succeeded in setting the vertical orientation.');  
    });  
  }).catch((err: BusinessError) => {  
    console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
 **示例代码2：**   
示例（promise）  
```ts    
import { BusinessError } from '@ohos.base';  
  
let densityDpi: number = 320;  
try {  
  class VirtualScreenOption {  
    name : string = '';  
    width : number =  0;  
    height : number = 0;  
    density : number = 0;  
    surfaceId : string = '';  
  }  
  
  let option : VirtualScreenOption = {  
    name: 'screen01',  
    width: 1080,  
    height: 2340,  
    density: 2,  
    surfaceId: ''  
  };  
  
  screen.createVirtualScreen(option).then((data: screen.Screen) => {  
    let screenClass: screen.Screen = data;  
    let promise: Promise<void> = screenClass.setDensityDpi(densityDpi);  
    promise.then(() => {  
      console.info('Succeeded in setting the pixel density of the screen to 320.');  
    }).catch((err: BusinessError) => {  
      console.error('Failed to set the pixel density of the screen to 320. Code: ' + JSON.stringify(err));  
    });  
  }).catch((err: BusinessError) => {  
    console.error('Failed to create the virtual screen. Code: ' + JSON.stringify(err));  
  });  
} catch (exception) {  
  console.error('Failed to set the vertical orientation. Code: ' + JSON.stringify(exception));  
};  
    
```    
  
    
## Orientation    
屏幕方向枚举。    
## ScreenModeInfo    
屏幕显示模式信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.WindowManager.WindowManager.Core    
 **示例代码：**   
```ts    
import screen from '@ohos.screen';    
```    
  
