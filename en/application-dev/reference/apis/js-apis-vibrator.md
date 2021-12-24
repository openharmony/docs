# Vibration<a name="EN-US_TOPIC_0000001144895807"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import vibrate from '@ohos.vibrator';
```

## Required Permissions<a name="section11257113618419"></a>

ohos.permission.VIBRATE

## vibrate.vibrate<a name="section94955414221"></a>

vibrate\(duration: number\): Promise<void\>

Triggers vibration with a specific duration. This method uses a promise to return the execution result.

-   Parameters

    <a name="table28081330115015"></a>
    <table><thead align="left"><tr id="row966192920"><th class="cellrowborder" valign="top" width="15.52%" id="mcps1.1.5.1.1"><p id="p1810113085020"><a name="p1810113085020"></a><a name="p1810113085020"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.420000000000002%" id="mcps1.1.5.1.2"><p id="p381033019500"><a name="p381033019500"></a><a name="p381033019500"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.41%" id="mcps1.1.5.1.3"><p id="p1681118302504"><a name="p1681118302504"></a><a name="p1681118302504"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.65%" id="mcps1.1.5.1.4"><p id="p781143065011"><a name="p781143065011"></a><a name="p781143065011"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1866217210219"><td class="cellrowborder" valign="top" width="15.52%" headers="mcps1.1.5.1.1 "><p id="p108121630205018"><a name="p108121630205018"></a><a name="p108121630205018"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.420000000000002%" headers="mcps1.1.5.1.2 "><p id="p3812173055018"><a name="p3812173055018"></a><a name="p3812173055018"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.5.1.3 "><p id="p19812163017502"><a name="p19812163017502"></a><a name="p19812163017502"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="p1781313065013"><a name="p1781313065013"></a><a name="p1781313065013"></a>Vibration duration.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table5574181751117"></a>
    <table><thead align="left"><tr id="row6574017191115"><th class="cellrowborder" valign="top" width="32.14%" id="mcps1.1.3.1.1"><p id="p11574101711111"><a name="p11574101711111"></a><a name="p11574101711111"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.86%" id="mcps1.1.3.1.2"><p id="p13574917151120"><a name="p13574917151120"></a><a name="p13574917151120"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1757410172116"><td class="cellrowborder" valign="top" width="32.14%" headers="mcps1.1.3.1.1 "><p id="p5991122122518"><a name="p5991122122518"></a><a name="p5991122122518"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.86%" headers="mcps1.1.3.1.2 "><p id="p229214354254"><a name="p229214354254"></a><a name="p229214354254"></a>Promise used to indicate whether the vibration is triggered successfully.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    vibrator.vibrate(1000).then(error)=>{
       if(error){  
           console.log("error.code"+error.code+"error.message"+error.message);
       }else{
           console.log("Promise returned to indicate a successful vibration.");
       }
    }
    ```


## vibrate.vibrate<a name="section476323710376"></a>

vibrate\(duration: number, callback?: AsyncCallback<void\>\): void

Triggers vibration with a specific duration. This method uses a callback to return the execution result.

-   Parameters

    <a name="table1985843010506"></a>
    <table><thead align="left"><tr id="row43411735153715"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p10860173013506"><a name="p10860173013506"></a><a name="p10860173013506"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.89%" id="mcps1.1.5.1.2"><p id="p3860173020500"><a name="p3860173020500"></a><a name="p3860173020500"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.21%" id="mcps1.1.5.1.3"><p id="p108601930115013"><a name="p108601930115013"></a><a name="p108601930115013"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="55.87%" id="mcps1.1.5.1.4"><p id="p2860123015011"><a name="p2860123015011"></a><a name="p2860123015011"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1534210358373"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p1286183020509"><a name="p1286183020509"></a><a name="p1286183020509"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.89%" headers="mcps1.1.5.1.2 "><p id="p118611130195019"><a name="p118611130195019"></a><a name="p118611130195019"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.21%" headers="mcps1.1.5.1.3 "><p id="p168611830115016"><a name="p168611830115016"></a><a name="p168611830115016"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.87%" headers="mcps1.1.5.1.4 "><p id="p15862193005013"><a name="p15862193005013"></a><a name="p15862193005013"></a>Vibration duration.</p>
    </td>
    </tr>
    <tr id="row137131143820"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p12862730165012"><a name="p12862730165012"></a><a name="p12862730165012"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.89%" headers="mcps1.1.5.1.2 "><p id="p108621030195013"><a name="p108621030195013"></a><a name="p108621030195013"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.21%" headers="mcps1.1.5.1.3 "><p id="p128621730195014"><a name="p128621730195014"></a><a name="p128621730195014"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.87%" headers="mcps1.1.5.1.4 "><p id="p198631830105015"><a name="p198631830105015"></a><a name="p198631830105015"></a>Callback used to indicate whether the vibration is triggered successfully.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    vibrator.vibrate(1000,function(error){
       if(error){
           console.log("error.code"+error.code+"error.message"+error.message);
       }else{
           console.log("Callback returned to indicate a successful vibration.");
       }
    })
    ```


## vibrate.vibrate<a name="section181541055163712"></a>

vibrate\(effectId: EffectId\): Promise<void\>

Triggers vibration with a specific effect. This method uses a promise to return the execution result.

-   Parameters

    <a name="table15870203020502"></a>
    <table><thead align="left"><tr id="row78491115165711"><th class="cellrowborder" valign="top" width="14.219999999999999%" id="mcps1.1.5.1.1"><p id="p19871123019506"><a name="p19871123019506"></a><a name="p19871123019506"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.7%" id="mcps1.1.5.1.2"><p id="p387163016504"><a name="p387163016504"></a><a name="p387163016504"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.51%" id="mcps1.1.5.1.3"><p id="p1587153020501"><a name="p1587153020501"></a><a name="p1587153020501"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.56999999999999%" id="mcps1.1.5.1.4"><p id="p18721630115010"><a name="p18721630115010"></a><a name="p18721630115010"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1384921516575"><td class="cellrowborder" valign="top" width="14.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p20872330165018"><a name="p20872330165018"></a><a name="p20872330165018"></a>effectId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.7%" headers="mcps1.1.5.1.2 "><p id="p8872143014501"><a name="p8872143014501"></a><a name="p8872143014501"></a><a href="#section153834312418">EffectId</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.51%" headers="mcps1.1.5.1.3 "><p id="p188721304503"><a name="p188721304503"></a><a name="p188721304503"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.56999999999999%" headers="mcps1.1.5.1.4 "><p id="p58731530185018"><a name="p58731530185018"></a><a name="p58731530185018"></a>String that indicates the vibration effect.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1785124316195"></a>
    <table><thead align="left"><tr id="row38514433192"><th class="cellrowborder" valign="top" width="32.14%" id="mcps1.1.3.1.1"><p id="p385154317196"><a name="p385154317196"></a><a name="p385154317196"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.86%" id="mcps1.1.3.1.2"><p id="p6852104316193"><a name="p6852104316193"></a><a name="p6852104316193"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15853134311917"><td class="cellrowborder" valign="top" width="32.14%" headers="mcps1.1.3.1.1 "><p id="p9853114371911"><a name="p9853114371911"></a><a name="p9853114371911"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.86%" headers="mcps1.1.3.1.2 "><p id="p11853114311918"><a name="p11853114311918"></a><a name="p11853114311918"></a>Promise used to indicate whether the vibration is triggered successfully.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    vibrator.vibrate(effectId:EffectId).then(error)=>{
       if(error){
           console.log("error.code"+error.code+"error.message"+error.message);
       }else{
           Console.log("Promise returned to indicate a successful vibration.");
       }
    }
    ```


## vibrate.vibrate<a name="section5358162183810"></a>

vibrate\(effectId: EffectId, callback?: AsyncCallback<void\>\): void

Triggers vibration with a specific effect. This method uses a callback to return the execution result.

-   Parameters

    <a name="table5884133035017"></a>
    <table><thead align="left"><tr id="row121831015576"><th class="cellrowborder" valign="top" width="13.489999999999998%" id="mcps1.1.5.1.1"><p id="p988518305507"><a name="p988518305507"></a><a name="p988518305507"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.500000000000004%" id="mcps1.1.5.1.2"><p id="p10885183014508"><a name="p10885183014508"></a><a name="p10885183014508"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.84%" id="mcps1.1.5.1.3"><p id="p11885133065010"><a name="p11885133065010"></a><a name="p11885133065010"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="48.17%" id="mcps1.1.5.1.4"><p id="p38851130155017"><a name="p38851130155017"></a><a name="p38851130155017"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14184110165716"><td class="cellrowborder" valign="top" width="13.489999999999998%" headers="mcps1.1.5.1.1 "><p id="p78861630135011"><a name="p78861630135011"></a><a name="p78861630135011"></a>effectId</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p id="p108861830175016"><a name="p108861830175016"></a><a name="p108861830175016"></a><a href="#section153834312418">EffectId</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.84%" headers="mcps1.1.5.1.3 "><p id="p108861730135013"><a name="p108861730135013"></a><a name="p108861730135013"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.17%" headers="mcps1.1.5.1.4 "><p id="p1788793085015"><a name="p1788793085015"></a><a name="p1788793085015"></a>String that indicates the vibration effect.</p>
    </td>
    </tr>
    <tr id="row201843013573"><td class="cellrowborder" valign="top" width="13.489999999999998%" headers="mcps1.1.5.1.1 "><p id="p1588783014502"><a name="p1588783014502"></a><a name="p1588783014502"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p id="p20887143095012"><a name="p20887143095012"></a><a name="p20887143095012"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.84%" headers="mcps1.1.5.1.3 "><p id="p13887123025015"><a name="p13887123025015"></a><a name="p13887123025015"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="48.17%" headers="mcps1.1.5.1.4 "><p id="p88881930145012"><a name="p88881930145012"></a><a name="p88881930145012"></a>Callback used to indicate whether the vibration is triggered successfully.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    vibrator.vibrate(effectId:EffectId,function(error){
       if(error){
           console.log("error.code"+error.code+"error.message"+error.message);
       }else{
           console.log("Callback returned to indicate a successful vibration.");
       }
    })
    ```


## vibrate.stop<a name="section1717861810386"></a>

stop\(stopMode: VibratorStopMode\): Promise<void\>

Stops the vibration based on the specified  **stopMode**. This method uses a promise to return the execution result. If the specified  **stopMode**  is different from the mode used to trigger the vibration, this method fails to be called.

-   Parameters

    <a name="table48931230185018"></a>
    <table><thead align="left"><tr id="row794383114561"><th class="cellrowborder" valign="top" width="17.2%" id="mcps1.1.5.1.1"><p id="p88941030195011"><a name="p88941030195011"></a><a name="p88941030195011"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.800000000000004%" id="mcps1.1.5.1.2"><p id="p189416305505"><a name="p189416305505"></a><a name="p189416305505"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.89%" id="mcps1.1.5.1.3"><p id="p1289583014501"><a name="p1289583014501"></a><a name="p1289583014501"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.11%" id="mcps1.1.5.1.4"><p id="p789573010507"><a name="p789573010507"></a><a name="p789573010507"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row094433111561"><td class="cellrowborder" valign="top" width="17.2%" headers="mcps1.1.5.1.1 "><p id="p13896030195020"><a name="p13896030195020"></a><a name="p13896030195020"></a>stopMode</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.800000000000004%" headers="mcps1.1.5.1.2 "><p id="p78961430125018"><a name="p78961430125018"></a><a name="p78961430125018"></a><a href="#section156137011615">VibratorStopMode</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="14.89%" headers="mcps1.1.5.1.3 "><p id="p68961730185016"><a name="p68961730185016"></a><a name="p68961730185016"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.11%" headers="mcps1.1.5.1.4 "><p id="p2896330125016"><a name="p2896330125016"></a><a name="p2896330125016"></a>Vibration mode to stop.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table5101547132414"></a>
    <table><thead align="left"><tr id="row1011124752414"><th class="cellrowborder" valign="top" width="32.14%" id="mcps1.1.3.1.1"><p id="p1811144732419"><a name="p1811144732419"></a><a name="p1811144732419"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.86%" id="mcps1.1.3.1.2"><p id="p911194712245"><a name="p911194712245"></a><a name="p911194712245"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row161117475243"><td class="cellrowborder" valign="top" width="32.14%" headers="mcps1.1.3.1.1 "><p id="p6111474249"><a name="p6111474249"></a><a name="p6111474249"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.86%" headers="mcps1.1.3.1.2 "><p id="p19111047112419"><a name="p19111047112419"></a><a name="p19111047112419"></a>Promise used to indicate whether the vibration is stopped successfully.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    vibrator.stop(stopMode:VibratorStopMode).then((error)=>{
       if(error){
           console.log("error.code"+error.code+"error.message"+error.message);
       }else{
           Console.log("Promise returned to indicate a successful stop.");
       }
    })
    ```


## vibrate.stop<a name="section237813213385"></a>

stop\(stopMode: VibratorStopMode, callback?: AsyncCallback<void\>\): void;

Stops the vibration based on the specified  **stopMode**. This method uses a callback to return the execution result. If the specified  **stopMode**  is different from the mode used to trigger the vibration, this method fails to be called.

-   Parameters

    <a name="table8906130165012"></a>
    <table><thead align="left"><tr id="row61232138569"><th class="cellrowborder" valign="top" width="19.2%" id="mcps1.1.5.1.1"><p id="p2090703018503"><a name="p2090703018503"></a><a name="p2090703018503"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.840000000000003%" id="mcps1.1.5.1.2"><p id="p290773055018"><a name="p290773055018"></a><a name="p290773055018"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.3"><p id="p18907173085017"><a name="p18907173085017"></a><a name="p18907173085017"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.85%" id="mcps1.1.5.1.4"><p id="p149081030115015"><a name="p149081030115015"></a><a name="p149081030115015"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1312381316560"><td class="cellrowborder" valign="top" width="19.2%" headers="mcps1.1.5.1.1 "><p id="p1390833045018"><a name="p1390833045018"></a><a name="p1390833045018"></a>stopMode</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.840000000000003%" headers="mcps1.1.5.1.2 "><p id="p8908153019508"><a name="p8908153019508"></a><a name="p8908153019508"></a><a href="#section156137011615">VibratorStopMode</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.3 "><p id="p1890813015018"><a name="p1890813015018"></a><a name="p1890813015018"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.85%" headers="mcps1.1.5.1.4 "><p id="p490953014500"><a name="p490953014500"></a><a name="p490953014500"></a>Vibration mode to stop.</p>
    </td>
    </tr>
    <tr id="row6115174720252"><td class="cellrowborder" valign="top" width="19.2%" headers="mcps1.1.5.1.1 "><p id="p390993095010"><a name="p390993095010"></a><a name="p390993095010"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.840000000000003%" headers="mcps1.1.5.1.2 "><p id="p1790933025011"><a name="p1790933025011"></a><a name="p1790933025011"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.3 "><p id="p159097308508"><a name="p159097308508"></a><a name="p159097308508"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.85%" headers="mcps1.1.5.1.4 "><p id="p1691013014508"><a name="p1691013014508"></a><a name="p1691013014508"></a>Callback used to indicate whether the vibration is stopped successfully.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    vibrator.stop(stopMode:VibratorStopMode,function(error){
       if(error){
           console.log("error.code"+error.code+"error.message"+error.message);
       }else{
           Console.log("Callback returned to indicate a successful stop.");
       }
    })
    ```


## EffectId<a name="section153834312418"></a>

Describes the vibration effect.

<a name="table148123357518"></a>
<table><thead align="left"><tr id="row881203535118"><th class="cellrowborder" valign="top" width="26.48264826482648%" id="mcps1.1.4.1.1"><p id="p843564511513"><a name="p843564511513"></a><a name="p843564511513"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25.68256825682568%" id="mcps1.1.4.1.2"><p id="p1143574513515"><a name="p1143574513515"></a><a name="p1143574513515"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="47.83478347834784%" id="mcps1.1.4.1.3"><p id="p5435154585112"><a name="p5435154585112"></a><a name="p5435154585112"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1181315353513"><td class="cellrowborder" valign="top" width="26.48264826482648%" headers="mcps1.1.4.1.1 "><p id="p1481317355519"><a name="p1481317355519"></a><a name="p1481317355519"></a>EFFECT_CLOCK_TIMER</p>
</td>
<td class="cellrowborder" valign="top" width="25.68256825682568%" headers="mcps1.1.4.1.2 "><p id="p4813035155112"><a name="p4813035155112"></a><a name="p4813035155112"></a>"haptic.clock.timer"</p>
</td>
<td class="cellrowborder" valign="top" width="47.83478347834784%" headers="mcps1.1.4.1.3 "><p id="p198131235115114"><a name="p198131235115114"></a><a name="p198131235115114"></a>Vibration effect of the vibrator when a user adjusts the timer.</p>
</td>
</tr>
</tbody>
</table>

## VibratorStopMode<a name="section156137011615"></a>

Describes the vibration mode to stop.

<a name="table183851068715"></a>
<table><thead align="left"><tr id="row23862069716"><th class="cellrowborder" valign="top" width="33.523352335233525%" id="mcps1.1.4.1.1"><p id="p1072910402072"><a name="p1072910402072"></a><a name="p1072910402072"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="15.4015401540154%" id="mcps1.1.4.1.2"><p id="p1772910401718"><a name="p1772910401718"></a><a name="p1772910401718"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="51.07510751075108%" id="mcps1.1.4.1.3"><p id="p10729114015717"><a name="p10729114015717"></a><a name="p10729114015717"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row5386186675"><td class="cellrowborder" valign="top" width="33.523352335233525%" headers="mcps1.1.4.1.1 "><p id="p1838614618717"><a name="p1838614618717"></a><a name="p1838614618717"></a>VIBRATOR_STOP_MODE_TIME</p>
</td>
<td class="cellrowborder" valign="top" width="15.4015401540154%" headers="mcps1.1.4.1.2 "><p id="p6821371787"><a name="p6821371787"></a><a name="p6821371787"></a>"time"</p>
</td>
<td class="cellrowborder" valign="top" width="51.07510751075108%" headers="mcps1.1.4.1.3 "><p id="p10386261671"><a name="p10386261671"></a><a name="p10386261671"></a>Indicates that the vibration to stop is in <strong id="b856012326541"><a name="b856012326541"></a><a name="b856012326541"></a>duration</strong> mode. This vibration is triggered with the parameter <strong id="b1722814576114"><a name="b1722814576114"></a><a name="b1722814576114"></a>duration</strong> of the <strong id="b264554925411"><a name="b264554925411"></a><a name="b264554925411"></a>number</strong> type.</p>
</td>
</tr>
<tr id="row8438152415720"><td class="cellrowborder" valign="top" width="33.523352335233525%" headers="mcps1.1.4.1.1 "><p id="p6446231085"><a name="p6446231085"></a><a name="p6446231085"></a>VIBRATOR_STOP_MODE_PRESET</p>
</td>
<td class="cellrowborder" valign="top" width="15.4015401540154%" headers="mcps1.1.4.1.2 "><p id="p178815321819"><a name="p178815321819"></a><a name="p178815321819"></a>"preset"</p>
</td>
<td class="cellrowborder" valign="top" width="51.07510751075108%" headers="mcps1.1.4.1.3 "><p id="p1219354892816"><a name="p1219354892816"></a><a name="p1219354892816"></a>Indicates the vibration to stop is in <strong id="b2716194015546"><a name="b2716194015546"></a><a name="b2716194015546"></a>EffectId</strong> mode. This vibration is triggered with the parameter <strong id="b131201122131212"><a name="b131201122131212"></a><a name="b131201122131212"></a>effectId</strong> of the <strong id="b34910596546"><a name="b34910596546"></a><a name="b34910596546"></a>EffectId</strong> type.</p>
</td>
</tr>
</tbody>
</table>

