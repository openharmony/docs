# AbilityComponent (系统接口)

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## AbilityComponent

ArkTS1.1接口声明：[AbilityComponent(value: {want: Want})](../reference/apis-arkui/arkui-ts/ts-container-ability-component-sys.md#接口)

替代的ArkTS1.2接口声明：[UIExtensionComponent(want: Want, options?: UIExtensionOptions)](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#接口)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct MyComponent {

  build() {
      Column() {
          AbilityComponent({
              want: {
                  bundleName: '',
                  abilityName: ''
              },
          })
      }
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct MyComponent {
build() {
  Column() {
      UIExtensionComponent({
        bundleName: "com.example.newdemo",
        abilityName: "UIExtensionProvider",
        parameters: {
          "ability.want.params.uiExtensionType": "sys/commonUI"
        }
      })
    }
  }
}
```

## onConnect

ArkTS1.1接口声明：[onConnect(callback:()&nbsp;=&gt;&nbsp;void)](../reference/apis-arkui/arkui-ts/ts-container-ability-component-sys.md#onconnect)

替代的ArkTS1.2接口声明：[onRemoteReady(callback: Callback\<UIExtensionProxy>)](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#onremoteready)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct MyComponent {

  build() {
      Column() {
          AbilityComponent({
              want: {
                  bundleName: '',
                  abilityName: ''
              },
          })
          .onConnect(() => {
              console.log('AbilityComponent connect')
          })
      }
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct MyComponent {
build() {
  Column() {
      UIExtensionComponent({
        bundleName: "com.example.newdemo",
        abilityName: "UIExtensionProvider",
        parameters: {
          "ability.want.params.uiExtensionType": "sys/commonUI"
        }
      })
      .onRemoteReady((proxy) => {
        console.info('onRemoteReady, for test');
      })
    }
  }
}
```

## onDisConnect

ArkTS1.1接口声明：[onRelease(callback: Callback\<number>)](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#onreleasedeprecated)

替代的ArkTS1.2接口声明：[onTerminated(callback: Callback&lt;TerminationInfo&gt;)](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#onterminated12)或者[onError(callback:ErrorCallback)](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#onerror)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct MyComponent {

  build() {
      Column() {
          AbilityComponent({
              want: {
                  bundleName: '',
                  abilityName: ''
              },
          })
          .onDisconnect(() => {
              console.log('AbilityComponent disconnect')
          })
      }
  }
}
```

ArkTS1.2
<!--code_no_check-->
```ts
// xxx.ets
@Entry
@Component
struct MyComponent {
build() {
  Column() {
      UIExtensionComponent({
        bundleName: "com.example.newdemo",
        abilityName: "UIExtensionProvider",
        parameters: {
          "ability.want.params.uiExtensionType": "sys/commonUI"
        }
      })
      .onRelease((info) => {
        console.info('onRelease: releaseCode =' + JSON.stringify(info));
      })
    }
  }
}
```