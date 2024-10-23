# 在build-profile.json5中配置arkOptions

## 配置文件标签

  **表1** arkOptions的types字段配置文件标签说明 

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| -------- | -------- | -------- | -------- |
| types | 通过types字段将指定的类型声明文件作为全局引入，从而避免在每个源码文件中单独引入 | 数组 | 该标签可缺省，缺省值为空 |

## arkOptions中的types字段配置说明

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

*注意：*

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