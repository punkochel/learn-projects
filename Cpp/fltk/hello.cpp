#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

enum {
	window_width = 300,
	window_height = 100
};

int main()
{
	Fl_Window *win = new Fl_Window(window_width, window_height, "Hello");
	Fl_Box *box = new Fl_Box(0, 0, window_width, window_height, "Hello, world!");
	box->labelsize(32);
	win->end();
	win->show();
	return Fl::run();
}

/*
	dep: libfltk1.3-dev
	clang++ -Wall -g hello.cpp -o hello -lfltk
*/