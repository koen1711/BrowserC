#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include "Loader/Renderer.h"
#include "EventHandler/EventHandler.h"

class App {

    public:
        App(int argc, char** argv);
        ~App();

        void Run();

    private:
        GtkWidget* webiew_;
        GtkWidget* window_;
        Renderer* renderer_;
        EventHandler* eventHandler_;
};  


