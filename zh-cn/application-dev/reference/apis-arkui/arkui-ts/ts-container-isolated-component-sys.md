# IsolatedComponent (系统接口)

IsolatedComponent用于支持在本页面内嵌入显示独立Abc（.abc文件）提供的UI，展示的内容在受限worker线程中运行。

通常用于有Abc热更新诉求的模块化开发场景。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本模块为系统接口。

## 使用约束

**规格约束**

1、本组件不支持预览。

2、Abc需要[VerifyAbc](../../apis-ability-kit/js-apis-bundleManager.md#bundlemanagerverifyabc11)校验通过之后才可以使用于当前组件。

3、不支持构造参数更新，仅首次传入有效。

4、不支持IsolatedComponent组件嵌套场景。

**体验约束**

1、创建IsolatedComponent组件时，受限worker线程加载Abc布局渲染存在一定耗时，在此等待期间显示IsolatedComponent组件的背景色。

2、主线程与受限worker线程之间布局渲染是异步处理，布局变化、旋转等导致的页面变化存在不同步现象。

3、主线程与受限worker线程之间事件传递是异步处理，不支持线程之间的事件冒泡，线程之间的UI交互存在事件冲突现象。

**安全约束**

1、独立Abc通过IsolatedComponent组件嵌入式显示在宿主进程，即可说明其Abc内容完全向宿主开放，宿主有权操作独立Abc的内容，对此安全敏感场景禁用。

2、独立Abc运行在受限worker可保证相对安全，独立Abc内容不影响主线程。

## 子组件

无

## 接口

IsolatedComponent(options: IsolatedOptions)

创建IsolatedComponent组件，用于显示受限worker运行的Abc。

**参数：**

| 参数名                | 参数类型                                                   | 必填 | 参数描述           |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------ |
| options | [IsolatedOptions](#isolatedoptions)                | 是   | 需要传递的构造项。 |

## IsolatedOptions
用于在IsolatedComponent进行构造的时候，传递可选的构造参数。

**参数：**

| 参数名               | 参数类型                                 | 必填 | 参数描述                                                                                                      |
| ----                 | ---------------------------------------- | ---- | ---------------                                                                                               |
| want | [Want](../../apis-ability-kit/js-apis-app-ability-want.md)                                  | 是   | 要加载的Abc信息。 |
| worker | [RestrictedWorker](../../apis-arkts/js-apis-worker.md#restrictedworker11)       | 是   | 运行Abc的受限worker。 |

## 属性
仅支持[width](ts-universal-attributes-size.md#width)、[height](ts-universal-attributes-size.md#height)、[backgroundColor](ts-universal-attributes-background.md#backgroundcolor)通用属性

## 事件

不支持[通用事件](ts-universal-events-click.md)。

将事件经过坐标转换后异步传递给受限worker线程处理。

支持以下事件：

### onError

onError(callback:ErrorCallback)

被拉起的Ability扩展在运行过程中发生异常时触发本回调。可通过回调参数中的code、name和message获取错误信息并做处理。

**参数：**

| 参数名                       | 类型   | 说明                                                         |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| callback                        | [ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback) | 报错信息。    |

## 示例

本示例仅展示组件使用的方法。

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
        // 1、 将应用沙箱下的/data/storage/el2/haps/entry/files/Index.abc 调用verifyAbc校验
        Button("verifyAbc").onClick(()=>{
          let abcFilePath = getContext(this).filesDir + "/" + this.fileName + ".abc";
          bundle.verifyAbc([abcFilePath], false);
        }).height(100).width(100)

        // 2、显示IsolatedComponent
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
