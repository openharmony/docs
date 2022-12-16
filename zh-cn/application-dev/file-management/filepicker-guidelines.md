# 文件选择器使用指导

文件选择器(FilePicker)是OpenHarmony中预置的系统应用，为用户提供文件选择及保存功能。具体实现可以参考[FilePicker代码仓库](https://gitee.com/openharmony/applications_filepicker)。

应用可以通过FilePicker的两种模式实现文件选择和文件保存的功能。
- choose模式（文件选择）：当应用需要选择并上传、发送设备中的文件（包括图片、音视频等媒体资源）时，可以选择该模式。拉起FilePicker的choose模式窗口，系统将弹出弹框供用户选择具体文件。用户通过界面选择目标文件并点击“上传”按钮，应用将接收到FilePicker传回的目标文件uri。
- save模式（文件保存）：当应用需要下载保存文件（包括图片、音视频等媒体资源）时，可以选择该模式。拉起FilePicker的save模式窗口，系统将弹出弹框供用户选择保存文件的目标路径。用户通过界面选择目标路径并点击“保存”按钮，应用将接收到FilePicker传回的已保存文件uri。

## 开发指导 

> **说明：**
> FilePicker仅支持基于Stage模型开发的应用拉起。<br/>
> Stage模型介绍请参考[应用模型解读](../application-models/application-model-description.md)。

使用不同的参数调用[AbilityContext.startAbilityForResult(want, options)](../reference/apis/js-apis-ability-context.md##abilitycontextstartabilityforresult-1)可以拉起FilePicker不同模式的窗口。

开发者需要通过[Want](../reference/apis/js-apis-application-want.md)指定"bundleName"和"abilityName"来拉起FilePicker，具体写法可参见下方的示例代码。

同时，开发者还需要设置属性Want.parameters，来指定FilePicker拉起的模式以及文件保存的名称：
- 文件选择：仅需要设置FilePicker拉起的窗口模式为`'startMode': 'choose'`。
- 文件保存：除了设置FilePicker拉起的窗口模式为`'startMode': 'save'`，还需要设置文件保存名称`'saveFile'`。

可以通过设置类型为[StartOptions](../reference/apis/js-apis-app-ability-startOptions.md)的入参options来指定弹出窗口样式，推荐设置为`windowMode: 102`，即自由悬浮形式窗口。

> **注意：**
> 1. save模式下，用户保存路径根据保存文件名执行强校验，用户保存路径参考[公共目录路径支持的文件格式](medialibrary-filepath-guidelines.md)。
> 2. 用户选择目标文件保存路径后，如存在同名文件，FilePicker将弹窗提醒用户是否覆盖原文件。

ArkTS语言示例代码如下：
```ts
// 拉起FilePicker选择文件
globalThis.context.startAbilityForResult(
    {
        bundleName: "com.ohos.filepicker",
        abilityName: "MainAbility",
        parameters: {
            'startMode': 'choose', //choose or save
        }
    },
    { windowMode: 102 }
)

// 拉起FilePicker保存文件
globalThis.context.startAbilityForResult(
    {
        bundleName: "com.ohos.filepicker",
        abilityName: "MainAbility",
        parameters: {
            'startMode': 'save', //choose or save
            'saveFile': 'test.jpg',
        }
    },
    { windowMode: 102 }
)

// FilePicker返回给startAbilityForResult的数据
var abilityResult = {
    resultCode: resultCode,
    want: {
        parameters: {
            'startMode': startMode,
            'result': result
        }
    }
}
globalThis.context.terminateSelfWithResult(abilityResult)
```

