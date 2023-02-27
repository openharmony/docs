# ArkUI Subsystem Changelog

## cl.arkui.1 Return Value Type Change of getInspectorTree

**Change Impact**

The code that uses the **getInspectorTree** API in versions earlier than OpenHarmony 4.0.3.2 must be adapted.

**Key API/Component Changes**

The return value of the **getInspectorTree** API is changed from the string type to the Object type.

**Adaptation Guide**

Adapt the code that takes the return value of **getInspectorTree** as a string.The sample code is as follows:

- Before change:

```typescript
console.info(getInspectorTree())
```

- After change:

```typescript
console.info(JSON.stringify(getInspectorTree())) 
```

## cl.arkui.2 Deprecation the forceRebuild Attribute of \<GridItem>

**Change Impact**

None. The attribute has no effect.

**Key API/Component Changes**

Deprecate the **forceRebuild** attribute of the **\<GridItem>** component.

**Adaptation Guide**

Delete the code that uses the **forceRebuild** attribute. This will not affect the functionality of the **\<GridItem>** component.


## cl.arkui.1 API Changes of the Router Module in API Version 9

Replaced the **enableAlertBeforeBackPage**, **enableBackPageAlert**, **disableAlertBeforeBackPage** APIs in **ohos.router** to **showAlertBeforeBackPage** and **hideAlertBeforeBackPage** to facilitate development.

**Change Impact**

The **enableAlertBeforeBackPage** and **enableBackPageAlert** APIs must be replaced with **showAlertBeforeBackPage**.

The **disableAlertBeforeBackPage** API must be replaced with **hideAlertBeforeBackPage**.

**Key API/Component Changes**

**router.enableAlertBeforeBackPage**, **router.enableBackPageAlert**, and **router.disableAlertBeforeBackPage**

* Before change:

```ts
router.enableAlertBeforeBackPage();
router.enableBackPageAlert()
```

* After change:

```ts
router.showAlertBeforeBackPage()
```

* Before change:

```ts
router.disableAlertBeforeBackPage()
```

* After change:

```ts
router.hideAlertBeforeBackPage()
```

**Adaptation Guide**

Replace **enableAlertBeforeBackPage** and **enableBackPageAlert** with **showAlertBeforeBackPage**.

Replace **disableAlertBeforeBackPage** with **hideAlertBeforeBackPage**.
