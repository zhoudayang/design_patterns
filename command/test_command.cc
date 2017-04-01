#include "command.h"

int main(int argc, char* argv[])
{
  std::unique_ptr<Light> light(new Light());
  std::unique_ptr<Command> light_command(new LightCommand(std::move(light)));

  Controller controller;
  controller.add_command(std::move(light_command));

  controller.onButtonPushed(0);
  controller.offButtonPushed(0);

  controller.offButtonPushed(0);
  controller.offButtonPushed(0);

  return 0;
}
