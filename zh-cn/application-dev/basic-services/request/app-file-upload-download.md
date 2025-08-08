# 应用文件上传下载
<!--Kit: Basic Services Kit-->
<!--Subsystem: Request-->
<!--Owner: @huaxin05-->
<!--SE: @hu-kai45-->
<!--TSE: @murphy1984-->

应用支持将文件上传到网络服务器，也支持从网络服务器下载资源文件到本地目录。

## 上传应用文件

开发者可以使用上传下载模块（[ohos.request](../../reference/apis-basic-services-kit/js-apis-request.md)）的上传接口将本地文件上传。文件上传过程通过系统服务代理完成。在api12中，`request.agent.create`接口增加了设置代理地址的参数，支持设置自定义代理地址。

> **说明：**
>
> · 当前上传应用文件功能。request.uploadFile方式仅支持上传应用缓存文件路径（cacheDir）下的文件，request.agent方式支持上传用户公共文件和应用缓存文件路径下的文件。
>
> · 使用上传下载模块，需[声明权限](../../security/AccessToken/declare-permissions.md)：ohos.permission.INTERNET。
>
> · 上传下载模块不支持Charles、Fiddler等代理抓包工具。
>
> · 上传下载模块接口目前暂不支持子线程调用场景，如[TaskPool](../../arkts-utils/taskpool-introduction.md)等。

以下示例代码展示了两种将缓存文件上传至服务器的方法：

```ts
// 方式一:request.uploadFile
// pages/xxx.ets
import { common } from '@kit.AbilityKit';
import fs from '@ohos.file.fs';
import { BusinessError, request } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("上传").onClick(() => {
          // 获取应用文件路径
          // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
          let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
          let cacheDir = context.cacheDir;

          // 新建一个本地应用文件
          try {
            let file = fs.openSync(cacheDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
            fs.writeSync(file.fd, 'upload file test');
            fs.closeSync(file);
          } catch (error) {
            let err: BusinessError = error as BusinessError;
            console.error(`Invoke uploadFile failed, code is ${err.code}, message is ${err.message}`);
          }

          // 上传任务配置项
          let files: Array<request.File> = [
          //uri前缀internal://cache 对应cacheDir目录
            { filename: 'test.txt', name: 'test', uri: 'internal://cache/test.txt', type: 'txt' }
          ]
          let data: Array<request.RequestData> = [{ name: 'name', value: 'value' }];
          let uploadConfig: request.UploadConfig = {
            url: 'https://xxx',
            header: {
              'key1':'value1',
              'key2':'value2'
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
                    console.info(`upload complete taskState: ${JSON.stringify(taskStates[i])}`);
                  }
                });
              })
              .catch((err: BusinessError) => {
                console.error(`Invoke uploadFile failed, code is ${err.code}, message is ${err.message}`);
              })
          } catch (error) {
            let err: BusinessError = error as BusinessError;
            console.error(`Invoke uploadFile failed, code is ${err.code}, message is ${err.message}`);
          }
        })
      }
    }
  }
}
```

```ts
// 方式二:request.agent
// pages/xxx.ets
import { common } from '@kit.AbilityKit';
import fs from '@ohos.file.fs';
import { BusinessError, request } from '@kit.BasicServicesKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("上传").onClick(() => {
          // 获取应用文件路径
          // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
          let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
          let cacheDir = context.cacheDir;

          // 新建一个本地应用文件
          let file = fs.openSync(cacheDir + '/test.txt', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
          fs.writeSync(file.fd, 'upload file test');
          fs.closeSync(file);
          let attachments: Array<request.agent.FormItem> = [{
            name: "test",
            value: [
              {
                filename: "test.txt",
                path: cacheDir + '/test.txt',
              },
            ]
          }];
          let config: request.agent.Config = {
            action: request.agent.Action.UPLOAD,
            url: 'http://xxx',
            mode: request.agent.Mode.FOREGROUND,
            overwrite: true,
            method: "POST",
            headers: {
              'key1':'value1',
              'key2':'value2'
            },
            data: attachments
          };
          request.agent.create(context, config).then((task: request.agent.Task) => {
            task.start((err: BusinessError) => {
              if (err) {
                console.error(`Failed to start the upload task, Code: ${err.code}  message: ${err.message}`);
                return;
              }
            });
            task.on('progress', async(progress) => {
              console.warn(`/Request upload status ${progress.state}, uploaded ${progress.processed}`);
            })
            task.on('completed', async() => {
              console.warn(`/Request upload completed`);
              //该方法需用户管理任务生命周期，任务结束后调用remove释放task对象
              request.agent.remove(task.tid);
            })
          }).catch((err: BusinessError) => {
            console.error(`Failed to create a upload task, Code: ${err.code}, message: ${err.message}`);
          });
        })
      }
    }
  }
}

```

## 下载网络资源文件至应用文件目录

开发者可以使用上传下载模块（[ohos.request](../../reference/apis-basic-services-kit/js-apis-request.md)）的下载接口将网络资源文件下载到应用文件目录。对已下载的网络资源应用文件，开发者可以使用基础文件IO接口（[ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md)）对其进行访问，使用方式与[应用文件访问](../../file-management/app-file-access.md)一致。文件下载过程使用系统服务代理完成，在api12中request.agent.create接口增加了设置代理地址参数，支持用户设置自定义代理地址。

> **说明：**
>
> 当前网络资源文件仅支持下载至应用文件目录。
>
> 使用上传下载模块，需[声明权限](../../security/AccessToken/declare-permissions.md)：ohos.permission.INTERNET。

以下示例代码展示了将网络资源文件下载到应用内部文件目录的两种方法：

```ts
// 方式一:request.downloadFile
// pages/xxx.ets
// 将网络资源文件下载到应用文件目录并读取一段内容
import { common } from '@kit.AbilityKit';
import fs from '@ohos.file.fs';
import { BusinessError, request } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("下载").onClick(() => {
          // 获取应用文件路径
          // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
          let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
          let filesDir = context.filesDir;

          try {
            request.downloadFile(context, {
              url: 'https://xxxx/xxxx.txt',
              filePath: filesDir + '/xxxx.txt'
            }).then((downloadTask: request.DownloadTask) => {
              downloadTask.on('complete', () => {
                console.info('download complete');
                let file = fs.openSync(filesDir + '/xxxx.txt', fs.OpenMode.READ_WRITE);
                let arrayBuffer = new ArrayBuffer(1024);
                let readLen = fs.readSync(file.fd, arrayBuffer);
                let buf = buffer.from(arrayBuffer, 0, readLen);
                console.info(`The content of file: ${buf.toString()}`);
                fs.closeSync(file);
              })
            }).catch((err: BusinessError) => {
              console.error(`Invoke downloadTask failed, code is ${err.code}, message is ${err.message}`);
            });
          } catch (error) {
            let err: BusinessError = error as BusinessError;
            console.error(`Invoke downloadFile failed, code is ${err.code}, message is ${err.message}`);
          }
        })
      }
    }
  }
}
```
```ts
// 方式二:request.agent
// pages/xxx.ets
// 将网络资源文件下载到应用文件目录并读取一段内容
import { common } from '@kit.AbilityKit';
import fs from '@ohos.file.fs';
import { BusinessError, request } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("下载").onClick(() => {
          // 获取应用文件路径
          // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
          let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
          let filesDir = context.filesDir;

          let config: request.agent.Config = {
            action: request.agent.Action.DOWNLOAD,
            url: 'https://xxxx/test.txt',
            saveas: 'xxxx.txt',
            gauge: true,
            overwrite: true,
            network: request.agent.Network.WIFI,
          };
          request.agent.create(context, config).then((task: request.agent.Task) => {
            task.start((err: BusinessError) => {
              if (err) {
                console.error(`Failed to start the download task, Code: ${err.code}  message: ${err.message}`);
                return;
              }
            });
            task.on('progress', async (progress) => {
              console.warn(`/Request download status ${progress.state}, downloaded ${progress.processed}`);
            })
            task.on('completed', async () => {
              console.warn(`/Request download completed`);
              let file = fs.openSync(filesDir + '/xxxx.txt', fs.OpenMode.READ_WRITE);
              let arrayBuffer = new ArrayBuffer(1024);
              let readLen = fs.readSync(file.fd, arrayBuffer);
              let buf = buffer.from(arrayBuffer, 0, readLen);
              console.info(`The content of file: ${buf.toString()}`);
              fs.closeSync(file);
              //该方法需用户管理任务生命周期，任务结束后调用remove释放task对象
              request.agent.remove(task.tid);
            })
          }).catch((err: BusinessError) => {
            console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
          });
        })
      }
    }
  }
}

```

## 下载网络资源文件至用户文件
开发者可以使用[ohos.request](../../reference/apis-basic-services-kit/js-apis-request.md)的[request.agent](../../reference/apis-basic-services-kit/js-apis-request.md#requestagentcreate10)接口下载网络资源文件到指定的用户文件目录。

> **说明：**
>
> 从API version 20开始支持下载网络资源文件至用户文件。

### 下载文档类文件

开发者可以通过调用[DocumentViewPicker](../../reference/apis-core-file-kit/js-apis-file-picker.md#documentviewpicker)的[save()](../../reference/apis-core-file-kit/js-apis-file-picker.md#save)接口保存文件并获得用户文件的uri，将此uri作为[Config](../../reference/apis-basic-services-kit/js-apis-request.md#config10)的saveas字段值进行下载。

```ts
import { BusinessError, request } from '@kit.BasicServicesKit';
import { picker } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("下载文档").width("50%").margin({ top: 20 }).height(40).onClick(async () => {

          // 创建文件管理器选项实例。
          try {
            const documentSaveOptions = new picker.DocumentSaveOptions();
            // 保存文件名（可选）。 默认为空。
            documentSaveOptions.newFileNames = ["xxxx.txt"];
            // 保存文件类型['后缀类型描述|后缀类型']，选择所有文件：'所有文件(*.*)|.*'（可选），如果选择项存在多个后缀（最大限制100个过滤后缀），默认选择第一个。如果不传该参数，默认无过滤后缀。
            documentSaveOptions.fileSuffixChoices = ['文档|.txt', '.pdf'];
            let uri: string = '';
            // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
            let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            const documentViewPicker = new picker.DocumentViewPicker(context);
            await documentViewPicker.save(documentSaveOptions).then((documentSaveResult: Array<string>) => {
              uri = documentSaveResult[0];
              console.info('DocumentViewPicker.save to file succeed and uri is:' + uri);
            }).catch((err: BusinessError) => {
              console.error(`Invoke documentViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
            })
            if (uri != '') {
              let config: request.agent.Config = {
                action: request.agent.Action.DOWNLOAD,
                url: 'https://xxxx/xxxx.txt',
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
                request.agent.create(context, config).then((task: request.agent.Task) => {
                  task.start((err: BusinessError) => {
                    if (err) {
                      console.error(`Failed to start the download task, Code: ${err.code}  message: ${err.message}`);
                      return;
                    }
                  });
                  task.on('progress', async (progress) => {
                    console.warn(`Request download status ${progress.state}, downloaded ${progress.processed}`);
                  })
                  task.on('completed', async (progress) => {
                    console.warn('Request download completed, ' + JSON.stringify(progress));
                    // 该方法需用户管理任务生命周期，任务结束后调用remove释放task对象
                    request.agent.remove(task.tid);
                  })
                }).catch((err: BusinessError) => {
                  console.error(`Failed to operate a download task, Code: ${err.code}, message: ${err.message}`);
                });
              } catch (err) {
                console.error(`Failed to create a download task, err: ${err}`);
              }
            }
          } catch (err) {
            console.error(`Failed to create a documentSaveOptions, err: ${err}`);
            return;
          }
        })
      }
    }
  }
}
```

### 下载音频类文件

开发者可以通过调用[AudioViewPicker](../../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker)的[save()](../../reference/apis-core-file-kit/js-apis-file-picker.md#save-3)接口保存文件并获得用户文件的uri，将此uri作为[Config](../../reference/apis-basic-services-kit/js-apis-request.md#config10)的saveas字段值进行下载。

```ts
import { BusinessError, request } from '@kit.BasicServicesKit';
import { picker } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("下载音频").width("50%").margin({ top: 20 }).height(40).onClick(async () => {
          // 创建文件管理器选项实例。
          const audioSaveOptions = new picker.AudioSaveOptions();
          // 保存文件名（可选）。 默认为空。
          audioSaveOptions.newFileNames = ['xxxx.mp3'];

          let uri: string = '';
          // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
          let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
          const audioViewPicker = new picker.AudioViewPicker(context);
          await audioViewPicker.save(audioSaveOptions).then((audioSelectResult: Array<string>) => {
            uri = audioSelectResult[0];
            console.info('AudioViewPicker.save to file succeed and uri is:' + uri);
          }).catch((err: BusinessError) => {
            console.error(`Invoke audioViewPicker.save failed, code is ${err.code}, message is ${err.message}`);
          })
          if (uri != '') {
            let config: request.agent.Config = {
              action: request.agent.Action.DOWNLOAD,
              url: 'https://xxxx/xxxx.mp3',
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
                    console.error(`Failed to start the download task, Code: ${err.code}  message: ${err.message}`);
                    return;
                  }
                });
                task.on('progress', async (progress) => {
                  console.warn(`Request download status ${progress.state}, downloaded ${progress.processed}`);
                })
                task.on('completed', async (progress) => {
                  console.warn('Request download completed, ' + JSON.stringify(progress));
                  // 该方法需用户管理任务生命周期，任务结束后调用remove释放task对象
                  request.agent.remove(task.tid);
                })
              }).catch((err: BusinessError) => {
                console.error(`Failed to operate a download task, Code: ${err.code}, message: ${err.message}`);
              });
            } catch (err) {
              console.error(`Failed to create a download task, err: ${err}`);
            }
          }
        })
      }
    }
  }
}
```

### 下载图片或视频类文件

开发者可以通过调用[PhotoAccessHelper](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper.md)的[createAsset()](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#createasset-2)接口创建媒体文件并获取用户文件的URI，将其作为[Config](../../reference/apis-basic-services-kit/js-apis-request.md#config10)的saveas字段值进行下载。

需要权限：[ohos.permission.WRITE_IMAGEVIDEO](../../security/AccessToken/permissions-for-all-user.md#ohospermissionwrite_media)

权限[ohos.permission.WRITE_IMAGEVIDEO](../../security/AccessToken/permissions-for-all-user.md#ohospermissionwrite_media)是[system_basic](../../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)级别的[受限开放权限](../../security/AccessToken/restricted-permissions.md)，normal等级的应用需要将自身的APL等级声明为system_basic及以上。授权方式为user_grant，需要[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

```ts
import { BusinessError, request } from '@kit.BasicServicesKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

import { bundleManager } from '@kit.AbilityKit';
import { abilityAccessCtrl, Context, PermissionRequestResult, common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        Button("下载图片").width("50%").margin({ top: 20 }).height(40).onClick(async () => {
          let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION |
          bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_METADATA;
          // 获取应用程序的accessTokenID。
          let tokenID = -1;
          try {
            await bundleManager.getBundleInfoForSelf(bundleFlags).then((data) => {
              console.info(`/Request getBundleInfoForSelf successfully. Data: ${JSON.stringify(data)}`);
              tokenID = data.appInfo.accessTokenId;
            }).catch((err: BusinessError) => {
              console.error(`GetBundleInfoForSelf failed. Cause: ${err.message}`);
            });
          } catch (err) {
            let message = (err as BusinessError).message;
            console.error('GetBundleInfoForSelf failed: %{public}s', message);
          }
          let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

          let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
          let grant = true;
          // 校验应用是否授予权限。使用Promise异步回调。
          await atManager.checkAccessToken(tokenID, 'ohos.permission.WRITE_IMAGEVIDEO')
            .then((data: abilityAccessCtrl.GrantStatus) => {
              console.log(`/Request checkAccessToken success, data->${JSON.stringify(data)}`);
              if (data != abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
                grant = false;
              }
            })
            .catch((err: BusinessError) => {
              console.error(`CheckAccessToken fail, err->${JSON.stringify(err)}`);
            });

          if (!grant) {
            // 用于UIAbility拉起弹框请求用户授权。使用callback异步回调。
            await atManager.requestPermissionsFromUser(context, ['ohos.permission.WRITE_IMAGEVIDEO'])
              .then((data: PermissionRequestResult) => {
                console.info('/Request grant:' + JSON.stringify(data));
                console.info('/Request grant permissions:' + data.permissions);
                console.info('/Request grant authResults:' + data.authResults);
                console.info('/Request grant dialogShownResults:' + data.dialogShownResults);
              }).catch((err: BusinessError) => {
                console.error('Grant error:' + JSON.stringify(err));
              });
          }

          try {
            let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
            let extension: string = 'jpg';
            let options: photoAccessHelper.CreateOptions = {
              title: 'xxxx'
            }
            // 获取相册管理模块的实例，用于访问和修改相册中的媒体文件。
            let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
            // 指定文件类型、后缀和创建选项，创建图片或视频资源，以Promise方式返回结果。
            let uri: string = await phAccessHelper.createAsset(photoType, extension, options);
            console.info('/Request createAsset uri' + uri);
            console.info('/Request createAsset successfully');

            let config: request.agent.Config = {
              action: request.agent.Action.DOWNLOAD,
              url: 'https://xxxx/xxxx.jpg',
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
                  console.error(`Failed to start the download task, Code: ${err.code}  message: ${err.message}`);
                  return;
                }
              });
              task.on('progress', async (progress) => {
                console.warn(`Request download status ${progress.state}, downloaded ${progress.processed}`);
              })
              task.on('completed', async (progress) => {
                console.warn('Request download completed, ' + JSON.stringify(progress));
                //该方法需用户管理任务生命周期，任务结束后调用remove释放task对象
                request.agent.remove(task.tid);
              })
            }).catch((err: BusinessError) => {
              console.error(`Failed to operate a download task, Code: ${err.code}, message: ${err.message}`);
            });
          } catch (err) {
            console.error(`Failed to create a download task, err: ${err}`);
          }
        })
      }
    }
  }
}
```

## 添加任务速度限制与超时限制

开发者可以使用[ohos.request (上传下载)](../../reference/apis-basic-services-kit/js-apis-request.md)模块中的接口上传本地文件或下载网络资源文件。为方便对任务速度及时长进行限制，分别在API version 18中增加了[setMaxSpeed](../../reference/apis-basic-services-kit/js-apis-request.md#setmaxspeed18)接口，支持用户设置任务的最高速度限制；在API version 20的[request.agent.create](../../reference/apis-basic-services-kit/js-apis-request.md#requestagentcreate10-1)接口中增加了最低限速及超时参数，支持用户自定义最低速度限制以及超时时间。

以下是对下载任务进行速度限制与超时限制的方式的示例代码演示：

```ts
// pages/xxx.ets
// 将网络资源文件下载到应用文件目录并读取一段内容
import { common } from '@kit.AbilityKit';
import { fileIo } from '@kit.CoreFileKit';
import { BusinessError, request } from '@kit.BasicServicesKit';
import { buffer } from '@kit.ArkTS';

@Entry
@Component
struct Index {
    build() {
        Row() {
            Column() {
                Button("下载").onClick(() => {
                    // 获取应用文件路径
                    // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext
                    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                    let filesDir = context.filesDir;

                    let config: request.agent.Config = {
                        action: request.agent.Action.DOWNLOAD,
                        url: 'https://xxxx/test.txt',
                        saveas: 'xxxx.txt',
                        gauge: true,
                        overwrite: true,
                        network: request.agent.Network.WIFI,
                        // 最低速度限制规则：
                        // 1. 若任务速度持续低于设定值（如：16 * 1024 B/s）达到指定时长（如：10s），则任务失败
                        // 2. 重置计时条件：
                        //    - 任一秒速度超过最低限速
                        //    - 任务暂停后恢复
                        //    - 任务停止后重启
                        minSpeed: {
                            speed: 16 * 1024,
                            duration: 10
                        },
                        // 超时控制规则：
                        // 1. 连接超时（connectionTimeout）：
                        //    - 单次连接建立耗时超过设定值（如：60s）则任务失败
                        //    - 多次连接时各次独立计时（不累积）
                        // 2. 总超时（totalTimeout）：
                        //    - 任务总耗时（含连接+传输时间）超过设定值（如：120s）则失败
                        //    - 暂停期间不计时，恢复后累积计时
                        // 3. 重置计时条件：任务失败或停止时重置计时
                        timeout: {
                            connectionTimeout: 60,
                            totalTimeout: 120,
                        }
                    };
                    request.agent.create(context, config).then((task: request.agent.Task) => {
                        task.start((err: BusinessError) => {
                            if (err) {
                                console.error(`Failed to start the download task, Code: ${err.code}  message: ${err.message}`);
                                return;
                            }
                            // 设置任务速度上限
                            task.setMaxSpeed(10 * 1024 * 1024).then(() => {
                                console.info(`Succeeded in setting the max speed of the task. result: ${task.tid}`);
                            }).catch((err: BusinessError) => {
                                console.error(`Failed to set the max speed of the task. result: ${task.tid}`);
                            });
                        });
                        task.on('progress', async (progress) => {
                            console.warn(`/Request download status ${progress.state}, downloaded ${progress.processed}`);
                        })
                        task.on('completed', async () => {
                            console.warn(`/Request download completed`);
                            let file = fileIo.openSync(filesDir + '/xxxx.txt', fileIo.OpenMode.READ_WRITE);
                            let arrayBuffer = new ArrayBuffer(1024);
                            let readLen = fileIo.readSync(file.fd, arrayBuffer);
                            let buf = buffer.from(arrayBuffer, 0, readLen);
                            console.info(`The content of file: ${buf.toString()}`);
                            fileIo.closeSync(file);
                            request.agent.remove(task.tid);
                        })
                    }).catch((err: BusinessError) => {
                        console.error(`Failed to create a download task, Code: ${err.code}, message: ${err.message}`);
                    });
                })
            }
        }
    }
}
```

## 添加网络配置

### HTTP拦截

开发者可以通过设置配置文件实现HTTP拦截功能。上传下载模块在应用配置文件中禁用HTTP后，无法创建明文HTTP传输的上传下载任务。配置文件在APP中的路径是：`src/main/resources/base/profile/network_config.json`。请参考网络管理模块[配置文件](../../reference/apis-network-kit/js-apis-net-connection.md#connectionsetapphttpproxy11)，了解需要配置的具体参数。

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
        ],
      }
    ]
  }
}
```

