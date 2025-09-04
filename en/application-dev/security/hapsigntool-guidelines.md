# hapsigner Guide

## Build

**Java**

1. Check that Maven 3 of the correct version has been installed and configured.
  
        mvn -version

2. Download the code, open **developtools_hapsigner/hapsigntool**, and run the following command to build the package:
            
        mvn package

3. You can find the binary file generated in the **./hap_sign_tool/target** directory.

**C++**

1. Build a signing tool for ohos-sdk.

   Release version (default): Run the following command to build the signing tool for the release version.

   Debug version: In the **hapsigntool_cpp/BUILD.gn** file, add **defines = [ "SIGNATURE_LOG_DEBUG" ]**, and then run the build command.

   Build command: **./build.sh --*product-name* ohos-sdk**

2. Decompress **out/sdk/packages/ohos-sdk/ohos/toolchains-ohos-x64-xxx.zip**.

   You can find the **hap-sign-tool** in the **lib** directory.

## How to Development

### When to Use

The OpenHarmony system has a built-in KeyStore (KS) file named **OpenHarmony.p12**. This file contains the root CA certificate, intermediate CA certificate, and entity certificate information. The hapsigner tool signs OpenHarmony apps based on this file.

The usage of hapsigner varies depending on whether an app signing certificate is available. 

1. If no signing certificate is available for your app,
   you can use this tool to generate a key pair for signing, generate an app signing certificate, sign the profile, and sign the app.
2. If a signing certificate is available for your app,
   you can directly sign the profile, and use the app signing certificate and the local KS file (containing the corresponding key) to sign your app.

### Command Description

1. Display command help information.

     ```
     -help     # If no parameter is specified, the command help information is displayed by default.
     ```

2. Display version information

     ```
     -version  # Display the tool version information.
     ```

3. Generate a key pair.

     ```
     generate-keypair: Generate a key pair.
         ├── -keyAlias          # Key alias. It is mandatory.
         ├── -keyPwd            # Key password. It is optional.
         ├── -keyAlg            # Key algorithm, which can be RSA or ECC. It is mandatory.
         ├── -keySize           # Key length. It is mandatory. The key length is 2048, 3072, or 4096 bits for an RSA key and is NIST-P-256 or NIST-P-384 for an ECC key.
         ├── -keystoreFile      # Keystore file, which is mandatory.
         ├── -keystorePwd       # KS password. It is optional.
     ```

4. Generate a CSR.
     ```
     generate-csr: Generate a CSR.
         ├── -keyAlias          # Key alias. It is mandatory.
         ├── -keyPwd            # Key password. It is optional.
         ├── -subject           # Certificate subject. It is mandatory.
         ├── -signAlg           # Signing algorithm, which can be SHA256withRSA, SHA384withRSA, SHA256withECDSA, or SHA384withECDSA. It is mandatory.
         ├── -keystoreFile      # Keystore file, which is mandatory.
         ├── -keystorePwd       # KS password. It is optional.
         ├── -outFile           # CSR to generate. It is optional. If you do not specify this parameter, the CSR is output to the console.
     ```
     
5. Generate a root CA or intermediate CA certificate.

     ```
     generate-ca: Generate a root CA or intermediate CA certificate. If there is no key, generate a key together with the certificate.
         ├── -keyAlias                        # Key alias. It is mandatory.
         ├── -keyPwd                          # Key password. It is optional.
         ├── -keyAlg                          # Key algorithm, which can be RSA or ECC. It is mandatory.
         ├── -keySize                         # Key length. It is mandatory. The key length is 2048, 3072, or 4096 bits for an RSA key and is NIST-P-256 or NIST-P-384 for an ECC key.
         ├── -issuer                          # Issuer of the certificate. It is optional. It indicates a root CA certificate if not specified.
         ├── -issuerKeyAlias                  # Key alias of the issuer. It is optional. It indicates a root CA certificate if not specified.
         ├── -issuerKeyPwd                    # Key password of the issuer. It is optional.
         ├── -subject                         # Certificate subject. It is mandatory.
         ├── -validity                        # Validity period of the certificate. It is optional. The default value is 3650 days.
         ├── -signAlg                         # Signing algorithm, which can be SHA256withRSA, SHA384withRSA,  SHA256withECDSA, or SHA384withECDSA. It is mandatory.
         ├── -basicConstraintsPathLen         # Path length. It is optional. The default value is 0.
         ├── -keystoreFile      # Keystore file, which is mandatory.
         ├── -keystorePwd                     # KS password. It is optional.
         ├── -issuerKeystoreFile              # Issuer keystore file, which is optional.
         ├── -issuerKeystorePwd               # KS password of the issuer. It is optional. 
         ├── -outFile                         # File to generate. It is optional. The file is output to the console if this parameter is not specified.
     ```

6. Generate a debug or release certificate for an app.

     ```
     generate-app-cert: Generate a debug or release certificate for an app.
         ├── -keyAlias                        # Key alias. It is mandatory.
         ├── -keyPwd                          # Key password. It is optional.
         ├── -issuer                          # Issuer of the certificate. It is mandatory.
         ├── -issuerKeyAlias                  # Key alias of the issuer. It is mandatory.
         ├── -issuerKeyPwd                    # Key password of the issuer. It is optional.
         ├── -subject                         # Certificate subject. It is mandatory.
         ├── -validity                        # Validity period of the certificate. It is optional. The default value is 3650 days.
         ├── -signAlg                         # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA.
         ├── -issuerKeystoreFile              # KS file of the issuer, in JKS or P12 format. It is optional.
         ├── -issuerKeystorePwd               # KS password of the issuer. It is optional. 
         ├── -keystoreFile      # Keystore file, which is mandatory.
         ├── -keystorePwd                     # KS password. It is optional.
         ├── -outForm                         # Format of the certificate to generate. It is optional. The value can be cert or certChain. The default value is certChain.
         ├── -rootCaCertFile                  # Root CA certificate, which is mandatory when outForm is certChain.
         ├── -subCaCertFile                   # Intermediate CA certificate file, which is mandatory when outForm is certChain.
         ├── -outFile                         # Certificate file (certificate or certificate chain) to generate. It is optional. The file is output to the console if this parameter is not specified.
     ```

7. Generate a debug or release certificate for a profile.

     ```
     generate-profile-cert: Generate a debug or release certificate for a profile.
         ├── -keyAlias                        # Key alias. It is mandatory.
         ├── -keyPwd                          # Key password. It is optional.
         ├── -issuer                          # Issuer of the certificate. It is mandatory.
         ├── -issuerKeyAlias                  # Key alias of the issuer. It is mandatory.
         ├── -issuerKeyPwd                    # Key password of the issuer. It is optional.
         ├── -subject                         # Certificate subject. It is mandatory.
         ├── -validity                        # Validity period of the certificate. It is optional. The default value is 3650 days.
         ├── -signAlg                         # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA.
         ├── -issuerKeystoreFile              # KS file of the issuer, in JKS or P12 format. It is optional.
         ├── -issuerKeystorePwd               # KS password of the issuer. It is optional. 
         ├── -keystoreFile      # Keystore file, which is mandatory.
         ├── -keystorePwd                     # KS password. It is optional.
         ├── -outForm                         # Format of the certificate to generate. It is optional. The value can be cert or certChain. The default value is certChain.
         ├── -rootCaCertFile                  # Root CA certificate, which is mandatory when outForm is certChain.
         ├── -subCaCertFile                   # Intermediate CA certificate file, which is mandatory when outForm is certChain.
         ├── -outFile                         # Certificate file (certificate or certificate chain) to generate. It is optional. The file is output to the console if this parameter is not specified.
     ```

8. Generate a common certificate, which can be used to generate a custom certificate.

     ```
     generate-cert: Generate a common certificate, which can be used to generate a custom certificate.
         ├── -keyAlias                          # Key alias. It is mandatory.
         ├── -keyPwd                            # Key password. It is optional.
         ├── -issuer                            # Issuer of the certificate. It is mandatory.
         ├── -issuerKeyAlias                    # Key alias of the issuer. It is mandatory.
         ├── -issuerKeyPwd                     # Key password of the issuer. It is optional.
         ├── -subject                          # Certificate subject. It is mandatory.
         ├── -validity                         # Validity period of the certificate. It is optional. The default value is 1095 days.
         ├── -keyUsage                          # Usages of the key. It is mandatory. The value can be one or more of digitalSignature, nonRepudiation, keyEncipherment,
         ├                                        dataEncipherment, keyAgreement, certificateSignature, crlSignature,
         ├                                        encipherOnly, and decipherOnly. Use a comma (,) to separate multiple values.
         ├── -keyUsageCritical                  # Whether keyUsage is a critical option. It is optional. The default value is true.
         ├── -extKeyUsage                       # Extended key usages. It is optional. The extended key usages include clientAuthentication, serverAuthentication,
         ├                                        codeSignature, emailProtection, smartCardLogin, timestamp, and ocspSignature.
         ├── -extKeyUsageCritical               # Whether extKeyUsage is a critical option. It is optional. The default value is false.
         ├── -signAlg                         # Signing algorithm, which can be SHA256withRSA, SHA384withRSA,  SHA256withECDSA, or SHA384withECDSA. It is mandatory.
         ├── -basicConstraints                  # Whether basicConstraints is contained. It is optional. The default value is false.
         ├── -basicConstraintsCritical          # Whether basicConstraints is a critical option. It is optional. The default value is false.
         ├── -basicConstraintsCa                # Whether it is CA. It is optional. The default value is false.
         ├── -basicConstraintsPathLen          # Path length. It is optional. The default value is 0.
         ├── -issuerKeystoreFile              # Issuer keystore file, which is optional.
         ├── -issuerKeystorePwd               # KS password of the issuer. It is optional. 
         ├── -keystoreFile      # Keystore file, which is mandatory.
         ├── -keystorePwd                     # KS password. It is optional.
         ├── -outFile                           # Certificate file to generate. It is optional. The file is output to the console if this parameter is not specified.
     ```

9. Sign a profile.

     ```
     sign-profile: Sign a profile.
         ├── -mode            # Signing mode, which can be localSign or remoteSign. It is mandatory.
         ├── -keyAlias        # Key alias. It is mandatory.
         ├── -keyPwd          # Key password. It is optional.
         ├── -profileCertFile # Profile signing certificate (certificate chain, in the entity certificate, intermediate CA certificate, and root certificate order). It is mandatory.
         ├── -inFile          # Profile to be signed, in JSON format (developtools_hapsigner/autosign/UnsgnedReleasedProfileTemplate.json). It is mandatory.
         ├── -signAlg         # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
         ├── -keystoreFile    # Keystore file, which is mandatory when mode is localSign.
         ├── -keystorePwd     # KS password. It is optional.
         ├── -outFile         # Signed profile to generate, in p7b format. This parameter is mandatory.
     ```

10. Verify the signature of a profile.

     ```
     verify-profile: Verify the profile signature.
         ├── -inFile       # Signed profile in p7b format. This parameter is mandatory.
         ├── -outFile       # Verification result file (including the verification result and profile content), in json format. It is optional. The verification result is output to the console if this parameter is not specified.
     ```

11. Sign an app package or a debug tool.

      ```
     sign-app: Sign an app package or a binary tool.
          ├── -mode          # Signing mode, which can be localSign, remoteSign, or remoteResign. It is mandatory.
          ├── -keyAlias      # Key alias. It is mandatory.
          ├── -keyPwd         # Key password. It is optional.
          ├── -appCertFile       # App signing certificate (certificate chain, in the entity certificate, intermediate CA certificate, and root certificate order). It is mandatory.
          ├── -profileFile   # Name of the signed provisioning profile. When profileSigned is 1, the file is in p7b format. When profileSigned is 0, the file is in JSON format. This parameter is mandatory if an app package is to be signed, and optional if a binary tool is to be signed.
          ├── -profileSigned # Whether to sign the profile. The value 1 means to sign the profile, and value 0 means the opposite. The default value is 1. This parameter is optional.
          ├── -inForm            # Format of the file to be signed. The value is zip for an app package in ZIP format, elf for a binary tool, and bin for an app package in BIN format. The default value is zip. This parameter is optional.
          ├── -inFile            # File to be signed, which can be an app package, an elf file, or a bin file. This parameter is mandatory.
          ├── -signAlg       # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
          ├── -keystoreFile  #  Keystore file, which is mandatory when mode is localSign.
          ├── -keystorePwd   # KS password. It is optional.
          ├── -outFile       # Signed app package to generate. It is mandatory.
          ├── -signCode          # Whether to enable code signing. The value 1 means to enable code signing, and the value 0 means the opposite. This parameter is optional. By default, code signing is enabled for .hap, .hsp, .hqf, and .elf files. To disable code signing, set this parameter to 0.

      ```

12. Verify the signature of an app package or a debug tool.

      ```
      verify-app: Verify the signature of an app package or a binary tool.
         ├── -inFile          # Signed file, which can be an app package, an elf file, or a bin file. This parameter is mandatory.
         ├── -outCertchain    # Signed certificate chain file. It is mandatory.
         ├── -outProfile      # Profile of the app. It is mandatory.
         ├── -inForm            # Format of the file to be verified. The value is zip for an app package in ZIP format, elf for a binary tool, and bin for an app package in BIN format. The default value is zip. This parameter is optional.
      ```

### Signing Procedure
The process of signing an app package is as follows:

- Generate a key pair for an app signing certificate.
- Generate an app signing certificate.
- Sign the profile.
- Sign the app package.


> **NOTE**<br>
>
> 1. For security purposes, use ECC to generate the key pair in step 1. Avoid using RSA.
> 2. You are advised to place the app package to be signed, profile, **OpenHarmony.p12**, root CA certificate, intermediate CA certificate, and hapsigner in the same directory for easy operation. The following files are stored in [**developtools_hapsigner/autosign/result**](https://gitcode.com/openharmony/developtools_hapsigner/tree/master/autosign/result):<br>- OpenHarmony keystore file **OpenHarmony.p12**<br>- Root CA certificate **rootCA.cer**<br>- intermediate CA certificate **subCA.cer**<br>- Profile signing certificate **OpenHarmonyProfileRelease.pem**

1. **Generate a key pair for the app signing certificate.**

   Generate a key pair for signing and save it to the KS.

   Example (Java):

   ```shell
   java -jar hap-sign-tool.jar generate-keypair -keyAlias "oh-app1-key-v1" -keyAlg "ECC"  -keySize "NIST-P-256" -keystoreFile "OpenHarmony.p12" -keyPwd "123456" -keystorePwd "123456"
   ```

   Example (C++):

   ```shell
   hap-sign-tool generate-keypair -keyAlias "oh-app1-key-v1" -keyAlg "ECC"  -keySize "NIST-P-256" -keystoreFile "OpenHarmony.p12" -keyPwd "123456" -keystorePwd "123456"
   ```

   > **NOTE**
   >
   > Record the **keyAlias**, **keyStorePwd**, and **keyPwd** values, which will be used when the app signing certificate is generated and the app package is signed.

   The command parameters are described as follows:

   ```
   generate-keypair: Generate a key pair for the app signing certificate.
       ├── -keyAlias         # Alias of the key used to generate the app signing certificate. It is stored in the OpenHarmony.p12 file. This parameter is mandatory.
       ├── -keyAlg           # Key algorithm. It is mandatory. ECC is recommended.
       ├── -keySize          # Key length. It is NIST-P-256 or NIST-P-384 for an ECC key. This parameter is mandatory.
       ├── -keyStoreFile     # Keystore file, which is mandatory. You are advised to use OpenHarmony.p12. The Java version supports two formats: PKCS#12 and JKS. The C++ version supports PKCS#12 only.
       ├── -keyStorePwd      # KS password. It is mandatory. The default password is 123456 for OpenHarmony.p12.
       ├── -keyPwd           # Key password. It is optional. If this parameter is not specified, the generated key pair has no password.
   ```

2. **Generate an app signing certificate.**

   Use the local intermediate CA certificate to issue an app signing certificate.

   Example (Java):

   ```shell
   java -jar hap-sign-tool.jar generate-app-cert -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA"  -issuer "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN= OpenHarmony Application CA" -issuerKeyAlias "openharmony application ca" -subject "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN=OpenHarmony Application Release" -keystoreFile "OpenHarmony.p12" -subCaCertFile "subCA.cer" -rootCaCertFile "rootCA.cer" -outForm "certChain" -outFile "app1.pem" -keyPwd "123456" -keystorePwd "123456" -issuerKeyPwd "123456" -validity "365"
   ```

   Example (C++):

   ```shell
   hap-sign-tool generate-app-cert -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA"  -issuer "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN= OpenHarmony Application CA" -issuerKeyAlias "openharmony application ca" -subject "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN=OpenHarmony Application Release" -keystoreFile "OpenHarmony.p12" -subCaCertFile "subCA.cer" -rootCaCertFile "rootCA.cer" -outForm "certChain" -outFile "app1.pem" -keyPwd "123456" -keystorePwd "123456" -issuerKeyPwd "123456" -validity "365"
   ```

   The command parameters are described as follows:

   ```
   generate-app-cert: Generate an app signing certificate.
       ├── -keyAlias         # Key alias, which must be the same as that in the previous step.
       ├── -signAlg         # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
       ├── -issuer           #  Issuer of the certificate. Enter the issuer of the intermediate CA certificate. It is mandatory and cannot be changed.
       ├── -issuerKeyAlias   #Alias of the issuer key. Enter the alias of the intermediate CA certificate key. This parameter is mandatory and cannot be changed.
       ├── -subject          # Subject of the certificate. Enter the subject in the same sequence specified in the command. This parameter is mandatory.
       ├── -issuerKeyPwd     # Key password of the issuer. Enter the key password of the intermediate CA certificate. It is mandatory and cannot be changed. In this example, it is 123456. 
       ├── -keystoreFile     # Keystore file, which is mandatory and cannot be changed. You are advised to use OpenHarmony.p12. The Java version supports two formats: PKCS#12 and JKS. The C++ version supports PKCS#12 only.
       ├── -rootCaCertFile   # Root CA certificate. It is mandatory and cannot be changed.
       ├── -subCaCertFile    # Intermediate CA certificate provided. This parameter is mandatory and cannot be modified.
       ├── -outForm          # Format of the certificate file to generate. certChain is recommended.
       ├── -outFile          # File to generate. It is optional. The file is output to the console if this parameter is not specified.
       ├── -keyPwd           # Key password. It is optional. It is the key password set when the key pair is generated. 
       ├── -keystorePwd      # KS password. The default value is 123456.
       ├── -validity         # Validity period of the certificate. It is optional. The default value is 3650 days.
   ```

3. **Sign the profile.**

   Call the profile signing API to sign the profile using the profile signing key.

   Example (Java):

   ```shell
   java -jar hap-sign-tool.jar  sign-profile -keyAlias "openharmony application profile release" -signAlg "SHA256withECDSA" -mode "localSign" -profileCertFile "OpenHarmonyProfileRelease.pem" -inFile "UnsgnedReleasedProfileTemplate.json" -keystoreFile "OpenHarmony.p12" -outFile "app1-profile.p7b" -keyPwd "123456" -keystorePwd "123456"
   ```

   Example (C++):

   ```shell
   hap-sign-tool sign-profile -keyAlias "openharmony application profile release" -signAlg "SHA256withECDSA" -mode "localSign" -profileCertFile "OpenHarmonyProfileRelease.pem" -inFile "UnsgnedReleasedProfileTemplate.json" -keystoreFile "OpenHarmony.p12" -outFile "app1-profile.p7b" -keyPwd "123456" -keystorePwd "123456"
   ```

   The command parameters are described as follows:

   ```
   sign-profile: Sign a profile.
       ├── -keyAlias         # Alias of the key for generating the profile certificate. It is mandatory and cannot be changed.
       ├── -signAlg          # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
       ├── -mode             # Signing mode, which must be localSign. It is mandatory.
       ├── -profileCertFile  # Profile signing certificate. Use the certificate provided. It is mandatory and cannot be changed.
       ├── -inFile           # Profile to be signed, in JSON format (developtools_hapsigner/autosign/UnsgnedReleasedProfileTemplate.json). It is mandatory.
       ├── -keystoreFile     # Keystore file, which is mandatory and cannot be changed. You are advised to use OpenHarmony.p12. The Java version supports two formats: PKCS#12 and JKS. The C++ version supports PKCS#12 only.
       ├── -outFile        # Signed profile to generate, in p7b format. This parameter is mandatory.
       ├── -keyPwd           # Key password. The default key password in OpenHarmony.p12 is 123456.
       ├── -keystorePwd      # KS password. The default key password in OpenHarmony.p12 is 123456.
   ```

4. **Sign the app package.**

   Sign the app package with the app signing key.

   Example (Java):

   ```shell
   java -jar hap-sign-tool.jar sign-app -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA" -mode "localSign" -appCertFile "app1.pem" -profileFile "app1-profile.p7b" -inFile "app1-unsigned.zip" -keystoreFile "OpenHarmony.p12" -outFile "app1-signed.hap" -keyPwd "123456" -keystorePwd "123456"
   ```

   Example (C++):
   
   ```shell
   hap-sign-tool sign-app -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA" -mode "localSign" -appCertFile "app1.pem" -profileFile "app1-profile.p7b" -inFile "app1-unsigned.zip" -keystoreFile "OpenHarmony.p12" -outFile "app1-signed.hap" -keyPwd "123456" -keystorePwd "123456"
   ```

   > **NOTE**
   >
   > The following parameters are used when there is no app signing certificate available. If the app signing certificate is available, the following parameters must be modified:
   > -**keyAlias**: Enter the key alias of the app signing certificate. This parameter is mandatory. <br/>
   > -**appCertFile**: Enter the app signing certificate. This parameter is mandatory.<br/>
   > -**keystoreFile**: Enter the KS file of the app signing certificate. This parameter is mandatory. <br/>
   > -**keyPwd**: Enter the key password in the KS file. <br/>
   > -**keystorePwd**: Enter the KS password in the KS file.

   The command parameters are described as follows:

   ```
   sign-app: Sign an app package.
       ├──-keyAlias          # Key alias, which must be the same as the alias of the key pair generated. This parameter is mandatory.
       ├── -signAlg          # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
       ├── -mode             # Signing mode, which must be localSign. It is mandatory.
       ├── -appCertFile      # App signing certificate (certificate chain, in the entity certificate, intermediate CA certificate, and root certificate order). Enter the app signing certificate generated in step 2. This parameter is mandatory.
       ├── -profileFile      # Signed profile in p7b format. Enter the profile generated. This parameter is mandatory.
       ├──  -inFile           # App package to be signed. This parameter is mandatory.
       ├──  -keystoreFile     # Keystore file, which is mandatory and cannot be changed. The value must be the same as that in step 1. The Java version supports two formats: PKCS#12 and JKS. The C++ version supports PKCS#12 only.
       ├── -outFile          # Signed file to generate. It is mandatory.
       ├── -keyPwd           # Key password, which must be the actual key password.
       ├── -keystorePwd      # KS password, which must be the actual KS password. 
   ```

## FAQs (Java)

1. The console displays the app signing certificate generated but no file is output.

   - **Symptom**

     When the tool is used to generate an app signing certificate, the certificate content is displayed on the console but no certificate is generated.  

   - **Possible Causes**
   
     The path specified by **outFile** is incorrect, or the hyphen (-) in **-outFile** is not an English character.
   
   - **Solution**
   
     Check and correct the value of **outFile**, and ensure the hyphen (-) in **-outFile** is an English character.

2. Failed to sign a profile.

   - **Symptom**

     When the tool is used to sign a profile, any of the following information is displayed:

     (1)  SIGN_ERROR, code: 107. Details: Failed to verify signature: Wrong key usage

     (2) NOT_SUPPORT_ERROR, code: 105. Details: Profile cert 'result\profile1.pem' must a cert chain

     (3) VERIFY_ERROR, code: 108. Details: Failed to verify signature: unable to find valid certification path to requested target

   - **Possible Causes**

     (1) The certificate chain of the profile signing certificate is in incorrect order.

     (2) The profile signing certificate is not a certificate chain.

     (3) The certificate subject is in incorrect sequence, or the **-issuerKeyAlias** parameter set to generate the app signing certificate is incorrect.

   - **Solution**

     (1) Check that the certificates in the certificate chain are in ascending or descending order of seniority.

     (2) Check that the certificate is a certificate chain.

     (3) Check that the certificate subject is in the C, O, OU, and CN order.

3. An error message is displayed when the tool is used to sign an application package.

   - **Symptom**

     The following information is displayed after the command is executed:<br>NOT_SUPPORT_ERROR, code: 105. Details: SignAlg params is incorrect, signature algorithms include SHA256withECDSA,SHA384withECDSA

   - **Possible Causes**

     The signing algorithm is not supported. Check the value of **signAlg**.

   - **Solution**

     Use ECC to generate the key pair for an app or profile signing certificate. Use SHA256withECDSA or SHA384withECDSA as the app signing algorithm.

4. Failed to sign an app package because CN of the certificate is empty.

   - **Symptom**

     The message "error: Common name of certificate is empty!" is displayed.

   - **Possible Causes**

     The app signing certificate used does not contain the CN field.

   - **Solution**

     The CN field of the app signing certificate cannot be empty. Generate a certificate in correct format.
     

## FAQs (C++)

> **NOTE**
> The numbers in **Symptom**, **Possible Causes**, and **Solution** are in one-to-one correspondence.

1. Command parameter errors

   + **Symptom**

     (1) Error message: ERROR - COMMAND_PARAM_ERROR, code: -107.Details: 'generate-cert' Parameters error, Param key - value must in pairs

     (2) Error message: ERROR - KEY_PASSWORD_ERROR, code: -114.Details: 'oh-app1-key-v1' keypair password error

     (3) Error message: ERROR - NOT_SUPPORT_ERROR, code: -104.Details: Not support file: ./OpenHarmony.p1

     (4) Error message: ERROR - KEY_ALIAS_ERROR, code: -109.Details: 'XXX' key alias already exists and cannot be generated repeatedly

   + **Possible Causes**

     (1) Extra command parameter is pasted, or the last parameter of the command is not specified.

     (2) The password of the key pair entered is incorrect.

     (3) The keystore file type specified is incorrect.

     (4) The key pair with the same alias already exists in the keystore.

   + **Solution**

     (1) Check for redundant or incorrect parameters and correct them.

     (2) Enter the correct password.

     (3) Check that the keystore file name extension is .p12 or .jks.

     (4) Rename the alias of the key pair.

2. Errors reported after the command for generating an app signing certificate is executed

   - **Symptom**

     (1) Error message: ERROR - KEY_ALIAS_ERROR, code: -109.Details: keyAlias: 'oh-app1-key-v2' is not exist in/mnt/d/file/Test_0528/OpenHarmony.p12

     (2) Error message: ERROR - KEYSTORE_PASSWORD_ERROR, code: -115.Details: keyStore password error

     (3) Error message: ERROR - KEY_PASSWORD_ERROR, code: -114.Details: 'oh-app-sign-srv-ca-key-v1' keypair password error

   - **Possible Causes**

     (1) The specified key alias cannot be found in the keystore.

     (2) The keystore password is incorrect.

     (3) The password of the key pair is specified when the intermediate CA certificate of the app is generated, but the **-issuerKeyPwd** parameter is not entered when the debug certificate of the app is generated.

   - **Solution**

     (1) Check that the key alias is the same as that entered when the key pair is generated.

     (2) Check that the keystore password is the same as that entered when the key pair is generated.

     (3) Check that **-issuerKeyPwd** is specified when the profile is generated, and that the value is the same as the password of the key pair when the intermediate CA certificate of the profile is generated.

3. Errors reported when the profile is executed for signing

   - **Symptom**

     (1) Error message: ERROR - PROVISION_INVALID, code: 0.Details: Tag app-distribution-type is empty

     (2) Error message: VERIFY_ERROR, code: -106.Details: Failed to verify signature: unable to find valid certification path to requested target

   - **Possible Causes**

     (1) The certificate subject is in incorrect sequence, or the **-issuerKeyAlias** parameter set to generate the app signing certificate is incorrect.

     (2) The value of **type** in **profile.json** does not match the value of **key** in **bundle_info**. The typ **debug** corresponds to **development-certificate**, and **release** to **distribution-certificate**.

   - **Solution**

     (1) Check that the certificate subject is in the C, O, OU, and CN order.

     (2) Check that the configuration in the **bundle.json** file is correct.

4. An error message is displayed when the tool is used to sign an application package.

   - **Symptom**

     (1) Error message: ERROR - PROVISION_INVALID, code: 0.Details: Require build type must be debug or release

     (2) Error message: ERROR - ZIP_ERROR, code: -111. Details: zip init failed
     
     (3) Error message: ERROR - SIGN_ERROR, code: -105.Details: No certificates configured for sign

   - **Possible Causes**

     (1) The profile is not signed (no .p7b file is generated). Before the HAP is signed, the profile does not contain the **type** parameter.

     (2) The size of the .zip package exceeds 4 GB. The change in the format of the compressed file causes a decompression failure.

     (3) The key used for signing does not match the entity certificate.

   - **Solution**

     (1) Before using an unsigned profile file to sign the HAP, add **type** with the value of **debug** or **release** in the **profile.json** file.

     (2) If the HAP to be signed exceeds 4 GB, split it into smaller ones.

     (3) Check **keyAlias** and **appCertFile** and ensure the key used for signing matches the certificate.

5. HAP installation failure

   - **Symptom**

     (1) When a .json file of the release or debug type is used to sign and install a HAP, the following information is displayed: device type is not supports

     (2) When a .json file of the debug type is used to install a HAP, the following information is displayed: verify pkcs7 info failed

     (3) When a HAP is installed on an OpenHarmony system of an earlier version, the following information is displayed: install sign info inconsistent

     (4) When a signed HAP is installed, the following information is displayed: "signature verification failed due to not trusted app source."

   - **Possible Causes**

     (1) The OpenHarmony system configuration file does not support the device type of the HAP.

     (2) The **device-ids** field in the .json file of the debug type does not contain your device **udid**.

     (3) The HAP with the same name has been installed.

     (4) The certificate in the .json file of the debug or release type is not a trusted certificate.

   - **Solution**

     (1) Run the **hdc shell param get const.product.devicetype** command to check the device types supported by the system and replace the HAP based on the device type.

     (2) Run the **hdc shell bm get --udid** command to obtain the UDID of the device and add it to **device-ids** in the .json file of the debug type.

     (3) Run the **bm uninstall -n *Bundle_name*** command to uninstall the HAP with the same name.

     (4) Check whether an incorrect .json file is used.
