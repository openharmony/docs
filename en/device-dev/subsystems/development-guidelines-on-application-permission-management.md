# Development Guidelines on Application Permission Management<a name="EN-US_TOPIC_0000001058864249"></a>

-   [How Application Permission Management Works](#section193961322175011)
-   [When to Use](#section18502174174019)
-   [Available APIs](#section1633115419401)
-   [How to Develop](#section022611498210)

## How Application Permission Management Works<a name="section193961322175011"></a>

OpenHarmony allows users to install third-party applications and controls calls made by third-party applications to sensitive permissions. When developing an application, you need to declare the sensitive permissions that the application may require in the  **profile.json**  file. The permissions include static and dynamic ones. Static permissions need to be registered during application installation, and dynamic permissions can be obtained only upon user authorization. Authorization modes include system settings, manual authorization by applications, and others. In addition, application signature control is used to ensure that the application installation package has been confirmed by the device vendor.

**Table  1**  OpenHarmony permissions

<a name="table058213105512"></a>
<table><thead align="left"><tr id="row4583510656"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.1"><p id="p75834101518"><a name="p75834101518"></a><a name="p75834101518"></a><span id="text1659749759"><a name="text1659749759"></a><a name="text1659749759"></a>OpenHarmony</span> Permission</p>
</th>
<th class="cellrowborder" valign="top" width="25.83258325832583%" id="mcps1.2.4.1.2"><p id="p1458351016516"><a name="p1458351016516"></a><a name="p1458351016516"></a>Grant Mode</p>
</th>
<th class="cellrowborder" valign="top" width="40.83408340834084%" id="mcps1.2.4.1.3"><p id="p105838101254"><a name="p105838101254"></a><a name="p105838101254"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row45831101153"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p155831510951"><a name="p155831510951"></a><a name="p155831510951"></a>ohos.permission.LISTEN_BUNDLE_CHANGE</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p158301014512"><a name="p158301014512"></a><a name="p158301014512"></a>system_grant (static permission)</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p155835101512"><a name="p155835101512"></a><a name="p155835101512"></a>Allows an application to listen for application changes.</p>
</td>
</tr>
<tr id="row958316106513"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1258313104515"><a name="p1258313104515"></a><a name="p1258313104515"></a>ohos.permission.GET_BUNDLE_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p16583161014519"><a name="p16583161014519"></a><a name="p16583161014519"></a>system_grant (static permission)</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p11583910850"><a name="p11583910850"></a><a name="p11583910850"></a>Allows an application to obtain information about other applications.</p>
</td>
</tr>
<tr id="row458351013520"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p11583310757"><a name="p11583310757"></a><a name="p11583310757"></a>ohos.permission.INSTALL_BUNDLE</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p95834109511"><a name="p95834109511"></a><a name="p95834109511"></a>system_grant (static permission)</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p858319108518"><a name="p858319108518"></a><a name="p858319108518"></a>Allows an application to install other applications.</p>
</td>
</tr>
<tr id="row139426341265"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p169421434164"><a name="p169421434164"></a><a name="p169421434164"></a>ohos.permission.CAMERA</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p1594212341164"><a name="p1594212341164"></a><a name="p1594212341164"></a>user_grant (dynamic permission)</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p1942334361"><a name="p1942334361"></a><a name="p1942334361"></a>Allows an application to use the camera to take photos and record videos at any time.</p>
</td>
</tr>
<tr id="row114648235612"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p746502318619"><a name="p746502318619"></a><a name="p746502318619"></a>ohos.permission.MODIFY_AUDIO_SETTINGS</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p6466223362"><a name="p6466223362"></a><a name="p6466223362"></a>system_grant (static permission)</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p8466323567"><a name="p8466323567"></a><a name="p8466323567"></a>Allows an application to modify global audio settings, such as the volume and speaker for output.</p>
</td>
</tr>
<tr id="row193133381266"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1631315381568"><a name="p1631315381568"></a><a name="p1631315381568"></a>ohos.permission.READ_MEDIA</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p1731320383610"><a name="p1731320383610"></a><a name="p1731320383610"></a>user_grant (dynamic permission)</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p931303817611"><a name="p931303817611"></a><a name="p931303817611"></a>Allows an application to read users' favorite videos.</p>
</td>
</tr>
<tr id="row738215284617"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p73824281363"><a name="p73824281363"></a><a name="p73824281363"></a>ohos.permission.MICROPHONE</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p1138217281162"><a name="p1138217281162"></a><a name="p1138217281162"></a>user_grant (dynamic permission)</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p1338214281661"><a name="p1338214281661"></a><a name="p1338214281661"></a>Allows an application to use the microphone for audio recording at any time.</p>
</td>
</tr>
<tr id="row1777413579619"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1577415710613"><a name="p1577415710613"></a><a name="p1577415710613"></a>ohos.permission.WRITE_MEDIA</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p14774175715612"><a name="p14774175715612"></a><a name="p14774175715612"></a>user_grant (dynamic permission)</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p677419573612"><a name="p677419573612"></a><a name="p677419573612"></a>Allows an application to write users' favorite music.</p>
</td>
</tr>
<tr id="row18922519719"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1892954719"><a name="p1892954719"></a><a name="p1892954719"></a>ohos.permission.DISTRIBUTED_DATASYNC</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p15892105875"><a name="p15892105875"></a><a name="p15892105875"></a>user_grant (dynamic permission)</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p12892175879"><a name="p12892175879"></a><a name="p12892175879"></a>Allows an application to manage distributed data transmission.</p>
</td>
</tr>
<tr id="row109781511376"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p797810117714"><a name="p797810117714"></a><a name="p797810117714"></a>ohos.permission.DISTRIBUTED_VIRTUALDEVICE</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p109787110712"><a name="p109787110712"></a><a name="p109787110712"></a>user_grant (dynamic permission)</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p19978813720"><a name="p19978813720"></a><a name="p19978813720"></a>Allows an application to use distributed virtualization features.</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>Static permission: a permission granted by the system during application installation. The sensitivity level of this type of permission is  **system\_grant**.
>Dynamic permission: a permission granted by users during application running. The sensitivity level of this type of permission is  **user\_grant**.

## When to Use<a name="section18502174174019"></a>

Application permissions are used to control access to system resources and features. In scenarios where an application wants to access features or data related to users' privacy, such as accessing hardware features of personal devices like cameras and microphones, and reading and writing media files, OpenHarmony uses the application permission management component to protect such features and data.

When developing a system application that requires a sensitive permission, you can call the corresponding API of the application permission management component to check whether the required permission is granted. If the permission is not granted, the application cannot use it.

## Available APIs<a name="section1633115419401"></a>

The following table lists the APIs available for application permission management. These APIs are only intended for system applications and services.

**Table  2**  APIs available for application permission management

<a name="table9789027162518"></a>
<table><thead align="left"><tr id="row9789427112518"><th class="cellrowborder" valign="top" width="55.66%" id="mcps1.2.3.1.1"><p id="p9790102717251"><a name="p9790102717251"></a><a name="p9790102717251"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="44.34%" id="mcps1.2.3.1.2"><p id="p779032715251"><a name="p779032715251"></a><a name="p779032715251"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row187901627112516"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p138014275353"><a name="p138014275353"></a><a name="p138014275353"></a>int CheckPermission(int uid, const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p57901727202510"><a name="p57901727202510"></a><a name="p57901727202510"></a>Checks whether the application with a specified UID has the permission to access system service APIs.</p>
</td>
</tr>
<tr id="row19341734164410"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p123453412448"><a name="p123453412448"></a><a name="p123453412448"></a>int CheckSelfPermission(const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p937645212447"><a name="p937645212447"></a><a name="p937645212447"></a>Checks whether the caller has the permission to access system service APIs.</p>
</td>
</tr>
<tr id="row879032715258"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p13071135133514"><a name="p13071135133514"></a><a name="p13071135133514"></a>int QueryPermission(const char *identifier, PermissionSaved **permissions, int *permNum)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p1379072718259"><a name="p1379072718259"></a><a name="p1379072718259"></a>Queries all permissions requested by the application and checks whether the requested permissions have been granted.</p>
</td>
</tr>
<tr id="row877239193516"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p878133903516"><a name="p878133903516"></a><a name="p878133903516"></a>int GrantPermission(const char *identifier, const char *permName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p678143943515"><a name="p678143943515"></a><a name="p678143943515"></a>Grants a specified permission to the application.</p>
</td>
</tr>
<tr id="row3616164223510"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p1617142163517"><a name="p1617142163517"></a><a name="p1617142163517"></a>int RevokePermission(const char *identifier, const char *permName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p06171242143517"><a name="p06171242143517"></a><a name="p06171242143517"></a>Revokes a specified permission from the application.</p>
</td>
</tr>
<tr id="row13790122742516"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p23273123365"><a name="p23273123365"></a><a name="p23273123365"></a>int GrantRuntimePermission(int uid, const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p177908273259"><a name="p177908273259"></a><a name="p177908273259"></a>Grants a specified runtime permission to the application.</p>
</td>
</tr>
<tr id="row18566191217452"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p169891916194512"><a name="p169891916194512"></a><a name="p169891916194512"></a>int RevokeRuntimePermission(int uid, const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p937132011440"><a name="p937132011440"></a><a name="p937132011440"></a>Revokes a specified runtime permission from the application.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section022611498210"></a>

This section uses the BMS as an example to describe the application permission development. Before starting development, you need to declare the required sensitive permissions in the  **config.json**  file. During application installation, the BMS calls APIs of the application permission management component to check whether the required permissions have been granted. If yes, the installation proceeds; if not, the installation fails.

1.  Declare the required permission \(**ohos.permission.INSTALL\_BUNDLE**\) in the  **config.json**  file.

    ```
    {
      ...
      "module": {
          "package": "com.huawei.kitframework",
          "deviceType": [
              "phone", "tv","tablet", "pc","car","smartWatch","sportsWatch","smartCamera", "smartVision"
          ],
          "reqPermissions": [{
            // Declare the ohos.permission.INSTALL_BUNDLE permission required for installing the application.
            "name": "ohos.permission.INSTALL_BUNDLE",   
            "reason": "install bundle",
            "usedScene": {
              "ability": [
                "KitFramework"
                ],
              "when": "always"
            }
          },
          {
            "name": "ohos.permission.LISTEN_BUNDLE_CHANGE",
            "reason": "install bundle",
            "usedScene": {
              "ability": [
                "KitFramework"
                ],
              "when": "always"
            }
          },
          {
            "name": "ohos.permission.GET_BUNDLE_INFO",
            "reason": "install bundle",
            "usedScene": {
              "ability": [
                "KitFramework"
                ],
              "when": "always"
            }
          }
          ],
        ...
    }
    ```

2.  The BMS calls the corresponding API of the application permission management component \(for example, the  **CheckPermission**  function with  **ohos.permission.INSTALL\_BUNDLE**  as an input parameter\) to check whether the BMS has the permission to install the application. If yes, the installation proceeds; if not, the installation fails.

    ```
    constexpr static char PERMISSION_INSTALL_BUNDLE[] = "ohos.permission.INSTALL_BUNDLE";
    
    bool Install(const char *hapPath, const InstallParam *installParam, InstallerCallback installerCallback)
    {
        if ((hapPath == nullptr) || (installerCallback == nullptr) || (installParam == nullptr)) {
            HILOG_ERROR(HILOG_MODULE_APP, "BundleManager install failed due to nullptr parameters");
            return false;
        }
        // Check whether the ohos.permission.INSTALL_BUNDLE permission has been granted.
        if (CheckPermission(0, static_cast<const char *>(PERMISSION_INSTALL_BUNDLE)) != GRANTED) {
            HILOG_ERROR(HILOG_MODULE_APP, "BundleManager install failed due to permission denied");
            return false;  // Application installation fails.
        }
        // Application installation process
        ...
    }
    ```


