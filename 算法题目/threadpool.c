//#include <stdlib.h>
//#include <pthread.h>
//#include <unistd.h>
//#include <assert.h>
//#include <stdio.h>
//#include <string.h>
//#include <signal.h>
//#include <errno.h>
//#include "threadpool.h"
//
//#define DEFAULT_TIME 10                 /*10s���һ��*/
//#define MIN_WAIT_TASK_NUM 10            /*���queue_size > MIN_WAIT_TASK_NUM ����µ��̵߳��̳߳�*/ 
//#define DEFAULT_THREAD_VARY 10          /*ÿ�δ����������̵߳ĸ���*/
//#define true 1
//#define false 0
//
//typedef struct {
//	void *(*function)(void *);          /* ����ָ�룬�ص����� */
//	void *arg;                          /* ���溯���Ĳ��� */
//} threadpool_task_t;                    /* �����߳�����ṹ�� */
//
//										/* �����̳߳������Ϣ */
//struct threadpool_t {
//	pthread_mutex_t lock;               /* ������ס���ṹ�� */
//	pthread_mutex_t thread_counter;     /* ��¼æ״̬�̸߳���de�� -- busy_thr_num */
//	pthread_cond_t queue_not_full;      /* �����������ʱ�����������߳��������ȴ����������� */
//	pthread_cond_t queue_not_empty;     /* ��������ﲻΪ��ʱ��֪ͨ�ȴ�������߳� */
//
//	pthread_t *threads;                 /* ����̳߳���ÿ���̵߳�tid������ */
//	pthread_t adjust_tid;               /* ������߳�tid */
//	threadpool_task_t *task_queue;      /* ������� */
//
//	int min_thr_num;                    /* �̳߳���С�߳��� */
//	int max_thr_num;                    /* �̳߳�����߳��� */
//	int live_thr_num;                   /* ��ǰ����̸߳��� */
//	int busy_thr_num;                   /* æ״̬�̸߳��� */
//	int wait_exit_thr_num;              /* Ҫ���ٵ��̸߳��� */
//
//	int queue_front;                    /* task_queue��ͷ�±� */
//	int queue_rear;                     /* task_queue��β�±� */
//	int queue_size;                     /* task_queue����ʵ�������� */
//	int queue_max_size;                 /* task_queue���п��������������� */
//
//	int shutdown;                       /* ��־λ���̳߳�ʹ��״̬��true��false */
//};
//
///**
//* @function void *threadpool_thread(void *threadpool)
//* @desc the worker thread
//* @param threadpool the pool which own the thread
//*/
//void *threadpool_thread(void *threadpool);
//
///**
//* @function void *adjust_thread(void *threadpool);
//* @desc manager thread
//* @param threadpool the threadpool
//*/
//void *adjust_thread(void *threadpool);
//
///**
//* check a thread is alive
//*/
//int is_thread_alive(pthread_t tid);
//int threadpool_free(threadpool_t *pool);
//
//threadpool_t *threadpool_create(int min_thr_num, int max_thr_num, int queue_max_size)
//{
//	int i;
//	threadpool_t *pool = NULL;
//	do {
//		if ((pool = (threadpool_t *)malloc(sizeof(threadpool_t))) == NULL) {
//			printf("malloc threadpool fail");
//			break;/*����do while*/
//		}
//
//		pool->min_thr_num = min_thr_num;
//		pool->max_thr_num = max_thr_num;
//		pool->busy_thr_num = 0;
//		pool->live_thr_num = min_thr_num;               /* ���ŵ��߳��� ��ֵ=��С�߳��� */
//		pool->queue_size = 0;                           /* ��0����Ʒ */
//		pool->queue_max_size = queue_max_size;
//		pool->queue_front = 0;
//		pool->queue_rear = 0;
//		pool->shutdown = false;                         /* ���ر��̳߳� */
//
//														/* ��������߳��������� �������߳����鿪�ٿռ�, ������ */
//		pool->threads = (pthread_t *)malloc(sizeof(pthread_t)*max_thr_num);
//		if (pool->threads == NULL) {
//			printf("malloc threads fail");
//			break;
//		}
//		memset(pool->threads, 0, sizeof(pthread_t)*max_thr_num);
//
//		/* ���п��ٿռ� */
//		pool->task_queue = (threadpool_task_t *)malloc(sizeof(threadpool_task_t)*queue_max_size);
//		if (pool->task_queue == NULL) {
//			printf("malloc task_queue fail");
//			break;
//		}
//
//		/* ��ʼ������������������ */
//		if (pthread_mutex_init(&(pool->lock), NULL) != 0
//			|| pthread_mutex_init(&(pool->thread_counter), NULL) != 0
//			|| pthread_cond_init(&(pool->queue_not_empty), NULL) != 0
//			|| pthread_cond_init(&(pool->queue_not_full), NULL) != 0)
//		{
//			printf("init the lock or cond fail");
//			break;
//		}
//
//		/* ���� min_thr_num �� work thread */
//		for (i = 0; i < min_thr_num; i++) {
//			pthread_create(&(pool->threads[i]), NULL, threadpool_thread//, (void *)pool);/*poolָ��ǰ�̳߳�*/
//			printf("start thread 0x%x...\n", (unsigned int)pool->threads[i]);
//		}
//		pthread_create(&(pool->adjust_tid), NULL, adjust_thread, (void *)pool);/* �����������߳� */
//
//		return pool;
//
//	} while (0);
//
//	threadpool_free(pool);      /* ǰ��������ʧ��ʱ���ͷ�poll�洢�ռ� */
//
//	return NULL;
//}
//
///* ���̳߳��� ���һ������ */
//int threadpool_add(threadpool_t *pool, void*(*function)(void *arg), void *arg)
//{
//	pthread_mutex_lock(&(pool->lock));
//
//	/* ==Ϊ�棬�����Ѿ����� ��wait���� */
//	while ((pool->queue_size == pool->queue_max_size) && (!pool->shutdown)) {
//		pthread_cond_wait(&(pool->queue_not_full), &(pool->lock));
//	}
//	if (pool->shutdown) {
//		pthread_mutex_unlock(&(pool->lock));
//	}
//
//	/* ��� �����߳� ���õĻص����� �Ĳ���arg */
//	if (pool->task_queue[pool->queue_rear].arg != NULL) {
//		free(pool->task_queue[pool->queue_rear].arg);
//		pool->task_queue[pool->queue_rear].arg = NULL;
//	}
//	/*����������������*/
//	pool->task_queue[pool->queue_rear].function = *-function;
//	pool->task_queue[pool->queue_rear].arg = arg;
//	pool->queue_rear = (pool->queue_rear + 1) % pool->queue_max_size;       /* ��βָ���ƶ�, ģ�⻷�� */
//	pool->queue_size++;
//
//	/*���������󣬶��в�Ϊ�գ������̳߳��� �ȴ�����������߳�*/
//	pthread_cond_signal(&(pool->queue_not_empty));
//	pthread_mutex_unlock(&(pool->lock));
//
//	return 0;
//}
//
///* �̳߳��и��������߳� */
//void *threadpool_thread(void *threadpool)
//{
//	threadpool_t *pool = (threadpool_t *)threadpool;
//	threadpool_task_t task;
//
//	while (true) {
//		/* Lock must be taken to wait on conditional variable */
//		/*�մ������̣߳��ȴ���������������񣬷��������ȴ������������������ٻ��ѽ�������*/
//		pthread_mutex_lock(&(pool->lock));
//
//		/*queue_size == 0 ˵��û�����񣬵� wait ����������������, ��������������while*/
//		while ((pool->queue_size == 0) && (!pool->shutdown)) {
//			printf("thread 0x%x is waiting\n", (unsigned int)pthread_self());
//			pthread_cond_wait(&(pool->queue_not_empty), &(pool->lock));
//
//			/*���ָ����Ŀ�Ŀ����̣߳����Ҫ�������̸߳�������0�������߳�*/
//			if (pool->wait_exit_thr_num > 0) {
//				pool->wait_exit_thr_num--;
//
//				/*����̳߳����̸߳���������Сֵʱ���Խ�����ǰ�߳�*/
//				if (pool->live_thr_num > pool->min_thr_num) {
//					printf("thread 0x%x is exiting\n", (unsigned int)pthread_self());
//					pool->live_thr_num--;
//					pthread_mutex_unlock(&(pool->lock));
//					pthread_exit(NULL);
//				}
//			}
//		}
//
//		/*���ָ����true��Ҫ�ر��̳߳����ÿ���̣߳������˳�����*/
//		if (pool->shutdown) {
//			pthread_mutex_unlock(&(pool->lock));
//			printf("thread 0x%x is exiting\n", (unsigned int)pthread_self());
//			pthread_exit(NULL);     /* �߳����н��� */
//		}
//
//		/*������������ȡ����, ��һ�����Ӳ���*/
//		task.function = pool->task_queue[pool->queue_front].function;
//		task.arg = pool->task_queue[pool->queue_front].arg;
//
//		pool->queue_front = (pool->queue_front + 1) % pool->queue_max_size;       /* ���ӣ�ģ�⻷�ζ��� */
//		pool->queue_size--;
//
//		/*֪ͨ�������µ�������ӽ���*/
//		pthread_cond_broadcast(&(pool->queue_not_full));
//
//		/*����ȡ���������� �̳߳��� �ͷ�*/
//		pthread_mutex_unlock(&(pool->lock));
//
//		/*ִ������*/
//		printf("thread 0x%x start working\n", (unsigned int)pthread_self());
//		pthread_mutex_lock(&(pool->thread_counter));                            /*æ״̬�߳���������*/
//		pool->busy_thr_num++;                                                   /*æ״̬�߳���+1*/
//		pthread_mutex_unlock(&(pool->thread_counter));
//		(*(task.function))(task.arg);                                           /*ִ�лص���������*/
//																				//task.function(task.arg);                                              /*ִ�лص���������*/
//
//																				/*�����������*/
//		printf("thread 0x%x end working\n", (unsigned int)pthread_self());
//		pthread_mutex_lock(&(pool->thread_counter));
//		pool->busy_thr_num--;                                       /*�����һ������æ״̬���߳���-1*/
//		pthread_mutex_unlock(&(pool->thread_counter));
//	}
//
//	pthread_exit(NULL);
//}
//
///* �����߳� */
//void *adjust_thread(void *threadpool)
//{
//	int i;
//	threadpool_t *pool = (threadpool_t *)threadpool;
//	while (!pool->shutdown) {
//
//		sleep(DEFAULT_TIME);                                    /*��ʱ ���̳߳ع���*/
//
//		pthread_mutex_lock(&(pool->lock));
//		int queue_size = pool->queue_size;                      /* ��ע ������ */
//		int live_thr_num = pool->live_thr_num;                  /* ��� �߳��� */
//		pthread_mutex_unlock(&(pool->lock));
//
//		pthread_mutex_lock(&(pool->thread_counter));
//		int busy_thr_num = pool->busy_thr_num;                  /* æ�ŵ��߳��� */
//		pthread_mutex_unlock(&(pool->thread_counter));
//
//		/* �������߳� �㷨�� ������������С�̳߳ظ���, �Ҵ����߳�����������̸߳���ʱ �磺30>=10 && 40<100*/
//		if (queue_size >= MIN_WAIT_TASK_NUM && live_thr_num < pool->max_thr_num) {
//			pthread_mutex_lock(&(pool->lock));
//			int add = 0;
//
//			/*һ������ DEFAULT_THREAD ���߳�*/
//			for (i = 0; i < pool->max_thr_num && add < DEFAULT_THREAD_VARY
//				&& pool->live_thr_num < pool->max_thr_num; i++) {
//				if (pool->threads[i] == 0 || !is_thread_alive(pool->threads[i])) {
//					pthread_create(&(pool->threads[i]), NULL, threadpool_thread, (void *)pool);
//					add++;
//					pool->live_thr_num++;
//				}
//			}
//
//			pthread_mutex_unlock(&(pool->lock));
//		}
//
//		/* ���ٶ���Ŀ����߳� �㷨��æ�߳�X2 С�� �����߳��� �� �����߳��� ���� ��С�߳���ʱ*/
//		if ((busy_thr_num * 2) < live_thr_num  &&  live_thr_num > pool->min_thr_num) {
//
//			/* һ������DEFAULT_THREAD���߳�, �S�C10������ */
//			pthread_mutex_lock(&(pool->lock));
//			pool->wait_exit_thr_num = DEFAULT_THREAD_VARY;      /* Ҫ���ٵ��߳��� ����Ϊ10 */
//			pthread_mutex_unlock(&(pool->lock));
//
//			for (i = 0; i < DEFAULT_THREAD_VARY; i++) {
//				/* ֪ͨ���ڿ���״̬���߳�, ���ǻ�������ֹ*/
//				pthread_cond_signal(&(pool->queue_not_empty));
//			}
//		}
//	}
//
//	return NULL;
//}
//
//int threadpool_destroy(threadpool_t *pool)
//{
//	int i;
//	if (pool == NULL) {
//		return -1;
//	}
//	pool->shutdown = true;
//
//	/*�����ٹ����߳�*/
//	pthread_join(pool->adjust_tid, NULL);
//
//	for (i = 0; i < pool->live_thr_num; i++) {
//		/*֪ͨ���еĿ����߳�*/
//		pthread_cond_broadcast(&(pool->queue_not_empty));
//	}
//	for (i = 0; i < pool->live_thr_num; i++) {
//		pthread_join(pool->threads[i], NULL);
//	}
//	threadpool_free(pool);
//
//	return 0;
//}
//
//int threadpool_free(threadpool_t *pool)
//{
//	if (pool == NULL) {
//		return -1;
//	}
//
//	if (pool->task_queue) {
//		free(pool->task_queue);
//	}
//	if (pool->threads) {
//		free(pool->threads);
//		pthread_mutex_lock(&(pool->lock));
//		pthread_mutex_destroy(&(pool->lock));
//		pthread_mutex_lock(&(pool->thread_counter));
//		pthread_mutex_destroy(&(pool->thread_counter));
//		pthread_cond_destroy(&(pool->queue_not_empty));
//		pthread_cond_destroy(&(pool->queue_not_full));
//	}
//	free(pool);
//	pool = NULL;
//
//	return 0;
//}
//
//int threadpool_all_threadnum(threadpool_t *pool)
//{
//	int all_threadnum = -1;
//	pthread_mutex_lock(&(pool->lock));
//	all_threadnum = pool->live_thr_num;
//	pthread_mutex_unlock(&(pool->lock));
//	return all_threadnum;
//}
//
//int threadpool_busy_threadnum(threadpool_t *pool)
//{
//	int busy_threadnum = -1;
//	pthread_mutex_lock(&(pool->thread_counter));
//	busy_threadnum = pool->busy_thr_num;
//	pthread_mutex_unlock(&(pool->thread_counter));
//	return busy_threadnum;
//}
//
//int is_thread_alive(pthread_t tid)
//{
//	int kill_rc = pthread_kill(tid, 0);     //��0���źţ������߳��Ƿ���
//	if (kill_rc == ESRCH) {
//		return false;
//	}
//
//	return true;
//}
//
///*����*/
//
//#if 1
///* �̳߳��е��̣߳�ģ�⴦��ҵ�� */
//void *process(void *arg)
//{
//	printf("thread 0x%x working on task %d\n ", (unsigned int)pthread_self(), *(int *)arg);
//	sleep(1);
//	printf("task %d is end\n", *(int *)arg);
//
//	return NULL;
//}
//int main(void)
//{
//	/*threadpool_t *threadpool_create(int min_thr_num, int max_thr_num, int queue_max_size);*/
//
//	threadpool_t *thp = threadpool_create(3, 100, 100);/*�����̳߳أ�������С3���̣߳����100���������100*/
//	printf("pool inited");
//
//	//int *num = (int *)malloc(sizeof(int)*20);
//	int num[20], i;
//	for (i = 0; i < 20; i++) {
//		num[i] = i;
//		printf("add task %d\n", i);
//		threadpool_add(thp, process, (void*)&num[i]);     /* ���̳߳���������� */
//	}
//	sleep(10);                                          /* �����߳�������� */
//	threadpool_destroy(thp);
//
//	return 0;
//}
//
//#endif
