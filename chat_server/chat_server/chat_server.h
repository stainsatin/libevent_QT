#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H

#include <event.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <stdlib.h>
#include <event2/listener.h>
#include "chat_database.h"
#include "chat_list.h"
#include "chat_thread.h"

#define IP     "10.0.16.3"
#define PORT   8887           /*安全组规则*/

class ChatServer
{
private:
	struct event_base *base;   //用于监听连接事件集合   
	DataBase *db;              //数据库对象
	ChatInfo *info;            //数据结构对象
	ChatThread *pool;          //线程池对象   
	int thread_num;            //线程数量
	int cur_thread;            //当前的线程
public:
	ChatServer();
	~ChatServer();
	void listen(const char *, int);
	void server_update_group_info();
	static void listener_cb(struct evconnlistener *, evutil_socket_t, 
			     	struct sockaddr *, int, void *);
	void server_alloc_event(int);
};



#endif
