# 合理使用缓存提升性能

## 简介

随着应用功能的日益丰富与复杂化，数据加载效率成为了衡量应用性能的重要指标。不合理的加载策略往往导致用户面临长时间的等待，这不仅损害了用户体验，还可能引发用户流失。因此，合理运用缓存技术变得尤为重要。
系统提供了[Preferences](../quick-start/arkts-persiststorage.md)、[数据库](../reference/apis-arkdata/js-apis-data-rdb.md)、[文件](../reference/apis-core-file-kit/js-apis-file-fs.md)、[AppStorage](../quick-start/arkts-appstorage.md)等缓存方式，开发者可以对应用数据先进行缓存，再次加载数据时优先展示缓存数据，减少加载时间，从而提升用户体验。本文将介绍如何通过缓存技术优化应用性能：针对网络数据和地址数据等内容，采用缓存策略，加速数据访问速度，提升应用性能。

## 问题场景

在应用启动流程中，开发者往往会遇到冷启动完成时延长的问题。这是由于大部分应用的首页数据依赖于网络请求或定位服务等方式来获取相应数据。如果网络、位置服务等信号差，就会导致应用请求网络和位置数据耗时变长，从而在页面冷启动过程中出现较长时间的白屏或白块现象。例如，在需要冷启动时即时加载首页地址数据的场景下，如果应用每次冷启动都通过[getCurrentLocation](../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation)获取位置数据，特别是在信号较弱的区域，这可能导致显著的延迟，迫使用户等待较长时间才能获取到所需的位置信息，从而极大地影响了应用的冷启动体验。针对上述问题，下面将通过使用缓存减少首次数据加载展示时间，优化应用启动性能，为开发者优化应用性能提供参考。


## 优化示例
在介绍示例前，先给开发者简单介绍一些冷启动首页中常用的缓存使用流程。

图1 三种常用的缓存使用流程

![reasonable_using_cache_improve_performance_flow_chart](./figures/reasonable_using_cache_improve_performance_flow_chart.png)

图1是三种常用的缓存使用流程。常用流程1的详细过程如下：

1.应用冷启动时，读取缓存。

2.判断是否有缓存数据。

3.如果本地没有缓存数据，则需要通过网络、位置服务等方式请求相应数据，然后把数据刷新到首页，同时异步更新缓存数据。

4.如果本地有缓存数据，则把缓存数据先刷新到应用首页，然后异步请求数据进行页面二刷，并更新缓存数据。

常用流程2和1的过程类似，只是常用流程2中省略了异步请求数据进行页面二刷并更新缓存的步骤。而常用流程3和2相比，常用流程3只是在本地有缓存数据时，增加了对缓存数据是否失效的处理。如果缓存数据没有失效，则把缓存数据刷新到应用首页。如果缓存数据已经失效，则需要重新请求数据，然后刷新到首页并更新缓存。

上述缓存使用流程仅为开发者提供参考，实际开发中需结合具体业务场景与需求进行灵活的调整与优化。下面将介绍缓存网络数据和缓存地址数据两个场景示例，并进行性能分析对比。

### 场景1缓存网络数据

图2 使用本地缓存首页数据流程图

![reasonable_using_cache_improve_performance_network_flow_chart](./figures/reasonable_using_cache_improve_performance_network_flow_chart.png)

图2是使用本地缓存首页数据的流程图。使用本地缓存优先展示冷启动首页数据，可以减少首帧展示完成时延，减少用户可见白屏或白块时间，提升用户的冷启动体验。

>**说明：**
>
> 应用需根据自身对于数据的时效性要求，来决定是否使用缓存数据。例如时效性要求为一天时，一天前保存的缓存数据就不适合进行展示，需从网络获取新数据进行展示，并更新本地缓存数据。

下面是一个缓存网络数据的场景示例。示例中应用首页需展示一张从网站获取的图片信息，在aboutToAppear()中发起网络请求，待数据返回解析后展示在首页上。之后将图片信息缓存至本地应用沙箱内，再次冷启动时首先从沙箱内获取图片信息。若存在，即可解析并展示，在网络请求返回时再次更新图片信息。

以下为关键示例代码：

```ts
import { http } from '@kit.NetworkKit';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl, common, Permissions } from '@kit.AbilityKit';
import { fileIo as fs } from '@kit.CoreFileKit';

const PERMISSIONS: Array<Permissions> = [
  'ohos.permission.READ_MEDIA',
  'ohos.permission.WRITE_MEDIA'
];
AppStorage.link('net_picture');
PersistentStorage.persistProp('net_picture', '');

@Entry
@Component
struct Index {
  @State image: PixelMap | undefined = undefined;
  @State imageBuffer: ArrayBuffer | undefined = undefined; // 图片ArrayBuffer

  /**
   * 通过http的request方法从网络下载图片资源
   */
  async getPicture() {
    http.createHttp()
      .request('https://www.example1.com/POST?e=f&g=h',
        (error: BusinessError, data: http.HttpResponse) => {
          if (error) {
            return;
          }
          // 判断网络获取到的资源是否为ArrayBuffer类型
          if (data.result instanceof ArrayBuffer) {
            this.imageBuffer = data.result as ArrayBuffer;
          }
          this.transcodePixelMap(data);
        }
      )
  }

  /**
   * 使用createPixelMap将ArrayBuffer类型的图片装换为PixelMap类型
   * @param data：网络获取到的资源
   */
  transcodePixelMap(data: http.HttpResponse) {
    if (http.ResponseCode.OK === data.responseCode) {
      const imageData: ArrayBuffer = data.result as ArrayBuffer;
      // 通过ArrayBuffer创建图片源实例。
      const imageSource: image.ImageSource = image.createImageSource(imageData);
      const options: image.InitializationOptions = {
        'alphaType': 0, // 透明度
        'editable': false, // 是否可编辑
        'pixelFormat': 3, // 像素格式
        'scaleMode': 1, // 缩略值
        'size': { height: 100, width: 100 }
      }; // 创建图片大小

      // 通过属性创建PixelMap
      imageSource.createPixelMap(options).then((pixelMap: PixelMap) => {
        this.image = pixelMap;
        setTimeout(() => {
          if (this.imageBuffer !== undefined) {
            this.saveImage(this.imageBuffer);
          }
        }, 0)
      });
    }
  }

  /**
   * 保存ArrayBuffer到沙箱路径
   * @param buffer：图片ArrayBuffer
   * @returns
   */
  async saveImage(buffer: ArrayBuffer | string): Promise<void> {
    const context = getContext(this) as common.UIAbilityContext;
    const filePath: string = context.cacheDir + '/test.jpg';
    AppStorage.set('net_picture', filePath);
    const file = await fs.open(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    await fs.write(file.fd, buffer);
    await fs.close(file.fd);
  }

  async useCachePic(): Promise<void> {
    if (AppStorage.get('net_picture') !== '') {
      // 获取图片的ArrayBuffer
      const imageSource: image.ImageSource = image.createImageSource(AppStorage.get('net_picture'));
      const options: image.InitializationOptions = {
        'alphaType': 0, // 透明度
        'editable': false, // 是否可编辑
        'pixelFormat': 3, // 像素格式
        'scaleMode': 1, // 缩略值
        'size': { height: 100, width: 100 }
      };
      imageSource.createPixelMap(options).then((pixelMap: PixelMap) => {
        this.image = pixelMap;
      });
    }
  }

  async aboutToAppear(): Promise<void> {
    const context = getContext(this) as common.UIAbilityContext;
    const atManager = abilityAccessCtrl.createAtManager();
    await atManager.requestPermissionsFromUser(context, PERMISSIONS);
    this.useCachePic(); // 从本地缓存获取数据
    this.getPicture(); // 从网络端获取数据
  }

  build() {
    Column() {
      Image(this.image)
        .objectFit(ImageFit.Contain)
        .width('50%')
        .height('50%')
    }
  }
}
```

**效果对比**

下面对优化前后启动性能进行对比分析。分析阶段的起点为启动Ability（即H:void OHOS::AppExecFwk::MainThread::HandleLaunchAbility的开始点），阶段终点为应用首次解析Pixelmap（即H:Napi execute, name:CreatePixelMap, traceid:0x0）后的第一个vsync（即H:ReceiveVsync dataCount: 24bytes now:timestamp expectedEnd:timestamp vsyncId:int的开始点）。

图3 优化前未使用本地缓存
![reasonable_using_cache_improve_performance_network_use_api](./figures/reasonable_using_cache_improve_performance_network_use_api.png)

图4 优化后使用本地缓存
![reasonable_using_cache_improve_performance_network_use_cache](./figures/reasonable_using_cache_improve_performance_network_use_cache.png)

图3是优化前未使用本地缓存（从网络端获取数据）的耗时，图4是优化后使用本地缓存的耗时，对比数据如下（性能耗时数据因设备版本环境而异，以实测为准）：

| 方案           |  阶段时长(毫秒)  |
|--------------|:----------:|
| （优化前）未使用本地缓存 |   641.8    |
| （优化后）使用本地缓存   |    68.9    |

可以看到在使用本地缓存后，应用冷启动时从Ability启动到图片显示的阶段耗时明显减少。

### 场景2缓存地址数据

下面是一个使用[PersistentStorage（持久化存储UI状态）](../quick-start/arkts-persiststorage.md)缓存地址数据的场景示例。主要步骤如下：

1.通过persistProp初始化PersistentStorage。

2.创建状态变量@StorageLink(MYLOCATION) myLocation，和AppStorage中MYLOCATION双向绑定。

3.应用冷启动时，先判断缓存AppStorage里MYLOCATION值是否为空（UI和业务逻辑不直接访问PersistentStorage中的属性，所有属性访问都是对AppStorage的访问）。

4.如果缓存为空，则从getCurrentLocation获取地址数据，并加载到页面，同时保存到缓存。如果缓存不为空，则直接从缓存获取地址数据，并加载到页面。

>**说明：**
>
> 为了方便对比性能差异，本例中未做缓存数据是否失效和页面二刷的业务处理。实际业务开发中冷启动时虽然是优先从缓存获取地址数据进行刷新，但是后面还需要再使用getCurrentLocation获取最新地址数据进行页面二刷，以确保地址数据的准确性。

```ts
import { abilityAccessCtrl, common, Permissions } from '@kit.AbilityKit'; // 程序访问控制管理模块
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog, hiTraceMeter } from '@kit.PerformanceAnalysisKit'; // 性能打点模块
import { geoLocationManager } from '@kit.LocationKit'; // 位置服务模块。需要在module.json5中配置ohos.permission.APPROXIMATELY_LOCATION权限。

// 写入与读取缓存位置数据的key值
const MYLOCATION = 'myLocation';
// 定义获取模糊位置的权限
const PERMISSIONS: Array<Permissions> = ['ohos.permission.APPROXIMATELY_LOCATION'];
// 获取上下文信息
const context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext;
// 初始化PersistentStorage。PersistentStorage用于持久化存储选定的AppStorage属性
PersistentStorage.persistProp(MYLOCATION, '');

@Entry
@Component
struct Index {
  // 创建状态变量@StorageLink(MYLOCATION) myLocation，和AppStorage中MYLOCATION双向绑定
  @StorageLink(MYLOCATION) myLocation: string = '';

  aboutToAppear() {
    // ApiDataTime表示从getCurrentLocation接口获取位置信息的性能打点起始位置。
    hiTraceMeter.startTrace("ApiDataTime", 1);
    // CacheDataTime表示从AppStorage缓存中获取位置信息的性能打点起始位置。
    hiTraceMeter.startTrace("CacheDataTime", 1);
    // 从AppStorage缓存中获取位置信息
    let cacheData = AppStorage.get<string>(MYLOCATION);
    // 缓存中如果有位置信息，则直接从缓存获取位置信息。如果没有，则从getCurrentLocation接口获取位置信息。
    if (cacheData !== '') {
      // 缓存中有位置信息，则从缓存中直接获取位置信息，并结束性能打点
      hiTraceMeter.finishTrace("CacheDataTime", 1);
      AlertDialog.show({
        message: 'AppStorage:' + cacheData,
        alignment: DialogAlignment.Center
      });
    } else {
      // 缓存中没有位置信息，则从接口获取位置信息
      this.apiGetLocation(PERMISSIONS, context);
    }
  }

  /**
   * 从getCurrentLocation接口获取位置信息。用户需要先授权。
   */
  apiGetLocation(permissions: Array<Permissions>, context: common.UIAbilityContext): void {
    // 获取访问控制模块对象
    let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
    // 拉起弹框请求用户授权。requestPermissionsFromUser会判断权限的授权状态来决定是否唤起弹窗
    atManager.requestPermissionsFromUser(context, permissions).then((data) => {
      // 获取相应请求权限的结果。 0表示已授权，否则表示未授权
      let grantStatus: Array<number> = data.authResults;
      let length: number = grantStatus.length;
      for (let i = 0; i < length; i++) {
        // 如果用户已授权模糊位置的权限，则调用getCurrentLocation获取位置信息，并保存到AppStorage
        if (data.permissions[i] === 'ohos.permission.APPROXIMATELY_LOCATION' && grantStatus[i] === 0) {
          // 设置位置请求参数
          let requestInfo: geoLocationManager.CurrentLocationRequest = {
            'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, // 设置优先级信息。FIRST_FIX表示快速获取位置优先，如果应用希望快速拿到一个位置，可以将优先级设置为该字段。
            'scenario': geoLocationManager.LocationRequestScenario.UNSET // 设置场景信息。UNSET表示未设置场景信息。当scenario取值为UNSET时，priority参数生效，否则priority参数不生效；
          };
          try {
            // 获取当前位置
            geoLocationManager.getCurrentLocation(requestInfo).then((result) => {
              // 获取位置信息后，结束性能打点
              hiTraceMeter.finishTrace("ApiDataTime", 1);
              let locationData = JSON.stringify(result);
              // 保存到本地缓存
              AppStorage.setOrCreate(MYLOCATION, JSON.stringify(locationData));
              AlertDialog.show({
                message: 'getCurrentLocation:' + locationData,
                alignment: DialogAlignment.Center
              });
            })
              .catch((error: BusinessError) => {
                hilog.error(0x0000, "UseCacheInsteadAddressInquiry", `getCurrentLocation: error= ${error}`);
              });
          } catch (err) {
            hilog.error(0x0000, "UseCacheInsteadAddressInquiry", `err: ${err}`);
          }
        } else {
          // 如果用户未授权，提示用户授权。
          AlertDialog.show({
            message: '用户未授权，请到系统设置中打开应用的位置权限后再试。',
            alignment: DialogAlignment.Center
          });
          return;
        }
      }
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, "UseCacheInsteadAddressInquiry", `failed to request permissions from user. Code is ${err.code} , message is ${err.message}`);
    })
  }

  build() {
    Column() {
      Button('clear cache').onClick(() => {
        // 清除AppStorage缓存中的位置信息
        this.myLocation = '';
        AlertDialog.show({
          message: 'cache cleared',
          alignment: DialogAlignment.Center
        });
      })
    }
    .height('100%')
    .width('100%')
  }
}
```

**效果对比**

下面使用DevEco Studio内置的Profiler中的启动分析工具Launch，对使用getCurrentLocation获取地址数据及使用缓存获取地址数据的冷启动性能进行对比分析。本例中通过在aboutToAppear进行起始位置的[性能打点](../reference/apis-performance-analysis-kit/js-apis-hitracemeter.md)，然后在使用本地缓存和使用getCurrentLocation获取到地址数据的位置分别进行结束位置的性能打点来分析两者的性能差异。对比性能前，需要先打开一次应用页面，在弹出位置信息授权弹窗时选择允许授权的选项。

优化前未使用本地缓存（通过getCurrentLocation获取地址数据）的测试步骤：先打开示例页面，点击'clear cache'按钮（清除本地位置信息的缓存）后退出应用，再使用Launch抓取性能数据。

图5 优化前未使用本地缓存

![reasonable_using_cache_improve_performance_use_api](./figures/reasonable_using_cache_improve_performance_use_api.png)

优化后使用本地缓存（通过PersistentStorage获取地址数据）的测试步骤：在使用getCurrentLocation获取地址数据后退出应用（本例中在getCurrentLocation获取地址数据数据后会保存到本地缓存），再使用Launch工具抓取性能数据。

图6 优化后使用本地缓存

![reasonable_using_cache_improve_performance_use_cache](./figures/reasonable_using_cache_improve_performance_use_cache.png)

图5是优化前未使用本地缓存（从getCurrentLocation获取地址数据）的耗时，图6是优化后使用本地缓存（从PersistentStorage获取地址数据）的耗时，对比数据如下（性能耗时数据因设备版本环境而异，以实测为准）：

| 方案                     | 阶段时长 |
| ------------------------ | :------: |
| （优化前）未使用本地缓存 |   46ms   |
| （优化后）使用本地缓存   |   19μs   |

由此可见，在冷启动首页需要加载地址数据的场景中，先采用本地缓存策略获取地址数据相比调用getCurrentLocation接口，能显著缩短地址数据的获取时间，减少用户等待，提升冷启动完成时延性能与用户体验。

## 总结

应用性能优化中，合理使用缓存是提升体验的关键。通过将频繁请求的网络数据或位置信息等缓存起来，可以在下次启动时优先加载缓存数据，避免网络延迟或位置服务信号差导致的白屏或白块现象。这样不仅能减少页面数据加载时间，提升应用性能，还能显著改善用户体验。