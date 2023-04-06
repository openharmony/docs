# arkui子系统ChangeLog

## cl.arkui.1 getInspectorTree接口返回值从string修改为Object。

**变更影响**

3.2.10.7之前使用getInspectorTree接口的代码需要适配

**关键的接口/组件变更**

getInspectorTree接口返回值从string修改为Object

**适配指导**

将getInspectorTree返回值作为string使用的代码需要修改，比如以下示例代码：

```typescript
console.info(getInspectorTree())
```

需要修改成

```typescript
console.info(JSON.stringify(getInspectorTree())) 
```

## cl.arkui.2 废弃GridItem的forceRebuild属性

**变更影响**

无，该属性无作用

**关键的接口/组件变更**

GridItem的forceRebuild属性废弃

**适配指导**

如有使用可以直接删除，不影响GridItem功能

## cl.arkui.3 Plugin模块接口变更


### 1. arkui子系统Plugin模块 `PluginComponentTemplate` 接口存在变更：

ability命名无法准确表达对应参数的语义，修改为bundleName。

开发者需要根据以下说明对应用进行适配。



**变更影响**

基于此前版本开发的应用，需适配变更接口，变更前的接口已经不能正常使用，会在编译过程中报错。



**关键的接口/组件变更**

- 涉及接口

 interface PluginComponentTemplate {
  source: string;
  bundleName: string;
  }

  interface PluginComponentInterface {
  (value: { template: PluginComponentTemplate; data: any }): PluginComponentAttribute;
}

- 变更前：

```js
 interface PluginComponentTemplate { source: string; ability: string; }
 interface PluginComponentInterface {
  (value: { template: PluginComponentTemplate; data: any }): PluginComponentAttribute; 
  }
```

- 变更后：

```js
 interface PluginComponentTemplate { source: string; bundleName: string; }
 interface PluginComponentInterface {
  (value: { template: PluginComponentTemplate; data: any }): PluginComponentAttribute; 
  }
```

**适配指导**

使用变更后的接口，示例代码如下：

- 变更前：
```js
PluginComponent({
    template: { source: 'plugincomponent1', ability: 'com.example.plugin' },
    data: { 'countDownStartValue': 'new countDownStartValue' }
}).size({ width: 500, height: 100 })
```

- 变更后：
```js
PluginComponent({
    template: { source: 'plugincomponent1', bundleName: 'com.example.plugin' },
    data: { 'countDownStartValue': 'new countDownStartValue' }
}).size({ width: 500, height: 100 })
```

### 2. arkui子系统Plugin模块 `pluginComponentManager` 接口存在变更：

want命名无法准确表达对应参数的语义，修改为target。

开发者需要根据以下说明对应用进行适配。



**变更影响**

基于此前版本开发的应用，需适配变更接口。变更前的接口会出现告警，虽然可以通过编译，但是已经不能正常使用其功能。



**关键的接口/组件变更**

- 涉及接口

  interface PushParameterForStage {
    owner: Want;
    target: Want;
    name: string;
    data: KVObject;
    extraData: KVObject;
    jsonPath?: string;
  }

  function push(param: PushParameterForStage, callback: AsyncCallback<void>): void;

  interface RequestParameterForStage {
    owner: Want;
    target: Want;
    name: string;
    data: KVObject;
    jsonPath?: string;
  }

  function request(param: RequestParameterForStage, callback: AsyncCallback<RequestCallbackParameters>): void;

- 变更前：

```js
  interface PushParameterForStage {
    owner: Want;
    want: Want;
    name: string;
    data: KVObject;
    extraData: KVObject;
    jsonPath?: string;
  }

  function push(param: PushParameterForStage, callback: AsyncCallback<void>): void;

  interface RequestParameterForStage {
    owner: Want;
    want: Want;
    name: string;
    data: KVObject;
    jsonPath?: string;
  }

  function request(param: RequestParameterForStage, callback: AsyncCallback<RequestCallbackParameters>): void;
```

- 变更后：

```js
  interface PushParameterForStage {
    owner: Want;
    target: Want;
    name: string;
    data: KVObject;
    extraData: KVObject;
    jsonPath?: string;
  }

  function push(param: PushParameterForStage, callback: AsyncCallback<void>): void;

  interface RequestParameterForStage {
    owner: Want;
    target: Want;
    name: string;
    data: KVObject;
    jsonPath?: string;
  }

  function request(param: RequestParameterForStage, callback: AsyncCallback<RequestCallbackParameters>): void;
```

**适配指导**

使用变更后的接口，示例代码如下：

- 变更前：
```js
import pluginComponentManager from '@ohos.pluginComponent'

pluginComponentManager.push({
    owner:{
          bundleName:"com.example.provider",
          abilityName:"com.example.provider.MainAbility"
    },
    want: {
        bundleName: "com.example.provider",
        abilityName: "com.example.provider.MainAbility",
    },
    name: "ets/pages/plugin2.js",
    data: {
        "js": "ets/pages/plugin.js",
        "key_1": 1111,
    },
    extraData: {
        "extra_str": "this is push event"
    },
    jsonPath: "",
  },
    (err, data) => {
        console.log("push_callback:err: " ,JSON.stringify(err));
        console.log("push_callback:data: " , JSON.stringify(data));
        console.log("push_callback: push ok!");
    }
)

pluginComponentManager.request({
    owner:{
        bundleName:"com.example.provider",
        abilityName:"com.example.provider.MainAbility"
    },
    want: {
        bundleName: "com.example.provider",
        abilityName: "ets/pages/plugin2.js",
    },
    name: "plugintemplate",
    data: {
        "key_1": " myapplication plugin component test",
        "key_2": 123456
    },
    jsonPath: "",
},
    (err, data) => {
            console.log("request_callback: componentTemplate.ability=" + data.componentTemplate.ability)
            console.log("request_callback: componentTemplate.source=" + data.componentTemplate.source)
    }
)
```

- 变更后：
```js
import pluginComponentManager from '@ohos.pluginComponent'

pluginComponentManager.push({
    owner:{
          bundleName:"com.example.provider",
          abilityName:"com.example.provider.MainAbility"
    },
    target: {
        bundleName: "com.example.provider",
        abilityName: "com.example.provider.MainAbility",
    },
    name: "ets/pages/plugin2.js",
    data: {
        "js": "ets/pages/plugin.js",
        "key_1": 1111,
    },
    extraData: {
        "extra_str": "this is push event"
    },
    jsonPath: "",
  },
    (err, data) => {
        console.log("push_callback:err: " ,JSON.stringify(err));
        console.log("push_callback:data: " , JSON.stringify(data));
        console.log("push_callback: push ok!");
    }
)

pluginComponentManager.request({
    owner:{
        bundleName:"com.example.provider",
        abilityName:"com.example.provider.MainAbility"
    },
    target: {
        bundleName: "com.example.provider",
        abilityName: "ets/pages/plugin2.js",
    },
    name: "plugintemplate",
    data: {
        "key_1": " myapplication plugin component test",
        "key_2": 123456
    },
    jsonPath: "",
},
    (err, data) => {
            console.log("request_callback: componentTemplate.ability=" + data.componentTemplate.ability)
            console.log("request_callback: componentTemplate.source=" + data.componentTemplate.source)
    }
)
```
