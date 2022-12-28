# ArkUI Web Component (ArkTS) Development

## What is the domStorageAccess attribute of the \<Web> component used for?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

The **domStorageAccess** attribute specifies whether to enable the DOM Storage API, which is disabled by default and provides **localStorage**, but not **sessionStorage**.

## How do I check the online status on the HTML page loaded by the \<Web> component?

Applicable to: OpenHarmony SDK 3.2.7.5, stage model of API version 9

1. Configure the **ohos.permission.INTERNET** and **ohos.permission.GET_NETWORK_INFO** application permissions.

2. Obtain the online status through **window.navigator.onLine** on the HTML page.

## What should I do if the UserAgent string cannot be used in concatenation before the initial HTML5 page loading by the \<Web> component?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

By default, the **UserAgent** string is obtained through the **WebController**. A **WebController** object can control only one **\<Web>** component, and methods on the **WebController** can only be called by the **\<Web>** component bound to it. To concatenate the default **UserAgent** string and a custom string before the initial page loading, perform the following:

1. Use **@State** to define the initial **userAgent** and bind it to the **\<Web>** component.

2. In the **onUrlLoadIntercept** callback of the **\<Web>** component, use **WebController** to obtain the default **userAgent** string and modify the **userAgent** bound to the **\<Web>** component.
   The code snippet is as follows:

   
   ```
   @Entry
   @Component
   struct Index {
     private controller: WebController = new WebController()
     @State userAgentPa: string = ''
     build() {
       Row() {
         Column() {
           Web({ src: 'www.example.com', controller: this.controller })
             .width('100%')
             .userAgent(this.userAgentPa)
             .onUrlLoadIntercept((event) => {
               let userAgent = this.controller.getDefaultUserAgent();
               this.userAgentPa = userAgent + ' 111111111'
               console.log("userAgent onUrlLoadIntercept: " + userAgent);
               return false;
             })
         }
         .width('100%').alignItems(HorizontalAlign.Start).backgroundColor(Color.Green)
       }
       .height('100%')
     }
   }
   ```

## Should the logic for loading the lottie animation be written in the onAppear or onReady function?

Applicable to: OpenHarmony SDK 3.2.6.5, stage model of API version 9

The logic for loading the lottie animation must be written in the **onReady** function. The **onReady** function is triggered when the canvas is ready, while the **onAppear** function is triggered when the canvas is displayed.

## Do I need to invoke the refresh API after invoking deleteJavaScriptRegister?

Applicable to: all versions

No. This operation is not needed.

## How do I pass data from a page to the \<Web> component?

Applicable to: OpenHarmony SDK 3.2.7.5, stage model of API version 9

1. Use **WebController** to create two message ports: message port 1 and message port 0.

2. Send message port 1 to the HTML side, which can then save and use the port.

3. Register a callback for message port 0 on the application side.

4. Use message port 0 on the application side to send messages to message port 1 on the HTML side.

Reference: [Web](../reference/arkui-ts/ts-basic-components-web.md#postmessage9)
