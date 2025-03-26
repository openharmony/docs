# @ohos.advertising (广告服务框架)

本模块提供广告操作能力，包括请求广告、展示广告。

> **说明：**<br/>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { advertising } from '@kit.AdsKit';
```

## advertising.showAd

showAd(ad: Advertisement, options: AdDisplayOptions, context?: common.UIAbilityContext): void

展示全屏广告。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名     | 类型                                                                                           | 必填 | 说明                                                    | 
|---------|----------------------------------------------------------------------------------------------|----|-------------------------------------------------------|
| ad      | [Advertisement](#advertisement)                                                              | 是  | 广告对象。                                                 | 
| options | [AdDisplayOptions](#addisplayoptions)                                                        | 是  | 广告展示参数。                                               | 
| context | common.[UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 否  | UIAbility的上下文环境，不设置从api: @ohos.app.ability.common中获取。 | 

**错误码：**

以下错误码的详细介绍请参见[广告服务框架错误码参考](errorcode-ads.md)。

| 错误码ID    | 错误信息                                                                                    | 
|----------|-----------------------------------------------------------------------------------------|
| 401      | Invalid input parameter. Possible causes: 1. Mandatory parameters are left unspecified. | 
| 21800001 | System internal error.                                                                  | 
| 21800004 | Failed to display the ad.                                                               | 

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  private context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
  // 请求到的广告内容
  private ad?: advertising.Advertisement;
  // 广告展示参数
  private adDisplayOptions: advertising.AdDisplayOptions = {
    // 是否静音，默认不静音
    mute: false
  }

  build() {
    Column() {
      Button('showAd')
        .onClick(() => {
          try {
            // 调用全屏广告展示接口
            advertising.showAd(this.ad, this.adDisplayOptions, this.context);
          } catch (err) {
            hilog.error(0x0000, 'testTag', `Fail to show ad. Code is ${err.code}, message is ${err.message}`);
          }
        });
    }
    .width('100%')
    .height('100%')
  }
}
```

## advertising.getAdRequestBody<sup>12+</sup>

getAdRequestBody(adParams: AdRequestParams[], adOptions: AdOptions): Promise&lt;string&gt;

获取广告请求响应体，使用Promise异步回调（该接口仅对部分系统预置应用开放）。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                              | 
|-----------|---------------------------------------|----|---------------------------------|
| adParams  | [AdRequestParams[]](#adrequestparams) | 是  | 广告请求参数。<br/> - 该接口体的adid参数可以不传。 | 
| adOptions | [AdOptions](#adoptions)               | 是  | 广告配置。                           | 

**返回值：**

| 类型                    | 说明                     | 
|-----------------------|------------------------|
| Promise&lt;string&gt; | Promise对象，返回字符类型的广告数据。 | 

**错误码：**

以下错误码的详细介绍请参见[广告服务框架错误码参考](errorcode-ads.md)。

| 错误码ID    | 错误信息                                                                                                                                                    |
|----------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | Invalid input parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801      | Device not supported.                                                                                                                                   |
| 21800001 | System internal error.                                                                                                                                  |

**示例：**

```ts
import { advertising } from '@kit.AdsKit';
import { Prompt } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

function getAdRequestBody(): void {
  const adRequestParamsArray: advertising.AdRequestParams[] = [];
  const adRequestParams: advertising.AdRequestParams = {
    adId: 'testu7m3hc4gvm',
    adType: 3,
    adCount: 2,
    adWidth: 100,
    adHeight: 100
  };
  adRequestParamsArray.push(adRequestParams);
  const adOptions: advertising.AdOptions = {
    // 设置是否只请求非个性化广告 0：请求个性化广告与非个性化广告 1：只请求非个性化广告。不填以业务逻辑为准
    nonPersonalizedAd: 0,
    // 是否希望根据 COPPA 的规定将您的内容视为面向儿童的内容: -1默认值，不确定 0不希望 1希望
    tagForChildProtection: -1,
    // 是否希望按适合未达到法定承诺年龄的欧洲经济区 (EEA) 用户的方式处理该广告请求： -1默认值，不确定 0不希望 1希望
    tagForUnderAgeOfPromise: -1,
    // 设置广告内容分级上限: W: 3+,所有受众 PI: 7+,家长指导 J:12+,青少年 A: 16+/18+，成人受众
    adContentClassification: 'A'
  };
  advertising.getAdRequestBody(adRequestParamsArray, adOptions).then((data) => {
    hilog.info(0x0000, 'testTag', `Succeeded in getting ad request body. Data is ${JSON.stringify(data)}`);
    Prompt.showToast({
      message: data,
      duration: 1000
    });
  }).catch((error: BusinessError) => {
    hilog.error(0x0000, 'testTag', `Fail to get ad request body. Code is ${error.code}, message is ${error.message}`);
    Prompt.showToast({
      message: error.code.toString() + ',' + error.message,
      duration: 1000
    });
  })
}
```

## advertising.parseAdResponse<sup>12+</sup>

parseAdResponse(adResponse: string, listener: MultiSlotsAdLoadListener, context: common.UIAbilityContext): void

解析并处理广告响应体（该接口仅对部分系统预置应用开放）。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名        | 类型                                                                                           | 必填 | 说明               |
|------------|----------------------------------------------------------------------------------------------|----|------------------|
| adResponse | string                                                                                       | 是  | 广告请求参数。          |
| listener   | [MultiSlotsAdLoadListener](#multislotsadloadlistener)                                        | 是  | 请求广告回调监听。        |
| context    | common.[UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是  | UIAbility的上下文环境。 |

**错误码：**

以下错误码的详细介绍请参见[广告服务框架错误码参考](errorcode-ads.md)。

| 错误码ID    | 错误信息                                                                                                                                                    |
|----------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | Invalid input parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed. |
| 801      | Device not supported.                                                                                                                                   |
| 21800001 | System internal error.                                                                                                                                  |
| 21800005 | Failed to parse the ad response.                                                                                                                        |

**示例：**

其中context的获取方式参见[UIAbilityContext的获取方式](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)。

```ts
import { common } from '@kit.AbilityKit';
import { advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

function parseAdResponse(adResponse: string, context: common.UIAbilityContext): void {
  // 广告解析处理回调监听
  const multiSlotsAdLoaderListener: advertising.MultiSlotsAdLoadListener = {
    // 广告解析处理失败回调
    onAdLoadFailure: (errorCode: number, errorMsg: string) => {
      hilog.error(0x0000, 'testTag', `Fail to load multiSlots ad. Code is ${errorCode}, message is ${errorMsg}`);
    },
    // 广告解析处理成功回调
    onAdLoadSuccess: (ads: Map<string, Array<advertising.Advertisement>>) => {
      hilog.info(0x0000, 'testTag', 'Succeed in loading multiSlots ad');
      // 保存解析处理完成的广告内容为数组用于展示
      const returnAds: Array<advertising.Advertisement> = [];
      ads.forEach((adsArray) => returnAds.push(...adsArray));
    }
  };
  // 调用响应体解析接口
  hilog.info(0x0000, 'testTag', 'Start to parse ad response');
  advertising.parseAdResponse(adResponse, multiSlotsAdLoaderListener, context);
}
```

## advertising.registerWebAdInterface<sup>12+</sup>

registerWebAdInterface(controller: web_webview.WebviewController, context: common.UIAbilityContext): void

注入广告JavaScript对象到Web组件中（该接口仅对部分系统预置应用开放）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名        | 类型                                                                                           | 必填 | 说明               | 
|------------|----------------------------------------------------------------------------------------------|----|------------------|
| controller | web_webview.[WebviewController](../apis-arkweb/js-apis-webview.md#webviewcontroller)         | 是  | Web组件控制器。        | 
| context    | common.[UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是  | UIAbility的上下文环境。 | 

**错误码：**

以下错误码的详细介绍请参见[广告服务框架错误码参考](errorcode-ads.md)。

| 错误码ID    | 错误信息                                                                                    | 
|----------|-----------------------------------------------------------------------------------------|
| 401      | Invalid input parameter. Possible causes: 1. Mandatory parameters are left unspecified. | 
| 21800001 | System internal error.                                                                  | 

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { advertising } from '@kit.AdsKit';
import { webview } from '@kit.ArkWeb';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  private webController: webview.WebviewController = new webview.WebviewController();
  private context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Button('registerWebAdInterface')
        .onClick(() => {
          try {
            advertising.registerWebAdInterface(this.webController, this.context);
          } catch (err) {
            hilog.error(0x0000, 'testTag', `Fail to register web ad interface. Code is ${err.code}, message is ${err.message}`);
          }
        })

      Web({
        src: 'www.example.com',
        controller: this.webController
      })
        .width("100%")
        .height("100%")
    }
  }
}
```

## advertising.registerWebAdInterface<sup>16+</sup>

registerWebAdInterface(controller: web_webview.WebviewController, context: common.UIAbilityContext, needRefresh: boolean): void

注入广告JavaScript对象到Web组件中（该接口仅对部分系统预置应用开放）。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名         | 类型                                                                                           | 必填 | 说明                             | 
|-------------|----------------------------------------------------------------------------------------------|----|--------------------------------|
| controller  | web_webview.[WebviewController](../apis-arkweb/js-apis-webview.md#webviewcontroller)         | 是  | Web组件控制器。                      | 
| context     | common.[UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) | 是  | UIAbility的上下文环境。               | 
| needRefresh | boolean                                                                                      | 是  | 是否需要刷新页面（true: 需要；false: 不需要）。 | 

**错误码：**

以下错误码的详细介绍请参见[广告服务框架错误码参考](errorcode-ads.md)。

| 错误码ID    | 错误信息                                                                                 | 
|----------|--------------------------------------------------------------------------------------|
| 401      | Invalid input parameter. Possible causes: Mandatory parameters are left unspecified. | 
| 21800001 | operation javascriptRegister error.                                                  |                                                       

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { advertising } from '@kit.AdsKit';
import { webview } from '@kit.ArkWeb';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  private webController: webview.WebviewController = new webview.WebviewController();
  private context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;

  build() {
    Column() {
      Button('registerWebAdInterface')
        .onClick(() => {
          try {
            advertising.registerWebAdInterface(this.webController, this.context, true);
          } catch (err) {
            hilog.error(0x0000, 'testTag', `Fail to register web ad interface. Code is ${err.code}, message is ${err.message}`);
          }
        })

      Web({
        src: 'www.example.com',
        controller: this.webController
      })
        .width("100%")
        .height("100%")
    }
  }
}
```

## advertising.deleteWebAdInterface<sup>16+</sup>

deleteWebAdInterface(controller: web_webview.WebviewController, needRefresh: boolean): void

删除通过registerWebAdInterface注入的广告JavaScript对象（该接口仅对部分系统预置应用开放）。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名         | 类型                                                                                   | 必填 | 说明                             | 
|-------------|--------------------------------------------------------------------------------------|----|--------------------------------|
| controller  | web_webview.[WebviewController](../apis-arkweb/js-apis-webview.md#webviewcontroller) | 是  | Web组件控制器。                      |
| needRefresh | boolean                                                                              | 是  | 是否需要刷新页面（true: 需要；false: 不需要）。 | 

**错误码：**

以下错误码的详细介绍请参见[广告服务框架错误码参考](errorcode-ads.md)。

| 错误码ID    | 错误信息                                                                                 | 
|----------|--------------------------------------------------------------------------------------|
| 401      | Invalid input parameter. Possible causes: Mandatory parameters are left unspecified. | 
| 21800001 | operation javascriptRegister error.                                                  |     

**示例：**

```ts
import { advertising } from '@kit.AdsKit';
import { webview } from '@kit.ArkWeb';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct Index {
  private webController: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('deleteWebAdInterface')
        .onClick(() => {
          try {
            advertising.deleteWebAdInterface(this.webController, true);
          } catch (err) {
            hilog.error(0x0000, 'testTag', `Fail to delete web ad interface. Code is ${err.code}, message is ${err.message}`);
          }
        })

      Web({
        src: 'www.example.com',
        controller: this.webController,
      })
        .width('100%')
        .height('100%')
    }
  }
}
```

## AdLoader

提供加载广告的功能。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

### constructor

constructor(context: common.Context)

构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名     | 类型                                                                         | 必填 | 说明                         |
|---------|----------------------------------------------------------------------------|----|----------------------------|
| context | common.[Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是  | ability或application的上下文环境。 |

**示例：**

其中context的获取方式参见[各类Context的获取方式](../../application-models/application-context-stage.md#概述)。

```ts
import { advertising } from '@kit.AdsKit';
import { common } from '@kit.AbilityKit';

function createConstructor(context: common.Context): void {
  const adLoader: advertising.AdLoader = new advertising.AdLoader(context);
}
```

### loadAd

loadAd(adParam: AdRequestParams, adOptions: AdOptions, listener: AdLoadListener): void

请求单广告位广告。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名       | 类型                                  | 必填 | 说明        | 
|-----------|-------------------------------------|----|-----------|
| adParam   | [AdRequestParams](#adrequestparams) | 是  | 广告请求参数。   | 
| adOptions | [AdOptions](#adoptions)             | 是  | 广告配置。     | 
| listener  | [AdLoadListener](#adloadlistener)   | 是  | 请求广告回调监听。 | 

**错误码：**

以下错误码的详细介绍请参见[广告服务框架错误码参考](errorcode-ads.md)。

| 错误码ID    | 错误信息                                                                                                                                                   | 
|----------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | Invalid input parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. | 
| 801      | Device not supported.                                                                                                                                  |
| 21800001 | System internal error.                                                                                                                                 | 
| 21800003 | Failed to load the ad request.                                                                                                                         | 

**示例：**

其中context的获取方式参见[各类Context的获取方式](../../application-models/application-context-stage.md#概述)。

```ts
import { common } from '@kit.AbilityKit';
import { advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

function loadAd(context: common.Context): void {
  const adRequestParams: advertising.AdRequestParams = {
    // 广告类型
    adType: 3,
    // 测试广告位ID
    adId: 'testy63txaom86'
  };
  const adOptions: advertising.AdOptions = {
    // 可选自定义参数，设置是否允许使用流量下载广告素材 0：不允许，1：允许，不设置以广告主设置为准。
    allowMobileTraffic: 0,
    // 是否希望根据 COPPA 的规定将您的内容视为面向儿童的内容: -1默认值，不确定 0不希望 1希望
    tagForChildProtection: -1,
    // 是否希望按适合未达到法定承诺年龄的欧洲经济区 (EEA) 用户的方式处理该广告请求： -1默认值，不确定 0不希望 1希望
    tagForUnderAgeOfPromise: -1,
    // 设置广告内容分级上限: W: 3+,所有受众 PI: 7+,家长指导 J:12+,青少年 A: 16+/18+，成人受众
    adContentClassification: 'A'
  };
  // 广告请求回调监听
  const adLoaderListener: advertising.AdLoadListener = {
    // 广告请求失败回调
    onAdLoadFailure: (errorCode: number, errorMsg: string) => {
      hilog.error(0x0000, 'testTag', `Fail to load ad. Code is ${errorCode}, message is ${errorMsg}`);
    },
    // 广告请求成功回调
    onAdLoadSuccess: (ads: Array<advertising.Advertisement>) => {
      hilog.info(0x0000, 'testTag', 'Succeed in loading ad');
      // 保存请求到的广告内容用于展示
      const returnAds = ads;
    }
  };
  // 创建AdLoader广告对象
  const adLoader: advertising.AdLoader = new advertising.AdLoader(context);
  // 调用广告请求接口
  hilog.info(0x0000, 'testTag', 'Start to load ad');
  adLoader.loadAd(adRequestParams, adOptions, adLoaderListener);
}
```

### loadAdWithMultiSlots

loadAdWithMultiSlots(adParams: AdRequestParams[], adOptions: AdOptions, listener: MultiSlotsAdLoadListener): void

请求多广告位广告。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名       | 类型                                                    | 必填 | 说明        | 
|-----------|-------------------------------------------------------|----|-----------|
| adParams  | [AdRequestParams](#adrequestparams)[]                 | 是  | 广告请求参数。   | 
| adOptions | [AdOptions](#adoptions)                               | 是  | 广告配置。     | 
| listener  | [MultiSlotsAdLoadListener](#multislotsadloadlistener) | 是  | 请求广告回调监听。 | 

**错误码：**

以下错误码的详细介绍请参见[广告服务框架错误码参考](errorcode-ads.md)。

| 错误码ID    | 错误信息                                                                                                                                                   | 
|----------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | Invalid input parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. | 
| 801      | Device not supported.                                                                                                                                  |
| 21800001 | System internal error.                                                                                                                                 | 
| 21800003 | Failed to load the ad request.                                                                                                                         | 

**示例：**

其中context的获取方式参见[各类Context的获取方式](../../application-models/application-context-stage.md#概述)。

```ts
import { common } from '@kit.AbilityKit';
import { advertising } from '@kit.AdsKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

function loadAdWithMultiSlots(context: common.Context): void {
  const adRequestParamsArray: advertising.AdRequestParams[] = [
    {
      // 广告类型
      adType: 3,
      // 测试广告位ID
      adId: 'testy63txaom86'
    },
    {
      // 广告类型
      adType: 3,
      // 测试广告位ID
      adId: 'testy63txaom86'
    }
  ];
  const adOptions: advertising.AdOptions = {
    // 可选自定义参数，设置是否允许使用流量下载广告素材 0：不允许，1：允许，不设置以广告主设置为准。
    allowMobileTraffic: 0,
    // 是否希望根据 COPPA 的规定将您的内容视为面向儿童的内容: -1默认值，不确定 0不希望 1希望
    tagForChildProtection: -1,
    // 是否希望按适合未达到法定承诺年龄的欧洲经济区 (EEA) 用户的方式处理该广告请求： -1默认值，不确定 0不希望 1希望
    tagForUnderAgeOfPromise: -1,
    // 设置广告内容分级上限: W: 3+,所有受众 PI: 7+,家长指导 J:12+,青少年 A: 16+/18+，成人受众
    adContentClassification: 'A'
  };
  // 广告请求回调监听
  const multiSlotsAdLoaderListener: advertising.MultiSlotsAdLoadListener = {
    // 广告请求失败回调
    onAdLoadFailure: (errorCode: number, errorMsg: string) => {
      hilog.error(0x0000, 'testTag', `Fail to load multiSlots ad. Code is ${errorCode}, message is ${errorMsg}`);
    },
    // 广告请求成功回调
    onAdLoadSuccess: (ads: Map<string, Array<advertising.Advertisement>>) => {
      hilog.info(0x0000, 'testTag', 'Succeed in loading multiSlots ad');
      // 保存请求到的广告内容为数组用于展示
      const returnAds: Array<advertising.Advertisement> = [];
      ads.forEach((adsArray) => returnAds.push(...adsArray));
    }
  };
  // 创建AdLoader广告对象
  const adLoader: advertising.AdLoader = new advertising.AdLoader(context);
  // 调用广告请求接口
  hilog.info(0x0000, 'testTag', 'Start to load multiSlots ad');
  adLoader.loadAdWithMultiSlots(adRequestParamsArray, adOptions, multiSlotsAdLoaderListener);
}
```

## AdLoadListener

单广告位广告请求回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

### onAdLoadFailure

onAdLoadFailure(errorCode: number, errorMsg: string): void

广告请求失败回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名       | 类型     | 必填 | 说明           | 
|-----------|--------|----|--------------|
| errorCode | number | 是  | 广告请求失败的错误码。  | 
| errorMsg  | string | 是  | 广告请求失败的错误信息。 | 

### onAdLoadSuccess

onAdLoadSuccess(ads: Array&lt;Advertisement&gt;): void

广告请求成功后回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名 | 类型                                           | 必填 | 说明    | 
|-----|----------------------------------------------|----|-------|
| ads | Array&lt;[Advertisement](#advertisement)&gt; | 是  | 广告数据。 | 

**示例：**

```ts
import { advertising } from '@kit.AdsKit';

const adLoaderListener: advertising.AdLoadListener = {
  onAdLoadFailure: (errorCode: number, errorMsg: string) => {
  },
  onAdLoadSuccess: (ads: Array<advertising.Advertisement>) => {
  }
}
```

## MultiSlotsAdLoadListener

多广告位广告请求回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

### onAdLoadFailure

onAdLoadFailure(errorCode: number, errorMsg: string): void

多广告位广告请求失败回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名       | 类型     | 必填 | 说明           | 
|-----------|--------|----|--------------|
| errorCode | number | 是  | 广告请求失败的错误码。  | 
| errorMsg  | string | 是  | 广告请求失败的错误信息。 | 

### onAdLoadSuccess

onAdLoadSuccess(adsMap: Map&lt;string, Array&lt;Advertisement&gt;&gt;): void

多广告位广告请求成功后回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名    | 类型                                                              | 必填 | 说明    | 
|--------|-----------------------------------------------------------------|----|-------|
| adsMap | Map&lt;string, Array&lt;[Advertisement](#advertisement)&gt;&gt; | 是  | 广告数据。 | 

**示例：**

```ts
import { advertising } from '@kit.AdsKit';

const multiSlotsAdLoadListener: advertising.MultiSlotsAdLoadListener = {
  onAdLoadFailure: (errorCode: number, errorMsg: string) => {
  },
  onAdLoadSuccess: (adsMap: Map<string, Array<advertising.Advertisement>>) => {
  }
}
```

## AdInteractionListener

广告状态变化回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

### onStatusChanged

onStatusChanged(status: string, ad: Advertisement, data: string)

广告状态回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

**参数：**

| 参数名    | 类型                              | 必填 | 说明                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
|--------|---------------------------------|----|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| status | string                          | 是  | status：广告展示状态，取值<br/>onAdOpen（打开广告回调）、onAdClose（关闭广告回调）、onAdClick（点击广告回调）、onVideoPlayBegin（广告视频开始播放回调）、onVideoPlayEnd（广告视频播放结束回调）、onAdLoad（广告加载成功回调）、onAdFail（广告加载失败回调）、onMediaProgress（广告播放进度回调）、onMediaStart（广告开始播放回调）、onMediaPause（广告暂停播放回调）、onMediaStop（广告停止播放回调）、onMediaComplete（广告播放完成回调）、onMediaError（广告播放失败回调）、onLandscape（竖屏状态下点击全屏按钮回调）、onPortrait（全屏状态下点击返回按钮回调）、onAdReward (广告获得奖励回调) 、onMediaCountDown (广告倒计时回调) 、onBackClicked (返回点击广告回调)。 | 
| ad     | [Advertisement](#advertisement) | 是  | 发生状态变化的广告内容。                                                                                                                                                                                                                                                                                                                                                                                                                                             | 
| data   | string                          | 是  | 扩展信息。                                                                                                                                                                                                                                                                                                                                                                                                                                                    | 

**示例：**

```ts
import { advertising } from '@kit.AdsKit';

const adInteractionListener: advertising.AdInteractionListener = {
  onStatusChanged: (status: string, ad: advertising.Advertisement, data: string) => {

  }
}
```

## AdOptions

广告配置参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

| 名称                      | 类型                                       | 只读 | 可选 | 说明                                                                                                                                                                                                                                                                                                                                                                                                        | 
|-------------------------|------------------------------------------|----|----|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| tagForChildProtection   | number                                   | 否  | 是  | 设置儿童保护标签，否希望根据 COPPA 的规定将您的内容视为面向儿童的内容。<br/>- -1：默认值，不确定。<br/>- 0：不希望。<br/>- 1：希望。<br/>默认为-1。                                                                                                                                                                                                                                                                                                             | 
| adContentClassification | string                                   | 否  | 是  | 设置广告内容分级上限。<br/>- W：3+,所有受众。<br/>- PI：7+，家长指导。<br/>- J：12+，青少年。<br/>- A：16+/18+,成人受众。<br/>不填以业务逻辑为准。                                                                                                                                                                                                                                                                                                      | 
| nonPersonalizedAd       | number                                   | 否  | 是  | 设置是否只请求非个性化广告。<br/>- 0：请求个性化广告与非个性化广告。<br/>- 1：只请求非个性化广告。<br/>不填以业务逻辑为准。                                                                                                                                                                                                                                                                                                                                  | 
| [key: string]           | number \| boolean \| string \| undefined | 否  | 是  | 自定义参数。<br/> - totalDuration：类型number，单位：s。贴片广告必填自定义参数，用于设置贴片广告展示时长。<br/> - placementAdCountDownDesc：类型string。贴片广告可选自定义参数，用于设置贴片广告倒计时文案，该参数需要使用encodeURI()方法编码。填写了该参数，则展示倒计时文案，否则只展示倒计时。<br/> - allowMobileTraffic：类型number。可选自定义参数，设置是否允许使用流量下载广告素材。0：不允许，1：允许，不设置以广告主设置为准。 <br/> - tagForUnderAgeOfPromise：类型number。非必填参数，用于设置未成年保护标签，表示是否希望按适合未达到法定承诺年龄的欧洲经济区 (EEA) 用户的方式处理该广告请求。-1：默认值，不确定 0：不希望 1：希望。 |

## AdRequestParams

广告请求参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

| 名称              | 类型                                       | 只读 | 可选 | 说明                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
|-----------------|------------------------------------------|----|----|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| adId            | string                                   | 否  | 否  | 广告位ID。<br/>- getAdRequestBody接口可以不传该参数。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                | 
| adType          | number                                   | 否  | 是  | 请求的广告类型。<br/>- 1：开屏广告。<br/>- 3：原生广告。<br/>- 7：激励广告。<br/>- 8：banner广告。<br/>- 12：插屏广告。<br/>- 60：贴片广告。<br/>不填默认为原生广告类型。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| adCount         | number                                   | 否  | 是  | 请求的广告数量。不填以业务逻辑为准。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     | 
| adWidth         | number                                   | 否  | 是  | 请求广告时期望的创意宽度，单位vp（横幅广告必填）。不填以业务逻辑为准。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | 
| adHeight        | number                                   | 否  | 是  | 请求广告时期望的创意高度，单位vp（横幅广告必填）。不填以业务逻辑为准。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | 
| adSearchKeyword | string                                   | 否  | 是  | 广告关键字。不填默认""。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          | 
| [key: string]   | number \| boolean \| string \| undefined | 否  | 是  | 自定义参数。<br/>- isPreload：类型boolean，请求贴片广告时，用于区分普通在线请求和素材预加载请求。true：素材预加载请求，false：普通在线请求。默认值false。仅对贴片广告生效，其他广告请求不解析该参数。<br/>- enableDirectReturnVideoAd：类型boolean，原生广告自定义扩展参数，是否直接返回广告，不用等待所有广告素材下载完成。true：不等待广告素材下载完成，展示广告时在线加载素材；false：等待广告素材下载完成，展示广告时从本地缓存中加载素材。如果不填以云侧配置为准。仅对原生广告生效，其他广告请求不解析该参数。<br/>- oaid: 类型string，开放匿名设备标识符，用于精准推送广告。不填无法获取到个性化广告。默认值为""。<br/>- tmax：类型number，交易的最大超时时间（包含网络延迟）单位毫秒。<br/>- cur：类型string，竞价请求支持的币种，支持传多个，用英文逗号分隔。当前支持五种货币：CNY、USD、EUR、GBP、JPY，不填则默认是CNY。<br/>- bidFloor：类型number，实时竞价广告位的底价。<br/>- bidFloorCur：类型string，广告位底价使用的币种。如果bidFloor非空，则bidFloorCur也非空。当前只支持五种货币中的一种：CNY、USD、EUR、GBP、JPY，不填则默认是CNY。<br/>- bpkgName：类型string，广告位禁投的APP包名，支持传多个，用英文逗号分隔。 |

## AdDisplayOptions

广告展示参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

| 名称                    | 类型                                       | 只读 | 可选 | 说明                                                                                                                                                     |
|-----------------------|------------------------------------------|----|----|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| customData            | string                                   | 否  | 是  | 媒体自定义数据。用于服务端通知媒体服务器某位用户因为与激励视频广告互动而应予以奖励，从而规避欺骗的行为（不填则不会通知）。                                                                                          | 
| userId                | string                                   | 否  | 是  | 媒体自定义用户id。用于服务端通知媒体服务器某位用户因为与激励视频广告互动而应予以奖励，从而规避欺骗的行为（不填则不会通知）。                                                                                        | 
| useMobileDataReminder | boolean                                  | 否  | 是  | 使用移动数据播放视频或下载应用时是否弹框通知用户。<br/>- true：弹框通知。<br/>- false：不弹框通知。<br/>该参数依赖流量弹窗功能，当前不支持完整功能的使用，暂不确定默认值。                                                    | 
| mute                  | boolean                                  | 否  | 是  | 广告视频播放是否静音。<br/>- true：静音播放。<br/>- false：非静音播放。<br/>不填以业务逻辑为准。                                                                                         | 
| audioFocusType        | number                                   | 否  | 是  | 视频播放过程中获得音频焦点的场景类型。<br/>- 0：视频播放静音、非静音时都获取焦点。<br/>- 1：视频静音播放时不获取焦点。<br/>- 2：视频播放静音、非静音时都不获取焦点。<br/>该接口依赖的相关功能当前不支持使用，暂不确定默认值。                          | 
| [key: string]         | number \| boolean \| string \| undefined | 否  | 是  | 自定义参数。<br/>- refreshTime：类型number，单位：ms，取值范围[30000, 120000]。AutoAdComponent组件可选自定义参数，用于控制广告的轮播时间间隔。填写了该参数，则广告按照参数配置的时间间隔轮播，否则广告不会轮播，只会展示广告响应中的第一个广告内容。 |

## Advertisement

type Advertisement = _Advertisement

请求的广告内容。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Advertising.Ads

| 类型                                                           | 说明                 |
|--------------------------------------------------------------|--------------------|
| [_Advertisement](js-apis-inner-advertising-advertisement.md) | 表示Advertisement对象。 |