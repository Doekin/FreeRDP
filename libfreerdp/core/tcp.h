/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Transmission Control Protocol (TCP)
 *
 * Copyright 2011 Vic Lee
 * Copyright 2011 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_LIB_CORE_TCP_H
#define FREERDP_LIB_CORE_TCP_H

#include <winpr/windows.h>

#include <freerdp/types.h>
#include <freerdp/settings.h>
#include <freerdp/freerdp.h>
#include <freerdp/api.h>
#include <freerdp/transport_io.h>

#include <winpr/crt.h>
#include <winpr/synch.h>
#include <winpr/stream.h>
#include <winpr/winsock.h>
#include <winpr/crypto.h>

#include <openssl/bio.h>

#include <freerdp/utils/ringbuffer.h>

#define BIO_TYPE_TSG 65
#define BIO_TYPE_SIMPLE 66
#define BIO_TYPE_BUFFERED 67
#define BIO_TYPE_NAMEDPIPE 69

#define BIO_C_SET_SOCKET 1101
#define BIO_C_GET_SOCKET 1102
#define BIO_C_GET_EVENT 1103
#define BIO_C_SET_NONBLOCK 1104
#define BIO_C_READ_BLOCKED 1105
#define BIO_C_WRITE_BLOCKED 1106
#define BIO_C_WAIT_READ 1107
#define BIO_C_WAIT_WRITE 1108
#define BIO_C_SET_HANDLE 1109

static INLINE long BIO_set_socket(BIO* b, SOCKET s, long c)
{
	return BIO_ctrl(b, BIO_C_SET_SOCKET, c, (void*)(intptr_t)s);
}
static INLINE long BIO_get_socket(BIO* b, SOCKET* c)
{
	return BIO_ctrl(b, BIO_C_GET_SOCKET, 0, c);
}
static INLINE long BIO_get_event(BIO* b, HANDLE* c)
{
	return BIO_ctrl(b, BIO_C_GET_EVENT, 0, c);
}
static INLINE long BIO_set_handle(BIO* b, HANDLE h)
{
	return BIO_ctrl(b, BIO_C_SET_HANDLE, 0, h);
}
static INLINE long BIO_set_nonblock(BIO* b, long c)
{
	return BIO_ctrl(b, BIO_C_SET_NONBLOCK, c, NULL);
}
static INLINE long BIO_read_blocked(BIO* b)
{
	return BIO_ctrl(b, BIO_C_READ_BLOCKED, 0, NULL);
}
static INLINE long BIO_write_blocked(BIO* b)
{
	return BIO_ctrl(b, BIO_C_WRITE_BLOCKED, 0, NULL);
}
static INLINE long BIO_wait_read(BIO* b, long c)
{
	return BIO_ctrl(b, BIO_C_WAIT_READ, c, NULL);
}

static INLINE long BIO_wait_write(BIO* b, long c)
{
	return BIO_ctrl(b, BIO_C_WAIT_WRITE, c, NULL);
}

FREERDP_LOCAL BIO_METHOD* BIO_s_simple_socket(void);
FREERDP_LOCAL BIO_METHOD* BIO_s_buffered_socket(void);

FREERDP_LOCAL BOOL freerdp_tcp_set_keep_alive_mode(const rdpSettings* settings, int sockfd);

FREERDP_LOCAL int freerdp_tcp_connect(rdpContext* context, const char* hostname, int port,
                                      DWORD timeout);

FREERDP_LOCAL int freerdp_tcp_default_connect(rdpContext* context, rdpSettings* settings,
                                              const char* hostname, int port, DWORD timeout);

FREERDP_LOCAL rdpTransportLayer*
freerdp_tcp_connect_layer(rdpContext* context, const char* hostname, int port, DWORD timeout);

FREERDP_LOCAL char* freerdp_tcp_get_peer_address(SOCKET sockfd);

FREERDP_LOCAL struct addrinfo* freerdp_tcp_resolve_host(const char* hostname, int port,
                                                        int ai_flags);
FREERDP_LOCAL char* freerdp_tcp_address_to_string(const struct sockaddr_storage* addr, BOOL* pIPv6);

#endif /* FREERDP_LIB_CORE_TCP_H */
