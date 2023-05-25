# 设备待机模块开发指南
## 设备待机模块概述
为提高设备续航，降低设备功耗，在设备进入待机空闲状态时，限制后台应用使用资源。开发者可以根据自身情况，为自己的应用申请纳入待机资源管控或者暂时不被待机资源管控。

## 待机低续航模式介绍
待机低续航模式会延迟应用后台cpu和网络活动，从而延长电池续航时间。
<br>包括：
<br>1.应用限网：限制应用访问网络
<br>2.work待机任务：延迟应用的work任务响应
<br>3.running_lock锁：释放应用申请的cpu running_lock锁
<br>4.Timer响应：延迟应用的timer响应
## 接口说明
[设备待机模块接口api开发文档](https://gitee.com/openharmony/docs/blob/4b89700885537543d26e2dfc96b4dee15a544229/zh-cn/application-dev/reference/apis/js-apis-resourceschedule-deviceStandby.md)

主要接口
| 接口                       | 说明 |
|--------------------------|----|
| isDeviceInStandby        |  查询应用是否处于待机空闲状态，如果处于空闲状态，该应用可能被纳入资源管控。  |
| getExemptedApps          | 获取不会被纳入待机资源管控的应用列表   |
| requestExemptionResource |  为应用申请暂时不会被纳入待机资源管控的能力  |
| releaseExemptionResource |  取消应用暂时不会被纳入待机资源管控能力  |