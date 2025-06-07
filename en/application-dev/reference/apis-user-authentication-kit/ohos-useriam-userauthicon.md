# @ohos.userIAM.userAuthIcon (Embedded User Authentication Widget)

The system provides **userAuthIcon** to simplify the user authentication process. With **userAuthIcon**, you can:

- Easily integrate the facial authentication and fingerprint authentication icons into your applications.

- Customize the color and size of the icons. The icon style cannot be changed.

- Start the facial or fingerprint authentication pop-up component once the icon is tapped.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { userAuth, UserAuthIcon } from '@kit.UserAuthenticationKit';
```


## Child Components

None.


## Attributes

The universal attributes are not supported.

## UserAuthIcon

UserAuthIcon({
  authParam: userAuth.AuthParam,
  widgetParam: userAuth.WidgetParam,
  iconHeight?: Dimension,
  iconColor?: ResourceColor,
  onIconClick?: ()=>void,
  onAuthResult: (result: userAuth.UserAuthResult)=>void
})

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.UserIAM.UserAuth.Core

**Parameters**

| Name          | Type                                                        | Mandatory| Description                                                        |
| -------------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| authParam      | [AuthParam](js-apis-useriam-userauth.md#authparam10)        | Yes  | User authentication parameters.                                            |
| widgetParam    | [WidgetParam](js-apis-useriam-userauth.md#widgetparam10)    | Yes  | Parameters on the user authentication page.                                     |
| iconHeight     | [Dimension](../apis-arkui/arkui-ts/ts-types.md#dimension10) | No  | Height of the icon. <br/>The aspect ratio is 1:1. <br/>The default value is **64**.                  |
| iconColor      | [ResourceColor](../apis-arkui/arkui-ts/ts-types.md#resourcecolor) | No  | Color of the icon. The default value is **$r('sys.color.ohos_id_color_activated')**.|
| onIconClick    | ()=>void                                                      | No  | Callback to be invoked when the icon is tapped.                                        |
| onAuthResult   | (result: [UserAuthResult](js-apis-useriam-userauth.md#userauthresult10))=>void| Yes  | Callback used to return the user authentication result.<br>**Required permissions**: ohos.permission.ACCESS_BIOMETRIC |


## Events

Universal events are not supported.

## Example

```ts
import { cryptoFramework } from '@kit.CryptoArchitectureKit';
import { userAuth, UserAuthIcon } from '@kit.UserAuthenticationKit';

@Entry
@Component
struct Index {
  rand = cryptoFramework.createRandom();
  len: number = 16;
  randData: Uint8Array = this.rand?.generateRandomSync(this.len)?.data;
  authParam: userAuth.AuthParam = {
    challenge: this.randData,
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
            console.info(`Get user auth result, result = ${JSON.stringify(result)}`);
          }
        })
      }
    }
  }
}
```

An error may be thrown when **onAuthResult** is called. For details about the error codes, see [User Authentication Error Codes](errorcode-useriam.md).

**Facial authentication icon**

![Face Icon](figures/user_auth_icon_face.png)

**Fingerprint authentication icon**

![Fingerprint icon](figures/user_auth_icon_fingerprint.png)
