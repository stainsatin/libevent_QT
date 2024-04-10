#ifndef CHAT_LIST_H
#define CHAT_LIST_H

#include <iostream>
#include <mutex>
#include <list>
#include <map>
#include <event.h>
#include <json/json.h>

struct User
{
	std::string name;             //账号（用户名）
	struct bufferevent *bev;      //客户端对应的事件
};

class ChatInfo
{
private:
	//保存在线用户信息
	std::list<User> *online_user;
	//保存所有群的信息
	std::map<std::string, std::list<std::string> > *group_info;
	//访问在线用户的锁
	std::mutex list_mutex;
	//访问群信息的锁
	std::mutex map_mutex;
public:
	ChatInfo();
	~ChatInfo();

	void list_update_group(std::string *, int);
	void list_print_group();
	bool list_update_list(Json::Value &, struct bufferevent *);
	struct bufferevent *list_friend_online(std::string);
	bool list_group_is_exist(std::string);
	void list_add_new_group(std::string, std::string);
	bool list_member_is_group(std::string, std::string);
	void list_update_group_member(std::string, std::string);
	void list_delete_user(std::string);
	void list_get_group_member(std::string, std::string &);
	std::list<std::string> &list_get_list(std::string);
};

#endif
