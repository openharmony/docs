# Development on Application Signature Verification<a name="EN-US_TOPIC_0000001058671627"></a>

## When to Use<a name="section18502174174019"></a>

To ensure the integrity and trustworthiness of the applications to be installed in OpenHarmony, the applications must be signed and their signatures must be verified.

-   In application development: After developing an application, you need to sign its installation package to ensure that the installation package is not tampered with when it is released on devices. To sign the application package, you can use the signature tools and the public key certificates and follow the signing certificate generation specifications provided by the application integrity verification module. For your convenience, a public key certificate and a corresponding private key are preset in OpenHarmony. You need to replace the public key certificate and private key in your commercial version of OpenHarmony.
-   In application installation: The Application Framework subsystem of OpenHarmony installs applications. Upon receiving an application installation package, the Application Framework subsystem parses the signature of the installation package, and verifies the signature using the application integrity verification APIs. The application can be installed only after the verification succeeds. During the verification, the application integrity verification module uses the preset public key certificate to verify the signature.

## Signature Verification Process<a name="section554632717226"></a>

An unsigned HAP is in  **.zip**  format and consists of a file block, central directory, and end of central directory \(EOCD\).

After the HAP is signed, a signature block is added between the file block and the central directory. The integrated signature block consists of a profile signature block, HAP signature block, and signature header. The following figure shows the structure of a signed HAP.

**Figure  1**  Structure of a signed HAP<a name="fig157962397486"></a>  
![](figures/structure-of-a-signed-hap.png "structure-of-a-signed-hap")

The signature verification process consists of three steps: HAP signature verification, profile signature verification, and profile content verification.

**HAP signature verification**

The HAP signature block is a signed data block in PKCS7 format. The signature verification process includes PKSC7 signature verification, hash comparison, certificate chain verification, and matching between the certificate chain and the device's preset root certificate.

**Profile signature verification**

The profile signature block is a signed data block in PKCS7 format. The profile content is stored in  **contentinfo**  of the PKCS7 signature block. The signature verification process includes PKCS7 signature verification, hash comparison, certificate chain verification, and profile certificate validity verification.

**Profile content verification**

The signature verification module checks the validity of the profile content. If the profile is of the debugging type, the module checks whether the UDID of the current device is contained in the UDID list in the profile. If yes, the module compares the certificate in the profile with the certificate used for HAP signature verification. If they are the same, the entire verification process is complete.

## Available APIs<a name="section1633115419401"></a>

The following table lists the innerkits APIs provided by the signature verification component. These APIs are available only for system applications.

**Table  1**  APIs provided by the signature verification component for mini systems

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a>API</p>
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

**Table  2**  API provided by the signature verification component for standard systems

<a name="table10383348161613"></a>
<table><thead align="left"><tr id="row9384114813161"><th class="cellrowborder" valign="top" width="37.66%" id="mcps1.2.3.1.1"><p id="p038411483162"><a name="p038411483162"></a><a name="p038411483162"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="62.339999999999996%" id="mcps1.2.3.1.2"><p id="p9384124871618"><a name="p9384124871618"></a><a name="p9384124871618"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row11384194871614"><td class="cellrowborder" valign="top" width="37.66%" headers="mcps1.2.3.1.1 "><p id="p138411487168"><a name="p138411487168"></a><a name="p138411487168"></a>nt HapVerify(const std::string&amp; filePath, HapVerifyResult&amp; hapVerifyResult)</p>
</td>
<td class="cellrowborder" valign="top" width="62.339999999999996%" headers="mcps1.2.3.1.2 "><p id="p0384184810169"><a name="p0384184810169"></a><a name="p0384184810169"></a>Verifies application integrity and identifies the application source.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section4207112818418"></a>

### OpenHarmony Self-signed Application<a name="section167151429133312"></a>

For details about how to develop an OpenHarmony self-signed application, see [_Having Your App Automatically Signed_](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465). 

