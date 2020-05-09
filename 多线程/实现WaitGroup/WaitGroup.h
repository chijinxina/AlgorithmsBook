//
// Created by chijx on 2020/5/9.
//

#ifndef ALGORITHMSBOOK_WAITGROUP_H
#define ALGORITHMSBOOK_WAITGROUP_H
#include <mutex>
#include <atomic>
#include <condition_variable>

class WaitGroup {
public:
  WaitGroup();
  void Add(int);
  void Done();
  void Wait();
private:
  std::mutex mu_;
  std::condition_variable cv_;
  std::atomic<int> counter_;
};

#endif // ALGORITHMSBOOK_WAITGROUP_H
