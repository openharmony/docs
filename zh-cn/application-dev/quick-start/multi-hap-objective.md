# 多HAP机制设计目标


- 方便开发者模块化的管理应用，好的应用一般都是模块化管理，模块之间属于松耦合关系。多HAP方便了开发者将业务划分成多个模块，每个模块放到独立的HAP中。例如支付类应用，有统一的主界面，主界面管理“扫一扫”、“收付款”、“消息”、“理财”等各个模块。其中主界面管理其他模块的逻辑在Entry包中实现，而“扫一扫”、“收付款”、“消息”和“理财”等模块在不同的Feature包中实现。可以同时开发多个Feature包，能够实现Feature包单独的开发测试，最终由Entry包统一集成Feature包的特性。

- 方便开发者将多HAP合理地组合并部署到不同的设备上。例如应用程序包含一个Entry包和两个Featrue包（Feature1和Feature2）。其中Entry包可以部署到设备A和设备B，Feature1只能部署到设备A，Feature2包只部署到设备B上，那么开发者就可以方便的组合Entry和Feature1部署到设备A上，组合Entry和Feature2部署到设备B上。


## 相关实例

针对多HAP开发，有以下相关实例可供参考：

- [多HAP（ArkTS）(API9)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Project/ApplicationHap/MultiHap)