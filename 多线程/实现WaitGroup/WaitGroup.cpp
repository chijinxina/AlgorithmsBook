//
// Created by chijx on 2020/5/9.
//
#include <iostream>
#include "WaitGroup.h"

WaitGroup::WaitGroup() : mu_(), cv_(), counter_(0) {

}
void WaitGroup::Add(int i) {
  counter_ += i;
}
void WaitGroup::Done() {
  counter_ -= 1;
  if(counter_ < 1) {
    cv_.notify_all();
  }
}
void WaitGroup::Wait() {
  std::unique_lock<std::mutex> lock(mu_);
  cv_.wait(lock, [this](){
    return this->counter_ < 1;
  });
}
