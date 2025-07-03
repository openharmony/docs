# Updating Widget Content Through a Proxy

A widget can be updated through a proxy – a system application that has data sharing enabled – when the widget provider is not running.

## Implementation Principles

**Figure 1** Updating widget content through a proxy

![UpdateWidgetByProxyPrinciple](figures/UpdateWidgetByProxyPrinciple.png)

Compared with the [implementation of the ArkTS widget](arkts-form-overview.md#how-to-implement) alone, updating through a proxy involves the data management service and data provider.

- Data management service: provides a mechanism for data sharing among multiple applications.
- Data provider: must be a system application that has data sharing enabled. The shared data is identified through the defined `key + subscriberId` combination.

> **NOTE**
>
> This feature can be used when the system provides applications as data providers and publicly available shared data identifiers.

Processing flow of the widget provider (indicated by the blue arrows in the figure):

1. The widget provider sets the `dataProxyEnabled` field to `true` in the `form_config.json` file to enable the update-through-proxy feature.
> **NOTE**
>
> After the update-through-proxy feature is enabled, the settings for [interval-based update](arkts-ui-widget-passive-refresh.md#interval-based-update) becomes invalid.

2. In the [onAddForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonaddform) callback, the widget provider returns the `key + subscriberId` combination defined by the data provider to the Widget Manager.

3. The Widget Manager parses the subscription information of the widget provider and registers a subscription instance with the data management service.

Processing flow of the widget update proxy (indicated by the red arrows in the figure):

1. The data provider uses the `key + subscriberId` combination as the data ID to store data to the database.
2. The data management service detects the change in the database and publishes the new data to all currently registered subscription instances.
3. The Widget Manager parses data from the subscription instance and sends the data to the widget rendering service.
4. The widget rendering service runs the widget page code **widgets.abc**, which implements rendering based on the new data and sends the rendered data to the <!--Del-->[<!--DelEnd-->FormComponent<!--Del-->](../reference/apis-arkui/arkui-ts/ts-basic-components-formcomponent-sys.md)<!--DelEnd--> corresponding to the widget host.

There are two types of shared data provided by the data provider:

- Ephemeral data: data that exists only for a specific period of time and can be subscribed to by system and non-system applications alike.

- Persistent data: data that can be subscribed to only by system applications.

The update-through-proxy configuration varies by the type of shared data.
<!--Del-->
## Data Provider Development

For details, see [Data Management](../database/share-data-by-silent-access.md).
<!--DelEnd-->
## Widget Provider Development (Ephemeral Data)

- Set the `dataProxyEnabled` field to `true` in the **form_config.json** file to enable the update-through-proxy feature. When the subscribed ephemeral data is updated, the system automatically updates the widget data.
  ```json
  {
    "forms": [
      {
        "name": "WidgetProcessData",
        "description": "$string:ProcessDataEntryAbility_desc",
        "src": "./ets/widgetprocessdata/pages/WidgetProcessDataCard.ets",
        "uiSyntax": "arkts",
        "window": {
          "designWidth": 720,
          "autoDesignWidth": true
        },
        "colorMode": "auto",
        "isDefault": true,
        "updateEnabled": true,
        "scheduledUpdateTime": "10:30",
        "defaultDimension": "2*2",
        "supportDimensions": [
          "2*2"
        ],
        "dataProxyEnabled": true
      }
    ]
  }
  ```
  
- Configure the subscription information [proxyData](../reference/apis-form-kit/js-apis-app-form-formBindingData.md#proxydata10) in the [onAddForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonaddform) callback and return the information to the Widget Manager through [formBinding](../reference/apis-form-kit/js-apis-app-form-formBindingData.md#formbindingdata). In this example, **key** is set to **datashareproxy://com.samples.widgetupdatebyproxy/weather** and **subscriberId** is set to **11**.
  > **NOTE**
  >
  > The value of **key** can be a URI or a simple string. The default value of **subscriberId** is the value of **formId**. The actual value depends on the definition of the data provider.
  ```ts
  import { formBindingData, FormExtensionAbility } from '@kit.FormKit';
  import { Want } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const TAG: string = 'ProcessDataFormAbility';
  const DOMAIN_NUMBER: number = 0xFF00;
  
  export default class ProcessDataFormAbility extends FormExtensionAbility {
    onAddForm(want: Want): formBindingData.FormBindingData {
      let formData: Record<string, Object> = {};
      let proxies: formBindingData.ProxyData[] = [
        {
          key: 'datashareproxy://com.samples.widgetupdatebyproxy/weather',
          subscriberId: '11'
        }
      ];
      let formBinding = formBindingData.createFormBindingData(formData);
      formBinding.proxies = proxies;
      hilog.info(DOMAIN_NUMBER, TAG, 'onAddForm');
      return formBinding;
    }
  }
  ```
  
- In the [widget page code file](arkts-ui-widget-creation.md), use the variable in LocalStorage to obtain the subscribed data. The variable in LocalStorage is bound to a string and updates the subscribed data in the key:value pair format. The key must be the same as that subscribed to by the widget provider. In this example, the subscribed data is obtained through **'city'** and displayed in the **\<Text>** component.
  ```ts
  let storageProcess = new LocalStorage();
  
  @Entry(storageProcess)
  @Component
  struct WidgetProcessDataCard {
    @LocalStorageProp('datashareproxy://com.samples.widgetupdatebyproxy/weather') city: ResourceStr = $r('app.string.loading');
  
    build() {
      Column() {
        Column() {
          Text(this.city)
            .fontColor('#FFFFFF')
            .opacity(0.9)
            .fontSize(14)
            .margin({ top: '8%', left: '10%' })
        }.width('100%')
        .alignItems(HorizontalAlign.Start)
      }.width('100%').height('100%')
      .backgroundImage($r('app.media.CardEvent'))
      .backgroundImageSize(ImageSize.Cover)
    }
  }
  ```

## Widget Provider Development (Persistent Data)
- Set the `dataProxyEnabled` field to `true` in the **form_config.json** file to enable the update-through-proxy feature.
  ```json
  {
    "forms": [
      {
        "name": "WidgetPersistentData",
        "description": "This is a service widget update by proxy using persistent data.",
        "src": "./ets/widgetpersistentdata/pages/WidgetPersistentDataCard.ets",
        "uiSyntax": "arkts",
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
        ],
        "dataProxyEnabled": true
      }
  ]
  }
  ```

- Add a subscription template <!--Del-->[<!--DelEnd-->addTemplate<!--Del-->](../reference/apis-arkdata/js-apis-data-dataShare-sys.md#addtemplate10)<!--DelEnd--> to the [onAddForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonaddform) callback and use the template predicates to notify the database of the subscribed data conditions. Then, configure the subscription information [proxyData](../reference/apis-form-kit/js-apis-app-form-formBindingData.md#proxydata10) and return it to the Widget Manager through [FormBindingData](../reference/apis-form-kit/js-apis-app-form-formBindingData.md#formbindingdata). In the example, the predicate is set to `"list" : "select type from TBL00 limit 0,1"`, indicating that the first data record in the **type** column is obtained from the **TBL00** database. The data is returned to the widget page code file **widgets.abc** in `{"list":[{"type":"value0"}]}` format. When the subscribed persistent data is updated, the system automatically updates the widget data.

  > **NOTE**
  >
  > - The value of **key** is a URI, which depends on the definition of the data release party.
  > - The value of **subscriberId** can be customized. Ensure that the value of **subscriberId** in **addTemplate** is the same as that of **proxies.subscriberId**.
  ```ts
  import { formBindingData, FormExtensionAbility } from '@kit.FormKit';
  import { Want } from '@kit.AbilityKit';
  import { dataShare } from '@kit.ArkData';

  export default class PersistentDataFormAbility extends FormExtensionAbility {
    onAddForm(want: Want): formBindingData.FormBindingData {
      let subscriberId = '111';
      let template: dataShare.Template = {
        predicates: {
          'list': `select type from TBL00 where cityId = ${subscriberId}`
        },
        scheduler: ''
      };
      dataShare.createDataShareHelper(this.context, 'datashareproxy://com.samples.widgetupdatebyproxy', {
        isProxy: true
      }).then((data) => {
        let dataShareHelper = data;
        dataShareHelper.addTemplate('datashareproxy://com.samples.widgetupdatebyproxy/test', subscriberId, template);
      });
      let formData: Record<string, Object> = {};
      let proxies: formBindingData.ProxyData[] = [
        {
          key: 'datashareproxy://com.samples.widgetupdatebyproxy/test',
          subscriberId: subscriberId
        }
      ];

      let formBinding: formBindingData.FormBindingData = {
        data: JSON.stringify(formData),
        proxies: proxies
      };
      return formBinding;
    }
  }
  ```

- In the [widget page code file](arkts-ui-widget-creation.md), use the variable in LocalStorage to obtain the subscribed data. The variable in LocalStorage is bound to a string and updates the subscribed data in the key:value pair format. The key must be the same as that subscribed to by the widget provider. In the example, the subscribed data is obtained through **'list'**, and the value of the first element is displayed on the **\<Text>** component.
  ```ts
  let storagePersis = new LocalStorage();
  
  @Entry(storagePersis)
  @Component
  struct WidgetPersistentDataCard {
    readonly FULL_WIDTH_PERCENT: string = '100%';
    readonly FULL_HEIGHT_PERCENT: string = '100%';
    @LocalStorageProp('list') list: Record<string, string>[] = [{ 'type': 'a' }];
  
    build() {
      Column() {
        Column() {
          Text((this.list[0]['type']))
            .fontColor('#FFFFFF')
            .opacity(0.9)
            .fontSize(14)
            .margin({ top: '8%', left: '10%' })
        }.width('100%')
        .alignItems(HorizontalAlign.Start)
      }.width(this.FULL_WIDTH_PERCENT).height(this.FULL_HEIGHT_PERCENT)
      .backgroundImage($r('app.media.CardEvent'))
      .backgroundImageSize(ImageSize.Cover)
    }
  }
  ```

