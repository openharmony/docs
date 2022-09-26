# Hap包签名工具指导

## 编译构建

 1. 该工具基于Gradle 7.1编译构建，请确认环境已安装配置Gradle环境，并且版本高于或等于7.1。

    ```shell 
    gradle -v
    ```
  
 2. 下载代码，命令行打开文件目录至developtools_hapsigner/hapsigntool，执行命令进行编译打包。

    ```shell    
    gradle build 
    ```
     或
    ```shell
    gradle jar
    ```
    
 3. 编译后得到二进制文件，目录为: ./hap_sign_tool/build/libs/hap-sign-tool.jar。

## 开发指导

### 场景介绍

OpenHarmony系统内置密钥库文件，文件名称为OpenHarmony.p12，内含根CA证书、中间CA证书、最终实体证书等信息，工具基于该密钥库文件对OpenHarmony应用进行签名。

按照有无应用签名证书可分为以下两种场景：

1. 无应用签名证书场景：
   开发者使用该工具对Hap包签名时，需按照签名步骤从第一步生成应用签名证书密钥对依次完成应用签名证书生成、profile文件签名、应用签名流程。
2. 有应用签名证书场景：
   开发者可直接从签名步骤第三步对profile文件进行签名开始开发，使用应用签名证书和包含对应密钥的本地密钥库文件对应用进行签名。

### 命令说明

1. 输出命令帮助信息。

     ```
     -help     # 输出命令帮助信息（不输入参数默认输出命令帮助信息）
     ```

2. 输出版本信息。

     ```
     -version  # 输出版本信息
     ```

3. 生成密钥对。

     ```
     generate-keypair : 生成密钥对
         ├── -keyAlias          # 密钥别名，必填项
         ├── -keyPwd            # 密钥口令，可选项
         ├── -keyAlg            # 密钥算法，必填项，包括RSA/ECC
         ├── -keySize           # 密钥长度，必填项，RSA算法的长度为2048/3072/4096，ECC算法的长度NIST-P-256/NIST-P-384
         ├── -keystoreFile      # 密钥库文件，必填项，JKS或P12格式
         ├── -keystorePwd       # 密钥库口令，可选项
     ```

4. 生成证书签名请求。
     ```
     generate-csr : 生成证书签名请求
         ├── -keyAlias          # 密钥别名，必填项
         ├── -keyPwd            # 密钥口令，可选项
         ├── -subject           # 证书主题，必填项
         ├── -signAlg           # 签名算法，必填项，包括SHA256withRSA / SHA384withRSA / SHA256withECDSA / SHA384withECDSA
         ├── -keystoreFile      # 密钥库文件，必填项，JKS或P12格式
         ├── -keystorePwd       # 密钥库口令，可选项
         ├── -outFile           # 输出文件，可选项，如果不填，则直接输出到控制台
     ```
     
5. 生成根CA/中间CA证书。

     ```
     generate-ca : 生成根CA/中间CA证书，如果密钥不存在，一起生成密钥
         ├── -keyAlias                        # 密钥别名，必填项
         ├── -keyPwd                          # 密钥口令，可选项
         ├── -keyAlg                          # 密钥算法，必填项，包括RSA/ECC
         ├── -keySize                         # 密钥长度，必填项，RSA算法的长度为2048/3072/4096，ECC算法的长度NIST-P-256/NIST-P-384
         ├── -issuer                          # 颁发者的主题，可选项，如果不填，表示根CA
         ├── -issuerKeyAlias                  # 颁发者的密钥别名，可选项，如果不填，表示根CA
         ├── -issuerKeyPwd                    # 颁发者的密钥口令，可选项
         ├── -subject                         # 证书主题，必填项
         ├── -validity                        # 证书有效期，可选项，默认为3650天
         ├── -signAlg                         # 签名算法，必填项，包括SHA256withRSA / SHA384withRSA / SHA256withECDSA / SHA384withECDSA
         ├── -basicConstraintsPathLen         # 路径长度，可选项，默认为0
         ├── -keystoreFile                    # 密钥库文件，必填项，JKS或P12格式
         ├── -keystorePwd                     # 密钥库口令，可选项
         ├── -issuerKeystoreFile              # 签发者密钥库文件，可选项，JKS或P12格式
         ├── -issuerKeystorePwd               # 签发者密钥库口令，可选项
         ├── -outFile                         # 输出文件，可选项，如果不填，则直接输出到控制台
     ```

6. 生成应用调试/发布证书。

     ```
     generate-app-cert : 生成应用调试/发布证书
         ├── -keyAlias                        # 密钥别名，必填项
         ├── -keyPwd                          # 密钥口令，可选项
         ├── -issuer                          # 颁发者的主题，必填项
         ├── -issuerKeyAlias                  # 颁发者的密钥别名，必填项
         ├── -issuerKeyPwd                    # 颁发者的密钥口令，可选项
         ├── -subject                         # 证书主题，必填项
         ├── -validity                        # 证书有效期，可选项，默认为3650天
         ├── -signAlg                         # 签名算法，必填项，包括SHA256withECDSA / SHA384withECDSA；
         ├── -issuerKeystoreFile              # 签发者密钥库文件，可选项，JKS或P12格式
         ├── -issuerKeystorePwd               # 签发者密钥库口令，可选项
         ├── -keystoreFile                    # 密钥库文件，必填项，JKS或P12格式
         ├── -keystorePwd                     # 密钥库口令，可选项
         ├── -outForm                         # 输出证书文件的格式，包括 cert / certChain，可选项，默认为certChain
         ├── -rootCaCertFile                  #  outForm为certChain时必填，根CA证书文件
         ├── -subCaCertFile                   #  outForm为certChain时必填，中间CA证书文件
         ├── -outFile                         #  输出证书文件(证书或证书链)，可选项，如果不填，则直接输出到控制台
     ```

7. 生成profile调试/发布证书。

     ```
     generate-profile-cert : 生成profile调试/发布证书
         ├── -keyAlias                        # 密钥别名，必填项
         ├── -keyPwd                          # 密钥口令，可选项
         ├── -issuer                          # 颁发者的主题，必填项
         ├── -issuerKeyAlias                  # 颁发者的密钥别名，必填项
         ├── -issuerKeyPwd                    # 颁发者的密钥口令，可选项
         ├── -subject                         # 证书主题，必填项
         ├── -validity                        # 证书有效期，可选项，默认为3650天
         ├── -signAlg                         # 签名算法，必填项，包括SHA256withECDSA / SHA384withECDSA；
         ├── -issuerKeystoreFile              # 签发者密钥库文件，可选项，JKS或P12格式
         ├── -issuerKeystorePwd               # 签发者密钥库口令，可选项
         ├── -keystoreFile                    # 密钥库文件，必填项，JKS或P12格式
         ├── -keystorePwd                     # 密钥库口令，可选项
         ├── -outForm                         # 输出证书文件的格式，包括 cert / certChain，可选项，默认为certChain
         ├── -rootCaCertFile                  #  outForm为certChain时必填，根CA证书文件
         ├── -subCaCertFile                   #  outForm为certChain时必填，中间CA证书文件
         ├── -outFile                         #  输出证书文件(证书或证书链)，可选项，如果不填，则直接输出到控制台
     ```

8. 通用证书生成，可以生成自定义证书。

     ```
     generate-cert : 通用证书生成，可以生成自定义证书
         ├── -keyAlias                          # 密钥别名，必填项
         ├── -keyPwd                            # 密钥口令，可选项
         ├── -issuer                            # 颁发者的主题，必填项
         ├── -issuerKeyAlias                    # 颁发者的密钥别名，必填项
         ├── -issuerKeyPwd                      # 颁发者的密钥口令，可选项
         ├── -subject                           # 证书主题，必填项
         ├── -validity                          # 证书有效期，可选项，默认为1095天
         ├── -keyUsage                          # 密钥用法，必选项，包括digitalSignature, nonRepudiation, keyEncipherment,
         ├                                        dataEncipherment, keyAgreement, certificateSignature, crlSignature，
         ├                                        encipherOnly和decipherOnly，如果证书包括多个密钥用法，用逗号分隔
         ├── -keyUsageCritical                  # keyUsage是否为关键项，可选项，默认为是
         ├── -extKeyUsage                       # 扩展密钥用法，可选项，包括clientAuthentication，serverAuthentication，
         ├                                        codeSignature，emailProtection，smartCardLogin，timestamp，ocspSignature
         ├── -extKeyUsageCritical               # extKeyUsage是否为关键项，可选项，默认为否
         ├── -signAlg                           # 签名算法，必填项，包括SHA256withRSA/SHA384withRSA/SHA256withECDSA/SHA384withECDSA 
         ├── -basicConstraints                  # 是否包含basicConstraints，可选项，默认为否
         ├── -basicConstraintsCritical          # basicConstraints是否包含为关键项，可选项，默认为否
         ├── -basicConstraintsCa                # 是否为CA，可选项，默认为否
         ├── -basicConstraintsPathLen           # 路径长度，可选项，默认为0
         ├── -issuerKeystoreFile                # 签发者密钥库文件，可选项，JKS或P12格式
         ├── -issuerKeystorePwd                 # 签发者密钥库口令，可选项
         ├── -keystoreFile                      # 密钥库文件，必填项，JKS或P12格式
         ├── -keystorePwd                       # 密钥库口令，可选项
         ├── -outFile                           # 输出证书文件，可选项，如果不填，则直接输出到控制台
     ```

9. profile文件签名。

     ```
     sign-profile : profile文件签名
         ├── -mode            # 签名模式，必填项，包括localSign，remoteSign
         ├── -keyAlias        # 密钥别名，必填项
         ├── -keyPwd          # 密钥口令，可选项
         ├── -profileCertFile # Profile签名证书（证书链，顺序为最终实体证书-中间CA证书-根证书），必填项
         ├── -inFile          # 输入原始的模板Profile文件，文件为json格式，所在目录为developtools_hapsigner/autosign/UnsgnedReleasedProfileTemplate.json，必填项
         ├── -signAlg         # 签名算法，必填项，包括SHA256withECDSA / SHA384withECDSA
         ├── -keystoreFile    # 密钥库文件，localSign模式时为必填项，JKS或P12格式
         ├── -keystorePwd     # 密钥库口令，可选项
         ├── -outFile         # 输出签名后的profile文件，p7b格式，必填项
     ```

10. profile文件验签。

     ```
     verify-profile : profile文件验签
         ├── -inFile       # 已签名的profile文件，p7b格式，必填项
         ├── -outFil       # 验证结果文件（包含验证结果和profile内容），json格式，可选项；如果不填，则直接输出到控制台
     ```

11. hap应用包签名。

      ```
      sign-app : hap应用包签名 
          ├── -mode          # 签名模式，必填项，包括localSign，remoteSign，remoteResign
          ├── -keyAlias      # 密钥别名，必填项
          ├──-keyPwd         # 密钥口令，可选项
          ├── -appCertFile   # 应用签名证书文件（证书链，顺序为最终实体证书-中间CA证书-根证书），必填项
          ├── -profileFile   # 签名后的profile文件名，p7b格式，必填项
          ├── -profileSigned # 指示profile文件是否带有签名，1表示有签名，0表示没有签名，默认为1。可选项
          ├── -inForm        # 输入的原始文件的格式，zip格式或bin格式，默认zip格式，可选项
          ├── -inFile        # 输入的原始APP包文件，hap格式或bin格式，必填项
          ├── -signAlg       # 签名算法，必填项，包括SHA256withECDSA / SHA384withECDSA
          ├── -keystoreFile  # 密钥库文件，localSign模式时为必填项，JKS或P12格式
          ├── -keystorePwd   # 密钥库口令，可选项
          ├── -outFile       # 输出签名后的包文件，必填项
      ```

12. hap应用包文件验签。

      ```
      verify-app : hap应用包文件验签
          ├── -inFile          # 已签名的应用包文件，hap格式或bin格式，必填项
          ├── -outCertchain    # 签名的证书链文件，必填项
          ├── -outProfile      # 应用包中的profile文件，必填项
      ```

### 签名步骤
对hap包签名的完整步骤为：

- 生成应用签名证书密钥对
- 生成应用签名证书
- 对profile文件进行签名
- 对Hap包进行签名


> **注意事项：** <br/>
>
> 1. 步骤一中的密钥对算法推荐使用ECC，出于安全性考虑，应用签名暂不使用RSA算法。
> 2. 建议将待签名hap包、profile文件、密钥库文件OpenHarmony.p12、根CA证书、中间CA证书、签名工具放在同一个目录下，方便操作。在[**developtools_hapsigner/autosign/result**](https://gitee.com/openharmony/developtools_hapsigner/tree/master/autosign/result)路径下，有如下文件：<br/>- OpenHarmony密钥库文件**OpenHarmony.p12**<br/>- 根CA证书**rootCA.cer**<br/>- 中间CA证书**subCA.cer**<br/>- profile签名证书**OpenHarmonyProfileRelease.pem**

1. **生成应用签名证书密钥对**

   调用密钥对生成接口，生成签名密钥并保存到密钥库。

   命令实例：

   ```shell
   java -jar hap-sign-tool.jar generate-keypair -keyAlias "oh-app1-key-v1" -keyAlg "ECC"  -keySize "NIST-P-256" -keystoreFile "OpenHarmony.p12" -keyPwd "123456" -keystorePwd "123456"
   ```
   
   > **说明：** 请记录下**keyAlias、keyStorePwd**和**keyPwd**的值，在后续生成应用  签名证书和对Hap包进行签名操作会使用到。

   该命令的参数说明：

   ```
   generate-keypair : 生成应用签名证书密钥对
       ├── -keyAlias         #用于生成应用签名证书的密钥别名，存于OpenHarmony.p12密钥库文件中，该参数必填
       ├── -keyAlg           #密钥算法，推荐使用ECC，该参数必填
       ├── -keySize          #密钥长度，ECC算法的长度NIST-P-256/NIST-P-384，该参数必填
       ├── -keyStoreFile     #密钥库文件，推荐使用提供的OpenHarmony.p12密钥库文件，该参数必填
       ├── -keyStorePwd      #密钥库口令，OpenHarmony.p12口令默认为“123456”，必填项
       ├── -keyPwd           #密钥口令，可选项，该参数不填默认生成的密钥对无口令
   ```

2. **生成应用签名证书**

   调用应用签名证书生成接口，使用本地中间CA证书签发应用签名证书。

   命令实例：

   ```shell
   java -jar hap-sign-tool.jar generate-app-cert -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA"  -issuer "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN= OpenHarmony Application CA" -issuerKeyAlias "openharmony application ca" -subject "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN=OpenHarmony Application Release" -keystoreFile "OpenHarmony.p12" -subCaCertFile "subCA.cer" -rootCaCertFile "rootCA.cer" -outForm "certChain" -outFile "app1.pem" -keyPwd "123456" -keystorePwd "123456" -issuerKeyPwd "123456" -validity "365"
   ```

   该命令的参数说明：

   ```
   generate-app-cert：生成应用签名证书
       ├── -keyAlias         # 用于生成应用签名证书的密钥别名，请与第一步生成密钥对的密钥别名-keyAlias保持一致
       ├── -signAlg          # 签名算法，必填项，包括 SHA256withECDSA / SHA384withECDSA
       ├── -issuer           # 颁发者主题，填写已提供的中间CA证书主题，该参数必填且不能修改
       ├── -issuerKeyAlias   # 颁发者密钥别名，填写中间CA证书密钥别名，该参数必填且不能修改
       ├── -subject          # 证书主题，请参照命令实例中内容保证顺序不变，该参数必填
       ├── -issuerKeyPwd     # 颁发者密钥口令，填写中间CA证书密钥口令，该参数必填，指定“123456”，不可修改
       ├── -keystoreFile     # 密钥库文件，指定使用提供的OpenHarmony.p12密钥库文件，该参数必填且不可修改
       ├── -rootCaCertFile   # 根CA证书文件，指定为已提供的根CA证书，该参数必填且不可修改
       ├── -subCaCertFile    # 中间CA证书文件，指定为已提供的中间CA证书，该参数必填且不可修改
       ├── -outForm          # 输出证书文件格式，推荐使用certChain
       ├── -outFile          # 可选项，建议填写，不填则默认输出到控制台
       ├── -keyPwd           # 密钥口令，可选项，为第一步生成的密钥对口令
       ├── -keystorePwd      # 密钥库口令，默认为“123456”
       ├── -validity         # 证书有效期，可选项，默认为3650天
   ```

3. **对profile文件进行签名**

   调用profile文件签名接口，使用Profile签名密钥对profile文件进行签名。

   命令实例：

   ```shell
   java -jar hap-sign-tool.jar  sign-profile -keyAlias "openharmony application profile release" -signAlg "SHA256withECDSA" -mode "localSign" -profileCertFile "OpenHarmonyProfileRelease.pem" -inFile "UnsgnedReleasedProfileTemplate.json" -keystoreFile "OpenHarmony.p12" -outFile "app1-profile.p7b" -keyPwd "123456" -keystorePwd "123456"
   ```

   该命令的参数说明：

   ```
   sign-profile：签名profile文件
       ├── -keyAlias         # 生成profile证书的密钥别名，该参数必填且不能修改
       ├── -signAlg          # 签名算法，包括 SHA256withECDSA / SHA384withECDSA，该参数必填
       ├── -mode             # 签名模式，目前仅支持localSign，该参数必填
       ├── -profileCertFile  # Profile签名证书，指定已提供的profile证书文件，该参数必填且不可修改
       ├── -inFile           # 输入原始的模板Profile文件，文件为json格式，所在目录为developtools_hapsigner/autosign/UnsgnedReleasedProfileTemplate.json，该参数必填
       ├── -keystoreFile     # 密钥库文件，指定使用提供的OpenHarmony.p12密钥库文件，该参数必填且不可修改
       ├── -outFile          # 输出签名后的profile文件，p7b格式，该参数必填
       ├── -keyPwd           # 密钥口令，OpenHarmony.p12中的口令默认“123456”
       ├── -keystorePwd      # 密钥库口令，OpenHarmony.p12口令默认为“123456”
   ```

4. **对Hap包进行签名**

   调用Hap包签名接口，使用应用签名密钥为Hap包签名。

   命令实例：

   ```shell
   java -jar hap-sign-tool.jar sign-app -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA" -mode "localSign" -appCertFile "app1.pem" -profileFile "app1-profile.p7b" -inFile "app1-unsigned.zip" -keystoreFile "OpenHarmony.p12" -outFile "app1-signed.hap" -keyPwd "123456" -keystorePwd "123456"
   ```
   > **说明**：以下参数说明默认为无应用签名证书场景，当开发场景为有应用签名证书场景时，下列参数需要修改：
   > -keyAlias：密钥别名，填写已有应用签名证书对应的密钥别名，参数必填。
   > -appCertFile：应用签名证书，填写已有的应用签名证书，参数必填。
   > -keystoreFile：密钥库文件，填写已有应用签名证书对应的密钥库文件，参数必填。
   > -keyPwd：密钥口令，填写密钥库文件中对应密钥的口令。
   > -keystorePwd：密钥库口令，填写密钥库文件的密钥口令。

   该命令的参数说明：

   ```
   sign-app：签名Hap包
       ├── -keyAlias          # 密钥别名，为第一步生成的密钥信息别名，该参数必填
       ├── -signAlg           # 签名算法，包括 SHA256withECDSA / SHA384withECDSA，该参数必填
       ├──  -mode             # 签名模式，目前仅支持localSign，该参数必填
       ├──  -appCertFile      # 应用签名证书（证书链，顺序为最终实体证书-中间CA证书-根证书），填写第二步生成的应用签名证书，该参数必填
       ├──  -profileFile      # 签名后的profile文件，p7b格式，填写第三步中生成的profile文件，必填项
       ├──  -inFile           # 输入原始APP包文件，该参数必填
       ├──  -keystoreFile     # 密钥库文件，请与步骤一中密钥库文件保持一致，该参数必填且不可修改
       ├──  -outFile          # 输出签名后的包文件，必填项
       ├──  -keyPwd           # 密钥口令，与第一步生成的密钥对口令保持一致
       ├──  -keystorePwd      # 密钥库口令，与第一步的密钥库口令保持一致
   ```


## 常见问题

1. 执行第二步生成应用签名证书命令时，控制台打印结果，无文件输出。

   - **现象描述**

     生成证书时，只在控制台打印证书内容，无对应文件输出。   

   - **可能原因**
   
     outFile参数中路径不正确 和 '-outFile'中的'-'非英文格式。
   
   - **解决办法**
   
     检查并修正outFile参数为正确路径，'-outFile'中的'-'为英文格式

2. 执行第三步对profile文件进行签名时，提示签名失败。

   - **现象描述**

     现象分为以下几种：

     （1）执行命令后提示` "SIGN_ERROR, code: 107. Details: Failed to verify signature: Wrong key usage"`

     （2）执行命令后提示 `"NOT_SUPPORT_ERROR, code: 105. Details: Profile cert 'result\profile1.pem' must a cert chain"`

     （3）执行命令后提示` "VERIFY_ERROR, code: 108. Details: Failed to verify signature: unable to find valid certification path to requested target"`

   - **可能原因**

     （1）profile签名证书（最终实体证书）证书链顺序不正确。

     （2）profile签名证书（最终实体证书）不是证书链。

     （3）证书主题顺序不正确 或者 生成应用签名证书时“-issuerKeyAlias”参数填写错误。

   - **解决办法**

     （1）检查并修正证书链顺序，只能正序或反序，不可乱序。

     （2）检查签名时的最终实体证书是否为证书链。

     （3）检查证书主题顺序是否正确，顺序须为C、O、OU、CN。

3. 对Hap包进行签名时提示签名错误。

   - **现象描述**

     执行命令后提示：`NOT_SUPPORT_ERROR, code: 105. Details: SignAlg params is incorrect, signature algorithms include SHA256withECDSA,SHA384withECDSA`。

   - **可能原因**

     签名算法不支持，signAlg参数填写错误。

   - **解决办法**

     最终实体证书密钥对推荐使用ECC生成，hap签名算法修改为ECC对应的SHA256withECDSA,SHA384withECDSA。
