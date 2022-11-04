## 申请能效资源

### 场景说明

在实际的系统中，存在一些重要性高的系统应用，虽然此类应用相比普通应用具有一定的特权，但为了进一步平衡系统的功耗开销，这些应用同样需要支持在后台可被挂起。但对于系统特权应用，为了避免挂起后重要功能受到影响，提供了独立的能效资源申请接口，使这些特权应用可以在后台执行一些特殊的任务和使用特定的系统资源，例如在被挂起期间如果仍然希望能够收到系统公共事件，可以使用能效资源接口向系统申请使用公共事件资源。

对于需要升级为特权应用的，开发者需要合理评估自己的业务诉求，向应用中心提出申请。

### 接口说明

**表1** 申请能效资源主要接口

| 接口名                                      | 描述                                       |
| ---------------------------------------- | ---------------------------------------- |
| applyEfficiencyResources(request: [EfficiencyResourcesRequest](../reference/apis/js-apis-backgroundTaskManager.md#efficiencyresourcesrequest9)): boolean | 申请能效资源。 |
| resetAllEfficiencyResources():void | 释放申请的能效资源。   |


### 开发步骤

1、当特权应用需要在后台使用特殊资源时。向系统申请目标资源。

2、当资源使用完毕，需要及时释放。支持释放部分资源或全部资源。

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';

// 申请能效资源
let request = {
    resourceTypes: backgroundTaskManager.ResourceType.COMMON_EVENT |
        backgroundTaskManager.ResourceType.TIMER,
    isApply: true,
    timeOut: 0,
    reason: "apply",
    isPersist: true,
    isProcess: true,
};
let res = backgroundTaskManager.applyEfficiencyResources(request);
console.info("the result of request is: " + res);

// 释放部分资源
request = {
    resourceTypes: backgroundTaskManager.ResourceType.COMMON_EVENT,
    isApply: false,
    timeOut: 0,
    reason: "reset",
};
res = backgroundTaskManager.applyEfficiencyResources(request);
console.info("the result of request is: " + res);

// 释放全部资源
backgroundTaskManager.resetAllEfficiencyResources();
```
