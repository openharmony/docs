# 使用Devtools工具调试前端页面


Web组件支持使用DevTools工具调试前端页面。DevTools是一个 Web前端开发调试工具，提供了电脑上调试移动设备前端页面的能力。开发者通过[setWebDebuggingAccess()](../reference/apis/js-apis-webview.md#setwebdebuggingaccess)接口开启Web组件前端页面调试能力，利用DevTools工具可以在电脑上调试移动设备上的前端网页。


使用DevTools工具，可以执行以下步骤：


1. 在应用代码中开启Web调试开关，具体如下：

   ```ts
   // xxx.ets
   import web_webview from '@ohos.web.webview';

   @Entry
   @Component
   struct WebComponent {
     controller: web_webview.WebviewController = new web_webview.WebviewController();
     aboutToAppear() {
       // 配置web开启调试模式
       web_webview.WebviewController.setWebDebuggingAccess(true);
     }
     build() {
       Column() {
         Web({ src: 'www.example.com', controller: this.controller })
       }
     }
   }
   ```
2. 开启调试功能需要在DevEco Studio应用工程的module.json5中增加权限, 具体如下：

   ```
   "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
   ```

3. 将设备连接上电脑，在电脑端配置端口映射，配置方法如下：

   ```
   // 添加映射 
   hdc fport tcp:9222 tcp:9222 
   // 查看映射 
   hdc fport ls
   ```

4. 在电脑端chrome浏览器地址栏中输入chrome://inspect/\#devices，页面识别到设备后，就可以开始页面调试。调试效果如下：

     **图1** 页面调试效果图  

     ![debug-effect](figures/debug-effect.png)
