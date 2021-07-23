# appspawn应用孵化组件<a name="ZH-CN_TOPIC_0000001063680582"></a>

appspawn被init启动后，向IPC框架注册服务名称，之后等待接收进程间消息，根据消息解析结果启动应用服务并赋予其对应权限。

appspawn注册的服务名称为“appspawn”，可通过包含“base\\startup\\appspawn\_lite\\services\\include\\appspawn\_service.h“头文件，获取服务名称对应的宏APPSPAWN\_SERVICE\_NAME定义。在安全子系统限制规则下，目前仅Ability Manager Service有权限可以向appspawn发送的进程间消息。

appspawn接收的消息为json格式，如下所示：

"\{\\"bundleName\\":\\"testvalid1\\",\\"identityID\\":\\"1234\\",\\"uID\\":1000,\\"gID\\":1000,\\"capability\\":\[0\]\}"

**表 1**  字段说明

<a name="table164915296372"></a>
<table><thead align="left"><tr id="row6650142913713"><th class="cellrowborder" valign="top" width="39.489999999999995%" id="mcps1.2.3.1.1"><p id="p17650112914379"><a name="p17650112914379"></a><a name="p17650112914379"></a>字段名</p>
</th>
<th class="cellrowborder" valign="top" width="60.51%" id="mcps1.2.3.1.2"><p id="p865032916376"><a name="p865032916376"></a><a name="p865032916376"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row36506298373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p76501029113715"><a name="p76501029113715"></a><a name="p76501029113715"></a>bundleName</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p2650329183715"><a name="p2650329183715"></a><a name="p2650329183715"></a>即将启动的应用服务进程名，长度≥7字节，≤127字节。</p>
</td>
</tr>
<tr id="row86501129183712"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p2065010298379"><a name="p2065010298379"></a><a name="p2065010298379"></a>identityID</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p13650192963715"><a name="p13650192963715"></a><a name="p13650192963715"></a>AMS为新进程生成的标识符，由appspawn透传给新进程，长度≥1字节，≤24字节。</p>
</td>
</tr>
<tr id="row13650329103719"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p16501292377"><a name="p16501292377"></a><a name="p16501292377"></a>uID</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p186503291371"><a name="p186503291371"></a><a name="p186503291371"></a>即将启动的应用服务进程的uID，必须为正值。</p>
</td>
</tr>
<tr id="row187625816314"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p188771758833"><a name="p188771758833"></a><a name="p188771758833"></a>gID</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p187716587310"><a name="p187716587310"></a><a name="p187716587310"></a>即将启动的应用服务进程的gID，必须为正值。</p>
</td>
</tr>
<tr id="row106508294373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p16501829183715"><a name="p16501829183715"></a><a name="p16501829183715"></a>capability</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p11650182953717"><a name="p11650182953717"></a><a name="p11650182953717"></a>即将启动的应用服务进程所需的capability权限，数量≤10个。</p>
</td>
</tr>
</tbody>
</table>

