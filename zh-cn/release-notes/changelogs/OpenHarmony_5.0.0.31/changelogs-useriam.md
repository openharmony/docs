# 用户IAM子系统Changelog

## cl.useriam.1 @ohos.useriam.userAuthIcon导出命名变更

**访问级别**

公开接口

**变更原因**

不符合命名规范，需将导出命名从小驼峰userAuthIcon改为大驼峰UserAuthIcon。

**变更影响**

该变更为不兼容变更，会导致编译报错，报错信息如下：
```
'"@kit.UserAuthenticationKit"' has no exported member named 'userAuthIcon'. Did you mean 'UserAuthIcon'? <ArkTSCheck>。
```

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.31开始。

**修改前**
```ts
import { userAuth, userAuthIcon } from '@kit.UserAuthenticationKit';
```

**修改后**
```ts
import { userAuth, UserAuthIcon } from '@kit.UserAuthenticationKit';
```

**适配指导**
```ts
import { userAuth, UserAuthIcon } from '@kit.UserAuthenticationKit';

@Entry
@Component
struct Index {
  authParam: userAuth.AuthParam = {
    challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
    authType: [userAuth.UserAuthType.FACE, userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3
  };
  widgetParam: userAuth.WidgetParam = {
    title: '请进行身份认证'
  };

  build() {
    Row() {
      Column() {
        UserAuthIcon({
          authParam: this.authParam,
          widgetParam: this.widgetParam,
          iconHeight: 200,
          iconColor: Color.Blue,
          onIconClick: () => {
            console.info('The user clicked the icon.');
          },
          onAuthResult: (result: userAuth.UserAuthResult) => {
            console.info('Get user auth result, result = ' + JSON.stringify(result));
          }
        })
      }
    }
  }
}
```
