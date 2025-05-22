# IAM Subsystem ChangeLog

## cl.useriam.1 Change of @ohos.useriam.userAuthIcon for Export

**Access Level**

Public API

**Reason for Change**

**userAuthIcon** does not comply with the naming rules for export and has been changed to **UserAuthIcon**.

**Change Impact**

This change is incompatible and will cause a compilation error. The error information is as follows:
```
'"@kit.UserAuthenticationKit"' has no exported member named 'userAuthIcon'. Did you mean 'UserAuthIcon'? <ArkTSCheck>.
```

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.31

**Before the Change**
```ts
import { userAuth, userAuthIcon } from '@kit.UserAuthenticationKit';
```

**After the Change**
```ts
import { userAuth, UserAuthIcon } from '@kit.UserAuthenticationKit';
```

**Adaptation Guide**
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
    title: 'Verify identity'
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
