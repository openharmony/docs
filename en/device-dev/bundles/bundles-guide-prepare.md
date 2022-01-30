# Installing hpm-cli Tool<a name="EN-US_TOPIC_0000001051770836"></a>

To develop a bundle, you first need to install the HarmonyOS Package Manager \(hpm\), a cross-platform command line tool developed based on Node.js. To run the hpm, you need to install Node.js, and then install the hpm using the Node Package Manager \(npm\).

## Installing Node.js and hpm<a name="section106591616205311"></a>

1.  Install  **Node.js**.

    Download  **Node.js**  from its official website and install it on your local PC.

    You are advised to install  [Node.js](https://nodejs.org/)  12.x \(including npm 6.14.4\) or a later version \(12.13.0 or later is recommended\).

2.  Install the  **hpm-cli**  tool using  **npm**  delivered with  **Node.js**. Run the following command:

    ```
    npm install -g @ohos/hpm-cli
    ```

3.  Run the following command to check whether the installation is successful. If an hpm version is displayed, the installation is successful.

    ```
    hpm -V or hpm --version
    ```

4.  \(Optional\) Run the following command to upgrade the hpm version if needed:

    ```
    npm update -g @ohos/hpm-cli
    ```


## \(Optional\) Configuring hpm<a name="section71821165412"></a>

After the  **hpm-cli**  tool is installed, run the following command to view the hpm configuration if you need to modify the configuration information, such as proxy and shell:

```
hpm config
```

Default hpm configurations are displayed upon successful command execution. You can modify the default configurations as required. The following lists common hpm configurations:

```
registry = https://hpm.harmonyos.com
### login Settings
# loginUser = invitation_code

#### Path Settings
shellPath = C:\WINDOWS\System32\cmd.exe
# shellPath = C:\Program Files\Git\bin\sh.exe
# globalRepo = C:\Users\username\.hpm\global

#### Network Settings
# no_proxy = *.server.com
# http_proxy = http://user:pwd@proxy_server:port
# https_proxy = http://user:pwd@proxy_server:port
# strictSsl = true

#### Other Settings
# privateSupport = true|false
# ignoreBundles = @ohos/llvm,@ohos/gn,
# OSPlatform = Auto|linux|darwin|win32
```

For details about  **hpm-cli**  commands, see  [HPM Commands](bundles-guide-overview.md).

## Downloading OpenHarmony Code<a name="section102338221707"></a>

For details, see  [Source Code Acquisition](../get-code/sourcecode-acquire.md).

