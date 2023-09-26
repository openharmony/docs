# ArkUI Subsystem ChangeLog

## cl.arkui.1 xcomponent API Change

Changed the following APIs of the **xcomponent** component of the ArkUI subsystem:

 - **getXComponentSurfaceId** and **setXComponentSurfaceSize**: Removed the **@systemapi** tag.
 - **getXComponentSurfaceId**, **getXComponentContext**, and **setXComponentSurfaceSize**: Specified return value types.

You need to adapt your application based on the following information.


**Change Impact**

Released JS APIs are affected. The application needs to adapt these APIs so that it can be properly compiled in the SDK environment of the new version.

**Key API/Component Changes**

 - **getXComponentSurfaceId**: is changed to a public API, with its return value type specified as string.
 - **setXComponentSurfaceSize**: is changed to a public API, with its return value type specified as void.
 - **getXComponentContext**: has its return value type specified as object.

**Adaptation Guide**

Startup rules for different scenarios are as follows:

Adaptions to be made:

  - **getXComponentSurfaceId**
    - In OpenHarmony 3.2 Beta3:
      - System API
      - No specified return value
    - In OpenHarmony 3.2 Beta4:
      - Public API
      - Return value type specified as string
      - You need to process the return value as a string.
  - **setXComponentSurfaceSize**
    - In OpenHarmony 3.2 Beta3:
      - System API
      - No specified return value
    - In OpenHarmony 3.2 Beta4:
      - Public API
      - Return value type specified as void
      - You need to process the return value as a void.
  - **getXComponentContext**
    - In OpenHarmony 3.2 Beta3:
      - No specified return value
    - In OpenHarmony 3.2 Beta4:
      - Return value type specified as object
      - You need to process the return value as an object.
        
## cl.arkui.2 Change of Styles of Popup Component and APIs

The styles of the **alertDialog**, **actionSheet**, and **customDialog** components, as well as the **prompt** and **promptAction** APIs were changed. Specifically speaking:

The popup background blurring effect is added to **promptAction.showDialog**, **promptAction.showActionMenu**, **alertDialog**, **actionSheet**, and **customDialog**.

**Change Impact**

The popup background blurring effect is set by default.

**Key API/Component Changes**

APIs: **promptAction.showDialog** and **promptAction.showActionMenu;**
Components: **alertDialog**, **actionSheet**, and **customDialog**

**Adaptation Guide**

No adaptation is required.

## cl.arkui.3 Supplementation of the Initialization Mode and Restriction Verification Scenarios of Custom Components' Member Variables

Added verification for scenarios previously left out concerning initialization of custom components' member variables.


**Change Impact**

If custom components' member variables are initialized or assigned with values not according to the document specifications, an error will be reported during compilation.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Make modification according to specifications in the above document.

## cl.arkui.4 Supplementation of Verification Scenarios of Value Assignment Restrictions on Member Variables of Custom Parent Components and Child Components

Added verification for scenarios previously left out concerning value assignment of member variables of custom parent components and child components.


**Change Impact**

If member variables of the parent component or child component are initialized not according to the document specifications, an error will be reported during compilation.

**Key API/Component Changes**

N/A

**Adaptation Guide**

Make modification according to specifications in the above document, using other decorators or normal member variables for value assignment.

## cl.arkui.5 Supplementation of Verification for a Single Child Component

Added verification for a single child component for the following components: **Button**, **FlowItem**, **GridItem**, **GridCol**, **ListItem**, **Navigator**, **Refresh**, **RichText**, **ScrollBar**, **StepperItem**, and **TabContent**.

**Change Impact**

If one of the preceding components contains more than one child component, an error will be reported during compilation.

**Key API/Component Changes**

```js
RichText('RichText') {
    Text('Text1')
    Text('Text2')
}
/* ArkTS:ERROR File: /root/newOH/developtools/ace-ets2bundle/compiler/sample/pages/home.ets:25:7
 The component 'RichText' can only have a single child component. */
```

**Adaptation Guide**

Make modification based on the error message. Make sure that the specified component contains only one child component.
