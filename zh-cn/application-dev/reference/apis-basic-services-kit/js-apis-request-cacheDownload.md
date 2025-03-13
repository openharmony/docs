# @ohos.request.cacheDownload (缓存下载)

request部件主要给应用提供上传下载文件、后台传输代理的基础能力。

- request的cacheDownload子组件主要给应用提供应用资源提前缓存的基础能力。

- cacheDownload组件使用HTTP协议进行数据下载，并将数据资源缓存至应用内存或应用沙箱目录的文件中。

- 这些缓存数据可以被部分ArkUI相关组件使用(例如：Image组件)，从而提升资源加载效率。请查看ArkUI组件文档确定组件是否支持该功能。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { cacheDownload } from '@kit.BasicServicesKit';
```

## cacheDownload.CacheDownloadOptions

缓存下载的配置选项。例如：HTTP选项、传输选项、任务选项等。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称      | 类型                       | 必填 | 说明                    |
|---------|--------------------------|----|-----------------------|
| headers | Record\<string, string\> | 否  | 缓存下载任务在HTTP传输时使用的请求头。 |

## cacheDownload.download

download(url: string, options: CacheDownloadOptions)

启动一个缓存下载任务，若传输成功，则将数据下载到内存缓存和文件缓存中。

- 目标资源经过HTTP传输自动解压后的大小不能超过20971520B(即20MB)，否则不会保存到内存缓存或文件缓存中。

- 在缓存下载数据时，如果在该URL下已存在缓存内容，新的缓存内容会覆盖旧缓存内容。

- 目标资源在存储到内存缓存或文件缓存中时，依照缓存下载组件的各类型缓存大小上限决定文件是否存储到指定位置，并默认使用“LRU”(最近最少使用)方式替换已有缓存内容。

- 该方法为同步方法，不阻塞调用线程。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                             |
|---------|------------------------------------------------------------|----|--------------------------------|
| url     | string                                                     | 是  | 目标资源的地址。仅支持HTTP协议，长度不超过8192字节。 |
| options | [CacheDownloadOptions](#cachedownloadcachedownloadoptions) | 是  | 目标资源的缓存下载选项。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                                                                                                      |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 201      | the permissions check fails.                                                                                                              |
| 401      | the parameters check fails. Possible causes: 1. Missing mandatory parameters 2. Incorrect parameter type 3. Parameter verification failed |

**示例：**

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';

  // 提供缓存下载任务的配置选项。
  let options: cacheDownload.CacheDownloadOptions;
  
  try {
    // 进行缓存下载，资源若下载成功会被缓存到应用内存或应用沙箱目录的特定文件中。  
    cacheDownload.download("https://www.example.com", options);
  } catch (err) {
    console.error(`Failed to download the resource. err: ${JSON.stringify(err)}`);
  }
  ```

## cacheDownload.cancel

cancel(url: string)

根据URL移除一个正在执行的缓存下载任务，已保存的内存缓存和文件缓存不会受到影响。

- 如果不存在对应URL的任务则无其他效果。

- 该方法为同步方法，不阻塞调用线程。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名  | 类型     | 必填 | 说明                             |
|------|--------|----|--------------------------------|
| url  | string | 是  | 目标资源的地址。仅支持HTTP协议，长度不超过8192字节。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                                                                                                      |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | the parameters check fails. Possible causes: 1. Missing mandatory parameters 2. Incorrect parameter type 3. Parameter verification failed |

**示例：**

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';

  // 提供缓存下载任务的配置选项。
  let options: cacheDownload.CacheDownloadOptions;
  
  try {
    // 进行缓存下载，资源若下载成功会被缓存到应用内存或应用沙箱目录的特定文件中。  
    cacheDownload.download("https://www.example.com", options);
  } catch (err) {
    console.error(`Failed to download the resource. err: ${JSON.stringify(err)}`);
  }

  // 处理其他业务逻辑。
  
  try {
    // 在不需要特定任务缓存时，移除缓存下载任务，已缓存的内容不受影响。
    cacheDownload.cancel("https://www.example.com");
  } catch (err) {
    console.error(`Failed to cancel the task. err: ${JSON.stringify(err)}`);
  }
  ```

## cacheDownload.setMemoryCacheSize

setMemoryCacheSize(bytes: number)

设置缓存下载组件能够保存的内存缓存上限。

- 使用该接口调整缓存大小时，默认使用“LRU”(最近最少使用方式)清除多余的已缓存的内存缓存内容。

- 该方法为同步方法，不阻塞调用线程。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名   | 类型     | 必填 | 说明                                      |
|-------|--------|----|-----------------------------------------|
| bytes | number | 是  | 设置的缓存上限。默认值为0B，最大值不超过1073741824B(即1GB)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                                                                                                      |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | the parameters check fails. Possible causes: 1. Missing mandatory parameters 2. Incorrect parameter type 3. Parameter verification failed |

**示例：**

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';
  
  try {
    // 设置内存缓存大小上限。  
    cacheDownload.setMemoryCacheSize(10 * 1024 * 1024);
  } catch (err) {
    console.error(`Failed to set memory cache size. err: ${JSON.stringify(err)}`);
  }
  ```

## cacheDownload.setFileCacheSize

setFileCacheSize(bytes: number)

设置缓存下载组件能够保存的文件缓存上限。

- 使用该接口调整缓存大小时，默认使用“LRU”(最近最少使用方式)清除多余的已缓存的文件缓存内容。

- 该方法为同步方法，不阻塞调用线程。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
|-------|--------|----|------------------------------------------------------------|
| bytes | number | 是  | 设置的缓存上限。默认值为104857600B(即100MB)，最大值不超过4294967296B(即4GB)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                                                                                                      |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | the parameters check fails. Possible causes: 1. Missing mandatory parameters 2. Incorrect parameter type 3. Parameter verification failed |

**示例：**

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';
  
  try {
    // 设置文件缓存大小上限。  
    cacheDownload.setFileCacheSize(100 * 1024 * 1024);
  } catch (err) {
    console.error(`Failed to set file cache size. err: ${JSON.stringify(err)}`);
  }
  ```