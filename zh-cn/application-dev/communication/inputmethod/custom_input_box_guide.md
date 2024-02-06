# 实现一个自绘编辑框

输入法框架提供了 InputMethodController，使用 InputMethodController可以绑定输入法，监听输入法应用的插入、删除、选择、光标移动等操作，从而实现一个自绘编辑框。

## 开发步骤

1. 开发者在实现一个自绘编辑框控件时，需要在在DevEco Studio工程中新建一个ets文件，命名为自定义控件的名称，本示例中命名为CustomInput，在文件中定义一个自定义控件，并从@kit.IMEKit中导入inputMethod。

   ```ets
   import { inputMethod } from '@kit.IMEKit';
   
   @Component
   export struct CustomInput {
     build() {
     }
   }
   ```

2. 在控件中，使用Text组件作为自会编辑框的文本显示组件，使用状态变量inputText作为Text组件要显示的内容。

   ```ets
   import { inputMethod } from '@kit.IMEKit';
   
   @Component
   export struct CustomInput {
     @State inputText: string = ''; // inputText作为Text组件要显示的内容。
     
     build() {
       Text(this.inputText) // Text组件作为自会编辑框的文本显示组件。
         .fontSize(16)
         .width('100%')
         .lineHeight(40)
         .id('customInput')
         .height(45)
         .border({ color: '#554455', radius: 30, width: 1 })
         .maxLines(1)
     }
   }
   ```

3. 在控件中获取inputMethodController实例，并在文本点击时调用controller示例的attach方法绑定和拉起软键盘，并注册监听输入法插入文本、删除等方法，本示例仅展示插入、删除。

   ```ets
   import { inputMethod } from '@kit.IMEKit';
   
   @Component
   export struct CustomInput {
     @State inputText: string = ''; // inputText作为Text组件要显示的内容。
     private inputController: inputMethod.InputMethodController = inputMethod.getController();
   
     build() {
       Text(this.inputText) // Text组件作为自会编辑框的文本显示组件。
         .fontSize(16)
         .width('100%')
         .lineHeight(40)
         .id('customInput')
         .height(45)
         .border({ color: '#554455', radius: 30, width: 1 })
         .maxLines(1)
         .onClick(()=>{
           this.attachAndListener(); // 点击控件
         })
     }
   
     async attachAndListener() { // 绑定和设置监听
       focusControl.requestFocus('CustomInput');
       await this.inputController.attach(true, {
         inputAttribute: {
           textInputType: inputMethod.TextInputType.TEXT,
           enterKeyType: inputMethod.EnterKeyType.SEARCH
         }
       });
       this.inputController.on('insertText', (text) => {
         this.inputText += text;
       })
       this.inputController.on('deleteLeft', (length) => {
         this.inputText = this.inputText.substring(0, this.inputText.length - length);
       })
     }
   }
   ```

4. 在应用界面布局中引入该控件即可，此处假设使用界面为Index.ets和控件CustomInput.ets在同一目录下。

   ```ets
   import { CustomInput } from './CustomInput'; // 导入控件
   
   @Entry
   @Component
   struct Index {
   
     build() {
       Column() {
         CustomInput() // 使用控件
       }
     }
   }
   ```