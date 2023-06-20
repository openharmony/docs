# ArkUI Subsystem Changelog

## cl.arkui.1 Return Value Type Change of getInspectorTree

**Change Impact**

The code that uses the **getInspectorTree** API in versions earlier than OpenHarmony 3.2.10.7 must be adapted.

**Key API/Component Changes**

The return value of the **getInspectorTree** API is changed from the string type to the Object type.

**Adaptation Guide**

Adapt the code that takes the return value of **getInspectorTree** as a string.The sample code is as follows:

- Before change:

```typescript
console.info(getInspectorTree())
```

- After change:

```typescript
console.info(JSON.stringify(getInspectorTree())) 
```

## cl.arkui.2 Deprecation the forceRebuild Attribute of \<GridItem>

**Change Impact**

None. The attribute has no effect.

**Key API/Component Changes**

Deprecate the **forceRebuild** attribute of the **\<GridItem>** component.

**Adaptation Guide**

Delete the code that uses the **forceRebuild** attribute. This will not affect the functionality of the **\<GridItem>** component.

## cl.arkui.3 Plugin Module API Changes


### 1. API Change in the **PluginComponentTemplate** Module

Renamed the **ability** parameter **bundleName** to more clearly indicate the intended meaning.

You need to adapt your application.



**Change Impact**

The application developed based on earlier versions must be adapted to the change. Otherwise, build errors will occur.



**Key API/Component Changes**

- Involved APIs:

 interface PluginComponentTemplate {
  source: string;
  bundleName: string;
  }

  interface PluginComponentInterface {
  (value: { template: PluginComponentTemplate; data: any }): PluginComponentAttribute;
}

- Before change:

```js
 interface PluginComponentTemplate { source: string; ability: string; }
 interface PluginComponentInterface {
  (value: { template: PluginComponentTemplate; data: any }): PluginComponentAttribute; 
  }
```

- After change:

```js
 interface PluginComponentTemplate { source: string; bundleName: string; }
 interface PluginComponentInterface {
  (value: { template: PluginComponentTemplate; data: any }): PluginComponentAttribute; 
  }
```

**Adaptation Guide**

Use the new API. The sample code is as follows:

- Before change:
```js
PluginComponent({
    template: { source: 'plugincomponent1', ability: 'com.example.plugin' },
    data: { 'countDownStartValue': 'new countDownStartValue' }
}).size({ width: 500, height: 100 })
```

- After change:
```js
PluginComponent({
    template: { source: 'plugincomponent1', bundleName: 'com.example.plugin' },
    data: { 'countDownStartValue': 'new countDownStartValue' }
}).size({ width: 500, height: 100 })
```

### 2. API Change in the **pluginComponentManager** Module

Renamed the **want** parameter **target** to more clearly indicate the intended meaning.

You need to adapt your application.



**Change Impact**

The application developed based on earlier versions must be adapted to the change. Otherwise, alarms will arise. Though the build may be successful, the API will not work as intended.



**Key API/Component Changes**

- Involved APIs:

  interface PushParameterForStage {
    owner: Want;
    target: Want;
    name: string;
    data: KVObject;
    extraData: KVObject;
    jsonPath?: string;
  }

  function push(param: PushParameterForStage, callback: AsyncCallback\<void>): void;

  interface RequestParameterForStage {
    owner: Want;
    target: Want;
    name: string;
    data: KVObject;
    jsonPath?: string;
  }

  function request(param: RequestParameterForStage, callback: AsyncCallback\<RequestCallbackParameters>): void;

- Before change:

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

- After change:

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

**Adaptation Guide**

Use the new API. The sample code is as follows:

- Before change:
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

- After change:
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
