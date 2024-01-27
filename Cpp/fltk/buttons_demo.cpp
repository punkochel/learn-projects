#include <Fl/Fl.H>
#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Check_Button.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Widget.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Radio_Round_Button.H>

enum {
	max_radio_buttons = 3,
	max_check_buttons = 1,
	max_buttons = 2,

	rc_button_w = 120, // rc - round / checkbox
	rc_button_h = 20,
	rc_spacing = 10,
	rc_font_size = 90,

	button_w = 150,
	button_h = 40,
	spacing = 10
};

enum {
	button_set,
	button_quit
};

static const char *radio_button_names[max_radio_buttons] = {
	"red",
	"green",
	"blue"
};

static const char *check_button_names[max_check_buttons] = {
	"show letter"
};

static const char *button_names[max_buttons] = {
	"Set",
	"Quit"
};

static const int colors[] = {
	FL_RED,
	FL_GREEN,
	FL_BLUE
};

struct controls {
	Fl_Radio_Round_Button *r_button[max_radio_buttons];
	Fl_Check_Button *ch_button[max_check_buttons];
	Fl_Box *box;
};

/*
	Forwards
*/
static void exit_callback(Fl_Widget *w, void *);
static void set_callback(Fl_Widget *, void *user);

int main()
{
	/*
		Drawing GUI
	*/
	int win_w = spacing + (button_w + spacing)*max_buttons;
	int win_h = (rc_button_h + rc_spacing)*(max_radio_buttons + max_check_buttons)
		+ button_h + spacing*2;
	Fl_Window *win = new Fl_Window(win_w, win_h, "Buttons Demo");

	controls *c = new controls;
	Fl_Button *button[max_buttons];
	int pos_y = rc_spacing;

	for(int i = 0; i < max_radio_buttons; i++)
	{
		c->r_button[i] = new Fl_Radio_Round_Button(
			rc_spacing,
			pos_y,
			rc_button_w,
			rc_button_h,
			radio_button_names[i]);
		pos_y += rc_button_h + rc_spacing;
	}
	c->r_button[0]->value(1); // Show background on start

	for(int i = 0; i < max_check_buttons; i++)
	{
		c->ch_button[i] = new Fl_Check_Button(
			rc_spacing,
			pos_y,
			rc_button_w,
			rc_button_h,
			check_button_names[i]);
		pos_y += rc_button_h + rc_spacing;
	}
	c->ch_button[0]->value(1); // Show label on start

	for(int i = 0; i < max_buttons; i++)
	{
		button[i] = new Fl_Button(
			spacing + (button_w + spacing)*i,
			pos_y,
			button_w,
			button_h,
			button_names[i]);
	}

	c->box = new Fl_Box(
		rc_button_w + rc_spacing,
		rc_spacing, win_w - rc_button_w - spacing*2, win_h - button_h - spacing*3);
	c->box->labelsize(rc_font_size);
	c->box->labelcolor(FL_WHITE);
	c->box->box(FL_FLAT_BOX);
	set_callback(0, (void *)c);

	win->end();
	win->show();

	/*
		Binding handlers
	*/
	button[button_quit]->callback(exit_callback);
	button[button_set]->callback(set_callback, (void *)c);
	return Fl::run();
}

/*
	Button Handlers
*/
static void set_callback(Fl_Widget *, void *user)
{
	controls *c = (controls *)user;
	for(int i = 0; i < max_radio_buttons; i++)
	{
		if(c->r_button[i]->value())
		{
			c->box->color(colors[i]);
			break;
		}
	}
	c->box->label(c->ch_button[0]->value() ? "A" : "");
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