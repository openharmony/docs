# HiSysEvent Error Codes

## 1120001 Invalid Event Domain

**Error Message**

Invalid event domain.

**Description**

This error code is reported if the **write** API is called to perform system event logging but the system ignores the logging operation because the input event domain name is invalid.

**Possible Causes**

1. The event domain name contains more than 16 characters.
2. The event domain name contains special characters.
3. The event domain name is empty.

**Solution**

Specify a valid event domain name.

## 1120002 Invalid Event Name

**Error Message**

Invalid event name.

**Description**

This error code is reported if the **write** API is called to perform system event logging but the system ignores the logging operation because the input event name is invalid.

**Possible Causes**

1. The event name contains more than 32 characters.
2. The event name contains special characters.
3. The event name is empty.

**Solution**

Check whether the event name is valid.

## 11200003 Environment Error

**Error Message**

Abnormal environment.

**Description**

This error code is reported if the **write** API is called to perform system event logging but the system ignores the logging operation because the environment is abnormal.

**Possible Causes**

1. The hiview service fails to be started.
2. The socket of the hiview service is abnormal.

**Solution**

Call the **write** API again to perform event logging.

## 11200004 Invalid Event Length

**Error Message**

Length of the event is over limit.

**Description**

This error code is reported if the **write** API is called to perform system event logging but the system ignores the logging operation because the total event length is invalid.

**Possible Causes**

The total event length exceeds 384 KB.

**Solution**

Check whether the total event length is greater than 384 KB.

## 11200051 Invalid Event Parameter

**Error Message**

Invalid event parameter.

**Description**

This error code is reported if the **write** API is called to perform system event logging but the system throws an exception because the input parameter name is invalid. However, the system will continue to complete the logging operation.

**Possible Causes**

1. The event parameter name contains more than 32 characters.
2. The event parameter name contains special characters.
3. The event parameter name is empty.

**Solution**

Check whether the event parameter name is valid.

## 11200052 Length of Event Parameter Values of the String Type Exceeding the Limit

**Error Message**

Size of the event parameter of the string type is over limit.

**Description**

This error code is reported if the **write** API is called to perform system event logging but the system throws an exception because the length of event parameter values of the string type is invalid. However, the system will continue to complete the logging operation.

**Possible Causes**

The length of parameter values of the string type exceeds 10 KB.

**Solution**

Check whether the length of parameter values of the string type exceeds 10 KB.

## 11200053 Number of Event Parameters Exceeding the Limit

**Error Message**

Count of event parameters is over limit.

**Description**

This error code is reported if the **write** API is called to perform system event logging but the system throws an exception because the number of event parameters is invalid. However, the system will continue to complete the logging operation.

**Possible Causes**

The number of event parameters exceeds 128.

**Solution**

Check whether the number of event parameters exceeds 128.

## 11200054 Length of Event Parameter Values of the Array Type Exceeding the Limit

**Error Message**

Count of event parameter of the array type is over limit.

**Description**

This error code is reported if the **write** API is called to perform system event logging but the system throws an exception because the length of event parameter values of the array type is invalid. However, the system will continue to complete the logging operation.

**Possible Causes**

The length of a parameter values of the array type exceeds 100.

**Solution**

Check whether the length of the parameter value of the array type exceeds 100.

## 11200101 Number of Event Watchers Exceeding the Limit

**Error Message**

Count of watchers is over limit.

**Description**

This error code is reported if the **addWatcher** API is called to add an event watcher but the system rejects the operation because the number of watchers has exceeded the limit.

**Possible Causes**

A total of 30 event watchers have been added.

**Solution**

Check whether the number of event watchers exceeds 30.

## 11200102 Number of Event Watcher Rules Exceeding the Limit

**Error Message**

Count of watch rules is over limit.

**Description**

This error code is reported if the **addWatcher** API is called to add an event watcher but the system rejects the operation because the number of watcher rules has exceeded the limit.

**Possible Causes**

A total of 20 event watcher rules have been added.

**Solution**

Check whether the number of event watcher rules exceeds 20.

## 11200201 Event Watcher Not Exist

**Error Message**

The watcher does not exist.

**Description**

This error code is reported if the **removeWatcher** API is called to remove an event watcher but the system rejects the operation because the watcher does not exist.

**Possible Causes**

1. The event watcher to be removed is empty.
2. The event watcher to be removed has not been successfully added.

**Solution**

Check whether the event watcher to the removed is empty or whether the event watcher has been successfully added.

## 11200301 Number of Query Rules Exceeding the Limit

**Error Message**

Count of query rules is over limit.

**Description**

This error code is reported if the **query** API is called to query system events but the system ignores the operation because the number of query rules has exceeded the limit.

**Possible Causes**

The number of query rules exceeds 10.

**Solution**

Check whether the number of query rules exceeds 10.


## 11200302 Invalid Query Rule

**Error Message**

Invalid query rule.


**Description**

This error code is reported if the **query** API is called to query system events but the system ignores the operation because the input query rule is invalid.

**Possible Causes**

1. The event domain name in the query rule contains more than 16 characters or the event name contains more than 32 characters.
2. The event domain name or event name in the query rule contains special characters.
3. The event domain name or event name in the query rule is empty.

**Solution**

Check whether the event domain name and event name configured in the query rule are valid.

## 11200303 Number of Concurrent Queries Exceeding the Limit

**Error Message**

Count of concurrent queries is over limit.

**Description**

This error code is reported if the **query** API is called to query system events but the system ignores the operation because the number of concurrent queries has exceeded the limit.

**Possible Causes**

The number of concurrent queries exceeds 4.

**Solution**

Check whether more than four queries are performed at the same time.

## 11200304  Query Frequency Exceeding the Limit

**Error Message**

Query frequency is over limit.

**Description**

This error code is reported if the **query** API is called to query system events but the system ignores the operation because the query frequency has exceeded the limit.

**Possible Causes**

More than one query is performed in one second.

**Solution**

Check whether more than one query is performed in one second.
