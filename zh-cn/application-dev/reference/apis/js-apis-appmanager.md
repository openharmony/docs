# appManager

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


App管理。


## 导入模块

  
```js
import app from '@ohos.application.appManager';
```


## appManager.isRunningInStabilityTest<sup>8+</sup>

static isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

查询当前是否处于稳定性测试场景。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 否 | 返回当前是否处于稳定性测试场景。 | 

**示例：**
    
  ```js
  import app from '@ohos.application.appManager';
  app.isRunningInStabilityTest((err, flag) => {
      console.log('startAbility result:' + JSON.stringfy(err));
  })  
  ```


## appManager.isRunningInStabilityTest<sup>8+</sup>

static isRunningInStabilityTest(): Promise&lt;boolean&gt;

查询当前是否处于稳定性测试场景。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 返回当前是否处于稳定性测试场景。 | 

**示例：**
    
  ```js
  import app from '@ohos.application.appManager';
  app.isRunningInStabilityTest().then((flag) => {
      console.log('success:' + JSON.stringfy(flag));
  }).catch((error) => {
      console.log('failed:' + JSON.stringfy(error));
  });
  ```


## appManager.isRamConstrainedDevice

isRamConstrainedDevice(): Promise\<boolean>;

它是ram受限设备吗。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 是否为ram受限设备。 | 

**示例：**
    
  ```js
  IsRamConstrainedDevicePromise(){
        app.isRamConstrainedDevicePromise().then((data) => {
            console.log('success:' + JSON.stringify(data));
        }).catch((error) => {
            console.log('failed:' + JSON.stringify(error));
        });
    }
  ```

## appManager.isRamConstrainedDevice

isRamConstrainedDevice(callback: AsyncCallback\<boolean>): void;

它是ram受限设备吗。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 否 | 返回当前是否是ram受限设备。 | 

**示例：**
    
  ```js
  IsRamConstrainedDeviceCallBack(){
        app.isRamConstrainedDevicePromise((err, data) => {
            console.log('startAbility result failed:' + JSON.stringify(err));
            console.log('startAbility result success:' + JSON.stringify(data));
        })
    }
  ```

## appManager.getAppMemorySize

getAppMemorySize(): Promise\<number>;

获取应用程序的内存大小。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;number&gt; | 应用程序内存大小。 | 

**示例：**
    
  ```js
  GetAppMemorySize(){
        app.getAppMemorySize().then((data) => {
            console.log('success:' + JSON.stringify(data));
        }).catch((error) => {
            console.log('failed:' + JSON.stringify(error));
        });
    }
  ```

## appManager.getAppMemorySize

getAppMemorySize(callback: AsyncCallback\<number>): void;

获取应用程序的内存大小。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | 否 | 应用程序内存大小。 | 

**示例：**
    
  ```js
  GetAppMemorySizeCallBack(){
        app.getAppMemorySize((err, data) => {
            console.log('startAbility result failed :' + JSON.stringify(err));
            console.log('startAbility result success:' + JSON.stringify(data));
        })
    }
  ```