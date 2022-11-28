## Efficiency Resource Request Development

### When to Use

To further balance power consumption overhead of the system, privileged system applications can be suspended in the background as other applications. To ensure normal provisioning of important functions, efficiency resource APIs are provided for these applications so that they can execute special tasks and use specific system resources in the background. For example, if they want to receive common events when suspended, they can use the APIs to request the common event resources.

To upgrade your application as a privileged application, you must evaluate your service requirements and submit a request to the application center. The application center will determine whether to accept the request based on the conditions.

### Available APIs

**Table 1** Main APIs for efficiency resources

| API                                     | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| applyEfficiencyResources(request: [EfficiencyResourcesRequest](../reference/apis/js-apis-backgroundTaskManager.md#efficiencyresourcesrequest9)): boolean | Requests efficiency resources.|
| resetAllEfficiencyResources():void | Releases efficiency resources.  |


### How to Develop

1. When a privileged application in the background needs to use special resources, request the target resources from the system.

2. When the task is complete, release the resources in time. You can choose whether to release some or all resources.

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';

// Request efficiency resources.
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

// Release some efficiency resources.
request = {
    resourceTypes: backgroundTaskManager.ResourceType.COMMON_EVENT,
    isApply: false,
    timeOut: 0,
    reason: "reset",
};
res = backgroundTaskManager.applyEfficiencyResources(request);
console.info("the result of request is: " + res);

// Release all efficiency resources.
backgroundTaskManager.resetAllEfficiencyResources();
```

<!--no_check-->