# @ohos.request.cacheDownload (缓存下载)
<!--Kit: Basic Services Kit-->
<!--Subsystem: Request-->
<!--Owner: @huaxin05-->
<!--SE: @hu-kai45-->
<!--TSE: @murphy1984-->

request部件主要给应用提供上传下载文件、后台传输代理的基础能力。

- request的cacheDownload子组件主要给应用提供应用资源提前缓存的基础能力。

- cacheDownload组件使用HTTP协议进行数据下载，并将数据资源缓存至应用内存或应用沙箱目录的文件中。

- 这些缓存数据可以被部分ArkUI相关组件使用（例如：Image组件），从而提升资源加载效率。请查看ArkUI组件文档确定组件是否支持该功能。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { cacheDownload } from '@kit.BasicServicesKit';
```

## CacheDownloadOptions

缓存下载的配置选项。例如：HTTP选项、传输选项、任务选项等。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称      | 类型                       | 必填 | 说明                    |
|---------|--------------------------|----|-----------------------|
| headers | Record\<string, string\> | 否  | 缓存下载任务在HTTP传输时使用的请求头。 |

## ResourceInfo<sup>20+</sup>

预下载的资源信息。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称   | 类型     | 只读 | 可选 | 说明                            |
|------|--------|----|----|-------------------------------|
| size | number | 是  | 否  | 预下载资源解压后的大小。整数值不为-1时表示资源下载成功。 |

## NetworkInfo<sup>20+</sup>

预下载的网络信息。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称         | 类型       | 只读 | 可选 | 说明                |
|------------|----------|----|----|-------------------|
| dnsServers | string[] | 是  | 否  | 下载资源时使用的DNS服务器列表。 |

## PerformanceInfo<sup>20+</sup>

预下载的性能信息。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称               | 类型     | 只读 | 可选 | 说明                            |
|------------------|--------|----|----|-------------------------------|
| dnsTime          | number | 是  | 否  | 从启动到dns解析完成所需的时间，单位：毫秒（ms）。   |
| connectTime      | number | 是  | 否  | 从启动到tcp连接完成所需的时间，单位：毫秒（ms）。   |
| tlsTime          | number | 是  | 否  | 从启动到tls连接完成所需的时间，单位：毫秒（ms）。   |
| firstSendTime    | number | 是  | 否  | 从启动到开始发送第一个字节所需的时间，单位：毫秒（ms）。 |
| firstReceiveTime | number | 是  | 否  | 从启动到接收第一个字节所需的时间，单位：毫秒（ms）。   |
| totalTime        | number | 是  | 否  | 从启动到完成请求所需的时间，单位：毫秒（ms）。      |
| redirectTime     | number | 是  | 否  | 从启动到完成所有重定向步骤所需的时间，单位：毫秒（ms）。 |

## DownloadInfo<sup>20+</sup>

预下载的下载信息。

**系统能力**：SystemCapability.Request.FileTransferAgent

| 名称          | 类型                                    | 只读 | 可选 | 说明        |
|-------------|---------------------------------------|----|----|-----------|
| resource    | [ResourceInfo](#resourceinfo20)       | 是  | 否  | 预下载的资源信息。 |
| network     | [NetworkInfo](#networkinfo20)         | 是  | 否  | 预下载的网络信息。 |
| performance | [PerformanceInfo](#performanceinfo20) | 是  | 否  | 预下载的性能信息。 |

## cacheDownload.download

download(url: string, options: CacheDownloadOptions)

启动一个缓存下载任务，若传输成功，则将数据下载到内存缓存和文件缓存中。

- 目标资源经过HTTP传输自动解压后的大小不能超过20971520B（即20MB），否则不会保存到内存缓存或文件缓存中。

- 在缓存下载数据时，如果在该url下已存在缓存内容，新的缓存内容会覆盖旧缓存内容。

- 目标资源在存储到内存缓存或文件缓存中时，依照缓存下载组件的各类型缓存大小上限决定文件是否存储到指定位置，并默认使用“LRU”（最近最少使用）方式替换已有缓存内容。

- 该方法为同步方法，不阻塞调用线程。

**需要权限**：ohos.permission.INTERNET

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                             |
|---------|------------------------------------------------------------|----|--------------------------------|
| url     | string                                                     | 是  | 目标资源的地址。仅支持HTTP协议，长度不超过8192字节。 |
| options | [CacheDownloadOptions](#cachedownloadoptions) | 是  | 目标资源的缓存下载选项。                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                                                                                                      |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 201      | permission denied.                                                                                                              |
| 401      | parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';

  // 提供缓存下载任务的配置选项。
  let options: cacheDownload.CacheDownloadOptions = {};
  
  try {
    // 进行缓存下载，资源若下载成功会被缓存到应用内存或应用沙箱目录的特定文件中。  
    cacheDownload.download("https://www.example.com", options);
  } catch (err) {
    console.error(`Failed to download the resource. err code: ${err.code}, err message: ${err.message}`);
  }
  ```

## cacheDownload.cancel

cancel(url: string)

根据url移除一个正在执行的缓存下载任务，已保存的内存缓存和文件缓存不会受到影响。

- 如果不存在对应url的任务则无其他效果。

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
| 401      | parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';

  // 提供缓存下载任务的配置选项。
  let options: cacheDownload.CacheDownloadOptions = {};
  
  try {
    // 进行缓存下载，资源若下载成功会被缓存到应用内存或应用沙箱目录的特定文件中。  
    cacheDownload.download("https://www.example.com", options);
  } catch (err) {
    console.error(`Failed to download the resource. err code: ${err.code}, err message: ${err.message}`);
  }

  // 处理其他业务逻辑。
  
  try {
    // 在不需要特定任务缓存时，移除缓存下载任务，已缓存的内容不受影响。
    cacheDownload.cancel("https://www.example.com");
  } catch (err) {
    console.error(`Failed to cancel the task. err code: ${err.code}, err message: ${err.message}`);
  }
  ```

## cacheDownload.setMemoryCacheSize

setMemoryCacheSize(bytes: number)

设置缓存下载组件能够保存的内存缓存上限。

- 使用该接口调整缓存大小时，默认使用“LRU”（最近最少使用）方式清除多余的已缓存的内存缓存内容。

- 该方法为同步方法，不阻塞调用线程。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名   | 类型     | 必填 | 说明                                      |
|-------|--------|----|-----------------------------------------|
| bytes | number | 是  | 设置的缓存上限。默认值为0B，最大值不超过1073741824B（即1GB）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                                                                                                      |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';
  
  try {
    // 设置内存缓存大小上限。  
    cacheDownload.setMemoryCacheSize(10 * 1024 * 1024);
  } catch (err) {
    console.error(`Failed to set memory cache size. err code: ${err.code}, err message: ${err.message}`);
  }
  ```

## cacheDownload.setFileCacheSize

setFileCacheSize(bytes: number)

设置缓存下载组件能够保存的文件缓存上限。

- 使用该接口调整缓存大小时，默认使用“LRU”（最近最少使用）方式清除多余的已缓存的文件缓存内容。

- 该方法为同步方法，不阻塞调用线程。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
|-------|--------|----|------------------------------------------------------------|
| bytes | number | 是  | 设置的缓存上限。默认值为104857600B（即100MB），最大值不超过4294967296B（即4GB）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID    | 错误信息                                                                                                                                      |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | parameter error. Possible causes: 1. Missing mandatory parameters. 2. Incorrect parameter type. 3. Parameter verification failed. |

**示例：**

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';
  
  try {
    // 设置文件缓存大小上限。  
    cacheDownload.setFileCacheSize(100 * 1024 * 1024);
  } catch (err) {
    console.error(`Failed to set file cache size. err code: ${err.code}, err message: ${err.message}`);
  }
  ```

## cacheDownload.setDownloadInfoListSize<sup>20+</sup>

setDownloadInfoListSize(size: number): void

设置下载信息列表的大小。

- 下载信息列表用于存储预下载信息。

- 下载信息和url一一对应，每次预下载都会生成一个下载信息，相同url下只会保存最新的下载信息。

- 使用该接口调整列表大小时，size更新增大，列表中原有的信息不变，更新减小，默认使用“LRU”（最近最少使用）方式清除多余的已缓存信息。

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名  | 类型     | 必填 | 说明                                            |
|------|--------|----|-----------------------------------------------|
| size | number | 是  | 设置的下载信息列表大小。取值范围：[0, 8192]，默认为0，表示不会存储任何下载信息。 |

**示例：**

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';
  
  try {
    // 设置下载信息列表大小。  
    cacheDownload.setDownloadInfoListSize(2048);
  } catch (err) {
    console.error(`Failed to set download information list size. err code: ${err.code}, err message: ${err.message}`);
  }
  ```

## cacheDownload.getDownloadInfo<sup>20+</sup>

getDownloadInfo(url: string): DownloadInfo | undefined

基于url获取预下载的下载信息。信息存储在内存中的下载信息列表，当应用程序退出时清除。

- 如果下载信息列表中能够找到指定url，返回url最近一次下载的[DownloadInfo](#downloadinfo20)。

- 如果下载信息列表中找不到指定url，返回undefined。

- 在缓存下载信息时，如果在该url下已存在缓存信息，新的缓存内容会覆盖旧缓存。

- 目标信息在存储到内存时，使用“LRU”（最近最少使用）方式替换已有缓存内容。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Request.FileTransferAgent

**参数：**

| 参数名 | 类型     | 必填 | 说明                   |
|-----|--------|----|----------------------|
| url | string | 是  | 待查询的url，最大长度为8192字节。 |

**返回值：**

| 类型                                           | 说明                               |
|----------------------------------------------|----------------------------------|
| [DownloadInfo](#downloadinfo20) \| undefined | 返回对应url的下载信息，url未记录时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息               |
|-------|--------------------|
| 201   | permission denied. |

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';

  try {
    // 设置下载信息列表大小。  
    cacheDownload.setDownloadInfoListSize(2048);
  } catch (err) {
    console.error(`Failed to set download information list size. err code: ${err.code}, err message: ${err.message}`);
  }

  // 提供缓存下载任务的配置选项。
  let options: cacheDownload.CacheDownloadOptions = {};
  
  try {
    // 进行缓存下载，资源若下载成功会被缓存到应用内存或应用沙箱目录的特定文件中。  
    cacheDownload.download("https://www.example.com", options);
  } catch (err) {
    console.error(`Failed to download the resource. err code: ${err.code}, err message: ${err.message}`);
  }

  // 处理其他业务逻辑。
  
  try {
    // 在缓存下载完成后，获取缓存下载的信息。
    let downloadInfo = cacheDownload.getDownloadInfo("https://www.example.com");
    if (downloadInfo == undefined) {
      console.info(`CacheDownload get download info undefined.`);
    } else {
      console.info(`CacheDownload get download info : ${JSON.stringify(downloadInfo)}`);
    }
  } catch (err) {
    console.error(`Failed to get download info. err code: ${err.code}, err message: ${err.message}`);
  }
  ```