# Ability Framework Development

## Is a guide similar to the Data ability development in the FA model available for the stage model?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

A guide is available for the **DataShareExtensionAbility** class, which provides APIs for sharing data with other applications and managing the data, in the stage model.

Reference: [DataShare Development](../database/database-datashare-guidelines.md)

## What should I do if the UI does not respond when an ability is started?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

1. If the ability is started using **startAbility**, check whether the **abilityName** field in **want** uses the bundle name as the prefix. If yes, delete the bundle name.

2. Make sure the ability's home page file configured by **onWindowStageCreate** in the **MainAbility.ts** file is defined in the **main_pages.json** file.

3. You are advised to use the SDK and OpenHarmony SDK versions released on the same day.

Reference: [Release Testing Version](https://gitee.com/openharmony-sig/oh-inner-release-management/blob/master/Release-Testing-Version.md)

## How do I set the UI of an ability to transparent?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Set the background color of the top container component to transparent, and then set the **opacity** attribute of the XComponent to **0.01**.

Example:

```
build() {
  Stack() {
    XComponent({
    id: 'componentId',
    type: 'surface',
    })
    .width('100%')
    .height('100%')
    .opacity(0.01)
    // Page content
  }
  .width('100%')
  .height('100%')
  .backgroundColor('rgba(255,255,255, 0)')
}
```

## How do I prevent "this" in a method from changing to "undefined" when the method is called?

Applicable to: OpenHarmony SDK 3.2.5.3, stage model of API version 9

Method 1: Add **.bind(this)** when calling the method.

Method 2: Use the arrow function.

## What should I do when the message "must have required property 'startWindowIcon'" is displayed?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Configure the **startWindowIcon** attribute under **abilities** in the **module.json5** file.

Reference: [Application Package Structure Configuration File](../quick-start/stage-structure.md)

Example:

```
{
  "module": {
    // Do something.
    "abilities": [{
      // Do something.
      "startWindowIcon": "$media:space",
      "startWindowBackground": "$color:white",
    }]
  }
}
```

## How do I obtain a notification when the device orientation changes?

Applicable to: OpenHarmony SDK 3.2.3.5, stage model of API version 9

Implement the **onConfigurationUpdated** callback in the **Ability** class. The callback is triggered when the system language, color mode, or display parameters (such as the orientation and density) change.

Reference: [Ability Development](../ability/stage-ability.md)

## Can I obtain the context through globalThis in the stage model?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Do not use **globalThis** to obtain the context in the stage model. This is because all the processes of an application share a JS VM instance in the stage model. Multiple abilities can run on these processes and share the same global object. If **globalThis** is used, the context of different abilities of the same JS VM instance may be returned.

For details about the recommended operation, see [Context in the Stage Model](../ability/context-userguide.md#context-in-the-stage-model).

## How do I obtain the HAP file installation path of application B from application A?

Applicable to: OpenHarmony SDK 3.0 or later, stage model of API version 9

First, request the system permission. For details, see [Having Your App Automatically Signed](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465). Then, import the **bundle** module, and call **bundle.getApplicationInfo()** to obtain application information based on the bundle name. Finally, use **application.moduleSourceDirs** to obtain the application storage path.

## How is data returned when startAbilityForResult is called?

Applicable to: OpenHarmony SDK3.0, stage model of API version 9

The callee uses **AbilityContext.terminateSelfWithResult** to destroy its ability and pass parameters to **startAbilityForResult**. For details, see [AbilityContext](../reference/apis/js-apis-ability-context.md#abilitycontextterminateselfwithresult).

## Can the lifecycle callback of a released FA widget be triggered when the widget is displayed in the service center so that the user login information can be obtained without opening the FA application?

Applicable to: OpenHarmony SDK 3.2.5.5, FA model of API version 8

After a widget is added, the **onCreate()** lifecycle is triggered so that related user information (silent login) can be displayed even when the application is not started. However, users must manually add the widget after the application is installed.

## How do I obtain the context?

Applicable to: OpenHarmony SDK 3.2.7.5, stage model of API version 9

You can use **this.context** to obtain the context in the **MainAbility.ts** file or call **getContext(this)** to obtain the context on the component page.

## What should I do when undefined is displayed for the calling of **abilityAccessCtrl.grantUserGrantedPermission** during API version 8 syntax verification?

Applicable to: OpenHarmony SDK 3.0, FA model of API version 8

**abilityAccessCtrl.grantUserGrantedPermission** is a system API. It is not available in the public SDK, which is provided as default on DevEco Studio. To use system APIs, switch to the full SDK. For details, see [Guide to Switching to Full SDK](../quick-start/full-sdk-switch-guide.md).

## Which of the following Extension abilities are available in the public SDK: ServiceExtensionAbility, FormExtensionAbility, and DataShareExtensionAbility?

Applicable to: OpenHarmony SDK 3.2.5.6, stage model of API version 9

Among the aforementioned Extension abilities, only **FormExtensionAbility** is available in the public SDK. **ServiceExtensionAbility** and **DataShareExtensionAbility** are system APIs and available only in the full SDK.

Public SDK: intended for application developers and does not contain system APIs that require system permissions.

Full SDK: intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.

## Why can't I play GIF images cyclically on the widget?

Applicable to: OpenHarmony SDK 3.2.5.6, stage model of API version 9

The system does not support the display of GIF images on the widget.

## How do I implement service login by touching a widget?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

You can start an ability upon the touch and implement service login in the ability.

## How do I redirect to the application details page in Settings?

Applicable to: OpenHarmony SDK 3.2.6.5

Refer to the following code:

```
this.context.startAbility(
{
  action: "action.settings.app.info",
  parameters: { "settingsParamBundleName": "your app bundlename" }
})
```

## How do I listen for screen rotation events?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Refer to the following code:

```
let listener = mediaquery.matchMediaSync('(orientation: landscape)')
onPortrait(mediaQueryResult) {
if (mediaQueryResult.matches) {
// Do something here.
    } else {
// Do something here.
    }
}
listener.on('change', onPortrait)
```

## How do I control the shadow background size during checkbox selection?

Applicable to: OpenHarmony SDK 3.2.5.5, stage model of API version 9

Set the **padding** attribute of the **\<checkbox>** component to control the shadow size.

## How do I set the widget background to transparent?

Applicable to: OpenHarmony SDK 3.2.5.5

1. Create the **widget/resources/styles/default.json** file in the root directory of the widget.

2. Add the following code to the **default.json** file:

```
{  
 "style": {   
      "app_background": "#00000000"   
   } 
}
```

## How do I pass parameters for FA widgets?

Applicable to: OpenHarmony SDK 3.2.5.5

Use **featureAbility.getWant()** and **featureAbility.getContext()** to send data through **router** in the JSON file and use **featureAbility** to receive data in the JS file.

## How do I trigger router.disableAlertBeforeBackPage and router.enableAlertBeforeBackPage?

Applicable to: OpenHarmony SDK 3.2.5.5

The following conditions must be met:

1. Before the redirection to the previous page, a confirm dialog box will be displayed. Note that **router.disableAlertBeforeBackPage** is used to disable the display of a confirm dialog box before returning to the previous page (default), and **router.enableAlertBeforeBackPage** is used to enable the display.

2. The system return key is used.
