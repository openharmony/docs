# hapsigner Guide

## Build

 1. Check that Gradle 7.1 has been installed.

    ```shell 
    gradle -v
    ```
  
 2. Download the code, open the file directory **developtools_hapsigner/hapsigntool**, and run the following command to build the code:

    ```shell    
    gradle build 
    ```
     Or
    ```shell
    gradle jar
    ```
    
 3. Check that **hap-sign-tool.jar** (binary files) is generated in the **./hap_sign_tool/build/libs** directory.

## Usage Guidelines

### When to Use

The OpenHarmony system has a built-in KeyStore (KS) file named **OpenHarmony.p12**. This file contains the root CA certificate, intermediate CA certificate, and end-entity certificate information. The hapsigner tool signs the OpenHarmony applications based on this KS file.

The usage of hapsigner varies depending on whether an application signing certificate is available. 

- If no application signing certificate is available:<br/>
  You need to generate a key pair, generate an application signing certificate, sign the profile, and sign the application.
- If an application signing certification is available:<br/>
  You need to sign the profile, and use the application signing certificate and the local KS file (containing the corresponding key) to sign the application.

### Description

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
         ├── -keySize           # Key length. It is mandatory. The key length is 2048, 3072, or 4096 bits if RSA is used and is NIST-P-256 or NIST-P-384 if ECC is used.
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
     generate-ca: Generate a root CA or intermediate CA certificate. If the key does not exist, generate a key together with the certificate.
         ├── -keyAlias                        # Key alias. It is mandatory.
         ├── -keyPwd                          # Key password. It is optional.
         ├── -keyAlg                          # Key algorithm, which can be RSA or ECC. It is mandatory.
         ├── -keySize                         # Key length. It is mandatory. The key length is 2048, 3072, or 4096 bits if RSA is used and is NIST-P-256 or NIST-P-384 if ECC is used.
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

6. Generate an application debug or release certificate.

     ```
     generate-app-cert: Generate an application debug or release certificate.
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
         ├── -subCaCertFile                   # Intermediate CA certificate, which is mandatory when outForm is certChain.
         ├── -outFile                         # Certificate file (certificate or certificate chain) to generate. It is optional. The file is output to the console if this parameter is not specified.
     ```

7. Generate a profile debug or release certificate.

     ```
     generate-profile-cert: Generate a profile debug or release certificate.
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
         ├── -subCaCertFile                   # Intermediate CA certificate, which is mandatory when outForm is certChain.
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
         ├── -keyUsage                          # Usages of the key. It is mandatory. The key usages include digitalSignature, nonRepudiation, keyEncipherment,
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
         ├── -profileCertFile # Profile signing certificate (certificate chain, in the end-entity certificate, intermediate CA certificate, and root certificate order). It is mandatory.
         ├── -inFile          # Raw profile template in JSON format (developtools_hapsigner/autosign/UnsgnedReleasedProfileTemplate.json). It is mandatory.
         ├── -signAlg         # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
         ├── -keystoreFile    # KS file, in JKS or P12 format. It is mandatory if the signing mode is localSign.
         ├── -keystorePwd     # KS password. It is optional.
         ├── -outFile         # Signed profile to generate, in p7b format. This parameter is mandatory.
     ```

10. Verify the signature of the profile.

     ```
     verify-profile: Verify the profile signature.
         ├── -inFile        # Signed profile in p7b format. This parameter is mandatory.
         ├── -outFile       # Verification result file (including the verification result and profile content), in json format. It is optional. The file is output to the console if this parameter is not specified.
     ```

11. Sign a HAP.

      ```
      sign-app: Sign a HAP.
          ├── -mode          # Signing mode, which can be localSign, remoteSign, or remoteResign. It is mandatory.
          ├── -keyAlias      # Key alias. It is mandatory.
          ├── -keyPwd        # Key password. It is optional.
          ├── -appCertFile   # Application signing certificate (certificate chain, in the end-entity certificate, intermediate CA certificate, and root certificate order). It is mandatory.
          ├── -profileFile   # Name of the signed profile in p7b format. This parameter is mandatory.
          ├── -profileSigned # Whether the profile is signed. The value 1 means signed, and value 0 means unsigned. The default value is 1. This parameter is optional.
          ├── -inForm        # Raw file, in .zip (default) or .bin format. It is optional.
          ├── -inFile        # Raw application package, in HAP or .bin format. It is mandatory.
          ├── -signAlg       # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
          ├── -keystoreFile  # KS file, in JKS or P12 format. It is mandatory if the signing mode is localSign.
          ├── -keystorePwd   # KS password. It is optional.
          ├── -outFile       # Signed HAP file to generate. It is mandatory.
      ```

12. Verify the HAP signature.

      ```
      verify-app: Verify the HAP signature.
          ├── -inFile          # Signed application file, in HAP or bin format. It is mandatory.
          ├── -outCertchain    # Signed certificate chain file. It is mandatory.
          ├── -outProfile      # Profile of the application. It is mandatory.
      ```

### Signing Procedure
The process of signing a HAP is as follows:

1. Generate a key pair for an application signing certificate.
2. Generate an application signing certificate.
3. Sign the profile.
4. Sign the HAP.


> **Precautions** <br>
>
> For security purposes, use ECC to generate the key pair in step 1. Do not use RSA.
>
> You are advised to place the HAP to be signed, profile, **OpenHarmony.p12**, root CA certificate, intermediate CA certificate, and hapsigner in the same directory for easy operation. The [**developtools_hapsigner/autosign/result**](https://gitee.com/openharmony/developtools_hapsigner/tree/master/autosign/result) directory has the following files:
>
> - OpenHarmony KS file: **OpenHarmony.p12** 
> - Root CA certificate: **rootCA.cer**
> - Intermediate CA certificate: **subCA.cer**
> - Profile signing certificate: **OpenHarmonyProfileRelease.pem**

1. **Generate a key pair for the application signing certificate.**

   Generate a signing key pair and save it to the KS.

   Example:

   ```shell
   java -jar hap-sign-tool.jar generate-keypair -keyAlias "oh-app1-key-v1" -keyAlg "ECC"  -keySize "NIST-P-256" -keystoreFile "OpenHarmony.p12" -keyPwd "123456" -keystorePwd "123456"
   ```
   
   > Note:<br>Record the values of **keyAlias**, **keyStorePwd**, and **keyPwd**. These values will be used when the application signing certificate is generated and the HAP is signed.

   The command parameters are described as follows:

   ```
   generate-keypair: Generate a key pair for the application signing certificate.
       ├── -keyAlias         # Alias of the key used to generate the application signing certificate. It is stored in the OpenHarmony.p12 file. This parameter is mandatory.
       ├── -keyAlg           # Key algorithm. It is mandatory. ECC is recommended.
       ├── -keySize          # Key length. It is NIST-P-256/NIST-P-384 if ECC is used. This parameter is mandatory.
       ├── -keyStoreFile     # KS file. OpenHarmony.p12 is recommended. This parameter is mandatory.
       ├── -keyStorePwd      # KS password. It is mandatory. The default password 123456 for OpenHarmony.p12.
       ├── -keyPwd           # Key password. It is optional. If this parameter is not specified, the generated key pair has no password.
   ```

2. **Generate an application signing certificate.**

   Use the local intermediate CA certificate to issue an application signing certificate.

   Example:

   ```shell
   java -jar hap-sign-tool.jar generate-app-cert -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA"  -issuer "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN= OpenHarmony Application CA" -issuerKeyAlias "openharmony application ca" -subject "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN=OpenHarmony Application Release" -keystoreFile "OpenHarmony.p12" -subCaCertFile "subCA.cer" -rootCaCertFile "rootCA.cer" -outForm "certChain" -outFile "app1.pem" -keyPwd "123456" -keystorePwd "123456" -issuerKeyPwd "123456" -validity "365"
   ```

   The command parameters are described as follows:

   ```
   generate-app-cert: Generate an application signing certificate.
       ├── -keyAlias         # Key alias, which must be the same as that in the previous step.
       ├── -signAlg          # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
       ├── -issuer           #  Issuer of the certificate. Enter the issuer of the intermediate CA certificate. It is mandatory and cannot be changed.
       ├── -issuerKeyAlias   # Key alias of the issuer. Enter the key alias of the intermediate CA certificate. This parameter is mandatory and cannot be changed.
       ├── -subject          # Subject of the certificate. Enter the subject in the same sequence specified in the command. This parameter is mandatory.
       ├── -issuerKeyPwd     # Key password of the issuer. Enter the key password of the intermediate CA certificate. It is mandatory and cannot be changed. In this example, it is 123456. 
       ├── -keystoreFile     # KS file. Use OpenHarmony.p12. It is mandatory and cannot be changed.
       ├── -rootCaCertFile   # Root certificate. It is mandatory and cannot be changed.
       ├── -subCaCertFile    # Intermediate CA certificate. This parameter is mandatory and cannot be changed.
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
       ├── -inFile           # Raw profile template in JSON format (developtools_hapsigner/autosign/UnsgnedReleasedProfileTemplate.json). It is mandatory.
       ├── -keystoreFile     # KS file. Use OpenHarmony.p12. It is mandatory and cannot be changed.
       ├── -outFile          # Signed profile to generate, in p7b format. This parameter is mandatory.
       ├── -keyPwd           # Key password. The default key password in OpenHarmony.p12 is 123456.
       ├── -keystorePwd      # KS password. The default key password in OpenHarmony.p12 is 123456.
   ```

4. **Sign the HAP.**

   Call the HAP signing API to sign the HAP using the application signing key.

   Example:

   ```shell
   java -jar hap-sign-tool.jar sign-app -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA" -mode "localSign" -appCertFile "app1.pem" -profileFile "app1-profile.p7b" -inFile "app1-unsigned.zip" -keystoreFile "OpenHarmony.p12" -outFile "app1-signed.hap" -keyPwd "123456" -keystorePwd "123456"
   ```
   > Note:<br>The following parameters are used when there is no application signing certificate available. If the application signing certificate is available, the following parameters must be modified.
   >
   > - **keyAlias**: Enter the key alias of the application signing certificate. This parameter is mandatory. 
   > - **appCertFile**: Enter the application signing certificate. This parameter is mandatory.
   > - **keystoreFile**: Enter the KS file of the application signing certificate. This parameter is mandatory. 
   > - **keyPwd**: Enter the key password in the KS file. 
   > - **keystorePwd**: Enter the KS password in the KS file.

   The command parameters are described as follows:

   ```
   sign-app: Sign a HAP.
       ├──-keyAlias          # Key alias, which must be the same as the alias of the key pair generated. This parameter is mandatory.
       ├── -signAlg          # Signing algorithm, which can be SHA256withECDSA or SHA384withECDSA. It is mandatory.
       ├── -mode             # Signing mode, which must be localSign. It is mandatory.
       ├── -appCertFile      # Application signing certificate (certificate chain, in the end-entity certificate, intermediate CA certificate, and root certificate order). Enter the application signing certificate generated in step 2. This parameter is mandatory.
       ├── -profileFile      # Signed profile in p7b format. Enter the profile generated. This parameter is mandatory.
       ├── -inFile           # Raw application package. It is mandatory.
       ├── -keystoreFile     # KS file, which must be the same as the KS file generated. It is mandatory and cannot be changed.
       ├── -outFile          # Signed file to generate. It is mandatory.
       ├── -keyPwd           # Key password, which must be the actual key password.
       ├── -keystorePwd      # KS password, which must be the actual KS password. 
   ```


## FAQs

1. When the application signing certificate is generated, the console displays the result but no file is output.

   - **Symptom**

     When the tool is used to generate an application signing certificate, the certificate content is displayed on the console and no certificate is generated.  

   - **Possible Causes**
   
     The path in the **outFile** parameter is incorrect, or the hyphen (-) in **-outFile** is not an English character.
   
   - **Solution**
   
     Check and correct the value of **outFile**, and ensure the hyphen (-) in **-outFile** is an English character.

2. Failed to sign the profile.

   - **Symptom**

     When the tool is used to sign a profile, any of the following information is displayed:

     (1) ` "SIGN_ERROR, code: 107. Details: Failed to verify signature: Wrong key usage"`

     (2) `"NOT_SUPPORT_ERROR, code: 105. Details: Profile cert 'result\profile1.pem' must a cert chain"`

     (3) ` "VERIFY_ERROR, code: 108. Details: Failed to verify signature: unable to find valid certification path to requested target"`

   - **Possible Causes**

     (1) The certificate chain of the profile signing certificate is in incorrect order.

     (2) The profile signing certificate is not a certificate chain.

     (3) The certificate subject is in incorrect sequence, or the **-issuerKeyAlias** parameter set to generate the application signing certificate is incorrect.

   - **Solution**

     (1) Check that the certificate chain is in ascending or descending order of seniority.

     (2) Check that the certificate is a certificate chain.

     (3) Check that the certificate subject is in the C, O, OU, and CN order.

3. An error message is displayed when the tool is used to sign a HAP.

   - **Symptom**

     The following information is displayed after the command is executed:<br>`NOT_SUPPORT_ERROR, code: 105. Details: SignAlg params is incorrect, signature algorithms include SHA256withECDSA,SHA384withECDSA`

   - **Possible Causes**

     The signing algorithm is not supported. Check the value of **signAlg**.

   - **Solution**

     Use ECC to generate the key pair for the application or profile signing certificate. Use SHA256withECDSA or SHA384withECDSA as the HAP signing algorithm.
