# 应用文件上传下载
<!--Kit: Basic Services Kit-->
<!--Subsystem: Request-->
<!--Owner: @huaxin05-->
<!--Designer: @hu-kai45-->
<!--Tester: @murphy1984-->
<!--Adviser: @fang-jinxu-->

应用支持将文件上传到网络服务器，也支持从网络服务器下载资源文件到本地目录。

## 上传应用文件

开发者可以使用上传下载模块（[ohos.request](../../reference/apis-basic-services-kit/js-apis-request.md)）的上传接口将本地文件上传。文件上传过程通过系统服务代理完成。在API version 12中，`request.agent.create`接口增加了设置代理地址的参数，支持设置自定义代理地址。

> **说明：**
>
> · 当前上传应用文件功能，request.uploadFile方式仅支持上传应用缓存文件路径（cacheDir）下的文件，request.agent方式支持上传用户公共文件和应用缓存文件路径下的文件。
>
> · 使用上传下载模块，需[声明权限](../../security/AccessToken/declare-permissions.md)：ohos.permission.INTERNET。
>
> · 上传下载模块不支持Charles、Fiddler等代理抓包工具。
>
> · 上传下载模块接口目前暂不支持子线程调用场景，如[TaskPool](../../arkts-utils/taskpool-introduction.md)等。

以下示例代码展示了两种将缓存文件上传至服务器的方法：

<!-- @[request_upload_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/UploadDownloadGuide/features/uploadanddownload/src/main/ets/upload/RequestUpload.ets)-->

``` TypeScript
async requestUploadFile(fileName: string, callback: (progress: number, isSuccess: boolean) => void,
  context: common.UIAbilityContext) {
  // 获取应用文件路径
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let url = await urlUtils.getUrl(context);
  let cacheDir = context.cacheDir;

  // 新建一个本地应用文件
  try {
    let file = fileIo.openSync(cacheDir + '/test.txt', fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    fileIo.writeSync(file.fd, 'upload file test');
    fileIo.closeSync(file);
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    logger.error(TAG, `Invoke uploadFile failed, code=${err.code}, message=${err.message}`);
  }

  // 上传任务配置项
  let files: request.File[] = [
  // uri前缀internal://cache 对应cacheDir目录
    {
      filename: fileName,
      name: 'test',
      uri: 'internal://cache/' + fileName,
      type: 'txt'
    }
  ]
  let data: request.RequestData[] = [{ name: 'name', value: 'value' }];
  let uploadConfig: request.UploadConfig = {
    url: url,
    header: {
      'key1': 'value1',
      'key2': 'value2'
    },
    method: 'POST',
    files: files,
    data: data
  }

  // 将本地应用文件上传至网络服务器
  try {
    request.uploadFile(context, uploadConfig)
      .then((uploadTask: request.UploadTask) => {
        uploadTask.on('complete', (taskStates: Array<request.TaskState>) => {
          for (let i = 0; i < taskStates.length; i++) {
            logger.info(TAG, `upload complete taskState: ${JSON.stringify(taskStates[i])}`);
          }
          callback(100, true);
        });
      })
      .catch((err: BusinessError) => {
        logger.error(TAG, `Invoke uploadFile failed, code=${err.code}, message=${err.message}`);
      })
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    logger.error(TAG, `Invoke uploadFile failed, code=${err.code}, message=${err.message}`);
  }
}
```


<!-- @[upload_agent_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/UploadDownloadGuide/features/uploadanddownload/src/main/ets/upload/RequestUpload.ets)--> 

``` TypeScript
async requestAgentUpload(fileName: string, callback: (progress: number, isSucceed: boolean) => void,
  context: common.UIAbilityContext) {
  // 获取应用文件路径
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let url = await urlUtils.getUrl(context);
  let cacheDir = context.cacheDir;

  let attachments: request.agent.FormItem[] = [{
    name: 'test',
    value: [
      {
        filename: fileName,
        path: cacheDir + '/' + fileName,
      },
    ]
  }];
  let config: request.agent.Config = {
    action: request.agent.Action.UPLOAD,
    url: url,
    mode: request.agent.Mode.FOREGROUND,
    overwrite: true,
    method: 'POST',
    headers: {
      'key1': 'value1',
      'key2': 'value2'
    },
    data: attachments
  };
  request.agent.create(context, config).then((task: request.agent.Task) => {
    task.start((err: BusinessError) => {
      if (err) {
        logger.error(TAG, `Failed to start the upload task, code=${err.code}, message=${err.message}`);
        return;
      }
    });
    task.on('progress', async (progress) => {
      logger.info(TAG, `Request upload status ${progress.state}, uploaded ${progress.processed}`);
    })
    task.on('completed', async () => {
      logger.info(TAG, `Request upload completed`);
      callback(100, true);
      // 该方法需用户管理任务生命周期，任务结束后调用remove释放task对象
      request.agent.remove(task.tid);
    })
  }).catch((err: BusinessError) => {
    logger.error(TAG, `Failed to start the upload task, code=${err.code}, message=${err.message}`);
  });
}
```

## 下载网络资源文件至应用文件目录

开发者可以使用上传下载模块（[ohos.request](../../reference/apis-basic-services-kit/js-apis-request.md)）的下载接口将网络资源文件下载到应用文件目录。对已下载的网络资源应用文件，开发者可以使用基础文件IO接口（[ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md)）对其进行访问，使用方式与[应用文件访问](../../file-management/app-file-access.md)一致。文件下载过程使用系统服务代理完成，在api12中request.agent.create接口增加了设置代理地址参数，支持用户设置自定义代理地址。

> **说明：**
>
> 从API version 20开始支持下载网络资源文件到用户文件。
>
> 使用上传下载模块，需[声明权限](../../security/AccessToken/declare-permissions.md)：ohos.permission.INTERNET。
>
> 下载任务不会删除生成的文件，若需清理文件，需由开发者手动操作。

以下示例代码展示了将网络资源文件下载到应用内部文件目录的两种方法（示例requestDownloadFile中的clearExistFile方法可点击代码块右下角链接查看）：

<!-- @[request_download_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/UploadDownloadGuide/features/uploadanddownload/src/main/ets/download/RequestDownload.ets)-->

``` TypeScript
async requestDownloadFile(url: string, fileName: string, callback: (progress: number, isSuccess: boolean) => void,
  context: common.UIAbilityContext) {
  // 获取应用文件路径
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let filesDir = context.cacheDir;
  let filePath = filesDir + '/' + fileName;
  this.clearExistFile(filePath);
  try {
    await request.downloadFile(context, {
      url: url,
      filePath: filePath,
    }).then((downloadTask: request.DownloadTask) => {
      downloadTask.on('complete', () => {
        // 获取文件状态信息，其中包含大小
        let fileStat = fileIo.statSync(filePath);
        let fileSize = fileStat.size;
        logger.info(TAG, `download complete, file= ${url}, size=${fileSize}, progress = 100%`);
        callback(100, true);
      })
    }).catch((err: BusinessError) => {
      logger.error(TAG, `downloadFile error, code=${err.code}, message=${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    logger.error(TAG, `downloadFile catch error, code=${err.code}, message=${err.message}`);
  }
}
```

<!-- @[download_agent_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/UploadDownloadGuide/features/uploadanddownload/src/main/ets/download/RequestDownload.ets)-->

``` TypeScript
async requestAgentDownload(url: string, fileName: string, callback: (progress: number, isSuccess: boolean) => void,
  context: common.UIAbilityContext) {
  // 获取应用文件路径
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let filesDir = context.cacheDir;

  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: url,
    saveas: fileName,
    gauge: true,
    overwrite: true,
    network: request.agent.Network.WIFI,
  };
  await request.agent.create(context, config).then((task: request.agent.Task) => {
    task.start((error: BusinessError) => {
      if (error) {
        logger.error(TAG, `start agent download task error, code=${error.code}, message=${error.message}`);
        return;
      }
    });
    task.on('progress', async (progress) => {
      logger.info(TAG, `Request download status ${progress.state}, downloaded ${progress.processed}`);
    })
    task.on('completed', async () => {
      logger.info(TAG, `Request download completed`);
      let filePath = filesDir + '/' + fileName;
      // 获取文件状态信息，其中包含大小
      let fileStat = fileIo.statSync(filePath);
      let fileSize = fileStat.size;
      logger.info(TAG, `download complete, file= ${url}, size=${fileSize}, progress = 100%`);
      callback(100, true);
      request.agent.remove(task.tid);
    })
  }).catch((err: BusinessError) => {
    logger.error(TAG, `download agent task catch error, code=${err.code}, message=${err.message}`);
  });
}
```

## 下载网络资源文件至用户文件
开发者可以使用[ohos.request](../../reference/apis-basic-services-kit/js-apis-request.md)的[request.agent.create](../../reference/apis-basic-services-kit/js-apis-request.md#requestagentcreate10)接口下载网络资源文件到指定的用户文件目录。

> **说明：**
>
> 从API version 20开始支持下载网络资源文件到用户文件。
>
> 下载任务不会删除生成的文件，若需清理文件，需由开发者手动操作。

### 下载文档类文件

开发者可以通过调用[DocumentViewPicker](../../reference/apis-core-file-kit/js-apis-file-picker.md#documentviewpicker)的[save()](../../reference/apis-core-file-kit/js-apis-file-picker.md#save)接口保存文件并获得用户文件的uri，将此uri作为[Config](../../reference/apis-basic-services-kit/js-apis-request.md#requestagentconfig10)的saveas字段值进行下载。

<!-- @[doc_user_file_download](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/UploadDownloadGuide/features/uploadanddownload/src/main/ets/download/userFile/DocumentDownload.ets)-->

``` TypeScript
async docFileAgentTask(url: string, fileName: string, callback: (progress: number, isSuccess: boolean) => void,
  context: common.UIAbilityContext) {
  // 创建文件管理器选项实例。
  try {
    const documentSaveOptions = new picker.DocumentSaveOptions();
    // 保存文件名（可选）。 默认为空。
    documentSaveOptions.newFileNames = [fileName];
    // 保存文件类型['后缀类型描述|后缀类型']，选择所有文件：'所有文件(*.*)|.*'（可选），如果选择项存在多个后缀（最大限制100个过滤后缀），默认选择第一个。如果不传该参数，默认无过滤后缀。
    documentSaveOptions.fileSuffixChoices = ['文档|.txt', '.pdf'];
    let uri: string = '';
    // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
    const documentViewPicker = new picker.DocumentViewPicker(context);
    await documentViewPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
      uri = documentSaveResult[0];
      logger.info(TAG, `DocumentViewPicker.save to file succeed and uri is ${uri}`);
    }).catch((err: BusinessError) => {
      logger.error(TAG, `documentViewPicker.save error, code=${err.code}, message=${err.message}`);
    })
    if (uri != '') {
      let config: request.agent.Config = {
        action: request.agent.Action.DOWNLOAD,
        url: url,
        // saveas字段是DocumentViewPicker保存的文件的uri
        saveas: uri,
        gauge: true,
        // overwrite字段必须为true
        overwrite: true,
        network: request.agent.Network.WIFI,
        // mode字段必须为request.agent.Mode.FOREGROUND
        mode: request.agent.Mode.FOREGROUND,
      };
      try {
        await request.agent.create(context, config).then((task: request.agent.Task) => {
          task.start((err: BusinessError) => {
            if (err) {
              logger.error(TAG, `start download task error, code=${err.code}, message=${err.message}`);
              return;
            }
          });
          task.on('progress', async (progress) => {
            logger.info(TAG, `download status ${progress.state}, downloaded ${progress.processed}`);
          })
          task.on('completed', async (progress) => {
            logger.info(TAG, `download completed ${JSON.stringify(progress)}`);
            callback(100, true);
            // 该方法需用户管理任务生命周期，任务结束后调用remove释放task对象
            request.agent.remove(task.tid);
          })
        }).catch((err: BusinessError) => {
          logger.error(TAG, `Failed to operate a download task, Code: ${err.code}, message: ${err.message}`);
        });
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        logger.error(TAG, `Failed to create a download task, code=${err.code}, message=${err.message}`);
      }
    }
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    logger.error(TAG, `Failed to create a documentSaveOptions, code=${err.code}, message=${err.message}`);
    return;
  }
}
```

### 下载音频类文件

开发者可以通过调用[AudioViewPicker](../../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker)的[save()](../../reference/apis-core-file-kit/js-apis-file-picker.md#save-3)接口保存文件并获得用户文件的uri，将此uri作为[Config](../../reference/apis-basic-services-kit/js-apis-request.md#requestagentconfig10)的saveas字段值进行下载。

<!-- @[audio_user_file_download](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/UploadDownloadGuide/features/uploadanddownload/src/main/ets/download/userFile/AudioDownload.ets)-->

``` TypeScript
async audioFileAgentTask(url: string, fileName: string, callback: (progress: number, isSuccess: boolean) => void,
  context: common.UIAbilityContext) {
  // 创建文件管理器选项实例。
  const audioSaveOptions = new picker.AudioSaveOptions();
  // 保存文件名（可选）。 默认为空。
  audioSaveOptions.newFileNames = [fileName];

  let uri: string = '';
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  const audioViewPicker = new picker.AudioViewPicker(context);
  await audioViewPicker.save(audioSaveOptions).then((audioSelectResult: Array<string>) => {
    uri = audioSelectResult[0];
    logger.info(TAG, `AudioViewPicker.save to file succeed and uri is ${uri}`);
  }).catch((err: BusinessError) => {
    logger.error(TAG, `Invoke audioViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
  })
  if (uri != '') {
    let config: request.agent.Config = {
      action: request.agent.Action.DOWNLOAD,
      url: url,
      // saveas字段是AudioViewPicker保存的文件的uri
      saveas: uri,
      gauge: true,
      // overwrite字段必须为true
      overwrite: true,
      network: request.agent.Network.WIFI,
      // mode字段必须为request.agent.Mode.FOREGROUND
      mode: request.agent.Mode.FOREGROUND,
    };
    try {
      request.agent.create(context, config).then((task: request.agent.Task) => {
        task.start((err: BusinessError) => {
          if (err) {
            logger.error(TAG, `Failed to start the download task, Code: ${err.code}  message: ${err.message}`);
            return;
          }
        });
        task.on('progress', async (progress) => {
          logger.info(TAG, `Request download status ${progress.state}, downloaded ${progress.processed}`);
        })
        task.on('completed', async (progress) => {
          logger.info(TAG, `Request download completed, ${JSON.stringify(progress)}`);
          callback(100, true);
          // 该方法需用户管理任务生命周期，任务结束后调用remove释放task对象.
          request.agent.remove(task.tid);
        })
      }).catch((err: BusinessError) => {
        logger.error(TAG, `Failed to create a download task, code=${err.code}, message=${err.message}`);
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      logger.error(TAG, `Failed to create a audio download task, code=${err.code}, message=${err.message}`);
    }
  }
}
```


### 下载图片或视频类文件

开发者可以通过调用PhotoAccessHelper[模块描述](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper.md)的[createAsset()](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#createasset-2)接口创建媒体文件并获取用户文件的URI，将其作为[Config](../../reference/apis-basic-services-kit/js-apis-request.md#requestagentconfig10)的saveas字段值进行下载。

需要权限：[ohos.permission.WRITE_IMAGEVIDEO](../../security/AccessToken/restricted-permissions.md#ohospermissionwrite_imagevideo)

权限[ohos.permission.WRITE_IMAGEVIDEO](../../security/AccessToken/restricted-permissions.md#ohospermissionwrite_imagevideo)是[权限机制中的基本概念](../../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)中system_basic(系统基础服务)级别的[受限开放权限](../../security/AccessToken/restricted-permissions.md)，normal等级的应用需要将自身的APL等级声明为system_basic及以上。授权方式为user_grant，需要[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

<!-- @[media_user_file_download](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/UploadDownloadGuide/features/uploadanddownload/src/main/ets/download/userFile/MediaDownload.ets)--> 

``` TypeScript
async mediaFileAgentTask(url: string, callback: (progress: number, isSuccess: boolean) => void,
  context: common.UIAbilityContext) {
  let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION |
  bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_METADATA;
  // 获取应用程序的accessTokenID。
  let tokenID = -1;
  try {
    await bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
      logger.info(TAG, `Request getBundleInfoForSelf successfully. Data: ${JSON.stringify(data)}`);
      tokenID = data.appInfo.accessTokenId;
    }).catch((err: BusinessError) => {
      logger.error(TAG, `GetBundleInfoForSelf failed, code=${err.code}, message=${err.message}`);
    });
  } catch (err) {
    let message = (err as BusinessError).message;
    logger.error(`GetBundleInfoForSelf failed: ${message}`);
  }

  let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
  let grant = true;
  // 校验应用是否授予权限。使用Promise异步回调。
  await atManager.checkAccessToken(tokenID, 'ohos.permission.WRITE_IMAGEVIDEO')
    .then((data: abilityAccessCtrl.GrantStatus) => {
      logger.info(TAG, `Request checkAccessToken success, data->${JSON.stringify(data)}`);
      if (data != abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
        grant = false;
      }
    })
    .catch((err: BusinessError) => {
      logger.error(TAG, `CheckAccessToken fail, code=${err.code}, message=${err.message}`);
    });

  if (!grant) {
    // 用于UIAbility拉起弹框请求用户授权。使用callback异步回调。
    await atManager.requestPermissionsFromUser(context, ['ohos.permission.WRITE_IMAGEVIDEO'])
      .then((data: PermissionRequestResult) => {
        logger.info(TAG, `Request grant: ${JSON.stringify(data)}`);
        logger.info(TAG, `Request grant permissions: ${data.permissions}`);
        logger.info(TAG, `Request grant authResults: ${data.authResults}`);
        logger.info(TAG, `Request grant dialogShownResults: ${data.dialogShownResults}`);
      }).catch((err: BusinessError) => {
        logger.error(TAG, `Grant error, code=${err.code}, message=${err.message}`);
      });
  }

  try {
    let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
    let extension: string = 'jpg';
    let options: photoAccessHelper.CreateOptions = {
      title: 'media'
    }
    // 获取相册管理模块的实例，用于访问和修改相册中的媒体文件。
    let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    // 指定文件类型、后缀和创建选项，创建图片或视频资源，以Promise方式返回结果。
    let uri: string = await phAccessHelper.createAsset(photoType, extension, options);
    logger.info(TAG, `Request createAsset uri ${uri}`);

    let config: request.agent.Config = {
      action: request.agent.Action.DOWNLOAD,
      url: url,
      // saveas字段是PhotoAccessHelper保存的文件的uri
      saveas: uri,
      gauge: true,
      // overwrite字段必须为true
      overwrite: true,
      network: request.agent.Network.WIFI,
      // mode字段必须为request.agent.Mode.FOREGROUND
      mode: request.agent.Mode.FOREGROUND,
    };
    request.agent.create(context, config).then((task: request.agent.Task) => {
      task.start((err: BusinessError) => {
        if (err) {
          logger.error(TAG, `Failed to start the download task, Code: ${err.code}  message: ${err.message}`);
          return;
        }
      });
      task.on('progress', async (progress) => {
        logger.info(TAG, `Request download status ${progress.state}, downloaded ${progress.processed}`);
      })
      task.on('completed', async (progress) => {
        logger.info(TAG, `Request download completed, ${JSON.stringify(progress)}`);
        callback(100, true);
        // 该方法需用户管理任务生命周期，任务结束后调用remove释放task对象
        request.agent.remove(task.tid);
      })
    }).catch((err: BusinessError) => {
      logger.error(TAG, `Failed to operate a download task, Code: ${err.code}, message: ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    logger.error(TAG, `Failed to create a media download task, code=${err.code}, message=${err.message}`);
  }
}
```


## 添加任务速度限制与超时限制

开发者可以使用[ohos.request (上传下载)](../../reference/apis-basic-services-kit/js-apis-request.md)模块中的接口上传本地文件或下载网络资源文件。为方便对任务速度及时长进行限制，分别在API version 18中增加了[setMaxSpeed](../../reference/apis-basic-services-kit/js-apis-request.md#setmaxspeed18)接口，支持用户设置任务的最高速度限制；在API version 20的[request.agent.create](../../reference/apis-basic-services-kit/js-apis-request.md#requestagentcreate10-1)接口中增加了最低限速及超时参数，支持用户自定义最低速度限制以及超时时间。

以下是对下载任务进行速度限制与超时限制的方式的示例代码演示：

<!-- @[speed_limit_download](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/UploadDownloadGuide/features/uploadanddownload/src/main/ets/download/SpeedLimitDownload.ets)--> 

``` TypeScript
async speedLimitDownload(url: string, fileName: string, callback: (progress: number, isSuccess: boolean) => void,
  context: common.UIAbilityContext) {
  // 获取应用文件路径
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
  let filesDir = context.cacheDir;

  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: url,
    saveas: fileName,
    gauge: true,
    overwrite: true,
    network: request.agent.Network.WIFI,
    // 最低速度限制规则：
    // 1. 若任务速度持续低于设定值（如：16 * 1024 B/s）达到指定时长（如：10s），则任务失败
    // 2. 重置计时条件：
    // - 任一秒速度超过最低限速
    // - 任务暂停后恢复
    // - 任务停止后重启
    minSpeed: {
      speed: 16 * 1024,
      duration: 10
    },
    // 超时控制规则：
    // 1. 连接超时（connectionTimeout）：
    // - 单次连接建立耗时超过设定值（如：60s）则任务失败
    // - 多次连接时各次独立计时（不累积）
    // 2. 总超时（totalTimeout）：
    // - 任务总耗时（含连接+传输时间）超过设定值（如：120s）则失败
    // - 暂停期间不计时，恢复后累积计时
    // 3. 重置计时条件：任务失败或停止时重置计时
    timeout: {
      connectionTimeout: 60,
      totalTimeout: 120,
    }
  };
  request.agent.create(context, config).then((task: request.agent.Task) => {
    // 设置任务速度上限
    task.setMaxSpeed(10 * 1024 * 1024).then(() => {
      logger.info(TAG, `Succeeded in setting the max speed of the task. result: ${task.tid}`);
    }).catch((err: BusinessError) => {
      logger.error(TAG, `Failed to set the max speed of the task, code=${err.code}, message=${err.message}`);
    });
    task.start((err: BusinessError) => {
      if (err) {
        logger.error(TAG, `Failed to start the download task, code=${err.code}, message=${err.message}`);
        return;
      }
    });
    task.on('progress', async (progress) => {
      logger.info(TAG, `Request download status ${progress.state}, downloaded ${progress.processed}`);
    })
    task.on('completed', async () => {
      logger.info(TAG, `Request download completed`);
      // 获取文件状态信息，其中包含大小
      let filePath = filesDir + '/' + fileName;
      // 获取文件状态信息，其中包含大小
      let fileStat = fileIo.statSync(filePath);
      let fileSize = fileStat.size;
      logger.info(TAG, `download complete, file= ${url}, size=${fileSize}, progress = 100%`);
      callback(100, true);
      request.agent.remove(task.tid);
    })
  }).catch((err: BusinessError) => {
    logger.error(TAG, `Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
  });
}
```


## 添加网络配置

### HTTP拦截

开发者可以通过设置配置文件实现HTTP拦截功能。上传下载模块在应用配置文件中禁用HTTP后，无法创建明文HTTP传输的上传下载任务。配置文件在APP中的路径是：`src/main/resources/base/profile/network_config.json`。请参考网络管理模块配置文件[网络连接安全配置](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/network-connection-security-configuration)，了解需要配置的具体参数。

参考配置文件如下所示：

```ts
{
  "network-security-config": {
    "base-config": {
      "cleartextTrafficPermitted": true, 
      "trust-anchors": [
        {
          "certificates": "/etc/security/certificates"
        }
      ]
    },
    "domain-config": [
      {
        "cleartextTrafficPermitted": true,
        "domains": [
          {
            "include-subdomains": true,
            "name": "*.example.com"
          }
        ]
      }
    ]
  }
}
```

## 使用WantAgent实现通知栏跳转功能

从API version 22开始，开发者可以使用[wantAgent](../../reference/apis-ability-kit/js-apis-app-ability-wantAgent.md)接口与上传下载模块结合，实现点击任务通知后跳转至应用指定页面的功能。

### 功能介绍

通过在下载任务的配置[request.agent.Notification](../../reference/apis-basic-services-kit/js-apis-request.md#requestagentnotification15)中设置wantAgent参数，开发者可以指定用户点击通知后要跳转的应用页面及相关参数。当用户点击正在进行或已完成的下载任务通知时，系统会根据wantAgent参数启动指定的应用能力。

### 示例代码

以下示例代码展示了如何创建一个带有wantAgent功能的下载任务：

<!-- @[want_agent_download](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Basic-Services-Kit/request/UploadDownloadGuide/features/uploadanddownload/src/main/ets/download/WantAgentDownload.ets)-->

``` TypeScript
async wantAgentDownload(url: string, fileName: string, callback: (progress: number, isSuccess: boolean) => void,
  context: common.UIAbilityContext) {
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext

  // 创建wantAgentInfo对象，用于定义点击通知后要执行的操作
  let wantAgentInfo: wantAgent.WantAgentInfo = {
    wants: [
      {
        deviceId: '',
        bundleName: 'com.samples.uploaddownloadguide', // 替换为实际应用的包名
        abilityName: 'EntryAbility', // 替换为实际的ability名称
        action: '',
        entities: [],
        uri: '',
        parameters: {} // 可以传递自定义参数
      }
    ],
    actionType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.CONSTANT_FLAG]
  };

  // 获取WantAgent实例
  let wantAgentInstance: WantAgent;
  try {
    wantAgentInstance = await wantAgent.getWantAgent(wantAgentInfo);
  } catch (error) {
    logger.error(TAG, `Failed to get WantAgent, Code: ${error.code}  message: ${error.message}`);
    return;
  }

  let filesDir = context.cacheDir;
  // 创建下载任务配置，包含wantAgent参数
  let config: request.agent.Config = {
    action: request.agent.Action.DOWNLOAD,
    url: url, // 替换为实际的下载地址
    title: '下载任务通知标题',
    description: '下载任务通知描述',
    mode: request.agent.Mode.BACKGROUND,
    overwrite: true,
    method: 'GET',
    saveas: fileName,
    network: request.agent.Network.ANY,
    gauge: true,
    notification: {
      visibility: request.agent.VISIBILITY_COMPLETION | request.agent.VISIBILITY_PROGRESS,
      wantAgent: wantAgentInstance,
    }
  };

  // 创建并启动下载任务
  try {
    request.agent.create(context, config).then((task: request.agent.Task) => {
      task.start((err: BusinessError) => {
        if (err) {
          logger.error(TAG, `Failed to start the download task, Code: ${err.code}  message: ${err.message}`);
          return;
        }
      });
      task.on('progress', async (progress) => {
        logger.error(TAG, `Request download status ${progress.state}, downloaded ${progress.processed}`);
      })
      task.on('completed', async (progress) => {
        logger.info(TAG, `Request download completed, ${JSON.stringify(progress)}`);
        // 获取文件状态信息，其中包含大小
        let filePath = filesDir + '/' + fileName;
        // 获取文件状态信息，其中包含大小
        let fileStat = fileIo.statSync(filePath);
        let fileSize = fileStat.size;
        logger.info(TAG, `download complete, file= ${url}, size=${fileSize}, progress = 100%`);
        callback(100, true);
        // 该方法需用户管理任务生命周期，任务结束后调用remove释放task对象
        request.agent.remove(task.tid);
      })
    }).catch((err: BusinessError) => {
      logger.error(TAG, `Failed to operate a download task, Code: ${err.code}, message: ${err.message}`);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    logger.error(TAG, `Failed to operate a download task, Code: ${err.code}, message: ${err.message}`);
  }
}
```


### 配置说明

在上面的示例代码中，我们主要通过以下几个步骤实现了通知栏跳转功能：

1. **创建WantAgentInfo对象**：定义点击通知后要执行的操作，包括目标应用的包名、ability名称和需要传递的具体参数。

2. **获取WantAgent实例**：通过`wantAgent.getWantAgent()`方法获取WantAgent实例。

3. **配置下载任务**：在`request.agent.Config`中设置`notification`属性，并将`wantAgent`参数设置为前面获取的WantAgent实例。

4. **设置通知可见性**：通过`visibility`参数可以控制通知显示的内容，例如进度、完成状态等。

### 注意事项

- 此功能仅支持API version 22及以上版本。
- 确保在配置`wantAgentInfo`时，填写正确的应用包名和ability名称。
- `wantAgent`参数需要与`notification`参数配合使用，才能在通知中显示跳转功能。
- 在实际应用中，建议根据业务需求调整通知的标题、描述、可见性以及其他相关参数。

