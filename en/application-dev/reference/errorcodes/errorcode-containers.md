# containers Error Codes

## 10200012 Constructor Calling Failure

**Error Message**

The {className}'s constructor cannot be directly invoked.

**Description**

A constructor of the **containers** class is called directly to create an instance.

**Possible Causes**

The constructors of the **containers** class cannot be directly called. The keyword **new** must be used.

**Solution**

Use the keyword **new** to create an instance.

## 10200011 Passed this object Is Not an Instance of the containers Class

**Error Message**

The {methodName} method cannot be bound.

**Description**

**this object** passed in the API is not an instance of the **containers** class.

**Possible Causes**

The APIs of the **containers** class do not support **bind()**.

**Solution**

1. Check whether **bind()** is used to call the API.
2. Check whether an object that is not a container instance is assigned to the API.

## 10200001 Invalid Parameter Value

**Error Message**

The parameter value is out of range.

**Description**

The value of a parameter passed in the API exceeds the valid range.

**Possible Causes**

The parameter value is out of range.

**Solution**

Use a value within the range.

## 10200010 Empty Container

**Error Message**

The container is empty.

**Description**

The container to be operated is empty.

**Possible Causes**

The container is empty.

**Solution**

Add elements to the container first.
