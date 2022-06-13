# Development Guidelines<a name="EN-US_TOPIC_0000001185364575"></a>

## When to Use<a name="section18502174174019"></a>

You can set your application to call the  **ReminderRequest**  class to create scheduled reminders for countdown timers, calendar events, and alarm clocks. When the created reminders are published, the timing and pop-up notification functions of your application will be taken over by the reminder agent in the background, even when your application is frozen or exits.

## Available APIs<a name="section1633115419401"></a>

**reminderAgent**  encapsulates the methods for publishing and canceling reminders.

**Table  1**  Major APIs in reminderAgent

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row34145016535"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p430944542010"><a name="p430944542010"></a><a name="p430944542010"></a>function publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback&lt;number&gt;): void;</p>
<p id="p830954512202"><a name="p830954512202"></a><a name="p830954512202"></a>function publishReminder(reminderReq: ReminderRequest): Promise&lt;number&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p13562171015712"><a name="p13562171015712"></a><a name="p13562171015712"></a>Publishes a scheduled reminder.</p>
<p id="p9591131611311"><a name="p9591131611311"></a><a name="p9591131611311"></a>The maximum number of valid notifications (excluding expired ones that will not pop up again) is 30 for one application and 2000 for the entire system.</p>
</td>
</tr>
<tr id="row1746172917474"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p44291637103317"><a name="p44291637103317"></a><a name="p44291637103317"></a>function cancelReminder(reminderId: number, callback: AsyncCallback&lt;void&gt;): void;</p>
<p id="p14430123714332"><a name="p14430123714332"></a><a name="p14430123714332"></a>function cancelReminder(reminderId: number): Promise&lt;void&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p3465939173317"><a name="p3465939173317"></a><a name="p3465939173317"></a>Cancels a specified reminder. (The value of <strong id="b83631346162614"><a name="b83631346162614"></a><a name="b83631346162614"></a>reminderId</strong> is obtained from the return value of <strong id="b236420465267"><a name="b236420465267"></a><a name="b236420465267"></a>publishReminder</strong>.)</p>
</td>
</tr>
<tr id="row10992232154714"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1989534943310"><a name="p1989534943310"></a><a name="p1989534943310"></a>function getValidReminders(callback: AsyncCallback&lt;Array&lt;ReminderRequest&gt;&gt;): void;</p>
<p id="p289513497333"><a name="p289513497333"></a><a name="p289513497333"></a>function getValidReminders(): Promise&lt;Array&lt;ReminderRequest&gt;&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p184651639143320"><a name="p184651639143320"></a><a name="p184651639143320"></a>Obtains all valid reminders set by the current application.</p>
</td>
</tr>
<tr id="row933265824817"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1061757123319"><a name="p1061757123319"></a><a name="p1061757123319"></a>function cancelAllReminders(callback: AsyncCallback&lt;void&gt;): void;</p>
<p id="p6615577336"><a name="p6615577336"></a><a name="p6615577336"></a>function cancelAllReminders(): Promise&lt;void&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p19451839143310"><a name="p19451839143310"></a><a name="p19451839143310"></a>Cancels all reminders set by the current application.</p>
</td>
</tr>
<tr id="row1241412130349"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p8882181819348"><a name="p8882181819348"></a><a name="p8882181819348"></a>function addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback&lt;void&gt;): void;</p>
<p id="p4882218173414"><a name="p4882218173414"></a><a name="p4882218173414"></a>function addNotificationSlot(slot: NotificationSlot): Promise&lt;void&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p142081320344"><a name="p142081320344"></a><a name="p142081320344"></a>Registers a <a href="../nottoctopics/en-us_topic_0000001180018813.md#section1382174172015">NotificationSlot</a> instance to be used by the reminder.</p>
</td>
</tr>
<tr id="row74014178349"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p12474202953413"><a name="p12474202953413"></a><a name="p12474202953413"></a>function removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback&lt;void&gt;): void;</p>
<p id="p174748294340"><a name="p174748294340"></a><a name="p174748294340"></a>function removeNotificationSlot(slotType: notification.SlotType): Promise&lt;void&gt;;</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1407141783410"><a name="p1407141783410"></a><a name="p1407141783410"></a>Removes a <a href="../nottoctopics/en-us_topic_0000001180018813.md#section1382174172015">NotificationSlot</a> instance of a specified type.</p>
</td>
</tr>
</tbody>
</table>

**ActionButtonType**  enumerates types of buttons displayed in a reminder notification.

**Table  2**  ActionButtonType enumeration

<a name="table8534712161513"></a>
<table><thead align="left"><tr id="row14540181231510"><th class="cellrowborder" valign="top" width="38.190000000000005%" id="mcps1.2.3.1.1"><p id="p1454718124159"><a name="p1454718124159"></a><a name="p1454718124159"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="61.809999999999995%" id="mcps1.2.3.1.2"><p id="p13547131219152"><a name="p13547131219152"></a><a name="p13547131219152"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row145471112121520"><td class="cellrowborder" valign="top" width="38.190000000000005%" headers="mcps1.2.3.1.1 "><p id="p25473122155"><a name="p25473122155"></a><a name="p25473122155"></a>ACTION_BUTTON_TYPE_CLOSE</p>
</td>
<td class="cellrowborder" valign="top" width="61.809999999999995%" headers="mcps1.2.3.1.2 "><p id="p13547161217154"><a name="p13547161217154"></a><a name="p13547161217154"></a>Close button, which can be tapped to stop the reminder alert tone, close the reminder notification, and cancel the reminder snoozing.</p>
</td>
</tr>
</tbody>
</table>

**ReminderType**  enumerates the reminder types.

**Table  3**  ReminderType enumeration

<a name="table486010552014"></a>
<table><thead align="left"><tr id="row2866856201"><th class="cellrowborder" valign="top" width="39.06%" id="mcps1.2.3.1.1"><p id="p986695162012"><a name="p986695162012"></a><a name="p986695162012"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="60.940000000000005%" id="mcps1.2.3.1.2"><p id="p1486620518202"><a name="p1486620518202"></a><a name="p1486620518202"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row786610513207"><td class="cellrowborder" valign="top" width="39.06%" headers="mcps1.2.3.1.1 "><p id="p13866125202014"><a name="p13866125202014"></a><a name="p13866125202014"></a>REMINDER_TYPE_TIMER</p>
</td>
<td class="cellrowborder" valign="top" width="60.940000000000005%" headers="mcps1.2.3.1.2 "><p id="p13866458201"><a name="p13866458201"></a><a name="p13866458201"></a>Countdown reminder.</p>
</td>
</tr>
<tr id="row186685122014"><td class="cellrowborder" valign="top" width="39.06%" headers="mcps1.2.3.1.1 "><p id="p0866453206"><a name="p0866453206"></a><a name="p0866453206"></a>REMINDER_TYPE_CALENDAR</p>
</td>
<td class="cellrowborder" valign="top" width="60.940000000000005%" headers="mcps1.2.3.1.2 "><p id="p128661457206"><a name="p128661457206"></a><a name="p128661457206"></a>Calendar reminder.</p>
</td>
</tr>
<tr id="row286616512011"><td class="cellrowborder" valign="top" width="39.06%" headers="mcps1.2.3.1.1 "><p id="p128664572016"><a name="p128664572016"></a><a name="p128664572016"></a>REMINDER_TYPE_ALARM</p>
</td>
<td class="cellrowborder" valign="top" width="60.940000000000005%" headers="mcps1.2.3.1.2 "><p id="p1786685122014"><a name="p1786685122014"></a><a name="p1786685122014"></a>Alarm reminder.</p>
</td>
</tr>
</tbody>
</table>

**ActionButton**  defines a button displayed in the reminder notification.

**Table  4**  ActionButton instance

<a name="table880311117225"></a>
<table><thead align="left"><tr id="row1480321118225"><th class="cellrowborder" valign="top" width="23.630000000000003%" id="mcps1.2.5.1.1"><p id="p1180321117222"><a name="p1180321117222"></a><a name="p1180321117222"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.81%" id="mcps1.2.5.1.2"><p id="p111051815193913"><a name="p111051815193913"></a><a name="p111051815193913"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.2.5.1.3"><p id="p765614597419"><a name="p765614597419"></a><a name="p765614597419"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="52.04%" id="mcps1.2.5.1.4"><p id="p1580412112223"><a name="p1580412112223"></a><a name="p1580412112223"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row28041711182219"><td class="cellrowborder" valign="top" width="23.630000000000003%" headers="mcps1.2.5.1.1 "><p id="p5804191132211"><a name="p5804191132211"></a><a name="p5804191132211"></a>title</p>
</td>
<td class="cellrowborder" valign="top" width="16.81%" headers="mcps1.2.5.1.2 "><p id="p8105161593916"><a name="p8105161593916"></a><a name="p8105161593916"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p7656659154110"><a name="p7656659154110"></a><a name="p7656659154110"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.04%" headers="mcps1.2.5.1.4 "><p id="p16804121112213"><a name="p16804121112213"></a><a name="p16804121112213"></a>Text on the button.</p>
</td>
</tr>
<tr id="row1080481114223"><td class="cellrowborder" valign="top" width="23.630000000000003%" headers="mcps1.2.5.1.1 "><p id="p8804811142212"><a name="p8804811142212"></a><a name="p8804811142212"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="16.81%" headers="mcps1.2.5.1.2 "><p id="p15105201573910"><a name="p15105201573910"></a><a name="p15105201573910"></a><a href="#table8534712161513">ActionButtonType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p196561059134118"><a name="p196561059134118"></a><a name="p196561059134118"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="52.04%" headers="mcps1.2.5.1.4 "><p id="p1080461192212"><a name="p1080461192212"></a><a name="p1080461192212"></a>Button type.</p>
</td>
</tr>
</tbody>
</table>

**WantAgent**  sets the package and ability that are redirected to when the reminder notification is clicked.

**Table  5**  WantAgent instance

<a name="table9490856350"></a>
<table><thead align="left"><tr id="row84962056352"><th class="cellrowborder" valign="top" width="23.917608239176083%" id="mcps1.2.5.1.1"><p id="p1849612519352"><a name="p1849612519352"></a><a name="p1849612519352"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.8983101689831%" id="mcps1.2.5.1.2"><p id="p1074419616402"><a name="p1074419616402"></a><a name="p1074419616402"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.2.5.1.3"><p id="p1281819114219"><a name="p1281819114219"></a><a name="p1281819114219"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="51.66483351664834%" id="mcps1.2.5.1.4"><p id="p7496125163511"><a name="p7496125163511"></a><a name="p7496125163511"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row114962512358"><td class="cellrowborder" valign="top" width="23.917608239176083%" headers="mcps1.2.5.1.1 "><p id="p15496856359"><a name="p15496856359"></a><a name="p15496856359"></a>pkgName</p>
</td>
<td class="cellrowborder" valign="top" width="16.8983101689831%" headers="mcps1.2.5.1.2 "><p id="p157445644017"><a name="p157445644017"></a><a name="p157445644017"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.2.5.1.3 "><p id="p17891915421"><a name="p17891915421"></a><a name="p17891915421"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="51.66483351664834%" headers="mcps1.2.5.1.4 "><p id="p24967514355"><a name="p24967514355"></a><a name="p24967514355"></a>Name of the package redirected to when the reminder notification is clicked.</p>
</td>
</tr>
<tr id="row5496135183515"><td class="cellrowborder" valign="top" width="23.917608239176083%" headers="mcps1.2.5.1.1 "><p id="p1449610533519"><a name="p1449610533519"></a><a name="p1449610533519"></a>abilityName</p>
</td>
<td class="cellrowborder" valign="top" width="16.8983101689831%" headers="mcps1.2.5.1.2 "><p id="p13744196164011"><a name="p13744196164011"></a><a name="p13744196164011"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.2.5.1.3 "><p id="p20815196420"><a name="p20815196420"></a><a name="p20815196420"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="51.66483351664834%" headers="mcps1.2.5.1.4 "><p id="p14966511359"><a name="p14966511359"></a><a name="p14966511359"></a>Name of the ability redirected to when the reminder notification is clicked.</p>
</td>
</tr>
</tbody>
</table>

**MaxScreenWantAgent**  sets the name of the target package and ability to start automatically when the reminder arrives and the device is not in use. If the device is in use, a notification will be displayed.

**Table  6**  MaxScreenWantAgent instance

<a name="table191319843714"></a>
<table><thead align="left"><tr id="row9131814374"><th class="cellrowborder" valign="top" width="24.44%" id="mcps1.2.5.1.1"><p id="p0131810372"><a name="p0131810372"></a><a name="p0131810372"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="16.74%" id="mcps1.2.5.1.2"><p id="p5493222124018"><a name="p5493222124018"></a><a name="p5493222124018"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.2.5.1.3"><p id="p12420143816426"><a name="p12420143816426"></a><a name="p12420143816426"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="51.300000000000004%" id="mcps1.2.5.1.4"><p id="p613188203712"><a name="p613188203712"></a><a name="p613188203712"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row81317819379"><td class="cellrowborder" valign="top" width="24.44%" headers="mcps1.2.5.1.1 "><p id="p1213083379"><a name="p1213083379"></a><a name="p1213083379"></a>pkgName</p>
</td>
<td class="cellrowborder" valign="top" width="16.74%" headers="mcps1.2.5.1.2 "><p id="p449311228408"><a name="p449311228408"></a><a name="p449311228408"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p54201738184212"><a name="p54201738184212"></a><a name="p54201738184212"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="51.300000000000004%" headers="mcps1.2.5.1.4 "><p id="p13390173423710"><a name="p13390173423710"></a><a name="p13390173423710"></a>Name of the package that is automatically started when the reminder arrives and the device is not in use.</p>
</td>
</tr>
<tr id="row14131285372"><td class="cellrowborder" valign="top" width="24.44%" headers="mcps1.2.5.1.1 "><p id="p913178203713"><a name="p913178203713"></a><a name="p913178203713"></a>abilityName</p>
</td>
<td class="cellrowborder" valign="top" width="16.74%" headers="mcps1.2.5.1.2 "><p id="p149352254017"><a name="p149352254017"></a><a name="p149352254017"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p11420193815427"><a name="p11420193815427"></a><a name="p11420193815427"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="51.300000000000004%" headers="mcps1.2.5.1.4 "><p id="p639093443717"><a name="p639093443717"></a><a name="p639093443717"></a>Name of the ability that is automatically started when the reminder arrives and the device is not in use.</p>
</td>
</tr>
</tbody>
</table>

**ReminderRequest**  defines the reminder to publish.

**Table  7**  ReminderRequest instance

<a name="table121851239193814"></a>
<table><thead align="left"><tr id="row1019153914389"><th class="cellrowborder" valign="top" width="24.94%" id="mcps1.2.5.1.1"><p id="p712019463387"><a name="p712019463387"></a><a name="p712019463387"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17.06%" id="mcps1.2.5.1.2"><p id="p13510183419404"><a name="p13510183419404"></a><a name="p13510183419404"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.2.5.1.3"><p id="p19861165634219"><a name="p19861165634219"></a><a name="p19861165634219"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="50.480000000000004%" id="mcps1.2.5.1.4"><p id="p171201246103818"><a name="p171201246103818"></a><a name="p171201246103818"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row419114391388"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p919193953819"><a name="p919193953819"></a><a name="p919193953819"></a>reminderType</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p3510113419402"><a name="p3510113419402"></a><a name="p3510113419402"></a><a href="#table486010552014">ReminderType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p2861175674219"><a name="p2861175674219"></a><a name="p2861175674219"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p1019193963812"><a name="p1019193963812"></a><a name="p1019193963812"></a>Type of the reminder.</p>
</td>
</tr>
<tr id="row11911939103813"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p1619123919389"><a name="p1619123919389"></a><a name="p1619123919389"></a>actionButton</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p18510034194010"><a name="p18510034194010"></a><a name="p18510034194010"></a>[<a href="#table880311117225">ActionButton</a>?, <a href="#table880311117225">ActionButton</a>?]</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p686185619429"><a name="p686185619429"></a><a name="p686185619429"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p3191133963820"><a name="p3191133963820"></a><a name="p3191133963820"></a>Action button displayed in the reminder notification.</p>
</td>
</tr>
<tr id="row16191739173818"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p1192203917389"><a name="p1192203917389"></a><a name="p1192203917389"></a>wantAgent</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p751063415403"><a name="p751063415403"></a><a name="p751063415403"></a><a href="#table9490856350">WantAgent</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p2073141213436"><a name="p2073141213436"></a><a name="p2073141213436"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p819218395387"><a name="p819218395387"></a><a name="p819218395387"></a>Information about the ability that is redirected to when the notification is clicked.</p>
</td>
</tr>
<tr id="row1619273923810"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p4192123913811"><a name="p4192123913811"></a><a name="p4192123913811"></a>maxScreenWantAgent</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p451023412402"><a name="p451023412402"></a><a name="p451023412402"></a><a href="#table191319843714">MaxScreenWantAgent</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p107401912144311"><a name="p107401912144311"></a><a name="p107401912144311"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p119213933815"><a name="p119213933815"></a><a name="p119213933815"></a>Information about the ability that is automatically started when the reminder arrives. If the device is in use, a notification will be displayed.</p>
</td>
</tr>
<tr id="row15192739143819"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p111927395386"><a name="p111927395386"></a><a name="p111927395386"></a>ringDuration</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p9510183415406"><a name="p9510183415406"></a><a name="p9510183415406"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p11747712154313"><a name="p11747712154313"></a><a name="p11747712154313"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p219216392383"><a name="p219216392383"></a><a name="p219216392383"></a>Ring duration.</p>
</td>
</tr>
<tr id="row0192183918384"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p1819210398387"><a name="p1819210398387"></a><a name="p1819210398387"></a>snoozeTimes</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p1251019344404"><a name="p1251019344404"></a><a name="p1251019344404"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p14753151217435"><a name="p14753151217435"></a><a name="p14753151217435"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p61921339123820"><a name="p61921339123820"></a><a name="p61921339123820"></a>Number of reminder snooze times.</p>
</td>
</tr>
<tr id="row6192193913384"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p191928395381"><a name="p191928395381"></a><a name="p191928395381"></a>timeInterval</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p1851013348407"><a name="p1851013348407"></a><a name="p1851013348407"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p157581712164315"><a name="p157581712164315"></a><a name="p157581712164315"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p719203912388"><a name="p719203912388"></a><a name="p719203912388"></a>Reminder snooze interval.</p>
</td>
</tr>
<tr id="row22821842154410"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p2282104244419"><a name="p2282104244419"></a><a name="p2282104244419"></a>title</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p1428204218441"><a name="p1428204218441"></a><a name="p1428204218441"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p313612319485"><a name="p313612319485"></a><a name="p313612319485"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p1028274244411"><a name="p1028274244411"></a><a name="p1028274244411"></a>Reminder title.</p>
</td>
</tr>
<tr id="row119442450449"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p994411458444"><a name="p994411458444"></a><a name="p994411458444"></a>content</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p10944164517447"><a name="p10944164517447"></a><a name="p10944164517447"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p191361723134820"><a name="p191361723134820"></a><a name="p191361723134820"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p159451245154413"><a name="p159451245154413"></a><a name="p159451245154413"></a>Reminder content.</p>
</td>
</tr>
<tr id="row1428595417443"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p92856546444"><a name="p92856546444"></a><a name="p92856546444"></a>expiredContent</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p9285125419445"><a name="p9285125419445"></a><a name="p9285125419445"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p8136202364819"><a name="p8136202364819"></a><a name="p8136202364819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p2286115418440"><a name="p2286115418440"></a><a name="p2286115418440"></a>Extended content to be displayed when the reminder expires.</p>
</td>
</tr>
<tr id="row56012507442"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p760105019447"><a name="p760105019447"></a><a name="p760105019447"></a>snoozeContent</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p460195019444"><a name="p460195019444"></a><a name="p460195019444"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p27102634812"><a name="p27102634812"></a><a name="p27102634812"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p66021050104419"><a name="p66021050104419"></a><a name="p66021050104419"></a>Extended content to be displayed when the reminder is snoozing.</p>
</td>
</tr>
<tr id="row123271239450"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p14327113104513"><a name="p14327113104513"></a><a name="p14327113104513"></a>notificationId</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p19327173154514"><a name="p19327173154514"></a><a name="p19327173154514"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p12898269481"><a name="p12898269481"></a><a name="p12898269481"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p16327733456"><a name="p16327733456"></a><a name="p16327733456"></a>Notification ID used by the reminder. For details, see the API reference of the <strong id="b1391142771410"><a name="b1391142771410"></a><a name="b1391142771410"></a>NotificationRequest::SetNotificationId(int32_t id)</strong> method.</p>
</td>
</tr>
<tr id="row4369223114511"><td class="cellrowborder" valign="top" width="24.94%" headers="mcps1.2.5.1.1 "><p id="p13370423174515"><a name="p13370423174515"></a><a name="p13370423174515"></a>slotType</p>
</td>
<td class="cellrowborder" valign="top" width="17.06%" headers="mcps1.2.5.1.2 "><p id="p8370102334517"><a name="p8370102334517"></a><a name="p8370102334517"></a><a href="../nottoctopics/en-us_topic_0000001180018813.md#section072355105110">SlotType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.2.5.1.3 "><p id="p41151626144814"><a name="p41151626144814"></a><a name="p41151626144814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.480000000000004%" headers="mcps1.2.5.1.4 "><p id="p193705238459"><a name="p193705238459"></a><a name="p193705238459"></a>Type of the slot used by the reminder</p>
</td>
</tr>
</tbody>
</table>

**ReminderRequestCalendar**  extends  **ReminderRequest**  and defines a reminder for a calendar event.

For the application to run properly, if both **repeatMonths** and **repeatDays** are not specified, the earliest reminder time must be later than the current time.  

**Table  8**  ReminderRequestCalendar instance

<a name="table19307315135210"></a>

<table><thead align="left"><tr id="row113131315175216"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p656917217528"><a name="p656917217528"></a><a name="p656917217528"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17.48%" id="mcps1.2.5.1.2"><p id="p1356913214522"><a name="p1356913214522"></a><a name="p1356913214522"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.22%" id="mcps1.2.5.1.3"><p id="p125701221135211"><a name="p125701221135211"></a><a name="p125701221135211"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="50.3%" id="mcps1.2.5.1.4"><p id="p1757012113526"><a name="p1757012113526"></a><a name="p1757012113526"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16314201516528"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p83141715105220"><a name="p83141715105220"></a><a name="p83141715105220"></a>dateTime</p>
</td>
<td class="cellrowborder" valign="top" width="17.48%" headers="mcps1.2.5.1.2 "><p id="p73141315165214"><a name="p73141315165214"></a><a name="p73141315165214"></a><a href="#table16133167515">LocalDateTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.5.1.3 "><p id="p4314201510524"><a name="p4314201510524"></a><a name="p4314201510524"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="50.3%" headers="mcps1.2.5.1.4 "><p id="p1031461511522"><a name="p1031461511522"></a><a name="p1031461511522"></a>Reminder time, accurate to the minute.</p>
</td>
</tr>
<tr id="row631461520524"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1431419151526"><a name="p1431419151526"></a><a name="p1431419151526"></a>repeatMonths</p>
</td>
<td class="cellrowborder" valign="top" width="17.48%" headers="mcps1.2.5.1.2 "><p id="p1231415155525"><a name="p1231415155525"></a><a name="p1231415155525"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.5.1.3 "><p id="p1031461595220"><a name="p1031461595220"></a><a name="p1031461595220"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.3%" headers="mcps1.2.5.1.4 "><p id="p2031411555218"><a name="p2031411555218"></a><a name="p2031411555218"></a>Months in which the reminder repeats. The value range is 1 to 12.</p>
</td>
</tr>
<tr id="row731481513526"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p031471515525"><a name="p031471515525"></a><a name="p031471515525"></a>repeatDays</p>
</td>
<td class="cellrowborder" valign="top" width="17.48%" headers="mcps1.2.5.1.2 "><p id="p1031401513523"><a name="p1031401513523"></a><a name="p1031401513523"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.5.1.3 "><p id="p93141115135214"><a name="p93141115135214"></a><a name="p93141115135214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="50.3%" headers="mcps1.2.5.1.4 "><p id="p18314141515212"><a name="p18314141515212"></a><a name="p18314141515212"></a>Date on which the reminder repeats. The value range is 1 to 31.</p>
</td>
</tr>
</tbody>
</table>

**ReminderRequestAlarm**  extends  **ReminderRequest**  and defines a reminder for the alarm clock.

**Table  9**  ReminderRequestAlarm instance

<a name="table187631616124414"></a>
<table><thead align="left"><tr id="row87697166445"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p6561172104414"><a name="p6561172104414"></a><a name="p6561172104414"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17.83%" id="mcps1.2.5.1.2"><p id="p135622219448"><a name="p135622219448"></a><a name="p135622219448"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.31%" id="mcps1.2.5.1.3"><p id="p256218218446"><a name="p256218218446"></a><a name="p256218218446"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.86%" id="mcps1.2.5.1.4"><p id="p1656212110445"><a name="p1656212110445"></a><a name="p1656212110445"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2770151624415"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p157701016164417"><a name="p157701016164417"></a><a name="p157701016164417"></a>hour</p>
</td>
<td class="cellrowborder" valign="top" width="17.83%" headers="mcps1.2.5.1.2 "><p id="p577071644418"><a name="p577071644418"></a><a name="p577071644418"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.31%" headers="mcps1.2.5.1.3 "><p id="p17770141618445"><a name="p17770141618445"></a><a name="p17770141618445"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="49.86%" headers="mcps1.2.5.1.4 "><p id="p1770161618444"><a name="p1770161618444"></a><a name="p1770161618444"></a>Hour portion of the reminder time. The value range is 0 to 23.</p>
</td>
</tr>
<tr id="row1177019161448"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p77705169442"><a name="p77705169442"></a><a name="p77705169442"></a>minute</p>
</td>
<td class="cellrowborder" valign="top" width="17.83%" headers="mcps1.2.5.1.2 "><p id="p127701216134415"><a name="p127701216134415"></a><a name="p127701216134415"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.31%" headers="mcps1.2.5.1.3 "><p id="p1477018169442"><a name="p1477018169442"></a><a name="p1477018169442"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="49.86%" headers="mcps1.2.5.1.4 "><p id="p17703161445"><a name="p17703161445"></a><a name="p17703161445"></a>Minute portion of the reminder time. The value range is 0 to 59.</p>
</td>
</tr>
<tr id="row16770416194410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p157706167440"><a name="p157706167440"></a><a name="p157706167440"></a>daysOfWeek</p>
</td>
<td class="cellrowborder" valign="top" width="17.83%" headers="mcps1.2.5.1.2 "><p id="p6770151654411"><a name="p6770151654411"></a><a name="p6770151654411"></a>Array&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.31%" headers="mcps1.2.5.1.3 "><p id="p19770616134413"><a name="p19770616134413"></a><a name="p19770616134413"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.86%" headers="mcps1.2.5.1.4 "><p id="p16101423134917"><a name="p16101423134917"></a><a name="p16101423134917"></a>Days of a week when the reminder repeats. The value range is 1 to 7.</p>
</td>
</tr>
</tbody>
</table>

**ReminderRequestTimer**  extends  **ReminderRequest**  and defines a reminder for a scheduled timer.

**Table  10**  ReminderRequestTimer instance

<a name="table7213172015507"></a>
<table><thead align="left"><tr id="row72131520155017"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p6603124145017"><a name="p6603124145017"></a><a name="p6603124145017"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="18.09%" id="mcps1.2.5.1.2"><p id="p1860442410503"><a name="p1860442410503"></a><a name="p1860442410503"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.739999999999999%" id="mcps1.2.5.1.3"><p id="p146049246506"><a name="p146049246506"></a><a name="p146049246506"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.17%" id="mcps1.2.5.1.4"><p id="p7604724175019"><a name="p7604724175019"></a><a name="p7604724175019"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row172131201507"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p32141320105018"><a name="p32141320105018"></a><a name="p32141320105018"></a>triggerTimeInSeconds</p>
</td>
<td class="cellrowborder" valign="top" width="18.09%" headers="mcps1.2.5.1.2 "><p id="p621420207509"><a name="p621420207509"></a><a name="p621420207509"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.739999999999999%" headers="mcps1.2.5.1.3 "><p id="p13214112075014"><a name="p13214112075014"></a><a name="p13214112075014"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="49.17%" headers="mcps1.2.5.1.4 "><p id="p7214112014509"><a name="p7214112014509"></a><a name="p7214112014509"></a>Number of seconds in the countdown timer.</p>
</td>
</tr>
</tbody>
</table>

**LocalDateTime**  defines a  **LocalDateTime**  instance.

**Table  11**  LocalDateTime instance

<a name="table16133167515"></a>
<table><thead align="left"><tr id="row161321615517"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p5894111825115"><a name="p5894111825115"></a><a name="p5894111825115"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="18.970000000000002%" id="mcps1.2.5.1.2"><p id="p0894161818514"><a name="p0894161818514"></a><a name="p0894161818514"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.39%" id="mcps1.2.5.1.3"><p id="p789419187513"><a name="p789419187513"></a><a name="p789419187513"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="48.64%" id="mcps1.2.5.1.4"><p id="p18949181519"><a name="p18949181519"></a><a name="p18949181519"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row814191617518"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p3141716115110"><a name="p3141716115110"></a><a name="p3141716115110"></a>year</p>
</td>
<td class="cellrowborder" valign="top" width="18.970000000000002%" headers="mcps1.2.5.1.2 "><p id="p714916145113"><a name="p714916145113"></a><a name="p714916145113"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.39%" headers="mcps1.2.5.1.3 "><p id="p314161620516"><a name="p314161620516"></a><a name="p314161620516"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="48.64%" headers="mcps1.2.5.1.4 "><p id="p1314716105114"><a name="p1314716105114"></a><a name="p1314716105114"></a>Year.</p>
</td>
</tr>
<tr id="row7147166511"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1314131615111"><a name="p1314131615111"></a><a name="p1314131615111"></a>month</p>
</td>
<td class="cellrowborder" valign="top" width="18.970000000000002%" headers="mcps1.2.5.1.2 "><p id="p154047112527"><a name="p154047112527"></a><a name="p154047112527"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.39%" headers="mcps1.2.5.1.3 "><p id="p20835587510"><a name="p20835587510"></a><a name="p20835587510"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="48.64%" headers="mcps1.2.5.1.4 "><p id="p13143167515"><a name="p13143167515"></a><a name="p13143167515"></a>Month.</p>
</td>
</tr>
<tr id="row61420169512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1114616185113"><a name="p1114616185113"></a><a name="p1114616185113"></a>day</p>
</td>
<td class="cellrowborder" valign="top" width="18.970000000000002%" headers="mcps1.2.5.1.2 "><p id="p44302113521"><a name="p44302113521"></a><a name="p44302113521"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.39%" headers="mcps1.2.5.1.3 "><p id="p12105105818518"><a name="p12105105818518"></a><a name="p12105105818518"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="48.64%" headers="mcps1.2.5.1.4 "><p id="p171491655111"><a name="p171491655111"></a><a name="p171491655111"></a>Date.</p>
</td>
</tr>
<tr id="row10141616155115"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p114171611514"><a name="p114171611514"></a><a name="p114171611514"></a>hour</p>
</td>
<td class="cellrowborder" valign="top" width="18.970000000000002%" headers="mcps1.2.5.1.2 "><p id="p245813117524"><a name="p245813117524"></a><a name="p245813117524"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.39%" headers="mcps1.2.5.1.3 "><p id="p613435845117"><a name="p613435845117"></a><a name="p613435845117"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="48.64%" headers="mcps1.2.5.1.4 "><p id="p71471645112"><a name="p71471645112"></a><a name="p71471645112"></a>Hour.</p>
</td>
</tr>
<tr id="row201417169511"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1814121615511"><a name="p1814121615511"></a><a name="p1814121615511"></a>minute</p>
</td>
<td class="cellrowborder" valign="top" width="18.970000000000002%" headers="mcps1.2.5.1.2 "><p id="p154671511175213"><a name="p154671511175213"></a><a name="p154671511175213"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.39%" headers="mcps1.2.5.1.3 "><p id="p61445587511"><a name="p61445587511"></a><a name="p61445587511"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="48.64%" headers="mcps1.2.5.1.4 "><p id="p1114141617511"><a name="p1114141617511"></a><a name="p1114141617511"></a>Minute.</p>
</td>
</tr>
<tr id="row114171610510"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p914131655118"><a name="p914131655118"></a><a name="p914131655118"></a>second</p>
</td>
<td class="cellrowborder" valign="top" width="18.970000000000002%" headers="mcps1.2.5.1.2 "><p id="p1847810111524"><a name="p1847810111524"></a><a name="p1847810111524"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.39%" headers="mcps1.2.5.1.3 "><p id="p3141816155111"><a name="p3141816155111"></a><a name="p3141816155111"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="48.64%" headers="mcps1.2.5.1.4 "><p id="p61471645118"><a name="p61471645118"></a><a name="p61471645118"></a>Second.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section4207112818418"></a>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>To publish a reminder, your application needs to apply for the  **ohos.permission.PUBLISH\_AGENT\_REMINDER**  permission.

Publish a 10-second countdown reminder.

1.  Define a countdown timer instance.

    ```
    import reminderAgent from '@ohos.reminderAgent';
    import notification from '@ohos.notification';
    export default {
        timer: {
            reminderType: reminderAgent.ReminderType.REMINDER_TYPE_TIMER,
            triggerTimeInSeconds: 10,
            actionButton: [
                {
                    title: "close",
                    type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
                }
            ],
            wantAgent: {
                pkgName: "com.example.device",
                abilityName: "com.example.device.MainAbility"
            },
            maxScreenWantAgent: {
                pkgName: "com.example.device",
                abilityName: "com.example.device.MainAbility"
            },
            title: "this is title",
            content: "this is content",
            expiredContent: "this reminder has expired",
            notificationId: 100,
            slotType: notification.SlotType.SOCIAL_COMMUNICATION
        }
    }
    ```

2.  Publish the reminder.

    ```
    startTimer() {
        reminderAgent.publishReminder(this.timer, (err, reminderId) =>{
            this.printInfo(JSON.stringify(err));
            this.printInfo("reminderId:" + reminderId);
        });
    }
    ```

    HTML page code:

    ```
    <div class="container">
        <button type="text" value="publishReminder" onclick="startTimer"></button>
    </div>
    ```


Sample code for defining a calendar reminder instance:

```
calendar: {
    reminderType: reminderAgent.ReminderType.REMINDER_TYPE_CALENDAR,
    dateTime: {
        year: 2050,
        month: 7,
        day: 30,
        hour: 11,
        minute: 14,
        second: 30
    },
    repeatMonths: [1],
    repeatDays: [1],
    actionButton: [
        {
            title: "close",
            type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
        },
        {
            title: "snooze",
            type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
        },
    ],
    wantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    maxScreenWantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    ringDuration: 5,
    snoozeTimes: 2,
    timeInterval: 5,
    title: "this is title",
    content: "this is content",
    expiredContent: "this reminder has expired",
    snoozeContent: "remind later",
    notificationId: 100,
    slotType: notification.SlotType.SOCIAL_COMMUNICATION
}
```

Sample code for defining an alarm reminder instance:

```
alarm: {
    reminderType: reminderAgent.ReminderType.REMINDER_TYPE_ALARM,
    hour: 11,
    minute: 14,
    daysOfWeek: [0],
    actionButton: [
        {
            title: "close",
            type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_CLOSE
        },
        {
            title: "snooze",
            type: reminderAgent.ActionButtonType.ACTION_BUTTON_TYPE_SNOOZE
        },
    ],
    wantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    maxScreenWantAgent: {
        pkgName: "com.example.device",
        abilityName: "com.example.device.MainAbility"
    },
    ringDuration: 5,
    snoozeTimes: 2,
    timeInterval: 5,
    title: "this is title",
    content: "this is content",
    expiredContent: "this reminder has expired",
    snoozeContent: "remind later",
    notificationId: 100,
    slotType: notification.SlotType.SOCIAL_COMMUNICATION
}
```

