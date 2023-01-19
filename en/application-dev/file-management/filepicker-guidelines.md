# FilePicker Guide

FilePicker is a system application preset in OpenHarmony. You can use it to select and save files. For details about the implementation of FilePicker, see [applications_filepicker](https://gitee.com/openharmony/applications_filepicker).

FilePicker provides the following modes:
- **choose**: Use this mode when an application needs to select and upload or send files (including media resources such as images, and audio and video clips) in the device. When this mode is selected, the FilePicker **choose** mode window will be triggered to display a dialog box for you to select a file. You can select the target file and tap **Upload**. The application will receive the URI of the target file returned by FilePicker.
- **save**: Use this mode when an application needs to download and save files (including media resources such as images and audio and video clips). When this mode is selected, the FilePicker **save** mode window will be triggered to display a dialog box for you to select the destination path of the file to save. You can select the destination path and tap **Save**. The application will receive the URI of the saved file returned by FilePicker.

## Development Guidelines

> **NOTE**
>
> FilePicker supports only the applications developed based on the stage model.
> For details about the stage model, see [Interpretation of the Application Model](../application-models/application-model-description.md).

You can use [AbilityContext.startAbilityForResult(want, options)](../reference/apis/js-apis-ability-context.md##abilitycontextstartabilityforresult-1) with different parameters to start different FilePicker modes.

You need to use [Want](../reference/apis/js-apis-application-want.md) to specify **bundleName** and **abilityName** to start FilePicker. For details, see the following sample code.

You also need to set **Want.parameters** to specify the FilePicker mode to start and the name of the file to save.
- To select a file, set **'startMode': 'choose'**.
- To save a file, set **'startMode': 'save'** and **'saveFile'**.

You can set **options** of the [StartOptions](../reference/apis/js-apis-app-ability-startOptions.md) type to specify the dialog box style. The recommended value is **windowMode: 102**, which indicates a floating window.

> **CAUTION**
> - In the **save** mode, a strong verification is performed on the file path based on the name of the file to save. For details about the file path format, see [File Path Management](medialibrary-filepath-guidelines.md).
> - If a file with the same name exists, a dialog box will be displayed asking you whether to overwrite the existing file.

ArkTS sample code:
```ts
// Start FilePicker to select a file.
globalThis.context.startAbilityForResult(
    {
        bundleName: "com.ohos.filepicker",
        abilityName: "EntryAbility",
        parameters: {
            'startMode': 'choose', //choose or save
        }
    },
    { windowMode: 102 }
)

// Start FilePicker to save a file.
globalThis.context.startAbilityForResult(
    {
        bundleName: "com.ohos.filepicker",
        abilityName: "EntryAbility",
        parameters: {
            'startMode': 'save', //choose or save
            'saveFile': 'test.jpg',
        }
    },
    { windowMode: 102 }
)

// Data returned by FilePicker to startAbilityForResult.
let abilityResult = {
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
