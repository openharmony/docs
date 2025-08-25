# 用户状态感知开发指导
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @zou_ye-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

UserStatus（用户状态感知）模块提供用户感知能力，可以感知到操作者特定状态，例如：检测用户年龄组。

详细的接口介绍请参考[userStatus接口](../../reference/apis-multimodalawareness-kit/js-apis-awareness-userStatus.md)。

## 感知用户年龄组开发指导
### 场景介绍
当应用需要获取用户年龄分类时，可以调用userStatus模块，例如判断设备具体操作者是儿童还是成年人。

### 接口说明

| 接口名                                                       | 描述                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type:'userAgeGroupDetected',callback:Callback&lt;UserClassification&gt;):void; | 订阅年龄群组检测功能，检测结果通过callback返回。 |
| off(type: 'userAgeGroupDetected', callback?: Callback&lt;UserClassification&gt;): void; | 取消年龄群组检测功能。                   |

### 约束与限制

 - 此功能如果设备不支持，将返回801错误码。

### 开发步骤

1. 导入模块。

   ```ts
   import { userStatus } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Callback } from '@ohos.base';
   ```

2. 定义回调，函数接受年龄群组检测结果。

   ```
   let callback : Callback<userStatus.UserClassification> = (data : userStatus.UserClassification) => {
     console.info('callback succeeded, ageGroup:' + data.ageGroup + ", confidence:" + data.confidence);
   };
   ```

3. 订阅年龄群组检测功能。

   ```
   try {
      userStatus.on('userAgeGroupDetected', callback);  
      console.info("on succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed on and err code is " + error.code);
   }
   ```

4. 取消订阅年龄群组检测功能。

   ```
   try {
      userStatus.off('userAgeGroupDetected');
      console.info("off succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed off and err code is " + error.code);
   }
   ```
