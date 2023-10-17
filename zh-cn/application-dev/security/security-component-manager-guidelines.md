# 安全控件开发指导


## 场景介绍

安全控件是OpenHarmony提供的一组系统实现的ArkUI组件，应用集成这类组件就可以实现在用户点击后自动授权，而无需弹窗授权。

目前有三类安全控件，分别是位置控件（LocationButton）、粘贴控件（PasteButton）、保存控件（SaveButton），分别对应精准定位、剪贴板读取、媒体库写入三类特权，下面分别说明这三种使用场景。

- 位置控件（LocationButton）

应用集成位置控件后，用户点击该控件，不管应用有没有申请过或者授予精准定位权限，都会在本次前台期间获得精准定位的授权，可以调用位置服务获取精准定位。精准定位的临时授权会持续到灭屏、应用切后台、应用退出等任一情况发生，之后恢复到临时授权之前的授权状态（授予/未授予/未申请）。应用在授权期间没有调用特权接口的次数限制。

使用场景：应用本身不是强位置关联应用（如导航、运动健康等），仅在"部分场景前台"需要使用位置信息（如：定位城市、打卡、分享位置等），如果需要长时间或者后台使用位置信息，建议申请权限。

- 粘贴控件（PasteButton）

应用集成粘贴控件后，用户点击该控件，会在本次前台期间获得读取剪贴板的授权，应用可以调用剪贴板读取接口，临时授权会持续到灭屏、应用切后台、应用退出情况发生，应用在授权期间没有次数限制。

使用场景：粘贴控件可以用于任何应用需要读取剪贴板的场景，避免toast提示对用户造成干扰。

- 保存控件（SaveButton）

应用集成保存控件后，用户点击该控件，应用会获取10秒内不限制次数的访问媒体库特权接口的授权。

开发者需要注意：

1. 应用在onClick()触发回调到调用媒体库特权接口的时间间隔不大于10秒。

2. 用户点击一次可以多次访问媒体库特权接口。

3. 使用场景：保存控件可以用于任何应用需要保存文件到媒体库的场景（保存图片、保存视频等），区别于使用filepicker方式（filepicker需要拉起系统应用，再由用户选择具体路径保存文件），安全控件操作更快捷。


## 创建方式

安全控件是由图标、文本、背景组成的类似button的按钮，其中图标、文本两者至少有其一，背景是可选的。图标和文本不支持自定义，仅支持在已有的选项中选择。应用申明安全控件的接口时，分为传参和不传参两种，不传参默认创建图标+文字+背景的按钮，传参根据传入的参数创建，不包含没有配置的元素。

例如保存控件：

```
/* 默认样式 */
SaveButton()

/* 只有图标的样式 */
SaveButton({ icon:SaveIconStyle.FULL_FILLED })

/* 只有文字和图标的样式 */
SaveButton({ icon:SaveIconStyle.FULL_FILLED, text:SaveDescription.DOWNLOAD })
```


## 公共属性

安全控件有公共的UX属性，应用可以通过这些属性定制样式。

| 属性名 | 描述 |
| -------- | -------- |
| iconSize(value: Dimension) | 设置安全控件的图标尺寸 |
| layoutDirection(value: SecurityComponentLayoutDirection) | 设置安全控件上图标和文字分布的方向 |
| position(value: Position) | 设置绝对定位 |
| markAnchor(value: Position) | 设置绝对定位的锚点 |
| offset(value: Position) | 设置相对定位 |
| fontSize(value: Dimension) | 设置安全控件上的文字尺寸 |
| fontStyle(value: FontStyle) | 设置安全控件上的文字样式 |
| fontWeight(value: number \| FontWeight \| string) | 设置安全控件上文字粗细 |
| fontFamily(value: string \| Resource) | 设置安全控件上文字的字体 |
| fontColor(value: ResourceColor) | 设置安全控件上文字颜色 |
| iconColor(value: ResourceColor) | 设置安全控件上图标颜色 |
| backgroundColor(value: ResourceColor) | 设置安全控件的背景颜色 |
| borderStyle(value: BorderStyle) | 设置安全控件边框的样式 |
| borderWidth(value: Dimension) | 设置安全控件边框的宽度 |
| borderColor(value: ResourceColor) | 设置安全控件的边框颜色 |
| borderRadius(value: Dimension) | 设置安全控件的边框圆角半径 |
| padding(value: Padding \| Dimension) | 设置安全控件的内边距 |
| textIconSpace(value: Dimension) | 设置安全控件中图标和文字的间距 |


## 开发步骤

1. ets文件中声明安全控件。
   ```
      LocationButton()
   ```

2. 配置安全控件的属性。
   ```
      LocationButton().iconSize(40.0)
   ```

3. 注册onCLick回调，回调中调用特权接口，以位置控件为例，获取定位信息。
   ```
   import geoLocationManager from '@ohos.geoLocationManager';
   import BusinessError from "@ohos.base";
   @Entry
   @Component
   struct locationButton {
     build() {
       Row() {
         Column() {
           LocationButton({ icon: LocationIconStyle.FULL_FILLED }).iconSize(40.0)
             .onClick((event: ClickEvent, result: LocationButtonOnClickResult) => {
               if (result == LocationButtonOnClickResult.SUCCESS) {
                 /* 示例接口来自js-apis-geoLocationManager.md#currentlocationrequest */
                 let requestInfo:geoLocationManager.CurrentLocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET,'maxAccuracy': 0};
                 let locationChange = (err:BusinessError.BusinessError, location:geoLocationManager.Location):void => {
                   if (err) {
                     console.log('locationChanger: err=' + JSON.stringify(err));
                   }
                   if (location) {
                     console.log('locationChanger: location=' + JSON.stringify(location));
                   }
                 };

                 try {
                   geoLocationManager.getCurrentLocation(requestInfo, locationChange);
                 } catch (err) {
                   console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
                 }
               }
             })
         }.width('100%')
       }.height('100%')
     }
   }
   ```
