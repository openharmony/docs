# Ability Development

## How do I obtain a notification when the device orientation changes?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

Use the **UIAbility.onConfigurationUpdate\(\)** callback to subscribe to system environment variable changes (including the language, color mode, and screen orientation).

**Reference**

[Subscribing to System Environment Variable Changes](../application-models/subscribe-system-environment-variable-changes.md#using-uiability-for-subscription)

## How do I redirect a user to a specified page after they touch a service widget?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

Configure a widget event with the redirected-to UIAbility specified, and call **loadContent** in the **onWindowStageCreate\(\)** callback of the target UIAbility to redirect to the specified page.

**Reference**

[Developing Widget Events](../application-models/arkts-ui-widget-configuration.md)

## How do I create a background service in the stage model?

Applicable to: OpenHarmony 3.2 Beta5

**Symptom**

**ServiceExtensionAbility** in the stage model is a system API. Therefore, third-party applications cannot use it to create a background service.

**Solution**

Create a background task to provide the background service.

**Reference**

[Background Task](../task-management/background-task-overview.md)

## Can I create a UIAbility and specify the process to run the UIAbility in the FA and Stage models?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

Yes.

-   FA model

    The FA model supports multiple processes. By default, all components of an application run in the same process. This default scenario is suitable for most applications. To run a specific component in an independent process, configure the **process** tag under **ability** in the configuration file. Note that this tag is available only for system applications.

-   Stage model

    The stage model supports multiple processes. The process model is defined by the system, and third-party applications cannot be configured with multiple processes. To customize an independent process, you must request special permissions, and then specify the **process** tag under **module** in the configuration file. This tag specifies the process in which all the abilities in an HAP run. If this tag is not set, the bundle name is used as the process name by default.


## What are the differences between the stage model and the FA model in intra-process object sharing?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

-   In the stage model, multiple application components share the same ArkTS engine instance. Therefore, they can easily share objects and state with each other. This also reduces the memory usage of complex applications.
-   In the FA model, each application component exclusively uses an ArkTS engine instance. Therefore, you are advised to use the stage model when developing complex applications in distributed scenarios.

**Reference**

[Data Synchronization Between UIAbility and UI](../application-models/uiability-data-sync-with-ui.md)

## How do I use the lifecycle functions of AbilityStage?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

Add the field **"srcEntry": "./ets/myabilitystage/MyAbilityStage.ts"** under **module** in the **module.json5** file.

**Reference**

[AbilityStage Component Container](../application-models/abilitystage.md)


## How do I delete the mission snapshot in Recents after terminateself is called in the multiton scenario?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

You can set **removeMissionAfterTerminate** to **true** in the **module.json5** file.

## Why can't I start a UIAbility instance by using startAbility\(\)?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

-   If the UIAbility is started using **startAbility**, check whether the **abilityName** field in **want** uses the bundle name as the prefix. If yes, delete the bundle name.
-   Make sure the UIAbility's home page file configured by **onWindowStageCreate** in the **MainAbility.ts** file is defined in the **main\_pages.json** file. You are advised to use the SDK and OpenHarmony SDK versions released on the same day.

## How do I prevent "this" in a method from changing to "undefined" when the method is called?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

Method 1: Add **.bind\(this\)** when calling the method.

Method 2: Use the arrow function.

## What should I do when the error message "must have required property 'startWindowIcon'" is displayed during the UIAbility startup?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

Configure the **startWindowIcon** attribute under **abilities** in the **module.json5** file.

**Example**

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

**Reference**

[module.json5 File](../quick-start/module-configuration-file.md)

## Can I obtain the context through globalThis in the stage model?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

Do not use **globalThis** to obtain the context in the stage model.

This is because all the processes of an application share a JS VM instance in the stage model. Multiple abilities can run on these processes and share the same global object. If **globalThis** is used, the context of different abilities of the same JS VM instance may be returned.

**Reference**

[Data Synchronization Between UIAbility and UI](../application-models/uiability-data-sync-with-ui.md)

## What should I do when an error indicating too large size is reported during HAP deployment?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Symptom**

During HAP deployment, the following error message is displayed:

Failure\[INSTALL\_FAILED\_SIZE\_TOO\_LARGE\] error while deploying hap?

**Solution**

You can split the HAP into multiple HAPs.

## How is data returned when startAbilityForResult is called?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

The target UIAbilities uses **AbilityContext.terminateSelfWithResult** to terminate itself and pass the result to **startAbilityForResult**.

**Reference**

[Starting UIAbility in the Same Application and Obtaining the Return Result](../application-models/uiability-intra-device-interaction.md)


## How do I obtain the system timestamp?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

Use **getCurrentTime** of **@ohos.systemDateTime** to obtain the system time and time zone.

**Example**

Use the **@ohos.systemDateTime** API as follows:

    ```
    try {
      systemDateTime.getCurrentTime(true, (error, time) => {
        if (error) {
          console.info(`Failed to get currentTime. message: ${error.message}, code: ${error.code}`);
          return;
        }
        console.info(`Succeeded in getting currentTime : ${time}`);
      });
    } catch(e) {
      console.info(`Failed to get currentTime. message: ${e.message}, code: ${e.code}`);
    }
    ```


**Reference**

[System time and time zone] (../reference/apis/js-apis-system-date-time.md#systemdatetimegetcurrenttime)

## How do I obtain the cache directory of the current application?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

Use **Context.cacheDir** to obtain the cache directory of the application.

**Reference**

[cacheDir](../application-models/application-context-stage.md#obtaining-application-file-paths)

## In which JS file is the service widget lifecycle callback invoked?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

When a widget is created, a **FormAblity.ts** file is generated, which contains the widget lifecycle.

**Reference**

[FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md)

## What should I do when the compilation on DevEco Studio fails while ServiceExtensionAbility and DataShareExtensionAbility APIs are used?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Symptom**

After the **ServiceExtensionAbility** and **DataShareExtensionAbility** APIs are used, DevEco Studio reports an error indicating that the compilation fails.

**Cause**

The following types of SDKs are provided:

-   Public SDK: intended for application developers and does not contain system APIs that require system permissions.
-   Full SDK: intended for original equipment manufacturers (OEMs) and contains system APIs that require system permissions.

The SDK downloaded using DevEco Studio is the public SDK.

**Solution**

Third-party application cannot use **ServiceExtensionAbility** and **DataShareExtensionAbility**. To develop a system application, first [download the full SDK](../quick-start/full-sdk-switch-guide.md).

## How do I obtain the temp and files paths at the application level?

Applicable to: OpenHarmony 3.2 Beta5

**Solution**

Obtain them from the application context. Specifically, use **this.context.getApplicationContext.tempDir** i to obtain the **temp** path, and use **this.context.getApplicationContext.filesDir** to obtain the **files** path.

**Reference**

[Obtaining Application File Paths](../application-models/application-context-stage.md#obtaining-application-file-paths)


## Can the lifecycle callback of a released FA widget be triggered when the widget is displayed in the service center so that the user login information can be obtained without opening the FA application? 

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

After a widget is added, the **onCreate()** lifecycle is triggered so that related user information (silent login) can be displayed even when the application is not started. However, users must manually add the widget after the application is installed.

## How do I implement service login by touching a widget?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

To create a service widget in the FA model, perform the following steps:

1. Implement lifecycle callbacks for the widget.

2. Configure the widget configuration file.

3. Persistently store widget data.

4. Update widget data.

5. Develop the widget UI page.

6. Develop a widget event. You can start a UIAbility upon the touch and implement service login in the UIAbility.

**Reference**

[Widget Development in the FA Model](../application-models/widget-development-fa.md)

## How do I redirect to the application details page in Settings?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

Refer to the following code:

```
this.context.startAbility(
{
  action: "action.settings.app.info",
  parameters: { "settingsParamBundleName": "your app bundlename" }
})
```

## How do I get UIAbilityContext within the @Component component in the stage model?

Applicable to: OpenHarmony 3.2 Beta5 (API version 9)

**Solution**

You can use **UIAbility.Context** to obtain the context.

**Example**

```
import UIAbility from '@ohos.app.ability.UIAbility';

let UIAbilityContext = UIAbility.context;
let ApplicationContext = UIAbility.context.getApplicationContext();
@Entry
@Component
struct AbilityContextTest {
  // abilityContext
  @State UIabilityInfo: string = 'Obtaining abilityInfo'
  UIabilityContext: UIAbilityContext

  aboutToAppear() {
    // Use getContext to obtain the context and convert it to abilityContext.
    this.UIabilityContext = getContext(this) as UIAbilityContext
  }

  build() {
    Row() {
      Column({ space: 20 }) {
        Text(this.abilityInfo)
          .fontSize(20)
          .onClick(()=>{
            this.UIabilityInfo = JSON.stringify(this.UIabilityContext.UIabilityInfo)
            console.log(`ContextDemo abilityInfo= ${this.UIabilityInfo}`)
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```
