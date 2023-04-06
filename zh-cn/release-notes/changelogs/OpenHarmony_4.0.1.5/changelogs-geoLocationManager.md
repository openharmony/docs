# 位置服务子系统ChangeLog

## cl.location.1 删除API9接口geoLocationManager.requestEnableLocation

在位置开关关闭的场景下，应用可以调用geoLocationManager.requestEnableLocation接口，以请求用户开启位置开关；实际该接口使用较少，并且该接口用户体验不太好，并没有告诉用户该应用在什么场景下使用位置信息。

因此变更为由应用本身弹框请求用户跳转到settings开启位置开关，并且在弹框上写清楚会在什么场景下使用位置信息，这样用户体验更好。

**变更影响**

在API9上应用无法使用geoLocationManager.requestEnableLocation请求用户开启位置开关，需要应用自己实现弹框，请求用户开启位置开关。

**关键的接口/组件变更**

| 类名 | 接口类型 | 接口声明 | 变更类型 | 
|  -- | -- | -- | -- |
|geoLocationManager| method | function requestEnableLocation(callback: AsyncCallback&lt;boolean&gt;): void; | 该接口从API9中删除  | 
|geoLocationManager| method | function requestEnableLocation(): Promise&lt;boolean&gt;; | 该接口从API9中删除  | 
