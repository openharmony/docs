# Development on Application Signature Verification


## When to Use

To ensure the integrity and trustworthiness of the applications to be installed in OpenHarmony, the applications must be signed and their signatures must be verified.

- Application development: After developing an application and generating a package for installation, you must sign the installation package to prevent it from being tampered with after release. The OpenHarmony application signature verification module provides a signing tool hapsigner, specifications for generating a signing certificate, and a public key certificate for you to sign your application package. To facilitate your app experience, OpenHarmony is preset with the public key certificate and the private key for offline signing and signature verification. For commercial applications, you need to replace the public key certificate and private key.

- Application installation: The Application Framework subsystem of OpenHarmony installs applications. Upon receiving an application installation package, the Application Framework subsystem parses the signature of the installation package, and verifies the signature using the application integrity verification APIs. The application can be installed only after the verification succeeds. During the verification, the application signature verification module uses the preset public key certificate to verify the signature.


## Signature Verification Process

An unsigned HAP is in **.zip** format and consists of a file block, central directory, and end of central directory (EOCD).

After the HAP is signed, a signature block is added between the file block and the central directory. The integrated signature block consists of a profile signature block, HAP signature block, and signature header. The following figure shows the structure of a signed HAP.

  **Figure 1** Structure of a signed HAP
  
![en_image_0000001217526184](figures/structure-of-a-signed-hap.png)

The signature verification process consists of three steps: HAP signature verification, profile signature verification, and profile content verification.

**HAP signature verification**

The HAP signature block is a signed data block in PKCS #7 format. The signature verification process includes PKSC7 signature verification, hash comparison, certificate chain verification, and matching between the certificate chain and the device's preset root certificate.

**Profile signature verification**

The profile signature block is a signed data block in PKCS #7 format. The profile content is stored in **contentinfo** of the PKCS #7 signature block. The signature verification process includes PKCS #7 signature verification, hash comparison, certificate chain verification, and profile certificate validity verification.

**Profile content verification**

The signature verification module checks the validity of the profile content. If the profile is of the debug type, the module checks whether the UDID of the current device is contained in the UDID list in the profile. If yes, the module compares the certificate in the profile with the certificate used for HAP signature verification. If they are the same, the entire verification process is complete.


## Available APIs

The following table lists the **innerkits** APIs provided by the signature verification component. These APIs are available only for system applications.

  **Table 1** Signature verification APIs for the mini system

| API| Description| 
| -------- | -------- |
| int&nbsp;APPVERI_AppVerify(const&nbsp;char&nbsp;\*filePath,&nbsp;VerifyResult&nbsp;\*verifyRst) | Verifies a signature based on the specified file path. This API returns the data obtained from the profile to the caller through **verifyRst**.| 
| int&nbsp;APPVERI_SetDebugMode(bool&nbsp;mode) | Sets the debugging mode. If **mode** is set to **true**, certificate chain verification based on the debugging root key is enabled; if **mode** is set to **false**, it is disabled.<br>Note: Currently, no certificate based on the existing debugging root key is available. You can replace the debugging root key and perform related verification as required.| 
| void&nbsp;APPVERI_FreeVerifyRst(VerifyResult&nbsp;\*verifyRst) | Releases the memory of **verifyRst**.| 

  **Table 2** Signature verification APIs for the standard system

| API| Description| 
| -------- | -------- |
| int&nbsp;HapVerify(const&nbsp;std::string&amp;&nbsp;filePath,&nbsp;HapVerifyResult&amp;&nbsp;hapVerifyResult) | Verifies the application integrity.| 


## How to Develop


### Developing an OpenHarmony Self-signed Application

For details, see [Having Your App Automatically Signed](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465).
