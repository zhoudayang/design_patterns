#include "state.h"

int main(int argc, char* argv[])
{
  Worker worker(10);
  cout << "current hour is " << worker.get_hour() << endl;
  worker.request();

  worker.set_hour(19);
  cout << "current hour is " << worker.get_hour() << endl;
  worker.request();

  worker.set_hour(13);
  cout << "current hour is " << worker.get_hour() << endl;
  worker.request();

  worker.set_hour(24);
  cout << "current hour is " << worker.get_hour() << endl;
  worker.request();

  return 0;
}
