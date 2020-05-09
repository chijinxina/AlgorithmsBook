//
// Created by chijx on 2020/5/9.
//
#include <iostream>
#include <thread>
#include <unordered_map>
#include "WaitGroup.h"
using namespace  std;

class ZeroEvenOdd {
private:
  int n;
  std::mutex mu;
  std::condition_variable cv;
  bool z;
  bool o;
  WaitGroup wg;
public:
  ZeroEvenOdd(int n) : wg(), mu(), cv(), z(true), o(false){
    this->n = n;
  }
  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for(int i = 1; i <= n; ++i){
      std::unique_lock<std::mutex> lock(mu);
      cv.wait(lock, [this](){
          return this->z;
      });
      printNumber(0);
      z = false;
      cv.notify_all();
    }
    wg.Done();
  }

  void even(function<void(int)> printNumber) {
    for(int i = 2; i <= n; i+=2){
      std::unique_lock<std::mutex> lock(mu);
      cv.wait(lock, [this](){
        return !this->z && this->o;
      });
      printNumber(i);
      z = true;
      o = false;
      cv.notify_all();
    }
    wg.Done();
  }

  void odd(function<void(int)> printNumber) {
    for(int i = 1; i <= n; i+=2){
      std::unique_lock<std::mutex> lock(mu);
      cv.wait(lock, [this](){
        return !this->z && !this->o;
      });
      printNumber(i);
      z = true;
      o = true;
      cv.notify_all();
    }
    wg.Done();
  }

  void AddWg(int i) {
    wg.Add(i);
  }
  void WaitWg() {
    wg.Wait();
  }
};

int main(){
  auto printNumber = [](int i){
      cout << i;
  };
  ZeroEvenOdd instance(10);
  instance.AddWg(3);
  std::thread t1(&ZeroEvenOdd::zero, &instance, std::bind(printNumber, std::placeholders::_1));
  t1.detach();
  std::thread t2(&ZeroEvenOdd::odd, &instance, std::bind(printNumber, std::placeholders::_1));
  t2.detach();
  std::thread t3(&ZeroEvenOdd::even, &instance, std::bind(printNumber, std::placeholders::_1));
  t3.detach();
  instance.WaitWg();
  return 0;
}
