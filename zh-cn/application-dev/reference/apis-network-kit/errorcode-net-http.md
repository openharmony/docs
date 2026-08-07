# HTTP错误码

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码](../errorcode-universal.md)说明文档。

## 2300001 不支持的协议

**错误信息**

Unsupported protocol.

**错误描述**

协议不支持。

**可能原因**

传入的协议版本，服务器不支持。

**处理步骤**

请检查传入的协议版本是否合理，排查服务器实现。

## 2300003 URL格式错误

**错误信息**

Invalid URL format or missing URL.

**错误描述**

URL格式错误或URL缺失。

**可能原因**

1. 传入的URL含有非法字符或格式不符合规范。

2. URL为空或未传入。

**处理步骤**

1. 检查传入的URL格式是否正确，确认URL不含有非法字符。

2. 确认URL参数不为空。

3. 可查看日志关键词"HttpClient CURLcode result 3"定位该错误。

## 2300005 代理服务器域名解析失败

**错误信息**

Failed to resolve the proxy name.

**错误描述**

代理服务器的域名无法解析。

**可能原因**

服务器的URL不正确。

**处理步骤**

排查代理服务器的URL是否正确。

## 2300006 域名解析失败

**错误信息**

Failed to resolve the host name.

**错误描述**

服务器的域名无法解析。

**可能原因**

1. 传入的服务器域名不正确或不存在。

2. 网络不通畅或DNS服务器无法访问。

3. 本地DNS缓存异常。

**处理步骤**

1. 检查传入的URL中域名是否正确。

2. 检查网络连接状态，确保网络可用。

3. 尝试使用其他DNS服务器或刷新DNS缓存。

4. 可查看日志关键词"HttpClient CURLcode result 6"定位该错误。

## 2300007 无法连接到服务器

**错误信息**

Failed to connect to the server.

**错误描述**

无法建立与服务器的连接。

**可能原因**

1. 服务器地址或端口不正确。

2. 服务器未启动或无法响应。

3. 网络连接被防火墙阻止。

4. 连接超时。

**处理步骤**

1. 检查服务器地址和端口是否正确。

2. 确认服务器是否正常运行。

3. 检查防火墙配置是否允许该连接。

4. 检查网络连通性。

5. 可查看日志关键词"HttpClient CURLcode result 7"定位该错误。

## 2300008 服务器返回非法数据

**错误信息**

Invalid server response.

**错误描述**

服务器返回了无法解析的非法数据。

**可能原因**

1. 服务器返回的数据不符合HTTP协议格式。
2. 代理服务器配置错误，代理地址指向了非HTTP代理服务。
3. 请求的端口上运行的不是HTTP/HTTPS服务。
4. 服务器或代理未按协议规范返回数据。

**处理步骤**

1. 排查服务器实现，确认返回的是合法HTTP格式数据。
2. 如果使用了代理，检查代理配置是否正确，确认代理地址指向的是HTTP代理服务。
3. 确认请求的目标端口是否运行HTTP/HTTPS服务。

## 2300009 拒绝对远程资源的访问

**错误信息**

Access to the remote resource denied.

**错误描述**

拒绝对远程资源的访问。

**可能原因**

指定的内容被服务器拒绝访问。

**处理步骤**

排查请求内容。

## 2300016 HTTP2帧层错误

**错误信息**

Error in the HTTP2 framing layer.

**错误描述**

HTTP2层级的错误。

**可能原因**

服务器不支持HTTP2。

**处理步骤**

抓包分析、排查服务器是否支持HTTP2。

## 2300018 服务器返回数据不完整

**错误信息**

Transferred a partial file.

**错误描述**

服务器返回的数据不完整。

**可能原因**

1. 服务器在传输过程中中断连接。

2. 网络不稳定导致数据传输中断。

3. 服务器返回的数据大小与声明不匹配。

**处理步骤**

1. 检查服务器实现是否正常。

2. 确认网络连接稳定性。

3. 检查是否设置了range请求导致部分传输。

4. 可查看日志关键词"HttpClient CURLcode result 18"定位该错误。

## 2300023 向磁盘/应用程序写入接收数据失败

**错误信息**

Failed to write the received data to the disk or application.

**错误描述**

向磁盘或应用程序写入接收数据失败。

**可能原因**

1. 应用没有写文件权限。

2. 调用[request](./js-apis-http.md#request)接口下载超过大小限制（API version 23之前限制为5MB，API version 23及之后的版本，限制为50MB），且未在[HttpRequestOptions](./js-apis-http.md#httprequestoptions)中设置maxLimit参数。

3. 磁盘空间不足。

4. 上一次请求数据未接收完毕便调用[destroy](./js-apis-http.md#destroy)销毁导致接收数据不完整。

**处理步骤**

1. 检查应用是否具有写文件权限。

2. 若需下载超过5MB的数据，请在[HttpRequestOptions](./js-apis-http.md#httprequestoptions)中设置合适的maxLimit参数，或改用[requestInStream](./js-apis-http.md#requestinstream10)接口发起流式请求。

3. 检查磁盘空间是否充足。

4. 确保请求完成后再调用[destroy](./js-apis-http.md#destroy)方法。

5. 可查看日志关键词"HttpClient CURLcode result 23"定位该错误。

## 2300025 上传失败

**错误信息**

Upload failed.

**错误描述**

上传失败。

**可能原因**

文件过大或者网络问题，对于FTP，服务器通常会拒绝STOR命令，错误缓冲区通常包含服务器的解释。

**处理步骤**

排查文件大小及网络状况。

## 2300026 从文件/应用程序中打开/读取本地数据失败

**错误信息**

Failed to open or read local data from the file or application.

**错误描述**

从文件/应用程序中打开/读取本地数据失败。

**可能原因**

应用没有读文件权限。

**处理步骤**

排查应用权限。

## 2300027 内存不足

**错误信息**

Out of memory.

**错误描述**

内存不足。

**可能原因**

内存不足。

**处理步骤**

排查系统内存。

## 2300028 操作超时

**错误信息**

Operation timeout.

**错误描述**

操作超时。

**可能原因**

1. TCP连接超时（connectTimeout默认60000ms）。

2. 数据读写超时（readTimeout默认60000ms）。

3. 网络不稳定导致响应延迟。

4. 服务器负载过高，处理速度缓慢。

5. 调用[connection.addCustomDnsRule](js-apis-net-connection.md#connectionaddcustomdnsrule11)设置了自定义DNS规则，导致域名解析到过期或错误的IP地址，连接无法建立。

**处理步骤**

1. 检查网络连接状态，确认网络稳定。

2. 根据实际情况调整readTimeout或connectTimeout参数。

3. 排查服务器负载情况。

4. 检查是否通过[connection.addCustomDnsRule](js-apis-net-connection.md#connectionaddcustomdnsrule11)设置了自定义DNS规则，若设置的IP地址已过期或错误，调用[removeCustomDnsRule](js-apis-net-connection.md#connectionremovecustomdnsrule11)或[clearCustomDnsRules](js-apis-net-connection.md#connectionclearcustomdnsrules11)清除规则后重试。

5. 可查看日志关键词"HttpClient CURLcode result 28"定位该错误。

## 2300047 重定向次数达到最大值

**错误信息**

The number of redirections reaches the maximum allowed.

**错误描述**

重定向次数达到最大值。

**可能原因**

重定向次数过多。

**处理步骤**

排查服务器实现。

## 2300052 服务器没有返回内容

**错误信息**

The server returned nothing (no header or data).

**错误描述**

服务器没有返回内容。

**可能原因**

可能与服务器实现有关。

**处理步骤**

排查服务器实现。

## 2300055 发送网络数据失败

**错误信息**

Failed to send data to the peer.

**错误描述**

无法往对端发送数据，发送网络数据失败。

**可能原因**

网络问题。

**处理步骤**

排查网络。

## 2300056 接收网络数据失败

**错误信息**

Failed to receive data from the peer.

**错误描述**

无法从对端接收数据，接收网络数据失败。

**可能原因**

1. 网络连接中断或不稳定。

2. 服务器关闭了连接。

3. 对端发送数据过程中出现异常。

4. 调用[connection.addCustomDnsRule](js-apis-net-connection.md#connectionaddcustomdnsrule11)设置了自定义DNS规则，但规则中IP地址已失效，导致向错误的地址发送请求后无法接收响应。

**处理步骤**

1. 检查网络连接状态。

2. 确认服务器端是否正常运行。

3. 重新发起请求尝试。

4. 检查是否通过[connection.addCustomDnsRule](js-apis-net-connection.md#connectionaddcustomdnsrule11)设置了自定义DNS规则，若设置的IP地址已过期或错误，调用[removeCustomDnsRule](js-apis-net-connection.md#connectionremovecustomdnsrule11)或[clearCustomDnsRules](js-apis-net-connection.md#connectionclearcustomdnsrules11)清除规则后重试，确保域名解析到正确的IP地址。

5. 可查看日志关键词"HttpClient CURLcode result 56"定位该错误。

## 2300058 本地SSL证书错误

**错误信息**

Local SSL certificate error.

**错误描述**

本地SSL证书错误。

**可能原因**

SSL证书格式有错误。

**处理步骤**

检查SSL证书格式。

## 2300059 无法使用指定的加密算法

**错误信息**

The specified SSL cipher cannot be used.

**错误描述**

无法使用指定的加密算法。

**可能原因**

client和server协商的加密算法系统不支持。

**处理步骤**

抓包分析协商的算法。

## 2300060 远程服务器SSL证书或SSH密钥不正确

**错误信息**

Invalid SSL peer certificate or SSH remote key.

**错误描述**

远程服务器SSL证书或SSH密钥验证失败。

**可能原因**

1. 服务器证书过期。

2. 证书未被信任的CA签发。

3. 证书域名与请求域名不匹配。

4. 证书配置了SSL Pinning（certificatePinning）但公钥哈希值不匹配，日志提示"Specified pinned public key did not match"。

5. 证书链不完整。

**处理步骤**

1. 建议参考[tls客户端证书验证流程](../../network/http-request.md#tls客户端证书验证流程)自排查问题原因。

2. 若配置了certificatePinning，请检查公钥哈希值是否正确。

3. 检查服务器证书是否过期或域名是否匹配。

4. 可查看日志关键词"HttpClient CURLcode result 60"定位该错误。

## 2300061 无法识别或错误的HTTP编码格式

**错误信息**

Invalid HTTP encoding format.

**错误描述**

无法识别或错误的HTTP编码格式。

**可能原因**

HTTP编码格式不正确。

**处理步骤**

排查服务器实现。目前仅支持gzip编码。

## 2300063 超出最大文件大小

**错误信息**

Maximum file size exceeded.

**错误描述**

超出最大文件大小。

**可能原因**

下载的文件过大。

**处理步骤**

排查服务器实现。

## 2300070 服务器磁盘空间不足

**错误信息**

Remote disk full.

**错误描述**

服务器磁盘空间不足。

**可能原因**

服务器磁盘已满。

**处理步骤**

检查服务器磁盘空间。

## 2300073 服务器返回文件已存在

**错误信息**

Remote file already exists.

**错误描述**

服务器返回文件已存在。

**可能原因**

上传文件的时候，服务器返回文件已经存在。

**处理步骤**

排查服务器。

## 2300077 SSL CA证书不存在或没有访问权限

**错误信息**

The SSL CA certificate does not exist or is inaccessible.

**错误描述**

SSL CA证书不存在或没有访问权限。

**可能原因**

证书不存在或者没有访问权限。

**处理步骤**

检查证书是否存在或者有没有访问权限。

## 2300078 URL请求的文件不存在

**错误信息**

Remote file not found.

**错误描述**

URL请求的文件不存在。

**可能原因**

URL请求的文件不存在。

**处理步骤**

检查URL请求的文件是否存在。

## 2300094 身份校验失败

**错误信息**

Authentication error.

**错误描述**

身份校验失败。

**可能原因**

传入的校验身份的字段与服务器不匹配。

**处理步骤**

排查传入的校验身份的字段是否与服务器匹配。

## 2300997 明文HTTP被拦截

**错误信息**

Cleartext traffic not permitted.

**错误描述**

明文HTTP被拦截，不允许访问。

**可能原因**

应用配置network_config.json文件中设置为明文不允许。

**处理步骤**

排查network_config.json中cleartextTrafficPermitted字段配置。

## 2300998 不允许访问域名

**错误信息**

It is not allowed to access this domain.

**错误描述**

不允许访问此域名。

**可能原因**

1. 元服务应用未正确配置服务器域名。

2. 访问的域名不在已配置的白名单中。

3. 域名配置后尚未生效（配置生效需要等待一天以上）。

**处理步骤**

可参考配置[服务器域名文档](https://developer.huawei.com/consumer/cn/doc/atomic-guides/agc-help-harmonyos-server-domain)完成服务器域名相关配置。服务器域名配置后一般需要等待一天以上才会生效。

## 2300999 内部错误

**错误信息**

Internal error.

**错误描述**

HTTP模块内部错误，通常由底层网络库返回的未映射错误或其他内部异常引起。

1. **底层网络库未映射错误**：
   - HTTP错误码映射规则为2300000 + CURL错误码。当CURL返回的错误码未在映射表中定义时，统一返回2300999。
   - 例如：CURL错误码1映射为2300001，CURL错误码28映射为2300028。若CURL返回的错误码没有对应映射，则返回2300999。
   - **日志关键词**：`CURLcode result`（日志中会打印具体的CURL错误码数值）


2. **HTTP3协议问题**：
   - 使用HTTP3协议时，请求启动前存在其他配置错误。
   - **日志关键词**：`error_.GetErrorCode()=`，且请求协议为HTTP3


3. **全局拦截器校验失败**：
   - 全局请求拦截器校验未通过。
   - **日志关键词**：`GlobalRequestInterceptorCheck fail`、`GlobalRequestInterceptorCheck failed`

**处理步骤**

1. **针对底层网络库错误**：
   - 查看完整日志获取底层CURL错误码。
   - 参考[CURL错误码文档](https://curl.se/libcurl/c/libcurl-errors.html)了解具体错误含义。
   - 根据错误类型采取相应措施（网络连接、SSL证书、超时等）。

2. **针对HTTP3协议问题**：
   - 如果使用HTTP3协议，检查请求配置是否存在其他错误（如URL格式、权限等）。
   - 查看日志中的具体错误信息，优先解决该错误。
   - 考虑降级使用HTTP/2或HTTP/1.1协议。

3. **针对全局拦截器问题**：
   - 检查是否配置了全局HTTP拦截器。
   - 验证拦截器回调函数的实现是否正确。

4. **通用处理措施**：
   - 尝试重新创建HTTP请求对象，避免使用已失效的对象。
   - 检查内存使用情况，确保系统资源充足。
   - 如果问题持续，收集完整日志并提交问题报告，联系技术支持以获取帮助。
   - 简化请求配置，逐步排查是哪个配置项导致问题。
