# WindowExtensionAbility（仅对系统应用开放）


[WindowExtensionAbility](../reference/apis-arkui/js-apis-application-windowExtensionAbility-sys.md)是一种ExtensionAbility组件，用于提供界面组合扩展能力，仅允许系统应用进行跨应用的界面拉起和嵌入。


WindowExtensionAbility必须和[UIExtensionComponent](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md)一起配合使用，并根据需求处理被拉起应用的业务。WindowExtensionAbility支持以连接形式运行，系统应用必须添加UIExtensionComponent组件启动WindowExtensionAbility服务。

每个ExtensionAbility都有自己的Context，WindowExtensionAbility通过
[WindowExtensionContext](../reference/apis-arkui/js-apis-inner-application-windowExtensionContext-sys.md)提供相关能力。本文描述中称被启动的WindowExtensionAbility为提供方，称启动WindowExtensionAbility的UIExtensionComponent组件为使用方。

> **说明：**
>
> 本文档涉及系统接口的使用，请使用full-SDK进行开发。<!--Del-->具体使用可见[full-SDK替换指南](../faqs/full-sdk-switch-guide.md)。<!--DelEnd-->


## 设置一个嵌入式UIAbility

WindowExtensionAbility提供了onConnect()、onDisconnect()和onWindowReady()生命周期回调，根据需要重写对应的回调方法。

- **onWindowReady**：当该Ability的应用窗口创建成功时触发该回调。

- **onConnect**：当窗口扩展组件AbilityComponent连接该Ability时回调。

- **onDisconnect**：当窗口扩展组件AbilityComponent断开与该Ability的连接时回调。


**开发步骤**

开发者在实现一个嵌入式应用时，需要在DevEco Studio工程中手动新建一个WindowExtensionAbility，具体步骤如下。

1. 在工程Module对应的ets目录下，右键选择“New &gt; Directory”，新建一个目录并命名为WindowExtAbility。

2. 在WindowExtAbility目录，右键选择“New &gt; ts File”，新建一个.ts文件并命名为WindowExtAbility.ts。

3. 打开WindowExtAbility.ts文件，导入WindowExtensionAbility的依赖包，自定义类继承WindowExtensionAbility并实现onWindowReady()、onConnect()和onDisconnect()生命周期回调。

   ```ts
    import { WindowExtensionAbility, window } from '@kit.ArkUI';
    import { Want } from '@kit.AbilityKit';
    import {BusinessError} from '@kit.BasicServiceKit';

    export default class WindowExtAbility extends WindowExtensionAbility {
        onWindowReady(window: window.Window) {
            window.setUIContent('WindowExtAbility/pages/index1',(err:BusinessError) => {
              let pro = window.getWindowProperties();
              console.log('WindowExtension pro: ${JSON.stringify(pro)}');
              window.showWindow();
            });
        }

        onConnect(want: Want) {
            console.info('JSWindowExtension onConnect ' + want.abilityName);
        }

        onDisconnect(want: Want) {
            console.info('JSWindowExtension onDisconnect ' + want.abilityName);
        }
    }
   ```

4. 在工程Module对应的[module.json5配置文件](../quick-start/module-configuration-file.md)中注册WindowExtensionAbility，type标签需要设置为“window”，srcEntry标签表示当前ExtensionAbility组件所对应的代码路径。

   ```json
   {
     "module": {
       "extensionAbilities": [
            {
                "name": "WindowExtAbility",
                "srcEntry": "./ets/WindowExtAbility/WindowExtAbility.ts",
                "icon": "$media:icon",
                "description": "WindowExtension",
                "type": "window",
                "exported": true,
            }
        ],
     }
   }
   ```


## 拉起一个嵌入式UIAbility

系统应用可以通过AbilityComponent容器加载创建好的WindowExtensionAbility。

**开发步骤**

1. 开发者在连接一个嵌入式应用时，需要在DevEco Studio工程中相应的pages界面中加入AbilityComponent控件。

2. 在AbilityComponent控件中写入正确的bundleName和abilityName。

3. 设置好宽高。示例代码如下：

```ts
@Entry
@Component
struct Index {
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        UIExtensionComponent({
          abilityName: "WindowExtAbility",
          bundleName: "com.example.WindowExtAbility"})
          .width(500)
          .height(500)
      }
      .width('100%')
    }
    .height('100%')
    .backgroundColor(0x64BB5c)
  }
}
```

## 相关实例

针对WindowExtensionAbility开发，有以下相关实例可供参考：

- [窗口扩展应用（ArkTS）（API9）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/WindowManagement/WindowExtAbility)
