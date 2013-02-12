#ifndef __EXPORTS_H__
#define __EXPORTS_H__

EXPORT(gcmInitBody, 0x15bae46b);
EXPORT(gcmSetDisplayBuffer, 0xa53d12ae);
EXPORT(gcmGetControlRegister, 0xa547adde);
EXPORT(gcmAddressToOffset, 0x21ac3697);
EXPORT(gcmGetConfiguration, 0xe315a0b2);
EXPORT(gcmGetCurrentField, 0xc8f3bd09);
EXPORT(gcmSetFlipMode, 0x4ae8d215);
EXPORT(gcmGetFlipStatus, 0x72a577ce);
EXPORT(gcmGetLastFlipTime, 0x63387071);
EXPORT(gcmGetVBlankCount, 0x723bbc7e);
EXPORT(gcmSetWaitFlip, 0x983fb9aa);
EXPORT(gcmSetFlipStatus, 0xa47c09ff);
EXPORT(gcmResetFlipStatus, 0xb2e761d4);
EXPORT(gcmSetFlip, 0xdc09357e);
EXPORT(gcmSetFlipImmediate, 0xacee8542);
EXPORT(gcmFunc15, 0x3a33c1fd);
EXPORT(gcmFunc3, 0x1bd633f8);
EXPORT(gcmFunc1, 0x5f909b17);
EXPORT(gcmFunc2, 0x8effb7fd);
EXPORT(gcmFunc4, 0x7fc034bc);
EXPORT(gcmFunc12, 0x661fe266);
EXPORT(gcmFunc13, 0xbb42a9dd);
EXPORT(gcmGetReport, 0x99d397ac);
EXPORT(gcmSetTile, 0xd0b1d189);
EXPORT(gcmBindTile, 0x4524cccd);
EXPORT(gcmUnbindTile, 0xd9b7653e);
EXPORT(gcmSetZcull, 0xd34a420d);
EXPORT(gcmBindZcull, 0x9dc04436);
EXPORT(gcmUnbindZcull, 0xa75640e8);
EXPORT(gcmGetTimeStamp, 0x5a41c10f);
EXPORT(gcmSetVBlankFrequency, 0xffe0160e);
EXPORT(gcmSetSecondVFrequency, 0x4d7ce993);
EXPORT(gcmSetDebugOutputLevel, 0x51c9d62b);
EXPORT(gcmGetLabelAddress, 0xf80196c1);
EXPORT(gcmSetVBlankHandlerEx, 0xa91b0402);
EXPORT(gcmSetFlipHandlerEx, 0xa41ef7e8);
EXPORT(gcmSetSecondVHandlerEx, 0xdc494430);
EXPORT(gcmSetGraphicsHandlerEx, 0xd01b570d);
EXPORT(gcmTerminate, 0x527c6439);
EXPORT(gcmMapMainMemory, 0xa114ec67);
EXPORT(gcmMapEaIoAddress, 0x63441cb4);
EXPORT(gcmUnmapEaIoAddress, 0xefd00f54);
EXPORT(gcmUnmapIoAddress, 0xdb23e867);
EXPORT(gcmIoOffsetToAddress, 0x2a6fba9c);
EXPORT(gcmSetDefaultCommandBuffer, 0xbc982946);
EXPORT(gcmSetTileInfo, 0xbd100dbc);
EXPORT(gcmGetTiledPitchSize, 0x055bd74d);
EXPORT(gcmSetInvalidateTile, 0xbd6d60d9);
EXPORT(gcmSetUserCommandEx, 0x8bde5ebf);
EXPORT(gcmSetUserHandlerEx, 0x06edea9e);
EXPORT(gcmSetQueueHandlerEx, 0x0a862772);
EXPORT(gcmSetPrepareFlip, 0x0b4b62d5);
EXPORT(gcmGetOffsetTable, 0x2922aed0);
EXPORT(gcmGetLastSecondVTime, 0x23ae55a3);
EXPORT(gcmSortRemapEaIoAddress, 0x25b40ab4);
EXPORT(gcmGetDisplayBufferByFlipIndex, 0x371674cf);
EXPORT(gcmGcmGetDefaultCommandWordSize, 0x5e2ee0f0);
EXPORT(gcmGcmGetDefaultSegmentWordSize, 0x8cdf8c70);
EXPORT(gcmSetDefaultCommandBufferAndSegmentWordSize, 0x172c3197);

EXPORT(gcmGetDisplayInfo, 0x0e6b0dae);
EXPORT(gcmDumpGraphicsError, 0x1f61b3ff);
EXPORT(gcmFunc38, 0x688b8ac9);
EXPORT(gcmGetCurrentDisplayBufferId, 0x93806525);
EXPORT(gcmGetDefaultCommandWordSize, 0x5e2ee0f0);
EXPORT(gcmGetDefaultSegmentWordSize, 0x8cdf8c70);
EXPORT(gcmGetMaxIoMapSize, 0xfb81c03e);
EXPORT(gcmGetNotifyDataAddress, 0x21cee035);
EXPORT(gcmGetReportDataAddress, 0x9a0159af);
EXPORT(gcmGetReportDataAddressLocation, 0x8572bce2);
EXPORT(gcmGetReportDataLocation, 0xa6b180ac);
EXPORT(gcmGetTileInfo, 0x657571f7);
EXPORT(gcmGetTimeStampLocation, 0x2ad4951b);
EXPORT(gcmGetZcullInfo, 0xd9a0a879);
EXPORT(gcmInitCursor, 0x107bf3a1);
EXPORT(gcmInitDefaultFifoMode, 0xcaabd992);
EXPORT(gcmInitSystemMode, 0xfce9e764);
EXPORT(gcmMapEaIoAddressWithFlags, 0x626e8518);
EXPORT(gcmMapLocalMemory, 0xdb769b32);
EXPORT(gcmReserveIoMapSize, 0xa7ede268);
EXPORT(gcmSetCursorDisable, 0x69c6cc82);
EXPORT(gcmSetCursorEnable, 0xc47d0812);
EXPORT(gcmSetCursorImageOffset, 0xf9bfdc72);
EXPORT(gcmSetCursorPosition, 0x1a0de550);
EXPORT(gcmSetDefaultFifoSize, 0x9ba451e4);
EXPORT(gcmSetFlipCommand, 0x21397818);
EXPORT(gcmSetFlipCommandWithWaitLabel, 0xd8f88e1a);
EXPORT(gcmSysGetLastVBlankTime, 0xe44874f3);
EXPORT(gcmUnreserveIoMapSize, 0x3b9bd5bd);
EXPORT(gcmUpdateCursor, 0xbd2fa0a7);

#endif
