# IPowerHdiCallback<a name="ZH-CN_TOPIC_0000001343120345"></a>

## **概述**<a name="section1345009711083932"></a>

**所属模块:**

[Power](power.md)

## **汇总**<a name="section183963458083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table76797656083932"></a>
<table><thead align="left"><tr id="row1049640294083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p764425193083932"><a name="p764425193083932"></a><a name="p764425193083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p112614654083932"><a name="p112614654083932"></a><a name="p112614654083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row910371948083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32862176083932"><a name="p32862176083932"></a><a name="p32862176083932"></a><a href="interface_i_power_hdi_callback.md#a3675643bb6747ccf1ec5de74dd0fd52b">OnSuspend</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p169520350083932"><a name="p169520350083932"></a><a name="p169520350083932"></a>休眠状态的回调方法。 <a href="interface_i_power_hdi_callback.md#a3675643bb6747ccf1ec5de74dd0fd52b">更多...</a></p>
</td>
</tr>
<tr id="row410421062083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1108527358083932"><a name="p1108527358083932"></a><a name="p1108527358083932"></a><a href="interface_i_power_hdi_callback.md#a4f67c3271d3466e91bd180a40ebc5927">OnWakeup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p300598574083932"><a name="p300598574083932"></a><a name="p300598574083932"></a>唤醒状态的回调方法。 <a href="interface_i_power_hdi_callback.md#a4f67c3271d3466e91bd180a40ebc5927">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section824689768083932"></a>

休眠/唤醒状态的回调。

服务创建此回调对象后，可以调用IPowerInterface的接口注册回调，从而订阅休眠/唤醒状态的变化。

**Since：**

3.1

## **成员函数说明**<a name="section1800992126083932"></a>

## OnSuspend\(\)<a name="a3675643bb6747ccf1ec5de74dd0fd52b"></a>

```
IPowerHdiCallback::OnSuspend ()
```

**描述：**

休眠状态的回调方法。

当设备进入休眠状态时，将通过此方法通知给服务。

## OnWakeup\(\)<a name="a4f67c3271d3466e91bd180a40ebc5927"></a>

```
IPowerHdiCallback::OnWakeup ()
```

**描述：**

唤醒状态的回调方法。

当设备进入唤醒状态时，将通过此方法通知给服务。

