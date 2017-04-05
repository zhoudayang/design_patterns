#include "state.h"

void WorkingState::doing()
{
  int hour = worker_->get_hour();
  if(hour >= 8 && hour <= 17)
  {
    cout << "workers are working now!" << endl;
  }
  else
  {
    worker_->set_rest_state();
    worker_->request();
  }
}

void RestState::doing()
{
  int hour = worker_->get_hour();
  if(hour >=8 && hour <= 17)
  {
    worker_->set_working_state();
    worker_->request();
  }
  else
  {
    cout << "workers are sleeping now!" << endl;
  }
}
