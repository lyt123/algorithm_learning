#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define BUFLEN 20

/* ���������ļ������������Ϣ */

struct myevent_s {
	int fd;                                                 //Ҫ�������ļ�������
	int events;                                             //��Ӧ�ļ����¼�
	void *arg;                                              //���Ͳ���
	void(*call_back)(myevent_s * myevent);       //�ص�����
	int status;                                             //�Ƿ��ڼ���:1->�ں������(����), 0->����(������)
	char buf[BUFLEN];
	int len;
	long last_active;                                       //��¼ÿ�μ������� g_efd ��ʱ��ֵ
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