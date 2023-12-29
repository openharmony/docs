# AccessibilityExtensionAbility

The **AccessibilityExtensionAbility** module provides accessibility extension capabilities based on the **ExtensionAbility** framework. You can develop your accessibility applications by applying the **AccessibilityExtensionAbility** template to enhance usability.

## AccessibilityExtensionAbility Overview

Accessibility is about giving equal access to everyone so that they can access and use information equally and conveniently under any circumstances. It helps narrow the digital divide between people of different classes, regions, ages, and health status in terms of information understanding, information exchange, and information utilization, so that they can participate in social life more conveniently and enjoy the benefits of technological advances.

AccessibilityExtensionAbility is an accessibility extension service framework. It allows you to develop your own extension services and provides a standard mechanism for exchanging information between applications and extension services. You can use the provided capabilities and APIs to develop accessibility features for users with disabilities or physical limitations. For example, you can develop a screen reader for users with vision impairments.

Below shows the AccessibilityExtensionAbility framework.

![AccessibilityFramework](figures/AccessibilityFramework.png)

1. Accessibility application: application developed based on the AccessibilityExtensionAbility framework to offer accessibility features, for example, a screen reader application.
2. Target application: application assisted by the accessibility application.
3. AccessibilityAbilityManagerService (AAMS): main service of the AccessibilityExtensionAbility framework, which is used to manage the lifecycle of accessibility applications and provide a bridge for information exchange between accessibility applications and target applications.
4. AccessibilityAbility (AAkit): ability that is used by the accessibility application to build an extension service ability operating environment and that provides interfaces for the accessibility application to query and operate the target application, including performing click/long press operations.
5. AccessibilitySystemAbilityClient (ASACkit): used by the target application to send accessibility events, such as content change events, to AAMS, and respond to the instructions (such as performing click/long press operations) sent by the accessibility application through AAMS.

## Capabilities Provided by Accessibility

1. Accessibility feature query capabilities: including capabilities to obtain the accessibility application list, accessibility application enabling status, accessibility application type, and capabilities to send accessibility events. For details about the APIs, see [@ohos.accessibility](../reference/apis/js-apis-accessibility.md).
2. Callbacks for events such as connection and disconnection of accessibility extension services, specified auxiliary events, and physical key events. For details about the APIs, see [@ohos.application.AccessibilityExtensionAbility](../reference/apis/js-apis-application-accessibilityExtensionAbility.md).
3. Context for accessibility extension services, which can be used to configure concerned information type, query node information, injects gestures, and more. For details about the APIs, see [AccessibilityExtensionContext ](../reference/apis/js-apis-inner-application-accessibilityExtensionContext.md). For details about the path information required to inject gestures, see [@ohos.accessibility.GesturePath](../reference/apis/js-apis-accessibility-GesturePath.md). For details about the gesture touch point information required to inject gestures, see [ohos.accessibility.GesturePoint](../reference/apis/js-apis-accessibility-GesturePoint.md).

## Creating an Accessibility Extension Service

You can create an accessibility extension service by creating a project from scratch or adding the service to an existing project. Only one accessibility extension service can be created for a project.
This example creates an accessibility extension service that implements the following functions:
When the accessibility function is enabled, a right-then-down gesture obtains all nodes on the current screen, and a following left-then-down gesture obtains all nodes.

### Creating a Project

To create an independent accessibility extension service, create a project in the stage model of API version 9 or later in DevEco Studio.

### Creating an AccessibilityExtAbility.ets File

In the **ets** folder of a project, add the **AccessibilityExtAbility** folder and then create the **AccessibilityExtAbility.ets** file in the folder. You can implement some callbacks in the file to add service processing logic.

```ts
import AccessibilityExtensionAbility, { AccessibilityEvent } from '@ohos.application.AccessibilityExtensionAbility';
import AccessibilityManager from './AccessibilityManager';

class AccessibilityExtAbility extends AccessibilityExtensionAbility {
    onConnect() {
        console.info(`AccessibilityExtAbility onConnect`);
        // Initialize the service logic.
        AccessibilityManager.getInstance().onStart(this.context);
    }

    onDisconnect() {
        console.info(`AccessibilityExtAbility onDisconnect`);
        // Reclaim resources and exit the service logic.
        AccessibilityManager.getInstance().onStop();
    }

    onAccessibilityEvent(accessibilityEvent: AccessibilityEvent) {
        console.info(`AccessibilityExtAbility onAccessibilityEvent: ${JSON.stringify(accessibilityEvent)}`);
        // Process the service logic based on the event information.
        AccessibilityManager.getInstance().onEvent(accessibilityEvent);
    }
}

export default AccessibilityExtAbility;
```

The APIs defined in the file are as follows.

| API| Description|
| ---- | ---- |
| onConnect(): void | Called when a connection with the extension service is set up.|
| onDisconnect(): void | Called when the connection with the extension service is severed.|
| onAccessibilityEvent(event: AccessibilityEvent): void | Called when an accessibility event occurs|

Create the **AccessibilityManager.ets** file for storing the service logic code.
```ts
import {
  AccessibilityElement,
  AccessibilityEvent,
  AccessibilityExtensionContext,
  ElementAttributeKeys
} from '@ohos.application.AccessibilityExtensionAbility';

interface Rect {
  left: number,
  top: number,
  width: number,
  height: number,
}

// Attribute information to be queried
let wantedAttribute: ElementAttributeKeys[] = ['bundleName', 'text', 'description', 'windowId'];
type attributeValues = string | number | boolean | AccessibilityElement | AccessibilityElement[] | string[] | Rect;

export default class AccessibilityManager {
  private static instance: AccessibilityManager;
  accessibleContext?: AccessibilityExtensionContext;
  currentPageElementArray: Array<AccessibilityElement> | null = null;

  static getInstance(): AccessibilityManager {
    if (!AccessibilityManager.instance) {
      AccessibilityManager.instance = new AccessibilityManager();
    }
    return AccessibilityManager.instance;
  }

  onStart(context: AccessibilityExtensionContext) {
    console.info(`AccessibilityManager onStart`);
    this.accessibleContext = context;
  }

  onStop() {
    console.info(`AccessibilityManager onStop`);
    this.accessibleContext = undefined;
  }

  onEvent(accessibilityEvent: AccessibilityEvent): void {
    console.info(`AccessibilityManager onEvent`);
    switch (accessibilityEvent.eventType) {
      case 'rightThenDown':
      // Obtain all nodes on the current screen.
        this.getCurrentPageAllElement();
        break;
      case 'leftThenDown':
      // Obtain all nodes.
        this.printAllElementInfo();
        break;
      default:
        break;
    }
  }

  async getCurrentPageAllElement(): Promise<void> {
    console.info(`AccessibilityManager getCurrentPageAllElement`);
    let rootElement: AccessibilityElement;
    if(!this.accessibleContext){
      console.error(`AccessibilityManager accessibleContext undefined`);
      return;
    }
    try {
      rootElement = await this.accessibleContext?.getWindowRootElement();
      this.currentPageElementArray = await this.getAttributeValue(rootElement, 'children') as AccessibilityElement[];
    } catch (error) {
      console.error(`AccessibilityExtAbility Failed to getWindowRootElement. Cause:${JSON.stringify(error)}`);
    }
  }

  async getElementWantedInfo(accessibilityElement: AccessibilityElement, wantedAttribute: ElementAttributeKeys[]):
    Promise<string | null> {
    console.info(`AccessibilityUtils getElementAllInfo`);
    if (accessibilityElement === null) {
      console.error(`AccessibilityUtils accessibilityElement is null`);
      return null;
    }

    let info = '';
    let value: attributeValues | null;
    for (let name of wantedAttribute) {
      value = await this.getAttributeValue(accessibilityElement, name);
      info = info.concat(name + ': ' + value + ' ');
    }
    return info;
  }

  async getAttributeValue(accessibilityElement: AccessibilityElement, key: ElementAttributeKeys):
    Promise<attributeValues | null> {
    console.info(`AccessibilityUtils getAttributeValue`);
    let value: attributeValues;
    let keys = await accessibilityElement.attributeNames();
    let isExit = false;
    for (let keyString of keys) {
      if (key == keyString) {
        isExit = true;
      }
    }
    if (isExit) {
      try {
        value = await accessibilityElement.attributeValue(key);
        return value;
      } catch (error) {
        console.error(`AccessibilityUtils Failed to get attributeValue of ${key} . Cause:  ${JSON.stringify(error)}`);
      }
    }
    return null;
  }

  async printAllElementInfo(): Promise<void> {
    console.info(`AccessibilityManager printAllElementInfo`);
    if (this.currentPageElementArray === null || this.currentPageElementArray.length === 0) {
      console.error(`AccessibilityManager currentPageElementArray is null`);
      return;
    }
    let info: string | null = null;
    for (let index = 0; index < this.currentPageElementArray.length; index++) {
      info = await this.getElementWantedInfo(this.currentPageElementArray[index], wantedAttribute);
      console.info(`AccessibilityManager element information: ${info}`);
    }
  }
}
```

## Processing an Accessibility Event

You can process the service logic for accessibility events through the **onAccessibilityEvent()** API. For details about the events, see [AccessibilityEvent](../reference/apis/js-apis-application-accessibilityExtensionAbility.md#accessibilityevent). In this example, the **rightThenDown** gesture is used.

```ts
onAccessibilityEvent(accessibilityEvent: AccessibilityEvent) {
    console.info('AccessibilityExtAbility onAccessibilityEvent: ' + JSON.stringify(accessibilityEvent));
    if (accessibilityEvent.eventType === 'rightThenDown') {
        console.info('AccessibilityExtAbility onAccessibilityEvent: rightThenDown');
        // TODO: Develop custom logic.
    }
}
```
For an accessibility event, you can use the APIs of the [AccessibilityExtensionContext](../reference/apis/js-apis-inner-application-accessibilityExtensionContext.md) module to configure the concerned information, obtain root information, and inject gestures.

You can also process physical key events in the accessibility extension service. For details, see [onKeyEvent](../reference/apis/js-apis-application-accessibilityExtensionAbility.md#accessibilityextensionabilityonkeyevent).

## Declaring Capabilities of Accessibility Extension Services

After developing the custom logic for an accessibility extension service, you must add the configuration information of the service to the corresponding module-level **module.json5** file in the project directory. In the file, the **srcEntry** tag indicates the path to the accessibility extension service. Make sure the value of the **type** tag is fixed at **accessibility**. Otherwise, the connection to the service will fail.

```json
"extensionAbilities": [
  {
    "name": "AccessibilityExtAbility",
    "srcEntry": "./ets/AccessibilityExtAbility/AccessibilityExtAbility.ets",
    "label": "$string:MainAbility_label",
    "description": "$string:MainAbility_desc",
    "type": "accessibility",
    "metadata": [
      {
        "name": "ohos.accessibleability",
        "resource": "$profile:accessibility_config"
      }
    ]
  }
]
```
In addition, **accessibility_config** is the specific configuration of the accessibility extension service. You need to create the **accessibility_config.json** file in **resources/base/profile/** and declare the [capability type](../reference/apis/js-apis-accessibility.md#capability) of the accessibility extension service in the file. In this example, the following declaration is required:
```json
{
  "accessibilityCapabilities": [
    "retrieve",
    "gesture",
    "touchGuide"
  ]
}
```
## Enabling or Disabling a Custom Accessibility Extension Service

You can enable or disable a custom accessibility extension service through the device settings. 

- From the device settings screen, access the list of installed extended services under accessibility. 
If an extended service is not installed, it is grayed out, and "No service" is displayed.
- Select the target extended service, and toggle on or off the switch to enable or disable it. 
- If you opt to enable a service, a security reminder is displayed. Wait until the countdown ends and then select the check box indicating that you are aware of and willing to assume the listed risks.  
