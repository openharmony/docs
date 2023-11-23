# @ohos.runningLock    
该模块主要提供RunningLock锁相关操作的接口，包括创建、查询、持锁、释放锁等操作。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import runningLock from '@ohos.runningLock'    
```  
    
## RunningLock    
### lock<sup>(deprecated)</sup>    
锁定和持有RunningLock。  
 **调用形式：**     
- lock(timeout: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: RunningLock#hold。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.RUNNING_LOCK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeout<sup>(deprecated)</sup> | number | true | 锁定和持有RunningLock的时长，单位：毫秒。 |  
    
 **示例代码：**   
```js    
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND).then((lock: runningLock.RunningLock) => {    lock.lock(500);    console.info('create running lock and lock success');}).catch((err: { code: number, message: string }) => {    console.error('create running lock failed, err: ' + err);});    
```    
  
    
### hold<sup>(9+)</sup>    
锁定和持有RunningLock。  
 **调用形式：**     
- hold(timeout: number): void  
  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.RUNNING_LOCK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeout | number | true | 锁定和持有RunningLock的时长，单位：毫秒。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND)  
.then((lock: runningLock.RunningLock) => {  
    console.info('create running lock success');  
    try {  
        lock.hold(500);  
        console.info('hold running lock success');  
    } catch(err) {  
        console.error('hold running lock failed, err: ' + err);  
    }  
})  
.catch((err: { code: number, message: string }) => {  
    console.error('create running lock failed, err: ' + err);  
});  
    
```    
  
    
### isUsed<sup>(deprecated)</sup>    
查询当前RunningLock是持有状态还是释放状态。  
 **调用形式：**     
- isUsed(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: RunningLock#isHolding。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示当前RunningLock是持有状态，返回false表示当前RunningLock是释放状态。 |  
    
 **示例代码：**   
```js    
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND).then((lock: runningLock.RunningLock) => {    let isUsed = lock.isUsed();    console.info('check running lock used status: ' + isUsed);}).catch((err: { code: number, message: string }) => {    console.error('check running lock used status failed, err: ' + err);});    
```    
  
    
### isHolding<sup>(9+)</sup>    
查询当前RunningLock是持有状态还是释放状。  
 **调用形式：**     
- isHolding(): boolean  
  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示当前RunningLock是持有状态，返回false表示当前RunningLock是释放状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND)  
.then((lock: runningLock.RunningLock) => {  
    console.info('create running lock success');  
    try {  
        let isHolding = lock.isHolding();  
        console.info('check running lock holding status: ' + isHolding);  
    } catch(err) {  
        console.error('check running lock holding status failed, err: ' + err);  
    }  
})  
.catch((err: { code: number, message: string }) => {  
    console.error('create running lock failed, err: ' + err);  
});  
    
```    
  
    
### unlock<sup>(deprecated)</sup>    
释放RunningLock锁。  
 **调用形式：**     
- unlock(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: RunningLock#unhold。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.RUNNING_LOCK    
 **示例代码：**   
```js    
runningLock.createRunningLock('running_lock_test', runningLock.RunningLockType.BACKGROUND).then((lock: runningLock.RunningLock) => {    lock.unlock();    console.info('create running lock and unlock success');}).catch((err: { code: number, message: string }) => {    console.error('create running lock failed, err: ' + err);});    
```    
  
    
### unhold<sup>(9+)</sup>  
 **调用形式：**     
- unhold(): void  
  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.RUNNING_LOCK    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 4900101 |  |  
    
## RunningLockType    
RunningLock锁的类型。    
    
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BACKGROUND<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 10 开始废弃。<br>阻止系统休眠的锁。<br>**说明：** 从API version 7开始支持，从API version 10开始废弃。 |  
| PROXIMITY_SCREEN_CONTROL | 2 | 通过接近或者远离状态来控制亮灭屏的锁。            |  
    
## isRunningLockTypeSupported<sup>(deprecated)</sup>    
查询系统是否支持该类型的锁。使用callback异步回调。  
 **调用形式：**     
- isRunningLockTypeSupported(type: RunningLockType, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: RunningLock#isSupported。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | RunningLockType | true |  需要查询的锁的类型。  |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。当查询成功，err为undefined，data为获取到的支持情况，返回true表示支持，返回false表示不支持；否则为错误对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```js    
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.BACKGROUND, (err: Error, data: boolean) => {  
    if (typeof err === 'undefined') {  
        console.info('BACKGROUND lock support status: ' + data);  
    } else {  
        console.log('check BACKGROUND lock support status failed, err: ' + err);  
    }  
});  
    
```    
  
    
## isRunningLockTypeSupported<sup>(deprecated)</sup>    
查询系统是否支持该类型的锁。使用Promise异步回调。  
 **调用形式：**     
- isRunningLockTypeSupported(type: RunningLockType): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: RunningLock#isSupported。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | RunningLockType | true | 需要查询的锁的类型 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示支持；返回false表示不支持。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```js    
runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.BACKGROUND).then((data: boolean) => {    console.info('BACKGROUND lock support status: ' + data);}).catch((err: { code: number, message: string }) => {    console.log('check BACKGROUND lock support status failed, err: ' + err);});    
```    
  
    
## isSupported<sup>(9+)</sup>    
查询系统是否支持该类型的锁。  
 **调用形式：**     
- isSupported(type: RunningLockType): boolean  
  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | RunningLockType | true | 需要查询的锁的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示支持，返回false表示不支持。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    let isSupported = runningLock.isSupported(runningLock.RunningLockType.BACKGROUND);  
    console.info('BACKGROUND type supported: ' + isSupported);  
} catch(err) {  
    console.error('check supported failed, err: ' + err);  
}  
    
```    
  
    
## createRunningLock<sup>(deprecated)</sup>    
创建RunningLock锁。  
 **调用形式：**     
- createRunningLock(name: string, type: RunningLockType, callback: AsyncCallback\<RunningLock>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: RunningLock#create。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.RUNNING_LOCK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 锁的名字。  |  
| type<sup>(deprecated)</sup> | RunningLockType | true | 要创建的锁的类型。   |  
| callback<sup>(deprecated)</sup> | AsyncCallback<RunningLock> | true | 回调函数。当创建锁成功，err为undefined，data为创建的RunningLock；否则为错误对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
  
```js    
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND, (err: Error, lock: runningLock.RunningLock) => {  
    if (typeof err === 'undefined') {  
        console.info('created running lock: ' + lock);  
    } else {  
        console.error('create running lock failed, err: ' + err);  
    }  
});  
    
```    
  
    
## createRunningLock<sup>(deprecated)</sup>    
创建RunningLock锁。  
 **调用形式：**     
- createRunningLock(name: string, type: RunningLockType): Promise\<RunningLock>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: RunningLock#create。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.RUNNING_LOCK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 锁的名字。  |  
| type<sup>(deprecated)</sup> | RunningLockType | true | 要创建的锁的类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<RunningLock> | Promise对象，返回RunningLock锁对象。 |  
    
 **示例代码：**   
示例（Promise）：  
  
```js    
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND).then((lock: runningLock.RunningLock) => {    console.info('created running lock: ' + lock);}).catch((err: { code: number, message: string }) => {    console.error('create running lock failed, error: ' + err);});    
```    
  
    
## create<sup>(9+)</sup>    
创建RunningLock锁。  
 **调用形式：**     
    
- create(name: string, type: RunningLockType, callback: AsyncCallback\<RunningLock>): void    
起始版本： 9    
- create(name: string, type: RunningLockType): Promise\<RunningLock>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.RUNNING_LOCK    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 锁的名字。         |  
| type | RunningLockType | true | 要创建的锁的类型。        |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当创建锁成功，err为undefined，data为创建的RunningLock；否则为错误对象。 |  
| Promise<RunningLock> | Promise对象，返回RunningLock锁对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```js    
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND, (err: Error, lock: runningLock.RunningLock) => {  
    if (typeof err === 'undefined') {  
        console.info('created running lock: ' + lock);  
    } else {  
        console.error('create running lock failed, err: ' + err);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```js    
runningLock.create('running_lock_test', runningLock.RunningLockType.BACKGROUND).then((lock: runningLock.RunningLock) => {    console.info('created running lock: ' + lock);}).catch((err: { code: number, message: string }) => {    console.error('create running lock failed, error: ' + err);});    
```    
  
