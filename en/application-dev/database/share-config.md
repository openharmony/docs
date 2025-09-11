# Sharing Configurations Between Applications (ArkTS)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @woodenarow-->
<!--Designer: @woodenarow; @xuelei3-->
<!--Tester: @chenwan188; @logic42-->
<!--Adviser: @ge-yafang-->

## When to Use

Sharing configurations between applications allows you to manage common configuration information in a centralized manner, thereby improving collaboration efficiency.

This feature is supported since API version 20.

## Working Principles

The working principles of configuration sharing between applications are as follows:

1. **Configuration publisher (data provider)**: provides default shared configuration items and dynamically modifies them. Currently, the following configuration modes are supported:
   - **Static configuration**: default shared configuration items are provided when the application package is installed. The configuration takes effect immediately without depending on the application startup.
   - **Dynamic configuration**: configuration items can be dynamically added, deleted, or modified via related APIs, without depending on application upgrade.
2. **Configuration accessor (data consumer)**: calls APIs to obtain configuration information or subscribe to/unsubscribe from a listening for configuration changes.

## Constraints

An application can publish a maximum of 32 configuration items, including static and dynamic ones.

## Available APIs
The following table lists the APIs used to share configurations between applications. For details about the APIs, see [dataShare.createDataProxyHandle](../reference/apis-arkdata/js-apis-data-dataShare.md#datasharecreatedataproxyhandle20).

### Public APIs

| Name                       | Description                                                                                                  |
| ------------------------------- | ------------------------------------------------------------------------------------------------------ |
| createDataProxyHandle(): Promise&lt;DataProxyHandle&gt; | Creates a data proxy operation handle, which is used to subscribe to, publish, and obtain configurations.|

### APIs for Configuration Publishers

| Name                                                    | Description              |
| ------------------------------------------------------------ | ------------------ |
| publish(data: ProxyData[], config: DataProxyConfig): Promise<DataProxyResult[]> | Publishes or modifies configuration items.|
| delete(uris: string[], config: DataProxyConfig): Promise<DataProxyResult[]> | Deletes configuration items.      |

### APIs for Configuration Accessors

| Name                                                    | Description                |
| ------------------------------------------------------------ | -------------------- |
| get(uris: string[], config: DataProxyConfig): Promise<DataProxyGetResult[]> | Obtains configuration items.    |
| on(event: 'dataChange', uris: string[], config: DataProxyConfig, callback: AsyncCallback<DataProxyChangeInfo[]>): DataProxyResult[] | Subscribes to configuration item changes.    |
| off(event: 'dataChange', uris: string[], config: DataProxyConfig, callback?: AsyncCallback<DataProxyChangeInfo[]>): DataProxyResult[] | Unsubscribes from configuration item changes.|


## Configuring the Publisher
### Configuration in module.json5
Reference the **shared_config.json** file by configuring the **crossAppSharedConfig** field in the **module.json5** file. The **shared_config.json** file defines the configuration items that can be shared between applications. You should store the file in the **resources/base/profile** directory of the project and reference it using the **$** symbol. 


```json
{
  "module":{
    "crossAppSharedConfig": "$profile:shared_config"
  }
}
```


The name of the **shared_config.json** file can be customized. The root node **crossAppSharedConfig** is an object array and indicates the number of shared configuration items. An application can publish a maximum of 32 configuration items, including static and dynamic ones. If the number of static configuration items exceeds 32, only the first 32 items that meet the following configuration requirements are parsed, and other configuration items do not take effect.

The following table describes the parameters in the **crossAppSharedConfig** field.

| Name| Description| Type| Mandatory|
| ------- | ------- | ------- | ------- |
| uri | Unique ID of a shared configuration, fixed at the format of **"datashareproxy://{*bundleName*}/{*path*}"**, in which **bundleName** indicates the bundle name of the publisher application, and **path** can be set to any value but must be unique in the same application. The maximum length is 256 bytes.| String| Yes|
| value | Value of a shared configuration item, with a maximum of 4096 bytes.| String| Yes|
| allowList | List of applications that are allowed to access the shared configuration items. The array can contain a maximum of 256 elements. Excess elements are invalid. Each element in the array is the [appIdentifier](../quick-start/common_problem_of_application.md#what-is-appidentifier) of an application. **appIdentifier** is a string containing only digits with a maximum of 128 bytes. If the **appIdentifier** exceeds 128 bytes, it does not take effect. You can use the [getBundleInfoForSelf](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself) API to obtain the **appIdentifier** of an application. | String array| Yes|

```json
{
    "crossAppSharedConfig": [
        {
            "uri": "datashareproxy://com.example.example/key1",
            "value": "SHARED_CONFIG_DEMO1",
            "allowList": ["6917573629901742292"]
        },
        {
            "uri": "datashareproxy://com.example.example/key2",
            "value": "SHARED_CONFIG_DEMO2",
            "allowList": ["6917573298752100864", "6917573298752100864"]
        }
    ]
}
```

### Static Configuration

Static configuration refers to the default shared configuration items provided during application installation. These predefined configuration items can take effect regardless of whether the application is started.

### Dynamic Configuration

You can call the **publish** or **delete** API to manage configuration items as follows: 

- Call the **publish** API to publish or modify configuration items.

  ```ts
  import { dataShare } from '@kit.ArkData';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  export function publish() {
    dataShare.createDataProxyHandle().then((dsProxyHelper) => {
      const newConfigData: dataShare.ProxyData[] = [{
        uri: 'datashareproxy://com.example.app1/config1',
        value: 'Value1',
        allowList: ['com.example.app2', 'com.example.app3'],
      }, {
        uri: 'datashareproxy://com.example.app1/config2',
        value: 'Value2',
        allowList: ['com.example.app3', 'com.example.app4'],
      },];
      const config: dataShare.DataProxyConfig = {
        type: dataShare.DataProxyType.SHARED_CONFIG,
      };
      dsProxyHelper.publish(newConfigData, config).then((results: dataShare.DataProxyResult[]) => {
        results.forEach((result) => {
          console.info(`URI: ${result.uri}, Result: ${result.result}`);
        });
      }).catch((error: BusinessError) => {
        console.error('Error publishing config:', error);
      });
    }).catch((error: BusinessError) => {
      console.error('Error creating DataProxyHandle:', error);
    });
  }
  ```

- Call the **delete** API to delete the configuration items.

  ```ts
  import { dataShare } from '@kit.ArkData';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  export function deleteShareConfig() {
    dataShare.createDataProxyHandle().then((dsProxyHelper) => {
      const urisToDelete: string[] =
        ['datashareproxy://com.example.app1/config1', 'datashareproxy://com.example.app1/config2',];
      const config: dataShare.DataProxyConfig = {
        type: dataShare.DataProxyType.SHARED_CONFIG,
      };
      dsProxyHelper.delete(urisToDelete, config).then((results: dataShare.DataProxyResult[]) => {
        results.forEach((result) => {
          console.info(`URI: ${result.uri}, Result: ${result.result}`);
        });
      }).catch((error: BusinessError) => {
        console.error('Error deleting config:', error);
      });
    }).catch((error: BusinessError) => {
      console.error('Error creating DataProxyHandle:', error);
    });
  }
  ```

## Configuring the Accessor

You can call the **get**, **on**, or **off** API to perform operations as follows:

### Obtaining Configuration Items

Call the **get** API to obtain the configuration information.

```ts
import { dataShare } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

export function get() {
  dataShare.createDataProxyHandle().then((dsProxyHelper) => {
    const urisToGet: string[] =
      ['datashareproxy://com.example.app1/config1', 'datashareproxy://com.example.app1/config2',];
    const config: dataShare.DataProxyConfig = {
      type: dataShare.DataProxyType.SHARED_CONFIG,
    };
    dsProxyHelper.get(urisToGet, config).then((results: dataShare.DataProxyGetResult[]) => {
      results.forEach((result) => {
        console.info(`URI: ${result.uri}, Result: ${result.result}, AllowList: ${result.allowList}`);
      });
    }).catch((error: BusinessError) => {
      console.error('Error getting config:', error);
    });
  }).catch((error: BusinessError) => {
    console.error('Error creating DataProxyHandle:', error);
  });
}
```

### Subscribing to/Unsubscribing from Configuration Changes

Call the **on** API to subscribe to configuration changes or the **off** API to unsubscribe from the configuration changes.

```ts
import { dataShare } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

export function watchConfigChanges() {
  dataShare.createDataProxyHandle().then((dsProxyHelper) => {
    const uris: string[] =
      ['datashareproxy://com.example.app1/config1', 'datashareproxy://com.example.app1/config2',];
    const config: dataShare.DataProxyConfig = {
      type: dataShare.DataProxyType.SHARED_CONFIG,
    };
    const callback = (err: BusinessError<void>, changes: dataShare.DataProxyChangeInfo[]): void => {
      if (err) {
        console.error('err:', err);
      } else {
        changes.forEach((change) => {
          console.info(`Change Type: ${change.type}, URI: ${change.uri}, Value: ${change.value}`);
        });
      }
    };
    // Subscribe to configuration changes.
    const listenResults: dataShare.DataProxyResult[] = dsProxyHelper.on('dataChange', uris, config, callback);
    listenResults.forEach((result) => {
      console.info(`URI: ${result.uri}, Result: ${result.result}`);
    });
    // Unsubscribe from configuration changes.   
    const unListenResults: dataShare.DataProxyResult[] = dsProxyHelper.off('dataChange', uris, config, callback);
    unListenResults.forEach((result) => {
      console.info(`URI: ${result.uri}, Result: ${result.result}`);
    });
  }).catch((error: BusinessError) => {
    console.error('Error creating DataProxyHandle:', error);
  });
}
```
