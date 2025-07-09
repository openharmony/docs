# IsolatedComponent (System API)

**IsolatedComponent** is designed to support the embedding and display of UIs provided by independent .abc files within the current page, with the displayed content running in a restricted Worker thread.

The **FolderStack** component is usually used in modular development scenarios where .abc file hot update is required.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Constraints

**Specifications Constraints**

1. This component does not support preview.

2. The .abc file must pass the [VerifyAbc](../../apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagerverifyabc11) verification before use.

3. Constructor parameter updates are not supported; only the initial input is effective.

4. Nesting of **IsolatedComponent** components is not supported.

**Experience Constraints**

1. When an **IsolatedComponent** component is created, there is a certain amount of time required for the restricted Worker thread to load and render the .abc file layout. During this period, the background color of the **IsolatedComponent** is displayed.

2. The main thread and the restricted Worker thread handle layout rendering asynchronously, which can lead to desynchronization in page changes caused by layout alterations or rotations.

3. Event passing between the main thread and the restricted Worker thread is managed asynchronously, and there is no support for event bubbling between threads. As a result, UI interactions between threads may encounter event conflicts.

**Security Constraints**

1. Displaying an independent .abc file through the **IsolatedComponent** component in the host process means that the .abc file content is fully accessible to the host, granting the host the control over the file content. For security-sensitive situations where such open access could be a risk, the use of this feature is disabled.

2. Running independent .abc files in a restricted Worker thread offers a level of security, as the .abc file content is isolated and does not interfere with the main thread.

## Child Components

Not supported

## APIs

IsolatedComponent(options: IsolatedOptions)

Creates an **IsolatedComponent** component to display the .abc file executed in a restricted Worker thread.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name               | Type                                                  | Mandatory| Description          |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------ |
| options | [IsolatedOptions](#isolatedoptions)                | Yes  | Construction parameters.|

## IsolatedOptions

Describes the optional construction parameters during **IsolatedComponent** construction.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name              | Type                                | Mandatory| Description                                                                                                     |
| ----                 | ---------------------------------------- | ---- | ---------------                                                                                               |
| want | [Want](../../apis-ability-kit/js-apis-app-ability-want.md)                                  | Yes  | .abc file information to load.|
| worker | [RestrictedWorker](../../apis-arkts/js-apis-worker-sys.md#restrictedworker11)       | Yes  | Restricted Worker thread where the .abc file is running.|

## Attributes
Only the [width](ts-universal-attributes-size.md#width), [height](ts-universal-attributes-size.md#height), and [backgroundColor](ts-universal-attributes-background.md#backgroundcolor) universal attributes are supported.

## Events

The [universal events](ts-component-general-events.md) are not supported.

Events are asynchronously passed to the restricted Worker thread after coordinate conversion.

The following events are supported:

### onError

onError(callback:ErrorCallback)

Invoked when an error occurs during the running of the **IsolatedComponent**. You can obtain the error information based on the **code**, **name**, and **message** parameters in the callback and rectify the exception accordingly.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name               | Type                                                  | Mandatory| Description          |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------ |
| callback | [ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback)                | Yes  | Error information.|

## Example: Loading an IsolatedComponent

This example demonstrates the basic usage of the **IsolatedComponent** component. The sample application's **bundleName** is **"com.example.isolateddemo"**, and the component uses the .abc file and an extension page from the same application as the embedded content. The specific testing steps after building the application project are as follows:
1. Build the HAP in DevEco Studio and install it on the device.
2. Upload the generated **modules.abc** file to the application sandbox path** /data/app/el2/100/base/com.example.isolateddemo/haps/entry/files** using DevEco Studio or the [hdc](../../../dfx/hdc.md) tool.
3. Open the application page and click the **verifyAbc** button to verify the .abc file, which logs "VerifyAbc successfully."
4. Click the **showIsolatedComponent** button to display the **IsolatedComponent** with the content "Hello World."

- Restricted Worker thread script **ets/workers/OhCardWorker.ets**:
  ```ts
  // OhCardWorker.ets
  import { worker, ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@kit.ArkTS';
  const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

  workerPort.onmessage = (e: MessageEvents) => {}
  workerPort.onmessageerror = (e: MessageEvents) => {}
  workerPort.onerror = (e: ErrorEvent) => {}
  ```

- Home page (**ets/pages/Index.ets**) loaded by the entry ability (**EntryAbility**):
  ```ts
  import { worker } from '@kit.ArkTS';
  import { bundleManager, common } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // Verify the .abc file and copy it to the specified sandbox path.
  function VerifyAbc(abcPaths: Array<string>, deleteOriginalFiles: boolean) {
    try {
      bundleManager.verifyAbc(abcPaths, deleteOriginalFiles, (err) => {
        if (err) {
          console.error("VerifyAbc failed, error message: " + err.message);
        } else {
          console.info("VerifyAbc successfully.");
        }
      });
    } catch (err) {
      let message = (err as BusinessError).message;
      console.error("VerifyAbc failed, error message: " + message);
    }
  }

  @Entry
  @Component
  struct Index {
    @State isShow: boolean = false;
    @State resourcePath: string = "";
    @State abcPath: string = "";
    @State entryPoint: string = "";
    @State context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    // .abc file name
    private fileName: string = "modules";
    // Bundle name of the application to which the .abc file belongs
    private bundleName: string = "com.example.isolateddemo";
    // Restricted Worker thread
    private worker ?: worker.RestrictedWorker = new worker.RestrictedWorker("entry/ets/workers/OhCardWorker.ets");

    build() {
      Row() {
        Column() {
          // 1. Verify the .abc file.
          Button("verifyAbc").onClick(() => {
            let abcFilePath = `${this.context.filesDir}/${this.fileName}.abc`;
            console.info("abcFilePath: " + abcFilePath);
            VerifyAbc([abcFilePath], false);
          }).height(100).width(100)

          // 2. Display the IsolatedComponent.
          Button("showIsolatedComponent").onClick(() => {
            if (!this.isShow) {
              // Resource path
              this.resourcePath = `${this.context.filesDir}/${this.fileName}.hap`;
              // Sandbox path after the .abc file is verified
              this.abcPath = `/abcs${this.context.filesDir}/${this.fileName}`;
              // Entry to the page to be displayed
              this.entryPoint = `${this.bundleName}/entry/ets/pages/extension`;
              this.isShow = true;
            }
          }).height(100).width(100)

          if (this.isShow) {
            IsolatedComponent({
              want: {
                "parameters": {
                  "resourcePath": this.resourcePath,
                  "abcPath": this.abcPath,
                  "entryPoint": this.entryPoint
                }
              },
              worker: this.worker
            })
              .width(300)
              .height(300)
              .onError((err) => {
                console.error("onError : " + JSON.stringify(err));
              })
          }
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```

- The entry page file **ets/pages/extension.ets**, which runs in a restricted Worker thread, needs to be configured in the **resources/base/profile/main_pages.json** file with the following content:
  ```ts
  @Entry
  @Component
  struct Extension {
    @State message: string = 'Hello World';

    build() {
      RelativeContainer() {
        Text(this.message)
          .id('HelloWorld')
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
          .alignRules({
            center: { anchor: '__container__', align: VerticalAlign.Center },
            middle: { anchor: '__container__', align: HorizontalAlign.Center }
          })
      }
      .height('100%')
      .width('100%')
    }
  }
  ```

- Add the **requestPermissions** tag in the **module.json5** configuration file to allow the execution of dynamically distributed Ark bytecode in restricted mode:
  ```json
  "requestPermissions": [
    {
      "name": "ohos.permission.RUN_DYN_CODE",
      "usedScene": {
        "abilities": [
          "EntryAbility"
        ],
        "when": "inuse"
      }
    }
  ]
  ```
