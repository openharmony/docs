# EmbeddedUIExtensionAbility

## 概述

[EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)是EMBEDDED_UI类型的ExtensionAbility组件，提供了跨进程界面嵌入的能力。

EmbeddedUIExtensionAbility需要和[EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md)一起配合使用，开发者可以在UIAbility的页面中通过EmbeddedComponent嵌入本应用的EmbeddedUIExtensionAbility提供的UI。EmbeddedUIExtensionAbility会在独立于UIAbility的进程中运行，完成其页面的布局和渲染。通常用于有进程隔离诉求的模块化开发场景。

> **说明：**
>
> 1. 当前EmbeddedUIExtensionAbility和EmbeddedComponent仅支持在拥有多进程配置的设备上使用。
> 2. EmbeddedComponent只能在UIAbility中使用，且被拉起的EmbeddedUIExtensionAbility需与UIAbility属于同一应用。

EmbeddedUIExtensionAbility通过[UIExtensionContext](../reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md)和[UIExtensionContentSession](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md)提供相关能力。本文描述中称被启动的EmbeddedUIExtensionAbility为提供方，称启动EmbeddedUIExtensionAbility的EmbeddedComponent组件为使用方。

## 开发EmbeddedUIExtensionAbility提供方

### 生命周期

[EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)提供了onCreate、onSessionCreate、onSessionDestroy、onForeground、onBackground和onDestroy生命周期回调，根据需要重写对应的回调方法。

- **onCreate**：当EmbeddedUIExtensionAbility创建时回调，执行初始化业务逻辑操作。
- **onSessionCreate**：当EmbeddedUIExtensionAbility界面内容对象创建后调用。
- **onSessionDestroy**：当EmbeddedUIExtensionAbility界面内容对象销毁后调用。
- **onForeground**：当EmbeddedUIExtensionAbility从后台转到前台时触发。
- **onBackground**：当EmbeddedUIExtensionAbility从前台转到后台时触发。
- **onDestroy**：当EmbeddedUIExtensionAbility销毁时回调，可以执行资源清理等操作。

### 开发步骤

开发者在实现一个EmbeddedUIExtensionAbility提供方时，需要在DevEco Studio工程中手动新建一个EmbeddedUIExtensionAbility，具体步骤如下。

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为EmbeddedUIExtAbility。

2. 在EmbeddedUIExtAbility目录，右键选择“New &gt; File”，新建一个.ts文件并命名为EmbeddedUIExtAbility.ts。

3. 打开EmbeddedUIExtAbility.ts文件，导入EmbeddedUIExtensionAbility的依赖包，自定义类继承EmbeddedUIExtensionAbility并实现onCreate、onSessionCreate、onSessionDestroy、onForeground、onBackground和onDestroy生命周期回调。

   ```ts
   import EmbeddedUIExtensionAbility from '@ohos.app.ability.EmbeddedUIExtensionAbility'
   import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession'
   import Want from '@ohos.app.ability.Want';
   
   const TAG: string = '[ExampleEmbeddedAbility]'
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
   import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
   
   let storage = LocalStorage.getShared()
   
   @Entry(storage)
   @Component
   struct Extension {
     @State message: string = 'EmbeddedUIExtensionAbility Index';
     private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
   
     build() {
       Column() {
         Text(this.message)
           .fontSize(20)
           .fontWeight(FontWeight.Bold)
         Button("terminateSelfWithResult").fontSize(20).onClick(() => {
           this.session?.terminateSelfWithResult({
             resultCode: 1,
             want: {
               bundleName: "com.example.embeddeddemo",
               abilityName: "ExampleEmbeddedAbility",
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
           "srcEntry": "./ets/EmbeddedUIExtAbility/EmbeddedUIExtAbility.ts"
         },
       ]
     }
   }
   ```



## 开发EmbeddedUIExtensionAbility使用方

开发者可以在UIAbility的页面中通过EmbeddedComponent容器加载自己应用内的EmbeddedUIExtensionAbility。如在首页文件：pages/Index.ets中添加如下内容：

```ts
import Want from '@ohos.app.ability.Want'
import { BusinessError } from '@ohos.base'

@Entry
@Component
struct Index {
  @State message: string = 'Message: '
  private want: Want = {
    bundleName: "com.example.embeddeddemo",
    abilityName: "ExampleEmbeddedAbility",
  }

  build() {
    Row() {
      Column() {
        Text(this.message).fontSize(30)
        EmbeddedComponent(this.want, EmbeddedType.EMBEDDED_UI_EXTENSION)
          .width('100%')
          .height('90%')
          .onTerminated((info: TerminationInfo)=>{
            this.message = 'Terminarion: code = ' + info.code + ', want = ' + JSON.stringify(info.want);
          })
          .onError((error: BusinessError)=>{
            this.message = 'Error: code = ' + error.code;
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```



