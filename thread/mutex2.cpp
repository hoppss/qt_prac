#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <list>

using namespace std;

// 死锁， 由多个线程多个锁导致的

// 实例
// 两个线程AB
// 线程A, 先锁金锁成功， 然后去锁银锁
// 此时出现了上下文切换
// 线程Ｂ, 先锁银锁，　因为银锁还没有被锁，所以银锁锁成功
// 此时就发生了死锁

// 需要保持两个互斥量lock 的顺序一致， 一般不会发生死锁
/*
t1:  mu1.lock; mu2.lock(); m2.unlock, m1.unlock
t2:  mu1.lock; mu2.lock(); m2.unlock, m1.unlock


or
std::lock_guard<std::mutex> l1(mu1); std::lock_guard<std::mutex> l2(m2);




or  std::lock 模板函数， 需要手工unlock
std::lock(mu1,mu2); // 至少两把锁， 如果其中一个没锁住，等待, 已经锁住的撒开； 直到所有锁都锁住，才往下走

mu1.unlock;
mu2.unlock;  // lock 函数，后面需要显式unlock()



or std::lock 模板函数， +lock_guard 不必手工unlock

std::lock(mu1,mu2);
std::lock_guard<std::mutex> guard1(mu1, std::adopt_lock); // 构造时不调用lock 函数, 用于收养已经锁过的互斥量
std::lock_guard<std::mutex> guard2(mu2, std::adopt_lock);
// 后面不需要手动unlock()

*/