# User Status Awareness Development
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @zou_ye-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

The UserStatus module, designed for user status awareness, empowers the system to perceive specific conditions of the operator, such as determining their age group.

For details about the APIs, see the [userStatus API Reference](../../reference/apis-multimodalawareness-kit/js-apis-awareness-userStatus.md).

## How to Develop 
### When to Use
An application can invoke the UserStatus module when it needs to obtain the age group of users. This way, the application can determine, for example, whether the individual interacting with the device is a child or an adult.

### Available APIs

| API                                                      | Description                                  |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type:'userAgeGroupDetected',callback:Callback&lt;UserClassification&gt;):void; | Enables the age group detection function. This API returns the result through a callback.|
| off(type: 'userAgeGroupDetected', callback?: Callback&lt;UserClassification&gt;): void; | Disables the age group detection function.                  |

### Constraints

 - If the device does not support the age group detection function, error code 801 is returned.

### Development Procedure

1. Import the related modules.

   ```ts
   import { userStatus } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { Callback } from '@ohos.base';
   ```

2. Define the callback used to receive the age group detection result.

   ```
   let callback : Callback<userStatus.UserClassification> = (data : userStatus.UserClassification) => {
     console.info('callback succeeded, ageGroup:' + data.ageGroup + ", confidence:" + data.confidence);
   };
   ```

3. Enable the age group detection function.

   ```
   try {
      userStatus.on('userAgeGroupDetected', callback);  
      console.info("on succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed on and err code is " + error.code);
   }
   ```

4. Disable the age group detection function.

   ```
   try {
      userStatus.off('userAgeGroupDetected');
      console.info("off succeeded");
   } catch (err) {
      let error = err as BusinessError;
      console.error("Failed off and err code is " + error.code);
   }
   ```
