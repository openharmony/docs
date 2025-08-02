# 应用包签名工具指导

## 编译构建

**Java流程**：

1. 该工具基于Maven3编译构建，请确认环境已安装配置Maven3环境，并且版本正确
  
        mvn -version

2. 下载代码，命令行打开文件目录至developtools_hapsigner/hapsigntool，执行命令进行编译打包
            
        mvn package

3. 编译后得到二进制文件，目录为: ./hap_sign_tool/target

**C++流程**：

1. 编译ohos-sdk形态的签名工具

   编译release版本：默认是release版本，直接编译即可。 

   编译debug版本：在 hapsigntool_cpp/BUILD.gn 中 添加 defines = [ "SIGNATURE_LOG_DEBUG" ] 即可。 

   编译命令：./build.sh --product-name ohos-sdk 

2. 编译产物最终路径：out/sdk/packages/ohos-sdk/ohos/toolchains-ohos-x64-xxx.zip

   解压压缩包后，在lib目录下获取最终二进制产物hap-sign-tool

## 开发指导

### 场景介绍

OpenHarmony系统内置密钥库文件，文件名称为OpenHarmony.p12，内含根CA证书、中间CA证书、最终实体证书等信息，工具基于该密钥库文件对OpenHarmony应用进行签名。

按照有无应用签名证书可分为以下两种场景：

1. 无应用签名证书场景：
   开发者使用该工具对应用包签名时，需按照签名步骤从第一步生成应用签名证书密钥对依次完成应用签名证书生成、profile文件签名、应用签名流程。
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
         ├── -keystoreFile      # 密钥库文件，必填项
         ├── -keystorePwd       # 密钥库口令，可选项
     ```

4. 生成证书签名请求。
     ```
     generate-csr : 生成证书签名请求
         ├── -keyAlias          # 密钥别名，必填项
         ├── -keyPwd            # 密钥口令，可选项
         ├── -subject           # 证书主题，必填项
         ├── -signAlg           # 签名算法，必填项，包括SHA256withRSA / SHA384withRSA / SHA256withECDSA / SHA384withECDSA
         ├── -keystoreFile      # 密钥库文件，必填项
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
         ├── -keystoreFile                    # 密钥库文件，必填项
         ├── -keystorePwd                     # 密钥库口令，可选项
         ├── -issuerKeystoreFile              # 签发者密钥库文件，可选项
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
         ├── -keystoreFile                    # 密钥库文件，必填项
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
         ├── -keystoreFile                    # 密钥库文件，必填项
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
         ├── -issuerKeystoreFile                # 签发者密钥库文件，可选项
         ├── -issuerKeystorePwd                 # 签发者密钥库口令，可选项
         ├── -keystoreFile                      # 密钥库文件，必填项
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
         ├── -keystoreFile    # 密钥库文件，localSign模式时为必填项
         ├── -keystorePwd     # 密钥库口令，可选项
         ├── -outFile         # 输出签名后的profile文件，p7b格式，必填项
     ```

10. profile文件验签。

     ```
     verify-profile : profile文件验签
         ├── -inFile       # 已签名的profile文件，p7b格式，必填项
         ├── -outFile      # 验证结果文件（包含验证结果和profile内容），json格式，可选项；如果不填，则直接输出到控制台
     ```

11. 应用包和调试工具签名。

      ```
     sign-app : 应用包和二进制工具签名
          ├── -mode          # 签名模式，必填项，包括localSign，remoteSign，remoteResign
          ├── -keyAlias      # 密钥别名，必填项
          ├── -keyPwd        # 密钥口令，可选项
          ├── -appCertFile   # 应用签名证书文件（证书链，顺序为实体证书-中间CA证书-根证书），必填项
          ├── -profileFile   # 签名后的Provision Profile文件名，profileSigned为1时为p7b格式，profileSigned为0时为json格式，应用包签名必填项，二进制工具签名选填
          ├── -profileSigned # 指示profile文件是否带有签名，1表示有签名，0表示没有签名，默认为1。可选项
          ├── -inForm        # 输入的原始文件的格式，枚举值：zip、elf或bin；zip应用包对应zip，二进制工具对应elf，bin应用包为bin，默认zip；可选项
          ├── -inFile        # 输入的原始文件，应用包、elf或bin文件，必填项
          ├── -signAlg       # 签名算法，必填项，包括SHA256withECDSA / SHA384withECDSA
          ├── -keystoreFile  # 密钥库文件，localSign模式时为必填项
          ├── -keystorePwd   # 密钥库口令，可选项
          ├── -outFile       # 输出签名后的包文件，必填项
          ├── -signCode      # 是否启用代码签名，1表示开启代码签名，0表示关闭代码签名。可选项。默认对hap、hsp、hqf、elf开启代码签名，通过参数配置为0关闭。

      ```

12. 应用包和调试工具文件验签。

      ```
      verify-app : 应用包和二进制工具文件验签
         ├── -inFile          # 已签名的文件，应用包、elf或bin文件，必填项
         ├── -outCertChain    # 签名的证书链文件，必填项
         ├── -outProfile      # 应用包中的profile文件，必填项
         ├── -inForm          # 输入的原始文件的格式，枚举值：zip、elf或bin；zip应用包对应zip，二进制工具对应elf，bin应用包为bin，默认zip；可选项
      ```

### 签名步骤
对应用包签名的完整步骤为：

- 生成应用签名证书密钥对
- 生成应用签名证书
- 对profile文件进行签名
- 对应用包进行签名


> **注意事项：** <br/>
>
> 1. 步骤一中的密钥对算法推荐使用ECC，出于安全性考虑，应用签名暂不使用RSA算法。
> 2. 建议将待签名应用包、profile文件、密钥库文件OpenHarmony.p12、根CA证书、中间CA证书、签名工具放在同一个目录下，方便操作。在[**developtools_hapsigner/autosign/result**](https://gitcode.com/openharmony/developtools_hapsigner/tree/master/autosign/result)路径下，有如下文件：<br/>- OpenHarmony密钥库文件**OpenHarmony.p12**<br/>- 根CA证书**rootCA.cer**<br/>- 中间CA证书**subCA.cer**<br/>- profile签名证书**OpenHarmonyProfileRelease.pem**

1. **生成应用签名证书密钥对**

   调用密钥对生成接口，生成签名密钥并保存到密钥库。

   Java版本命令实例：

   ```shell
   java -jar hap-sign-tool.jar generate-keypair -keyAlias "oh-app1-key-v1" -keyAlg "ECC"  -keySize "NIST-P-256" -keystoreFile "OpenHarmony.p12" -keyPwd "123456" -keystorePwd "123456"
   ```

   C++版本命令实例：

   ```shell
   hap-sign-tool generate-keypair -keyAlias "oh-app1-key-v1" -keyAlg "ECC"  -keySize "NIST-P-256" -keystoreFile "OpenHarmony.p12" -keyPwd "123456" -keystorePwd "123456"
   ```

   > **说明：**
   >
   > 请记录下**keyAlias、keyStorePwd**和**keyPwd**的值，在后续生成应用签名证书和对应用包进行签名操作会使用到。

   该命令的参数说明：

   ```
   generate-keypair : 生成应用签名证书密钥对
       ├── -keyAlias         #用于生成应用签名证书的密钥别名，存于OpenHarmony.p12密钥库文件中，该参数必填
       ├── -keyAlg           #密钥算法，推荐使用ECC，该参数必填
       ├── -keySize          #密钥长度，ECC算法的长度NIST-P-256/NIST-P-384，该参数必填
       ├── -keyStoreFile     #密钥库文件，推荐使用提供的OpenHarmony.p12密钥库文件，该参数必填。java版本支持PKCS#12和JKS两种密钥库格式，C++版本仅支持PKCS#12密钥库格式
       ├── -keyStorePwd      #密钥库口令，OpenHarmony.p12口令默认为“123456”，必填项
       ├── -keyPwd           #密钥口令，可选项，该参数不填默认生成的密钥对无口令
   ```

2. **生成应用签名证书**

   调用应用签名证书生成接口，使用本地中间CA证书签发应用签名证书。

   Java版本命令实例：

   ```shell
   java -jar hap-sign-tool.jar generate-app-cert -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA"  -issuer "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN= OpenHarmony Application CA" -issuerKeyAlias "openharmony application ca" -subject "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN=OpenHarmony Application Release" -keystoreFile "OpenHarmony.p12" -subCaCertFile "subCA.cer" -rootCaCertFile "rootCA.cer" -outForm "certChain" -outFile "app1.pem" -keyPwd "123456" -keystorePwd "123456" -issuerKeyPwd "123456" -validity "365"
   ```

   C++版本命令实例：

   ```shell
   hap-sign-tool generate-app-cert -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA"  -issuer "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN= OpenHarmony Application CA" -issuerKeyAlias "openharmony application ca" -subject "C=CN,O=OpenHarmony,OU=OpenHarmony Team,CN=OpenHarmony Application Release" -keystoreFile "OpenHarmony.p12" -subCaCertFile "subCA.cer" -rootCaCertFile "rootCA.cer" -outForm "certChain" -outFile "app1.pem" -keyPwd "123456" -keystorePwd "123456" -issuerKeyPwd "123456" -validity "365"
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
       ├── -keystoreFile     # 密钥库文件，指定使用提供的OpenHarmony.p12密钥库文件，该参数必填且不可修改。java版本支持PKCS#12和JKS两种密钥库格式，C++版本仅支持PKCS#12密钥库格式
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

   Java版本命令实例：

   ```shell
   java -jar hap-sign-tool.jar  sign-profile -keyAlias "openharmony application profile release" -signAlg "SHA256withECDSA" -mode "localSign" -profileCertFile "OpenHarmonyProfileRelease.pem" -inFile "UnsgnedReleasedProfileTemplate.json" -keystoreFile "OpenHarmony.p12" -outFile "app1-profile.p7b" -keyPwd "123456" -keystorePwd "123456"
   ```

   C++版本命令实例：

   ```shell
   hap-sign-tool sign-profile -keyAlias "openharmony application profile release" -signAlg "SHA256withECDSA" -mode "localSign" -profileCertFile "OpenHarmonyProfileRelease.pem" -inFile "UnsgnedReleasedProfileTemplate.json" -keystoreFile "OpenHarmony.p12" -outFile "app1-profile.p7b" -keyPwd "123456" -keystorePwd "123456"
   ```

   该命令的参数说明：

   ```
   sign-profile：签名profile文件
       ├── -keyAlias         # 生成profile证书的密钥别名，该参数必填且不能修改
       ├── -signAlg          # 签名算法，包括 SHA256withECDSA / SHA384withECDSA，该参数必填
       ├── -mode             # 签名模式，目前仅支持localSign，该参数必填
       ├── -profileCertFile  # Profile签名证书，指定已提供的profile证书文件，该参数必填且不可修改
       ├── -inFile           # 输入原始的模板Profile文件，文件为json格式，所在目录为developtools_hapsigner/autosign/UnsgnedReleasedProfileTemplate.json，该参数必填
       ├── -keystoreFile     # 密钥库文件，指定使用提供的OpenHarmony.p12密钥库文件，该参数必填且不可修改。java版本支持PKCS#12和JKS两种密钥库格式，C++版本仅支持PKCS#12密钥库格式
       ├── -outFile          # 输出签名后的profile文件，p7b格式，该参数必填
       ├── -keyPwd           # 密钥口令，OpenHarmony.p12中的口令默认“123456”
       ├── -keystorePwd      # 密钥库口令，OpenHarmony.p12口令默认为“123456”
   ```

4. **对应用包进行签名**

   调用应用包签名接口，使用应用签名密钥为应用包签名。

   Java版本命令实例：

   ```shell
   java -jar hap-sign-tool.jar sign-app -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA" -mode "localSign" -appCertFile "app1.pem" -profileFile "app1-profile.p7b" -inFile "app1-unsigned.zip" -keystoreFile "OpenHarmony.p12" -outFile "app1-signed.hap" -keyPwd "123456" -keystorePwd "123456"
   ```

   C++版本命令实例：
   
   ```shell
   hap-sign-tool sign-app -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA" -mode "localSign" -appCertFile "app1.pem" -profileFile "app1-profile.p7b" -inFile "app1-unsigned.zip" -keystoreFile "OpenHarmony.p12" -outFile "app1-signed.hap" -keyPwd "123456" -keystorePwd "123456"
   ```

   > **说明**：
   >
   > 以下参数说明默认为无应用签名证书场景，当开发场景为有应用签名证书场景时，下列参数需要修改：
   > -keyAlias：密钥别名，填写已有应用签名证书对应的密钥别名，参数必填。
   > -appCertFile：应用签名证书，填写已有的应用签名证书，参数必填。
   > -keystoreFile：密钥库文件，填写已有应用签名证书对应的密钥库文件，参数必填。
   > -keyPwd：密钥口令，填写密钥库文件中对应密钥的口令。
   > -keystorePwd：密钥库口令，填写密钥库文件的密钥口令。

   该命令的参数说明：

   ```
   sign-app：签名应用包
       ├── -keyAlias          # 密钥别名，为第一步生成的密钥信息别名，该参数必填
       ├── -signAlg           # 签名算法，包括 SHA256withECDSA / SHA384withECDSA，该参数必填
       ├──  -mode             # 签名模式，目前仅支持localSign，该参数必填
       ├──  -appCertFile      # 应用签名证书（证书链，顺序为最终实体证书-中间CA证书-根证书），填写第二步生成的应用签名证书，该参数必填
       ├──  -profileFile      # 签名后的profile文件，p7b格式，填写第三步中生成的profile文件，必填项
       ├──  -inFile           # 输入原始应用包文件，该参数必填
       ├──  -keystoreFile     # 密钥库文件，请与步骤一中密钥库文件保持一致，该参数必填且不可修改。java版本支持PKCS#12和JKS两种密钥库格式，C++版本仅支持PKCS#12密钥库格式
       ├──  -outFile          # 输出签名后的包文件，必填项
       ├──  -keyPwd           # 密钥口令，与第一步生成的密钥对口令保持一致
       ├──  -keystorePwd      # 密钥库口令，与第一步的密钥库口令保持一致
   ```

## Java版本工具常见问题

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

3. 对应用包进行签名时提示签名错误。

   - **现象描述**

     执行命令后提示：`NOT_SUPPORT_ERROR, code: 105. Details: SignAlg params is incorrect, signature algorithms include SHA256withECDSA,SHA384withECDSA`。

   - **可能原因**

     签名算法不支持，signAlg参数填写错误。

   - **解决办法**

     最终实体证书密钥对推荐使用ECC生成，hap签名算法修改为ECC对应的SHA256withECDSA,SHA384withECDSA。

4. 签名应用包失败，提示证书CN字段为空。

   - **现象描述**

     执行命令后提示：`error: Common name of certificate is empty! `。

   - **可能原因**

     当前使用的应用包签名证书，不包含CN字段，导致签名失败。

   - **解决办法**

     根据业界证书规范，应用包签名证书的CN字段必须不为空，请重新生成格式正确的证书。
     

## C++版本工具常见问题

> **说明：**
> 以下每个小条目按序号一一对应，比如现象描述的(1)，对应可能原因的(1)，对应解决办法的(1)，以此类推。

1. 命令行参数输入有误报错

   + **现象描述**

     （1）执行命令，报错提示：ERROR - COMMAND_PARAM_ERROR, code: -107. Details: 'generate-cert' Parameters error, Param key - value must in pairs

     （2）执行命令，报错提示：ERROR - KEY_PASSWORD_ERROR, code: -114. Details: 'oh-app1-key-v1' keypair password error

     （3）执行命令，报错提示：ERROR - NOT_SUPPORT_ERROR, code: -104. Details: Not support file: ./OpenHarmony.p1

     （4）执行命令，报错提示：ERROR - KEY_ALIAS_ERROR, code: -109. Details: 'XXX' key alias already exists and cannot be generated repeatedly

   + **可能原因**

     （1）粘贴某条命令时，多粘贴了一段造成COMMAND_PARAM_ERROR错误，或者填写命令时，最后一个参数的value值忘记填写触发该COMMAND_PARAM_ERROR错误

     （2）密钥对密码填写错误时，会触发 KEY_PASSWORD_ERROR错误

     （3）填写了错误的密钥库文件类型，触发NOT_SUPPORT_ERROR错误

     （4）密钥库中已存在该别名的密钥对，触发KEY_ALIAS_ERROR错误

   + **解决办法**

     （1）检查填写的命令是否有误，修正多余或错误的命令

     （2）仔细检查命令中密码参数是否正确，访问不同密钥库获取密钥不要忘记填写各自的密钥对密码

     （3）检查密钥库文件后缀是否为：`{.p12、.jks}`

     （4）将需要生成密钥对的别名替换为其他的命名

2. 执行生成应用签名证书命令时，提示参数错误。

   - **现象描述**

     （1）执行命令后，报错提示 ERROR - KEY_ALIAS_ERROR, code: -109. Details: keyAlias: 'oh-app1-key-v2' is not exist in/mnt/d/file/Test_0528/OpenHarmony.p12

     （2）执行命令后，报错提示 ERROR - KEYSTORE_PASSWORD_ERROR, code: -115. Details: keyStore password error

     （3）执行命令后，报错提示 ERROR - KEY_PASSWORD_ERROR, code: -114. Details: 'oh-app-sign-srv-ca-key-v1' keypair password error

   - **可能原因**

     （1）参数中的密钥别名在密钥库中找不到

     （2）输入的密钥库密码输入错误

     （3）生成app中间CA证书时输入的参数中有密钥对的密码，但是生成app调试证书没有输入-issuerKeyPwd参数

   - **解决办法**

     （1）检查密钥别名修改为与生成密钥对时输入的参数一致

     （2）检查密钥库密码与生成密钥对时的输入的密钥库密码一致

     （3）生成profile证书时，输入的参数必须有-issuerKeyPwd和对应的密码且与生成profile中间CA证书时密钥对的密码一致

3. 执行profile文件进行签名时，提示签名失败。

   - **现象描述**

     （1）执行命令后，报错提示 ：ERROR - PROVISION_INVALID, code: 0. Details: Tag app-distribution-type is empty

     （2）执行命令后，报错提示 ：VERIFY_ERROR, code: -106. Details: Failed to verify signature: unable to find valid certification path to requested target

   - **可能原因**

     （1）证书主题顺序不正确 或者 生成应用签名证书时“-issuerKeyAlias”参数填写错误

     （2）profile.json中type值与bundle_info中的key值不对应 "type": "debug"对应"development-certificate"，"type": "release"对应"distribution-certificate"

   - **解决办法**

     （1）检查证书主题顺序是否正确，顺序须为C、O、OU、CN

     （2）检查bundle.json文件配置信息

4. 对应用包进行签名时提示签名错误。

   - **现象描述**

     （1）执行命令后，报错提示：ERROR - PROVISION_INVALID, code: 0. Details: Require build type must be debug or release

     （2）执行命令后，报错提示：ERROR - ZIP_ERROR, code: -111. Details: zip init failed
     
     （3）执行命令后，报错提示：ERROR - SIGN_ERROR, code: -105. Details: No certificates configured for sign

   - **可能原因**

     （1）profile文件并没有被签名(没有生成p7b文件),在进行hap签名之前profile文件里的不存在"type"键值信息

     （2）输入的zip包超过了4G，压缩文件格式发生变化，导致解压错误

     （3）签名使用的密钥和实体证书不匹配。

   - **解决办法**

     （1）当app签名时使用未签名的profile文件对hap包进行签名之前，在profile.json文件中添加"type"键，值对应debug或者release

     （2）通过资源文件拆分、分包等方式降低hap包大小，最大不超过4G

     （3）检查keyAlias密钥是否使用正确；检查appCertFile是否使用正确，确保密钥和证书匹配

5. 安装hap包失败。

   - **现象描述**

     （1）使用release或debug类型的json文件签名安装hap包失败，报错提示：device type is not supports

     （2）使用debug类型的json文件安装hap包失败，报错提示：verify pkcs7 info falied

     （3）使用低版本的openharmony系统安装hap包失败，报错提示：install sign info inconsistent

     （4）已签名的hap安装报错提示：signature verification failed due to not trusted app source.

   - **可能原因**

     （1）openharmmony系统的配置文件不支持该app包的设备类型

     （2）debug类型的json文件中device-ids中没有你的设备udid

     （3）安装了相同包名的hap包

     （4）debug或者release类型json文件中的证书不是受信的证书

   - **解决办法**

     （1）使用 `hdc shell param get const.product.devicetype` 查看系统支持的设备类型，根据设备类型来替换hap包类型

     （2）使用 `hdc shell bm get --udid` 获取设备的设备udid，并将获取的udid加入debug类型json文件中device-ids项中

     （3）使用 `bm uninstall -n + 包名` 卸载原来安装的同包名hap包

     （4）检查是否使用了错误的json文件
