# 应用权限管理开发指导<a name="ZH-CN_TOPIC_0000001058864249"></a>

## 运作机制<a name="section193961322175011"></a>

由于OpenHarmony允许安装三方应用，所以需要对三方应用的敏感权限调用进行管控，具体实现是应用在开发阶段就需要在profile.json中指明此应用在运行过程中可能会调用哪些敏感权限，这些权限包括静态权限和动态权限，静态权限表示只需要在安装阶段注册就可以，而动态权限一般表示获取用户的敏感信息，所以需要在运行时让用户确认才可以调用，授权方式包括系统设置应用手动授权等。除了运行时对应用调用敏感权限进行管控外，还需要利用应用签名管控手段确保应用安装包已经被设备厂商进行了确认。

**表 1**  OpenHarmony权限列表

<a name="table058213105512"></a>
<table><thead align="left"><tr id="row4583510656"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.1"><p id="p75834101518"><a name="p75834101518"></a><a name="p75834101518"></a><span id="text1659749759"><a name="text1659749759"></a><a name="text1659749759"></a>OpenHarmony</span>权限</p>
</th>
<th class="cellrowborder" valign="top" width="25.83258325832583%" id="mcps1.2.4.1.2"><p id="p1458351016516"><a name="p1458351016516"></a><a name="p1458351016516"></a>授权方式</p>
</th>
<th class="cellrowborder" valign="top" width="40.83408340834084%" id="mcps1.2.4.1.3"><p id="p105838101254"><a name="p105838101254"></a><a name="p105838101254"></a>权限说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row45831101153"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p155831510951"><a name="p155831510951"></a><a name="p155831510951"></a>ohos.permission.LISTEN_BUNDLE_CHANGE</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p158301014512"><a name="p158301014512"></a><a name="p158301014512"></a>system_grant（静态权限）</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p155835101512"><a name="p155835101512"></a><a name="p155835101512"></a>允许该应用获取应用变化消息。</p>
</td>
</tr>
<tr id="row958316106513"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1258313104515"><a name="p1258313104515"></a><a name="p1258313104515"></a>ohos.permission.GET_BUNDLE_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p16583161014519"><a name="p16583161014519"></a><a name="p16583161014519"></a>system_grant（静态权限）</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p11583910850"><a name="p11583910850"></a><a name="p11583910850"></a>允许该应用获取应用信息。</p>
</td>
</tr>
<tr id="row458351013520"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p11583310757"><a name="p11583310757"></a><a name="p11583310757"></a>ohos.permission.INSTALL_BUNDLE</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p95834109511"><a name="p95834109511"></a><a name="p95834109511"></a>system_grant（静态权限）</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p858319108518"><a name="p858319108518"></a><a name="p858319108518"></a>允许该应用安装应用。</p>
</td>
</tr>
<tr id="row139426341265"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p169421434164"><a name="p169421434164"></a><a name="p169421434164"></a>ohos.permission.CAMERA</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p1594212341164"><a name="p1594212341164"></a><a name="p1594212341164"></a>user_grant（动态权限）</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p1942334361"><a name="p1942334361"></a><a name="p1942334361"></a>此应用可随时使用相机拍摄照片和录制视频。</p>
</td>
</tr>
<tr id="row114648235612"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p746502318619"><a name="p746502318619"></a><a name="p746502318619"></a>ohos.permission.MODIFY_AUDIO_SETTINGS</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p6466223362"><a name="p6466223362"></a><a name="p6466223362"></a>system_grant（静态权限）</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p8466323567"><a name="p8466323567"></a><a name="p8466323567"></a>允许该应用修改全局音频设置，例如音量和用于输出的扬声器。</p>
</td>
</tr>
<tr id="row193133381266"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1631315381568"><a name="p1631315381568"></a><a name="p1631315381568"></a>ohos.permission.READ_MEDIA</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p1731320383610"><a name="p1731320383610"></a><a name="p1731320383610"></a>user_grant（动态权限）</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p931303817611"><a name="p931303817611"></a><a name="p931303817611"></a>允许该应用读取您的视频收藏。</p>
</td>
</tr>
<tr id="row738215284617"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p73824281363"><a name="p73824281363"></a><a name="p73824281363"></a>ohos.permission.MICROPHONE</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p1138217281162"><a name="p1138217281162"></a><a name="p1138217281162"></a>user_grant（动态权限）</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p1338214281661"><a name="p1338214281661"></a><a name="p1338214281661"></a>此应用可随时使用麦克风进行录音。</p>
</td>
</tr>
<tr id="row1777413579619"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1577415710613"><a name="p1577415710613"></a><a name="p1577415710613"></a>ohos.permission.WRITE_MEDIA</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p14774175715612"><a name="p14774175715612"></a><a name="p14774175715612"></a>user_grant（动态权限）</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p677419573612"><a name="p677419573612"></a><a name="p677419573612"></a>允许该应用写入您的音乐收藏。</p>
</td>
</tr>
<tr id="row18922519719"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1892954719"><a name="p1892954719"></a><a name="p1892954719"></a>ohos.permission.DISTRIBUTED_DATASYNC</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p15892105875"><a name="p15892105875"></a><a name="p15892105875"></a>user_grant（动态权限）</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p12892175879"><a name="p12892175879"></a><a name="p12892175879"></a>管控分布式数据传输能力。</p>
</td>
</tr>
<tr id="row109781511376"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p797810117714"><a name="p797810117714"></a><a name="p797810117714"></a>ohos.permission.DISTRIBUTED_VIRTUALDEVICE</p>
</td>
<td class="cellrowborder" valign="top" width="25.83258325832583%" headers="mcps1.2.4.1.2 "><p id="p109787110712"><a name="p109787110712"></a><a name="p109787110712"></a>user_grant（动态权限）</p>
</td>
<td class="cellrowborder" valign="top" width="40.83408340834084%" headers="mcps1.2.4.1.3 "><p id="p19978813720"><a name="p19978813720"></a><a name="p19978813720"></a>允许应用使用分布式虚拟能力</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>静态权限：应用安装时由系统授予的权限，对应于权限敏感级别的system\_grant
>动态权限：应用在运行过程中需要用户授权的权限，对应于权限敏感级别的user\_grant

## 场景介绍<a name="section18502174174019"></a>

应用权限是软件用来访问系统资源和使用系统能力的一种通行方式。在涉及用户隐私相关功能和数据的场景，例如：访问个人设备的硬件特性，如摄像头、麦克风，以及读写媒体文件等，OpenHarmony通过应用权限管理组件来保护这些数据以及能力。

在系统应用开发过程中，如果应用要使用敏感权限，开发者可以调用应用权限管理组件接口检查待访问权限是否被授权，如果未授权，操作不允许。

## 接口说明<a name="section1633115419401"></a>

应用权限管理提供的API接口，当前仅供系统应用和系统服务调用，具体API接口如下。

**表 2**  应用权限管理API接口功能介绍

<a name="table9789027162518"></a>
<table><thead align="left"><tr id="row9789427112518"><th class="cellrowborder" valign="top" width="55.66%" id="mcps1.2.3.1.1"><p id="p9790102717251"><a name="p9790102717251"></a><a name="p9790102717251"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="44.34%" id="mcps1.2.3.1.2"><p id="p779032715251"><a name="p779032715251"></a><a name="p779032715251"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row187901627112516"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p138014275353"><a name="p138014275353"></a><a name="p138014275353"></a>int CheckPermission(int uid, const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p57901727202510"><a name="p57901727202510"></a><a name="p57901727202510"></a>检查指定UID的应用进程是否具有访问系统服务API的权限</p>
</td>
</tr>
<tr id="row19341734164410"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p123453412448"><a name="p123453412448"></a><a name="p123453412448"></a>int CheckSelfPermission(const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p937645212447"><a name="p937645212447"></a><a name="p937645212447"></a>检查调用者是否具有访问系统服务API的权限</p>
</td>
</tr>
<tr id="row879032715258"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p13071135133514"><a name="p13071135133514"></a><a name="p13071135133514"></a>int QueryPermission(const char *identifier, PermissionSaved **permissions, int *permNum)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p1379072718259"><a name="p1379072718259"></a><a name="p1379072718259"></a>查询应用申请的所有权限，并检查权限是否被授予</p>
</td>
</tr>
<tr id="row877239193516"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p878133903516"><a name="p878133903516"></a><a name="p878133903516"></a>int GrantPermission(const char *identifier, const char *permName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p678143943515"><a name="p678143943515"></a><a name="p678143943515"></a>将指定权限授予应用程序</p>
</td>
</tr>
<tr id="row3616164223510"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p1617142163517"><a name="p1617142163517"></a><a name="p1617142163517"></a>int RevokePermission(const char *identifier, const char *permName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p06171242143517"><a name="p06171242143517"></a><a name="p06171242143517"></a>收回应用程序的指定权限</p>
</td>
</tr>
<tr id="row13790122742516"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p23273123365"><a name="p23273123365"></a><a name="p23273123365"></a>int GrantRuntimePermission(int uid, const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p177908273259"><a name="p177908273259"></a><a name="p177908273259"></a>应用运行时动态授予指定权限</p>
</td>
</tr>
<tr id="row18566191217452"><td class="cellrowborder" valign="top" width="55.66%" headers="mcps1.2.3.1.1 "><p id="p169891916194512"><a name="p169891916194512"></a><a name="p169891916194512"></a>int RevokeRuntimePermission(int uid, const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="44.34%" headers="mcps1.2.3.1.2 "><p id="p937132011440"><a name="p937132011440"></a><a name="p937132011440"></a>应用运行时动态撤销指定权限</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section022611498210"></a>

本部分以包管理器的应用权限开发为例进行讲解。开发过程中，首先需要明确涉及的敏感权限，并在config.json中声明该权限，在安装应用程序时，包管理器会调用应用权限管理组件的接口检查该权限是否被授予，若授予，安装流程正常进行，否则安装失败。

1.  在开发过程中，包管理器明确需要安装应用的权限（ohos.permission.INSTALL\_BUNDLE），并在config.json中声明该权限；
    FA模型：需要在config.json中声明权限，示例：
    ```json
    {
      "module": {
          "package": "ohos.demo.kitframework",
          "deviceType": [
              "phone", "tv","tablet", "car","smartWatch","sportsWatch","smartCamera", "smartVision"
          ],
          "reqPermissions": [{
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
        ]
      }
    }
    ```
    Stage模型：需要在module.json5中声明权限，示例：
    ```json
    {
      "module": {
        "requestPermissions": [{
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
        }]
      }
    }
    ```

2.  当包管理器开发应用安装功能接口时，会调用权限管理相关接口检查自身是否具有安装应用程序的权限，例如：以安装应用的权限名"ohos.permission.INSTALL\_BUNDLE"作为入参，调用CheckPermission接口检查包管理器是否具有安装应用的权限，如果有权限，安装流程继续执行，否则返回安装失败；

    ```c++
    constexpr static char PERMISSION_INSTALL_BUNDLE[] = "ohos.permission.INSTALL_BUNDLE";
    
    bool Install(const char *hapPath, const InstallParam *installParam, InstallerCallback installerCallback)
    {
        if ((hapPath == nullptr) || (installerCallback == nullptr) || (installParam == nullptr)) {
            HILOG_ERROR(HILOG_MODULE_APP, "BundleManager install failed due to nullptr parameters");
            return false;
        }
        // 检查ohos.permission.INSTALL_BUNDLE权限是否被授予
        if (CheckPermission(0, static_cast<const char *>(PERMISSION_INSTALL_BUNDLE)) != GRANTED) {
            HILOG_ERROR(HILOG_MODULE_APP, "BundleManager install failed due to permission denied");
            return false;  // 返回安装失败
        }
        // 安装流程
        ...
    }
    ```


