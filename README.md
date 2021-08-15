# philosophers
I’ve never thought philosophy would be so deadly | école 42

*in process*

* [Introduction](#introduction)
* [Usage](#usage)
* [Philos_and_forks_map](#philos_and_forks_map)
* [New Functions Allowed](#new_functions_allowed)
* [Step by step](#step_by_step)
* [Study resources](#study_resources)
* [Work Diary](#work_diary)

## introduction

This project is about learning the basics of threading a process, learning how to make threads and discover the mutex.
______________
*Several philosophers are sitting at a round table doing one of three things: eating, thinking, or sleeping. While eating, they are not thinking or sleeping, while sleeping, they are not eating or thinking and of course, while thinking, they are not eating or sleeping. The philosophers sit at a circular table with a large bowl of spaghetti in the center. There are some forks on the table,  it is assumed that a philosopher must eat with two forks, one for each hand. The philosophers must never be starving and every philosofer needs to eat. Philosophers don’t speak with each other and don’t know when another philosopher is about to die. Each time a philosopher has finished eating, he will drop his forks and start sleeping. When a philosopher is done sleeping, he will start thinking. The simulation stops when a philosopher dies.*
______________
## usage


## philos_and_forks_map

![philos forks](https://user-images.githubusercontent.com/63563271/129487272-adfb6d27-f57d-4e85-8042-8bc09b9b086b.png)


## new_functions_allowed

name  | prototype | description |
---|------|------|
[**usleep**](https://man7.org/linux/man-pages/man3/usleep.3.html) | int usleep(useconds_t usec); |shall cause the calling thread to be suspended from execution until either the number of realtime microseconds specified by the argument useconds has elapsed or a signal is delivered to the calling thread and its action is to invoke a signal-catching function or to terminate the process. The suspension time may be longer than requested due to the scheduling of other activity by the system.			|
[**gettimeofday**](https://c-for-dummies.com/blog/?p=4236) | int gettimeofday( struct timeval *, struct tzp * ); | fills two structures with details about the current time of day	|
[**pthread_create**](https://man7.org/linux/man-pages/man3/pthread_create.3.html) | int pthread_create(pthread_t * restrict thread, const pthread_attr_t * restrict attr, void *(* start_routine)(void *), void * restrict arg);| create a new thread |
[**pthread_detach**](https://man7.org/linux/man-pages/man3/pthread_detach.3.html) | int pthread_detach(pthread_t thread); | marks the thread identified by thread as detached.  When a detached thread terminates, its resources are automatically released back to the system without    the need for another thread to join with the terminated thread. Attempting to detach an already detached thread results in unspecified behavior.|
[**pthread_join**](https://man7.org/linux/man-pages/man3/pthread_join.3.html) | int pthread_join(pthread_t thread, void ** retval); | join with a terminated thread. The function waits for the thread specified by thread to terminate.  If that thread has already terminated, then      pthread_join() returns immediately.  The thread specified by thread must be joinable. |
[**pthread_mutex_init**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_init.html) | int pthread_mutex_init(pthread_mutex_t * mutex, const pthread_mutexattr_t * attr); | initialises the mutex referenced by mutex with attributes specified by attr. If attr is NULL, the default mutex attributes are used; the effect is the same as passing the address of a default mutex attributes object. Upon successful initialisation, the state of the mutex becomes initialised and unlocked.	|
[**pthread_mutex_destroy**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_init.html) | int pthread_mutex_destroy(pthread_mutex_t * mutex); |destroys the mutex object referenced by mutex; the mutex object becomes, in effect, uninitialised.|
[**pthread_mutex_lock**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_lock.html) | int pthread_mutex_lock(pthread_mutex_t * mutex); | locks the object referenced by mutex. If the mutex is already locked, the calling thread blocks until the mutex becomes available. This operation returns with the mutex object referenced by mutex in the locked state with the calling thread as its owner			|
[**pthread_mutex_unlock**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_lock.html) | int pthread_mutex_unlock(pthread_mutex_t * mutex); |releases the mutex object referenced by mutex.	|

## step_by_step

## study_resources

* [Unix Threads in C -playlist](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

## work_diary

<details>
  <summary>Click to expand </summary>
  
  * 08/08, 09/08, 10/08: Thread studies
  * 11/08: Error handler and arguments parser
