# In-Application Embedded Component (EmbeddedComponent)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @dutie123-->
<!--Designer: @dutie123-->
<!--Tester: @fredyuan0912-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=04ff9074f3c577e505d0a99eec93fa72810d5fa3 translatedAt=2026-07-30T11:34:52.114Z pushedAt=2026-07-31T01:46:04.974Z -->

The **EmbeddedComponent** allows the current page to embed UI content provided by other EmbeddedUIExtensionAbility instances within the same app. These UIs run in independent processes, offering higher security and stability.

The **EmbeddedComponent** is primarily used for cross-module, cross-process embedded UI integration. Its core objective is to improve application flexibility and user experience through modular design.

Be aware of the component's usage constraints and lifecycle management to maximize its benefits in application architecture.

## Basic Concepts

- [EmbeddedComponent](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md)

  The **EmbeddedComponent** enables embedding UI content from another EmbeddedUIExtensionAbility within the same application. It supports modular development scenarios requiring process isolation, allowing flexible UI design by integrating specific functionalities or interfaces into another page.

- [EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md)

  Defined and used in the provider app to implement cross-process UI embedding. By default, it can only be started by a UIAbility of the same app (starting from API version 26.0.0, cross-app startup is supported when specific permission conditions are met. For details, see Constraints - Applicable Scope), and it must be used in scenarios where multi-process permissions are enabled.

## Constraints

- Device Requirements

  The **EmbeddedComponent** is supported only on devices that support [EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md).

- Applicable Scope

  The **EmbeddedComponent** can only be used in a [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md), and the EmbeddedUIExtensionAbility being started must belong to the same app as the UIAbility. Starting from API version 26.0.0, if the app to which the **EmbeddedComponent** belongs has applied for the ohos.permission.SUPPORT_CROSS_APP_EMBED_FOR_OA permission (this permission can only be applied for by enterprise normal apps), and the [appIdentifier](../quick-start/common-problem-of-application.md#what-is-appidentifier) of that app is included in the app list supported by the EmbeddedUIExtensionAbility (that is, the appIdentifierAllowList attribute of the [extensionAbilities tag](../quick-start/module-configuration-file.md#extensionabilities)), the **EmbeddedComponent** is allowed to start the EmbeddedUIExtensionAbility across apps.

- Attribute Restrictions

  The **EmbeddedComponent** supports [universal attributes](../reference/apis-arkui/arkui-ts/ts-component-general-attributes.md), with default and minimum width and height values set to 10 vp.

  The following width- and height-related attributes are not supported:

  "[constraintSize](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#constraintsize)", "[aspectRatio](../reference/apis-arkui/arkui-ts/ts-universal-attributes-layout-constraints.md#aspectratio)", "[layoutWeight](../reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#layoutweight)", "[flexBasis](../reference/apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexbasis)", "[flexGrow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexgrow)", and "[flexShrink](../reference/apis-arkui/arkui-ts/ts-universal-attributes-flex-layout.md#flexshrink)".

- Event handling

  Event information related to screen coordinates is converted based on the position, width, and height of the **EmbeddedComponent**, before being passed to the EmbeddedUIExtensionAbility for processing.

  The **EmbeddedComponent** does not support universal events such as the [click event](../reference/apis-arkui/arkui-ts/ts-universal-events-click.md). It only supports the [onTerminated](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md#onterminated) event and the [onError](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md#onerror) event. Starting from API version 26.0.0, the [onDrawReady](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md#ondrawready) event is also supported.

## Focus Behavior

Before API version 26.0.0, when the **EmbeddedComponent** gained focus, the focus within the EmbeddedUIExtensionAbility process it started was directly dispatched to the first focusable child node. Starting from API version 26.0.0,

1. If focus moves from outside to the EmbeddedUIExtensionAbility, focus is normally dispatched to the first focusable child node.

2. If focus is transferred to the EmbeddedUIExtensionAbility due to page level switching, the same rule as the UIAbility applies. When either starts a hierarchical page and that page has neither set [defaultFocus](../reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md#defaultfocus9) nor [actively requested focus](arkts-common-events-focus-event.md#active-focus-acquisitionloss), focus remains on the root container and is not dispatched to child nodes.

## Scenario Example

This example demonstrates the basic usage of the **EmbeddedComponent** and EmbeddedUIExtensionAbility.

**Host Page**

The add-on home page is the host page for the **EmbeddedComponent**, responsible for loading and displaying the content of the embedded UI extension capability. The following is a complete implementation example of an add-on home page.

<!-- @[embedded_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIExtensionAndAccessibility/entry/src/main/ets/pages/EmbeddedComponent/Embedded.ets) -->

``` TypeScript
import { Want } from '@kit.AbilityKit';

@Component
export struct Embedded {
  @State message: string = 'Message: ';
  private want: Want = {
    bundleName: 'com.samples.uiextensionandaccessibility',
    abilityName: 'ExampleEmbeddedAbility',
  };
  build() {
    // ...
      Row() {
        Column() {
          Text(this.message).fontSize(30)
          EmbeddedComponent(this.want, EmbeddedType.EMBEDDED_UI_EXTENSION)
            .width('100%')
            .height('90%')
            .onTerminated((info) => {
              // onTerminated is triggered when the terminateSelfWithResult button is clicked on the extension page.
              this.message = `Termination: code = ${info.code} , want = ${JSON.stringify(info.want)}`;
            })
            .onError((error) => {
              // onError is triggered on failure or exception.
              this.message = `Error: code = ${error.code}`;
            })
            .onDrawReady(() => {
              // Starting from API version 26.0.0, the onDrawReady callback is triggered when the launched EmbeddedUIExtensionAbility draws the first frame.
            })
        }
        .width('100%')
      }
      .height('100%')
      // ...
  }
}
```

In an ArkTS project, the implementation code of the EmbeddedUIExtensionAbility is typically located in the ets/extensionability directory of the project. For example, the ExampleEmbeddedAbility.ets file is located in the ./ets/extensionability/ directory.

Key considerations for implementing the host page:

- Multi-process model check

  Check whether the device has multi-process mode enabled during application startup. Provide clear error messages or guidance if it is disabled.

- Exception handling

  Use the [onError](../reference/apis-arkui/arkui-ts/ts-container-embedded-component.md#onerror) event to handle errors during embedded ability loading or execution.

- Lifecycle management

  Manage the lifecycle of the **EmbeddedComponent** to ensure proper resource cleanup.

- Style configuration

  Properly configure the size and position of the **EmbeddedComponent** to display embedded UIs as expected.

**Provider Application Lifecycle Implementation**

The provider application implements embedded UI extension abilities. Below is an example lifecycle implementation:

<!-- @[exampleEmbeddedAbility_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIExtensionAndAccessibility/entry/src/main/ets/extensionability/ExampleEmbeddedAbility.ets) -->

``` TypeScript
import { EmbeddedUIExtensionAbility, UIExtensionContentSession, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[ExampleEmbeddedAbility]'

export default class ExampleEmbeddedAbility extends EmbeddedUIExtensionAbility {
  onCreate() {
    hilog.info(0x0000, TAG, '%{public}s', `onCreate`);
  }

  onForeground() {
    hilog.info(0x0000, TAG, '%{public}s',  `onForeground`);
  }

  onBackground() {
    hilog.info(0x0000, TAG, '%{public}s', `onBackground`);
  }

  onDestroy() {
    hilog.info(0x0000, TAG, '%{public}s', `onDestroy`);
  }

  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    hilog.info(0x0000, TAG, '%{public}s', `onSessionCreate, want: ${JSON.stringify(want)}`);
    let param: Record<string, UIExtensionContentSession> = {
      'session': session
    };
    let storage: LocalStorage = new LocalStorage(param);
    // Load the Extension.ets page content.
    session.loadContent('pages/EmbeddedComponent/Extension', storage);
  }

  onSessionDestroy(session: UIExtensionContentSession) {
    hilog.info(0x0000, TAG, '%{public}s', `onSessionDestroy`);
  }
}
```

Key implementation details:

- Lifecycle stages

  [onCreate](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#oncreate) → [onForeground](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#onforeground): the complete flow from EmbeddedUIExtensionAbility initialization to visibility;

  [onBackground](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#onbackground) → [onForeground](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#onforeground): state transition during foreground-background switching;

  [onDestroy](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#ondestroy): the resource cleanup point when the EmbeddedUIExtensionAbility is destroyed.

- Session management

  [onSessionCreate](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#onsessioncreate): creates an independent storage context and loads the UI;

  [onSessionDestroy](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#onsessiondestroy): handles cleanup when the session ends (for example, when the user actively closes it).

- Context passing

  Implements cross-component passing of [UIExtensionContentSession](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md) through [LocalStorage](../ui/state-management/arkts-localstorage.md);

  Uses the [loadContent](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#loadcontent) method to bind the ArkTS page to the extension capability context.

**Entry Page**

The following is an implementation of the entry component of the provider application, which demonstrates how to use **UIExtensionContentSession** and how to exit the embedded page and return the result through a button click event. This code file needs to be declared in the **main_pages.json** configuration file.

<!-- @[extension_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIExtensionAndAccessibility/entry/src/main/ets/pages/EmbeddedComponent/Extension.ets) -->

``` TypeScript
import { UIExtensionContentSession } from '@kit.AbilityKit';

@Entry()
@Component
struct Extension {
  @State message: string = 'EmbeddedUIExtensionAbility Index';
  private storage: LocalStorage | undefined = this.getUIContext().getSharedLocalStorage();
  private session: UIExtensionContentSession | undefined = this.storage?.get<UIExtensionContentSession>('session');

  build() {
    Column() {
      Text(this.message)
        .fontSize(20)
        .fontWeight(FontWeight.Bold)
      Button('terminateSelfWithResult').fontSize(20).onClick(() => {
        // Call terminateSelfWithResult to exit when the button is clicked.
        this.session?.terminateSelfWithResult({
          resultCode: 1,
          want: {
            bundleName: 'com.samples.uiextensionandaccessibility',
            abilityName: 'ExampleEmbeddedAbility',
          }
        });
      })
    }.width('100%').height('100%')
  }
}
```

Key considerations for implementing the entry page:

1. Session management

   Properly obtain and use the **UIExtensionContentSession** instances to ensure communication with the host application.

2. Result return

   When returning results to the host through **terminateSelfWithResult**, specify:

   - **resultCode**: result code.

   - **want**: recipient of the result.

3. Page lifecycle

   Manage the lifecycle of the entry page to ensure proper resource cleanup.

4. Style configuration

   Properly configure page element styles to display the page as expected.

**Configuration**

  To enable embedded UI extension abilities, configure the application's configuration file.

  Add the **ExampleEmbeddedAbility** configuration under the **extensionAbilities** tag in the **module.json5** file:

<!-- @[exampleEmbeddedAbility_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/UIExtensionAndAccessibility/entry/src/main/module.json5) -->

``` JSON5
{
  "name": "ExampleEmbeddedAbility",
  "srcEntry": "./ets/extensionability/ExampleEmbeddedAbility.ets",
  "type": "embeddedUI"
}
```

**Expected Results**

1. Start the application on the device that supports **EmbeddedUIExtensionAbility**.

   ![en-us_image_0000001502261065](figures/Scenario-Example.jpg)

2. Clicking the **terminateSelfWithResult** button hides the provider content and displays **onTerminated** information.

<!--no_check-->