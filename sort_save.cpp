#include "sort_save.h"
#include <StringView.h>
#include <String.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <View.h>
#include <OS.h>
// MAIN INSTANTIATION FUNCTION
int x=260;
int swp;
unsigned int count;
int bar[50][4];
int row[50];
int j = 1;
BRect r;
BRect rr;	
int lr = (rand() % 2);
int display = (rand() %3);
bigtime_t idle = idle_time();
int useraction;
float h1 = (rand() %3);
unsigned int dly = (rand()%80000);
int updown = (rand()%100);
colorpicker palate1;

extern "C" _EXPORT BScreenSaver *instantiate_screen_saver(BMessage *message, image_id image)
{
	return new sort_save(message, image);
}

sort_save::sort_save(BMessage *message, image_id image)
 : BScreenSaver(message, image)
{
}

void sort_save::StartConfig(BView *view)
{
	view->AddChild(new BStringView(BRect(10, 10, 300, 55), B_EMPTY_STRING, "Sort Saver   by Jim Saxton "));
}

status_t sort_save::StartSaver(BView* view, bool preview )
{
	if( preview ) return B_ERROR;
	SetTickSize(50000);
	return B_OK;
}

//_________________________________________________________________

void swapbars(BView *view,int j,int swp, int colors)
{
	
int tmp;
int tmp1;
int hit;




	tmp= bar[j][3];
	tmp1 = bar[swp][3];
	bar [j][3]=tmp1;
	bar [swp][3]=tmp;
	
	
	
	
	
	
	int screenheight = (view->Bounds().IntegerHeight());
	
	int screenwidth = (view->Bounds().IntegerWidth());
	int wid=screenwidth/100;
	hit= screenheight / 54;
	if (updown >= 90)
	hit= screenheight / 55;
	float bhight = hit *.3* h1;
	
	int row=bar[j][3];
	if (row==0) 
	r.top = -50;
	else
	{
		if (updown < 90)
		r.top = row*(hit+1);
		
		if (updown>= 90)
		r.top = ((abs(row-51))*(hit+1));
	}	
	//r.top = jjj*(hit+1);
	rr.top=r.top;
	rr.left=0;
	rr.right=screenwidth;
	rr.bottom=r.top + bhight+1;
	view->FillRect(rr, B_SOLID_LOW);
	 row=bar[swp][3];
	
	//r.top = jjj*(hit+1);
	rr.top=r.top;
	rr.left=0;
	rr.right=screenwidth;
	rr.bottom=r.top + bhight;
	view->FillRect(rr, B_SOLID_LOW);
	usleep(.5*dly);
	
	for ( tmp = 1;tmp < 3; tmp ++)
	{ 
	if (tmp == 2)
		j = swp;
		
	int barlength = bar[j][1];
	 row=bar[j][3];
	 if (row==0) 
	r.top = -50;
	else
	{
		if (updown < 90)
		r.top = row*(hit+1);
		if (updown>= 90)
		r.top = (abs(row-51))*(hit+1);
	}	
	//r.top = jjj*(hit+1);
	rr.top=r.top;
	rr.left=0;
	rr.right=screenwidth;
	rr.bottom=r.top + bhight+1;
	
	
	switch(display)
	{
		case 1:
		r.left = (rand() % screenwidth - barlength);
		break;
		
		case 2:
		lr = rand() % 50;
		if (lr > 25)
			r.left = 0;
		if (lr <= 25)	
			r.left =  screenwidth - (barlength*wid);
			
		break;
			
		case 3:
		lr = rand() % 50;
		if (lr > 25)	 
			r.left = 150;
		if (lr <= 25)
			r.left =  (screenwidth - (barlength*wid)) -150;
			
			
		break;
		
	
		
		case 4:
		r.left =(screenwidth/2)-(25*wid);
		break;
		
		case 5:
		lr = rand() % 50;
		if (lr > 25)	 
			r.left =(screenwidth/2)-(25*wid);
		if (lr <= 25)
			r.left =  (screenwidth/2)+(25*wid)-(barlength*wid);		
		break;
		
		case 6:
		r.left =  (screenwidth/2)+(25*wid)-(barlength*wid);		
		break;
		case 7:
		r.left =  (screenwidth/2)-(barlength*wid)/2;		
		break;
		
			
		default:
		r.left = (rand() % screenwidth - barlength);
		break;
	}	
			
			
	//r.left =  screenwidth;
	r.bottom = r.top + bhight;
	r.right = r.left + (barlength*wid);
	if (r.right > screenwidth)
	 {
		r.right = screenwidth - (r.right-screenwidth);
		r.left =  r.right - (barlength*wid);
	}
	//hit = (rand() % view->Bounds().IntegerHeight());
	//wid = (rand() % view->Bounds().IntegerWidth());
	
			
	
			
			
	 palate1.setcolors( bar[j][2], colors);
	
	
		
	
	
	
	
	
	
	
	view->SetHighColor(palate1.Red,palate1.Green,palate1.Blue);
	view->FillRect(rr, B_SOLID_LOW);
	usleep(100);
	if (h1>=1)
	view->FillRoundRect(r, 2, 2, B_SOLID_HIGH);
	else
	view->FillRoundRect(r, 0, 0, B_SOLID_HIGH);
	//view->FillRect(r, B_SOLID_HIGH);
	
	}
	
}


//_________________________________________________________________


void sortfinish(BView *view, int colors)
// place all the bars to one side of the screen.

{
	if (useraction == 1)
	return;
int tmp;
int hit;
tmp = (rand() % 100);

sleep(1);	

	
	
	
	
for (j=1; j<50; j++)	
{	
	
	
	if (idle_time() <= idle)
	return;
			
	int screenheight = (view->Bounds().IntegerHeight());
	
	
	int screenwidth = (view->Bounds().IntegerWidth());
	int wid = screenwidth/100;
	
	hit= screenheight / 54;
	if (updown >= 90)
	hit= screenheight / 55;
	
	float bhight = hit *.3* h1;
	
	int barlength = bar[j][1];
	int row=bar[j][3];
	if (row==0) 
	r.top = -50;
	else
	{
		if (updown < 90)
		r.top = row*(hit+1);
		
		if (updown >= 90)
		r.top = (abs(row-51))*(hit+1);
	}	
	//r.top = jjj*(hit+1);
	rr.top=r.top;
	rr.left=0;
	rr.right=screenwidth;
	rr.bottom=r.top + hit;
	r.bottom=r.top + bhight;
	
	
	
	if (tmp < 50)
		{
			
			r.left = 0;
		}	
	if (tmp >= 50)
		{
			
			r.left =  screenwidth - (barlength*wid);
		}	
	
		
			
			
	//r.left =  screenwidth;
	r.bottom = r.top + bhight;
	r.right = r.left + (barlength*wid);
	if (r.right > screenwidth)
	 {
		r.right = screenwidth;
		r.left =  screenwidth - (barlength*wid);
	}
	//hit = (rand() % view->Bounds().IntegerHeight());
	//wid = (rand() % view->Bounds().IntegerWidth());
	
			
	
			
			
	 palate1.setcolors( bar[j][2], colors);
	
	
		
	
	
	
	
	
	
	
	view->SetHighColor(palate1.Red,palate1.Green,palate1.Blue);
	view->FillRect(rr, B_SOLID_LOW);
	if (h1>=1)
	view->FillRoundRect(r, 2, 2, B_SOLID_HIGH);
	else
	view->FillRoundRect(r, 0, 0, B_SOLID_HIGH);
	//view->FillRect(r, B_SOLID_HIGH);
	usleep(100000);
	}
	sleep(1);	
}	
	
	
	
	
	


//_________________________________________________________________


void bubblesort(BView *view, int colors)
{

int test = 49;
int j;
int limit = 49;

while (test > 1)
	{
	test = 1;

	for (j = 1; j < limit; j++)
		{
		if (bar[bar[j][3]][1] > bar[bar[j+1][3]][1])
			{
				swapbars(view,j,j+1, colors);
				test = j;
			}	
		}	
		limit = test;	
	
	if (idle_time() <= idle)
	{
		useraction=1;
		return;
	}
	}


sortfinish(view, colors);		
	
}




//_________________________________________________________________


void PercolateDown(BView *view, int colors, int MaxLevel)


{
	
	int i = 1;
	int child;
	do
	{
		if (idle_time() <= idle)
	{
		useraction=1;
		return;
	} 
		child = 2*i;
		if (child>MaxLevel)
		break;
		
		if (child+1 <= MaxLevel)
		{
			if (bar[bar[child+1][3]][1] > bar[bar[child][3]][1])
			child++;
		}
			
		if (bar[bar[i][3]][1] < bar[bar[child][3]][1])
		{
			swapbars(view, i, child, colors);
			i = child;
		}
		else
		break;
	} while (MaxLevel > -5);
			 
		
}





//_________________________________________________________________


void PercolateUp(BView *view, int colors, int MaxLevel)


{
int i=MaxLevel;
int Parent;
while (i != 1)
{
	Parent = i / 2;
	if (bar[bar[i][3]][1] > bar[bar[Parent][3]][1])
	{
		swapbars(view, i, Parent, colors);
		i=Parent;
		if (idle_time() <= idle)
	{
		useraction=1;
		return;
	} 
	}
	else
	break;
}
}





//_________________________________________________________________


void HeapSort(BView *view, int colors)



{
	int i;
	
	for(  i = 2; i < 50; i++)
	{
	PercolateUp( view,colors,i);
	}
	for( i= 49; i>0; --i)
	{
		swapbars(view, i, 1, colors);
		PercolateDown( view,colors,i-1);
		if (idle_time() <= idle)
	{
		useraction=1;
		return;
	} 
	}
}
	
	
	
	
	





//_________________________________________________________________


void simplesort(BView *view, int colors)
{
	


	int swap = 2;
	while (swap > 0)
	{
		
		
		
		for (j = 1; j < 49; j++)
		{
			if (idle_time() <= idle)
	{
		useraction=1;
		return;
	}
		
			if (bar[bar[j][3]][1] > bar[bar[j +1][3]][1])
			{
				swapbars(view,j,j+1,colors);
				usleep(40000);
				
				swap = 1;
				if (idle_time() <= idle)
	{
		useraction=1;
		return;
	} 
			}
			
			if (bar[bar[49-j][3]][1] < bar[bar[49-(j +1)][3]][1])
			{
				swapbars(view,49-j,49-(j+1),colors);
				usleep(40000);
				
				swap = 1;
				if (idle_time() <= idle)
	{
		useraction=1;
		return;
	} 
			}
			
		}
		
		
		
		
		
		if ( swap ==1)
		
			swap = 2;
			
		else
		swap = 0;
	}
	
sortfinish(view, colors);		
}

//_________________________________________________________________



void insertionsort(BView *view, int colors)




{
	

	
	int jj;
	j=jj;
	for (jj=2; jj < 50; jj++)
	{
		swapbars(view,0,jj,colors);
		
		 
		
		for ( j = jj; j > 1; j-- )
		
		{
					
					
					if (idle_time() <= idle)
	{
		useraction=1;
		return;
	}
					
			if ( bar[j-1] [3] > bar[0][3])
			
			
			{
				swapbars(view,j,j-1,colors);
				
				
				
			}
			else
			break;
			
		}
		
		swapbars(view,j,0,colors);
		
	}
}			

		

		
//_________________________________________________________________

void exchangesort(BView *view, int colors)
{
	
	int j;	
int row;	
for (row=1; row<50; row++)
	{	
	int smallestrow = row;
	for ( j=row+1; j<50; j++)
		{
			if (idle_time() <= idle)
	{
		useraction=1;
		return;
	}
			if (bar[bar[j][3]][1] < bar[bar[smallestrow][3]][1])
			{
				smallestrow = j;
			}	
		}	
		if ( smallestrow > row )
		{
			swapbars(view, row, smallestrow, colors); 
		}	
		
	if (idle_time() <= idle)
	{
		useraction=1;
		return;
	}
	
	
	}
	sortfinish(view, colors);
	
	
	
}





//_________________________________________________________________


void shellsort(BView *view, int colors)
{
	
	int switch1;
	int rw;
	int limit;
	int maxrow = 49;
	int offset = maxrow / 2;
	while (offset >= 1)
	{
		
	if (idle_time() <= idle)
	{
		useraction=1;
		return;
	}
		
		limit = maxrow - offset;
		do
		{
			switch1 = 0;
			for (rw = 1; rw < limit+1; rw ++)
			{
				if (bar[bar[rw][3]][1] > bar[bar[rw + offset][3]] [1])
				{
					swapbars(view, rw, rw + offset, colors);
					switch1 = rw;
					if (idle_time() <= idle)
	{
		useraction=1;
		return;
	}
				}
				
			}
			limit = switch1 - offset;
		}
		while (switch1 > 0);
		
		offset = offset / 2;
	}
	sortfinish(view, colors);	
}



//_________________________________________________________________


int quicksort(BView *view, int colors, int low, int high)

{
	
	int test;
	int i;
	int j;
	int partition;
	
	if (low < high)
	{
		if (high -low == 1)
		{
			if (bar[bar[low][3]] [1] > bar[bar[high][3]] [1])
			{
				swapbars(view, low, high, colors);
			}
		}
		else
		{
			int randindex = (rand() %(high - low));
			randindex = randindex + low;
			swapbars(view, high, randindex, colors);
			partition =  bar[bar[high][3]] [1];
			do
			{
				i = low;
				j = high;
				while ((i < j) &&  (bar[bar[i][3]][1] <= partition))
				{
					i++;
				}
				while (( j > i) && (bar[bar[j][3]][1] >= partition))
				{
					j--;
				}
				if (i < j)
				{
					swapbars(view, i, j, colors);
				}
			} while (i < j);
			swapbars(view, i, high, colors);
			if ((i-low)< (high - i))
			{
					
				if (idle_time() <= idle)
	{
		useraction=1;
		return 1;
	}
				
				test= quicksort(view,colors,low,i-1);
				if (test == 1)
				return 1;
				test = quicksort(view,colors,i+1,high);
				if (test == 1)
				return 1;
			}
			else
			{
				test = quicksort(view,colors,i+1,high);
				if (test == 1)
				return 1;
				test = quicksort(view,colors,low,i-1);
				if (test == 1)
				return 1;
			}
		}
	}
return 0;		
}

					
//________________________________________________________________









int initbar()
{
	updown = (rand()%100);
	//updown=92;
	dly = (rand()%80000);
	//dly = 1;
	
h1 = (rand() %32);
	h1=h1/10;
	//h1=3.2;
	useraction=0;
	idle = idle_time();
	int tmp;
	
		for (j=0;j<51;++j)
		{
			bar[j][1]= j;
			bar [j][2] = j;
				
			bar [j][3]=j;
			row[j]=j;
		}
				

	srand(real_time_clock());
	count++;
	if (count>5000)
		count=1;
	int k;
	for (j=1;j<50;++j)	
	{	
	
	k=(rand()%50);
	if (k==0)
		k=1;	
	tmp= bar[j][3];
	bar[j][3]=bar[k][3];
	bar[k][3]=tmp;
	row[j]=j;
	}
	display = (rand() %230);
	if (display <= 30)
		display = 1;
	if ((display >30) && (display < 60))	
		display = 2;
	if ((display >=60) && (display < 90))
	display =3;	
	
	if ((display >= 90) && (display < 120))
	display = 4;
	
	if ((display >= 120) && (display < 150))
	display = 5;
	if ((display >= 150) && (display < 180))
	display = 6;
	if ((display >= 180) && (display < 200))
	display = 7;
	
	
	if (display >= 200)
		display = 1;
		
		//display = 7;
		
		
		
	int colors = (rand() % 800);
	colors = (rand() % 800);
	colors = (rand() % 2500);
	//colors = 2250;
	
	if ( colors < 100)
	colors=1;
	if ((colors >= 100) && (colors < 200))
	colors=2;
	if ((colors >= 200) && (colors < 300))
	colors=3;
	if ((colors >= 300) && (colors < 400))
	colors=4;
	if ((colors >= 400) && (colors < 500))
	colors=5;
	if ((colors >= 500) && (colors < 600))
	colors=6;
	if ((colors >= 600) && (colors < 700))
	colors=7;
	if ((colors >= 700) & (colors < 800))
	colors=8;
	if ((colors >= 800) & (colors < 850))
	colors=9;
	if ((colors >= 850) & (colors < 900))
	colors=10;
	if ((colors >= 900) & (colors < 950))
	colors=11;
	if ((colors >= 950) & (colors < 1000))
	colors=12;
	if ((colors >= 1000) & (colors < 1050))
	colors=13;
	if ((colors >= 1050) & (colors < 1100))
	colors=14;
	if ((colors >= 1100) & (colors < 1150))
	colors=15;
	if ((colors >= 1150) & (colors < 1200))
	colors=16;
	if ((colors >= 1200) & (colors < 1250))
	colors=17;
	if ((colors >= 1250) & (colors < 1300))
	colors=18;
	if ((colors >= 1300) & (colors < 1350))
	colors=19;
	if ((colors >= 1350) & (colors < 1400))
	colors=20;
	if ((colors >= 1400) & (colors < 1450))
	colors=21;
	if ((colors >= 1450) & (colors < 1600))
	colors = 22;
	if ((colors >= 1600) & (colors < 1800))
	{
		
		colors = 23;
		palate1.setrandom();
	}
	
	if ((colors >= 1800) & (colors < 2000))
		colors = 24;
		
	
	
	if ((colors >= 2000) & (colors < 2200)){
		
		colors = 25;
		palate1.setrandom();
	}
	
	if (colors >= 2200){
	colors = 23;
	palate1.setrandom();
	}
	
	
		
	bar [0][0] = colors;
	return colors;	
}
	
//___________________________________________________________________


void sort_save::Draw(BView *view, int32 frame)
{
view->SetLowColor(0,0,0);
 
view->FillRect( view->Bounds(), B_SOLID_LOW );
int row;
int jjj;
int barlength;
int wid;
int hit;
int screenwidth;
int screenheight;
float bhight;


int colors = initbar();
jjj=1;
 screenheight = (view->Bounds().IntegerHeight());
 screenwidth = (view->Bounds().IntegerWidth());
	hit= screenheight / 54;
	if (updown >= 90)
	hit= screenheight / 55;
	
	bhight = hit *.3* h1;
while (jjj < 50)
	{	
	
	x++;
	
	
	
	
	
	
	wid=screenwidth/100;
	
	
	
	
	barlength = bar[jjj][1];
	row=bar[jjj][3];
	if (row==0) 
	r.top = -50;
	else
	{
		if (updown < 90)
		r.top = row*(hit+1);
		
		if (updown >=90)
		r.top = (abs(row-51))*(hit+1);
	}		
	
	r.bottom=r.top+bhight;
	//r.top = jjj*(hit+1);
	rr.top=r.top;
	rr.left=0;
	rr.right=screenwidth;
	rr.bottom=r.top + hit;
	
	
	switch(display)
	{
		case 1:
		r.left = (rand() % screenwidth - barlength);
		
		break;
		
		case 2:
		lr = rand() % 50;
		if (lr > 25)
			r.left = 0;
		if (lr <= 25)	
			r.left =  screenwidth - (barlength*wid);
			
		break;
			
		case 3:
		lr = rand() % 50;
		if (lr > 25)	 
			r.left = 150;
		if (lr <= 25)
			r.left =  (screenwidth - (barlength*wid)) -150;
			
			
		break;
		
	
		
		case 4:
		r.left =(screenwidth/2)-(25*wid);
		break;
		
		case 5:
		lr = rand() % 50;
		if (lr > 25)	 
			r.left =(screenwidth/2)-(25*wid);
		if (lr <= 25)
			r.left =  (screenwidth/2)+(25*wid)-(barlength*wid);		
		break;
		
		case 6:
		r.left =  (screenwidth/2)+(25*wid)-(barlength*wid);		
		break;
		
		case 7:
		r.left =  (screenwidth/2)-(barlength*wid)/2;		
		break;
		
			
		default:
		r.left =(rand() % screenwidth - barlength);
		break;
	}	
			
			
	
	r.bottom = r.top + bhight;
	r.right = r.left + (barlength*wid);
	if (r.right > screenwidth)
	 {
		r.right = screenwidth - (r.right-screenwidth);
		r.left =  r.right - (barlength*wid);
	}
	
			
	
			
			
	 palate1.setcolors( bar[jjj][2], colors);
	
	
		
	
	
	
	
	
	
	
	view->SetHighColor(palate1.Red,palate1.Green,palate1.Blue);
	view->FillRect(rr, B_SOLID_LOW);
	if (h1>=1)
	view->FillRoundRect(r, 2, 2, B_SOLID_HIGH);
	else
	view->FillRoundRect(r, 0, 0, B_SOLID_HIGH);
	
	
	
usleep(10000);	
jjj = jjj +1;
x=250;

	}
	usleep(500000);
	if (x > 250)
	{
		view->FillRect( view->Bounds(), B_SOLID_LOW );
		x=0;
		j=50;
		
	}
int sorttype = (rand() % 70);
//view->SetHighColor(200,200,200);
view->SetHighColor(0,0,0);
BString fText="";
//sorttype = 62;




if (sorttype < 10)
{
dly = dly+40000;
	fText="ExchangeSort";
	//view->DrawString(fText.String(),BPoint((screenwidth/2)-15, screenheight-6)); 
	exchangesort(view, colors);
	
}
if ((sorttype >= 10)&& (sorttype < 20))
{
	dly = dly+10000;
	fText="BubbleSort";
	//view->DrawString(fText.String(),BPoint((screenwidth/2)-15, screenheight-6)); 
	bubblesort(view, colors);
	
}
if ((sorttype >= 20) && (sorttype < 30))
{
	dly = dly+20000;
	fText="ShellSort";
	//view->DrawString(fText.String(),BPoint((screenwidth/2)-15, screenheight-6)); 
	shellsort(view, colors);
	
}
if ((sorttype >= 30) && (sorttype < 40))

{
	dly = dly+30000;
	fText="QuickSort";
	//view->DrawString(fText.String(),BPoint((screenwidth/2)-15, screenheight-6)); 
	int test = quicksort(view, colors, 1, 49);
	if (test != 1)
	sortfinish(view, colors);
	
}


if ((sorttype >= 40) && (sorttype < 50))
{
	dly = dly+10000;
	fText="InsertionSort";
	//view->DrawString(fText.String(),BPoint((screenwidth/2)-15, screenheight-6)); 
	insertionsort(view, colors);
	sortfinish(view, colors);
	
}

if ((sorttype >= 50) && (sorttype < 60))
{	dly=dly/2;
	fText="SimpleSort";
	//view->DrawString(fText.String(),BPoint((screenwidth/2)-15, screenheight-6)); 
	simplesort(view, colors);
		

}

if (sorttype >= 60)
{
	dly = dly+10000;
	
	fText="HeapSort";
	//view->DrawString(fText.String(),BPoint((screenwidth/2)-15, screenheight-6)); 
 	usleep(500000);
	HeapSort(view,colors);
	sortfinish(view, colors);
	
}


}






void colorpicker::setrandom ()

{
	
	int r=0;
	int g=0;
	int b=0;
	
	r = (rand() % 250);
	
	b = (rand() % 250);
	
	g = (rand() % 250);
	
	
	
	
	ranr=r;
	ranb=b;
	rang=g;
}

void colorpicker :: setcolors (int bar, int colors)
{
		int b = 0;
		int g = 0;
		int r = 0;
		
	if (colors<1)
	 	colors=1;	
	
	if (colors==1)
	{
	while (bar > 15)
			{
			bar -= 15;
			}
	
	switch(bar)
	{
		case 0:
		Red = 0;
		Blue = 0;
		Green = 0;
		break;
		case 1:
		Red = 0;
		Blue = 0;
		Green = 168;
		break;
		
		case 2:
		Red = 0;
		Blue = 168;
		Green = 0;
		break;
		
		
		
		case 3:
		Red = 0;
		Blue = 168;
		Green = 168;
		break;
		
		
		case 4:
		Red = 168;
		Blue = 0;
		Green = 0;
		break;
		
		case 5:
		Red = 168;
		Blue = 0;
		Green = 168;
		break;
		
		case 6:
		Red = 168;
		Blue = 168;
		Green = 0;
		break;
		
		case 7:
		Red = 168;
		Blue = 168;
		Green = 168;
		break;
		
		case 8:
		Red = 84;
		Blue = 84;
		Green = 84;
		break;
		
		
		case 9:
		Red = 84;
		Blue = 84;
		Green = 252;
		break;
		
		
		case 10:
		Red = 84;
		Blue = 252;
		Green = 84;
		break;
		
		
		case 11:
		Red = 84;
		Blue = 252;
		Green = 252;
		break;
		
		
		case 12:
		Red = 252;
		Blue = 84;
		Green = 84;
		
		
		break;
		
		
		case 13:
		Red = 252;
		Blue = 84;
		Green = 252;
		break;
		
		
		case 14:
		Red = 252;
		Blue = 252;
		Green = 84;
		break;
		
		
		case 15:
		Red = 252;
		Blue = 252;
		Green = 252;
		break;
		
		default:
		
		Red = 252;
		Blue = 252;
		Green = 252;
		break;
		
	}	
	}
	if (colors == 2)
	{
		Red=250 - (5*bar) ;
		Blue = 255 - (2*bar);
		Green = 250 - (5*bar);
	}
		
	if (colors == 3)
	{
		Red=255 - (2*bar) ;
		Blue = 250 - (5*bar);
		Green = 250 - (5*bar);
	}
	
	if (colors == 4)
	{
		Red=7;
		Blue = 250 - (5*bar);
		Green = 255 - (2*bar);
	}	
	
	if (colors == 5)
	
	{
		Red=7;
		Blue = 250 - (4*bar);
		Green = 250 - (4*bar);
	}
	
	
	if (colors == 6)
	
	{
		Red=250 - (4*bar);
		Blue = 250 - (4*bar);
		Green = 250 - (4*bar);
	}
	if (colors == 7)
	
	{
		Red=250 - (4*bar);
		Blue = 7;
		Green = 250 - (4*bar);
	}
	if (colors == 8)
	
	{
		Red=250 - (4*bar);
		Blue = 250 - (4*bar);
		Green = 7;
	}
	if (colors == 9)
	{
		Red = 0;
		Blue = 0;
		Green = 168;
	}
	
	if (colors == 10)
	{
		Red = 0;
		Blue = 168;
		Green = 0;
	}
	
	if (colors == 11)
	{
		Red = 0;
		Blue = 168;
		Green = 168;
	}
	if (colors == 12)
	{
		Red = 168;
		Blue = 0;
		Green = 0;
	}
	if (colors == 13)
	{
		Red = 168;
		Blue = 0;
		Green = 168;
	}
	
	if (colors == 14)
	{
		Red = 168;
		Blue = 168;
		Green = 0;
	}
	
	if (colors == 15)
	{
		Red = 168;
		Blue = 168;
		Green = 168;
	}
	
	if (colors == 16)
	{
		Red = 84;
		Blue = 84;
		Green = 84;
	}
	
	if (colors == 17)
	{
		Red = 84;
		Blue = 84;
		Green = 252;
		
	}
	
	if (colors == 18)
	{
		Red = 84;
		Blue = 252;
		Green = 84;
	}

if (colors == 19)
	{
		Red = 84;
		Blue = 252;
		Green = 252;
	}

if (colors == 20)
	{
		Red = 252;
		Blue = 84;
		Green = 252;
	}
if (colors == 21)
	{
		Red = 252;
		Blue = 252;
		Green = 84;
	}
	
	if (bar<1)
	{
		Red = 0;
		Blue = 0;
		Green = 0;
	}
	
	
	
	if ((colors==22) | (colors == 24))
	{
		int base;
		int step;
		
		if (colors== 22)
		{
			base = 50;
			step = 25;
		}
		else
			base = 100;
			step = 18;
		
		r=base;
		g=base;
		b=base;
		
		if (bar <=8)
		{
			b=250;
			r += (step*bar);
			
		}
		if ((bar > 8) & (bar <=16))
		{
			b=250;
			r=250;
			
			
			b = b - (step*(bar-8));
			
		}
		if ((bar > 16)&(bar <=24))
		{
			r=250;
			g+= ((bar-16)*step);
		}
		if ((bar > 24)&(bar <=32))
		{
			g=250;
			r=250;
			r= r-((bar-24)*step);
			
		}
		if ((bar > 32)&(bar <=40))
		{
			g=250;
			b+= ((bar-32)*step);
		}
		
		if ((bar > 40)&(bar <=48))
		{
			b=250;
			g=250;
			g= g - ((bar-40)*step);
			
		}		
	
		if ((bar > 48)&(bar <=50))
		{
			b=250;
			r+= ((bar-48)*step);
		}		
	
		
		
		Red = r;
		Blue = b;
		Green = g;			
	
	}
	
	
	if (colors==23)
	{
		if (ranr>126)		
			Red = ranr-(2.5*bar);
		else
			Red = ranr+(2.5*bar);
		if (ranb > 126)
			Blue = ranb-(2.5*bar); 
		else		  
			Blue = ranb+(2.5*bar);
		if (rang > 126)
		 	Green = rang-(2.5*bar);
		else
		 	Green = rang+(2.5*bar);
	}
	
	if (colors==25)
	{
		Red = ranr;
		Blue = ranb;
		Green = rang;
	}
	
	
	if (bar < 1)
	{
		Red = 0;
		Blue = 0;
		Green = 0;
	}	
	
	
	
	
	

}

