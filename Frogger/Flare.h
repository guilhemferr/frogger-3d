#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_
#include "StaticObject.h"
#endif

#ifndef __FLARE_H
#define __FLARE_H

/* --- Defines --- */

#define FLARE_MAXELEMENTSPERFLARE         5

#define FLARE_RANGE(A,B)    ( (rand()%((B)-(A)+1)) + (A) )
#define FLARE_FRANGE(A,B)   ( ((float)(rand()&0xffffff)/(float)0xfffffe)*((B)-(A)) + (A) )

#define MAKEID(a,b,c,d)     (((a)<<24) | ((b)<<16) | ((c)<<8) | ((d)<<0))

#define FLARE_MINCOLOUR        MAKEID(140, 100, 50, 100)
#define FLARE_MAXCOLOUR        MAKEID(255, 255, 200, 255)

typedef struct FLARE_ELEMENT_DEF
{
	struct TEXTURE_DEF  *texture;

	float           fDistance;        // Distance along ray from source (0.0-1.0)
	float           fSize;            // Size relative to flare envelope (0.0-1.0)
	unsigned int    argb;            // ARGB for intensity mapping
}
FLARE_ELEMENT_DEF;
#endif

class Flare : public StaticObject{

private:
	int flareId;
	int nPieces;
	float fMaxSize;
	unsigned int minColour;
	unsigned int maxColour;

	//for render purposes
	int lx, ly, cx, cy, wth, ht;


	FLARE_ELEMENT_DEF elements[FLARE_MAXELEMENTSPERFLARE];


public:
	Flare(float xcoord, float ycoord, float zcoord, int flareId, int* idVector) : StaticObject(idVector){
		setX(xcoord);
		setY(ycoord);
		setZ(zcoord);

		Flare::nPieces = FLARE_MAXELEMENTSPERFLARE;
		Flare::fMaxSize = FLARE_MAXELEMENTSPERFLARE;
		Flare::minColour = FLARE_MINCOLOUR;
		Flare::maxColour = FLARE_MAXCOLOUR;
		Flare::wth = 1;
		Flare::ht = 1;

		Flare::flareId = flareId;
	}
	
	void create(VSMathLib* vsml, VSResSurfRevLib mySurfRev);
	void draw(VSMathLib *vsml);

	//setAttr(5, )
	//FLARE_randomize(&renderFlare, NPIECETEXTURES, FLARE_RANGE(FLARE_MINELEMENTSPERFLARE, FLARE_MAXELEMENTSPERFLARE), FLARE_MAXSIZE, FLARE_MINCOLOUR, FLARE_MAXCOLOUR);
	//NOT USED
	void setAttr(int nPieces, unsigned int minColour, unsigned int maxColour){
		Flare::nPieces = nPieces;
		Flare::fMaxSize = FLARE_MAXELEMENTSPERFLARE;
		Flare::minColour = minColour;
		Flare::maxColour = maxColour;
	}

	void setRenderAttr(int lx, int ly, int cx, int cy, int width, int height){
		Flare::lx = lx;
		Flare::ly = ly;
		Flare::cx = cx;
		Flare::cy = cy;
		Flare::wth = width;
		Flare::ht = height;
	}
};