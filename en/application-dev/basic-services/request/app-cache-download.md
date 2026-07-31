# App File Cache Download

<!--Kit: Basic Services Kit-->
<!--Subsystem: Request-->
<!--Owner: @huaxin05-->
<!--Designer: @hu-kai45-->
<!--Tester: @murphy1984-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=7fe1a9441f6ed3b8102412ded8b971ee1d1d6aae translatedAt=2026-07-28T07:32:10.383Z pushedAt=2026-07-31T09:37:43.286Z -->

Developers can use the Cache Download module ([cacheDownload](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md)) to download network resource files and cache them in the file system. The cache download feature supports configuring retry strategies and timeout control. Starting from API version 26.0.0, developers can configure retry and timeout parameters for individual tasks, or set global default configurations.

> **NOTE**
>
> · To use the Cache Download module, you must [declare the permission](../../security/AccessToken/declare-permissions.md): ohos.permission.INTERNET.
>
> · To obtain download information or check network availability, you must also declare the permission: ohos.permission.GET_NETWORK_INFO.
>
> · Cached downloaded resources are stored in the file cache. A single downloaded resource supports a maximum of 20 MB after decompression.
>
> · Cache download callback listeners (onDownloadSuccess/onDownloadError) are process-level and must be properly managed with registration and deregistration within the page lifecycle.

## Task-Level Retry Strategy

Starting from API version 26.0.0, developers can configure the retry strategy for a cache download task through [RetryOptions](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md#retryoptions) when creating the task. If the download fails, the system automatically retries based on the configuration.

The following example shows how to configure retry parameters for a single cache download task:

<!-- @[cache_download_with_retry](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/CacheDownload/entry/src/main/ets/pages/CacheDownloadRetry.ets)--> 

``` TypeScript
startCacheDownloadWithRetry(): void {
  this.downloadStatus = 'Downloading';
  this.errorMessage = '';
  logger.info(TAG, `Starting cache download with retry, url: ${this.downloadUrl}, maxRetryCount: ${this.maxRetryCount}`);

  // If the URL changes, re-register the callbacks.
  this.unregisterCallbacks();
  this.registerCallbacks();

  try {
    // Configure RetryOptions - new parameter in API 26.
    let retryOptions: cacheDownload.RetryOptions = {
      maxRetryCount: this.maxRetryCount  // Maximum number of retries. Range: 0-10. Default value: 1.
    };

    // Configure CacheDownloadOptions, including the retry parameter.
    let options: cacheDownload.CacheDownloadOptions = {
      retry: retryOptions
    };

    // Start the cache download task.
    cacheDownload.download(this.downloadUrl, options);
    logger.info(TAG, 'Cache download task started');
  } catch (err) {
    let error = err as BusinessError;
    logger.error(TAG, `Failed to start cache download, code: ${error.code}, message: ${error.message}`);
    this.downloadStatus = 'Failed';
    this.errorMessage = `BusinessError: ${error.code}, ${error.message}`;
  }
}
```

## Task-Level Timeout Policy Configuration

Starting from API version 26.0.0, developers can configure the timeout policy for a cache download task through [TimeoutOptions](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md#timeoutoptions) when creating the task.

The following example shows how to configure timeout parameters for a single cache download task:

<!-- @[cache_download_with_timeout](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/CacheDownload/entry/src/main/ets/pages/CacheDownloadTimeout.ets)--> 

``` TypeScript
startCacheDownloadWithTimeout(): void {
  this.downloadStatus = 'Downloading';
  this.errorMessage = '';
  logger.info(TAG, `Starting cache download with timeout, url: ${this.downloadUrl}`);
  logger.info(TAG, `networkCheckTimeout: ${this.networkCheckTimeout}s, httpTotalTimeout: ${this.httpTotalTimeout}s`);

  // Re-register the callbacks if the URL changes.
  this.unregisterCallbacks();
  this.registerCallbacks();

  try {
    let timeoutOptions: cacheDownload.TimeoutOptions = {
      networkCheckTimeout: this.networkCheckTimeout,
      httpTotalTimeout: this.httpTotalTimeout
    };

    let options: cacheDownload.CacheDownloadOptions = {
      timeout: timeoutOptions
    };

    cacheDownload.download(this.downloadUrl, options);
    logger.info(TAG, 'Cache download task started');
  } catch (err) {
    let error = err as BusinessError;
    logger.error(TAG, `Failed to start cache download, code: ${error.code}, message: ${error.message}`);
    this.downloadStatus = 'Failed';
    this.errorMessage = `BusinessError: ${error.code}, ${error.message}`;
  }
}
```

## Setting Global Retry Configuration

Starting from API version 26.0.0, developers can use [setGlobalRetryOptions](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md#cachedownloadsetglobalretryoptions) to set the global default retry configuration. This configuration applies to all cache download tasks that do not specify task-level retry parameters.

The following example shows how to set the global retry configuration:

<!-- @[set_global_retry_options](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/CacheDownload/entry/src/main/ets/pages/GlobalRetryOptions.ets)--> 

``` TypeScript
setGlobalRetryOptions(): void {
  logger.info(TAG, `Setting global retry options, maxRetryCount: ${this.globalMaxRetryCount}`);

  try {
    let globalRetryOptions: cacheDownload.RetryOptions = {
      maxRetryCount: this.globalMaxRetryCount
    };

    // Call setGlobalRetryOptions to set the global retry configuration.
    // This configuration applies to all cache download tasks that do not specify task-level retry.
    cacheDownload.setGlobalRetryOptions(globalRetryOptions);
      
    this.globalConfigStatus = `maxRetryCount = ${this.globalMaxRetryCount}`;
    logger.info(TAG, 'Global retry options set successfully');
    this.showToast($r('app.string.global_config_success'));
  } catch (err) {
    let error = err as BusinessError;
    logger.error(TAG, `Failed to set global retry options, code: ${error.code}, message: ${error.message}`);
    this.globalConfigStatus = 'Failed';
    this.showToast($r('app.string.global_config_failed'));
  }
}
```

## Global Timeout Configuration

Starting from API version 26.0.0, developers can set global default timeout options through the [setGlobalTimeoutOptions](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md#cachedownloadsetglobaltimeoutoptions) API. This configuration applies to all cache download tasks that do not specify task-level timeout parameters.

The following example shows how to set global timeout options:

<!-- @[set_global_timeout_options](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/CacheDownload/entry/src/main/ets/pages/GlobalTimeoutOptions.ets)--> 

``` TypeScript
setGlobalTimeoutOptions(): void {
  logger.info(TAG, `Setting global timeout options`);
  logger.info(TAG, `networkCheckTimeout: ${this.globalNetworkCheckTimeout}s, httpTotalTimeout: ${this.globalHttpTotalTimeout}s`);

  try {
    let globalTimeoutOptions: cacheDownload.TimeoutOptions = {
      networkCheckTimeout: this.globalNetworkCheckTimeout,
      httpTotalTimeout: this.globalHttpTotalTimeout
    };

    // Call setGlobalTimeoutOptions to set global timeout options.
    // This configuration applies to all cache download tasks that do not specify task-level timeout.
    cacheDownload.setGlobalTimeoutOptions(globalTimeoutOptions);
      
    this.globalConfigStatus = `networkCheckTimeout=${this.globalNetworkCheckTimeout}s, httpTotalTimeout=${this.globalHttpTotalTimeout}s`;
    logger.info(TAG, 'Global timeout options set successfully');
    this.showToast($r('app.string.global_config_success'));
  } catch (err) {
    let error = err as BusinessError;
    logger.error(TAG, `Failed to set global timeout options, code: ${error.code}, message: ${error.message}`);
    this.globalConfigStatus = 'Failed';
    this.showToast($r('app.string.global_config_failed'));
  }
}
```

## Registering Download Callback Listeners

Starting from API version 23, developers can register callback functions through the [onDownloadSuccess](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md#cachedownloadondownloadsuccess23) and [onDownloadError](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md#cachedownloadondownloaderror23) APIs to listen for download success and failure events.

> **NOTE**
>
> · Callback listeners are process-level and take effect for the entire app process.
>
> · Registering the same URL multiple times registers multiple callbacks, and all callbacks are triggered when the download completes.
>
> · When exiting a page, call [offDownloadSuccess](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md#cachedownloadoffdownloadsuccess23) and [offDownloadError](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md#cachedownloadoffdownloaderror23) to unregister callbacks and avoid memory leaks.

The basic usage of registering and unregistering callbacks is as follows:

<!-- @[cache_download_register_callbacks](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/CacheDownload/entry/src/main/ets/pages/CacheDownloadRetry.ets)--> 

``` TypeScript
// Register the callback listener (register only once within the page lifecycle).
private registerCallbacks(): void {
  this.successCallback = () => {
    logger.info(TAG, 'Cache download succeeded');
    this.downloadStatus = 'Success';
    this.showToast($r('app.string.download_success'));
  };

  this.errorCallback = (error: cacheDownload.DownloadError) => {
    logger.error(TAG, `Cache download failed, errorCode: ${error.errorCode}, message: ${error.message}`);
    this.downloadStatus = 'Failed';
    this.errorMessage = `Error: ${error.errorCode}, ${error.message}`;
    this.showToast($r('app.string.download_failed'));
  };

  // Register the callback using the current URL (initial URL).
  cacheDownload.onDownloadSuccess(this.downloadUrl, this.successCallback);
  cacheDownload.onDownloadError(this.downloadUrl, this.errorCallback);
}
```

<!-- --> 

<!-- @[cache_download_unregister_callbacks](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/CacheDownload/entry/src/main/ets/pages/CacheDownloadRetry.ets)--> 

``` TypeScript
// Unregister the callback listener.
private unregisterCallbacks(): void {
  cacheDownload.offDownloadSuccess(this.downloadUrl, this.successCallback);
  cacheDownload.offDownloadError(this.downloadUrl, this.errorCallback);
}
```

## Canceling a Cache Download Task

Developers can cancel an ongoing cache download task through the [cancel](../../reference/apis-basic-services-kit/js-apis-request-cacheDownload.md#cachedownloadcancel) API.

<!-- @[cache_download_cancel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/CacheDownload/entry/src/main/ets/pages/CacheDownloadRetry.ets)-->

``` TypeScript
cancelCacheDownload(): void {
  try {
    cacheDownload.cancel(this.downloadUrl);
    logger.info(TAG, 'Cache download task cancelled');
    this.downloadStatus = 'Cancelled';
    this.showToast($r('app.string.download_cancelled'));
  } catch (err) {
    let error = err as BusinessError;
    logger.error(TAG, `Failed to cancel, code: ${error.code}, message: ${error.message}`);
  }
}
```

## Related Permissions

The following permissions must be declared to use the Cache Download feature:

| Permission | Description |
|---|---|
| [ohos.permission.INTERNET](../../security/AccessToken/permissions-for-all.md#ohospermissioninternet) | Allows the app to access the network. This is a mandatory permission. |
| [ohos.permission.GET_NETWORK_INFO](../../security/AccessToken/permissions-for-all.md#ohospermissionget_network_info) | Allows the app to obtain network information. This permission is required when using the getDownloadInfo API to obtain download information or waiting to check network availability. |