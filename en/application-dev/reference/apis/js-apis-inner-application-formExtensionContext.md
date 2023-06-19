# FormExtensionContext

The **FormExtensionContext** module, inherited from **ExtensionContext**, provides context for FormExtensionAbilities.

You can use the APIs of this module to start FormExtensionAbilities.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## Usage

Before using the **ServiceExtensionContext** module, you must first obtain a **FormExtensionAbility** instance.

```ts
import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
import formBindingData from '@ohos.app.form.formBindingData';
export default class MyFormExtensionAbility extends FormExtensionAbility {
    onAddForm() {
        let formContext = this.context; // Obtain a FormExtensionContext instance.
        // ...
        let dataObj1 = {
            temperature:'11c',
            'time':'11:00'
        };
        let obj1 = formBindingData.createFormBindingData(dataObj1);
        return obj1;
    }
}
```

## startAbility

startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.Form

**Error codes**

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16500101 | The application is not a system application. |
| 16501000 | An internal functional error occurred. |
|For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).|

**Parameters**

| Name|                Type              | Mandatory|              Description              |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](js-apis-application-want.md) | Yes | Information about the ability to start, such as the bundle name, ability name, and custom parameters.|
| callback| AsyncCallback&lt;void&gt;       | Yes | Callback used to return the result. If the ability is started, **err** is undefined; otherwise, **err** is an error object.|

**Example**

```ts
let want = {
    deviceId: '',
    bundleName: 'com.example.formstartability',
    abilityName: 'MainAbility',
    action: 'action1',
    entities: ['entity1'],
    type: 'MIMETYPE',
    uri: 'key={true,true,false}',
    parameters: {}
};
this.context.startAbility(want, (error) => {
    if (error) {
      console.log('FormExtensionContext startAbility, error:' + JSON.stringify(error));
    } else {
      console.log(`FormExtensionContext startAbility success`);
    }
});
```

## startAbility

startAbility(want: Want): Promise&lt;void&gt;

Starts an ability. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.Form

**Parameters**

| Name|                Type              | Mandatory|              Description              |
| ------| --------------------------------- | ---- | -------------------------------------- |
| want| [Want](js-apis-application-want.md) | Yes | Information about the ability to start, such as the bundle name, ability name, and custom parameters.|

**Return value**

| Type         | Description                               |
| ------------ | ---------------------------------- |
| Promise&lt;void&lt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| -------- | -------- |
| 202 | The application is not a system application. |
| 401 | If the input parameter is not valid parameter. |
| 16500050 | An IPC connection error happened. |
| 16500100 | Failed to obtain the configuration information. |
| 16500101 | The application is not a system application. |
| 16501000 | An internal functional error occurred. |
|For details about the error codes, see [Form Error Codes](../errorcodes/errorcode-form.md).|

**Example**

```ts
let want = {
    deviceId: '',
    bundleName: 'com.example.formstartability',
    abilityName: 'MainAbility',
    action: 'action1',
    entities: ['entity1'],
    type: 'MIMETYPE',
    uri: 'key={true,true,false}',
    parameters: {}
};
this.context.startAbility(want).then(() => {
    console.info('StartAbility Success');
}).catch((error) => {
    console.info('StartAbility failed');
});
```
