#include "Application.hpp"

Application &Application::run() {

  TitleView titleView;
  titleView.goView();

  return this->getInstance();
}