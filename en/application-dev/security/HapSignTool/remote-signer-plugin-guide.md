# HAP Remote Signing Plugin Development

<!--Kit: Common-->
<!--Subsystem: Security-->
<!--Owner: @scuteehuangjun-->
<!--Designer: @scuteehuangjun; @liuchibin-->
<!--Tester: @wwrongs-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=dcde939651beeae72b0926bd071ad604aaaec4f0 translatedAt=2026-08-17T10:41:41.068Z pushedAt=2026-08-17T10:50:45.429Z -->

## Overview

The HAP signing tool supports two modes: local signing and remote signing.

**Local signing mode**: The signing key is stored in a local KeyStore file, which you can use directly. However, enterprise app development typically requires stricter key management policies. For example, an enterprise may want to centrally manage all app signing keys to avoid the security risk of keys being scattered across individual developers' computers.

**Remote signing mode**: A Java plugin that implements the `ISigner` API sends signing requests to a remote signing service. The private key is stored in the hardware security module (HSM) of the remote service, which performs the actual signing operation. This approach preserves the familiar usage of the HAP signing tool while enabling centralized key management and security protection.

## Basic Concepts

Before using the remote signing plugin, you should understand the following basic concepts:

- **[ISigner API](#signing-api)**

  An API that all remote signing plugins must implement. It defines the core methods for signing operations. By implementing this API, a plugin integrates its custom signing logic into the HAP signing tool.

- **Plugin JAR**

  A packaged plugin file that contains the plugin implementation classes and configuration file. The HAP signing tool dynamically loads the classes in the JAR file through a class loader.

- **signer.properties**

  The configuration file of the plugin, which must be located in the root directory of the JAR file. The configuration file defines the mapping between APIs and their implementation classes.

## Working Principles

**Remote Signing Plugin Workflow**

When the HAP signing tool detects that the `mode` parameter value is `remoteSign` and the `signerPlugin` parameter is specified, the plugin loading process is triggered.

1. **Create a class loader**: Use `URLClassLoader` to create a class loader for the plugin JAR, with the parent class loader being the HAP signing tool's class loader.

2. **Read the configuration file**: Read the `signer.properties` configuration file from the class loader to obtain the mapping between APIs and implementation classes.

3. **Load and instantiate the class**: Load the plugin implementation class through reflection, and call the constructor that accepts `Map<String, Object>` parameters to create an instance.

4. **Verify the API**: Verify that the created object implements the `ISigner` API to ensure the validity of the plugin.

5. **Call the signing method**: Call the signing method of the plugin to perform the signing operation.

## Constraints

- The remote signing plugin supports only the `remoteSign` mode and does not support the `localSign` mode.

- The plugin must implement all methods of the `ISigner` API, and the implementation class must have the `public` modifier.

- The plugin JAR must contain the `signer.properties` configuration file.

## Available APIs

### Signing API

```java
package com.ohos.hapsigntool.signer;

import java.security.cert.X509CRL;
import java.security.cert.X509Certificate;
import java.security.spec.AlgorithmParameterSpec;
import java.util.List;

/**
 * Signer interface.
 * All remote signing plugins must implement this interface.
 */
public interface ISigner {
    /**
     * Performs the signing operation.
     *
     * @param data          Data to be signed.
     * @param signAlg       Signing algorithm (for example, "SHA256withECDSA").
     * @param parameterSpec Algorithm parameters (usually null).
     * @return Byte array after signing.
     */
    byte[] getSignature(byte[] data, String signAlg, AlgorithmParameterSpec parameterSpec);

    /**
     * Obtains the certificate revocation list.
     *
     * @return CRL list.
     */
    List<X509CRL> getCrls();

    /**
     * Obtains the certificate chain.
     *
     * @return Certificate chain.
     */
    List<X509Certificate> getCertificates();
}
```

## Environment Setup

| Component | Version Requirement | Purpose |
| ----------- | ----------- | ---------------- |
| JDK         | 1.8+       | Java development environment |
| Maven       | 3.6+        | Project build tool |
| HAP signing tool | 4.0.0+ | Plugin loading and signing test |

**Obtaining the HAP Signing Tool**

- [Download from the signing tool repository](https://gitcode.com/openharmony/developtools_hapsigner/blob/master/dist/hap-sign-tool.jar).

- Obtain via the SDK. The signing tool path is: `${SDK installation directory}/toolchains/lib/hap-sign-tool.jar`.

## How to Develop

1. Create the plugin project.

    Create a Maven project with the following directory structure:

    ```log
    my-remote-signer-plugin/
    ├── pom.xml
    ├── lib
    |   └── hap-sign-tool.jar
    └── src/
        └── main/
            ├── java/
            │   └── com/
            │       └── example/
            │           └── MyRemoteSigner.java
            └── resources/
                └── signer.properties
    ```

2. Configure the **pom.xml** file.

    Add the HAP signing tool library dependency and related dependencies in the pom.xml file:

    ```xml
    <?xml version="1.0" encoding="UTF-8"?>
    <project xmlns="http://maven.apache.org/POM/4.0.0"
             xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
             xsi:schemaLocation="http://maven.apache.org/POM/4.0.0
             http://maven.apache.org/xsd/maven-4.0.0.xsd">
    
        <modelVersion>4.0.0</modelVersion>
        
        <groupId>com.example</groupId>
        <artifactId>my-remote-signer-plugin</artifactId>
        <version>1.0.0</version>
        <packaging>jar</packaging>
        
        <properties>
            <maven.compiler.source>1.8</maven.compiler.source>
            <maven.compiler.target>1.8</maven.compiler.target>
            <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
        </properties>
        
        <dependencies>
            <dependency>
                <groupId>com.ohos</groupId>
                <artifactId>hap-sign-tool</artifactId>
                <version>4.0</version>
                <scope>system</scope>
                <systemPath>${project.basedir}/lib/hap-sign-tool.jar</systemPath>
            </dependency>
        </dependencies>
    </project>
    ```

3. Create the **signer.properties** configuration file.

    Create the `signer.properties` file in the `src/main/resources/` directory:

    ```properties
    com.ohos.hapsigntool.signer.ISigner=com.example.MyRemoteSigner
    ```

4. Implementing the **ISigner** API.

    Create the `MyRemoteSigner.java` class and implement the `ISigner` API:

    ```java
    package com.example;

    import com.ohos.hapsigntool.error.CustomException;
    import com.ohos.hapsigntool.error.ERROR;
    import com.ohos.hapsigntool.signer.ISigner;

    import java.security.cert.X509CRL;
    import java.security.cert.X509Certificate;
    import java.security.spec.AlgorithmParameterSpec;
    import java.util.Collections;
    import java.util.List;
    import java.util.Map;

    public class MyRemoteSigner implements ISigner {
        private final Map<String, Object> params;

        public MyRemoteSigner(Map<String, Object> params) {
            this.params = params;
        }

        @Override
        public byte[] getSignature(byte[] data, String signAlg, AlgorithmParameterSpec parameterSpec) {
            try {
                // Obtain the keyAlias command line parameter.
                String keyAlias = String.valueOf(params.get("keyAlias"));
                // Here you can send the data to be signed and the signing algorithm to the server, where the private key corresponding to the certificate is used to sign the data and return the signature result.
                byte[] signature = new byte[0];
                return signature;
            } catch (Exception e) {
                // If signing fails, throw an exception. The HAP signing tool catches this exception and aborts the signing process.
                CustomException.throwException(ERROR.SIGN_ERROR, "remote sign failed, msg: " + e.getMessage());
                return null;
            }
        }

        @Override
        public List<X509CRL> getCrls() {
            return Collections.emptyList();
        }

        @Override
        public List<X509Certificate> getCertificates() {
            return Collections.emptyList();
        }
    }
    ```

5. Package the plugin JAR.

    Use Maven to package the plugin:

    ```bash
    mvn clean package
    ```

    After successful packaging, the plugin JAR file is generated in the `target/` directory.

## Plugin Usage

1. Use the plugin.

    ```shell
    java -jar hap-sign-tool.jar sign-app \
        -mode remoteSign \
        -keyAlias remoteKeyAlias \
        -signerPlugin my-remote-signer-plugin-1.0.0.jar \
        -inFile input.hap \
        -outFile output.hap \
        -appCertFile app-cert-chain.cer \
        -profileFile provision-profile.p7b \
        -signAlg SHA256withECDSA
    ```

2. View parameter description.

    | Name | Description |
    | --- | --- |
    | -mode | Signing mode. The following values are available:<br>localSign: local signing mode.<br>remoteSign: remote signing mode. |
    | -keyAlias | Key alias used for signing. |
    | -profileFile | Path of the profile file corresponding to the signing certificate. Both absolute and relative paths are supported. |
    | -appCertFile | Path of the signing certificate file. Both absolute and relative paths are supported. |
    | -inFile | Path of the HAP package file to be signed. Both absolute and relative paths are supported. |
    | -outFile | Path of the signed HAP package file. Both absolute and relative paths are supported. |
    | -signAlg | Signing algorithm. Supported algorithms: SHA256withECDSA and SHA384withECDSA. |
    | -signerPlugin | Path of the remoteSign plugin. Both absolute and relative paths are supported. |

## FAQs

### Failed to Load the Plugin

**Symptom**

```text
[WARN] lost parameter signerPlugin
[WARN] can not find signerPlugin or not a file by param signerPlugin = xxx.jar
```

**Possible Causes**

1. The `-signerPlugin` parameter is not specified.

2. The plugin JAR file does not exist.

**Solution**

1. Ensure that the correct `-signerPlugin` parameter is passed.

2. Verify that the JAR file exists.

### signer.properties Not Found

**Symptom**

```text
[WARN] can not find entry signer.properties in xxx.jar
```

**Possible Causes**

The `signer.properties` file is not in the JAR root directory.

**Solution**

Verify that `signer.properties` is in the JAR root directory. To check, run `jar tf plugin.jar` and inspect the JAR file entries to ensure that `signer.properties` is included.

### Class Loading Failure

**Symptom**

```text
[WARN] load remote signer from xxx.jar failed, msg: ClassNotFoundException
```

**Possible Causes**

1. The class name in `signer.properties` is incorrect.

2. The class is missing the `public` modifier.

3. The constructor signature does not match.

**Solution**

1. Check whether the class name in `signer.properties` is correct.

2. Verify that the class has the `public` modifier.

3. Verify that the class has a constructor that accepts `Map<String, Object>`.