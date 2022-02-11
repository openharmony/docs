# Reminder Agent<a name="EN-US_TOPIC_0000001158696346"></a>

>**NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Applicable Devices<a name="section16881239114912"></a>

<a name="table857714145377"></a>
<table><thead align="left"><tr id="row55778146373"><th class="cellrowborder" valign="top" width="24.257574242575743%" id="mcps1.1.5.1.1"><p id="p7577141417376"><a name="p7577141417376"></a><a name="p7577141417376"></a>Phone</p>
</th>
<th class="cellrowborder" valign="top" width="25.5974402559744%" id="mcps1.1.5.1.2"><p id="p487719816463"><a name="p487719816463"></a><a name="p487719816463"></a>Tablet</p>
</th>
<th class="cellrowborder" valign="top" width="25.147485251474855%" id="mcps1.1.5.1.3"><p id="p135771614203720"><a name="p135771614203720"></a><a name="p135771614203720"></a>Smart TV</p>
</th>
<th class="cellrowborder" valign="top" width="24.997500249975%" id="mcps1.1.5.1.4"><p id="p25772014133712"><a name="p25772014133712"></a><a name="p25772014133712"></a>Wearable</p>
</th>
</tr>
</thead>
<tbody><tr id="row8578151423715"><td class="cellrowborder" valign="top" width="24.257574242575743%" headers="mcps1.1.5.1.1 "><p id="p65782014203718"><a name="p65782014203718"></a><a name="p65782014203718"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25.5974402559744%" headers="mcps1.1.5.1.2 "><p id="p137739557452"><a name="p137739557452"></a><a name="p137739557452"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25.147485251474855%" headers="mcps1.1.5.1.3 "><p id="p26978547459"><a name="p26978547459"></a><a name="p26978547459"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="24.997500249975%" headers="mcps1.1.5.1.4 "><p id="p1893114512453"><a name="p1893114512453"></a><a name="p1893114512453"></a>Yes</p>
</td>
</tr>
</tbody>
</table>

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import reminderAgent from '@ohos.reminderAgent';
```

## Required Permissions<a name="section11257113618419"></a>

ohos.permission.PUBLISH\_AGENT\_REMINDER

## reminderAgent.publishReminder<a name="section192192415554"></a>

publishReminder\(reminderReq: ReminderRequest, callback: AsyncCallback<number\>\): void

Publishes an agent-powered reminder. This method uses an asynchronous callback to return the published reminder's ID.

-   Parameters

    <a name="table552833562419"></a>
    <table><thead align="left"><tr id="row149668318915_1"><th class="cellrowborder" valign="top" width="14.820000000000002%" id="mcps1.1.5.1.1"><p id="p653073517241"><a name="p653073517241"></a><a name="p653073517241"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.950000000000003%" id="mcps1.1.5.1.2"><p id="p1853017357240"><a name="p1853017357240"></a><a name="p1853017357240"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.970000000000002%" id="mcps1.1.5.1.3"><p id="p12530153562416"><a name="p12530153562416"></a><a name="p12530153562416"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.260000000000005%" id="mcps1.1.5.1.4"><p id="p17531173542420"><a name="p17531173542420"></a><a name="p17531173542420"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914_1"><td class="cellrowborder" valign="top" width="14.820000000000002%" headers="mcps1.1.5.1.1 "><p id="p1953114358246"><a name="p1953114358246"></a><a name="p1953114358246"></a>reminderReq</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.950000000000003%" headers="mcps1.1.5.1.2 "><p id="p125321335162419"><a name="p125321335162419"></a><a name="p125321335162419"></a><a href="#section351144413217">ReminderRequest</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="16.970000000000002%" headers="mcps1.1.5.1.3 "><p id="p20532133542419"><a name="p20532133542419"></a><a name="p20532133542419"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p7533153542413"><a name="p7533153542413"></a><a name="p7533153542413"></a>Reminder to be published.</p>
    </td>
    </tr>
    <tr id="row18967831393_1"><td class="cellrowborder" valign="top" width="14.820000000000002%" headers="mcps1.1.5.1.1 "><p id="p19533535132417"><a name="p19533535132417"></a><a name="p19533535132417"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.950000000000003%" headers="mcps1.1.5.1.2 "><p id="p05341035122417"><a name="p05341035122417"></a><a name="p05341035122417"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.970000000000002%" headers="mcps1.1.5.1.3 "><p id="p18534235142412"><a name="p18534235142412"></a><a name="p18534235142412"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.260000000000005%" headers="mcps1.1.5.1.4 "><p id="p12534335162410"><a name="p12534335162410"></a><a name="p12534335162410"></a>Asynchronous callback used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    export default {
        data: {
            timer: {
                reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
                triggerTimeInSeconds: 3
            }
        },
        startTimer() {
            reminderAgent.publishReminder(timer, (err, reminderId) => {
                console.log("reminderId = " + reminderId);
            });
        }
    }
    ```


## reminderAgent.publishReminder<a name="section01485631611"></a>

publishReminder\(reminderReq: ReminderRequest\): Promise<number\>

Publishes an agent-powered reminder. This method uses a promise callback to return the published reminder's ID.

-   Parameters

    <a name="table17452145512178"></a>
    <table><thead align="left"><tr id="row545235520177"><th class="cellrowborder" valign="top" width="14.81%" id="mcps1.1.5.1.1"><p id="p17452155131715"><a name="p17452155131715"></a><a name="p17452155131715"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.850000000000001%" id="mcps1.1.5.1.2"><p id="p2452105519172"><a name="p2452105519172"></a><a name="p2452105519172"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.879999999999999%" id="mcps1.1.5.1.3"><p id="p14452955121711"><a name="p14452955121711"></a><a name="p14452955121711"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="55.46%" id="mcps1.1.5.1.4"><p id="p1145295512176"><a name="p1145295512176"></a><a name="p1145295512176"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row104521255121719"><td class="cellrowborder" valign="top" width="14.81%" headers="mcps1.1.5.1.1 "><p id="p345235519176"><a name="p345235519176"></a><a name="p345235519176"></a>reminderReq</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="p12452165591710"><a name="p12452165591710"></a><a name="p12452165591710"></a><a href="#section351144413217">ReminderRequest</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="15.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p345325517172"><a name="p345325517172"></a><a name="p345325517172"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.46%" headers="mcps1.1.5.1.4 "><p id="p17453655181710"><a name="p17453655181710"></a><a name="p17453655181710"></a>Reminder to be published.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table8453175520171"></a>
    <table><thead align="left"><tr id="row1245355510178"><th class="cellrowborder" valign="top" width="16.49%" id="mcps1.1.3.1.1"><p id="p111061550175217"><a name="p111061550175217"></a><a name="p111061550175217"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="83.50999999999999%" id="mcps1.1.3.1.2"><p id="p54532557176"><a name="p54532557176"></a><a name="p54532557176"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row194530559171"><td class="cellrowborder" valign="top" width="16.49%" headers="mcps1.1.3.1.1 "><p id="p6106250165212"><a name="p6106250165212"></a><a name="p6106250165212"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.50999999999999%" headers="mcps1.1.3.1.2 "><p id="p3453185521713"><a name="p3453185521713"></a><a name="p3453185521713"></a>Promise used to return the result.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    export default {
        data: {
            timer: {
                reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
                triggerTimeInSeconds: 3
            }
        },
        startTimer() {
            reminderAgent.publishReminder(this.timer).then((reminderId) => {
                console.log("reminderId = " + reminderId);
            });
        }
    }
    ```


## reminderAgent.cancelReminder<a name="section1499919239817"></a>

cancelReminder\(reminderId: number, callback: AsyncCallback<void\>\): void

Cancels the reminder with the specified ID. This method uses an asynchronous callback to return the cancellation result.

-   Parameters

<a name="table1552512311910"></a>
<table><thead align="left"><tr id="row155261223298"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p14766356916"><a name="p14766356916"></a><a name="p14766356916"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="24.560000000000002%" id="mcps1.1.5.1.2"><p id="p137619351911"><a name="p137619351911"></a><a name="p137619351911"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25.44%" id="mcps1.1.5.1.3"><p id="p15761335196"><a name="p15761335196"></a><a name="p15761335196"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p207653514912"><a name="p207653514912"></a><a name="p207653514912"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row9526723692"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1526523397"><a name="p1526523397"></a><a name="p1526523397"></a>reminderId</p>
</td>
<td class="cellrowborder" valign="top" width="24.560000000000002%" headers="mcps1.1.5.1.2 "><p id="p1526023792"><a name="p1526023792"></a><a name="p1526023792"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25.44%" headers="mcps1.1.5.1.3 "><p id="p1652613231193"><a name="p1652613231193"></a><a name="p1652613231193"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p8526323195"><a name="p8526323195"></a><a name="p8526323195"></a>ID of the reminder to cancel.</p>
</td>
</tr>
<tr id="row2526102316910"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p42419381017"><a name="p42419381017"></a><a name="p42419381017"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="24.560000000000002%" headers="mcps1.1.5.1.2 "><p id="p32413316101"><a name="p32413316101"></a><a name="p32413316101"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25.44%" headers="mcps1.1.5.1.3 "><p id="p20241237108"><a name="p20241237108"></a><a name="p20241237108"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p10241193191015"><a name="p10241193191015"></a><a name="p10241193191015"></a>Asynchronous callback used to return the result.</p>
</td>
</tr>
</tbody>
</table>

-   Example

```
export default {
    cancel() { 
        reminderAgent.cancelReminder(1, (err, data) => {
            console.log("do next");
        });
    }
}
```

## reminderAgent.cancelReminder<a name="section12314647135615"></a>

cancelReminder\(reminderId: number\): Promise<void\>

Cancels the reminder with the specified ID. This method uses a promise to return the cancellation result.

-   Parameters

<a name="table155132817584"></a>
<table><thead align="left"><tr id="row65511428165816"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p9551112875817"><a name="p9551112875817"></a><a name="p9551112875817"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p1655112285580"><a name="p1655112285580"></a><a name="p1655112285580"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p955119288584"><a name="p955119288584"></a><a name="p955119288584"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p1055118285589"><a name="p1055118285589"></a><a name="p1055118285589"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row13552192814585"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p355272875812"><a name="p355272875812"></a><a name="p355272875812"></a>reminderId</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p1155212287589"><a name="p1155212287589"></a><a name="p1155212287589"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p6552182811589"><a name="p6552182811589"></a><a name="p6552182811589"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p15521284588"><a name="p15521284588"></a><a name="p15521284588"></a>ID of the reminder to cancel.</p>
</td>
</tr>
</tbody>
</table>

-   Return values

<a name="table146386141918"></a>
<table><thead align="left"><tr id="row8638214612"><th class="cellrowborder" valign="top" width="16.49%" id="mcps1.1.3.1.1"><p id="p1363871412117"><a name="p1363871412117"></a><a name="p1363871412117"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="83.50999999999999%" id="mcps1.1.3.1.2"><p id="p156381514110"><a name="p156381514110"></a><a name="p156381514110"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row9638161420117"><td class="cellrowborder" valign="top" width="16.49%" headers="mcps1.1.3.1.1 "><p id="p106382141716"><a name="p106382141716"></a><a name="p106382141716"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="83.50999999999999%" headers="mcps1.1.3.1.2 "><p id="p9638101412116"><a name="p9638101412116"></a><a name="p9638101412116"></a>Promise used to return the result.</p>
</td>
</tr>
</tbody>
</table>

-   Example

```
export default {
    cancel() {
        reminderAgent.cancelReminder(1).then(() => {
            console.log("do next");
        });
    }
}
```

## reminderAgent.getValidReminders<a name="section1132713911215"></a>

getValidReminders\(callback: AsyncCallback<Array<ReminderRequest\>\>\): void

Obtains all valid \(not yet expired\) reminders set by the current application. This method uses an asynchronous callback to return the reminders.

-   Parameters

<a name="table178891222111215"></a>
<table><thead align="left"><tr id="row1589513222126"><th class="cellrowborder" valign="top" width="19.470000000000002%" id="mcps1.1.5.1.1"><p id="p7279112691218"><a name="p7279112691218"></a><a name="p7279112691218"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.53%" id="mcps1.1.5.1.2"><p id="p11279132611126"><a name="p11279132611126"></a><a name="p11279132611126"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p19279142611217"><a name="p19279142611217"></a><a name="p19279142611217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p132791526191220"><a name="p132791526191220"></a><a name="p132791526191220"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row188961221122"><td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.1 "><p id="p154501725111319"><a name="p154501725111319"></a><a name="p154501725111319"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="30.53%" headers="mcps1.1.5.1.2 "><p id="p545020254138"><a name="p545020254138"></a><a name="p545020254138"></a>AsyncCallback&lt;Array&lt;<a href="#section351144413217">ReminderRequest</a>&gt;&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p3450102511131"><a name="p3450102511131"></a><a name="p3450102511131"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p9450122531318"><a name="p9450122531318"></a><a name="p9450122531318"></a>Asynchronous callback used to return an array of all valid reminders set by the current application.</p>
</td>
</tr>
</tbody>
</table>

-   Example

```
reminderAgent.getValidReminders((err, reminders) => {
    for (let i = 0; i < reminders.length; i++) {
        console.log("getValidReminders = " + reminders[i]);
        console.log("getValidReminders, reminderType = " + reminders[i].reminderType);
        for (let j = 0; j < reminders[i].actionButton.length; j++) {
            console.log("getValidReminders, actionButton.title = " + reminders[i].actionButton[j].title);
            console.log("getValidReminders, actionButton.type = " + reminders[i].actionButton[j].type);
        }
        console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent.pkgName);
        console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent.abilityName);
        console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent.pkgName);
        console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent.abilityName);
        console.log("getValidReminders, ringDuration = " + reminders[i].ringDuration);
        console.log("getValidReminders, snoozeTimes = " + reminders[i].snoozeTimes);
        console.log("getValidReminders, timeInterval = " + reminders[i].timeInterval);
        console.log("getValidReminders, title = " + reminders[i].title);
        console.log("getValidReminders, content = " + reminders[i].content);
        console.log("getValidReminders, expiredContent = " + reminders[i].expiredContent);
        console.log("getValidReminders, snoozeContent = " + reminders[i].snoozeContent);
        console.log("getValidReminders, notificationId = " + reminders[i].notificationId);
        console.log("getValidReminders, slotType = " + reminders[i].slotType);
    }
})
```

## reminderAgent.getValidReminders<a name="section43649405310"></a>

getValidReminders\(\): Promise<Array<ReminderRequest\>\>

Obtains all valid \(not yet expired\) reminders set by the current application. This method uses a promise to return the reminders.

-   Return values

<a name="table187080176416"></a>
<table><thead align="left"><tr id="row770816172041"><th class="cellrowborder" valign="top" width="35.42%" id="mcps1.1.3.1.1"><p id="p931203175318"><a name="p931203175318"></a><a name="p931203175318"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="64.58%" id="mcps1.1.3.1.2"><p id="p157099171145"><a name="p157099171145"></a><a name="p157099171145"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row970914171947"><td class="cellrowborder" valign="top" width="35.42%" headers="mcps1.1.3.1.1 "><p id="p15311231145316"><a name="p15311231145316"></a><a name="p15311231145316"></a>Promise&lt;Array&lt;<a href="#section351144413217">ReminderRequest</a>&gt;&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="64.58%" headers="mcps1.1.3.1.2 "><p id="p5709101715414"><a name="p5709101715414"></a><a name="p5709101715414"></a>Promise used to return an array of all valid reminders set by the current application.</p>
</td>
</tr>
</tbody>
</table>

-   Example

```
reminderAgent.getValidReminders().then((reminders) => {    
    for (let i = 0; i < reminders.length; i++) {
        console.log("getValidReminders = " + reminders[i]);
        console.log("getValidReminders, reminderType = " + reminders[i].reminderType);
        for (let j = 0; j < reminders[i].actionButton.length; j++) {
            console.log("getValidReminders, actionButton.title = " + reminders[i].actionButton[j].title);
            console.log("getValidReminders, actionButton.type = " + reminders[i].actionButton[j].type);
        }
        console.log("getValidReminders, wantAgent.pkgName = " + reminders[i].wantAgent.pkgName);
        console.log("getValidReminders, wantAgent.abilityName = " + reminders[i].wantAgent.abilityName);
        console.log("getValidReminders, maxScreenWantAgent.pkgName = " + reminders[i].maxScreenWantAgent.pkgName);
        console.log("getValidReminders, maxScreenWantAgent.abilityName = " + reminders[i].maxScreenWantAgent.abilityName);
        console.log("getValidReminders, ringDuration = " + reminders[i].ringDuration);
        console.log("getValidReminders, snoozeTimes = " + reminders[i].snoozeTimes);
        console.log("getValidReminders, timeInterval = " + reminders[i].timeInterval);
        console.log("getValidReminders, title = " + reminders[i].title);
        console.log("getValidReminders, content = " + reminders[i].content);
        console.log("getValidReminders, expiredContent = " + reminders[i].expiredContent);
        console.log("getValidReminders, snoozeContent = " + reminders[i].snoozeContent);
        console.log("getValidReminders, notificationId = " + reminders[i].notificationId);
        console.log("getValidReminders, slotType = " + reminders[i].slotType);
    }
})
```

## reminderAgent.cancelAllReminders<a name="section45271040171518"></a>

cancelAllReminders\(callback: AsyncCallback<void\>\): void

Cancels all reminders set by the current application. This method uses an asynchronous callback to return the cancellation result.

-   Parameters

<a name="table534005201614"></a>
<table><thead align="left"><tr id="row1834055141618"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p1662742420169"><a name="p1662742420169"></a><a name="p1662742420169"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p16272247164"><a name="p16272247164"></a><a name="p16272247164"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p146271924151612"><a name="p146271924151612"></a><a name="p146271924151612"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p46276248164"><a name="p46276248164"></a><a name="p46276248164"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row634025131612"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1374893112168"><a name="p1374893112168"></a><a name="p1374893112168"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p12748531141615"><a name="p12748531141615"></a><a name="p12748531141615"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p7748531111615"><a name="p7748531111615"></a><a name="p7748531111615"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p13748123131616"><a name="p13748123131616"></a><a name="p13748123131616"></a>Asynchronous callback used to return the result.</p>
</td>
</tr>
</tbody>
</table>

-   Example

```
reminderAgent.cancelAllReminders((err, data) =>{ 
    console.log("do next")}
)
```

## reminderAgent.cancelAllReminders<a name="section995114367166"></a>

cancelAllReminders\(\): Promise<void\>

Cancels all reminders set by the current application. This method uses a promise to return the cancellation result.

-   Return values

<a name="table29095131310"></a>
<table><thead align="left"><tr id="row12909161310318"><th class="cellrowborder" valign="top" width="16.49%" id="mcps1.1.3.1.1"><p id="p14909141310317"><a name="p14909141310317"></a><a name="p14909141310317"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="83.50999999999999%" id="mcps1.1.3.1.2"><p id="p99097132317"><a name="p99097132317"></a><a name="p99097132317"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row790913131530"><td class="cellrowborder" valign="top" width="16.49%" headers="mcps1.1.3.1.1 "><p id="p1790912131337"><a name="p1790912131337"></a><a name="p1790912131337"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="83.50999999999999%" headers="mcps1.1.3.1.2 "><p id="p10909141313310"><a name="p10909141313310"></a><a name="p10909141313310"></a>Promise used to return the result.</p>
</td>
</tr>
</tbody>
</table>

-   Example

```
reminderAgent.cancelAllReminders().then(() => {
    console.log("do next")}
)
```

## reminderAgent.addNotificationSlot<a name="section5438241287"></a>

addNotificationSlot\(slot: NotificationSlot, callback: AsyncCallback<void\>\): void

Adds a reminder notification slot. This method uses an asynchronous callback to return the result.

-   Parameters

<a name="table35415101896"></a>
<table><thead align="left"><tr id="row19548100916"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p20542107919"><a name="p20542107919"></a><a name="p20542107919"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p4548106917"><a name="p4548106917"></a><a name="p4548106917"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p05410105910"><a name="p05410105910"></a><a name="p05410105910"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p1054101017911"><a name="p1054101017911"></a><a name="p1054101017911"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row35416101090"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p3542103919"><a name="p3542103919"></a><a name="p3542103919"></a>slot</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p75441016916"><a name="p75441016916"></a><a name="p75441016916"></a><a href="../nottoctopics/en-us_topic_0000001180018813.md#section1382174172015">NotificationSlot</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p1754181020915"><a name="p1754181020915"></a><a name="p1754181020915"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p13541510592"><a name="p13541510592"></a><a name="p13541510592"></a>Reminder notification slot to add.</p>
</td>
</tr>
<tr id="row8545101292"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1754910498"><a name="p1754910498"></a><a name="p1754910498"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p11541310397"><a name="p11541310397"></a><a name="p11541310397"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p3548101192"><a name="p3548101192"></a><a name="p3548101192"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p9553101593"><a name="p9553101593"></a><a name="p9553101593"></a>Asynchronous callback used to return the result.</p>
</td>
</tr>
</tbody>
</table>

-   Example

```
export default {
    data: {
        mySlot: {
            type: 3,
            sound: "/sdcard/music2.mp3"
        }
    },
    addSlot() {
        reminderAgent.addNotificationSlot(this.mySlot, (err, data) => {
            console.log("do next");
        });
    }
}
```

## reminderAgent.addNotificationSlot<a name="section9578138886"></a>

addNotificationSlot\(slot: NotificationSlot\): Promise<void\>

Adds a reminder notification slot. This method uses a promise to return the result.

-   Parameters

<a name="table144984401798"></a>
<table><thead align="left"><tr id="row204981240997"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p94982040897"><a name="p94982040897"></a><a name="p94982040897"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p549904010913"><a name="p549904010913"></a><a name="p549904010913"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p94999405911"><a name="p94999405911"></a><a name="p94999405911"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p1549924017914"><a name="p1549924017914"></a><a name="p1549924017914"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row949919401498"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p449911401493"><a name="p449911401493"></a><a name="p449911401493"></a>slot</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p114991540996"><a name="p114991540996"></a><a name="p114991540996"></a><a href="../nottoctopics/en-us_topic_0000001180018813.md#section1382174172015">NotificationSlot</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p04991140690"><a name="p04991140690"></a><a name="p04991140690"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p6499114013913"><a name="p6499114013913"></a><a name="p6499114013913"></a>Reminder notification slot to add.</p>
</td>
</tr>
</tbody>
</table>

-   Return values

<a name="table8952481825"></a>
<table><thead align="left"><tr id="row129527818213"><th class="cellrowborder" valign="top" width="16.49%" id="mcps1.1.3.1.1"><p id="p5952789213"><a name="p5952789213"></a><a name="p5952789213"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="83.50999999999999%" id="mcps1.1.3.1.2"><p id="p199526812214"><a name="p199526812214"></a><a name="p199526812214"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row8952198027"><td class="cellrowborder" valign="top" width="16.49%" headers="mcps1.1.3.1.1 "><p id="p15952281027"><a name="p15952281027"></a><a name="p15952281027"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="83.50999999999999%" headers="mcps1.1.3.1.2 "><p id="p69521686215"><a name="p69521686215"></a><a name="p69521686215"></a>Promise used to return the result.</p>
</td>
</tr>
</tbody>
</table>

-   Example

```
export default {
    data: {
        mySlot: {
            type: 3,
            sound: "/sdcard/music2.mp3"
        }
    },
    addSlot() {
        reminderAgent.addNotificationSlot(this.mySlot).then(() => {
            console.log("do next");
        });
    }
}
```

## reminderAgent.removeNotificationSlot<a name="section690314291188"></a>

removeNotificationSlot\(slotType: notification.SlotType, callback: AsyncCallback<void\>\): void

Removes a  **NotificationSlot**  instance of a specified type. This method uses an asynchronous callback to return the result.

-   Parameters

<a name="table18836121111196"></a>
<table><thead align="left"><tr id="row1283611161918"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p11229116171910"><a name="p11229116171910"></a><a name="p11229116171910"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p172294165191"><a name="p172294165191"></a><a name="p172294165191"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p422941611194"><a name="p422941611194"></a><a name="p422941611194"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p1122910168192"><a name="p1122910168192"></a><a name="p1122910168192"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row48371611201912"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p583701119198"><a name="p583701119198"></a><a name="p583701119198"></a>slotType</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p283751171916"><a name="p283751171916"></a><a name="p283751171916"></a><a href="../nottoctopics/en-us_topic_0000001180018813.md#section072355105110">notification.SlotType</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p2083731110197"><a name="p2083731110197"></a><a name="p2083731110197"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p38371711181913"><a name="p38371711181913"></a><a name="p38371711181913"></a>Type of the reminder notification slot to remove.</p>
</td>
</tr>
<tr id="row483718118198"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p106321702208"><a name="p106321702208"></a><a name="p106321702208"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p186324012019"><a name="p186324012019"></a><a name="p186324012019"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p263210012203"><a name="p263210012203"></a><a name="p263210012203"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p13632804203"><a name="p13632804203"></a><a name="p13632804203"></a>Asynchronous callback used to return the result.</p>
</td>
</tr>
</tbody>
</table>

-   Example

```
export default {
    removeSlot() {        
        reminderAgent.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION, (err, data) => {
            console.log("do next");
        });
    }
}
```

## reminderAgent.removeNotificationSlot<a name="section7370189151011"></a>

removeNotificationSlot\(slotType: notification.SlotType\): Promise<void\>

Removes a  **NotificationSlot**  instance of a specified type. This method uses a promise to return the result.

-   Parameters

<a name="table12207123541011"></a>
<table><thead align="left"><tr id="row142073350105"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p1720712352109"><a name="p1720712352109"></a><a name="p1720712352109"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p720719355109"><a name="p720719355109"></a><a name="p720719355109"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p1720793591014"><a name="p1720793591014"></a><a name="p1720793591014"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p72077353109"><a name="p72077353109"></a><a name="p72077353109"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row120720355108"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1120893520105"><a name="p1120893520105"></a><a name="p1120893520105"></a>slotType</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p22081435141018"><a name="p22081435141018"></a><a name="p22081435141018"></a><a href="../nottoctopics/en-us_topic_0000001180018813.md#section072355105110">notification.SlotType</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p920813531010"><a name="p920813531010"></a><a name="p920813531010"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p72081335131013"><a name="p72081335131013"></a><a name="p72081335131013"></a>Type of the reminder notification slot to remove.</p>
</td>
</tr>
</tbody>
</table>

-   Return values

<a name="table993713301926"></a>
<table><thead align="left"><tr id="row493714301427"><th class="cellrowborder" valign="top" width="16.49%" id="mcps1.1.3.1.1"><p id="p17937430426"><a name="p17937430426"></a><a name="p17937430426"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="83.50999999999999%" id="mcps1.1.3.1.2"><p id="p1493712301211"><a name="p1493712301211"></a><a name="p1493712301211"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row119371130229"><td class="cellrowborder" valign="top" width="16.49%" headers="mcps1.1.3.1.1 "><p id="p139372301324"><a name="p139372301324"></a><a name="p139372301324"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="83.50999999999999%" headers="mcps1.1.3.1.2 "><p id="p159379302215"><a name="p159379302215"></a><a name="p159379302215"></a>Promise used to return the result.</p>
</td>
</tr>
</tbody>
</table>

-   Example

```
export default {
    removeSlot() {     
        reminderAgent.removeNotificationSlot(notification.SlotType.CONTENT_INFORMATION).then(() => {
            console.log("do next");
        });
    }
}
```

## ActionButtonType<a name="section099619567453"></a>

Enumerates button types.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="a3d0fc780cc904c1cbab7991251622f65"><a name="a3d0fc780cc904c1cbab7991251622f65"></a><a name="a3d0fc780cc904c1cbab7991251622f65"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="aace9cae4ba0d4939bfa048460f61c3c7"><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="afec895de33f94e3c87ee7acc20190a17"><a name="afec895de33f94e3c87ee7acc20190a17"></a><a name="afec895de33f94e3c87ee7acc20190a17"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p52851329122117"><a name="p52851329122117"></a><a name="p52851329122117"></a>ACTION_BUTTON_TYPE_CLOSE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p2282152962115"><a name="p2282152962115"></a><a name="p2282152962115"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p328012293211"><a name="p328012293211"></a><a name="p328012293211"></a>Button for closing the reminder.</p>
</td>
</tr>
<tr id="row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p12106173918219"><a name="p12106173918219"></a><a name="p12106173918219"></a>ACTION_BUTTON_TYPE_SNOOZE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1310553911218"><a name="p1310553911218"></a><a name="p1310553911218"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p15865395215"><a name="p15865395215"></a><a name="p15865395215"></a>Button for snoozing the reminder.</p>
</td>
</tr>
</tbody>
</table>

## ReminderType<a name="section2657271303"></a>

Enumerates reminder types.

<a name="table2900133119415"></a>
<table><thead align="left"><tr id="row19067314413"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p179062311742"><a name="p179062311742"></a><a name="p179062311742"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p29062313419"><a name="p29062313419"></a><a name="p29062313419"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p09061317413"><a name="p09061317413"></a><a name="p09061317413"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1290613318410"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p99062311246"><a name="p99062311246"></a><a name="p99062311246"></a>REMINDER_TYPE_TIMER</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1890618311647"><a name="p1890618311647"></a><a name="p1890618311647"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p19068314416"><a name="p19068314416"></a><a name="p19068314416"></a>Countdown reminder.</p>
</td>
</tr>
<tr id="row19906631841"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p119061831645"><a name="p119061831645"></a><a name="p119061831645"></a>REMINDER_TYPE_CALENDAR</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p29067311648"><a name="p29067311648"></a><a name="p29067311648"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1212482762"><a name="p1212482762"></a><a name="p1212482762"></a>Calendar reminder.</p>
</td>
</tr>
<tr id="row13209436251"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p19215133613519"><a name="p19215133613519"></a><a name="p19215133613519"></a>REMINDER_TYPE_ALARM</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p18215183620512"><a name="p18215183620512"></a><a name="p18215183620512"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p3768321467"><a name="p3768321467"></a><a name="p3768321467"></a>Alarm reminder.</p>
</td>
</tr>
</tbody>
</table>

## ActionButton<a name="section256244135613"></a>

Defines a button displayed in the reminder notification.

<a name="table0103172561814"></a>
<table><thead align="left"><tr id="row12103152513185"><th class="cellrowborder" valign="top" width="15.3015301530153%" id="mcps1.1.5.1.1"><p id="p1610322561817"><a name="p1610322561817"></a><a name="p1610322561817"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="14.891489148914891%" id="mcps1.1.5.1.2"><p id="p20103132551816"><a name="p20103132551816"></a><a name="p20103132551816"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.561056105610561%" id="mcps1.1.5.1.3"><p id="p1103172518188"><a name="p1103172518188"></a><a name="p1103172518188"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.245924592459254%" id="mcps1.1.5.1.4"><p id="p19103125141812"><a name="p19103125141812"></a><a name="p19103125141812"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row201031125101812"><td class="cellrowborder" valign="top" width="15.3015301530153%" headers="mcps1.1.5.1.1 "><p id="p293518218251"><a name="p293518218251"></a><a name="p293518218251"></a>title</p>
</td>
<td class="cellrowborder" valign="top" width="14.891489148914891%" headers="mcps1.1.5.1.2 "><p id="p39351925253"><a name="p39351925253"></a><a name="p39351925253"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.561056105610561%" headers="mcps1.1.5.1.3 "><p id="p8935162182512"><a name="p8935162182512"></a><a name="p8935162182512"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p109351224253"><a name="p109351224253"></a><a name="p109351224253"></a>Text on the button.</p>
</td>
</tr>
<tr id="row750201314232"><td class="cellrowborder" valign="top" width="15.3015301530153%" headers="mcps1.1.5.1.1 "><p id="p5501413112313"><a name="p5501413112313"></a><a name="p5501413112313"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="14.891489148914891%" headers="mcps1.1.5.1.2 "><p id="p7501313142310"><a name="p7501313142310"></a><a name="p7501313142310"></a><a href="#section099619567453">ActionButtonType</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.561056105610561%" headers="mcps1.1.5.1.3 "><p id="p550141313239"><a name="p550141313239"></a><a name="p550141313239"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p197354308819"><a name="p197354308819"></a><a name="p197354308819"></a>Button type.</p>
</td>
</tr>
</tbody>
</table>

## WantAgent<a name="section1225014446367"></a>

Sets the package and ability that are redirected to when the reminder notification is clicked.

<a name="table189723718371"></a>
<table><thead align="left"><tr id="row1410333716376"><th class="cellrowborder" valign="top" width="17.49%" id="mcps1.1.5.1.1"><p id="p1835875816376"><a name="p1835875816376"></a><a name="p1835875816376"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17.599999999999998%" id="mcps1.1.5.1.2"><p id="p161031537183718"><a name="p161031537183718"></a><a name="p161031537183718"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="21.97%" id="mcps1.1.5.1.3"><p id="p15103133743715"><a name="p15103133743715"></a><a name="p15103133743715"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="42.94%" id="mcps1.1.5.1.4"><p id="p17103537133712"><a name="p17103537133712"></a><a name="p17103537133712"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row6103113719375"><td class="cellrowborder" valign="top" width="17.49%" headers="mcps1.1.5.1.1 "><p id="p1110319371371"><a name="p1110319371371"></a><a name="p1110319371371"></a>pkgName</p>
</td>
<td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.2 "><p id="p13103837173713"><a name="p13103837173713"></a><a name="p13103837173713"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.97%" headers="mcps1.1.5.1.3 "><p id="p111038377378"><a name="p111038377378"></a><a name="p111038377378"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="42.94%" headers="mcps1.1.5.1.4 "><p id="p11032371372"><a name="p11032371372"></a><a name="p11032371372"></a>Name of the package redirected to when the reminder notification is clicked.</p>
</td>
</tr>
<tr id="row1010313376379"><td class="cellrowborder" valign="top" width="17.49%" headers="mcps1.1.5.1.1 "><p id="p10103137163715"><a name="p10103137163715"></a><a name="p10103137163715"></a>abilityName</p>
</td>
<td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.2 "><p id="p131031237103713"><a name="p131031237103713"></a><a name="p131031237103713"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="21.97%" headers="mcps1.1.5.1.3 "><p id="p910353793716"><a name="p910353793716"></a><a name="p910353793716"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="42.94%" headers="mcps1.1.5.1.4 "><p id="p110323723719"><a name="p110323723719"></a><a name="p110323723719"></a>Name of the ability that is redirected to when the reminder notification is clicked.</p>
</td>
</tr>
</tbody>
</table>

## MaxScreenWantAgent<a name="section442031712444"></a>

Sets the name of the target package and ability to start automatically when the reminder arrives and the device is not in use. If the device is in use, a notification will be displayed.

<a name="table5665154184414"></a>
<table><thead align="left"><tr id="row667004164415"><th class="cellrowborder" valign="top" width="15.22%" id="mcps1.1.5.1.1"><p id="p067875154419"><a name="p067875154419"></a><a name="p067875154419"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="15.21%" id="mcps1.1.5.1.2"><p id="p1067895112446"><a name="p1067895112446"></a><a name="p1067895112446"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.3"><p id="p166784511444"><a name="p166784511444"></a><a name="p166784511444"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="52.56999999999999%" id="mcps1.1.5.1.4"><p id="p166784518445"><a name="p166784518445"></a><a name="p166784518445"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row10671124114440"><td class="cellrowborder" valign="top" width="15.22%" headers="mcps1.1.5.1.1 "><p id="p1641510290476"><a name="p1641510290476"></a><a name="p1641510290476"></a>pkgName</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.2 "><p id="p941516290477"><a name="p941516290477"></a><a name="p941516290477"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.3 "><p id="p134158295472"><a name="p134158295472"></a><a name="p134158295472"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.56999999999999%" headers="mcps1.1.5.1.4 "><p id="p06713419449"><a name="p06713419449"></a><a name="p06713419449"></a>Name of the package that is automatically started when the reminder arrives and the device is not in use.</p>
</td>
</tr>
<tr id="row1767164104416"><td class="cellrowborder" valign="top" width="15.22%" headers="mcps1.1.5.1.1 "><p id="p1415182918479"><a name="p1415182918479"></a><a name="p1415182918479"></a>abilityName</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.2 "><p id="p9415142974718"><a name="p9415142974718"></a><a name="p9415142974718"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.3 "><p id="p1441502944718"><a name="p1441502944718"></a><a name="p1441502944718"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.56999999999999%" headers="mcps1.1.5.1.4 "><p id="p1067124114413"><a name="p1067124114413"></a><a name="p1067124114413"></a>Name of the ability that is automatically started when the reminder arrives and the device is not in use.</p>
</td>
</tr>
</tbody>
</table>

## ReminderRequest<a name="section351144413217"></a>

Defines the reminder to publish.

<a name="table1290341511316"></a>
<table><thead align="left"><tr id="row89081015834"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p15182016319"><a name="p15182016319"></a><a name="p15182016319"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p4117201531"><a name="p4117201531"></a><a name="p4117201531"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="15.21%" id="mcps1.1.5.1.3"><p id="p91132015318"><a name="p91132015318"></a><a name="p91132015318"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="34.79%" id="mcps1.1.5.1.4"><p id="p4116201939"><a name="p4116201939"></a><a name="p4116201939"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row19096154313"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p17909121519315"><a name="p17909121519315"></a><a name="p17909121519315"></a>reminderType</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p119096151035"><a name="p119096151035"></a><a name="p119096151035"></a>ReminderType</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p1890916151932"><a name="p1890916151932"></a><a name="p1890916151932"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p189097154319"><a name="p189097154319"></a><a name="p189097154319"></a>Type of the reminder.</p>
</td>
</tr>
<tr id="row4909111515313"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p79090155314"><a name="p79090155314"></a><a name="p79090155314"></a>actionButton</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p690913152319"><a name="p690913152319"></a><a name="p690913152319"></a>[ActionButton?, ActionButton?]</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p109096151136"><a name="p109096151136"></a><a name="p109096151136"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p290916157310"><a name="p290916157310"></a><a name="p290916157310"></a>Action button displayed in the reminder notification. (The parameter is optional. Up to two buttons are supported.)</p>
</td>
</tr>
<tr id="row18909415537"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p10909215036"><a name="p10909215036"></a><a name="p10909215036"></a>wantAgent</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p1790917151030"><a name="p1790917151030"></a><a name="p1790917151030"></a>WantAgent</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p690918155311"><a name="p690918155311"></a><a name="p690918155311"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p39099154310"><a name="p39099154310"></a><a name="p39099154310"></a>Information about the ability that is redirected to when the notification is clicked.</p>
</td>
</tr>
<tr id="row290961515313"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p59094154320"><a name="p59094154320"></a><a name="p59094154320"></a>maxScreenWantAgent</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p15909161517314"><a name="p15909161517314"></a><a name="p15909161517314"></a>MaxScreenWantAgent</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p1286714720714"><a name="p1286714720714"></a><a name="p1286714720714"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p1590971511318"><a name="p1590971511318"></a><a name="p1590971511318"></a>Information about the ability that is automatically started when the reminder arrives. If the device is in use, a notification will be displayed.</p>
</td>
</tr>
<tr id="row8909715730"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1890918151311"><a name="p1890918151311"></a><a name="p1890918151311"></a>ringDuration</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p59091515030"><a name="p59091515030"></a><a name="p59091515030"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p1889171471"><a name="p1889171471"></a><a name="p1889171471"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p0909815932"><a name="p0909815932"></a><a name="p0909815932"></a>Ringing duration.</p>
</td>
</tr>
<tr id="row189091151637"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p490919153316"><a name="p490919153316"></a><a name="p490919153316"></a>snoozeTimes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p13909181514311"><a name="p13909181514311"></a><a name="p13909181514311"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p292087771"><a name="p292087771"></a><a name="p292087771"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p09101215435"><a name="p09101215435"></a><a name="p09101215435"></a>Number of reminder snooze times.</p>
</td>
</tr>
<tr id="row1691016154310"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p15910151518311"><a name="p15910151518311"></a><a name="p15910151518311"></a>timeInterval</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p59100152035"><a name="p59100152035"></a><a name="p59100152035"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p59381172719"><a name="p59381172719"></a><a name="p59381172719"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p1891016151332"><a name="p1891016151332"></a><a name="p1891016151332"></a>Reminder snooze interval.</p>
</td>
</tr>
<tr id="row66171484413"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p06261381549"><a name="p06261381549"></a><a name="p06261381549"></a>title</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p1962612820413"><a name="p1962612820413"></a><a name="p1962612820413"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p495618718720"><a name="p495618718720"></a><a name="p495618718720"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p3626380410"><a name="p3626380410"></a><a name="p3626380410"></a>Reminder title.</p>
</td>
</tr>
<tr id="row0463331249"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1946733249"><a name="p1946733249"></a><a name="p1946733249"></a>content</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p04616336415"><a name="p04616336415"></a><a name="p04616336415"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p4973672710"><a name="p4973672710"></a><a name="p4973672710"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p11461533349"><a name="p11461533349"></a><a name="p11461533349"></a>Reminder content.</p>
</td>
</tr>
<tr id="row93248291645"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p63301829549"><a name="p63301829549"></a><a name="p63301829549"></a>expiredContent</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p233012291047"><a name="p233012291047"></a><a name="p233012291047"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p1298567671"><a name="p1298567671"></a><a name="p1298567671"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p1133019297412"><a name="p1133019297412"></a><a name="p1133019297412"></a>Content to be displayed after the reminder expires.</p>
</td>
</tr>
<tr id="row34302231744"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1443614231246"><a name="p1443614231246"></a><a name="p1443614231246"></a>snoozeContent</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p74365234411"><a name="p74365234411"></a><a name="p74365234411"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p499627179"><a name="p499627179"></a><a name="p499627179"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p144369238411"><a name="p144369238411"></a><a name="p144369238411"></a>Content to be displayed when the reminder is snoozing.</p>
</td>
</tr>
<tr id="row540852612412"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p34081726541"><a name="p34081726541"></a><a name="p34081726541"></a>notificationId</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p2408426148"><a name="p2408426148"></a><a name="p2408426148"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p14848475"><a name="p14848475"></a><a name="p14848475"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p1408226147"><a name="p1408226147"></a><a name="p1408226147"></a>Notification ID used by the reminder. If there are reminders with the same notification ID, the later one will overwrite the earlier one.</p>
</td>
</tr>
<tr id="row47993181141"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p198054189418"><a name="p198054189418"></a><a name="p198054189418"></a>slotType</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p18805318844"><a name="p18805318844"></a><a name="p18805318844"></a><a href="../nottoctopics/en-us_topic_0000001180018813.md#section072355105110">notification.SlotType</a></p>
</td>
<td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p162610811713"><a name="p162610811713"></a><a name="p162610811713"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="34.79%" headers="mcps1.1.5.1.4 "><p id="p38051918641"><a name="p38051918641"></a><a name="p38051918641"></a>Type of the slot used by the reminder.</p>
</td>
</tr>
</tbody>
</table>

## ReminderRequestCalendar<a name="section91823641810"></a>

ReminderRequestCalendar extends ReminderRequest

Defines a reminder for a calendar event.

<a name="table1348794314217"></a>
<table><thead align="left"><tr id="row9493164312218"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p814317512211"><a name="p814317512211"></a><a name="p814317512211"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p191435510217"><a name="p191435510217"></a><a name="p191435510217"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p114310513214"><a name="p114310513214"></a><a name="p114310513214"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p1514345102118"><a name="p1514345102118"></a><a name="p1514345102118"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row11493184352111"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p15493114310215"><a name="p15493114310215"></a><a name="p15493114310215"></a>dateTime</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p949412434212"><a name="p949412434212"></a><a name="p949412434212"></a><a href="#section89511926203615">LocalDateTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p20494184362111"><a name="p20494184362111"></a><a name="p20494184362111"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p54942043142112"><a name="p54942043142112"></a><a name="p54942043142112"></a>Reminder time.</p>
</td>
</tr>
<tr id="row1849434312114"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1849454342114"><a name="p1849454342114"></a><a name="p1849454342114"></a>repeatMonths</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p5494194352117"><a name="p5494194352117"></a><a name="p5494194352117"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p184941143112110"><a name="p184941143112110"></a><a name="p184941143112110"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p1949464352118"><a name="p1949464352118"></a><a name="p1949464352118"></a>Month in which the reminder repeats.</p>
</td>
</tr>
<tr id="row1049415430216"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p114941243132113"><a name="p114941243132113"></a><a name="p114941243132113"></a>repeatDays</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p1549434315212"><a name="p1549434315212"></a><a name="p1549434315212"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p1349414432218"><a name="p1349414432218"></a><a name="p1349414432218"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p18494164317214"><a name="p18494164317214"></a><a name="p18494164317214"></a>Date on which the reminder repeats.</p>
</td>
</tr>
</tbody>
</table>

## ReminderRequestAlarm<a name="section1195619282246"></a>

ReminderRequestAlarm extends ReminderRequest

Defines a reminder for the alarm clock.

<a name="table2536135232411"></a>
<table><thead align="left"><tr id="row10542195232417"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p10944125614245"><a name="p10944125614245"></a><a name="p10944125614245"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p11944105662411"><a name="p11944105662411"></a><a name="p11944105662411"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p149441568241"><a name="p149441568241"></a><a name="p149441568241"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p1494412560242"><a name="p1494412560242"></a><a name="p1494412560242"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row75421252122412"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p45421952152415"><a name="p45421952152415"></a><a name="p45421952152415"></a>hour</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p15421152172418"><a name="p15421152172418"></a><a name="p15421152172418"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p18542165212416"><a name="p18542165212416"></a><a name="p18542165212416"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p654235218243"><a name="p654235218243"></a><a name="p654235218243"></a>Hour portion of the reminder time.</p>
</td>
</tr>
<tr id="row195427528245"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p16542115212419"><a name="p16542115212419"></a><a name="p16542115212419"></a>minute</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p6542552202417"><a name="p6542552202417"></a><a name="p6542552202417"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p55421152172415"><a name="p55421152172415"></a><a name="p55421152172415"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p1254265213248"><a name="p1254265213248"></a><a name="p1254265213248"></a>Minute portion of the reminder time.</p>
</td>
</tr>
<tr id="row10542752132419"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p155421952112417"><a name="p155421952112417"></a><a name="p155421952112417"></a>daysOfWeek</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p154295292414"><a name="p154295292414"></a><a name="p154295292414"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p5542185212410"><a name="p5542185212410"></a><a name="p5542185212410"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p125422524244"><a name="p125422524244"></a><a name="p125422524244"></a>Days of a week when the reminder repeats.</p>
</td>
</tr>
</tbody>
</table>

## ReminderRequestTimer<a name="section383902012275"></a>

Defines a  **ReminderRequestTimer**  instance, which extends  **ReminderRequest**.

Defines a reminder for a scheduled timer.

<a name="table16410183917272"></a>
<table><thead align="left"><tr id="row11416103915275"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p28631117296"><a name="p28631117296"></a><a name="p28631117296"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p108632102910"><a name="p108632102910"></a><a name="p108632102910"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p286314116295"><a name="p286314116295"></a><a name="p286314116295"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p98631811291"><a name="p98631811291"></a><a name="p98631811291"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1241643916276"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p8416139132718"><a name="p8416139132718"></a><a name="p8416139132718"></a>triggerTimeInSeconds</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p174162039172719"><a name="p174162039172719"></a><a name="p174162039172719"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p1241693916278"><a name="p1241693916278"></a><a name="p1241693916278"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p7416133915270"><a name="p7416133915270"></a><a name="p7416133915270"></a>Number of seconds in the countdown timer.</p>
</td>
</tr>
</tbody>
</table>

## LocalDateTime<a name="section89511926203615"></a>

Sets the time information for a calendar reminder.

<a name="table2073374723614"></a>
<table><thead align="left"><tr id="row373424723619"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p12446655133620"><a name="p12446655133620"></a><a name="p12446655133620"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p144625543610"><a name="p144625543610"></a><a name="p144625543610"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p16446655123612"><a name="p16446655123612"></a><a name="p16446655123612"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p114461755133614"><a name="p114461755133614"></a><a name="p114461755133614"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4734164773613"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p173454718366"><a name="p173454718366"></a><a name="p173454718366"></a>year</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p3734447143614"><a name="p3734447143614"></a><a name="p3734447143614"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p4734247113610"><a name="p4734247113610"></a><a name="p4734247113610"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p16734124783614"><a name="p16734124783614"></a><a name="p16734124783614"></a>Year.</p>
</td>
</tr>
<tr id="row11734194723614"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p6734124717362"><a name="p6734124717362"></a><a name="p6734124717362"></a>month</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p573424710363"><a name="p573424710363"></a><a name="p573424710363"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p094429163719"><a name="p094429163719"></a><a name="p094429163719"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p373418475366"><a name="p373418475366"></a><a name="p373418475366"></a>Month.</p>
</td>
</tr>
<tr id="row7734114712363"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p157347473362"><a name="p157347473362"></a><a name="p157347473362"></a>day</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p1972412153716"><a name="p1972412153716"></a><a name="p1972412153716"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p10110122973716"><a name="p10110122973716"></a><a name="p10110122973716"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p773534733618"><a name="p773534733618"></a><a name="p773534733618"></a>Date.</p>
</td>
</tr>
<tr id="row0735134753616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p10735124718366"><a name="p10735124718366"></a><a name="p10735124718366"></a>hour</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p5751142117378"><a name="p5751142117378"></a><a name="p5751142117378"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p112512298377"><a name="p112512298377"></a><a name="p112512298377"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p15735144743613"><a name="p15735144743613"></a><a name="p15735144743613"></a>Hour.</p>
</td>
</tr>
<tr id="row11735247103620"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p1473554717364"><a name="p1473554717364"></a><a name="p1473554717364"></a>minute</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p4786921183715"><a name="p4786921183715"></a><a name="p4786921183715"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p151411029133719"><a name="p151411029133719"></a><a name="p151411029133719"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p147356473363"><a name="p147356473363"></a><a name="p147356473363"></a>Minute.</p>
</td>
</tr>
<tr id="row5735347113619"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p107351847113615"><a name="p107351847113615"></a><a name="p107351847113615"></a>second</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p108021121103713"><a name="p108021121103713"></a><a name="p108021121103713"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p1173554743616"><a name="p1173554743616"></a><a name="p1173554743616"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p773574753611"><a name="p773574753611"></a><a name="p773574753611"></a>Second.</p>
</td>
</tr>
</tbody>
</table>

