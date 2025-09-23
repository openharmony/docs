# 使用系统预置CA证书校验证书链

<!--Kit: Device Certificate Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

从API 20开始，支持使用系统预置CA证书校验证书链。

以校验证书链为例，完成证书链对象的创建，使用系统预置CA证书对证书链进行校验。

## 开发步骤

1. 导入[证书算法库框架模块](../../reference/apis-device-certificate-kit/js-apis-cert.md)。

   ```ts
   import { cert } from '@kit.DeviceCertificateKit';
   ```

2. 基于已有的证书数据，调用[cert.createX509CertChain](../../reference/apis-device-certificate-kit/js-apis-cert.md#certcreatex509certchain11)创建X509证书链对象，并返回结果。

3. 调用[x509CertChain.validate](../../reference/apis-device-certificate-kit/js-apis-cert.md#validate11)设置校验参数trustSystemCa为true，使用系统预置CA证书校验证书链并返回结果。

```ts
import { cert } from '@kit.DeviceCertificateKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { util } from '@kit.ArkTS';

let certChainData = "-----BEGIN CERTIFICATE-----\r\n" +
"MIIJ7DCCCNSgAwIBAgIMTkADpl62gfh/S9jrMA0GCSqGSIb3DQEBCwUAMFAxCzAJ\r\n" +
"BgNVBAYTAkJFMRkwFwYDVQQKExBHbG9iYWxTaWduIG52LXNhMSYwJAYDVQQDEx1H\r\n" +
"bG9iYWxTaWduIFJTQSBPViBTU0wgQ0EgMjAxODAeFw0yNDA3MDgwMTQxMDJaFw0y\r\n" +
"NTA4MDkwMTQxMDFaMIGAMQswCQYDVQQGEwJDTjEQMA4GA1UECBMHYmVpamluZzEQ\r\n" +
"MA4GA1UEBxMHYmVpamluZzE5MDcGA1UEChMwQmVpamluZyBCYWlkdSBOZXRjb20g\r\n" +
"U2NpZW5jZSBUZWNobm9sb2d5IENvLiwgTHRkMRIwEAYDVQQDEwliYWlkdS5jb20w\r\n" +
"ggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC1wFMskJ2dseOqoHptNwot\r\n" +
"FOhdBERsZ4VQnRNKXEEXMQEfgbNtScQ+C/Z+IpRAt1EObhYlifn74kt2nTsCQLng\r\n" +
"jfQkRVBuO/6PNGKdlCYGBeGqAL7xR+LOyHnpH9mwCBJc+WVt2zYM9I1clpXCJa+I\r\n" +
"tsq6qpb1AGoQxRDZ2n4K8Gd61wgNCPHDHc/Lk9NPJoUBMvYWvEe5lKhHsJtWtHe4\r\n" +
"QC3y58Vi+r5R0PWn2hyTBr9fCo58p/stDiRqp9Irtmi95YhwkNkmgwpMB8RhcGoN\r\n" +
"h+Uw5TkPZVj4AVaoPT1ED/GMKZev0+ypmp0+nmjVg2x7yUfLUfp3X7oBdI4TS2hv\r\n" +
"AgMBAAGjggaTMIIGjzAOBgNVHQ8BAf8EBAMCBaAwDAYDVR0TAQH/BAIwADCBjgYI\r\n" +
"KwYBBQUHAQEEgYEwfzBEBggrBgEFBQcwAoY4aHR0cDovL3NlY3VyZS5nbG9iYWxz\r\n" +
"aWduLmNvbS9jYWNlcnQvZ3Nyc2FvdnNzbGNhMjAxOC5jcnQwNwYIKwYBBQUHMAGG\r\n" +
"K2h0dHA6Ly9vY3NwLmdsb2JhbHNpZ24uY29tL2dzcnNhb3Zzc2xjYTIwMTgwVgYD\r\n" +
"VR0gBE8wTTBBBgkrBgEEAaAyARQwNDAyBggrBgEFBQcCARYmaHR0cHM6Ly93d3cu\r\n" +
"Z2xvYmFsc2lnbi5jb20vcmVwb3NpdG9yeS8wCAYGZ4EMAQICMD8GA1UdHwQ4MDYw\r\n" +
"NKAyoDCGLmh0dHA6Ly9jcmwuZ2xvYmFsc2lnbi5jb20vZ3Nyc2FvdnNzbGNhMjAx\r\n" +
"OC5jcmwwggNhBgNVHREEggNYMIIDVIIJYmFpZHUuY29tggxiYWlmdWJhby5jb22C\r\n" +
"DHd3dy5iYWlkdS5jboIQd3d3LmJhaWR1LmNvbS5jboIPbWN0LnkubnVvbWkuY29t\r\n" +
"ggthcG9sbG8uYXV0b4IGZHd6LmNuggsqLmJhaWR1LmNvbYIOKi5iYWlmdWJhby5j\r\n" +
"b22CESouYmFpZHVzdGF0aWMuY29tgg4qLmJkc3RhdGljLmNvbYILKi5iZGltZy5j\r\n" +
"b22CDCouaGFvMTIzLmNvbYILKi5udW9taS5jb22CDSouY2h1YW5rZS5jb22CDSou\r\n" +
"dHJ1c3Rnby5jb22CDyouYmNlLmJhaWR1LmNvbYIQKi5leXVuLmJhaWR1LmNvbYIP\r\n" +
"Ki5tYXAuYmFpZHUuY29tgg8qLm1iZC5iYWlkdS5jb22CESouZmFueWkuYmFpZHUu\r\n" +
"Y29tgg4qLmJhaWR1YmNlLmNvbYIMKi5taXBjZG4uY29tghAqLm5ld3MuYmFpZHUu\r\n" +
"Y29tgg4qLmJhaWR1cGNzLmNvbYIMKi5haXBhZ2UuY29tggsqLmFpcGFnZS5jboIN\r\n" +
"Ki5iY2Vob3N0LmNvbYIQKi5zYWZlLmJhaWR1LmNvbYIOKi5pbS5iYWlkdS5jb22C\r\n" +
"EiouYmFpZHVjb250ZW50LmNvbYILKi5kbG5lbC5jb22CCyouZGxuZWwub3JnghIq\r\n" +
"LmR1ZXJvcy5iYWlkdS5jb22CDiouc3UuYmFpZHUuY29tgggqLjkxLmNvbYISKi5o\r\n" +
"YW8xMjMuYmFpZHUuY29tgg0qLmFwb2xsby5hdXRvghIqLnh1ZXNodS5iYWlkdS5j\r\n" +
"b22CESouYmouYmFpZHViY2UuY29tghEqLmd6LmJhaWR1YmNlLmNvbYIOKi5zbWFy\r\n" +
"dGFwcHMuY26CDSouYmR0anJjdi5jb22CDCouaGFvMjIyLmNvbYIMKi5oYW9rYW4u\r\n" +
"Y29tgg8qLnBhZS5iYWlkdS5jb22CESoudmQuYmRzdGF0aWMuY29tghEqLmNsb3Vk\r\n" +
"LmJhaWR1LmNvbYISY2xpY2suaG0uYmFpZHUuY29tghBsb2cuaG0uYmFpZHUuY29t\r\n" +
"ghBjbS5wb3MuYmFpZHUuY29tghB3bi5wb3MuYmFpZHUuY29tghR1cGRhdGUucGFu\r\n" +
"LmJhaWR1LmNvbTAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwHwYDVR0j\r\n" +
"BBgwFoAU+O9/8s14Z6jeb48kjYjxhwMCs+swHQYDVR0OBBYEFK3KAFTK2OWUto+D\r\n" +
"2ieAKE5ZJDsYMIIBfwYKKwYBBAHWeQIEAgSCAW8EggFrAWkAdgCvGBoo1oyj4KmK\r\n" +
"TJxnqwn4u7wiuq68sTijoZ3T+bYDDQAAAZCQAGzzAAAEAwBHMEUCIFwF5Jc+zyIF\r\n" +
"Gnpxchz9fY1qzlqg/oVrs2nnuxcpBuuIAiEAu3scD6u51VOP/9aMSqR2yKHZLbHw\r\n" +
"Fos9U7AzSdLIZa8AdgAS8U40vVNyTIQGGcOPP3oT+Oe1YoeInG0wBYTr5YYmOgAA\r\n" +
"AZCQAG3iAAAEAwBHMEUCIBBYQ6NP7VUDgfktWRg5QxT23QAbTqYovtV2D9O8Qc0T\r\n" +
"AiEA2P7+44EvQ5adwL1y56oyxv/m+Gujeia7wpo7+Xbhv6MAdwAN4fIwK9MNwUBi\r\n" +
"EgnqVS78R3R8sdfpMO8OQh60fk6qNAAAAZCQAGy+AAAEAwBIMEYCIQDU7Hxtx4c9\r\n" +
"p9Jd+cr+DCMtyRYSc0b8cktCcbMmtDE9ygIhAIpJd4yb7jtxnaEC8oLWDushbK1v\r\n" +
"0BIuZu6YrQvsf1nQMA0GCSqGSIb3DQEBCwUAA4IBAQCh9DfewC012/+fHZpmSpCn\r\n" +
"y+h3/+ClAZ8cJVO+LCmYz9r6bkyhcFquJ5qUpyoW8AYtU0oUFlqH6zLIyujW+7lq\r\n" +
"wFxB6NsXKKdwBKmMbmnZr2Fca5f+TtwD/GDJgG/egr7fI1u8194j9KEl8cK8Fujm\r\n" +
"+UsoWklEzd1It9xkLazJR/6SwbhSR4k610pvj8rQrS4wAewuYFDaDOfqsHtDIsx1\r\n" +
"tZfIfoB/O1wGWZQJU2M9wC8uYq0jQ2Q0MQJXuyJz04MFiGrPAS1Uk8mWd8M+3p65\r\n" +
"Xy4iAf8uWzs1M+fcwBE8BNBghkQgE+FSUsldm+5ZBCazU0joJswzldWisXMLTagI\r\n" +
"-----END CERTIFICATE-----\r\n" +
"-----BEGIN CERTIFICATE-----\r\n" +
"MIIETjCCAzagAwIBAgINAe5fIh38YjvUMzqFVzANBgkqhkiG9w0BAQsFADBMMSAw\r\n" +
"HgYDVQQLExdHbG9iYWxTaWduIFJvb3QgQ0EgLSBSMzETMBEGA1UEChMKR2xvYmFs\r\n" +
"U2lnbjETMBEGA1UEAxMKR2xvYmFsU2lnbjAeFw0xODExMjEwMDAwMDBaFw0yODEx\r\n" +
"MjEwMDAwMDBaMFAxCzAJBgNVBAYTAkJFMRkwFwYDVQQKExBHbG9iYWxTaWduIG52\r\n" +
"LXNhMSYwJAYDVQQDEx1HbG9iYWxTaWduIFJTQSBPViBTU0wgQ0EgMjAxODCCASIw\r\n" +
"DQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKdaydUMGCEAI9WXD+uu3Vxoa2uP\r\n" +
"UGATeoHLl+6OimGUSyZ59gSnKvuk2la77qCk8HuKf1UfR5NhDW5xUTolJAgvjOH3\r\n" +
"idaSz6+zpz8w7bXfIa7+9UQX/dhj2S/TgVprX9NHsKzyqzskeU8fxy7quRU6fBhM\r\n" +
"abO1IFkJXinDY+YuRluqlJBJDrnw9UqhCS98NE3QvADFBlV5Bs6i0BDxSEPouVq1\r\n" +
"lVW9MdIbPYa+oewNEtssmSStR8JvA+Z6cLVwzM0nLKWMjsIYPJLJLnNvBhBWk0Cq\r\n" +
"o8VS++XFBdZpaFwGue5RieGKDkFNm5KQConpFmvv73W+eka440eKHRwup08CAwEA\r\n" +
"AaOCASkwggElMA4GA1UdDwEB/wQEAwIBhjASBgNVHRMBAf8ECDAGAQH/AgEAMB0G\r\n" +
"A1UdDgQWBBT473/yzXhnqN5vjySNiPGHAwKz6zAfBgNVHSMEGDAWgBSP8Et/qC5F\r\n" +
"JK5NUPpjmove4t0bvDA+BggrBgEFBQcBAQQyMDAwLgYIKwYBBQUHMAGGImh0dHA6\r\n" +
"Ly9vY3NwMi5nbG9iYWxzaWduLmNvbS9yb290cjMwNgYDVR0fBC8wLTAroCmgJ4Yl\r\n" +
"aHR0cDovL2NybC5nbG9iYWxzaWduLmNvbS9yb290LXIzLmNybDBHBgNVHSAEQDA+\r\n" +
"MDwGBFUdIAAwNDAyBggrBgEFBQcCARYmaHR0cHM6Ly93d3cuZ2xvYmFsc2lnbi5j\r\n" +
"b20vcmVwb3NpdG9yeS8wDQYJKoZIhvcNAQELBQADggEBAJmQyC1fQorUC2bbmANz\r\n" +
"EdSIhlIoU4r7rd/9c446ZwTbw1MUcBQJfMPg+NccmBqixD7b6QDjynCy8SIwIVbb\r\n" +
"0615XoFYC20UgDX1b10d65pHBf9ZjQCxQNqQmJYaumxtf4z1s4DfjGRzNpZ5eWl0\r\n" +
"6r/4ngGPoJVpjemEuunl1Ig423g7mNA2eymw0lIYkN5SQwCuaifIFJ6GlazhgDEw\r\n" +
"fpolu4usBCOmmQDo8dIm7A9+O4orkjgTHY+GzYZSR+Y0fFukAj6KYXwidlNalFMz\r\n" +
"hriSqHKvoflShx8xpfywgVcvzfTO3PYkz6fiNJBonf6q8amaEsybwMbDqKWwIX7e\r\n" +
"SPY=\r\n" +
"-----END CERTIFICATE-----\r\n" +
"-----BEGIN CERTIFICATE-----\r\n" +
"MIIDXzCCAkegAwIBAgILBAAAAAABIVhTCKIwDQYJKoZIhvcNAQELBQAwTDEgMB4G\r\n" +
"A1UECxMXR2xvYmFsU2lnbiBSb290IENBIC0gUjMxEzARBgNVBAoTCkdsb2JhbFNp\r\n" +
"Z24xEzARBgNVBAMTCkdsb2JhbFNpZ24wHhcNMDkwMzE4MTAwMDAwWhcNMjkwMzE4\r\n" +
"MTAwMDAwWjBMMSAwHgYDVQQLExdHbG9iYWxTaWduIFJvb3QgQ0EgLSBSMzETMBEG\r\n" +
"A1UEChMKR2xvYmFsU2lnbjETMBEGA1UEAxMKR2xvYmFsU2lnbjCCASIwDQYJKoZI\r\n" +
"hvcNAQEBBQADggEPADCCAQoCggEBAMwldpB5BngiFvXAg7aEyiie/QV2EcWtiHL8\r\n" +
"RgJDx7KKnQRfJMsuS+FggkbhUqsMgUdwbN1k0ev1LKMPgj0MK66X17YUhhB5uzsT\r\n" +
"gHeMCOFJ0mpiLx9e+pZo34knlTifBtc+ycsmWQ1z3rDI6SYOgxXG71uL0gRgykmm\r\n" +
"KPZpO/bLyCiR5Z2KYVc3rHQU3HTgOu5yLy6c+9C7v/U9AOEGM+iCK65TpjoWc4zd\r\n" +
"QQ4gOsC0p6Hpsk+QLjJg6VfLuQSSaGjlOCZgdbKfd/+RFO+uIEn8rUAVSNECMWEZ\r\n" +
"XriX7613t2Saer9fwRPvm2L7DWzgVGkWqQPabumDk3F2xmmFghcCAwEAAaNCMEAw\r\n" +
"DgYDVR0PAQH/BAQDAgEGMA8GA1UdEwEB/wQFMAMBAf8wHQYDVR0OBBYEFI/wS3+o\r\n" +
"LkUkrk1Q+mOai97i3Ru8MA0GCSqGSIb3DQEBCwUAA4IBAQBLQNvAUKr+yAzv95ZU\r\n" +
"RUm7lgAJQayzE4aGKAczymvmdLm6AC2upArT9fHxD4q/c2dKg8dEe3jgr25sbwMp\r\n" +
"jjM5RcOO5LlXbKr8EpbsU8Yt5CRsuZRj+9xTaGdWPoO4zzUhw8lo/s7awlOqzJCK\r\n" +
"6fBdRoyV3XpYKBovHd7NADdBj+1EbddTKJd+82cEHhXXipa0095MJ6RMG3NzdvQX\r\n" +
"mcIfeg7jLQitChws/zyrVQ4PkX4268NXSb7hLi18YIvDQVETI53O9zJrlAGomecs\r\n" +
"Mx86OyXShkDOOyyGeMlhLxS67ttVb9+E7gUJTb0o2HLO02JQZR7rkpeDMdmztcpH\r\n" +
"WD9f\r\n" +
"-----END CERTIFICATE-----\r\n";

async function sample() {
  let textEncoder = new util.TextEncoder();
  // 证书链二进制数据，需业务自行赋值。
  const encodingBlob: cert.EncodingBlob = {
    data: textEncoder.encodeInto(certChainData),
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM、FORMAT_DER和FORMAT_PKCS7。
    encodingFormat: cert.EncodingFormat.FORMAT_PEM
  };
  let x509CertChain: cert.X509CertChain = {} as cert.X509CertChain;
  try {
    x509CertChain = await cert.createX509CertChain(encodingBlob);
  } catch (err) {
    let e: BusinessError = err as BusinessError;
    console.error(`createX509CertChain failed, errCode: ${e.code}, errMsg: ${e.message}`);
  }

  // 证书链校验数据，需业务自行赋值。
  const param: cert.CertChainValidationParameters = {
    date: '20250623163000Z',
    trustAnchors: [{}],
    trustSystemCa: true,
  };
  try {
    const validationRes = await x509CertChain.validate(param);
    console.info('X509CertChain validate success');
  } catch (err) {
    console.error('X509CertChain validate failed');
  }
}
```
