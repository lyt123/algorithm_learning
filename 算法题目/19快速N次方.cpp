//#include <iostream>
//using namespace std;
//int gg = 5;
//int my_func(int fd, int events, void *arg) {
//	gg = 3;
//	return fd;
//}
//
//struct myevent_s {
//	int fd;                 //cfd listenfd
//	int events;             //EPOLLIN  EPLLOUT
//	void *arg;              //指向自己结构体指针
//	int(*my_func)(int fd, int events, void *arg);
//	int status;
//	int len;
//	long last_active;
//};
//
//int main()
//{
//	myevent_s s;
//	s.fd = 3;
//	int res;
//	res = *(s.my_func);
//	cout << gg << endl;
//	system("pause");
//	return 0;
//}