/*       +------------------------------------+
 *       | Inspire Internet Relay Chat Daemon |
 *       +------------------------------------+
 *
 *  Inspire is copyright (C) 2002-2005 ChatSpike-Dev.
 *                       E-mail:
 *                <brain@chatspike.net>
 *                <Craig@chatspike.net>
 *
 * Written by Craig Edwards, Craig McLure, and others.
 * This program is free but copyrighted software; see
 *            the file COPYING for details.
 *
 * ---------------------------------------------------
 */

#ifndef _HELPER_H_
#define _HELPER_H_

#include "dynamic.h"
#include "base.h"
#include "ctables.h"
#include "users.h"
#include "channels.h"
#include <string>
#include <deque>
#include <sstream>

void log(int level,char *text, ...);
void readfile(file_cache &F, const char* fname);
void Write(int sock,char *text, ...);
void WriteServ(int sock, char* text, ...);
void WriteFrom(int sock, userrec *user,char* text, ...);
void WriteTo(userrec *source, userrec *dest,char *data, ...);
void WriteChannel(chanrec* Ptr, userrec* user, char* text, ...);
void WriteChannelLocal(chanrec* Ptr, userrec* user, char* text, ...);
void WriteChannelWithServ(char* ServName, chanrec* Ptr, char* text, ...);
void ChanExceptSender(chanrec* Ptr, userrec* user, char* text, ...);
std::string GetServerDescription(char* servername);
void WriteCommon(userrec *u, char* text, ...);
void WriteCommonExcept(userrec *u, char* text, ...);
void WriteOpers(char* text, ...);
void NoticeAllOpers(userrec *source, bool local_only, char* text, ...);
bool ChanAnyOnThisServer(chanrec *c,char* servername);
bool CommonOnThisServer(userrec* u,const char* servername);
void NetSendToCommon(userrec* u, char* s);
void NetSendToAll(char* s);
void NetSendToAll_WithSum(char* s,char* u);
void NetSendToAllAlive(char* s);
void NetSendToOne(char* target,char* s);
void NetSendToAllExcept(const char* target,char* s);
void NetSendToAllExcept_WithSum(const char* target,char* s,char* u);
void WriteMode(const char* modes, int flags, const char* text, ...);
void NoticeAll(userrec *source, bool local_only, char* text, ...);
void WriteWallOps(userrec *source, bool local_only, char* text, ...);
void strlower(char *n);
userrec* Find(std::string nick);
chanrec* FindChan(const char* chan);
long GetMaxBans(char* name);
void purge_empty_chans(userrec* u);
char* chanmodes(chanrec *chan);
void userlist(userrec *user,chanrec *c);
int usercount_i(chanrec *c);
int usercount(chanrec *c);
char* Passwd(userrec *user);
bool IsDenied(userrec *user);
void send_error(char *s);
void Error(int status);
int usercnt(void);
int registered_usercount(void);
int usercount_invisible(void);
int usercount_opers(void);
int usercount_unknown(void);
long chancount(void);
long count_servs(void);
long servercount(void);
long local_count();
void ShowMOTD(userrec *user);
void ShowRULES(userrec *user);
bool AllModulesReportReady(userrec* user);
char islast(const char* s);
long map_count(const char* s);
void createcommand(char* cmd, handlerfunc f, char flags, int minparams,char* source);
void SetupCommandTable(void);
bool DirValid(char* dirandfile);
std::string GetFullProgDir(char** argv, int argc);

#endif
