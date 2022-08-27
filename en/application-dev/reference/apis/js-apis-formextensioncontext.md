# FormExtensionContext

The **FormExtensionContext** module, inherited from **ExtensionContext**, provides context for Form Extension abilities.

You can use the APIs of this module to start Form Extension abilities.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Usage

Before using the **ServiceExtensionContext** module, you must first obtain a **FormExtension** instance.
```js
import FormExtension from '@ohos.application.FormExtension';
import formBindingData from '@ohos.application.formBindingData'
export default class MyFormExtension extends FormExtension {
    onCreate() {
        let dataObj1 = {
            temperature:"11c",
            "time":"11:00"
        };
        let obj1 = formBindingData.createFormBindingData(dataObj1);
        return obj1;
    }
}

```

## FormExtensionContext.startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name|                Type              | Mandatory|              Description              |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](js-apis-application-Want.md) | Yes | Information about the ability to start, such as the ability name and bundle name.|
| callback| AsyncCallback&lt;void&gt;       | Yes | Callback used to return the result.|

**Example**

```js
var want = {
    deviceId: "",
    bundleName: "com.example.formstartability",
    abilityName: "MainAbility",
    action: "action1",
    entities: ["entity1"],
    type: "MIMETYPE",
    uri: "key={true,true,false}",
    parameters: {}
}
this.context.startAbility(want, function(err) {
    console.info(err.code);
})
```

## FormExtensionContext.startAbility

startAbility(want: Want): Promise&lt;void&gt;

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.Form

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name|                Type              | Mandatory|              Description              |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](js-apis-application-Want.md) | Yes | Information about the ability to start, such as the ability name and bundle name.|

**Return value**

| Type         | Description                               |
| ------------ | ---------------------------------- |
| Promise&lt;void&lt; | Promise used to return the result.|

**Example**

```js
var want = {
    deviceId: "",
    bundleName: "com.example.formstartability",
    abilityName: "MainAbility",
    action: "action1",
    entities: ["entity1"],
    type: "MIMETYPE",
    uri: "key={true,true,false}",
    parameters: {}
}
this.context.startAbility(want).then(() => {
    console.info("StartAbility Success");
}).catch((error) => {
    console.info("StartAbility failed");
});
```
