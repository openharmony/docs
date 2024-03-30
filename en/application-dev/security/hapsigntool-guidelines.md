# hapsigner Guide

## Build


1. Check that Maven 3 of the correct version has been installed and configured.
  
        mvn -version

2. Download the code, open **developtools_hapsigner/hapsigntool**, and run the following command to build the package:         
   
        mvn package

3. You can find the binary file generated in the **./hap_sign_tool/target** directory.

## How to Development

### When to Use

The OpenHarmony system has a built-in KeyStore (KS) file named **OpenHarmony.p12**. This file contains the root CA certificate, intermediate CA certificate, and entity certificate information. The hapsigner tool signs OpenHarmony apps based on this file.

The usage of hapsigner varies depending on whether an app signing certificate is available. 

- If no signing certificate is available for your app, you can use this tool to generate a key pair for signing, generate an app signing certificate, sign the profile, and sign the app.
- If a signing certificate is available for your app, you can directly sign the profile, and use the app signing certificate and the local KS file (containing the corresponding key) to sign your app.

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
         ├── -keystoreFile      # KS file, in JKS or P12 format. It is mandatory.
         ├── -keystorePwd       # KS password. It is optional.
     ```

4. Generate a CSR.
     ```
     generate-csr: Generate a CSR.
         ├── -keyAlias          # Key alias. It is mandatory.
         ├── -keyPwd            # Key password. It is optional.
         ├── -subject           # Certificate subject. It is mandatory.
         ├── -signAlg           # Signing algorithm, which can be SHA256withRSA, SHA384withRSA, SHA256withECDSA, or SHA384withECDSA. It is mandatory.
         ├── -keystoreFile      # KS file, in JKS or P12 format. It is mandatory.
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
         ├── -keystoreFile                    # KS file, in JKS or P12 format. It is mandatory.
         ├── -keystorePwd                     # KS password. It is optional.
         ├── -issuerKeystoreFile              # KS file of the issuer, in JKS or P12 format. It is optional.
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
         ├── -keystoreFile                    # KS file, in JKS or P12 format. It is mandatory.
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
         ├── -keystoreFile                    # KS file, in JKS or P12 format. It is mandatory.
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
         ├── -issuerKeyPwd                      # Key password of the issuer. It is optional.
         ├── -subject                           # Certificate subject. It is mandatory.
         ├── -validity                          # Validity period of the certificate. It is optional. The default value is 1095 days.
         ├── -keyUsage                          # Usages of the key. It is mandatory. The value can be one or more of digitalSignature, nonRepudiation, keyEncipherment,
         ├                                        dataEncipherment, keyAgreement, certificateSignature, crlSignature,
         ├                                        encipherOnly, and decipherOnly. Use a comma (,) to separate multiple values.
         ├── -keyUsageCritical                  # Whether keyUsage is a critical option. It is optional. The default value is true.
         ├── -extKeyUsage                       # Extended key usages. It is optional. The extended key usages include clientAuthentication, serverAuthentication,
         ├                                        codeSignature, emailProtection, smartCardLogin, timestamp, and ocspSignature.
         ├── -extKeyUsageCritical               # Whether extKeyUsage is a critical option. It is optional. The default value is false.
         ├── -signAlg                           # Signing algorithm, which can be SHA256withRSA, SHA384withRSA,  SHA256withECDSA, or SHA384withECDSA. It is mandatory.
         ├── -basicConstraints                  # Whether basicConstraints is contained. It is optional. The default value is false.
         ├── -basicConstraintsCritical          # Whether basicConstraints is a critical option. It is optional. The default value is false.
         ├── -basicConstraintsCa                # Whether it is CA. It is optional. The default value is false.
         ├── -basicConstraintsPathLen           # Path length. It is optional. The default value is 0.
         ├── -issuerKeystoreFile                # KS file of the issuer, in JKS or P12 format. It is optional.
         ├── -issuerKeystorePwd                 # KS password of the issuer. It is optional. 
         ├── -keystoreFile                      # KS file, in JKS or P12 format. It is mandatory.
         ├── -keystorePwd                       # KS password. It is optional.
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
         ├── -keystoreFile    # KS file, in JKS or P12 format. It is mandatory if mode is localSign.
         ├── -keystorePwd     # KS password. It is optional.
         ├── -outFile         # Signed profile to generate, in p7b format. This parameter is mandatory.
     ```

10. Verify the signature of a profile.

     ```
     verify-profile: Verify the profile signature.
         ├── -inFile       # Signed profile in p7b format. This parameter is mandatory.
         ├── -outFile      # Verification result file (containing the verification result and profile content), in JSON format. It is optional. The file is output to the console if this parameter is not specified.
     ```

11. Sign an app package or a debug tool.

      ```
     sign-app: Sign an app package or a binary tool.
          ├── -mode          # Signing mode, which can be localSign, remoteSign, or remoteResign. It is mandatory.
          ├── -keyAlias      # Key alias. It is mandatory.
          ├── -keyPwd        # Key password. It is optional.
          ├── -appCertFile   # App signing certificate (certificate chain, in the entity certificate, intermediate CA certificate, and root certificate order). It is mandatory.
          ├── -profileFile   # Name of the signed provisioning profile. When profileSigned is 1, the file is in p7b format. When profileSigned is 0, the file is in JSON format. This parameter is mandatory if an app package is to be signed, and optional if a binary tool is to be signed.
          ├── -profileSigned # Whether to sign the profile. The value 1 means to sign the profile, and value 0 means the opposite. The default value is 1. This parameter is optional.
          ├── -inForm        # Format of the file to be signed. The value is zip for an app package in ZIP format, elf for a binary tool, and bin for an app package in BIN format. The default value is zip. This parameter is optional.
          ├── -inFile        # File to be signed, which can be an app package, an elf file, or a bin file. This parameter is mandatory.
          ├── -signAlg       # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
          ├── -keystoreFile  # KS file, in JKS or P12 format. It is mandatory if mode is localSign.
          ├── -keystorePwd   # KS password. It is optional.
          ├── -outFile       # Signed app package to generate. It is mandatory.
          ├── -signCode      # Whether to enable code signing. The value 1 means to enable code signing, and the value 0 means the opposite. This parameter is optional. By default, code signing is enabled for .hap, .hsp, .hqf, and .elf files. To disable code signing, set this parameter to 0.
      ```

12. Verify the signature of an app package or a debug tool.

    ```
    verify-app: Verify the signature of an app package or a binary tool.
         ├── -inFile          # Signed file, which can be an app package, an elf file, or a bin file. This parameter is mandatory.
         ├── -outCertchain    # Signed certificate chain file. It is mandatory.
         ├── -outProfile      # Profile of the app. It is mandatory.
         ├── -inForm          # Format of the file to be verified. The value is zip for an app package in ZIP format, elf for a binary tool, and bin for an app package in BIN format. The default value is zip. This parameter is optional.
    ```

    

### Signing Procedure
The process of signing an app package is as follows:

1. Generate a key pair for an app signing certificate.
2. Generate an app signing certificate.
3. Sign the profile.
4. Sign the app package.


> **NOTE**<br>
>
> - For security purposes, use ECC to generate the key pair in step 1. Avoid using RSA.
> - You are advised to place the app package to be signed, profile, **OpenHarmony.p12**, root CA certificate, intermediate CA certificate, and hapsigner in the same directory for easy operation. The following files are stored in [**developtools_hapsigner/autosign/result**](https://gitee.com/openharmony/developtools_hapsigner/tree/master/autosign/result):<br>- OpenHarmony keystore file **OpenHarmony.p12**<br>- Root CA certificate **rootCA.cer**<br>- intermediate CA certificate **subCA.cer**<br>- Profile signing certificate **OpenHarmonyProfileRelease.pem**

1. **Generate a key pair for the app signing certificate.**

   Generate a key pair for signing and save it to the KS.

   Example:

   ```shell
   java -jar hap-sign-tool.jar generate-keypair -keyAlias "oh-app1-key-v1" -keyAlg "ECC"  -keySize "NIST-P-256" -keystoreFile "OpenHarmony.p12" -keyPwd "123456" -keystorePwd "123456"
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
       ├── -keyStoreFile     # KS file. OpenHarmony.p12 is recommended. This parameter is mandatory.
       ├── -keyStorePwd      # KS password. It is mandatory. The default password is 123456 for OpenHarmony.p12.
       ├── -keyPwd           # Key password. It is optional. If this parameter is not specified, the generated key pair has no password.
   ```

2. **Generate an app signing certificate.**

   Use the local intermediate CA certificate to issue an app signing certificate.

   Example:

   ```shell
   java -jar hap-sign-tool.jar generate-app-cert -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA"  -issuer "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN= OpenHarmony Application CA" -issuerKeyAlias "openharmony application ca" -subject "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN=OpenHarmony Application Release" -keystoreFile "OpenHarmony.p12" -subCaCertFile "subCA.cer" -rootCaCertFile "rootCA.cer" -outForm "certChain" -outFile "app1.pem" -keyPwd "123456" -keystorePwd "123456" -issuerKeyPwd "123456" -validity "365"
   ```

   The command parameters are described as follows:

   ```
   generate-app-cert: Generate an app signing certificate.
       ├── -keyAlias         # Key alias, which must be the same as that in the previous step.
       ├── -signAlg          # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
       ├── -issuer           # Issuer of the certificate. Enter the issuer of the intermediate CA certificate. It is mandatory and cannot be changed.
       ├── -issuerKeyAlias   # Alias of the issuer key. Enter the alias of the intermediate CA certificate key. This parameter is mandatory and cannot be changed.
       ├── -subject          # Subject of the certificate. Enter the subject in the same sequence specified in the command. This parameter is mandatory.
       ├── -issuerKeyPwd     # Key password of the issuer. Enter the key password of the intermediate CA certificate. It is mandatory and cannot be changed. In this example, it is 123456. 
       ├── -keystoreFile     # KS file. Use OpenHarmony.p12. It is mandatory and cannot be changed.
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

   Example:

   ```shell
   java -jar hap-sign-tool.jar  sign-profile -keyAlias "openharmony application profile release" -signAlg "SHA256withECDSA" -mode "localSign" -profileCertFile "OpenHarmonyProfileRelease.pem" -inFile "UnsgnedReleasedProfileTemplate.json" -keystoreFile "OpenHarmony.p12" -outFile "app1-profile.p7b" -keyPwd "123456" -keystorePwd "123456"
   ```

   The command parameters are described as follows:

   ```
   sign-profile: Sign a profile.
       ├── -keyAlias         # Alias of the key for generating the profile certificate. It is mandatory and cannot be changed.
       ├── -signAlg          # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
       ├── -mode             # Signing mode, which must be localSign. It is mandatory.
       ├── -profileCertFile  # Profile signing certificate. Use the certificate provided. It is mandatory and cannot be changed.
       ├── -inFile           # Profile to be signed, in JSON format (developtools_hapsigner/autosign/UnsgnedReleasedProfileTemplate.json). It is mandatory.
       ├── -keystoreFile     # KS file. Use OpenHarmony.p12. It is mandatory and cannot be changed.
       ├── -outFile          # Signed profile to generate, in p7b format. This parameter is mandatory.
       ├── -keyPwd           # Key password. The default key password in OpenHarmony.p12 is 123456.
       ├── -keystorePwd      # KS password. The default key password in OpenHarmony.p12 is 123456.
   ```

4. **Sign the app package.**

   Sign the app package with the app signing key.

   Example:

   ```shell
   java -jar hap-sign-tool.jar sign-app -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA" -mode "localSign" -appCertFile "app1.pem" -profileFile "app1-profile.p7b" -inFile "app1-unsigned.zip" -keystoreFile "OpenHarmony.p12" -outFile "app1-signed.hap" -keyPwd "123456" -keystorePwd "123456"
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
       ├──  -inFile          # App package to be signed. This parameter is mandatory.
       ├── -keystoreFile     # KS file, which must be the same as the KS file generated. It is mandatory and cannot be changed.
       ├── -outFile          # Signed file to generate. It is mandatory.
       ├── -keyPwd           # Key password, which must be the actual key password.
       ├── -keystorePwd      # KS password, which must be the actual KS password. 
   ```


## FAQs

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

     (1)  "SIGN_ERROR, code: 107. Details: Failed to verify signature: Wrong key usage"

     (2) "NOT_SUPPORT_ERROR, code: 105. Details: Profile cert 'result\profile1.pem' must a cert chain"

     (3)  "VERIFY_ERROR, code: 108. Details: Failed to verify signature: unable to find valid certification path to requested target"

   - **Possible Causes**

     (1) The certificate chain of the profile signing certificate is in incorrect order.

     (2) The profile signing certificate is not a certificate chain.

     (3) The certificate subject is in incorrect sequence, or the **-issuerKeyAlias** parameter set to generate the app signing certificate is incorrect.

   - **Solution**

     (1) Check that the certificates in the certificate chain are in ascending or descending order of seniority.

     (2) Check that the certificate is a certificate chain.

     (3) Check that the certificate subject is in the C, O, OU, and CN order.

3. Incorrect SignAlg is displayed when an app package is signed.

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
