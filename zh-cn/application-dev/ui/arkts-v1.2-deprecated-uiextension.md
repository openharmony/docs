# UIExtensionComponent (系统接口)

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## onResult

ArkTS1.1接口声明：[onResult(callback: Callback\<{code: number; want?: Want}>)](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#onresultdeprecated)

替代的ArkTS1.2接口声明：[onTerminated(callback: Callback&lt;TerminationInfo&gt;)](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#onterminated12)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
UIExtensionComponent({
                bundleName: "com.example.newdemo",
                abilityName: "UIExtensionProvider",
                parameters: {
                  "ability.want.params.uiExtensionType": "sys/commonUI"
                }
})
.onResult((info) => {
    console.info('onResult: code =' + info.code + ', want = ' + JSON.stringify(info.want));
})
```

ArkTS1.2
<!--code_no_check-->
```ts
UIExtensionComponent({
                bundleName: "com.example.newdemo",
                abilityName: "UIExtensionProvider",
                parameters: {
                  "ability.want.params.uiExtensionType": "sys/commonUI"
                }
})
.onTerminated((info) => {
    console.info('onTerminated: code =' + info.code + ', want = ' + JSON.stringify(info.want));
})
```

## onRelease

ArkTS1.1接口声明：[onRelease(callback: Callback\<number>)](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#onreleasedeprecated)

替代的ArkTS1.2接口声明：[onTerminated(callback: Callback&lt;TerminationInfo&gt;)](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#onterminated12)或者[onError(callback:ErrorCallback)](../reference/apis-arkui/arkui-ts/ts-container-ui-extension-component-sys.md#onerror)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
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
```

ArkTS1.2
<!--code_no_check-->
```ts
UIExtensionComponent({
                bundleName: "com.example.newdemo",
                abilityName: "UIExtensionProvider",
                parameters: {
                  "ability.want.params.uiExtensionType": "sys/commonUI"
                }
})
.onError((err) => {
    console.error('onError: code =' + err.code + ', name = ' + err.name + ', message = ' + err.message);
    console.error('onError: ' + JSON.stringify(err));
})
```