# AuthSolution


## **概述**

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [userId](#userid) | 用户ID。 | 
| [authTrustLevel](#authtrustlevel) | 认证结果可信等级。 | 
| [authType](#authtype) | 用户认证凭据类型AuthType}。 | 
| [executorId](#executorid) | 既定用户认证凭据类型的执行器ID。 | 
| [challenge](#challenge) | 挑战值，用于签发认证令牌。 | 


## **详细描述**

认证方案。

**Since：**

3.2

**Version：**

1.0


## **类成员变量说明**


### authTrustLevel

  
```
unsigned int AuthSolution::authTrustLevel
```

**描述：**

认证结果可信等级。


### authType

  
```
enum AuthType AuthSolution::authType
```

**描述：**

用户认证凭据类型AuthType}。


### challenge

  
```
unsigned char [] AuthSolution::challenge
```

**描述：**

挑战值，用于签发认证令牌。


### executorId

  
```
unsigned int AuthSolution::executorId
```

**描述：**

既定用户认证凭据类型的执行器ID。


### userId

  
```
int AuthSolution::userId
```

**描述：**

用户ID。
