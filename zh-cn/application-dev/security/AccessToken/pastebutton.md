# 使用粘贴控件

粘贴控件是一种特殊的系统安全控件，它允许应用在用户的授权下无提示地读取剪贴板数据。

在应用集成粘贴控件后，用户点击该控件，应用读取剪贴板数据时不会弹窗提示。可以用于任何应用需要读取剪贴板的场景，避免弹窗提示对用户造成干扰。

例如，用户在应用外（如短信）复制了验证码，要在应用内粘贴验证码。用户原来在进入应用后，还需要长按输入框、在弹出的选项中点击粘贴，才能完成输入。而使用粘贴控件，用户只需进入应用后直接点击粘贴按钮，即可一步到位。

粘贴控件效果如图所示。

![zh-cn_image_0000001760763261](figures/zh-cn_image_0000001760763261.gif)

## 约束与限制

- 临时授权会持续到灭屏、应用切后台或应用退出时终止。

- 应用在授权期间没有调用次数限制。

- 为了保障用户的隐私不被恶意应用获取，应用需确保安全控件是可见的且用户能够识别的。开发者需要合理地配置控件的尺寸、颜色等属性，避免视觉混淆的情况，如果发生因控件的样式不合法导致授权失败的情况，请检查设备错误日志。

## 开发步骤

以简化用户填写验证码为例，参考以下步骤，实现效果：点击控件获取临时授权，粘贴内容到文本框，效果图请见上文。

1. 导入剪贴板依赖。
   
   ```ts
   import { pasteboard } from '@kit.BasicServicesKit';
   ```

2. 添加输入框和粘贴控件。
   
   粘贴控件是由图标、文本、背景组成的类似Button的按钮，其中图标、文本两者至少有其一，背景必选。图标和文本不支持自定义，仅支持在已有的选项中选择。

   应用申明安全控件的接口时，分为传参和不传参两种，不传参默认创建图标+文字+背景的按钮，传参根据传入的参数创建，不包含没有配置的元素。

   当前示例使用默认参数。具体请参见[PasteButton控件](../../reference/apis-arkui/arkui-ts/ts-security-components-pastebutton.md)。此外，所有安全控件都继承[安全控件通用属性](../../reference/apis-arkui/arkui-ts/ts-securitycomponent-attributes.md)，可用于定制样式。
   
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
