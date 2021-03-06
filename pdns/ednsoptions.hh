/*
 * This file is part of PowerDNS or dnsdist.
 * Copyright -- PowerDNS.COM B.V. and its contributors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * In addition, for the avoidance of any doubt, permission is granted to
 * link this program with OpenSSL and to (re)distribute the binaries
 * produced as the result of such linking.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef PDNS_EDNSOPTIONS_HH
#define PDNS_EDNSOPTIONS_HH

#include "namespaces.hh"

struct EDNSOptionCode
{
  enum EDNSOptionCodeEnum {NSID=3, DAU=4, DHU=6, N3U=7, ECS=8, EXPIRE=9, COOKIE=10, TCPKEEPALIVE=11, PADDING=12, CHAIN=13};
};

/* extract a specific EDNS0 option from a pointer on the beginning rdLen of the OPT RR */
int getEDNSOption(char* optRR, size_t len, uint16_t wantedOption, char ** optionValue, size_t * optionValueSize);
void generateEDNSOption(uint16_t optionCode, const std::string& payload, std::string& res);

#endif
