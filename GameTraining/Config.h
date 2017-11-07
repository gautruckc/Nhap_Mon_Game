#pragma once

#define FPS 160

#pragma region String

#define TITLE_STR "Mega Man"
#define CVFORM_CLASS_NAME "MegaManForm"  

#pragma endregion


#pragma region Size

#define FORM_WIDTH 257*2
#define FORM_HEIGHT 216*2

#define BACKBUFFER_WIDTH 257
#define BACKBUFFER_HEIGHT 216

#pragma endregion

#pragma region Constants

extern int STAIR_DELTA;
extern int STAIR_DY;
extern int DISTANCE_OUT_STAIR;
extern float RM_VY_JUMP;
extern float RM_V_RUN;
extern float RM_VX_STAND;

/*le thi kim chung update 27.10.2017*/
extern float ALD_VY_JUMP;
extern float ALD_V_RUN;
extern float ALD_VX_STAND;
extern int CAMERA_CHANGEMAPVIEW_DY;
extern float ALADIN_CHANGEMAPVIEW_DY;

extern int CAMERA_CHANGESTAGEVIEW_DY;
extern float ROCKMAN_CHANGESTAGEVIEW_DY;
extern float TIME_BLINK_OPEN;
extern float TIME_BLINK_CLOSE;
extern float TIME_BEAK_CLOSED;
extern float TIME_BEAK_SHOOTING;
extern float TIME_BEAK_CHANGE_STATE;
extern int BLADER_FIND_ROCKMAN_DISTANCE;
extern float BLADER_ATTACK_DY;
extern int RM_BULLET_WAITING_DELAYTIME;
extern int RM_SHOOTING_DELAYTIME;
#pragma endregion