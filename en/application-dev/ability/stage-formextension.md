# Stage Widget Development

## Widget Overview

A widget is a set of UI components used to display important information or operations for an application. It provides users with direct access to a desired application service, without requiring them to open the application.

A widget displays brief information about an application on the UI of another application (host application, currently system applications only) and provides basic interactive functions such as opening a UI page or sending a message. 

Basic concepts:

- Widget provider: an atomic service that controls what and how content is displayed in a widget and interacts with users.
- Widget host: an application that displays the widget content and controls the position where the widget is displayed in the host application.
- Widget Manager: a resident agent that manages widgets added to the system and provides functions such as periodic widget update.

> **NOTE**
>
> The widget host and provider do not keep running all the time. The Widget Manager starts the widget provider to obtain widget information when a widget is added, deleted, or updated.

You only need to develop widget content as the widget provider. The system automatically handles the work done by the widget host and Widget Manager.

The widget provider controls the widget content to display, component layout, and click events bound to components.

## When to Use

Stage widget development refers to the development conducted by the widget provider based on the [stage model](stage-brief.md). As a widget provider, you need to carry out the following operations:

- Develop the lifecycle callbacks in **FormExtension**.
- Create a **FormBindingData** instance.
- Update a widget through **FormProvider**.
- Develop the widget UI page.

## Available APIs

The **FormExtension** class has the following APIs. For details, see [FormExtension](../reference/apis/js-apis-formextension.md).

**Table 1** FormExtension APIs

| API                                                      | Description                                        |
| :----------------------------------------------------------- | :------------------------------------------- |
| onCreate(want: Want): formBindingData.FormBindingData        | Called to notify the widget provider that a **Form** instance (widget) has been created.          |
| onCastToNormal(formId: string): void                         | Called to notify the widget provider that a temporary widget has been converted to a normal one.|
| onUpdate(formId: string): void                               | Called to notify the widget provider that a widget has been updated.          |
| onVisibilityChange(newStatus: { [key: string]: number }): void | Called to notify the widget provider of the change in widget visibility.        |
| onEvent(formId: string, message: string): void               | Called to instruct the widget provider to receive and process a widget event.      |
| onDestroy(formId: string): void                              | Called to notify the widget provider that a **Form** instance (widget) has been destroyed.          |
| onConfigurationUpdated(config: Configuration): void;         | Called when the configuration of the environment where the widget is running is updated.                      |

The **FormExtension** class also has a member context, that is, the **FormExtensionContext** class. For details, see [FormExtensionContext](../reference/apis/js-apis-formextensioncontext.md).

**Table 2** FormExtensionContext APIs

| API                                                      | Description                                                        |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| updateForm(formId: string, formBindingData: formBindingData.FormBindingData, callback: AsyncCallback\<void>): void | Updates a widget. This API uses an asynchronous callback to return the result.|
| updateForm(formId: string, formBindingData: formBindingData.FormBindingData): Promise\<void>                | Updates a widget. This API uses a promise to return the result.|

For details about the **FormProvider** APIs, see [FormProvider](../reference/apis/js-apis-formprovider.md).

**Table 3** FormProvider APIs

| API                                                      | Description                                             |
| :----------------------------------------------------------- | :------------------------------------------------ |
| setFormNextRefreshTime(formId: string, minute: number, callback: AsyncCallback&lt;void&gt;): void; | Sets the next refresh time for a widget. This API uses an asynchronous callback to return the result.                   |
| setFormNextRefreshTime(formId: string, minute: number): Promise&lt;void&gt;; | Sets the next refresh time for a widget. This API uses a promise to return the result.|
| updateForm(formId: string, formBindingData: FormBindingData, callback: AsyncCallback&lt;void&gt;): void; | Updates a widget. This API uses an asynchronous callback to return the result.                                 |
| updateForm(formId: string, formBindingData: FormBindingData): Promise&lt;void&gt;; | Updates a widget. This API uses a promise to return the result.              |

## How to Develop

### Creating a FormExtension Instance

To create a widget in the stage model, implement the lifecycle callbacks of **FormExtension**. The sample code is as follows:

1. Import the required modules.

   ```javascript
   import FormExtension from '@ohos.application.FormExtension'
   import formBindingData from '@ohos.application.formBindingData'
   import formInfo from '@ohos.application.formInfo'
   import formProvider from '@ohos.application.formProvider'
   ```

2. Implement the lifecycle callbacks of **FormExtension**.

   ```javascript
   export default class FormAbility extends FormExtension {
       onCreate(want) {
           console.log('FormAbility onCreate');
           // Persistently store widget information for subsequent use, such as widget instance retrieval or update.
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
           // To support scheduled update, periodic update, or update requested by the widget host, override this method for widget data update.
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

### Configuring the Widget Configuration File

- Configure Extension ability information under **extensionAbilities** in the **module.json5** file. The internal field structure is described as follows:

  | Field   | Description                                                        | Data Type  | Default          |
  | ----------- | ------------------------------------------------------------ | ---------- | -------------------- |
  | name        | Name of the Extension ability. This field must be specified.                | String    | No                  |
  | srcEntrance | Path of the Extension ability lifecycle code. This field must be specified.| String    | No                  |
  | description | Description of the Extension ability. The value can be a string or a resource index to descriptions in multiple languages.| String    | Yes (initial value: left empty)|
  | icon        | Index of the Extension ability icon file.                  | String    | Yes (initial value: left empty)|
  | label       | Descriptive information about the Extension ability presented externally. The value can be a string or a resource index to the description.| String    | Yes (initial value: left empty)|
  | type        | Type of the Extension ability. In the current development scenario, set this field to **form**.| String    | No                  |
  | permissions | Permissions required for abilities of another application to call the current ability.        | String array| Yes (initial value: left empty)|
  | metadata    | Metadata (configuration information) of the Extension ability.| Object      | Yes (initial value: left empty)  |

  For a Form Extension ability, you must specify **metadata**. Specifically, set **name** to **ohos.extension.form** (fixed), and set **resource** to the index of the widget configuration information.

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

- Configure the widget configuration information. **resource** in **metadata** specifies the index of the widget configuration information. For example, **$profile:form_config** means that **form_config.json** in the **resources/base/profile/** directory of the development view is used as the widget profile configuration file.

  The internal field structure is described as follows:
  
  | Field           | Description                                                        | Data Type  | Default              |
  | ------------------- | ------------------------------------------------------------ | ---------- | ------------------------ |
  | name                | Class name of a widget. The value is a string with a maximum of 127 bytes.                   | String    | No                      |
  | description         | Description of the widget. The value can be a string or a resource index to descriptions in multiple languages. The value is a string with a maximum of 255 bytes.| String    | Yes (initial value: left empty)      |
  | src                 | Full path of the UI code corresponding to the widget.                            | String    | No                      |
  | window              | Window-related configurations.                              | Object      | Yes                  |
  | isDefault           | Whether the widget is a default one. Each ability has only one default widget.<br>**true**: The widget is the default one.<br>**false**: The widget is not the default one.| Boolean    | No                      |
  | colorMode           | Color mode of the widget. Available values are as follows:<br>**auto**: The widget adopts the auto-adaptive color mode.<br>**dark**: The widget adopts the dark color mode.<br>**light**: The widget adopts the light color mode.| String    | Yes (initial value: **auto**)|
  | supportDimensions   | Grid styles supported by the widget. Available values are as follows:<br>**1 * 2**: indicates a grid with one row and two columns.<br>**2 * 2**: indicates a grid with two rows and two columns.<br>**2 * 4**: indicates a grid with two rows and four columns.<br>**4 * 4**: indicates a grid with four rows and four columns.| String array| No                      |
  | defaultDimension    | Default grid style of the widget. The value must be available in the **supportDimensions** array of the widget.| String    | No                      |
  | updateEnabled       | Whether the widget can be updated periodically. Available values are as follows:<br>**true**: The widget can be updated periodically, depending on the update way you select, either at a specified interval (**updateDuration**) or at the scheduled time (**scheduledUpdateTime**). **updateDuration** is recommended.<br>**false**: The widget cannot be updated periodically.| Boolean  | No                      |
  | scheduledUpdateTime | Scheduled time to update the widget. The value is in 24-hour format and accurate to minute.<br>This parameter has a lower priority than **updateDuration**. If both are specified, the value specified by **updateDuration** is used.| String    | Yes (initial value: **0:0**) |
  | updateDuration      | Interval to update the widget. The value is a natural number, in the unit of 30 minutes.<br>If the value is **0**, this field does not take effect.<br>If the value is a positive integer ***N***, the interval is calculated by multiplying ***N*** and 30 minutes.<br>This parameter has a higher priority than **scheduledUpdateTime**. If both are specified, the value specified by **updateDuration** is used.| Number      | Yes (initial value: **0**)   |
  | formConfigAbility   | Link to a specific page of the application. The value is a URI.                       | String    | Yes (initial value: left empty)    |
  | formVisibleNotify   | Whether the widget is allowed to use the widget visibility notification.                        | String    | Yes (initial value: left empty)    |
  | metaData            | Metadata of the widget. This field contains the array of the **customizeData** field.           | Object      | Yes (initial value: left empty)    |

     A configuration example is as follows:
  
     ```json
  {
      "forms": [{
          "name": "widget",
          "description": "This is a widget.",
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
          "formConfigAbility": "ability://ohos.samples.FormApplication.MainAbility"
      }]
  }
     ```


### Persistently Storing Widget Data

Mostly, the widget provider is started only when it needs to obtain information about a widget. The Widget Manager supports multi-instance management and uses the widget ID to identify an instance. If the widget provider supports widget data modification, it must persistently store the data based on the widget ID, so that it can access the data of the target widget when obtaining, updating, or starting the widget.

```javascript
       onCreate(want) {
           console.log('FormAbility onCreate');

           let formId = want.parameters["ohos.extra.param.key.form_identity"];
           let formName = want.parameters["ohos.extra.param.key.form_name"];
           let tempFlag = want.parameters["ohos.extra.param.key.form_temporary"];
           // Persistently store widget data for subsequent use, such as widget instance retrieval or update.
           // The storeFormInfo API is not implemented here.
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
           console.log('FormAbility onDestroy');

           // You need to implement the code for deleting the persistent widget data.
           // The deleteFormInfo API is not implemented here.
           deleteFormInfo(formId);
       }
```

For details about the persistence method, see [Lightweight Data Store Development](../database/database-storage-guidelines.md).

Note that the **Want** passed by the widget host to the widget provider contains a temporary flag, indicating whether the requested widget is a temporary one.

- Normal widget: a widget that will be persistently used by the widget host

- Temporary widget: a widget that is temporarily used by the widget host

Data of a temporary widget is not persistently stored. If it is deleted from the Widget Manager due to exceptions, such as crash of the widget framework, the widget provider will not be notified of which widget is deleted, and still keeps the data. In light of this, the widget provider should implement data clearing. If the widget host successfully converts a temporary widget into a normal one, the widget provider should also process the widget ID and store the data persistently. This prevents the widget provider from deleting the widget data when clearing temporary widgets.

### Updating Widget Data

When a widget application initiates a data update upon a scheduled or periodic update, the application obtains the latest data and calls **updateForm** to update the widget. The sample code is as follows:

```javascript
onUpdate(formId) {
    // To support scheduled update, periodic update, or update requested by the widget host, override this method for widget data update.
    console.log('FormAbility onUpdate');
    let obj = {
        "title": "titleOnUpdate",
        "detail": "detailOnUpdate"
    };
    let formData = formBindingData.createFormBindingData(obj);
    // Call the updateForm method to update the widget. Only the data passed through the input parameter is updated. Other information remains unchanged.
    formProvider.updateForm(formId, formData).catch((error) => {
        console.log('FormAbility updateForm, error:' + JSON.stringify(error));
    });
}
```

### Developing the Widget UI Page

You can use HML, CSS, and JSON to develop the UI page for a JavaScript-programmed widget.

> **NOTE**
>
> Currently, only the JavaScript-based web-like development paradigm can be used to develop the widget UI.

   - In the HML file:
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

   - In the CSS file:

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

   - In the JSON file:
   ```json
   {
     "data": {
       "title": "TitleDefault",
       "detail": "TextDefault"
     },
     "actions": {
       "routerEvent": {
         "action": "router",
         "abilityName": "MainAbility",
         "params": {
           "message": "add detail"
         }
       }
     }
   }
   ```

Now you've got a widget shown below.

![fa-form-example](figures/fa-form-example.png)

### Developing Widget Events

You can set router and message events for components on a widget. The router event applies to ability redirection, and the message event applies to custom click events. The key steps are as follows:

1. Set **onclick** in the HML file to **routerEvent** or **messageEvent**, depending on the **actions** settings in the JSON file.
2. For the router event, set the following attributes:
   - **action**: **"router"**.
   - **abilityName**: target ability name, for example, **MainAbility**, which is the default main ability name in DevEco Studio for the stage model.
   - **params**: custom parameters of the target ability. Set them as required. The value can be obtained from **parameters** in **want** used for starting the target ability. For example, in the lifecycle function **onCreate** of the main ability in the stage model, you can obtain **want** and its **parameters** field.
3. For the message event, set the following attributes:
   - **action**: **"message"**.
   - **params**: custom parameters of the message event. Set them as required. The value can be obtained from **message** in the widget lifecycle function **onEvent**.

The following is an example:

   - In the HML file:
   ```html
   <div class="container">
       <stack>
           <div class="container-img">
               <image src="/common/widget.png" class="bg-img"></image>
           </div>
           <div class="container-inner">
               <text class="title" onclick="routerEvent">{{title}}</text>
               <text class="detail_text" onclick="messageEvent">{{detail}}</text>
           </div>
       </stack>
   </div>
   ```

   - In the JSON file:
   ```json
   {
     "data": {
       "title": "TitleDefault",
       "detail": "TextDefault"
     },
     "actions": {
       "routerEvent": {
         "action": "router",
         "abilityName": "MainAbility",
         "params": {
           "message": "add detail"
         }
       },
       "messageEvent": {
         "action": "message",
         "params": {
           "message": "add detail"
         }
       }
     }
   }
   ```