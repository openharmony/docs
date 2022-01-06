# 配置OpenHarmony SDK

- [前提条件](#前提条件)
- [配置SDK信息](#配置SDK信息)
- [参考信息](#参考信息)
 - [配置DevEco Studio代理](#配置DevEco-Studio代理)
 - [配置NPM代理](#配置NPM代理)
 - [设置Gradle代理](#设置Gradle代理)

在设置OpenHarmony应用开发环境时，需要开发者在DevEco Studio中配置对应的SDK信息。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 请注意，OpenHarmony SDK版本精简了部分工具链，因此不适用于HarmonyOS应用开发。


## 前提条件

已下载并安装好DevEco Studio 3.0 Beta1及以上版本，点击[链接下载](https://developer.harmonyos.com/cn/develop/deveco-studio#download)。


## 配置SDK信息

DevEco Studio通过SDK Manager统一管理SDK及工具链，OpenHarmony包含如下SDK包：

| 类别 | 包名 | 说明 | 
| -------- | -------- | -------- |
| SDK | JS | JS语言SDK包。 | 
| eTS | eTS（Extended&nbsp;TypeScript）&nbsp;SDK包。 | 
| SDK&nbsp;Tool | Toolchains | SDK工具链，OpenHarmony应用开发必备工具集，包括编译、打包、签名、数据库管理等工具的集合。 | 
| Previewer | OpenHarmony应用预览器，可以在应用开发过程中查看界面UI布局效果。 | 

1. 运行已安装的DevEco Studio，首次使用，请选择**Do not import settings**，点击OK。

2. 进入配置向导页面，设置**npm registry**，DevEco Studio已预置对应的仓，直接点击**Start using DevEco Studio**进入下一步。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果配置向导界面出现的是设置**Set up HTTP Proxy**界面，说明网络受限，请根据[参考信息](#参考信息)配置DevEco Studio代理、NPM代理和Gradle代理后，再下载OpenHarmony SDK。

   ![zh-cn_image_0000001163314102](figures/zh-cn_image_0000001163314102.png)

3. DevEco Studio向导指引开发者下载SDK，默认下载OpenHarmony SDK。SDK下载到user目录下，也可以指定对应的存储路径，SDK存储路径不支持中文字符，然后点击**Next**。
   ![zh-cn_image_0000001208394019](figures/zh-cn_image_0000001208394019.png)

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果不是首次安装DevEco Studio，可能无法查看进入该界面，可通过欢迎页的**Configure （或**![zh-cn_image_0000001208274069](figures/zh-cn_image_0000001208274069.png)**图标）&gt; Settings &gt; SDK Manager &gt; OpenHarmony SDK**界面，点击**OpenHarmony SDK Location**加载SDK。

4. 在弹出的SDK下载信息页面，点击**Next**，并在弹出的**License Agreement**窗口，点击**Accept**开始下载SDK。

   ![zh-cn_image_0000001163472654](figures/zh-cn_image_0000001163472654.png)

5. 等待OpenHarmony SDK及工具下载完成，点击**Finish**，界面会进入到DevEco Studio欢迎页。
   ![zh-cn_image_0000001163632602](figures/zh-cn_image_0000001163632602.png)


## 参考信息

DevEco Studio开发环境需要依赖于网络环境，需要连接上网络才能确保工具的正常使用。

一般来说，如果使用的是个人或家庭网络，是不需要设置代理信息的；只有部分企业网络受限的情况下，才需要设置代理信息。

如果是第一次打开DevEco Studio，配置向导界面出现设置**Set up HTTP Proxy**界面，说明网络受限，可以通过配置代理的方式来解决，需要配置DevEco Studio代理、NPM代理和Gradle代理。

![zh-cn_image_0000001166582138](figures/zh-cn_image_0000001166582138.png)


### 配置DevEco Studio代理

1. 启动DevEco Studio，配置向导进入**Set up HTTP Proxy**界面，勾选**Manual proxy configuration**，设置DevEco Studio的HTTP Proxy。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果非首次设置向导进入HTTP Proxy，可以通过如下方式进入HTTP Proxy配置界面：
   > 
   > - 在欢迎页点击**Configure（或**![zh-cn_image_0000001212142015](figures/zh-cn_image_0000001212142015.png)**图标） &gt; Settings &gt; Appearance &amp; Behavior &gt; System Settings &gt; HTTP Proxy**进入HTTP Proxy设置界面（Mac系统为**Configure &gt; Preferences &gt; Appearance &amp; Behavior &gt; System Settings &gt; HTTP Proxy**）。
   > 
   > - 在打开了工程的情况下，可以点击**File &gt; Settings &gt; Appearance &amp; Behavior &gt; System Settings &gt; HTTP Proxy**进入HTTP Proxy设置界面（Mac系统为**DevEco Studio &gt; Preferences &gt; Appearance &amp; Behavior &gt; System Settings &gt; HTTP Proxy**）

   - **HTTP**配置项，设置代理服务器信息。**如果不清楚代理服务器信息，可以咨询你们的网络管理人员**。
      - **Host name**：代理服务器主机名或IP地址。
      - **Port number**：代理服务器对应的端口号。
      - **No proxy for**：不需要通过代理服务器访问的URL或者IP地址（地址之间用英文逗号分隔）。
   - **Proxy authentication**配置项，如果代理服务器需要通过认证鉴权才能访问，则需要设置。否则，请跳过该配置项。
      - **Login**：访问代理服务器的用户名。
      - **Password**：访问代理服务器的密码。
      - **Remember**：勾选，记住密码。

   ![zh-cn_image_0000001212062065](figures/zh-cn_image_0000001212062065.png)

2. 配置完成后，点击**Check connection**，输入网络地址（如：https://developer.harmonyos.com），检查网络连通性。提示Connection successful表示代理设置成功。

3. 点击**Next: Configure npm**继续设置NPM代理信息，请参考[配置NPM代理](#配置npm代理)。


### 配置NPM代理

通过DevEco Studio的设置向导设置NPM代理信息，代理信息将写入用户“users/用户名/”目录下的**.npmrc**文件。
> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该向导只有第一次安装DevEco Studio才会出现。如果未出现该向导，可以直接在“users/用户名/”目录下的**.npmrc**文件中，添加代理配置信息。

- npm registry：设置npm仓的地址信息，建议勾选。

- HTTP proxy：代理服务器信息，默认会与DevEco Studio的HTTP proxy设置项保持一致。

- Enable Https Proxy：同步设置HTTPS Proxy配置信息，建议勾选。

![zh-cn_image_0000001164577336](figures/zh-cn_image_0000001164577336.png)

然后点击**Start using DevEco Studio**继续下一步操作。

如果代理服务器需要认证（需要用户名和密码），请先根据如下指导配置代理服务器的用户名和密码信息，然后再下载OpenHarmony SDK；否则，请跳过该操作，参考[配置SDK信息](#配置sdk信息)进行操作即可。

![zh-cn_image_0000001209817299](figures/zh-cn_image_0000001209817299.png)

1. 进入用户的users目录，打开**.npmrc**文件。

2. 修改npm代理信息，在proxy和https-proxy中，增加user和password字段，具体取值请以实际代理信息为准。示例如下所示：
   ```
   proxy=http://user:password@proxy.server.com:80
   https-proxy=http://user:password@proxy.server.com:80
   ```

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 如果password中存在特殊字符，如\@、\#、\*等符号，可能导致配置不生效，建议将特殊字符替换为ASCII码，并在ASCII码前加百分号%。常用符号替换为ASCII码对照表如下：
   > 
   > - !：%21
   > 
   > - \@：%40
   > 
   > - \#：%23
   > 
   > - ￥：%24
   > 
   > - &amp;：%26
   > 
   > - \*：%2A

3. 代理设置完成后，打开命令行工具，执行如下命令进行验证网络是否正常。
   ```
   npm info express
   ```

   执行结果如下图所示，则说明代理设置成功。

   ![zh-cn_image_0000001164417356](figures/zh-cn_image_0000001164417356.png)

4. 网络设置完成后，然后再[配置SDK信息](#配置sdk信息)。


### 设置Gradle代理

1. 打开“此电脑”，在文件夹地址栏中输入**%userprofile%**（Mac系统请点击**前往 &gt; 个人**），进入个人用户文件夹。
   ![zh-cn_image_0000001166740700](figures/zh-cn_image_0000001166740700.png)

2. 创建一个文件夹，命名为**.gradle**。如果已有.gradle文件夹，请跳过此操作。
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > macOS系统创建.gradle文件夹前，请将系统设置为“显示隐藏文件”。

3. 进入.gradle文件夹，新建一个文本文档，命名为**gradle**，并修改后缀为**.properties**。

4. 打开**gradle.properties**文件中，添加如下脚本，然后保存。
   其中代理服务器、端口、用户名、密码和不使用代理的域名，请根据实际代理情况进行修改。其中不使用代理的nonProxyHosts的配置间隔符是 “|”。
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
