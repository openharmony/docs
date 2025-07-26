# 应用间配置共享 (ArkTS)

## 场景介绍

应用间配置共享通过集中管理公共配置信息，在不同应用间共享配置，提升协作效率。

从API version 20开始，支持应用间配置共享。

## 运作机制

应用间配置共享运作机制如下所示：

1. **配置发布方（即数据提供方）**：负责提供默认共享配置项，并能动态修改配置项信息。当前支持静态配置和动态配置两种配置方式。
   - **静态配置**：应用包在安装时提供的默认共享配置项（不依赖应用启动即生效）。
   - **动态配置**：配置发布方通过调用相关接口可以动态新增、删除或修改配置项（不依赖应用升级）。
2. **配置访问方（即数据访问方）**：可通过调用接口获取配置信息、或者监听/取消监听配置变化。

## 约束与限制

一个应用最多可以发布32个配置项，这个数量是静态配置与动态配置的总和。

## 接口说明
以下接口为应用间配置共享的相关接口。详细接口和说明，请参考[应用间配置共享接口](../reference/apis-arkdata/js-apis-data-dataShare.md#datasharecreatedataproxyhandle20)。

### 公共接口

| 接口名称                        | 描述                                                                                                   |
| ------------------------------- | ------------------------------------------------------------------------------------------------------ |
| createDataProxyHandle(): Promise&lt;DataProxyHandle&gt; | 创建数据代理操作句柄，可用于订阅、发布、获取等操作。 |

### 配置发布方接口

| 接口名称                                                     | 描述               |
| ------------------------------------------------------------ | ------------------ |
| publish(data: ProxyData[], config: DataProxyConfig): Promise<DataProxyResult[]> | 发布或修改配置项。 |
| delete(uris: string[], config: DataProxyConfig): Promise<DataProxyResult[]> | 删除配置项。       |

### 配置访问方接口

| 接口名称                                                     | 描述                 |
| ------------------------------------------------------------ | -------------------- |
| get(uris: string[], config: DataProxyConfig): Promise<DataProxyGetResult[]> | 获取配置项信息。     |
| on(event: 'dataChange', uris: string[], config: DataProxyConfig, callback: AsyncCallback<DataProxyChangeInfo[]>): DataProxyResult[] | 监听配置项变化。     |
| off(event: 'dataChange', uris: string[], config: DataProxyConfig, callback?: AsyncCallback<DataProxyChangeInfo[]>): DataProxyResult[] | 取消监听配置项变化。 |


## 配置发布方
### module.json5 配置
配置发布方需要配置module.json5文件中的crossAppSharedConfig字段，通过crossAppSharedConfig字段引用shared_config.json文件，shared_config.json为共享配置文件，定义了应用希望与其他应用共享的配置项。共享配置文件需放置在工程resources/base/profile目录下，并通过`$`资源访问方式引用。  


```json
"module":{
    "crossAppSharedConfig": "$profile:shared_config"
  }
```


共享配置文件shared_config.json的文件名"shared_config"可自定义，根节点名称为crossAppSharedConfig，为对象数组，标识当前共享配置项的数量。（一个应用最多可以发布32个配置项，这个数量是静态配置项与动态配置项的总和。静态配置项数量超过32时，只解析前32个符合crossAppSharedConfig字段配置说明要求的配置项，其余配置项不生效。）

crossAppSharedConfig字段配置说明：

| 属性名称 | 含义 | 数据类型 | 必填 |
| ------- | ------- | ------- | ------- |
| uri | 共享配置项的全局唯一标识。固定格式为`"datashareproxy://{bundleName}/{path}"`，其中bundleName为配置发布方应用的bundleName，path可随意填写，但同一应用内不允许重复。uri最大长度为256字节。 | 字符串 | 是 |
| value | 共享配置项的值，最大长度为4096字节。 | 字符串 | 是 |
| allowList | 允许访问该共享配置项的应用程序列表。数组最大长度为256，超过256的部分不生效。数组中每个元素为应用的[appIdentifier](../quick-start/common_problem_of_application.md#什么是appidentifier)，单个appIdentifier为只包含数字的字符串，最大长度为128字节，超过128字节的appIdentifier不会生效。可使用[getBundleInfoForSelf](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself)接口来获取当前应用的appIdentifier。 | 字符串数组 | 是 |

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

### 静态配置

应用包在安装时提供的默认共享配置项，即在应用安装过程中，预先定义并设置好的共享配置项，这些配置项不依赖应用的启动即可生效。 

### 动态配置

可通过调用publish接口或delete接口，动态新增、删除或修改配置项。  

- 通过调用publish接口发布或修改配置项。

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

- 通过调用delete接口删除配置项。

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

## 配置访问方

配置访问方可以通过调用get、on或off接口来获取配置信息或监听/取消监听配置变化。

### 获取配置项信息

使用get接口获取配置信息。

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

### 监听/取消监听配置变化

使用on接口监听配置变化，使用off接口取消监听配置变化。

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
    // 监听配置变化
    const listenResults: dataShare.DataProxyResult[] = dsProxyHelper.on('dataChange', uris, config, callback);
    listenResults.forEach((result) => {
      console.info(`URI: ${result.uri}, Result: ${result.result}`);
    });
    // 取消监听配置变化    
    const unListenResults: dataShare.DataProxyResult[] = dsProxyHelper.off('dataChange', uris, config, callback);
    unListenResults.forEach((result) => {
      console.info(`URI: ${result.uri}, Result: ${result.result}`);
    });
  }).catch((error: BusinessError) => {
    console.error('Error creating DataProxyHandle:', error);
  });
}
```
