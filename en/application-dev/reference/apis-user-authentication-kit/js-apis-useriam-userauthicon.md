# @ohos.userIAM.userAuthIcon (Embedded User Authentication Control)

Provide face and fingerprint authentication icon displayed on the application interface, with specific functions as follows:
1. Provide embedded face and fingerprint authentication control icon that can be integrated into applications.
2. Support customizing the color and size of icon, but the icon style cannot be changed.
3. After clicking on the control icon, the system pop-up style face and fingerprint authentication control can be pulled up.

> **说明：**
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the APIs provided by the module. For details about its public APIs, see [@ohos.userIAM.userAuth (User Authentication)](js-apis-useriam-userauth.md).



## Modules to Import

```ts
import userAuthIcon from '@ohos.userIAM.userAuthIcon';
```

## Attributes

Only the following attributes are supported.

| Name           | Type                                                         | Mandatory | Description                                                                    |
| -------------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------------------------------ |
| authParam      | [AuthParam](js-apis-useriam-userauth.md#authparam10)        | Yes  | The user authentication parameters.                                                  |
| widgetParam    | [UserAuthType](js-apis-useriam-userauth.md#widgetparam10)   | Yes  | Represents the information presented on the user authentication page.                |
| iconHeight     | [Dimension](../apis-arkui/arkui-ts/ts-types.md#dimension10)                        | No   | Set the height of the icon, width and height ratio 1:1, default value is 64.         |
| iconColor      | [ResourceColor](../apis-arkui/arkui-ts/ts-types.md#resourcecolor)         | No   | Set the color of the icon, default value is $r('sys.color.ohos_id_color_activated')  |

## Methods

Only the following methods are supported.

| Name           | Type                                                          | Mandatory | Description                                                   |
| -------------- | ------------------------------------------------------------- | ---- | ------------------------------------------------------------       |
| onIconClick    | ()=>void                                                      | No   | Notify the application that a click event has been triggered.      |
| onAuthResult   | [UserAuthResult](js-apis-useriam-userauth.md#userauthresult10)| Yes  | Notify the application of user authentication result information.You need to apply for permission:ohos.permission.ACCESS_BIOMETRIC to use user authentication ability.  |

**Demo：**

```ts
import userAuth from '@ohos.userIAM.userAuth';
import UserAuthIcon from '@ohos.userIAM.userAuthIcon';

@Entry
@Component
struct Index {
  authParam: userAuth.AuthParam = {
    challenge: new Uint8Array([49, 49, 49, 49, 49, 49]),
    authType: [userAuth.UserAuthType.FACE, userAuth.UserAuthType.PIN],
    authTrustLevel: userAuth.AuthTrustLevel.ATL3,
  };
  widgetParam: userAuth.WidgetParam = {
    title: 'Please complete user authentication',
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
            console.info("The user clicked the icon.");
          },
          onAuthResult: (result: userAuth.UserAuthResult) => {
            console.info('Get user auth result, result = ' + JSON.stringify(result));
          },
        })
      }
    }
  }
}
```
