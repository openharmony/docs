# @ohos.userIAM.userAuthIcon (嵌入式用户身份认证控件)

提供应用界面上展示的人脸、指纹认证图标，具体功能如下：

1、提供嵌入式人脸、指纹认证控件图标，可被应用集成。

2、支持自定义图标的颜色和大小，但图标样式不可变更。

3、点击控件图标后可拉起系统弹窗式人脸、指纹认证控件。

> **说明：**
> - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的接口，其他公开接口参见[@ohos.userIAM.userAuth (用户认证)](js-apis-useriam-userauth.md)。


## 导入模块

```ts
import userAuthIcon from '@ohos.userIAM.userAuthIcon';
```

## 属性

不支持[通用属性](../apis-arkui/arkui-js/js-components-common-attributes.md)，仅支持如下属性:

| 名称           | 类型                                                         | 必填 | 说明                                                         |
| -------------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| authParam      | [AuthParam](js-apis-useriam-userauth.md#authparam10)        | 是   | 用户认证相关参数。                                             |
| widgetParam    | [WidgetParam](js-apis-useriam-userauth.md#widgetparam10)    | 是   | 用户认证界面配置相关参数。                                      |
| iconHeight     | [Dimension](../apis-arkui/arkui-ts/ts-types.md#dimension10) | 否   | 设置icon的高度，宽高比1:1，默认64。                             |
| iconColor      | [ResourceColor](../apis-arkui/arkui-ts/ts-types.md#resourcecolor) | 否   | 设置icon的颜色，默认值：$r('sys.color.ohos_id_color_activated')。|

## 方法

不支持[通用方法](js-components-common-methods.md)，仅支持如下方法：

| 名称           | 类型                                                           | 必填 | 说明                                                         |
| -------------- | ------------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| onIconClick    | ()=>void                                                      | 否   | 用户点击icon回调接口。                                         |
| onAuthResult   | [UserAuthResult](js-apis-useriam-userauth.md#userauthresult10)| 是   | 用户认证结果信息回调接口，使用此方法需申请权限：ohos.permission.ACCESS_BIOMETRIC。    |

## 示例

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
