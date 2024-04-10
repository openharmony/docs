# 嵌入式用户身份认证控件介绍

主要用于提供应用界面上展示的人脸、指纹认证图标，具体功能如下：

1、提供嵌入式人脸、指纹认证控件图标，可被应用集成。

2、支持自定义图标的颜色和大小，但图标样式不可变更。

3、点击控件图标后可拉起系统弹窗式人脸、指纹认证控件。

当前支持使用认证控件的认证类型包括：

- 人脸认证

- 指纹认证

- 人脸+锁屏密码认证

- 指纹+锁屏密码认证

- 人脸+指纹+锁屏密码认证


## 参数说明

具体参数等信息，请参考对应的[API文档](../../reference/apis-user-authentication-kit/js-apis-useriam-userauthicon.md)。

## 开发步骤

1. [申请权限](prerequisites.md#申请权限)：ohos.permission.ACCESS_BIOMETRIC。

2. 指定用户认证相关参数[AuthParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authparam10)（包括挑战值、认证类型[UserAuthType](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#userauthtype8)列表和认证等级[AuthTrustLevel](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#authtrustlevel8)）、配置认证控件界面[WidgetParam](../../reference/apis-user-authentication-kit/js-apis-useriam-userauth.md#widgetparam10)，icon图标大小，icon图标的颜色，回调方法等，从而使用嵌入式用户身份认证控件。


**示例**

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
    title: '请进行身份认证',
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
