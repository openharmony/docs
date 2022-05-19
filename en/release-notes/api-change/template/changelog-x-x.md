# ChangeLog
## *Example* Subsystem (Do not modify or delete this example)
Changes that affect contract compatibility of a released version should be described in the ChangeLog. The changes include but are not limited to those related to API names, parameters, return values, required permissions, call sequence, enumerated values, configuration parameters, and paths. Contract compatibility, also called semantic compatibility, means that the original program behavior should remain consistent over versions.
### cl.subsystemname.x xxx Function Change (Example: DeviceType Attribute Change or Camera Permission Change. Use a short description.)
Add the number **cl.*subsystemname*.*x*** before each change title, where **cl** is the abbreviation of ChangeLog, *subsystemname* is the standard English name of the subsystem, and *x* indicates the change sequence number (in ascending order).
Describe the changes in terms of functions. Example: *n* and *m* of the *a* function are changed. Developers need to adapt their applications based on the change description.
If there is a requirement or design document corresponding to the change, attach the requirement number or design document number in the description.

**Change Impact**

Describe whether released APIs (JS, Java, or native APIs) are affected or API behavior is changed.

**Key API/Component Changes**

List the API/component changes involved in the function change.

**Adaptation Guide (Optional)**

Provide guidance for developers on how to adapt their application to the changes to be compatible with the new version. Example:
Change parameter *n* to *m* in the *a* file.
```
sample code
```
### cl.subsystemname.x xxx Function Change
If a subsystem introduces any function changes, include a standalone section in the subsystem chapter to describe the function changes.

## *Example* Subsystem
Each subsystem has only one such chapter.
