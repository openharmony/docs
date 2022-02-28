# appManager

- [导入模块](#导入模块)
- [isRunningInStabilityTest](#isRunningInStabilityTest)
- [isRunningInStabilityTest](#isRunningInStabilityTest)


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API 8开始支持。


App运行相关信息。


## 导入模块

  
```
import app from '@ohos.application.appManager';
```


## isRunningInStabilityTest

static isRunningInStabilityTest(callback: AsyncCallback&lt;boolean&gt;): void

查询当前用户是否是一个稳定性测试。

- 参数：
    | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 否 | 返回当前是否处于稳定性测试场景。 | 

- 示例：
    
  ```
  import app from '@ohos.application.appManager';
  app.isRunningInStabilityTest((err， flag) => {
      console.log('startAbility result:' + JSON.stringfy(err);
  }  
  ```


## isRunningInStabilityTest

static isRunningInStabilityTest(): Promise&lt;boolean&gt;

查询当前是否处于稳定性测试场景。

- 返回值：
    | 类型 | 说明 | 
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 返回当前是否处于稳定性测试场景。 | 

- 示例：
    
  ```
  import app from '@ohos.application.appManager';
  app.isRunningInStabilityTest().then((flag) => {
      console.log('success:' + JSON.stringfy(flag));
  )).catch((error) => {
      console.log('failed:' + JSON.stringfy(error));
  });
  ```
