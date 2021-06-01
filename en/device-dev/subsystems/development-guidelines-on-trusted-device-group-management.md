# Development Guidelines on Trusted Device Group Management<a name="EN-US_TOPIC_0000001059937740"></a>

-   [When to Use](#section18502174174019)
-   [Available APIs](#section1633115419401)
-   [How to Develop](#section17516229192313)
-   [Debugging and Verification](#section427316292411)

## When to Use<a name="section18502174174019"></a>

When a distributed service needs to exploit the secure communication channel provided by the distributed virtual bus for different devices, it can use the trusted device group management component to create groups of trusted devices. Distributed applications can establish and use secure, trusted relationships between devices based on the authentication capabilities for devices using different HUAWEI IDs, such as PIN code, QR code, and OneHop, and the capabilities for grouped devices using the same HUAWEI ID. For a device on which you have not logged in using your HUAWEI ID, you can enter the PIN code or scan the QR code to obtain the connection and PIN code information of the device. Then you can create a group of trusted devices and add this device to the group. If other applications have created and shared their groups of trusted devices, or have logged in using the same HUAWEI ID as yours, you can call APIs to query and use the groups.

## Available APIs<a name="section1633115419401"></a>

The following tables list the innerkits APIs provided by trusted device group management. These APIs are intended for system applications only.

**Table  1**  Java APIs provided by trusted device group management

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row34145016535"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p188293163217"><a name="p188293163217"></a><a name="p188293163217"></a>public static DeviceGroupManager getInstance(Abilityability, StringappID, IHichainGroupCallbackcallbackHandler)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p13562171015712"><a name="p13562171015712"></a><a name="p13562171015712"></a>Obtains a <strong id="b73411940163616"><a name="b73411940163616"></a><a name="b73411940163616"></a>DeviceGroupManager</strong> instance and registers a listener.</p>
</td>
</tr>
<tr id="row1746172917474"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p2131144717619"><a name="p2131144717619"></a><a name="p2131144717619"></a>int createGroup(String appId, String groupName, int groupType, String groupInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p2431455765"><a name="p2431455765"></a><a name="p2431455765"></a>Creates a group of trusted devices.</p>
</td>
</tr>
<tr id="row10992232154714"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p685215538611"><a name="p685215538611"></a><a name="p685215538611"></a>public int deleteGroup(String gourpId)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p126575774517"><a name="p126575774517"></a><a name="p126575774517"></a>Deletes a group of trusted devices.</p>
</td>
</tr>
<tr id="row67932413301"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p98022416308"><a name="p98022416308"></a><a name="p98022416308"></a>public String getLocalConnectInfo()</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p4801624183014"><a name="p4801624183014"></a><a name="p4801624183014"></a>Obtains the network connection information of the local device.</p>
</td>
</tr>
<tr id="row1440154863415"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1040284812348"><a name="p1040284812348"></a><a name="p1040284812348"></a>int addMemberToGroup(String appId, long requestId, String addParams, String connectParams, int groupType)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p240224817343"><a name="p240224817343"></a><a name="p240224817343"></a>Adds a member to a specified group.</p>
</td>
</tr>
<tr id="row495164812345"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1795174853413"><a name="p1795174853413"></a><a name="p1795174853413"></a>int deleteMemberFromGroup(String appId, long requestId, String deleteParams, String connectParams)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1995144893411"><a name="p1995144893411"></a><a name="p1995144893411"></a>Deletes a member from a specified group.</p>
</td>
</tr>
<tr id="row4107114933418"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p3107194923412"><a name="p3107194923412"></a><a name="p3107194923412"></a>int cancelRequest(long requestId)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p11107849113418"><a name="p11107849113418"></a><a name="p11107849113418"></a>Cancels an ongoing request, for example, adding or deleting a member.</p>
</td>
</tr>
<tr id="row3270349193419"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p72707495346"><a name="p72707495346"></a><a name="p72707495346"></a>List&lt;String&gt; listJoinedGroups(int groupType)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p12701049183411"><a name="p12701049183411"></a><a name="p12701049183411"></a>Obtains a list of groups of a specified type to which the current device has been added.</p>
</td>
</tr>
<tr id="row84091549103413"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p440914915343"><a name="p440914915343"></a><a name="p440914915343"></a>List&lt;String&gt; listTrustedDevices(String groupId)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p104091749163412"><a name="p104091749163412"></a><a name="p104091749163412"></a>Obtains a list of devices in a specified group.</p>
</td>
</tr>
<tr id="row76661118163810"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p566691863810"><a name="p566691863810"></a><a name="p566691863810"></a>boolean isDeviceInGroup(String groupId, String deviceId)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p17666618193818"><a name="p17666618193818"></a><a name="p17666618193818"></a>Checks whether a specified device has been added to the given group.</p>
</td>
</tr>
<tr id="row8648246163810"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p564914683820"><a name="p564914683820"></a><a name="p564914683820"></a>List&lt;String&gt; getGroupInfo(String queryParams)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p96491546173820"><a name="p96491546173820"></a><a name="p96491546173820"></a>Obtains a list of information about the groups that match the input parameters.</p>
</td>
</tr>
<tr id="row6118113464013"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p41191334164018"><a name="p41191334164018"></a><a name="p41191334164018"></a>int setFriendsList(String groupId, List&lt;String&gt; friendsList)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1511919343403"><a name="p1511919343403"></a><a name="p1511919343403"></a>Adds a friend list to a specified group.</p>
</td>
</tr>
<tr id="row214411864111"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p3145131814120"><a name="p3145131814120"></a><a name="p3145131814120"></a>List&lt;String&gt; getFriendsList(String groupId)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p201450182414"><a name="p201450182414"></a><a name="p201450182414"></a>Obtains the friend list of a specified group.</p>
</td>
</tr>
<tr id="row15812171974119"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p208122190416"><a name="p208122190416"></a><a name="p208122190416"></a>int registerGroupNotice(String groupId, IHichainGroupChangeListener groupChangeListener)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p581281912419"><a name="p581281912419"></a><a name="p581281912419"></a>Registers a listener for changes to a specified group.</p>
</td>
</tr>
<tr id="row14944183024217"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p79441930184212"><a name="p79441930184212"></a><a name="p79441930184212"></a>int revokeGroupNotice(String groupId)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p159441630134217"><a name="p159441630134217"></a><a name="p159441630134217"></a>Revokes the listener for changes to a specified group.</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  C++ APIs provided by trusted device group management for internal applications to query group information using SA

<a name="table16387194455318"></a>
<table><thead align="left"><tr id="row4387544135313"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p1838719449537"><a name="p1838719449537"></a><a name="p1838719449537"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p113872044195317"><a name="p113872044195317"></a><a name="p113872044195317"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row83871844115314"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p0387174425316"><a name="p0387174425316"></a><a name="p0387174425316"></a>DeviceAuthProxy()</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p143877448539"><a name="p143877448539"></a><a name="p143877448539"></a>Obtains a <strong id="b148669279514"><a name="b148669279514"></a><a name="b148669279514"></a>DeviceAuthProxy</strong> instance.</p>
</td>
</tr>
<tr id="row93871544185318"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p19387144105311"><a name="p19387144105311"></a><a name="p19387144105311"></a>~DeviceAuthProxy()</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p9387944115313"><a name="p9387944115313"></a><a name="p9387944115313"></a>A destructor used to delete the <strong id="b69296716526"><a name="b69296716526"></a><a name="b69296716526"></a>DeviceAuthProxy</strong> instance.</p>
</td>
</tr>
<tr id="row16387144175313"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p6553322195518"><a name="p6553322195518"></a><a name="p6553322195518"></a>static int CheckAccessToGroup(const std::string &amp;groupId, const std::string &amp;pkgName);</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p9387174414536"><a name="p9387174414536"></a><a name="p9387174414536"></a>Checks whether an application with a specified bundle name can access a specified group.</p>
</td>
</tr>
<tr id="row12387194418531"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1338714416537"><a name="p1338714416537"></a><a name="p1338714416537"></a>static int CheckAccessToDevice(const std::string &amp;connDeviceId, const std::string &amp;pkgName);</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p938794418538"><a name="p938794418538"></a><a name="p938794418538"></a>Checks whether an application with a specified bundle name can access the group that contains a specified device.</p>
</td>
</tr>
<tr id="row1238744411534"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p9218125135811"><a name="p9218125135811"></a><a name="p9218125135811"></a>static std::vector&lt;std::string&gt; GetRelatedGroupInfo(const std::string &amp;connDeviceId);</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1388124411537"><a name="p1388124411537"></a><a name="p1388124411537"></a>Obtains information about all the groups that contain both the local device and the device with a specified ID.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section17516229192313"></a>

To develop trusted device group management, first obtain a management instance \(a callback to obtain group operation results is registered during the process\). Then you can use the instance to add or delete members, set a friend list for a group, and perform related query operations.

**Scenario 1**: Create a group.

```
private HwDeviceGroupManager hwDeviceGroupManager;
...
private HichainGroupCallback groupCallbackByA = new HichainGroupCallback() {
    @Override public void onFinish(long requestId, GroupOperation operationCode, String returnData) {

    }    
    @Override public void onError(long requestId, GroupOperation operationCode, int errorCode, String errorReturn) { 

    }    
    @Override public String onRequest(long requestId, GroupOperation operationCode, String reqParams) {
        JSONObject onRequestJson = generateConfirmation(REQUEST_ACCEPTED);       
        return onRequestJson.toString();
    }
};
...
Optional<Context> context = convertAbilityToContext(mAbility);
Context ctxt = context.get();
hwDeviceGroupManager = HwDeviceGroupManager.getInstance(ctxt, APP_ID, groupCallbackByA);
int ret = hwDeviceGroupManager.createGroup(APP_ID, GROUP_NAME, GROUP_TYPE, GROUP_INFO);
```

1.  Declare the private member variable of the  **HwDeviceGroupManager**  instance.

    ```
    private HwDeviceGroupManager hwDeviceGroupManager;
    ```

2.  Create a callback for group management operations.

    ```
    private HichainGroupCallback groupCallbackByA = new HichainGroupCallback();
    ```

3.  Obtain a  **HwDeviceGroupManager**  instance. \(In distributed scenarios, the same application on different devices must use the same  **APP\_ID**.\)

    ```
    hwDeviceGroupManager = HwDeviceGroupManager.getInstance(ctxt, APP_ID, groupCallbackByA);
    ```

4.  Call the  **createGroup**  function to create a group. If  **0**  is returned, the creation request is submitted successfully.

    ```
    int ret = hwDeviceGroupManager.createGroup(APP_ID, GROUP_NAME, GROUP_TYPE, GROUP_INFO);
    ```

5.  After the group is created,  **onFinish**  is called. In this callback, the value of  **operationCode**  is  **OperationCode.CREATE**, indicating a group creation operation.  **returnData**  is in JSON format and contains the  **groupId**  field, indicating the ID of the created group.

**Scenario 2**: Add an authenticated device \(member\) to a group so that you can initiate trusted, encrypted connections to the device through the distributed virtual bus.

```
deviceGroupManager = DeviceGroupManager.getInstance(mAbility, APP_ID, hichainGroupCallback);
private static final String CONN_PARAM ="{\"DEVICE_ID\":\"11111111\",\"WIFI_IP\":\"192.168.43.149\",\"WIFI_PORT\":\"30000\",\"BLE_MAC\":\"\"}";
private static final String ADD_PARAM ="{\"groupId\":\"344C1C8B149\",\"groupName\":\"myGroup\",\"addId\":\"11111111\",\"isAdmin\":\"false\"}";
private static final int GROUP_TYPE = 256;
int result = deviceGroupManager.addMemberToGroup(APP_ID, reqId, ADD_PARAM, CONN_PARAM, GROUP_TYPE);
```

1.  Obtain an  **HwDeviceGroupManager**  instance.

    ```
    deviceGroupManager = HwDeviceGroupManager.getInstance(mAbility, APP_ID, hichainGroupCallback);
    ```

2.  Set network connection parameters for the member to add \(in JSON format\), which are network parameters supported by the distributed virtual bus, such as  **WIFI\_IP**,  **WIFI\_PORT**,  **BLR\_MAC**, and  **DEVICE\_ID**. For details about the parameters, see the distributed virtual bus development guidelines.

    ```
    String CONN_PARAM ="{\"DEVICE_ID\":\"11111111\",\"WIFI_IP\":\"192.168.43.149\",\"WIFI_PORT\":\"30000\",\"BLE_MAC\":\"\"}";
    ```

3.  Set parameters for the member to add \(in JSON format\), including the group ID, name, and whether the member is an administrator. If the member is invited to add a group, the value of  **isAdmin**  is  **true**; otherwise, the value of  **isAdmin**  is  **false**.

    ```
    String ADD_PARAM ="{\"groupId\":\"344C1C8B149\",\"groupName\":\"myGroup\",\"addId\":\"11111111\",\"isAdmin\":\"false\"}";
    ```

4.  Set the type of the target group to  **256**, indicating a P2P group.

    ```
    private static final int GROUP_TYPE = 256;
    ```

5.  Set  **generateConfirmation**  of the  **onRequest**  function in  **HichainGroupCallback**.  **PIN\_CODE**  indicates the PIN code, which is input by users on the UI of the service. \(In a distributed communication, two devices must use the same PIN code.\)

    ```
    private JSONObject generateConfirmation(int confirmation) {    
        JSONObject jsonObject = new JSONObject();    
        try {    jsonObject.put("pinCode", PIN_CODE);
                 jsonObject.put("confirmation", confirmation);    
        } catch (JSONException e) {
            LogUtil.error(TAG, "" + e.getMessage());    
        }
        return jsonObject;
    }
    ```

6.  Call the  **addMemberToGroup**  function to add the member to the group.

    ```
    result = deviceGroupManager.addMemberToGroup(APP_ID, reqId, ADD_PARAM, CONN_PARAM, GROUP_TYPE);
    ```

7.  Check whether  **HichainGroupCallback.onFinish**  is called \(**operationCode**  is  **OperationCode.JOIN**\). If it is called, the member is added successfully.
8.  Call APIs of the distributed virtual bus to create secure sessions between devices.

## Debugging and Verification<a name="section427316292411"></a>

1. Develop an application with OpenHarmony.

2. Develop an application by following the development guidelines.

3. Create a group. If the  **onFinish**  callback is invoked, the group is created successfully.

4. Deploy the same application on two devices, A and B.

5. Transmit the connection parameters of device B to device A through a QR code.

6. In the application on device A, create group1 and call the API to add device B to group1. If  **HichainGroupCallback.onFinish**  is called, device B is successfully added to group1.

