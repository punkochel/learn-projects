#include <FL/Enumerations.H>
#include <FL/Fl_Button.H>
#include <Fl/Fl.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Window.H>
#include <cstdio> // for printf

enum {
	max_buttons = 3,
	space = 10,
	button_w = 100,
	button_h = 40,
	label_w = 50,
	input_h = 30,
	input_w = button_w*max_buttons - label_w + space*2
};

enum {
	button_say,
	button_clear,
	button_quit
};

static const char *button_names[max_buttons] = {
	"Say",
	"Clear",
	"Quit"
};

static void say_callback(Fl_Widget *, void *user)
{
	printf("%s\n", ((Fl_Input *)user)->value());
	((Fl_Input *)user)->take_focus();
}

static void clear_callback(Fl_Widget *, void *user)
{
	((Fl_Input *)user)->value("");
	((Fl_Input *)user)->take_focus();
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

int main()
{
	int win_w = button_w*max_buttons + space*(max_buttons + 1);
	int win_h = button_h + input_h + space*3;
	Fl_Window *win = new Fl_Window(win_w, win_h, "Input");

	Fl_Input *field = new Fl_Input(
		space + label_w, space, input_w, input_h, "Type:");
	field->callback(say_callback, (void *)field);
	field->when(FL_WHEN_ENTER_KEY | FL_WHEN_NOT_CHANGED); // output when pressing enter

	Fl_Button *button[max_buttons];
	for(int i = 0; i < max_buttons; i++)
	{
		button[i] = new Fl_Button(
			space + (space + button_w)*i,
			win_h - button_h - space,
			button_w,
			button_h,
			button_names[i]);
	}

	button[button_say]->callback(say_callback, (void *)field);
	button[button_clear]->callback(clear_callback, (void *)field);
	button[button_quit]->callback(exit_callback);

	win->end();
	win->show();
	return Fl::run();
}