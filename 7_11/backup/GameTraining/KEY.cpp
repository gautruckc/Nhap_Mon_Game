#include "KEY.h"



KEY * KEY::instance = 0;
KEY * KEY::getInstance()
{
	if (instance == 0)
		instance = new KEY();
	return instance;
}

void KEY::update()
{
	CKeyboard::getInstance()->UpdateKeyboard();

	isUpDown = CKeyboard::getInstance()->IsKeyDown(DIK_UP);
	isUpPress = isUpDown && !isPreviousUpDown;
	isPreviousUpDown = isUpDown;

	isDownDown = CKeyboard::getInstance()->IsKeyDown(DIK_DOWN);
	isDownPress = isDownDown && !isPreviousDownDown;
	isPreviousDownDown = isDownDown;

	isLeftDown = CKeyboard::getInstance()->IsKeyDown(DIK_LEFT);
	isRightDown = CKeyboard::getInstance()->IsKeyDown(DIK_RIGHT); // || CKeyboard::getInstance()->IsKeyDown(DIK_D)

	isJumpDown = CKeyboard::getInstance()->IsKeyDown(DIK_SPACE); // || CKeyboard::getInstance()->IsKeyDown(DIK_X)
	isJumpPress = isJumpDown && !isPreviousJumpDown;
	isPreviousJumpDown = isJumpDown;

	isAttackDown = CKeyboard::getInstance()->IsKeyDown(DIK_Z);
	isAttackPress = isAttackDown && !isPreviousAttackDown;
	isPreviousAttackDown = isAttackDown;

	isMoveDown = isLeftDown || isRightDown;

}

KEY::KEY()
{
	isPreviousJumpDown = isPreviousAttackDown = false;
}


KEY::~KEY()
{
}
