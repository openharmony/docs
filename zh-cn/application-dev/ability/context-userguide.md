# 应用上下文使用指导

## Context概述
​        context是应用中对象的上下文，提供获取应用程序环境信息的能力。

## Context整体结构介绍

​        OpenHarmony的应用框架分为FA模型和Stage两种模型。对应存在两套Context机制适配两种应用框架模型：

​        **application/BaseContext** 属于一个通用的Context基类，既不属于FA模型也不属于Stage模型，里面只有一个属性stageMode，用来区分开发模型是FA还是Stage。

​        **FA模型** 只有app/Context中的方法属于FA模型对应的Context。该模式下，应用级别的Context和Ability级别的Context都是该类型的实例，如果在应用级别的Context里面调用了Ability级别的方法，会产生错误。所以开发者需要注意context实例所代表的实际含义。

​        **Stage模型** 除了app/Context之外的Context都属于Stage模型，分别有application/Context、application/AbilityStageContext、application/ExtensionContext、application/AbilityContext、application/FormExtensionContext和application/ServiceExtensionContext六种Context。这些Context的介绍及使用方式将会在[Stage模型和Context详细介绍](#stage模型和context详细介绍)种进行说明。


![contextIntroduction](figures/contextIntroduction.png)

## FA模型的Context详细介绍

​        只有app/Context中的方法属于FA模型对应的Context。

​        FA模型只有一个Context定义。Context中所有的功能都是通过方法来提供的，它提供了一些featureAbility中不存在的方法，相当于featureAbility的一个扩展和补全。

​        d.ts文件如下：

​        https://gitee.com/openharmony/interface_sdk-js/blob/master/api/app/context.d.ts

​        应用的使用方式：

```javascript
// 1.引入featureAbility
import featureAbility from '@ohos.ability.featureAbility'

export default {
  onCreate() {
    console.log('Application onCreate')

    // 2.获取Context
    let context = featureAbility.getContext();

    // 3.调用对应的方法
    context.setShowOnLockScreen(false, (data) => {
      console.log("data: " + JSON.stringify(data));
    });
  },
  onActive() {
    console.log('Application onActive')
  },
  onDestroy() {
    console.log('Application onDestroy')
  },
}
```

## Stage模型和Context详细介绍

​        Stage模型有6大Context：

### application/Context

**概述**

​        application/Context类型的Context是基类Context，里面提供了应用的一些基础信息：resourceManager、applicationInfo、cacheDir等，还有应用的一些基本方法：createBundleContext、switchArea等。应用级别的Context也是application/Context这种类型。

**获取方法**

​        需要在AbilityStage、Ability、Extension等组件中通过context.getApplicationContext()拿到。

**示例**

```javascript
export default class MainAbility extends Ability {
  onCreate(want, launchParam) {
    console.log('MainAbility onCreate is called' + want + launchParam);
    // 获取ApplicationContext
    let appContext = this.context.getApplicationContext();
    // 获取路径
    console.log('filesDir is ' + appContext.filesDir);
  }

  onDestroy() {
    console.log('MainAbility onDestroy is called');
  }
}
```

**d.ts声明**

​        https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/Context.d.ts

### application/AbilityStageContext

​ **概述**

​        application/AbilityStageContext是Hap包级别的Context。和基类Context相比，Hap包级别的Context中多了HapModuleInfo和Configuration两个信息。

**获取方法**

​        可以直接在AbilityStage中通过context属性拿到。

**示例**

```javascript
export default class MyAbilityStage extends AbilityStage {
  onCreate() {
    // 属性context就是AbilityStageContext类型的
    console.log('HapModuleInfo is ' + context.currentHapModuleInfo);
  }
}
```

**d.ts声明**

​        https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/AbilityStageContext.d.ts

### application/AbilityContext

​ **概述**

​        Stage模型下，每个Ability中都包含了一个Context属性。

​        Ability功能主要是处理生命周期，其余操作Ability的方法(如startAbility、connectAbility等)都是在AbilityContext中实现的。

**获取方法**

​        在Ability中通过context属性拿到。

**示例**

```javascript
export default class MainAbility extends Ability {
  onCreate(want, launchParam) {
    console.log('MainAbility onCreate is called' + want + launchParam);
    var want = {
      "bundleName": "com.example.MyApplication",
      "abilityName": "ServiceExtAbility",
    }
    // 1.这里的Context就是AbilityContext
    let contxt = this.context;
    // 2.startAbility
    contxt.startAbility(want).then((data) => {
      console.info("startAbility success:" + JSON.stringify(data));
    }).catch((error) => {
      console.error("startAbility failed:" + JSON.stringify(error));
    });
  }

  onDestroy() {
    console.log("MainAbility on Destroy is called");
  }
}
```

**d.ts声明**

​        https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/AbilityContext.d.ts

### application/ExtensionContext

​ **概述**

​        和FA模型不同的是，Stage模型把Service从Ability中剥离出来，单独定义了一组通用扩展类Extension用来处理等同的功能。Extension是一个基类，不承担具体业务功能。业务方根据自己的需要去扩展对应的Extension，例如：ServiceAbility扩展为了ServiceExtensionAbility，卡片扩展为了FormExtension。

​        因此新增了一种和Extension匹配的ExtensionContext。ExtensionContext中包含HapModuleInfo和Configuration两个属性。

**获取方法**

​        不会单独使用。

**d.ts声明**

​        https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/ExtensionContext.d.ts

### application/ServiceExtensionContext

​ **概述**

​        ServiceExtensionAbility类似于FA模型的ServiceAbility，里面只有生命周期回调相关的处理。

​        操作ServiceExtensionAbility的方法移动到了ServiceExtensionContext中(如startAbility、connectAbility等)。

**获取方法**

​        ServiceExtensionAbility中通过context属性获取。

**示例**
```javascript
export default class ServiceExtAbility extends ServiceExtensionAbility {
  onCreate(want) {
    console.info("ServiceAbility onCreate**");
    // 1.这里的Context就是ServiceExtensionContext
    let contxt = this.context;
  }

  onRequest(want, startId)  {
    console.info("ServiceAbility onRequest**");
  }

  onConnect(want)  {
    console.info("ServiceAbility onConnect**");
    return new StubTest("test");
  }

  onDisconnect(want) {
    console.info("ServiceAbility onDisconnect**");
  }

  onDestroy() {
    console.info("ServiceAbility onDestroy**");
  }
}

```

**d.ts声明**

​        https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/ServiceExtensionContext.d.ts

### application/FormExtensionContext

​        [FormExtensionContext](/zh-cn/application-dev/reference/apis/js-apis-formextensioncontext.md)

**d.ts声明**

​        https://gitee.com/openharmony/interface_sdk-js/blob/master/api/application/FormExtensionContext.d.ts

## 常见问题

**通过globalThis去获取Context**

**结论**

​        FA模型可以通过该方式去获取；Stage模型不可通过该方式去获取，要通过对应组件的属性去获取。

**原因**

​        应用框架在API8上推出了新的应用模型（Stage模型）。在老的模型（FA模型）下，每个Ability实例有一个js虚拟机实例，所以可以从js引擎的global对象上，获取到一个全局的Ability实例，但是在新的模型（Stage模型）下，整个应用进程共用一个js虚拟机实例，其中可以运行多个Ability实例，这样就不存在一个全局的Ability实例。如果开发者在新的模型（Stage模型）下，调用的API实现仍然走到了获取全局Ability实例的方法，就可能会发生错误或者崩溃。