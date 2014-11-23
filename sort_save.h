#include <ScreenSaver.h>

class sort_save : public BScreenSaver
{
public:
				sort_save(BMessage *message, image_id id);
	void		StartConfig(BView *view);
	status_t	StartSaver(BView *v, bool preview);
	 virtual void Draw( BView *view, int32 frame );
};

class colorpicker
{
	

	
public:

int Red;
int Blue;
int Green;




void setcolors( int bar, int colors );
void setrandom();

private:
int ranr;
int ranb;
int rang;

};
