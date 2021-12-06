# Runninglock锁<a name="ZH-CN_TOPIC_0000001164290736"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001209249145_s56d19203690d4782bfc74069abb6bd71"></a>

```
import runninglock from '@runninglock';
```

## 权限<a name="zh-cn_topic_0000001209249145_section11257113618419"></a>

申请、使用锁的权限：ohos.permission.RUNNING\_LOCK

## RunningLockType<a name="zh-cn_topic_0000001209249145_section7299123218370"></a>

Runninglock锁的类型。

<a name="zh-cn_topic_0000001209249145_table1540155452420"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001209249145_row1947713549244"><th class="cellrowborder" valign="top" width="30.78%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001209249145_p74771754102410"><a name="zh-cn_topic_0000001209249145_p74771754102410"></a><a name="zh-cn_topic_0000001209249145_p74771754102410"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.52%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001209249145_p1047755412411"><a name="zh-cn_topic_0000001209249145_p1047755412411"></a><a name="zh-cn_topic_0000001209249145_p1047755412411"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="57.699999999999996%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001209249145_p12478954132419"><a name="zh-cn_topic_0000001209249145_p12478954132419"></a><a name="zh-cn_topic_0000001209249145_p12478954132419"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001209249145_row1247811541240"><td class="cellrowborder" valign="top" width="30.78%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001209249145_p11478654162419"><a name="zh-cn_topic_0000001209249145_p11478654162419"></a><a name="zh-cn_topic_0000001209249145_p11478654162419"></a>BACKGROUND</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001209249145_p9478135414243"><a name="zh-cn_topic_0000001209249145_p9478135414243"></a><a name="zh-cn_topic_0000001209249145_p9478135414243"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="57.699999999999996%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001209249145_p12478654172415"><a name="zh-cn_topic_0000001209249145_p12478654172415"></a><a name="zh-cn_topic_0000001209249145_p12478654172415"></a>阻止系统休眠的锁。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001209249145_row184789546249"><td class="cellrowborder" valign="top" width="30.78%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001209249145_p1971014525154"><a name="zh-cn_topic_0000001209249145_p1971014525154"></a><a name="zh-cn_topic_0000001209249145_p1971014525154"></a>PROXIMITY_SCREEN_CONTROL</p>
</td>
<td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001209249145_p570945210150"><a name="zh-cn_topic_0000001209249145_p570945210150"></a><a name="zh-cn_topic_0000001209249145_p570945210150"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="57.699999999999996%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001209249145_p1470645211154"><a name="zh-cn_topic_0000001209249145_p1470645211154"></a><a name="zh-cn_topic_0000001209249145_p1470645211154"></a>通过接近或者远离状态来控制亮灭屏的锁。</p>
</td>
</tr>
</tbody>
</table>

## runninglock.isRunningLockTypeSupported<a name="zh-cn_topic_0000001209249145_section192192415554"></a>

isRunningLockTypeSupported\(type: RunningLockType, callback: AsyncCallback<boolean\>\): void

查询系统是否支持该类型的锁。

-   参数：

    <a name="zh-cn_topic_0000001209249145_table69661135912"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209249145_row149668318915"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209249145_p7966738914"><a name="zh-cn_topic_0000001209249145_p7966738914"></a><a name="zh-cn_topic_0000001209249145_p7966738914"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="27.74%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209249145_p296713699"><a name="zh-cn_topic_0000001209249145_p296713699"></a><a name="zh-cn_topic_0000001209249145_p296713699"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.200000000000001%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209249145_p196718315911"><a name="zh-cn_topic_0000001209249145_p196718315911"></a><a name="zh-cn_topic_0000001209249145_p196718315911"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="46.239999999999995%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209249145_p9967231197"><a name="zh-cn_topic_0000001209249145_p9967231197"></a><a name="zh-cn_topic_0000001209249145_p9967231197"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209249145_row99671533914"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209249145_p134721811816"><a name="zh-cn_topic_0000001209249145_p134721811816"></a><a name="zh-cn_topic_0000001209249145_p134721811816"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.74%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209249145_p11967433914"><a name="zh-cn_topic_0000001209249145_p11967433914"></a><a name="zh-cn_topic_0000001209249145_p11967433914"></a>RunningLockType</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.200000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209249145_p19671336916"><a name="zh-cn_topic_0000001209249145_p19671336916"></a><a name="zh-cn_topic_0000001209249145_p19671336916"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209249145_p69671631796"><a name="zh-cn_topic_0000001209249145_p69671631796"></a><a name="zh-cn_topic_0000001209249145_p69671631796"></a>需要查询的锁的类型。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001209249145_row10192174731012"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209249145_p61933477103"><a name="zh-cn_topic_0000001209249145_p61933477103"></a><a name="zh-cn_topic_0000001209249145_p61933477103"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="27.74%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209249145_p1193104791012"><a name="zh-cn_topic_0000001209249145_p1193104791012"></a><a name="zh-cn_topic_0000001209249145_p1193104791012"></a>AsyncCallback&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.200000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209249145_p1919313476105"><a name="zh-cn_topic_0000001209249145_p1919313476105"></a><a name="zh-cn_topic_0000001209249145_p1919313476105"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="46.239999999999995%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209249145_p81931947161019"><a name="zh-cn_topic_0000001209249145_p81931947161019"></a><a name="zh-cn_topic_0000001209249145_p81931947161019"></a>指定的callback回调方法，用于获取返回值。</p>
    <p id="zh-cn_topic_0000001209249145_p1189279101115"><a name="zh-cn_topic_0000001209249145_p1189279101115"></a><a name="zh-cn_topic_0000001209249145_p1189279101115"></a>callback返回值：支持返回true，不支持返回false。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    runningLock.isRunningLockTypeSupported(runningLock.RunningLockType.BACKGROUND, (error, supported) => {
        if (typeof error === "undefined") {
            console.info('BACKGROUND support status is ' + supported);
            done();
        } else {
            console.log('error: ' + error);
            done();
        }
    })
    ```


## runninglock.isRunningLockTypeSupported<a name="zh-cn_topic_0000001209249145_section517513334611"></a>

isRunningLockTypeSupported\(type: RunningLockType\): Promise<boolean\>

查询系统是否支持该类型的锁。

-   参数：

    <a name="zh-cn_topic_0000001209249145_table12266112710718"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209249145_row626618271679"><th class="cellrowborder" valign="top" width="15.1%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209249145_p626612710712"><a name="zh-cn_topic_0000001209249145_p626612710712"></a><a name="zh-cn_topic_0000001209249145_p626612710712"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.55%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209249145_p826613271875"><a name="zh-cn_topic_0000001209249145_p826613271875"></a><a name="zh-cn_topic_0000001209249145_p826613271875"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.100000000000001%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209249145_p142678273718"><a name="zh-cn_topic_0000001209249145_p142678273718"></a><a name="zh-cn_topic_0000001209249145_p142678273718"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.25%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209249145_p1926718271072"><a name="zh-cn_topic_0000001209249145_p1926718271072"></a><a name="zh-cn_topic_0000001209249145_p1926718271072"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209249145_row162676272717"><td class="cellrowborder" valign="top" width="15.1%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209249145_p1826716272716"><a name="zh-cn_topic_0000001209249145_p1826716272716"></a><a name="zh-cn_topic_0000001209249145_p1826716272716"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.55%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209249145_p42673277712"><a name="zh-cn_topic_0000001209249145_p42673277712"></a><a name="zh-cn_topic_0000001209249145_p42673277712"></a>RunningLockType</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209249145_p426792717710"><a name="zh-cn_topic_0000001209249145_p426792717710"></a><a name="zh-cn_topic_0000001209249145_p426792717710"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.25%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209249145_p1426717270710"><a name="zh-cn_topic_0000001209249145_p1426717270710"></a><a name="zh-cn_topic_0000001209249145_p1426717270710"></a>需要查询的锁的类型。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001209249145_table82682027272"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209249145_row92681627972"><th class="cellrowborder" valign="top" width="25.569999999999997%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001209249145_p19268192715713"><a name="zh-cn_topic_0000001209249145_p19268192715713"></a><a name="zh-cn_topic_0000001209249145_p19268192715713"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.42999999999999%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001209249145_p22684273719"><a name="zh-cn_topic_0000001209249145_p22684273719"></a><a name="zh-cn_topic_0000001209249145_p22684273719"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209249145_row1926882720712"><td class="cellrowborder" valign="top" width="25.569999999999997%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001209249145_p172682272071"><a name="zh-cn_topic_0000001209249145_p172682272071"></a><a name="zh-cn_topic_0000001209249145_p172682272071"></a>Promise&lt;boolean&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.42999999999999%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001209249145_p102681127973"><a name="zh-cn_topic_0000001209249145_p102681127973"></a><a name="zh-cn_topic_0000001209249145_p102681127973"></a>Promise实例，用于异步获取返回值，支持返回true，不支持返回false。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    runninglock.isRunningLockTypeSupported(runninglock.RunningLockType.PROXIMITY_SCREEN_CONTROL)
    .then(supported => {
        console.info('PROXIMITY_SCREEN_CONTROL support status is ' + supported);
        done();
    })
    .catch(error => {
        console.log('error: ' + error);
        done();
    });
    ```


## runningLock.createRunningLock<a name="zh-cn_topic_0000001209249145_section787751152220"></a>

createRunningLock\(name: string, type: RunningLockType, callback: AsyncCallback<RunningLock\>\): void

创建Runninglock锁。

-   参数：

    <a name="zh-cn_topic_0000001209249145_table9878312223"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209249145_row6878618227"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209249145_p1487811115229"><a name="zh-cn_topic_0000001209249145_p1487811115229"></a><a name="zh-cn_topic_0000001209249145_p1487811115229"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.88%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209249145_p1987813113226"><a name="zh-cn_topic_0000001209249145_p1987813113226"></a><a name="zh-cn_topic_0000001209249145_p1987813113226"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.8100000000000005%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209249145_p10878101102213"><a name="zh-cn_topic_0000001209249145_p10878101102213"></a><a name="zh-cn_topic_0000001209249145_p10878101102213"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.489999999999995%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209249145_p68781112224"><a name="zh-cn_topic_0000001209249145_p68781112224"></a><a name="zh-cn_topic_0000001209249145_p68781112224"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209249145_row205362045162115"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209249145_p5536134542111"><a name="zh-cn_topic_0000001209249145_p5536134542111"></a><a name="zh-cn_topic_0000001209249145_p5536134542111"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.88%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209249145_p5536114512117"><a name="zh-cn_topic_0000001209249145_p5536114512117"></a><a name="zh-cn_topic_0000001209249145_p5536114512117"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.8100000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209249145_p1253617450215"><a name="zh-cn_topic_0000001209249145_p1253617450215"></a><a name="zh-cn_topic_0000001209249145_p1253617450215"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.489999999999995%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209249145_p155361545102116"><a name="zh-cn_topic_0000001209249145_p155361545102116"></a><a name="zh-cn_topic_0000001209249145_p155361545102116"></a>锁的名字。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001209249145_row19878113221"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209249145_p1087811152212"><a name="zh-cn_topic_0000001209249145_p1087811152212"></a><a name="zh-cn_topic_0000001209249145_p1087811152212"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.88%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209249145_p14878615224"><a name="zh-cn_topic_0000001209249145_p14878615224"></a><a name="zh-cn_topic_0000001209249145_p14878615224"></a>RunningLockType</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.8100000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209249145_p198788152211"><a name="zh-cn_topic_0000001209249145_p198788152211"></a><a name="zh-cn_topic_0000001209249145_p198788152211"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.489999999999995%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209249145_p1287815113222"><a name="zh-cn_topic_0000001209249145_p1287815113222"></a><a name="zh-cn_topic_0000001209249145_p1287815113222"></a>要创建的锁的类型。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001209249145_row84458101013"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209249145_p104459119108"><a name="zh-cn_topic_0000001209249145_p104459119108"></a><a name="zh-cn_topic_0000001209249145_p104459119108"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.88%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209249145_p144619141011"><a name="zh-cn_topic_0000001209249145_p144619141011"></a><a name="zh-cn_topic_0000001209249145_p144619141011"></a>AsyncCallback&lt;<a href="#zh-cn_topic_0000001209249145_section189341937163212">RunningLock</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.8100000000000005%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209249145_p844617111014"><a name="zh-cn_topic_0000001209249145_p844617111014"></a><a name="zh-cn_topic_0000001209249145_p844617111014"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.489999999999995%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209249145_p14467151017"><a name="zh-cn_topic_0000001209249145_p14467151017"></a><a name="zh-cn_topic_0000001209249145_p14467151017"></a>指定的callback回调方法，用于获取返回的RunningLock锁对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
    .then(runninglock => {
        var used = runninglock.isUsed();
        console.info('runninglock is used: ' + used);
        runninglock.lock(500);
        used = runninglock.isUsed();
        console.info('after lock runninglock is used ' + used);
        done();
    })
    .catch(error => {
        console.log('create runningLock test error: ' + error);
        done();
    })
    ```


## runningLock.createRunningLock<a name="zh-cn_topic_0000001209249145_section16799155115717"></a>

createRunningLock\(name: string, type: RunningLockType\): Promise<RunningLock\>

创建Runninglock锁。

-   参数：

    <a name="zh-cn_topic_0000001209249145_table254113503814"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209249145_row85411350182"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209249145_p15415503818"><a name="zh-cn_topic_0000001209249145_p15415503818"></a><a name="zh-cn_topic_0000001209249145_p15415503818"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.57%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209249145_p4541105010811"><a name="zh-cn_topic_0000001209249145_p4541105010811"></a><a name="zh-cn_topic_0000001209249145_p4541105010811"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.1%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209249145_p1554115507812"><a name="zh-cn_topic_0000001209249145_p1554115507812"></a><a name="zh-cn_topic_0000001209249145_p1554115507812"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="39.51%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209249145_p5541650982"><a name="zh-cn_topic_0000001209249145_p5541650982"></a><a name="zh-cn_topic_0000001209249145_p5541650982"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209249145_row55417507819"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209249145_p1754114500810"><a name="zh-cn_topic_0000001209249145_p1754114500810"></a><a name="zh-cn_topic_0000001209249145_p1754114500810"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.57%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209249145_p65412501586"><a name="zh-cn_topic_0000001209249145_p65412501586"></a><a name="zh-cn_topic_0000001209249145_p65412501586"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.1%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209249145_p1354195015810"><a name="zh-cn_topic_0000001209249145_p1354195015810"></a><a name="zh-cn_topic_0000001209249145_p1354195015810"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209249145_p654111501384"><a name="zh-cn_topic_0000001209249145_p654111501384"></a><a name="zh-cn_topic_0000001209249145_p654111501384"></a>锁的名字。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001209249145_row454111501682"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209249145_p1054275016813"><a name="zh-cn_topic_0000001209249145_p1054275016813"></a><a name="zh-cn_topic_0000001209249145_p1054275016813"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.57%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209249145_p55426505812"><a name="zh-cn_topic_0000001209249145_p55426505812"></a><a name="zh-cn_topic_0000001209249145_p55426505812"></a>RunningLockType</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.1%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209249145_p1254210501587"><a name="zh-cn_topic_0000001209249145_p1254210501587"></a><a name="zh-cn_topic_0000001209249145_p1254210501587"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="39.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209249145_p1254245010819"><a name="zh-cn_topic_0000001209249145_p1254245010819"></a><a name="zh-cn_topic_0000001209249145_p1254245010819"></a>要创建的锁的类型。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001209249145_table17542250488"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209249145_row35421550384"><th class="cellrowborder" valign="top" width="32.57%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001209249145_p35421501189"><a name="zh-cn_topic_0000001209249145_p35421501189"></a><a name="zh-cn_topic_0000001209249145_p35421501189"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="67.43%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001209249145_p1254213507819"><a name="zh-cn_topic_0000001209249145_p1254213507819"></a><a name="zh-cn_topic_0000001209249145_p1254213507819"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209249145_row165431250282"><td class="cellrowborder" valign="top" width="32.57%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001209249145_p115430501589"><a name="zh-cn_topic_0000001209249145_p115430501589"></a><a name="zh-cn_topic_0000001209249145_p115430501589"></a>Promise&lt;<a href="#zh-cn_topic_0000001209249145_section189341937163212">RunningLock</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="67.43%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001209249145_p165439501082"><a name="zh-cn_topic_0000001209249145_p165439501082"></a><a name="zh-cn_topic_0000001209249145_p165439501082"></a>Promise实例，用于异步获取返回的RunningLock锁对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    runningLock.createRunningLock("running_lock_test", runningLock.RunningLockType.BACKGROUND)
    .then(runninglock => {
        console.info('create runningLock success');
        done();
    })
    .catch(error => {
        console.log('create runningLock test error: ' + error);
        done();
    })
    ```


## RunningLock<a name="zh-cn_topic_0000001209249145_section189341937163212"></a>

阻止系统休眠的锁。

### lock<a name="zh-cn_topic_0000001209249145_section86521450132716"></a>

lock\(timeout: number\): void

锁定和持有RunningLock

-   参数：

    <a name="zh-cn_topic_0000001209249145_table206539501273"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209249145_row3653205002714"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001209249145_p165311506273"><a name="zh-cn_topic_0000001209249145_p165311506273"></a><a name="zh-cn_topic_0000001209249145_p165311506273"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001209249145_p1065365082714"><a name="zh-cn_topic_0000001209249145_p1065365082714"></a><a name="zh-cn_topic_0000001209249145_p1065365082714"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001209249145_p4653175062711"><a name="zh-cn_topic_0000001209249145_p4653175062711"></a><a name="zh-cn_topic_0000001209249145_p4653175062711"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001209249145_p665425019272"><a name="zh-cn_topic_0000001209249145_p665425019272"></a><a name="zh-cn_topic_0000001209249145_p665425019272"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209249145_row7654150172712"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001209249145_p0444142272919"><a name="zh-cn_topic_0000001209249145_p0444142272919"></a><a name="zh-cn_topic_0000001209249145_p0444142272919"></a>timeout</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001209249145_p26542503275"><a name="zh-cn_topic_0000001209249145_p26542503275"></a><a name="zh-cn_topic_0000001209249145_p26542503275"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001209249145_p17654105062720"><a name="zh-cn_topic_0000001209249145_p17654105062720"></a><a name="zh-cn_topic_0000001209249145_p17654105062720"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001209249145_p965405018273"><a name="zh-cn_topic_0000001209249145_p965405018273"></a><a name="zh-cn_topic_0000001209249145_p965405018273"></a>锁定和持有Runninglock的时长。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    runninglock.createRunningLock("running_lock_test", runninglock.RunningLockType.BACKGROUND)
    .then(runningLock => {
        runningLock.lock(100)
        console.info('create runningLock success')
    })
    .catch(error => {
        console.log('Lock runningLock test error: ' + error)
    });
    ```


### unlock<a name="zh-cn_topic_0000001209249145_section19100160122813"></a>

unlock\(\): void

释放Runninglock锁。

-   示例：

    ```
    runninglock.createRunningLock("running_lock_test", runninglock.RunningLockType.BACKGROUND)
    .then(runningLock => {
        runningLock.unlock()
        console.info('unLock runningLock success')
    })
    .catch(error => {
        console.log('unLock runningLock test error: ' + error)
    });
    ```


### isUsed<a name="zh-cn_topic_0000001209249145_section1410593619146"></a>

isUsed\(\): boolean

查询当前Runninglock是持有状态，还是释放状态。

-   返回值：

    <a name="zh-cn_topic_0000001209249145_table115061181517"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001209249145_row1150161121510"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001209249145_p1015015113159"><a name="zh-cn_topic_0000001209249145_p1015015113159"></a><a name="zh-cn_topic_0000001209249145_p1015015113159"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001209249145_p2150211201512"><a name="zh-cn_topic_0000001209249145_p2150211201512"></a><a name="zh-cn_topic_0000001209249145_p2150211201512"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001209249145_row17150811131514"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001209249145_p1150161110157"><a name="zh-cn_topic_0000001209249145_p1150161110157"></a><a name="zh-cn_topic_0000001209249145_p1150161110157"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001209249145_p51501611141518"><a name="zh-cn_topic_0000001209249145_p51501611141518"></a><a name="zh-cn_topic_0000001209249145_p51501611141518"></a>当前Runninglock是持有状态返回true，释放状态返回false。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    runninglock.createRunningLock("running_lock_test", runninglock.RunningLockType.BACKGROUND)
    .then(runningLock => {
        var used = runningLock.isUsed()
        console.info('runningLock used status: ' + used)
    })
    .catch(error => {
        console.log('runningLock isUsed test error: ' + error)
    });
    ```


