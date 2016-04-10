
#ifndef __IOCTLS_H__
#define __IOCTLS_H__

#include "kernel-shared.h"

#define IOCTL_IRPMNDRV_CONNECT                         CTL_CODE(FILE_DEVICE_UNKNOWN, 0x01, METHOD_NEITHER, FILE_WRITE_ACCESS)
#define IOCTL_IRPMNDRV_DISCONNECT                      CTL_CODE(FILE_DEVICE_UNKNOWN, 0x02, METHOD_NEITHER, FILE_WRITE_ACCESS)
#define IOCTL_IRPMNDRV_GET_RECORD                      CTL_CODE(FILE_DEVICE_UNKNOWN, 0x03, METHOD_NEITHER, FILE_WRITE_ACCESS)
#define IOCTL_IRPMNDRV_HOOK_DRIVER                     CTL_CODE(FILE_DEVICE_UNKNOWN, 0x04, METHOD_NEITHER, FILE_WRITE_ACCESS)
#define IOCTL_IRPMNDRV_UNHOOK_DRIVER                   CTL_CODE(FILE_DEVICE_UNKNOWN, 0x05, METHOD_NEITHER, FILE_WRITE_ACCESS)
#define IOCTL_IRPMNDRV_HOOK_ADD_DEVICE                 CTL_CODE(FILE_DEVICE_UNKNOWN, 0x06, METHOD_NEITHER, FILE_WRITE_ACCESS)
#define IOCTL_IRPMNDRV_HOOK_REMOVE_DEVICE              CTL_CODE(FILE_DEVICE_UNKNOWN, 0x07, METHOD_NEITHER, FILE_WRITE_ACCESS)
#define IOCTL_IRPMNDRV_GET_DRIVER_DEVICE_INFO          CTL_CODE(FILE_DEVICE_UNKNOWN, 0x08, METHOD_NEITHER, FILE_READ_ACCESS)
#define IOCTL_IRPMNDRV_HOOK_DRIVER_SET_INFO            CTL_CODE(FILE_DEVICE_UNKNOWN, 0x09, METHOD_NEITHER, FILE_WRITE_ACCESS)
#define IOCTL_IRPMNDRV_HOOK_DRIVER_MONITORING_CHANGE   CTL_CODE(FILE_DEVICE_UNKNOWN, 0x0a, METHOD_NEITHER, FILE_WRITE_ACCESS)
#define IOCTL_IRPMONDRV_HOOK_GET_INFO                  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x0b, METHOD_NEITHER, FILE_READ_ACCESS)
#define IOCTL_IRPMONDRV_HOOK_OPEN                      CTL_CODE(FILE_DEVICE_UNKNOWN, 0x0c, METHOD_NEITHER, FILE_ANY_ACCESS)
#define IOCTL_IRPMONDRV_HOOK_CLOSE                     CTL_CODE(FILE_DEVICE_UNKNOWN, 0x0d, METHOD_NEITHER, FILE_ANY_ACCESS)
#define IOCTL_IRPMNDRV_HOOK_DRIVER_GET_INFO            CTL_CODE(FILE_DEVICE_UNKNOWN, 0x0e, METHOD_NEITHER, FILE_WRITE_ACCESS)
#define IOCTL_IRPMNDRV_HOOK_DEVICE_SET_INFO            CTL_CODE(FILE_DEVICE_UNKNOWN, 0x0f, METHOD_NEITHER, FILE_READ_ACCESS)
#define IOCTL_IRPMNDRV_HOOK_DEVICE_GET_INFO            CTL_CODE(FILE_DEVICE_UNKNOWN, 0x10, METHOD_NEITHER, FILE_WRITE_ACCESS)


typedef struct _IOCTL_IRPMNDRV_CONNECT_INPUT {
	HANDLE SemaphoreHandle;
} IOCTL_IRPMNDRV_CONNECT_INPUT, *PIOCTL_IRPMNDRV_CONNECT_INPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_DRIVER_INPUT {
	PWCHAR DriverName;
	ULONG DriverNameLength;
	DRIVER_MONITOR_SETTINGS MonitorSettings;
} IOCTL_IRPMNDRV_HOOK_DRIVER_INPUT, *PIOCTL_IRPMNDRV_HOOK_DRIVER_INPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_DRIVER_OUTPUT {
	HANDLE HookHandle;
} IOCTL_IRPMNDRV_HOOK_DRIVER_OUTPUT, *PIOCTL_IRPMNDRV_HOOK_DRIVER_OUTPUT;

typedef struct _IOCTL_IRPMNDRV_UNHOOK_DRIVER_INPUT {
	HANDLE HookHandle;
} IOCTL_IRPMNDRV_UNHOOK_DRIVER_INPUT, *PIOCTL_IRPMNDRV_UNHOOK_DRIVER_INPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_ADD_DEVICE_INPUT {
	BOOLEAN HookByName;
	PWCHAR DeviceName;
	ULONG DeviceNameLength;
	PVOID DeviceAddress;
	PUCHAR IRPSettings;
	PUCHAR FastIoSettings;
} IOCTL_IRPMNDRV_HOOK_ADD_DEVICE_INPUT, *PIOCTL_IRPMNDRV_HOOK_ADD_DEVICE_INPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_ADD_DEVICE_OUTPUT {
	HANDLE DeviceHandle;
} IOCTL_IRPMNDRV_HOOK_ADD_DEVICE_OUTPUT, *PIOCTL_IRPMNDRV_HOOK_ADD_DEVICE_OUTPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_REMOVE_DEVICE_INPUT {
	HANDLE DeviceHandle;
} IOCTL_IRPMNDRV_HOOK_REMOVE_DEVICE_INPUT, *PIOCTL_IRPMNDRV_HOOK_REMOVE_DEVICE_INPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_DRIVER_SET_INFO_INPUT {
	HANDLE DriverHandle;
	BOOLEAN MonitorNewDevices;
	BOOLEAN MonitorAddDevice;
	BOOLEAN MonitorStartIo;
	BOOLEAN MonitorUnload;
} IOCTL_IRPMNDRV_HOOK_DRIVER_SET_INFO_INPUT, *PIOCTL_IRPMNDRV_HOOK_DRIVER_SET_INFO_INPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_DRIVER_GET_INFO_INPUT {
	HANDLE DriverHandle;
} IOCTL_IRPMNDRV_HOOK_DRIVER_GET_INFO_INPUT, *PIOCTL_IRPMNDRV_HOOK_DRIVER_GET_INFO_INPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_DRIVER_GET_INFO_OUTPUT {
	DRIVER_MONITOR_SETTINGS Settings;
	BOOLEAN MonitoringEnabled;
} IOCTL_IRPMNDRV_HOOK_DRIVER_GET_INFO_OUTPUT, *PIOCTL_IRPMNDRV_HOOK_DRIVER_GET_INFO_OUTPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_DRIVER_MONITORING_CHANGE_INPUT {
	HANDLE DriverHandle;
	BOOLEAN EnableMonitoring;
} IOCTL_IRPMNDRV_HOOK_DRIVER_MONITORING_CHANGE_INPUT, *PIOCTL_IRPMNDRV_HOOK_DRIVER_MONITORING_CHANGE_INPUT;

typedef struct _IOCTL_IRPMONDRV_HOOK_GET_INFO_OUTPUT {
	HOOKED_OBJECTS_INFO Info;
} IOCTL_IRPMONDRV_HOOK_GET_INFO_OUTPUT, *PIOCTL_IRPMONDRV_HOOK_GET_INFO_OUTPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_DEVICE_SET_INFO_INPUT {
	HANDLE DeviceHandle;
	PUCHAR IRPSettings;
	PUCHAR FastIoSettings;
	BOOLEAN MonitoringEnabled;
} IOCTL_IRPMNDRV_HOOK_DEVICE_SET_INFO_INPUT, *PIOCTL_IRPMNDRV_HOOK_DEVICE_SET_INFO_INPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_DEVICE_GET_INFO_INPUT {
	HANDLE DeviceHandle;
} IOCTL_IRPMNDRV_HOOK_DEVICE_GET_INFO_INPUT, *PIOCTL_IRPMNDRV_HOOK_DEVICE_GET_INFO_INPUT;

typedef struct _IOCTL_IRPMNDRV_HOOK_DEVICE_GET_INFO_OUTPUT {
	UCHAR IRPSettings[0x1C];
	UCHAR FastIoSettings[FastIoMax];
	BOOLEAN MonitoringEnabled;
} IOCTL_IRPMNDRV_HOOK_DEVICE_GET_INFO_OUTPUT, *PIOCTL_IRPMNDRV_HOOK_DEVICE_GET_INFO_OUTPUT;

typedef enum _EHandleType {
	ehtUnknown,
	ehtDriver,
	ehtDevice
} EHandletype, *PEHandleType;

typedef struct _IOCTL_IRPMONDRV_HOOK_OPEN_INPUT {
	EHandletype ObjectType;
	PVOID ObjectId;
} IOCTL_IRPMONDRV_HOOK_OPEN_INPUT, *PIOCTL_IRPMONDRV_HOOK_OPEN_INPUT;

typedef struct _IOCTL_IRPMONDRV_HOOK_OPEN_OUTPUT {
	HANDLE Handle;
} IOCTL_IRPMONDRV_HOOK_OPEN_OUTPUT, *PIOCTL_IRPMONDRV_HOOK_OPEN_OUTPUT;

typedef struct _IOCTL_IRPMONDRV_HOOK_CLOSE_INPUT {
	EHandletype ObjectType;
	HANDLE Handle;
} IOCTL_IRPMONDRV_HOOK_CLOSE_INPUT, *PIOCTL_IRPMONDRV_HOOK_CLOSE_INPUT;

#endif
