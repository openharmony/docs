# 配置OpenHarmony SDK<a name="ZH-CN_TOPIC_0000001113561194"></a>

-   [前提条件](#section164161442154812)
-   [配置SDK信息](#section1265592425017)
-   [参考信息](#section0384143616409)
    -   [配置DevEco Studio代理](#section10129720184214)
    -   [配置NPM代理](#section19984059114316)
    -   [设置Gradle代理](#section164211820465)


在设置OpenHarmony应用开发环境时，需要开发者在DevEco Studio中配置对应的SDK信息。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>请注意，OpenHarmony SDK版本精简了部分工具链，因此不适用于HarmonyOS应用开发。

## 前提条件<a name="section164161442154812"></a>

已下载并安装好DevEco Studio 3.0 Beta1及以上版本，点击[链接下载](https://developer.harmonyos.com/cn/develop/deveco-studio#download)。

## 配置SDK信息<a name="section1265592425017"></a>

DevEco Studio通过SDK Manager统一管理SDK及工具链，OpenHarmony包含如下SDK包：

<a name="table64565810577"></a>
<table><thead align="left"><tr id="row12455580576"><th class="cellrowborder" valign="top" width="24.709999999999997%" id="mcps1.1.4.1.1"><p id="p34565812572"><a name="p34565812572"></a><a name="p34565812572"></a>类别</p>
</th>
<th class="cellrowborder" valign="top" width="25.3%" id="mcps1.1.4.1.2"><p id="p104675817575"><a name="p104675817575"></a><a name="p104675817575"></a>包名</p>
</th>
<th class="cellrowborder" valign="top" width="49.99%" id="mcps1.1.4.1.3"><p id="p194610586574"><a name="p194610586574"></a><a name="p194610586574"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row44334409916"><td class="cellrowborder" valign="top" width="24.709999999999997%" headers="mcps1.1.4.1.1 "><p id="p88381448125813"><a name="p88381448125813"></a><a name="p88381448125813"></a>SDK</p>
</td>
<td class="cellrowborder" valign="top" width="25.3%" headers="mcps1.1.4.1.2 "><p id="p1946175813574"><a name="p1946175813574"></a><a name="p1946175813574"></a>JS</p>
</td>
<td class="cellrowborder" valign="top" width="49.99%" headers="mcps1.1.4.1.3 "><p id="p54625885713"><a name="p54625885713"></a><a name="p54625885713"></a>JS语言SDK包。</p>
</td>
</tr>
<tr id="row14474585576"><td class="cellrowborder" rowspan="2" valign="top" width="24.709999999999997%" headers="mcps1.1.4.1.1 "><p id="p124765819578"><a name="p124765819578"></a><a name="p124765819578"></a>SDK Tool</p>
</td>
<td class="cellrowborder" valign="top" width="25.3%" headers="mcps1.1.4.1.2 "><p id="p1947135818571"><a name="p1947135818571"></a><a name="p1947135818571"></a>Toolchains</p>
</td>
<td class="cellrowborder" valign="top" width="49.99%" headers="mcps1.1.4.1.3 "><p id="p7471158105711"><a name="p7471158105711"></a><a name="p7471158105711"></a>SDK工具链，OpenHarmony应用开发必备工具集，包括编译、打包、签名、数据库管理等工具的集合。</p>
</td>
</tr>
<tr id="row337931010"><td class="cellrowborder" valign="top" headers="mcps1.1.4.1.1 "><p id="p193791108"><a name="p193791108"></a><a name="p193791108"></a>Previewer</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1238951018"><a name="p1238951018"></a><a name="p1238951018"></a>OpenHarmony应用预览器，可以在应用开发过程中查看界面UI布局效果。</p>
</td>
</tr>
</tbody>
</table>

1.  运行已安装的DevEco Studio，首次使用，请选择**Do not import settings**，点击OK。
2.  进入配置向导页面，设置**npm registry**，DevEco Studio已预置对应的仓，直接点击**Start using DevEco Studio**进入下一步。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >如果配置向导界面出现的是设置**Set up HTTP Proxy**界面，说明网络受限，请根据[参考信息](#section0384143616409)配置DevEco Studio代理、NPM代理和Gradle代理后，再下载OpenHarmony SDK。

    ![](figures/zh-cn_image_0000001163314102.png)

3.  DevEco Studio向导指引开发者下载SDK，默认下载OpenHarmony SDK。SDK下载到user目录下，也可以指定对应的存储路径，SDK存储路径不支持中文字符，然后点击**Next**。

    ![](figures/zh-cn_image_0000001208394019.png)

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >如果不是首次安装DevEco Studio，可能无法查看进入该界面，可通过欢迎页的**Configure （或**![](figures/zh-cn_image_0000001208274069.png)**图标）\> Settings \> SDK Manager \> OpenHarmony SDK**界面，点击**OpenHarmony SDK Location**加载SDK。

4.  在弹出的SDK下载信息页面，点击**Next**，并在弹出的**License Agreement**窗口，点击**Accept**开始下载SDK。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >下载SDK过程中，如果出现下载JS SDK失败，提示“Install js dependencies failed”，请根据[JS SDK安装失败处理指导](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/faq-development-environment-0000001168829643#section1311117111474)进行处理。

    ![](figures/zh-cn_image_0000001163472654.png)

5.  等待OpenHarmony SDK及工具下载完成，点击**Finish**，界面会进入到DevEco Studio欢迎页。

    ![](figures/zh-cn_image_0000001163632602.png)


## 参考信息<a name="section0384143616409"></a>

DevEco Studio开发环境需要依赖于网络环境，需要连接上网络才能确保工具的正常使用。

一般来说，如果使用的是个人或家庭网络，是不需要设置代理信息的；只有部分企业网络受限的情况下，才需要设置代理信息。

如果是第一次打开DevEco Studio，配置向导界面出现设置**Set up HTTP Proxy**界面，说明网络受限，可以通过配置代理的方式来解决，需要配置DevEco Studio代理、NPM代理和Gradle代理。

![](figures/zh-cn_image_0000001123021842.png)

### 配置DevEco Studio代理<a name="section10129720184214"></a>

1.  启动DevEco Studio，配置向导进入**Set up HTTP Proxy**界面，勾选**Manual proxy configuration**，设置DevEco Studio的HTTP Proxy。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >如果非首次设置向导进入HTTP Proxy，可以通过如下方式进入HTTP Proxy配置界面：
    >-   在欢迎页点击**Configure（或**![](figures/zh-cn_image_0000001122862128.png)**图标） \> Settings \> Appearance & Behavior \> System Settings \> HTTP Proxy**进入HTTP Proxy设置界面（Mac系统为**Configure \> Preferences \> Appearance & Behavior \> System Settings \> HTTP Proxy**）。
    >-   在打开了工程的情况下，可以点击**File \> Settings \> Appearance & Behavior \> System Settings \> HTTP Proxy**进入HTTP Proxy设置界面（Mac系统为**DevEco Studio \> Preferences \> Appearance & Behavior \> System Settings \> HTTP Proxy**）

    -   **HTTP**配置项，设置代理服务器信息。**如果不清楚代理服务器信息，可以咨询你们的网络管理人员**。
        -   **Host name**：代理服务器主机名或IP地址。
        -   **Port number**：代理服务器对应的端口号。
        -   **No proxy for**：不需要通过代理服务器访问的URL或者IP地址（地址之间用英文逗号分隔）。

    -   **Proxy authentication**配置项，如果代理服务器需要通过认证鉴权才能访问，则需要设置。否则，请跳过该配置项。
        -   **Login**：访问代理服务器的用户名。
        -   **Password**：访问代理服务器的密码。
        -   **Remember**：勾选，记住密码。

    ![](figures/zh-cn_image_0000001123021962.png)

2.  配置完成后，点击**Check connection**，输入网络地址（如：https://developer.harmonyos.com），检查网络连通性。提示“Connection successful“表示代理设置成功。
3.  点击**Next: Configure npm**继续设置NPM代理信息，请参考[配置NPM代理](#section19984059114316)。

### 配置NPM代理<a name="section19984059114316"></a>

通过DevEco Studio的设置向导设置NPM代理信息，代理信息将写入用户“users/用户名/”目录下的**.npmrc**文件。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>该向导只有第一次安装DevEco Studio才会出现。如果未出现该向导，可以直接在“users/用户名/”目录下的**.npmrc**文件中，添加代理配置信息。

-   npm registry：设置npm仓的地址信息，建议勾选。
-   HTTP proxy：代理服务器信息，默认会与DevEco Studio的HTTP proxy设置项保持一致。
-   Enable Https Proxy：同步设置HTTPS Proxy配置信息，建议勾选。

![](figures/zh-cn_image_0000001164577336.png)

然后点击**Start using DevEco Studio**继续下一步操作。

如果代理服务器需要认证（需要用户名和密码），请先根据如下指导配置代理服务器的用户名和密码信息，然后再下载OpenHarmony SDK；否则，请跳过该操作，参考[配置SDK信息](#section1265592425017)进行操作即可。

![](figures/zh-cn_image_0000001209817299.png)

1.  进入用户的users目录，打开**.npmrc**文件。
2.  修改npm代理信息，在proxy和https-proxy中，增加user和password字段，具体取值请以实际代理信息为准。示例如下所示：

    ```
    proxy=http://user:password@proxy.server.com:80
    https-proxy=http://user:password@proxy.server.com:80
    ```

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >如果password中存在特殊字符，如@、\#、\*等符号，可能导致配置不生效，建议将特殊字符替换为ASCII码，并在ASCII码前加百分号%。常用符号替换为ASCII码对照表如下：
    >-   !：%21
    >-   @：%40
    >-   \#：%23
    >-   ￥：%24
    >-   &：%26
    >-   \*：%2A

3.  代理设置完成后，打开命令行工具，执行如下命令进行验证网络是否正常。

    ```
    npm info express
    ```

    执行结果如下图所示，则说明代理设置成功。

    ![](figures/zh-cn_image_0000001164417356.png)

4.  网络设置完成后，然后再[配置SDK信息](#section1265592425017)。

### 设置Gradle代理<a name="section164211820465"></a>

1.  打开“此电脑”，在文件夹地址栏中输入**%userprofile%**（Mac系统请点击**前往 \> 个人**），进入个人用户文件夹。

    ![](figures/zh-cn_image_0000001123024482.png)

2.  创建一个文件夹，命名为**.gradle**。如果已有.gradle文件夹，请跳过此操作。

    >![](../public_sys-resources/icon-note.gif) **说明：** 
    >macOS系统创建.gradle文件夹前，请将系统设置为“显示隐藏文件”。

3.  进入.gradle文件夹，新建一个文本文档，命名为**gradle**，并修改后缀为**.properties**。
4.  打开**gradle.properties**文件中，添加如下脚本，然后保存。

    其中代理服务器、端口、用户名、密码和不使用代理的域名，请根据实际代理情况进行修改。其中不使用代理的“nonProxyHosts“的配置间隔符是 “|”。

    ```
    systemProp.http.proxyHost=proxy.server.com
    systemProp.http.proxyPort=8080
    systemProp.http.nonProxyHosts=*.company.com|10.*|100.*
    systemProp.http.proxyUser=userId
    systemProp.http.proxyPassword=password
    systemProp.https.proxyHost=proxy.server.com
    systemProp.https.proxyPort=8080
    systemProp.https.nonProxyHosts=*.company.com|10.*|100.*
    systemProp.https.proxyUser=userId
    systemProp.https.proxyPassword=password
    ```


