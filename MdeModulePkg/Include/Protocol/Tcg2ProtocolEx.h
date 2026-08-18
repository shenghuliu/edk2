/** @file
  Extended TCG2 Protocol definitions.

  This header defines additional APIs that extend the TCG2 Protocol as defined
  in the TCG PC Client Platform EFI Protocol Specification Family "2.0".
  See http://trustedcomputinggroup.org for the latest specification.

Copyright (c) Qualcomm Technologies, Inc. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#pragma once

extern EFI_GUID  gEfiTcg2ProtocolExGuid;

//
// Protocol version.
//
#define EFI_TCG2_PROTOCOL_EX_REVISION  0x0000000000010000

#define EFI_TCG2_PROTOCOL_EX_GUID \
  {0xf82300be, 0x6568, 0x46fa, { 0x96, 0xf2, 0xd5, 0xe5, 0x8d, 0x82, 0x07, 0xcd }}

typedef struct tdEFI_TCG2_PROTOCOL_EX EFI_TCG2_PROTOCOL_EX;

/**
  Build a TCG2 event from the supplied digest list without extending a PCR.

  @param[in]      This             Indicates the calling context.
  @param[in]      DigestList       Pointer to a TPML_DIGEST_LIST structure
                                   containing the list of digests to log.
  @param[in]      DigestListSize   Size, in bytes, of the digest list.
  @param[in]      Tcg2Event        Pointer to an EFI_TCG2_EVENT structure
                                   that describes the event to log.
  @param[in]      Tcg2EventSize    Size, in bytes, of the Tcg2Event structure.

  @retval EFI_SUCCESS              The event was logged successfully.
  @retval EFI_INVALID_PARAMETER    One or more parameters are invalid.
  @retval EFI_BUFFER_TOO_SMALL     The Tcg2Event buffer is too small.
  @retval EFI_DEVICE_ERROR         The operation was unsuccessful.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_TCG2_LOG_EVENT)(
  IN EFI_TCG2_PROTOCOL_EX  *This,
  IN VOID                  *DigestList,
  IN UINTN                 DigestListSize,
  IN VOID                  *Tcg2Event,
  IN UINTN                 Tcg2EventSize
  );

struct tdEFI_TCG2_PROTOCOL_EX {
  UINT64                Revision;
  EFI_TCG2_LOG_EVENT    LogEvent;
};
