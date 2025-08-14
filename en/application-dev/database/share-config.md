# Sharing Configurations Between Applications (ArkTS)

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
The following table lists the APIs used to share configurations between applications.  

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
Store the the **shared_config.json** file in the **resources/base/profile** directory and reference it by using the **$** symbol in the **crossAppSharedConfig** field of the **module.json5** file. The **shared_config.json** file defines the configuration items that can be shared between applications. 


```json
"module":{
    "crossAppSharedConfig": "$profile:shared_config.json"
  }
```


The **shared_config.json** file contains the following configuration items:

- **uri**: fixed at the format of **"datashareproxy://{*bundleName*}/{*path*}"**, in which **bundleName** indicates the bundle name of the publisher application, and **path** can be set to any value but must be unique in the same application. The maximum length is 256 bytes.

- **value**: value of the configuration item, with a maximum length of 4096 bytes.

- **allowList**: [appIdentifiers](../reference/apis-ability-kit/js-apis-bundleManager.md#signatureinfo) list of applications that are allowed to access the configuration. A maximum of 256 **appIdentifiers** are supported. You can use the [getBundleInfoForSelf](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself) API to obtain the **appIdentifier** of an application.

-  An application can publish a maximum of 32 configuration items, including static and dynamic ones.
```json
{
    "crossAppSharedConfig": [
        {
            "uri": "datashareproxy://com.example.example/key1",
            "value": "xxx",
            "allowList": ["xxx", "xxx"]
        },
        {
            "uri": "datashareproxy://com.example.example/key2",
            "value": "xxx",
            "allowList": ["xxx", "xxx"]
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
