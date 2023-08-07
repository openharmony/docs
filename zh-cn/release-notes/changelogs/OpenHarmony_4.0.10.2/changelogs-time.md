# 时间时区子系统ChangeLog

## cl.time.1 setTime、setDate、setTimezone接口新增权限校验

此前版本设置时间、设置日期及设置时区接口对调用方只进行系统API校验，未进行权限校验，存在安全风险，不符合OpenHarmony的API接口规范。
现做出如下变更：
  - 调用方使用setTime方法前需提前申请"ohos.permission.SET_TIME"权限。
  - 调用方使用setDate方法前需提前申请"ohos.permission.SET_TIME"权限。
  - 调用方使用setTimezone方法前需提前申请"ohos.permission.SET_TIME_ZONE"权限。

**变更影响**

基于此前版本开发的应用，需提前申请相应权限，否则无法正常调用接口，影响原有业务逻辑。

**关键的接口/组件变更**

涉及接口

  - systemDateTime.setTime;
  - systemDateTime.setDate;
  - systemDateTime.setTimezone;

变更前：
  - 接口无需任何权限限制可正常调用。

变更后：
  - 接口需要申请相应权限才可正常调用，若权限使用有误，将返回201表示权限否定异常。

**适配指导**

调用setTime、setDate、setTimezone接口时，需申请相应的权限才可正常使用。
