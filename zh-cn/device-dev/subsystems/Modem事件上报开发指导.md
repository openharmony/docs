# Modem事件上报开发指导<a name="ZH-CN_TOPIC_0000001149173923"></a>

-   [场景介绍](#section337mcpsimp)
-   [接口说明](#section340mcpsimp)
-   [开发步骤](#section183291958165215)
-   [调测验证（可选）](#section405mcpsimp)

## 场景介绍<a name="section337mcpsimp"></a>

Modem事件上报是指在Modem设备节点读取线程循环读取到Modem主动上报的消息后，将读取到的消息解析为对应的Modem上报事件，然后上报给RIL Adapter。

## 接口说明<a name="section340mcpsimp"></a>

Modem事件上报接口。

**表 1**  Modem事件上报接口功能介绍

<a name="table343mcpsimp"></a>
<table><thead align="left"><tr id="row349mcpsimp"><th class="cellrowborder" valign="top" width="56.99999999999999%" id="mcps1.2.3.1.1"><p id="p351mcpsimp"><a name="p351mcpsimp"></a><a name="p351mcpsimp"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="43%" id="mcps1.2.3.1.2"><p id="p353mcpsimp"><a name="p353mcpsimp"></a><a name="p353mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row355mcpsimp"><td class="cellrowborder" valign="top" width="56.99999999999999%" headers="mcps1.2.3.1.1 "><p id="p357mcpsimp"><a name="p357mcpsimp"></a><a name="p357mcpsimp"></a>static void OnNotificationResponse(const char *s, const char *sms_pdu)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.3.1.2 "><p id="p359mcpsimp"><a name="p359mcpsimp"></a><a name="p359mcpsimp"></a>该接口对Modem上报的事件进行分发处理</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section183291958165215"></a>

在Modem设备节点读取线程s\_tid\_read里调用OnNotificationResponse\(\)解析具体的Modem上报事件，并调用OnRadioEventNotify\(\)把解析得到的事件上报给RIL Adapter。

```
bool IsCallStatusUpdated(const char *s)
{
    return (StrBeginWith(s, "+CRING:") 
        || StrBeginWith(s, "RING") 
        || StrBeginWith(s, "NO CARRIER") 
        || StrBeginWith(s, "+CCWA"));
}
 
bool IsSetRadioPower(const char *s)
{
    return StrBeginWith(s, "+CFUN: 0");
}
 
static void OnNotificationResponse(const char *s, const char *sms_pdu) 
{ 
    if (IsCallStatusUpdated(s)) { 
        OnRadioEventNotify(HNOTI_CALL_STATUS, NULL, 0); 
    } else if (IsSetRadioPower(s)) { 
        SetRadioState(RADIO_OFF); 
    } 
    ……
}
```

## 调测验证（可选）<a name="section405mcpsimp"></a>

1.  用hdc工具连接调试设备，把编译生成的libvendor.z.so库文件通过hdc file send推到/system/lib/目录下。
2.  执行hdc shell sync, hdc shell reboot重启设备。
3.  hdc shell后输入hilog命令，查看OnNotificationResponse\(\)是否正确执行完成，根据日志信息判断是否成功。

