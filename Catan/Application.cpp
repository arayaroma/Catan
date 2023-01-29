#include "Application.hpp"

Application &Application::run() {

  TitleView titleView;
  titleView.goTitleView();

  return this->getInstance();
}