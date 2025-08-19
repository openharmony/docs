# PageAbility Lifecycle


The PageAbility lifecycle defines all states of a PageAbility, such as **INACTIVE**, **ACTIVE**, and **BACKGROUND**. The figure below shows the lifecycle state transition.

**Figure 1** PageAbility lifecycle

![page-ability-lifecycle](figures/page-ability-lifecycle.png)

**Table 1** PageAbility lifecycle states

| State| Description|
| -------- | -------- |
| UNINITIALIZED | The PageAbility is not initialized. This is a temporary state, from which a PageAbility changes directly to the **INITIAL** state upon its creation.|
| INITIAL | The PageAbility is initialized but not running. The PageAbility enters the **INACTIVE** state after it is started.|
| INACTIVE | The PageAbility is visible but does not gain focus.|
| ACTIVE | The PageAbility runs in the foreground and has focus.|
| BACKGROUND | The PageAbility runs in the background. After being re-activated, the PageAbility enters the **ACTIVE** state. After being destroyed, it enters the **INITIAL** state.|


You can implement the lifecycle callbacks (as described in the table below) in **app.js** or **app.ets**.


**Table 2** PageAbility lifecycle callbacks

| API| Description|
| -------- | -------- |
| onCreate() | Called when the ability is started for the first time. You can initialize the application in this callback.|
| onDestroy() | Called when the ability is destroyed. In this callback, you can make preparations for application exit, such as recycling resources and clearing the cache.|
| onActive() | Called when the ability is switched to the foreground and gains focus.|
| onInactive() | Called when the ability loses focus. An ability loses focus when it is about to enter the background state.|
| onShow() | Called when the ability is switched from the background to the foreground. In this case, the ability is visible to users.|
| onHide() | Called when the ability is switched from the foreground to the background. In this case, the ability is invisible to users.|


The following figure shows the relationship between lifecycle callbacks and lifecycle states of the PageAbility.

Figure 2 Relationship between lifecycle callbacks and lifecycle states

![fa-pageAbility-lifecycle](figures/fa-pageAbility-lifecycle.png)


> **NOTE**
>
> - The PageAbility lifecycle callbacks are synchronous.
> - The **app.js** file provides only the **onCreate** and **onDestroy** callbacks, and the **app.ets** file provides the full lifecycle callbacks.
