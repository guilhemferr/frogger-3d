#include "GameManager.h"


void GameManager::updateGame(double delta_t) {
	for(int i = 0; i < dynamic_objs.size(); i++) {
		dynamic_objs[i]->update(delta_t);
	}
}

void GameManager::drawScene(VSMathLib* vsml) {
	for(int i = 0; i < dynamic_objs.size(); i++) {
		dynamic_objs[i]->draw(vsml);
	}
}

