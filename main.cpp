#include <iostream>
#include <vector>
#include "Thread.h"
#include <X11/Xlib.h>
#include <unistd.h>


using namespace std;


int main()
{
  //First, open a display and set up a window
  Display *display = XOpenDisplay(NULL);
  if (!display)
  {
    cerr << "Error: Cannot Open Display" << endl;
    return 1;
  }

  int screenNum = DefaultScreen(display);
  Window root = RootWindow(display, screenNum);

  Window background = XCreateSimpleWindow(display, root, 0, 0, 400, 300, 1, BlackPixel(display, screenNum), WhitePixel(display, screenNum));

  XSelectInput(display, background, ExposureMask | KeyPressMask);

  XMapWindow(display, background);

  GC gc = XCreateGC(display, background, 0, NULL);

  XColor blue;
  Colormap colormap = DefaultColormap(display, screenNum);
  XParseColor(display, colormap, "#001AFF", &blue);
  XAllocColor(display, colormap, &blue);


  XSetWindowBackground(display, background, blue.pixel);
  
  XSetForeground(display, gc, BlackPixel(display, screenNum));

  XEvent event;
  int count = 0;
  while (true)
  {

    // Clear the window and redraw the text
    XClearWindow(display, background);
    string message = to_string(count);
    XDrawString(display, background, gc, 10, 30, message.data(), message.length());

    // Introduce a delay (usleep) to control the update rate
    usleep(1000); // Sleep for 1 second
    count++;

  }

  XFreeGC(display, gc);
  XDestroyWindow(display, background);
  XCloseDisplay(display);
  return 0;

}