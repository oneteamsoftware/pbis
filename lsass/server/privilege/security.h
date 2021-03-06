/* -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
 * ex: set softtabstop=4 tabstop=8 expandtab shiftwidth=4: *
 * Editor Settings: expandtabs and use 4 spaces for indentation */

/*
 * Copyright Likewise Software    2004-2011
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.  You should have received a copy of the GNU General
 * Public License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * LIKEWISE SOFTWARE MAKES THIS SOFTWARE AVAILABLE UNDER OTHER LICENSING
 * TERMS AS WELL.  IF YOU HAVE ENTERED INTO A SEPARATE LICENSE AGREEMENT
 * WITH LIKEWISE SOFTWARE, THEN YOU MAY ELECT TO USE THE SOFTWARE UNDER THE
 * TERMS OF THAT SOFTWARE LICENSE AGREEMENT INSTEAD OF THE TERMS OF THE GNU
 * GENERAL PUBLIC LICENSE, NOTWITHSTANDING THE ABOVE NOTICE.  IF YOU
 * HAVE QUESTIONS, OR WISH TO REQUEST A COPY OF THE ALTERNATE LICENSING
 * TERMS OFFERED BY LIKEWISE SOFTWARE, PLEASE CONTACT LIKEWISE SOFTWARE AT
 * license@likewisesoftware.com
 */

/*
 * Copyright (C) Likewise Software. All rights reserved.
 *
 * Module Name:
 *
 *        security.h
 *
 * Abstract:
 *
 *        Likewise Security and Authentication Subsystem (LSASS)
 *
 *        Lsa Accounts and Privileges security
 *
 * Authors: Rafal Szczesniak (rafal@likewise.com)
 */

#ifndef __LSASRV_PRIVILEGE_SECURITY_H__
#define __LSASRV_PRIVILEGE_SECURITY_H__


typedef struct _ACCESS_LIST
{
    PSID        *ppSid;
    ACCESS_MASK AccessMask;
    ULONG       ulAccessType;
} ACCESS_LIST, *PACCESS_LIST;


DWORD
LsaSrvInitPrivilegesSecurity(
    OUT PSECURITY_DESCRIPTOR_ABSOLUTE *ppSecurityDescriptor
    );


DWORD
LsaSrvInitAccountsSecurity(
    OUT PSECURITY_DESCRIPTOR_RELATIVE *ppSecurityDescRelative,
    OUT PDWORD pSecurityDescRelativeSize
    );


DWORD
LsaSrvFreeSecurityDescriptor(
    IN PSECURITY_DESCRIPTOR_ABSOLUTE pSecDesc
    );


DWORD
LsaSrvAllocateAbsoluteFromSelfRelativeSD(
    IN PSECURITY_DESCRIPTOR_RELATIVE pSecurityDescRelative,
    OUT PSECURITY_DESCRIPTOR_ABSOLUTE *ppSecurityDesc
    );


VOID
LsaSrvPrivsGetClientCreds(
    IN HANDLE hServer,
    OUT PDWORD pUid,
    OUT PDWORD pGid,
    OUT PDWORD pPid
    );


DWORD
LsaSrvPrivsGetAccessTokenFromServerHandle(
    HANDLE hServer,
    PACCESS_TOKEN *pAccessToken
    );


#endif /* __LSASRV_PRIVILEGE_SECURITY_H__ */
