#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define BUFLEN 20

/* 描述就绪文件描述符相关信息 */

struct myevent_s {
	int fd;                                                 //要监听的文件描述符
	int events;                                             //对应的监听事件
	void *arg;                                              //泛型参数
	void(*call_back)(myevent_s * myevent);       //回调函数
	int status;                                             //是否在监听:1->在红黑树上(监听), 0->不在(不监听)
	char buf[BUFLEN];
	int len;
	long last_active;                                       //记录每次加入红黑树 g_efd 的时间值
};
void recvdata(myevent_s * myevent) {
	cout << myevent->fd << endl;
	return;
}


int maintest()
{
	/*myevent_s * myevent = new myevent_s();

	myevent->fd = 5;
	myevent->call_back = recvdata;
	myevent->events = 10;
	myevent->arg = nullptr;
	
	myevent->call_back(myevent);*/
	vector<int> a = { 2, 3, 5, 6, 7 };
	//for()
	//cout << ;


	//cout << sizeof(A) << endl;
	system("pause");
	return 0;
}