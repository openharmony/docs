# 振动<a name="ZH-CN_TOPIC_0000001144895807"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version  7 开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import vibrate from '@ohos.vibrator';
```

## 权限列表<a name="section11257113618419"></a>

ohos.permission.VIBRATE

## vibrate.vibrate<a name="section94955414221"></a>

vibrate\(duration: number\): Promise<void\>

按照指定持续时间触发马达振动。

**参数：**

<a name="table366016210217"></a>
<table><thead align="left"><tr id="row966192920"><th class="cellrowborder" valign="top" width="15.52%" id="mcps1.1.5.1.1"><p id="p3661421219"><a name="p3661421219"></a><a name="p3661421219"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="13.420000000000002%" id="mcps1.1.5.1.2"><p id="p26611722215"><a name="p26611722215"></a><a name="p26611722215"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="18.41%" id="mcps1.1.5.1.3"><p id="p2661425211"><a name="p2661425211"></a><a name="p2661425211"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.65%" id="mcps1.1.5.1.4"><p id="p13661729217"><a name="p13661729217"></a><a name="p13661729217"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1866217210219"><td class="cellrowborder" valign="top" width="15.52%" headers="mcps1.1.5.1.1 "><p id="p186571105532"><a name="p186571105532"></a><a name="p186571105532"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="13.420000000000002%" headers="mcps1.1.5.1.2 "><p id="p06570015314"><a name="p06570015314"></a><a name="p06570015314"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.5.1.3 "><p id="p865715085315"><a name="p865715085315"></a><a name="p865715085315"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.65%" headers="mcps1.1.5.1.4 "><p id="p17657110105317"><a name="p17657110105317"></a><a name="p17657110105317"></a>指示马达振动的持续时间。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table5574181751117"></a>
<table><thead align="left"><tr id="row6574017191115"><th class="cellrowborder" valign="top" width="32.14%" id="mcps1.1.3.1.1"><p id="p11574101711111"><a name="p11574101711111"></a><a name="p11574101711111"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="67.86%" id="mcps1.1.3.1.2"><p id="p13574917151120"><a name="p13574917151120"></a><a name="p13574917151120"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1757410172116"><td class="cellrowborder" valign="top" width="32.14%" headers="mcps1.1.3.1.1 "><p id="p5991122122518"><a name="p5991122122518"></a><a name="p5991122122518"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="67.86%" headers="mcps1.1.3.1.2 "><p id="p229214354254"><a name="p229214354254"></a><a name="p229214354254"></a>指示触发振动是否成功。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
vibrate.vibrate(100).then(()=>
    console.log('Promise returned to indicate a successful vibration.')
).catch((error) => {
    console.error('Failed to trigger vibration.');
});
```

## vibrate.vibrate<a name="section476323710376"></a>

vibrate\(duration: number, callback?: AsyncCallback<void\>\): void

按照指定持续时间触发马达振动。

**参数：**

<a name="table16341143583713"></a>
<table><thead align="left"><tr id="row43411735153715"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p1134243517370"><a name="p1134243517370"></a><a name="p1134243517370"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="24.89%" id="mcps1.1.5.1.2"><p id="p634210351371"><a name="p634210351371"></a><a name="p634210351371"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.21%" id="mcps1.1.5.1.3"><p id="p1234213514373"><a name="p1234213514373"></a><a name="p1234213514373"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.87%" id="mcps1.1.5.1.4"><p id="p19342153573711"><a name="p19342153573711"></a><a name="p19342153573711"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1534210358373"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p33429354373"><a name="p33429354373"></a><a name="p33429354373"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="24.89%" headers="mcps1.1.5.1.2 "><p id="p153421354376"><a name="p153421354376"></a><a name="p153421354376"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.21%" headers="mcps1.1.5.1.3 "><p id="p1534219353376"><a name="p1534219353376"></a><a name="p1534219353376"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.87%" headers="mcps1.1.5.1.4 "><p id="p113425351379"><a name="p113425351379"></a><a name="p113425351379"></a>指示马达振动的持续时间。</p>
</td>
</tr>
<tr id="row137131143820"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p1681411133817"><a name="p1681411133817"></a><a name="p1681411133817"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="24.89%" headers="mcps1.1.5.1.2 "><p id="p1882115383"><a name="p1882115383"></a><a name="p1882115383"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.21%" headers="mcps1.1.5.1.3 "><p id="p6831113380"><a name="p6831113380"></a><a name="p6831113380"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="55.87%" headers="mcps1.1.5.1.4 "><p id="p12861113812"><a name="p12861113812"></a><a name="p12861113812"></a>马达执行振动的回调函数，指示触发振动是否成功。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
vibrate.vibrate(100, function(error) {
    if (error) {
        console.error("Failed to trigger vibration. Error code: " + error.code + ", message: " + error.message);
        return;
    }
    console.info("Succeeded in triggering vibration.");
});
```

## vibrate.vibrate<a name="section181541055163712"></a>

vibrate\(effectId: EffectId\): Promise<void\>

按照指定振动效果触发马达振动。

**参数：**

<a name="table1384941535713"></a>
<table><thead align="left"><tr id="row78491115165711"><th class="cellrowborder" valign="top" width="14.219999999999999%" id="mcps1.1.5.1.1"><p id="p1284915159571"><a name="p1284915159571"></a><a name="p1284915159571"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="21.7%" id="mcps1.1.5.1.2"><p id="p198491515145711"><a name="p198491515145711"></a><a name="p198491515145711"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.51%" id="mcps1.1.5.1.3"><p id="p178491315195713"><a name="p178491315195713"></a><a name="p178491315195713"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="54.56999999999999%" id="mcps1.1.5.1.4"><p id="p14849915175715"><a name="p14849915175715"></a><a name="p14849915175715"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1384921516575"><td class="cellrowborder" valign="top" width="14.219999999999999%" headers="mcps1.1.5.1.1 "><p id="p13850161575713"><a name="p13850161575713"></a><a name="p13850161575713"></a>effectId</p>
</td>
<td class="cellrowborder" valign="top" width="21.7%" headers="mcps1.1.5.1.2 "><p id="p1985091595719"><a name="p1985091595719"></a><a name="p1985091595719"></a><a href="#section153834312418">EffectId</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.51%" headers="mcps1.1.5.1.3 "><p id="p1985013154573"><a name="p1985013154573"></a><a name="p1985013154573"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="54.56999999999999%" headers="mcps1.1.5.1.4 "><p id="p7850151585712"><a name="p7850151585712"></a><a name="p7850151585712"></a>指示马达振动效果的字符串。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table1785124316195"></a>
<table><thead align="left"><tr id="row38514433192"><th class="cellrowborder" valign="top" width="32.14%" id="mcps1.1.3.1.1"><p id="p385154317196"><a name="p385154317196"></a><a name="p385154317196"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="67.86%" id="mcps1.1.3.1.2"><p id="p6852104316193"><a name="p6852104316193"></a><a name="p6852104316193"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row15853134311917"><td class="cellrowborder" valign="top" width="32.14%" headers="mcps1.1.3.1.1 "><p id="p9853114371911"><a name="p9853114371911"></a><a name="p9853114371911"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="67.86%" headers="mcps1.1.3.1.2 "><p id="p11853114311918"><a name="p11853114311918"></a><a name="p11853114311918"></a>指示触发振动是否成功。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
vibrate.vibrate(vibrate.EffectId.EFFECT_CLOCK_TIMER).then(()=>
    console.log('Promise returned to indicate a successful vibration.')
).catch((error) => {
    console.error('Failed to trigger vibration.');
});
```

## vibrate.vibrate<a name="section5358162183810"></a>

vibrate\(effectId: EffectId, callback?: AsyncCallback<void\>\): void

按照指定振动效果触发马达振动。

**参数：**

<a name="table818312045715"></a>
<table><thead align="left"><tr id="row121831015576"><th class="cellrowborder" valign="top" width="13.489999999999998%" id="mcps1.1.5.1.1"><p id="p111841506574"><a name="p111841506574"></a><a name="p111841506574"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="27.500000000000004%" id="mcps1.1.5.1.2"><p id="p11843011576"><a name="p11843011576"></a><a name="p11843011576"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.84%" id="mcps1.1.5.1.3"><p id="p3184170195711"><a name="p3184170195711"></a><a name="p3184170195711"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="48.17%" id="mcps1.1.5.1.4"><p id="p1118414018570"><a name="p1118414018570"></a><a name="p1118414018570"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row14184110165716"><td class="cellrowborder" valign="top" width="13.489999999999998%" headers="mcps1.1.5.1.1 "><p id="p11841207577"><a name="p11841207577"></a><a name="p11841207577"></a>effectId</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p id="p3466172518113"><a name="p3466172518113"></a><a name="p3466172518113"></a><a href="#section153834312418">EffectId</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.84%" headers="mcps1.1.5.1.3 "><p id="p1018419011571"><a name="p1018419011571"></a><a name="p1018419011571"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.17%" headers="mcps1.1.5.1.4 "><p id="p545018271000"><a name="p545018271000"></a><a name="p545018271000"></a>指示马达振动效果的字符串。</p>
</td>
</tr>
<tr id="row201843013573"><td class="cellrowborder" valign="top" width="13.489999999999998%" headers="mcps1.1.5.1.1 "><p id="p218411095720"><a name="p218411095720"></a><a name="p218411095720"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="27.500000000000004%" headers="mcps1.1.5.1.2 "><p id="p818413018578"><a name="p818413018578"></a><a name="p818413018578"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.84%" headers="mcps1.1.5.1.3 "><p id="p191841085713"><a name="p191841085713"></a><a name="p191841085713"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="48.17%" headers="mcps1.1.5.1.4 "><p id="p19184170125717"><a name="p19184170125717"></a><a name="p19184170125717"></a>马达执行振动的回调函数，指示触发振动是否成功。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
vibrate.vibrate(vibrate.EffectId.EFFECT_CLOCK_TIMER, function(error) {
    if (error) {
        console.error("Failed to trigger vibration. Error code: " + error.code + ", message: " + error.message);
        return;
    }
    console.info("Succeeded in triggering vibration.");
});
```

## vibrate.stop<a name="section1717861810386"></a>

stop\(stopMode: VibratorStopMode\): Promise<void\>

按照要停止指定的振动模式来停止马达的振动。如果要停止的振动模式与触发马达振动时的模式不相同，则调用本接口会失败。

**参数：**

<a name="table18943631185618"></a>
<table><thead align="left"><tr id="row794383114561"><th class="cellrowborder" valign="top" width="17.2%" id="mcps1.1.5.1.1"><p id="p169431131155618"><a name="p169431131155618"></a><a name="p169431131155618"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="27.800000000000004%" id="mcps1.1.5.1.2"><p id="p17943103115561"><a name="p17943103115561"></a><a name="p17943103115561"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.89%" id="mcps1.1.5.1.3"><p id="p894373145610"><a name="p894373145610"></a><a name="p894373145610"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="40.11%" id="mcps1.1.5.1.4"><p id="p6943331165611"><a name="p6943331165611"></a><a name="p6943331165611"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row094433111561"><td class="cellrowborder" valign="top" width="17.2%" headers="mcps1.1.5.1.1 "><p id="p1594411314562"><a name="p1594411314562"></a><a name="p1594411314562"></a>stopMode</p>
</td>
<td class="cellrowborder" valign="top" width="27.800000000000004%" headers="mcps1.1.5.1.2 "><p id="p6944631155616"><a name="p6944631155616"></a><a name="p6944631155616"></a><a href="#section156137011615">VibratorStopMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="14.89%" headers="mcps1.1.5.1.3 "><p id="p1294418316567"><a name="p1294418316567"></a><a name="p1294418316567"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="40.11%" headers="mcps1.1.5.1.4 "><p id="p14944131175617"><a name="p14944131175617"></a><a name="p14944131175617"></a>指示马达要停止指定的振动模式。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table5101547132414"></a>
<table><thead align="left"><tr id="row1011124752414"><th class="cellrowborder" valign="top" width="32.14%" id="mcps1.1.3.1.1"><p id="p1811144732419"><a name="p1811144732419"></a><a name="p1811144732419"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="67.86%" id="mcps1.1.3.1.2"><p id="p911194712245"><a name="p911194712245"></a><a name="p911194712245"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row161117475243"><td class="cellrowborder" valign="top" width="32.14%" headers="mcps1.1.3.1.1 "><p id="p6111474249"><a name="p6111474249"></a><a name="p6111474249"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="67.86%" headers="mcps1.1.3.1.2 "><p id="p19111047112419"><a name="p19111047112419"></a><a name="p19111047112419"></a>指示停止振动是否成功。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
vibrate.stop(vibrate.VibratorStopMode.VIBRATOR_STOP_MODE_TIME).then(()=>
    console.log('Promise returned to indicate a successful vibration stop.')
).catch((error) => {
    console.error('Failed to stop vibration.');
});
```

## vibrate.stop<a name="section237813213385"></a>

stop\(stopMode: VibratorStopMode, callback?: AsyncCallback<void\>\): void;

按照要停止指定的振动模式来停止马达的振动。如果要停止的振动模式与触发马达振动时的模式不相同，则调用本接口会失败。

**参数：**

<a name="table2123191316565"></a>
<table><thead align="left"><tr id="row61232138569"><th class="cellrowborder" valign="top" width="19.2%" id="mcps1.1.5.1.1"><p id="p1512361335615"><a name="p1512361335615"></a><a name="p1512361335615"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="26.840000000000003%" id="mcps1.1.5.1.2"><p id="p61231113135614"><a name="p61231113135614"></a><a name="p61231113135614"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.5.1.3"><p id="p12123313115615"><a name="p12123313115615"></a><a name="p12123313115615"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="45.85%" id="mcps1.1.5.1.4"><p id="p6123101310560"><a name="p6123101310560"></a><a name="p6123101310560"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1312381316560"><td class="cellrowborder" valign="top" width="19.2%" headers="mcps1.1.5.1.1 "><p id="p1212461355617"><a name="p1212461355617"></a><a name="p1212461355617"></a>stopMode</p>
</td>
<td class="cellrowborder" valign="top" width="26.840000000000003%" headers="mcps1.1.5.1.2 "><p id="p4124513105614"><a name="p4124513105614"></a><a name="p4124513105614"></a><a href="#section156137011615">VibratorStopMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.3 "><p id="p1912451318562"><a name="p1912451318562"></a><a name="p1912451318562"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="45.85%" headers="mcps1.1.5.1.4 "><p id="p2124151325616"><a name="p2124151325616"></a><a name="p2124151325616"></a>指示马达要停止指定的振动模式。</p>
</td>
</tr>
<tr id="row6115174720252"><td class="cellrowborder" valign="top" width="19.2%" headers="mcps1.1.5.1.1 "><p id="p13116847102516"><a name="p13116847102516"></a><a name="p13116847102516"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="26.840000000000003%" headers="mcps1.1.5.1.2 "><p id="p5911537251"><a name="p5911537251"></a><a name="p5911537251"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.5.1.3 "><p id="p711713471251"><a name="p711713471251"></a><a name="p711713471251"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="45.85%" headers="mcps1.1.5.1.4 "><p id="p8117114711255"><a name="p8117114711255"></a><a name="p8117114711255"></a>马达停止振动的回调函数，指示停止振动是否成功。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
vibrate.stop(vibrate.VibratorStopMode.VIBRATOR_STOP_MODE_TIME, function(error) {
    if (error) {
        console.error("Failed to stop vibration. Error code: " + error.code + ", message: " + error.message);
        return;
    }
    console.info("Vibration stopped.");
});
```

## EffectId<a name="section153834312418"></a>

表示马达振动效果的字符串。

<a name="table148123357518"></a>
<table><thead align="left"><tr id="row881203535118"><th class="cellrowborder" valign="top" width="26.48264826482648%" id="mcps1.1.4.1.1"><p id="p843564511513"><a name="p843564511513"></a><a name="p843564511513"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="25.68256825682568%" id="mcps1.1.4.1.2"><p id="p1143574513515"><a name="p1143574513515"></a><a name="p1143574513515"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="47.83478347834784%" id="mcps1.1.4.1.3"><p id="p5435154585112"><a name="p5435154585112"></a><a name="p5435154585112"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1181315353513"><td class="cellrowborder" valign="top" width="26.48264826482648%" headers="mcps1.1.4.1.1 "><p id="p1481317355519"><a name="p1481317355519"></a><a name="p1481317355519"></a>EFFECT_CLOCK_TIMER</p>
</td>
<td class="cellrowborder" valign="top" width="25.68256825682568%" headers="mcps1.1.4.1.2 "><p id="p4813035155112"><a name="p4813035155112"></a><a name="p4813035155112"></a>"haptic.clock.timer"</p>
</td>
<td class="cellrowborder" valign="top" width="47.83478347834784%" headers="mcps1.1.4.1.3 "><p id="p198131235115114"><a name="p198131235115114"></a><a name="p198131235115114"></a>调整定时器时振动器的振动效果。</p>
</td>
</tr>
</tbody>
</table>

## VibratorStopMode<a name="section156137011615"></a>

表示马达要停止指定的振动模式。

<a name="table183851068715"></a>
<table><thead align="left"><tr id="row23862069716"><th class="cellrowborder" valign="top" width="33.523352335233525%" id="mcps1.1.4.1.1"><p id="p1072910402072"><a name="p1072910402072"></a><a name="p1072910402072"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.4015401540154%" id="mcps1.1.4.1.2"><p id="p1772910401718"><a name="p1772910401718"></a><a name="p1772910401718"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="51.07510751075108%" id="mcps1.1.4.1.3"><p id="p10729114015717"><a name="p10729114015717"></a><a name="p10729114015717"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row5386186675"><td class="cellrowborder" valign="top" width="33.523352335233525%" headers="mcps1.1.4.1.1 "><p id="p1838614618717"><a name="p1838614618717"></a><a name="p1838614618717"></a>VIBRATOR_STOP_MODE_TIME</p>
</td>
<td class="cellrowborder" valign="top" width="15.4015401540154%" headers="mcps1.1.4.1.2 "><p id="p6821371787"><a name="p6821371787"></a><a name="p6821371787"></a>"time"</p>
</td>
<td class="cellrowborder" valign="top" width="51.07510751075108%" headers="mcps1.1.4.1.3 "><p id="p10386261671"><a name="p10386261671"></a><a name="p10386261671"></a>停止模式为duration模式的振动。即触发振动时参数类型为number，参数本身为指示振动持续时间的触发方式。</p>
</td>
</tr>
<tr id="row8438152415720"><td class="cellrowborder" valign="top" width="33.523352335233525%" headers="mcps1.1.4.1.1 "><p id="p6446231085"><a name="p6446231085"></a><a name="p6446231085"></a>VIBRATOR_STOP_MODE_PRESET</p>
</td>
<td class="cellrowborder" valign="top" width="15.4015401540154%" headers="mcps1.1.4.1.2 "><p id="p178815321819"><a name="p178815321819"></a><a name="p178815321819"></a>"preset"</p>
</td>
<td class="cellrowborder" valign="top" width="51.07510751075108%" headers="mcps1.1.4.1.3 "><p id="p1219354892816"><a name="p1219354892816"></a><a name="p1219354892816"></a>停止模式为预置EffectId的振动。即触发振动时参数类型为EffectId，参数本身为指示马达振动效果的字符串的触发方式。</p>
</td>
</tr>
</tbody>
</table>

