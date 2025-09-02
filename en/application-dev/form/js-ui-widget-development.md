# Developing a JS Widget (Stage Model)
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @cx983299475-->
<!--Designer: @xueyulong-->
<!--Tester: @chenmingze-->
<!--Adviser: @Brilliantry_Rui-->
The stage model is supported since API version 9. It is the mainstream model with a long evolution plan. This model is object-oriented and provides open application components as classes. You can derive application components for capability expansion.

## Available APIs

The **FormExtensionAbility** class has the following APIs. For details, see [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md).

| Name                                                                                             | Description|
| -------- | -------- |
| onAddForm(want:&nbsp;Want):&nbsp;formBindingData.FormBindingData                                 | Called to notify the widget provider that a widget is being created.|
| onCastToNormalForm(formId:&nbsp;string):&nbsp;void                                               | Called to notify the widget provider that a temporary widget is being converted to a normal one.|
| onUpdateForm(formId:&nbsp;string):&nbsp;void                                                     | Called to notify the widget provider that a widget is being updated.|
| onChangeFormVisibility(newStatus:&nbsp;Record&lt;string,&nbsp;number&gt;):&nbsp;void             | Called to notify the widget provider that the widget visibility status is being changed.|
| onFormEvent(formId:&nbsp;string,&nbsp;message:&nbsp;string):&nbsp;void                           | Called to instruct the widget provider to process a widget event.|
| onRemoveForm(formId:&nbsp;string):&nbsp;void                                                     | Called to notify the widget provider that a widget is being destroyed.|
| onConfigurationUpdate(newConfig:&nbsp;Configuration):&nbsp;void                                  | Called when the configuration of the environment where the widget is running is being updated.|

The following table lists some APIs provided by the **formProvider** class. For details about the APIs, see [API Reference](../reference/apis-form-kit/js-apis-app-form-formProvider.md).

| Name| Description|
| -------- | -------- |
| setFormNextRefreshTime(formId:&nbsp;string,&nbsp;minute:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Sets the next refresh time for a widget. This API uses an asynchronous callback to return the result.|
| setFormNextRefreshTime(formId:&nbsp;string,&nbsp;minute:&nbsp;number):&nbsp;Promise&lt;void&gt; | Sets the next refresh time for a widget. This API uses a promise to return the result.|
| updateForm(formId:&nbsp;string,&nbsp;formBindingData:&nbsp;formBindingData.FormBindingData,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Updates a widget. This API uses an asynchronous callback to return the result.|
| updateForm(formId:&nbsp;string,&nbsp;formBindingData:&nbsp;formBindingData.FormBindingData):&nbsp;Promise&lt;void&gt; | Updates a widget. This API uses a promise to return the result.|

The **FormBindingData** class has the following APIs. For details, see [FormBindingData](../reference/apis-form-kit/js-apis-app-form-formBindingData.md).

| Name| Description|
| -------- | -------- |
| createFormBindingData(obj?:&nbsp;Object&nbsp;\|&nbsp;string):&nbsp;FormBindingData | Creates a **FormBindingData** object.|


## How to Develop

The widget provider development based on the [stage model](../application-models/stage-model-development-overview.md) involves the following key steps:

- [Creating a FormExtensionAbility Instance](#creating-a-formextensionability-instance): Develop the lifecycle callback functions of FormExtensionAbility.

- [Configuring the Widget Configuration Files](#configuring-the-widget-configuration-files): Configure the application configuration file **module.json5** and profile configuration file.

- [Persistently Storing Widget Data](#persistently-storing-widget-data): Manage widget data persistence.

- [Updating Widget Data](#updating-widget-data): Call **updateForm()** to update the information displayed in a widget.

- [Developing the Widget UI Page](#developing-the-widget-ui-page): Use HML+CSS+JSON to develop a JS widget UI page.

- [Developing Widget Events](#developing-widget-events): Add the router and message events for a widget.


### Creating a FormExtensionAbility Instance

To create a widget in the stage model, you need to implement the lifecycle callbacks of FormExtensionAbility. For details about how to generate a service widget template, see <!--RP1-->[Developing a Service Widget](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/ide-service-widget-V5)<!--RP1End-->.

1. Import related modules to **EntryFormAbility.ets**.
    ```ts
    import { Want } from '@kit.AbilityKit';
    import { formBindingData, FormExtensionAbility, formInfo, formProvider } from '@kit.FormKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    const TAG: string = 'JsCardFormAbility';
    const DOMAIN_NUMBER: number = 0xFF00;
    ```

2. Implement the FormExtension lifecycle callbacks in **EntryFormAbility.ets**.

    ```ts
    export default class EntryFormAbility extends FormExtensionAbility {
      onAddForm(want: Want): formBindingData.FormBindingData {
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onAddForm');
        // Called when the widget is created. The widget provider should return the widget data binding class.
        let obj: Record<string, string> = {
          'title': 'titleOnCreate',
          'detail': 'detailOnCreate'
        };
        let formData: formBindingData.FormBindingData = formBindingData.createFormBindingData(obj);
        return formData;
      }
      onCastToNormalForm(formId: string): void {
        // Called when a temporary widget is being converted into a normal one. The widget provider should respond to the conversion.
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onCastToNormalForm');
      }
      onUpdateForm(formId: string): void {
        // Override this method to support scheduled updates, periodic updates, or updates requested by the widget host.
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onUpdateForm');
        let obj: Record<string, string> = {
          'title': 'titleOnUpdate',
          'detail': 'detailOnUpdate'
        };
        let formData: formBindingData.FormBindingData = formBindingData.createFormBindingData(obj);
        formProvider.updateForm(formId, formData).catch((error: BusinessError) => {
          hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] updateForm, error:' + JSON.stringify(error));
        });
      }
      onChangeFormVisibility(newStatus: Record<string, number>): void {
        // Called when the widget host initiates an event about visibility changes. The widget provider should do something to respond to the notification. This callback takes effect only for system applications.
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onChangeFormVisibility');
        //...
      }
      onFormEvent(formId: string, message: string): void {
        // If the widget supports event triggering, override this method and implement the trigger.
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onFormEvent');
      }
      onRemoveForm(formId: string): void {
        // Delete widget data.
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onRemoveForm');
        //...
      }
      onAcquireFormState(want: Want): formInfo.FormState {
        return formInfo.FormState.READY;
      }
    }
    ```

> **NOTE**
>
> FormExtensionAbility cannot reside in the background. Therefore, continuous tasks cannot be processed in the widget lifecycle callbacks.


### Configuring the Widget Configuration Files

1. Configure ExtensionAbility information under **extensionAbilities** in the [module.json5 file](../quick-start/module-configuration-file.md). For a FormExtensionAbility, you must specify **metadata**. Specifically, set **name** to **ohos.extension.form** (fixed), and set **resource** to the index of the widget configuration information.
   Example configuration:

   
   ```json
   {
     "module": {
       // ...
       "extensionAbilities": [
         {
           "name": "JsCardFormAbility",
           "srcEntry": "./ets/jscardformability/JsCardFormAbility.ts",
           "description": "$string:JSCardFormAbility_desc",
           "label": "$string:JSCardFormAbility_label",
           "type": "form",
           "metadata": [
             {
               "name": "ohos.extension.form",
               "resource": "$profile:form_jscard_config"
             }
           ]
         }
       ]
     }
   }
   ```

2. Configure the widget configuration information. In the **metadata** configuration item of FormExtensionAbility, you can specify the resource index of specific configuration information of the widget. For example, if **resource** is set to **$profile:form_config**, **form_config.json** in the **resources/base/profile/** directory of the development view is used as the profile configuration file of the widget. The following table describes the internal structure of the profile configuration file.

   **Table 1** Widget profile configuration file

   | Field| Description| Data Type| Default Value Allowed|
   | -------- | -------- | -------- | -------- |
   | name | Class name of the widget. The value is a string with a maximum of 127 bytes.| String| No|
   | description | Description of the widget. The value can be a string or a resource index to descriptions in multiple languages. The value is a string with a maximum of 255 bytes.| String| Yes (initial value: left empty)|
   | src | Full path of the UI code corresponding to the widget.| String| No|
   | window | Window-related configurations.| Object| Yes|
   | isDefault | Whether the widget is a default one. Each UIAbility has only one default widget.<br>- **true**: The widget is the default one.<br>- **false**: The widget is not the default one.| Boolean| No|
   | colorMode | Color mode of the widget.<br>- **auto**: auto-adaptive color mode<br>- **dark**: dark color mode<br>- **light**: light color mode| String| Yes (initial value: **auto**)|
   | supportDimensions | Grid styles supported by the widget.<br>- **1 * 2**: indicates a grid with one row and two columns.<br>- **2 * 2**: indicates a grid with two rows and two columns.<br>- **2 * 4**: indicates a grid with two rows and four columns.<br>- **4 * 4**: indicates a grid with four rows and four columns.| String array| No|
   | defaultDimension | Default grid style of the widget. The value must be available in the **supportDimensions** array of the widget.| String| No|
   | updateEnabled | Whether the widget can be updated periodically.<br>- **true**: The widget can be updated at a specified interval (**updateDuration**) or at the scheduled time (**scheduledUpdateTime**). **updateDuration** takes precedence over **scheduledUpdateTime**.<br>- **false**: The widget cannot be updated periodically.| Boolean| No|
   | scheduledUpdateTime | Scheduled time to update the widget. The value is in 24-hour format and accurate to minute.<br>**updateDuration** takes precedence over **scheduledUpdateTime**. If both are specified, the value specified by **updateDuration** is used.| String| Yes (initial value: **0:0**)|
   | updateDuration | Interval to update the widget. The value is a natural number, in the unit of 30 minutes.<br>If the value is **0**, this field does not take effect.<br>If the value is a positive integer *N*, the interval is calculated by multiplying *N* and 30 minutes.<br>**updateDuration** takes precedence over **scheduledUpdateTime**. If both are specified, the value specified by **updateDuration** is used.| Number| Yes (initial value: **0**)|
   | formConfigAbility | Link to a specific page of the application. The value is a URI.| String| Yes (initial value: left empty)|
   | formVisibleNotify | Whether the widget is allowed to use the widget visibility notification.| String| Yes (initial value: left empty)|
   | metaData | Metadata of the widget. This field contains the array of the **customizeData** field.| Object| Yes (initial value: left empty)|

   Example configuration:

   
   ```json
   {
     "forms": [
       {
         "name": "WidgetJS",
         "description": "$string:JSCardEntryAbility_desc",
         "src": "./js/WidgetJS/pages/index/index",
         "window": {
           "designWidth": 720,
           "autoDesignWidth": true
         },
         "colorMode": "auto",
         "isDefault": true,
         "updateEnabled": true,
         "scheduledUpdateTime": "10:30",
         "updateDuration": 1,
         "defaultDimension": "2*2",
         "supportDimensions": [
           "2*2"
         ]
       }
     ]
   }
   ```


### Persistently Storing Widget Data

A widget provider is usually started when it is needed to provide information about a widget. The Widget Manager supports multi-instance management and uses the widget ID to identify an instance. If the widget provider supports widget data modification, it must persistently store the data based on the widget ID, so that it can access the data of the target widget when obtaining, updating, or starting a widget.


```ts
import { common, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { formBindingData, FormExtensionAbility } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { preferences } from '@kit.ArkData';

const TAG: string = 'JsCardFormAbility';
const DATA_STORAGE_PATH: string = '/data/storage/el2/base/haps/form_store';
const DOMAIN_NUMBER: number = 0xFF00;

let storeFormInfo = async (formId: string, formName: string, tempFlag: boolean, context: common.FormExtensionContext): Promise<void> => {
  // Only the widget ID (formId), widget name (formName), and whether the widget is a temporary one (tempFlag) are persistently stored.
  let formInfo: Record<string, string | boolean | number> = {
    'formName': formName,
    'tempFlag': tempFlag,
    'updateCount': 0
  };
  try {
    const storage: preferences.Preferences = await preferences.getPreferences(context, DATA_STORAGE_PATH);
    // put form info
    await storage.put(formId, JSON.stringify(formInfo));
    hilog.info(DOMAIN_NUMBER, TAG, `[EntryFormAbility] storeFormInfo, put form info successfully, formId: ${formId}`);
    await storage.flush();
  } catch (err) {
    hilog.error(DOMAIN_NUMBER, TAG, `[EntryFormAbility] failed to storeFormInfo, err: ${JSON.stringify(err as BusinessError)}`);
  }
}

export default class JsCardFormAbility extends FormExtensionAbility {
  onAddForm(want: Want): formBindingData.FormBindingData {
    hilog.info(DOMAIN_NUMBER, TAG, '[JsCardFormAbility] onAddForm');

    if (want.parameters) {
      let formId = JSON.stringify(want.parameters['ohos.extra.param.key.form_identity']);
      let formName = JSON.stringify(want.parameters['ohos.extra.param.key.form_name']);
      let tempFlag = want.parameters['ohos.extra.param.key.form_temporary'] as boolean;
      // Persistently store widget data for subsequent use, such as instance acquisition and update.
      // Implement this API based on project requirements.
      storeFormInfo(formId, formName, tempFlag, this.context);
    }

    let obj: Record<string, string> = {
      'title': 'titleOnCreate',
      'detail': 'detailOnCreate'
    };
    let formData: formBindingData.FormBindingData = formBindingData.createFormBindingData(obj);
    return formData;
  }
}
```

You should override **onRemoveForm** to implement widget data deletion.


```ts
import { common } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { FormExtensionAbility } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { preferences } from '@kit.ArkData';

const TAG: string = 'JsCardFormAbility';
const DATA_STORAGE_PATH: string = '/data/storage/el2/base/haps/form_store';
const DOMAIN_NUMBER: number = 0xFF00;

let deleteFormInfo = async (formId: string, context: common.FormExtensionContext): Promise<void> => {
  try {
    const storage: preferences.Preferences = await preferences.getPreferences(context, DATA_STORAGE_PATH);
    // Delete the widget information.
    await storage.delete(formId);
    hilog.info(DOMAIN_NUMBER, TAG, `[EntryFormAbility] deleteFormInfo, del form info successfully, formId: ${formId}`);
    await storage.flush();
  } catch (err) {
    hilog.error(DOMAIN_NUMBER, TAG, `[EntryFormAbility] failed to deleteFormInfo, err: ${JSON.stringify(err as BusinessError)}`);
  };
};

export default class JsCardFormAbility extends FormExtensionAbility {
  onRemoveForm(formId: string): void {
    // Delete widget data.
    hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onRemoveForm');
    // Delete the persistent widget instance data.
    // Implement this API based on project requirements.
    deleteFormInfo(formId, this.context);
  }
}
```

For details about how to implement persistent data storage, see [Application Data Persistence](../database/app-data-persistence-overview.md).

The **Want** object passed in by the widget host to the widget provider contains a flag that specifies whether the requested widget is normal or temporary.

- Normal widget: a widget persistently used by the widget host

- Temporary widget: a widget temporarily used by the widget host

Data of a temporary widget will be deleted on the Widget Manager if the widget framework is killed and restarted. The widget provider, however, is not notified of the deletion and still keeps the data. Therefore, the widget provider needs to clear the data of temporary widgets proactively if the data has been kept for a long period of time. If the widget host has converted a temporary widget into a normal one, the widget provider should change the widget data from temporary storage to persistent storage. Otherwise, the widget data may be deleted by mistake.


### Updating Widget Data

When an application initiates a scheduled or periodic update, the application obtains the latest data and calls **updateForm()** to update the widget.


```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = 'JsCardFormAbility';
const DOMAIN_NUMBER: number = 0xFF00;

export default class EntryFormAbility extends FormExtensionAbility {
  onUpdateForm(formId: string): void {
    // Override this method to support scheduled updates, periodic updates, or updates requested by the widget host.
    hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onUpdateForm');
    let obj: Record<string, string> = {
      'title': 'titleOnUpdate',
      'detail': 'detailOnUpdate'
    };
    let formData: formBindingData.FormBindingData = formBindingData.createFormBindingData(obj);
    formProvider.updateForm(formId, formData).catch((error: BusinessError) => {
      hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] updateForm, error:' + JSON.stringify(error));
    });
  }
}
```


### Developing the Widget UI Page

You can use the web-like paradigm (HML+CSS+JSON) to develop JS widget pages. This section describes how to develop a page shown below.

![WidgetCardPage](figures/WidgetCardPage.png)

- HML: uses web-like paradigm components to describe the widget page information.

  
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

- CSS: defines style information about the web-like paradigm components in HML.


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

- JSON: defines data and event interaction on the widget UI page.

  
  ```json
  {
    "data": {
      "title": "TitleDefault",
      "detail": "TextDefault"
    },
    "actions": {
      "routerEvent": {
        "action": "router",
        "abilityName": "EntryAbility",
        "params": {
          "message": "add detail"
        }
      }
    }
  }
  ```


### Developing Widget Events

You can set router and message events for components on a widget. The router event applies to UIAbility redirection, and the message event applies to custom click events.

The key steps are as follows:

1. Set the **onclick** field in the HML file to **routerEvent** or **messageEvent**, depending on the **actions** settings in the JSON file.

2. Set the router event.

   - **action**: **"router"**, which indicates a router event.
   - **abilityName**: name of the UIAbility to redirect to (PageAbility component in the FA model and UIAbility component in the stage model). For example, the default UIAbility name of the stage model created by DevEco Studio is EntryAbility.
   - **params**: custom parameters passed to the target UIAbility. Set them as required. The value can be obtained from **parameters** in **want** used for starting the target UIAbility. For example, in the lifecycle function **onCreate** of the MainAbility in the stage model, you can obtain **want** and its **parameters** field.

3. Set the message event.

   - **action**: **"message"**, which indicates a message event.
   - **params**: custom parameters of the message event. Set them as required. The value can be obtained from **message** in the widget lifecycle function **onFormEvent()**.

The following are examples:

- HML file:


  ```html
  <div class="container">
      <stack>
          <div class="container-img">
              <image src="/common/CardWebImg.png" class="bg-img"></image>
              <image src="/common/CardWebImgMatrix.png"
                     class="bottom-img"/>
          </div>
          <div class="container-inner">
              <text class="title" onclick="routerEvent">{{ title }}</text>
              <text class="detail_text" onclick="messageEvent">{{ detail }}</text>
          </div>
      </stack>
  </div>
  ```

- CSS file:


  ```css
  .container {
      flex-direction: column;
      justify-content: center;
      align-items: center;
  }

  .bg-img {
      flex-shrink: 0;
      height: 100%;
      z-index: 1;
  }

  .bottom-img {
      position: absolute;
      width: 150px;
      height: 56px;
      top: 63%;
      background-color: rgba(216, 216, 216, 0.15);
      filter: blur(20px);
      z-index: 2;
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
      font-family: HarmonyHeiTi-Medium;
      font-size: 14px;
      color: rgba(255, 255, 255, 0.90);
      letter-spacing: 0.6px;
      font-weight: 500;
      width: 100%;
      text-overflow: ellipsis;
      max-lines: 1;
  }

  .detail_text {
      ffont-family: HarmonyHeiTi;
      font-size: 12px;
      color: rgba(255, 255, 255, 0.60);
      letter-spacing: 0.51px;
      font-weight: 400;
      text-overflow: ellipsis;
      max-lines: 1;
      margin-top: 6px;
      width: 100%;
  }
  ```

- JSON file:

  
  ```json
  {
    "data": {
      "title": "TitleDefault",
      "detail": "TextDefault"
    },
    "actions": {
      "routerEvent": {
        "action": "router",
        "abilityName": "JSCardEntryAbility",
        "params": {
          "info": "router info",
          "message": "router message"
        }
      },
      "messageEvent": {
        "action": "message",
        "params": {
          "detail": "message detail"
        }
      }
    }
  }
  ```

  > **NOTE**
  >
  > **JSON Value** in **data** supports multi-level nested data. When updating data, ensure that complete data is carried.

  Assume that a widget is displaying the course information of Mr. Zhang on July 18, as shown in the following code snippet.
  ```ts
  "data": {
      "Day": "07.18",
      "teacher": {
          "name": "Mr.Zhang",
          "course": "Math"
      }
  }
  ```
  To update the widget content to the course information of Mr. Li on July 18, you must pass the complete data as follows, instead of only a single date item such as **name** or **course**:
  ```ts
  "teacher": {
      "name": "Mr.Li",
      "course": "English"
  }
  ```


- Receive the router event in UIAbility and obtain parameters.


  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';
  import Want from '@ohos.app.ability.Want';
  import hilog from '@ohos.hilog';

  const TAG: string = 'EtsCardEntryAbility';
  const DOMAIN_NUMBER: number = 0xFF00;

  export default class EtsCardEntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      if (want.parameters) {
        let params: Record<string, Object> = JSON.parse(JSON.stringify(want.parameters.params));
        // Obtain the info parameter passed in the router event.
        if (params.info === 'router info') {
          // Execute the service logic.
          hilog.info(DOMAIN_NUMBER, TAG, `router info: ${params.info}`);
        }
        // Obtain the message parameter passed in the router event.
        if (params.message === 'router message') {
          // Execute the service logic.
          hilog.info(DOMAIN_NUMBER, TAG, `router message: ${params.message}`);
        }
      }
    }
  };
  ```

- Receive the message event in FormExtensionAbility and obtain parameters.

  
  ```ts
  import FormExtension from '@ohos.app.form.FormExtensionAbility';
  import hilog from '@ohos.hilog';

  const TAG: string = 'FormAbility';
  const DOMAIN_NUMBER: number = 0xFF00;

  export default class FormAbility extends FormExtension {
    onFormEvent(formId: string, message: string): void {
      // If the widget supports event triggering, override this method and implement the trigger.
      hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onFormEvent');
      // Obtain the detail parameter passed in the message event.
      let msg: Record<string, string> = JSON.parse(message);
      if (msg.detail === 'message detail') {
        // Execute the service logic.
        hilog.info(DOMAIN_NUMBER, TAG, 'message info:' + msg.detail);
      }
    }
  };
  ```
