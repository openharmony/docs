# IsolatedComponent (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @lmleon-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @HelloCrease-->

IsolatedComponent用于支持在本页面内嵌入显示独立Abc（.abc文件）提供的UI，展示的内容在受限worker线程中运行。

通常用于有Abc热更新（可动态替换Isolated加载的abc文件，无需通过重新安装应用的方式实现内容更新）诉求的模块化开发场景。

> **说明：**
>
> 该组件从API Version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 本模块为系统接口。

## 使用约束

**规格约束**

1、本组件不支持预览。

2、Abc需要[VerifyAbc](../../apis-ability-kit/js-apis-bundleManager-sys.md#bundlemanagerverifyabc11)校验通过之后才可以使用于当前组件。

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

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名                | 类型                                                   | 必填 | 说明           |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------ |
| options | [IsolatedOptions](#isolatedoptions)                | 是   | 需要传递的构造项。 |

## IsolatedOptions

用于在IsolatedComponent进行构造的时候，传递可选的构造参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型       | 只读 | 可选 | 说明 |
| ---- | ------------ | ---- | ---- | --------------- |
| want | [Want](../../apis-ability-kit/js-apis-app-ability-want.md) | 否 | 否 | 要加载的Abc信息。 |
| worker | [RestrictedWorker](../../apis-arkts/js-apis-worker-sys.md#restrictedworker11) | 否 | 否 | 运行Abc的受限worker。 |

## 属性
仅支持[width](ts-universal-attributes-size.md#width)、[height](ts-universal-attributes-size.md#height)、[backgroundColor](ts-universal-attributes-background.md#backgroundcolor)通用属性。

## 事件

不支持[通用事件](ts-component-general-events.md)。

将事件经过坐标转换后异步传递给受限worker线程处理。

支持以下事件：

### onError

onError(callback:ErrorCallback)

被拉起的Ability扩展在运行过程中发生异常时触发本回调。可通过回调参数中的code、name和message获取错误信息并做处理。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名                | 类型                                                   | 必填 | 说明           |
| --------------------- | ---------------------------------------------------------- | ---- | ------------------ |
| callback | [ErrorCallback](../../apis-basic-services-kit/js-apis-base.md#errorcallback)                | 是   | 报错信息。 |

## 示例（加载IsolatedComponent）

本示例展示`IsolatedComponent`组件的基础使用方式，示例应用的`bundleName`为"com.example.isolateddemo"，并使用本应用的Abc文件和extension页面作为嵌入展示的内容。构建应用项目后，具体测试步骤如下：
1. 在DevEco Studio上编译构建生成hap包，并安装到设备上；
2. 将本应用构建生成的modules.abc文件通过DevEco Studio或[hdc工具](../../../dfx/hdc.md)上传至应用沙箱路径`/data/app/el2/100/base/com.example.isolateddemo/haps/entry/files`下；
3. 打开应用页面，点击"verifyAbc"按钮进行校验，输出"VerifyAbc successfully"日志；
4. 点击"showIsolatedComponent"按钮，显示`IsolatedComponent`组件，内容为"Hello World"。

- 受限worker脚本`ets/workers/OhCardWorker.ets`的内容如下：
  ```ts
  // OhCardWorker.ets
  import { worker, ThreadWorkerGlobalScope, MessageEvents, ErrorEvent } from '@kit.ArkTS';

  const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

  workerPort.onmessage = (e: MessageEvents) => {
  }
  workerPort.onmessageerror = (e: MessageEvents) => {
  }
  workerPort.onerror = (e: ErrorEvent) => {
  }
  ```

- 示例应用中`EntryAbility(UIAbility)`加载首页文件`ets/pages/Index.ets`的内容如下：
  ```ts
  import { worker } from '@kit.ArkTS';
  import { bundleManager, common } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  // 对abc文件进行校验，并拷贝到指定沙箱路径下
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
    // abc文件名
    private fileName: string = "modules";
    // abc文件所属应用的bundleName
    private bundleName: string = "com.example.isolateddemo";
    // 受限worker
    private worker ?: worker.RestrictedWorker = new worker.RestrictedWorker("entry/ets/workers/OhCardWorker.ets");

    build() {
      Row() {
        Column() {
          // 1.调用verifyAbc接口校验abc文件
          Button("verifyAbc").onClick(() => {
            let abcFilePath = `${this.context.filesDir}/${this.fileName}.abc`;
            console.info("abcFilePath: " + abcFilePath);
            VerifyAbc([abcFilePath], false);
          }).height(100).width(100)

          // 2.显示IsolatedComponent
          Button("showIsolatedComponent").onClick(() => {
            if (!this.isShow) {
              // 资源路径
              this.resourcePath = `${this.context.filesDir}/${this.fileName}.hap`;
              // abc文件校验后的沙箱路径
              this.abcPath = `/abcs${this.context.filesDir}/${this.fileName}`;
              // 需要显示页面的入口路径
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

- 在受限worker线程中运行的入口页面文件`ets/pages/extension.ets`，需要在`resources/base/profile/main_pages.json`文件中配置该页面路径，其中内容如下：
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

- 在`module.json5`配置文件中增加`requestPermissions`标签，允许在受限模式下执行动态下发的方舟字节码：
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