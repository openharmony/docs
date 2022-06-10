# Stage Widget Development

## Widget Overview

A widget is a set of UI components used to display important information or operations for an application. It provides users with direct access to a desired application service, without requiring them to open the application.

A widget displays brief information about an application on the UI of another application (host application, currently system applications only) and provides basic interactive features such as opening a UI page or sending a message. The widget host is responsible for displaying the service widget.

Basic concepts:

- Widget provider<br>
  The widget provider is an atomic service that provides the content to be displayed. It controls the display content, component layout, and component click events of a widget.
- Widget host<br>
  The widget host is an application that displays the widget content and controls the position where the widget is displayed in the host application.
- Widget Manager<br>
  The Widget Manager is a resident agent that manages widgets added to the system and provides functions such as periodic widget update.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> The widget host and provider do not keep running all the time. The Widget Manager starts the widget provider to obtain widget information when a widget is added, deleted, or updated.

You only need to develop widget content as the widget provider. The system automatically handles the work done by the widget host and Widget Manager.

The widget provider controls the widget content to display, component layout, and click events bound to components.

## When to Use

Stage ability development refers to the development conducted by the widget provider based on the [stage model](stage-brief.md). As a widget provider, you need to carry out the following operations:

- Develop the lifecycle callback functions in **FormExtension**.
- Create a **FormBindingData** object.
- Update a widget through **FormProvider**.
- Develop the widget UI page.

## Available APIs

The **FormExtension** class has the **context** attribute. For details on the APIs provided by the **FormExtension** class, see [FormExtension](../reference/apis/js-apis-formextension.md).

**Table 1** FormExtension APIs

| API                                                      | Description                                        |
| :----------------------------------------------------------- | :------------------------------------------- |
| onCreate(want: Want): formBindingData.FormBindingData        | Called to notify the widget provider that a **Form** instance (widget) has been created.          |
| onCastToNormal(formId: string): void                         | Called to notify the widget provider that a temporary widget has been converted to a normal one.|
| onUpdate(formId: string): void                               | Called to notify the widget provider that a widget has been updated.          |
| onVisibilityChange(newStatus: { [key: string]: number }): void | Called to notify the widget provider of the change of widget visibility.        |
| onEvent(formId: string, message: string): void               | Called to instruct the widget provider to receive and process the widget event.      |
| onDestroy(formId: string): void                              | Called to notify the widget provider that a **Form** instance (widget) has been destroyed.          |
| onConfigurationUpdated(config: Configuration): void;         | Called when the configuration of the environment where the ability is running is updated.                      |

The **context** attribute of the **FormExtension** class inherits from the **FormExtensionContext** class. For details about the APIs provided by the **FormExtensionContext** class, see [FormExtensionContext](../reference/apis/js-apis-formextensioncontext.md).

**Table 2** FormExtensionContext APIs

| API                                                      | Description                     |
| :----------------------------------------------------------- | :------------------------ |
| updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<void>): void | Updates a widget. This method uses a callback to return the result.   |
| updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void> | Updates a widget. This method uses a promise to return the result.|

For details about the **FormProvider** APIs, see [FormProvider](../reference/apis/js-apis-formprovider.md).

**Table 3** FormProvider APIs

| API                                                      | Description                                             |
| :----------------------------------------------------------- | :------------------------------------------------ |
| setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void; | Sets the next refresh time for a widget. This API uses an asynchronous callback to return the result.                   |
| setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;; | Sets the next refresh time for a widget. This API uses a promise to return the result.|
| updateForm(formId: string, formBindingData: FormBindingData, callback: AsyncCallback&lt;void&gt;): void; | Updates a widget. This API uses an asynchronous callback to return the result.                                 |
| updateForm(formId: string, formBindingData: FormBindingData): Promise&lt;void&gt;; | Updates a widget. This API uses a promise to return the result.              |

## How to Develop

### Creating a Form Extension

To create a widget in the stage model, you need to implement the lifecycle callback functions of **FormExtension**. The sample code is as follows:

1. Import the required modules.

   ```javascript
   import FormExtension from '@ohos.application.FormExtension'
   import formBindingData from '@ohos.application.formBindingData'
   import formInfo from '@ohos.application.formInfo'
   import formProvider from '@ohos.application.formProvider'
   ```

2. Implement the lifecycle callback functions of **FormExtension**.

   ```javascript
   export default class FormAbility extends FormExtension {
       onCreate(want) {
           console.log('FormAbility onCreate');
           // Persistently store widget information for subsequent use, such as widget instance retrieval and update.
           let obj = {
               "title": "titleOnCreate",
               "detail": "detailOnCreate"
           };
           let formData = formBindingData.createFormBindingData(obj);
           return formData;
       }
       onCastToNormal(formId) {
           // Called when the widget host converts the temporary widget into a normal one. The widget provider should do something to respond to the conversion.
           console.log('FormAbility onCastToNormal');
       }
       onUpdate(formId) {
           // To support scheduled update, periodic update, or update requested by the widget host for a widget, override this method for data update.
           console.log('FormAbility onUpdate');
           let obj = {
               "title": "titleOnUpdate",
               "detail": "detailOnUpdate"
           };
           let formData = formBindingData.createFormBindingData(obj);
           formProvider.updateForm(formId, formData).catch((error) => {
               console.log('FormAbility updateForm, error:' + JSON.stringify(error));
           });
       }
       onVisibilityChange(newStatus) {
           // Called when the widget host initiates an event about visibility changes. The widget provider should do something to respond to the notification.
           console.log('FormAbility onVisibilityChange');
       }
       onEvent(formId, message) {
           // If the widget supports event triggering, override this method and implement the trigger.
           console.log('FormAbility onEvent');
       }
       onDestroy(formId) {
           // Delete widget data.
           console.log('FormAbility onDestroy');
       }
       onConfigurationUpdated(config) {
           console.log('FormAbility onConfigurationUpdated, config:' + JSON.stringify(config));
       }
   }
   ```

### Configuring config.json for the Form Ability

Configure the **module.json** file for the **Form** ability.

- The internal field structure of the **extensionAbility** module is described as follows:

  | Field   | Description                                                        | Data Type  | Default          |
  | ----------- | ------------------------------------------------------------ | ---------- | -------------------- |
  | name        | Name of an extension ability.                  | String    | No                  |
  | srcEntrance | JS code path of the extension ability.    | String    | No                  |
  | description | Description of the extension ability. The value can be a string or a resource index to descriptions in multiple languages.| String    | Yes (initial value: left empty)|
  | icon        | Index of the extension ability icon file.                  | String    | Yes (initial value: left empty)|
  | label       | Descriptive information about the extension ability presented externally. The value can be a string or a resource index to the description.| String    | Yes (initial value: left empty)|
  | type        | Type of the extension ability. The value can be **form** or **service**.             | String    | No                  |
  | permissions | Permissions required for abilities of another application to call the current ability.        | String array| Yes (initial value: left empty)|
  | metadata    | Metadata of the extension ability. It describes the configuration information of the extension ability.| Object      | Yes (initial value: left empty)  |

  For a Form Extension ability, set **type** to **form** and **metadata** to the widget details.

  A configuration example is as follows:

     ```json
  "extensionAbilities": [{
      "name": "FormAbility",
      "srcEntrance": "./ets/FormAbility/FormAbility.ts",
      "label": "$string:form_FormAbility_label",
      "description": "$string:form_FormAbility_desc",
      "type": "form",
      "metadata": [{
          "name": "ohos.extension.form",
          "resource": "$profile:form_config"
      }]
  }]
     ```

- Configure the widget profile module. In the metadata of the Form Extension ability, the resource file path specified by **ohos.extension.form** must be used. For example, **$profile:form_config** means that **form_config.json** in the **resources/base/profile/** directory of the development view is used as the widget profile.

  The internal field structure is described as follows:
  
  | Field           | Description                                                        | Data Type  | Default              |
  | ------------------- | ------------------------------------------------------------ | ---------- | ------------------------ |
  | name                | Class name of the widget. The value is a string with a maximum of 127 bytes.                   | String    | No                      |
  | description         | Description of the widget. The value can be a string or a resource index to descriptions in multiple languages. The value is a string with a maximum of 255 bytes.| String    | Yes (initial value: left empty)      |
  | src                 | Full path of the UI code corresponding to the widget.                            | String    | No                      |
  | window              | Window-related configurations.                              | Object      | Yes                  |
  | isDefault           | Whether the widget is a default one. Each ability has only one default widget.<br>**true**: The widget is the default one.<br>**false**: The widget is not the default one.| Boolean    | No                      |
  | colorMode           | Color mode of the widget. Available values are as follows:<br>**auto**: The widget adopts the auto-adaptive color mode.<br>**dark**: The widget adopts the dark color mode.<br>**light**: The widget adopts the light color mode.| String    | Yes (initial value: **auto**)|
  | supportDimensions   | Grid styles supported by the widget. Available values are as follows:<br>1 * 2: indicates a grid with one row and two columns.<br>2 * 2: indicates a grid with two rows and two columns.<br>2 * 4: indicates a grid with two rows and four columns.<br>4 * 4: indicates a grid with four rows and four columns.| String array| No                      |
  | defaultDimension    | Default grid style of the widget. The value must be available in the **supportDimensions** array of the widget.| String    | No                      |
  | updateEnabled       | Whether the widget can be updated periodically. Available values are as follows:<br>**true**: The widget can be updated periodically, depending on the update way you select, either at a specified interval (**updateDuration**) or at the scheduled time (**scheduledUpdateTime**). **updateDuration** is preferentially recommended.<br>**false**: The widget cannot be updated periodically.| Boolean  | No                      |
  | scheduledUpdateTime | Scheduled time to update the widget. The value is in 24-hour format and accurate to minute.        | String    | Yes (initial value: **0:0**) |
  | updateDuration      | Interval to update the widget. The value is a natural number, in the unit of 30 minutes.<br>If the value is **0**, this field does not take effect.<br>If the value is a positive integer ***N***, the interval is calculated by multiplying ***N*** and 30 minutes.| Number      | Yes (initial value: **0**)   |
  | formConfigAbility   | Link to a specific page of the application. The value is a URI.                       | String    | Yes (initial value: left empty)    |
  | formVisibleNotify   | Whether the widget is allowed to use the widget visibility notification.                          | String    | Yes (initial value: left empty)    |
  | metaData            | Metadata of the widget. This field contains the array of the **customizeData** field.           | Object      | Yes (initial value: left empty)    |

     A configuration example is as follows:
  
     ```json
  {
      "forms": [{
          "name": "widget",
          "description": "This is a service widget.",
          "src": "./js/widget/pages/index/index",
          "window": {
              "autoDesignWidth": true,
              "designWidth": 720
          },
          "isDefault": true,
          "colorMode": "auto",
          "supportDimensions": ["2*2"],
          "defaultDimension": "2*2",
          "updateEnabled": true,
          "scheduledUpdateTime": "10:30",
          "updateDuration": 1,
          "formConfigAbility": "ability://ohos.samples.FormApplication.MainAbility"
      }]
  }
     ```


### Widget Data Persistence

Mostly, the widget provider is started only when it needs to obtain information about a widget. The Widget Manager supports multi-instance management and uses the widget ID to identify an instance. If the widget provider supports widget data modification, it must persistently store the data based on the widget ID, so that it can access the data of the target widget when obtaining, updating, or starting a widget.

```javascript
       onCreate(want) {
           console.log('FormAbility onCreate');

           let formId = want.parameters["ohos.extra.param.key.form_identity"];
           let formName = want.parameters["ohos.extra.param.key.form_name"];
           let tempFlag = want.parameters["ohos.extra.param.key.form_temporary"];
           // Persistently store widget information for subsequent use, such as widget instance retrieval and update.
           storeFormInfo(formId, formName, tempFlag, want);

           let obj = {
               "title": "titleOnCreate",
               "detail": "detailOnCreate"
           };
           let formData = formBindingData.createFormBindingData(obj);
           return formData;
       }
```

You should override **onDestroy** to delete widget data.

```javascript
       onDestroy(formId) {
           // Delete widget data.
           deleteFormInfo(formId);
           console.log('FormAbility onDestroy');
       }
```

For details about the persistence method, see [Lightweight Data Store Development](../database/database-preference-guidelines.md).

Note that the **Want** passed by the widget host to the widget provider contains a temporary flag, indicating whether the requested widget is a temporary one.

Normal widget: a widget that will be persistently used by the widget host

Temporary widget: a widget that is temporarily used by the widget host

Data of a temporary widget is not persistently stored. If the widget framework is killed and restarted, data of a temporary widget will be deleted. However, the widget provider is not notified of which widget is deleted, and still keeps the data. Therefore, the widget provider should implement data clearing. In addition, the widget host may convert a temporary widget into a normal one. If the conversion is successful, the widget provider should process the widget ID and store the data persistently. This prevents the widget provider from deleting persistent data when clearing temporary widgets.

### Developing the Widget UI Page
You can use HML, CSS, and JSON to develop the UI page for a JavaScript-programmed widget.

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> Currently, only the JavaScript-based web-like development paradigm can be used to develop the widget UI.

   - hml:
   ```html
   <div class="container">
       <stack>
           <div class="container-img">
               <image src="/common/widget.png" class="bg-img"></image>
           </div>
           <div class="container-inner">
               <text class="title">{{title}}</text>
               <text class="detail_text" onclick="routerEvent">{{detail}}</text>
           </div>
       </stack>
   </div>
   ```

   - css:

   ```css
.container {
    flex-direction: column;
    justify-content: center;
    align-items: center;
}

.bg-img {
    flex-shrink: 0;
    height: 100%;
}

.container-inner {
    flex-direction: column;
    justify-content: flex-end;
    align-items: flex-start;
    height: 100%;
    width: 100%;
    padding: 12px;
}

.title {
    font-size: 19px;
    font-weight: bold;
    color: white;
    text-overflow: ellipsis;
    max-lines: 1;
}

.detail_text {
    font-size: 16px;
    color: white;
    opacity: 0.66;
    text-overflow: ellipsis;
    max-lines: 1;
    margin-top: 6px;
}
   ```

   - json:
   ```json
   {
     "data": {
       "title": "TitleDefault",
       "detail": "TextDefault"
     },
     "actions": {
       "routerEvent": {
         "action": "router",
         "abilityName": "com.example.MyApplication.hmservice.FormAbility",
         "params": {
           "message": "add detail"
         }
       }
     }
   }
   ```

Now you've got a widget shown below.

![fa-form-example](figures/fa-form-example.png)

## Development Example

The following sample is provided to help you better understand how to develop a widget on the stage model:

[FormExtAbility](https://gitee.com/openharmony/app_samples/tree/master/ability/FormExtAbility)

Users can create, update, and delete widgets on the home screen of their devices or by using their own widget host. This sample also implements widget information persistence by using lightweight data storage.