# Using PasteButton

The **PasteButton** component comes with the pasteboard (also called clipboard) read privilege, which allows an application to read data from the pasteboard without any prompt information.

After the component integrated into your application is tapped, no authorization dialog box will be displayed when your application reads data from the pasteboard. You can use this component for any application that needs to read data from the pasteboard, while eliminating the pop-up windows.

For example, if a user needs to copy a verification code (received from the Messaging application) to another application, the user has to touch and hold the input box, and select **Paste** from the options displayed. With the **PasteButton** component integrated into your application, the user only needs to tap the **Paste** button.

The following figure shows the effect of **PasteButton** component.

![](figures/PasteButton_effect.gif)

## Constraints

- The temporary authorization will be automatically revoked when the screen turns off, the application switches to the background, or the application exits.

- During the authorization period, there is no limit on the number of API calls.

- The **PasteButton** component must be visible and legible to users. You need to properly configure the component attributes such as the size and color to prevent authorization failures. If the authorization fails due to invalid component style, check the device error logs.

## How to Develop

The following procedure implements the following: After **Paste** is tapped, the text is pasted to the text box. See the figure above.

1. Import the dependency **pasteboard**.
   
   ```ts
   import { pasteboard } from '@kit.BasicServicesKit';
   ```

2. Add the text boxes and **PasteButton** component.
   
   **PasteButton** is a button-like component consisting of an icon, text, and background. Either the icon or text is mandatory, and the background is mandatory. The icon and text cannot be customized. You can only select from the existing options.

   When declaring the API for creating a security component, you can determine whether to pass in parameters. If parameters are passed in, the component is created based on the specified parameters. If no parameter is passed in, a component with default icon, text, and background is created.

   The following example uses the default parameters. For details, see [PasteButton](../../reference/apis-arkui/arkui-ts/ts-security-components-pastebutton.md). In addition, all security components inherit the [Security Component Universal Attributes](../../reference/apis-arkui/arkui-ts/ts-securitycomponent-attributes.md), which can be used to customize styles.
   
   ```ts
   import { pasteboard, BusinessError } from '@kit.BasicServicesKit';
   
   @Entry
   @Component
   struct Index {
     @State message: string = '';
   
     build() {
       Row() {
         Column({ space: 10 }) {
           TextInput({placeholder: 'Please enter the verification code.', text: this.message})
           PasteButton()
             .padding({top: 12, bottom: 12, left: 24, right: 24})
             .onClick((event: ClickEvent, result: PasteButtonOnClickResult) => {
               if (PasteButtonOnClickResult.SUCCESS === result) {
                 pasteboard.getSystemPasteboard().getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
                   if (err) {
                     console.error(`Failed to get paste data. Code is ${err.code}, message is ${err.message}`);
                     return;
                   }
                   // The content to paste is '123456'.
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
