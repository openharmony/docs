# 使用粘贴控件

<!--Kit: ArkUI-->
<!--Subsystem: Security-->
<!--Owner: @harylee-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

粘贴控件是一种特殊的系统安全控件，它允许应用在用户的授权下无提示地读取剪贴板数据。

集成粘贴控件后，单击该控件时，应用读取剪贴板数据不会弹窗提示。适用于任何需要读取剪贴板的应用场景，避免弹窗干扰用户。

例如，用户在应用外（如短信）复制了验证码，要在应用内粘贴验证码。用户原来在进入应用后，还需要长按输入框、在弹出的选项中点击粘贴，才能完成输入。而使用粘贴控件，用户只需进入应用后直接点击粘贴按钮，即可一步到位。

粘贴控件效果如图所示。

![zh-cn_image_0000001760763261](figures/zh-cn_image_0000001760763261.gif)

## 约束与限制

- 临时授权会持续到灭屏、应用切后台或应用退出时终止。

- 应用在授权期间的调用次数无限制。

- 为了保障用户隐私，应用需确保安全控件可见且可识别。开发者应合理配置控件的尺寸和颜色等属性，避免视觉混淆。若因控件样式不合法导致授权失败请检查设备错误日志。

## 开发步骤

以简化用户填写验证码为例，参考以下步骤：单击控件获取临时授权，将内容粘贴到文本框。效果图见上文。

1. 导入剪贴板依赖。
   
   ```ts
   import { pasteboard } from '@kit.BasicServicesKit';
   ```

2. 添加输入框和粘贴控件。
   
   粘贴控件是一种类似按钮的安全控件，由图标、文本和背景组成。其中，背景是必选的，而图标和文本至少需要选择其一。图标和文本不支持自定义，仅能在已有的选项中选择。

   应用安全控件的接口时，分为传参和不传参两种情况。不传参时，默认创建包含图标、文本和背景的按钮；传参时，根据传入的参数创建按钮，不包含未配置的元素。

   当前示例使用了默认参数。具体详情，请参见[PasteButton控件](../../reference/apis-arkui/arkui-ts/ts-security-components-pastebutton.md)。此外，所有安全控件均继承了[安全控件通用属性](../../reference/apis-arkui/arkui-ts/ts-securitycomponent-attributes.md)，可用于自定义样式。
   
   ```ts
   import { pasteboard, BusinessError } from '@kit.BasicServicesKit';
   
   @Entry
   @Component
   struct Index {
     @State message: string = '';
   
     build() {
       Row() {
         Column({ space: 10 }) {
           TextInput({ placeholder: '请输入验证码', text: this.message })
           PasteButton()
             .padding({top: 12, bottom: 12, left: 24, right: 24})
             .onClick((event: ClickEvent, result: PasteButtonOnClickResult) => {
               if (PasteButtonOnClickResult.SUCCESS === result) {
                 pasteboard.getSystemPasteboard().getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
                   if (err) {
                     console.error(`Failed to get paste data. Code is ${err.code}, message is ${err.message}`);
                     return;
                   }
                   // 剪贴板内容为 '123456'。
                   this.message = pasteData.getPrimaryText();
                 });
               }
             })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
