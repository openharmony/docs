# JS卡片开发指导（Stage模型）
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @cx983299475-->
<!--Designer: @xueyulong-->
<!--Tester: @chenmingze-->
<!--Adviser: @Brilliantry_Rui-->
Stage模型是从API 9开始支持，目前主推且会长期演进的模型。该模型采用面向对象的方式，将应用组件以类接口的形式开放给开发者，可以进行派生，利于扩展能力。

## 接口说明

FormExtensionAbility类拥有如下API接口，具体的API介绍详见[接口文档](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)。

| 接口名                                                                                              | 描述 |
| -------- | -------- |
| onAddForm(want:&nbsp;Want):&nbsp;formBindingData.FormBindingData                                 | 卡片提供方接收创建卡片的通知接口。 |
| onCastToNormalForm(formId:&nbsp;string):&nbsp;void                                               | 卡片提供方接收临时卡片转常态卡片的通知接口。 |
| onUpdateForm(formId:&nbsp;string):&nbsp;void                                                     | 卡片提供方接收更新卡片的通知接口。 |
| onChangeFormVisibility(newStatus:&nbsp;Record&lt;string,&nbsp;number&gt;):&nbsp;void             | 卡片提供方接收修改可见性的通知接口。 |
| onFormEvent(formId:&nbsp;string,&nbsp;message:&nbsp;string):&nbsp;void                           | 卡片提供方接收处理卡片事件的通知接口。 |
| onRemoveForm(formId:&nbsp;string):&nbsp;void                                                     | 卡片提供方接收销毁卡片的通知接口。 |
| onConfigurationUpdate(newConfig:&nbsp;Configuration):&nbsp;void                                  | 当系统配置更新时调用。 |

formProvider类部分API接口如下，具体的API介绍详见[接口文档](../reference/apis-form-kit/js-apis-app-form-formProvider.md)。

| 接口名 | 描述 |
| -------- | -------- |
| setFormNextRefreshTime(formId:&nbsp;string,&nbsp;minute:&nbsp;number,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 设置指定卡片的下一次更新时间。 |
| setFormNextRefreshTime(formId:&nbsp;string,&nbsp;minute:&nbsp;number):&nbsp;Promise&lt;void&gt; | 设置指定卡片的下一次更新时间，以promise方式返回。 |
| updateForm(formId:&nbsp;string,&nbsp;formBindingData:&nbsp;formBindingData.FormBindingData,&nbsp;callback:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 更新指定的卡片。 |
| updateForm(formId:&nbsp;string,&nbsp;formBindingData:&nbsp;formBindingData.FormBindingData):&nbsp;Promise&lt;void&gt; | 更新指定的卡片，以promise方式返回。 |

formBindingData类部分API接口如下，具体的API介绍详见[接口文档](../reference/apis-form-kit/js-apis-app-form-formBindingData.md)。

| 接口名 | 描述 |
| -------- | -------- |
| createFormBindingData(obj?:&nbsp;Object&nbsp;\|&nbsp;string):&nbsp;FormBindingData | 创建一个FormBindingData对象。 |


## 开发步骤

Stage卡片开发，即基于[Stage模型](../application-models/stage-model-development-overview.md)的卡片提供方开发，主要涉及如下关键步骤：

- [创建卡片FormExtensionAbility](#创建卡片formextensionability)：卡片生命周期回调函数FormExtensionAbility开发。

- [配置卡片配置文件](#配置卡片配置文件)：配置应用配置文件module.json5和profile配置文件。

- [卡片信息的持久化](#卡片信息的持久化)：对卡片信息进行持久化管理。

- [卡片数据交互](#卡片数据交互)：通过updateForm更新卡片显示的信息。

- [开发卡片页面](#开发卡片页面)：使用HML+CSS+JSON开发JS卡片页面。

- [开发卡片事件](#开发卡片事件)：为卡片添加router事件和message事件。


### 创建卡片FormExtensionAbility

创建Stage模型的卡片，需实现FormExtensionAbility生命周期接口。先参考<!--RP1-->[DevEco Studio服务卡片开发指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-service-widget-V5)<!--RP1End-->生成服务卡片模板。

1. 在EntryFormAbility.ets中，导入相关模块。
    ```ts
    import { Want } from '@kit.AbilityKit';
    import { formBindingData, FormExtensionAbility, formInfo, formProvider } from '@kit.FormKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    const TAG: string = 'JsCardFormAbility';
    const DOMAIN_NUMBER: number = 0xFF00;
    ```

2. 在EntryFormAbility.ets中，实现FormExtension生命周期接口。

    ```ts
    export default class EntryFormAbility extends FormExtensionAbility {
      onAddForm(want: Want): formBindingData.FormBindingData {
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onAddForm');
        // 使用方创建卡片时触发，提供方需要返回卡片数据绑定类
        let obj: Record<string, string> = {
          'title': 'titleOnCreate',
          'detail': 'detailOnCreate'
        };
        let formData: formBindingData.FormBindingData = formBindingData.createFormBindingData(obj);
        return formData;
      }
      onCastToNormalForm(formId: string): void {
        // 使用方将临时卡片转换为常态卡片触发，提供方需要做相应的处理
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onCastToNormalForm');
      }
      onUpdateForm(formId: string): void {
        // 若卡片支持定时更新/定点更新/卡片使用方主动请求更新功能，则提供方需要重写该方法以支持数据更新
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
        // 使用方发起可见或者不可见通知触发，提供方需要做相应的处理，仅系统应用生效
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onChangeFormVisibility');
        //...
      }
      onFormEvent(formId: string, message: string): void {
        // 若卡片支持触发事件，则需要重写该方法并实现对事件的触发
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onFormEvent');
      }
      onRemoveForm(formId: string): void {
        // 删除卡片实例数据
        hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onRemoveForm');
        //...
      }
      onAcquireFormState(want: Want): formInfo.FormState {
        return formInfo.FormState.READY;
      }
    }
    ```

> **说明：**
> FormExtensionAbility不能常驻后台，即在卡片生命周期回调函数中无法处理长时间的任务。


### 配置卡片配置文件

1. 卡片需要在[module.json5配置文件](../quick-start/module-configuration-file.md)中的extensionAbilities标签下，配置ExtensionAbility相关信息。FormExtensionAbility需要填写metadata元信息标签，其中键名称为固定字符串"ohos.extension.form"，资源为卡片的具体配置信息的索引。
   配置示例如下：

   
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

2. 卡片的具体配置信息。在上述FormExtensionAbility的元信息（"metadata"配置项）中，可以指定卡片具体配置信息的资源索引。例如当resource指定为$profile:form_config时，会使用开发视图的resources/base/profile/目录下的form_config.json作为卡片profile配置文件。内部字段结构说明如下表所示。

   **表1** 卡片profile配置文件

   | 属性名称 | 含义 | 数据类型 | 是否可缺省 |
   | -------- | -------- | -------- | -------- |
   | name | 表示卡片的类名，字符串最大长度为127字节。 | 字符串 | 否 |
   | description | 表示卡片的描述。取值可以是描述性内容，也可以是对描述性内容的资源索引，以支持多语言。字符串最大长度为255字节。 | 字符串 | 可缺省，缺省为空。 |
   | src | 表示卡片对应的UI代码的完整路径。 | 字符串 | 否 |
   | window | 用于定义与显示窗口相关的配置。 | 对象 | 可缺省。 |
   | isDefault | 表示该卡片是否为默认卡片，每个UIAbility有且只有一个默认卡片。<br/>-&nbsp;true：默认卡片。<br/>-&nbsp;false：非默认卡片。 | 布尔值 | 否 |
   | colorMode | 表示卡片的主题样式，取值范围如下：<br/>-&nbsp;auto：自适应。<br/>-&nbsp;dark：深色主题。<br/>-&nbsp;light：浅色主题。 | 字符串 | 可缺省，缺省值为“auto”。 |
   | supportDimensions | 表示卡片支持的外观规格，取值范围：<br/>-&nbsp;1&nbsp;\*&nbsp;2：表示1行2列的二宫格。<br/>-&nbsp;2&nbsp;\*&nbsp;2：表示2行2列的四宫格。<br/>-&nbsp;2&nbsp;\*&nbsp;4：表示2行4列的八宫格。<br/>-&nbsp;4&nbsp;\*&nbsp;4：表示4行4列的十六宫格。 | 字符串数组 | 否 |
   | defaultDimension | 表示卡片的默认外观规格，取值必须在该卡片supportDimensions配置的列表中。 | 字符串 | 否 |
   | updateEnabled | 表示卡片是否支持周期性刷新，取值范围：<br/>-&nbsp;true：表示支持周期性刷新，可以在定时刷新（updateDuration）和定点刷新（scheduledUpdateTime）两种方式任选其一，优先选择定时刷新。<br/>-&nbsp;false：表示不支持周期性刷新。 | 布尔类型 | 否 |
   | scheduledUpdateTime | 表示卡片的定点刷新的时刻，采用24小时制，精确到分钟。<br/>updateDuration参数优先级高于scheduledUpdateTime，两者同时配置时，以updateDuration配置的刷新时间为准。 | 字符串 | 可缺省，缺省值为“0:0”。 |
   | updateDuration | 表示卡片定时刷新的更新周期，单位为30分钟，取值为自然数。<br/>当取值为0时，表示该参数不生效。<br/>当取值为正整数N时，表示刷新周期为30\*N分钟。<br/>updateDuration参数优先级高于scheduledUpdateTime，两者同时配置时，以updateDuration配置的刷新时间为准。 | 数值 | 可缺省，缺省值为“0”。 |
   | formConfigAbility | 表示卡片的配置跳转链接，采用URI格式。 | 字符串 | 可缺省，缺省值为空。 |
   | formVisibleNotify | 标识是否允许卡片使用卡片可见性通知。 | 字符串 | 可缺省，缺省值为空。 |
   | metaData | 表示卡片的自定义信息，包含customizeData数组标签。 | 对象 | 可缺省，缺省值为空。 |

   配置示例如下：

   
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


### 卡片信息的持久化

因大部分卡片提供方都不是常驻服务，只有在需要使用时才会被拉起获取卡片信息，且卡片管理服务支持对卡片进行多实例管理，卡片ID对应实例ID，因此若卡片提供方支持对卡片数据进行配置，则需要对卡片的业务数据按照卡片ID进行持久化管理，以便在后续获取、更新以及拉起时能获取到正确的卡片业务数据。


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
  // 此处仅对卡片ID：formId，卡片名：formName和是否为临时卡片：tempFlag进行了持久化
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
      // 将创建的卡片信息持久化，以便在下次获取/更新该卡片实例时进行使用
      // 此接口请根据实际情况实现，具体请参考：FormExtAbility Stage模型卡片实例
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

且需要适配onRemoveForm卡片删除通知接口，在其中实现卡片实例数据的删除。


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
    // del form info
    await storage.delete(formId);
    hilog.info(DOMAIN_NUMBER, TAG, `[EntryFormAbility] deleteFormInfo, del form info successfully, formId: ${formId}`);
    await storage.flush();
  } catch (err) {
    hilog.error(DOMAIN_NUMBER, TAG, `[EntryFormAbility] failed to deleteFormInfo, err: ${JSON.stringify(err as BusinessError)}`);
  };
};

export default class JsCardFormAbility extends FormExtensionAbility {
  onRemoveForm(formId: string): void {
    // 删除卡片实例数据
    hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onRemoveForm');
    // 删除之前持久化的卡片实例数据
    // 此接口请根据实际情况实现，具体请参考：FormExtAbility Stage模型卡片实例
    deleteFormInfo(formId, this.context);
  }
}
```

具体的持久化方法可以参考[轻量级数据存储开发指导](../database/app-data-persistence-overview.md)。

需要注意的是，卡片使用方在请求卡片时传递给提供方应用的Want数据中存在临时标记字段，表示此次请求的卡片是否为临时卡片：

- 常态卡片：卡片使用方会持久化的卡片。

- 临时卡片：卡片使用方不会持久化的卡片。

由于临时卡片的数据具有非持久化的特殊性，某些场景例如卡片服务框架死亡重启，此时临时卡片数据在卡片管理服务中已经删除，且对应的卡片ID不会通知到提供方，所以卡片提供方需要自己负责清理长时间未删除的临时卡片数据。同时对应的卡片使用方可能会将之前请求的临时卡片转换为常态卡片。如果转换成功，卡片提供方也需要对对应的临时卡片ID进行处理，把卡片提供方记录的临时卡片数据转换为常态卡片数据，防止提供方在清理长时间未删除的临时卡片时，把已经转换为常态卡片的临时卡片信息删除，导致卡片信息丢失。


### 卡片数据交互

当卡片应用需要更新数据时（如触发了定时更新或定点更新），卡片应用获取最新数据，并调用updateForm()接口主动触发卡片的更新。


```ts
import { hilog } from '@kit.PerformanceAnalysisKit';
import { formBindingData, FormExtensionAbility, formProvider } from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';

const TAG: string = 'JsCardFormAbility';
const DOMAIN_NUMBER: number = 0xFF00;

export default class EntryFormAbility extends FormExtensionAbility {
  onUpdateForm(formId: string): void {
    // 若卡片支持定时更新/定点更新/卡片使用方主动请求更新功能，则提供方需要重写该方法以支持数据更新
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


### 开发卡片页面

开发者可以使用类Web范式（HML+CSS+JSON）开发JS卡片页面。生成如下卡片页面，可以这样配置卡片页面文件：

![WidgetCardPage](figures/WidgetCardPage.png)

- HML：使用类Web范式的组件描述卡片的页面信息。

  
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

- CSS：HML中类Web范式组件的样式信息。


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

- JSON：卡片页面中的数据和事件交互。

  
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


### 开发卡片事件

卡片支持为组件设置交互事件（action），包括router事件和message事件，其中router事件用于UIAbility跳转，message事件用于卡片开发人员自定义点击事件。

关键步骤说明如下：

1. 在HML中为组件设置onclick属性，其值对应到JSON文件的actions字段中。

2. 设置router事件：

   - action属性值为"router"。
   - abilityName为跳转目标的UIAbility名（支持跳转FA模型的PageAbility组件和Stage模型的UIAbility组件），如目前DevEco Studio创建的Stage模型的UIAbility默认名为EntryAbility。
   - params为传递给跳转目标UIAbility的自定义参数，可以按需填写。其值可以在目标UIAbility启动时的want中的parameters里获取。如Stage模型MainAbility的onCreate生命周期里的入参want的parameters字段下获取到配置的参数。

3. 设置message事件：

   - action属性值为"message"。
   - params为message事件的用户自定义参数，可以按需填写。其值可以在卡片生命周期函数onFormEvent()中的message里获取。

示例如下。

- HML文件


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

- CSS文件


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

- JSON文件

  
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

  说明：

  "data"中JSON Value支持多级嵌套数据，在更新数据时，需要注意携带完整数据。

  例如：当前卡片显示07.18日Mr.Zhang的课程信息，示例如下。
  ```ts
  "data": {
      "Day": "07.18",
      "teacher": {
          "name": "Mr.Zhang",
          "course": "Math"
      }
  }
  ```
  当卡片内容需要更新为07.18日Mr.Li的课程信息时，需要传递待更新的完整数据，不能只传递单个数据项，如只传name或只传course，示例如下。
  ```ts
  "teacher": {
      "name": "Mr.Li",
      "course": "English"
  }
  ```


- 在UIAbility中接收router事件并获取参数


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
        // 获取router事件中传递的info参数
        if (params.info === 'router info') {
          // 执行业务逻辑
          hilog.info(DOMAIN_NUMBER, TAG, `router info: ${params.info}`);
        }
        // 获取router事件中传递的message参数
        if (params.message === 'router message') {
          // 执行业务逻辑
          hilog.info(DOMAIN_NUMBER, TAG, `router message: ${params.message}`);
        }
      }
    }
  };
  ```

- 在FormExtensionAbility中接收message事件并获取参数

  
  ```ts
  import FormExtension from '@ohos.app.form.FormExtensionAbility';
  import hilog from '@ohos.hilog';

  const TAG: string = 'FormAbility';
  const DOMAIN_NUMBER: number = 0xFF00;

  export default class FormAbility extends FormExtension {
    onFormEvent(formId: string, message: string): void {
      // 若卡片支持触发事件，则需要重写该方法并实现对事件的触发
      hilog.info(DOMAIN_NUMBER, TAG, '[EntryFormAbility] onFormEvent');
      // 获取message事件中传递的detail参数
      let msg: Record<string, string> = JSON.parse(message);
      if (msg.detail === 'message detail') {
        // 执行业务逻辑
        hilog.info(DOMAIN_NUMBER, TAG, 'message info:' + msg.detail);
      }
    }
  };
  ```
<!--Del-->
## 相关实例

针对卡片开发，有以下相关实例可供参考：

- [JS多设备自适应服务卡片（JS）（API9）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SuperFeature/Widget/AdaptiveServiceWidget)

- [电影卡片（JS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Card/MovieCard)

- [计步器卡片（JS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/Card/StepsCardJS)
<!--DelEnd-->