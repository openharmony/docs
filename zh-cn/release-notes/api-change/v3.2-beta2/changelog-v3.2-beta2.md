# 3.2 beta2相对3.2 beta1变更详细说明

## 启用应用沙箱机制

基于namespace机制强化OpenHarmony应用数据安全，建立应用沙盒机制，增加目录可见性数据访问防线，减少了应用数据和用户隐私信息泄露，建立了更加严格安全的应用沙盒隔离能力。
同时也解决了目录混乱、文件访问方式多途径造成的文件管理的垃圾文件、文件混乱等体验问题和并发稳定性问题。

**变更影响**

OpenHarmony启用应用沙箱机制后，所有被appspawn进程孵化的应用访问资源会受到应用沙箱的限制。
如果应用没有适配应用沙箱的文件访问模型，则会导致应用功能异常。
应用对于/data目录下文件的访问，需要将所有硬编码路径访问的方式调整为使用context接口访问，具体请见[适配流程](application-sandbox-adaptation-guide.md#适配流程)。

**关键的接口/组件变更**

OpenHarmony应用沙箱组件

**适配指导**

请参考[适配指导](application-sandbox-adaptation-guide.md)。

## 增加对于自定义组件Struct的编译校验

**变更1**：自定义组件Struct的生命周期函数（比如aboutToAppear）不能使用private修饰。

**变更影响**

旧版本只有编辑器做了校验，新版本编译也加了校验报错。

**关键的接口/组件变更**

无

**适配指导**

当出现以下情况时，将private修饰去掉，即可通过编译。

![](figures/compile-change1-1.png)

![](figures/compile-change1-2.png)

**变更2**：自定义组件Struct的成员属性不能和内置属性方法名重名。

**变更影响**

与内置属性方法名重名的Struct的成员属性无法通过校验。

**关键的接口/组件变更**

无

**适配指导**

当出现以下情况时，修改属性名，使其与内置属性方法名不重名。

![](figures/compile-change2-1.png)

![](figures/compile-change2-2.png)
