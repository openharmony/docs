# arkui子系统ChangeLog

## cl.arkui.1 xcomponent组件接口变更

arkui子系统xcomponent组件接口存在变更：

 - 去除getXComponentSurfaceId和setXComponentSurfaceSize接口的@systemapi标签
 - 指定getXComponentSurfaceId，getXComponentContext和setXComponentSurfaceSize接口的返回值类型

开发者需要根据以下说明对应用进行适配。


**变更影响**

影响已发布的JS接口，应用需要进行适配才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**

 - getXComponentSurfaceId：改为public接口，指定返回值类型为string
 - setXComponentSurfaceSize：改为public接口，指定返回值类型为void
 - getXComponentContext：指定返回值类型为Object

**适配指导**

不同场景下的启动规则说明如下：
开发者适配内容：

  - **getXComponentSurfaceId**
    - OpenHarmony 3.2-beta3 版本规则：
      - 系统接口systemapi。
      - 未指定返回值
    - OpenHarmony 3.2-Beta4 版本新规则：
      - 公共接口。
      - 指定返回值类型为string
      - 开发者需要按照string类型处理返回值
  - **setXComponentSurfaceSize**
    - OpenHarmony 3.2-beta3 版本规则：
      - 系统接口systemapi。
      - 未指定返回值
    - OpenHarmony 3.2-Beta4 版本新规则：
      - 公共接口。
      - 指定返回值类型为void
      - 开发者需要按照void类型处理返回值
  - **getXComponentContext**
    - OpenHarmony 3.2-beta3 版本规则：
      - 未指定返回值
    - OpenHarmony 3.2-Beta4 版本新规则：
      - 指定返回值类型为Object
      - 开发者需要按照Object类型处理返回值
        