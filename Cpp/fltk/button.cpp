#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <cstdio> // for printf

enum {
	max_buttons = 3,
	button_width = 200,
	button_height = 70,
	button_space_ud = 10, // up / down
	button_space_lf = 15, // left / right
	window_width = button_width + button_space_lf*2,
	window_height = button_height*max_buttons + (max_buttons+1)*button_space_ud
};

enum {
	button_say_hello,
	button_say_goodbye,
	button_quit
};

static const char *button_names[max_buttons] = {
	"Say Hello",
	"Say Goodbye",
	"Quit"
};

static void say_callback(Fl_Widget *, void *user);
static void exit_callback(Fl_Widget *w, void *);

int main()
{
	Fl_Window *win = new Fl_Window(window_width, window_height, "Buttons");
	
	Fl_Button *button[max_buttons];
	for(int i = 0; i < max_buttons; i++)
	{
		button[i] = new Fl_Button(
			button_space_lf,
			button_space_ud + (button_height + button_space_ud)*i,
			button_width,
			button_height,
			button_names[i]);
	}
	win->end();

	button[button_say_hello]->callback(say_callback, (void*)"Hello, world!\n");
	button[button_say_goodbye]->callback(say_callback, (void*)"Goodbye, world!\n");
	button[button_quit]->callback(exit_callback);

	win->show();
	return Fl::run();
}

static void say_callback(Fl_Widget *, void *user)
{
	printf("%s", (const char*)user);
}

static void exit_callback(Fl_Widget *w, void *)
{
	Fl_Widget *p;
	do {
		p = w->parent();
		if(p)
			w = p;
	}
	while(p);

	w->hide();
}
