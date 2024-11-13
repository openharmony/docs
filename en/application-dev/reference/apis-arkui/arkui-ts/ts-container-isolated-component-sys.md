# IsolatedComponent (System API)

**IsolatedComponent** is designed to support the embedding and display of UIs provided by independent .abc files within the current page, with the displayed content running in a restricted worker thread.

The **FolderStack** component is usually used in modular development scenarios where .abc file hot update is required.

> **NOTE**
>
> This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Constraints

**Specifications Constraints**

1. This component does not support preview.

2. .abc files must pass the [VerifyAbc](../../apis-ability-kit/js-apis-bundleManager.md#bundlemanagerverifyabc11) verification to be used in this component.

3. Construction parameter updates are not supported; only the initial input is effective.

4. Nesting of **IsolatedComponent** components is not supported.

**Experience Constraints**

1. When an **IsolatedComponent** component is created, there is a certain amount of time required for the restricted worker thread to load and render the .abc file layout. During this period, the background color of the **IsolatedComponent** is displayed.

2. The main thread and the restricted worker thread handle layout rendering asynchronously, which can lead to desynchronization in page changes caused by layout alterations or rotations.

3. Event transmission between the main thread and the restricted worker thread is managed asynchronously, and there is no support for event bubbling between threads. As a result, UI interactions between threads may encounter event conflicts.

**Security Constraints**

1. Displaying an independent .abc file through the **IsolatedComponent** component in the host process means that the .abc file content is fully accessible to the host, granting the host the control over the file content. For security-sensitive situations where such open access could be a risk, the use of this feature is disabled.

2. Running independent .abc files in a restricted worker thread offers a level of security, as the .abc file content is isolated and does not interfere with the main thread.

## Child Components

Not supported

## APIs

IsolatedComponent(options: IsolatedOptions)

Creates an **IsolatedComponent** component to display the .abc file executed in a restricted worker thread.

**Parameters**

| Name               | Type                                                  | Mandatory| Description          |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------ |
| options | [IsolatedOptions](#isolatedoptions)                | Yes  | Construction parameters.|

## IsolatedOptions
Describes the optional construction parameters during **IsolatedComponent** construction.

**Parameters**

| Name              | Type                                | Mandatory| Description                                                                                                     |
| ----                 | ---------------------------------------- | ---- | ---------------                                                                                               |
| want | [Want](../../apis-ability-kit/js-apis-app-ability-want.md)                                  | Yes  | .abc file information to load.|
| worker | [RestrictedWorker](../../apis-arkts/js-apis-worker.md#restrictedworker11)       | Yes  | Restricted worker thread where the .abc file is running.|

## Attributes
Only the [width](ts-universal-attributes-size.md#width), [height](ts-universal-attributes-size.md#height), and [backgroundColor](ts-universal-attributes-background.md#backgroundcolor) universal attributes are supported.

## Events

The [universal events](ts-universal-events-click.md) are not supported.

Events are asynchronously passed to the restricted worker thread after coordinate conversion.

The following events are supported:

### onError

onError(callback:ErrorCallback)

Invoked when an error occurs during the running of the **IsolatedComponent**. You can obtain the error information based on the **code**, **name**, and **message** parameters in the callback and rectify the exception accordingly.

**Parameters**

| Name                      | Type  | Description                                                        |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| callback                        | [ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | Error information.   |

## Example

This example shows only the usage of the component.

```ts
// OhCardWorker.ets
import { worker, ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@kit.ArkTS';
const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {}
workerPort.onmessageerror = (e: MessageEvents) => {}
workerPort.onerror = (e: ErrorEvent) => {}
```

```ts
// Index.ets
import { worker } from '@kit.ArkTS';
import { bundleManager } from '@kit.AbilityKit';

@Entry
@Component
struct Index2 {
  @State isShow: boolean = false;
  worker ?: worker.RestrictedWorker;
  resourcePath : string = "";
  abcPath : string = "";
  entryPoint : string = "";
  fileName: string = "Index"

  build() {
    Row() {
      Column() {
        // 1. Call verifyAbc to verify /data/storage/el2/haps/entry/files/Index.abc in the application sandbox.
        Button("verifyAbc").onClick(()=>{
          let abcFilePath = getContext(this).filesDir + "/" + this.fileName + ".abc";
          bundle.verifyAbc([abcFilePath], false);
        }).height(100).width(100)

        // 2. Display the IsolatedComponent.
        Button("showIsolatedComponent").onClick(()=>{
          if (!this.isShow) {
            this.worker = new worker.RestrictedWorker("./OhCardWorker");
            // /data/storage/el2/haps/entry/files/{fileName}.hap
            this.resourcePath = getContext(this).filesDir + "/" + this.fileName + '.hap';
            // /abcs/data/storage/el2/haps/entry/files/{fileName}.hap
            this.abcPath = "/abcs" + getContext(this).filesDir + "/" + this.fileName;
            this.entryPoint = "com.ohos.test/entry/ets/pages/Index"
            this.isShow = true;
          }
        }).height(100).width(100)

        if (this.isShow) {
          IsolatedComponent({
            want: {
              "parameters" : {
                "resourcePath" : this.resourcePath,
                "abcPath" : this.abcPath,
                "entryPoint" : this.entryPoint
              }
            },
            "worker" : this.worker
          }).width(300).height(300).onError((err)=>{
            console.info("onError : " + JSON.stringify(err));
          })
        }
      }
      .width('100%')
    }
    .height('100%')
  }
}

```
