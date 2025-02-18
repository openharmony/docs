# @ohos.app.ability.FenceExtensionContext (FenceExtensionContext系统接口)

FenceExtensionContext是FenceExtensionAbility的上下文环境，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)，提供FenceExtensionAbility的相关配置信息以及启动Ability接口。

> **说明：**
>
> 本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。  
> 本模块接口为系统接口。

## 导入模块

```ts
import { FenceExtensionContext } from '@kit.LocationKit';
```

## 使用说明

在使用FenceExtensionContext的功能前，需要通过FenceExtensionAbility获取。

```ts
import { FenceExtensionAbility, FenceExtensionContext } from '@kit.LocationKit';

class MyFenceExtensionAbility extends FenceExtensionAbility {
  onCreate() {
    let fenceExtensionContext: FenceExtensionContext = this.context;
  }
}
```

## FenceExtensionContext.startAbility

startAbility(want: Want): Promise&lt;void&gt;

启动Ability。使用Promise异步回调。仅支持在主线程调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Location.Location.Geofence

**参数：**

| 参数名 |                类型               | 必填 |              说明               |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是  | 	启动Ability的want信息。 |

**返回值：**

| 类型          | 说明                                |
| ------------ | ---------------------------------- |
| Promise&lt;void&gt; | Promise形式返回启动结果。 |

**错误码：**

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202     | The application is not system-app, can not use system-api.      |
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |
| 16000001 | The specified ability does not exist.                        |
| 16000002 | Incorrect ability type.                                      |
| 16000004 | Can not start invisible component.                           |
| 16000005 | The specified process does not have the permission.          |
| 16000006 | Cross-user operations are not allowed.                       |
| 16000008 | The crowdtesting application expires.                        |
| 16000009 | An ability cannot be started or stopped in Wukong mode.      |
| 16000011 | The context does not exist.                                  |
| 16000050 | Internal error.                                              |
| 16000053 | The ability is not on the top of the UI.                     |
| 16000055 | Installation-free timed out.                                 |
| 16200001 | The caller has been released.                                |
| 16300003 | The target application is not self application.              |

以上错误码详细介绍请参考[元能力子系统错误码](../apis-ability-kit/errorcode-ability.md)。

**示例：**

```ts
import { FenceExtensionAbility, geoLocationManager } from '@kit.LocationKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

export class MyFenceExtensionAbility extends FenceExtensionAbility {
  onFenceStatusChange(transition: geoLocationManager.GeofenceTransition, additions: Record<string, string>): void {
    // 接受围栏状态变化事件，处理业务逻辑
    console.info(`on geofence transition,id:${transition.geofenceId},event:${transition.transitionEvent},additions:${JSON.stringify(additions)}`);
    let want: Want = {
      bundleName: "com.example.myapp",
      abilityName: "MyServiceExtensionAbility"
    };
    try {
      this.context.startAbility(want)
        .then(() => {
          // 执行正常业务
          console.info('startAbility succeed');
        })
        .catch((error: BusinessError) => {
          // 处理业务逻辑错误
          console.info('startAbility failed, error.code: ' + JSON.stringify(error.code) +
            ' error.message: ' + JSON.stringify(error.message));
        });
    } catch (paramError) {
      // 处理入参错误异常
      let code = (paramError as BusinessError).code;
      let message = (paramError as BusinessError).message;
      console.info('startAbility failed, error.code: ' + JSON.stringify(code) +
        ' error.message: ' + JSON.stringify(message));
    }
  }
}
```