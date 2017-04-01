#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <assert.h>

using std::cout;
using std::endl;

class Command
{
  public:
   virtual void execute() = 0;
   virtual void undo() = 0;
};

// receiver
class Light
{
  public:
    Light() = default;

    void on()
    {
      cout << "the Light is on" << endl;
    }

    void off()
    {
      cout << "the light is off" << endl;
    }
};

// concrete command
class LightCommand : public Command
{
  public:
    explicit LightCommand(std::unique_ptr<Light>&& light)
      : light_(std::move(light)),
        on_(false)
    {

    }

    // turn off the light
    virtual void execute() override
    {
      light_->on();
      on_ = true;
    }

    // taggle button indeed
    virtual void undo() override
    {
      if(on_)
      {
        light_->off();
      }
      else
      {
        light_->on();
      }
      on_ = !on_;
    }

  private:
    std::unique_ptr<Light> light_;
    // store light working state
    bool on_;
};

// Invoker, 调用者
class Controller
{
  public:
    Controller()
      : commands_()
    { }

    void add_command(std::unique_ptr<Command>&& command)
    {
      commands_.push_back(std::move(command));
    }

    void onButtonPushed(size_t pos)
    {
      assert(pos >= 0 && pos < commands_.size());
      commands_[pos]->execute();
    }

    void offButtonPushed(size_t pos)
    {
      assert(pos >= 0 && pos < commands_.size());
      commands_[pos]->undo();
    }

  private:
    std::vector<std::unique_ptr<Command>> commands_;
};


