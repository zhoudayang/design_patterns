#pragma once

#include <iostream>
#include <boost/shared_ptr.hpp>

using std::cout;
using std::endl;
using std::shared_ptr;

class Worker;

class State
{
  public:
    explicit State(Worker* worker)
      : worker_(worker)
    { }

    virtual void doing() = 0;

    virtual ~State() { }

  protected:
    Worker* worker_;
};

class WorkingState : public State
{
  public:
    explicit WorkingState(Worker* worker)
      : State(worker)
    { }

    virtual void doing() override;

    virtual ~WorkingState() { }
};

class RestState : public State
{
  public:
    explicit RestState(Worker* worker)
      : State(worker)
    { }

    virtual void doing() override;

    virtual ~RestState() { }
};

class Worker
{
  public:
    explicit Worker(int hour)
      : workingState_(),
        restState_(),
        curState_(),
        hour_(hour)
    {
      init_state();
    }

    void set_working_state()
    {
      curState_ = workingState_;
    }

    void set_rest_state()
    {
      curState_ = restState_;
    }

    void request()
    {
      curState_->doing();
    }

    int get_hour() const { return hour_; }

    void set_hour(int hour) { hour_ = hour; }

  private:

    void init_state()
    {
      workingState_ = shared_ptr<State>(new WorkingState(this));
      restState_ = shared_ptr<State>(new RestState(this));
      if(hour_ >= 8 && hour_ <= 17)
      {
        curState_ = workingState_;
      }
      else
      {
        curState_ = restState_;
      }
    }

    shared_ptr<State> workingState_;
    shared_ptr<State> restState_;
    // current working state
    shared_ptr<State> curState_;

    int hour_;
};
