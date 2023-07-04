#include <AppCore/App.h>
#include <AppCore/Window.h>
#include <AppCore/Overlay.h>
#include "render/App.h"
#include "datamanager/AppData.h"

AppData app_data = AppData();

int main() {
  // copy the contents of /assets folder to the appdata folder
  // this is where we will store all of our data
  system(("cp -r ./assets " + app_data.getPath()).c_str());

  MainApp app;
  app.Run();

  return 0;
}

