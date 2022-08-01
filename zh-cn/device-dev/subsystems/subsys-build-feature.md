# 特性
### 特性配置规则

下面介绍feature的声明、定义以及使用方法。

- feature的声明

  在部件的bundle.json文件中通过feature_list来声明部件的feature列表，每个feature都必须以"**{部件名}**"开头。示例如下：

  ```
  {
    "name": "@ohos/xxx",
    "component": {
      "name": "partName",
      "subsystem": "subsystemName",
      "features": [
        "{partName}_feature_A"
      ]
    }
  }
  ```

       features中可以为部件声明多个feature。

- feature的定义

  在部件内可通过以下方式定义feature的默认值：

  ```
  declare_args() {
    {partName}_feature_A = true
  }
  ```

  该值是此部件的默认值，产品可以在部件列表中重载该feature的值。

  feature需给部件内多个模块使用时，建议把feature定义在部件的全局gni文件中，各个模块的BUILD.gn中import该gni文件。

- feature的使用

  BUILD.gn文件中可通过以下方式进行根据feature决定部分代码或模块参与编译：

  ```
  if ({partName}_feature_A) {
      sources += [ "xxx.c" ]
  }
  
  # 某个特性引入的依赖，需要通过该feature进行隔离
  if ({partName}_feature_A) {
      deps += [ "xxx" ]
      external_deps += [ "xxx" ]
  }
  
  # bundle.json中不支持if判断，如果bundle.json中包含的sub_component需要被裁减，可以定义group进行裁减判断
  group("testGroup") {
    deps = []
    if ({partName}_feature_A) {
      deps += [ "xxx" ]
    }
  }
  ```

  也可以通过以下方式为模块定义代码宏进行代码级差异化配置：

  ```
  if ({partName}_feature_A) {
      defines += ["FEATUREA_DEFINE"]
  }
  ```

