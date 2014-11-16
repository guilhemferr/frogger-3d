#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>

#include "flare.h"

/************************************************************
Defines.
************************************************************/

// Get height from width, assuming certain aspect ratio.
#define HEIGHTFROMWIDTH(w)  ((320*(w)*Flare::ht)/(240*Flare::wth))

#define isqrt(x)        (int)((double)(x))

void Flare::create(VSMathLib *vsml, VSResSurfRevLib mySurfRev){
	float amb[] = { 0.25f, 0.25f, 0.25f, 1.0f };
	float diff[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	float spec[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
	float emissive[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	float* shininess = new float(128.0f * 0.1f);
	
	
	int             i;
	float           fFracDist;
	float           fEnvelopeSize;
	int     dx, dy;          // Screen coordinates of "destination"
	int     px, py;          // Screen coordinates of flare element
	int     maxflaredist, flaredist, flaremaxsize, flarescale;
	int     width, height, alpha;    // Piece parameters;
	FLARE_ELEMENT_DEF *element;

	fFracDist = 1.0f / (float)(Flare::nPieces - 1);

	// Compute how far off-center the flare source is.
	maxflaredist = isqrt(cx*cx + cy*cy);
	flaredist = isqrt((lx - cx)*(lx - cx) +
		(ly - cy)*(ly - cy));
	flaredist = (maxflaredist - flaredist);
	flaremaxsize = (int)(Flare::wth * Flare::fMaxSize);
	flarescale = (int)(Flare::wth * Flare::fMaxSize);

	// Destination is opposite side of centre from source
	dx = cx + (cx - lx);
	dy = cy + (cy - ly);

	for (i = 0; i < Flare::nPieces; ++i)
	{
		element = &Flare::elements[i];
		element->fDistance = (fFracDist*i) + FLARE_FRANGE(0, fFracDist);

		// Envelope size is maximum at ends of line, minimum in the middle (i.e. two
		// cones, touching at the tips).
		fEnvelopeSize = (float)fabs(1.0f - 2 * element->fDistance);

		element->fSize = FLARE_FRANGE(0.6f, 1.0f) * fEnvelopeSize;
		element->argb = FLARE_RANGE(minColour & 0xff000000, maxColour & 0xff000000) |
			FLARE_RANGE(minColour & 0x00ff0000, maxColour & 0x00ff0000) |
			FLARE_RANGE(minColour & 0x0000ff00, maxColour & 0x0000ff00) |
			FLARE_RANGE(minColour & 0x000000ff, maxColour & 0x000000ff);

		// Position is interpolated along line between start and destination.
		px = (int)((1.0f - element->fDistance)*lx + element->fDistance*dx);
		py = (int)((1.0f - element->fDistance)*ly + element->fDistance*dy);

		// Piece size are 0 to 1; flare size is proportion of
		// screen width; scale by flaredist/maxflaredist.
		width = (int)((flaredist*flarescale*element->fSize) / maxflaredist);

		// Width gets clamped, to allows the off-axis flares
		// to keep a good size without letting the elements get
		// too big when centered.
		if (width > flaremaxsize)
		{
			width = flaremaxsize;
		}

		// Flare elements are square (round) so height is just
		// width scaled by aspect ratio.
		height = HEIGHTFROMWIDTH(width);
		alpha = (flaredist*(element->argb >> 24)) / maxflaredist;
		//diff[3] = alpha;
		
		mySurfRev.createRectangleNotBillboard(px - width / 2, py - height / 2, width, height);
		mySurfRev.setColor(VSResourceLib::MaterialSemantics::AMBIENT, amb);
		mySurfRev.setColor(VSResourceLib::MaterialSemantics::DIFFUSE, diff);
		mySurfRev.setColor(VSResourceLib::MaterialSemantics::SPECULAR, spec);
		mySurfRev.setColor(VSResourceLib::MaterialSemantics::EMISSIVE, emissive);
		mySurfRev.setColor(VSResourceLib::MaterialSemantics::SHININESS, shininess);
		objId++;
	}
}

void  Flare::draw(VSMathLib *vsml)
{
	int i;
	int currentId = Flare::flareId;

	// Render each element.
	for (i = 0; i < Flare::nPieces; ++i)
	{
		vsml->pushMatrix(VSMathLib::MODEL);
			initShadersVars(vsml, currentId);
			if (i % 2 == 0){
				glUniform1i(getIdVector()[TEXID], 6);
			}
			else {
				glUniform1i(getIdVector()[TEXID], 7);
			}

			
			glBindVertexArray(mesh[currentId].vao);
			glDrawElements(mesh[currentId].type, mesh[currentId].numIndexes, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		vsml->popMatrix(VSMathLib::MODEL);
		currentId++;
	}
}