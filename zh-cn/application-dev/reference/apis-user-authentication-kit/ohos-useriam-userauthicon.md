# @ohos.userIAM.userAuthIcon (嵌入式用户身份认证控件)

提供应用界面上展示的人脸、指纹认证图标，具体功能如下：

1. 提供嵌入式的人脸、指纹认证控件图标，可被应用集成。

2. 支持自定义图标的颜色和大小，但图标样式不可变更。

3. 点击控件图标后将以系统弹窗的方式，拉起人脸、指纹认证控件。

> **说明：**
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { userAuth, UserAuthIcon } from '@kit.UserAuthenticationKit';
```


## 子组件

无


## 属性

不支持通用属性。

## UserAuthIcon

UserAuthIcon({
  authParam: userAuth.AuthParam,
  widgetParam: userAuth.WidgetParam,
  iconHeight?: Dimension,
  iconColor?: ResourceColor,
  onIconClick?: ()=>void,
  onAuthResult: (result: userAuth.UserAuthResult)=>void
})

**装饰器类型：**\@Component

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.UserIAM.UserAuth.Core

**参数：**

| 名称           | 类型                                                         | 必填 | 说明                                                         |
| -------------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| authParam      | [AuthParam](js-apis-useriam-userauth.md#authparam10)        | 是   | 用户认证相关参数。                                             |
| widgetParam    | [WidgetParam](js-apis-useriam-userauth.md#widgetparam10)    | 是   | 用户认证界面配置相关参数。                                      |
| iconHeight     | [Dimension](../apis-arkui/arkui-ts/ts-types.md#dimension10) | 否   | 设置icon的高度，宽高比1:1，默认64。                             |
| iconColor      | [ResourceColor](../apis-arkui/arkui-ts/ts-types.md#resourcecolor) | 否   | 设置icon的颜色，默认值：$r('sys.color.ohos_id_color_activated')。|
| onIconClick    | ()=>void                                                      | 否   | 用户点击icon回调接口。                                         |
| onAuthResult   | (result: [UserAuthResult](js-apis-useriam-userauth.md#userauthresult10))=>void| 是   | 用户认证结果信息回调接口。<br/>**需要权限：** ohos.permission.ACCESS_BIOMETRIC  |


## 事件

不支持通用事件。

## 示例

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
            console.info(`Get user auth result, result = ${JSON.stringify(result)}`);
          }
        })
      }
    }
  }
}
```

调用onAuthResult可能会抛出错误码，错误码详细介绍请参见[用户认证错误码](errorcode-useriam.md)。

**人脸认证图例：**

![人脸图标](figures/user_auth_icon_face.png)

**指纹认证图例：**

![指纹图标](figures/user_auth_icon_fingerprint.png)
