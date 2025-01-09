# 在build-profile.json5中配置arkOptions

## 概述

arkOptions主要提供ArkTS编译相关配置，当前文档介绍arkOptions中types配置类型、maxFlowDepth配置控制流分析最大栈深度等，arkOptions中的其他配置项请参考[build-profile.json5](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-hvigor-build-profile-V5)。

## types

### types配置文件标签说明

  arkOptions的types字段配置文件标签说明

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| types | 通过types字段将指定的类型声明文件作为全局引入，从而避免在每个源码文件中单独引入 | 数组 | 该标签可缺省，缺省值为空 |

### arkOptions中的types字段配置说明

arkOptions中types字段示例

在模块build-profile.json5配置文件buildOption标签的arkOptions属性中添加types字段。
```json
// 在/entry/build-profile.json5
{
  "arkOptions": {
    "types": ["chai", "./oh_modules/@types/mocha", "./src/main/ets/pages/global"]
  }
}
```

types字段支持填写包名、包所在位置的相对路径以及声明文件所在相对路径，仅支持当前模块内的查找，若目录下存在同名文件（后缀不同），默认加载顺序.d.ets > .d.ts。<br />
（1）填写包名方式：通过包名到oh_modules/@types/目录查找包名中定义的声明文件，如"chai"。<br />
（2）填写包所在相对路径方式：支持在基于build-profile.json5的相对路径中查找定义的声明文件，如"./oh_modules/@types/mocha"。<br />
（3）填写声明文件所在相对路径方式：支持查找相对路径下的声明文件，如"./src/main/ets/pages/global"。

### 注意事项

如果在types字段中填写包名或者包所在位置的相对路径，需要在工程文件/entry/oh-package.json5中dependencies作如下配置，
```json
"dependencies": {
  "@types/chai": "latest",
  "@types/mocha": "latest"
}
```

如果在types字段中填写声明文件所在相对路径，前提是在模块下存在相应的声明文件，比如模块下存在src/main/ets/pages/global.d.ts声明文件，声明文件内容如下所示：
```typescript
declare namespace Global {
  type ObjectType = string | number;
}
```

通过types全局引入后，对全局类型的使用示例如下：
```typescript
// 在entry/src/main/ets/pages/Index.ets
let a: Chai.Message;
let b: Mocha.HookFunction;
let c: Global.ObjectType;
```

## maxFlowDepth

### maxFlowDepth配置文件标签说明

  arkOptions下tscConfig中maxFlowDepth字段配置文件标签说明 

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| maxFlowDepth | 开发者通过maxFlowDepth字段自定义配置tsc编译过程中的tsc控制流分析最大栈，避免固定最大栈导致编译报栈问题，该配置项可配置的最小值为2000，可配置最大值为65535 | 数字型 | 该标签可缺省，缺省值时使用tsc控制流分析最大栈默认值2000 |

### arkOptions下的tscConfig中maxFlowDepth字段配置说明

arkOptions/tscConfig中maxFlowDepth字段展示
在工程级目录下的build-profile.json5配置文件buildOption标签的arkOptions/tscConfig属性中添加maxFlowDepth字段

```typescript
// 在工程名/build-profile.json5文件中
"arkOptions": {
  "tscConfig": {
    "maxFlowDepth": 2222
  }
}
```

### 注意事项

- 仅可在工程级目录下build-profile.json5文件中配置maxFlowDepth字段。
- 若开发者未对maxFlowDepth字段进行配置时，则该字段默认为2000；若开发者对maxFlowDepth字段配置的值超过可配置范围，则会出现编译构建相关报错。

  ```txt
   hvigor ERROR: Schema validate failed.
    Detail: Please check the following fields.
      {
         instancePath: 'app.products[0].buildOption.arkOptions.tscConfig.maxFlowDepth',
         keyword: 'maximum',
         params: { comparision: '<=', limit: 65535 },
         message: 'must be <= 65535',
         location: 'D:/工程名/build-profile.json5:行号:列号'
      }
  ```

- 如果代码中函数或者模块过长导致控制流分析深度大于或者等于该字段所配置/默认的值，则会终止控制流分析并且报错：The containing function or module body is too large for control flow analysis.