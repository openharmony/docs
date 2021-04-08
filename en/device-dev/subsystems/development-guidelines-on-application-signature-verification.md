# Development Guidelines on Application Signature Verification<a name="EN-US_TOPIC_0000001058671627"></a>

-   [When to Use](#section18502174174019)
-   [Signature Verification Process](#section554632717226)
-   [Available APIs](#section1633115419401)
-   [Development Procedure \(Scenario 1\)](#section4207112818418)
    -   [Signature Verification](#section11470123816297)
    -   [Self-signed Application Generation](#section167151429133312)
    -   [Development Examples](#section174318361353)

-   [Development Procedure \(Scenario 2\)](#section81272563427)
    -   [Signature Verification](#section07028210442)
    -   [Development Examples](#section1930711345445)

-   [Debugging and Verification](#section427316292411)

## When to Use<a name="section18502174174019"></a>

You can call the APIs provided by the signature verification component to check integrity of a debugging, released, or OpenHarmony self-signed application. You can also call APIs of the signature verification component to obtain some information in the profile, for example,  **appid**. In addition, you can call APIs to check whether the UDID of a debugging application matches that of the device to ensure that the application is installed on the right device.

## Signature Verification Process<a name="section554632717226"></a>

An unsigned HAP is in  **.zip**  format and consists of a file block, central directory, and end of central directory \(EOCD\).

After the HAP is signed, a signature block is added between the file block and the central directory. The signature block consists of a file signature block, profile signature block, and signature header. The following figure shows the structure of a signed HAP.

**Figure  1**  Structure of a signed HAP<a name="fig699855043"></a>  


![](figures/安全子系统.png)

The signature verification process consists of three steps: HAP signature verification, signature verification for the profile signature block, and profile content verification.

**HAP signature verification**

Use the preset root certificate of the device and the certificate chain to prove that the leaf certificate is trusted. Then use the digest obtained by decrypting the public key of the leaf certificate to prove that the HAP is not tampered with.

The process is as follows:

1.  Use the preset root certificate of the device to verify the certificate chain in the file signature block and prove that the leaf certificate is trusted.
2.  Use the public key in the leaf certificate to verify the file signature block and prove that this block is not tampered with.
3.  Calculate and merge the digests of the file block, central directory, and EOCD. Merge the calculation result with the digest of the profile signature block in the signature block. Then compare the merge result with the digest of the file signature block. If they are the same, the HAP signature verification is successful.

**Signature verification for the profile signature block**

First of all, check who issued the signature of the profile signature block. If the signature was issued by the application market, the signature is trusted and does not need to be verified. Otherwise, the signature needs to be verified. Next, verify the certificate chain and then use the leaf certificate to verify the signature of the profile signature block to prove that it is not tampered with.

**Profile content verification**

Obtain the profile and check the validity of its content. If the HAP is a debugging application, check whether the UDID of the current device is contained in the UDID list in the profile. If yes, the verification is successful. Then compare the certificate in the profile with the leaf certificate used for HAP verification \(this is not required for a released or OpenHarmony self-signed application\). If they are the same, the entire signature verification process is complete.

## Available APIs<a name="section1633115419401"></a>

The following table lists the innerkits APIs provided by the signature verification component. These APIs are available only for system applications.

**Table  1**  APIs provided by the signature verification component

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row34145016535"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p122711391160"><a name="p122711391160"></a><a name="p122711391160"></a>int APPVERI_AppVerify(const char *filePath, VerifyResult *verifyRst)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p13562171015712"><a name="p13562171015712"></a><a name="p13562171015712"></a>Verifies a signature by specifying the file path and returns the data obtained from the profile to the caller through <strong id="b7884251078"><a name="b7884251078"></a><a name="b7884251078"></a>verifyRst</strong>. This is the main entry function.</p>
</td>
</tr>
<tr id="row1746172917474"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p2131144717619"><a name="p2131144717619"></a><a name="p2131144717619"></a>int APPVERI_SetDebugMode(bool mode)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1577114614282"><a name="p1577114614282"></a><a name="p1577114614282"></a>Sets the debugging mode. If <strong id="b357165110811"><a name="b357165110811"></a><a name="b357165110811"></a>mode</strong> is set to <strong id="b425811565813"><a name="b425811565813"></a><a name="b425811565813"></a>true</strong>, certificate chain verification based on the debugging root key is enabled; if <strong id="b1846271515134"><a name="b1846271515134"></a><a name="b1846271515134"></a>mode</strong> is set to <strong id="b1646271551319"><a name="b1646271551319"></a><a name="b1646271551319"></a>false</strong>, it is disabled.</p>
<p id="p2431455765"><a name="p2431455765"></a><a name="p2431455765"></a>Note: Currently, no certificate based on the existing debugging root key is available. You can replace the debugging root key and perform related verification as required.</p>
</td>
</tr>
<tr id="row10992232154714"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p685215538611"><a name="p685215538611"></a><a name="p685215538611"></a>void APPVERI_FreeVerifyRst(VerifyResult *verifyRst)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p126575774517"><a name="p126575774517"></a><a name="p126575774517"></a>Releases memory in <strong id="b12392192921512"><a name="b12392192921512"></a><a name="b12392192921512"></a>verifyRst</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Development Procedure \(Scenario 1\)<a name="section4207112818418"></a>

### Signature Verification<a name="section11470123816297"></a>

Verification of applications released in the application market, debugging applications signed with debugging certificates of the application market, and OpenHarmony self-signed applications

1.  Construct the VerifyResult structure.

    ```
    VerifyResult verifyResult = {0};
    ```

2.  Call the APPVERI\_AppVerify function by specifying the file path and VerifyResult to verify the application signature.

    ```
    int32_t ret = APPVERI_AppVerify(hapFilepath.c_str(), &verifyResult);
    ```

3.  Check the returned result. If the verification is successful, obtain and process the data in VerifyResult.

    ```
    signatureInfo.appId = verifyResult.profile.appid;
    signatureInfo.provisionBundleName = verifyResult.profile.bundleInfo.bundleName;
    ```

4.  Call the APPVERI\_FreeVerifyRst function to release memory in VerifyResult.

    ```
    APPVERI_FreeVerifyRst(&verifyResult);
    ```


### OpenHarmony Self-signed Application Generation<a name="section167151429133312"></a>

The OpenHarmony self-signed application generation procedure is as follows:

1.  Prepare required materials.

    Prepare the signature tool, system application HAP, system application profile \(\*.p7b\), signing certificate \(\*.cer\), and signing public/private key pair \(\*.jks\).

2.  Place all the materials in the same directory and start the shell.
3.  Run the following command in the shell to sign the application:

    ```
    java -jar hapsigntoolv2.jar sign -mode localjks -privatekey "OpenHarmony Software Signature" -inputFile camera.hap -outputFile signed_camera.hap -signAlg SHA256withECDSA -keystore OpenHarmony.jks -keystorepasswd 123456 -keyaliaspasswd 123456 -profile camera_release.p7b -certpath OpenHarmony.cer -profileSigned 1
    ```

    Key fields:

    **-jar**: signature tool, which is  **[hapsigntool](https://repo.huaweicloud.com/harmonyos/develop_tools/hapsigntoolv2.jar)**

    **-mode**: local signature flag, which is fixed at  **localjks**

    **-privatekey**: alias of the public/private key pair, which is  **OpenHarmony Software Signature**

    **-inputFile**: application to be signed, which is generated through compilation

    **-outputFile**: signed application

    **-signAlg**: signing algorithm, which is fixed at  **SHA256withECDSA**

    **-keystore**: public/private key pair, which is  [OpenHarmony.jks](https://gitee.com/openharmony/security_appverify/blob/master/interfaces/innerkits/appverify_lite/OpenHarmonyCer/OpenHarmony.jks)  in the  **OpenHarmonyCer**  directory of the  **security\_services\_app\_verify**  repository. The default password is  **123456**. You can use a tool \(such as keytool\) to change the password.

    **-keystorepasswd**: password of the public/private key pair, which is  **123456**  by default

    **-keyaliaspasswd**: password of the public/private key pair alias, which is  **123456**  by default

    **-profile**: application profile, which is stored in the code directory

    **-certpath**: signing certificate, which is  [OpenHarmony.cer](https://gitee.com/openharmony/security_appverify/blob/master/interfaces/innerkits/appverify_lite/OpenHarmonyCer/OpenHarmony.cer)  in the  **OpenHarmonyCer**  directory of the  **security\_services\_app\_verify**  repository.

    **-profileSigned**: whether the signature block contains the profile. The value is fixed at  **1**, indicating that the signature block contains the profile.


### Development Examples<a name="section174318361353"></a>

The following example describes how the application management framework component verifies the signature of an application during its installation.

```
uint8_t HapSignVerify::VerifySignature(const std::string &hapFilepath, SignatureInfo &signatureInfo)
{
	bool mode = ManagerService::GetInstance().IsDebugMode();
	HILOG_INFO(HILOG_MODULE_APP, "current mode is %d!", mode);
        // Construct the VerifyResult structure.
	VerifyResult verifyResult = {0};
        // Verify the signature by specifying the file path.
	int32_t ret = APPVERI_AppVerify(hapFilepath.c_str(), &verifyResult); 
	uint8_t errorCode = SwitchErrorCode(ret);
	if (errorCode != ERR_OK) {
		return errorCode;
	}
        // Obtain appid from the VerifyResult structure.
	signatureInfo.appId = verifyResult.profile.appid; 
        // Obtain the application name written in the profile from the VerifyResult structure.
	signatureInfo.provisionBundleName = verifyResult.profile.bundleInfo.bundleName; 
	int32_t restricNum = verifyResult.profile.permission.restricNum;
	for (int32_t i = 0; i < restricNum; i++) {
		signatureInfo.restrictedPermissions.emplace_back((verifyResult.profile.permission.restricPermission)[i]);
	}
        // Release memory in VerifyResult.
	APPVERI_FreeVerifyRst(&verifyResult); 
	return ERR_OK;
}
```

## Development Procedure \(Scenario 2\)<a name="section81272563427"></a>

### Signature Verification<a name="section07028210442"></a>

The procedure is as follows:

1.  Call the APPVERI\_SetDebugMode\(true\) function to enable the debugging mode.

    ```
    	ManagerService::SetDebugMode(true);
    ...
    uint8_t ManagerService::SetDebugMode(bool enable)
    {
    	int32_t ret = APPVERI_SetDebugMode(enable);
    	if (ret < 0) {
    		HILOG_ERROR(HILOG_MODULE_APP, "set signature debug mode failed");
    		return ERR_APPEXECFWK_SET_DEBUG_MODE_ERROR;
    	}
    	isDebugMode_ = enable;
    	HILOG_INFO(HILOG_MODULE_APP, "current sign debug mode is %d", isDebugMode_);
    	return ERR_OK;
    }
    ```

2.  Construct the  **VerifyResult**  structure, verify the application signature, and release memory in  **VerifyResult**.
3.  Call the APPVERI\_SetDebugMode\(false\) function to disable the debugging mode.

    ```
            ManagerService::SetDebugMode(false);
    ```


### Development Examples<a name="section1930711345445"></a>

The following is the example code \(supplemented based on the example code for scenario 1\):

```
uint8_t ManagerService::SetDebugMode(bool enable)
{
	int32_t ret = APPVERI_SetDebugMode(enable);
	if (ret < 0) {
		HILOG_ERROR(HILOG_MODULE_APP, "set signature debug mode failed");
		return ERR_APPEXECFWK_SET_DEBUG_MODE_ERROR;
	}
	isDebugMode_ = enable;
	HILOG_INFO(HILOG_MODULE_APP, "current sign debug mode is %d", isDebugMode_);
	return ERR_OK;
}
uint8_t HapSignVerify::VerifySignature(const std::string &hapFilepath, SignatureInfo &signatureInfo)
{
        // Enable debugging mode.
        ManagerService::SetDebugMode(true); 
	bool mode = ManagerService::GetInstance().IsDebugMode();
	HILOG_INFO(HILOG_MODULE_APP, "current mode is %d!", mode);
        // Construct the VerifyResult structure.
	VerifyResult verifyResult = {0}; 
        // Verify the signature by specifying the file path.
	int32_t ret = APPVERI_AppVerify(hapFilepath.c_str(), &verifyResult); 
	uint8_t errorCode = SwitchErrorCode(ret);
	if (errorCode != ERR_OK) {
		return errorCode;
	}
        // Obtain appid from the VerifyResult structure.
	signatureInfo.appId = verifyResult.profile.appid; 
        // Obtain the application name written in the profile from the VerifyResult structure.
	signatureInfo.provisionBundleName = verifyResult.profile.bundleInfo.bundleName; 
	int32_t restricNum = verifyResult.profile.permission.restricNum;
	for (int32_t i = 0; i < restricNum; i++) {
		signatureInfo.restrictedPermissions.emplace_back((verifyResult.profile.permission.restricPermission)[i]);
	}
        // Release memory in VerifyResult.
        APPVERI_FreeVerifyRst(&verifyResult); 
        // Disable debugging mode.
        ManagerService::SetDebugMode(false); 
	return ERR_OK;
}
```

## Debugging and Verification<a name="section427316292411"></a>

1.  Choose an application that can be properly installed on OpenHarmony.
2.  Develop the application based on the development guidelines.
3.  Use a self-developed program to verify the signature of the developed application. If the verification is successful and  **appid**  can be obtained, the development is successful.

