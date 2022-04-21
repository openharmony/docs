# 代码管理规范


AI引擎框架包含client、server和common三个主要模块，其中client提供server端连接管理功能，北向SDK在算法对外接口中需封装调用client提供的公共接口；server提供插件加载以及任务管理等功能，各Plugin实现由server提供的插件接口，完成插件接入；common提供与平台相关的操作方法、引擎协议以及相关工具类，供其他各模块调用。


AI引擎框架各模块之间的代码依赖关系如下图所示：


  **图1** AI引擎代码依赖关系

  ![zh-cn_image_0000001151931738](figures/zh-cn_image_0000001151931738.jpg)


## 建议：插件与北向SDK在AI引擎指定的路径下进行代码开发

在AI引擎框架的整体规划中，北向SDK属于client端的一部分，插件由server端调用，属于server端的一部分，因此AI引擎框架为接入的插件与北向SDK规划的路径：

- SDK代码路径：//foundation/ai/engine/services/client/algorithm_sdk
  e.g. //foundation/ai/engine/services/client/algorithm_sdk/cv

  e.g. //foundation/ai/engine/services/client/algorithm_sdk/nlu

- 插件代码路径：//foundation/ai/engine/services/server/plugin
  e.g. //foundation/ai/engine/services/server/plugin/cv

  e.g. //foundation/ai/engine/services/server/plugin/nlu


## 规则：插件提供的全部对外接口，统一存放在AI业务子系统interfaces/kits目录

北向SDK对外接口是AI业务子系统提供能力的对外暴露方式，按照OpenHarmony的接口管理要求，需统一存放在各子系统的interfaces/kits目录中。当前AI业务子系统插件对外接口路径为//foundation/ai/engine/interfaces/kits，不同插件可在该路径下添加目录，比如增加cv插件，则在路径//foundation/ai/engine/interfaces/kits/cv下面存放接口文件。


## 规则：插件编译输出路径必须是在/usr/lib

server端加载插件是采用dlopen方式，只支持在/usr/lib路径进行，因此插件在编译so时，需要在编译配置文件中指定输出路径为/usr/lib。
