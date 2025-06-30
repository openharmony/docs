# EmbeddedUIExtensionAbility

## 概述

[EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)是EMBEDDED_UI类型的[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)组件，提供了跨进程界面嵌入的能力。

EmbeddedUIExtensionAbility需要和[EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md)一起配合使用，开发者可以在[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)的页面中通过EmbeddedComponent嵌入本应用的EmbeddedUIExtensionAbility提供的UI。EmbeddedUIExtensionAbility会在独立于UIAbility的进程中运行，完成其页面的布局和渲染。通常用于有进程隔离诉求的模块化开发场景。

## 约束限制

当前EmbeddedUIExtensionAbility和EmbeddedComponent仅支持在拥有多进程配置的设备上使用，目前支持多进程配置的设备有2in1与tablet。

## 生命周期 

[EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)提供了onCreate、onSessionCreate、onSessionDestroy、onForeground、onBackground和onDestroy生命周期回调，根据需要重写对应的回调方法。以下生命周期回调均继承自[UIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)。

- **onCreate**：当EmbeddedUIExtensionAbility创建时回调，执行初始化业务逻辑操作。
- **onSessionCreate**：当EmbeddedUIExtensionAbility界面内容对象创建后调用。
- **onSessionDestroy**：当EmbeddedUIExtensionAbility界面内容对象销毁后调用。
- **onForeground**：当EmbeddedUIExtensionAbility从后台转到前台时触发。
- **onBackground**：当EmbeddedUIExtensionAbility从前台转到后台时触发。
- **onDestroy**：当EmbeddedUIExtensionAbility销毁时回调，可以执行资源清理等操作。

> **说明：**
>
> EmbeddedComponent只能在UIAbility中使用，且被拉起的EmbeddedUIExtensionAbility需与UIAbility属于同一应用。
> 
> <!--Del-->当前提供的EmbeddedUIExtensionAbility支持多实例场景，并且继承了UIExtensionAbility的进程模型，UIExtensionAbility的多实例及进程配置相关介绍可参见[UIExtensionAbility](uiextensionability.md)。<!--DelEnd-->

EmbeddedUIExtensionAbility通过[UIExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md)和[UIExtensionContentSession](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md)提供相关能力。本文描述中称被启动的EmbeddedUIExtensionAbility为提供方，称启动EmbeddedUIExtensionAbility的EmbeddedComponent组件为使用方。

## 开发EmbeddedUIExtensionAbility提供方

开发者在实现一个[EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)提供方时，需要在DevEco Studio工程中手动新建一个EmbeddedUIExtensionAbility，具体步骤如下。

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为EmbeddedUIExtAbility。

2. 在EmbeddedUIExtAbility目录，右键选择“New &gt; File”，新建一个.ets文件并命名为EmbeddedUIExtAbility.ets。

3. 打开EmbeddedUIExtAbility.ets文件，导入EmbeddedUIExtensionAbility的依赖包，自定义类继承EmbeddedUIExtensionAbility并实现onCreate、onSessionCreate、onSessionDestroy、onForeground、onBackground和onDestroy生命周期回调。

    ```ts
    import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';

    const TAG: string = '[ExampleEmbeddedAbility]';

    export default class ExampleEmbeddedAbility extends EmbeddedUIExtensionAbility {
      onCreate() {
        console.log(TAG, `onCreate`);
      }

      onForeground() {
        console.log(TAG, `onForeground`);
      }

      onBackground() {
        console.log(TAG, `onBackground`);
      }

      onDestroy() {
        console.log(TAG, `onDestroy`);
      }

      onSessionCreate(want: Want, session: UIExtensionContentSession) {
        console.log(TAG, `onSessionCreate, want: ${JSON.stringify(want)}`);
        let param: Record<string, UIExtensionContentSession> = {
          'session': session
        };
        let storage: LocalStorage = new LocalStorage(param);
        session.loadContent('pages/extension', storage);
      }

      onSessionDestroy(session: UIExtensionContentSession) {
        console.log(TAG, `onSessionDestroy`);
      }
    }
    ```

4. EmbeddedUIExtensionAbility的onSessionCreate中加载了入口页面文件pages/extension.ets内容如下：

    ```ts
    import { UIExtensionContentSession } from '@kit.AbilityKit';

    @Entry()
    @Component
    struct Extension {
      @State message: string = 'EmbeddedUIExtensionAbility Index';
      localStorage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
      private session: UIExtensionContentSession | undefined = this.localStorage?.get<UIExtensionContentSession>('session');

      build() {
        Column() {
          Text(this.message)
            .fontSize(20)
            .fontWeight(FontWeight.Bold)
          Button('terminateSelfWithResult').fontSize(20).onClick(() => {
            this.session?.terminateSelfWithResult({
              resultCode: 1,
              want: {
                bundleName: 'com.example.embeddeddemo',
                abilityName: 'ExampleEmbeddedAbility'
              }});
          })
        }.width('100%').height('100%')
      }
    }
    ```

5. 在工程Module对应的[module.json5配置文件](../quick-start/module-configuration-file.md)中注册EmbeddedUIExtensionAbility，type标签需要设置为“embeddedUI”，srcEntry标签表示当前EmbeddedUIExtensionAbility组件所对应的代码路径。

    ```json
    {
      "module": {
        "extensionAbilities": [
          {
            "name": "EmbeddedUIExtAbility",
            "icon": "$media:icon",
            "description": "EmbeddedUIExtAbility",
            "type": "embeddedUI",
            "srcEntry": "./ets/EmbeddedUIExtAbility/EmbeddedUIExtAbility.ets"
          },
        ]
      }
    }
    ```



## 开发EmbeddedUIExtensionAbility使用方

开发者可以在[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)的页面中通过[EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md)容器加载自己应用内的[EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)。此外，EmbeddedUIExtensionAbility在[want](../reference/apis-ability-kit/js-apis-app-ability-want.md).parameters中新增了两个字段ohos.extension.processMode.hostSpecified和ohos.extension.processMode.hostInstance。
- ohos.extension.processMode.hostSpecified控制非首次启动的EmbeddedUIExtensionAbility是否运行在同[UIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)的进程中，参数是进程名称。例如，"ohos.extension.processMode.hostSpecified"： "com.ohos.inentexecutedemo:share"。  
- ohos.extension.processMode.hostInstance控制启动的EmbeddedUIExtensionAbility是否按照独立进程启动，传入false时，按照UIExtensionAbility的进程模型启动，入参true的时候，不管被拉起的UIExtensionAbility配置的是什么进程模型，都会新增一个进程，例如，"ohos.extension.processMode.hostInstance": "true"。

ohos.extension.processMode.hostSpecified和ohos.extension.processMode.hostInstance同时配置时，hostSpecified优先，会运行在指定的进程中。
如在首页文件：pages/Index.ets中添加如下内容：
```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  @State message: string = 'Message: '
  private want: Want = {
    bundleName: 'com.example.embeddeddemo',
    abilityName: 'EmbeddedUIExtAbility',
    parameters: {
      'ohos.extension.processMode.hostInstance': 'true'
    }
  }

  build() {
    Row() {
      Column() {
        Text(this.message).fontSize(30)
        EmbeddedComponent(this.want, EmbeddedType.EMBEDDED_UI_EXTENSION)
          .width('100%')
          .height('90%')
          .onTerminated((info: TerminationInfo) => {
            this.message = 'Termination: code = ' + info.code + ', want = ' + JSON.stringify(info.want);
          })
          .onError((error: BusinessError) => {
            this.message = 'Error: code = ' + error.code;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
