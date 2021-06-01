# Reporting Modem Events<a name="EN-US_TOPIC_0000001149173923"></a>

-   [When to Use](#section337mcpsimp)
-   [Available APIs](#section340mcpsimp)
-   [How to Develop](#section183291958165215)
-   [\(Optional\) Commissioning and Verification](#section405mcpsimp)

## When to Use<a name="section337mcpsimp"></a>

In a modem node thread, the messages reported by the modem are read cyclically, parsed into specific events, and then reported to RIL Adapter.

## Available APIs<a name="section340mcpsimp"></a>

The following table describes the API for reporting modem events.

**Table  1**  API for reporting modem events

<a name="table343mcpsimp"></a>
<table><thead align="left"><tr id="row349mcpsimp"><th class="cellrowborder" valign="top" width="56.99999999999999%" id="mcps1.2.3.1.1"><p id="p351mcpsimp"><a name="p351mcpsimp"></a><a name="p351mcpsimp"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="43%" id="mcps1.2.3.1.2"><p id="p353mcpsimp"><a name="p353mcpsimp"></a><a name="p353mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row355mcpsimp"><td class="cellrowborder" valign="top" width="56.99999999999999%" headers="mcps1.2.3.1.1 "><p id="p357mcpsimp"><a name="p357mcpsimp"></a><a name="p357mcpsimp"></a>static void OnNotificationResponse(const char *s, const char *sms_pdu)</p>
</td>
<td class="cellrowborder" valign="top" width="43%" headers="mcps1.2.3.1.2 "><p id="p359mcpsimp"><a name="p359mcpsimp"></a><a name="p359mcpsimp"></a>Reports modem events.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section183291958165215"></a>

In the  **s\_tid\_read**  thread of the modem node, call  **OnNotificationResponse\(\)**  to parse the data read into a specific event and call  **OnRadioEventNotify\(\)**  to report the generated event to RIL Adapter.

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
    ...
}
```

## \(Optional\) Commissioning and Verification<a name="section405mcpsimp"></a>

1.  Use the  **HDC**  tool to connect to a commissioning device, and run the  **hdc file send**  command to send the generated  **libvendor.z.so**  library file to the  **/system/lib/**  directory.
2.  Run the  **hdc shell sync**  and  **hdc shell reboot**  commands to restart the device.
3.  Run the  **hdc shell hilog**  command to check whether  **OnNotificationResponse\(\)**  is successfully executed based on the log information.

