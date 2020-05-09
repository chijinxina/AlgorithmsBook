//
// Created by chijx on 2020/5/9.
//

#include <iostream>
#include <thread>

using namespace std;

class FooBar {
private:
  int n;
  std::condition_variable cv;
  std::mutex mu;
  bool isFoo;
public:
  FooBar(int n) : cv(), mu(), isFoo(true) {
    this->n = n;
  }
  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lock(mu);
      // cout << "foo thread:" << isFoo <<endl;
      cv.wait(lock, [=](){
        return isFoo;
      });
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();

      // 状态改变，通知另一个线程
      isFoo = false;
      cv.notify_all();
    }
  }
  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lock(mu);
      // cout << "bar thread:" << isFoo <<endl;
      cv.wait(lock, [=](){
        return !isFoo;
      });
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      isFoo = true;
      cv.notify_all();
    }
  }
};

int main() {
  FooBar fb(10);
  auto printBar = [](){ cout<<"bar "; };
  auto printFoo = [](){ cout<<"foo "; };
  std::thread t1(&FooBar::bar, &fb, printBar);
  std::thread t2(&FooBar::foo, &fb, printFoo);

  t1.join();
  t2.join();
  return 0;
}


